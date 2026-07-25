from fastapi import APIRouter, status, Depends, HTTPException

from app.schemas import ProductCreate, Product as ProductSchema
from app.models.products import Product as ProductModel
from app.models.categories import Category as CategoryModel
from app.models.users import User as UserModel

from app.auth import get_current_seller

from app.db_depends import get_async_db

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select, update

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


@router.get("/", status_code=status.HTTP_200_OK, response_model=List[ProductSchema])
async def get_products(db: AsyncSession = Depends(get_async_db)):
    stmt = select(ProductModel).where(ProductModel.is_active == True)
    all_products = (await db.scalars(stmt)).all()

    return all_products


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
            detail='You can update only your own products',
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
            detail='You can update only your own products',
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
