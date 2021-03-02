[nl -&#98;]: #nl '```&#10;$ nl -b $STYLE&#10;$ nl --body-numbering $STYLE&#10;```&#10;Set body numbering style to `$STYLE`:&#10;  - `A`: Number all lines&#10;  - `t`: Number only nonempty lines&#10;  - `n`: Do not number lines&#10;  - `p$REGEXP`: Number only lines that contain a match for `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 81'
[nl -&#102;]: #nl '```&#10;$ nl -f $STYLE&#10;```&#10;Set footer numbering style to `$STYLE`:&#10;  - `A`: Number all lines&#10;  - `t`: Number only nonempty lines&#10;  - `n`: Do not number lines&#10;  - `p$REGEXP`: Number only lines that contain a match for `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 81'
[nl -&#104;]: #nl '```&#10;$ nl -h $STYLE&#10;```&#10;Set header numbering style to `$STYLE`:&#10;  - `A`: Number all lines&#10;  - `t`: Number only nonempty lines&#10;  - `n`: Do not number lines&#10;  - `p$REGEXP`: Number only lines that contain a match for `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 81'

<code>&nbsp;</code> <code>&nbsp;</code> [`b`][nl -&#98;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`f`][nl -&#102;] <code>&nbsp;</code> [`h`][nl -&#104;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Number all lines, including blank lines
```sh
nl -b a file
nl --body-numbering=a file
```