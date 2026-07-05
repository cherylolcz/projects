from fastapi import APIRouter, status, Depends

from sqlalchemy.orm import Session
from sqlalchemy import select, update

from app.db_depends import get_db

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
async def get_categories(db: Session = Depends(get_db)):
    stmt = select(CategoryModel).where(CategoryModel.is_active == True)
    categories = db.scalars(stmt).all()

    return categories


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=CategorySchema)
async def create_category(
    category: CategoryCreate,
    db: Session = Depends(get_db),
    _: None = Depends(check_parent_category),
):

    db_category = CategoryModel(**category.model_dump())

    db.add(db_category)
    db.commit()
    db.refresh(db_category)

    return db_category


@router.put("/{category_id}", status_code=status.HTTP_200_OK)
async def update_category(
    category_id: int,
    category: CategoryCreate,
    db: Session = Depends(get_db),
    cur_category: CategoryModel = Depends(check_category),
    _: None = Depends(check_parent_category),
):

    db.execute(
        update(CategoryModel)
        .where(CategoryModel.id == category_id, CategoryModel.is_active == True)
        .values(**category.model_dump())
    )
    db.commit()
    db.refresh(cur_category)

    return cur_category


@router.delete("/{category_id}", status_code=status.HTTP_200_OK)
async def delete_category(
    category_id: int,
    db: Session = Depends(get_db),
    cur_category: CategoryModel = Depends(check_category),
):
    db.execute(
        update(CategoryModel)
        .where(CategoryModel.id == category_id)
        .values(is_active=False)
    )
    db.commit()

    return {"status": "success", "message": "Category marked as inactive"}
