from app.db_depends import get_db

from app.models.categories import Category as CategoryModel
from app.schemas import CategoryCreate

from fastapi import HTTPException, status, Depends

from sqlalchemy import select
from sqlalchemy.orm import Session


# ПРОВЕРКА РОДИТЕЛЬСКОЙ КАТЕГОРИИ
def check_parent_category(category: CategoryCreate, db: Session = Depends(get_db)):
    if category.parent_id is not None:
        stmt = select(CategoryModel).where(
            CategoryModel.id == category.parent_id, CategoryModel.is_active == True
        )

        parent_category = db.scalars(stmt).first()

        if parent_category is None:
            raise HTTPException(
                detail="Parent category not found",
                status_code=status.HTTP_404_NOT_FOUND,
            )


# ПРОВЕРКА ТЕКУЩЕЙ КАТЕГОРИИ
def check_category(category_id: int, db: Session = Depends(get_db)):
    stmt = select(CategoryModel).where(
        CategoryModel.id == category_id, CategoryModel.is_active == True
    )
    category = db.scalars(stmt).first()

    if category is None:
        raise HTTPException(
            detail="Category not found or inactive",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return category
