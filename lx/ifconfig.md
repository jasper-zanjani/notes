### ifconfig

Syntax | Effect
:--- | :---
"RX packets" refers to received packets
"TX" transmitted
`ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0` apply a static IP address to interface {eth0} and turn it on ("up")
`ifup eth0`, `ifdown eth0` bring an interface up or down
`ifconfig eth0 up`, `ifconfig eth0 down` bring an interface up or down

