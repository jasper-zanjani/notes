# Linux container commands
&nbsp;  | Commands
---     | ---
&nbsp;  | 

### `lsns`
List existing namespaces. Namespace with which PIDs can also be accessed [^][1]
```sh
ls /proc/*/ns
```
### `pidof`
Query system to discover the PID of any named application. [^][1]
```sh
pidof zsh
```

### unshare
Run a program in a namespace **unshared** from its parent process. [^][1]
```sh
sudo unshare --fork --pid --mount-proc zsh
```

[1]: https://opensource.com/article/19/10/namespaces-and-containers-linux 'opensource.com - "Demistifying namespaces and containers in Linux"'