# Classic Computer Science Problems in Python

## 1. Small Problems

### Fibonacci sequence
_Fibonacci sequence_ is the sequence of numbers such that every number, except for the first and second, is the sum of the previous two:
0, 1, 1, 2, 3, 5, 8, 13, 21 ...

fib(n) = fib(n-1) + fib(n-2)

```py
def fib1(n: int) -> int:
  return fib1(n-1) + fib1(n-2)
```

This causes `RecursionError` because we didn't specify _base cases_, which in the case of recursive functionsspecify stopping points.

```py
def fib2(n: int) -> int:
  if n < 2: # base case
    return n
  return fib2(n-2) + fib2(n-1)
```

Calls with even moderately higher arguments will not execute, because the call tree grows exponentially (each call to `fib2()` results in two more.

_Memoization_, where you store the results of computational tasks so they can be used when needed, can be implemented.

```py
from typing import Dict
memo: Dict[int,int] = {0: 0, 1: 1} # base cases

def fib3(n: int) -> int:
  if n not in memo:
    memo[n] = fib3(n-1) + fib3(n-2) # memoization
  return memo[n]
```

Python has a built-in decorator for memoizing any function automagically: `@functools.lru_cache()`, which can be used with `fib2()`: every time the function is called with a new argument, the result is cached.

```py
from functools import lru_cache

@lrucache(maxsize=None)
def fib4(n: int) -> int:
  if n < 2: # base case
    return n
  return fib4(n-2) + fib4(n-1)
```

An old-fashioned, iterative approach is the most performant: recursion is the most intuitive way to solve a problem, but any naive recursion can be converted to iteration.

```py
def fib5(n: int) -> int:
  if n==0: return n
  last: int = 0 # initially set to fib(0)
  next: int = 1 # initially set to fib(1)
  for _ in range(1,n):
    last, next = next, last + next
  return next
```

Using generators:

```py
from typing import Generator

def fib6(n: int) -> Generator[int, None, None]:
  yield 0
  if n > 0: yield 1
  last: int = 0 # initially set to fib(0)
  next: int = 1 # initially set to fib(1)
  for _ in range(1,n):
    last, next = next, last + next
    yield next
```


### Trivial compression
Gene sequences waste a lot of space if stored as strings; preferably they can be stored as two bits to form _bit strings_. `_compress_` shifts the string left by two bits on each iteration and adds the appropriate nucleotide bit value (using `|=` operator), but perhaps addition would work as well

```py
def _compress(self, gene: str) -> None:
  self.bit_string: int = 1
  for nucleotide in gene.upper():
    self.bit_string <<=2
    if nucleotide == "A":
      self.bit_string |= 0b00
    if nucleotide == "C":
      self.bit_string |= 0b01
    if nucleotide == "G":
      self.bit_string |= 0b10
    if nucleotide == "T":
      self.bit_string |= 0b11
    else:
      raise ValueError(f'Invalid Nucleotide:{nucleotide}')
```


