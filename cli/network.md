# Linux networking

## Procedures
### Diagnosing network problems
Test from the inside out, starting with the loopback
  1. ping looback address, testing the TCP/IP stack
  2. ping the hardware interface
  3. ping another host on the network
  4. ping the gateway
  5. ping an IP address on the Internet
  6. ping a hostname on the Internet


## Commands

### dhclient
obtain and configure TCP/IP information from a server on the network (LGLC: 34)
  - `sudo dhclient` turn on the DHCP client and get a new address from the server
  - `sudo dhclient -r` __release__ the IP address currently assigned and __request__ a new IP lease

### dig
Perform a DNS lookup, useful when troubleshooting a DNS issue (cf. `nslookup`)
  - `dig example.com NS` nameserver
  - `dig example.com MX` mail server


### firewalld
Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved
  - `firewall-cmd --state` status of service
  - `firewall-cmd --get-default-zone` display default zone
  - `firewall-cmd --get-active-zones` display zones that are attached to an interface
  - `firewall-cmd --new-zone=testlab` add a new zone
  - `firewall-cmd --new-zone=testlab --permanent` add a new zone, and write the change to disk
  - `firewall-cmd --reload` load saved configuration
  - `firewall-cmd --get-services` display names of all available services
  - `firewall-cmd --add-service=ftp --permanent; firewalld-cmd --add-service=ftp`
  - `firewall-cmd --list-services` display services loaded in memory
  - `firewall-cmd --remove-service`
  - `firewall-cmd --add-port=8080/tcp` add nonstandard port
  - `firewall-cmd --add-port=50000-60000/udp` add a range of nonstandard ports
  - `firewall-cmd --list-ports` see approved port numbers
  - /etc/sysconfig/network-scripts/ifcfg-ens33 interface settings
  - /usr/lib/firewalld/services display .xml files that define services ("ZONE=public")

### ftp
Encrypted file transfers

### hostnamectl
  - `sudo hostnamectl set-hostname hostname` permanently change hostname to {hostname} (systemd)

### ifconfig
Interface configuration, used to assign a TCP/IP configuration to a network interface, but no longer installed on modern distros.
  - "RX packets" refers to received packets
  - "TX" transmitted
  - `ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0` apply a static IP address to interface {eth0} and turn it on ("up")
  - `ifup eth0`, `ifdown eth0` bring an interface up or down
  - `ifconfig eth0 up`, `ifconfig eth0 down` bring an interface up or down

### ip
  - `ip link` show current link status
  - `ip route` display routing table

### iptables
A popular firewall, like `firewalld`, a frontend for the kernel-level `netfilters` service.
  - `iptables --list` will produce output even if the service is not running
  - `systemctl enable --now iptables` start iptables service
  - `iptables --list-rules` display rules as written on disk
  - `iptables -A INPUT -p tcp --dport 80 -j ACCEPT` accept TCP traffic to port 80
  - `iptables -A INPUT -p tcp --dport ssh -s 10.0.222.222 -j ACCEPT` accept SSH traffic from a particular source
  - `iptables-save` stdout only; must be redirected to a file
  - `iptables -F` reload config file
  - `systemctl restart iptables`
  - `iptables -vnL --line` show statistics for configuration lines
  - `watch -n 0.5 iptables -vnL` update twice a second, producing a dashboard
  - /etc/sysconfig/iptables location of saved config

### nc
netcat utility. It allows testing of a host's ports, similar to __ping__, but more versatile because __ping__ only uses the portless ICMP protocol. GNU and OpenBSD versions available (itp-l+: 28)
`nc example.com 80` connect to host on port 80

### netplan
Ubuntu network configuration tool
  - `sudo netplan apply` apply network configuration changes
  - /etc/netplan/ directory containing various configuration files and scripts
  - /etc/nplan/99_config.yaml netplan config

### netstat
  - `netstat -i` show interface statistics (LGLC: 535)
  - `netstat -r` , `netstat --route` display routing table (lxa-lpic: 109.2, itp-lpic: 39)
  - `netstat -a` show all sockets on all active interfaces (lxa-lpic: 109.2)
  - `netstat -an` show network traffic (itp-lpic.md)
  - `netstat -a | grep tcp - | wc -l` count number of TCP connections (lxa-lpic: 109.2)
  - `netstat -c 5 -a` refresh every 5 seconds (lxa-lpic: 109.2)
  - `netstat -t` TCP connections (lxa-lpic: 109.2)
  - `netstat -tp` active sessions (itp-lpic: 39)
  - `netstat -atp` all sessions (itp-lpic: 39)
  - `netstat -rn` routing table with name resolution (lxa-lpic: 109.2)
  - `watch -n 1 'netstat -an | grep ":443"'` get the list of IPs and ports that are connected via https on your webserver every second
  - `watch -n 1 'netstat -an | grep ":80" | wc -l'` get the total number of connections on port 80 every second

### NetworkManager
  - `chkconfig NetworkManager off`, `systemctl disable NetworkManager.service`, `service NetworkManager stop` stop NetworkManager service (Upstart, Systemd, Sysvinit)

### nmap
audit open ports on a host

### nmcli
Interface to Network Manager, which allows for consistent network configuration across a system.
  - `nmcli device status` display devices and statuses
  - `nmcli dev status` display information on interfaces as well as status, including other network connections not managed by network manager ("unmanaged") or not connected ("unavailable") 
  - `nmcli general status` display what connections are enabled 
  - `nmcli connection show --active` display UUIDs associated with network connections 
  - `nmcli device show` display much more information on network devices
[NetworkWorld](https://www.networkworld.com/video/94347/how-to-use-the-nmcli-command-linux-tip#tk.rss_linux)

### nslookup
Perform a DNS lookup in an interactive shell with cleaner output than __dig__. Enter a domain name and you get output in two sections. [NetworkWorld](https://www.networkworld.com/video/95669/how-to-use-the-nslookup-command-2-minute-linux-tip#tk.rss_linux)

### ping
"packet Internet groper" utility used for checking network connections, using ICMP packets (cf. __nc__)
`ping -n` numeric output only
`ping -c n` send {n} number of pings
`ping -f` flood ping
`ping -D` print timestamp
`ping -m` mark outgoing packet to be __processed__ appropriate to kernel's policy
`ping -r` bypass routing tables

### route
Display and manipulate the routing table
  - `route -n` display routing table
  - `route add default gw 192.168.0.1` add a default gateway
  - `route del default gw 192.168.0.1` remove a default gateway
  - `route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1` give a particular network a different gateway

### ss
"socket statistics", successor to __netstat__. __ss__ arguments are of two kinds:
  1. Connection type (listening or established)
    - `ss` display established connections (default)
    - `ss -l` , `ss --listening` display sockets listening
    - `ss -a` , `ss --all` display both listening sockets and established connections
  2. Protocol type
    - `ss` display all protocol sockets (default)
    - `ss -t` , `ss --tcp` display TCP protocol sockets
    - `ss -u` , `ss --udp` display UDP sockets
    - `ss -x` , `ss --unix` display Unix domain sockets
`ss -n`, `ss --numeric`  display port numbers instead of protocol names 
`ss -an` do __name__ lookups and display __all__ information
`ss -atp` display all active TCP sessions
`ss -tp` display active TCP sessions
`ss --route` display routing table (cf. `ip route`)
`ss --program` display programs with open ports
`ss -tunapl` ("tuna please") show all running servers (Bite Size Networking)[https://wizardzines.com/zines/bite-size-networking/]

### tcpdump
Inspect actual IP packets (Wireshark is a GUI-based alternative)
  - `tcpdump -i eth0` all network data will be displayed to stdout

### tracepath
Successor to `traceroute`, allowing the user to test connectivity along the path. Doesn't show as much detail with regard to time, so it may be faster.

### traceroute
Provides much more information than `tracepath`, even though it's older (lxa-lpic: 109.3)

### xinetd
Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.
  - /etc/xinet.d/ config files
  - /etc/xinetd.conf  master xinetd configuration
  - /etc/cmd.allow  specify who is allowed to run a command
  - /etc/cmd.deny specify who is disallowed from running a command


