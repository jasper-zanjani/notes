# Weakref

**Weak references** are references to objects which return exceptions when that object has been garbage collected
Create a weak reference to {object} 
```py
# A weak reference created using `ref` must be dereferenced 
r = weakref.ref(obj) 
r().method() 
r.method()          # will not work

# A weak reference created using `proxy` does not need to be dereferenced:
weakref.proxy(obj)
```
