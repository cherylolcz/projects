from datetime import datetime

from sqlalchemy.orm import relationship, Mapped, mapped_column
from sqlalchemy import ForeignKey, Integer, DateTime, Boolean, Text, CheckConstraint

from app.database import Base


class Review(Base):
    __tablename__ = "reviews"

    id: Mapped[int] = mapped_column(
        Integer,
        primary_key=True,
    )
    user_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("users.id"),
        nullable=False,
    )
    product_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("products.id"),
        nullable=False,
    )
    comment: Mapped[str | None] = mapped_column(
        Text,
    )
    comment_date: Mapped[datetime] = mapped_column(
        DateTime,
        default=datetime.now,
    )
    grade: Mapped[int] = mapped_column(
        CheckConstraint("grade >= 1 AND grade <= 5"),
        nullable=False,
    )
    is_active: Mapped[bool] = mapped_column(
        Boolean,
        default=True,
    )

    users: Mapped["User"] = relationship("User", back_populates="reviews")
    products: Mapped["Product"] = relationship("Product", back_populates="reviews")
