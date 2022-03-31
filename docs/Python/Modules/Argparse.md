# Argparse

The **ArgumentParser** object exposes an attribute that contains the value passed in from the command-line. This attribute takes its identifier from the **dest** keyword argument when invoking the **add_argument()** method.

```py
import argparse

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        dest='bar',
        description=helptext, # (1)
    )
    return parser.parse_args()

def main():
    args = get_args().bar
```

1. The optional value assigned to `description` will be displayed when running the script with the options **-h** or **--help**

A help string can be provided as a keyword argument to **`help`**.
```py
parser.add_argument("foo", help="bar")
```

A data type can be specified as an argument to **`type`**:
```py
parser.add_argument("foo", type=int)
```
An alternative name for the `dest` value on the command-line (but which does not affect the identifier of the attribute on which the value is exposed) can be specified by **`metavar`**.
```py
parser.add_argument("foo", metavar="bar")
```

The examples above used **positional parameters** (i.e. an argument). A **named parameter** (an option or flag, i.e. `-h`, `--help`, etc) requires <kbd>-</kbd> at the beginning of the string and values from the command-line to be passed after `=` or <kbd>Space</kbd>. `add_argument` supports the **`required`** keyword argument for named parameters. Note that use of the option on the command-line at all requires an argument to it, even if the option is not required itself.
```py
parser.add_argument('-r','--radius',type=int,required=True,help='radius')
```

A **flag option** can be created by defining an **`action`** keyword parameter. ([src](# "Tiny Python Projects p. 391))
```py
parser.add_argument('-o', '--on', help='A boolean flag', action='store_true')
```

**`add_mutually_exclusive_group()`** can be used to add a group of mutually exclusive arguments. In this case, `add_argument()` is invoked on the new object returned by this method and not directly on the `ArgumentParser()` object.
```py
g=ArgumentParser.add_mutually_exclusive_group()
g.add_argument("-v","--verbose", action="store_true")
g.add_argument("-q","--quiet","-s","--silent", action="store_true",help='quiet/silent mode')
```

User input can be restricted by providing a value for **`choices`**, which will accept any iterable value including lists, ranges, and strings:
```py
parser.add_argument("foo", choices=["bar","baz"])
parser.add_argument("foo", choices=range(1,10))
parser.add_argument("foo", choices='Hello, world!') # equivalent to ['H','e', ...]
```

Sources

- [:material-language-python: Python documentation](https://docs.python.org/3/library/argparse.html)
