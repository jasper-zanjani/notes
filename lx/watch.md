### watch


Syntax | Effect
:--- | :---
`watch cmd -n n` | execute {cmd} at periods of {n} seconds, watching its output (CLKF)
`watch -n 5 free -m` | check memory usage in megabytes (`-m`) every 5 seconds (Enki)
`watch -n 1 'netstat -an | grep ":443"'` | get the list of IPs and ports that are connected via https on your webserver every second
`watch -n 1 'netstat -an | grep ":80" | wc -l'` | get the total number of connections on port 80 every second

