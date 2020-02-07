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

# Archive commands
Commands                        | Options
---                             | ---
[`ar`][ar]                      |
[`bzip2`][bzip2]                | <code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][bzip2 -&#99;] [`d`][bzip2 -&#100;] <code>&nbsp;</code> [`f`][bzip2 -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][bzip2 -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`z`][bzip2 -&#122;]
[`compress`][compress]          | 
[`cpio`][cpio][` -i`][cpio -i]  | <code>&nbsp;</code> <code>&nbsp;</code>  [`b`][cpio -b]  [`c`][cpio -c]&nbsp;[`d`][cpio -d]  <code>&nbsp;</code>  [`f`][cpio -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`m`][cpio -m]  [`n`][cpio -n]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`r`][cpio -r]  [`s`][cpio -s]  [`t`][cpio -t]  [`u`][cpio -u]  [`v`][cpio -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br> <code>&nbsp;</code> <code>&nbsp;</code>  [`B`][cpio -B]  [`C`][cpio -C]  <code>&nbsp;</code>  [`E`][cpio -E]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`H`][cpio -H]  [`I`][cpio -I]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`M`][cpio -M]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`R`][cpio -R]  [`S`][cpio -S]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`V`][cpio -V]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
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