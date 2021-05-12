Once a popular firewall but no longer installed on modern distros.
Like `firewalld`, it is a frontend for the kernel-level `netfilters` service. 

Display rules as written on disk
```sh
iptables --list-rules
```
Accept SSH traffic from a particular IP
```sh
iptables -A INPUT -p ssh -s 10.0.222.222 -j ACCEPT
```
Accept incoming TCP traffic to port 80
```sh
iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```
Reload configuration file
```sh
iptables -F
```
Show statistics for configuration lines
```sh
iptables -vnL --lines
```
Display rules as written on disk
```sh
iptables --list-rules
```
Set an iptable rule to accept SSH traffic from a particular IP
```sh
iptables -A INPUT -p ssh -s 10.0.222.222 -j ACCEPT
```
Set an iptable rule to accept incoming TCP traffic to port 80
```sh
iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```
Reload configuration file
```sh
iptables -F
```
Show statistics for configuration lines
```sh
iptables -vnL --lines
```