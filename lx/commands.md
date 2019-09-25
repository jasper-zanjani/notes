# Linux Commands
#### Contents

Topic | Commands
:---  | :---
Filters 
Hardware settings | [`insmod`](#insmod) [ `lsmod` ](#lsmod) [ `lspci` ](#lspci) [ `lsusb` ](#lsusb) [ `modprobe` ](#modprobe) [`rmmod`](#rmmod)
Logical volumes
Manjaro           | [`mhwd`](#mhwd) [`mhwd-chroot`](#mhwd-chroot)
Package managers
Systemd


\#  | Commands sorted alphabetically
:---| :---
A   | [adduser](#adduser) [add-apt-repository](#add-apt-repository) [alsamixer](#alsamixer) [apropos](#apropos) [apt](#apt) [apt-cache](#apt-cache) [apt-key](#apt-key) [at](#at) [ausearch](#ausearch) [awk](#awk) 
B   | [bash](#bash) [blkid](#blkid) [bpftrace](#bpftrace) [bzcat](#bzcat) [bzip2](#bzip2) [bzless](#bzless) [bzmore](#bzmore) 
C   | [cancel](#cancel) [cat](#cat) [chage](#chage) [chcon](#chcon) [chgrp](#chgrp) [chkconfig](#sysvinit) [chmod](#chmod) [chown](#chown) [chpass](#chpass) [chsh](#chsh) [column](#column) [compress](#compress) [cp](#cp) [crontab](#crontab) [crossystem](#crossystem) [cryptsetup](#cryptsetup) [curl](#curl) [cut](#cut) 
D   | [dar](#dar) [date](#date) [dbus](#dbus) [dd](#dd) [declare](#declare) [df](#df) [dhclient](#dhclient) [diff](#diff) [dig](#dig) [dirname](#dirname) [dm-crypt](#dm-crypt) [dmesg](#dmesg) [doveadm](#doveadm) [dpkg](#dpkg) [dpkg-reconfigure](#dpkg-reconfigure) [du](#du) [dumpe2fs](#dumpe2fs) 
E   | [e2image](#e2image) [e2label](#e2label) [edquota](#edquota) [elvis](#elvis) [elvish](#elvish) [espeak](#espeak) [exif](#exif) 
F   | [fam](#fam) [fdisk](#fdisk) [file](#file) [find](#find) [firewall-cmd](#firewall-cmd) [firewalld](#firewalld) [fish](#fish) [fmt](#fmt) [fold](#fold) [free](#free) [fsck](#fsck) [fstrim](#fstrim) [ftp](#ftp) [fusermount](#fusermount) 
G   | [gconf-editor](#gconf-editor) [gdisk](#gdisk) [gdmsetup](#gdmsetup) [gem](#gem) [getfacl](#getfacl) [git](#git) [gpasswd](#gpasswd) [gpg](#gpg) [grep](#grep) [groupadd](#groupadd) [groupdel](#groupdel) [groupmod](#groupmod) [grub](#grub) [gzip](#gzip) 
H   | [hdiutil](#hdiutil) [hdparm](#hdparm) [head](#head) [history](#history) [host](#host) [hostname](#hostname) [hostnamectl](#hostnamectl) [hwclock](#hwclock) 
I   | [iconv](#iconv) [ifconfig](#ifconfig) [imagemagick](#imagemagick) [init](#sysvinit) [initctl](#initctl) [insmod](#insmod) [install](#install) [ip](#ip) [iptables](#iptables) [iscsiadm](#iscsiadm) [iwlist](#iwlist) 
J   | [journalctl](#journalctl) 
K   | [kill](#kill) 
L   | [last](#last) [ldapadd](#ldapadd) [ldconfig](#ldconfig) [ldd](#ldd) [less](#less) [let](#let) [link](#link) [locale](#locale) [localectl](#localectl) [logout](#logout) [lp](#lp) [lpadmin](#lpadmin) [lpstat](#lpstat) [ls](#ls) [lsblk](#lsblk) [lsmod](#lsmod) [lsof](#lsof) [lspci](#lspci) [lsusb](#lsusb) [lvcreate](#lvcreate) [lvdisplay](#lvdisplay) [lvremove](#lvremove) [lvresize](#lvresize) 
M   | [mail](#mail) [mailq](#mailq) [mailstats](#mailstats) [make](#make) [makemap](#makemap) [mdadm](#mdadm) [mhwd](#mhwd) [mhwd-chroot](#mhwd-chroot) [mkdir](#mkdir) [mke2fs](#mke2fs) [mkfontscale](#mkfontscale) [mkfs](#mkfs) [mkswap](#mkswap) [mktemp](#mktemp) [modinfo](#modinfo) [modprobe](#modprobe) [mongod](#mongod) [mount](#mount) [mt](#mt) 
N   | [nc](#nc) [netplan](#netplan) [netstat](#netstat) [NetworkManager](#NetworkManager) [newaliases](#newaliases) [nice](#nice) [nl](#nl) [nmap](#nmap) [nmblookup](#nmblookup) [nmcli](#nmcli) [nohup](#nohup) [nslookup](#nslookup) [ntpdate](#ntpdate) 
O   | [openssl](#openssl) 
P   | [pacman](#pacman) [partx](#partx) [paste](#paste) [passwd](#passwd) [paste](#paste) [patch](#patch) [ping](#ping) [pip](#pip) [postfix](#postfix) [postqueue](#postqueue) [postsuper](#postsuper) [ps](#ps) [pvcreate](#pvcreate) [pvdisplay](#pvdisplay) [pvremove](#pvremove) [pydoc](#pydoc) 
Q   | [qmail](#qmail) [quota](#quota) [quotacheck](#quotacheck) [quotaoff](#quotaoff) [quotaon](#quotaon) 
R   | [read](#read) [rename](#rename) [repquota](#repquota) [resize2fs](#resize2fs) [resize4fs](#resize4fs) [restorecon](#restorecon) [rmmod](#rmmod) [route](#route) [rpm](#rpm) [rsync](#rsync) [runlevel](#runlevel) 
S   | [samba](#samba) [sc](#sc) [sed](#sed) [semanage](#selinux) [sendmail](#sendmail) [seq](#seq) [service](#sysvinit) [sestatus](#sestatus) [setenforce](#selinux) [setfacl](#setfacl) [sfdisk](#sfdisk) [shred](#shred) [shuf](#shuf) [shutdown](#shutdown) [slapadd](#slapadd)  [sleep](#sleep) [snap](#snap) [sort](#sort) [sosreport](#sosreport) [source](#source) [speaker-test](#speaker-test) [ss](#ss) [ssh](#ssh) [ssh-copy-id](#ssh-copy-id) [ssh-keygen](#ssh-keygen) [ssh-keyscan](#ssh-keyscan) [sshfs](#sshfs) [ssmtp](#ssmtp) [startx](#startx) [stty](#stty) [su](#su) [sudo](#sudo) [swapoff](#swapoff) [swapon](#swapon) [sysctl](#sysctl) [syslog](#syslog) [sysvinit](#sysvinit) [systemctl](#systemctl) [systemd-delta](#systemd-delta) 
T   | [tail](#tail) [tar](#tar) [tcpdump](#tcpdump) [telinit](#telinit) [test](#test) [tig](#tig) [timedatectl](#timedatectl) [tmux](#tmux) [touch](#touch) [top](#top) [tput](#tput) [tr](#tr) [tracepath](#tracepath) [traceroute](#traceroute) [tune2fs](#tune2fs) [tzselect](#tzselect) 
U   | [udevadm](#udevadm) [umount](#umount) [uname](#uname) [uncompress](#uncompress) [unzip](#unzip) [update-grub](#update-grub) [update-rc.d](#update-rc.d) [useradd](#useradd) [userdel](#userdel) [usermod](#usermod) 
V   | [variable](#variable) [vgcreate](#vgcreate) [vgdisplay](#vgdisplay) [vgextend](#vgextend) [vgremove](#vgremove) [vgscan](#vgscan) [vifs](#vifs) [visudo](#visudo) 
W   | [wall](#wall) [watch](#watch) [wc](#wc) [whatis](#whatis) 
X   | [X](#X) [xdpyinfo](#xdpyinfo) [xhost](#xhost) [xinetd](#xinetd) [Xorg](#Xorg) [xrandr](#xrandr) [xwininfo](#xwininfo) 
Y   | [yay](#yay) [yum](#yum) 
Z   | [zip](#zip) [zipcloak](#zipcloak) [zipdetails](#zipdetails) [zipgrep](#zipgrep) [zipinfo](#zipinfo) [zipnote](#zipnote) [zipsplit](#zipsplit) [zsh](#zsh)
### bash
#### bash variables
Syntax                                              | Effect
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
### bzcat
Page through bz2 files
### bzless
Page through bz2 files
### bzmore
Page through bz2 files
### bzip2
#### bzip2 options
Option  | POSIX option            | Effect
:---    | :---                    | :---
c       | stdout                  | compress or decompress to standard output
d       | decompress              | force decompression
z       | compress                | force compression
f       | force                   | force overwrite of output files
#### Display contents of {archive} to stdout
```sh
bzip2 -c archive
bzip2 --stdout archive
```
#### Decompress {archive}
```sh
bzip2 -d archive
bzip2 --decompress archive
```
#### Compress {symlink}
```sh
bzip2 -f symlink
bzip2 --force symlink
```
### compress
#### Display contents of the compressed file to stdout (same as using `zcat`)
```sh
compress -c
```
#### Compress symbolic links
```sh
compress -f
```
#### Compress files recursively within a specified directory
```sh
compress -r
```
### dar
#### Create a differential (or incremental) backup of {file}, using full.bak as reference
```sh
dar -R /path/to/file -c diff1.bak -A full.bak
```
#### Create a full backup of {file}
```sh
dar -R /path/to/file -c full.bak
```
#### Restore full.bak
```sh
dar -x full.bak
```
### gzip
Zip a single file in-place; each file is replaced by one with the extension `.gz` or `.z`, maintaining ownership modes, access and modification times
#### gzip options
Option  | POSIX option            | Effect
:---    | :---                    | :---
1       | fast                    
9       | best      
c       | stdout, to-stdout       | output will go to STDOUT, leaving files intact
d       | decompress, uncompress 
f       | force                   | overwrite preexisting files
S       | suffix                  | change default suffix (.gz)
#### Compress {file} at compression ratio {#}, ranging from 1 to 9 (6 by default)
```sh
gzip -#
gzip --fast
gzip --best
```
#### Display contents of {archive} to stdout
```sh
gzip -c archive
gzip --stdout -to-stdout archive
```
#### Decompress {archive}
```sh
gzip -d archive
gzip --decompress archive
```
#### Compress {symlink}
```sh
gzip -f symlink
gzip --force symlink
```
#### Do not preserve original modification and access time for files
```sh
gzip -n
gzip --no-name
```
#### Specify extension {.ext} instead of default ".gz" while compressing {file}
```sh
gzip -S .ext file
gzip --suffix .ext file
```
### zcat
Page through .gz files
### tar
#### tar options
Option  | POSIX option            | Effect
:---    | :---                    | :---
c       | create                  | create a new archive
f       | file                    | use file or device
j       | bzip2                   | filter the archive through [`bzip2`](#bzip2
p       | preserve-permissions    | extract information about file perfmissions
r       | append                  | append files to the end of an archive
t       | list                    | list the contents of an archive
x       | extract, get            | extract files from an archive
z       | gzip                    | filter the archive through [`gzip`](#gzip)

#### Change directory `dir` before adding `files` to the tar archive, using relative pathnames; makes it possible to archive files that don't share a common ancestor directory
```sh
tar -C path files tar --directory=path files
```
#### Create {archive} from contents of {path}
```sh
tar -cf archive path
tar --create --file archive path
```
#### Create bzip2-compressed {archive} from contents of {path}
```sh
tar -cfj archive path
tar --create --file --bzip archive path
```
#### Create gzip-compressed {archive} from contents of {path}
```sh
tar -cfz archive path
tar --create --file --gzip archive path
```
#### Preserve permissions
```sh
tar -p
```
#### Add {file} to {archive}
```sh
tar -rf archive file
tar --append --file archive file
```
#### Read a list of filenames to be archived, one filename per line, from file
```sh
tar -T file
tar --files-from=file
```
#### List the contents of {archive}
```sh
tar -tf archive
tar --list --file archive
```
#### Extract contents of {tarfile} in the current directory
```sh
tar -xf archive
tar --extract --file archive
```
#### Extract only {file} from {archive}
```sh
tar -xf archive file tar--extract --file archive file
```
#### Extract contents of gzip-compressed {archive} to {path}
```sh
tar -xzf archive -C path
```
### uncompress
#### Overwrite existing files without prompting, if they exist
```sh
uncompress  -f
```
#### Decompress files recursively
```sh
uncompress -r
```
### unzip
Extract compressed files in a zip archive
### zip
#### Archive files in InfoZIP format
```sh
zip zipfile *files
```
### zipcloak
#### Encrypt a zip {archive}
```sh
zipcloak archive
```
### zipdetails
#### Produce a detailed list of information about a zip {archive}
```sh
zipdetails archive
```
### zipgrep
#### Search for {string} within all files of a zip {archive}
```sh
zipgrep string archive
```
### zipinfo
#### Print information about ZIP format archives
```sh
zipinfo *zipfiles
```
### zipnote
#### Annotate a zip {archive} by creating a {comments} file, which can then be edited and rewritten with `-w` flag
```sh
zipnote archive > comments
```
### zipsplit
#### Split `zipfile` into segments of size `size`
```sh
zipsplit -n size zipfile
```
### bpftrace
New open-source tracer for analyzing production performance problems and troubleshooting software [[19](README.md#sources)]
### chown
#### Change a file or directory's ownership
To change the user and group owner of a file to {user} and {group}, `chown`'s syntax is of the format `user:group` [[32](README.md#sources)].
```sh
chown susan:delta file          # Assign {file} to user `susan` and group `delta`
chown alan file                 # Assign {file} to user `alan`
chown alan: file                # Assign {file} to user and group `alan`
chown :gamma file               # Assign {file} to the group `gamma`
```
#### Recursively grant {user} ownership to {path}
```sh
chown -R user path
```
Assign {path} to `susan` and group `delta`, recursively and with verbose output
```sh
chown --verbose --recursive susan:delta path 
chown -vR susan:delta path
```
```sh
chown -vR --reference=. path    # Use a `reference` file to match the configuration of a particular file
chown -cfR --preserve-root alan # `preserve-root` prevents changes to files in the root directory, but has no effect when not used with `recursive`
```
### exif
#### View image metadata
Unlike alternatives like `file` and ImageMagick's `identify`, `exif` produces columnar output [[31](README.md#sources)]
```sh
exif image.png 
```
### file
#### View image metadata
[[31](README.md#sources)]
```sh
file image.png # => file type, dimensions, color depth
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
[[23](README.md#sources)]
```sh
fusermount -u mountpoint
```
### grep
#### grep options
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
#### history options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    |                         | clear history [[23](README.md#sources)]
### hostnamectl
#### Permanently change hostname to {$HOSTNAME}
```sh
hostnamectl set-hostname hostname
```
### install
With `install`, files can be copied while maintaining various metadata, including timestamp, owner, etc. [[9](README.md#sources)]
#### Copy a file while preserving timestamp
The copy will have the `install` default of `755`, but the original's `mtime` is maintained:
```sh
install --preserve-timestamp example/foo .
```
#### Copy a file, setting permissions, owner, and group
```sh
install --preserve-timestamp --owner=jdoe --group=sudoers --mode=753
```
### iptables
A popular firewall, like `firewalld`, a frontend for the kernel-level `netfilters` service. Interface configuration, used to assign a TCP/IP configuration to a network interface, but no longer installed on modern distros.
#### iptables config
Config files  | Description
:---          | :---
/etc/sysconfig/iptables | location of saved config
#### Display rules as written on disk
```sh
iptables --list-rules
```
#### Accept SSH traffic from a particular IP
```sh
iptables -A INPUT -p ssh -s 10.0.222.222 -j ACCEPT
```
#### Accept incoming TCP traffic to port 80
```sh
iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```
#### Reload configuration file
```sh
iptables -F
```
#### Show statistics for configuration lines
```sh
iptables -vnL --lines
```
#### Display rules as written on disk
```sh
iptables --list-rules
```
#### Set an iptable rule to accept SSH traffic from a particular IP
```sh
iptables -A INPUT -p ssh -s 10.0.222.222 -j ACCEPT
```
#### Set an iptable rule to accept incoming TCP traffic to port 80
```sh
iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```
#### Reload configuration file
```sh
iptables -F
```
#### Show statistics for configuration lines
```sh
iptables -vnL --lines
```
### iptables-save
Display what the running configuration would look like if written to disk (must be redirected to a file)
#### Display what the running configuration would look like if written to disk 
Must be redirected to a file
```sh
iptables-save > $FILE
```
### lowriter
`lowriter` is a command-line utility installed with LibreOffice Writer.[[21](README.md#sources)]
#### Convert a single file to PDF
```sh
lowriter --convert-to pdf filename.doc
```
#### Convert a batch of files using globbing
```sh
lowriter --convert-to pdf *.docx
```
### localectl
Change locale
#### Change locale to French
```sh
localectl set-locale LANG=fr_FR.utf8
```
### lsof
`lsof` can be used to display open files, open network ports, and network connections; `-P` prevents the conversion of port numbers to port names; `-i` displays network connections; `-n` prevents the conversion of IP addresses to hostnames [[23](README.md#sources)]
#### lsof options
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-i`    | | display network connections
`-n`    | | prevent the conversion of IP addresses to hostnames
`-P`    | | prevent the conversion of port numbers to port names
#### Show open network connections
```sh
sudo lsof -Pni
```
### mail
Mail User Agent (MUA) which accepts interactive input using the `&` prompt
#### Check {user}'s email
```sh
mail -u user
```
#### Send email to {user}
```sh
mail user
```
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
### mktemp
Create a temporary file or directory safely and print its name. These will not need to be manually cleaned up because they will be placed in the temporary directory (**/tmp**) [[29](README.md#sources)]
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
#### Connect to {port} at {host}
```sh
nc host port
```
#### Netcat command that retrieves a webpage
```sh
nc host port \get
```
### netstat
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-a`    | `--all` | display both listening and non-listening sockets
`-c`    | `--continuous` | display selected information every second continuously
`-e`    | `--extend` | display additional information (repeat for maximum detail)
`-g`    | `--groups` | display multicast group membership information for IPv4 and IPv6
`-i`    | `--interfaces` | display a table of all network interfaces
`-l`    | `--listening` | display only listening sockets
`-M`    | `--masquerade` | display masqueraded connections
`-n`    | `--numeric` | display numerical addresses instead of symbolic host, port, or user names
`-o`    | `--timers` | display information related to networking timers
`-p`    | `--program` | display PID and name of program to which each socket belongs
`-r`    | `--route` | display routing tables
`-s`    | `--statistics` | display summary statistics by protocol
#### Show network traffic
```sh
netstat -an
```
#### Refresh every five seconds
```sh
netstat -c5
``` 
#### Show the current default route without performing DNS lookups on the IP addresses involved
```sh
netstat -rn
```
#### Count number of TCP connections 
```
netstat -a | grep tcp - | wc -l
``` 
#### Active sessions 
```
netstat -tp
``` 
#### All sessions
```
netstat -atp
``` 
#### Routing table with name resolution 
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
#### Stop NetworkManager service
```sh
chkconfig NetworkManager off               # Upstart
systemctl disable NetworkManager.service   # Systemd
service NetworkManager stop                # sysvinit
```
### nslookup
Perform a DNS lookup in an interactive shell with cleaner output than __dig__. Enter a domain name and you get output in two sections. 
#### Retrieve IP address of {host}
```sh
nslookup host
```
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
Mail Transfer Agent (MTA) designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". Its various modular subcomponents run independently and are mutually untrustful. It uses SMTP to exchange messages with other MTAs. It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. Deprecated and removed from Arch repos in 2005. [[27](README.md#sources)]
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
#### List installed packages
```sh
pacman -Q
pacman --query
```
#### List all orphaned dependencies (no longer needed)
```sh
pacman -Qdt
pacman --query --deps --unrequired
```
#### List only explicitly installed packages and versions
```sh
pacman -Qe
pacman --query --explicit
```
#### List explicitly installed packages, limiting output to program names
```sh
pacman -Qeq
pacman --query --explicit --quiet
```
#### List all packages installed from the AUR
```sh
pacman -Qm
pacman --query --foreign
```
#### List all packages installed from main repos
```sh
pacman -Qn
pacman --query --native
```
#### Find which package owns {file}
```sh
pacman -Qo file
pacman --query --owns file
```
#### List all install packages, filtering output to packages that are out-of-date on the local system
```sh
pacman -Qu
pacman --query --upgrades
```
#### Remove {package}
```sh
pacman -R package
pacman --remove package
```
#### Remove {package}, dependencies, and config files
```sh
pacman -Rns package
pacman --remove --recursive --nosave
```
#### Remove {package} as well as its dependencies
```sh
pacman -Rs
pacman --remove --recursive
```
#### Install {pkg} from the AUR
```sh
pacman -S package
pacman --sync package
```
#### Remove all packages from the cache as well as unused sync databases
```sh
pacman -Scc
pacman --sync --clean --clean
```
#### Display information about {package}
```sh
pacman -Si package
pacman --sync --info package
```
#### Search for {pkg} in AUR repos
```sh
pacman -Ss package
pacman --sync --search package
```
#### Search for packages matching {searchexpression}
```sh
pacman -Ss pattern
pacman --sync --search pattern
```
#### Update package database
```sh
pacman -Sy
pacman --sync --refresh
```
#### Update all packages from AUR and official repos
```sh
pacman -Syu
pacman --sync --refresh --sysupgrade
```
#### Force refresh of all package databases, even if they appear to be up-to-date
```sh
pacman -Syy
pacman --sync --refresh --refresh
```
#### Download program updates but don't install them
```sh
pacman -Syyuw
pacman --sync --refresh --refresh --sysupgrade --downloadonly
```
#### Get number of total installed packages
```sh
pacman -Q | wc -l
```
### partx
`partx` is a utility that provides information on drive partitions to the Linux kernel. [[12](README.md#sources)]
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
#### Display length in sectors and human-readable size of a partition
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
### rename
`rename` uses regular expressions [[33](README.md#sources)]
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
Script-based partition table editor, similar to [`fdisk`](#fdisk) and [`gdisk`](#gdisk), which can be run interactively. It does not interface with GPT format, neither is it designed for large partitions. [[11](README.md#sources)]
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
[[10](README.md#sources)]
#### Shuffle items separated by newline 
```sh
shuf -n 1 cards.txt
```
[[10](README.md#sources)]
### sort
#### Sort by space-delimited columns
Processes consuming the most memory will be at the bottom [[23](README.md#sources)]
```sh
ps aux | sort -nk 4
```
Processes consuming the most CPU will be at the bottom
```sh
ps aux | sort -nk 3
```
### ssmtp
Installable client program [[25](README.md#sources)]

#### ssmtp config
Configuration file                            | Description
:---                                          | :---
[ /etc/ssmtp/ssmtp.conf ](#etcssmtpssmtpconf) | Configuration file
#### Send {msg} to {recipient} from {user} at {host} using password {pw}
```sh
ssmtp -au recipient -ap pw user@host < msg
```
### sendmail
Mail daemon once the de facto standard for accepting and redirecting mail on Linux distributions, long ago fallen into disuse. It was infamous for its difficulty to set up, with roots in ARPANET itself.
### ssh
#### Compare the differences between a remote and local file
`cat` a file over SSH and pipe the output into a diff or sdiff command [[23](README.md#sources)j]
```sh
ssh remotehost cat /path/to/remotefile | diff /path/to/localfile
```
#### Create an SSH tunnel to access remote resources
Tunnel into a server to access a website which your local machine may not; `-L` creates the SSH tunnel; first port is the port that will be opened on the local machine [[23](README.md#sources)]
```sh
ssh -N -L localport:host:remoteport remotehost
```
### sshfs
#### Mount a directory from a remote server on your local host via SSH
[[23](README.md#sources)]
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
### tig
Provides a curses-based browser that allows you to navigate the commits in the current branch. It is essentially a wrapper around `git log`, and therefore accepts the same arguments that can be passed to it.[[34](README.md#sources)]
#### tig config
Config file   | Description
:---          | :---
$HOME/.tigrc  | 
#### Browse the commit history for a single {file}
```sh
tig file
```
#### Browse the commit history for a single {file}, filtering to a specific date range
```sh
tig --after="2017-01-01" --before="2018-05-16" -- README.md
```
#### Find who made a change toa  file and why
```sh
tig blame file
```
#### Browse stash
```sh
tig stash
```
#### Browse refs
```sh
tig refs
```
#### Navigate the output of `git grep`
```sh
tig grep -i foo lib/Bar
```
#### Pipe a list of commit IDs to tig
```sh
git rev-list --author=olaf HEAD | tig show --stdin
```
### tr
#### Change the case of a string
[[23](README.md#sources)]
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
Execute {cmd} at periods of {n} seconds, watching its output [[23](README.md#sources)]
```sh
watch cmd -n n
```
#### Display a dashboard that will run {cmd} every second, displaying the output
```sh
watch -n 1 cmd
watch -n 0.5 iptables -vnL # Update twice a second, producing a dashboard
```
### xinetd
Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.  
#### xinetd configuration files
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
### yum
Yellow Dog Updater, Modified package manager (Yellow Dog was a variation of Red Hat for PowerPC architectures), package manager more commonly used today. [[35](README.md#sources), [37](README.md#sources)]
#### yum options
Option  | POSIX option            | Effect
:---    | :---                    | :---
y       | assumeyes               | respond to any prompt with "yes" automatically
x       | exclude                 | exclude specific packages from updates [[38](README.md#sources)]
#### Install {package}
```sh
yum install package
yum groupinstall packagegroup # package group
yum --enablerepo=repo install package # from a specific {repo}
```
#### Remove {package} 
```sh
yum remove package
yum -y remove package # without confirmation
yum erase package # as well as the cached package
yum groupremove packagegroup
```
#### Update installed packages
```sh
yum update
yum update package # update a specific {package}
yum upgrade # equivalent to `yum update --obsoletes`
yum groupupdate packagegroup

# Exclude some packages from update
yum update --exclude=kernel
yum update --exclude=httpd,php
```
#### List all available packages in database
```sh
yum list
yum grouplist
```
#### List all installed packages
```sh
yum list installed
```
#### Query repos for information on {package}
```sh
yum info package
```
#### Find packages
```sh
yum list name # name matching {name} exactly
yum search pattern # search for package name matching {pattern}
```
#### Find what package {config} belongs to
```sh
yum provides /path/to/config
```
#### List repositories
```sh
yum repolist
yum repolist all # enabled and disabled repos
```
#### Interactive shell
```sh
yum shell
```
#### Clear cache
```sh
yum clean all
```
#### View command history
```sh
yum history
```
### lvcreate
#### Create a 20 gigabyte logical volume named "Marketing" from volume group {vg1}
```sh
lvcreate -L 20G vg1 -n Marketing
```
#### Create logical volume named {lv1} of size {500G} from volume group {vg1}
```sh
lvcreate-L 500G vg1 -n lv1
```
### lvdisplay
### lvs
View logical volumes
### lvremove
#### Remove logical volume {/dev/vg1/lv1}
```sh
lvremove /dev/vg1/lv1
```
### lvresize
#### Resize existent logical volume {Marketing} in volume group {vg1} to have an additional 10 gigabytes of space
```sh
lvresize -L +10G /dev/vg1/Marketing
```
### pvcreate
#### Create physical volumes from {/dev/sdb} and {/dev/sdc}
```sh
pvcreate /dev/sdb /dev/sdc
```
#### Create physical volumes from {partitions}
```sh
pvcreate*partitions
```
### pvdisplay
#### View physical volumes
```sh
pvdisplay | pvs
```
### pvremove
#### Remove physical volumes {/dev/sdb1}, {/dev/sdc1}, {/dev/sdd1}
```sh
pvremove /dev/sdb1 /dev/sdc1 /dev/sdd1
```
### resize2fs
#### Resize filesystem of logical volume {Marketing} on volume group {vg1} to take up the entire logical volume
```sh
resize2fs /dev/vg1/Marketing
```
### vgcreate
#### Create volume group {vg1} from physical volumes {/dev/sdb} and {/dev/sdc}
```sh
vgcreate vg1 /dev/sdb /dev/sdc
```
#### Create a volume group {vg1} from device {/dev/sdb1}
```sh
vgcreatevg1 /dev/sdb1
```
### vgdisplay
### vgs
View volume groups
### vgextend
#### Add an additional drive {/dev/sdd} to existent volume group {vg1}
```sh
vgextend vg1 /dev/sdd
```
### vgremove
#### Remove volume group {/dev/vg1}
```sh
vgremove /dev/vg1
```
### vgscan
Build the LVM cache file
### adduser
#### Create a new user (on Debian systems, preferred to `useradd`)
```sh
adduser 
```
### alsamixer
Command-line audio mixer
### apropos
#### Look up one or more `keywords` in the online manpages: same as `man -k` (rf. `whatis`)
```sh
apropos keywords
```
### apt
#### Upgrade distribution
```sh
apt dist-upgrade
```
#### Install local {file} as a package
```sh
apt install file
```
#### Install {package}
```sh
apt install package
```
#### Search for packages matching {searchexpression}
```sh
apt list pattern
```
#### Remove {package}
```sh
apt remove package
```
#### Update package database
```sh
apt update
```
#### Upgrade all packages
```sh
apt upgrade
```
### apt-cache
Display package information regarding package cache
#### apt-cache commands
Command   | Description
:---      | :---
search    | display all packages with the search term listed in the package name or description
showpkg   | display information about a package
stats     | display statistics about the package cache
showsrc   | display information about a source package
depends   | display a package's dependencies
rdepends  | display a package's reverse dependencies, i.e. what packages for which this package is a dependency
#### Display basic information about each available package and its dependencies 
```sh
apt-cache dump
```
### apt-key
#### Add a public GPG key to keyring
```sh
curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add - # Google Cloud SDK
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -	# Docker
```
### add-apt-repository
#### Add a repository
```sh
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
```
### at
#### Execute a command at a given time
```sh
echo "cmd" | at time
```
```sh
at -f file time
```
#### List scheduled jobs
```sh
at -l
```
#### Remove scheduled jobs
```sh
at -r
```
#### Execute {cmd} at {time}
```sh
at time
> cmd
```
### ausearch
#### Display audit logs from {startdate} to {enddate}
```sh
ausearch --start startdate--end enddate
```
#### Search audit logs for today for logins of UID 500
```sh
ausearch --start today --loginuid500
```
### blkid
Show UUID, Label, and filesystems of GPT block devices
### chage
Change user password expiry information
#### Remove expiration date from an account
```sh
chage -E -1 user
```
#### Set the date (or number of days since January 1, 1970) on which the user's account will no longer be accessible to {date} (YYYY-MM-DD)
```sh
chage -E days chage --expiredate days
```
#### Set the maximum number of days during which a password is valid
```sh
chage -M days chage --maxdays days
```
#### Set the minimum number of days between password changes
```sh
chage -m days chage --mindays days
```
### chage
#### Set the number of days of warning before a password change is required
```sh
chage -W days chage --warndays days
```
### chcon
#### Change context for website directory
```sh
chcon -Rv --type=httpd_sys_content_t website
```
### chgrp
#### Change ownership of {file} to {user} and {group}
```sh
chgrp user:group
```
### chmod
#### Set sticky bit on {file}
```sh
chmod +t file
```
#### Clear sticky bit on {file}
```sh
chmod -t file
```
#### Clear SGID bit on {file}
```sh
chmod g-s file
```
#### Set SGID bit on {file}
```sh
chmod g+s file
```
#### Clear SUID bit on {file}
```sh
chmod u-s file
```
#### Set SUID bit on {file}
```sh
chmod u+s file
```
#### Set `setuid` permission on {file}
```sh
chmod +s file
```
### chpass
#### Change default shell to Fish
```sh
chpass -s /usr/local/bin/fish
```
### chsh
#### Change the user's default shell to Bash
```sh
chsh-s /bin/bash
```
#### Change the user's default shell to Fish
```sh
chsh-s /usr/local/bin/fish
```
### cp
#### Preserve symlinks in a recursive copy
```sh
cp -a
cp --archive
```
### crontab
#### Remove current crontab, clearing cron jobs for the effective user
```sh
crontab -r
```
#### Specify that {user}'s crontab is to be modified
```sh
crontab -u user
```
### crossystem
Print all parameters with descriptions and current values
### cryptsetup
#### Incorporate full-disk encryption on /dev/sdb1, asking for passphrase twice
```sh
cryptsetup --verify-passphrase luksFormat /dev/sdb1
```
#### Assign virtual name "storage1" to encrypted disk /dev/sdb1
```sh
cryptsetup luksOpen /dev/sdb1 storage1
```
### curl
#### Download {url}, posting form-encoded {name} as {value}
```sh
curl -d '{name}={value}' url
```
#### Download {url}, but produce no output in case of failure
```sh
curl -f url
curl --fail url
```
#### Download {url}, following redirects
```sh
curl -L url
curl --location url
```
#### Download {url} saving output under the filename indicated by the URL itself
```sh
curl -O url
curl --remote-name url
```
#### Make an http GET request to the URL provided, displaying the response in the terminal
```sh
curl url
```
#### Download {url} and save to {file}
```sh
curl url -o file
```
### cut
#### cut options

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    |                         | character number
`-d`    | delimiter
```sh
cut -d
```
#### Field number
```sh
cut -f
```
### date
Display the date and time according to locale settings
#### Set the current date and time to {datestring}
```sh
date -s "datestring"
```
### date
#### Print or set UTC time
```sh
date -u
date --utc
date universal
```
### dbus-monitor
Monitor messages going through a D-Bus message bus
### dd
#### Implement a simple CPU benchmark by writing 1 GB of zeroes and piping it to md5sum
```sh
dd if=/dev/zero bs=1M count=1024 | md5sum
```
### declare
#### Option which displays output in a way that could then be used as input to another command
```sh
declare -p
```
### df
#### Change scale to terabytes
```sh
df -BT
df --block-size=T
```
#### Show drive utilization
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
### dig
DNS lookup tool that returns the text of the actual response from the DNS server, useful when troubleshooting a DNS issue (cf. [ `nslookup` ](#nslookup))
#### Nameserver
```
dig example.com NS
```
#### Mail server
```
dig example.com MX
```
#### Perform a reverse DNS lookup on an IP address
```sh
dig -x 8.8.8.8
```
#### Specify an alternate DNS server to query
```sh
dig @8.8.8.8 example.com
```
#### Find authoritative nameservers for the zone and display SOA records
```sh
dig +nsearch example.com
```
#### Lookup the IP associated with a domain name
```sh
dig +short example.com
```
#### Lookup the mail server IP associated with a domain name
```sh
dig +short example.com MX example.com MX
```
#### Perform iterative queries and display the entire trace path to resolve a domain name
```sh
dig +trace example.com
```
#### Get all types of records for a given domain name
```sh
dig example.com ANY
```
#### Display Start of Authority information for a domain
```sh
dig example.com soa
```
### dirname
#### Strip filename from $PATH
(cf. [ `basename` ](#basename))
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
I       | info                    | show information about {$PACKAGE}
i       | install                 | install {$PACKAGE}
l       | list                    | list packages currently installed
L       | listfiles               | list packages that were installed as dependencies of another package
p       | print-avail             | show details about {$PACKAGE}
P       | purge                   | remove {$PACKAGE}, including configuration files
r       | remove                  | remove {$PACKAGE}, keeping configuration files
s       | status                  | display package status
S       | search                  | list package name responsible for a specific file being installed on the system
C       | audit                   | check for broken packages
\-      | get-selections          | display list of package selections
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
#### Add a range of nonstandard ports
```sh
firewall-cmd --add-port=50000-60000/udp
```
#### Add a nonstandard port
```sh
firewall-cmd --add-port=8080/tcp
```
#### Add the FTP service to the firewall
```sh
firewall-cmd --add-service=ftp
```
#### Display zones that actually have an attached interface
```sh
firewall-cmd --get-active-zones
```
#### Display the default zone
```sh
firewall-cmd --get-default-zone
```
#### Display names of available services
```sh
firewall-cmd --get-services
```
#### Display approved port numbers
```sh
firewall-cmd --list-ports
```
#### Define a new zone "testlab"
```sh
firewall-cmd --new-zone=testlab
```
#### Record a change to the configuration on disk
```sh
firewall-cmd --permanent
```
#### Load configuration on disk into memory
```sh
firewall-cmd --reload
```
#### Remove firewalld service
```sh
firewall-cmd --remove-service
```
#### Confirm firewalld is running
```sh
firewall-cmd --state
```
### fold
#### Display text of {file}, wrapping long lines
```sh
fold  file
```
### fsck
Check filesystem for errors
#### Display progress indicators
```sh
fsck -C
```
#### Specify {ext3} filesystem and check {/dev/sdc1} for errors
```sh
fsck -t ext3 /dev/sdc1
```
#### Prompt when attempting a repair action 
```sh
fsck -r
```
### fstrim
Discard unused blocks on a mounted filesystem
### gconf-editor
GUI-based configuration editor for GNOME
### gdmsetup
GUI program used to set options for the login window when using GDM
### gem
#### Install a Ruby {package}
```sh
gem install package
```
#### Display currently installed Ruby packages
```sh
gem list
```
#### Remove a Ruby {package}
```sh
gem uninstall package
```
#### Update a Ruby {package}
```sh
gem update package
```
### getfacl
#### Get access control list for {file}
```sh
getfacl file
```
### gpasswd
#### Add {user} to {group}
```sh
gpasswd -a user group
```
#### Add {user} as admin of {group}
```sh
gpasswd -A user group
```
#### Remove {user} from {group}
```sh
gpasswd -d user group
```
### gpg
PGP was bought by Semantec, and GNU has since released GPG, an open-source replacement.[35](README.md#sources)
#### gpg options
Option  | POSIX option                | Effect
:---    | :---                        | :---
\-      | clearsign, clear-sign       | make a cleartext signature, readable without any special software
\-      | send-keys                   | send keys to a keyserver
d       | decrypt                     | decrypt {$FILE}
k       | list-keys, list-public-keys | list available GPG keys
#### Decrypt file
```sh
gpg file.txt
```
#### Export GPG public key
```sh
gpg --export --output ~/jdoe.pub
```
#### Import another person's public key
```sh
gpg --import jdoe.pub
```
#### List available GPG keys
```sh
gpg --list-key
```
#### Encrypt a file
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
### groupadd
Create a new group
### groupdel
Delete a group
### groupmod
Modify definition of specified group by modifying the appropriate entry in the group database
#### Rename {group} to {newname}
```sh
groupmod -n group newname
```
#### Change name of {group} to {newname}
```sh
groupmod -n newname group<hr># groupmod --new-name newname group
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
Get/set SATA/IDE device parameters
#### Check power mode
```sh
hdparm -C
```
#### Show drive geometry, including size in sectors and starting offset
```sh
hdparm -g
```
### head
#### Print first 8 characters of {file}
```sh
head -c8 file
```
### host
#### Display SOA record frm each authoritative DNS nameserver
```sh
host -C
```
### hostname
#### Return the domain name configured for the server
```sh
hostname -d
```
### hwclock
Access the BIOS clock
#### Set hardware clock to software clock
```sh
hwclock --hctosys
```
#### Set software clock to hardware clock
```sh
hwclock --systohw
```
### system
#### Display the Hardware Clock time
```sh
hwclock --show
```
### iconv
Convert text from one encoding to another
#### Convert {file} from ASCII to UTF-8
```sh
iconv -f ASCII -t UTF-8 file
```
#### Show available character sets
```sh
iconv -l --list
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
#### Display details of all interfaces (even disabled)
```sh
ifconfig -a
```
#### Disable eth0
```sh
ifconfig eth0 down
```
#### Configure eth0 with an additional IPv6 address
```sh
ifconfig eth0 inet6 add fdd6:551:b09e::/128
```
#### Enable eth0
```sh
ifconfig eth0 up
```
#### Turn network interface {eth0} on or off using `ifconfig`
```sh
ifconfig eth0 up
ifconfig eth0 down
```
#### Turn off network interface {eth0}
```sh
ifdown eth0
```
#### Bring online all interfaces marked as auto within the networking configuration
```sh
ifup -a
```
#### Turn on network interface {eth0}
```sh
ifup eth0
```
### initctl
#### Reload configuration files (on Upstart-controlled system)
```sh
initctl reload
```
### insmod
#### Insert a module into the Linux kernel
```sh
insmod module
```
### ip
#### Newer alternative to the old `ifconfig`
```sh
ip addr
```
#### Show L2 status (links)
```sh
ip link
```
#### Listen for netlink messages
```sh
ip monitor 
```
#### Display routing information
```sh
ip route
```
#### Change the default gateway to 192.168.1.1 on eth0
```sh
ip route change default via 192.168.1.1 dev eth0
```
### iscsiadm
Command-line utility allowing discovery and login to iSCSI targets
#### Set interval length between two ping requests
```sh
iscsiadm -i
```
#### Discover iSCSI targets
```sh
iscsiadm discovery
```
### iwlist
Get detailed wireless information about a wireless interface
### journalctl
Display the systemd binary logs
#### Show current disk usage of all journal files
```sh
journalctl --disk-usage
```
#### Continuously update the display as new log entries are created
```sh
journalctl -f
```
#### Display output in reverse (newest entries first)
```sh
journalctl -r
```
### kill
#### List signal options
```sh
kill -l
kill --list
```
#### Transmit SIGKILL to {proc}
```sh
kill -9 proc
kill --KILL proc
```
### last
Display history of successful logins
#### Load information from an alternate file
```sh
last -f file
last --file file
```
#### Display history of successful logins by {username}
```sh
last username
```
### lastb
Display history of unsuccessful logins
### ldconfig
#### Change location of cache to be updated
```sh
ldconfig -C
```
#### Print current directories and libraries in cache
```sh
ldconfig -p
```
#### Display all shared libraries
```sh
ldconfig -v
```
### ldd
#### Display dependencies of {program}
```sh
ldd program
```
### let
#### Perform arithmetic as specified by one or more `expressions`
```sh
let  expressions | ((expressions))
```
### link
#### Create a link between two files; same as `ln`, but with no error checking
```sh
link file1 file2
```
### locale
Display all environment variables related to localization with their current values
#### Display all localizations currently supported by the system
```sh
locale -a
```
### logout
#### Exit a login shell
```sh
logout 
```
### lp
Send `files` to the printer; with no arguments, prints stdin
### lpstat
Print the `lp` print queue status
### ls
#### Display hidden files
```sh
ls -a ls --all
```
#### Append indicator (*/=>@|) to entries
```sh
ls -F ls --classify
```
#### Display SELinux context for files
```sh
ls -Z
```
### lsblk
Display information about all block devices
#### Show UUID, Label, and filesystems of non-GPT block devices
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
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-k`    |                         | display PCI devices and the drivers being used
`-n`    |                         | display device numbers rather than names
`-nn`   |                         | display both device numbers and names (typically stored in [ /usr/share/hwdata/pci.ids ](#configs) or [ /usr/share/hwdata/pci.ids.gz ](#configs))
### lsusb
Display devices that are attached to the PCI bus
Option  | POSIX option            | Effect
:---    | :---                    | :---
`-D`    |                         | display {$DEVICE} rather than probing the /dev/bus/usb directory and displaying all devices
`-t`    |                         | display devices in a tree-like format
### mailq
Display the current mail queue on a Postfix server
### mailstats
Gather and display statistics about mail processed on a server running sendmail
### makemap
Execute after making a change to the sendmail access database /etc/access
### mdadm
Manage Linux Software RAID devices
#### Start a stopped RAID array
```sh
mdadm --assemble
```
#### Set the polling interval ?
```sh
mdadm --delay
```
### mhwd
Manjaro hardware utility
`sudo mhwd -a pci nonfree 0300` : command was run while troubleshooting black screen on startup 
### mhwd-chroot
Chroot into an installed Linux installation from a live boot of a Manjaro Installation Media
### mkdir
#### Quickly create multiple directories using brace expansion
```sh
mkdir -p ~/my-app/{bin,lib,log}
```
#### Create new directory {dirname} along with all of the parents in its pathname, if they do not exist
```sh
mkdir -p dirname
mkdir --parents dirname
```
### mke2fs
Create an ext2/3/4 filesystem
### mkfontscale
Create a fonts.scale file definition when executed against the current directory
### mkfs
#### Create an ext4 filesystem on {partition}
```sh
mkfs -t ext4 partition
```
#### Specify {filesystemtype} to be created
```sh
mkfs -T filesystemtype
```
#### Make a swap file out of {partition}
```sh
mkswap partition
```
### modinfo
#### Determine options that a given module supports
```sh
modinfo -p
```
#### Show information about a Linux kernel module
```sh
modinfo module
```
### modprobe
Add and remove modules from the Linux kernel

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-c`    |                         | display current `modprobe` configuration
`-R`    |                         | display all modules that match an alias
`-r`    | `--remove`              | remove specified module from memory

#### Remove {$MODULE} from the Linux kernel
```sh
modprobe --remove $MODULE
```
#### Show kernel {$MODULE}'s dependencies
```sh
modprobe --show-depends $MODULE
```
### mongod
MongoDB daemon
#### mongod options
Option  | POSIX option            | Effect
:---    | :---                    | :---
        | dbpath                  | 
        | fork                    |
        | logpath                 |
        | port                    |

#### Run MongoDB service in the background on port 80
```sh
mongod --dbpath $HOME/db --port 80 --fork --logpath /var/tmp/mongodb
```
#### Mount all filesystems in fstab
```sh
mount -a
```
#### Mount {filesystem} as read-only
```sh
mount -r filesystem
```
#### Specify filesystem type
```sh
mount -t
```
#### Mount a partition using its UUID
```sh
mount -U
```
#### Mount {filesystem} as read-write
```sh
mount -w filesystem
```
#### Mount a USB stick that is made available on /dev/sdb in /media/usb
```sh
mount /dev/sdb1 /media/usb
```
### mt
Control magnetic tape drive operation; operates on environment variable TAPE
### netplan
Ubuntu network configuration tool

Config file   | Description
:---          | :---
/etc/netplan/ | directory containing various configuration files and scripts
/etc/nplan/99_config.yaml | netplan config
#### Apply network configuration settings
```sh
netplan apply
```
### newaliases
Refresh the mail system after a change to the [ /etc/aliases ](#configs) file; Must be run after making a change to email aliases on a server running [ `postfix` ](#postfix)
### nice
#### Run {prog} at a nice value of (positive) 10
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
### nmap
Scan hosts and ports on a network
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
#### Aggressive scan
```sh
nmap -A 192.168.1.0/24
```
#### Ping scan home network (not bothering with ports)
```sh
nmap -sn 192.168.1.0/24
```
#### Fast port scan using SYN packets
```sh
nmap -sS -F 192.168.1.0/24
```
#### Port scan using SYN ("synchronize") packet, first element of TCP handshake
```sh
nmap -sS 192.168.1.0/24
```
#### Port scan using normal TCP
```sh
nmap -sT 192.168.1.0/24
```
#### Port scan using UDP
```sh
nmap -sU 192.168.1.0/24
```
#### Xmas scan
```sh
nmap -sX
```
### nmblookup
Test NetBIOS name resolution
### nmcli
Control NetworkManager and report network status
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
#### Configure settings for network interface {ens01} via interactive shell
```sh
nmcli connection edit ens01
```
#### List all connections NetworkManager has
```sh
nmcli connection show
```
#### Show settings for network interface {ens01}
```sh
nmcli device show ens01
```
#### Show status for all devices
```sh
nmcli device status
```
#### Display devices and status
```sh
nmcli device status
```
#### Display currently configured hostname
```sh
nmcli general hostname
```
#### Set hostname to {hostname}
```sh
nmcli general hostname hostname
```
#### Show overall status of NetworkManager
```sh
nmcli general status
```
### nohup
#### Execute {cmd} in the background such that it won't be interrupted by a logoff
```sh
nohup cmd &
```
### ntpdate
#### Synchronize system clock to that of an online Network Time Protocol server
```sh
ntpdate -upool.ntp.org
```
### passwd
#### Immediately expire the passwore of {user}, forcing a password change on next login
```sh
passwd -e user # passwd --expire user
```
#### Disable an account after {n} days of inactivity
```sh
passwd -i n # passwd --inactive n
```
#### Lock {user}'s account
```sh
passwd -l user # passwd --lock
```
#### Unlock {user}'s account
```sh
passwd -u user # passwd --unlock
```
### paste
Merge lines of files
#### Make a .csv file from two lists
```sh
paste -d ',' file1 file2
```
#### Transpose rows
```sh
paste -s file1 file2
```
### patch
#### Ignore whitespace
```sh
patch -i
```
### ping
"packet Internet groper" utility used for checking network connections, using ICMP packets (cf. [ `nc` ](#nc))
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
#### Send {n} number of pings
```sh
ping -c n
```
#### Print timestamp
```sh
ping -D
```
#### Flood ping
```sh
ping -f
```
#### Mark outgoing packet to be processed appropriate to kernel's policy
```sh
ping -m
```
#### Numeric output only; disable name resolution
```sh
ping -n
```
#### Bypass routing tables
```sh
ping -r
```
### pip
#### Display installed packages
```sh
pip list
```
#### Display information about {package}
```sh
pip show package
```
### postqueue
#### Cause mail queue to be processed on a Postfix server
```sh
postqueue -f
```
### postsuper
#### Delete all of the messages from the queue on a postfix server
```sh
postsuper -d
```
### ps
#### Display processes in a tree-like display illustrating parent-child relationships
```sh
ps -f
ps --forest
```
#### Show system processes
```sh
ps ax
ps -e
```
#### Display full listing of processes
```sh
ps u
ps -f
```
#### Display user processes
```sh
ps xG
ps -a
```
#### Display SELinux contexts for processes
```sh
ps auxZ
```
### pydoc
#### Display all installed Python modules
```sh
pydoc modules
```
### quota
#### Check quota status of {user}
```sh
quota user
```
### quotacheck
Create the quota database
### quotaoff
#### Turn off all quotas
```sh
quotaoff -a
```
### quotaon
#### Turn on all quotas
```sh
quotaon -a
```
#### Turn on quotas for {user}
```sh
quotaon -u user
```
### read
Option  | POSIX option            | Effect
:---    | :---                    | :---
a | | read from standard input, with the words assigned to sequential indices of {array}
d | | read from standard input, with the first character of `delim` being used to terminate input, rather than newline
e | | read from standard input, if standard input is coming from a terminal, readline is used to obtain the line
n | | read from standard input, returning after reading {n} chars
p | | read from standard input, displaying {$PROMPT} on standard error before reading any input
r | | read from standard input, backslash no longer will act as an escape character
s | | read from standard input, silent mode (characters are not echoed)
t | | read from standard input, returning failure is a complete line of input is not read within {n} seconds
u | | read input from file descriptor { $FILE }
#### Stopwatch
Will stop when you press enter, displaying how much time elapsed
```sh
time read
```
### repquota
#### Human-readable
```sh
repquota -sh
```
### resize4fs
Resize ext4 filesystem
### restorecon
#### Restore security context default in the policy
```sh
restorecon -Rv website
```
### rmmod
#### Wait until a module is no longer in use before unloading
```sh
rmmod -w
```
#### Remove $MODULE from the Linux kernel
```sh
rmmod $MODULE
```
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
#### Add a route to the server for the network 192.168.51.0/24 through the gateway 192.168.51.1
```sh
route add -net192.168.51.0 netmask 255.255.255.0 gw 192.168.51.1
```
#### Add default gateway at {ipaddr}
```sh
route add default gw ipaddr
```
### rpm
#### rpm option groups
Option  | POSIX option            | Effect
:---    | :---                    | :---
e       | erase                   | remove specified package, including config files
i       | install                 | install specified package
q       | query                   | query for specified package
U       | upgrade                 | upgrade specified package
#### rpm query options
Option  | POSIX option            | Effect
:---    | :---                    | :---
a       |                         | lista all installed packages
c       |                         | list configs installed with specified package
d       |                         | list documentation files installed with specified package
i       |                         | display information about specified package
K       |                         | Verify integrity of specified package
l       |                         | List all files installed with specified package
provides|                         | List which capabilities the specified package provides
R       |                         | list which capabilities the specified package requires
s       |                         | display state of each file that was installed by specified package (normal, not installed, or replaced)
#### Query repos for information on {package}
```sh
rpm -qi package
rpm --query --info package
```
#### Upgrade or install {package}, with progress bars
```sh
rpm -Uvh package
rpm --upgrade --verbose --hash package
```
### rsync
#### Copy recursively, preserving group, owner, modification times, and device-files (if super-user)
```sh
rsync -a
rsync --archive
```
#### Specify remote shell to use
```sh
rsync -e ssh
rsync --rsh=ssh
```
#### Preserve group
```sh
rsync -g
rsync --group
```
#### Preserve owner
```sh
rsync -o
rsync --owner
```
#### Copy file to remotepath on remotehost
```sh
rsync file remotehost:remotepath
```
#### Archive mode: equivalent to -rptlgoD
```sh
rsync -a
```
#### Create a backup of every file destination file transferred
```sh
rsync -b
```
#### Copy remotefile from remotehost to path
```sh
rsync remotehost:remotefilepath
```
### runlevel
#### Show runlevel for system
```sh
runlevel 
```
### smbclient
Connect to a Samba server
#### Set the port while connecting to a Samba server
```
smbclient -p
```
### smbpasswd
Create a Samba password
### smbstatus
Report on current Samba connections
#### List Samba shares
```sh
smbstatus -S
```
### sed
#### Run sed commands in `sedscr` on file
```sh
sed -f sedscript file
```
#### Suppress automatic printing of pattern space
```sh
sed -n
sed --quiet
sed --silent
```
### SELinux
#### Display SELinux contexts for processes
```sh
ps auxZ
```
#### Display SELinux context for files
```sh
ls -Z
```
#### Display status of SELinux
```sh
sestatus
```
#### Change SELinux mode
{$MODE} can be "enforcing" (or "1"), "permissive" ("0") or "disabled"
```sh
setenforce $MODE
```
#### Amend policy to add a file context
```sh
semanage fcontext -a -t httpd_sys_content_t website
```
#### Add a port context
```sh
semanage port -a -t http_port_t -p tcp 8080
```
#### Display all ports with attached types
```sh
semanage port -l
```
### seq
#### Sequence from 1 to 15
```sh
seq -f "%03g" 15
```
#### Sequence from 5 to 99, separated by a space instead of a newline
```sh
seq -s " " 5 99
```
#### Sequence every third number from 5 to 20
```sh
seq 5 320
```
#### Sequence from 1 to 8
```sh
seq 8
```
### sysvinit
#### Access different runlevels
```sh
init 
```
#### Switch to runlevel {n}
```sh
init n
init 6 # reboot
```
#### Restart network service 
```sh
service network restart
```
#### Check status of {daemon}
```sh
service daemon status
```
#### Stop {daemon}
```sh
service daemon stop
service mongodb stop
```
#### Turn services on or off for runlevels
Without arguments, `chkconfig` defaults to runlevels 3 or 5:
```sh
chkconfig
```
#### Display all services and runlevels
```sh
chkconfig --list
```
#### Turn {daemon} on for runlevels 3 and 5
```sh
chkconfig --level 35 daemon on
```
#### Turn {daemon} off
```sh
chkconfig daemon off
chkconfig NetworkManager off
```
#### Turn {daemon} service on
```sh
chkconfig daemon on
```
### setfacl
Set file access control lists
#### Grant user {lisa} right to read {file}
```sh
setfacl -m u:lisa:r file
```
#### Remove named group {staff} from {file}'s ACL
```sh
setfacl -x g:staff file
```
#### Modify file access control list for {file} to revoke write access from all groups and all named users
```sh
setfacl -m m::rx file
```
### sfdisk
Script-oriented tool for partitioning disk devices
### sfdisk
#### Set the first partition of the first SATA device to a RAID type
```sh
sfdisk --id /dev/sda 1 fd
```
#### Set the first partition of the first SATA device to a RAID type
```sh
sfdisk --id /dev/sda 1 fd
```
#### List partitions on all devices
```sh
sfdisk-l # sfdisk --list
```
#### List partitions on {device}
```sh
sfdisk-l device # sfdisk --list device
```
### shred
#### Write random data to an unmounted disk for {n} passes
```sh
shred --iterations=n
```
### shuf
#### Randomly permute input
```sh
shuf 
```
#### Shuffle items separated by a space
```sh
shuf -e *items
```
#### Print random selection of integers from {x} to {y} (inclusive) without replacement
```sh
shuf -i x-y
```
#### Print random selection of integers from {x} to {y} (inclusive), with replacement
```sh
shuf -i x-y -r
```
#### Shuffle items separated by newline in file `cards.txt`, displaying only one
```sh
shuf -n 1 items.txt
```
### shutdown
#### Shut down at 8 pm
```sh
shutdown 20:00
```
### slapadd
Add entries to the slapd LDAP directory
### sleep
#### Wait a specified number of `seconds` before executing another command; often used in shell scripts
```sh
sleep seconds
```
### snap
#### Disable snap {pkg}
```sh
snap disable package
```
#### Enable disabled snap {pkg}
```sh
snap enable package
```
#### Display information about {package}
```sh
snap info --verbose package
```
#### Install snap {pkg}
```sh
snap install package
```
#### Display logs of snap {pkg}
```sh
snap logs package
```
#### Check for snap updates
```sh
snap refresh
```
#### Uninstall snap {pkg}
```sh
snap remove package
```
### sort
#### Sort by column number {n}
```sh
sort -k n
```
#### Reverse sort order
```sh
sort -r
```
#### Set delimiter to character {x}
```sh
sort -t x
```
### source
#### Execute commands from a file in the current shell
```sh
source file
. file
```
### speaker-test
#### Test loudspeakers with a 2-speaker setup
```sh
speaker-test -c 2
```
### ss
Dump socket statistics
#### Do name lookups and display all information
```sh
ss -an
ss --all --numeric
```
#### Display all sessions, filtering to just TCP that are actively listening
```sh
ss -atp
ss --all --tcp --processes
```
#### Display active TCP connections
```sh
ss -tp
ss --tcp --processes
```
### ssh
#### Display timer information
```sh
ss -o
ss --options
```
#### Request a SSHv1 connection to {user@host}
```sh
ssh -1 user@host
```
#### Request a SSHv2 connection to {user@host}
```sh
ssh -2 user@host
```
#### Request a IPv4 connection to {user@host}
```sh
ssh -4 user@host
```
#### Request a IPv6 connection to {user@host}
```sh
ssh -6 user@host
```
#### Enable the use of a key for authentication
```sh
ssh -i privatekey
```
#### Ssh to {user} at {host} and {hostport} from {port}
```sh
ssh -L port:host:hostport user@host
```
#### Set the port for the remote host
```sh
ssh -p
```
#### Initiate a SSH session with {user@host}, enabling X forwarding
```sh
ssh -Y user@host
```
#### List currently loaded keys
```sh
ssh-add -l
```
### ssh-keygen
#### Generate a MD5 fingerprint from public key at {file}
```sh
ssh-keygen -E md5-lf /path/to/file
```
#### Generate a SHA512 fingerprint from public key at {file}
```sh
ssh-keygen -E sha512 -lf /path/to/file
```
#### Generate a fingerprint from the public key
```sh
ssh-keygen -lf /path/to/file
```
### ssh-keyscan
#### Display the public key of {host}
```sh
ssh-keyscan host
```
### stty
#### Return number of rows and columns of the terminal
```sh
stty size
```
### su
#### Obtain the normal login environment
```sh
su -
```
#### Execute a single command with a non-interactive session
```sh
su -c cmd
```
### sudo
#### Prevent sudo from prompting for credentials or for any other reason
```sh
sudo --noprompt
```
### swapon
#### Instruct system to begin using {partition} as a swap file
```sh
swapon partition
```
### sysctl
View and configure kernel parameters at runtime
#### Display current hostname as known to the kernel
```sh
sysctl -n kernel.hostname
```
### syslog
System logging facility used for messages from the kernel
### systemctl
#### Display 
```sh
systemctl --failed
```
#### Turn NetworkManager off (systemd)
```sh
systemctl disable NetworkManager.service
```
#### Disable {service}, ensuring it does not run on boot
```sh
systemctl disable service
```
#### Make {service} run on boot 
```sh
systemctl enable  service
```
#### Configure iptables to start on boot and start it immediately
```sh
systemctl enable --now iptables
```
#### Display default target (on a systemd-controlled system)
```sh
systemctl get-default 
```
#### ?
```sh
systemctl isolate --now service
```
#### Change target to runlevel emergency
```sh
systemctl isolate emergency.target
```
#### Change target to runlevel 5
```sh
systemctl isolate graphical.target
systemctl isolate runlevel5.target
```
#### Change target to runlevel 3
```sh
systemctl isolate multi-user.target
systemctl isolate runlevel3.target
```
#### Change target to runlevel 0
```sh
systemctl isolate poweroff.target
systemctl isolate runlevel0.target
```
#### Change target to runlevel 6
```sh
systemctl isolate reboot.target
systemctl isolate runlevel6.target
```
#### Change target to runlevel 1
```sh
systemctl isolate rescue.target
systemctl isolate runlevel1.target
```
#### Change signal type sent to process to be killed
```sh
systemctl kill -s
```
#### Equivalent to chkconfig --list
```sh
systemctl list-unit-files --type=service
```
#### List available service units
```sh
systemctl list-units
```
#### Prevent firewalld from being started inadvertently by another process
```sh
systemctl mask firewalld
```
#### Reboot the system
```sh
systemctl reboot
```
#### Restart {service}
```sh
systemctl restart  service
```
#### Restart iptables service
```sh
systemctl restart iptables
```
#### Restart network service
```sh
systemctl restart network.service
```
#### Configure system to boot to a GUI
```sh
systemctl set-default graphical.target
```
#### Start {service}
```sh
systemctl start  service
```
#### Check status of {service}
```sh
systemctl status  service
```
#### Terminate {service}
```sh
systemctl stop  service
```
#### Stop the firewalld service
```sh
systemctl stop firewalld
```
#### Suspend the system
```sh
systemctl suspend
```
### systemd-delta
Show files that are overridden with systemd
### systemd-delta
#### Display differences among files when they are overridden
```sh
systemd-delta --diff
```
### tail
#### Output last lines beginning at 30th line from the start
```sh
tail -n=+30
tail --lines=+30
```
### tcpdump
Inspect actual IP packets
#### Set snapshot length of capture (default 65,535B)
```sh
tcpdump -s
```
### telinit
#### Refresh system after changes to `/etc/inittab`
```sh
telinit 
```
#### Cause operation to not send any notice to logged-on users
```sh
telinit--no-wall
```
### test
Evaluate a condition, returning 0 if true and 1 if false
#### test options
Option  | Effect
:---    | :---
a       | Test if both EXPRESSION1 and EXPRESSION2 are true
b       | Test if {file} exists and is block special
c       | Test if {file} exists and is character special
d       | Test if {file} exists and is a directory
e       | Test if {file} exists
ef      | Test if {file} and {other} have the same device and inode numbers
eq      | Test if INT1 is equal to INT2
f       | Test if {file} exists and is a regular file
ge      | Test if INT1 is greater than or equal to INT2
o       | Test if either EXPRESSION1 or EXPRESSION2 are true
le      | Test if INT1 is less than or equal to INT2
lt      | Test if INT1 is less than INT2
ne      | Test if INT1 is unequal to INT2
nt      | Test if {file} is newer (modification date) than {other}
ot      | Test if {file} is older than {other}
g       | Test if {file} exists and is set-group-ID
G       | Test if {file} exists and is owned by the effective group ID
h       | Test if {file} exists and is a symbolic link
k       | Test if {file} exists and has its sticky bit set
L       | Test if {file} exists and is a symbolic link
n       | Test if the length of {string} is nonzero
O       | Test if {file} exists and is owned by the effective user ID
p       | Test if {file} exists and is a named pipe
r       | Test if {file} exists and read permission is granted
s       | Test if {file} exists and has a size greater than zero
S       | Test if {file} exists and is a socket
u       | Test if {file} exists and its set-userID bit is set
w       | Test if {file} exists and write permission is granted
x       | Test if {file} exists and execute (or search) permission is granted
z       | Test if the length of {string} is zero
#### Test if {VAR} has either the text "string1" or "string2" within it
```sh
[[ $VAR =~ 'string1' \| 'string2' ]]
```
#### Test if {VAR} matches a regex {pattern} (must not be quoted, otherwise, {pattern} will be treated as a string literal)
```sh
[[ $VAR =~ pattern ]]
```
### timedatectl
Display the system clock, including local time, universal time, time zone, etc
### top
#### Change update interval
```sh
top -n
```
### tput
#### Return width of current terminal window
```sh
tput cols 
```
#### Return height of current terminal window
```sh
tput lines
```
### tracepath
Successor to `traceroute`, blocked by many ISPs because it is a newer tool
### traceroute
Follow the path a packet takes between two hosts
#### Choose the interface to be used for the path trace
```sh
traceroute -i
```
#### Choose the source address to be used for the path trace
```sh
traceroute -s
```
#### Use TCP SYN packets for the path trace
```sh
traceroute -T
```
#### Set the Type of Service (ToS) flag to be used for the path trace
```sh
traceroute -t
```
### tune2fs
Adjust various 
#### Run `fsck` on {/dev/sdb1} on every boot
```sh
tune2fs -c 1 /dev/sdb1
```
#### Run `fsck` on {/dev/sda1} at intervals of 60 mounts or 6 months
```sh
tune2fs -c 60 -i 6m /dev/sda1
```
#### Enable journaling on ext2 partition {/dev/sdc1}
```sh
tune2fs -j /dev/sdc1
```
#### Assign label "Sales" to logical volume {/dev/vg1/Sales}
```sh
tune2fs -L Sales /dev/vg1/Sales
```
### tzselect
Select timezone
### udevadm
Udev management tool
#### Update the hardware database index after updating source files related to udev
```sh
udevadm -u
```
### umount
#### Unmount a USB stick mounted a `/dev/sda`
```sh
umount /dev/sda1
```
### uname
#### Display operating system release number
```sh
uname -r
```
### update-grub
Make changes take effect for a GRUB2 configuration change
### update-rc.d
Create links within /etc/rc.d/ for starting and stopping services
### useradd
Create a new user
#### useradd options
Option  | POSIX option            | Effect
:---    | :---                    | :---
b       | base-dir                | default base directory for the system if `HOME_DIR` is not specified (sets `HOME` variable in [/etc/default/useradd](#etcdefaultuseradd)
c       | comment                 | typically user's full name
d       | home-dir                | specify user's login directory: default is to append the `LOGIN` name to `BASE_DIR`
D       | defaults                | 
e       | expire-date             | specify date on which the user account will be disabled (in format `YYYY-MM-DD`) (sets `EXPIRE` variable in [/etc/default/useradd](#etcdefaultuseradd))
k       | skel                    | specify skeleton directory (defaulting to definition of `SKEL` variable in [/etc/default/useradd](#etcdefaultuseradd), failing to /etc/skel)
m       | create-home             | create user's home directory if it does not exist, copying contents of skeleton directory
r       | system                  | create a system account
s       | shell                   | specify user's login shell (defaulting to definition of `SHELL` variable in [/etc/default/useradd](#etcdefaultuseradd), failing to an empty string)
u       | uid                     | specify UID

#### Add {user}
```sh
useradd user
```
#### View defaults for new users
```sh
useradd -D
```
#### Add {user}, noting her full {name}
```sh
useradd user -c name
```
#### Add {user}, specifying home directory at {path}
```sh
useradd user -d path
```
#### Add {user}, specifying expiration {date} (YYYY-MM-DD)
```sh
useradd user -e date
```
#### Create new {user} leaving a {comment} field (conventionally noting the full name of the user) and creating a home directory
```sh
useradd -c comment -m user
```
#### Create a system user rather than a normal user
```sh
useradd -r
```
### userdel
Delete an existing user account;
#### Delete an existing user account as well as the user's home directory
```sh
userdel-r  user
```
### usermod
Modify user account files
#### usermod options
Option  | POSIX option            | Effect
:---    | :---                    | :---
a       | append                  | add user to supplementary group(s), only used with `-G`
G       | groups                  | specify a list of groups to which the user will be added
l       | login                   | change user's name or "login"
L       | lock                    | lock a user's password
u       | uid                     | change UID
U       | unlock                  | unlock account

#### Lock account of {user}
```sh
usermod -L user
```
#### Rename {user} {new}
```sh
usermod -l user new
```
#### Unlock account of {user}
```sh
usermod -U user
```
#### Add {user} to {group}
```sh
usermod user -a -G group
```
### vifs
Safely edit fstab file
### visudo
Edit and view the `etc/sudoers` file
### wall
#### Send {message} to users in {group}
```sh
wall -g group message
wall --group group message
```
### wc
#### Display byte count
```sh
wc -c
```
#### Count lines of text
```sh
wc -l 
```
#### Display character count
```sh
wc -m
```
#### Count words of text
```sh
wc -w
```
### whatis
#### Look up one or more commands in the online manpages and display a brief description
```sh
whatis commands
```
### X
Start the graphical interface from a command line
#### Test X11 with the config file automatically generated after `Xorg -configure`
```sh
X -config $HOME/xorg.conf.new
```
### xdpyinfo
Show detailed information about display
### xhost
#### Enable access control to X server
```sh
xhost -
```
#### Remove {host} from list of authorized clients for X server
```sh
xhost -host
```
#### Disable access control to X server
```sh
xhost +
```
#### Add {host} to list of authorized clients for X server
```sh
xhost +host
```
### Xorg
#### Enable automatic configuration of X11 server
```sh
Xorg -configure
```
### xrandr
Set size, orientation, and reflection of video output
#### Change resolution of DisplayPort1 to 1920x1080
```sh
xrandr --output DP1 --mode 1920x1080
```
#### Disable VGA1 output
```sh
xrandr --output VGA1 --off
```
#### Display current state of the system
```sh
xrandr -q  --query
```
### xwininfo
Utility that provides information about a clicked window, including dimensions, position, etc
### yay
#### Display all AUR packages that need to be updated (deprecated)
```sh
yay -Pu
yay --show --upgrades package
```
#### List all install packages, filtering output to packages that are out-of-date on the local system
```sh
yay -Qu
yay --query --upgrades
```
#### Install {pkg} from the AUR
```sh
yay -S package
yay --sync package
```
#### Display information about {package}
```sh
yay -Si package
yay --sync --info package
```
#### Search for {pkg} in AUR repos
```sh
yay -Ss package
yay --sync --search package
```
#### Update all packages from AUR and official repos
```sh
yay -Syu
yay --sync --refresh --sysupgrade
```
#### Remove unwanted dependencies of now-removed installations of AUR repos
```sh
yay -Yc
yay --yay --clean
```
### touch
#### Update {newfile}'s modification date to match {oldfile}
[[36](README.md#sources)]
```sh
touch -r oldfile newfile
```

### sosreport
**SOS** is an open-source data collection tool that can be used to collect system configuration details and diagnostic information from a Unix-like operating system. It is installed by default on Ubuntu Server. [[39](README.md#sources)]
#### sosreport options
Option  | POSIX option            | Effect
:---    | :---                    | :---
\-      | compression-type        | specify alternative compression (`xz` by default)
l       |                         | list plugins
\-      | tmp-dir                 | specify alternative temporary directory


#### Collect system configuration details
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
#### Install and configure Samba server
Install `samba`
```sh
sudo apt install samba
```
Verify the samba service `smbd` is running
```sh
sudo systemctl status smbd
```
#### Configure Samba 
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
Restart Samba service
```sh
sudo systemctl restart smbd.service
```
[[40](README.md#sources), [41](README.md#sources)]
#### Install and configure Samba as a client
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
[[40](README.md#sources)]
### Bash scripting
#### Validating arguments
```sh 
if [ $# != 2 ]
then 
  echo "..."
  exit 1
fi
```
[[PGL](../sources/pgl.md): 548]
```sh
[ -z "$1" ] && echo "..." && exit 1
```
[[7](README.md#sources)]
```sh
if [ ! -z "$2" ] ; then ...; fi
```
[[8](README.md#sources)]
#### Looping based on user input
Placed in a while loop, if user responds with anything except "y" (the read command will read only the first letter) the loop will terminate [[23](README.md#sources)]
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
