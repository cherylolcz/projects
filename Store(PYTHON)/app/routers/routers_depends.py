from app.db_depends import get_async_db

from app.models.categories import Category as CategoryModel
from app.models.products import Product as ProductModel

from app.schemas import CategoryCreate, ProductCreate

from fastapi import HTTPException, status, Depends

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession


# ПРОВЕРКА РОДИТЕЛЬСКОЙ КАТЕГОРИИ
async def check_parent_category(
    category: CategoryCreate, db: AsyncSession = Depends(get_async_db)
):
    if category.parent_id is not None:
        stmt = select(CategoryModel).where(
            CategoryModel.id == category.parent_id, CategoryModel.is_active == True
        )

        parent_category = (await db.scalars(stmt)).first()

        if parent_category is None:
            raise HTTPException(
                detail="Parent category not found",
                status_code=status.HTTP_404_NOT_FOUND,
            )


# ПРОВЕРКА ТЕКУЩЕЙ КАТЕГОРИИ
async def check_category(category_id: int, db: AsyncSession = Depends(get_async_db)):
    stmt = select(CategoryModel).where(
        CategoryModel.id == category_id, CategoryModel.is_active == True
    )
    category = (await db.scalars(stmt)).first()

    if category is None:
        raise HTTPException(
            detail="Category not found or inactive",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return category


# ПРОВЕРКА ПРОДУКТА И КАТЕГОРИИ
async def check_product_and_category(
    product_id: int,
    new_product: ProductCreate,
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(ProductModel).where(
        ProductModel.id == product_id, ProductModel.is_active.is_(True)
    )
    product = (await db.scalars(stmt)).first()

    if product is None:
        raise HTTPException(
            detail="Product not found or inactive",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    stmt = select(ProductModel).where(
        ProductModel.category_id == new_product.category_id,
        ProductModel.is_active.is_(True),
    )
    category = (await db.scalars(stmt)).first()

    if category is None:
        raise HTTPException(
            detail="Category not found or inactive",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return product


# ПРОВЕРКА ПРОДУКТА
async def check_product(
    product_id: int,
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(ProductModel).where(
        ProductModel.id == product_id,
        ProductModel.is_active.is_(True),
    )
    product = (await db.scalars(stmt)).first()

    if product is None:
        raise HTTPException(
            detail="Product not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return product
