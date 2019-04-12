# Python
## alternative data types
### list (FP:54-56)
`array` 
: alternative to lists which is much more efficient for holding millions of numbers (FP:47-50)
`memoryview` 
: built-in class, inspired by NumPythat lets you read and write data without moving bits around (FP:51)
`collections.deque` 
: thread-safe double-ended queue
### queues implemented in stdlib packages (FP:56-57)
  - `queue`: `Queue`, `LifoQueue`, `PriorityQueue`
  - `multiprocessing`: `Queue`, `JoinableQueue`
  - `asyncio`: `Queue`,`LifoQueue`, `PriorityQueue`, `JoinableQueue`
  - `heapq`: functions `heappush` and `heappop` treat any mutable squence as a heap queue or priority queue
### dict (FP:75)
`collections.OrderedDict` 
  maintains keys in insertion order
`collections.ChainMap` 
  lookups are performed on each mapping in order
`collections.Counter`
  - holds an integer count for each key
  - each new key adds to the count
`collections.UserDict` 
  designed to be subclassed
## research needed
`bisect(haystack,needle)` 
  FP:44
`bisect.insort` 
  insert an item into a sorted iterable, maintaining sort (FP:46)
  Chapter 3 of FP on dicts was rather over my head
### list comprehension
`genexp` 
  generator expressions use the same syntax as list comprehensions, but are enclosed in parentheses rather than brackets (FP:25)
### dummy variables
`for country, _ in traveler_ids: print(country)`
  - `traveler_ids= [('USA', '31195855'), ('BRA', 'CE342567)...]`
  - `_` is a throwaway "dummy" variables
  - (FP:27)
### `*` unpacking operator
  - (FP:28)
## Class methods
`__init__(self)`
: - initialize instances of that class
`__repr__()`
: allows Python to use the `eval()` command on the string outputted by `repr()` to reconstruct the object
`!r`
: flag that forces f-strings to use `__repr__()`
`@classmethod`
`@staticmethod`
`self`
  - Python keyword that represents the instance itself. parameter with which instance methods can freely access attributes and other methods on the same object
## File handling
`with open(filename,['r'][,encoding="utf-8"]) as f:...`
: read files (`r` positional parameter optional)
`with open(filename,'w') as f:...`
: writing files (`w` positional parameter _necessary_)
`data=f.read().splitlines()`
: import a `txt` file with newlines stripped
`data=f.readlines()`
: newlines will be in there
`data=[r for r in f]`
: identical to `readlines` method above
## Context managers
`with`
  - useful in managing system resources
  - typical use case is opening and closing files
  - abstracts the pattern:
    ```py
    f=open('hello.txt','w')
    try:      f.write('hello world')
    finally:  f.close()
    ```
### special methods
`__enter__(self)`
: called when `with` statement is invoked; returned value is assigned to the variable after the `as` keyword
`__exit__(self)`
: called when indentation level returns to normal and interpreter leaves `with` block
### Pizza class
`Pizza(['cheese', 'tomatoes'])`
Modify class by addition of factory methods that return ingredients of well-known pizzas
  ```py
  class Pizza:
    '''
    define a class that returns an f-string of its own ingredients
    '''
    def __init__(self, ingredients):
      self.ingredients = ingredients
    def __repr__(self):
      return f'Pizza({self.ingredients!r})'
    @classmethod
    def margherita(cls):
      return cls(['mozzarella', 'tomatoes'])

    @classmethod
    def prosciutto(cls):
      return cls(['mozzarella', 'tomatoes', 'ham'])
  Pizza.margherita() # output: Pizza(['mozzarella', 'tomatoes'])
  Pizza.prosciutto() # output: Pizza(['mozzarella', 'tomatoes', 'ham'])
  ```
## Decorators
[Real Python](https://realpython.com/primer-on-python-decorators/#reusing-decorators)
## other syntax
`\` 
  join two adjacent physical lines into a single logical line by placing a backslash at the end of the first physical line (with no comment). Multiple subsequent lines, called continuation lines, can be added to the logical line.
### lambda
#### sorted
#### functools.reduce

## Command-line applications
### [Python Toolkit](http://pythontoolkit.sourceforge.net/) (obs.)
### [Python Prompt Toolkit](https://github.com/prompt-toolkit/python-prompt-toolkit)
### [Click](https://github.com/pallets/click)
## GUI applications
### tkinter
### PyQt
### wxpython
source: [Real Python](https://realpython.com/python-gui-with-wxpython/)
`pip install wxpython`
: install wxpython package
```py
import wx
app = wx.App()
frame = wx.Frame(parent=None, title='Hello World')
frame.Show()
app.MainLoop()
```