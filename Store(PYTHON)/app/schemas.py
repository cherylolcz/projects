from pydantic import BaseModel, Field, ConfigDict, EmailStr

from decimal import Decimal
from datetime import datetime


# PYDANTIC МОДЕЛЬ ДЛЯ ОТЗЫВОВ
class ReviewBase(BaseModel):
    comment: str | None = Field(
        default=None,
        max_length=500,
    )
    grade: int = Field(
        le=5,
        ge=1,
    )


class ReviewCreate(ReviewBase):
    product_id: int = Field(..., description="ID товара, к которому пишется отзыв")


class Review(ReviewBase):
    id: int = Field(..., description="Уникальный идентификатор отзыва.")
    is_active: bool = Field(
        default=True,
    )
    comment_date: datetime = Field(
        default_factory=datetime.now,
    )

    model_config = ConfigDict(from_attributes=True)


# PYDANTIC МОДЕЛЬ ДЛЯ ОБНОВЛЕНИЯ REFRESH И ACCSES ТОКЕНА
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


class User(UserBase):
    id: int = Field(
        description="Уникальный идентификатор пользователя",
    )
    is_active: bool = Field(
        default=True,
        description="Активность пользователя",
    )

    model_config = ConfigDict(from_attributes=True)


# PYDANTIC МОДЕЛИ ДЛЯ КАТЕГОРИИ
class CategoryBase(BaseModel):
    name: str = Field(
        min_length=3,
        max_length=50,
        description="Название категории",
    )
    parent_id: int | None = Field(
        default=None,
        description="ID родительской категории",
    )


class CategoryCreate(CategoryBase):
    pass


class Category(CategoryBase):
    id: int = Field(
        description="Уникальный идентификатор категории",
    )
    is_active: bool = Field(
        default=True,
        description="Активность категории",
    )

    model_config = ConfigDict(from_attributes=True)


# PYDANTIC МОДЕЛИ ДЛЯ ПРОДУКТОВ
class ProductList(BaseModel):
    """
    Список пагинации для товаров.
    """
    items: list[Product] = Field(description="Товары для текущей страницы")
    total: int = Field(description="Общее количество товаров")
    page: int = Field(description="Номер текущей страницы")
    page_size: int = Field(description="Размер текущей страницы")

    model_config = ConfigDict(from_attributes=True)


class ProductBase(BaseModel):
    name: str = Field(
        ...,
        min_length=3,
        max_length=100,
        description="Название товара",
    )
    description: str | None = Field(
        default=None,
        max_length=500,
        description="Описание товара",
    )
    price: Decimal = Field(
        ...,
        gt=0,
        decimal_places=2,
        description="Цена товара",
    )
    image_url: str | None = Field(
        default=None,
        max_length=200,
        description="URL изображения товара",
    )
    stock: int = Field(
        ...,
        ge=0,
        description="Количество товара на складе",
    )
    category_id: int = Field(
        ...,
        description="ID категории",
    )
    rating: Decimal = Field(
        ...,
        description="Средний рейтинг товара"
    )


class ProductCreate(ProductBase):
    pass


class Product(ProductBase):
    id: int = Field(
        ...,
        description="Уникальный идентификатор товара",
    )
    is_active: bool = Field(
        default=True,
        description="Активность товара",
    )

    model_config = ConfigDict(from_attributes=True)
