# Standard Library
## argparse
`ArgumentParser(description=String)`
  - `String` contains usage that will appear with `-h` or `--help`
`ArgumentParser.add_argument("x", type=int, help="the base")`
  - positional arguments are valid if only one option is provided
  - do not require `-` at the beginning of the string
  - `help` string is what is printed next to the argument name in the `help` dialog
`ArgumentParser.add_argument('-r','--radius',type=int,required=True,help='radius)`
  - `-` is required at the beginning of the string
  - values need to be passed after `=` or `<space>`
  - no longer behaves as a positional argument
`qv=ArgumentParser.add_mutually_exclusive_group()`
  - add a group of arguments which may not be used together
  - appears as `[-v | -q]` in the usage provided to a user
`qv.add_argument("-v","--verbose", action="store_true")`
`qv.add_argument("-q","--quiet","-s","--silent", action="store_true",help='quiet/silent mode')`
  - many invocation options can be added to the same argument 
## array (FP:48-50, PiaN:375)
`import array`
`frombytes`
`tofile`
## bisect
## collections
`collections.namedtuple(name, *field_names` (FP:30-32) subclasses of `tuple` with field names and a class name
  - `Card = namedtuple('Card',['rank','suit'])`
  - `City = namedtuple('City', 'name country population coordinates')`
`collections.deque` (FP:54-56, PiaN: 173) supports most `list` methods
`collections.abc` module provides `Mapping` and `MutableMapping` ABCs to formalize the interfaces of dict and similar types (FP:64)
`collections.defaultdict` (PiaN: 174)
## contextlib
`@contextmanager`
  - builds a context manager out of generator functions
  - function it decorates must run exactly twice (typically `try ... yield finally ...` structure)
  - `yield` can pass a value back (can be assigned to variable after `as` keyword)
`capsys fixture`
  - from pytest allows access to stdout/stderr output generated during text execution
`contextlib.redirect_stdout`
  - context manager temporarily redirects `sys.stdout` to another file or file-like object
## ctypes
## curses
curses.textpad
curses.ascii
curses.panel
## datetime
difference between `datetime` objects is a `timedelta`
`datetime.date(2016,7,24)`
`datetime.date.today()`
`datetime.strptime(datestring,formatstring)` 
  - parse strings into datetime objects
  - various metacharacters are defined for `strptime`
`datetime.datetime.strptime('06/30/1992','%m/%d/%Y')`
  - produces a `datetime` object
## functools
for higher-order functions (functions that act on or return other functions)
`functools.reduce(function, iterable [, initializer])`
: apply `function` of two arguments cumulatively to the items of `iterable` in order to reduce it to a single value
`functools.reduce(lambda x, y: x+y, [1,2,3,4,5])`
: calculates ((((1+2) +3) +4) +5)
`functools.reduce(lambda a,b: a*b, range(1,6))` => 120
: factorial

## getpass
## glob
`import glob`
`glob.glob('*.py')`
  - produces a list of strings

## heapq
Support _heaps_, which are data objects where each node is either greater than or equal to its parent (max-heap) or less than or equal to its parent (min-heap)
`heapq.heappop(heap)`
: remove and return the smallest element of {heap}
`heapq.heapreplace(heap,element)`
: replace the smallest element of {heap} with {element}
`heapq.heapify(iterable)`
: create a heap from {iterable}

## json
`data=json.load(f)`
  - JSON files
`json.dump(data,f)`
`jsonfile.write(json.dumps(data, indent=4))`
  - write JSON files

## optparse
`parser = optparse.OptionParser(usage=__doc__.strip())`
: after importing `optparse`, instantiate the parser object
: k

`parser.add_option('--timeout')`
: add an option

## os
`os.system('ls -la')`
  - execute shell command given by string
`os.popen('ls -la').read()`
  - store output in a variable
`os.chdir(path)`
`os.getcwd()`
## pathlib
`pathlib.Path(path)`
  - create a new pathlib object
  - represents a file or directory
`pathlib.Path.is_file()`
`pathlib.Path.is_dir()`
`pathlib.Path.exists()`
`pathlib.Path.glob('*.py')`
  - find all `.py` files
  - returns a generator
`pathlib.Path.open()`
  - makes a file object that is automatically closed
  - builtin `open` function will also work
`pathlib.Path.suffix()`
  - returns file extension
`pathlib.Path.stat().st_size`
  - returns file size
## platform
## random
`random.choice(iterable)`
  - random choice with replacement
`random.shuffle(iterable)`
  - shuffle elements of an iterable in-place (FP:42)
## subprocess
`subprocess.run('ls','-l,'.')`
  - arguments and options are provided in a list
## sqlite3
[SQLite tutorial](https://youtu.be/pd-0G0MigUA)
`import sqlite3`
`conn = sqlite.connect('employee.db')`
: create a `Connection` object and `employee.db` (binary) if it doesn't exist
`c = conn.cursor()`
: create a `Cursor` object
`c.execute('''CREATE TABLE {tablename} ({field} {type}, {field} {type} ...))`
: perform SQL commands
: create {tablename} with fields {field} of type {type} (null, integer, real, text, blob)
: never use Python's native string operations (f-strings, etc) to form commands, because this method is vulnerable to SQL injection
`conn.commit()`
: save changes
`conn.close()`

## weakref
Support weak references, that is, references to objects which return exceptions when that object has been garbage collected
`weakref.ref(object)`
: create a weak reference to {object} (which must be dereferenced in practice); i.e. `r = weakref.ref(obj); r.method() # will not work; r().method()`
`weakref.proxy(object)`
: create a weak reference to {object} (which does not need to be dereferenced in use)

# Libraries and packages
## click
`import click`
`@click.command()`
  - general-purpose decorator
  - docstring will come up when `--help` invocation argument is passed
`@click.option('--string',default='world',help='This is the person greeted')`
  - add command-line options
  - option string itself defines the variable identifier within the code
    - option string has to begin with (at least one) `-`
    - `-` in the middle of the string become underscore `_` in the variable identifier
`@click.argument('out', required=False,type=click.File('w'))`
  - arguments are mandatory by default
  - arguments do not take usage text: they must be documented within the docstring
`click.echo(f'Hello {name[0:-1]}{name[-1]*(n+1)}!', file=out)`
  - supposedly superior to `print`
  - will output to `out` argument
`out.write('\n{name} lives!\n')`
  - `out` is of type LazyFile (NFI)
## setuptools
set of enhancements to `distutils` that facilitates the building and distribution of Python packages
`setuptools.setup`
## numpy
`numpy.ndarray`
  - 2-dimensional array
  - items can be fetched using the syntax `a[i, j]`
  - arrays can be sliced with syntax `a[m:n, k:l]`
  - FP:35
`numpy.arange(n)` build a `numpy.ndarray` object with numbers 0 to n-1 (FP:52)
`numpy.loadtxt(filename)` load numbers stored in a text file (FP:53)
## pandas
summary: open-source Python library used for data science
operation: runs over NumPy
`import pandas`
`df=pandas.DataFrame()`
  - `DataFrame` is the main object in `pandas`
  - good for storing lists-of-lists (CSV)
`print(df)`
  - prints it out in an easy to read tabular format
### DataFrame methods
  - `head()`, `tail()`
    - prints out the first, last several rows (5 by default)
    - optional numerical argument defines number of rows
  - `describe()`
    - numerical analyses, including count, unique, mean, etc
  - `sort_values('field',ascending=False)`
## parse
First heard about on pythonbytes podcast
"if you have a problem and you solve it with a regular expression you now have two problems"
## PyPDF2
`with open(filename,'rb') as f:`
`original = PdfFileReader(f)`
`out=PdfFileWriter()`
`p = original.getPage(x)`
## curses
make sure `pdcurses.dll` is in both Python's root directory (C:\Users\jaspe\AppData\Local\Programs\Python\Python37, for instance) as well as the directory where the script is located. This file must be compiled from source code using the make program
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
  ├ d __pycache__/
  │ └ - app-cpython-16.pyc
  ├ - app.py
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
`apistar test`
  built-in pytest
`apistar run`
  start server
### Syntax
`apistar.Include`
  incorporate Views from other frameworks like Django
`apistar.Route`

  `apistar.Route('/', 'GET', welcome)`
