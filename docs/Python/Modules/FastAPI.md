# FastAPI

Variables values can be taken from the route or from **query parameters** following a question mark.

=== "Routes"

    ```python
    from fastapi import FastAPI

    starships = FastAPI()

    @starships.get("/starships/{registry}")
    def get_starship(name: str):
        return {"response": f"Hello, {name}"}
    ```

=== "Query parameters"

    ```python
    from fastapi import FastAPI

    starships = FastAPI()

    @starships.get("/")
    def get_starship(name: str = "world"):
        return {"response": f"Hello, {name}"}
    ```

FastAPI is notable for being able to use type hints to construct data models, which are much lighter than the object relational models used by other frameworks.

=== "FastAPI"

    ```python
    from pydantic import BaseModel

    class Starship(BaseModel):
        name : str
        registry : str
        crew : int
    ```

=== "Django"

    ```python
    from django.db import models

    class Starship(models.Model):
        name = models.CharField(max_length=50)
        registry = models.CharField(max_length=15)
        crew = models.IntegerField()
    ```

Dogfood data can be incorporated by using the **keyword argument unpacking** or "double splat" operator (**`**`**)

```python
data = {"name": "USS Enterprise", "registry" : "NCC-1701", "crew" : 203}
enterprise = Starship(**data)
```

POST method definitions then can use this newly defined class to validate posted data

```python
db = []

@app.post("/starships")
async def create_starship(starship : Starship):
    db.append(starship)
```

FastAPI supports Jinja templates to serve HTML templates
```python
import fastapi
from fastapi.templating import Jinja2Templates

# specifies the directory where templates are to be found
templates = Jinja2Templates("templates") 

api = fastapi.APIRouter()

@api.get('/')
def index(request: starlette.requests.Request):
    return templates.TemplateResponse("helloworld.html", {"request" : request})
```


By default, FastAPI also exposes web applications at /docs where you can test out all the exposed API methods.

FastAPI integrates with [ASGI servers](https://github.com/florimondmanca/awesome-asgi#servers) like Uvicorn and Hypercorn, which can run a specific web application by name from the command-line or from within the script:

=== "Shell"

    ```sh
    uvicorn main:starships --port 7000
    ```

=== "Python"

    ```python
    import uvicorn

    uvicorn.run(starships, port=7000)
    ```
