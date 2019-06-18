### test

Syntax | Effect
:--- | :---
`[[ $VAR =~ 'string1' \| 'string2' ]]` | test if {VAR} has either the text "string1" or "string2" within it
`[[ $VAR =~ pattern ]]` | test if {VAR} matches a regex {pattern} (must not be quoted, otherwise, {pattern} will be treated as a string literal)
