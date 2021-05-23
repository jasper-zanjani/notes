`rename` uses regular expressions [Network World][https://www.networkworld.com/article/3433865/how-to-rename-a-group-of-files-on-linux.html#tk.rss_linux]

| Option | POSIX option | Effect                                                                            |
| :----- | :----------- | :-------------------------------------------------------------------------------- |
| `-n`   | `--nono`     | dry-run: describe the changes the command would make, without actually doing them |

Rename multiple files
```sh
# Renaming file.old to file.new
rename 's/old/new/' this.old

# Use globbing to rename all matching files
rename 's/old/new/' *.old
rename 's/report/review/' *

# Change all uppercase letters to lowercase
rename 'y/A-Z/a-z/' *
```