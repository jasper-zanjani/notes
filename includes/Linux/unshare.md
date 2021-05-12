# unshare

Run a program in a namespace **unshared** from its parent process. [ref][https://opensource.com/article/19/10/namespaces-and-containers-linux]
```sh
sudo unshare --fork --pid --mount-proc zsh
```