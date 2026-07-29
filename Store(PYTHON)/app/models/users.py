from app.database import Base

from sqlalchemy import Integer, String, Boolean
from sqlalchemy.orm import relationship, Mapped, mapped_column

from typing import List


class User(Base):
    __tablename__ = "users"

    id: Mapped[int] = mapped_column(Integer, primary_key=True)
    email: Mapped[str] = mapped_column(
        String,
        nullable=False,
        unique=True,
        index=True,
    )
    hashed_password: Mapped[str] = mapped_column(
        String,
        nullable=False,
    )
    is_active: Mapped[bool] = mapped_column(
        Boolean,
        default=True,
        nullable=False,
    )
    role: Mapped[str] = mapped_column(
        default="buyer",
        nullable=False,
    )

    products: Mapped[List["Product"]] = relationship(
        "Product",
        back_populates="seller",
    )
    reviews: Mapped[List["Review"]] = relationship("Review", back_populates="users")
