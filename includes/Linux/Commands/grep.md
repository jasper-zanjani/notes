[grep -&#99;]:  #grep '```&#10;$ grep -c&#10;$ grep --count&#10;```&#10;Display only a count of matched lines, but not the lines themselves.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#104;]: #grep '```&#10;$ grep -h&#10;```&#10;Display matched lines, but do not include filenames for multiple file input.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#105;]: #grep '```&#10;$ grep -i&#10;```&#10;Case-insensitive search.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#110;]: #grep '```&#10;$ grep -n&#10;$ grep --line-number&#10;```&#10;Display matched lines prefixed with their line numbers.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#118;]: #grep '```&#10;$ grep -v&#10;$ grep --invert-match&#10;```&#10;Print all lines that do not match `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#69;]:  #grep '```&#10;$ grep -E&#10;```&#10;Interpret `$PATTERN` as an extended regular expression&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[grep -&#108;]: #grep '```&#10;$ grep -l&#10;$ grep --files-with-matches&#10;```&#10;Display filenames that match the pattern, rather than the lines of matches themselves&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 100'
[grep -&#119;]: #grep '```&#10;$ grep -w&#10;```&#10;Match whole words only&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 100'
[grep -&#114;]: #grep '```&#10;$ grep -r&#10;```&#10;Recursively search all the files in the directory structure&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 100'
[grep -&#102;]: #grep '```&#10;$ grep -f&#10;```&#10;Fixed strings; all characters in the pattern will be treated as regular characters&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 100'
[grep -&#65;]:  #grep '```&#10;$ grep -A $N&#10;```&#10;print `$N` lines of trailing context from the file after each match'
[grep -&#66;]:  #grep '```&#10;$ grep -B $N&#10;```&#10;print `$N` lines of leading context from the file after each match'
[grep -&#67;]:  #grep '```&#10;$ grep -C $N&#10;```&#10;print `$N` lines of leading and trailing context surrounding each match'
[grep -&#69;]:  #grep '```&#10;$ grep -E&#10;$ grep --extended-regexp&#10;```&#10;force grep to use extended regular expressions, making it similar to `egrep`'
[grep -&#70;]:  #grep '```&#10;$ grep -F&#10;$ grep --fixed-strings&#10;```&#10;force grep to interpret pattern as fixed strings, making it similar to `fgrep`'
[grep -&#72;]:  #grep '```&#10;$ grep -H&#10;```&#10;always print filename headers with output lines'

<code>&nbsp;</code>   <code>&nbsp;</code> <code>&nbsp;</code> [`c`][grep -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> [`f`][grep -&#102;] <code>&nbsp;</code> [`h`][grep -&#104;] [`i`][grep -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> [`l`][grep -&#108;] <code>&nbsp;</code> [`n`][grep -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][grep -&#114;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][grep -&#118;] [`w`][grep -&#119;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;[`A`][grep -&#65;] [`B`][grep -&#66;] [`C`][grep -&#67;] <code>&nbsp;</code> [`E`][grep -&#69;] [`F`][grep -&#70;] <code>&nbsp;</code> [`H`][grep -&#72;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

### head
[head -&#99;]: #head '```&#10;$ head -c $N&#10;```&#10;Print the first `$N` bytes. If `$N` is followed by "k" or "m", the first `$N` kilobytes or megabytes, respectively.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 80'
[head -&#110;]: #head '```&#10;$ head -n $N&#10;```&#10;Print the first `$N` lines (10 by default)&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 80'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`c`][head -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`n`][head -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Print first 8 characters of `$FILE`
```sh
head -c8 $FILE
```