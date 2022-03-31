# threading
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
