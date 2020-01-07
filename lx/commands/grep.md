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