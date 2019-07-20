# Markdown

## Hyperlinks and images
`[Text](url)` : {Text} linking to {url} 
`![AltText](url)`: image at {url} with {AltText}

## Checkboxes
`- [ ] Item` : empty checkbox
`- [x] Item` : checked checkbox

## Newlines
GitHub does not honor single newlines: you have to use double newlines to achieve the effect or append `\` to the end of a line, **so long as there is no change in format from the current line to the next**

```markdown
> Foo\
> Bar
```

But the backslash is unnecessary if, for example, you are placing the checkbox within a blockquote for the next line:
```markdown
> Foo
> - [ ] Bar
```

## Links
In GitHub, relative links to other files in the repo are maintained
  - `[Readme](../README.md)` will link to the blob of README.md
  - `[Back](../)` will not work
  - `[Root](/)` also does not work
