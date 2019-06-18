### ss

Arguments are of two kinds:
  1. Connection type (listening or established)
    - `ss` display established connections (default)
    - `ss -l` , `ss --listening` display sockets listening
    - `ss -a` , `ss --all` display both listening sockets and established connections
  2. Protocol type
    - `ss` display all protocol sockets (default)
    - `ss -t` , `ss --tcp` display TCP protocol sockets
    - `ss -u` , `ss --udp` display UDP sockets
    - `ss -x` , `ss --unix` display Unix domain sockets

Syntax | Effect
:---  | :---
`ss -n`, `ss --numeric`  | display port numbers instead of protocol names
`ss -an` | do __name__ lookups and display __all__ information
`ss -atp` | display all active TCP sessions
`ss -tp` | display active TCP sessions
`ss --route` | display routing table (cf. `ip route`)
`ss --program` | display programs with open ports
`ss -tunapl` | ("tuna please") show all running servers 


### Sources
  - [Bite Size Networking](https://wizardzines.com/zines/bite-size-networking/)
