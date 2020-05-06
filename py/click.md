## `click`
General-purpose decorator, docstring will come up when `--help` invocation argument is passed
```py
@click.command()
```
Add command-line options ; option string itself defines the variable identifier within the code ; option string has to begin with (at least one) `-` ; `-` in the middle of the string become underscore `_` in the variable identifier
```py
@click.option('--string',default='world',help='This is the person greeted')
```
Arguments are mandatory by default; arguments do not take usage text: they must be documented within the docstring
```py
@click.argument('out', required=False,type=click.File('w'))
```
Supposedly superior to `print`; will output to `out` argument
```py
click.echo(f'Hello {name[0:-1]}{name[-1]*(n+1)}!', file=out)
```
```py
out.write('\n{name} lives!\n') # `out` is of type LazyFile (NFI)
```
