from abc import ABC, abstractmethod
from domain.model import Model


class RepositoryInterface(ABC):

    @abstractmethod
    def save(self, model: Model) -> None:
        pass

    @abstractmethod
    def get(self, game_id: str) -> Model:
        pass
