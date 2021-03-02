Copy files while maintaining various metadata, including timestamp, owner, etc. [[9]()]

Copy a file while preserving timestamp. The copy will have the `install` default of `755`, but the original's `mtime` is maintained:
```sh
install --preserve-timestamp example/foo .
```
Copy a file, setting permissions, owner, and group
```sh
install --preserve-timestamp --owner=jdoe --group=sudoers --mode=753
```