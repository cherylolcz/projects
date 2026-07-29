from fastapi import APIRouter, status, Depends

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select, update

from app.db_depends import get_async_db

from app.schemas import CategoryCreate, Category as CategorySchema
from app.models.categories import Category as CategoryModel

from typing import List

from .routers_depends import (
    check_parent_category,
    check_category,
)

router = APIRouter(
    prefix="/categories",
    tags=["categories"],
)


@router.get("/", status_code=status.HTTP_200_OK, response_model=List[CategorySchema])
async def get_categories(db: AsyncSession = Depends(get_async_db)):
    stmt = select(CategoryModel).where(CategoryModel.is_active == True)
    categories = (await db.scalars(stmt)).all()

    return categories


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=CategorySchema)
async def create_category(
    category: CategoryCreate,
    _: None = Depends(check_parent_category),
    db: AsyncSession = Depends(get_async_db),
):

    db_category = CategoryModel(**category.model_dump())

    db.add(db_category)
    await db.commit()

    return db_category


@router.put(
    "/{category_id}", status_code=status.HTTP_200_OK, response_model=CategorySchema
)
async def update_category(
    category_id: int,
    category: CategoryCreate,
    cur_category: CategoryModel = Depends(check_category),
    _: None = Depends(check_parent_category),
    db: AsyncSession = Depends(get_async_db),
):

    await db.execute(
        update(CategoryModel)
        .where(CategoryModel.id == category_id, CategoryModel.is_active == True)
        .values(**category.model_dump())
    )
    await db.commit()

    return cur_category


@router.delete("/{category_id}", status_code=status.HTTP_200_OK)
async def delete_category(
    category_id: int,
    _: CategoryModel = Depends(check_category),
    db: AsyncSession = Depends(get_async_db),
):
    await db.execute(
        update(CategoryModel)
        .where(CategoryModel.id == category_id)
        .values(is_active=False)
    )
    await db.commit()

    return {"status": "success", "message": "Category marked as inactive"}
