### gzip
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