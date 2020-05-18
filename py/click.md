# click
Hello World program. <sup>[Click documentation](https://click.palletsprojects.com/en/7.x/quickstart/#screencast-and-examples "Quickstart - Click Documentation")
```py
import click

@click.command()
def hello():
  click.echo('Hello World!')

if __name__ = '__main__':
  hello()
```

Nesting commands
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
Developing the pdfcropper tool; passing `--examref` changes the numbers.
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