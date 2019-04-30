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
`mixin NAME` 
: define mixin

`mixin NAME(var)`
: define a mixin with arguments

`+NAME`
: invoke mixin

`mixin article(title='Default Title')` 
: default values

`mixin list(id, ...items)` 
: rest operator (`...`) can be used to specify an unknown number of multiple items

### Example 1
```pug
mixin pet(name)
  li.pet= name`

+pet('cat')
+pet('dog')
+pet('pig')
```

### Example 2
```pug
mixin list
ul
  li foo
  li bar
  li baz

ul(id=id)
  each item in items
    li= item
```

## Includes
`include file`
: the keyword `include` is followed by {file} to be included

`include:markdown-it file`
: `markdown-it` is a filter, and it can be used to render a markdown {file} into HTML
