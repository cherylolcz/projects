from fastapi import FastAPI
from app.routers import (
    categories,
    products,
    users,
    reviews
    )

app = FastAPI(
    version="0.0.1",
    description="Интернет магазин",
)

app.include_router(categories.router)
app.include_router(products.router)
app.include_router(users.router)
app.include_router(reviews.router)