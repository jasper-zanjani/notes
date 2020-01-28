# Archive commands
&nbsp;  | Commands
---     | ---
&nbsp;  | `ar` &bull; `bzcat` `bzless` `bzmore` `bzip2` &bull; `compress` `cpio` &bull; `dar` &bull; `gzip` &bull; `tar` &bull; `uncompress` `unzip`  &bull; `zip` `zipcloak` `zipdetails` `zipgrep` `zipinfo` `zipnote` `zipsplit`
### `ar`
### `bzcat`
Page through bz2 files
### `bzless`
Page through bz2 files
### `bzmore`
Page through bz2 files
### `bzip2`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    | `--stdout`              | compress or decompress to standard output
`-d`    | `--decompress`          | force decompression
`-z`    | `--compress`            | force compression
`-f`    | `--force`               | force overwrite of output files

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
### `cpio`
Option  | POSIX option            | Effect [^][Eckert]
:---    | :---                    | :---
`-A`    | `--append`              | append files to an existing archive
`-d`    | `--make-directories`    | create directories as needed during extraction
`-i`    | `--extract`             | read files from an archive
`-L`    | `--dereference`         | prevent cpio from backing up symbolic links, only their target files
`-o`    | `--create`              | create a new archive
`-t`    | `--list`                | list the filename contents ("**t**able of contents")
`-u`    | `--unconditional`       | overwrite existing files during extraction without prompting for u ser confirmation
`-B`    |                         | change default block size from 512 bytes to 5KB, speeding up the transfer of information
`-c`    |                         | use a storage format (SVR4) that is widely recognized by different versions of cpio for UNIX and Linux
`-I`    |                         | indicate **i**nput device or file when viewing or extracting files
\-      | `--no-absolute-filenames` | store filenames in an archive using relative pathnames
`-O`    |                         | indicate **o**utput archive
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
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    | `--create`              | create a new archive
`-C`    | `--directory`           | change directory `$PATH` before adding `$FILES` to the tar archive, using relative pathnames; makes it possible to archive files that don't share a common ancestor directory
`-f`    | `--file`                | use file or device
`-j`    | `--bzip2`               | filter the archive through [`bzip2`](#bzip2
`-p`    | `--preserve-permissions`| extract information about file perfmissions
`-r`    | `--append`              | append files to the end of an archive
`-t`    | `--list`                | list the contents of an archive
`-T`    | `--files-from`          | read a list of filenames to be archived, one filename per line, from file
`-x`    | `--extract`<br/>`--get` | extract files from an archive
`-z`    | `--gzip`                | filter the archive through [`gzip`](#gzip)

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
### `zipcloak`
Encrypt a zip {archive}
```sh
zipcloak archive
```
### `zipdetails`
Produce a detailed list of information about a zip {archive}
```sh
zipdetails archive
```
### `zipgrep`
Search for {string} within all files of a zip {archive}
```sh
zipgrep string archive
```
### `zipinfo`
Print information about ZIP format archives
```sh
zipinfo *zipfiles
```
### `zipnote`
Annotate a zip {archive} by creating a {comments} file, which can then be edited and rewritten with `-w` flag
```sh
zipnote archive > comments
```
### `zipsplit`
Split `zipfile` into segments of size `size`
```sh
zipsplit -n size zipfile
```
## 
[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."