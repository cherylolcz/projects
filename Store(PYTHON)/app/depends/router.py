from fastapi import HTTPException, status, Depends

from app.depends.db import get_db

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from app.models import Category
from app.schemas import CategoryCreate
from app.schemas import ProductCreate


async def check_parent_category(
    new_category: CategoryCreate,
    db: AsyncSession = Depends(get_db),
):
    if new_category.parent_id is None:
        return

    stmt = select(Category).where(
        Category.id == new_category.parent_id, Category.is_active.is_(True)
    )

    res = (await db.scalars(stmt)).first()

    if res is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Parent category with this id is not exists",
        )


async def check_category(
    product: ProductCreate,
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Category).where(
        Category.id == product.category_id,
        Category.is_active.is_(True),
    )
    res = (await db.scalars(stmt)).first()

    if res is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Category with this id is not exists",
        )
