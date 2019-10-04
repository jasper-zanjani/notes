# Python packaging

#### Directory structure
```
PROJECT
├── PROJECT     # Additional code files will be placed in here
│   └── init.py
└── setup.py    # Containing a call to `setuptools.setup()`

1 directory, 2 files
```
setup.py
```python
from setuptools import setup

setup(
  name='funniest',
  version='0.1',
  description='The funniest joke in the world',
  url='http://github.com/storborg/funniest',
  author='Flying Circus',
  author_email='flyingcircus@example.com',
  license='MIT',
  packages=['funniest'],
  zip_safe=False
)
```
If the package has dependencies, they can be added by appending a `install_requires` keyword argument passing an array of the module names
```python
..., install_requires=[ 'markdown', ], ...
```


### .gitignore
```
*.pyc
/dist/
/*.egg-info
```

## Publishing on PyPI
`python setup.py register` : reserve the name, upload package metadata, and create the pypi.python.org webpage
`python setup.py sdist` : create a source distribution, producing a tarball inside the top-level directory
`python setup.py sdist upload` upload the source distribution
`python setup.py register sdist upload` do all the above in a single step

## Sources
- "How to package your Python code". [Read the Docs](https://python-packaging.readthedocs.io/en/latest/)
- "Building and distributing packages with [`setuptools`]()". [Web](https://setuptools.readthedocs.io/en/latest/setuptools.html)
