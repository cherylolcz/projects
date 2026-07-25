from threading import Lock
from datasource.ds_model import DataSourceEntity


class Storage:
    def __init__(self):
        self._lock = Lock()
        self._game_info = dict()

    def save(self, entity: DataSourceEntity):
        with self._lock:
            self._game_info[entity.game_id] = entity

    def get(self, game_id: str):
        with self._lock:
            return self._game_info[game_id]
