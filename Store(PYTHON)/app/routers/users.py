import jwt
from app.config import settings

from fastapi import APIRouter, status, HTTPException, Depends
from fastapi.security import OAuth2PasswordRequestForm

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select

from app.schemas import UserCreate, UserRead, RefreshTokenRequest
from app.models.users import User

from app.depends.db import get_db

from app.auth import (
    hash_password,
    verify_password,
    create_access_token,
    create_refresh_token,
)

router = APIRouter(
    prefix="/users",
    tags=["users"],
)


@router.post("/access-token")
async def access_token(
    body: RefreshTokenRequest,
    db: AsyncSession = Depends(get_db),
):
    credential_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Could not validate refresh token",
        headers={"WWW-Authenticate": "Bearer"},
    )

    refresh_token = body.refresh_token

    try:
        payload = jwt.decode(refresh_token, settings.secret_key, settings.algorithm)
        email: str | None = payload.get("sub")
        token_type: str | None = payload.get("token_type")

        if email is None or token_type != "refresh":
            raise credential_exception

    except jwt.ExpiredSignatureError:
        raise credential_exception
    except jwt.PyJWTError:
        raise credential_exception

    id: int = payload.get("id")
    stmt = select(User).where(User.id == id, User.is_active.is_(True))
    user = (await db.scalars(stmt)).first()

    if user is None:
        raise credential_exception

    new_access_token = create_access_token(
        data={"sub": user.email, "role": user.role, "id": user.id}
    )

    return {
        "access_token": new_access_token,
        "token_type": "bearer",
    }


@router.post("/refresh-token")
async def refresh_token(
    body: RefreshTokenRequest,
    db: AsyncSession = Depends(get_db),
):
    credential_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Could not validate refresh token",
        headers={"WWW-Authenticate": "Bearer"},
    )

    old_refresh_token = body.refresh_token

    try:
        payload = jwt.decode(old_refresh_token, settings.secret_key, settings.algorithm)
        email: str | None = payload.get("sub")
        token_type: str | None = payload.get("token_type")

        if email is None or token_type != "refresh":
            raise credential_exception

    except jwt.ExpiredSignatureError:
        raise credential_exception
    except jwt.PyJWTError:
        raise credential_exception

    stmt = select(User).where(User.email == email, User.is_active.is_(True))
    user = (await db.scalars(stmt)).first()

    if user is None:
        raise credential_exception

    new_refresh_token = create_refresh_token(
        data={"sub": user.email, "role": user.role, "id": user.id}
    )

    return {
        "refresh_token": new_refresh_token,
        "token_type": "bearer",
    }


@router.post("/", status_code=status.HTTP_201_CREATED, response_model=UserRead)
async def create_user(new_user: UserCreate, db: AsyncSession = Depends(get_db)):
    stmt = select(User).where(
        User.email == new_user.email,
        User.is_active.is_(True),
    )
    user = (await db.scalars(stmt)).first()

    if user is not None:
        raise HTTPException(
            detail="Email already registered",
            status_code=status.HTTP_409_CONFLICT,
        )

    new_user_model = User(
        email=new_user.email,
        hashed_password=hash_password(new_user.password),
        role=new_user.role,
    )

    db.add(new_user_model)
    await db.commit()

    return new_user_model


@router.post("/token")
async def login(
    form_data: OAuth2PasswordRequestForm = Depends(),
    db: AsyncSession = Depends(get_db),
):
    stmt = select(User).where(
        User.email == form_data.username,
        User.is_active.is_(True),
    )
    user = (await db.scalars(stmt)).first()

    if not user or not verify_password(form_data.password, user.hashed_password):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Incorrect email or password",
            headers={"WWW-Authenticate": "Bearer"},
        )
    access_token = create_access_token(
        data={"sub": user.email, "role": user.role, "id": user.id}
    )
    refresh_token = create_refresh_token(
        data={"sub": user.email, "role": user.role, "id": user.id}
    )

    return {
        "access_token": access_token,
        "refresh_token": refresh_token,
        "token_type": "bearer",
    }
