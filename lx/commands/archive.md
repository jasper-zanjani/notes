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
[uncompress]:                                        package.md#uncompress                              '```&#10;$ uncompress&#10;```&#10;Aliased to `gunzip` on Ubuntu'
[unxz]:                                              archive.md#unxz                                    '```&#10;$ unxz&#10;```&#10;Decompress an archive created with `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[unzip]:                                             archive.md#unzip                                   '```&#10;$ unzip&#10;```&#10;Decompress a .zip archive'
[xz]:                                                archive.md#xz                                      '```&#10;$ xz&#10;```&#10;Compress or decompress archives using the LZMA and LZMA2 compression methods.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[zip]:                                               archive.md#zip                                     '```&#10;$ zip&#10;```&#10;Merge multiple files into a single, compressed file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'

[bzip2 -c]:                                           #bzip2                                             '```&#10;$ bzip2 -c&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -d]:                                           #bzip2                                             '```&#10;$ bzip2 -d&#10;```&#10;Decompress archive (equivalent to `bunzip2`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -v]:                                           #bzip2                                             '```&#10;$ bzip2 -v&#10;```&#10;Verbose&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzip2 -f]:                                           #bzip2                                             '```&#10;$ bzip2 -f&#10;$ bzip2 --force&#10;```&#10;force overwrite of output files'
[bzip2 -z]:                                           #bzip2                                             '```&#10;$ bzip2 -z&#10;$ bzip2 --compress&#10;```&#10;force compression'
[cpio -0]:                                            #cpio                                              '```&#10;$ cpio -0&#10;$ cpio --null&#10;```&#10;With `-o` or `-p`, read a list of filenames terminated with a `NUL` byte (all zeros) instead of a newline.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 45'
[cpio -a]:                                            #cpio                                              '```&#10;$ cpio -a&#10;$ cpio --reset-access-time&#10;```&#10;Reset access times of input files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -A]:                                            #cpio                                              '```&#10;$ cpio -A&#10;$ cpio --append&#10;```&#10;Append files to an archive (must be used with `-O` or `-F`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -b]:                                            #cpio                                              '```&#10;$ cpio -b&#10;$ cpio --swap&#10;```&#10;Swap bytes and half-words to convert between big-endian and little-endian 32-bit integers.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -B]:                                            #cpio                                              '```&#10;$ cpio -B&#10;```&#10;block input or output using 5120 bytes per record (512 bytes is default)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -c]:                                            #cpio                                              '```&#10;$ cpio -c&#10;```&#10;read or write header information as ASCII characters&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -C]:                                            #cpio                                              '```&#10;$ cpio -C $N&#10;$ cpio --io-size $N&#10;```&#10;Like `-B`, but block size can be any positive integer `$N`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -d]:                                            #cpio                                              '```&#10;$ cpio -d&#10;$ cpio --make-directories&#10;```&#10;Create directories as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -E]:                                            #cpio                                              '```&#10;$ cpio -E $FILE&#10;$ cpio --pattern-file $FILE&#10;```&#10;Extract filenames listed in `$FILE` from the archive&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -f]:                                            #cpio                                              '```&#10;$ cpio -f&#10;$ cpio --nonmatching&#10;```&#10;Reverse the sense of copying; copy all files except those that match `$PATTERNS`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -F]:                                            #cpio                                              '```&#10;$ cpio -F $FILE&#10;$ cpio --file $FILE&#10;```&#10;Same as `-O`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -H]:                                            #cpio                                              '```&#10;$ cpio -H $TYPE&#10;$ cpio --format $TYPE&#10;```&#10;Read or write header information according to `$TYPE`, whose values include:&#10;  - `bin`                 original binary format&#10;  - `crc`                 ASCII header containing expanded device numbers&#10;  - `hpbin`               obsolete binary format used by the HP-UX `cpio`&#10;  - `hpodc`               HP-UX\'s portable format&#10;  - `newc`                SVR4 portable (ASCII) format&#10;  - `odc`                 old POSIX.1 portable (ASCII) format&#10;  - `tar`                 `tar` header&#10;  - `ustar`               IEEE/P1003 Data Interchange Standard header&#10;&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -i]:                                            #cpio                                              '```&#10;$ cpio -i $PATTERNS&#10;$ cpio --extract $PATTERNS&#10;```&#10;Copy "in" (extract) files whose names match selected `$PATTERNS`, which can include bash filename metacharacters. If no patterns are provided, then all files are copied.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -I]:                                            #cpio                                              '```&#10;$ cpio -I $FILE&#10;```&#10;Read `$FILE` as an input archive&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -l]:                                            #cpio                                              '```&#10;$ cpio -l&#10;$ cpio --link&#10;```&#10;Link files instead of copying (can only be used with `-p`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -L]:                                            #cpio                                              '```&#10;$ cpio -L&#10;$ cpio --dereference&#10;```&#10;Follow symbolic links&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 43'
[cpio -m]:                                            #cpio                                              '```&#10;$ cpio -m&#10;$ cpio --preserve-modification-time&#10;```&#10;Retain previous file modification time&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -M]:                                            #cpio                                              '```&#10;$ cpio -M $MESSAGE&#10;$ cpio --message $MESSAGE&#10;```&#10;Print `$MESSAGE` when switching media (valid only with `-I` or `-O`)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -n]:                                            #cpio                                              '```&#10;$ cpio -n&#10;$ cpio --numeric-uid-gid&#10;```&#10;When verbosely listing contents, show user ID and group ID numerically&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 45'
[cpio -o]:                                            #cpio                                              '```&#10;$ cpio -o&#10;$ cpio --create&#10;```&#10;Copy "out" a list of files whose names are given on STDIN.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -O]:                                            #cpio                                              '```&#10;$ cpio -O $FILE&#10;```&#10;Direct output to `$FILE`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -p]:                                            #cpio                                              '```&#10;$ cpio -p $DIRECTORY&#10;$ cpio --create $DIRECTORY&#10;```&#10;Copy (pass) files to another local directory. Destination pathnames are interpreted relative to the named `$DIRECTORY`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 42'
[cpio -r]:                                            #cpio                                              '```&#10;$ cpio -r&#10;$ cpio --rename&#10;```&#10;Rename files interactively&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -R]:                                            #cpio                                              '```&#10;$ cpio -R $ID&#10;$ cpio --owner $ID&#10;```&#10;Reassign file ownership and group information to `$ID` (following the format "user:group")&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -s]:                                            #cpio                                              '```&#10;$ cpio -s&#10;$ cpio --swap-bytes&#10;```&#10;Swap bytes of each two-byte half-word&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -S]:                                            #cpio                                              '```&#10;$ cpio -S&#10;$ cpio --swap-halfwords&#10;```&#10;Swap half-words of each four-byte word&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -t]:                                            #cpio                                              '```&#10;$ cpio -t&#10;$ cpio --list&#10;```&#10;Print a table of contents of the input (create no files). When used with `-v`, output resembles that of `ls -l`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -u]:                                            #cpio                                              '```&#10;$ cpio -u&#10;$ cpio --unconditional&#10;```&#10;Unconditional copy; old files can overwrite new ones&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -v]:                                            #cpio                                              '```&#10;$ cpio -v&#10;$ cpio --verbose&#10;```&#10;Print a list of filenames processed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[cpio -V]:                                            #cpio                                              '```&#10;$ cpio -V&#10;$ cpio --dot&#10;```&#10;Print a dot for each file read or written (showing cpio working without cluttering the screen).&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 44'
[gzip -c]:                                            #gzip                                              '```&#10;$ gzip -c&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -d]:                                            #gzip                                              '```&#10;$ gzip -d&#10;```&#10;Decompress the file (equivalent to `gunzip`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -r]:                                            #gzip                                              '```&#10;$ gzip -r&#10;```&#10;Recursive: Used when a directory argument is given to compress all files within it, as well as subdirectories.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[gzip -v]:                                            #gzip                                              '```&#10;$ gzip -v&#10;```&#10;Verbose: Display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[tar -A]:                                             #tar                                               '```&#10;$ tar -A&#10;$ tar --concatenate&#10;```&#10;Append new files to an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -c]:                                             #tar                                               '```&#10;$ tar -c&#10;$ tar --create&#10;```&#10;Create an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -C]:                                             #tar                                               '```&#10;$ tar -C $PATH $FILES&#10;$ tar --directory $PATH $FILES&#10;```&#10;change working directory to `$PATH` before adding $FILES; makes it possible to archive files that do not share a common ancestor directory'
[tar -d]:                                             #tar                                               '```&#10;$ tar -d&#10;```&#10;Compare the difference between the contents of an archive and the files in a directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -f]:                                             #tar                                               '```&#10;$ tar -f&#10;$ tar --file&#10;```&#10;Specify the name of the archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -j]:                                             #tar                                               '```&#10;$ tar -j&#10;$ tar --bzip2&#10;```&#10;Compress/uncompress archive using `bzip2`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -J]:                                             #tar                                               '```&#10;$ tar -J&#10;```&#10;Compress/uncompress archive using `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -p]:                                             #tar                                               '```&#10;$ tar -p&#10;$ tar --preserve-permissions&#10;```&#10;extract information about file permissions'
[tar -r]:                                             #tar                                               '```&#10;$ tar -r&#10;$ tar --append&#10;```&#10;append files to the end of an archive'
[tar -T]:                                             #tar                                               '```&#10;$ tar -T $FILENAMES&#10;$ tar --files-from $FILENAMES&#10;```&#10; a list of filenames to be archived, one filename per line, from `$FILENAMES`'
[tar -t]:                                             #tar                                               '```&#10;$ tar -t&#10;$ tar --list&#10;```&#10;List the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -u]:                                             #tar                                               '```&#10;$ tar -u&#10;```&#10;Update; only append newer files into an existing archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -v]:                                             #tar                                               '```&#10;$ tar -v&#10;$ tar --verbose&#10;```&#10;Verbose output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -x]:                                             #tar                                               '```&#10;$ tar -x&#10;$ tar --extract&#10;```&#10;Extract the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -z]:                                             #tar                                               '```&#10;$ tar -z&#10;$ tar --gzip&#10;```&#10;Compress/uncompress archive using `gzip`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[uncompress -f]:                                      #uncompress                                        '```&#10;$ uncompress -f&#10;```&#10;overwrite existing files without prompting, if they exist'
[uncompress -r]:                                      #uncompress                                        '```&#10;$ uncompress -r&#10;```&#10;decompress files recursively'
[xz -c]:                                              #xz                                                '```&#10;$ xz -c&#10;```&#10;Write output to STDOUT and do not replace the original file.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -d]:                                              #xz                                                '```&#10;$ xz -d&#10;```&#10;Decompress archive (equivalent to `unxz`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -l]:                                              #xz                                                '```&#10;$ xz -l&#10;```&#10;List information about an existing archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[xz -v]:                                              #xz                                                '```&#10;$ xz -v&#10;```&#10;Display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[zip -d]:                                             #zip                                               '```&#10;$ zip -d&#10;```&#10;Decompress archive (equivalent to `unzip`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -v]:                                             #zip                                               '```&#10;$ zip -v&#10;```&#10;Verbose; display percentage of compression&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -u]:                                             #zip                                               '```&#10;$ zip -u&#10;```&#10;Update an archive with new content&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -r]:                                             #zip                                               '```&#10;$ zip -r&#10;```&#10;Zip recursively&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'
[zip -x]:                                             #zip                                               '```&#10;$ zip -x $FILES&#10;```&#10;Specify files to be excluded from the archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 272'

# Archive commands
Commands                        | Options
---                             | ---
[`ar`][ar]                      |
[`bzcat`][bzcat]                |
[`bzless`][bzless]              |
[`bzmore`][bzmore]              |
[`bzip2`][bzip2]                | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`c`][bzip2 -c]  [`d`][bzip2 -d]  <code>&nbsp;</code>  [`f`][bzip2 -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`v`][bzip2 -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`z`][bzip2 -z] 
[`compress`][compress]          | 
[`cpio`][cpio][` -i`][cpio -i]  | <code>&nbsp;</code> <code>&nbsp;</code>  [`b`][cpio -b]  [`c`][cpio -c]  [`d`][cpio -d]  <code>&nbsp;</code>  [`f`][cpio -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`m`][cpio -m]  [`n`][cpio -n]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`r`][cpio -r]  [`s`][cpio -s]  [`t`][cpio -t]  [`u`][cpio -u]  [`v`][cpio -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br> <code>&nbsp;</code> <code>&nbsp;</code>  [`B`][cpio -B]  [`C`][cpio -C]  <code>&nbsp;</code>  [`E`][cpio -E]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`H`][cpio -H]  [`I`][cpio -I]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`M`][cpio -M]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`R`][cpio -R]  [`S`][cpio -S]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`V`][cpio -V]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`cpio`][cpio][` -o`][cpio -o]  | [`0`][cpio -0]  [`a`][cpio -a]  <code>&nbsp;</code>  [`c`][cpio -c]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`v`][cpio -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br> <code>&nbsp;</code> [`A`][cpio -A]  [`B`][cpio -B]  [`C`][cpio -C]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`F`][cpio -F]  <code>&nbsp;</code>  [`H`][cpio -H]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`L`][cpio -L]  [`M`][cpio -M]  <code>&nbsp;</code>  [`O`][cpio -O]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`V`][cpio -V]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`cpio`][cpio][` -p`][cpio -p]  | [`0`][cpio -0]  [`a`][cpio -a]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`d`][cpio -d]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`l`][cpio -l]  [`m`][cpio -m]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`u`][cpio -u]  [`v`][cpio -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br>  <code>&nbsp;</code> <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`L`][cpio -L]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`P`][cpio -P]  <code>&nbsp;</code>  [`R`][cpio -R]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`V`][cpio -V]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`dar`][dar]                    |
[`gunzip`][gunzip]              |
[`gzip`][gzip]                  | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`c`][gzip -c]  [`d`][gzip -d]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`r`][gzip -r]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`v`][gzip -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> 
[`tar`][tar]                    | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`c`][tar -c]  [`d`][tar -d]  <code>&nbsp;</code>  [`f`][tar -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`j`][tar -j]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`p`][tar -p]  <code>&nbsp;</code>  [`r`][tar -r]  <code>&nbsp;</code>  [`t`][tar -t]  [`u`][tar -u]  [`v`][tar -v]  <code>&nbsp;</code>  [`x`][tar -x]  <code>&nbsp;</code>  [`z`][tar -z] <br><code>&nbsp;</code>  [`A`][tar -A]  <code>&nbsp;</code>  [`C`][tar -C]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`J`][tar -J]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`T`][tar -T]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`uncompress`][uncompress]      | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`f`][uncompress -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`r`][uncompress -r]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> 
[`unxz`][unxz]                  |
[`unzip`][unzip]                |
[`xz`][xz]                      | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`c`][xz -c]  [`d`][xz -d]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`l`][xz -l]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`v`][xz -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> 
[`zip`][zip]                    | <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`d`][zip -d]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`r`][zip -r]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`u`][zip -u]  [`v`][zip -v]  <code>&nbsp;</code>  [`x`][zip -x]  <code>&nbsp;</code>  <code>&nbsp;</code>


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

[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."