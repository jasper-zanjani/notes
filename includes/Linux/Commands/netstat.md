[netstat -&#97;]:               #netstat                       'Apply to all&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[netstat -&#99;]:               #netstat                       'Continuous operation, yielding a `netstat` display every second until interrupted with Ctrl-C&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 398'
[netstat -&#103;]:              #netstat                       'Display multicast group membership information for IPv4 and IPv6'
[netstat -&#105;]:              #netstat                       'Display a list of interfaces&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 399'
[netstat -&#108;]:              #netstat                       'Display only listening sockets'
[netstat -&#77;]:               #netstat                       'Display masqueraded connections'
[netstat -&#110;]:              #netstat                       'Numeric mode; do not resolve hostnames&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 399'
[netstat -&#111;]:              #netstat                       'Display information related to networking timers'
[netstat -&#112;]:              #netstat                       'Programs mode; display the PID and process name&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 399'
[netstat -&#114;]:              #netstat                       'Routing mode; display the routing table in the format of `route`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 399'
[netstat -&#115;]:              #netstat                       'Display statistics for the output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[netstat -&#116;]:              #netstat                       'Display TCP information&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[netstat -&#117;]:              #netstat                       'Display UDP information&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[netstat -&#118;]:              #netstat                       'Verbose output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'

<code>&nbsp;</code>   [`a`][netstat -&#97;] <code>&nbsp;</code> [`c`][netstat -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`g`][netstat -&#103;] <code>&nbsp;</code> [`i`][netstat -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> [`l`][netstat -&#108;] <code>&nbsp;</code> [`n`][netstat -&#110;] [`o`][netstat -&#111;] [`p`][netstat -&#112;] <code>&nbsp;</code> [`r`][netstat -&#114;] [`s`][netstat -&#115;] [`t`][netstat -&#116;] [`u`][netstat -&#117;] [`v`][netstat -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`M`][netstat -&#77;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

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

```sh
netstat -tulpn
```