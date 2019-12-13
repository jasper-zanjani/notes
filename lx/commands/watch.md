### watch
Execute `cmd` at periods of `$N` seconds, watching its output (CLKF)
```sh
watch cmd -n n
```
Check memory usage in megabytes (`-m`) every `5` seconds (Enki)
```sh
watch -n 5 free -m
```
Get the list of IPs and ports that are connected via https on your webserver every second
```sh
watch -n 1 'netstat -an | grep ":443"'
```
Get the total number of connections on port 80 every second
```sh
watch -n 1 'netstat -an | grep ":80" | wc -l'
```

