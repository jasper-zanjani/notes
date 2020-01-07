### bzcat
Page through bz2 files
### bzless
Page through bz2 files
### bzmore
Page through bz2 files
### bzip2
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