# Perl

## General syntax
- Semicolons terminate lines
- Whitespace is irrelevant, except inside strings
- Double-quotes allow escaped characters to be rendered as intended, but single-quotes will render the text naively
- arguments to functions can be enclosed in parentheses, or delimited by a single space, to taste
`#!/usr/bin/env perl`
: shebang

## Command-line invocation options
`-e 'code'`
: execute {code} inline (MP:17)
`-w`
: enable warning messages
`-n`
: request an implicit input-reading loop that stores records in `$_`
`-p`
: request an implicit input-reading loop that stores records in `$_` and automatically prints that variable after optional processing of its contents
`-l`
:automatically insert an output record separator at end of the output of `print`
`-0digits`
: define the character that marks the end of an input record, using octal digits

## Data types and variables
`my $animal = "camel"`
: `my` keyword declares a variable

### Arrays
`my @animals = ('camel', 'llama', 'owl')`
: `@` prepended to identifier of arrays; shell-style with parentheses and not square brackets
`print $animals[0]`
: standard 0-based array indexing

### Hashes
Hashes are key-value pairs
`my %fruits = (apple => red, ...)`
: declare a hash
