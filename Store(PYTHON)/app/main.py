from fastapi import FastAPI

from app.routers import category
from app.routers import product
from app.routers import review
from app.routers import users

app = FastAPI(
    version="0.0.1",
    description="Store",
)

app.include_router(category.router)
app.include_router(product.router)
app.include_router(review.router)
app.include_router(users.router)
