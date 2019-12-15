# Linux Commands
#### Contents

Topic                         | Commands
:---                          | :---
Ansible                       | [`ansible`](../ansible.md#ansible) [`ansible-galaxy`](../ansible.md#ansible-galaxy) [`ansible-playbook`](../ansible.md#ansible-playbook)
Archive                       | [**`bzip2`**](bzip2.md) `bzcat` `bzless` `bzmore` &bull; [`compress`](compress.md#compress) [`uncompress`](compress.md#uncompress) &bull; [`gzip`](gzip.md) [`tar`](tar.md#tar) &bull; [**`zip`**](zip.md#zip) [`unzip`](zip.md#unzip) [`zipcloak`](zip.md#zipcloak) [`zipdetails`](zip.md#zipdetails) [`zipgrep`](zip.md#zipgrep) [`zipinfo`](zip.md#zipinfo) [`zipnote`](zip.md#zipnote) [`zipsplit`](zip.md#zipsplit) &bull; [`dar`](dar.md)
Date and time                 | [`chrony`](#chrony) [`date`](date.md#date) [`hwclock`](#hwclock) [`timedatectl`](init.md#timedatectl)
Disk management               | `blkid` [`partx`](partx.md)
Distributions                 | **Debian** [`adduser`](useradd.md#adduser) [**`apt`**](apt.md#apt) `apt-cache` `apt-key` `add-apt-repository` **Manjaro** [`mhwd`](#mhwd) [`mhwd-chroot`](#mhwd-chroot) [`pacman`](pacman.md) [`yay`](yay.md) **Red Hat** [`dnf`](#dnf) [`rpm`](rpm.md) [`yum`](yum.md)
Files	                        | [`chown`](chown.md) [`fallocate`](fallocate.md) [`install`](install.md "Copy files while maintaining metadata") [`lsof`](lsof.md "Display open files, open network ports, and network connections"] [`setfacl`](setfacl.md) [`sshfs`](ssh.md#sshfs) [`tree`](#tree)
Filters                       | [`sed`](sed.md#sed) [`awk`](awk.md#awk) [`grep`](grep.md) [`egrep`](grep.md) [`fgrep`](grep.md) &bull; [`copy`](#copy) [`paste`](#paste) &bull; [`cat`](cat.md#cat) [`shuf`](shuf.md) [`tr`](tr.md)
Gnome                         | [`gconf-editor`](gsettings.md) [`gsettings`](gsettings.md) 
GRUB                          | [`update-grub`](grub.md#update-grub)
Hardware settings             | [`insmod`](#insmod) [ `lsmod` ](#lsmod) [ `lspci` ](#lspci) [ `lsusb` ](#lsusb) [ `modprobe` ](#modprobe) [`rmmod`](#rmmod)
Init                          | **Systemd** [`hostnamectl`](init.md#hostnamectl) [`journalctl`](init.md#journalctl) [`localectl`](init.md#localectl) [`systemctl`](init.md#systemctl) [`systemd-delta`](init.md#systemd-delta) [`timedatectl`](init.md#timedatectl) &bull; **Sysvinit** [`chkconfig`](init.md#chkconfig) [`init`](init.md#init) [`service`](init.md#service) [`telinit`](init.md#telinit) &bull; **Upstart** [`initctl`](init.md#initctl)
Kubernetes                    | [`kubeadm`](../devops/k8s.md#kubeadm) [`kubectl`](../devops/k8s.md#kubectl)
Logical volumes               | [`lvcreate`](lvm.md#lvcreate) [`lvdisplay`](lvm.md##lvdisplay) [`lvremove`](lvm.md##lvremove) [`lvs`](lvm.md##lvs) [`pvcreate`](lvm.md##pvcreate) [`pvdisplay`](lvm.md##pvdisplay) [`pvremove`](lvm.md##pvremove) [`pvs`](lvm.md##pvs) [`vgcreate`](lvm.md##vgcreate) [`vgdisplay`](lvm.md##vgdisplay) [`vgextend`](lvm.md##vgextend) [`vgremove`](lvm.md##vgremove) [`vgs`](lvm.md##vgs)
Mac OS X                      | `pbcopy` `pbpaste` `screencapture`
Mail                          | [`mail`](#mail) [`mailmerge`](mailmerge.md#mailmerge) [`mailx`](#mail) [`msmtp`](#msmtp) [`qmail`](#qmail) [`postfix`](#postfix) 
Network                       | `iwlist` `iwconfig` [`netstat`](netstat.md) [`nc`](nc.md) [`nmap`](nmap.md) [`nmcli`](nmcli.md) [`rfkill`](rfkill.md) [`ss`](ss.md) `tracepath` `traceroute` `xinetd` &bull; **DNS** [`dig`](dig.md) [`nslookup`](nslookup.md)
Package managers              | [`apt`](apt.md#apt) [`brew`](#brew) [`dnf`](#dnf) [`gem`](gem.md) [`pacman`](pacman.md) [`pip`](#pip) [`snap`](snap.md) [`yay`](yay.md) [`yum`](yum.md)
Processes                     | [`lsns`](containers.md) [`pidof`](containers.md) [`ps`](ps.md) [`top`](sysadmin.md#top) [`unshare`](containers.md)
Remote connections            | [`rsync`](rsync.md) [`ssh`](ssh.md#ssh) [`ssh-keygen`](ssh.md#ssh-keygen) [`ssh-keyscan`](ssh.md#ssh-keyscan) [`sshfs`](ssh.md#sshfs)
System administration         | [`free`](sysadmin.md#free) [`getent`](sysadmin.md#getent) [`gpasswd`](gpasswd.md) [`groupadd`](useradd.md#groupadd) [`groupdel`](useradd.md#groupdel) [`groupmod`](useradd.md#groupmod) [`stty`](#stty) [`su`](sudo.md#su) [`sudo`](sudo.md#sudo) [`top`](sysadmin.md#top) [`uname`](sysadmin.md#uname) [`useradd`](useradd.md#useradd) [`userdel`](useradd.md#userdel) [`usermod`](useradd.md#usermod) `vifs` `visudo` &bull; **Debian** [`adduser`](useradd.md#adduser)
Version control               | [`git`](git.md#git) [`tig`](git.md#tig)
Wi-Fi                         | [`iw`](iw.md) `iwlist` `iwconfig` [`rfkill`](rfkill.md)
X                             | [`xdpyinfo`](X.md#xdpyinfo) [`xmodmap`](xmodmap.md) [`xwininfo`](X.md#xwininfo) [`Xorg`](X.md#xorg) [`xrandr`](X.md#xrandr)


\#  | Commands sorted alphabetically
:---| :---
A   | [`adduser`](#adduser) [`add-apt-repository`](#add-apt-repository) [`alsamixer`](#alsamixer) [`apropos`](#apropos) [`apt`](apt.md#apt) [`apt-cache`](apt.md#apt-cache) [`apt-key`](apt.md#apt-key) [`arp`](#arp) [`at`](#at) [`ausearch`](#ausearch) [`awk`](#awk) 
B   | [`bash`](#bash) [`blkid`](#blkid) [`bmon`](#bmon) [`borg`](#borg) [`bpftrace`](#bpftrace) [`bzcat`](bzip2.md#bzcat) [`bzip2`](bzip2.md#bzip2) [`bzless`](bzip2.md#bzless) [`bzmore`](bzip2.md#bzmore) 
C   | [`cancel`](#cancel) [`cat`](cat.md#cat) [`chage`](#chage) [`chcon`](#chcon) [`chgrp`](#chgrp) [`chkconfig`](#sysvinit) [`chmod`](#chmod) [`chown`](chown.md) [`chpass`](#chpass) [`chrony`](#chrony) [`chsh`](#chsh) [`column`](#column) [`compress`](#compress) [`cp`](#cp) [`crontab`](#crontab) [`crossystem`](#crossystem) [`cryptsetup`](#cryptsetup) [`curl`](#curl) [`cut`](#cut) 
D   | [`dar`](#dar) [`date`](date.md#date) [`dbus`](#dbus) [`dd`](#dd) [`declare`](#declare) [`df`](#df) [`dhclient`](#dhclient) [`diff`](#diff) [`dig`](#dig) [`dirname`](#dirname) [`dm-crypt`](#dm-crypt) [`dmesg`](#dmesg) [`doveadm`](#doveadm) [`dpkg`](#dpkg) [`dpkg-reconfigure`](#dpkg-reconfigure) [`du`](#du) [`dumpe2fs`](#dumpe2fs) 
E   | [`e2image`](#e2image) [`e2label`](#e2label) [`edquota`](#edquota) [`elvis`](#elvis) [`elvish`](#elvish) [`espeak`](#espeak) [`exif`](#exif) 
F   | [`fallocate`](fallocate.md) [`fam`](#fam) [`fdisk`](#fdisk) [`file`](#file) [`find`](#find) [`firewall-cmd`](#firewall-cmd) [`firewalld`](#firewalld) [`fish`](#fish) [`fmt`](#fmt) [`fold`](#fold) [`free`](#free) [`fsck`](#fsck) [`fstrim`](#fstrim) [`ftp`](#ftp) [`fusermount`](#fusermount) 
G   | [`gconf-editor`](gsettings.md) [`gdisk`](#gdisk) [`gdmsetup`](#gdmsetup) [`gem`](#gem) [`getent`](#getent) [`getfacl`](#getfacl) [`git`](git.md#git) [`gpasswd`](gpasswd.md) [`gpg`](#gpg) [`grep`](grep.md) [`groupadd`](#groupadd) [`groupdel`](#groupdel) [`groupmod`](#groupmod) [`grub`](#grub) [`gsettings`](gsettings.md) [`gzip`](#gzip) 
H   | [`hdiutil`](#hdiutil) [`hdparm`](#hdparm) [`head`](#head) [`history`](#history) [`host`](#host) [`hostname`](#hostname) [`hostnamectl`](#hostnamectl) [`hwclock`](#hwclock) 
I   | [`iconv`](#iconv) [`ifconfig`](#ifconfig) [`imagemagick`](#imagemagick) [`init`](#sysvinit) [`initctl`](#initctl) [`insmod`](#insmod) [`install`](#install.md) [`ip`](#ip) [`iptables`](#iptables) [`iscsiadm`](#iscsiadm) [`iw`](iw.md) [`iwconfig`](#iwconfig) [`iwlist`](#iwlist) 
J-K | [`journalctl`](init.md#journalctl) &bull; [`kill`](#kill) [`kubeadm`](../devops/k8s.md#kubeadm) [`kubectl`](../devops/k8s.md#kubectl)
L   | [`last`](#last) [`ldapadd`](#ldapadd) [`ldconfig`](#ldconfig) [`ldd`](#ldd) [`less`](#less) [`let`](#let) [`link`](#link) [`locale`](#locale) [`localectl`](init.md#localectl) [`logout`](#logout) [`lp`](#lp) [`lpadmin`](#lpadmin) [`lpstat`](#lpstat) [`ls`](#ls) [`lsblk`](#lsblk) [`lsmod`](#lsmod) [`lsns`](containers.md) [`lsof`](#lsof) [`lspci`](#lspci) [`lsusb`](#lsusb) [`lvcreate`](#lvcreate) [`lvdisplay`](#lvdisplay) [`lvremove`](#lvremove) [`lvresize`](#lvresize) 
M   | [`mail`](#mail) [`mailq`](#mailq) [`mailstats`](#mailstats) [`make`](#make) [`makemap`](#makemap) [`mdadm`](#mdadm) [`mhwd`](#mhwd) [`mhwd-chroot`](#mhwd-chroot) [`mkdir`](#mkdir) [`mke2fs`](#mke2fs) [`mkfontscale`](#mkfontscale) [`mkfs`](#mkfs) [`mkswap`](#mkswap) [`mktemp`](#mktemp) [`modinfo`](#modinfo) [`modprobe`](#modprobe) [`mongod`](#mongod) [`mount`](#mount) [`msmtp`](#msmtp) [`mt`](#mt) 
N-O | [`nc`](nc.md) [`netplan`](#netplan) [`netstat`](#netstat) [`NetworkManager`](#NetworkManager) [`newaliases`](#newaliases) [`nice`](#nice) [`nl`](#nl) [`nmap`](nmap.md) [`nmblookup`](#nmblookup) [`nmcli`](nmcli.md) [`nohup`](#nohup) [`nslookup`](nslookup.md) [`ntpdate`](#ntpdate) &bull; [`openssl`](#openssl)
P   | [`pacman`](pacman.md) [`partx`](partx.md) [`paste`](#paste) [`passwd`](#passwd) [`paste`](#paste) [`patch`](#patch) [`pidof`](containers.md) [`ping`](#ping) [`pip`](#pip) [`postfix`](#postfix) [`postqueue`](#postqueue) [`postsuper`](#postsuper) [`ps`](#ps) [`pvcreate`](#pvcreate) [`pvdisplay`](#pvdisplay) [`pvremove`](#pvremove) [`pydoc`](#pydoc) 
Q-R | [`qmail`](#qmail) [`quota`](#quota) [`quotacheck`](#quotacheck) [`quotaoff`](#quotaoff) [`quotaon`](#quotaon) &bull; [`read`](#read) [`rename`](#rename) [`repquota`](#repquota) [`resize2fs`](#resize2fs) [`rfkill`](#rfkill) [`resize4fs`](#resize4fs) [`restorecon`](#restorecon) [`rmmod`](#rmmod) [`route`](#route) [`rpm`](#rpm) [`rsync`](rsync.md) [`runlevel`](#runlevel) 
S   | [`samba`](#samba) [`sc`](#sc) [`screencapture`](#screencapture) [`sed`](sed.md#sed) [`semanage`](#selinux) [`sendmail`](#sendmail) [`seq`](#seq) [`service`](#sysvinit) [`sestatus`](#sestatus) [`setenforce`](#selinux) [`setfacl`](#setfacl) [`sfdisk`](#sfdisk) [`shred`](#shred) [`shuf`](#shuf) [`shutdown`](#shutdown) [`slapadd`](#slapadd)  [`sleep`](#sleep) [`snap`](#snap) [`sort`](#sort) [`sosreport`](#sosreport) [`source`](#source) [`speaker-test`](#speaker-test) [`ss`](ss.md) [`ssh`](#ssh) [`ssh-copy-id`](#ssh-copy-id) [`ssh-keygen`](#ssh-keygen) [`ssh-keyscan`](#ssh-keyscan) [`sshfs`](#sshfs) [`ssmtp`](#ssmtp) [`startx`](#startx) [`stty`](#stty) [`su`](#su) [`sudo`](sudo.md) [`swapoff`](#swapoff) [`swapon`](#swapon) [`sysctl`](#sysctl) [`syslog`](#syslog) [`sysvinit`](#sysvinit) [`systemctl`](init.md#systemctl) [`systemd-delta`](#systemd-delta) 
T   | [`tail`](#tail) [`tar`](tar.md#tar) [`tcpdump`](#tcpdump) [`telinit`](#telinit) [`test`](test.md#test) [`tig`](#tig) [`timedatectl`](init.md#timedatectl) [`tmux`](tmux.md#tmux) [`touch`](#touch) [`top`](sysadmin.md#top) [`tput`](#tput) [`tr`](tr.md) [`tree`](#tree) [`tracepath`](#tracepath) [`traceroute`](#traceroute) [`tune2fs`](#tune2fs) [`tzselect`](#tzselect) 
U-V | [`udevadm`](#udevadm) [`umount`](#umount) [`uname`](sysadmin.md#uname) [`uncompress`](#uncompress) [`unshare`](containers.md) [`unzip`](#unzip) [`update-grub`](#update-grub) [`update-rc.d`](#update-rc.d) [`useradd`](#useradd) [`userdel`](#userdel) [`usermod`](#usermod) &bull; [`variable`](#variable) [`vgcreate`](#vgcreate) [`vgdisplay`](#vgdisplay) [`vgextend`](#vgextend) [`vgremove`](#vgremove) [`vgscan`](#vgscan) [`vifs`](#vifs) [`visudo`](#visudo) 
W-Z | [`wall`](#wall) [`watch`](watch.md#watch) [`wc`](#wc) [`whatis`](#whatis) &bull; [`X`](#X) [`xdpyinfo`](#xdpyinfo) [`xhost`](#xhost) [`xinetd`](#xinetd) [`Xorg`](#Xorg) [`xrandr`](#xrandr) [`xwininfo`](#xwininfo) &bull; [`yay`](#yay) [`yum`](yum.md) &bull; [`zip`](#zip) [`zipcloak`](#zipcloak) [`zipdetails`](#zipdetails) [`zipgrep`](#zipgrep) [`zipinfo`](#zipinfo) [`zipnote`](#zipnote) [`zipsplit`](#zipsplit) [`zsh`](#zsh)


### bash
Variable                                            | Effect
:---                                                | :---
`${string//search/substitution}`                    | replace all matches of {search} with {substitution} within {string}
`${string/#search/substitution}`                    | replace {search} with {substituion} if it occurs at start of {string}
`${string/%search/substitution}`                    | replace {search} with {substituion} if it occurs at end of {string}
`${string/search/substitution}`                     | replace first match of {search} with {substitution} within {string}
`${string##substring}`                              | delete longest match of {substring} from start of {string}
`${string#substring}`                               | delete shortest match of {substring} from start of {string}
`${string%%substring}`                              | delete longest match of {substring} from end of {string}
`${string%substring}`                               | delete shortest match of {substring} from end of {string}
`$_`                                                | return last field of the last command
`$!`                                                | return process ID (pid) of the last job run in the background
`$?`                                                | return exit status of the last executed function or command
`$@`                                                | return all command line arguments as an array of strings
`$*`                                                | return all positional parameters in a single string separated by space
`$#`                                                | return number of positional arguments passed to the script or function
`$$`                                                | return process ID (pid) of the current process
`$BASH_ENV`                                         | environment variable pointing to the Bash startup file which is read when a script is invoked
`$BASH_VERSINFO`                                    | array containing the full version information split into elements
`$BASH_VERSION`                                     | string that shows the version of bash that is running
`$BASHPID`                                          | process ID of the current bash instance (see `$$`)
`$EDITOR`                                           | default editor that will be invoked by any scripts or programs (usually `vi` or `emacs`)
`$FUNCNAME`                                         | name of the current function
`$GROUPS`                                           | array containing the numbers of groups the user is a member of
`$HISTFILE`                                         | location of the history file (~/.bash_history by default)
`$HISTFILESIZE`                                     | maximum number of events saved between sessions
`$HISTSIZE`                                         | maximum number of events saved during a session
`$HOME`                                             | home directory of the user
`$HOSTNAME`                                         | hostname assigned to the system during startup
`$HOSTTYPE`                                         | identifies hardware
`$IFS`                                              | internal field separator, used when bash is splitting strings while looping, etc (white space characters by default)
`$LANG=C`                                           | cause programs to bypass locale translations
`$LINENO`                                           | line number of the current script (useful when debugging)
`$MACHTYPE`                                         | identifies hardware but includes OS information (rf. `$HOSTTYPE`)
`$OLDPWD`                                           | return working directory before the last `cd` command
`$OSTYPE`                                           | type of OS running on the machine
`$PATH`                                             | search path for finding binaries for commands
`$PIPESTATUS`                                       | array containing the exit statuses of the commands in the most recent foreground pipeline
`$PPID`                                             | process ID of the script or shell's parent (the process that invoked the current script or shell)
`$PWD`                                              | return current working directory
`$RANDOM`                                           | a random integer between 0 and 32767
`$REPLY`                                            | default reply used by `select` and `read`
`$SECONDS`                                          | number of seconds the script has been running
`$SHELL`                                            | name of user's default shell ('/bin/bash')
`$SHELLOPTS`                                        | list of options bash is supplied on startup to control its behavior
`$SHLVL`                                            | number of shell levels the current shell is running on top of
`$TMOUT`                                            | log users out of shell automatically after a certain period of inactivity
`$TMOUT=n`                                          | exit the shell if no command is typed after `n` seconds; also affects the `read` command and `select` loop
`$TMPDIR`                                           | place temporary files created and used by the shell in `directory`
`$TMPDIR=directory`                                 | place temporary files created and used by the shell in directory
`$UID`                                              | user's ID number
`$XDG_SESSION_TYPE`                                 | display compositor (e.g. `wayland`)

**"Here Documents"** or **"Heredocs"** consist of double less-than `<<` followed by an arbitrary character sequence which will be used as delimeter, typically "EOF".
```sh
cat << EOF
1 a
2 b
3 c
EOF
```
Variable substitution can take place in the heredoc, but if the delimiter is quoted (i.e. `"EOF"`), variables will not be substituted.
```sh
local y=3
cat << EOF
a=1
x=$y
```
Output:
```
a=1
x=3
```
Here string
```sh
wc -c <<< "$x"
```

### `bmon`
[[56](sources.md)]

### `bpftrace`
New open-source tracer for analyzing production performance problems and troubleshooting software [[19](sources.md)]

### `exif`
View image metadata. Unlike alternatives like `file` and ImageMagick's `identify`, `exif` produces columnar output [[31](sources.md)]
```sh
exif image.png 
```

### `file`
View image metadata [[31](sources.md)]
```sh
file image.png # => file type, dimensions, color depth
```

### `ftp`
encrypted file transfers

### `fusermount`
Mount a directory from a remote server on your local host via SSH [[23](sources.md)]
```sh
fusermount -u mountpoint
```

### `history`

Option  | Effect
:---    | :---
`-c`    | clear history [[23](sources.md)]


### `lowriter`
`lowriter` is a command-line utility installed with LibreOffice Writer.[[21](sources.md)]
Convert a single file to PDF
```sh
lowriter --convert-to pdf filename.doc
```
Convert a batch of files using globbing
```sh
lowriter --convert-to pdf *.docx
```

### `mail`
**Mail User Agent (MUA)** which accepts interactive input using the `&` prompt
Check email of `$USER`
```sh
mail -u $USER
```
Send email to `$USER`
```sh
mail $USER
```
Send email from the command-line
Send email interactively
```sh
mail $ADDRESS
```
Send message via pipe 
```sh
echo 'message' | mail -s 'subject' recipient@domain.com
```
Send an email attachment from the command-line
```sh
mail -a /path/to/attachment
```
Send message via pipe
```sh
echo 'message' | mail -s 'subject' -a /path/to/attachment
```

### `mailq`
Prints summary of mail messages queued for future delivery

### `mktemp`
Create a temporary file or directory safely and print its name. These will not need to be manually cleaned up because they will be placed in the temporary directory (**/tmp**) [[29](sources.md)]\
Create a new temporary file
```sh
mktemp
```
Create a new temporary directory
```sh
mktemp -d
```
Create a new temporary file or directory with a custom name. Append at least 3 `X`'s to the end of the filename
```sh
mktemp ostechnixXXX
```
Add a suffix
```sh
mktemp ostechnixXXX --suffix=blog
```

### `mv`
Option  | POSIX option            | Effect
:---    | :---                    | :---
\-      | `--backup`              | takes an argument defining how the backup file is named (not available in BSD): <br/> `existing` if numbered backups already exist in the destination, then a numbered backup is created. Otherwise, the `simple` scheme is used <br/> `none` do not create a backup even if `--backup` is set; useful to override a `mv` alias that sets the `--backup` option <br/> `numbered` append number to the destination file <br/> `simple` append "~" to the destination filename, which will be hidden when running `ls --ignore-backups`
`-f`    | `--force`               | overrides `--interactive`
`-i`    | `--interactive`         | 
`-n`    | `--no-clobber`          | silently reject move action in the event of a conflict
`-u`    | `--update`              | only overwrite if the modification time of the destination is older than the source

### `networkmanager`
Stop NetworkManager service
```sh
chkconfig NetworkManager off               # Upstart
systemctl disable NetworkManager.service   # Systemd
service NetworkManager stop                # sysvinit
```

### `qmail`
Mail Transfer Agent (MTA) designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". Its various modular subcomponents run independently and are mutually untrustful. It uses SMTP to exchange messages with other MTAs. It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. Deprecated and removed from Arch repos in 2005. [[27](sources.md)]

### `postfix`
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

### `rename`
`rename` uses regular expressions [[33](sources.md)]

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-n`    | `--nono`                | dry-run: describe the changes the command would make, without actually doing them

Rename multiple files
```sh
# Renaming file.old to file.new
rename 's/old/new/' this.old

# Use globbing to rename all matching files
rename 's/old/new/' *.old
rename 's/report/review/' *

# Change all uppercase letters to lowercase
rename 'y/A-Z/a-z/' *
```

### `screen`
Share your screen session with another user
```sh
screen -x user/session
```

### `sfdisk`
Script-based partition table editor, similar to [`fdisk`](#fdisk) and [`gdisk`](#gdisk), which can be run interactively. It does not interface with GPT format, neither is it designed for large partitions. [[11](sources.md)]
List partitions on all devices
```sh
sfdisk -l
sfdisk --list
```
List partitions on {device}
```sh
sfdisk -l device
sfdisk --list device
```
Display size of {partition} or {device}
This command produces the size of {partition} (i.e. `/dev/sda1`) or even {device} (`/dev/sda`) in blocks
```sh
sfdisk -s partition
sfdisk -s device
```
Apply consistency checks to {partition} or {device}
```sh
sfdisk -V partition
sfdisk --verify device
```
Create a partition
```sh
sfdisk device
```
Save sectors changed
This command will allow recovery using the following command
```sh
sfdisk /dev/hdd -O hdd-partition-sectors.save
```
Recovery
Man page indicates this flag is no longer supported, and recommends use of `dd` instead.
```sh
sfdisk /dev/hdd -I hdd-partition-sectors.save
```

### `ssmtp`
Installable client program [[25](sources.md)]

Configuration file                            | Description
:---                                          | :---
[/etc/ssmtp/ssmtp.conf](configs.md#etcssmtpssmtpconf) | Configuration file

Send {msg} to {recipient} from {user} at {host} using password {pw}
```sh
ssmtp -au recipient -ap pw user@host < msg
```

### `sendmail`
Mail daemon once the de facto standard for accepting and redirecting mail on Linux distributions, long ago fallen into disuse. It was infamous for its difficulty to set up, with roots in ARPANET itself.

### `tcpdump`
Inspect actual IP packets (Wireshark is a GUI-based alternative)\
All network data will be displayed to STDOUT
```
tcpdump -i eth0
```

### `tracepath`
Successor to `traceroute`, allowing the user to test connectivity along the path. Doesn't show as much detail with regard to time, so it may be faster.

### `traceroute`
Provides much more information than `tracepath`, even though it's older [[lxa-lpic](../sources/lxa-lpic.md)]


### `tree`
display contents of directories in a tree-like format[[46](sources.md)]

Option  | Effect
:---    | :---
`-a`    | all files
`-d`    | display directories only
`-f`    | display full path prefix for each file
`-g`    | display group name or GID for each file
`-p`    | display permissions, similar to `ls -l`
`-u`    | display username or UID
`-L $N` | limit to `$N` maximum depth
`-I $PATTERN` | suppress files matching `$PATTERN`
`-P $PATTERN` | display only files matching `$PATTERN`
`--prune`     | suppress empty directories

### `watch`
Repeat a command at regular intervals and watch its changing output
Execute {cmd} at periods of {n} seconds, watching its output [[23](sources.md)]
```sh
watch cmd -n n
```
Display a dashboard that will run {cmd} every second, displaying the output
```sh
watch -n 1 cmd
watch -n 0.5 iptables -vnL # Update twice a second, producing a dashboard
```

### `xinetd`
Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.  

Configuration file  | Description
:---                | :---
/etc/xinet.d/       | config files
/etc/xinetd.conf    | master xinetd configuration
/etc/cmd.allow      | specify who is allowed to run a command
/etc/cmd.deny       | specify who is disallowed from running a command

Display statistics for a file
```sh
stat file
```

### `resize2fs`
Resize filesystem of logical volume {Marketing} on volume group {vg1} to take up the entire logical volume
```sh
resize2fs /dev/vg1/Marketing
```

### `alsamixer`
Command-line audio mixer

### `apropos`
Look up one or more `keywords` in the online manpages: same as `man -k` (rf. `whatis`)
```sh
apropos keywords
```

#### `arp`
Option  | Effect
:---    | :---
`-a`    | display entries in the cache
`-s`    | manually add a static entry to the cache
`-d`    | delete an entry from the cache


### `at`
Execute a command at a given time
```sh
echo "cmd" | at time
```
```sh
at -f file time
```
List scheduled jobs
```sh
at -l
```
Remove scheduled jobs
```sh
at -r
```
Execute `cmd` at `time`
```sh
at time
> cmd
```

### `ausearch`
Display audit logs from {startdate} to {enddate}
```sh
ausearch --start startdate--end enddate
```
Search audit logs for today for logins of UID 500
```sh
ausearch --start today --loginuid500
```

### `blkid`
Show UUID, Label, and filesystems of GPT block devices

### chage
Change user password expiry information
Remove expiration date from an account
```sh
chage -E -1 user
```
Set the date (or number of days since January 1, 1970) on which the user's account will no longer be accessible to {date} (YYYY-MM-DD)
```sh
chage -E days chage --expiredate days
```
Set the maximum number of days during which a password is valid
```sh
chage -M days chage --maxdays days
```
Set the minimum number of days between password changes
```sh
chage -m days chage --mindays days
```
Set the number of days of warning before a password change is required
```sh
chage -W days chage --warndays days
```

### chcon
Change context for website directory
```sh
chcon -Rv --type=httpd_sys_content_t website
```

### chgrp
Change ownership of `$FILE` to `$USER` and `$GROUP`
```sh
chgrp $USER:$GROUP $FILE
```

### chmod
Set sticky bit on `$FILE`
```sh
chmod +t $FILE
```
Clear sticky bit on `$FILE`
```sh
chmod -t file
```
Clear SGID bit on `$FILE`
```sh
chmod g-s file
```
Set SGID bit on `$FILE`
```sh
chmod g+s file
```
Clear SUID bit on `$FILE`
```sh
chmod u-s file
```
Set SUID bit on `$FILE`
```sh
chmod u+s file
```
Set `setuid` permission on `$FILE`
```sh
chmod +s file
```

### chpass
Change default shell to Fish
```sh
chpass -s /usr/local/bin/fish
```

### chrony
Synchronize system time using NTP (cf. [`timedatectl`](init.md#timedatectl)\
Stop the `systemd-timesyncd` service
```sh
sudo systemctl stop systemd-timesyncd.service
```
Install `chrony` if it is not already present and enable and start the service
```sh
sudo systemctl enable chronyd && sudo systemctl start chronyd
```

### chsh
Change the user's default shell to Bash
```sh
chsh-s /bin/bash
```
Change the user's default shell to Fish
```sh
chsh-s /usr/local/bin/fish
```

### cp
Preserve symlinks in a recursive copy
```sh
cp -a
cp --archive
```

### crontab
There are 2 types of `crontab`, taking similar syntax:
1. User crontabs, where cron jobs take the syntax: `minute hour day month weekday cmd`
2. System crontabs found in /etc/cron.d/, /etc/cron.hourly, /etc/cron.weekly, or /etc/monthly specify a user: `minute hour day month weekday USER cmd`

Command | Effect
:---                    | :---
`-e`                    | create or __edit__ crontab (using $EDITOR path variable)
`-l`                    | list cron jobs
`-u  $USER -l`          | list {user}'s cron jobs
`-r`                    | delete all cron jobs
`-u $USER -r`           | delete cron jobs of `$USER`
`-u $SUSER $NEWCRONTAB` | replace current crontab of `$USER` with `$NEWCRONTAB`

Remove current crontab, clearing cron jobs for the effective user
```sh
crontab -r
```
Specify that {user}'s crontab is to be modified
```sh
crontab -u user
```


### crossystem
Print all parameters with descriptions and current values

### cryptsetup
Incorporate full-disk encryption on /dev/sdb1, asking for passphrase twice
```sh
cryptsetup --verify-passphrase luksFormat /dev/sdb1
```
Assign virtual name "storage1" to encrypted disk /dev/sdb1
```sh
cryptsetup luksOpen /dev/sdb1 storage1
```


### curl
Download {url}, posting form-encoded {name} as {value}
```sh
curl -d '{name}={value}' url
```
Download {url}, but produce no output in case of failure
```sh
curl -f url
curl --fail url
```
Download {url}, following redirects
```sh
curl -L url
curl --location url
```
Download {url} saving output under the filename indicated by the URL itself
```sh
curl -O url
curl --remote-name url
```
Make an http GET request to the URL provided, displaying the response in the terminal
```sh
curl url
```
Download {url} and save to {file}
```sh
curl url -o file
```


### cut

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    |                         | character number
`-d`    | `--delimiter`
`-f`    |                         | field number


### date
Display the date and time according to locale settings\

Option  | Effect
:---    | :---
`-s`    | set date [[4](sources.md)]

Set the current date and time to `$DATESTRING`
```sh
date -s "$DATESTRING"
```
Set only the year using `"next year"` or `"last year"`
```sh
date -s "next year"
date -s "last year"
```
Set only the day
```sh
date -s "next day"
date -s "monday"
```
Print or set UTC time
```sh
date -u
date --utc
date universal
```
Display the date fifty days into the future [[50](sources.md)]
```sh
date -d '+50days' +%F
```


### dbus-monitor
Monitor messages going through a D-Bus message bus


### dd
Implement a simple CPU benchmark by writing 1 GB of zeroes and piping it to md5sum
```sh
dd if=/dev/zero bs=1M count=1024 | md5sum
```


### declare
Option which displays output in a way that could then be used as input to another command
```sh
declare -p
```

### df
Change scale to terabytes
```sh
df -BT
df --block-size=T
```
Show drive utilization
```sh
df -h
```

### dhclient
Obtain and configure TCP/IP information from a server on the network [[LGLC](../sources/lglc.md): 34]
#### Turn on the DHCP client and get a new address from the server
```
dhclient
```
#### Release the currently assigned IP address and get a new one
```sh
dhclient -r
```
### diff
#### Three lines of context
```sh
diff -c
```
#### Case-insensitive
```sh
diff -i
```
#### Ignore whitespace
```sh
diff -w
```

### dirname
Strip filename from $PATH (cf. [ `basename` ](#basename))
```sh
dirname $PATH
```
### dm-crypt
Disk-encryption subsystem which serves as the backend to [ `cryptsetup` ](#cryptsetup)
### dmesg
#### Disable kernel messages from being sent to the console
```sh
dmesg -d
```
#### Enable kernel messages being sent to the console
```sh
dmesg -e
```
#### Display the time in local time
```sh
dmesg -e
dmesg --reltime
```
### doveadm
#### Produce a password appropriate for use with dovecot
```sh
doveadm pw
```
### dpkg
Manage local Debian packages
#### dpkg options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-I`    | `--info`                | show information about {$PACKAGE}
`-i`    | `--install`             | install {$PACKAGE}
`-l`    | `--list`                | list packages currently installed
`-L`    | `--listfiles`           | list packages that were installed as dependencies of another package
`-p`    | `--print-avail`:         | show details about {$PACKAGE}
`-P`    | `--purge`               | remove {$PACKAGE}, including configuration files
`-r`    | `--remove`              | remove {$PACKAGE}, keeping configuration files
`-s`    | `--status`              | display package status
`-S`    | `--search`              | list package name responsible for a specific file being installed on the system
`-C`    | `--audit`               | check for broken packages
\-      | `--get-selections`      | display list of package selections
### dpkg-reconfigure
Run a package's configuration script after it has already been installed.
#### Change the time zone on a Debian based system using package-based tools
```sh
dpkg-reconfigure tzdata
```
### du
#### Summary of information in human-readable format
```sh
du -sh
du --summarize --human-readable
```
#### Show the size of all files and subdirectories of {dir} in human-readable form
```sh
du -h dir
```
#### Show the size of {file} in human-readable form
```sh
du -h file
```
#### Show the size of a directory at {path} in human-readable form
```sh
du -hs path
```
### dumpe2fs
Display detailed filesystem information
### e2label
Create an image of important metadata for an ext3 filesystem
#### Assign label "Storage" to /dev/sdb1
```sh
e2label /dev/sdb1 Storage
```
### find
Search for files in a directory hierarchy
#### Find all files in {$PATH} that are owned by {user}
```sh
find $PATH -user username
```
#### Find recently modified files/folders
There are 3 timestamps associated with files in Linux [[42](README.md)]:
- `atime` "access time": last time file was accessed by a command or application
- `mtime` "modify time": last time file's contents were modified
- `ctime` "change time": last time file's attribute was modified 

Numerical arguments can be specified in 3 ways:
- `+n` greater than {n} days ago
- `-n` less than {n} days ago
- `n` exactly {n} days ago
```sh
find $PATH -type f -mtime +120 -ls # Find only files that were modified more than 120 days ago
find $PATH -type f -mtime -15 -ls # Modified less than 15 days ago
find $PATH -type f -mtime 10 -ls # Modified exactly 10 days ago

# Find files modified over the past day
find $PATH -type f -newermt "1 day ago" -ls
find $PATH -type f -newermt "-24 hours" -ls
find $PATH -type f -newermt "yesterday" -ls

find $PATH -type f -ctime -1 -ls # Find files created today
```
### firewall-cmd
Successor to `iptables` in Red Hat, and like its predecessor a frontend to the netfilter protocols. Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved

Configuration file                          | Description
:---                                        | :---
/etc/sysconfig/network-scripts/ifcfg-ens33  | interface settings
/usr/lib/firewalld/services                 | .xml files that define services ("ZONE=public")

Display status of service
```
firewall-cmd --state
```
Display default zone
```
firewall-cmd --get-default-zone
```
Display zones that are attached to an interface
```
firewall-cmd --get-active-zones
```
Add a new zone
```
firewall-cmd --new-zone=testlab
```
Add a new zone, and write the change to disk
```
firewall-cmd --new-zone=testlab  --permanent
```
Load saved configuration
```
firewall-cmd --reload
```
Display names of all available services
```
firewall-cmd --get-services
```
Add a service permanently
```
firewall-cmd --add-service=ftp --permanent
```
Display services loaded in memory
```
firewall-cmd --list-services
```
Remove service
```
firewall-cmd --remove-service
```
Add nonstandard port
```
firewall-cmd --add-port=8080/tcp
```
Add a range of nonstandard ports
```
firewall-cmd --add-port=50000-60000/udp
```
See approved port numbers
```
firewall-cmd --list-ports
```
Add a range of nonstandard ports
```sh
firewall-cmd --add-port=50000-60000/udp
```
Add a nonstandard port
```sh
firewall-cmd --add-port=8080/tcp
```
Add the FTP service to the firewall
```sh
firewall-cmd --add-service=ftp
```
Display zones that actually have an attached interface
```sh
firewall-cmd --get-active-zones
```
Display the default zone
```sh
firewall-cmd --get-default-zone
```
Display names of available services
```sh
firewall-cmd --get-services
```
Display approved port numbers
```sh
firewall-cmd --list-ports
```
Define a new zone "testlab"
```sh
firewall-cmd --new-zone=testlab
```
Record a change to the configuration on disk
```sh
firewall-cmd --permanent
```
Load configuration on disk into memory
```sh
firewall-cmd --reload
```
Remove firewalld service
```sh
firewall-cmd --remove-service
```
Confirm firewalld is running
```sh
firewall-cmd --state
```


### fold
Display text of {file}, wrapping long lines
```sh
fold  file
```

### fsck
Check filesystem for errors\
Display progress indicators
```sh
fsck -C
```
Specify {ext3} filesystem and check {/dev/sdc1} for errors
```sh
fsck -t ext3 /dev/sdc1
```
Prompt when attempting a repair action 
```sh
fsck -r
```

### fstrim
Discard unused blocks on a mounted filesystem

### gdmsetup
GUI program used to set options for the login window when using GDM


### getfacl
Get access control list for {file}

### gpg
PGP was bought by Semantec, and GNU has since released GPG, an open-source replacement.[35](sources.md)

Option  | POSIX option  | Effect
:---    | :---          | :---
\-      | `--clearsign`<br/>`--clear-sign` | make a cleartext signature, readable without any special software
\-      | `--send-keys` | send keys to a keyserver
`-d`    | `--decrypt`   | decrypt $FILE}
`-k`    | `--list-keys`<br/>`--list-public-keys` | list available GPG keys

Decrypt file
```sh
gpg file.txt
```
Export GPG public key
```sh
gpg --export --output ~/jdoe.pub
```
Import another person's public key
```sh
gpg --import jdoe.pub
```
List available GPG keys
```sh
gpg --list-key
```
Encrypt a file
```sh
gpg --encrypt -r jdoe@dplaptop.lab.itpro.tv ./file.txt
```

#### Sign {file} without encrypting it (produces file.asc)
```sh
gpg --clearsign file
```
#### Generate a key
```sh
gpg --generate-key
gpg --gen-key
```
#### Import another person's public key
```sh
gpg --import ~/jdoe.pub
```
#### Send keys to {keyserver}
```sh
gpg --send-keys keyIDs --keyserver keyserver
```



### grub
#### Install boot images within a directory other than /boot
```sh
grub-install --boot-directory
```
#### Send output of grub2-mkconfig to the correct location for booting
```sh
grub2-mkconfig --output=/boot/grub2/grub.cfg
```

### hdiutil
Manipulate disk images

### hdparm
Get/set SATA/IDE device parameters\
Check power mode
```sh
hdparm -C
```
Show drive geometry, including size in sectors and starting offset
```sh
hdparm -g
```

### head
Print first 8 characters of `$FILE`
```sh
head -c8 $FILE
```

### host
Display SOA record frm each authoritative DNS nameserver
```sh
host -C
```

### hostname
Return the domain name configured for the server
```sh
hostname -d
```

### hwclock
Access the BIOS clock\
Set hardware clock to software clock
```sh
hwclock --hctosys
```
Set software clock to hardware clock
```sh
hwclock --systohw
```

### system
Display the Hardware Clock time
```sh
hwclock --show
```

### iconv
Convert text from one encoding to another\
Convert {file} from ASCII to UTF-8
```sh
iconv -f ASCII -t UTF-8 file
```
Show available character sets
```sh
iconv -l --list
```

### ifconfig
"RX" and "TX" stand for received and transmitted.\
Apply a static IP address to interface {eth0} and turn it on ("up")
```
ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0
```
Bring an interface up or down
```
ifup eth0
ifdown eth0
```
```
ifconfig eth0 up
ifconfig eth0 down
```
Display details of all interfaces (even disabled)
```sh
ifconfig -a
```
Disable eth0
```sh
ifconfig eth0 down
```
Configure eth0 with an additional IPv6 address
```sh
ifconfig eth0 inet6 add fdd6:551:b09e::/128
```
Enable eth0
```sh
ifconfig eth0 up
```
Turn network interface {eth0} on or off using `ifconfig`
```sh
ifconfig eth0 up
ifconfig eth0 down
```
Turn off network interface {eth0}
```sh
ifdown eth0
```
Bring online all interfaces marked as auto within the networking configuration
```sh
ifup -a
```
Turn on network interface {eth0}
```sh
ifup eth0
```

### insmod
Insert a module into the Linux kernel
```sh
insmod module
```

### iscsiadm
Command-line utility allowing discovery and login to iSCSI targets\
Set interval length between two ping requests
```sh
iscsiadm -i
```
Discover iSCSI targets
```sh
iscsiadm discovery
```

### `iwlist`
Get detailed wireless information about a wireless interface

### `kill`
List signal options
```sh
kill -l
kill --list
```
Transmit SIGKILL to {proc}
```sh
kill -9 proc
kill --KILL proc
```

### last
Display history of successful logins\
Load information from an alternate file
```sh
last -f file
last --file file
```
Display history of successful logins by {username}
```sh
last username
```

### lastb
Display history of unsuccessful logins

### ldconfig
Change location of cache to be updated
```sh
ldconfig -C
```
Print current directories and libraries in cache
```sh
ldconfig -p
```
Display all shared libraries
```sh
ldconfig -v
```

### ldd
Display dependencies of {program}
```sh
ldd program
```

### let
Perform arithmetic as specified by one or more `expressions`
```sh
let  expressions | ((expressions))
```

### link
Create a link between two files; same as `ln`, but with no error checking
```sh
link file1 file2
```

### locale
Display all environment variables related to localization with their current values\
Display all localizations currently supported by the system
```sh
locale -a
```

### logout
Exit a login shell

### lp
Send `files` to the printer; with no arguments, prints stdin

### lpstat
Print the `lp` print queue status

### lsblk
Display information about all block devices\
Show UUID, Label, and filesystems of non-GPT block devices
```sh
lsblk -f
```

### lsmod
Display currently loaded modules. Output in three columns:
1. Module name
2. Module size (bytes)
3. Processes, filesystems, or other modules using the module

### lspci
Display devices that are attached to the PCI bus

Option  | Effect
:---    | :---
`-k`    | display PCI devices and the drivers being used
`-n`    | display device numbers rather than names
`-nn`   | display both device numbers and names (typically stored in [ /usr/share/hwdata/pci.ids ](#configs) or [ /usr/share/hwdata/pci.ids.gz ](#configs))

### lsusb
Display devices that are attached to the PCI bus

Option  | Effect
:---    | :---
`-D`    | display {$DEVICE} rather than probing the /dev/bus/usb directory and displaying all devices
`-t`    | display devices in a tree-like format

### mailq
Display the current mail queue on a Postfix server

### mailstats
Gather and display statistics about mail processed on a server running [ `sendmail` ](#sendmail)

### makemap
Execute after making a change to the [ `sendmail` ](#sendmail) access database [ **/etc/access** ](configs.md)

### mdadm
Manage Linux Software RAID devices

POSIX option  | Effect
:---          | :---
`--assemble`  | Start a stopped RAID array
`--delay`     | Set the polling interval

### `mhwd`
Manjaro hardware utility
`sudo mhwd -a pci nonfree 0300` : command was run while troubleshooting black screen on startup 

### `mhwd-chroot`
Chroot into an installed Linux installation from a live boot of a Manjaro Installation Media

### `mkdir`
Quickly create multiple directories using brace expansion
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
Create new directory {dirname} along with all of the parents in its pathname, if they do not exist
```sh
mkdir -p dirname
mkdir --parents dirname
```

### mke2fs
Create an ext2/3/4 filesystem

### mkfontscale
Create a fonts.scale file definition when executed against the current directory

### mkfs
Create an ext4 filesystem on {partition}
```sh
mkfs -t ext4 partition
```
Specify {filesystemtype} to be created
```sh
mkfs -T filesystemtype
```
Make a swap file out of {partition}
```sh
mkswap partition
```

### modinfo
Determine options that a given module supports
```sh
modinfo -p
```
Show information about a Linux kernel module
```sh
modinfo module
```

### modprobe
Add and remove modules from the Linux kernel

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    | `--showconfig`          | display current `modprobe` configuration
`-R`    | `--resolve-alias`       | display all modules that match an alias
`-r`    | `--remove`              | remove specified module from memory

Remove {$MODULE} from the Linux kernel
```sh
modprobe --remove $MODULE
```
Show kernel {$MODULE}'s dependencies
```sh
modprobe --show-depends $MODULE
```

### mongod
MongoDB daemon

POSIX option  | Effect
:---          | :---
`--dbpath`    | 
`--fork`      |
`--logpath`   |
`--port`      |

Run MongoDB service in the background on port 80
```sh
mongod --dbpath $HOME/db --port 80 --fork --logpath /var/tmp/mongodb
```

### mount
Mount all filesystems in `fstab`
```sh
mount -a
```
Mount `$FILESYSTEM` as read-only
```sh
mount -r $FILESYSTEM
```
Specify `$FILESYSTEM` type
```sh
mount -t
```
Mount a partition using its UUID
```sh
mount -U
```
Mount `$FILESYSTEM` as read-write
```sh
mount -w filesystem
```
Mount a USB stick that is made available on /dev/sdb in /media/usb
```sh
mount /dev/sdb1 /media/usb
```

### msmtp
[[51](sources.md)]
Config file   | Description
:---          | :---
~/.msmtprc    | 


### mt
Control magnetic tape drive operation; operates on environment variable TAPE

### netplan
Ubuntu network configuration tool

Config file   | Description
:---          | :---
/etc/netplan/ | directory containing various configuration files and scripts
/etc/nplan/99_config.yaml | netplan config

Apply network configuration settings
```sh
netplan apply
```

### newaliases
Refresh the mail system after a change to the [ /etc/aliases ](#configs) file; Must be run after making a change to email aliases on a server running [ `postfix` ](#postfix)

### nice
Run {prog} at a nice value of (positive) 10
```sh
nice -10 prog
nice -n 10
nice prog
```
### nl
#### Number all lines, including blank lines
```sh
nl -b a file
nl --body-numbering=a file
```
### nmblookup
Test NetBIOS name resolution

### nohup
Execute {cmd} in the background such that it won't be interrupted by a logoff
```sh
nohup cmd &
```

### `ntpdate`
Synchronize system clock to that of an online Network Time Protocol server
```sh
ntpdate -upool.ntp.org
```

### `passwd`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-e`    | `--expire`              | immediately expire the passwore of {user}, forcing a password change on next login
`-i`    | `--inactive`            |
`-l`    | `--lock`                | 
`-u`    | `--unlock`              |

```sh
passwd -e user # passwd --expire user
```
Disable an account after {n} days of inactivity
```sh
passwd -i n # passwd --inactive n
```
Lock {user}'s account
```sh
passwd -l user # passwd --lock
```
Unlock {user}'s account
```sh
passwd -u user # passwd --unlock
```

### paste
Merge lines of files\
Make a .csv file from two lists
```sh
paste -d ',' file1 file2
```
Transpose rows
```sh
paste -s file1 file2
```

### patch
Ignore whitespace
```sh
patch -i
```

### `ping`
"packet Internet groper" utility used for checking network connections, using ICMP packets (cf. [ `nc` ](nc.md))\
Send `$N` number of pings
```
ping -c $N
``` 
Flood ping
```
ping -f
```
Print timestamp
```
ping -D
```
Mark outgoing packet to be processed appropriate to kernel's policy
```
ping -m
``` 
Numeric output only; disable name resolution
```sh
ping -n
```
Bypass routing tables
```sh
ping -r
```

### pip
Display installed packages
```sh
pip list
```
Display information about {package}
```sh
pip show package
```

### postqueue
Cause mail queue to be processed on a Postfix server
```sh
postqueue -f
```
### postsuper
Delete all of the messages from the queue on a postfix server
```sh
postsuper -d
```
### pydoc
Display all installed Python modules
```sh
pydoc modules
```
### quota
Check quota status of {user}
```sh
quota user
```
### quotacheck
Create the quota database
### quotaoff
Turn off all quotas
```sh
quotaoff -a
```
### `quotaon`
Turn on all quotas
```sh
quotaon -a
```
Turn on quotas for {user}
```sh
quotaon -u user
```
### read
Option  | Effect
:---    | :---
`-a`    | read from standard input, with the words assigned to sequential indices of {array}
`-d`    | read from standard input, with the first character of `delim` being used to terminate input, rather than newline
`-e`    | read from standard input, if standard input is coming from a terminal, readline is used to obtain the line
`-n`    | read from standard input, returning after reading {n} chars
`-p`    | read from standard input, displaying {$PROMPT} on standard error before reading any input
`-r`    | read from standard input, backslash no longer will act as an escape character
`-s`    | read from standard input, silent mode (characters are not echoed)
`-t`    | read from standard input, returning failure is a complete line of input is not read within {n} seconds
`-u`    | read input from file descriptor { $FILE }

Stopwatch\
Will stop when you press enter, displaying how much time elapsed
```sh
time read
```
### `repquota`
#### Human-readable
```sh
repquota -sh
```
### `resize4fs`
Resize ext4 filesystem

### `restorecon`
Restore security context default in the policy
```sh
restorecon -Rv website
```

### `rmmod`
Wait until a module is no longer in use before unloading
```sh
rmmod -w
```
Remove $MODULE from the Linux kernel
```sh
rmmod $MODULE
```
### `route`
Display and manipulate the routing table\
Display routing table
```
route -n
```
Add a default gateway
```
route add default gw 192.168.0.1
```
Remove a default gateway
```
route del default gw 192.168.0.1
```
Give a particular network a different gateway
```
route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1
```
Add a route to the server for the network 192.168.51.0/24 through the gateway 192.168.51.1
```sh
route add -net192.168.51.0 netmask 255.255.255.0 gw 192.168.51.1
```
Add default gateway at {ipaddr}
```sh
route add default gw ipaddr
```


### runlevel
Show runlevel for system
```sh
runlevel 
```
### smbclient
Connect to a Samba server
Set the port while connecting to a Samba server
```
smbclient -p
```

### smbpasswd
Create a Samba password

### smbstatus
Report on current Samba connections
List Samba shares
```sh
smbstatus -S
```

### sed
Run sed commands in `sedscr` on file
```sh
sed -f sedscript file
```
Suppress automatic printing of pattern space
```sh
sed -n
sed --quiet
sed --silent
```

### SELinux
Display SELinux contexts for processes
```sh
ps auxZ
```
Display SELinux context for files
```sh
ls -Z
```
Display status of SELinux
```sh
sestatus
```
Change SELinux mode
{$MODE} can be "enforcing" (or "1"), "permissive" ("0") or "disabled"
```sh
setenforce $MODE
```
Amend policy to add a file context
```sh
semanage fcontext -a -t httpd_sys_content_t website
```
Add a port context
```sh
semanage port -a -t http_port_t -p tcp 8080
```
Display all ports with attached types
```sh
semanage port -l
```

### `seq`
Sequence from 1 to 15
```sh
seq -f "%03g" 15
```
Sequence from 5 to 99, separated by a space instead of a newline
```sh
seq -s " " 5 99
```
Sequence every third number from 5 to 20
```sh
seq 5 320
```
Sequence from 1 to 8
```sh
seq 8
```

### `sfdisk`
Script-oriented tool for partitioning disk devices

Set the first partition of the first SATA device to a RAID type
```sh
sfdisk --id /dev/sda 1 fd
```
Set the first partition of the first SATA device to a RAID type
```sh
sfdisk --id /dev/sda 1 fd
```
List partitions on all devices
```sh
sfdisk-l # sfdisk --list
```
List partitions on {device}
```sh
sfdisk-l device # sfdisk --list device
```

### `shred`
Write random data to an unmounted disk for {n} passes
```sh
shred --iterations=n
```

### `shutdown`
Shut down at 8 pm
```sh
shutdown 20:00
```

### `slapadd`
Add entries to the slapd LDAP directory

### `sleep`
Wait a specified number of `seconds` before executing another command; often used in shell scripts
```sh
sleep seconds
```

### source
Execute commands from a file in the current shell
```sh
source file
. file
```
### speaker-test
Test loudspeakers with a 2-speaker setup
```sh
speaker-test -c 2
```

### `stty`
Return number of rows and columns of the terminal
```sh
stty size
```

### swapon
Instruct system to begin using {partition} as a swap file
```sh
swapon partition
```
### `sysctl`
View and configure kernel parameters at runtime\
Display current hostname as known to the kernel
```sh
sysctl -n kernel.hostname
```

### `syslog`
System logging facility used for messages from the kernel


### `tail`
Output last lines beginning at 30th line from the start
```sh
tail -n=+30
tail --lines=+30
```

### `tcpdump`
Inspect actual IP packets\
Set snapshot length of capture (default 65,535B)
```sh
tcpdump -s
```

### tput
Return width of current terminal window
```sh
tput cols 
```
Return height of current terminal window
```sh
tput lines
```

### tracepath
Successor to `traceroute`, blocked by many ISPs because it is a newer tool

### traceroute
Follow the path a packet takes between two hosts

Option  | Effect
:---    | :---
`-i`    | choose the **i**nterface to be used for the path trace
`-s`    | choose the **s**ource address to be used for the path trace
`-T`    | use **T**CP SYN packets for the path trace
`-t`    | set the **t** of service flag (ToS) to be used for the path trace

### `tune2fs`
Adjust various ...
Run `fsck` on {/dev/sdb1} on every boot
```sh
tune2fs -c 1 /dev/sdb1
```
Run `fsck` on {/dev/sda1} at intervals of 60 mounts or 6 months
```sh
tune2fs -c 60 -i 6m /dev/sda1
```
Enable journaling on ext2 partition {/dev/sdc1}
```sh
tune2fs -j /dev/sdc1
```
Assign label "Sales" to logical volume {/dev/vg1/Sales}
```sh
tune2fs -L Sales /dev/vg1/Sales
```

### `tzselect`
Select timezone

### `udevadm`
Udev management tool

Option  | Effect
:---    | :---
`-u`    | **u**pdate the hardware database index after updating source files related to udev

### `umount`
Unmount a USB stick mounted a `/dev/sda`
```sh
umount /dev/sda1
```

### update-rc.d
Create links within /etc/rc.d/ for starting and stopping services

### `vifs`
Safely edit fstab file

### `visudo`
Edit and view the `etc/sudoers` file

### wall
Send {message} to users in {group}
```sh
wall -g group message
wall --group group message
```
### `whatis`
Look up one or more commands in the online manpages and display a brief description
```sh
whatis commands
```

### `touch`
Update {newfile}'s modification date to match {oldfile} [[36](sources.md)]
```sh
touch -r oldfile newfile
```

### `sosreport`
**SOS** is an open-source data collection tool that can be used to collect system configuration details and diagnostic information from a Unix-like operating system. It is installed by default on Ubuntu Server. [[39](sources.md)]

Option  | POSIX option            | Effect
:---    | :---                    | :---
\-      | `--compression-type`    | specify alternative compression (`xz` by default)
`-l`    |                         | list plugins
\-      | `--tmp-dir`             | specify alternative temporary directory


Collect system configuration details
Without arguments, the report will be generated and stored in `$TMPDIR`
```sh
sosreport

# Specify alternative temporary directory
sosreport --tmp-dir /opt

# Specify alternative compression (`xz` by default)
sosreport --compression-type gzip

# Generate report for only specific plugins
sosreport -o apache --batch
```

## Tasks
### Samba
Install and configure Samba server
Install `samba`
```sh
sudo apt install samba
```
Verify the samba service `smbd` is running
```sh
sudo systemctl status smbd
```
Configure Samba 
```sh
sudo mkdir /samba                   # Create a directory for the share
sudo chmod -R 0777 /samba
sudo chown -R nobody:nobody /samba  # Remove ownership
```
Open firewall rule
```sh
sudo firewall-cmd --permanent --add-service=samba
sudo firewall-cmd --reload
```
Configure Samba config file at [/etc/samba/smb.conf](#etcsambasmbconf)
```conf
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
Set up a Samba account for {user} 
```sh
sudo smbpasswd -a user
```
Restart Samba service [[40](sources.md), [41](sources.md)]
```sh
sudo systemctl restart smbd.service
```
Install and configure Samba as a client
```sh
sudo apt install smbclient 
```
Access samba share at {$shareName} at server {$ipAddress} using user credential {$user}
```sh
sudo smbclient //$ipAddress/$shareName -U $user
```
This will display the Samba CLI
```
smb: \>
```
[[40](sources.md)]

### Bash scripting
Validating arguments [[PGL](../sources/pgl.md): 548]
```sh 
if [ $# != 2 ]
then 
  echo "..."
  exit 1
fi
```
[[7](sources.md)]
```sh
[ -z "$1" ] && echo "..." && exit 1
```
[[8](sources.md)]
```sh
if [ ! -z "$2" ] ; then ...; fi
```
Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate [[23](sources.md)]
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

Display contents of a random file
```sh
ls | sort -R | sed 1q | xargs cat
```
Find out which commands you use most often
```sh
history | awk '{print $2' | sort | uniq -c | sort -rn | head
```
Count the number of occurrences of a string
```sh
| uniq -c | sort -nr
```