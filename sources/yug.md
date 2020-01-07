# _Your Unix: The Ultimate Guide_ by Sumitabha Das

##  2.   Understanding the UNIX Command
commands: `type`, `man`, `info`, `whatis`, `apropos`, `less`, `more`
### 2.1. General features of a command
  - case-insensitive
  - commands are files, mostly written in C
### 2.2. `PATH`: locating commands
  - directories separated by colon `:`
  - shell will search directories listed in order
  - `type` command displays location of a command file
### 2.3. Internal and external comands
  - some commands are shell built-ins, like `type`, known as internal commands; others are external commands
### 2.4. Command structure
  - every command is made of words separated by whitespace, only the first command is the real command, the rest are arguments 
  - never make a filename beginning with a hyphen, this will cause problems
### 2.5. Flexibility of command usage
  - commands can be combined on the same line by separating them with a semicolon
  - output and input can be redirected
  - commands can be entered over multiple lines, and the shell will display secondary prompt `>`
  - shell will wait for command to finish executing, but subsequent commands can still be entered, they will be entered into a type-ahead `buffer`
### 2.6. `man`: online help
  - `more` Berkeley's pager program, which replaces the original `pg` by AT&T (`--More--` appears at bottom)
  - `less` standard pager on Linux systems, modeled on vi (`:` appears at bottom)
### 2.7. `man` documentation
  - generally 8 sections of the UNIX manual
  - `man 1 cp` specify section 1, same as `man cp`
  - NAME, SYNOPSIS, and DESCRIPTION headers are generally seen in all man pages
### 2.8. `info`: Texinfo documentation
  - more up-to-date body of documentation with interface based on emacs
### 2.9. `whatis` and `apropos`
  - `whatis` provides a one-line answer to what a command does
  - `apropos` search for keywords within whatis descriptions
##  4.   The vi/vim Editor
### 4.1. `vi` preliminaries
The three modes and the `.exrc` file, 
### 4.2. Quitting `vi`, the last line mode
- Saving and quitting (`:wq` and `:x`)
- Aborting editing (`:q`)
### 4.3. Inserting and replacing text
- inserting text (`i` and `I`)
- appending text (`a` and `A`)
### 4.4 Saving text `:w`
- writing selected lines
- recovering from a crash

## Electronic mail
### `mail`
The earliest mail handling tool "still' offered by all UNIX systems (ca. 2001).
### `elm`
### `pine`
"Program for Internet news and e-mail", featuring an interface similar to the `nano` text editor and developed at the University of Washington. [[^][YUG]: 372]

Option  | Effect
:---    | :---
`-I`    | Execute 


[mail]: # ""
[pine]: ../lx/commands/mail.md#pine "\"Program for Internet news and email\", popular mailer during the 1990s which has since been replaced by the Alpine client."
[YUG]: # "Das, Samitabha. _Your Unix: The Ultimate Guide_. McGraw-Hill, 2001."