[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."

[bunzip2]:                                           archive.md#bunzip2                                 '```&#10;$ bunzip2&#10;```&#10;Decompress an archive created with `bzip2`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2]:                                             archive.md#bzip2                                               '```&#10;$ bzip2&#10;```&#10;Compress or decompress archives using the Burrows-Wheeler block-sorting text-compression algorithm.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzcat]:                                             archive.md#bzcat                                   '```&#10;$ bzcat&#10;```&#10;Page through .bz2 files'
[bzmore]:                                            archive.md#bzmore                                  '```&#10;$ bzmore&#10;```&#10;Page through .bz2 files'
[bzless]:                                            archive.md#bzless                                  '```&#10;$ bzless&#10;```&#10;Page through .bz2 files'
[compress]:                                          #compress                                          '```&#10;$ compress&#10;```&#10;Compress and expand data&#10;&#10;Compress reduces the size of the named files using adaptive Lempel-Ziv coding. Whenever possible, each file is replaced by one with the extension .Z, while keeping the same ownership modes, access and modification times. If no files are specified, the standard input is compressed to the standard output. Compress will only attempt to compress regular files. In particular, it will ignore symbolic links. If a file has multiple hard links, compress will refuse to compress it unless the -f flag is given.'
[cpio]:                                              archive.md#cpio                                    '```&#10;$ cpio&#10;```&#10;Create archives&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[dar]:                                               archive.md#dar                                     '```&#10;$ dar&#10;```&#10;Backup tool that can make differential and incremental backups&#10;"`dar` manpage". _Ubuntu Manpage Repository_.'
[gunzip]:                                            archive.md#gunzip                                  '```&#10;$ gunzip&#10;```&#10;Decompress an archive created with `gzip`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip]:                                              archive.md#gzip                                    '```&#10;$ gzip&#10;```&#10;Compress or decompress archives using the Lempel-Ziv compression algorithm.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 269'
[tar]:                                               archive.md#tar                                     '```&#10;$ tar&#10;```&#10;Merge multiple files into a single file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[unxz]:                                              archive.md#unxz                                    '```&#10;$ unxz&#10;```&#10;Decompress an archive created with `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[unzip]:                                             archive.md#unzip                                   '```&#10;$ unzip&#10;```&#10;Decompress a .zip archive'
[xz]:                                                archive.md#xz                                      '```&#10;$ xz&#10;```&#10;Compress or decompress archives using the LZMA and LZMA2 compression methods.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[zip]:                                               archive.md#zip                                     '```&#10;$ zip&#10;```&#10;Merge multiple files into a single, compressed file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'

<!-- `bzip2` options -->
[bzip2 -&#99;]:                                           #bzip2                                             '```&#10;$ bzip2 -c&#10;$ bzip2 --stdout&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -&#100;]:                                           #bzip2                                             '```&#10;$ bzip2 -d&#10;$ bzip2 --decompress&#10;```&#10;Decompress archive (equivalent to `bunzip2`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -&#118;]:                                           #bzip2                                             '```&#10;$ bzip2 -v&#10;```&#10;Verbose&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -&#102;]:                                           #bzip2                                             '```&#10;$ bzip2 -f&#10;$ bzip2 --force&#10;```&#10;force overwrite of output files'
[bzip2 -&#122;]:                                           #bzip2                                             '```&#10;$ bzip2 -z&#10;$ bzip2 --compress&#10;```&#10;force compression'

<!-- `cpio` options -->
[cpio -0]:                                            #cpio                                              '```&#10;$ cpio -0&#10;$ cpio --null&#10;```&#10;With `-o` or `-p`, read a list of filenames terminated with a `NUL` byte (all zeros) instead of a newline.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 45'
[cpio -&#100;]:                                            #cpio                                              '```&#10;$ cpio -d&#10;$ cpio --make-directories&#10;```&#10;Create directories as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#102;]:                                            #cpio                                              '```&#10;$ cpio -f&#10;$ cpio --nonmatching&#10;```&#10;Reverse the sense of copying; copy all files except those that match `$PATTERNS`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#105;]:                                            #cpio                                              '```&#10;$ cpio -i $PATTERNS&#10;$ cpio --extract $PATTERNS&#10;```&#10;Copy "in" (extract) files whose names match selected `$PATTERNS`, which can include bash filename metacharacters. If no patterns are provided, then all files are copied.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -&#107;]:                                            #cpio                                              '```&#10;$ cpio -k&#10;```&#10;Ignored for compatibility'
[cpio -&#108;]:                                            #cpio                                              '```&#10;$ cpio -l&#10;$ cpio --link&#10;```&#10;Link files instead of copying (can only be used with `-p`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#109;]:                                            #cpio                                              '```&#10;$ cpio -m&#10;$ cpio --preserve-modification-time&#10;```&#10;Retain previous file modification time&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#110;]:                                            #cpio                                              '```&#10;$ cpio -n&#10;$ cpio --numeric-uid-gid&#10;```&#10;When verbosely listing contents, show user ID and group ID numerically&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 45'
[cpio -&#111;]:                                            #cpio                                              '```&#10;$ cpio -o&#10;$ cpio --create&#10;```&#10;Copy "out" a list of files whose names are given on STDIN.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -&#112;]:                                            #cpio                                              '```&#10;$ cpio -p $DIRECTORY&#10;$ cpio --create $DIRECTORY&#10;```&#10;Copy (pass) files to another local directory. Destination pathnames are interpreted relative to the named `$DIRECTORY`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -&#114;]:                                            #cpio                                              '```&#10;$ cpio -r&#10;$ cpio --rename&#10;```&#10;Rename files interactively&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#115;]:                                            #cpio                                              '```&#10;$ cpio -s&#10;$ cpio --swap-bytes&#10;```&#10;Swap bytes of each two-byte half-word&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#116;]:                                            #cpio                                              '```&#10;$ cpio -t&#10;$ cpio --list&#10;```&#10;Print a table of contents of the input (create no files). When used with `-v`, output resembles that of `ls -l`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#117;]:                                            #cpio                                              '```&#10;$ cpio -u&#10;$ cpio --unconditional&#10;```&#10;Unconditional copy; old files can overwrite new ones&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#118;]:                                            #cpio                                              '```&#10;$ cpio -v&#10;$ cpio --verbose&#10;```&#10;Print a list of filenames processed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#65;]:                                            #cpio                                              '```&#10;$ cpio -A&#10;$ cpio --append&#10;```&#10;Append files to an archive (must be used with `-O` or `-F`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#66;]:                                            #cpio                                              '```&#10;$ cpio -B&#10;```&#10;block input or output using 5120 bytes per record (512 bytes is default)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#67;]:                                            #cpio                                              '```&#10;$ cpio -C $N&#10;$ cpio --io-size $N&#10;```&#10;Like `-B`, but block size can be any positive integer `$N`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#69;]:                                            #cpio                                              '```&#10;$ cpio -E $FILE&#10;$ cpio --pattern-file $FILE&#10;```&#10;Extract filenames listed in `$FILE` from the archive&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#70;]:                                            #cpio                                              '```&#10;$ cpio -F $FILE&#10;$ cpio --file $FILE&#10;```&#10;Same as `-O`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#72;]:                                            #cpio                                              '```&#10;$ cpio -H $TYPE&#10;$ cpio --format $TYPE&#10;```&#10;Read or write header information according to `$TYPE`, whose values include:&#10;  - `bin`                 original binary format&#10;  - `crc`                 ASCII header containing expanded device numbers&#10;  - `hpbin`               obsolete binary format used by the HP-UX `cpio`&#10;  - `hpodc`               HP-UX\'s portable format&#10;  - `newc`                SVR4 portable (ASCII) format&#10;  - `odc`                 old POSIX.1 portable (ASCII) format&#10;  - `tar`                 `tar` header&#10;  - `ustar`               IEEE/P1003 Data Interchange Standard header&#10;&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#73;]:                                            #cpio                                              '```&#10;$ cpio -I $FILE&#10;```&#10;Read `$FILE` as an input archive&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#76;]:                                            #cpio                                              '```&#10;$ cpio -L&#10;$ cpio --dereference&#10;```&#10;Follow symbolic links&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#77;]:                                            #cpio                                              '```&#10;$ cpio -M $MESSAGE&#10;$ cpio --message $MESSAGE&#10;```&#10;Print `$MESSAGE` when switching media (valid only with `-I` or `-O`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#79;]:                                            #cpio                                              '```&#10;$ cpio -O $FILE&#10;```&#10;Direct output to `$FILE`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#82;]:                                            #cpio                                              '```&#10;$ cpio -R $ID&#10;$ cpio --owner $ID&#10;```&#10;Reassign file ownership and group information to `$ID` (following the format "user:group")&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#83;]:                                            #cpio                                              '```&#10;$ cpio -S&#10;$ cpio --swap-halfwords&#10;```&#10;Swap half-words of each four-byte word&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#86;]:                                            #cpio                                              '```&#10;$ cpio -V&#10;$ cpio --dot&#10;```&#10;Print a dot for each file read or written (showing cpio working without cluttering the screen).&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -&#97;]:                                            #cpio                                              '```&#10;$ cpio -a&#10;$ cpio --reset-access-time&#10;```&#10;Reset access times of input files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#98;]:                                            #cpio                                              '```&#10;$ cpio -b&#10;$ cpio --swap&#10;```&#10;Swap bytes and half-words to convert between big-endian and little-endian 32-bit integers.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -&#99;]:                                            #cpio                                              '```&#10;$ cpio -c&#10;```&#10;read or write header information as ASCII characters&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'

<!-- `gzip` options -->
[gzip -&#99;]:                                            #gzip                                              '```&#10;$ gzip -c&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#100;]:                                            #gzip                                              '```&#10;$ gzip -d&#10;```&#10;Decompress the file (equivalent to `gunzip`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#114;]:                                            #gzip                                              '```&#10;$ gzip -r&#10;```&#10;Recursive: Used when a directory argument is given to compress all files within it, as well as subdirectories.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -&#118;]:                                            #gzip                                              '```&#10;$ gzip -v&#10;```&#10;Verbose: Display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'


<!-- `tar` options -->
[tar -&#65;]:                                             #tar                                               '```&#10;$ tar -A&#10;$ tar --concatenate&#10;```&#10;Append new files to an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#99;]:                                             #tar                                               '```&#10;$ tar -c&#10;$ tar --create&#10;```&#10;Create an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#67;]:                                             #tar                                               '```&#10;$ tar -C $PATH $FILES&#10;$ tar --directory $PATH $FILES&#10;```&#10;change working directory to `$PATH` before adding $FILES; makes it possible to archive files that do not share a common ancestor directory'
[tar -&#100;]:                                             #tar                                               '```&#10;$ tar -d&#10;```&#10;Compare the difference between the contents of an archive and the files in a directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#102;]:                                             #tar                                               '```&#10;$ tar -f&#10;$ tar --file&#10;```&#10;Specify the name of the archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#106;]:                                             #tar                                               '```&#10;$ tar -j&#10;$ tar --bzip2&#10;```&#10;Compress/uncompress archive using `bzip2`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#74;]:                                             #tar                                               '```&#10;$ tar -J&#10;```&#10;Compress/uncompress archive using `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#112;]:                                             #tar                                               '```&#10;$ tar -p&#10;$ tar --preserve-permissions&#10;```&#10;extract information about file permissions'
[tar -&#114;]:                                             #tar                                               '```&#10;$ tar -r&#10;$ tar --append&#10;```&#10;append files to the end of an archive'
[tar -&#116;]:                                             #tar                                               '```&#10;$ tar -t&#10;$ tar --list&#10;```&#10;List the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#117;]:                                             #tar                                               '```&#10;$ tar -u&#10;```&#10;Update; only append newer files into an existing archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#118;]:                                             #tar                                               '```&#10;$ tar -v&#10;$ tar --verbose&#10;```&#10;Verbose output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#120;]:                                             #tar                                               '```&#10;$ tar -x&#10;$ tar --extract&#10;```&#10;Extract the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#122;]:                                             #tar                                               '```&#10;$ tar -z&#10;$ tar --gzip&#10;```&#10;Compress/uncompress archive using `gzip`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#84;]:                                             #tar                                               '```&#10;$ tar -T $FILENAMES&#10;$ tar --files-from $FILENAMES&#10;```&#10; a list of filenames to be archived, one filename per line, from `$FILENAMES`'

<!-- `xz` options -->
[xz -&#99;]:                                              #xz                                                '```&#10;$ xz -c&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -&#100;]:                                              #xz                                                '```&#10;$ xz -d&#10;```&#10;Decompress archive (equivalent to `unxz`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -&#108;]:                                              #xz                                                '```&#10;$ xz -l&#10;```&#10;List information about an existing archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -&#118;]:                                              #xz                                                '```&#10;$ xz -v&#10;```&#10;Display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'

<!-- `zip` options -->
[zip -&#100;]:                                             #zip                                               '```&#10;$ zip -d&#10;```&#10;Decompress archive (equivalent to `unzip`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -&#118;]:                                             #zip                                               '```&#10;$ zip -v&#10;```&#10;Verbose; display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -&#117;]:                                             #zip                                               '```&#10;$ zip -u&#10;```&#10;Update an archive with new content&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -&#114;]:                                             #zip                                               '```&#10;$ zip -r&#10;```&#10;Zip recursively&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -&#120;]:                                             #zip                                               '```&#10;$ zip -x $FILES&#10;```&#10;Specify files to be excluded from the archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'


# Archive commands
Commands                        | Options
---                             | ---
[`bzip2`][bzip2]                | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][bzip2 -&#99;] [`d`][bzip2 -&#100;] <code>&nbsp;</code> [`f`][bzip2 -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][bzip2 -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`z`][bzip2 -&#122;]
[`cpio`][cpio][` -i`][cpio -&#105;]  | <code>&nbsp;</code>  <code>&nbsp;</code> [`b`][cpio -&#98;] [`c`][cpio -&#99;] [`d`][cpio -&#100;] <code>&nbsp;</code> [`f`][cpio -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`k`][cpio -&#107;] <code>&nbsp;</code> [`m`][cpio -&#109;] [`n`][cpio -&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][cpio -&#114;] [`s`][cpio -&#115;] [`t`][cpio -&#116;] [`u`][cpio -&#117;] [`v`][cpio -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> [`B`][cpio -&#66;] [`C`][cpio -&#67;] <code>&nbsp;</code> [`E`][cpio -&#69;] <code>&nbsp;</code> <code>&nbsp;</code> [`H`][cpio -&#72;] [`I`][cpio -&#73;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`M`][cpio -&#77;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`R`][cpio -&#82;] [`S`][cpio -&#83;] <code>&nbsp;</code> <code>&nbsp;</code> [`V`][cpio -&#86;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 
[`cpio`][cpio][` -o`][cpio -&#111;]  | [`0`][cpio -0]  [`a`][cpio -&#97;] <code>&nbsp;</code> [`c`][cpio -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][cpio -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code> [`A`][cpio -&#65;] [`B`][cpio -&#66;] [`C`][cpio -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> [`F`][cpio -&#70;] <code>&nbsp;</code> [`H`][cpio -&#72;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`L`][cpio -&#76;] [`M`][cpio -&#77;] <code>&nbsp;</code> [`O`][cpio -&#79;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`V`][cpio -&#86;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 
[`cpio`][cpio][` -p`][cpio -&#112;]  | [`0`][cpio -0]  [`a`][cpio -&#97;] <code>&nbsp;</code> <code>&nbsp;</code> [`d`][cpio -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][cpio -&#108;] [`m`][cpio -&#109;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`u`][cpio -&#117;] [`v`][cpio -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`L`][cpio -&#76;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`R`][cpio -&#82;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`V`][cpio -&#86;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 
[`gzip`][gzip]                  | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][gzip -&#99;] [`d`][gzip -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][gzip -&#114;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][gzip -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>
[`tar`][tar]                    | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][tar -&#99;] [`d`][tar -&#100;] <code>&nbsp;</code> [`f`][tar -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`j`][tar -&#106;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][tar -&#112;] <code>&nbsp;</code> [`r`][tar -&#114;] <code>&nbsp;</code> [`t`][tar -&#116;] [`u`][tar -&#117;] [`v`][tar -&#118;] <code>&nbsp;</code> [`x`][tar -&#120;] <code>&nbsp;</code> [`z`][tar -&#122;]  <br><code>&nbsp;</code> [`A`][tar -&#65;] <code>&nbsp;</code> [`C`][tar -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`J`][tar -&#74;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 
[`xz`][xz]                      | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][xz -&#99;] [`d`][xz -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][xz -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][xz -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>
[`zip`][zip]                    | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][zip -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][zip -&#114;] <code>&nbsp;</code> <code>&nbsp;</code> [`u`][zip -&#117;] [`v`][zip -&#118;] <code>&nbsp;</code> [`x`][zip -&#120;] <code>&nbsp;</code> <code>&nbsp;</code>


### `bzip2`
Compress `$SYMLINK`
```sh
bzip2 -f $SYMLINK
bzip2 --force $SYMLINK
```
### `compress`
Display contents of the compressed file to stdout (same as using `zcat`)
```sh
compress -c
```
Compress symbolic links
```sh
compress -f
```
Compress files recursively within a specified directory
```sh
compress -r
```
### `dar`
Create a differential (or incremental) backup of {file}, using full.bak as reference
```sh
dar -R /path/to/file -c diff1.bak -A full.bak
```
Create a full backup of {file}
```sh
dar -R /path/to/file -c full.bak
```
Restore full.bak
```sh
dar -x full.bak
```
### `gzip`
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
### `tar`
Create {archive} from contents of {path}
```sh
tar -cf archive path
tar --create --file archive path
```
Create bzip2-compressed {archive} from contents of {path}
```sh
tar -cfj archive path
tar --create --file --bzip archive path
```
Create gzip-compressed {archive} from contents of {path}
```sh
tar -cfz archive path
tar --create --file --gzip archive path
```
Add {file} to {archive}
```sh
tar -rf archive file
tar --append --file archive file
```
List the contents of {archive}
```sh
tar -tf archive
tar --list --file archive
```
Extract contents of {tarfile} in the current directory
```sh
tar -xf archive
tar --extract --file archive
```
Extract only {file} from {archive}
```sh
tar -xf archive file tar--extract --file archive file
```
Extract contents of gzip-compressed {archive} to {path}
```sh
tar -xzf archive -C path
```
### `uncompress`
Option  | Effect
:---    | :---
`-f`    | overwrite existing files without prompting, if they exist
`-r`    | decompress files recursively
### `unzip`
Extract compressed files in a zip archive
### `zip`
Archive files in InfoZIP format
```sh
zip zipfile *files
```
