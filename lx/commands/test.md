### `test`
Evaluate a condition, returning 0 if true and 1 if false

Option  | Effect
:---    | :---
`-a`    | Test if both EXPRESSION1 and EXPRESSION2 are true
`-b`    | Test if {file} exists and is block special
`-c`    | Test if {file} exists and is character special
`-d`    | Test if {file} exists and is a directory
`-e`    | Test if {file} exists
`-ef`   | Test if {file} and {other} have the same device and inode numbers
`-eq`   | Test if INT1 is equal to INT2
`-f`    | Test if {file} exists and is a regular file
`-ge`   | Test if INT1 is greater than or equal to INT2
`-o`    | Test if either EXPRESSION1 or EXPRESSION2 are true
`-le`   | Test if INT1 is less than or equal to INT2
`-lt`   | Test if INT1 is less than INT2
`-ne`   | Test if INT1 is unequal to INT2
`-nt`   | Test if {file} is newer (modification date) than {other}
`-ot`   | Test if {file} is older than {other}
`-g`    | Test if {file} exists and is set-group-ID
`-G`    | Test if {file} exists and is owned by the effective group ID
`-h`    | Test if {file} exists and is a symbolic link
`-k`    | Test if {file} exists and has its sticky bit set
`-L`    | Test if {file} exists and is a symbolic link
`-n`    | Test if the length of {string} is nonzero
`-O`    | Test if {file} exists and is owned by the effective user ID
`-p`    | Test if {file} exists and is a named pipe
`-r`    | Test if {file} exists and read permission is granted
`-s`    | Test if {file} exists and has a size greater than zero
`-S`    | Test if {file} exists and is a socket
`-u`    | Test if {file} exists and its set-userID bit is set
`-w`    | Test if {file} exists and write permission is granted
`-x`    | Test if {file} exists and execute (or search) permission is granted
`-z`    | Test if the length of {string} is zero

Test if {VAR} has either the text "string1" or "string2" within it
```sh
[[ $VAR =~ 'string1' | 'string2' ]]
```
Test if {VAR} matches a regex {pattern} (must not be quoted, otherwise, {pattern} will be treated as a string literal)
```sh
[[ $VAR =~ pattern ]]
```
Test if {VAR} has either the text "string1" or "string2" within it
```sh
[[ $VAR =~ 'string1' \| 'string2' ]]
```
Test if {VAR} matches a regex {pattern} (must not be quoted, otherwise, {pattern} will be treated as a string literal)
```sh
[[ $VAR =~ pattern ]]
```
