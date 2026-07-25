from datasource.ds_storage import Storage
from datasource.ds_mapper import DSMapper
from domain.model import Model
from domain.repository_interface import RepositoryInterface


class RepositoryIMPL(RepositoryInterface):
    def __init__(self, mapper: DSMapper, storage: Storage):
        self.mapper = mapper
        self.storage = storage

    def save(self, model: Model):
        entity = self.mapper.to_entity(model)
        self.storage.save(entity)

    def get(self, game_id: str):
        entity = self.storage.get(game_id)
        return self.mapper.to_model(entity)
