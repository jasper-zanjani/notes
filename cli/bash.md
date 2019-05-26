# Bash

## Command-line options
  - single alphanumeric character preceded by a hyphen
  - `--` ends all command-line option arguments, subsequent arguments are non-option arguments
  - `getopt` and `argp_parse` reorder the elements of `argv` by default, but this behavior can be suppressed by setting the `_POSIX_OPTION_ORDER` environment variable
  - long names are conventionally preceded by `--`, and they may be abbreviated by users if unique
[GNU](https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html)

## Event designators
`!^` : first argument from previous command 
`!$` : last argument from previous command 
`^string` : repeat last command, deleting the first instance of {string} 
`^string^substitute` : repeat last command, substituting the first instance of {string} with {substitute} (CLKF) 
`!!:n` : {n}th argument from previous command 
`!#:n` : {n}th word of _current_ command

## Configuration
`C:\Program Files\Git\etc\profile.d\git-prompt.sh` : Git Bash `.bashrc` location
`PS1` : environment variable accepting a string of escaped character sequences representing colors and strings

### Metacharacters
`\a` : a bell character
`\d` : the date (DDD MMM dd)
`\Dformat` : {format} is passed to `strftime` and the result is inserted into the prompt string; empty format results in a locale-specific time representation.
`\e` : escape character
`\h` : hostname, up to the first '.'
`\H` : hostname
`\j` : number of jobs currently managed by the shell
`\l` : basename of the shell's terminal device name
`\n` : newline
`\r` : carriage return
`\s` : name of the shell, basename of `$0` (portion following the final slash)
`\t` : time in 24 hour HH:MM:SS format
`\T` : time in 12-hour HH:MM:SS format
`\@` : time in 12-hour am/pm format
`\A` : time in 24-hour HH:MM format
`\W` : basename of `$PWD` with `$HOME` abbreviated with a tilde
`\w` : current working directory, with `$HOME` abbreviated with a tilde (using `$PROMPT_DIRTRIM` variable)
`\!` : history number of this command
`\#` : command number of this command
`\$` : if effective UID is 0, '#', otherwise '$'
`\nnn` : character whose ASCII code is the octal value 'nnn'
`\\` : backslash
`\[` : begin a sequence of non-printing characters (used to embed a terminal control sequence)
`\]` : end a sequence of non-printing characters

### Colors
ANSI/VT100 terminals and emulators can display colors and formatted texts by using _escape sequences_ (_escape character_ followed by _format code_, terminated by _m_).
`\e` | `\033` | `\x1B` : C-style octal code for escape character

### Symlinks
Windows traditionally does not support symlinks
- `ln -s` will create a copy instead
- `mklink /d {linkname} {directory}` use `mklink` command prompt command instead

## Syntax
`$((...))` : arithmetic expansion
`[...]` : alias for `test`
`$(...)` : command substitution
`${...}` : variable substitution
`${var:start:size}` : variable slicing
`filename{,.new}` : brace expansion makes multiple arguments from a single one

## Loops: `for i in ...`
Content of all loops is bracketed by `do` and `done`: `for i in ... do ...; done;` and `for ((i=0; i<N; i++)); do cmd; done;`
  - `for i in {01..07}; do cmd; done;`
  - `for i in {000..100}; do cmd; done;`
  - `for i in 1 2 3 4 5; do cmd; done;`

## Number bases `${radix}#${number}`
`2#1111001110011010` : binary 
`0x32` : hex numbers 
`032` : octal 
`32#@_` : base-32: a range of ASCII characters can be used to define numbers with bases up to 64: 10 digits, 26 lowercase characters, 26 uppercase characters, '@', and '_' 

## Commands
`echo "hello" | pbcopy` : put text onto the Mac OS X clipboard ("PasteBoard") 
`ls | sort -R | sed 1q | xargs bat` : send a random file from within the current directory to `bat` for display 
`open .` : open current directory in Finder (osx)
`open -a /Applications/application.app` : open {application} from Terminal (osx)
`explorer.exe .` : open current directory in Explorer (win)

## `case` statement

