# 🐍 Python

[Ortega]: # "Jose Manuel Ortega, et al. Learning Python Networking."

#### Decorators

A **decorator** is any function that accepts a function and returns a function.
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

**flake8**, **black**, and **yapf** are CLI tools used to automatically format Python code.

## Virtual environments
### pipenv

```sh
pipenv --python 3.6
```

### venv

Create a virtual environment named **project**
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

## Tasks

Deserialize

=== "YAML"

    ```py hl_lines="5"
    import yaml


    with open('./starships.yaml') as f:
        starships = yaml.safe_load(f)
    ```

=== ":material-code-json: JSON"

    ```py
    import json


    with open('./starships.json') as f:
        data=json.load(f)
    ```



Serialize

=== "YAML"

    ```py
    import yaml


    with open('./starships.yaml','w') as f:
        yaml.dump(starships, f)
    ```

=== ":material-code-json: JSON"

    ```py
    import json


    with open('/starships.json',"w") as f:
        json.dump(data,f)
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





## Glossary


**Method resolution order**
:   
    **Method resolution order (MRO)** is the order of base classes that are searched [when using **super()**](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/). 
    It is accessed with `__mro__`, which returns a tuple of base classes in order of precedence, ending in `object` which is the root class of all classes.

**Non-interactive debugging**
:   
    **Non-interactive debugging** is the most basic form of debugging, dependent on `print` or `log` statements placed within the body of code.

**Type slot**
:   
    A **type slot is any of a number of fields within each magic method, including** `__new__()`, `__init__()`, and `__prepare__()` (which returns a dictionary-like object that's used as the local namespace for all code from the class body)


