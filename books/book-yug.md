# _Your Unix: The Ultimate Guide_ by Sumitabha Das
  commands: passwd who tty mkdir cd cat

## Definitions
operating system
: interacts with the applications that require access to the machine's hardware and with the user who passes commands to it

command language interpreter
: used by user to pass commands to the operating system

<^d>
: log out of shell (equivalent to `logout`)

runlevel
: current state of operating system on Unix-like systems [TecMint](https://www.tecmint.com/change-runlevels-targets-in-systemd/)

##  0. Intro
Unix can be broadly divided into two schools
  1. System V from AT&T Bell Laboratories (SVR4 last version release before being rolled up)
  2. Berkeley from the University of California, Berkeley (BSD) 

##  1.0. Getting Started
### The Operating System
### The UNIX Operating System
### Knowing your machine
### Knowing your keyboard
### The System Administrator
### Logging in and out
### Trying out some commands
### Two important observations
### When things go wrong
### Yet another session: working with files and directories
### How it all clicked
### Linux and GNU
### Inside UNIX

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
##  3.   General-purpose Utilities
### 3.1. `passwd`: change your password
### 3.2. `who` and `w`: know the users
### 3.3. `tty`: know your terminal
### 3.4. `lock` lock your terminal
### 3.5. `stty` set terminal characteristics
### 3.6. `script` record your session
### 3.7. `clear` and `tput`: clear your screen
### 3.8. `uname` know your machine's name
### 3.9. `date` display the system date
### 3.10. `cal` calendar
### 3.11. `calendar` a useful reminder mechanism
### 3.12. `bc`: the calculator
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
### 4.5 exit to the UNIX shell
### 4.6. the repeat factor
### 4.7. the command mode
### 4.8. navigation
### 4.9. operators
### 4.10. Deleting, moving, and yanking text
### 4.11. Changing text (`c` and `~`)
### 4.12. The dot: repeating the last command
### 4.13. Undoing last editing instructions (`u` and `U`)
### 4.14. String search
### 4.15. Searching with regular expressions
### 4.16. Search and replace (`:s`)
### 4.17. Handling multiple files
### 4.18. Marking text
### 4.19. Filtering text - the `!` operator
### 4.20. Named buffers: copying and moving multiple text sections
### 4.21. Recovering multiple deletions
### 4.22. Abbreviating text (`:ab`)
### 4.23. Customizing the keyboard (`:map`)
### 4.24. Customizing the environment (`:set`)
##  5. The GNU emacs Editor
### 5.1.  `emacs` preliminaries
### 5.2.  Quitting `emacs`
### 5.3.  Inserting and replacing text
### 5.4.  Saving text
### 5.5.  The digit argument
### 5.6.  Navigation
### 5.7.  Working with regions
### 5.8.  Deleting, moving, and copying text
### 5.9.  Changing case of text
### 5.10. Command completion
### 5.11. Undoing and redoing editing
### 5.12. String search
### 5.13. Searching with regular expressions
### 5.14. Search and replace
### 5.15. Using multiple files, windows and buffers
### 5.16. Escape to shell
### 5.17. Using the help facility
### 5.18. Marking text
### 5.19. Filtering text
### 5.20. Storing multiple text sections
### 5.21. Recovering multiple deletions (*[Alt-y]*)
### 5.22. Abbreviating text (`abbrev-mode`)
### 5.23. Customizing the keyboard
### 5.24. Using macros
### 5.25. Customizing the editor environment
##  6. The File System
##  7. File Attributes
##  8. The Shell
##  9. Simple Filters
## 10. The Process
## 11. TCP/IP Networking Tools
## 12. The X Window System
## 13. Electronic Mail
## 14. The Internet
## 15. Filters Using Regular Expressions
## 16. Programming with awk
## 17. Customizing the Environment
## 18. Shell Programming
## 19. Advanced Shell Programming Including Korn and bash
## 20. perl - the Master Manipulator
## 21. System Administration I - The File System Revisited
## 22. System Administration II - The General Duties
## 23. TCP/IP Network Administration
## 24. Going Further - Building the Internet Server
