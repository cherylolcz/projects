from sqlalchemy.orm import Mapped, mapped_column, relationship
from sqlalchemy import Boolean, Integer, ForeignKey, Text, DateTime

from app.database import Base

from datetime import datetime


class Review(Base):
    __tablename__ = "reviews"

    id: Mapped[int] = mapped_column(
        Integer,
        primary_key=True,
    )
    product_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("products.id"),
        nullable=False,
    )
    user_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("users.id"),
        nullable=False,
    )
    comment: Mapped[str | None] = mapped_column(
        Text,
        nullable=True,
    )
    comment_date: Mapped[datetime] = mapped_column(
        DateTime,
        default=datetime.now,
    )
    grade: Mapped[int] = mapped_column(
        Integer,
        nullable=False,
    )
    is_active: Mapped[bool] = mapped_column(
        Boolean,
        default=True,
    )

    product: Mapped["Product"] = relationship(
        "Product",
        back_populates="reviews",
    )

    user: Mapped["User"] = relationship("User", back_populates="reviews")
