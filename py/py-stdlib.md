# Standard Library

## argparse
`ArgumentParser(description=helptext)` where {helptext} contains usage that will appear with `-h` or `--help`
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

## array 
`import array`
`frombytes`
`tofile`
(FP:48-50, PiaN:375)

## bisect

## collections
`collections.namedtuple(name, *field_names` (FP:30-32) subclasses of `tuple` with field names and a class name
  - `Card = namedtuple('Card',['rank','suit'])`
  - `City = namedtuple('City', 'name country population coordinates')`
`collections.deque` (FP:54-56, PiaN: 173) supports most `list` methods
`collections.abc` module provides `Mapping` and `MutableMapping` ABCs to formalize the interfaces of dict and similar types (FP:64)
`collections.defaultdict` (PiaN: 174)

## contextlib
`@contextmanager` - builds a context manager out of generator functions - function it decorates must run exactly twice (typically `try ... yield finally ...` structure) - `yield` can pass a value back (can be assigned to variable after `as` keyword)
`capsys fixture` - from pytest allows access to stdout/stderr output generated during text execution
`contextlib.redirect_stdout` - context manager temporarily redirects `sys.stdout` to another file or file-like object

## ctypes

## curses
make sure `pdcurses.dll` is in both Python's root directory (C:\Users\jaspe\AppData\Local\Programs\Python\Python37, for instance) as well as the directory where the script is located. This file must be compiled from source code using the make program
curses.textpad
curses.ascii
curses.panel

## datetime
difference between `datetime` objects is a `timedelta`
`datetime.date(2016,7,24)`
`datetime.date.today()`
`datetime.strptime(datestring,formatstring)` parse strings into datetime objects; various metacharacters are defined for `strptime`
`datetime.datetime.strptime('06/30/1992','%m/%d/%Y')` produce a `datetime` object

## functools
for higher-order functions (functions that act on or return other functions)
`functools.reduce(function, iterable [, initializer])` : apply `function` of two arguments cumulatively to the items of `iterable` in order to reduce it to a single value
`functools.reduce(lambda x, y: x+y, [1,2,3,4,5])` : calculates ((((1+2) +3) +4) +5)
`functools.reduce(lambda a,b: a*b, range(1,6))` => 120 : factorial

## getpass

## glob
`glob.glob('*.py')` produces a list of strings

## heapq
Support _heaps_, which are data objects where each node is either greater than or equal to its parent (max-heap) or less than or equal to its parent (min-heap)
`heapq.heappop(heap)`
: remove and return the smallest element of {heap}
`heapq.heapreplace(heap,element)`
: replace the smallest element of {heap} with {element}
`heapq.heapify(iterable)`
: create a heap from {iterable}

## json
`data=json.load(jsonfile)` parse a JSON file opened as `jsonfile`
`json.dump(data,jsonfile)` write {data} to a JSON file opened as `jsonfile`
`jsonfile.write(json.dumps(data, indent=4))` write {data} to a JSON file opened as `jsonfile`

## optparse
`parser = optparse.OptionParser(usage=__doc__.strip())` : after importing `optparse`, instantiate the parser object
`parser.add_option('--timeout')` : add an option

## os
`os.system('ls -la')` execute shell command given by string
`os.popen('ls -la').read()` store output in a variable
`os.chdir(path)`
`os.getcwd()`
`os.path.isfile(file)` return True if exists

## pathlib
`pathlib.Path(path)` create a new pathlib object; represents a file or directory
`pathlib.Path.is_file(file)` return True if {file} exists
`pathlib.Path.is_dir(dir)` return True if {dir} exists
`pathlib.Path.exists()`
`pathlib.Path.glob('*.py')` find all `.py` files; returns a generator
`pathlib.Path.open()` makes a file object that is automatically closed; builtin `open` function will also work
`pathlib.Path.suffix()` returns file extension
`pathlib.Path.stat().st_size` returns file size

## platform

## random
`random.choice(iterable)` random choice with replacement
`random.shuffle(iterable)` shuffle elements of an iterable in-place (FP:42)

## subprocess
__subprocess__ modules allows you to spawn new processes, interact with file descriptors, and obtain exit codes. The recommended approach is to use the `run()` function as default, which runs a CLI command with options as a list of strings and returns a `CompletedProcess` instance.
`subprocess.run('ls','-l,'.')` arguments and options are provided in a list
`subprocess.run(['ls','-l','/dev/null'], capture_output=True` will return a CompletedProcess instance with the command's output stored under `stdout`
`subprocess.run('exit 1', shell=True, check=True)` will raise a `CalledProcessError` exception because of the non-zero exit code

## sqlite3
`import sqlite3`
`conn = sqlite.connect('employee.db')` : create a `Connection` object and `employee.db` (binary) if it doesn't exist
`c = conn.cursor()` : create a `Cursor` object
`c.execute('''CREATE TABLE {tablename} ({field} {type}, {field} {type} ...))` perform SQL commands; create {tablename} with fields {field} of type {type} (null, integer, real, text, blob); never use Python's native string operations (f-strings, etc) to form commands, because this method is vulnerable to SQL injection
`conn.commit()` : save changes
`conn.close()`
[SQLite tutorial](https://youtu.be/pd-0G0MigUA)

## sys
`sys.prefix` : return site-specific directory where Python files are installed (/usr/local/ by default)

## termcolor
`cprint(text,color)` : print {text} in {color} (unix color)

## weakref
Support weak references, that is, references to objects which return exceptions when that object has been garbage collected
`weakref.ref(object)` : create a weak reference to {object} (which must be dereferenced in practice); i.e. `r = weakref.ref(obj); r.method() # will not work; r().method()`
`weakref.proxy(object)` : create a weak reference to {object} (which does not need to be dereferenced in use)

