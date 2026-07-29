from fastapi import APIRouter, status, Depends, HTTPException

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select, update, func

from app.auth import get_current_buyer
from app.db_depends import get_async_db

from app.schemas import ReviewCreate, Review as ReviewSchema

from app.models.reviews import Review as ReviewModel
from app.models.products import Product as ProductModel
from app.models.users import User as UserModel

from typing import List


router = APIRouter(
    prefix="/reviews",
    tags=["reviews"],
)


@router.get("/", response_model=List[ReviewSchema])
async def get_all_reviews(db: AsyncSession = Depends(get_async_db)):
    stmt = select(ReviewModel).where(ReviewModel.is_active.is_(True))
    reviews = (await db.scalars(stmt)).all()

    if reviews is None:
        raise HTTPException(
            detail="Reviews not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return reviews


@router.get("/{product_id}/reviews", response_model=List[ReviewSchema])
async def get_review(
    product_id: int,
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(ProductModel).where(
        ProductModel.id == product_id,
        ProductModel.is_active.is_(True)
    )
    product = (await db.scalars(stmt)).first()

    if product is None:
        raise HTTPException(
            detail="Product is not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    stmt = select(ReviewModel).where(
        ReviewModel.product_id == product_id,
        ReviewModel.is_active.is_(True)
    )
    reviews = (await db.scalars(stmt)).all()

    if reviews is None:
        raise HTTPException(
            detail="Review is not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    return reviews


async def update_product_rating(
    product_id: int,
    db: AsyncSession,
):
    stmt = (
        select(func.avg(ReviewModel.grade))
        .where(
            ReviewModel.product_id == product_id,
            ReviewModel.is_active.is_(True)
        )
    )
    new_rating = await db.scalar(stmt)

    await db.execute(
        update(ProductModel)
        .where(
            ProductModel.id == product_id,
            ProductModel.is_active.is_(True)
        )
        .values(rating=new_rating)
    )


@router.post("/", response_model=ReviewSchema)
async def create_review(
    review: ReviewCreate,
    current_user: UserModel = Depends(get_current_buyer),
    db: AsyncSession = Depends(get_async_db),
):
    if not 1 <= review.grade <= 5:
        raise HTTPException(
            detail="Not correct grade",
            status_code=status.HTTP_422_UNPROCESSABLE_CONTENT,
        )

    stmt = select(ProductModel).where(
        ProductModel.id == review.product_id,
        ProductModel.is_active.is_(True)
    )
    product = (await db.scalars(stmt)).first()
    if product is None:
        raise HTTPException(
            detail="Product is not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    new_review = ReviewModel(
        **review.model_dump(),
        user_id=current_user.id,
    )

    db.add(new_review)
    await db.flush()

    await update_product_rating(review.product_id, db)

    await db.commit()
    await db.refresh(new_review)

    return new_review


@router.delete("/{review_id}")
async def del_review(
    review_id: int,
    current_buyer: UserModel = Depends(get_current_buyer),
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(ReviewModel).where(
        ReviewModel.id == review_id,
        ReviewModel.is_active.is_(True)
    )
    review = (await db.scalars(stmt)).first()

    if review is None:
        raise HTTPException(
            detail="Review is not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )

    if current_buyer.id != review.user_id:
        raise HTTPException(
            detail="You can delete only your own reviews",
            status_code=status.HTTP_401_UNAUTHORIZED,
        )

    review.is_active = False
    await db.flush()

    await update_product_rating(review.product_id, db)

    await db.commit()

    return {"status": "success", "message": "review marked as inactive"}