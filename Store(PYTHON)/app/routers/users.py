from fastapi import APIRouter, status, HTTPException, Depends
from fastapi.security import OAuth2PasswordRequestForm

from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy import select

from app.schemas import UserCreate, User as UserSchema
from app.models.users import User as UserModel

from app.db_depends import get_async_db

from app.auth import hash_password, verify_password, create_access_token

router = APIRouter(
    prefix='/users',
    tags=['users'],
)

@router.post('/', status_code=status.HTTP_201_CREATED, response_model=UserSchema)
async def create_user(
    new_user: UserCreate,
    db: AsyncSession = Depends(get_async_db)
):
    stmt = select(UserModel).where(
        UserModel.email == new_user.email,
        UserModel.is_active.is_(True),
    )
    user = (await db.scalars(stmt)).first()

    if user is not None:
        raise HTTPException(
            detail='Email already registered',
            status_code=status.HTTP_409_CONFLICT,
        )

    new_user_model = UserModel(
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
    db: AsyncSession = Depends(get_async_db),
):
    stmt = select(UserModel).where(
        UserModel.email == form_data.username,
        UserModel.is_active.is_(True),
    )
    user = (await db.scalars(stmt)).first()

    if not user or not verify_password(form_data.password, user.hashed_password):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail='Incorrect email or password',
            headers={'WWW-Authenticate': 'Bearer'},
        )
    access_token = create_access_token(data={"sub": user.email, "role": user.role, "id": user.id})
    return {"access_token": access_token, "token_type": "bearer"}