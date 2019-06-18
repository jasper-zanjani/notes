### firewalld
Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved

Syntax | Effect
:--- | :---
`firewall-cmd --state` | status of service
`firewall-cmd --get-default-zone` | display default zone
`firewall-cmd --get-active-zones` | display zones that are attached to an interface
`firewall-cmd --new-zone=testlab` | add a new zone
`firewall-cmd --new-zone=testlab  --permanent` | add a new zone, and write the change to disk
`firewall-cmd --reload` | load saved configuration
`firewall-cmd --get-services` | display names of all available services
`firewall-cmd --add-service=ftp --permanent` |
`firewall-cmd --list-services` | display services loaded in memory
`firewall-cmd --remove-service` |
`firewall-cmd --add-port=8080/tcp` | add nonstandard port
`firewall-cmd --add-port=50000-60000/udp` | add a range of nonstandard ports
`firewall-cmd --list-ports` | see approved port numbers

File | Description
:--- | :---
/etc/sysconfig/network-scripts/ifcfg-ens33 | interface settings
/usr/lib/firewalld/services | .xml files that define services ("ZONE=public")
