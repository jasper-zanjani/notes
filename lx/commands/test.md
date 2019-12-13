### test
Test if {VAR} has either the text "string1" or "string2" within it
```sh
[[ $VAR =~ 'string1' \| 'string2' ]]
```
Test if {VAR} matches a regex {pattern} (must not be quoted, otherwise, {pattern} will be treated as a string literal)
```sh
[[ $VAR =~ pattern ]]
```
