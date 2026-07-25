from domain.model import Model
from datasource.ds_model import DataSourceEntity
from uuid import UUID


class DSMapper:
    @staticmethod
    def to_entity(model: Model):
        return DataSourceEntity(
            game_id=str(model.game_id),
            current_player=model.current_player,
            board=model.board.copy(),
            is_game_over=model.is_game_over,
            winner=model.winner,
        )

    @staticmethod
    def to_model(entity: DataSourceEntity):
        model = Model()

        model.game_id = UUID(entity.game_id)
        model.current_player = entity.current_player
        model.board = entity.board.copy()
        model.is_game_over = entity.is_game_over
        model.winner = entity.winner

        return model
