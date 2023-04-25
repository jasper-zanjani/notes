Awk **programs** are equivalent to [**sed**](#sed) "instructions" and can be defined **inline** or in a **program file** (also "source files"). 
If no input files are specified awk can accept input from standard input.

```sh 
# Inline
awk $OPTIONS $PROGRAM $INPUTFILES

# Program file
awk $OPTIONS -f $PROGRAMFILE $INPUTFILES
```

awk programs combine **patterns** and **actions**

Patterns can be:

- regular expressions or fixed strings
- line numbers using builtin variable `NR`
- predefined patterns `BEGIN` or `END`, whose actions are executed before and after processing any lines of the data file, respectively

Convert ":" to newlines in **$PATH** environment variable
```sh
echo $PATH | awk 'BEGIN {RS=":"} {print}'
```

Print the first field of all files in the current directory, taking semicolon `;` as the field separator, outputting filename, line number, and first field of matches, with colon `:` between the filename and line number
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
