from dataclasses import dataclass
from typing import List, Optional


@dataclass
class DataSourceEntity:
    game_id: str
    current_player: str
    board: List[List[int]]
    is_game_over: bool
    winner: int
