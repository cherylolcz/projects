from fastapi import (
    APIRouter,
    HTTPException,
    status,
    Depends,
)

from app.schemas import ReviewRead, ReviewCreate
from app.models import Product, Review, User

from app.auth import get_current_buyer

from sqlalchemy import select, func
from sqlalchemy.ext.asyncio import AsyncSession

from typing import List

from app.depends.db import get_db
from app.depends.router import check_category

router = APIRouter(
    prefix="/review",
    tags=["review"],
)


@router.get("/", response_model=List[ReviewRead])
async def get_reviews(db: AsyncSession = Depends(get_db)):
    stmt = select(Review).where(Review.is_active.is_(True))
    res = (await db.scalars(stmt)).all()

    return res


@router.get("/{product_id}/review", response_model=List[ReviewRead])
async def get_review(product_id: int, db: AsyncSession = Depends(get_db)):
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

    stmt = select(Review).where(
        Review.product_id == product_id,
        Review.is_active.is_(True),
    )
    res = (await db.scalars(stmt)).all()

    return res


@router.post("/", response_model=ReviewRead)
async def create_review(
    review: ReviewCreate,
    current_user: User = Depends(get_current_buyer),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Product).where(
        Product.id == review.product_id,
        Product.is_active.is_(True),
    )
    product = (await db.scalars(stmt)).first()

    if product is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Product with this id is not exists",
        )

    review_model = Review(
        **review.model_dump(),
        user_id=current_user.id,
    )
    db.add(review_model)
    await db.flush()

    await count_new_rating(product, db)
    await db.commit()

    return review_model


@router.put("/{review_id}", response_model=ReviewRead)
async def create_review(
    new_review: ReviewCreate,
    review_id: int,
    current_user: User = Depends(get_current_buyer),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Product).where(
        Product.id == new_review.product_id,
        Product.is_active.is_(True),
    )
    product = (await db.scalars(stmt)).first()

    if product is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Product with this id is not exists",
        )

    stmt = select(Review).where(Review.id == review_id, Review.is_active.is_(True))
    review = (await db.scalars(stmt)).first()

    if review is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Review with this id is not exists",
        )

    if review.user_id != current_user.id:
        raise HTTPException(
            detail="You can update only your own products",
            status_code=status.HTTP_403_FORBIDDEN,
        )

    for key, value in new_review.model_dump().items():
        setattr(review, key, value)

    await db.flush()

    await count_new_rating(product, db)
    await db.commit()

    return review


@router.delete("/{review_id}")
async def get_reviews(
    review_id: int,
    db: AsyncSession = Depends(get_db),
):
    stmt = select(Review).where(Review.id == review_id, Review.is_active.is_(True))
    review = (await db.scalars(stmt)).first()

    stmt = select(Product).where(review.product_id == Product.id)
    product = (await db.scalars(stmt)).first()

    setattr(review, "is_active", False)
    await db.flush()

    await count_new_rating(product, db)
    await db.commit()

    return {"status": "success", "message": "category marked as inactive"}


async def count_new_rating(product: Product, db: AsyncSession):
    stmt = select(func.avg(Review.grade)).where(
        Review.product_id == product.id, Review.is_active.is_(True)
    )
    new_rating = await db.scalar(stmt)

    product.rating = new_rating if new_rating else 0