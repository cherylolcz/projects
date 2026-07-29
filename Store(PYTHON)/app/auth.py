from fastapi.security import OAuth2PasswordBearer
from fastapi import Depends, HTTPException, status

from passlib.context import CryptContext
import jwt

from datetime import datetime, timedelta, timezone
from app.config import SECRET_KEY, ALGORITHM

from app.db_depends import get_async_db
from app.models.users import User as UserModel

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select

from typing import Dict

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="users/token")

ACCESS_TOKEN_EXPIRE_MINUTES = 1
REFRESH_TOKEN_EXPIRE_DAYS = 7


def hash_password(password: str) -> str:
    return pwd_context.hash(password)


def verify_password(plain_password: str, hashed_password: str) -> bool:
    return pwd_context.verify(plain_password, hashed_password)


def create_access_token(data: Dict):
    to_encode = data.copy()
    time_to_expire = datetime.now(timezone.utc) + timedelta(
        minutes=ACCESS_TOKEN_EXPIRE_MINUTES
    )
    to_encode.update(
        {
            "exp": time_to_expire,
            "token_type": "access",
        }
    )

    return jwt.encode(to_encode, SECRET_KEY, ALGORITHM)


def create_refresh_token(data: Dict):
    to_encode = data.copy()
    time_to_expire = datetime.now(timezone.utc) + timedelta(
        days=REFRESH_TOKEN_EXPIRE_DAYS
    )
    to_encode.update(
        {
            "exp": time_to_expire,
            "token_type": "refresh",
        }
    )
    return jwt.encode(to_encode, SECRET_KEY, ALGORITHM)


async def get_current_user(
    token: str = Depends(oauth2_scheme),
    db: AsyncSession = Depends(get_async_db),
) -> UserModel:
    credentials_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Couldn't validate credentials",
        headers={"WWW-Authenticate": "Bearer"},
    )

    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        email: str | None = payload.get("sub")
        token_type: str | None = payload.get("token_type")
        if email is None or token_type != "access":
            raise credentials_exception
    except jwt.ExpiredSignatureError:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Token has expired",
            headers={"WWW-Authenticate": "Bearer"},
        )
    except jwt.PyJWTError:
        raise credentials_exception

    stmt = select(UserModel).where(
        UserModel.email == email,
        UserModel.is_active.is_(True),
    )
    cur_user = (await db.scalars(stmt)).first()
    if cur_user is None:
        raise credentials_exception

    return cur_user


async def get_current_seller(current_user: UserModel = Depends(get_current_user)):
    if current_user.role != "seller":
        raise HTTPException(
            status_code=status.HTTP_403_FORBIDDEN,
            detail="Only sellers can perform this action",
        )

    return current_user


async def get_current_buyer(current_user: UserModel = Depends(get_current_user)):
    if current_user.role != "buyer":
        raise HTTPException(
            status_code=status.HTTP_403_FORBIDDEN,
            detail="Only buyers can perform this action",
        )

    return current_user
