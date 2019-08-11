# Linux

## Contents

Topic                            | Contents
:---                            | :---
BSD | [BSD](bsd.md) [Mac OS X](macosx.md)
[lx](lx.md)                     | Technical aspects of Linux operation: boot sequence, processes, `init`, control groups, filesystems, FACL
Desktop environments | [KDE](kde.md)
Distros | [Kali Linux](lx-kali.md)
[lx-arch](lx-arch.md)           | Arch Linux installation process
[lx-network](lx-network.md)     | Networking topics and index to network-related commands
[lx-xbox](lx-xbox.md)           | Setup process for Xbox 360 wireless controller (does not appear to be necessary on Manjaro)
[lx-email](lx-email.md)         | Applications used for email services 
[lx-terms](lx-terms.md)         | Linux applications, abbreviations, file formats, and other terms to be memorized
[X](X.md)
SystemD | [hostnamectl](hostnamectl.md) [xinetd](xinetd.md)

## Commands

Commands
:---
[awk](awk.md) [bash](bash.md) [cat](cat.md) [crontab](crontab.md) [date](date.md) [dhclient](lx-network.md#dhclient) [dig](lx-network.md#dig) [elvish](elvish.md) [firewalld](lx-network.md#firewalld) [fish](fish.md) ftp [grep](grep.md) [history](history.md) [hostnamectl](lx-network.md#hostnamectl) [ifconfig](lx-network.md#ifconfig) [imagemagick](imagemagick.md) [iptables](lx-network.md#iptables) [less](less.md) [make](make.md) [nc](lx-network.md#nc) [netplan](lx-network.md#netplan) [netstat](lx-network.md#netstat) [NetworkManager](lx-network.md#networkmanager) nmap [nmcli](lx-network.md#nmcli) [nslookup](lx-network.md#nslookup) [pacman](pacman.md) [ping](lx-network.md#ping) [route](lx-network.md#route) [sed](sed.md) [sfdisk](sfdisk.md) [shuf](shuf.md) [sort](sort.md) [ss](lx-network.md#ss) [sudo](sudo.md) [test](test.md) [tcpdump](lx-network.md#tcpdump) [tmux](tmux.md) tracepath traceroute [watch](watch.md) [xinetd](lx-network.md#xinetd) 

## CLI conventions for shell scripts
#### Validating arguments
> PGL:548
```
if [ $# != 2 ]
then 
  echo "..."
  exit 1
fi
```
> Luke Smith video. [YouTube](https://youtu.be/ksAfmJfdub0) 
```
[ -z "$1" ] && echo "..." && exit 1
```
> "Yakuake scripting". [coderwall.dom](https://coderwall.com/p/kq9ghg/yakuake-scripting)
```
if [ ! -z "$2" ] ; then ...; fi
```
#### Looping based on user input
Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate (CLKF)
```bash
read -p "Backup another server? (y/n)" -n 1
["$BACKUP_AGAIN"="y"] || break
```

