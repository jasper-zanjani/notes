# Linux

Table of contents
-:-
[Commands](#commands) [Glossary](#glossary) [Sources](#sources)

Topic                           | Contents
:---                            | :---
[lx](lx.md)                     | Technical aspects of Linux operation: boot sequence, processes, `init`, control groups, filesystems, FACL
**Desktop environments** [KDE](kde.md) [i3](i3.md)
**Distros** [Arch Linux](lx-distros.md#arch-linux) [BSD](bsd.md)  [Clear Linux](lx-distros.md#clear-linux) [Fedora CoreOS](#lx-distros.md#fedora-coreos) [Kali Linux](lx-distros.md#kali-linux) [Mac OS X](macosx.md)
[X](X.md)

## Configuration files
Config file                       | Description
:---                              | :---
$HOME/.forward                    | forwarding to only one address
$HOME/.gnupg/pubring.gpg          | default storage for public [gpg](#gpg) keyrings 
$HOME/.ssh/known_hosts            | public keys of SSH hosts
$HOME/xorg.conf                   | user config which overrides system defaults
/boot/grub/grub.cfg               | GRUB2 bootloader
/etc/aliases                      | systemwide email aliases
/etc/apt/sources.list             | APT repos <br/>`deb-src` is the prefix used to denote a Debian source repo
/etc/default/useradd              | [useradd](#useradd)
/etc/fstab                        | filesystems to be mounted by the system at boot
/etc/gdm/custom.conf              | GNOME config
/etc/group                        | colon-delimited values for groups<br/>**Format**:<br/>`name:password:GID:user1,user2,user3,...`
/etc/hosts                        | global hostnames
/etc/hotplug/usb                  | location of scripts executed when a hotplug device is inserted
/etc/hostname                     | contains hostname
/etc/init.d/                      | [sysvinit](#sysvinit) scripts run during startup and shutdown
/etc/inittab                      | initialization table
/etc/ld.so.conf.d/                | configs that establish pathnames where shared libraries may be found
/etc/lightdm/                     | directory containing **users.conf**, and the subdirectory **lightdm.conf.d**, if created, the contents of which will be loaded as well
/etc/lightdm/lightdm.conf         | [lightdm](#lightdm) 
/etc/ld.so.conf                   | [ldconfig](#ldconfig) 
/etc/login.defs                   | default configuration values for [useradd](#useradd), [userdel](#userdel), [usermod](#usermod), and [groupadd](#groupadd)
/etc/logrotate.conf               | [logrotate](#logrotate)
/etc/lvm/.cache                   | default location of LVM cache
/etc/modprobe.d/                  | [modprobe](#modprobe)
/etc/mtab                         | updated dynamically with information about currently mounted filesystems
/etc/network                      | global network settings
/etc/ntp.conf                     | NTP config
/etc/nsswitch.conf                | controls lookup system beyond just DNS
/etc/passwd                       |
/etc/postfix/main.cf              | [postfix](#postfix)
/etc/rc.d/rc.sysinit              | first script run by init
/etc/resolv.conf                  | nameserver definitions (maximum of 6 domains with total of 256 characters)
/etc/samba/smb.conf               | Samba configuration fileA
/etc/selinux/config               | [SELinux](#selinux)
/etc/services                     | used to resolve port numbers
/etc/skel/                        | default configs for new users
/etc/ssh/ssh_config               | client config for ssh
/etc/ssh/sshd_config              | server configuration file for ssh
/etc/sudoers                      | who has sudo access
/etc/sysconfig/desktop            | Specifies display manager and desktops on Red Hat
/etc/sysconfig/network-scripts/   | directory containing network configs and scripts for Red Hat
/etc/syslog-ng/syslog-ng.conf     | [syslog-ng](#syslog-ng)
/etc/udev/hwdb.bin                | udev hardware database
/etc/X11/xdm/xdm-config           | XFCE config
/etc/xinet.d/                     | directory of config files for xinetd
/etc/yum.repos.d/                 | repository definitions with filenames that follow the pattern **\*.repo**
/etc/yum.conf                     | config
/lib/systemd/system/              | directory containing unit configs
/proc/loadavg                     | virtual file that has information about load average for use in [`uptime`](#uptime)
/var/log/dmesg                    | kernel ring buffer information
/var/log/audit/audit.log          | audit file for SELinux
/sys/class/net/eth0/address       | MAC address of eth0
/usr/share/config/kdm/kdmrc       | KDM config
/usr/share/lightdm/lightdm.conf.d/ | [lightdm](#lightdm) configs, all of whose filenames follow the pattern **50-\*.conf**

## Commands
All commands
:---:
[at](#at)  [bash](bash.md) [cat](cat.md) [crontab](crontab.md) [date](date.md) [dhclient](#dhclient) [elvish](elvish.md) [exif](#exif) [file](#file) [fish](fish.md) [free](#free) [fusermount](#fusermount) [history](#history) [imagemagick](imagemagick.md) [install](#install) [make](make.md) [mkdir](#mkdir) [mktemp](#mktemp) [read](#read) [rename](#rename) [sudo](sudo.md) [test](test.md) [tmux](tmux.md) [watch](watch.md)
**Disk** [partx](#partx) [sfdisk](#sfdisk) 
**E-mail** [mail](#mail) [mailq](#mailq) [postfix](#postfix) [qmail](#qmail) [sendmail](#sendmail) [ssmtp](#ssmtp) 
**Filters** [awk](awk.md) [grep](#grep) [less](less.md) [sed](#sed) [shuf](#shuf) [sort](#sort) [tr](#tr) 
**Network** [bpftrace](#bpftrace) [dhclient](#dhclient) [dig](#dig) [ftp](#ftp) [firewalld](#firewalld) [hostnamectl](#hostnamectl) [ifconfig](#ifconfig) [iptables](#iptables) [nc](#nc) [netplan](#netplan) [netstat](#netstat) [NetworkManager](#networkmanager) [nmap](#nmap) [nmcli](#nmcli) [nslookup](#nslookup) [ping](#ping) [route](#route) [ss](#ss) [tcpdump](#tcpdump) [tracepath](#tracepath) [traceroute](#traceroute) [xinetd](#xinetd) 
**Package managers** [apt](#apt) [dpkg](#dpkg) [pacman](pacman.md) [rpm](#rpm) [yay](#yay) [yum](#yum)
**SSH** [sshfs](#sshfs) [ssh-copy-id](#ssh-copy-id) [ssh-keygen](#ssh-keygen) [ssh](#ssh)
**SystemD** [firewalld](#firewalld) [hostnamectl](#hostnamectl) [xinetd](#xinetd)
**Needing further research** [lsof](#lsof) [column](#column) [sc](#sc) [espeak](#espeak) [visudo](#visudo) [fmt](#fmt) [paste](#paste) [openssl](#openssl) [sshfs](#sshfs) [ssh-copy-id](#ssh-copy-id)
### at
#### Execute a command at a given time
```sh
echo "cmd" | at time
```
```sh
at -f file time
```
### bpftrace
New open-source tracer for analyzing production performance problems and troubleshooting software [[19](#sources)]
### chown
#### Change a file or directory's ownership
To change the user and group owner of a file to {user} and {group}, `chown`'s syntax is of the format `user:group` [[32](#sources)].
```sh
chown susan:delta file          # Assign {file} to user `susan` and group `delta`
chown alan file                 # Assign {file} to user `alan`
chown alan: file                # Assign {file} to user and group `alan`
chown :gamma file               # Assign {file} to the group `gamma`
```
Assign {path} to `susan` and group `delta`, recursively and with verbose output
```sh
chown --verbose --recursive susan:delta path 
chown -vR susan:delta path
```
```sh
chown -vR --reference=. path    # Use a `reference` file to match the configuration of a particular file
chown -cfR --preserve-root alan # `preserve-root` prevents changes to files in the root directory, but has no effect when not used with `recursive`
k
```
### dhclient
Obtain and configure TCP/IP information from a server on the network [[LGLC](../sources/lglc.md): 34]
#### Turn on the DHCP client and get a new address from the server
```
sudo dhclient
```
#### Release the IP address currently assigned and request a new IP lease
```
sudo dhclient -r
```
### dig
Perform a DNS lookup, useful when troubleshooting a DNS issue (cf. `nslookup`)
#### Nameserver
```
dig example.com NS
```
#### Mail server
```
dig example.com MX
```
### dpkg

### exif
#### View image metadata
Unlike alternatives like `file` and ImageMagick's `identify`, `exif` produces columnar output [[31](#sources)]
```sh
exif image.png 
```
### file
#### View image metadata
[[31](#sources)]
```sh
file image.png # => file type, dimensions, color depth
```
### firewalld
Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved

Configuration file                          | Description
:---                                        | :---
/etc/sysconfig/network-scripts/ifcfg-ens33  | interface settings
/usr/lib/firewalld/services                 | .xml files that define services ("ZONE=public")

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
### free
Simple utility that display realtime memory information.\
#### free options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c n`  |                         | run the program {n} times
`-h`    |                         | human-readable output
`-s n`  |                         | run the program every {n} seconds, until the program is manually interrupted
#### List memory statistics in kilobytes
Without any options, `free` returns a table listing general statistics in kilobytes:
```bash
free
```
#### Command-line memory dashboard
```bash
watch free -h
```
### ftp
encrypted file transfers
### fusermount
#### Mount a directory from a remote server on your local host via SSH
[[23](#sources)]
```sh
fusermount -u mountpoint
```
### grep
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-A n`  |                         | print {n} lines of trailing context from the file after each match
`-B n`  |                         | print {n} lines of leading context from the file after each match
`-c`    | `--count`               | print number of lines containing the pattern
`-C n`  |                         | print {n} lines of leading and trailing context surrounding each match
`-E`    | `--extended-regexp`     | force grep to use extended regular expressions, making it similar to `egrep`
`-F`    | `--fixed-strings`       | force grep to interpret pattern as fixed strings, making it similar to `fgrep`
`-H`    |                         | always pr int filename headers with output lines
`-l`    | `--files-with-matches`  | print only filenames where pattern matches occur; search continues to the next file if a match is found, making it less computationally expensive
`-n`    | `--line-number`         | print line number where match occurs
`-r`    |                         | recursive
`-v`    | `--invert-match`        | print lines **not** matching the pattern
### history
#### Clear your shell history
[[23](#sources)]
```
history -c
```
### hostnamectl
#### Change hostname
```
sudo hostnamectl set-hostname hostname
```
### install
With `install`, files can be copied while maintaining various metadata, including timestamp, owner, etc. [[9](#sources)]
#### Copy a file while preserving timestamp
The copy will have the `install` default of `755`, but the original's `mtime` is maintained:
```sh
install --preserve-timestamp example/foo .
```
#### Copy a file, setting permissions, owner, and group
```sh
install --preserve-timestamp --owner=jdoe --group=sudoers --mode=753
```
### ifconfig
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
### iptables
A popular firewall, like `firewalld`, a frontend for the kernel-level `netfilters` service. Interface configuration, used to assign a TCP/IP configuration to a network interface, but no longer installed on modern distros.

Config files | Description
:---   | :---
/etc/sysconfig/iptables | location of saved config

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
### lowriter
`lowriter` is a command-line utility installed with LibreOffice Writer.[[21](#sources)]
#### Convert a single file to PDF
```sh
lowriter --convert-to pdf filename.doc
```
#### Convert a batch of files using globbing
```sh
lowriter --convert-to pdf *.docx
```
### lsof
#### Show open network connections
`lsof` can be used to display open files, open network ports, and network connections; `-P` prevents the conversion of port numbers to port names; `-i` displays network connections; `-n` prevents the conversion of IP addresses to hostnames [[23](#sources)]
```sh
sudo lsof -Pni
```
### mail
Mail User Agent (MUA) which accepts interactive input using the `&` prompt
#### Send email from the command-line
Send email interactively
```sh
mail recipient@domain.com
```
Send message via pipe 
```sh
echo 'message' | mail -s 'subject' recipient@domain.com
```
#### Send an email attachment from the command-line
Send email interactively
```sh
mail -a /path/to/attachment
```
Send message via pipe
```sh
echo 'message' | mail -s 'subject' -a /path/to/attachment
```
#### mailq
Prints summary of mail messages queued for future delivery
### mkdir
#### Quickly create multiple directories using brace expansion
`-p` argument creates parent directories if they don't exist
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
### mktemp
Create a temporary file or directory safely and print its name. These will not need to be manually cleaned up because they will be placed in the temporary directory (**/tmp**) [[29](#sources)]
#### Create a new temporary file
```sh
mktemp
```
#### Create a new temporary directory
```sh
mktemp -d
```
#### Create a new temporary file or directory with a custom name
Append at least 3 `X`'s to the end of the filename
```sh
mktemp ostechnixXXX
```
Add a suffix
```sh
mktemp ostechnixXXX --suffix=blog
```
### mv
Option  | POSIX option            | Effect
:---    | :---                    | :---
\-      | `--backup`              | takes an argument defining how the backup file is named (not available in BSD): <br/> `existing` if numbered backups already exist in the destination, then a numbered backup is created. Otherwise, the `simple` scheme is used <br/> `none` do not create a backup even if `--backup` is set; useful to override a `mv` alias that sets the `--backup` option <br/> `numbered` append number to the destination file <br/> `simple` append "~" to the destination filename, which will be hidden when running `ls --ignore-backups`
`-f`    | `--force`               | overrides `--interactive`
`-i`    | `--interactive`         | 
`-n`    | `--no-clobber`          | silently reject move action in the event of a conflict
`-u`    | `--update`              | only overwrite if the modification time of the destination is older than the source
### nc
The netcat utility allows testing of a host's ports, similar to __ping__, but more versatile because __ping__ only uses the portless ICMP protocol. GNU and OpenBSD versions available (itp-l+: 28)
#### nc options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-l`    |                         | listening mode
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
### netplan
Ubuntu network configuration tool

Config file   | Description
:---          | :---
/etc/netplan/ | directory containing various configuration files and scripts
/etc/nplan/99_config.yaml | netplan config
#### Apply network configuration changes
```
sudo netplan apply
```
### netstat
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
### networkmanager
`chkconfig NetworkManager off`, `systemctl disable NetworkManager.service`, `service NetworkManager stop` stop NetworkManager service (Upstart, Systemd, Sysvinit)
### nmap
Audit open ports on a host
#### Scan hosts from a text file
```sh
nmap -iL hosts.txt
```
#### Identify a host's operating system
```sh
nmap -A localhost.example.com
```
#### Determine whether a host has a firewall enabled
```sh
nmap -sA localhost.example.com
```
#### Scan a specified range of ports
```sh
nmap -p 10-300 localhost.example.com
```
#### Perform a SYN TCP scan, stealthier than the TCP connect scan
```sh
nmap -sT localhost.example.com
```
### nmcli
Interface to Network Manager, which allows for consistent network configuration across a system.
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
### nslookup
Perform a DNS lookup in an interactive shell with cleaner output than __dig__. Enter a domain name and you get output in two sections. 
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
### qmail
Mail Transfer Agent (MTA) designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". Its various modular subcomponents run independently and are mutually untrustful. It uses SMTP to exchange messages with other MTAs. It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. Deprecated and removed from Arch repos in 2005. [[27](#sources)]
### pacman
Option  | POSIX option            | Effect
:---    | :---                    | :---
`Q`     | `--query`               | list all installed packages
`-R`    |                         | remove {pkg}, but leave dependencies
`-Qe`   |                         | list programs explicitly installed by user or program command
`-Qeq`  |                         | list only program names explicitly installed
`-Qm`   |                         | list programs only installed from AUR
`-Qn`   |                         | list programs only installed from main repositories
`-Qdt`  |                         | list dependencies no longer needed (orphans)
`-Ql`   | `--query` `--list`      | list all files owned by a package
`-S`    | `sync`                  | install {pkg}
`-Sy`   |                         | synchronize package database 
`-Su`   |                         | update programs 
`-Syu`  |                         | sync package database (`Sy`) and upgrade all programs (`u`) (equivalent to `apt-get update && apt-get upgrade`)
`-Syy`  |                         | force double-check of repositories
`-Syyuw` |                        | downloads programs but doesn't install them, for the option of manual installation
`-Rs`   |                         | remove {pkg} as well as its dependencies
`-Rns`  |                         | remove {pkg}, dependencies, as well as config files 
#### Get number of total installed packages
```sh
pacman -Q | wc -l
```
### partx
`partx` is a utility that provides information on drive partitions to the Linux kernel. [[12](#sources)]
#### Display partition table of a drive
```bash
partx --show /dev/sda
```
#### Show details of only one partition of a drive
```bash
partx --show /dev/sda1
```
#### Specify a range of partitions on a drive
```bash
partx -o START, END --nr 10 /dev/sda
```
#### Add all partitions on a disk to the system
```bash
partx -a /dev/sda
```
#### Dos[;au tje ;emgtj om sectors and human-readable size of a partition
```bash
partx -o SECTORS,SIZE /dev/sda1 /dev/sda
```
#### Remove the last partition
```bash
partx -d --nr -1:-1 /dev/sda
```
#### Disable headers
```bash
partx -o START -g --nr 5 /dev/sda
```
### postfix
Designed to replace Sendmail. 
- multiple processes with no particular parent/child relationship
Receives mail by two methods:
  1. Local mail (sendmail)
  2. Internet mail (SMTP)
Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery. It delivers mail using three methods:
  1. Local inboxes
  2. Internet (SMTP)
  3. Piped to programs
### read
#### Stopwatch
Will stop when you press enter, displaying how much time elapsed
```sh
time read
```
### rename
`rename` uses regular expressions [[33](#sources)]
#### rename options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-n`    | `--nono`                | dry-run: describe the changes the command would make, without actually doing them
#### Rename multiple files
```sh
# Renaming file.old to file.new
rename 's/old/new/' this.old

# Use globbing to rename all matching files
rename 's/old/new/' *.old
rename 's/report/review/' *

# Change all uppercase letters to lowercase
rename 'y/A-Z/a-z/' *
```
### screen
#### Share your screen session with another user
```sh
screen -x user/session
```
### sed
`sed` ("Stream-oriented editor") is typically used for applying repetitive edits across all lines of multiple files. In particular it is, alongside `awk` one of the two primary commands which accept regular expressions in Unix systems. 
#### sed options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-e`    |                         | when providing more than one instruction, this flag precedes every one
`-f`    | `--file`                | read from a **command file** (called a **program file** in some places [[PGL](../sources/README.md): 564]
`-i`    |                         | edit the file in-place instead of outputting to stdout
`-n`    |                         | suppress duplicate line printing; only print lines specified with the `p` command 
#### sed scripting
`#` : comments begin with octothorpe
`#n` : if first line of script begins with these two characters, it is equivalent to using the `-n` flag
#### sed syntax
Invocation syntax has two forms:
```sh
sed options 'instruction' file # Instructions provided inline
```
```sh
sed options -f scriptfile file # Instructions read from a **command file**
```
`sed` instructions are made of **addresses** and **procedures** . Sources do not use consistent terminology to describe the two components of most sed commands:

:---                                | :---
`sed 'pattern {procedure}' file`    | [[SA](../sources/README.md): 14]
`sed 'address {action}' file`       | [[YUG](../sources/README.md): 449]
`sed 'address {instruction}' file`  | [[PGL](../sources/README.md): 565]

Zero, one, or two addresses can precede a procedure.
  - In the absence of an address, the procedure is executed over every line of input
  - With one address, the procedure will be executed over every line of input that matches
  - With two addresses, the procedure will be executed over groups of lines whereby:
    - The first address selects the first line in the first group
    - The second address selects the next subsequent line that it matches, which becomes the last line in the first group
    - If no match for the second address is found, it point to the end of the file
    - After the match, the selection process for the next group begins by searching for a match to the first address
Addressing can be done in one of two ways:
  1. **Line addressing**, specifying line numbers separated by a comma (e.g. `3,7p`); `$` represents the last line of input
  2. **Context addressing**, using a regular expression enclosed by forward slashes (e.g. `/From:/p`)

Procedure   | Description
:---        | :---  
`!c`        | negation operator can be used with any procedure {c}
`a`         | append text to the addressed lines
`d`         | cause sed not to display the addressed lines ("delete"); can emulate `grep -v`, which selects lines which do _not_ match the specified pattern
`i`         | prepend text to the addressed lines
`n`         | write out the currently selected line if appropriate, read the next input line, and start processing the new line with the next instruction
`x`         | where {x} is a number, specifying occurrence (e.g. `2` would replace only the second occurrence of each pattern per line)
`g`         | replace all occurrences
`p`         | print original content (e.g. `sed -n 's/test/another test/p' myfile`)
`w outputfile`        | write results to {outputfile} (e.g. `sed 's/test/another test/w output' myfile`)
`s/pattern/replacement/flags`         | replace regex {pattern} with {replacement} ("substitute")
`g`         | replace **all** instances of the search pattern with the replacement, rather than the first instance (global)
`&`         | known as the **repeated pattern**, represents the represents the entire source string; the only special character used in the replacement string - all other characters are treated literally
#### Edit the file in-place, but save a backup copy of the original with {suffix} appended to - the filename
```sh
-i=suffix
```
#### Display first 3 lines
```sh

sed '3q' emp.lst
```
[[YUG](../sources/README.md): 450]
Display first 5 lines, similar to `head -5 emp.lst`
```sh
sed '5q' new
```
[[PGL](../sources/README.md):569]\
Pipe output of `ps` to `sed`, displaying top 10 memory-intensive processes
```sh
ps axch -o cmd,%mem --sort=-%mem | sed 11q
```
Pipe output of `ps` to `sed`, displaying top 10 CPU-intensive processes
```sh
ps axch -o cmd:15,%cpu --sort=-%cpu | sed 11q
```
#### Display first two lines of file
Without `-n`, each line will be printed twice
```sh
sed -n '1,2p' emp.lst
```
Prepending `!` to the procedure reverses the sense of the command
```sh
sed -n '3,$!p' emp.lst
```
[[YUG](../sources/README.md): 450-451]
#### Display a range of lines
```sh
sed -n '9,11p' emp.lst
```
Use the `-e` flag to precede multiple instructions
```sh
sed -n -e '1,2p' -e '7,9p' -e '$p' emp.lst
```
#### Delete lines
Delete second line alone
```sh
sed '2d' myfile
```
Delete a range of lines: from the 2nd through the 3rd
```sh
sed '2,3d' myfile
```
Delete a range of lines, from the first occurrence of 'second' to the line with the first occurrence of 'fourth'
```sh
sed '/second/,/fourth/d' myfile
```
#### Print all of a file except for specific lines
Suppress any line with 'test' in it
```sh
sed '/test/d' myfile
```
Suppress from the 3rd line to EOF
```sh
sed '3,$d' myfile
```
#### Replace text
Replace the first instance of the `|` character with `:` and display the first two lines [[YUG](../sources/README.md):455]
```sh
sed 's/|/:/ emp.lst | head -2
```
Replace all instances of the `|` character with `:`, displaying the first two lines [[YUG](../sources/README.md):455]
```sh
sed 's/|/:/g' emp.lst | head -2
```
Substitute HTML tags:
```sh
sed 's/<I>/<EM>/g'
```
These commands will replace "director" with "executive director"
```sh
sed 's/director/executive director/' emp.lst
```
```sh
sed 's/director/executive &/' emp.lst
```
```sh
sed '/director/s//executive &/' emp.lst
```
[[YUG](../sources/README.md): 456-457]
#### Searching for text
Equivalent to `grep MA *`
```sh
sed -n '/MA/p' *
```
#### Stringing sed statements together with pipe
Take lines beginning with "fake" and remove all instances of "fake.", piping them... remove all parentheses with content and count lines of output (results)
```sh
sed -n '/^fake/s/fake\.//p' * | sed -nr 's/\(.*\)//p' | wc -l
```
Take lines of all files in CWD beginning with "fake" and remove all instances of string "fake." Then remove all parentheses with any content within them and print only the top 10 lines
```sh
sed -ne '/^fake/p' * | sed -n 's/fake\.//p' | sed -nr 's/\(.*\)//p' | sed 11q
```
Count the number of pipes replaced by piping output to `cmp`, which will use the `-l` option to output byte numbers of differing values, then counting the lines of output (YUG:456)
```sh
sed 's/|/:/g' emp.lst | cmp -l - emp.lst | wc -l
```
### sfdisk
Script-based partition table editor, similar to [`fdisk`](#fdisk) and [`gdisk`](#gdisk), which can be run interactively. It does not interface with GPT format, neither is it designed for large partitions. [[11](#sources)]
#### List partitions on all devices
```sh
sfdisk -l
sfdisk --list
```
#### List partitions on {device}
```sh
sfdisk -l device
sfdisk --list device
```
#### Display size of {partition} or {device}
This command produces the size of {partition} (i.e. `/dev/sda1`) or even {device} (`/dev/sda`) in blocks
```sh
sfdisk -s partition
sfdisk -s device
```
#### Apply consistency checks to {partition} or {device}
```sh
sfdisk -V partition
sfdisk --verify device
```
#### Create a partition
```sh
sfdisk device
```
#### Save sectors changed
This command will allow recovery using the following command
```sh
sfdisk /dev/hdd -O hdd-partition-sectors.save
```
#### Recovery
Man page indicates this flag is no longer supported, and recommends use of `dd` instead.
```sh
sfdisk /dev/hdd -I hdd-partition-sectors.save
```
### shuf
#### Shuffle items separated by a space
```sh
shuf -e one two three
```
[[10](#sources)]
#### Shuffle items separated by newline 
```sh
shuf -n 1 cards.txt
```
[[10](#sources)]
### sort
#### Sort by space-delimited columns
Processes consuming the most memory will be at the bottom [[23](#sources)]
```sh
ps aux | sort -nk 4
```
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```
### sh
### ssmtp
Installable client program [[25](#sources)]

Configuration file | Description
:--- | :---
/etc/ssmtp/ssmtp.conf | Configuration file

Syntax | Effect or description
:---   | :---
#### Send {msg} to {recipient} from {user} at {host} using password {pw}
```sh
ssmtp -au recipient -ap pw user@host < msg
```
#### Configuration file
```ini
mailhub=smtp.gmail.com:587
UseTLS=YES
UseSTARTTLS=YES
```
### stat
### ping
"packet Internet groper" utility used for checking network connections, using ICMP packets (cf. __nc__)
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
### postfix
Multiple processes with no particular parent/child relationship\
Receives mail by two methods:
  1. Local mail (sendmail)
  2. Internet mail (SMTP)

Before mail is queued for delivery, it goes through a cleanup daemon, which can be configured to do header and body inspection using regex
`Qmgr` is the heart of postfix mail delivery; it maintains an active queue, which attempts delivery.\ 
It delivers mail using three methods:
  1. Local inboxes
  2. Internet (SMTP)
  3. Piped to programs\
### route
Display and manipulate the routing table
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
### sendmail
Mail daemon once the de facto standard for accepting and redirecting mail on Linux distributions, long ago fallen into disuse. It was infamous for its difficulty to set up, with roots in ARPANET itself.
### ssh
#### Compare the differences between a remote and local file
`cat` a file over SSH and pipe the output into a diff or sdiff command [[23](#sources)j]
```sh
ssh remotehost cat /path/to/remotefile | diff /path/to/localfile
```
#### Create an SSH tunnel to access remote resources
Tunnel into a server to access a website which your local machine may not; `-L` creates the SSH tunnel; first port is the port that will be opened on the local machine [[23](#sources)]
```sh
ssh -N -L localport:host:remoteport remotehost
```
### sshfs
#### Mount a directory from a remote server on your local host via SSH
[[23](#sources)]
```sh
sshfs remotehost:/directory mountpoint
```
### ss
"Socket statistics", successor to __netstat__. 
#### ss options
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
### tcpdump
Inspect actual IP packets (Wireshark is a GUI-based alternative)
#### All network data will be displayed to STDOUT
```
tcpdump -i eth0
```
### tr
#### Change the case of a string
[[23](#sources)]
```sh
tr [:upper:] [:lower:]
```
#### Remove a character or set of characters from a string or line of output
```sh
tr -d "text"
```
### tracepath
Successor to `traceroute`, allowing the user to test connectivity along the path. Doesn't show as much detail with regard to time, so it may be faster.
### traceroute
Provides much more information than `tracepath`, even though it's older [[lxa-lpic](../sources/lxa-lpic.md)]
### uname
#### Check kernel version (uname)
```bash
uname -srm
```
### watch
#### Repeat a command at regular intervals and watch its changing output
Execute {cmd} at periods of {n} seconds, watching its output [[23](#sources)]
```sh
watch cmd -n n
```
### xinetd
Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.  
#### xinetd configuration
Configuration file  | Description
:---                | :---
/etc/xinet.d/       | config files
/etc/xinetd.conf    | master xinetd configuration
/etc/cmd.allow      | specify who is allowed to run a command
/etc/cmd.deny       | specify who is disallowed from running a command
#### Display statistics for a file
```sh
stat file
```
## Assorted tasks, procedures, and recommendations
#### Validating arguments
```
if [ $# != 2 ]
then 
  echo "..."
  exit 1
fi
```
[[PGL](../sources/README.md): 548]
```
[ -z "$1" ] && echo "..." && exit 1
```
[[7](#sources)]
```
if [ ! -z "$2" ] ; then ...; fi
```
[[8](#sources)]
#### Looping based on user input
Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate [[23](#sources)]
```bash
read -p "Backup another server? (y/n)" -n 1
["$BACKUP_AGAIN"="y"] || break
```
#### Diagnosing network problems
Test from the inside out, starting with the loopback
  1. ping looback address, testing the TCP/IP stack
  2. ping the hardware interface
  3. ping another host on the network
  4. ping the gateway
  5. ping an IP address on the Internet
  6. ping a hostname on the Internet
#### Display contents of a random file
```sh
ls | sort -R | sed 1q | xargs cat
```
#### Find out which commands you use most often
```sh
history | awk '{print $2' | sort | uniq -c | sort -rn | head
```
#### Count the number of occurrences of a string
```sh
| uniq -c | sort -nr
```
## Glossary
Name                            | Description
:---                            | :---
Akira                           | design tool; alternative to `Sketch` and `Adobe XD`
Anthos                          | Google cloud service, competitor to AWS, runs on Kubernetes
Ardour                          | edit multiple audio tracks [[1](#sources)]
Audacity                        | process and edit audio files [[1](#sources)]
Bentoo Linux                    | Linux distribution made as a version of Funtoo which is easier to install
bro                             | alternative to man 
btrfs                           | B-Tree File System or "butter FS": file system was adopted by SUSE Enterprise Linux, but support was dropped by Red Hat in 2017
cheat                           | alternative to man 
Click                           | Python package that uses decorators to create command-line interfaces
Clonezilla                      | open-source software package for disk imaging and cloning; started as an alternative to the commercial software package Norton Ghost | DL: 111
coreboot                        | open-source firmware | [[LS](../sources/README.md)]
eta                             | command-line tool that draws a progress bar for long-running processes 
rdesktop                        | command-line utility for initiating a REmote Desktop Protocol connection with a Windows host [[4](#sources)]
Rosegarden                      | read and edit notations, MIDI files [[1](#sources)]
Timeshift                       | backup utility that can capture the entire drive as a snapshot [[2](#sources)]
darktable                       | open-source photography workflow application; more involved than `digikam` [[LU](../sources/README.md): 289]
digikam                         | open-source image organizer and tag editor; switched from `Exiv2` to `QtAV` for video support; written in C++ [[LU](../sources/README.md): 289]
dmenu                           | dynamic menu for X11; originally designed for `dwm`
dolphin                         | KDE file manager [[LCL](../sources/READMe.md): 27]
dwm                             | window manager written in C that needs to be recompiled when you change configuration
enlightenment                   | stacking window manager for X Window System 
Endlessh                        | SSH tarpit that sends an endless SSH banner to keep malicious SSH clients locked up for long periods of time
exa                             | open-source replacement for `ls`, with additional options
ext4                            | filesystem adopted by Linux in 2008; developed by Theodore Ts'o
feh                             | X11 image viewer 
Fedora                          | Linux distribution available in 3 flavors: Server, Workstation, and Cloud; Default desktop environment: GNOME; Default user interface: GNOME Shell; Package management system: RPM 
Fedora CoreOS Config (.fcc)     | YAML file that specifies the desired configuration of a CoreOS machine. It is converted to an **Ignition config** file using the **Fedore CoreOS Config Transpiler**  [[5](#sources)
Fedora CoreOS Config Transpiler (FCCT) | utility used to generate an **Ignition config** file from a **Fedora CoreOS Config** file [[5](#sources), [6](#sources)]
Funtoo Linux                    | Linux distribution also made by Daniel Robbins | 
hexchat                         | open-source IRC client typically preinstalled with Linux distros | DL: 112
Ignition Config (.ign)          | configuration file generated by the **Fedora CoreOS Config Transpiler** from a **Fedora CoreOS Config** file to provision a CoreOS system [[6](#sources)]
Flameshot                       | open-source screenshot tool with convenient options for graphical editing [[DL](../sources/README.md): 110]
flatpak                         | building and distributing desktop applications on Linux 
flowblade                       | open-source video editor [[LU](../sources/README.md): 295]
FSCrypt                         | Ubuntu tool that took the mantle from EncryptFS | 
geary                           | GUI email application for GNOME 3 | [[LU](../sources/README.md): 289]
Gentoo                          | Linux distribution for which the source code is compiled locally according to the user's preferences, optimizing the distro to the specific computer; started by Daniel Robbins | 
Glimpse                         | GIMP fork [[24](#sources)] [Web](https://getglimpse.app/) [Twitter](https://twitter.com/glimpse_editor) [Github](https://github.com/glimpse-editor/)
GNOME                           | desktop environment; unique among desktop environments for being single-threaded process and thus susceptible to catastrophic crashes [[DL](../sources/README.md): 110]
gopass                          | command-line password manager 
gparted                         | partition editor; graphical frontend to GNU Parted
htop                            | interactive process viewer 
immutable infrastructure        | a machine that is not modified **in-place**, but configured only through the provisioning process | 5
iptables                        | userspace utility program that allows a sysadmin to configure tables provided by the Linux kernel firewall; `iptables` applies to IPv4; `ip6tables` to IPv6; `arptables` to ARP; `ebtables` to Ethernet frames
Kali Linux                      | Linux distribution which is the most popular one for ethical hacking and pentesting; based on Debian; installable on a banana board (Raspberry Pi) | DL: 110
KDE                             | desktop environment [[DL](../sources/README.md): 105]
kpcli                           | command-line version of `keepass` or `keepassx` 
libcgroup                       | easiest way to work with cgroups on Red Hat Linux; `cgconfig` service installed with libcgroup package
lightdm                         | user login screen
Lightworks                      | video editor [[DL](../sources/README.md): 105]
Linux Multimedia Studio (LMMS)  | alternative to Frooty Loops [[1](#sources)]
Lubuntu                         | Ubuntu flavor using the LXQt desktop environment | 
lynx                            | open-source terminal-based web browser | DT
Minix                           | POSIX-compliant Unix-like OS based on a microkernel architecture; although the source code was released in print form (in 1987), the license cost $69, which was included in the cost of the book; had its own filesystem which could handle filenames up to 14 characters and address 64MB of storage; developed by Andrew Tannenbaum for teaching; used by Linus Torvalds to develop the original Linux kernel | 
Mixxx                           | DJ software, including BPM, key detection, sync, effects  [[1](#sources)]
MPlayer                         | multimedia player with support for streaming online radio  [[3](#sources)]
MuseScore                       | arrange a musical score  [[1](#sources)]
Matrix                          | open standard for messaging; integrates with and bridges to IRC and other protocols, potentially consolidating the fractured landscape of messaging on Linux [[DL](../sources/README.md#destination-linux): 110
MyPy                            | most common Python static type checker
Nautilus                        | file manager used by default in GNOME
Nemo                            | file manager used by default in Budgie
netcat                          | open-source tool (which replaces and refines the features of another, older, identically-named program) which facilitates TCP/IP connections and requests | DT
netdata                         | open-source real-time performance and health monitor
nm-applet                       | network manager
nnn                             | terminal-based file browser; written in Python
OBS                             | open-source live video streaming production software which has become the de facto standard; alternative to WireCast | DL: 111
pacman                          | package manager for Arch Linux | 
Parted Magic                    | commercial Linux distribution with data recovery and disk partitioning tools; started as a free alternative to the commercial software package "Partition Magic" | DL: 111
PDF Chain                       | graphical utility which works as a wrapper to common `PDFtk` commands; allows user to merge PDFs, extract pages, and add watermarks | OSc
PDF-Shuffler                    | graphical utility to move pages around in a PDF file | OSc
Pi MusicBox                     | turns Raspberry Pi into a standalone streaming music player | 
pitivi                          | buggy video editing application still in beta; written in Python | OSc
Plasma                          | KDE desktop environment | DL: 110
prepros                         | GUI  commercial CSS compiler | 
Qt                              | open-source widget toolkit for creating GUIs and cross-platform applications; `GTK+` is an alternative | 
QtAV                            | multimedia playback framework based on `Qt` and `FFmpeg`; directly uses ffmpeg codecs; alternative to `Exiv2` [[LU](../sources/README.md): 289]
qtile                           | tiling window manager written and configured in Python used by Luke Smith; abandoned by DT in 2019 after a few weeks of use 
ranger                          | file manager
rxvt-unicode                    | terminal emulator
shorewall                       | open-source command-line firewall tool for Linux; works off plaintext configuration files; more user-friendly than `iptables`; alternative: `FireHOL` [[LU](../sources/README.md): 289]
snapcraft                       | platform to allow high-frequency updates of applications; developed by Canonical; uses YAML format; written in Go, C
solVItaire                      | terminal-based solitarie game that uses vim key bindings
st                              | "simple terminal"; suckless terminal emulator
surf                            | suckless web browser
sxiv                            | suckless image viewer
systemctl                       | main command used to inspect and control `systemd`
systemd                         | suite of basic building blocks for a Linux system
termite                         | terminal disfavored by Distro Tube
Thunar                          | file manager used by XFCE
Tilix                           | tiling terminal emulator; GTK3 [[DL](../sources/README.md): 104]
Titan                           | command-line password manager and file encryption tool; stores passwords in an encrypted SQLite database 
tldr                            | alternative to man
tutanota                        | encrypted open-source email service
Ubuntu Touch                    | open-source operating system for mobile devices [[DL](../sources/README.md): 104]
urxvt                           | terminal favored by Distro Tube
vifm                            | file manager; lacks image previews and file icons
Wasmer                          | Python module that allows Python to run web assembly
Wayland                         | intended to be a successor to X [[DL](../sources/README.md): 110]
wine                            | method of running Windows applications on linux which is faster than a virtual machine or emulator
xfce4                           | desktop environment
xorg                            | X.org server
Xubuntu                         | Linux distribution based on Ubuntu which uses the XFCE desktop environment
YaST                            | package manager and configuration tool for openSUSE and SUSE Linux Enterprise; "Yet Another Setup Tool" [[LU](../sources/README.md): 289]
yum                             | package management tool for Red Hat Enterprise Linux
Youtube-dl                      | command-line utility for downloading YouTube videos [[3](#sources)]
ZFS                             | Zettabyte File System: next-generation filesystem with a problematic license by Oracle [[LU](../sources/README.md): 284]
ZynAddSubFX                     | LMMS plugin, used with synthesizers [[1](#sources)]
## Sources
  1. "7 Open Source Software Related To Music". [Fosslicious](https://www.fosslicious.com/2019/01/7-open-source-software-related-to-music.html): 2019/01/02.
  2. "How to create snapshots on Linux with Timeshift". [TechRepublic](https://www.techrepublic.com/article/how-to-create-snapshots-on-linux-with-timeshift/#ftag=RSS56d97e7)
  3. "Music and video at the Linux terminal". [Red Hat](https://www.redhat.com/sysadmin/music-video-linux-terminal?sc_cid=70160000001273HAAQ): 2019/06/25.
  4. "rdesktop - A RDP Client to Connect Windows Desktop from Linux". [TecMint](https://www.tecmint.com/rdesktop-connect-windows-desktop-from-linux/): 2019/07/09.
  5. "Introducing Fedora CoreOS". [Fedora Magazine](https://fedoramagazine.org/introducing-fedora-coreos/): 2019/07/24.  
  6. "Fedora CoreOS - Getting Started". [Fedora Documentation](https://docs.fedoraproject.org/en-US/fedora-coreos/getting-started/): 
  7. "Easy Academic References on the Command Line". [YouTube](https://youtu.be/ksAfmJfdub0) 
  8. "Yakuake scripting". [coderwall.com](https://coderwall.com/p/kq9ghg/yakuake-scripting)
  9. "Moving files on Linux without `mv`". [opensource.com](https://opensource.com/article/19/8/moving-files-linux-without-mv): 2019/08/19.
  10. "Linux and Unix shuf command tutorial with examples". [shapeshed.com](https://shapeshed.com/unix-shuf/): 2016/08/09.
  11. "Linux `sfdisk` command". [ComputerHope](https://www.computerhope.com/unix/sfdisk.htm): 2019/05/04.
  12. "8 Partx Command Usage Examples in Linux". [TecMint](https://www.tecmint.com/partx-command-in-linux-with-examples/)
  13. "How to use the stat command: 2-Minute Linux Tips". [NetworkWorld](https://www.networkworld.com/video/96327/how-to-use-the-stat-command-2-minute-linux-tips#tk.rss_linux)
  14. "8 Netcat (nc) Command with Examples". [TecMint](https://www.tecmint.com/netcat-nc-command-examples/): 2019/08/09.
  15. "Bite Size Networking". [wizardzines.com](https://wizardzines.com/zines/bite-size-networking/)
  16. "How to use the nmcli command: Linux Tip" [networkworld.com](https://www.networkworld.com/video/94347/how-to-use-the-nmcli-command-linux-tip#tk.rss_linux)
  17. "nslookup Command: 7 Practical Examples" [linuxhandbook.com](https://linuxhandbook.com/nslookup-command/)
  18. "How to use the nslookup command". [NetworkWorld](https://www.networkworld.com/video/95669/how-to-use-the-nslookup-command-2-minute-linux-tip#tk.rss_linux)
  19. "An introduction to bpftrace for Linux". [opensource.com](https://opensource.com/article/19/8/introduction-bpftrace): 2019/08/19.
  20. "Six practical use cases for `nmap`". [Red Hat](https://www.redhat.com/sysadmin/use-cases-nmap): 2019/08/19.
  21. "How to convert documents to PDF format on the Ubuntu Command Line". [vitux.com](https://vitux.com/how-to-convert-documents-to-pdf-format-on-the-ubuntu-command-line/).
  22. "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)
  23. Cannon, Jason. [*Command Line Kung Fu.*](../sources/clkf.md)
  24. "Someone forked GIMP into Glimpse because gimp is an offensive word". [It's FOSS](https://itsfoss.com/gimp-fork-glimpse/): 2019/08/27.
  25. "Send Emails From Linux Terminal Using SSMTP". [linuxhandbook.com](https://linuxhandbook.com/linux-send-email-ssmtp/)
  26. "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)
  27. "Qmail deprecation" [archlinux.org](https://www.archlinux.org/news/qmail-deprecation/)
  28. "Free Command in Linux Explained With Examples". [linuxhandbook.com](https://linuxhandbook.com/free-command/)
  29. "The `mktemp` Command Tutorial With examples". [OSTechnix](https://www.ostechnix.com/the-mktemp-command-tutorial-with-examples-for-beginners/)
  30. "How to move a file in Linux". [opensource.com](https://opensource.com/article/19/8/moving-files-linux-depth): 2019/08/22.
  31. "How to view image metadata". [OSTechNix](https://www.ostechnix.com/how-to-view-image-metadata-on-linux/): 2019/08/26.
  32. "Introduction to the Linux `chown` command". [opensource.com](https://opensource.com/article/19/8/linux-chown-command): 2019/08/26.
  33. "How to rename a group of files on Linux". [NetworkWorld](https://www.networkworld.com/article/3433865/how-to-rename-a-group-of-files-on-linux.html#tk.rss_linux): 2019/08/26.