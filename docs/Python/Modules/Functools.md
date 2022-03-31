# Functools

For higher-order functions (functions that act on or return other functions)

Apply **function** of two arguments cumulatively to the items of **iterable** in order to reduce it to a single value
```py
functools.reduce(function, iterable [, initializer])
```

Calculate a cumulative sum
```py
functools.reduce(lambda x, y: x+y, [1,2,3,4,5])
```

