# АСИНХРОННОЕ ПОДКЛЮЧЕНИЕ
from sqlalchemy.ext.asyncio import AsyncSession, create_async_engine, async_sessionmaker
from sqlalchemy.orm import DeclarativeBase

DATABASE_URL = "postgresql+asyncpg://eccomerce_user:0104@localhost:5432/eccomerce_db"
async_engine = create_async_engine(DATABASE_URL, echo=True)

async_session = async_sessionmaker(
    async_engine, expire_on_commit=False, class_=AsyncSession
)


class Base(DeclarativeBase):
    pass
