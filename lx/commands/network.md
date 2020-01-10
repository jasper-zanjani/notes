### `hping3`
Hping3 crafts "SYN" (sequence) packets from random spoofed IP addresses and sends them out at very short intervals. [^][Sec+ Lab]

Option  | POSIX option            | Effect [^][Kali hping3]
:---    | :---                    | :---
`-i`    | `--interval`            | wait for specified number of microseconds
`-p`    | `--destport`            | destination port 
`-q`    | `--quiet`               | quiet
`-S`    | `--baseport`            | base source port (default random)
&nbsp;  | `--rand-source`         | random source address mode


```sh
hping3 192.168.0.2 -p 80 -i u10 -S -q --rand-source
```

### `ifconfig`
"RX" and "TX" stand for received and transmitted.\
Apply a static IP address to interface {eth0} and turn it on ("up")
```
ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0
```
Bring an interface up or down
```
ifup eth0
ifdown eth0
```
```
ifconfig eth0 up
ifconfig eth0 down
```
Display details of all interfaces (even disabled)
```sh
ifconfig -a
```
Disable eth0
```sh
ifconfig eth0 down
```
Configure eth0 with an additional IPv6 address
```sh
ifconfig eth0 inet6 add fdd6:551:b09e::/128
```
Enable eth0
```sh
ifconfig eth0 up
```
Turn network interface {eth0} on or off using `ifconfig`
```sh
ifconfig eth0 up
ifconfig eth0 down
```
Turn off network interface {eth0}
```sh
ifdown eth0
```
Bring online all interfaces marked as auto within the networking configuration
```sh
ifup -a
```
Turn on network interface {eth0}
```sh
ifup eth0
```



[Sec+ Lab]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[Kali hping3]: https://tools.kali.org/information-gathering/hping3 "tools.kali.org: \"hping3 - Active Network Smashing Tool\""