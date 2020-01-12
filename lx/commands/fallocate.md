### `fallocate`
Allocate and deallocate space to a file

Create a file size of 1 gigabyte
```sh
fallocate -l 1G $FILENAME  # gibibyte
fallocate -l 1GB $FILENAME # gigabyte
```