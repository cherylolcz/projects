from sqlalchemy.orm import Mapped, mapped_column, relationship
from sqlalchemy import String, Boolean, Integer, ForeignKey, Numeric

from app.database import Base

from decimal import Decimal
from typing import List


class Product(Base):
    __tablename__ = "products"

    id: Mapped[int] = mapped_column(
        Integer,
        primary_key=True,
    )
    category_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("categories.id"),
        nullable=False,
    )
    user_id: Mapped[int] = mapped_column(
        Integer,
        ForeignKey("users.id"),
        nullable=False,
    )
    name: Mapped[str] = mapped_column(
        String(100),
        nullable=False,
    )
    description: Mapped[str] = mapped_column(
        String(500),
        nullable=False,
    )
    price: Mapped[Decimal] = mapped_column(
        Numeric(10, 2),
        nullable=False,
    )
    image_url: Mapped[str | None] = mapped_column(
        String(200),
        default=None,
    )
    stock: Mapped[int] = mapped_column(
        Integer,
        nullable=False,
    )
    rating: Mapped[float] = mapped_column(
        Numeric(3, 2),
        default=0.0,
        nullable=False,
    )
    is_active: Mapped[bool] = mapped_column(
        Boolean,
        default=True,
    )

    category: Mapped["Category"] = relationship("Category", back_populates="product")

    reviews: Mapped[List["Review"]] = relationship("Review", back_populates="product")

    user: Mapped["User"] = relationship("User", back_populates="products")
