# setuptools

Setuptools is for uploading to PyPi. To create self-contained executable files, use [**pyinstaller**](#pyinstaller).

```
PROJECT
├── PROJECT # (1)
│   └── init.py
└── setup.py # (2)

1 directory, 2 files
```

1. Additional code files will be placed in here
2. Containing a call to **setuptools.setup()**
```py title="setup.py"
import setuptools

setuptools.setup(
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
If the package has dependencies, they can be added by appending an **install\_requires** keyword argument passing an array of the module names
```python
setup(
  install_requires=[ 'markdown', ],
)
```

Reserve the name, upload package metadata, and create the pypi.python.org webpage
```py
python setup.py register
```
Create a source distribution, producing a tarball inside the top-level directory
```py
python setup.py sdist
```
Upload the source distribution
```py
python setup.py sdist upload
```
Do all the above in a single step
```py
python setup.py register sdist upload
```