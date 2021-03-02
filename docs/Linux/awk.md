
#### Options
[awk -&#70;]: #awk '```&#10;$ awk -F $C&#10;```&#10;Set field separator to `$C`'
[awk -&#102;]: #awk '```&#10;$ awk -f $PROGRAMFILE&#10;```&#10;Specify awk program-file `$PROGRAMFILE`'
[awk -&#118;]: #awk '```&#10;$ awk -v $VAR=$VAL&#10;$ awk --assign $VAR=$VAL&#10;```&#10;Set variable `$VAR` to value `$VAL` before script is executed'

<code>&nbsp;</code>   <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`f`][awk -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][awk -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`F`][awk -&#70;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

#### Variables
[awk ARGC]: #awk '```&#10;$ ARGC&#10;```&#10;&#10;Number of arguments in command line'
[awk ARGV]: #awk '```&#10;$ ARGV&#10;```&#10;&#10;List of arguments'
[awk FILENAME]: #awk '```&#10;$ FILENAME&#10;```&#10;&#10;Current input filename'
[awk FNR]: #awk '```&#10;$ FNR&#10;```&#10;&#10;Number of the current record relative to the current input file'
[awk FS]: #awk '```&#10;$ FS&#10;```&#10;&#10;Field separator (whitespace by default)'
[awk NF]: #awk '```&#10;$ NF&#10;```&#10;&#10;Number of fields for the current input record'
[awk NR]: #awk '```&#10;$ NR&#10;```&#10;&#10;Number of the current input record'
[awk OFS]: #awk '```&#10;$ OFS&#10;```&#10;&#10;Output field separator (space by default)'
[awk ORS]: #awk '```&#10;$ ORS&#10;```&#10;&#10;Output record separator'
[awk RS]: #awk '```&#10;$ RS&#10;```&#10;&#10;Record separator (newline by default)'

[`ARGC`][awk ARGC] 
[`ARGV`][AWK ARGV] 
[`FILENAME`][AWK FILENAME] 
[`FNR`][AWK FNR] 
[`FS`][AWK FS] 
[`NF`][AWK NF] 
[`NR`][AWK NR] 
[`OFS`][AWK OFS] 
[`ORS`][AWK ORS] 
[`RS`][AWK RS] 

#### Functions
[awk gsub()]: #gsub() '```&#10;$ gsub()&#10;$ gsub($PATTERN,$SUBSTITUTION,$STRING)&#10;```&#10;&#10;Replace all instances of `$PATTERN` with `$SUBSTITUTION` in `$STRING` (`$0` if not specified)'
[awk sub()]: #sub() '```&#10;$ sub()&#10;$ sub($PATTERN,$SUBSTITUTION,$STRING)&#10;```&#10;&#10;Replace first instance of `$PATTERN` with `$SUBSTITUTION` in `$STRING` (`$0` if not specified)'
[awk index()]: #index() '```&#10;$ index()&#10;$ index($SUBSTR,$STRING)&#10;```&#10;&#10;Return (1-indexed) position of `$SUBSTR` within `$STRING` (or `$0` if not specified)'
[awk length()]: #length() '```&#10;$ length()&#10;$ length($STRING)&#10;```&#10;&#10;Return length of `$STRING` (or `$0` if not specified)'
[awk match()]: #match() '```&#10;$ match()&#10;$ match($STRING,$PATTERN)&#10;```&#10;&#10;Return position in `$STRING` where `$PATTERN` begins, or 0 if not found'
[awk printf()]: #printf() '```&#10;$ printf()&#10;$ printf "$CTRLSTR", *args&#10;```&#10;&#10;The "control-string" `$CTRLSTR` is interpolated with expressions called **conversion specifications**, with the syntax `%[-][x[.y]]conv` where `x` represents minimum field width, `y` number of places to the right of a decimal point in a number, and `conv` can be one of the following values&#10;  - `d` integer&#10;  - `e` exponential notation&#10;  - `f` floating point number&#10;  - `g` use `f` or `e`, whichever is shorter&#10;  - `o` unsigned octal&#10;  - `s` string&#10;  - `x` unsigned hexadecimal&#10;Olushile, Paul. _Linux 5 Performance Monitoring and Tuning_.: 534'
[awk split()]: #split() '```&#10;$ split()&#10;$ split($STRING,$ARRAY,$DELIM)&#10;```&#10;&#10;Break up `$STRING` by `$DELIM` and store the fields in `$ARRAY`&#10;"Universal Windows Platform apps". _Wikipedia_.: 481'
[awk substr()]: #substr() '```&#10;$ substr()&#10;$ substr($STRING,$N,$M)&#10;```&#10;&#10;Extract a substring from `$STRING`, where `$N` represents the starting position and `$M` the number of characters to be extracted from that point'
[awk tolower()]: #tolower() '```&#10;$ tolower()&#10;$ tolower($STRING)&#10;```&#10;&#10;Convert `$STRING` to lowercase letters'
[awk toupper()]: #toupper() '```&#10;$ toupper()&#10;$ toupper($STRING)&#10;```&#10;&#10;Convert `$STRING` to uppercase letters'

[`gsub()`][awk gsub()] 
[`sub()`][awk sub()] 
[`index()`][awk index()] 
[`length()`][awk length()] 
[`match()`][awk match()] 
[`printf()`][awk printf()] 
[`split()`][awk split()] 
[`substr()`][awk substr()] 
[`tolower()`][awk tolower()] 
[`toupper()`][awk toupper()] 

>"The basic function of awk is to search files for lines that contain certain patterns." (GEAP: 17

Pattern-scanning utility and processing language, one of the two primary commands which accept regular expressions in Unix systems.

`awk` **programs** can be defined **inline** or in a **program-file** (PGL: 528)
  - inline: `awk options 'program' input-files`
  - **program-file**, also "source-file" (GEAP:18): `awk options -f program-file input-files` 

`awk` programs can be run without defining **input-files**, in which case awk will accept input from STDIN

`awk` **programs** are the equivalent of sed "instructions", and similarly combine **patterns** and **actions** (PGL: 530, GEAP: 17)

Patterns can be:
- regular expressions or fixed strings
- line numbers using builtin variable `NR`
- predefined patterns `BEGIN` or `END`, whose actions are executed before and after processing any lines of the data file, respectively

change ":" to newlines in PATH variable; equivalent to `echo $PATH \| tr ":" "\n"` 
```sh
echo $PATH | awk 'BEGIN {RS=":"} {print}'
```
print the first field of all files in the current directory, taking semicolon `;` as the field separator, outputting filename, line number, and first field of matches, with colon `:` between the filename and line number
```sh
awk 'BEGIN {FS=";"} /enable/ {print FILENAME ":" FNR,$1}' *
```
search for string `MA` in all files, outputting filename, line, and line number for matches
```sh
awk '/MA/ {OFS=" " print FILENAME OFS FNR OFS $0} *
``` 
change field separator (`FS`) to a colon (`:`) and run `awkscr`
```sh
awk -F: -f awkscr /etc/passwd
```
flag also works for awk
```sh
awk -f script files` `-f
```
print the first field of each line in the input file
```sh
awk '{ print $1 }' list
```
equivalent to `grep MA *` (`{print}` is implied)
```sh
awk '/MA/' * | awk '/MA/ {print}' *
```
`-F` flag is followed by field separator
```sh
awk -F, '/MA/ { print $1 }' list
```
pipe output of `free` to `awk` to get free memory and total memory
```sh
free -h | awk '/^Mem|/ {print $3 "/" $2}
```
pipe output of `sensors` to `awk` to get CPU temperature
```sh
sensors | awk '/^temp1/ {print $2}
```
replace initial "fake." with "real;" in file `fake_isbn`
```sh
awk 'sub(^fake.,"real;")' fake_isbn
```
print all lines
```sh
awk '1 { print }' file
```
remove file header
```sh
awk 'NR>1' file
```
remove file header
```sh
awk 'NR>1 { print } file
```
print lines in a range
```sh
awk 'NR>1 && NR < 4' file
```
remove whitespace-only lines
```sh
awk 'NF' file
```
remove all blank lines
```sh
awk '1' RS='' file
```
extract fields
```sh
awk '{ print $1, $3}' FS=, OFS=, file
```
perform column-wise calculations
```sh
awk '{ SUM=SUM+$1 } END { print SUM }' FS=, OFS=, file
```
count the number of nonempty lines
```sh
awk '/./ { COUNT+=1 } END { print COUNT }' file
```
count the number of nonempty lines
```sh
awk 'NF { COUNT+=1 } END { print COUNT }' file
```
count the number of nonempty lines
```sh
awk '+$1 { COUNT+=1 } END { print COUNT }' file
```
Arrays
```sh
awk '+$1 { CREDITS[$3]+=$1 } END { for (NAME in CREDITS) print NAME, CREDITS[NAME] }' FS=, file
```
Identify duplicate lines
```sh
awk 'a[$0]++' file
```
Remove duplicate lines
```sh
awk '!a[$0]++' file
```
Remove multiple spaces
```sh
awk '$1=$1' file
```
Join lines
```sh
awk '{ print $3 }' FS=, ORS=' ' file; echo
```
```sh
awk '+$1 { SUM+=$1; NUM+=1 } END { printf("AVG=%f",SUM/NUM); }' FS=, file` | format 
```
```sh
awk '+$1 { SUM+=$1; NUM+=1 } END { printf("AVG=%6.1f",SUM/NUM); }' FS=, file
```
Convert to uppercase 
```sh
awk '$3 { print toupper($0); }' file
```
Change part of a string
```sh
awk '{ $3 = toupper(substr($3,1,1)) substr($3,2) } $3' FS=, OFS=, file
```
Split the second field ("EXPDATE") by spaces, storing the result into the array DATE; then print credits ($1) and username ($3) as well as the month (DATE[2]) and year (DATE[3]) 
```sh
awk '+$1 { split($2, DATE, " "); print $1,$3, DATE[2], DATE[3] }' FS=, OFS=, file
```
```sh
awk '+$1 { split($4, GRP, ":"); print $3, GRP[1], GRP[2] }' FS=, file
```
```sh
awk '+$1 { split($4, GRP, /:+/); print $3, GRP[1], GRP[2] }' FS=, file
``` 
Search and replace with comma 
```sh
awk '+$1 { gsub(/ +/, "-", $2); print }' FS=, file
```
Adding date 
```sh
awk 'BEGIN { printf("UPDATED: "); system("date") } /^UPDATED:/ { next } 1' file
```
Modify a field externally 
```sh
awk '+$1 { CMD | getline $5; close(CMD); print }' CMD="uuid -v4" FS=, OFS=, file
```
Invoke dynamically generated command
```sh
awk '+$1 { cmd = sprintf(FMT, $2); cmd | getline $2; close(cmd); print }' FMT='date -I -d "%s"'  FS=, file
```
Join data
```sh
awk '+$1 { CMD | getline $5; print }' CMD='od -vAn -w4 -t x /dev/urandom' FS=, file
```
Add up all first records to {sum}, then print that number out at the end
```sh
awk '{sum += $1} END {print sum}' file
```
