### `netstat`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-a`    | `--all` | display both listening and non-listening sockets
`-c`    | `--continuous` | display selected information every second continuously
`-e`    | `--extend` | display additional information (repeat for maximum detail)
`-g`    | `--groups` | display multicast group membership information for IPv4 and IPv6
`-i`    | `--interfaces` | display a table of all network interfaces
`-l`    | `--listening` | display only listening sockets
`-M`    | `--masquerade` | display masqueraded connections
`-n`    | `--numeric` | display numerical addresses instead of symbolic host, port, or user names
`-o`    | `--timers` | display information related to networking timers
`-p`    | `--program` | display PID and name of program to which each socket belongs
`-r`    | `--route` | display routing tables
`-s`    | `--statistics` | display summary statistics by protocol
Show network traffic
```sh
netstat -an
```
Refresh every five seconds
```sh
netstat -c5
``` 
Show the current default route without performing DNS lookups on the IP addresses involved
```sh
netstat -rn
```
Count number of TCP connections 
```
netstat -a | grep tcp - | wc -l
``` 
Active sessions 
```
netstat -tp
``` 
All sessions
```
netstat -atp
``` 
Routing table with name resolution 
```
netstat -rn
``` 
Get the list of IPs and ports that are connected via https on your webserver every second
```
watch -n 1 'netstat -an | grep ":443"'
``` 
Get the total number of connections on port 80 every second
```
watch -n 1 'netstat -an | grep ":80" | wc -l'
```