[sort -&#102;]: #sort '```&#10;$ sort -f&#10;```&#10;Case-insensitive sort&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 84'
[sort -&#107;]: #sort '```&#10;$ sort -k $N,$M&#10;```&#10;Sort on the key starting at `$N` and (optionally) ending at `$M`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 84'
[sort -&#110;]: #sort '```&#10;$ sort -n&#10;```&#10;Sort numerically&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 85'
[sort -&#114;]: #sort '```&#10;$ sort -r&#10;```&#10;Sort in reverse order&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 85'
[sort -&#116;]: #sort '```&#10;$ sort -t $SEP&#10;```&#10;Use `$SEP` as the key separator (whitespace by default)&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 85'
[sort -&#104;]: #sort '```&#10;$ sort -h&#10;```&#10;Human-based numeric sort (i.e. "2K" is lower than "1G")&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 66'
[sort -&#77;]: #sort '```&#10;$ sort -M&#10;```&#10;Month-based sort&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 66'
[sort -&#117;]: #sort '```&#10;$ sort -u&#10;```&#10;Remove duplicate lines&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 66'

<code>&nbsp;</code>   <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`f`][sort -&#102;] <code>&nbsp;</code> [`h`][sort -&#104;] <code>&nbsp;</code> <code>&nbsp;</code> [`k`][sort -&#107;] <code>&nbsp;</code> <code>&nbsp;</code> [`n`][sort -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][sort -&#114;] <code>&nbsp;</code> [`t`][sort -&#116;] [`u`][sort -&#117;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`M`][sort -&#77;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Sort by space-delimited columns. Processes consuming the most memory will be at the bottom 
```sh
ps aux | sort -nk 4
```
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```