from fastapi import (
    APIRouter,
    HTTPException,
    status,
    Depends,
    Query,
)

from app.schemas import ProductRead, ProductCreate, ProductPagination
from app.models import Product, Category, User

from app.auth import get_current_seller

from sqlalchemy import select, func
from sqlalchemy.ext.asyncio import AsyncSession

from app.depends.db import get_db
from app.depends.router import check_category

router = APIRouter(
    prefix="/product",
    tags=["product"],
)


@router.get("/", response_model=ProductPagination)
async def get_products(
    page: int = Query(1, ge=1),
    page_size: int = Query(20, ge=10, le=80),
    min_price: float | None = Query(None),
    max_price: float | None = Query(None),
    db: AsyncSession = Depends(get_db),
):
    filters = [Product.is_active.is_(True)]

    if min_price is not None:
        filters.append(Product.price >= min_price)
    if max_price is not None:
        filters.append(Product.price <= max_price)

    stmt = select(func.count()).select_from(Product).where(*filters)
    total = await db.scalar(stmt)

    stmt = (
        select(Product)
        .where(*filters)
        .limit(page_size)
        .offset((page - 1) * page_size)
        .order_by(Product.id)
    )
    product_items = (await db.scalars(stmt)).all()

    return {
        "products": product_items,
        "total": total,
        "page": page,
        "page_size": page_size,
    }


@router.get("/category/{category_id}", response_model=ProductPagination)
async def get_product(
    category_id: int,
    page: int = Query(1, ge=1),
    page_size: int = Query(20, ge=10, le=80),
    min_price: float | None = Query(None),
    max_price: float | None = Query(None),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Category).where(
        Category.id == category_id,
        Category.is_active.is_(True),
    )
    res = (await db.scalars(stmt)).first()

    if res is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Category with this id is not exists",
        )

    filters = [Product.category_id == category_id, Product.is_active.is_(True)]

    if min_price is not None:
        filters.append(Product.price >= min_price)
    if max_price is not None:
        filters.append(Product.price <= max_price)

    stmt = select(func.count()).select_from(Product).where(*filters)
    total = await db.scalar(stmt)

    stmt = (
        select(Product)
        .where(*filters)
        .limit(page_size)
        .offset((page - 1) * page_size)
        .order_by(Product.id)
    )
    product_items = (await db.scalars(stmt)).all()

    return {
        "products": product_items,
        "total": total,
        "page": page,
        "page_size": page_size,
    }


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=ProductRead)
async def create_product(
    product: ProductCreate,
    _: None = Depends(check_category),
    current_user: User = Depends(get_current_seller),
    db: AsyncSession = Depends(get_db),
):
    new_product_model = Product(
        **product.model_dump(),
        user_id=current_user.id,
    )

    db.add(new_product_model)
    await db.commit()

    return new_product_model


@router.put("/{product_id}", response_model=ProductRead)
async def change_product(
    product_id: int,
    product: ProductCreate,
    _: None = Depends(check_category),
    current_user: User = Depends(get_current_seller),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Product).where(
        Product.id == product_id,
        Product.is_active.is_(True),
    )
    res = (await db.scalars(stmt)).first()

    if res is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Product with this id is not exists",
        )

    if product.user_id != current_user.id:
        raise HTTPException(
            detail="You can update only your own products",
            status_code=status.HTTP_403_FORBIDDEN,
        )

    for key, value in product.model_dump().items():
        setattr(res, key, value)
    await db.commit()

    return res


@router.delete("/{product_id}")
async def delete_product(
    product_id: int,
    current_user: User = Depends(get_current_seller),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Product).where(
        Product.id == product_id,
        Product.is_active.is_(True),
    )
    res = (await db.scalars(stmt)).first()

    if res is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Product with this id is not exists",
        )

    if product.user_id != current_user.id:
        raise HTTPException(
            detail="You can update only your own products",
            status_code=status.HTTP_403_FORBIDDEN,
        )

    setattr(res, "is_active", False)
    await db.commit()

    return {"status": "success", "message": "category marked as inactive"}
