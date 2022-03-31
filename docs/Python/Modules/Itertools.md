# itertools

**cycle()** works like next(), but it restarts from the beginning of the iterable that is passed as argument after the last element has been reached.
```py
with open('raven') as f:
    raven = [ l for l in f ]

itertools.cycle(raven)
```
