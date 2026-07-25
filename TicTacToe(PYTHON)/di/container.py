from datasource.ds_storage import Storage
from datasource.ds_mapper import DSMapper
from datasource.ds_repository_impl import RepositoryIMPL
from datasource.service_impl import ServiceIMPL


class Container:

    def __init__(self):
        self._container = {}

    def get_storage(self):
        if "storage" not in self._container:
            self._container["storage"] = Storage()
        return self._container["storage"]

    def get_ds_mapper(self):
        if "ds_mapper" not in self._container:
            self._container["ds_mapper"] = DSMapper()
        return self._container["ds_mapper"]

    def get_repository(self):
        if "repository" not in self._container:
            self._container["repository"] = RepositoryIMPL(
                self.get_ds_mapper(), self.get_storage()
            )
        return self._container["repository"]

    def get_service(self):
        if "service" not in self._container:
            self._container["service"] = ServiceIMPL(self.get_repository())
        return self._container["service"]
