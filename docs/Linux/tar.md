[tar -&#65;]:                   #tar                           '```&#10;$ tar -&#65;&#10;$ tar --concatenate&#10;```&#10;Append new files to an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#99;]:                   #tar                           '```&#10;$ tar -&#99;&#10;$ tar --create&#10;```&#10;Create an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#67;]:                   #tar                           '```&#10;$ tar -&#67; $PATH $FILES&#10;$ tar --directory $PATH $FILES&#10;```&#10;change working directory to `$PATH` before adding $FILES; makes it possible to archive files that do not share a common ancestor directory'
[tar -&#100;]:                  #tar                           '```&#10;$ tar -&#100;&#10;```&#10;Compare the difference between the contents of an archive and the files in a directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#102;]:                  #tar                           '```&#10;$ tar -&#102;&#10;$ tar --file&#10;```&#10;Specify the name of the archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#106;]:                  #tar                           '```&#10;$ tar -&#106;&#10;$ tar --bzip2&#10;```&#10;Compress/uncompress archive using `bzip2`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#74;]:                   #tar                           '```&#10;$ tar -&#74;&#10;```&#10;Compress/uncompress archive using `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#112;]:                  #tar                           '```&#10;$ tar -&#112;&#10;$ tar --preserve-permissions&#10;```&#10;extract information about file permissions'
[tar -&#114;]:                  #tar                           '```&#10;$ tar -&#114;&#10;$ tar --append&#10;```&#10;append files to the end of an archive'
[tar -&#116;]:                  #tar                           '```&#10;$ tar -&#116;&#10;$ tar --list&#10;```&#10;List the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#117;]:                  #tar                           '```&#10;$ tar -&#117;&#10;```&#10;Update; only append newer files into an existing archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#118;]:                  #tar                           '```&#10;$ tar -&#118;&#10;$ tar --verbose&#10;```&#10;Verbose output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#120;]:                  #tar                           '```&#10;$ tar -&#120;&#10;$ tar --extract&#10;```&#10;Extract the contents of an archive&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#122;]:                  #tar                           '```&#10;$ tar -&#122;&#10;$ tar --gzip&#10;```&#10;Compress/uncompress archive using `gzip`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tar -&#84;]:                   #tar                           '```&#10;$ tar -&#84; $FILENAMES&#10;$ tar --files-from $FILENAMES&#10;```&#10; a list of filenames to be archived, one filename per line, from `$FILENAMES`'

<code>&nbsp;</code>  <code>&nbsp;</code> <code>&nbsp;</code> [`c`][tar -&#99;] [`d`][tar -&#100;] <code>&nbsp;</code> [`f`][tar -&#102;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`j`][tar -&#106;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][tar -&#112;] <code>&nbsp;</code> [`r`][tar -&#114;] <code>&nbsp;</code> [`t`][tar -&#116;] [`u`][tar -&#117;] [`v`][tar -&#118;] <code>&nbsp;</code> [`x`][tar -&#120;] <code>&nbsp;</code> [`z`][tar -&#122;]  <br><code>&nbsp;</code> [`A`][tar -&#65;] <code>&nbsp;</code> [`C`][tar -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`J`][tar -&#74;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

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