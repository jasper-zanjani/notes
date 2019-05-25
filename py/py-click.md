## click
`import click`
`@click.command()`
  - general-purpose decorator
  - docstring will come up when `--help` invocation argument is passed
`@click.option('--string',default='world',help='This is the person greeted')`
  - add command-line options
  - option string itself defines the variable identifier within the code
    - option string has to begin with (at least one) `-`
    - `-` in the middle of the string become underscore `_` in the variable identifier
`@click.argument('out', required=False,type=click.File('w'))`
  - arguments are mandatory by default
  - arguments do not take usage text: they must be documented within the docstring
`click.echo(f'Hello {name[0:-1]}{name[-1]*(n+1)}!', file=out)`
  - supposedly superior to `print`
  - will output to `out` argument
`out.write('\n{name} lives!\n')`
  - `out` is of type LazyFile (NFI)
