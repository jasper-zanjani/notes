# 🐍 Python
## Decorators
Sources:

- [Primer on Python Decorators ](https://realpython.com/primer-on-python-decorators/)
- [YouTube tutorial](https://youtu.be/T8CQwGIsrx4)

> A **decorator** is any function that accepts a function and returns a function.

Decorators are one of the main ways that Python implements **functional programming** principles.

Functions are **first-class objects** and can be passed as parameters.
```py
import logging

def hello_wrapper(name, func):
  func(f'Hello {name}')

hello_wrapper("world", func=print) # Hello world
hello_wrapper("logs", func=logging.warning) # WARNING:root:Hello logs
```
```py
with open('hello.txt', 'w') as f:
  hello_wrapper('everyone!', func=f.write)
```
```py
import random

def anagram(t):
  l = [c for c in t]
  random.shuffle(l)
  print("".join(l))

hello_wrapper('Japushku', anagram) #  eHoulhluaskpJ
```
The function has to be passed as a reference, actually calling it will cause the wrapper function to attempt to execute the value **returned** by the inner function.
```py
hello_wrapper("world", func=print()) # Error
```
```py
def outer():
  print('Hi from the outer function')
  def inner():
    print('Hello from the inner function')
  inner()
```

We can use the **`__name__`** attribute to access a passed function's name.
```py
def hello(func):
  print(f'Hello {func.__name__}')

hello(outer) # Hello outer
```
We can also return functions, which can then be invoked
```py
def hello(func):
  print(f'Hello {func.__name__}')
  return func

hello(outer)()  
'''
Hi from the outer function
Hello from the inner function
'''

new_outer = hello(outer)
new_outer is outer # True
```

```py
def wrapper(func):
  print(f'Before {func.__name__}')
  func()
  print(f'After {func.__name__}')

wrapper(outer)
'''
Before outer
Hi from the outer function
Hello from the inner function
After outer
'''
```
The true decorator pattern appears here, where `wrapper` is called the **decorator** and `outer` has been **decorated**.
```py
def wrapper(func):
  def _wrapper():
    print(f'Before {func.__name__}')
    func()
    print(f'After {func.__name__}')
  return _wrapper

outer = wrapper(outer)
```
But the usual syntax since Python 2.4 is to place the decorator on the line above the decorated function, preceded by `@`:
```py
@wrapper
def outer():
  print('Hi from the outer function')
  def inner():
    print('Hello from the inner function')
  inner()
```
`_wrapper` here does not accept any positional arguments, so wrapping functions that take arguments will produce a `TypeError`
```py
@wrapper
def say_hello(name):
  print(f'Hello {name}!') # error
```
The solution is to incorporate `*args, **kwargs` into the definition of the inner function, as well as the invocation of the function passed in.
```py
def wrapper(func):
  def _wrapper(*args, **kwargs):
    print(f'Before {func.__name__}')
    func(*args, **kwargs)
    print(f'After {func.__name__}')
  return _wrapper
```
Returned values are not captured yet:
```py
def wrapper(func):
  def _wrapper(*args, **kwargs):
    print(f'Before {func.__name__}')
    value = func(*args, **kwargs)
    print(f'After {func.__name__}')
    return value
  return _wrapper
```
Inspecting the decorated function's `__name__` attribute reveals that it is still named `_wrapper`
```py
say_hello.__name__ # '_wrapper'
```
This is also true for other attributes, including docstring. `functools.wraps` is a decorator factory to reassign attributes to the wrapped function. This is considered superior to the `functools.update_wrapper` function which is also available.
```py
def wrapper(func):
  @functools.wraps(func)
  def _wrapper(*args, **kwargs):
    print(f'Before {func.__name__}')
    value = func(*args, **kwargs)
    print(f'After {func.__name__}')
    return value
  return _wrapper
```
This forms an ideal starting template for the creation of custom decorators.

## Classes

### Properties

In the [Python documentation](https://docs.python.org/3/library/functions.html#property), attributes accessed with accessor functions are called **managed attributes**, which makes the term equivalent to **properties** in C#.

Three methods can be defined using the `@property` decorator

=== "Constructor"
    ```python
    def __init__(self, price):
        self._price = price
    ```
=== "Getter"
    ```python
    @property
    def price(self):
      return self._price
    ```
=== "Setter"
    ```python
    @price.setter
    def price(self, new_price):
        if new_price > 0:
            self._price = new_price
        else:
            raise ValueError
    ```
=== "Deleter"
    ```python
    @price.deleter
    def price(self):
        del self._price
    ```


### Class methods

The **`@classmethod`** decorator prevents the interpreter from passing in the instantiated object using `self`, rather the class itself is passed in as the `cls` argument. This means that the methods decorated as such must take not `self` as the first argument but `cls`

```py
@classmethod
def classmethod(cls):
  pass
```

The **`@staticmethod`** decorator prevents the interpreter from passing any additional arguments whatsoever. The resulting method has no access to the object itself nor the class and functions like a procedurally defined function.

## Formatting

`flake8`, `black`, and **`yapf`** (Google) are CLI tools used to automatically format Python code.


## Web frameworks

### Django
A typical Django **project** contains multiple **apps**, which are Python packages containing their own models, views, templates, and urls.

- A [**model**](#models) is the single definitive source of information about your data, and contains the essential fields and behaviors of the data you're storing. 
- **Migrations** are necessary when Model classes are updated. And for projects sufficiently advanced, migration scripts must be developed for any such changes.

- **Async Server Gateway Interface (ASGI)** is the spiritual successor to, and superset of, [**WSGI**](#wsgi). It implements the new Python standard for asynchronous web servers and applications, which resembles that of [websockets](#sockets). :point_right: [From WSGI to ASGI](https://youtu.be/IhF2JwyH664)
- **WSGI** is coupled tightly with the synchronous request-response model familiar from HTTP 1.1.

URL patterns (stored in the `urlpatterns` list defined in the project-level **urls.py** file) can be parameterized. Here, the template `<int:x>` specifies an integer to be assigned to the view parameter `x`.
```py
from app.views import my_view

urlpatterns = [
  path('/example/<int:x>', my_view)
]
```
`modelform_factory` can be used to automatically produce a webform from a Model class.
```py
# views.py

MeetingForm = modelform_factory(Meeting, exclude=[])
```
This can be placed into a template using the `{{ form }}` template tag. Note, a `{% csrf_token %}` template tag must also be present for a submit button to work.
```py
{% block content %}
<h1>Plan a new meeting</h1>
<form method="POST">
  <table>
    {{form}}
  </table>
  {% csrf_token %}
  <button type="submit">Create</button>
</form>
{% endblock content %}
```
When the `modelform_factory` class has been defined, it is instantiated within the **view function**. This object exposes several methods:
- **is_valid** data validation is strongly recommended for any form input
- **save** imports the validated form data into the database
```py
def new(request):
  if request.method == 'POST':
    form = MeetingForm(request.POST)
    if form.is_valid():
      form.save()
      return redirect("home")
  else:
    form = MeetingForm()
  
  return render(request, "meetings/new.html", {"form": form})
```

#### Template

Django **templates** are HTML files with additional markup to signify places where data can be dynamically inserted. The data used by the views file is called the **template context**.

Templates must be placed within the **/templates** folder within the app, and it is considered best practice to place templates within a nested subdirectory within it, e.g. **/templates/app**.

Django **template tags** are specified beween `{% .. %}` and allow for interpolation of data.

```py
<ul>
  {% for m in meetings %}

  {% endfor %}
</ul>
```

URLs can be built by using the `url` template tag, specifying the name of a URL
```py
urlpatterns = [
  path('', home, name='home')
]
```
```py
<a href="{% url 'home' %}">Home</a>
```

#### Models

:point_right: [Models](https://docs.djangoproject.com/en/3.1/topics/db/models/)

In Django, a **Model** class is mapped to a database table. Each object is a record in that table.

Model objects expose several attributes and methods

Get all objects
```py
meetings = Meeting.objects.all()
```
Get count of objects in database
```py
count = Meeting.objects.count()
```
Query for a specific object
```py
meeting = Meeting.objects.get(pk=id)
```
:point_right: [`get_object_or_404`](https://docs.djangoproject.com/en/3.1/topics/http/shortcuts/#get-object-or-404) may be better for most cases
```py
meeting = get_object_or_404(Meeting, pk=id)
```

Adding a new **app**
```sh
python manage.py startapp app
```
Then add to **settings.py** in project directory
```py
INSTALLED_APPS = [
  # ...
  'app',
]
```

There appears to be much flexibility in the arrangement of input controls in a form.

So long as the Submit button is child to the `form` element, tasks are accepted in the To-Do app.

Per Bulma documentation, the `field` class is intended as a container for `label.label`s, `.control`s, and optional `p.help` text. [:point_right:](https://bulma.io/documentation/form/general/#form-field)

In contrast, `control` is a **block** container meant to enhance single form controls and can only contain `input`, `select`, `button`, or `icon` elements. [:point_right:](https://bulma.io/documentation/form/general/#form-control)
```pug
form.field(method="POST", action="/")
	label.label Enter something to do
	.control
		| {{form.title}}
		| {% csrf_token %}
	button.button.is-primary(type="submit") Submit
```

### FastAPI

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



## Virtual environments
### pipenv

```sh
pipenv --python 3.6
```

### venv
Create a virtual environment named `project`
```sh
python -m venv project
```

### virtualenv
Create a virtual environment named `project` using a different version of Python
```sh
virtualenv -p /usr/bin/python2 project
```

## Testing

[Pytest](https://docs.pytest.org/en/stable/) is a popular **testing framework** preferred to [unittest](#unittest) by many Python developers because it follows Pythonic conventions more closely.
In contrast to unittest's custom methods, pytest relies on the builtin [`assert`](https://docs.python.org/3/reference/simple_stmts.html?highlight=assert#the-assert-statement) statement.

=== "pytest"

    ```py
    from phonebook import PhoneBook
    import pytest

    @pytest.fixture
    def phonebook():
        phonebook = PhoneBook()
        yield phonebook
        phonebook.clear()

    def test_lookup_by_name(phonebook):
        phonebook.add("Bob","1234")
        assert "1234" == phonebook.lookup("Bob")

    def test_phonebook_contains_all_names(phonebook):
        phonebook.add("Bob", "1234")
        assert "Bob" in phonebook.names()

    def test_missing_name_raises_error(phonebook):
        with pytest.raises(KeyError):
            phonebook.lookup("Bob")
    ```
    ```sh
    python -m pytest
    ```

=== "unittest"

    ```py
    import unittest

    from phonebook import PhoneBook


    class PhoneBookTest(unittest.TestCase):

        def test_lookup_by_name(self):
            self.phonebook.add("Bob", "12345")
            number = self.phonebook.lookup("Bob")
            self.assertEqual("12345", number)

        def test_missing_name(self):
            with self.assertRaises(KeyError):
                self.phonebook.lookup("missing")

        def test_empty_phonebook_is_consistent(self):
            self.assertTrue(self.phonebook.is_consistent())

        def setUp(self) -> None:
            self.phonebook = PhoneBook()

        def tearDown(self) -> None:
            self.phonebook.clear()
    ```
    ```sh
    python -m unittest
    ```

=== "Class under test"

    ```py
    import os

    class PhoneBook:
        def __init__(self, cache_directory = os.getcwd()):
            self.numbers = {}
            self.filename = os.path.join(cache_directory, "phonebook.txt")
            self.cache = open(self.filename, "w")

        def add(self, name, number):
            self.numbers[name] = number

        def lookup(self, name):
            return self.numbers[name]

        def is_consistent(self):
            return True

        def names(self):
            return set(self.numbers.keys())

        def clear(self):
            self.cache.close()
            os.remove(self.filename )
    ```

### Doctest
A **doctest** is a docstring containing what looks like interactive Python sessions. <sup>[Python Docs](https://docs.python.org/3/library/doctest.html "doctest - Test interactive Python examples")</sup>
```py
"""
Return the factorial of n, an exact integer >= 0.

>>> [factorial(n) for n in range(6)]
[1, 1, 2, 6, 24, 120]
>>> factorial(30)
265252859812191058636308480000000
>>> factorial(-1)
Traceback (most recent call last):
    ...
ValueError: n must be >= 0

Factorials of floats are OK, but the float must be an exact integer:
>>> factorial(30.1)
Traceback (most recent call last):
    ...
ValueError: n must be exact integer
>>> factorial(30.0)
265252859812191058636308480000000

It must also not be ridiculously large:
>>> factorial(1e100)
Traceback (most recent call last):
    ...
OverflowError: n too large
"""
```
This can then be run 
```py
if __name__ == '__main__':
  import doctest
  doctest.testmod()
```

### pytest

**PyTest** relies on the built-in `assert` statement.

#### Fixtures

The **`@pytest.fixture`** decorator facilitiates the creation of test fixtures.
The fixture function's name is used as argument to the test case, and the value returned can be used by the logic within. 
([src](https://app.pluralsight.com/course-player?clipId=6d87a3a0-2869-419b-ac1d-abbd9b076c98))

Any clean-up logic can be invoked in this fixture as well by replacing `return` with `yield`.
Pytest also provides its own **`tmpdir`** test fixture for temporary directories. ([src](https://app.pluralsight.com/course-player?clipId=8a53dec3-dabb-4b5a-9a6f-0bfb696db0da))

=== "Before"

    ```py
    from phonebook import PhoneBook
    import pytest







    def test_lookup_by_name(phonebook):
        phonebook=PhoneBook()
        phonebook.add("Bob","1234")
        assert "1234" == phonebook.lookup("Bob")

    def test_phonebook_contains_all_names(phonebook):
        phonebook = PhoneBook()
        phonebook.add("Bob", "1234")
        assert "Bob" in phonebook.names()

    def test_missing_name_raises_error(phonebook):
        phonebook = PhoneBook()
        with pytest.raises(KeyError):
            phonebook.lookup("Bob")
    ```


=== "After"

    ```py
    from phonebook import PhoneBook
    import pytest

    @pytest.fixture
    def phonebook():
        phonebook = PhoneBook()
        yield phonebook
        phonebook.clear()

    def test_lookup_by_name(phonebook):
        # phonebook = PhoneBook()
        phonebook.add("Bob","1234")
        assert "1234" == phonebook.lookup("Bob")

    def test_phonebook_contains_all_names(phonebook):
        # phonebook = PhoneBook()
        phonebook.add("Bob", "1234")
        assert "Bob" in phonebook.names()

    def test_missing_name_raises_error(phonebook):
        # phonebook = PhoneBook()
        with pytest.raises(KeyError):
            phonebook.lookup("Bob")
    ```

=== "tmpdir"

    ```py
    from phonebook import PhoneBook
    import pytest

    @pytest.fixture
    def phonebook(tmpdir):
        phonebook = PhoneBook(tmpdir)
        return phonebook


    def test_lookup_by_name(phonebook):
        # phonebook = PhoneBook()
        phonebook.add("Bob","1234")
        assert "1234" == phonebook.lookup("Bob")

    def test_phonebook_contains_all_names(phonebook):
        # phonebook = PhoneBook()
        phonebook.add("Bob", "1234")
        assert "Bob" in phonebook.names()

    def test_missing_name_raises_error(phonebook):
        # phonebook = PhoneBook()
        with pytest.raises(KeyError):
            phonebook.lookup("Bob")
    ```

### [unittest](https://docs.python.org/3.8/library/unittest.html)

**unittest** is a testing framework built into Python's Standard Library that was based on JUnit. 
unittest came out in 2001, when JUnit was being ported and adapted to many languages.
Collectively, these frameworks were referred to as the **xUnit family**.
unittest's method names do not follow Python conventions because it predates the PEP-8 naming standard.

unittest allows you to create test classes that inherit from **`TestCase`**.

#### Assertions

Assertions are implemented in individual methods of the TestCase subclass through unittest methods like `assertEqual` and `assertRaises`, etc.
Notably, TestCase subclasses must **not** have an `__init__()` constructor method defined.

```py
def test_lookup_by_name(self):
    phonebook = PhoneBook()
    phonebook.add("Bob", "12345")
    number = phonebook.lookup("Bob")
    self.assertEqual("12345", number)
```

**`assertRaises`** must be placed in a context manager.
Here, the test case will run the code within the `with` block and check to make sure it raises the specified exception: `KeyError`: ([src](https://app.pluralsight.com/course-player?clipId=fa55af11-913d-4171-a2b0-db9f75f249e1))

```py
def test_missing_name(self):
    fleet = Fleet()
    with self.assertRaises(KeyError):
        fleet.lookup("bla")
```

#### Fixtures

**`setUp`** is run before every test method, allowing a **test fixture** to be created to avoid repetitive code.
**`tearDown`** is called after every method, which allows these resources to be released, even if the test case raises an exception. However, if it is `setUp` that raises the exception, then neither the test case nor `tearDown` will run. ([src](https://app.pluralsight.com/course-player?clipId=efd71803-d18f-4860-baca-d94bf935765a), [src](https://app.pluralsight.com/course-player?clipId=efd71803-d18f-4860-baca-d94bf935765a))

=== "Before"

    ```py
    import unittest

    from phonebook import PhoneBook


    class PhoneBookTest(unittest.TestCase):






        def test_lookup_by_name(self):
            phonebook = PhoneBook()
            phonebook.add("Bob", "12345")
            number = phonebook.lookup("Bob")
            self.assertEqual("12345", number)

        def test_missing_name(self):
            phonebook = PhoneBook()
            with self.assertRaises(KeyError):
                phonebook.lookup("missing")

        @unittest.skip("WIP")
        def test_empty_phonebook_is_consistent(self):
            phonebook = PhoneBook()
            self.assertTrue(phonebook.is_consistent())
    ```

=== "After"

    ```py
    import unittest

    from phonebook import PhoneBook


    class PhoneBookTest(unittest.TestCase):
        def setUp(self) -> None:
            self.phonebook = PhoneBook()

        def tearDown(self) -> None:
            self.phonebook.clear()

        def test_lookup_by_name(self):
            # phonebook = PhoneBook()
            self.phonebook.add("Bob", "12345")
            number = self.phonebook.lookup("Bob")
            self.assertEqual("12345", number)

        def test_missing_name(self):
            # phonebook = PhoneBook()
            with self.assertRaises(KeyError):
                self.phonebook.lookup("missing")

        @unittest.skip("WIP")
        def test_empty_phonebook_is_consistent(self):
            # phonebook = PhoneBook()
            self.assertTrue(self.phonebook.is_consistent())


    ```

The **`@unittest.skip`** decorator will tell the test runner to skip the decorated test case ([src](https://app.pluralsight.com/course-player?clipId=efd71803-d18f-4860-baca-d94bf935765a))

```py
@unittest.skip("WIP")
def test_empty_phonebook_is_consistent(self):
    phonebook = PhoneBook()
    self.assertTrue(phonebook.is_consistent())
```

The **command line entry point** is made with a call to `unittest.main()`, which executes the tests.
([src](https://realpython.com/python-testing/#how-to-use-unittest-and-flask "Getting Started With Testing in Python"))

```py
import unittest

from my_sum import sum

class TestSum(unittest.TestCase):
  def test_list_int(self):
    """
    Test that it can sum a list of integers
    """
    data = [1, 2, 3]
    result = sum(data)
    self.assertEqual(result, 6)

if __name__ == '__main__':
  unittest.main()
```

#### Integration tests

By convention, tests are put in their own directory as sibling to the main module ( in order to be able to import it ).
Integration and unit tests should be organized separately.

```
.
├── project
│   └── __init__.py
└── tests
    ├── integration
    └── unit
```

Run all integration tests within specified directory.
```sh
python -m unittest discover -s tests/integration
```

## Modules

When learning unfamiliar packages and importing them in a demonstration script, care must be taken that the 
demonstration script does not have the same name as the package being studied. 
If so, attempting to import the package while in an interpreter within that directory will cause the interpreter to try 
importing the incomplete script and not the package.

When running a Python interpreter within this directory, the files "calc" and "main" can be imported as modules by
specifying their names with no file extension.
```
. 
├── calc.py 
└── main.py
```
```py
import calc # No errors
import main # No errors
```
Specifying the full filename including extension does produce an error
```py
import calc.py # Error
import main.py # Error
```

### argparse


The `ArgumentParser` object exposes an attribute that contains the value passed in from the command-line. This attribute takes its identifier from the `dest` keyword argument when invoking the `add_argument()` method.

=== "Python"

    ```py
    import argparse

    def get_args():
      parser = argparse.ArgumentParser()
      parser.add_argument(dest='bar')
      return parser.parse_args()

    def main():
      args = get_args().bar
    ```

    The optional value assigned to `description` will be displayed when running the script with the options `-h` or `--help`
    
    ```py
    parser = argparse.ArgumentParser(description=helptext)
    ```

=== "Output"

    ```
    usage: argparse_practice.py [-h] [-f bar]
    
    optional arguments:
      -h, --help         show this help message and exit
      -f bar, --foo bar
    ```

A help string can be provided as a keyword argument to **`help`**.
```py
parser.add_argument("foo", help="bar")
```

A data type can be specified as an argument to **`type`**:
```py
parser.add_argument("foo", type=int)
```
An alternative name for the `dest` value on the command-line (but which does not affect the identifier of the attribute on which the value is exposed) can be specified by **`metavar`**.
```py
parser.add_argument("foo", metavar="bar")
```

The examples above used **positional parameters** (i.e. an argument). A **named parameter** (an option or flag, i.e. `-h`, `--help`, etc) requires <kbd>-</kbd> at the beginning of the string and values from the command-line to be passed after `=` or <kbd>Space</kbd>. `add_argument` supports the **`required`** keyword argument for named parameters. Note that use of the option on the command-line at all requires an argument to it, even if the option is not required itself.
```py
parser.add_argument('-r','--radius',type=int,required=True,help='radius')
```

A **flag option** can be created by defining an **`action`** keyword parameter. ([src](# "Tiny Python Projects p. 391))
```py
parser.add_argument('-o', '--on', help='A boolean flag', action='store_true')
```

**`add_mutually_exclusive_group()`** can be used to add a group of mutually exclusive arguments. In this case, `add_argument()` is invoked on the new object returned by this method and not directly on the `ArgumentParser()` object.
```py
g=ArgumentParser.add_mutually_exclusive_group()
g.add_argument("-v","--verbose", action="store_true")
g.add_argument("-q","--quiet","-s","--silent", action="store_true",help='quiet/silent mode')
```

User input can be restricted by providing a value for **`choices`**, which will accept any iterable value including lists, ranges, and strings:
```py
parser.add_argument("foo", choices=["bar","baz"])
parser.add_argument("foo", choices=range(1,10))
parser.add_argument("foo", choices='Hello, world!') # equivalent to ['H','e', ...]
```

Sources

- [Python documentation](https://docs.python.org/3/library/argparse.html)

### asyncio


The `asyncio` module offers an implementation of **coroutines** which allow tasks to control context switching to implement [**concurrency**](Concurrency).

The **`await`** keyword is a checkpoint that indicates where it is safe for the process to go to another coroutine, allowing total control over **context switching**

```py
import asyncio
import time

counter = 0

async def func1():
  global counter

  while True:
    counter += 1
    counter -= 1
    await asyncio.sleep(0)

async def func2():
  global counter

  while True:
    counter += 1
    counter -= 1
    await asyncio.sleep(0)

asyncio.gather(func1(), func2())
asyncio.get_event_loop().run_forever()
```


```py
async def get_users():
  users = await client.do_query('select * from users')
  return users

async def main():
  task = asyncio.create_task(get_users())
  # ...
  await task

asyncio.run(main())
```

Allows the joining of multiple threads.
```py
async def get_users():
  users = await client.do_query('select * from users')
  return users

async def main():
  await asyncio.gather(
    get_users(),
    get_users(),
  )

asyncio.run(main())
```
```py
async def get_users():
  users = await client.do_query('select * from users')
  return users

asyncio.run(get_users())
```

```py
async def main():
    users = await get_users()
    print(users)

asyncio.run(main())
```

Sources:

- [Demistifying Python's Async and Await keywords](https://youtu.be/F19R_M4Nay4)

### azure.cosmos

```py
import azure.cosmos
from azure.cosmos.partition_key import PartitionKey

database = cosmos_client.create_database('RetailDemo')
container = database.create_container(id='WebsiteData', partition_key=PartitionKey(path='/CartID'))
print('Container WebsiteData created')
```

### [bullet](https://github.com/bchao1/bullet)

**`bullet.Check()`** implements a checkbox widget:
```py
cli = bullet.Check(prompt = "Choose from the following items: ", choices=['pepperoni','sausage','green peppers'])
```
**`bullet.Bullet()`** implements a radio button widget:
```py
cli = bullet.Bullet(prompt = "Choose from the following items: ", choices=['red','white','blue'])
```
The resulting object then exposes a **`launch()`** method.
```py
cli.launch()
```

### click

`Click` modifies functions using decorators whch determine the command-line arguments elements that the decorated function can see.

Hello World program. <sup>[Click](https://click.palletsprojects.com/en/7.x/quickstart/#screencast-and-examples "Quickstart - Click Documentation")
```py
import click

@click.command()
def hello():
  click.echo('Hello World!')

if __name__ = '__main__':
  hello()
```
Modified Hello World
```py
import click

@click.command()
@click.option('--count', default=1, help='number of greetings')
@click.argument('name')
def hello(count, name):
  for x in range(count):
    click.echo('Hello %s!' % name)

if __name__ == '__main__':
  hello()
```
Developing the pdfcropper tool; passing `--examref` changes the numbers.
```py
import click

@click.command()
@click.option('--examref',is_flag=True)
def hello(examref):
  top, right, bottom, left = 0,0,0,0
  if examref:
    top, right, bottom, left = 1, 2, 3, 4
  click.echo(f'Your numbers are: top ({top}), right {right}, bottom {bottom}, left {left}')

if __name__ == '__main__':
  hello()
```
**@click.group()** decorators allow nested command groups to be created.
There are two ways of adding commands to command **groups**:
- Using the group as a decorator, whereby the name of the function decorated by `@click.group()` is then used to 
decorate commands:
```py
@click.group()
def group1()
  pass

@group1.command()
def command1():
  pass
```
- Using the `add_command` method
```py
@click.group()
def group1()
  pass

@click.command()
def command1():
  pass

group1.add_command(command1)
```
For example, to imitate the nested commands available in `netsh`:
```cmd
netsh interface ip
```
```py
@click.group()
def interface():
  pass

@interface.command('ip')
@click.argument('args', nargs=-1) # All arguments passed in as tuple "args"
def interface_ip(args):
  pass
```

Docstrings of groups and commands show up as progressive help messages when they are invoked from the command-line.

```py
@click.group()
def cli():
  pass

@click.command()
def initdb():
  click.echo('Initialized the database')

@click.command()
def dropdb():
  click.echo('Dropped the database')

cli.add_command(initdb)
cli.add_command(dropdb)

if __name__ == '__main__':
  cli()
```
**CommandCollection** flattens the structure of grouped commands so that the commands in all the contained groups
appear in a single tier. It also becomes the entry-point of the script.

Example from [GitHub](https://github.com/limbov8/fire/blob/30c7c5abef35d203ad1217093623edc5b9bbc922/bin/fire):
```py
# Three command groups cli1, cli2, and cli3 declared:

@click.group()
def cli1():
  pass

@click.group()
def cli2():
  pass

@click.group()
def cli3():
  pass

# Three commands each belonging to a separate group

@cli1.command()
def server():
  pass

@cli2.command()
def console():
  pass

@cli3.command()
def routes():
  pass

# CommandCollection flattens the grouped commands such that all the commands are available at once:

cli = click.CommandCollection(sources=[cli1,cli2,cli3])

if __name__ == '__main__':
  cli()
```
### collections
- **abc** provides `Mapping` and `MutableMapping` ABCs to formalize the interfaces of dict and similar types
- **ChainMap** Lookups are performed on each mapping in order
- **Counter** Holds an integer count for each key; each new key adds to the count
- **deque**: Thread-safe double-ended queue that supports most `list` methods
- **namedtuple**
```py
Card = namedtuple('Card',['rank','suit'])`
City = namedtuple('City', 'Name Country Population Coordinates'.split(' ')]
```
- OrderedDict: Maintains keys in insertion order
- UserDict: Designed to be subclassed
### colorama
Colorama provides a set of enums that resolve to terminal codes when concatenated with strings.
```py
colorama.Fore.GREEN
```
```py
colorama.Style.RESET_ALL
```
### csv
```py
with open('file.csv', newline=''):
  data = [row for row in csv.reader(f)]
```
[csv.DictReader](https://docs.python.org/3/library/csv.html#csv.DictReader)
```py
with open('greeks.csv') as f:
  reader = csv.DictReader(f)
  for row in reader:
    print(row['name'],row['city'],row['dob'])
```
### datetime
```py
datetime.date(2016,7,24)
datetime.date.today()
```
Difference between `datetime` objects is a `timedelta`
Parse strings into datetime objects
```py
datetime.strptime(datestring,formatstring)
``` 
```py
# Various metacharacters are defined for `strptime`
datetime.datetime.strptime('06/30/1992','%m/%d/%Y')
``` 

### discord.py

```sh
pip install discord.py
client = discord.Client()
```
`Client` objects expose a decorator that is used for event handlers, functions named after various events:
- `on_ready`
- `on_member_join`
- `on_error`
- `on_message`
```py
@client.event
async def on_ready():
  print(f'{client.user} has connected to Discord!')
```
Another decorator is exposed for in-chat commands ([`commands.Bot`](#discordextcommandsbot) has to be instantiated first.)
```py
@bot.command(name='roll_dice', help='Simulates rolling dice.')
async def roll(ctx, number_of_dice: int, number_of_sides: int):
  dice = [
    str(random.choice(range(1, number_of_sides + 1)))
    for _ in range(number_of_dice)
  ]
  await ctx.send(', '.join(dice))
```
```py
client.run(token)
```

```py
bot = comands.Bot(command_prefix='!')
```

### dotenv

```sh
pip install -U python-dotenv
```
Load a .env file placed in the current working directory.
```py
load_dotenv()
value =  os.getenv('key')
```


### functools

For higher-order functions (functions that act on or return other functions)\
Apply `function` of two arguments cumulatively to the items of `iterable` in order to reduce it to a single value
```py
functools.reduce(function, iterable [, initializer])
```
Calculate ((((1+2) +3) +4) +5)
```py
functools.reduce(lambda x, y: x+y, [1,2,3,4,5])
```
`functools.reduce(lambda a,b: a*b, range(1,6))` => 120 : factorial

### glob

Produce a list of strings
```py
glob.glob('*.py')
```

### heapq

Support **heaps**, data objects where each node is either greater than or equal to its parent (**max-heap**) or less than or equal to its parent (**min-heap**)
Create a heap from {iterable}
```py
heapq.heapify(iterable)
```
Remove and return the smallest element of {heap}
```py
heapq.heappop(heap)
```
Replace the smallest element of {heap} with {element}
```py
heapq.heapreplace(heap,element)
```
### http
Start an HTTP server for the current directory
```sh
python http.server
```
### itertools
**`cycle()`** works like `next()`, but it restarts from the beginning of the iterable that is passed as argument after the last element has been reached.
```py
with open('raven') as f:
    raven = [ l for l in f ]

itertools.cycle(raven)
```
### json
Parse an open file descriptor
```py
with open('file.json') as f:
  data=json.load(f)
```
Deserialize a JSON document `rawdata` that has been loaded
```py
data = json.loads(rawdata)
``` 
Write to an open file descriptor
```py
with open("file.json","w") as f:
  json.dump(data,f)
```
Specify indentation
```py
with open('file.json','w') as f:
  f.write(json.dumps(data, indent=4))
```
### logging
```python
import logging

def main():
  logging.basicConfig(filename='/tmp/learn-logging.log', level=logging.ERROR, format='%(asctime)s %(levelname)s: %(message)s')
  logging.info("Once upon a midnight dreary,")
  logging.warning('While I pondered weak and weary,')
  logging.error('Over many a quaint and curious volume of forgotten lore,')

if __name__ == '__main__':
  main()
```

### npyscreen

Widget library and application framework built on top of [`ncurses`](#ncurses). <sup>[Documentation](https://npyscreen.readthedocs.io/)]

Three main types of object compose `npyscreen` applications:
- **Application objects** manage forms and other classes
- **Form objects** form the canvas upon which widgets are arrayed
  - `Form` general-purpose
  - [`FormMutt`](#npyscreenFormMutt)
- **Widget objects** are individual controls
  - `TitleText` text entry
  - `TitleSelectOne` equivalent to radio buttons
  - `TitleDateCombo` allows picking of date on a small calendar

`npyscreen.wrapper_basic` is the main entry point
```py
import npyscreen

def myFunction(*args):
  pass

if __name__ == '__main__':
  npyscreen.wrapper_basic(myFunction)
  print "Blink and you missed it!"
```
`npyscreen.Form` is equivalent to the `Tk()` object, which is typically instantiated as `win` in GUI frameworks.
```py
F = npyscreen.Form(name='My Test Application')
```
Several important methods are key:
- `create()` The standard constructor calls this method, which does nothing by default and is meant to be overriden in subclasses. Widgets are defined here.

[**`npyscreen.FormMutt`**](https://npyscreen.readthedocs.io/form-objects.html#mutt-like-forms) imitates a UI layout popularized by applications like [`mutt`](https://github.com/jasper-zanjani/notes/tree/master/lx), `irssi`, and `vim`, with a title bar at the top, a command line at the bottom, and a status line directly above the command line.

`ACTION_CONTROLLER` can be defined in the `FormMutt` subclass as the name of a subclass of `ActionControllerSimple`.
Commands for the application can be defined as callbacks in the `create()` method.
```py
self.add_action(ident,call_back, True)
```
Callbacks are called with the following arguments:
```py
call_back(command_line, control_widget_proxy, live=True)
```
```py
class ActionControllerSearch(npyscreen.ActionControllerSimple):
    def create(self):
        self.add_action('^/.*', self.set_search, True)
    
    def set_search(self, command_line, widget_proxy, live):
        self.parent.value.set_filter(command_line[1:])
        self.parent.wMain.values = self.parent.value.get()
        self.parent.wMain.display()

class FmSearchActive(npyscreen.FormMuttActiveTraditional):
    ACTION_CONTROLLER = ActionControllerSearch
```

**`npyscreen.NPSAppManaged`** is the preferred superclass to support object-oriented implementation.
```py
class MyApplication(npyscreen.NPSAppManaged):
  pass
```
Calling `run()` method of application object as main entry point.
`run()` activates the default form, which should be given an id of `MAIN`
```py
if __name__ == '__main__':
  TestApp = MyApplication().run()
  print "All objects, baby."
```
Using a `try`/`except` block to allow for well-mannered exit in case of `KeyboardInterrupt` (Ctrl+C)<sup>[GitHub](https://github.com/c1ko/nh/blob/master/nh.py)</sup>
```py
try:
  App().run()
except KeyboardInterrupt:
  sys.exit(0)
```
There are three methods for registering a `Form` object with a `NPSAppManaged` instance;
- `addForm()` creates a new form and returns a `weakref.proxy` to it
- `addFormClass()` register a class of `Form` rather than an instance
- `registerForm()`

It continually displays the Form named by its `NEXT_ACTIVE_FORM` attribute.
Use the `afterEditing` method to allow exiting.
```py
class myEmployeeForm(npyscreen.Form):
  def afterEditing(self):
    self.parentApp.setNextForm(None)
```
### numpy
`numpy.ndarray`
  - 2-dimensional array
  - items can be fetched using the syntax `a[i, j]`
  - arrays can be sliced with syntax `a[m:n, k:l]`
  - FP:35
`numpy.arange(n)` build a `numpy.ndarray` object with numbers 0 to n-1 (FP:52)
`numpy.loadtxt(filename)` load numbers stored in a text file (FP:53)
### optparse
Instantiate the parser object
```py
parser = optparse.OptionParser(usage=__doc__.strip())

# add an option
parser.add_option('--timeout')
```
### os
Execute shell command given by string.  The value returned is actually the exit code, **not** the output of the command to STDOUT.
```py
os.system('ls -la')
``` 
Store output in a variable
```py
os.popen('ls -la').read()
``` 
Navigate filesystem
```py
os.getcwd()
os.chdir(path)
```
Test for existence of a file
```py
os.path.isfile(file)
``` 
### pandas
summary: open-source Python library used for data science
operation: runs over NumPy
  - good for storing lists-of-lists (CSV)
`print(df)`
  - prints it out in an easy to read tabular format

`DataFrame` is the main object in `pandas`
- `head()`, `tail()`
  - prints out the first, last several rows (5 by default)
  - optional numerical argument defines number of rows
- `describe()`
  - numerical analyses, including count, unique, mean, etc
- `sort_values('field',ascending=False)`
### pathlib
Create a new pathlib object; represents a file or directory
```py
pathlib.Path(path)
```
Test for existence of a file
```py
pathlib.Path.is_file(file)
``` 
Test for existence of a directory
```py
pathlib.Path.is_dir(dir)
```
Find all `.py` files
Returns a generator
```py
pathlib.Path.glob('*.py')
```
Open a file. This makes a file object that is automatically closed, similar to `open` builtin:
```py
pathlib.Path.open()
``` 
Display file extension
```py
pathlib.Path.suffix()
```
Display file size
```py
pathlib.Path.stat().st_size
```
### pyinstaller
[pyinstaller --name]: # "Change the name of the executable artifact"
[pyinstaller --onefile]: # "Package the entire application intoa  single executable file"
[pyinstaller --hidden-import]: # "Explicitly specify imports that may not have been detected by PyInstaller."

Source: [RealPython tutorial](https://realpython.com/pyinstaller-python/)

Installing **PyInstaller**, even in a virtual environment, will install the pyinstaller executable to $HOME/.local/bin.
On Windows, it is installed to another directory within 
[`LOCALAPPDATA`](# "$Env:LOCALAPPDATA\Packages\PythonSoftwareFoundation.Python.3.x....\LocalCache\local-packages\Python3x\Scripts").
```sh
pip install pyinstaller
```
PyInstaller creates primarily 3 items:
- .spec file, named after the CLI script
- build/ folder, which can be ignored
- dist/ folder, containing the final artifact at dist/cli/cli or dist/cli/cli.exe

Several options are available
[`hidden-import`][pyinstaller --hidden-import]
[`name`][pyinstaller --name]
[`onefile`][pyinstaller --onefile]
```sh
pyinstaller script.py --onefile
```
On Windows, if PyInstaller is run from a virtual environment without necessary modules installed, they may not be available for compilation into the artifact. This does not appear to be an issue with Linux.

This problem appears to be specific to certain modules, like [**emoji**](https://github.com/carpedm20/emoji/).
### pythonnet
- Docs: [?](https://github.com/pythonnet/pythonnet "Github") [!](http://pythonnet.github.io/)
Developers recommend Mono version 5.20.1 <sup>Issues [939](https://github.com/pythonnet/pythonnet/issues/939)</sup>
On Ubuntu, the `eoan` `universe` repository has to be added 
```
deb https://archive.ubuntu.com/ubuntu/ eoan universe
deb https://archive.ubuntu.com/ubuntu/ eoan-updates universe
```
But I can't figure out how to add the older version, because the recommended syntax produces the error "Unable to correct problems, you have held broken packages"
```sh
sudo apt install mono-devel=5.18.0.240+dfsg-3
```
Maybe try the [tarballs](https://download.mono-project.com/sources/mono/) on Mono's website...
Or maybe there's [another repo](https://github.com/jonemo/pythonnet-docker/blob/master/python3.6.5-mono5.4.1.6-pythonnet2.4.0.dev0.Dockerfile) I don't know about..
```sh
apt install clang libglib2.0-dev python3-dev
```
```sh
pip install pycparser pythonnet
pip install -U setuptools
```
### random

Random choice with replacement
```py
random.choice(iterable)
```
Shuffle elements of an iterable in-place [FP:42]
```py
random.shuffle(iterable)
```
### scrapy

Best used to obtain one "stream" of data at a time, without trying to obtain data from different pages
```sh
scrapy runspider spider.py -o file.json
```
Display HTML source of the scraped page
```python
print(response.txt)
```
Get `{URL}`
```python
fetch('url')
```
Select a CSS selector
```python
# Returns a `SelectorList`
response.css('p')
# Retrieve full HTML elements
response.css('p').extract()
```
Retrieve only the text within the element
```python
response.css('p::text').extract()
response.css('p::text').extract_first()
response.css('p::text').extract()[0]
```
Get the `href` attribute value for an anchor tag
```python
response.css('a').attrib['href']
```
Launch Scrapy shell and scrape `$URL`
```bash
scrapy shell $URL
```
Make a default spider named {quotes} that will be restricted to {domain}
```python
scrapy genspider quotes domain
```
```python
scrapy runspider scrapy1.py
```
Run a spider, saving scraped data to a JSON file
```python
scrapy runspider spider.py -o items.json
``` 
Method which contains most of the logic of the spider, especially after the `yield` keyword. For multiple items, a structural basis for iteration must be found and for each iteration, data is yielded

Extract URL from link using standard CSS selection techniques

Add the domain name to a relative link
```python
response.urljoin()
```
Recursively call the `parse` method again on the next page
```python
yield scrapy.Request(url=next_page_url, callback=self.parse)
``` 
Scrape detail pages
  - `parse_details` would be a spider method _sibling_ to the main `parse` method
  - if a detail page has more information than the main, then the `yield` keyword should be in `parse_details`
```python
yield scrapy.Request(url={url}, callback=self.parse_details)
```
### setuptools
Setuptools is for uploading to PyPi. To create self-contained executable files, use [**pyinstaller**](#pyinstaller).

```
PROJECT
├── PROJECT     # Additional code files will be placed in here
│   └── init.py
└── setup.py    # Containing a call to `setuptools.setup()`

1 directory, 2 files
```
setup.py
```python
from setuptools import setup

setup(
  name='funniest',
  version='0.1',
  description='The funniest joke in the world',
  url='http://github.com/storborg/funniest',
  author='Flying Circus',
  author_email='flyingcircus@example.com',
  license='MIT',
  packages=['funniest'],
  zip_safe=False
)
```
If the package has dependencies, they can be added by appending a `install_requires` keyword argument passing an array of the module names
```python
setup(
  install_requires=[ 'markdown', ],
)
```

Reserve the name, upload package metadata, and create the pypi.python.org webpage
```py
python setup.py register
```
Create a source distribution, producing a tarball inside the top-level directory
```py
python setup.py sdist
```
Upload the source distribution
```py
python setup.py sdist upload
```
Do all the above in a single step
```py
python setup.py register sdist upload
```
### socket


The socket module is Python's standard interface for the transport layer.
Sockets can be classified by **`family`**

- **`AF_INET`** Internet
- `AF_UNIX` for UNIX sockets

and **`type`**:
  - **`SOCK_STREAM`** TCP
  - `SOCK_DGRAM` UDP

These enum values are required upon initialization of a socket object: <sup>[Ortega][Ortega]: 25</sup>

```py
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

Sources: 

- [Sockets tutorial](https://youtu.be/Lbfe3-v7yE0)


=== "TCP server"

    ```py
    import socket
    

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST,PORT))
    ```

=== "TCP Client" 

    ```py
    import socket


    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST,PORT))
    ```

=== "UDP server"

    ```py
    import socket


    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind((HOST,PORT))
    ```

=== "UDP client"

    ```py
    import socket

    msg = "Hello, world!"
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.sendto(msg.encode(), (HOST,PORT))
    ```

Define port on which to listen for connections.
```py
serversocket.bind(('localhost',80))
```
Connect to a remote socket in one direction
```py
client_socket.connect(('www.packtpub.com',80))
```
Convert a domain name into IPv4 address
```py
socket.gethostbyname('packtpub.com') # '83.166.169.231'
```
Defaults to **localhost** with no arguments
```py
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1234))
```
Get protocol name from port number
```py
socket.getservbyport(80) # 'http'
```
Listen to a maximum of 10 connections
```py
serversocket.listen(10)
```
Receive bytestream from server
```py
msg = s.recv(1024)
print(msg.decode('utf-8'))
```

### sqlite3

Create a `Connect` connection object and **employee.db** (binary) if it doesn't exist
```py
conn = sqlite.connect('employee.db')
```
Create a `Connect.Cursor` object
```py
c = conn.cursor()
```
Perform SQL commands with `Connect.Cursor.execute()`. Create `tablename` with fields `field` of type `type` (`null`, `integer`, `real`, `text`, `blob`); never use Python's native string operations (f-strings, etc) to form commands, because this method is vulnerable to SQL injection. <sup>[YouTube](https://youtu.be/pd-0G0MigUA)</sup>
```py
c.execute('''CREATE TABLE {tablename} ({field} {type}, {field} {type} ...))
``` 
Save changes
```py
conn.commit()
```
Close connection
```py
conn.close()
```
### subprocess

**subprocess** modules allows you to spawn new processes, interact with file descriptors, and obtain exit codes. The recommended approach is to use the `run()` function as default, which runs a CLI command with options as a list of strings and returns a `CompletedProcess` instance.\
Execute shell command
Unlike `os.system`, `subprocess.run()` takes a list of arguments. 
```py
subprocess.run(['ls','-l,'.'], 0)
```
Set `capture_output` to `True` to save output, stored as property `stdout` of the returned object. 
```py
data = subprocess.run(['ls,'-l','.'], 0, capture_output=True)
```
The data is stored as a **bytestring**, which can be decoded to a normal string.
```py
data.stdout.decode('utf-8')
```
This return a `CompletedProcess` instance with the command's output stored under the `stdout` property
```py
subprocess.run(['ls','-l','/dev/null'], capture_output=True)
```
This will raise a `CalledProcessError` exception because of the non-zero exit code
```py
subprocess.run('exit 1', shell=True, check=True)
```
### sys
Return site-specific directory where Python files are installed 
```py
sys.prefix          # /usr/local/ by default
```
### tabulate
### termcolor
Print `text` in a color code
```py
termcolor.cprint(text,color)
```
### threading
:point_right: [Docs](https://docs.python.org/3/library/threading.html)

```py
counter = 0
lock = threading.RLock()

def func1():
  global counter

  while True:
    with lock:
      counter += 1
      counter -= 1

def func2():
  global counter

  while True:
    with lock:
      counter += 1
      counter -= 1

threading.Thrad(target=func1).start()
threading.Thrad(target=func2).start()
```
```py
counter = 0

def func1():
  global counter

  while True:
    counter += 1
    counter -= 1

def func2():
  global counter

  while True:
    counter += 1
    counter -= 1

threading.Thrad(target=func1).start()
threading.Thrad(target=func2).start()
```
### typing
As tuples, their attributes are **immutable**
```py
class Starship(NamedTuple):
  name: str
  registry: str
  crew: int
```


### urllib

Download an RFC file from rfc-editor.org <sup>[Ortega][Ortega]</sup>
```py
rfc_raw = urllib.request.urlopen(url).read()
rfc = rfc_raw.decode()
```
### weakref
**Weak references** are references to objects which return exceptions when that object has been garbage collected
Create a weak reference to {object} 
```py
# A weak reference created using `ref` must be dereferenced 
r = weakref.ref(obj) 
r().method() 
r.method()          # will not work

# A weak reference created using `proxy` does not need to be dereferenced:
weakref.proxy(obj)
```
### winrm
**Winrm** allows you to connect Linux and Windows hosts over WinRM. <sup>[adamtheautomator.com](https://adamtheautomator.com/winrm-linux-remoting/ "Step-by-step guide on how to set up WinRM on a Linux client") </sup>
Begin a WinRM session. If no errors are thrown, the session has been successfully established
```py
session = winrm.Session(ipaddress,auth=(username,password))
```

### yaml
```py
from ruamel.yaml import YAML
yaml = YAML()

# Adjust indentation levels
yaml.indent(mapping=4,sequence=6,offset=3)

# Print all `data` to stdout
yaml.dump(data,sys.stdout)

with open("file") as f:
    yaml.dump(data,f)
```

Resources:

- [Introduction to YAML](https://www.cncf.io/blog/2019/02/21/introduction-to-yaml-creating-a-kubernetes-deployment/)

## Glossary


### Method resolution order

**Method resolution order (MRO)** is the order of base classes that are searched when using `super()`. 
It is accessed with `__mro__`, which returns a tuple of base classes in order of precedence, ending in `object` which is the root class of all classes.
([src](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/))

### Non-interactive debugging

**Non-interactive debugging** is the most basic form of debugging, dependent on `print` or `log` statements placed within the body of code.

### Type slot

A **type slot is any of a number of fields within each magic method, including** `__new__()`, `__init__()`, and `__prepare__()` (which returns a dictionary-like object that's used as the local namespace for all code from the class body)


[Ortega]: # "Jose Manuel Ortega, et al. Learning Python Networking."