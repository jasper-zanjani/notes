# Linux text filtering commands
&nbsp;  | Commands
---     | ---
&nbsp;  | [`cat`][cat] &bull; [`fold`][fold] &bull; [`grep`][grep] &bull; [`head`][head] &bull; [`nl`][nl] &bull; [`sed`][sed] [`seq`][seq] [`sort`][sort] &bull; [`tail`][tail]

### `cat`
&nbsp;  | Options
---     | ---
&nbsp;  | [`b`][cat -b] [`n`][cat -n]

[cat -b]:                                            #cat                                     '```&#10;$ cat -b&#10;```&#10;Number blank lines'
[cat -n]:                                            #cat                                     '```&#10;$ cat -n&#10;```&#10;Number lines'
### `fold`
Display text of {file}, wrapping long lines
```sh
fold  file
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