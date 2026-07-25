from web.web_model import WebEntity
from domain.model import Model


class WebMapper:
    @staticmethod
    def to_web(model: Model):
        return WebEntity(
            game_id=str(model.game_id),
            current_player=model.current_player,
            board=model.board.copy(),
            is_game_over=model.is_game_over,
            winner=model.winner,
        )
