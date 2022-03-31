# Click

Click modifies functions using decorators whch determine the command-line arguments elements that the decorated function can see.

[Hello, World](https://click.palletsprojects.com/en/7.x/quickstart/#screencast-and-examples "Quickstart - Click Documentation")
```py
import click

@click.command()
def hello():
  click.echo('Hello World!')

if __name__ = '__main__':
  hello()
```
Modified Hello World
```py
import click

@click.command()
@click.option('--count', default=1, help='number of greetings')
@click.argument('name')
def hello(count, name):
  for x in range(count):
    click.echo('Hello %s!' % name)

if __name__ == '__main__':
  hello()
```

Developing the pdfcropper tool; passing **--examref** changes the numbers.
```py
import click

@click.command()
@click.option('--examref',is_flag=True)
def hello(examref):
  top, right, bottom, left = 0,0,0,0
  if examref:
    top, right, bottom, left = 1, 2, 3, 4
  click.echo(f'Your numbers are: top ({top}), right {right}, bottom {bottom}, left {left}')

if __name__ == '__main__':
  hello()
```
**@click.group()** decorators allow nested command groups to be created.
There are two ways of adding commands to command **groups**:
- Using the group as a decorator, whereby the name of the function decorated by `@click.group()` is then used to 
decorate commands:
```py
@click.group()
def group1()
  pass

@group1.command()
def command1():
  pass
```

- Using the `add_command` method
```py
@click.group()
def group1()
  pass

@click.command()
def command1():
  pass

group1.add_command(command1)
```

For example, to imitate the nested commands available in `netsh`:
```cmd
netsh interface ip
```

```py
@click.group()
def interface():
  pass

@interface.command('ip')
@click.argument('args', nargs=-1) # All arguments passed in as tuple "args"
def interface_ip(args):
  pass
```

Docstrings of groups and commands show up as progressive help messages when they are invoked from the command-line.

```py
@click.group()
def cli():
  pass

@click.command()
def initdb():
  click.echo('Initialized the database')

@click.command()
def dropdb():
  click.echo('Dropped the database')

cli.add_command(initdb)
cli.add_command(dropdb)

if __name__ == '__main__':
  cli()
```
**CommandCollection** flattens the structure of grouped commands so that the commands in all the contained groups
appear in a single tier. It also becomes the entry-point of the script.

Example from [GitHub](https://github.com/limbov8/fire/blob/30c7c5abef35d203ad1217093623edc5b9bbc922/bin/fire):
```py
# Three command groups cli1, cli2, and cli3 declared:

@click.group()
def cli1():
  pass

@click.group()
def cli2():
  pass

@click.group()
def cli3():
  pass

# Three commands each belonging to a separate group

@cli1.command()
def server():
  pass

@cli2.command()
def console():
  pass

@cli3.command()
def routes():
  pass

# CommandCollection flattens the grouped commands such that all the commands are available at once:

cli = click.CommandCollection(sources=[cli1,cli2,cli3])

if __name__ == '__main__':
  cli()
```