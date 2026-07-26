from fastapi import APIRouter, status, Depends, HTTPException

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select, update

from app.db_depends import get_async_db

from app.schemas import ReviewCreate, Review as ReviewSchema
from app.models.reviews import Review as ReviewModel

from typing import List


router = APIRouter(
    prefix="reviews",
    tags=["reviews"],
)


@router.get("/", response_model=List[ReviewSchema])
async def get_all_reviews(
    db: AsyncSession = Depends(get_async_db)
):
    stmt = select(ReviewModel).where(ReviewModel.is_active.is_(True))
    reviews = (await db.scalars(stmt)).all()

    if reviews is None:
        raise HTTPException(
            detail="Reviews not found",
            status_code=status.HTTP_404_NOT_FOUND,
        )
    
    return reviews