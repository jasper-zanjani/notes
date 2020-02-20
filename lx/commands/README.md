# Linux Commands

Topic                         | Commands
:---                          | :---
Ansible                       | [`ansible`][ansible] [`ansible-galaxy`][ansible-galaxy] [`ansible-playbook`][ansible-playbook] `ansible-inventory`
Archive                       | [`ar`][ar] [`bzip2`][bzip2] &bull; [`compress`][compress] &bull; [`gzip`][gzip] [`tar`][tar] [`xz`][xz] &bull; [`zip`][zip] [`unzip`][unzip] [`zipcloak`][zipcloak] [`zipdetails`][zipdetails] [`zipgrep`][zipgrep] [`zipinfo`][zipinfo] [`zipnote`][zipnote] [`zipsplit`][zipsplit] &bull; [`cpio`][cpio] [`dar`][dar]
Audio                         | [`alsamixer`][alsamixer] [`amixer`][amixer] [`speaker-test`][speaker-test]
Bash builtins                 | [`let`][let] [`source`][source]
Build tools                   | [`as`][as] [`xgettext`][xgettext] <br>**Autotools** [`aclocal`][aclocal]  [`autoconf`][autoconf] [`autoheader`][autoheader] [`autoreconf`][autoreconf] [`autoscan`][autoscan] [`autoupdate`][autoupdate] <br>**Compiler-compilers** [`bison`][bison] [`flex`][lex] [`yacc`][yacc]
Date and time                 | [`chrony`][chrony] [`date`][date] [`hwclock`][hwclock] [`timedatectl`][timedatectl]
Distributions                 | **Debian** [`adduser`][adduser] [`apt`][apt] [`apt-cache`] [`apt-key`] [`add-apt-repository`] <br> **Manjaro** [`mhwd`][mhwd] [`mhwd-chroot`][mhwd-chroot] [`pacman`][pacman] [`yay`][yay] <br> **Red Hat** [`dnf`][dnf] [`firewall-cmd`][firewall-cmd] [`yum`][yum] <br> **Ubuntu** [`netplan`][netplan] <br> **Mac OS X** [`pbcopy`][pbcopy] [`pbpaste`][pbpaste] [`screencapture`][screencapture]
Files	                        | [`fallocate`][fallocate] [`install`][install] [`ls`][ls] [`lsof`][lsof] [`setfacl`][setfacl] [`sshfs`][sshfs] [`tree`][tree]
Gnome                         | [`gconf-editor`][gconf-editor] [`gsettings`][gsettings]
GRUB                          | [`update-grub`][update-grub]
Hardware settings             | [`bluetoothctl`][bluetoothctl] [`insmod`][insmod] [`lsmod`][lsmod] [`lspci`][lspci] [`lsusb`][lsusb] [`modprobe`][modprobe] [`rmmod`][rmmod]
Information                   | [`stat`][stat] **Benchmarking** [`free`][free] [`glances`][glances]  [`iperf`][iperf] [`lscpu`][lscpu] [`nproc`][nproc] [`top`][top] [`uptime`][uptime] <br>**Sysstat** [`iostat`][iostat] [`mpstat`][mpstat] [`sar`][sar]
Init                          | **Systemd** [`hostnamectl`][hostnamectl] [`journalctl`][journalctl] [`localectl`][localectl] [`systemctl`][systemd-delta] [`systemd-delta`][systemd-delta] [`timedatectl`][timedatectl] <br> **Sysvinit** [`chkconfig`][chkconfig] [`init`][init] [`service`][service] [`telinit`][telinit] &bull; **Upstart** [`initctl`][initctl]
Kubernetes                    | [`kubeadm`][kubeadm] [`kubectl`][kubectl]
Mail                          | [`mail`][mail] [`mailmerge`][mailmerge] [`mailx`][mailx] [`msmtp`][msmtp] <br> **SMTP servers** [`exim`][exim] [`qmail`][qmail] [`postfix`][postfix] [`sendmail`][sendmail]
Network                       | [`bmon`][bmon] [`ethtool`][ethtool] [`hping3`][hping3] [`iftop`][iftop] [`ip`][ip] [`iperf`][iperf] [`ipset`][ipset] [`netstat`][netstat] [`nc`][nc] [`nmap`][nmap] [`nmcli`][nmcli] [`ss`][ss] [`tracepath`][tracepath] [`traceroute`][traceroute] [`tshark`][tshark] `xinetd` <br>**DNS** [`dig`][dig] [`nslookup`][nslookup] <br>**Wi-Fi** [`iw`][iw] [`iwlist`][iwlist] [`iwconfig`][iwconfig] [`rfkill`][rfkill]
Package managers              | [`apt`][apt] [`brew`][brew] [`dnf`][dnf] [`dpkg`][dpkg] [`gem`][gem] [`pacman`][pacman] [`pip`][pip] [`rpm`][rpm] [`snap`][snap] [`yay`][yay] [`yum`][yum]
Printing                      | [**CUPS**][CUPS] [`cupsaccept`][cupsaccept] [`cupsenable`][cupsenable] [`cupsdisable`][cupsdisable] [`cupsreject`][cupsreject] [`lp`][lp] [`cancel`][cancel] <br> [**LPD**][LPD] [`lpc`][lpc] [`lpq`][lpq] [`lpr`][lpr] [`lprm`][lprm]
Remote connections            | [`rsync`][rsync] [`ssh`][ssh] [`ssh-keygen`][ssh-keygen] [`ssh-keyscan`][ssh-keyscan] [`sshfs`][sshfs]
SELinux                       | [`semanage`][semanage] [`sestatus`][sestatus] [`setenforce`][setenforce]
System administration         | [`chage`][chage] [`chcon`][chcon] [`chgrp`][chgrp] [`chmod`][chmod] [`chown`][chown] [`chpass`][chpass] [`chrony`][chrony] [`chsh`][chsh]  [`free`][free] [`getent`][getent] [`gpasswd`][gpasswd] [`groupadd`][groupadd] [`groupdel`][groupdel] [`groupmod`][groupmod] [`logger`][logger] [`logrotate`][logrotate] [`stty`][stty] [`su`][su] [`sudo`][sudo] [`uname`][uname] [`useradd`][useradd] [`userdel`][userdel] [`usermod`][usermod] [`vifs`][vifs] [`visudo`][visudo] &bull; **Debian** [`adduser`][adduser] <br>**Process management** [`lsns`][lsns] [`pidof`][pidof] [`ps`][ps] [`unshare`][unshare] <br>**Disk management** [`blkid`][blkid] [`partx`][partx] <br>**Logical volumes** [`lvcreate`][lvcreate] [`lvdisplay`][lvdisplay] [`lvremove`][lvremove] [`lvs`][lvdisplay] [`pvcreate`][pvcreate] [`pvdisplay`][pvdisplay] [`pvremove`][pvremove] [`pvs`][pvdisplay] [`vgcreate`][vgcreate] [`vgdisplay`][vgdisplay] [`vgextend`][vgextend] [`vgremove`][vgremove] [`vgs`][vgs]
Text filters                  | [`awk`][awk] [`cat`][cat] [`copy`][copy] [`grep`][grep] [`head`][head] [`nl`][nl] [`paste`][paste] [`sed`][sed] [`shuf`][shuf] [`sort`][sort] [`tail`][tail] [`tr`][tr]
Version control               | [`git`][git] [`tig`][tig]
Virtualization                | [`virt-install`][virt-install] [`virt-manager`][virt-manager]
X                             | [`xdpyinfo`][xdpyinfo] [`xlsclients`][xlsclients] [`xmodmap`][xmodmap] [`Xorg`][xorg] [`xrandr`][xrandr] [`xwininfo`][xwininfo]

\#  | Commands sorted alphabetically
--- | ---
A   | [`aclocal`][aclocal] [`adduser`][adduser] [`add-apt-repository`][add-apt-repository] [`alsamixer`][alsamixer] [`apropos`][apropos] [`apt`][apt] [`apt-cache`][apt-cache] [`apt-key`][apt-key] [`ar`][ar] [`arp`][arp] [`as`][as] [`at`][at] [`ausearch`][ausearch] [`autoconf`][autoconf] [`autoheader`][autoheader] [`awk`][awk]
B   | [`bash`][bash] [`bc`][bc] [`biff`][biff] [`blkid`][blkid] [`bmon`][bmon] [`borg`][borg] [`bpftrace`][bpftrace] [`bzcat`][bzcat] [`bzip2`][bzip2] [`bzless`][bzless] [`bzmore`][bzmore]
C   | [`cancel`][cancel] [`cat`][cat] [`chage`][chage] [`chcon`][chcon] [`chgrp`][chgrp] [`chkconfig`][chkconfig] [`chmod`][chmod] [`chown`][chown] [`chpass`][chpass] [`chrony`][chrony] [`chsh`][chsh] [`column`][column] [`compress`][compress] [`cp`][cp] [`crontab`][crontab] [`crossystem`][crossystem] [`cryptsetup`][cryptsetup] [`curl`][curl] [`cut`][cut]
D   | [`dar`][dar] [`date`][date] [`dbus`][dbus] [`dd`][dd] [`declare`][declare] [`depmod`][depmod] [`df`][df] [`dhclient`][dhclient] [`diff`][diff] [`dig`][dig] [`dirname`][dirname] [`dm-crypt`][dm-crypt] [`dmesg`][dmesg] [`dmidecode`][dmidecode] [`dnf`][dnf] [`doveadm`][doveadm] [`dpkg`][dpkg] [`dpkg-reconfigure`][dpkg-reconfigure] [`dracut`][dracut] [`du`][du] [`dumpe2fs`][dumpe2fs]
E   | [`e2image`][e2image] [`e2label`][e2label] [`edquota`][edquota] [`elvis`][elvis] [`elvish`][elvish] [`espeak`][espeak] [`ethtool`][ethtool] [`exif`][exif]
F   | [`fallocate`][fallocate] [`fam`][fam] [`fc-cache`][fc-cache] [`fdisk`][fdisk] [`file`][file] [`find`][find] [`firewall-cmd`][firewall-cmd] [`firewalld`][firewalld] [`fish`][fish] [`fmt`][fmt] [`fold`][fold] [`free`][free] [`fsck`][fsck] [`fstrim`][fstrim] [`ftp`][ftp] [`fusermount`][fusermount]
G   | [`gconf-editor`][gconf-editor] [`gdisk`][gdisk] [`gdmsetup`][gdmsetup] [`gem`][gem] [`getent`][getent] [`getfacl`][getfacl] [`git`][git] [`gpasswd`][gpasswd] [`gpg`][gpg] [`grep`][grep] [`groupadd`][groupadd] [`groupdel`][groupdel] [`groupmod`][groupmod] [`grub`][grub] [`gsettings`][gsettings] [`gzip`][gzip]
H   | [`hdiutil`][hdiutil] [`hdparm`][hdparm] [`head`][head] [`history`][history] [`host`][host] [`hostname`][hostname] [`hostnamectl`][hostnamectl] [`hwclock`][hwclock]
I   | [`iconv`][iconv] [`ifconfig`][ifconfig] [`iftop`][iftop] [`imagemagick`][imagemagick] [`init`][init] [`initctl`][initctl] [`insmod`][insmod] [`install`][install] [`iostat`][iostat] [`ip`][ip] [`iperf`][iperf] [`ipset`][ipset] [`iptables`][iptables] [`iscsiadm`][iscsiadm] [`iw`][iw] [`iwconfig`][iwconfig] [`iwlist`][iwlist]
J   | [`journalctl`][journalctl]
K   | [`kill`][kill] [`kinit`][kinit] [`klist`][klist] [`kubeadm`][kubeadm] [`kubectl`][kubectl]
L   | [`last`][last] [`ldapadd`][ldapadd] [`ldconfig`][ldconfig] [`ldd`][ldd] [`less`][less] [`let`][let] [`link`][link] [`locale`][locale] [`localectl`][localectl] [`loginctl`][loginctl] [`logout`][logout] [`lp`][lp] [`lpadmin`][lpadmin] [`lpstat`][lpstat] [`ls`][ls] [`lsblk`][lsblk] [`lshw`][lshw] [`lsmod`][lsmod] [`lsns`][lsns] [`lsof`][lsof] [`lspci`][lspci] [`lsusb`][lsusb] [`lvcreate`][lvcreate] [`lvdisplay`][lvdisplay] [`lvremove`][lvremove] [`lvresize`][lvresize]
M   | [`mail`][mail] [`mailq`][mailq] [`mailstats`][mailstats] [`make`][make] [`makemap`][makemap] [`mdadm`][mdadm] [`mhwd`][mhwd] [`mhwd-chroot`][mhwd-chroot] [`mkdir`][mkdir] [`mke2fs`][mke2fs] [`mkfontscale`][mkfontscale] [`mkfs`][mkfs] [`mkinitrd`][mkinitrd] [`mkswap`][mkswap] [`mktemp`][mktemp] [`modinfo`][modinfo] [`modprobe`][modprobe] [`mongod`][mongod] [`mount`][mount] [`msmtp`][msmtp] [`mt`][mt]
N   | [`nc`][nc] [`netplan`][netplan] [`netstat`][netstat] [`NetworkManager`][networkmanager] [`newaliases`][newaliases] [`nice`][nice] [`nl`][nl] [`nmap`][nmap] [`nmblookup`][nmblookup] [`nmcli`][nmcli] [`nohup`][nohup] [`nslookup`][nslookup] [`ntpdate`][ntpdate] [`ntsysv`][ntsysv]
O   | [`openssl`][openssl]
P   | [`pacman`][pacman] [`partx`][partx] [`paste`][paste] [`passwd`][passwd] [`paste`][paste] [`patch`][patch] [`pidof`][pidof] [`ping`][ping] [`pip`][pip] [`postfix`][postfix] [`postqueue`][postqueue] [`postsuper`][postsuper] [`ps`][ps] [`pvcreate`][pvcreate] [`pvdisplay`][pvdisplay] [`pvremove`][pvremove] [`pydoc`][pydoc]
Q   | [`qmail`][qmail] [`quota`][quota] [`quotacheck`][quotacheck] [`quotaoff`][quotaoff] [`quotaon`][quotaon]
R   | [`read`][read] [`rename`][rename] [`repquota`][repquota] [`resize2fs`][resize2fs] [`rfkill`][rfkill] [`resize4fs`][resize4fs] [`restorecon`][restorecon] [`rmmod`][rmmod] [`route`][route] [`rpm`][rpm] [`rsync`][rsync] [`runlevel`][runlevel]
S   | [`samba`][samba] [`sc`][sc] [`screencapture`][screencapture] [`sed`][sed] [`semanage`][selinux] [`sendmail`][sendmail] [`seq`][seq] [`service`][service] [`sestatus`][sestatus] [`setenforce`][setenforce] [`setfacl`][setfacl] [`sfdisk`][sfdisk] [`shred`][shred] [`shuf`][shuf] [`shutdown`][shutdown] [`slapadd`][slapadd]  [`sleep`][sleep] [`snap`][snap] [`sort`][sort] [`sosreport`][sosreport] [`source`][source] [`speaker-test`][speaker-test] [`ss`][ss] [`ssh`][ssh] [`ssh-copy-id`][ssh-copy-id] [`ssh-keygen`][ssh-keygen] [`ssh-keyscan`][ssh-keyscan] [`sshfs`][sshfs] [`ssmtp`][ssmtp] [`startx`][startx] [`stty`][stty] [`su`][su] [`sudo`][sudo] [`swapoff`][swapoff] [`swapon`][swapon] [`sysbench`][sysbench] [`sysctl`][sysctl] [`sysvinit`][sysvinit] [`systemctl`][systemctl] [`systemd-delta`][systemd-delta]
T   | [`tail`][tail] [`tar`][tar] [`tcpdump`][tcpdump] [`telinit`][telinit] [`test`][test] [`tig`][tig] [`timedatectl`][timedatectl] [`tmux`][tmux] [`touch`][touch] [`top`][top] [`tput`][tput] [`tr`][tr] [`tree`][tree] [`tracepath`][tracepath] [`traceroute`][traceroute] [`tshark`][tshark] [`tune2fs`][tune2fs] [`tzselect`][tzselect]
U   | [`udevadm`][udevadm] [`umount`][umount] [`uname`][uname] [`uncompress`][uncompress] [`unshare`][unshare] [`unzip`][unzip] [`update-grub`][update-grub] [`update-rc.d`][update-rc.d] [`useradd`][useradd] [`userdel`][userdel] [`usermod`][usermod]
V   | [`variable`][variable] [`vgcreate`][vgcreate] [`vgdisplay`][vgdisplay] [`vgextend`][vgextend] [`vgremove`][vgremove] [`vgscan`][vgscan] [`vifs`][vifs] [`visudo`][visudo]
W   | [`w`][w] [`wall`][wall] [`watch`][watch] [`wc`][wc] [`whatis`][whatis]
X   | [`X`][x] [`xdpyinfo`][xdpyinfo] [`xgettext`][xgettext] [`xhost`][xhost] [`xinetd`][xinetd] [`Xorg`][xorg] [`xrandr`][xrandr] [`xwininfo`][xwininfo] [`xz`][xz]
Y   | [`yay`][yay] [`yum`][yum] [`yumdownloader`][yumdownloader]
Z   | [`zip`][zip] [`zipcloak`][zipcloak] [`zipdetails`][zipdetails] [`zipgrep`][zipgrep] [`zipinfo`][zipinfo] [`zipnote`][zipnote] [`zipsplit`][zipsplit] [`zsh`][zsh] [`zypper`][zypper]

Command | Options
---     | ---
`xgettext` | [`a`][xgettext -a] <code>&nbsp;</code> [`c`][xgettext -c] [`d`][xgettext -d] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`h`][xgettext -h] <code>&nbsp;</code>  [`j`][xgettext -j] <code>&nbsp;</code> <code>&nbsp;</code> [`m`][xgettext -m] [`n`][xgettext -n] <code>&nbsp;</code>  [`p`][xgettext -p] <code>&nbsp;</code> <code>&nbsp;</code> [`s`][xgettext -s] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  [`x`][xgettext -x] <code>&nbsp;</code> <code>&nbsp;</code> <br><code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`M`][xgettext -M] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 


[xgettext -a]:                                        #xgettext                                          '```&#10;$ xgettext -a&#10;$ xgettext --extract-all&#10;```&#10;Extract all strings, not just those in calls to `gettext` or `dgettext` (applies to C, C++, Objective-C, Shell, Python, Lisp, EmacsLisp, librep, Scheme, Java, C#, awk, Tcl, Perl, PHP, GCC-source, and Glade)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 234'
[xgettext -c]:                                        #xgettext                                          '```&#10;$ xgettext -c $TAG&#10;$ xgettext --add-comments $TAG&#10;```&#10;Copy source file comments marked with $TAG into the .po file as #-delimited comments&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 234'
[xgettext -d]:                                        #xgettext                                          '```&#10;$ xgettext -d $DOMAIN&#10;$ xgettext --default-domain $DOMAIN&#10;```&#10;Use $DOMAIN.po as the output file instead of messages.po&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 234'
[xgettext -h]:                                        #xgettext                                          '```&#10;$ xgettext -h&#10;$ xgettext --help&#10;```&#10;Print a help message on STDOUT'
[xgettext -j]:                                        #xgettext                                          '```&#10;$ xgettext -j&#10;$ xgettext --join-existing&#10;```&#10;Join (merge) extracted messages with those in the current .po file. Domain directives in the existing .po file are ignored'
[xgettext -m]:                                        #xgettext                                          '```&#10;$ xgettext -m $PREFIX&#10;$ xgettext --msgstr-prefix $PREFIX&#10;```&#10;Fill in each `msgstr` with $PREFIX. Intended for debugging.'
[xgettext -M]:                                        #xgettext                                          '```&#10;$ xgettext -M $SUFFIX&#10;$ xgettext --mststr-suffix $SUFFIX&#10;```&#10;Fill in each `msgstr` with $SUFFIX. Intended for debugging.'
[xgettext -n]:                                        #xgettext                                          '```&#10;$ xgettext -n&#10;$ xgettext --add-location&#10;```&#10;Add comments to the .po file indicating the source filename and line number where each string is used'
[xgettext -p]:                                        #xgettext                                          '```&#10;$ xgettext -p $PATH&#10;$ xgettext --output-dir $PATH&#10;```&#10;Place output files in the directory $PATH'
[xgettext -s]:                                        #xgettext                                          '```&#10;$ xgettext -s&#10;$ xgettext --sort-output&#10;```&#10;Sort the output by `msgid` (original string), with all duplicates removed.'
[xgettext -x]:                                        #xgettext                                          '```&#10;$ xgettext -x $EXFILE&#10;```&#10;$EXFILE is a .po file with `msgid`s that are not to be extracted (and thus excluded).'
### `adduser`
### `apropos`
Look up one or more `keywords` in the online manpages: same as `man -k` (rf. `whatis`)
```sh
apropos keywords
```
### `arp`
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
### `bluetoothctl`
&nbsp;  | `bluetoothctl` commands [^][http://www.linux-magazine.com/Issues/2017/197/Command-Line-bluetoothctl#article_i1] [^][https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]
---     | ---
&nbsp;  | [`device`][bluetoothctl devices] &bull; [`list`][bluetoothctl list] &bull; [`pair`][bluetoothctl pair] &bull; [`pairable on`][bluetoothctl pairable on] &bull; [`scan on`][bluetoothctl scan on] &bull; [`select`][bluetoothctl select] &bull; [`show`][bluetoothctl show]

[bluetoothctl list]:                                              #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# list&#10;```&#10;Display available controllers'
[bluetoothctl show]:                                              #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# show&#10;```&#10;Display more detailed inormation about available controllers'
[bluetoothctl select]:                                            #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# select&#10;```&#10;Select controller to pair, if the system has more than one'
[bluetoothctl scan on]:                                           #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# scan on&#10;```&#10;Receive a list of detected devices'
[bluetoothctl pairable on]:                                       #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# pairable on&#10;```&#10;Prepare controller for pairing'
[bluetoothctl devices]:                                           #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# devices&#10;```&#10;List available devices'
[bluetoothctl pair]:                                              #bluetoothctl                                       '```&#10;$ bluetoothctl&#10;[bluetooth]# pair $DEVICE&#10;```&#10;Pair with `$DEVICE`, which is the MAC address of the pairable device'
### `bpftrace`
New open-source tracer for analyzing production performance problems and troubleshooting software [^][19]
### `cp`
Preserve symlinks in a recursive copy
```sh
cp -a
cp --archive
```
### `crontab`
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
### `crossystem`
Print all parameters with descriptions and current values
### `cryptsetup`
Incorporate full-disk encryption on /dev/sdb1, asking for passphrase twice
```sh
cryptsetup --verify-passphrase luksFormat /dev/sdb1
```
Assign virtual name "storage1" to encrypted disk /dev/sdb1
```sh
cryptsetup luksOpen /dev/sdb1 storage1
```
### `curl`
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
### `cut`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    |                         | character number
`-d`    | `--delimiter`
`-f`    |                         | field number
### `date`
Display the date and time according to locale settings\

Option  | Effect
:---    | :---
`-s`    | set date [^][4]

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
Display the date fifty days into the future [^][50]
```sh
date -d '+50days' +%F
```
### `dbus-monitor`
Monitor messages going through a D-Bus message bus
### `dd`
Implement a simple CPU benchmark by writing 1 GB of zeroes and piping it to md5sum
```sh
dd if=/dev/zero bs=1M count=1024 | md5sum
```
### `declare`
Option which displays output in a way that could then be used as input to another command
```sh
declare -p
```
### `df`
Change scale to terabytes
```sh
df -BT
df --block-size=T
```
Show drive utilization
```sh
df -h
```
### `dhclient`
Obtain and configure TCP/IP information from a server on the network [[LGLC](../sources/lglc.md): 34]
Turn on the DHCP client and get a new address from the server
```
dhclient
```
Release the currently assigned IP address and get a new one
```sh
dhclient -r
```
### `diff`
Three lines of context
```sh
diff -c
```
Case-insensitive
```sh
diff -i
```
Ignore whitespace
```sh
diff -w
```
### `dirname`
Strip filename from $PATH (cf. [ `basename` ](#basename))
```sh
dirname $PATH
```
### `dm-crypt`
Disk-encryption subsystem which serves as the backend to [ `cryptsetup` ](#cryptsetup)
### `dmesg`
Disable kernel messages from being sent to the console
```sh
dmesg -d
```
Enable kernel messages being sent to the console
```sh
dmesg -e
```
Display the time in local time
```sh
dmesg -e
dmesg --reltime
```
### `du`
Summary of information in human-readable format
```sh
du -sh
du --summarize --human-readable
```
Show the size of all files and subdirectories of {dir} in human-readable form
```sh
du -h dir
```
Show the size of {file} in human-readable form
```sh
du -h file
```
Show the size of a directory at {path} in human-readable form
```sh
du -hs path
```
### `dumpe2fs`
Display detailed filesystem information
### `e2label`
Create an image of important metadata for an ext3 filesystem
Assign label "Storage" to /dev/sdb1
```sh
e2label /dev/sdb1 Storage
```
### `exif`
View image metadata. Unlike alternatives like `file` and ImageMagick's `identify`, `exif` produces columnar output [^][31]
```sh
exif image.png 
```
### `fc-cache`
Update the font cache [^][59]
```sh
fc-cache -v
```
### `file`
View image metadata [^][31]
```sh
file image.png # => file type, dimensions, color depth
```
### `find`
Search for files in a directory hierarchy
Find all files in {$PATH} that are owned by {user}
```sh
find $PATH -user username
```
Find recently modified files/folders
There are 3 timestamps associated with files in Linux [^][42]
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
### `firewall-cmd`
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
### `fsck`
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
### `fstrim`
Discard unused blocks on a mounted filesystem
### `ftp`
encrypted file transfers
### `fusermount`
Mount a directory from a remote server on your local host via SSH [^][[23]
```sh
fusermount -u mountpoint
```
### `gdmsetup`
GUI program used to set options for the login window when using GDM
### `getfacl`
Get access control list for {file}
### `gpg`
PGP was bought by Semantec, and GNU has since released GPG, an open-source replacement.

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
Sign {file} without encrypting it (produces file.asc)
```sh
gpg --clearsign file
```
Generate a key
```sh
gpg --generate-key
gpg --gen-key
```
Import another person's public key
```sh
gpg --import ~/jdoe.pub
```
Send keys to {keyserver}
```sh
gpg --send-keys keyIDs --keyserver keyserver
```
### `hdiutil`
Manipulate disk images
### `hdparm`
Get/set SATA/IDE device parameters\
Check power mode
```sh
hdparm -C
```
Show drive geometry, including size in sectors and starting offset
```sh
hdparm -g
```
### `history`
Option  | Effect
:---    | :---
`-c`    | clear history [^][23]
### `host`
Display SOA record frm each authoritative DNS nameserver
```sh
host -C
```
### `hostname`
Return the domain name configured for the server
```sh
hostname -d
```
### `hwclock`
Access the BIOS clock\
Set hardware clock to software clock
```sh
hwclock --hctosys
```
Set software clock to hardware clock
```sh
hwclock --systohw
```
Display the Hardware Clock time
```sh
hwclock --show
```
### `iconv`
Convert text from one encoding to another\
Convert {file} from ASCII to UTF-8
```sh
iconv -f ASCII -t UTF-8 file
```
Show available character sets
```sh
iconv -l --list
```
### `insmod`
Insert a module into the Linux kernel
```sh
insmod module
```
### `iscsiadm`
Command-line utility allowing discovery and login to iSCSI targets\
Set interval length between two ping requests
```sh
iscsiadm -i
```
Discover iSCSI targets
```sh
iscsiadm discovery
```
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
### `last`
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
### `lastb`
Display history of unsuccessful logins
### `ldconfig`
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
### `ldd`
Display dependencies of {program}
```sh
ldd program
```
### `link`
Create a link between two files; same as `ln`, but with no error checking
```sh
link file1 file2
```
### `locale`
Display all environment variables related to localization with their current values\
Display all localizations currently supported by the system
```sh
locale -a
```
### `logger`
Create a one-time log file entry that you specify.
### `logout`
Exit a login shell
### `lowriter`
`lowriter` is a command-line utility installed with LibreOffice Writer. [^][21]
Convert a single file to PDF
```sh
lowriter --convert-to pdf filename.doc
```
Convert a batch of files using globbing
```sh
lowriter --convert-to pdf *.docx
```
### `lp`
Send `files` to the printer; with no arguments, prints stdin
### `lpstat`
Print the `lp` print queue status
### `lsblk`
Display information about all block devices\
Show UUID, Label, and filesystems of non-GPT block devices
```sh
lsblk -f
```
### `lsmod`
Display currently loaded modules. Output in three columns:
1. Module name
2. Module size (bytes)
3. Processes, filesystems, or other modules using the module
### `lspci`
Display devices that are attached to the PCI bus

Option  | Effect
:---    | :---
`-k`    | display PCI devices and the drivers being used
`-n`    | display device numbers rather than names
`-nn`   | display both device numbers and names (typically stored in [ /usr/share/hwdata/pci.ids ](#configs) or [ /usr/share/hwdata/pci.ids.gz ](#configs))
### `lsusb`
Display devices that are attached to the PCI bus

Option  | Effect
:---    | :---
`-D`    | display {$DEVICE} rather than probing the /dev/bus/usb directory and displaying all devices
`-t`    | display devices in a tree-like format
### `makemap`
Execute after making a change to the [ `sendmail` ](#sendmail) access database [ **/etc/access** ](configs.md)
### `mdadm`
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
### `mke2fs`
Create an ext2/3/4 filesystem
### `mkfontscale`
Create a fonts.scale file definition when executed against the current directory
### `mkfs`
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
### `mktemp`
Create a temporary file or directory safely and print its name. These will not need to be manually cleaned up because they will be placed in the temporary directory (**/tmp**) [^][29]

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
### `modinfo`
Determine options that a given module supports
```sh
modinfo -p
```
Show information about a Linux kernel module
```sh
modinfo module
```
### `modprobe`
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
### `mongod`
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
### `mount`
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
### `mt`
Control magnetic tape drive operation; operates on environment variable TAPE
### `mv`
Option  | POSIX option            | Effect
:---    | :---                    | :---
\-      | `--backup`              | takes an argument defining how the backup file is named (not available in BSD)
`-f`    | `--force`               | overrides `--interactive`
`-i`    | `--interactive`         | 
`-n`    | `--no-clobber`          | silently reject move action in the event of a conflict
`-u`    | `--update`              | only overwrite if the modification time of the destination is older than the source
### `netplan`
Ubuntu network configuration tool

Config file   | Description
:---          | :---
/etc/netplan/ | directory containing various configuration files and scripts
/etc/nplan/99_config.yaml | netplan config

Apply network configuration settings
```sh
netplan apply
```
### `networkmanager`
Stop NetworkManager service
```sh
chkconfig NetworkManager off               # Upstart
systemctl disable NetworkManager.service   # Systemd
service NetworkManager stop                # sysvinit
```
### `newaliases`
Refresh the mail system after a change to the [ /etc/aliases ](#configs) file; Must be run after making a change to email aliases on a server running [ `postfix` ](#postfix)
### `nice`
Run {prog} at a nice value of (positive) 10
```sh
nice -10 prog
nice -n 10
nice prog
```
### `nmblookup`
Test NetBIOS name resolution
### `nohup`
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
### `paste`
Merge lines of files\
Make a .csv file from two lists
```sh
paste -d ',' file1 file2
```
Transpose rows
```sh
paste -s file1 file2
```
### `patch`
Ignore whitespace
```sh
patch -i
```
### `ping`
"packet Internet groper" utility used for checking network connections, using ICMP packets (cf. [ `nc` ](network.md#nc))\
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
### `pydoc`
Display all installed Python modules
```sh
pydoc modules
```
### `quota`
Check quota status of {user}
```sh
quota user
```
### `quotacheck`
Create the quota database
### `quotaoff`
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
### `read`
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
### `rename`
`rename` uses regular expressions [^][33]

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
### `repquota`
Human-readable
```sh
repquota -sh
```
### `resize2fs`
Resize filesystem of logical volume {Marketing} on volume group {vg1} to take up the entire logical volume
```sh
resize2fs /dev/vg1/Marketing
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
### `screen`
Share your screen session with another user
```sh
screen -x user/session
```
### `smbclient`
Connect to a Samba server
Set the port while connecting to a Samba server
```
smbclient -p
```
### `smbpasswd`
Create a Samba password
### `smbstatus`
Report on current Samba connections
List Samba shares
```sh
smbstatus -S
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

Script-based partition table editor, similar to [`fdisk`](#fdisk) and [`gdisk`](#gdisk), which can be run interactively. It does not interface with GPT format, neither is it designed for large partitions. [^][11]

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
#### `stat`
Display statistics for a file
```sh
stat file
```
### `stty`
Return number of rows and columns of the terminal
```sh
stty size
```
### `swapon`
Instruct system to begin using {partition} as a swap file
```sh
swapon partition
```
### `sysctl`
View and configure kernel parameters at runtime

Display current hostname as known to the kernel
```sh
sysctl -n kernel.hostname
```
### `syslog`
System logging facility used for messages from the kernel
### `tcpdump`
Inspect actual IP packets

All network data will be displayed to STDOUT
```
tcpdump -i eth0   
```
Set snapshot length of capture (default 65,535B)
```sh
tcpdump -s
```
### `touch`
Update `$NEW`'s modification date to match `$OLD` [^][36]
```sh
touch -r $OLD $NEW
```
### `tput`
Return width of current terminal window
```sh
tput cols 
```
Return height of current terminal window
```sh
tput lines
```
### `tracepath`
Successor to `traceroute`, blocked by many ISPs because it is a newer tool
### `traceroute`
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
### `update-rc.d`
Create links within /etc/rc.d/ for starting and stopping services
### `vifs`
Safely edit fstab file
### `visudo`
Edit and view the `etc/sudoers` file
### `wall`
Send {message} to users in {group}
```sh
wall -g group message
wall --group group message
```
### `watch`
Repeat a command at regular intervals and watch its changing output

Execute {cmd} at periods of {n} seconds, watching its output [^][23]
```sh
watch cmd -n n
```
Display a dashboard that will run {cmd} every second, displaying the output
```sh
watch -n 1 cmd
watch -n 0.5 iptables -vnL # Update twice a second, producing a dashboard
```
### `whatis`
Look up one or more commands in the online manpages and display a brief description
```sh
whatis commands
```
### `xinetd`
Configuration file  | Description
:---                | :---
/etc/xinet.d/       | config files
/etc/xinetd.conf    | master xinetd configuration
/etc/cmd.allow      | specify who is allowed to run a command
/etc/cmd.deny       | specify who is disallowed from running a command

## Tasks
### Samba
Install and configure Samba server [^][40]
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
Configure Samba config file at [/etc/samba/smb.conf][/etc/samba/smb.conf]
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
Restart Samba service [^][40][^][41]
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
### Bash scripting
Validating arguments [[PGL](../sources/pgl.md): 548]
```sh 
if [ $# != 2 ]
then 
  echo "..."
  exit 1
fi
```
[^][7]
```sh
[ -z "$1" ] && echo "..." && exit 1
```
[^][8]
```sh
if [ ! -z "$2" ] ; then ...; fi
```
Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate [^][23]
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
## 

[4]: https://www.tecmint.com/rdesktop-connect-windows-desktop-from-linux/ "TecMint: \"rdesktop - A RDP Client to Connect Windows Desktop from Linux\""
[7]: https://youtu.be/ksAfmJfdub0 "YouTube: \"Easy Academic References on the Command Line\""
[8]: https://coderwall.com/p/kq9ghg/yakuake-scripting "coderwall.com: \"Yakuake scripting\""
[19]: https://opensource.com/article/19/8/introduction-bpftrace "opensource.com: \"An introduction to bpftrace for Linux\""
[21]: https://vitux.com/how-to-convert-documents-to-pdf-format-on-the-ubuntu-command-line/ "vitux.com: \"How to convert documents to PDF format on the Ubuntu Command Line\""
[23]: ../sources/clkf.md "Cannon, Jason. _Command Line Kung Fu_."
[29]: https://www.ostechnix.com/the-mktemp-command-tutorial-with-examples-for-beginners/ "The mktemp Command Tutorial With examples"
[31]: https://www.ostechnix.com/how-to-view-image-metadata-on-linux/ "ostechnix.com: \"How to view image metadata\""
[33]: https://www.networkworld.com/article/3433865/how-to-rename-a-group-of-files-on-linux.html#tk.rss_linux "networkworld.com: \"How to rename a group of files on Linux\""
[36]: https://www.networkworld.com/article/3435279/unix-as-a-second-language-the-touch-command.html#tk.rss_linux "networkworld.com: \"Unix as a Second Language: The touch command\""
[39]: https://www.howtoforge.com/how-to-install-and-use-sosreport-on-ubuntu-1804/ "howtoforge.com: \"How to install and use sosreport on Ubuntu\""
[40]: https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/ "vitux.com: \"How to Install and Configure Samba on Ubuntu\""
[41]: https://www.tecmint.com/install-samba-on-rhel-8-for-file-sharing-on-windows/ "tecmint.com: \"Install Samba4 on RHEL 8 for File Sharing on Windows\""
[42]: https://www.2daygeek.com/check-find-recently-modified-files-folders-linux/ "2daygeek: \"How to find recently modified files/folders in Linux\""
[46]: https://www.tecmint.com/linux-tree-command-examples/ "tecmint.com: \"Linux tree command usage examples for beginners\""
[50]: https://devconnected.com/user-administration-complete-guide-on-linux/#Setting_an_account_expiration_date_easily "devconnected.com: \"User administration complete guide on Linux\""
[56]: https://www.redhat.com/sysadmin/raid-intro "redhat.com: \"RAID for those who avoid it\""
[59]: https://docs.fedoraproject.org/en-US/quick-docs/adding-new-fonts-fedora/ "Fedora Docs - Adding new fonts in Fedora"

[https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]: https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/ "Computing for Geeks: \"How to connect to Bluetooth device from Linux terminal\""
[http://www.linux-magazine.com/Issues/2017/197/Command-Line-bluetoothctl#article_i1]: http://www.linux-magazine.com/Issues/2017/197/Command-Line-bluetoothctl#article_i1 "Linux Magazine: \"Blue Control\""

[aclocal]:                                           autotools.md#aclocal                                           '```&#10;aclocal&#10;```&#10;Place m4 macro definitions needed by `autoconf` into a single file. `aclocal` first scans for macro definitions in m4 files in its default directory (/usr/share/aclocal) and in the file acinclude.m4, then in the configure.ac file. IT generates an aclocal.m4 file that contains definitions of all m4 macros required by `autoconf`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[adduser]:                                           #adduser                                           '```&#10;adduser&#10;```&#10;Create a new user or update default new user information'
[alsamixer]:                                         audio.md#alsamixer                                 '```&#10;$ alsamixer&#10;```&#10;Command-line mixer'
[amixer]:                                            audio.md#amixer                                                '```&#10;$ amixer&#10;```&#10;Command-line mixer for ALSA sound card driver'
[ansible]:                                           ../../devops/ansible.md#ansible                    '```&#10;$ ansible&#10;```&#10;Agentless configuration management and automation tool using YAML templates, developed by Red Hat'
[ansible-galaxy]:                                    ../../devops/ansible.md#ansible-galaxy             '```&#10;$ ansible-galaxy&#10;```&#10;Command-line interface to public gallery of reusable roles for use in Ansible'
[ansible-playbook]:                                  ../../devops/ansible.md#ansible-playbook           '```&#10;$ ansible-playbook&#10;```&#10;Execute Ansible playbooks'
[ar]:                                                archive.md#ar                                                  '```&#10;ar&#10;```&#10;Maintain a group of files that are combined into a file archive. Used most commonly to create and update library files as used by `ld`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[as]:                                                autotools.md#as                                                '```&#10;as&#10;```&#10;Generate an object file from each specified assembly language source file. Primarily intended to assemble the output of the GNU C compiler `gcc` for use by the linker `ld`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 18'
[autoconf]:                                          autotools.md#autoconf                                          '```&#10;autoconf&#10;```&#10;Generate a configuration script from m4 macros defined in a template file, if given, or in a configure.ac or configure.in file in the CWD. The generated script is almost invariably called "configure".&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoheader]:                                        autotools.md#autoheader                                        '```&#10;autoheader&#10;```&#10;Generate a template file of C `#define` statements from m4 macros defined in a template file, if specified, or in configure.ac or configure.in in the CWD. The generated template file is almost invariably called config.h.in or config.hin&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 22'
[automake]:                                          autotools.md#automake                                          '```&#10;automake&#10;```&#10;Create GNU standards-compliant Makefile.in files from Makefile.am template files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 23'
[autoreconf]:                                        autotools.md#autoreconf                                        '```&#10;autoreconf&#10;```&#10;Update configure scripts by running `autoconf`, `autoheader`, `aclocal`, `automake`, and `libtoolize` as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoscan]:                                          autotools.md#autoscan                                          '```&#10;autoscan&#10;```&#10;Create or maintain a preliminary configure.ac file named configure.scan based on source files in specified directory or CWD.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoupdate]:                                        autotools.md#autoupdate                                        '```&#10;autoupdate&#10;```&#10;Update the configure template file or configure.ac if none is specified&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[bc]:                                                #bc                                                            '```&#10;$ bc&#10;```&#10;An arbitrary precision calculator language&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 26'
[biff]:                                              #biff                                                          '```&#10;$ biff&#10;```&#10;Turn mail notifications on or off. With no arguments, `biff` indicates the current status&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 27'
[bison]:                                             #bison                                                         '```&#10;$ bison&#10;```&#10;Convert specified "file.y" containing a context-free grammar into tables for subsequent parsing while sending output to a new file named "file.c". Largely compatible with `yacc`, from which it derives its name.&#10;Originated as an adaptation of Bob Corbett\'s reimplementation of yacc which was distributed under the Berkeley license. Now maintained as a project of the FSF under a GPL license.'
[bluetoothctl]:                                      #bluetoothctl                                                  '```&#10;$ bluetoothctl&#10;```&#10;Canonical implementation of Bluetooth on Linux'
[bmon]:                                              network.md#bmon                                    '```&#10;$ bmon&#10;```&#10;Terminal-based graphical bandwidth monitor'
[bpftrace]:                                          #bpftrace                                          '```&#10;$ bpftrace&#10;```&#10;New open-source tracer for analyzing production performance problems and troubleshooting software&#10;"An introduction to `bpftrace` for Linux." opensource.com'
[bzip2]:                                             archive.md#bzip2                                               '```&#10;$ bzip2&#10;```&#10;Compress or decompress archives using the Burrows-Wheeler block-sorting text-compression algorithm.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[cancel]:                                            #cancel                                                        '```&#10;$ cancel&#10;```&#10;Remove a print job that is in the queue&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 431'
[compress]:                                          #compress                                          '```&#10;$ compress&#10;```&#10;Compress and expand data&#10;&#10;Compress reduces the size of the named files using adaptive Lempel-Ziv coding. Whenever possible, each file is replaced by one with the extension .Z, while keeping the same ownership modes, access and modification times. If no files are specified, the standard input is compressed to the standard output. Compress will only attempt to compress regular files. In particular, it will ignore symbolic links. If a file has multiple hard links, compress will refuse to compress it unless the -f flag is given.'
[cpio]:                                              archive.md#cpio                                                '```&#10;$ cpio&#10;```&#10;Backup utility that uses options similar to `tar`&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 491-492'
[CUPS]:                                              #                                                              'Common Unix Printing System (CUPS)&#10;Most common printing system used on Linux computers today&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 428'
[cupsaccept]:                                        #cupsaccept                                                    '```&#10;$ cupsaccept&#10;```&#10;Enable spooling for specified printer&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 429'
[cupsreject]:                                        #cupsreject                                                    '```&#10;$ cupsreject&#10;```&#10;Disable spooling for specified printer&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 429'
[cupsenable]:                                        #cupsenable                                                    '```&#10;$ cupsenable&#10;```&#10;Enable printing from the specified printer&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 429'
[cupsdisable]:                                       #cupsdisable                                                   '```&#10;$ cupsdisable&#10;```&#10;Disable printing from the specified printer&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 429'
[depmod]:                                            #                                                              '```&#10;$ depmod&#10;```&#10;Builds the modules.dep file, which contains module dependencies and is used by `modprobe` to determine which modules need to be loaded&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 15'
[dmidecode]:                                         #dmidecode                                                     '```&#10;$ dmidecode&#10;```&#10;Display a description of hardware components&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 324'
[dnf]:                                               package.md#dnf                                                 '```&#10;$ dnf&#10;```"Dandified YUM", successor to `yum` as a package manager for RPM-based Linux distributions like Fedora.'
[dpkg]:                                              package.md#dpkg                                    '```&#10;$ dpkg&#10;```&#10;Manage local Debian packages'
[dracut]:                                            #                                                              '`dracut`&#10;Executed by `mkinitrd` but rarely used manually&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 8'
[ethtool]:                                           #                                                              '`ethtool`&#10;Display and configure network device settings.'
[fs-cache]:                                          #fs-cache                                          '```&#10;$ fs-cache&#10;```&#10;Update the font cache'
[free]:                                              #free                                              '```&#10;$ free&#10;```&#10;Display amount of free and used memory in the system&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[ftp]:                                               #                                                              'Transfer files to and from a remote network site'
[glances]:                                           benchmarking.md#glances                            '```&#10;$ glances&#10;```&#10;Cross-platform monitoring tool, written in Python'
[groupadd]:                                          #groupadd                                          '```&#10;$ groupadd&#10;```&#10;Create a new group&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[gzip]:                                              #archive.md#gzip                                               '`gzip`&#10;Compress or decompress archives using the Lempel-Ziv coding method&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 269'
[hostnamectl]:                                       #hostnamectl                                       '```&#10;$ hostnamectl&#10;```&#10;Control the system hostname&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[hping3]:                                            network.md#hping3                                  '```&#10;$ hping3&#10;```&#10;Active network smashing tool'
[hwclock]:                                           #hwclock                                           '```&#10;$ hwclock&#10;```&#10;Access the BIOS clock&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[ifconfig]:                                          network.md#ifconfig                                '```&#10;$ ifconfig&#10;```&#10;Obsolete program that configures network interfaces'
[iftop]:                                             #                                                              '`iftop`&#10;Display network connections using the most bandwidth&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 281'
[install]:                                           file.md#install                                    '```&#10;$ install&#10;```&#10;Copy files while maintaining metadata'
[iostat]:                                            benchmarking.md#iostat                                         '`iostat`&#10;Display input/output statistics on devices, including partitions&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 48&#10;---&#10;Measure the flow of information to and from disk devices&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 637'
[ip]:                                                network.md#ip                                                '```&#10;ip&#10;```&#10;Newer alternative to the old `ifconfig`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[iperf]:                                             #                                                              '`iperf`&#10;Create tests of the throughput between two systems, requiring setup on both client and server&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 281'
[ipset]:                                             #                                                              '`ipset`&#10;Create a "set" of IP addresses to which firewall rules can be applied&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 282'
[iw]:                                                network.md#iw                                      '```&#10;$ iw&#10;```&#10;Show or manipulate wireless devices and their configuration'
[iwlist]:                                            network.md#iwlist                                  '```&#10;$ iwlist&#10;```&#10;Get detailed wireless information about a wireless interface'
[journalctl]:                                        #journalctl                                        '```&#10;$ journalctl&#10;```&#10;Query the systemd journal&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[kinit]:                                             #                                                              '`kinit`&#10;Kerberos utility to obtain an individual ticket, which is then cached on the local system.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 239'
[klist]:                                             #                                                              '`klist`&#10;Display a list of cached Kerberos tickets&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 239'
[lex]:                                               #lex                                                           '```&#10;$ lex&#10;```&#10;Generate a lexical analysis program based on the regular expressions and C statements contained in one or more input files&#10;Lexical analyzer generator written by Eric Schmidt'
[localectl]:                                         #localectl                                         '```&#10;localectl&#10;```&#10;Control the system locale and keyboard layout settings&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[logger]:                                            #logger                                            '```&#10;$ logger&#10;```&#10;Create a one-time file entry specified by the user'
[logrotate]:                                         #logrotate                                                     '`logrotate`&#10;Rename ("rotate") log files on a cyclic basis using /etc/logrotate.conf to determine behavior&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 445-447&#10;---&#10;Utility designed to ensure the partition that holds log files has enough room to handle them by rotating log files, reducing the space they use, typically configured to run automatically as a cron job&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 250-252'
[loginctl]:                                          systemd.md#loginctl                                '```&#10;$ loginctl&#10;```&#10;Control the systemd login manager'
[lp]:                                                #lp                                                '`lp`&#10;Send a print job to a printer&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 428'
[LPD]:                                               #                                                  'Line Printer Daemon (LPD)&#10;Older Linux printing system&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 432'
[lpc]:                                               #lpc                                               '`lpc`&#10;View status of printers&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 432'
[lpq]:                                               #lpq                                               '`lpq`&#10;View print jobs in the print queue&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 432'
[lpr]:                                               #lpr                                               '`lpr`&#10;Print documents to the print queue&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 432'
[lprm]:                                              #lprm                                              '`lprm`&#10;Remove print jobs&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 432'
[lscpu]:                                             benchmarking.md#lscpu                              '```&#10;$ lscpu&#10;```&#10;Display CPU architecture'
[lshw]:                                              #lshw                                              '`lshw`&#10;Display detailed information on system hardware&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 325'
[lsof]:                                              file.md#lsof                                       '```&#10;lsof&#10;```&#10;Display open files, open network ports, and network connections&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[mkinitrd]:                                          #                                                  '`mkinitrd`&#10;Creates initramfs file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 8'
[mpstat]:                                            benchmarking.md#mpstat                             '`mpstat`&#10;Report processor-related statistics&#10;---&#10;Utility for monitoring CPU performance&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 635-637'
[netstat]:                                           #netstat                                           '```&#10;$ netstat&#10;```&#10;Print network connections, routing tables, interface statistics, masquerade connections, and multi-cast memberships'
[nproc]:                                             benchmarking.md#nproc                              '```&#10;$ nproc&#10;```&#10;Display number of CPU processors or cores'
[ntsysv]:                                            #ntsysv                                            '```&#10;$ ntsysv&#10;```&#10;TUI utility used to modify appropriate runtime configuration files so that they start and stop daemons when entering a particular runlevel&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 367'
[rfkill]:                                            network.md#rfkill                                  '```&#10;$ rfkill&#10;```&#10;Tool for enabling and disabling wireless devices'
[rpm]:                                               rpm.md#rpm                                         '`rpm`&#10;RPM package manager'
[sar]:                                               benchmarking.md#sar                                '`sar`&#10;"system activity reporter", the most widely used performance monitoring tool on Linux&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 637-641'
[semanage]:                                          selinux.md#semanage                                '```&#10;$ semanage&#10;```&#10;Edit security contexts for files and ports'
[sestatus]:                                          selinux.md#sestatus                                '```&#10;sestatus&#10;```&#10;Display status of SELinux&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[setenforce]:                                        selinux.md#setenforce                              '```&#10;setenforce&#10;```&#10;Change SELinux mode&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.'
[speaker-test]:                                      audio.md#speaker-test                              '```&#10;$ speaker-test&#10;```&#10;Generates a tone that can be used to test the speakers of a computer'
[stat]:                                              #stat                                              '```&#10;$ stat&#10;```&#10;Display file or file system status'
[systemctl]:                                         systemd.md#systemctl                               '```&#10;$ systemctl&#10;```&#10;Control the systemd system and service manager'
[systemd-delta]:                                     systemd.md#systemd-delta                           '```&#10;$ systemd-delta&#10;```&#10;Find overridden configuration files'
[tar]:                                               archive.md#tar                                     '```&#10;$ tar&#10;```&#10;Saves many files together into a single tape or disk archive, and can restore individual files from the archive'
[tcpdump]:                                           #tcpdump                                           '```&#10;$ tcpdump&#10;```&#10;Inspect IP packets (Wireshark is a GUI-based alternative)'
[timedatectl]:                                       systemd.md#timedatectl                             '```&#10;$ timedatectl&#10;```&#10;Control the system time and date'
[tree]:                                              file.md#tree                                       '```&#10;$ tree&#10;```&#10;Display contents of directories in a tree-like format'
[tshark]:                                            #                                                  '`tshark`&#10;Wireshark terminal interface&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 283'
[virt-install]:                                      virt.md#virt-install                               '`virt-install`&#10;Command-line tool for creating new KVM, Xen, or Linux container guests using the libvirt hypervisor management library'
[virt-manager]:                                      virt.md#virt-manager                               '`virt-manager`&#10;"Virtual Machine Manager", GUI tool for managing VMs developed by Red Hat'
[vmstat]:                                            benchmarking.md#vmstat                             '`vmstat`&#10;Provides more detail than `free`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 642'
[w]:                                                 #                                                  '```&#10;$ w&#10;```&#10;Display output similar to that of `uptime` for all logged-in users'
[xgettext]:                                          #xgettext                                          '```&#10;$ xgettext&#10;```&#10;Extract specially marked strings from C and C++ source files, placing them in a .po ("portable object" file for translation and compilation by `msgfmt`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 234'
[xinetd]:                                            #xinetd                                            '```&#10;$ xinetd&#10;```&#10;Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.'
[xlsclients]:                                        X.md#xlsclients                                    '```&#10;$ xlsclients&#10;```&#10;Determine what applications are running on the legacy X11 server provided with Wayland'
[xz]:                                                #                                                  '```&#10;$ xz&#10;```&#10;Compress or decompress archives using the LZMA and LZMA2 compression methods.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[yacc]:                                              #yacc                                              '```&#10;$ yacc&#10;```&#10;"yet another compiler-compiler", parser generator that converts a file containing a context-free LALR grmamar and converts it to tables for subsequent pasring, sending output to y.tab.c. Written between 1975 and 1978 by Stephen C. Johnson at Bell Labs.'
[yumdownloader]:                                     #                                                  '```&#10;$ yumdownloader&#10;```&#10;Download software packages without installing them&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 84'
[zypper]:                                            #                                                  '```&#10;$ zypper&#10;```&#10;Package manager for SUSE with a syntax similar to that of `yum`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'

[/etc/samba/smb.conf]:                               #                                                              "Samba configuration file"

