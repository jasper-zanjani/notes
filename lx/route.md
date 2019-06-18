### route

Syntax | Effect
:--- | :---
`route -n` | display routing table
`route add default gw 192.168.0.1` | add a default gateway
`route del default gw 192.168.0.1` | remove a default gateway
`route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1` | give a particular network a different gateway
