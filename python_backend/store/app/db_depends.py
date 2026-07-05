from app.database import SessionLocal
from sqlalchemy.orm import Session

from collections.abc import Generator


def get_db() -> Generator[Session, None, None]:
    db: Session = SessionLocal()

    try:
        yield db
    finally:
        db.close()
