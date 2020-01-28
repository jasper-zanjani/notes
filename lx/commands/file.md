# Linux file manipulation commands
&nbsp;  | Commands
---     | ---
&nbsp;  | [`install`][install] `ls` `lsof` `mkdir` `shred` [`tree`][tree]
### `install`
Copy files while maintaining various metadata, including timestamp, owner, etc. [[9](sources.md)]

Copy a file while preserving timestamp. The copy will have the `install` default of `755`, but the original's `mtime` is maintained:
```sh
install --preserve-timestamp example/foo .
```
Copy a file, setting permissions, owner, and group
```sh
install --preserve-timestamp --owner=jdoe --group=sudoers --mode=753
```
### `ls`
Display hidden files
```sh
ls -a
ls --all
```
Append indicators to entries
```sh
ls -F
ls --classify
```
Display SELinux context for files
```sh
ls -Z
```
### `lsof`
Display open files, open network ports, and network connections [[23](sources.md)]

Option  | Effect
:---    | :---
`-i`    | display network connections
`-n`    | prevent the conversion of IP addresses to hostnames
`-P`    | prevent the conversion of port numbers to port names

Show open network connections
```sh
sudo lsof -Pni
```
### `mkdir`
Quickly create multiple directories using brace expansion
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
Create new directory {dirname} along with all of the parents in its pathname, if they do not exist
```sh
mkdir -p dirname
mkdir --parents dirname
```
### `shred`
Write random data to an unmounted disk for {n} passes
```sh
shred --iterations=n
```
### `tree`
Display contents of directories in a tree-like format [^][46]

Option  | Effect
:---    | :---
`-a`    | all files
`-d`    | display directories only
`-f`    | display full path prefix for each file
`-g`    | display group name or GID for each file
`-p`    | display permissions, similar to `ls -l`
`-u`    | display username or UID
`-L $N` | limit to `$N` maximum depth
`-I $PATTERN` | suppress files matching `$PATTERN`
`-P $PATTERN` | display only files matching `$PATTERN`
`--prune`     | suppress empty directories
## 
[install]:                                           #install                                    '```&#10;$ install&#10;```&#10;Copy files while maintaining metadata'
[lsof]:                                              #lsof                                       '```&#10;lsof&#10;```&#10;Display open files, open network ports, and network connections&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[tree]:                                              #tree                                       '```&#10;$ tree&#10;```&#10;Display contents of directories in a tree-like format'