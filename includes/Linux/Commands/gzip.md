[gzip -&#99;]:                  #gzip                          '```&#10;$ gzip -&#99;&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#100;]:                 #gzip                          '```&#10;$ gzip -&#100;&#10;```&#10;Decompress the file (equivalent to `gunzip`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#114;]:                 #gzip                          '```&#10;$ gzip -&#114;&#10;```&#10;Recursive: Used when a directory argument is given to compress all files within it, as well as subdirectories.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#118;]:                 #gzip                          '```&#10;$ gzip -&#118;&#10;```&#10;Verbose: Display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'

<code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][gzip -&#99;] [`d`][gzip -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][gzip -&#114;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][gzip -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>

Zip a single file in-place; each file is replaced by one with the extension `.gz` or `.z`, maintaining ownership modes, access and modification times
```sh
gzip -#
gzip --fast
gzip --best
```
Compress {symlink}
```sh
gzip -f symlink
gzip --force symlink
```
Page through .gz files
