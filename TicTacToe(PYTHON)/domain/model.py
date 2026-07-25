from tabnanny import check
from uuid import uuid4, UUID
from typing import List, Optional


BOARD_SIZE = 3


class Model:
    players = (1, -1)

    def __init__(self):
        self._board = [[0 for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]
        self._current_player = 1
        self._game_id = uuid4()
        self._is_game_over = False
        self._winner = 0

    @property
    def board(self):
        return self._board

    @property
    def current_player(self):
        return self._current_player

    @property
    def is_game_over(self):
        return self._is_game_over

    @property
    def winner(self):
        return self._winner

    @property
    def game_id(self):
        return self._game_id

    @board.setter
    def board(self, new_value: List[Optional[str]]):
        self._board = new_value

    @current_player.setter
    def current_player(self, new_value: str):
        self._current_player = new_value

    @is_game_over.setter
    def is_game_over(self, new_value):
        self._is_game_over = new_value

    @winner.setter
    def winner(self, new_value):
        self._winner = new_value

    @game_id.setter
    def game_id(self, new_value):
        self._game_id = new_value

    def check_winner(self):
        for i in range(BOARD_SIZE):
            if self._board[i][0] == self._board[i][1] == self._board[i][2] != 0:
                return self._board[i][0]

            if self._board[0][i] == self._board[1][i] == self._board[2][i] != 0:
                return self._board[0][i]

        if self._board[0][0] == self._board[1][1] == self._board[2][2] != 0:
            return self._board[0][0]

        if self._board[0][2] == self._board[1][1] == self._board[2][0] != 0:
            return self._board[0][2]

        return 0

    def is_full_board(self):
        for row in self._board:
            for item in row:
                if item == 0:
                    return False
        return True

    def get_available_moves(self):
        moves = list()
        for row_index, row in enumerate(self._board):
            for col_index, value in enumerate(row):
                if value == 0:
                    moves.append([row_index, col_index])
        return moves

    def switch_player(self):
        current_player_index = Model.players.index(self._current_player)
        self._current_player = Model.players[abs(current_player_index - 1)]
