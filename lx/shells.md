[NVMe]: # 'Nonvolatile Memory Express (NVMe)&#10;Next-generation interface protocol for accelerated communication between the processor and flash storage hardware.&#10;NVMe was initially limited to the consumer market and intended for smartphones and large enterprise storage. It supports up to 64,000 parallel queues with 64,000 commands per queue, and thus delivers significantly higher performance than the previously predominant SAS and SATA hard disk interfaces.&#10;_Admin Magazine_. Issue 54, Feb/Mar 2020.: 16'

[NVMe][NVMe]
# Shells
## bash
- `getopt` and `argp_parse` reorder the elements of `argv` by default, but this behavior can be suppressed by setting the `_POSIX_OPTION_ORDER` environment variable
#### Terminal prompt


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
## Elvish shell
### if/else
```elvish
~> if $true { echo good } else { echo bad }
```
### for loop iterating over an array
```elvish
~> for x [lorem ipsum] {
     echo $x.pdf
   }
```
### try/catch block and raising an error
```elvish
~> try {
     fail 'bad error'
   } except e {
     echo error $e
   } else {
     echo ok
   }
```
## Fish
#### Fish color variables
  - `fish_color_normal`
  - `fish_color_command`
  - `fish_color_quote`
  - `fish_color_redirection` 

## Sources
  1. [gnu.org](https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html)
  2. [putorius.net](https://www.putorius.net/bash-using-control-operators.html)
  3. "Using Variables in `bash`" [opensource.com](https://opensource.com/article/19/8/using-variables-bash): 2019/08/26.
  4. [ItsFOSS](https://itsfoss.com/elvish-shell/)