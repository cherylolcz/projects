from pydantic import BaseModel, Field, ConfigDict

from decimal import Decimal


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
