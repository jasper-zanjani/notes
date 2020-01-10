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

### uncompress
Option  | Effect
:---    | :---
`-f`    | overwrite existing files without prompting, if they exist
`-r`    | decompress files recursively