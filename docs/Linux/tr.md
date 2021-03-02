[tr -&#99;]: #tr '```&#10;$ tr -c&#10;```&#10;Use the complement of (or all characters not in) `$STRING`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 88'
[tr -&#100;]: #tr '```&#10;$ tr -d&#10;```&#10;Delete characters in `$STRING` from the output&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 88'
[tr -&#115;]: #tr '```&#10;$ tr -s&#10;```&#10;Squeeze out repeated output characters in `$STRING`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 88'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`c`][tr -&#99;] [`d`][tr -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][tr -&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Change the case of a string ]
```sh
tr [:upper:] [:lower:]
```
Remove a character or set of characters from a string or line of output
```sh
tr -d "text"
```
