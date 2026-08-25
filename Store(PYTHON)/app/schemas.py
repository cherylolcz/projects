from pydantic import BaseModel, Field, EmailStr, ConfigDict
from typing import List

from decimal import Decimal
from datetime import datetime


# СХЕМЫ ДЛЯ КАТЕГОРИЙ
class CategoryBase(BaseModel):
    name: str = Field(
        min_length=3,
        max_length=50,
    )
    parent_id: int | None = Field(
        default=None,
    )


class CategoryCreate(CategoryBase):
    pass


class CategoryRead(CategoryBase):
    id: int = Field()
    is_active: bool = Field(
        default=True,
    )

    model_config = ConfigDict(from_attributes=True)


# СХЕМЫ ДЛЯ ПРОДУКТОВ
class ProductPagination(BaseModel):
    products: List[ProductRead] = Field()
    total: int = Field()
    page: int = Field()
    page_size: int = Field()


class ProductBase(BaseModel):
    category_id: int = Field()
    name: str = Field(
        min_length=3,
        max_length=100,
    )
    description: str | None = Field(
        default=None,
        max_length=500,
    )
    price: Decimal = Field(
        gt=0,
        decimal_places=2,
    )
    image_url: str | None = Field(
        default=None,
        max_length=200,
    )
    stock: int = Field(
        ge=0,
    )
    rating: float = Field(
        default=0.0,
    )


class ProductCreate(ProductBase):
    pass


class ProductRead(ProductBase):
    id: int = Field()
    is_active: bool = Field(
        default=True,
    )

    model_config = ConfigDict(from_attributes=True)


# СХЕМЫ ДЛЯ ОТЗЫВОВ
class ReviewBase(BaseModel):
    comment: str | None = Field(
        max_length=500,
    )
    grade: int = Field(
        ge=1,
        le=5,
    )


class ReviewCreate(ReviewBase):
    product_id: int = Field()


class ReviewRead(ReviewBase):
    id: int = Field()
    comment_date: datetime = Field()
    is_active: bool = Field(
        default=True,
    )


# PYDANTIC МОДЕЛЬ ДЛЯ ОБНОВЛЕНИЯ REFRESH И ACCESS ТОКЕНА
class RefreshTokenRequest(BaseModel):
    refresh_token: str


class AccessTokenRequest(BaseModel):
    access_token: str


# PYDANTIC МОДЕЛИ ДЛЯ ПОЛЬЗОВАТЕЛЕЙ
class UserBase(BaseModel):
    email: EmailStr = Field(description="Email пользователя")
    role: str = Field(
        default="buyer",
        pattern="^(buyer|seller)$",
        description="Роль: 'buyer' или 'seller'",
    )


class UserCreate(UserBase):
    password: str = Field(
        min_length=8,
        description="Пароль (минимум 8 символов)",
    )


class UserRead(UserBase):
    id: int = Field(
        description="Уникальный идентификатор пользователя",
    )
    is_active: bool = Field(
        default=True,
        description="Активность пользователя",
    )

    model_config = ConfigDict(from_attributes=True)
