# bash

- `getopt` and `argp_parse` reorder the elements of `argv` by default, but this behavior can be suppressed by setting the `_POSIX_OPTION_ORDER` environment variable


ANSI/VT100 terminals and emulators can display colors and formatted texts by using **escape sequences** ( **escape character** followed by **format code**, terminated by "m").\
Three escape characters:
  - `\e` 
  - `\033`
  - `\x1B`

| Event designator     | Effect                                                                                                                                                      |
| :------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `!^`                 | first argument from previous command                                                                                                                        |
| `!$`                 | last argument from previous command                                                                                                                         |
| `^$STRING`            | repeat last command, deleting the first instance of `$STRING`                                                                                                |
| `^$STRING^$SUBSTITUTE` | repeat last command, substituting the first instance of `$STRING` with `$SUBSTITUTE`  |
| `!!:n`               | {n}th argument from previous command (0-indexed)                                                                                                                        |
| `!#:n`               | {n}th word of **current** command (0-indexed)                                                                                                                         |

| Syntax              | Effect                                                     |
| :------------------ | :--------------------------------------------------------- |
| `$((...))`          | arithmetic expansion                                       |
| `[...]`             | alias for `test`                                           |
| `$(...)`            | command substitution                                       |
| `${...}`            | variable substitution                                      |
| `${var:start:size}` | variable slicing                                           |
| `filename{,.new}`   | brace expansion makes multiple arguments from a single one |

Content of all loops is bracketed by `do` and `done`: `for i in ... do ...; done;` and `for ((i=0; i<N; i++)); do cmd; done;`
  - `for i in {01..07}; do cmd; done;`
  - `for i in {000..100}; do cmd; done;`
  - `for i in 1 2 3 4 5; do cmd; done;`

| Number bases         | Description                                                                                                                                                       |
| :------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `r#n`                | general format for interpreting number <n> as having base (radix) <r>                                                                                             |
| `2#1111001110011010` | binary                                                                                                                                                            |
| `0x32`               | hex numbers                                                                                                                                                       |
| `032`                | octal                                                                                                                                                             |
| `32#@_`              | base-32: a range of ASCII characters can be used to define numbers with bases up to 64: 10 digits, 26 lowercase characters, 26 uppercase characters, '@', and '_' |

| Command sequence syntax | Effect                                                                     |
| :---------------------- | :------------------------------------------------------------------------- |
| `;`                     | run commands synchnonously                                                 |
| `&`                     | run commands asynchronously                                                |
| `&&`                    | logical AND; run next command synchronously only if first command succeeds |
| `||`                    | logical OR; run next command synchronously only if first command fails     |

## Tasks

Extracting audio from mp4 files in a directory
```sh
# Using variable substitution to replace one file extension with another
for f in *.mp4
do 
  ffmpeg -i $f ${f/.mp4/.wav} 
done
```

Less gracefully:
```sh
for f in *.mp4
do 
  l=$(expr length "$f" - 4) 
  # Slice string to remove the file extension, then concatenate extensions again
  # using brace expansion to form two quoted strings from the original filename
  echo  \"${f::$l}{.mp4\",.wav\"} | xargs ffmpeg -i
done
```

#### Validating arguments 

=== "`$#`"

    ```sh 
    # From Sobell p. 548
    if [ $# != 2 ]
    then 
      echo "..."
      exit 1
    fi
    ```

=== "`-z $1`"

    ```sh
    #From https://youtu.be/ksAfmJfdub0
    [ -z "$1" ] && echo "..." && exit 1
    ```

=== "`! -z $2`"

    ```sh
    # From https://coderwall.com/p/kq9ghg/yakuake-scripting
    if [ ! -z "$2" ] ; then ...; fi
    ```

=== "`while` ... `break`"

    Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate [Cannon][CLKF]

    ```bash
    read -p "Backup another server? (y/n)" -n 1
    ["$BACKUP_AGAIN"="y"] || break
    ```

#### Debugging

With `-x` bash will produce the text of each line of a script being run.
This can be placed in the shebang of the script so that it will always run in debugging mode.

Debugging output can also be turned on ad hoc using `set -x` and `set +x` within the body of the code.