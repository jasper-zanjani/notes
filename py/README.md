[Ortega]: # "Jose Manuel Ortega et al. _Learning Python Networking, Second Edition._"

- [Python Concepts](#python-concepts)
    - [Decorators](#decorators)
    - [Doctest](#doctest)
    - [Pointers](#pointers)
    - [Shebang](#shebang)
    - [Type object](#type-object)
    - [MRO](#mro)
- [Python Modules](#python-modules)
  - [argparse](#argparse)
  - [array](#array)
  - [bisect](#bisect)
  - [collections](#collections)
        - [namedtuple](#namedtuple)
        - [deque](#deque)
        - [abc](#abc)
        - [defaultdict](#defaultdict)
  - [contextlib](#contextlib)
  - [csv](#csv)
        - [csv.reader](#csvreader)
  - [ctypes](#ctypes)
  - [curses](#curses)
  - [datetime](#datetime)
  - [functools](#functools)
  - [getpass](#getpass)
  - [glob](#glob)
  - [heapq](#heapq)
  - [json](#json)
        - [json.load](#jsonload)
        - [json.loads](#jsonloads)
        - [json.dump](#jsondump)
        - [json.write](#jsonwrite)
  - [npyscreen](#npyscreen)
      - [npyscreen.wrapper_basic](#npyscreenwrapper_basic)
      - [npyscreen.Form](#npyscreenform)
      - [npyscreen.FormMutt](#npyscreenformmutt)
      - [npyscreen.NPSAppManaged](#npyscreennpsappmanaged)
  - [optparse](#optparse)
  - [os](#os)
  - [pathlib](#pathlib)
  - [platform](#platform)
  - [pythonnet<sup>?[^](http://pythonnet.github.io/)</sup>](#pythonnetsupsup)
  - [random](#random)
  - [socket](#socket)
  - [subprocess](#subprocess)
  - [sqlite3](#sqlite3)
  - [sys](#sys)
  - [termcolor](#termcolor)
  - [typing](#typing)
        - [typing.NamedTuple](#typingnamedtuple)
  - [unittest](#unittest)
  - [venv](#venv)
  - [virtualenv](#virtualenv)
  - [weakref](#weakref)
  - [winrm](#winrm)
- [Python packages](#python-packages)
    - [click](#click)
        - [click.group](#clickgroup)
    - [Scrapy](#scrapy)
      - [Scrapy shell](#scrapy-shell)
      - [Pagination](#pagination)
      - [Scrape detail pages](#scrape-detail-pages)

# Python Concepts
### Decorators
"Primer on Python Decorators" [realpython.com](https://realpython.com/primer-on-python-decorators/)
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
### Pointers
Python, which emphasizes abstraction and usability, does **not** support pointers natively. <sup>[realpython.com](https://realpython.com/pointers-in-python/)</sup>
But there are some features of Python which provide the benefits of pointers.
- `id(object)` Return {object}'s memory address
- `object is other` return True if {object} and {other} share the same memory address

Mutable primitives `list`, `set`, `dict` can be used to simulate pointers, since their memory address will not change. 
Custom objects can also be used to recreate the behavior of pointers.
Lastly, the `ctypes` module allows you to use shared libraries compiled from C programs, calling C functions from within Python. <sup>[dbader.org](https://dbader.org/blog/python-ctypes-tutorial "Extending Python with C Libraries and the 'ctypes' Module")</sup>
### Shebang
```py
#!/usr/bin/env python
```
### Type object
The `PyTypeObject` structure defines a new type and are fundamental to Python's object data model. <sup>[ionel's codelog](https://blog.ionelmc.ro/2015/02/09/understanding-python-metaclasses/)</sup>
This is a struct that describes the class.
Each magic method has a field within this struct, which are called **type slots**.

The `__new__` method is the **constructor** while `__init__` is the **initializer**.

`__prepare__` returns a dictionary-like object that's used as the local namespace for all the code from the class body.
### MRO
The **method resolution order (MRO)** refers to the order of base classes that are searched when using `super()`. <sup>[src](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/)</sup>

It is accessed with the `__mro__` [magic method][dunder method], which returns a tuple of base classes in order of precedence, ending in `object` which is the root class of all classes.
# Python Modules
## argparse
Define information that will appear when the user wants help. The string {helptext} contains the usage that will appear with `-h` or `--help`.
```py
ArgumentParser(description=helptext)
```
Add a positional argument
- positional arguments are valid if only one option is provided
- do not require `-` at the beginning of the string
- `help` string is what is printed next to the argument name in the `help` dialog
```py
ArgumentParser.add_argument("x", type=int, help="the base")
```
Add a named parameters
- `-` is required at the beginning of the string
- values need to be passed after `=` or `<space>`
- no longer behaves as a positional argument
```py
ArgumentParser.add_argument('-r','--radius',type=int,required=True,help='radius)
```
Add a group of mutually exclusive arguments (may not be used together)\
Usage appears as `[-v | -q]` indicating one of the options may be used. Many invocation options can be added to the same argument:
```py
qv=ArgumentParser.add_mutually_exclusive_group()
qv.add_argument("-v","--verbose", action="store_true")
qv.add_argument("-q","--quiet","-s","--silent", action="store_true",help='quiet/silent mode')
```
## array 
`frombytes`
`tofile`
(FP:48-50, PiaN:375)
## bisect
## collections
##### namedtuple
```py
Card = namedtuple('Card',['rank','suit'])`
City = namedtuple('City', 'Name Country Population Coordinates'.split(' ')]
```
##### deque 
Supports most `list` methods
FP:54-56, PiaN: 173
##### abc
provides `Mapping` and `MutableMapping` ABCs to formalize the interfaces of dict and similar types <sup>[FP][FP]:64</sup>
##### defaultdict
s  <sup>[PiaN][PiaN]: 174</sup>
## contextlib
Build a context manager out of **generator functions** - function it decorates must run exactly twice (typically `try ... yield finally ...` structure) - `yield` can pass a value back (can be assigned to variable after `as` keyword)\
```py
@contextmanager
```
`capsys fixture` - from pytest allows access to stdout/stderr output generated during text execution
`contextlib.redirect_stdout` - context manager temporarily redirects `sys.stdout` to another file or file-like object
## csv
##### csv.reader
```py
with open('file.csv', newline=''):
  data = [row for row in csv.reader(f)]
```
## ctypes
## curses
make sure `pdcurses.dll` is in both Python's root directory (C:\Users\jaspe\AppData\Local\Programs\Python\Python37, for instance) as well as the directory where the script is located. This file must be compiled from source code using the make program
curses.textpad
curses.ascii
curses.panel
## datetime
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
## functools
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
## getpass
## glob
Produce a list of strings
```py
glob.glob('*.py')
```
## heapq
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
## json
##### json.load
Parse an open file descriptor
```py
with open('file.json') as f:
  data=json.load(f)
```
##### json.loads
Deserialize a JSON document `rawdata` that has been loaded
```py
data = json.loads(rawdata)
``` 
##### json.dump
Write to an open file descriptor
```py
with open("file.json","w") as f:
  json.dump(data,f)
```
##### json.write
Specify indentation
```py
with open('file.json','w') as f:
  f.write(json.dumps(data, indent=4))
```
## npyscreen
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

#### npyscreen.wrapper_basic
Main entry point
```py
import npyscreen

def myFunction(*args):
  pass

if __name__ == '__main__':
  npyscreen.wrapper_basic(myFunction)
  print "Blink and you missed it!"
```
#### npyscreen.Form
Equivalent to the `Tk()` object, which is typically instantiated as `win` in GUI frameworks.
```py
F = npyscreen.Form(name='My Test Application')
```
Several important methods are key:
- `create()` The standard constructor calls this method, which does nothing by default and is meant to be overriden in subclasses. Widgets are defined here.

#### npyscreen.FormMutt
[`FormMutt`](https://npyscreen.readthedocs.io/form-objects.html#mutt-like-forms) imitates a UI layout popularized by applications like [`mutt`](https://github.com/jasper-zanjani/notes/tree/master/lx), `irssi`, and `vim`, with a title bar at the top, a command line at the bottom, and a status line directly above the command line.

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

#### npyscreen.NPSAppManaged
Preferred superclass for OO implementation.
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
## optparse
Instantiate the parser object
```py
parser = optparse.OptionParser(usage=__doc__.strip())

# add an option
parser.add_option('--timeout')
```
## os
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
## pathlib
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
## platform
## pythonnet<sup>[?](https://github.com/pythonnet/pythonnet "Github")[^](http://pythonnet.github.io/)</sup>
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
## random
Random choice with replacement
```py
random.choice(iterable)
```
Shuffle elements of an iterable in-place [FP:42]
```py
random.shuffle(iterable)
```
## socket
Constructor used to create a socket <sup>[Ortega][Ortega]: 25</sup>
- `socket_family` can be either 
  - **`AF_INET`**
  - `AF_UNIX` for UNIX sockets
- `socket_type` can be either 
  - **`SOCK_STREAM`**
  - `SOCK_DGRAM`
- `protocol` is usually left out and defaults to 0
```py
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```
Connect to a remote socket in one direction
```py
client_socket.connect(('www.packtpub.com',80))
```
Define port on which to listen for connections.
```py
serversocket.bind(('localhost',80))
```
Listen to a maximum of 10 connections
```py
serversocket.listen(10)
```
## subprocess
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
## sqlite3
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
## sys
Return site-specific directory where Python files are installed 
```py
sys.prefix          # /usr/local/ by default
```
## termcolor
Print `text` in a color code
```py
from termcolor import cprint

cprint(text,color)
```
## typing
##### typing.NamedTuple
As tuples, their attributes are **immutable**
```py
class Starship(NamedTuple):
  name: str
  registry: str
  crew: int
```
## unittest
By convention, tests are put in their own directory as sibling to the main module ( in order to be able to import it ).
Integration and unit tests should be organized separately.
```
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

A **test case**, which checks for a specific response to a particular set of inputs, is created by subclassing `unittest.TestCase`. <sup>[Python docs](https://docs.python.org/3.8/library/unittest.html)
The test case contains individual tests which are defined in methods with names starting with "test".
Within each test, a call to one of various **assertion**  methods is made which checks for an expected result.
- `assertEquals()`
- `assertTrue()`
- `assertIs()`
- `assertIsNone()`
- `assertIn()`
- `assertIsInstance()`
- `assertRaises()`

Finally, the **command line entry point** is made with a call to `unittest.main()`, which executes the tests.


Simple example<sup>[Real Python](https://realpython.com/python-testing/#how-to-use-unittest-and-flask "Getting Started With Testing in Python")</sup>
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
Notably, the test case subclasses you create must not have an `__init__()` constructor method defined, because this will produce an error while running the test.
## venv
Create a virtual environment named `project`
```sh
python -m venv project
```
## virtualenv
Create a virtual environment named `project` using a different installed Python interpreter
```sh
virtualenv -p /usr/bin/python2 project
```
## weakref
Support **weak references**, that is, references to objects which return exceptions when that object has been garbage collected
Create a weak reference to {object} 
```py
# A weak reference created using `ref` must be dereferenced 
r = weakref.ref(obj) 
r().method() 
r.method()          # will not work

# A weak reference created using `proxy` does not need to be dereferenced:
weakref.proxy(obj)
```
## winrm
**Winrm** allows you to connect Linux and Windows hosts over WinRM. <sup>[adamtheautomator.com](https://adamtheautomator.com/winrm-linux-remoting/ "Step-by-step guide on how to set up WinRM on a Linux client") </sup>
Begin a WinRM session. If no errors are thrown, the session has been successfully established
```py
session = winrm.Session(ipaddress,auth=(username,password))
```
# Python packages
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
##### click.group
Nesting commands
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
### Scrapy
Best used to obtain one "stream" of data at a time, without trying to obtain data from different pages
```sh
scrapy runspider spider.py -o file.json
```
#### Scrapy shell
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
#### Pagination
Extract URL from link using standard CSS selection techniques

Add the domain name to a relative link
```python
response.urljoin()
```
Recursively call the `parse` method again on the next page
```python
yield scrapy.Request(url=next_page_url, callback=self.parse)
``` 
#### Scrape detail pages
  - `parse_details` would be a spider method _sibling_ to the main `parse` method
  - if a detail page has more information than the main, then the `yield` keyword should be in `parse_details`
```python
yield scrapy.Request(url={url}, callback=self.parse_details)
```
