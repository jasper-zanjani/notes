[cat]:                                               text.md#cat                                        '```&#10;$ cat&#10;```&#10;Display contents of text files&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[cat -A]:                                             #cat                                               '```&#10;$ cat -A&#10;```&#10;same as `-vET`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[cat -b]:                                             #cat                                               '```&#10;$ cat -b&#10;$ cat --number-nonblank&#10;```&#10;number all nonblank output lines&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -E]:                                             #cat                                               '```&#10;$ cat -E&#10;$ cat --show-ends&#10;```&#10;print "$" at the end of each line&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -e]:                                             #cat                                               '```&#10;$ cat -e&#10;```&#10;same as `-vE`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -n]:                                             #cat                                               '```&#10;$ cat -n&#10;$ cat --number&#10;```&#10;number lines, including blank lines&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -s]:                                             #cat                                               '```&#10;$ cat -s&#10;$ cat --squeeze-blank&#10;```&#10;collapse multiple blank lines to a single one&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -t]:                                             #cat                                               '```&#10;$ cat -t&#10;```&#10;same as `-vT`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -T]:                                             #cat                                               '```&#10;$ cat -T&#10;$ cat --show-tabs&#10;```&#10;print TAB characters as "^I"&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -u]:                                             #cat                                               '```&#10;$ cat -u&#10;```&#10;ignored; retained for Unix compatibility&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cat -v]:                                             #cat                                               '```&#10;$ cat -v&#10;$ cat --show-nonprinting&#10;```&#10;display conrol characters and nonprinting characters, except LINEFEED and TAB&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'

# Linux text filtering commands

Commands              | Options
---                   | ---
[`cat`][cat]          | <code>&nbsp;</code>  [`b`][cat -b]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`e`][cat -e]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`n`][cat -n]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`s`][cat -s]  [`t`][cat -t]  [`u`][cat -u]  [`v`][cat -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code><br>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`E`][cat -E]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`T`][cat -T]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`fold`][fold]        |
[`grep`][grep]        |
[`head`][head]        |
[`nl`][nl]            |
[`sed`][sed]          |
[`seq`][seq]          |
[`sort`][sort]        |
[`tail`][tail]        |


### `fold`
Display text of {file}, wrapping long lines
```sh
fold file
```
### `grep`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-A`    |                         | print {n} lines of trailing context from the file after each match
`-B`    |                         | print {n} lines of leading context from the file after each match
`-c`    | `--count`               | print number of lines containing the pattern
`-C`    |                         | print {n} lines of leading and trailing context surrounding each match
`-E`    | `--extended-regexp`     | force grep to use extended regular expressions, making it similar to `egrep`
`-F`    | `--fixed-strings`       | force grep to interpret pattern as fixed strings, making it similar to `fgrep`
`-H`    |                         | always pr int filename headers with output lines
`-l`    | `--files-with-matches`  | print only filenames where pattern matches occur; search continues to the next file if a match is found, making it less computationally expensive
`-n`    | `--line-number`         | print line number where match occurs
`-r`    |                         | recursive
`-v`    | `--invert-match`        | print lines **not** matching the pattern
### `head`
Print first 8 characters of `$FILE`
```sh
head -c8 $FILE
```
### `nl`
Number all lines, including blank lines
```sh
nl -b a file
nl --body-numbering=a file
```
### `sed`
Run sed commands in `sedscr` on file
```sh
sed -f sedscript file
```
Suppress automatic printing of pattern space
```sh
sed -n
sed --quiet
sed --silent
```
### `seq`
Sequence from 1 to 15
```sh
seq -f "%03g" 15
```
Sequence from 5 to 99, separated by a space instead of a newline
```sh
seq -s " " 5 99
```
Sequence every third number from 5 to 20
```sh
seq 5 320
```
Sequence from 1 to 8
```sh
seq 8
```
### `sort`
Option  | Effect
:---    | :---
`-k $N` | sort by column number `$N`
`-r`    | reverse sort order
`-t $X` | set delimiter to character `$X`

Sort by space-delimited columns. Processes consuming the most memory will be at the bottom [[23](sources.md)]
```sh
ps aux | sort -nk 4
```
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```
### `tail`
Output last lines beginning at 30th line from the start
```sh
tail -n=+30
tail --lines=+30
```