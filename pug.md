# Pug
Jade is the old name for the Pug template engine
## Multiline
`|` at same level of indentation (Jade)
  `p bla bla bla bla`
  `| bla bla bla bla`
`{tag}.` with an additional level of indentation (Pug)
  `p.`
  `bla bla bla bla bla`

- `!=`
- Use pipe to add mustaches in _Vue_ and other frameworks

## Mixins
`mixin NAME` define mixin
  - `mixin list`
    `ul`
    `  li foo`
    `  li bar`
    `  li baz`
`+NAME` call mixin
  - `+list`
`mixin NAME(var)` pass in variables
  - `mixin pet(name)`
    `  li.pet= name`
  - `+pet('cat')`
    `+pet('dog')`
    `+pet('pig')`
  - `mixin article(title='Default Title')` default values
`mixin list(id, ...items)` rest operator (`...`)
`ul(id=id)`
`  each item in items`
`    li= item`
