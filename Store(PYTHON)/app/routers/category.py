from fastapi import APIRouter, HTTPException, status, Depends

from app.schemas import CategoryRead, CategoryCreate
from app.models import Category

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from typing import List

from app.depends.db import get_db
from app.depends.router import check_parent_category

router = APIRouter(
    prefix="/category",
    tags=["category"],
)


@router.get("/", response_model=List[CategoryRead])
async def get_category(db: AsyncSession = Depends(get_db)):
    stmt = select(Category).where(Category.is_active.is_(True))
    res = (await db.scalars(stmt)).all()

    return res


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=CategoryRead)
async def create_category(
    new_category: CategoryCreate,
    _: None = Depends(check_parent_category),
    db: AsyncSession = Depends(get_db),
):
    new_category_model = Category(**new_category.model_dump())

    db.add(new_category_model)
    await db.commit()

    return new_category_model


@router.put("/{category_id}", response_model=CategoryRead)
async def change_category(
    category_id: int,
    new_category: CategoryCreate,
    _: None = Depends(check_parent_category),
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

    for key, value in new_category.model_dump().items():
        setattr(res, key, value)

    await db.commit()
    await db.refresh(res)

    return res


@router.delete("/{category_id}")
async def delete_category(
    category_id: int,
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

    setattr(res, "is_active", False)

    await db.commit()
    await db.refresh(res)

    return {"status": "success", "message": "category marked as inactive"}
