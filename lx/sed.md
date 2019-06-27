# sed

## Summary
stream-oriented editor typically used for applying repetitive edits across all lines of multiple files. In particular it is, alongside `awk` one of the two primary commands which accept regular expressions in Unix systems. 

## Command line
Invocation syntax has two forms:
`sed options 'instruction' file`
: inline instructions
`sed options -f scriptfile file`
: instructions read from a file (called a _command_file_ in the man page)

### Options
`-e`
: when providing more than one instruction, this flag precedes every one
`-f` | `--file`
: read from a file (called a _command_file_ in the man page and a _program-file_ in PGL:564)
`-i`
: edit the file in-place instead of outputting to stdout
`-i=suffix`
: edit the file in-place, but save a backup copy of the original with {suffix} appended to the filename
`-n`
: suppress duplicate line printing; only print lines specified with the `p` command 

## Scripts
`#`
: comments begin with octothorpe
`#n`
: if first line of script begins with these two characters, it is equivalent to using the `-n` flag

## Instructions
sed instructions are made of _addresses_ and _procedures_ (see Semantics below)
```sed
address{
  procedure
  procedure
  procedure
}
```
: multiple procedures can be executed on the same address if they are enclosed within braces; but no whitespace can be left after a line, which will cause an error

### Semantics
Sources do not use consistent terminology to describe the two components of most sed commands:
  - In _sed & awk_, each instruction is considered to be made up of a _pattern_ and a _procedure_ (s&a:14). But later on, the term procedure is dropped for _command_ (78).
  - In _Your Unix Guide_,  the terms _address_ and _action_ are used first (YUG:449). 
  - In _Practical Guide to Linux_ the author calls these components _addresses_ and _instructions_, respectively, for each line of syntax (PGL:565)

### Addressing
Zero, one, or two addresses can precede a procedure.
  - In the absence of an address, the procedure is executed over every line of input
  - With one address, the procedure will be executed over every line of input that matches
  - With two addresses, the procedure will be executed over groups of lines whereby:
    - The first address selects the first line in the first group
    - The second address selects the next subsequent line that it matches, which becomes the last line in the first group
    - If no match for the second address is found, it point to the end of the file
    - After the match, the selection process for the next group begins by searching for a match to the first address
Addressing can be done in one of two ways:
  1. Line addressing, specifying line numbers separated by a comma (e.g. `3,7p`); `$` represents the last line of input
  2. Context addressing, using a regular expression enclosed by forward slashes (e.g. `/From:/p`)

### Procedures
`!c`
: negation operator can be used with any procedure {c}
`a`
: append text to the addressed lines
`d`
: cause sed not to display the addressed lines ("delete"); can emulate `grep -v`, which selects lines which do _not_ match the specified pattern
`i`
: prepend text to the addressed lines
`n`
: write out the currently selected line if appropriate, read the next input line, and start processing the new line with the next instruction
`x`
: where {x} is a number, specifying occurrence (e.g. `2` would replace only the second occurrence of each pattern per line)
`g`
: replace all occurrences
`p`
: print original content (e.g. `sed -n 's/test/another test/p' myfile`)
`w outputfile`
: write results to {outputfile} (e.g. `sed 's/test/another test/w output' myfile`)
`s/pattern/replacement/flags`
: replace regex {pattern} with {replacement} ("substitute")
#### Substitution syntax
`g` flag
: replace _all_ instances of the search pattern with the replacement, rather than the first instance (global)
`&`
: known as the _repeated pattern_, represents the represents the entire source string; the only special character used in the replacement string - all other characters are treated literally

## Examples
`sed '3q' emp.lst`
: display first 3 lines of emp.lst (YUG:450)
`sed '5 q' new`
: display the first five lines of file new, similar to `head -5 new` (PGL:569)
`sed '1,2p' emp.lst`
: without using the `-n` flag, this will display the first two lines of emp.lst twice (YUG:450)
`sed -n '1,2p' emp.lst`
: display only the first two lines of emp.lst (YUG:451)
`sed -n '3,$!p' emp.lst`
: prepending `!` to the procedure reverses the sense of the command; this instruction causes sed to display only the first two lines of emp.lst (YUG:451)
`sed -n '9,11p' emp.lst`
: display lines from the middle of emp.lst
`sed -n -e '1,2p' -e '7,9p' -e '$p' emp.lst`
: use the `-e` flag to precede multiple instructions
`sed -n '/MA/p' *`
: equivalent to `grep MA *`
`sed '2d' myfile` 
: delete second line alone
`sed '2,3d' myfile` 
: delete a range of lines: from the 2nd through the 3rd
`sed '3,$d' myfile` 
: suppress from the 3rd line to EOF
`sed '/test/d' myfile` 
: suppress any line with 'test' in it
`sed '/second/,/fourth/d' myfile` 
: delete a range of lines, from the first occurrence of 'second' to the line with the first occurrence of 'fourth'
`sed -ne '/^fake/p' * | sed -n 's/fake\.//p' | sed -nr 's/\(.*\)//p' | sed 11q`
: take lines of all files in CWD beginning with "fake" and remove all instances of string "fake." Then remove all parentheses with any content within them and print only the top 10 lines
`sed -n '/^fake/s/fake\.//p' * | sed -nr 's/\(.*\)//p' | wc -l`
: take lines beginning with "fake" and remove all instances of "fake.", piping them... remove all parentheses with content and count lines of output (results)
`ps axch -o cmd,%mem --sort=-%mem | sed 11q`
: pipe output of `ps` to `sed`, displaying top 10 memory-intensive processes
`ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q`
: pipe output of `ps` to `sed`, displaying top 10 CPU-intensive processes
`sed 's/|/:/ emp.lst | head -2`
: replace the first instance of the `|` character with `:` and display the first two lines (YUG:455)
`sed 's/|/:/g' emp.lst | head -2`
: replace all instances of the `|` character with `:`, displaying the first two lines (YUG:455)
`sed 's/|/:/g' emp.lst | cmp -l - emp.lst | wc -l`
: count the number of pipes replaced by piping output to `cmp`, which will use the `-l` option to output byte numbers of differing values, then counting the lines of output (YUG:456)
`sed 's/<I>/<EM>/g'`
: perform multiple substitutions of HTML tags (YUG:456)
`sed 's/director/executive director/' emp.lst` | `sed 's/director/executive &/' emp.lst` | `sed '/director/s//executive &/' emp.lst`
: replace "director" with "executive director" (YUG:457)
