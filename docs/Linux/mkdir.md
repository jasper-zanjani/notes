Quickly create multiple directories using brace expansion
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
Create new directory {dirname} along with all of the parents in its pathname, if they do not exist
```sh
mkdir -p dirname
mkdir --parents dirname
```