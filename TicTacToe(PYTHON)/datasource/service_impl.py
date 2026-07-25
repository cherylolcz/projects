from typing import Optional, List
from domain.service_interface import ServiceInterface
from domain.model import Model
from domain.repository_interface import RepositoryInterface


class ServiceIMPL(ServiceInterface):
    def __init__(self, repository: RepositoryInterface):
        self.repository = repository

    def save_game(self, model: Model):
        self.repository.save(model)

    def get_game(self, game_id: str) -> Model:
        return self.repository.get(game_id)

    def create_game(self) -> Model:
        model = Model()
        self.repository.save(model)

        return model

    def process_player_move(self, model: Model, row: int, col: int) -> Model:
        if model.board[row][col] != 0:
            raise ValueError(f"Клетка уже занята")
        model.board[row][col] = 1
        self.validate_board(model)

        if self.is_game_over(model):
            self.repository.save(model)
            return model

        self.make_move_for_ai(model)
        model.is_game_over = self.is_game_over(model)
        model.winner = model.check_winner()

        self.repository.save(model)
        return model

    def validate_board(self, model: Model) -> None:
        board_values = (1, -1, 0)
        flat_board = [cell for row in model.board for cell in row]

        if len(flat_board) != 9:
            raise ValueError(f"Кол-во ячеек некорректно")

        if abs(flat_board.count(1) - flat_board.count(-1)) > 1:
            raise ValueError("Некорректное количество ходов")

        if not all(cell in board_values for cell in flat_board):
            raise ValueError("Недопустимые значения")

    def is_game_over(self, model: Model) -> bool:
        return model.check_winner() != 0 or model.is_full_board()

    def minimax(self, model: Model, is_maximizing: bool):
        winner = model.check_winner()
        if winner == 1:
            return 1
        elif winner == -1:
            return -1
        elif model.is_full_board():
            return 0

        best_score = -float("inf") if is_maximizing else float("inf")
        for row, col in model.get_available_moves():
            model.board[row][col] = 1 if is_maximizing else -1
            score = self.minimax(model, not is_maximizing)
            model.board[row][col] = 0

            func = max if is_maximizing else min
            best_score = func(best_score, score)
        return best_score

    def best_move_for_ai(self, model: Model):
        best_score = float("inf")
        best_move = None

        for row, col in model.get_available_moves():
            model.board[row][col] = -1
            score = self.minimax(model, True)
            model.board[row][col] = 0

            if score < best_score:
                best_score = score
                best_move = (row, col)

        return best_move

    def make_move_for_ai(self, model: Model):
        row, col = self.best_move_for_ai(model)
        model.board[row][col] = -1
        model.switch_player()

    def set_new_board(self, model: Model, new_board: List[List[int]]):
        model.board = new_board
        self.validate_board(model)
