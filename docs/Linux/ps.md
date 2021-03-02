[ps -&#97;]:                    #ps                            '```&#10;$ ps -a&#10;$ ps xG&#10;```&#10;Show processes that are owned by other users and attached to a terminal&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#102;]:                   #ps                            '```&#10;$ ps -f&#10;```&#10;Full-format listing that prints command arguments in addition to the command itself&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#108;]:                   #ps                            '```&#10;$ ps -l&#10;```&#10;Long format that includes priority, parent PID, and other information&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#117;]:                   #ps                            '```&#10;$ ps -u&#10;```&#10;User format that includes usernames and the start time of processes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#119;]:                   #ps                            '```&#10;$ ps -w&#10;```&#10;Wide output format, used to eliminate the default output line truncation.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#120;]:                   #ps                            '```&#10;$ ps -x&#10;```&#10;Include processes without controlling terminals&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#67;]:                    #ps                            '```&#10;$ ps -C $CMD&#10;```&#10;Display instancess of `$CMD`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#85;]:                    #ps                            '```&#10;$ ps -U $USER&#10;```&#10;Display processes owned by `$USER`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 109'
[ps -&#101;]:                   #ps                            '```&#10;$ ps -e&#10;$ ps ax&#10;```&#10;Show system processes'

<code>&nbsp;</code>   [`a`][ps -&#97;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`e`][ps -&#101;] [`f`][ps -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][ps -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`u`][ps -&#117;] <code>&nbsp;</code> [`w`][ps -&#119;] [`x`][ps -&#120;] <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> [`C`][ps -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`U`][ps -&#85;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Display processes in a tree-like display illustrating parent-child relationships
```sh
ps -f
ps --forest
```
Show system processes
```sh
ps ax
ps -e
```
Display full listing of processes
```sh
ps u
ps -f
```
Display user processes
```sh
ps xG
ps -a
```
Display SELinux contexts for processes
```sh
ps auxZ
```