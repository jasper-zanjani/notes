### bash
- `getopt` and `argp_parse` reorder the elements of `argv` by default, but this behavior can be suppressed by setting the `_POSIX_OPTION_ORDER` environment variable
#### Terminal prompt
`$PS1` Metacharacters   | Effect
:---                    | :---
`\a`                    | a bell character
`\d`                    | the date (DDD MMM dd)
`\Dformat`              | {format} is passed to `strftime` and the result is inserted into the prompt string; empty format results in a locale-specific time representation.
`\e`                    | escape character
`\h`                    | hostname, up to the first '.'
`\H`                    | hostname
`\j`                    | number of jobs currently managed by the shell
`\l`                    | basename of the shell's terminal device name
`\n`                    | newline
`\r`                    | carriage return
`\s`                    | name of the shell, basename of `$0` (portion following the final slash)
`\t`                    | time in 24 hour HH:MM:SS format
`\T`                    | time in 12-hour HH:MM:SS format
`\@`                    | time in 12-hour am/pm format
`\A`                    | time in 24-hour HH:MM format
`\W`                    | basename of `$PWD` with `$HOME` abbreviated with a tilde
`\w`                    | current working directory, with `$HOME` abbreviated with a tilde (using `$PROMPT_DIRTRIM` variable)
`\!`                    | history number of this command
`\#`                    | command number of this command
`\$`                    | if effective UID is 0, '#', otherwise '$'
`\nnn`                  | character whose ASCII code is the octal value 'nnn'
`\\`                    | backslash
`\[`                    | begin a sequence of non-printing characters (used to embed a terminal control sequence)
`\]`                    | end a sequence of non-printing characters

ANSI/VT100 terminals and emulators can display colors and formatted texts by using __escape sequences__ ( __escape character__ followed by __format code__, terminated by "m").\
Three escape characters:
  - `\e` 
  - `\033`
  - `\x1B`

#### Syntax

Event designator        | Effect
:---                    | :---
`!^`                    | first argument from previous command 
`!$`                    | last argument from previous command 
`^string`               | repeat last command, deleting the first instance of {string} 
`^string^substitute`    | repeat last command, substituting the first instance of {string} with {substitute} ([CLKF](https://github.com/jasper-zanjani/notes/blob/master/sources.md))
`!!:n`                  | {n}th argument from previous command 
`!#:n`                  | {n}th word of _current_ command

Syntax                  | Effect
:---                    | :---
`$((...))`              | arithmetic expansion
`[...]`                 | alias for `test`
`$(...)`                | command substitution
`${...}`                | variable substitution
`${var:start:size}`     | variable slicing
`filename{,.new}`       | brace expansion makes multiple arguments from a single one

Content of all loops is bracketed by `do` and `done`: `for i in ... do ...; done;` and `for ((i=0; i<N; i++)); do cmd; done;`
  - `for i in {01..07}; do cmd; done;`
  - `for i in {000..100}; do cmd; done;`
  - `for i in 1 2 3 4 5; do cmd; done;`

Number bases            | Description
:---                    | :---
`r#n`                   | general format for interpreting number <n> as having base (radix) <r>
`2#1111001110011010`    | binary 
`0x32`                  | hex numbers 
`032`                   | octal 
`32#@_`                 | base-32: a range of ASCII characters can be used to define numbers with bases up to 64: 10 digits, 26 lowercase characters, 26 uppercase characters, '@', and '_' 

Command sequence syntax | Effect
:---                    | :---
`;`   | run commands synchnonously
`&`   | run commands asynchronously
`&&`  | logical AND; run next command synchronously only if first command succeeds
`||`  | logical OR; run next command synchronously only if first command fails
#### Variables
[[3](#sources)]
## Sources
  1. [gnu.org](https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html)
  2. [putorius.net](https://www.putorius.net/bash-using-control-operators.html)
  3. "Using Variables in `bash`" [opensource.com](https://opensource.com/article/19/8/using-variables-bash): 2019/08/26.