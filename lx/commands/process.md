[https://opensource.com/article/19/10/namespaces-and-containers-linux]: https://opensource.com/article/19/10/namespaces-and-containers-linux 'opensource.com - "Demistifying namespaces and containers in Linux"'

### `unshare`
Run a program in a namespace **unshared** from its parent process. [<sup>opensource.com</sup>][https://opensource.com/article/19/10/namespaces-and-containers-linux]
```sh
sudo unshare --fork --pid --mount-proc zsh
```
