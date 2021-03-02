[free -&#98;]:                  #free                          '```&#10;$ free -b&#10;```&#10;Show memory usage in bytes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[free -&#107;]:                 #free                          '```&#10;$ free -k&#10;```&#10;Show memory usage in kilobytes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[free -&#109;]:                 #free                          '```&#10;$ free -m&#10;```&#10;Show memory usage in megabytes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[free -&#116;]:                 #free                          '```&#10;$ free -t&#10;```&#10;Display a line showing total&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[free -&#115;]:                 #free                          '```&#10;$ free -s $N&#10;```&#10;Continuous operation at `$N`-second intervals&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[free -&#99;]:                  #free                          '```&#10;$ free -c $N&#10;```&#10;Run the program `$N` times'
[free -&#104;]:                 #free                          '```&#10;$ free -h&#10;```&#10;Human-readable output'

<code>&nbsp;</code> <code>&nbsp;</code> [`b`][free -&#98;] [`c`][free -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`h`][free -&#104;] <code>&nbsp;</code> <code>&nbsp;</code> [`k`][free -&#107;] <code>&nbsp;</code> [`m`][free -&#109;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][free -&#115;] [`t`][free -&#116;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

List memory statistics in kilobytes. Without any options, `free` returns a table listing general statistics in kilobytes:
```bash
free
```

Command-line memory dashboard
```bash
watch free -h
```

Display amount of free and used memory in the system [ref][L5PMT-memory]
```sh
free -m
```