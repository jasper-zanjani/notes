# grep
`grep options pattern filename`

Options | Effect
:--- | :---
`-A n` | print {n} lines of trailing context from the file after each match
`-B n` | print {n} lines of leading context from the file after each match
`-C n` | print {n} lines of leading and trailing context surrounding each match
`-E` , `--extended-regexp` | force grep to use extended regular expressions, making it similar to `egrep`
`-F` , `--fixed-strings` | force grep to interpret pattern as fixed strings, making it similar to `fgrep`
`-H` , always print filename headers with output lines
`-v` , `--invert-match` | print lines _not_ matching the pattern
`-l` , `--files-with-matches` | print only filenames where pattern matches occur; search continues to the next file if a match is found, making it less computationally expensive
`-n` , `--line-number` | print line number where match occurs
`-c` , `--count` | print number of lines containing the pattern

## Examples

Syntax | Effect
:--- | :---
`grep -Rin string path` | recursively search for string in path, insensitive to case, display line-numbers of matches
`grep -H` | always print filename headers with output lines

 
