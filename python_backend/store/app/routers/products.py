from fastapi import APIRouter, status, Depends, HTTPException

from app.schemas import ProductCreate, Product as ProductSchema
from app.models.products import Product as ProductModel
from app.models.categories import Category as CategoryModel

from app.db_depends import get_db

from sqlalchemy.orm import Session
from sqlalchemy import select, update

from typing import List

from .routers_depends import (
    check_category,
)

router = APIRouter(
    prefix="/products",
    tags=["products"],
)


@router.get("/", status_code=status.HTTP_200_OK, response_model=List[ProductSchema])
async def get_products(db: Session = Depends(get_db)):
    stmt = select(ProductModel).where(ProductModel.is_active == True)
    all_products = db.scalars(stmt).all()

    return all_products


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=ProductSchema)
async def create_product(
    product: ProductCreate,
    db: Session = Depends(get_db),
):

    stmt = select(CategoryModel).where(
        CategoryModel.id == product.category_id, CategoryModel.is_active == True
    )
    category = db.scalars(stmt).first()

    if category is None:
        raise HTTPException(
            detail="Category not found or inactive",
            status_code=status.HTTP_400_BAD_REQUEST,
        )

    cur_product = ProductModel(
        **product.model_dump(),
    )

    db.add(cur_product)
    db.commit()
    db.refresh(cur_product)

    return cur_product


@router.get("/category/{category_id}", status_code=status.HTTP_200_OK, response_model=List[ProductSchema])
async def get_product_by_category(
    category_id: int,
    db: Session = Depends(get_db),
    cur_category: CategoryModel = Depends(check_category),
):
    
    stmt = select(ProductModel).where(ProductModel.category_id == cur_category.id, ProductModel.is_active == True)
    product_by_category = db.scalars(stmt).all()

    return product_by_category
    


@router.put("/{product_id}", status_code=status.HTTP_200_OK)
async def update_product(product_id: int):
    return {"message": "ЗАГЛУШКА"}


@router.delete("/{product_id}", status_code=status.HTTP_200_OK)
async def delete_category(product_id: int):
    return {"message": "ЗАГЛУШКА"}
