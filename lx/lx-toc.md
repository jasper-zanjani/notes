# Linux

## Contents

File                            | Contents
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

