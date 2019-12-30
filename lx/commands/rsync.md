### `rsync`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-a`    | `--archive`             | copy recursively, preserving group, owner, modification times, and device-files (if super-user) (equivalent to `-rptlgoD`)
`-b`    |                         | create a backup of every file transferred
`-e`    | `--rsh`                 | specify remote shell to use
`-g`    | `--group`               | preserve group
`-o`    | `--owner`               | preserve owner
`-p`    |                         | specify nonstandard port
\-      | `--delete`              | remove files and folders that aren't in the sender system
\-      | `--exclude`             | exclude files (accepts globbing)
\-      | `--include`             | specify specific files (accepts globbing)
\-      | `--progress`            | display a progress bar
\-      | `--remove-source-files` | remove original files after synchronization

Copy `$FILE` locally [^][44]
```sh
rsync -zvr $FILE $PATH
```
Copy `$FILE` to `$PATH` on remote `$HOST`
```sh
rsync $FILE $HOST:$PATH
```
Copy $FILE from $HOST to local $PATH
```sh
rsync $HOST:$FILE $PATH
```
Copy `$DIR` recursively [^][44]
```sh
rsync -zvr $DIR $PATH
rsync -avz $DIR $PATH
```
Copy to remote systems over SSH [^][44]
```sh
rsync -zvre ssh $DIR $HOST:$REMOTEPATH
rsync -avze ssh $DIR $HOST:$REMOTEPATH
```
Synchronize only specific file type [^][44]
```sh
rsync -zvre ssh --include '*.php' --exclude '*' $PATH
```

[44]: https://www.2daygeek.com/linux-rsync-command-local-remote-file-synchronization/ "rsync (Remote Sync) command examples and usage"
