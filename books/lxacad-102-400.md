# Linux+ and LPIC-1: System Administrator - Exam 102 (v4) on LinuxAcademy.com

## 105.1 - Customize and use the shell environment
## 105.2 - Customize or write simple scripts
## 105.3 - Customize or write simple scripts (testing files, looping, and conditionals)
## 105.4 - SQL Data Management

## 106.1 - Install and configure X11 (X Utilites for screen and window information)
X11 and Xorg are often still used interchangeably, but strictly speaking Xorg is a newer system that replaced and improved upon the earlier X11. 
`yum groupinstall "X Window System" "Desktop" "Desktop Platform"` installation of GUI for a headless server
/etc/X11 primary location for configs, including xorg.conf
Xorg configuration can be generated in two ways
`X` `Xorg` binary for X windows server
`X -configure` `Xorg -configure` generate an Xorg configuration file for the user running the command
Sections of xorg.conf.new
  - `Section "Title" ... EndSection`
  - Module, InputDevice, Monitor, Screen

## 106.2 - Set up a display manager
`xwininfo` determine resolution by clicking on Desktop itself
`xdpyinfo`
`xhost` remotely run desktop applications
`xhost +` disable access control (enabled by default), allowing clients to connect remotely and run desktop applications
`xhost +192.168.1.119` add a host to list of authorized clients
`xhost -192.168.1.119` remove a host from list of authorized clients
`yum install xorg-x11-xdm` install X display manager
/etc/X11/xdm config for X display manager
lightdm replaces kdm, but configuration isn't typically necessary
/etc/lightdm/lightdm.conf
Changing preferred display manager varies on distribution:
 - Red Hat: /etc/X11/prefdm on RHEL determines preferred DM based on $DISPLAYMANAGER
 - Debian: `dpkg-reconfigure lightdm` is a utility that will allow the choice of display manager on an ncurses menu

## 106.3 - Accessibility
Options are available under "Universal Access" or "Accesibility"

## 107.1 - Manage user and group accounts and related system files (UIDs, GIDs, and password files)
## 107.2 - Automate system administration tasks by scheduling jobs
## 107.3 - Localization and internationalization

## 108.1 - Maintain system time (hardware clock, system clock, and NTP)
`date` display or set the time/date
`date +"%H"` display the current hours
`date +"%s"` display seconds of current epoch
`date MMDDHHmm` set date and time to MM/DD HH:mm; this causes a discrepancy with the hardware clock: "drift"
`hwclock` allows you to interface directly with the hardware clock, which is unaware of time zones
Two ways to synchronize these clocks:
  1. `hwclock --systohc` set the system clock to the hardware clock
  2. `hwclock --hctosys` set the hardware clock to the system clock
`ntpdate` : network time protocol, often not included by distros by default
`start ntpd` : start NTP daemon
/etc/ntp.conf : configures the pool of servers used to synchronize via NTP: `server 0.centos.pool.ntp.org iburst`
`ntpq` : produces a special prompt that allows you to get more information on NTP servers
  - `peers` servers
  - `associations` information on servers in pool
`systemctl stop ntpd; ntpq; peers` this will produce a "read: Connection refused" error
## 108.2 - System logging
syslog daemon logs system messages according to log "levels", but modern distros typically use systemd's logging utility, `journalctl`

## 108.3 - Mail Transfer Agent (MTA) Basics (Email overview)
### Mail servers:
- Sendmail : legacy email server that served as de facto standard installed by distributions, despite the difficulty of configuring it using the M4 language, before security issues caused it to be deprecated
- Postfix : modern mail server developed by IBM originally, incorporating policy support to reduce spam and separate processes for security
- Qmail : secure replacement for sendmail; development has stagnated recently
- Exim : simpler configuration, seen in older Debian distributions
### Abbreviations
- SMTP
- MUA: mail user agent, application used to __send__ email
- MSA: mail submission agent, intermediary between MUA and MTA
- MTA: mail transfer agent, accepts email from MUA and sends it to the receiving mail server (relay action)
- MDA: mail delivery agent, receives email from MTA and delivers to the local mail spool
- POP: Post Office Protocol, used by MUAs to get email
- IMAP: Internet Message Access Protocol, also used by MUAs to get email
- MX Record: mail DNS records

## 108.4 - Mail Transfer Agent (MTA) Basics (Creating aliases)
Routing root email is a problem because root is often more than a single user
`mailq`
`mail` enter mail shell interface which checks your new email
`mail user` send new email to {user}
`mail -u user` check another user's email, as root
`d 1` delete first message (from within mail shell)
/etc/aliases : systemwide aliases
  - `root: user` redirect root mail to {user}
  - `root: user,newuser` redirect root mail to more than one account
  - `support: | /opt/HelpDesk/create_ticket.sh` run an application or script by prepending pipe character to script name
  - requires `newaliases` command to be run to update the /etc/aliases.db file which actually is used by the system to determine routing of messages
/var/spool/mail contains mail by user
/var/spool/mailq
/var/spool/mqueue empty unless there is mail queued to be delivered
/var/log/maillog contains relay errors, delivery confirmations, etc regarding mail delivery
$HOME/.forward file created within recipient's home directory which contains the account name to receive email to recipient
/home/john/.forward : `bob` will forward john's email

## 108.4 - Manage printers and printing (CUPS, lpr, and printing at the CLI)
## 109.1 - Fundamentals of Internet Protocols (Overview)
## 109.2 - Basic network configuration (working with interfaces and routes)
`ifconfig` display information on active interfaces
`ifup` `ifdown`
`ip` unified network routing and management command, meant to unify functionality of `ifconfig`, `netstat`, `route`, and others
`ip addr show` display information on active interfaces
/etc/sysconfig/
/etc/sysconfig/network-scripts/ifcfg-eth0 : network interface config file
  - `DEVICE=eth0`
  - `BOOTPROTO=dhcp` can be `static` as well, for manual configuration
  - `ONBOOT=on`
  - `IPADDR=10.1.0.10`
  - `NETMASK=255.255.255.0`
  - `GATEWAY=10.1.0.1`
`route` display routing table
  - `default` indicates where all IP addresses __other__ than those specified in the table will be routed (13:00)
  - space-delimited output with fields: Destination, Gateway, Genmask, Flags, Metric, Ref, Use, Iface
`netstat -r` also display routing table
  - space-delimited output with fields: Destination, Gateway, Genmask, Flags, MSS, Window, irtt, Iface
`route add 8.8.8.8 gw 172.31.10.10` when going to 8.8.8.8 go through 172.31.10.10:W
`route del 8.8.8.8 gw 172.31.10.10` clear the rule above
/proc/sys/net/ipv4/ip_forward : virtual file which contains a 0 or 1; changing this value alone can disable or enable IP forwarding 
`echo 1 > /proc/sys/net/ipv4/ip_forward` : system will now function as a router, forwarding IP traffic
/etc/sysctl.conf : if the file exists..
  - `net.ipv4.ip_forward = 1` note that this value is analogous to that of the virtual file in /proc, substituting `.` for `/`; on reboot the value will take effect
3 ways to enable DHCP on a system (LPIC-2 course covers in more depth)
  1. `dhcpd -k` kill and restart the DHCP daemon
  2. `pump` request a new IP lease
  3. `dhclient` request a new IP lease

## 109.3 - Basic network troubleshooting
ping, netstat, traceroute, and tracepath along with IPv6 equivalents.
`ping` uses ICMP, which is often stopped at the firewall.
`ping -c 5 -i 2 google.com` intervals of 2 seconds
`traceroute` provides much more information when run with superuser privileges than tracepath
`netstat -a` show all sockets on all active interfaces (8:40)
`netstat -a | grep tcp | wc -l` find number of active tcp connections
`netstat -c 5 -a` refresh every five seconds
`netstat -a -p`
`netstat -t` just tcp, omitting Unix sockets
`netstat -r` generate routing table
`netstat -rn` routing table with name resolution
`ping6` IPv6 equivalent of `ping`, also `ping -6`, but many servers leave ICMP disabled for IPv6
`tracepath6`, `traceroute6`

## 109.4 - Configure client-side DNS
3 files affect DNS behavior on clients:
  1. /etc/hosts overrides public DNS query results
  2. /etc/resolv.conf contains nameserver definitions
  3. /etc/nsswitch.conf : `hosts` section determines order of resolution of domain names
`bind-utils` Berkeley Internet Naming Daemon
`host www.linuxacademy.com`
`ping www.linuxacademy.com` domain name is resolved to IP:W
`getent hosts www.linuxacademy.com` gets effectively the same information, but in reverse order
`dig www.linuxacademy.com`
`dig www.linuxacademy.com NS` "name server" record
  - `MX` email


## 110.1 - Perform security administration tasks
## 110.2 - Set up host security
## 110.3 - Securing data with encryption (GPG)

