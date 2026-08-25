from pydantic_settings import BaseSettings, SettingsConfigDict


class Settings(BaseSettings):
    db_user: str
    db_password: str
    db_host: str
    db_port: int
    db_name: str
    db_driver: str = "asyncpg"

    secret_key: str
    algorithm: str = "HS256"

    model_config = SettingsConfigDict(env_file=".env")

    @property
    def database_url(self) -> str:
        return (
            f"postgresql+{self.db_driver}://"
            f"{self.db_user}:{self.db_password}@"
            f"{self.db_host}:{self.db_port}/{self.db_name}"
        )


settings = Settings()
