# Git Bash

Configuration files | Effect
:---                | :---
`C:\Program Files\Git\etc\profile.d\git-prompt.sh` | Git Bash `.bashrc` location
### Symlinks
Windows traditionally does not support symlinks
- `ln -s` will create a copy instead
- `mklink /d {linkname} {directory}` use `mklink` command prompt command instead

#### Open path in Explorer 
```sh
explorer.exe $PATH
```