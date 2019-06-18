# Linux networking

## Diagnosing network problems
Test from the inside out, starting with the loopback
  1. ping looback address, testing the TCP/IP stack
  2. ping the hardware interface
  3. ping another host on the network
  4. ping the gateway
  5. ping an IP address on the Internet
  6. ping a hostname on the Internet

## Syntax

Command                                     | Effect or description
:---                                        | :---
[`dhclient`](dhclient.md)                   | obtain and configure TCP/IP information from a server on the network (LGLC: 34)
`[dig](dig.md)`                             | Perform a DNS lookup, useful when troubleshooting a DNS issue (cf. `nslookup`)
`ftp`                                       | encrypted file transfers
[`firewalld`](firewalld.md)                 | Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved
`hostnamectl`                               | 
[`ifconfig`](ifconfig.md)                   | Interface configuration, used to assign a TCP/IP configuration to a network interface, but no longer installed on modern distros.
[`iptables`](iptables.md)                   | A popular firewall, like `firewalld`, a frontend for the kernel-level `netfilters` service.
`nc`                                        | netcat utility. It allows testing of a host's ports, similar to __ping__, but more versatile because __ping__ only uses the portless ICMP protocol. GNU and OpenBSD versions available (itp-l+: 28)
`netplan`                                   | Ubuntu network configuration tool
`netstat`                                   | 
[`NetworkManager`](networkmanager.md)       | 
`nmap`                                      | audit open ports on a host
[`nmcli`](nmcli.md)                         | Interface to Network Manager, which allows for consistent network configuration across a system.
`nslookup`                                  | Perform a DNS lookup in an interactive shell with cleaner output than __dig__. Enter a domain name and you get output in two sections. [NetworkWorld](https://www.networkworld.com/video/95669/how-to-use-the-nslookup-command-2-minute-linux-tip#tk.rss_linux)
`ping`                                      | "packet Internet groper" utility used for checking network connections, using ICMP packets (cf. __nc__)
`route`                                     | Display and manipulate the routing table
[`ss`](ss.md)                               | "socket statistics", successor to __netstat__. 
`tcpdump`                                   | Inspect actual IP packets (Wireshark is a GUI-based alternative)
`tracepath`                                 | Successor to `traceroute`, allowing the user to test connectivity along the path. Doesn't show as much detail with regard to time, so it may be faster.
`traceroute`                                | Provides much more information than `tracepath`, even though it's older (lxa-lpic: 109.3)
`xinetd`                                    | Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.  
