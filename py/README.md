[PiaN]: # "Python in a Nutshell"
[FP]: # "Fluent Python"
[Ortega]: # "Jose Manuel Ortega et al. _Learning Python Networking Second Edition_."

# Python
- [Python](#python)
  - [Modules](#modules)
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
    - [optparse](#optparse)
    - [os](#os)
    - [pathlib](#pathlib)
    - [platform](#platform)
    - [pythonnet<sup>?[^](http://pythonnet.github.io/)</sup>](#pythonnetsupsup)
    - [random](#random)
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

## Modules
### argparse
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
### array 
`frombytes`
`tofile`
(FP:48-50, PiaN:375)
### bisect
### collections
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
### contextlib
Build a context manager out of **generator functions** - function it decorates must run exactly twice (typically `try ... yield finally ...` structure) - `yield` can pass a value back (can be assigned to variable after `as` keyword)\
```py
@contextmanager
```
`capsys fixture` - from pytest allows access to stdout/stderr output generated during text execution
`contextlib.redirect_stdout` - context manager temporarily redirects `sys.stdout` to another file or file-like object
### csv
##### csv.reader
```py
with open('file.csv', newline=''):
  data = [row for row in csv.reader(f)]
```
### ctypes
### curses
make sure `pdcurses.dll` is in both Python's root directory (C:\Users\jaspe\AppData\Local\Programs\Python\Python37, for instance) as well as the directory where the script is located. This file must be compiled from source code using the make program
curses.textpad
curses.ascii
curses.panel
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
### getpass
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
### json
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
### platform
### pythonnet<sup>[?](https://github.com/pythonnet/pythonnet "Github")[^](http://pythonnet.github.io/)</sup>
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
### sys
Return site-specific directory where Python files are installed 
```py
sys.prefix          # /usr/local/ by default
```
### termcolor
Print {text} in a color code
```py
from termcolor import cprint

cprint(text,color)
```
### typing
##### typing.NamedTuple
As tuples, their attributes are **immutable**
```py
class Starship(NamedTuple):
  name: str
  registry: str
  crew: int
```
### unittest
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
### urllib
#### urllib.request
Download an RFC file from rfc-editor.org <sup>[Ortega][Ortega]</sup>
```py
rfc_raw = urllib.request.urlopen(url).read()
rfc = rfc_raw.decode()
```
### venv
Create a virtual environment named `project`
```sh
python -m venv project
```
### virtualenv
Create a virtual environment named `project` using a different installed Python interpreter
```sh
virtualenv -p /usr/bin/python2 project
```
### weakref
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
### winrm
**Winrm** allows you to connect Linux and Windows hosts over WinRM. <sup>[adamtheautomator.com](https://adamtheautomator.com/winrm-linux-remoting/ "Step-by-step guide on how to set up WinRM on a Linux client") </sup>
Begin a WinRM session. If no errors are thrown, the session has been successfully established
```py
session = winrm.Session(ipaddress,auth=(username,password))
```
