from fastapi import APIRouter, status, Depends, HTTPException, Query

from app.schemas import ProductCreate, Product as ProductSchema, ProductList
from app.models.products import Product as ProductModel
from app.models.categories import Category as CategoryModel
from app.models.users import User as UserModel

from app.auth import get_current_seller

from app.db_depends import get_async_db

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select, update, desc, func

from typing import List

from .routers_depends import (
    check_category,
    check_product_and_category,
    check_product,
)


router = APIRouter(
    prefix="/products",
    tags=["products"],
)


@router.get("/", status_code=status.HTTP_200_OK, response_model=ProductList)
async def get_products(
    page: int = Query(1, ge=1),
    page_size: int = Query(20, ge=1, le=100),
    min_price: float | None = Query(
        None, description="Минимальная цена"
    ),
    max_price: float | None = Query(
        None, description="Максимальная цена цена"
    ),
    in_stock: int | None = Query(
        None, description="True - товар в наличии, в ином случае - False"
    ),
    seller_id: int | None = Query(
        None, description="id продавца"
    ),
    db: AsyncSession = Depends(get_async_db)
):
    if min_price is not None and max_price is not None and min_price > max_price:
        raise HTTPException(
            detail="min price > max price",
            status_code=status.HTTP_400_BAD_REQUEST,
        )

    filters = [ProductModel.is_active.is_(True)]

    if min_price is not None:
        filters.append(ProductModel.price >= min_price)
    if max_price is not None:
        filters.append(ProductModel.price <= max_price)
    if in_stock is not None:
        filters.append(ProductModel.stock > 0 if in_stock else ProductModel.stock == 0)
    if seller_id is not None:
        filters.append(ProductModel.user_id >= seller_id)

    total_stmt = select(func.count()).select_from(ProductModel).where(*filters)
    total = await db.scalar(total_stmt)

    products_stmt = (
        select(ProductModel)
        .where(*filters)
        .order_by(ProductModel.id)
        .offset((page - 1) * page_size)
        .limit(page_size)
    )
    items = (await db.scalars(products_stmt)).all()

    return {
        "items": items,
        "total": total,
        "page": page,
        "page_size": page_size,
    }


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=ProductSchema)
async def create_product(
    product: ProductCreate,
    current_user: UserModel = Depends(get_current_seller),
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(CategoryModel).where(
        CategoryModel.id == product.category_id, CategoryModel.is_active == True
    )
    category = (await db.scalars(stmt)).first()

    if category is None:
        raise HTTPException(
            detail="Category not found or inactive",
            status_code=status.HTTP_400_BAD_REQUEST,
        )

    cur_product = ProductModel(
        **product.model_dump(),
        user_id=current_user.id,
    )

    db.add(cur_product)
    await db.commit()
    await db.refresh(cur_product)

    return cur_product


@router.get(
    "/category/{category_id}",
    status_code=status.HTTP_200_OK,
    response_model=List[ProductSchema],
)
async def get_product_by_category(
    category_id: int,
    cur_category: CategoryModel = Depends(check_category),
    db: AsyncSession = Depends(get_async_db),
):

    stmt = select(ProductModel).where(
        ProductModel.category_id == cur_category.id, ProductModel.is_active == True
    )
    product_by_category = (await db.scalars(stmt)).all()

    return product_by_category


@router.put(
    "/{product_id}", status_code=status.HTTP_200_OK, response_model=ProductSchema
)
async def update_product(
    new_product: ProductCreate,
    product_id: int,
    new_product_model: ProductModel = Depends(check_product_and_category),
    current_user: UserModel = Depends(get_current_seller),
    db: AsyncSession = Depends(get_async_db),
):
    if new_product_model.user_id != current_user.id:
        raise HTTPException(
            detail="You can update only your own products",
            status_code=status.HTTP_403_FORBIDDEN,
        )

    await db.execute(
        update(ProductModel)
        .where(ProductModel.id == product_id, ProductModel.is_active.is_(True))
        .values(**new_product.model_dump())
    )
    await db.commit()
    await db.refresh(new_product_model)

    return new_product_model


@router.delete("/{product_id}", status_code=status.HTTP_200_OK)
async def delete_category(
    product_id: int,
    product: ProductModel = Depends(check_product),
    current_user: UserModel = Depends(get_current_seller),
    db: AsyncSession = Depends(get_async_db),
):
    if product.user_id != current_user.id:
        raise HTTPException(
            detail="You can update only your own products",
            status_code=status.HTTP_403_FORBIDDEN,
        )

    await db.execute(
        update(ProductModel)
        .where(ProductModel.id == product_id, ProductModel.is_active.is_(True))
        .values(is_active=False)
    )

    await db.commit()
    await db.refresh(product)
    return {"status": "success", "message": "Product marked as inactive"}
