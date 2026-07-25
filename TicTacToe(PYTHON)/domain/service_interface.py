from abc import ABC, abstractmethod
from typing import Optional, List
from domain.model import Model


class ServiceInterface(ABC):

    @abstractmethod
    def save_game(self, model: Model):
        """Сохранение данных об игре"""
        pass

    @abstractmethod
    def get_game(self, game_id: str) -> Model:
        """Получение данных об игре"""
        pass

    @abstractmethod
    def create_game(self) -> Model:
        pass

    @abstractmethod
    def process_player_move(self, model: Model, row: int, col: int) -> Model:
        """Получение следующего хода текущей игры алгоритмом Минимакс"""
        pass

    @abstractmethod
    def validate_board(self, model: Model) -> None:
        """Проверка, что игровое поле корректно и предыдущие ходы не изменены"""
        pass

    @abstractmethod
    def is_game_over(self, model: Model) -> bool:
        """Проверка окончания игры"""
        pass
