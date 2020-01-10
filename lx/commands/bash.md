### `bash`
Variable                                            | Effect
:---                                                | :---
`${string//search/substitution}`                    | replace all matches of {search} with {substitution} within {string}
`${string/#search/substitution}`                    | replace {search} with {substituion} if it occurs at start of {string}
`${string/%search/substitution}`                    | replace {search} with {substituion} if it occurs at end of {string}
`${string/search/substitution}`                     | replace first match of {search} with {substitution} within {string}
`${string##substring}`                              | delete longest match of {substring} from start of {string}
`${string#substring}`                               | delete shortest match of {substring} from start of {string}
`${string%%substring}`                              | delete longest match of {substring} from end of {string}
`${string%substring}`                               | delete shortest match of {substring} from end of {string}
`$_`                                                | return last field of the last command
`$!`                                                | return process ID (pid) of the last job run in the background
`$?`                                                | return exit status of the last executed function or command
`$@`                                                | return all command line arguments as an array of strings
`$*`                                                | return all positional parameters in a single string separated by space
`$#`                                                | return number of positional arguments passed to the script or function
`$$`                                                | return process ID (pid) of the current process
`$BASH_ENV`                                         | environment variable pointing to the Bash startup file which is read when a script is invoked
`$BASH_VERSINFO`                                    | array containing the full version information split into elements
`$BASH_VERSION`                                     | string that shows the version of bash that is running
`$BASHPID`                                          | process ID of the current bash instance (see `$$`)
`$EDITOR`                                           | default editor that will be invoked by any scripts or programs (usually `vi` or `emacs`)
`$FUNCNAME`                                         | name of the current function
`$GROUPS`                                           | array containing the numbers of groups the user is a member of
`$HISTFILE`                                         | location of the history file (~/.bash_history by default)
`$HISTFILESIZE`                                     | maximum number of events saved between sessions
`$HISTSIZE`                                         | maximum number of events saved during a session
`$HOME`                                             | home directory of the user
`$HOSTNAME`                                         | hostname assigned to the system during startup
`$HOSTTYPE`                                         | identifies hardware
`$IFS`                                              | internal field separator, used when bash is splitting strings while looping, etc (white space characters by default)
`$LANG=C`                                           | cause programs to bypass locale translations
`$LINENO`                                           | line number of the current script (useful when debugging)
`$MACHTYPE`                                         | identifies hardware but includes OS information (rf. `$HOSTTYPE`)
`$OLDPWD`                                           | return working directory before the last `cd` command
`$OSTYPE`                                           | type of OS running on the machine
`$PATH`                                             | search path for finding binaries for commands
`$PIPESTATUS`                                       | array containing the exit statuses of the commands in the most recent foreground pipeline
`$PPID`                                             | process ID of the script or shell's parent (the process that invoked the current script or shell)
`$PWD`                                              | return current working directory
`$RANDOM`                                           | a random integer between 0 and 32767
`$REPLY`                                            | default reply used by `select` and `read`
`$SECONDS`                                          | number of seconds the script has been running
`$SHELL`                                            | name of user's default shell ('/bin/bash')
`$SHELLOPTS`                                        | list of options bash is supplied on startup to control its behavior
`$SHLVL`                                            | number of shell levels the current shell is running on top of
`$TMOUT`                                            | log users out of shell automatically after a certain period of inactivity
`$TMOUT=n`                                          | exit the shell if no command is typed after `n` seconds; also affects the `read` command and `select` loop
`$TMPDIR`                                           | place temporary files created and used by the shell in `directory`
`$TMPDIR=directory`                                 | place temporary files created and used by the shell in directory
`$UID`                                              | user's ID number
`$WAYLAND_DISPLAY`                                  | determine if Wayland is running (example output: `wayland-0`) [^](https://docs.fedoraproject.org/en-US/fedora/f31/system-administrators-guide/Wayland/ "docs.fedoraproject.org - The Wayland Display Server")
`$XDG_SESSION_TYPE`                                 | display compositor (e.g. `wayland`)


#### Heredoc
**"Here Documents"** or **"Heredocs"** consist of double less-than `<<` followed by an arbitrary character sequence which will be used as delimeter, typically "EOF".
```sh
cat << EOF
1 a
2 b
3 c
EOF
```
Variable substitution can take place in the heredoc, but if the delimiter is quoted (i.e. `"EOF"`), variables will not be substituted.
```sh
local y=3
cat << EOF
a=1
x=$y
```
Output:
```
a=1
x=3
```
Here string
```sh
wc -c <<< "$x"
```

### `let`
Perform arithmetic as specified by one or more `expressions`
```sh
let  expressions | ((expressions))
```
### `source`
Execute commands from a file in the current shell
```sh
source file
. file
```
