## Api Star
### Command line
`pip install apistar`
`apistar new --layout minimal`
: Generate files:
  ```
  ├ d __pycache__/
  │ ├ - app.cpython-16.pyc
  │ └ - tests.cpython-16.pyc
  ├ - app.py
  └ - tests.py
  ```
`apistar new --layout standard`
: Generate files
  ```
  \ __pycache__/
   . app-cpython-16.pyc
   \ - app.py
  ├ d project/
  │  ├ d __init__.py
  │  ├ d __pycache__/
  │      __init__.cpython-16.pyc
        routes.cpython-16.pyc
        views.cpython-16.pyc
      routes.py
      views.py
    tests/
      __pycache__/
        test.app.cpython-16.pyc
      test_app.py
  ```
`apistar test` built-in pytest
`apistar run` start server

### Syntax
`apistar.Include`
  incorporate Views from other frameworks like Django
`apistar.Route`
`apistar.Route('/', 'GET', welcome)`

