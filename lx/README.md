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


## Commands

Type | Commands
:--- | :---
BSD | [BSD](bsd.md) [Mac OS X](macosx.md)
Desktop environments | [KDE](kde.md)
Distros | [Kali Linux](lx-kali.md)
Filters | [awk](awk.md) [grep](grep.md) [sed](sed.md)
GNU Utilities | [cat](cat.md) [crontab](crontab.md) [date](date.md) [history](history.md) [less](less.md) [make](make.md) [sfdisk](sfdisk.md) [shuf](shuf.md) [sort](sort.md) [sudo](sudo.md) [test](test.md) [watch](watch.md)
Network | [dhclient](lx-network.md#dhclient) [dig](lx-network.md#dig) ftp [firewalld](lx-network.md#firewalld) [hostnamectl](lx-network.md#hostnamectl) [ifconfig](lx-network.md#ifconfig) [iptables](lx-network.md#iptables) [nc](lx-network.md#nc) [netplan](lx-network.md#netplan) [netstat](lx-network.md#netstat) [NetworkManager](lx-network.md#networkmanager) nmap [nmcli](lx-network.md#nmcli) [nslookup](lx-network.md#nslookup) [ping](lx-network.md#ping) [route](lx-network.md#route) [ss](lx-network.md#ss) [tcpdump](lx-network.md#tcpdump) tracepath traceroute [xinetd](lx-network.md#xinetd) 
Package managers | [pacman](pacman.md)
Shells | [bash](bash.md) [elvish](elvish.md) [fish](fish.md)
SystemD | [hostnamectl](hostnamectl.md) [xinetd](xinetd.md)
Utilities | [imagemagick](imagemagick.md) [tmux](tmux.md)

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

