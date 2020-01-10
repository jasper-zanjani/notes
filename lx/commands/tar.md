### tar
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