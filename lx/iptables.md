## iptables

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

File | Description
:---   | :---
/etc/sysconfig/iptables | location of saved config
