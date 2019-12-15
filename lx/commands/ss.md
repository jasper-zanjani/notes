### `ss`
"Socket statistics", successor to __netstat__. 

Options are of two kinds:
1. Connection type (listening or established)
2. Protocol type

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-l`    | `--listening`           | display sockets that are listening
`-a`    | `--all`                 | display both listening sockets and established connections
`-t`    | `--tcp`                 | display TCP sockets
`-u`    | `--udp`                 | display UDP sockets
`-x`    | `--unix`                | display Unix domain sockets
Display port numbers instead of protocol names
```
ss -n
```
```
ss --numeric
```
Do __name__ lookups and display __all__ information
```
ss -an
```
Display all active TCP sessions
```
ss -atp
```
Display active TCP sessions
```
ss -tp
```
Display routing table (cf. `ip route`)
```
ss --route
```
Display programs with open ports 
```
ss --program
```
Show all running servers 
"Tuna please"
```
ss -tunapl
```
Do name lookups and display all information
```sh
ss -an
ss --all --numeric
```
Display all sessions, filtering to just TCP that are actively listening
```sh
ss -atp
ss --all --tcp --processes
```
Display active TCP connections
```sh
ss -tp
ss --tcp --processes
```