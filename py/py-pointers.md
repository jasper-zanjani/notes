# Python pointers
Python, which emphasizes abstraction and usability, does __not__ support pointers natively. But there are some features of Python which provide the benefits of pointers.
  - `id(object)` Return {object}'s memory address
  - `object is other` return True if {object} and {other} share the same memory address

Mutable primitives (`list`, `set`, `dict`) can be used to simulate pointers, since their memory address will not change. Custom objects can also be used to recreate the behavior of pointers. Lastly, the `ctypes` module allows you to use shared libraries compiled from C programs, calling C functions from within Python.
## Further reading
  - "Extending Python with C Libraries and the 'ctypes' Module" [dbader.org](https://dbader.org/blog/python-ctypes-tutorial)
  - "Primer on Python Decorators" [realpython.com](https://realpython.com/primer-on-python-decorators/)
## Sources
  - "Pointers in Python" [realpython.com](https://realpython.com/pointers-in-python/)