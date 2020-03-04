[cat]:                                               #cat                                        '```&#10;$ cat&#10;```&#10;Display contents of text files&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[cut]:                                               #cut                                        '```&#10;$ cut&#10;```&#10;Display "sections" of data&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 128'
[diff]:                                              #diff                                       '```&#10;$ diff&#10;```&#10;Compare two files&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 140'
[echo]:                                              #echo                                       '```&#10;$ echo&#10;```&#10;Display the value of variables&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 331'
[egrep]:                                             #egrep                                      '```&#10;$ egrep&#10;```&#10;Equivalent to `grep -E`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 128'
[grep]:                                              #grep                                       '```&#10;$ grep&#10;```&#10;Search files for lines that contain a specific pattern&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 114'
[head]:                                              #head                                       '```&#10;$ head&#10;```&#10;Display the top part of text data&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 116'
[less]:                                              #less                                       '```&#10;$ less&#10;```&#10;Display text one page at a time; more capable than `more`.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 116'
[more]:                                              #more                                       '```&#10;$ more&#10;```&#10;Display text one page at a time; superceded by `less`.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 116'
[nl]:                                                #nl                                         '```&#10;$ nl&#10;```&#10;Number lines of output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 119'
[sort]:                                              #sort                                       '```&#10;$ sort&#10;```&#10;Sort text data&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 124'
[tail]:                                              #tail                                       '```&#10;$ tail&#10;```&#10;Display the bottom part of text data.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[tee]:                                               #tee                                        '```&#10;$ tee&#10;```&#10;Send output to both STDOUT and to a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 122'
[tr]:                                                #tr                                         '```&#10;$ tr&#10;```&#10;Translate characters from one set to another&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 123'
[wc]:                                                #wc                                         '```&#10;$ wc&#10;```&#10;Display number of lines, words, or characters of data.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 128'

<!-- `cat` options -->
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

<!-- `diff` options -->
[diff -a]:                                            #diff                                              '```&#10;$ diff -a&#10;$ diff --text&#10;```&#10;Treat all files as text files'
[diff -b]:                                            #diff                                              '```&#10;$ diff -b&#10;$ diff --ignore-space-change&#10;```&#10;Treat successive blanks as one, including end-of-line blanks&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -B]:                                            #diff                                              '```&#10;$ diff -B&#10;$ diff --ignore-blank-lines&#10;```&#10;Ignore blank lines in files'
[diff -c]:                                            #diff                                              '```&#10;$ diff -c&#10;```&#10;Produce output in "context diff" format, with three lines of context&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -C]:                                            #diff                                              '```&#10;$ diff -C&#10;$ diff --$N&#10;```&#10;Like `-c`, but produce `$N` lines of context&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -D]:                                            #diff                                              '```&#10;$ diff -D $SYMBOL&#10;$ diff --ifdef $SYMBOL&#10;```&#10;Merge files into a single one, containing conditional C preprocessor directives (`#ifdef`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -d]:                                            #diff                                              '```&#10;$ diff -d&#10;$ diff --minimal&#10;```&#10;Ignore segments of numerous changes and output a smaller set of changes, to speed up comparison.'
[diff -e]:                                            #diff                                              '```&#10;$ diff -e&#10;$ diff --ed&#10;```&#10;Produce an `ed` script to recreate `$OTHER` from `$FILE`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -E]:                                            #diff                                              '```&#10;$ diff -E&#10;$ diff --ignore-tab-expansion&#10;```&#10;Ignore differences due to expanding tabs'
[diff -f]:                                            #diff                                              '```&#10;$ diff -f&#10;$ diff --forward-ed&#10;```&#10;Produce an `ed` script to recreate `$FILE` from `$OTHER`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -F]:                                            #diff                                              '```&#10;$ diff -F $PATTERN&#10;$ diff --show-function-line $PATTERN&#10;```&#10;For context and unified diffs, show the most recent line containing regex `$PATTERN` before each block of changed lines'
[diff -h]:                                            #diff                                              '```&#10;$ diff -h&#10;```&#10;Ignored by GNU `diff`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -i]:                                            #diff                                              '```&#10;$ diff -i&#10;$ diff --ignore-case&#10;```&#10;Case-insensitive comparison&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -l]:                                            #diff                                              '```&#10;$ diff -l&#10;$ diff --paginate&#10;```&#10;Long format; output is paginated by `pr` so that diff listings for each file begin on a new page.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -L]:                                            #diff                                              '```&#10;$ diff -L $LABEL&#10;$ diff --label $LABEL&#10;```&#10;For context and unified diffs, print `$LABEL` in place of the filename being compared; use once for `$FILE` and again for `$OTHER`'
[diff -n]:                                            #diff                                              '```&#10;$ diff -n&#10;$ diff --rcs&#10;```&#10;Like `-f`, but counts changed lines the way `rcsdiff` does&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -n]:                                            #diff                                              '```&#10;$ diff -n&#10;$ diff --normal&#10;```&#10;Produce a normal diff (default)'
[diff -N]:                                            #diff                                              '```&#10;$ diff -N&#10;$ diff --new-file&#10;```&#10;Treat nonexistent files as empty'
[diff -p]:                                            #diff                                              '```&#10;$ diff -p&#10;$ diff --show-c-function&#10;```&#10;When handling files in C or C-like languages such as Java, show the function containing each block of changed lines.'
[diff -q]:                                            #diff                                              '```&#10;$ diff -q&#10;$ diff --brief&#10;```&#10;Output only when files differ&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 61'
[diff -q]:                                            #diff                                              '```&#10;$ diff -q&#10;$ diff --brief&#10;```&#10;Output only whether files differ'
[diff -r]:                                            #diff                                              '```&#10;$ diff -r&#10;$ diff --recursive&#10;```&#10;Run `diff` recursively for files in common subdirectories&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -s]:                                            #diff                                              '```&#10;$ diff -s&#10;$ diff --report-identical-files&#10;```&#10;Report files that are identical'
[diff -S]:                                            #diff                                              '```&#10;$ diff -S $FILENAME&#10;$ diff --starting-file $FILENAME&#10;```&#10;Begin directory comparisons with `$FILE`, skipping files whose filenames alphabetically precede `$FILENAME`'
[diff -t]:                                            #diff                                              '```&#10;$ diff -t&#10;$ diff --expand-tabs&#10;```&#10;Expand tabs in output lines; usefulf or preserving indentation changed by `-c`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -T]:                                            #diff                                              '```&#10;$ diff -T&#10;$ diff --initial-tab&#10;```&#10;Insert initial tabs into output to line up tabs properly'
[diff -u]:                                            #diff                                              '```&#10;$ diff -u&#10;```&#10;Produce output in "unified `diff`" format, with 3 lines of context&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -U]:                                            #diff                                              '```&#10;$ diff -U $N&#10;$ diff --unified $N&#10;```&#10;Like `-u`, but produces output with `$N` lines of context&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -v]:                                            #diff                                              '```&#10;$ diff -v&#10;$ diff --version&#10;```&#10;Print version number.'
[diff -w]:                                            #diff                                              '```&#10;$ diff -w&#10;$ diff --ignore-all-space&#10;```&#10;Ignore spaces and tabs&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 59'
[diff -W]:                                            #diff                                              '```&#10;$ diff -W $N&#10;$ diff --width $N&#10;```&#10;For two-column output (`-y`), produce columns with a maximum width of `$N` characters (130 by default)'
[diff -x]:                                            #diff                                              '```&#10;$ diff -x $PATTERN&#10;$ diff --exclude $PATTERN&#10;```&#10;Do not compare files in a directory whose names match regex `$PATTERN`'
[diff -X]:                                            #diff                                              '```&#10;$ diff -X $FILE&#10;$ diff --exclude-from $FILE&#10;```&#10;Do not compare files in a directory whose names match patterns described in `$FILE`'
[diff -y]:                                            #diff                                              '```&#10;$ diff -y&#10;$ diff --side-by-side&#10;```&#10;Two-column output&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 61'

## Text

Commands              | Options
---                   | ---
[`cat`][cat]          | <code>&nbsp;</code>  [`b`][cat -b]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`e`][cat -e]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`n`][cat -n]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`s`][cat -s]  [`t`][cat -t]  [`u`][cat -u]  [`v`][cat -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code><br>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`E`][cat -E]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`T`][cat -T]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`cut`][cut]          | 
[`diff`][diff]        | <code>&nbsp;</code>  [`a`][diff -a]  [`b`][diff -b]  [`c`][diff -c]  [`d`][diff -d]  [`e`][diff -e]  [`f`][diff -f]  <code>&nbsp;</code>  [`h`][diff -h]  [`i`][diff -i]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`l`][diff -l]  <code>&nbsp;</code>  [`n`][diff -n]  <code>&nbsp;</code>  [`p`][diff -p]  [`q`][diff -q]  [`r`][diff -r]  [`s`][diff -s]  [`t`][diff -t]  [`u`][diff -u]  [`v`][diff -v]  [`w`][diff -w]  [`x`][diff -x]  [`y`][diff -y]  <code>&nbsp;</code> <br><code>&nbsp;</code>  <code>&nbsp;</code>  [`B`][diff -B]  [`C`][diff -C]  [`D`][diff -D]  [`E`][diff -E]  [`F`][diff -F]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`L`][diff -L]  <code>&nbsp;</code>  [`N`][diff -N]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`S`][diff -S]  [`T`][diff -T]  [`U`][diff -U]  <code>&nbsp;</code>  [`W`][diff -W]  [`X`][diff -X]  <code>&nbsp;</code>  <code>&nbsp;</code>
[`echo`][echo]        | 
[`egrep`][egrep]      | 
[`grep`][grep]        |   
[`head`][head]        | 
[`less`][less]        | 
[`more`][more]        | 
[`nl`][nl]            | 
[`sort`][sort]        | 
[`tail`][tail]        | 
[`tee`][tee]          | 
[`tr`][tr]            | 
[`wc`][wc]            | 

### `awk`
>"The basic function of awk is to search files for lines that contain certain patterns." ([GEAP](../sources/README.md): 17

Pattern-scanning utility and processing language, one of the two primary commands which accept regular expressions in Unix systems.

awk __programs__ can be defined __inline__ or in a __program-file__ ([PGL](../sources/README.md): 528)
  - inline: `awk options 'program' input-files`
  - __program-file__, also "source-file" ([GEAP](../sources/README.md):18): `awk options -f program-file input-files` 

awk programs can be run without defining __input-files__, in which case awk will accept input from STDIN

awk __programs__ are the equivalent of sed "instructions", and similarly combine __patterns__ and __actions__ ([PGL](../sources/README.md): 530, [GEAP](../sources/README.md): 17)

Patterns can be:
- regular expressions or fixed strings
- line numbers using builtin variable `NR`
- predefined patterns `BEGIN` or `END`, whose actions are executed before and after processing any lines of the data file, respectively

Option            | Effect
:---              | :---
`-Fx` , `-F="x"` | sets field separator `FS` to {x}
`-f program-file` | `--file program-file` : specify awk program-file {program-file}
`-v var=value` | `--assign var=value` : sets variable {var} to {value} before script is executed (even before `BEGIN` pattern)
`--` | POSIX-standard flag which marks end of command-line options (allowing specification of a datafile with a "-" at the beginning of its filename)

#### Syntax

Syntax      | Effect
:---        | :---
`#!/bin/awk -f` | shebang
`#` | comments begin with octothorpe

#### Predefined variables

Syntax      | Effect
:---        | :---
`$0`        | current record
`$n`        | field number `$N`
`ARGC`      | number of arguments in command line
`ARGV`      | list of arguments
`FILENAME`  | current input filename
`FNR`       | number of the current record relative to the current input file
`FS`        | field separator (' ' by default)
`NF`        | number of fields for the current input record
`NR`        | number of the current input record
`OFS`       | output field separator (' ' by default)
`ORS`       | output record separator
`RS`        | record separator (newline by default)

## Functions

Syntax      | Effect
:---        | :---
`gsub(regex,substitution[,string])` | replace all instances of {regex} with {substitution} in {string} (defaults to $0 if not provided)
`sub(regex,substitution[,string])` | replace first instance of {regex} with {substitution} in {string} (defaults to $0 if not provided)
`index(substring,string)` | return (1-indexed) position of {substring} within {string}, or 1 if not found
`length(string)` | return length of {string} (defaults to $0 if not provided)
`match(string,regex)` | return position in {string} where {regex} begins, or 0 if not found
`printf("control-string",*args)` | formatted strings (see below)
`split(string,array,delim)` | break up {string} by delimiter {delim} and store the fields in {array} (YUG: 481)
`substr(string,start,chars)` | extract a substring from {string}, where {start} represents the starting position and {chars} indicates the number of characters to extracted from that point
`tolower(string)` | convert {string} to lowercase
`toupper(string)` | convert {string} to uppercase

### Formatted strings
Formatted strings use the `printf` command, with the syntax `printf "control-string", *args`. The {control-string} is interpolated with expressions called _conversion specifications_, with the syntax `%[-][x[.y]]conv` where {x} represents minimum field width, {y} number of places to the right of a decimal point in a number, and _conv_ can be one of the following values (PGL:534):
  - `d` integer
  - `e` exponential notation
  - `f` floating point number
  - `g` use `f` or `e`, whichever is shorter
  - `o` unsigned octal
  - `s` string
  - `x` unsigned hexadecimal

#### Examples

Syntax      | Effect
:---        | :---
`%6d`   | integer taking up six characters
`%-10s` | left-aligned string taking up 10 characters (a positive number means the string is right-aligned)
`%6.1f` | floating point taking up six characters, including one digit after a decimal point

### Examples

Syntax      | Effect
:---        | :---
`echo $PATH \| awk 'BEGIN {RS=":"} {print}'` | change ":" to newlines in PATH variable; equivalent to `echo $PATH \| tr ":" "\n"` 
`awk 'BEGIN {FS=";"} /enable/ {print FILENAME ":" FNR,$1}' *` | print the first field of all files in the current directory, taking semicolon `;` as the field separator, outputting filename, line number, and first field of matches, with colon `:` between the filename and line number
`awk '/MA/ {OFS=" " print FILENAME OFS FNR OFS $0} *` | search for string `MA` in all files, outputting filename, line, and line number for matches
`awk -F: -f awkscr /etc/passwd` | change field separator (`FS`) to a colon (`:`) and run `awkscr`
`awk -f script files` `-f` | flag also works for awk
`awk '{ print $1 }' list` | print the first field of each line in the input file
`awk '/MA/' * \| awk '/MA/ {print}' *` | equivalent to `grep MA *` (`{print}` is implied)
`awk -F, '/MA/ { print $1 }' list` | `-F` flag is followed by field separator
`free -h \| awk '/^Mem|/ {print $3 "/" $2}` | pipe output of `free` to `awk` to get free memory and total memory
`sensors \| awk '/^temp1/ {print $2}` | pipe output of `sensors` to `awk` to get CPU temperature
`awk 'sub(^fake.,"real;")' fake_isbn` | replace initial "fake." with "real;" in file `fake_isbn`
`awk '1 { print }' file` | print all lines
`awk 'NR>1' file` | remove file header
`awk 'NR>1 { print } file` | remove file header
`awk 'NR>1 && NR < 4' file` | print lines in a range
`awk 'NF' file` | remove whitespace-only lines
`awk '1' RS='' file` | remove all blank lines
`awk '{ print $1, $3}' FS=, OFS=, file` | extract fields
`awk '{ SUM=SUM+$1 } END { print SUM }' FS=, OFS=, file` | perform column-wise calculations
`awk '/./ { COUNT+=1 } END { print COUNT }' file` | count the number of nonempty lines
`awk 'NF { COUNT+=1 } END { print COUNT }' file` | count the number of nonempty lines
`awk '+$1 { COUNT+=1 } END { print COUNT }' file` | count the number of nonempty lines
`awk '+$1 { CREDITS[$3]+=$1 } END { for (NAME in CREDITS) print NAME, CREDITS[NAME] }' FS=, file` | awk arrays
`awk 'a[$0]++' file` | identify duplicate lines
`awk '!a[$0]++' file` | remove duplicate lines
`awk '$1=$1' file` | remove multiple spaces
`awk '{ print $3 }' FS=, ORS=' ' file; echo` | join lines
`awk '+$1 { SUM+=$1; NUM+=1 } END { printf("AVG=%f",SUM/NUM); }' FS=, file` | format 
`awk '+$1 { SUM+=$1; NUM+=1 } END { printf("AVG=%6.1f",SUM/NUM); }' FS=, file` 
`awk '$3 { print toupper($0); }' file` | convert to uppercase 
`awk '{ $3 = toupper(substr($3,1,1)) substr($3,2) } $3' FS=, OFS=, file` | change part of a string
`awk '+$1 { split($2, DATE, " "); print $1,$3, DATE[2], DATE[3] }' FS=, OFS=, file` | split the second field ("EXPDATE") by spaces, storing the result into the array DATE; then print credits ($1) and username ($3) as well as the month (DATE[2]) and year (DATE[3]) 
`awk '+$1 { split($4, GRP, ":"); print $3, GRP[1], GRP[2] }' FS=, file` 
`awk '+$1 { split($4, GRP, /:+/); print $3, GRP[1], GRP[2] }' FS=, file` 
`awk '+$1 { gsub(/ +/, "-", $2); print }' FS=, file` | search and replace with comma 
`awk 'BEGIN { printf("UPDATED: "); system("date") } /^UPDATED:/ { next } 1' file` | adding date 
`awk '+$1 { CMD \| getline $5; close(CMD); print }' CMD="uuid -v4" FS=, OFS=, file` | modify a field externally 
`awk '+$1 { cmd = sprintf(FMT, $2); cmd \| getline $2; close(cmd); print }' FMT='date -I -d "%s"'  FS=, file` | invoke dynamically generated command
`awk '+$1 { CMD \| getline $5; print }' CMD='od -vAn -w4 -t x /dev/urandom' FS=, file` | join data

#### Arithmetic

Syntax      | Effect
:---        | :---
`awk '{sum += $1} END {print sum}' file` | add up all first records to {sum}, then print that number out at the end

#### Output redirection 

Syntax      | Effect
:---        | :---
`> "file"` | redirect output to {file} (note quotes; filenames are treated as strings); if a file is already open from a previous write, the new data is appended
`>> "file"` | {file} is expected to already exist, can be one of the special file names as well ("/dev/stderr", etc)
`\| "program"` | piping to a command
`close(cmd)` | closing a file or command uses the exact same syntax, down to spaces, thus it is preferable to define the command as a string variable
`sprintf` | takes a string template and interpolated values as argument, it is useful to dynamically build a string which is then treated within the script as a command
`\|&` | redirect to a coprocess, that is allows output to be read back with `getline`


## Sources
  - "Getting Started With AWK Command [Beginner's Guide]" [linuxhandbook.com](https://linuxhandbook.com/awk-command-tutorial/)
  - [HPR](../sources/README.md) 2816 
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
### sed
`sed` ("Stream-oriented editor") is typically used for applying repetitive edits across all lines of multiple files. In particular it is, alongside `awk` one of the two primary commands which accept regular expressions in Unix systems. 

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-e`    |                         | when providing more than one instruction, this flag precedes every one
`-f`    | `--file`                | read from a **command file** (called a **program file** in some places [[PGL](../sources/README.md): 564]
`-i`    |                         | edit the file in-place instead of outputting to stdout
`-n`    |                         | suppress duplicate line printing; only print lines specified with the `p` command 

Script syntax | Effect
---           | ---
`#`           | comments begin with **octothorpe**
`#n`          | If first line of script begins with these two characters, it is equivalent to using the `-n` flag

#### sed syntax
Invocation syntax has two forms:
```sh
sed options 'instruction' file # Instructions provided inline
```
```sh
sed options -f scriptfile file # Instructions read from a **command file**
```
`sed` instructions are made of **addresses** and **procedures** . Sources do not use consistent terminology to describe the two components of most sed commands:

:---                                | :---
`sed 'pattern {procedure}' file`    | [[SA](../sources/README.md): 14]
`sed 'address {action}' file`       | [[YUG](../sources/README.md): 449]
`sed 'address {instruction}' file`  | [[PGL](../sources/README.md): 565]

Zero, one, or two addresses can precede a procedure.
  - In the absence of an address, the procedure is executed over every line of input
  - With one address, the procedure will be executed over every line of input that matches
  - With two addresses, the procedure will be executed over groups of lines whereby:
    - The first address selects the first line in the first group
    - The second address selects the next subsequent line that it matches, which becomes the last line in the first group
    - If no match for the second address is found, it point to the end of the file
    - After the match, the selection process for the next group begins by searching for a match to the first address
Addressing can be done in one of two ways:
  1. **Line addressing**, specifying line numbers separated by a comma (e.g. `3,7p`); `$` represents the last line of input
  2. **Context addressing**, using a regular expression enclosed by forward slashes (e.g. `/From:/p`)

Procedure   | Description
:---        | :---  
`!c`        | negation operator can be used with any procedure {c}
`a`         | append text to the addressed lines
`d`         | cause sed not to display the addressed lines ("delete"); can emulate `grep -v`, which selects lines which do _not_ match the specified pattern
`i`         | prepend text to the addressed lines
`n`         | write out the currently selected line if appropriate, read the next input line, and start processing the new line with the next instruction
`x`         | where {x} is a number, specifying occurrence (e.g. `2` would replace only the second occurrence of each pattern per line)
`g`         | replace all occurrences
`p`         | print original content (e.g. `sed -n 's/test/another test/p' myfile`)
`w outputfile`        | write results to {outputfile} (e.g. `sed 's/test/another test/w output' myfile`)
`s/pattern/replacement/flags`         | replace regex {pattern} with {replacement} ("substitute")
`g`         | replace **all** instances of the search pattern with the replacement, rather than the first instance (global)
`&`         | known as the **repeated pattern**, represents the represents the entire source string; the only special character used in the replacement string - all other characters are treated literally

Edit the file in-place, but save a backup copy of the original with {suffix} appended to - the filename
```sh
-i=suffix
```
Display first 3 lines [[YUG](../sources/README.md): 450]
```sh
sed '3q' emp.lst
```
Display first 5 lines, similar to `head -5 emp.lst` [[PGL](../sources/README.md):569]
```sh
sed '5q' new
```
Pipe output of `ps` to `sed`, displaying top 10 memory-intensive processes
```sh
ps axch -o cmd,%mem --sort=-%mem | sed 11q
```
Pipe output of `ps` to `sed`, displaying top 10 CPU-intensive processes
```sh
ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q
```
Display first two lines of file
Without `-n`, each line will be printed twice
```sh
sed -n '1,2p' emp.lst
```
Prepending `!` to the procedure reverses the sense of the command [[YUG](../sources/README.md): 450-451]
```sh
sed -n '3,$!p' emp.lst
```
Display a range of lines
```sh
sed -n '9,11p' emp.lst
```
Use the `-e` flag to precede multiple instructions
```sh
sed -n -e '1,2p' -e '7,9p' -e '$p' emp.lst
```
Delete lines
Delete second line alone
```sh
sed '2d' myfile
```
Delete a range of lines: from the 2nd through the 3rd
```sh
sed '2,3d' myfile
```
Delete a range of lines, from the first occurrence of 'second' to the line with the first occurrence of 'fourth'
```sh
sed '/second/,/fourth/d' myfile
```
Print all of a file except for specific lines
Suppress any line with 'test' in it
```sh
sed '/test/d' myfile
```
Suppress from the 3rd line to EOF
```sh
sed '3,$d' myfile
```
Replace text
Replace the first instance of the `|` character with `:` and display the first two lines [[YUG](../sources/README.md):455]
```sh
sed 's/|/:/ emp.lst | head -2
```
Replace all instances of the `|` character with `:`, displaying the first two lines [[YUG](../sources/README.md):455]
```sh
sed 's/|/:/g' emp.lst | head -2
```
Substitute HTML tags:
```sh
sed 's/<I>/<EM>/g'
```
These commands will replace "director" with "executive director"
```sh
sed 's/director/executive director/' emp.lst
```
```sh
sed 's/director/executive &/' emp.lst
```
```sh
sed '/director/s//executive &/' emp.lst
```
[[YUG](../sources/README.md): 456-457]
Searching for text\
Equivalent to `grep MA *`
```sh
sed -n '/MA/p' *
```
Stringing sed statements together with pipe
Take lines beginning with "fake" and remove all instances of "fake.", piping them... remove all parentheses with content and count lines of output (results)
```sh
sed -n '/^fake/s/fake\.//p' * | sed -nr 's/\(.*\)//p' | wc -l
```
Take lines of all files in CWD beginning with "fake" and remove all instances of string "fake." Then remove all parentheses with any content within them and print only the top 10 lines
```sh
sed -ne '/^fake/p' * | sed -n 's/fake\.//p' | sed -nr 's/\(.*\)//p' | sed 11q
```
Count the number of pipes replaced by piping output to `cmp`, which will use the `-l` option to output byte numbers of differing values, then counting the lines of output (YUG:456)
```sh
sed 's/|/:/g' emp.lst | cmp -l - emp.lst | wc -l
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
### `shuf`
Print random selection of integers from {x} to {y} (inclusive) without replacement
```sh
shuf -i x-y
```
Print random selection of integers from {x} to {y} (inclusive), with replacement
```sh
shuf -i x-y -r
```
Shuffle items separated by newline in file `cards.txt`, displaying only one [[10](sources.md)]
```sh
shuf -n 1 items.txt
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
### `tr`
Change the case of a string [[23](sources.md)]
```sh
tr [:upper:] [:lower:]
```
Remove a character or set of characters from a string or line of output
```sh
tr -d "text"
```
### `wc`
Display byte count
```sh
wc -c
```
Count lines of text
```sh
wc -l 
```
Display character count
```sh
wc -m
```
Count words of text
```sh
wc -w
```