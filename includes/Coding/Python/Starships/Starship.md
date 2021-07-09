```py
class Starship:
    def __init__(
        self,
        name=None,
        starshipclass: StarshipClass = StarshipClass.NX,
        registry=None,
        crew=0,
    ):
        self.name = name
        self.registry = registry
        self._crew = crew
        self.crew_on_leave = 0
        self._starshipclass = starshipclass

    @property
    def crew(self):
        return self._crew

    @crew.setter
    def crew(self, crew: int):
        if crew < 0:
            raise Exception
        else:
            self._crew = crew

    @property
    def starshipclass(self):
        return self._starshipclass

    @starshipclass.setter
    def starshipclass(self, starshipclass: StarshipClass):
        if starshipclass not in StarshipClass:
            raise Exception
        else:
            self._starshipclass = starshipclass
```