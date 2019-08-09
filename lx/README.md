# Linux

## Contents

Topic                            | Contents
:---                            | :---
[lx](lx.md)                     | Technical aspects of Linux operation: boot sequence, processes, `init`, control groups, filesystems, FACL
[lx-arch](lx-arch.md)           | Arch Linux installation process
[lx-network](lx-network.md)     | Networking topics and index to network-related commands
[lx-xbox](lx-xbox.md)           | Setup process for Xbox 360 wireless controller (does not appear to be necessary on Manjaro)
[lx-email](lx-email.md)         | Applications used for email services 
[lx-terms](lx-terms.md)         | Linux applications, abbreviations, file formats, and other terms to be memorized
[X](X.md)

### Other operating systems

Operating system  | Description
:---              | :---  
[BSD](bsd.md)
[Mac OS X](macosx.md)
[Kali Linux](lx-kali.md)

### Shells

Shell | Description
:---  | :---
[bash](bash.md) 
[elvish](elvish.md
[fish](fish.md)

### Desktop environments

Desktop environments
:---
[KDE](kde.md)

## Commands
### Network

Letter | Commands
:--- | :---
D | [dhclient](lx-network.md#dhclient) [dig](lx-network.md#dig) 
F | ftp [firewalld](lx-network.md#firewalld)
H | [hostnamectl](lx-network.md#hostnamectl)
I | [ifconfig](lx-network.md#ifconfig) [iptables](lx-network.md#iptables)
N | [nc](lx-network.md#nc) [netplan](lx-network.md#netplan) [netstat](lx-network.md#netstat) [NetworkManager](lx-network.md#networkmanager) nmap [nmcli](lx-network.md#nmcli) [nslookup](lx-network.md#nslookup)
P | [ping](lx-network.md#ping)
R | [route](lx-network.md#route)
S | [ss](lx-network.md#ss)
T | [tcpdump](lx-network.md#tcpdump) tracepath traceroute
X | [xinetd](lx-network.md#xinetd) 

### Filters

Command                         | Description
:---                            | :---
[awk](awk.md)
[sed](sed.md)
[grep](grep.md)

### GNU Utilities

Command                         | Description
:---                            | :---
[cat](cat.md)
[crontab](crontab.md)
[date](date.md)
[history](history.md)
[less](less.md)
[make](make.md)
[sfdisk](sfdisk.md)
[shuf](shuf.md)
[sort](sort.md)
[sudo](sudo.md)
[test](test.md)
[watch](watch.md)

### SystemD

Command                         | Description
:---                            | :---
[hostnamectl](hostnamectl.md)
[xinetd](xinetd.md)


### Utilities

Command                         | Description
:---                            | :---
[imagemagick](imagemagick.md)
[tmux](tmux.md)

### Package managers

Command                         | Description
:---                            | :---
[pacman](pacman.md)

# CLI conventions for shell scripts
## Validating arguments
`if [ $# != 2 ]; then echo "..."; exit 1; fi` : (PGL:548)
`[ -z "$1" ] && echo "..." && exit 1` : [Luke Smith](https://youtu.be/ksAfmJfdub0) 
`if [ ! -z "$2" ] ; then ...; fi` : [Yakuake scripting](https://coderwall.com/p/kq9ghg/yakuake-scripting)
## Looping based on user input
placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate (CLKF)
```bash
read -p "Backup another server? (y/n)" -n 1
["$BACKUP_AGAIN"="y"] || break
```

