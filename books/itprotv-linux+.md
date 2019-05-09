# CompTIA Linux+ XK0-004, ITPro.TV

## xk0004-01 Overview
Five domains of exam
  1. Hardware and system configuration
  2. System operation and maintenance
  3. Securty
  4. Linux troubleshooting and diagnostics
  5. Automating and scripting

## xk0004-02 Introduction to Linux
  - Historical background on development of Linux: Linux Torvalds, ca. 1991
  - Distinction between operating system and kernel
  - Lineage of distributions: CentOS from Red Hat, Ubuntu from Debian
  - Linux+ exam covers Ubuntu and CentOS

## xk0004-03 Linux Command Line
  - Access to command-line via 
    1) Boot direct to console
    2) Terminal software (XTERM, Konsole, Gnome Terminal, etc)
  - /bin/sh generally links to another shell, /bin/bash on CentOS and /bin/dash on Ubuntu
  - Execute commands in CLI by using _commands_ and _options_ or arguments
  - Common commands: ls, mkdir, cd, pwd, echo, touch, cp
  - Edit and view text files: cat, more/less, vim, nano, gedit
  - Tab auto-complete

## xk0004-04 Super user privileges
  - `su` substitute user
  - `su -` switch to root, including normal environment
  - `su username` login as {username}
  - `sudo cmd` execute {cmd} as root (password cached for 5 minutes by default)
  - `visudo` view and edit sudoers
  - `%techsupport localhost=/sbin/mount /mnt/cdrom, /sbin/umount /mnt/cdrom` example...
  - `sudoedit`

## xk0004-05 Managing users
  - `useradd username` add {username}: `useradd jdoe -c "John Doe" -e 2019/12/31 -s /bin/dash -d /home/john_doe`
    - `-c` add full name in the comment field
    - `-e` expiration date
    - `-a` default shell
    - `-d` home directory
  - `usermod`
    - `-l old new` rename user {old} to {new}
    - `-L` lock account
    - `-U` unlock account
    - `-a -G group` add to {group}
  - `chsh` change shell
    - `/bin/nologin` prevent an account from logging in interactively
  - `passwd username` set password for {username}
  - `chage` view or modify expiration
    - `-m days` minimum {days}
    - `-M days` maximum {days}
    - `-E date` expiry {date}
    - `-W days` warn {days} before expiration

## xk0004-06 Managing groups
  - `groupadd`
  - `groupdel`
  - `groupmod`
    - `-n group new` rename {group} to {new}
  - `gpasswd`
    - `-a user group` add {user} to {group}
    - `-d user group` remove {user} from {group}
    - `-A user group` add {user} as admin of {group}
  - /etc/group
  - `newgrp group` change context temporarily
  - `chgrp group`
  - `chown group`
  - `groups user` see group membership of {user}

## xk0004-07 Managing file permission
## xk0004-08 Advanced permissions
  - `getfacl`
  - `setfacl`
    - `-m` modify
    - `-s` set
    - `-x` remove
  - `tune2fs`

## xk0004-09  Partitioning disks
`fdisk`
`gdisk`

## xk0004-10 Linux file system
Two main choices for Linux:
  - ext (long history)
  - xfs (Red Hat)
`mkfs` tool used to make file systems
  - `-t ext4` specify "type", ext4 or xfs
  - `mkfs.ext4 partition` format {partition} with the ext4 file system
  - /etc/mkfs
`mkswap partition` : make swap partition out of {partition} (15:00)
`swapon partition` : tell system to use {partition} as swap partition
### Changing partitions after creation
`e2label partition Storage` : label ext {partition} "Storage" (18:40)
`xfs_admin -L Storage partition` : label xfs {partition} "Storage"
`resize4fs` : resize filesystems
`tune` commands in /usr/sbin
  - `tune2fs` change behaviors of ext file systems
### Making filesystems usable
Filesystems must be mounted before they can be used
  - Mount points are commonly /mount or /mnt (older convention)
`mount [-alsvw] [-t fstype] [-o options] device mountpoint` 
: mount {device} to {mountpoint} (20:00)
  - `-a` mount all filesystems in /etc/fstab
  - `-r` mount as "read-only"
  - `-w` mount as "read-write"
  - `-t` specify filesystem type
  - `-o` specify additional options
`umount device mountpoint` 
: unmount {device}
### Making filesystems permanent
Mount changes are made permanent by inclusion in /etc/fstab
`vifs` 
: safely edit /etc/fstab
`lsblk -v` | `blkid`
: find UUID of block devices

## xk0004-11 Logical volume manager (LVM)
Procedure to create logical volums
  1. Create physical volumes (`pvcreate`)
  2. Create a volume group (`vgcreate`)
  3. Creage logical volume (`lvcreate`)
`pvcreate *partitions`
: create physical volumes from {*partitions}
`pvdisplay` | `pvs`
: verify creation of LVM
`vgcreate vg1 /dev/sdb1`
: create volume group {vg1} from {*devices}
`vgdisplay` | `vgs`
`lvcreate -L size vg -n name` : create logical volume of size {size} from volume group {vg} with the name {name}
`lvdisplay` | `lvs`
Logical volumes are formatted and mounted like regular disks
  - `mkfs.ext4 /dev/vg1/lv1`
  - `mount /dev/vg1/lv1 path`
Add more storage to the volume group/logical volume
```bash
fdisk /dev/scc # `n` create new partition `w` write changes
partprobe
pvcreate /dev/sdd1
vgextend vg1 /dev/sdd1
lvresize -L +1G /dev/vg1/lv1
df -h
resize 2fs /dev/vg1/lv1
df -h
lvdisplay
```
Remove LVM
```bash
umount path
lvremove /dev/vg1/lv1
vgremove /dev/vg1
pvremove /dev/sdb1 /dev/sdc1 /dev/sdd1
```

## xk0004-12 Filesystem Hierarchy Standard (FHS)
Applications typically stored in:
  - /bin: essential user command binaries, available to all users
  - /sbin: system binaries, required for system to boot (linked to /usr/sbin in RHEL)
  - /usr/bin: most user commands
  - /usr/sbin: non-essential system binaries
  - /opt : software not included with installation
Other key folders:
  - /boot: boot files and Linux kernel
  - /dev: device nodes representing hardware
  - /etc: configuration files
  - /mnt: temporary mount points for media
  - /proc: virtual file system containing data files for processes on the system
  - /sys: virtual file system containing data for hotplug devices (rf. /proc)
  - /usr: contains binaries and data shareable between users
`which`
`whereis`
`locate`
`find`

## xk0004-13-14 Editing files with vi
`:` : command mode
`i` : insert at current location
`I` : insert at beginning of line
`a` : append after cursor
`A` : append to end of line
`dw` : delete word
`:d` | `dd` : delete line
`nG` | `:n` : move to line {n}
`m,ncmd` : execute {cmd} across lines {m} through {n}
`:set number` : display line numbers
`:set number!` : disable line numbers
`vi +n file` : open {file} to line {n}
`o` : open new line after current line
`h|j|k|l` : motion commands
`/string` | `:s/string` : search for {string}
`:s/string/substitute` : replace {string} with {substitute}
`:%s/string/substitute` : replace all instances of {string} with {substitute}
`:n,ms/string/substitute` : replace {string} with {substitute} between lines {n} through {m}
`yy` : copy current line
`p` : put (paste) after current line
`:w!` : save, overwriting file
`:e` : switch to another file
`:e!` : switch to another file without saving current file
`:w` : save file
`:wq` | `:x` | `ZZ` : save and exit
`:q!` : exit without saving

## xk0004-15 Working with files
`ls`
  - `-l` list view
  - `-a` all files
  - `-h` human-readable file sizes
`cat`
`more`
`less`
`head`
  - `-n 5`
`tail`
  - `-f`
`touch`
`cp`
  - `-R` recursive
`mv`
`rm`
  - `-r`
`mkdir`
`rmdir`

## xk0004-16 Locating files
`find path expression`
  - `-perm` permission mode (e.g. `-perm +rwx`, `-perm -rwx`)
  - `-size` file size (e.g. `-size 2M`, `-size 2c`, `-size +20M`)
  - `-group` `-gid` (e.g. `find / -group dpezet`)
  - `-user` `-uid` (e.g. `find /home/dpezet -user dpezet`)
  - `-maxdepth n` maximum search depth of {n} (e.g. `find / -maxdepth 6 -name README.txt`)
`locate` : e.g. `locate README`
`whereis` : `whereis ls`
`which` : `which xterm`
`type` : `type cat` | `type -a ls`

## xk0004-17 Searching with grep
Regular expressions
`[ ]` : list of possible values
`-` : range of values
`.` : any single character
`*` : any number of characters
`^` : beginning of line
`$` : end of line
`( )` : subexpression or slice
`\` : escape character
`grep -F` | `fgrep` : fixed strings
`grep -E` | `egrep` : extended regular expressions

## xk0004-18 Manipulating text
`echo`
`printf`
`wc`
  - `-c` display byte count
  - `-m` display character count
  - `-l` newline count
  - `-w` word count
`sort`
  - `-t` delimiter
  - `-r` reverse sort order (descending)
  - `-k` column number
`sort -k 2 -t, ./cal-2019.txt`
: sort by column 2 in comma-delimited {cal-2019.txt}
`cut`
  - `-c` character number to extract
  - `-f` field number to extract
  - `-d` delimiter
`cut -f 2 -d, ./cal-2019.txt`
`diff`
  - `-i` case-insensitive
  - `-w` ignore whitespace
  - `-c` list of differences with three lines of context
`diff dracula.txt kermit.txt`
`awk`
`sed`

## xk0004-21 Managing kernel modules
kernels interact with the hardware, including RAM and file storage, and manage resources
kernelspace programs, such as systemd services, are privileged and have access to everything. But Linux's stability is thanks in large part to the Linux kernel's 
monolithic kernels are fast
Topics: modprobe, insmod, rmmod, lsmod, modinfo

## xk0004-20 Managing the Linux boot process


## xk0004-22 Graphical user interfaces
X.org Server
Alternatives to X include VNC and RDP, but X can be faster because the desktop is rendered natively on the client. But the connection is unencrypted, so typically the X session is built on top of an SSH tunnel when working remotely.
Wayland combines X Server and Compositor, default in Fedora
X Clients include GNOME, MATE, and KDE Plasma

## xk0004-25 Managing services with systemd
Systemd replaces the old _sysvinit_ init daemon, and all major distros use systemd by default, with the exception of Slackware. Systemd systems can be identified by the presence of the `/lib/systemd/systemd` executable, although `/sbin/init` which is conventionally indicative of sysvinit, may be present as a symlink to the systemd executable to maintain backwards compatibility.
`/lib/systemd/system/` contains _unit files_, text files with filenames ending in ".target" (runlevels), ".socket" (network port that allows applications to talk to one another via network connections), ".mount" (mount locations of disks, obviating the need for the `fstab` file, if so desired). They can be changed, but when they are updated by the system, user changes will be overwritten. User modifications should be placed in `/etc/systemd/system/` to override the settings in `/lib`.
Targets are like collections of files, they contain "Requires" and "Wants" fields which refer to other .target and .service files. The "Wants" field indicates services which must be kept running as a dependency, while the "After" field specifies services to be run along with the service in question.
When a package is removed, its unit file is also removed, when using a package file.  Unit files are needed for software that runs in the background and may not be created for software intended to be run interactively, but even some services that don't start automatically may still not create them. 
`systemctl enable/disable` commands actually create symlinks in unit files for various runlevels

## xk0004-23 Managing services with sysvinit
ysvinit is not a binary executable, but rather a system of scripts. Amazon Web Services uses Amazon Linux, which is based off of CentOS 6, which used Sysvinit. `/sbin/init` is typically the hallmark of sysvinit, but in modern systems it is actually symlinked to systemd
settings. /sbin/init then launches a series of scripts in serial. `/etc/rc.d` contains `rc.sysinit`, which is the first script called by init, and this script spawns others, tied to runlevels. 
Within `/etc/rc.d` there are other folders that correspond to runlevels, including `rc0.d`, `rc1.d` etc up to `rc6.d`. `rc.local` is also present, which historically would be run finally and would override the settings established by the runlevel defaults1
`/etc/inittab` is the initialization table, which determines the OS's default runlevel (on the line that reads "id:n:initdefault:" where {n} is the runlevel
`chkconfig` : turn services on or off for runlevels, defaulting to 3 or 5
`sudo chkconfig mysqld on` : turn MySQL service on
`sudo chkconfig mysqld off` : off
`sudo chkconfig --level 35 mysqld on` : turn MySQL for runlevels 3, 5
`chkconfig --list` display a table of all services with information on each runlevel, indicating whether or not it is enabled for that runlevel
`sudo service mysqld status` : check status of service mysqld
`init n` : immediately configure the system to runlevel {n}
`cron` is recommended for executing a _scheduled_ change in runlevel (previously the `telinit` command had been used)

## xk0004-23 Troubleshooting services, 1
`top`
`ps aux`
`systemd-analyze blame`
`lsof`

## xk0004-24 Troubleshooting services, 2
Niceness values range from -20 to +19 (smaller or more negative numbers mean a higher priority)
`bg`
`fg`
`jobs`
`%1`
`^z`
`^c`
`nice`
`renice`
`pgrep`
`kill`

## xk0004-26 Supporting printers
Most Linux distros handle printing the same way, a situation which was not always this way. When Apple switched to BSD, they open-sourced the printing solution (CUPS) which greatly benefited the situation for Linux printer drivers. CUPS is typically accessed through a web interface
Printer driver files are PPD files 
`lpadmin`

## xk0004-28 Understanding TCP/IP
`ip addr` : newer command, replacing `ifconfig`, that shows network adapters and associated ip addresses
DHCP IP assignment process (DORA):
  - _Discover_
  - _Offer_
  - _Response_
  - _Accept_
Although fake IPs can be used privately by using a router that does Network Address Translation, hiding it from the Internet, but IEEE has reserved 3 ranges of IP addresses that can be used privately.
  - Class C: 192.168.x.x/24
  - Class B: 172.16.x.x - 172.31.x.x/16
  - Class A: 10.x.x.x/8
`nslookup site` : retrieve IP number of {site}
`ss` : "socket statistics"
`ss -an` : do _name_-lookups and display _all_ information

## xk0004-27 Configure networking
`ip` : is the successor to the old commands `ifconfig` and `route` which isn't even installed on newer systems by default
`ip route` : see routing information
restarting services locally is often the answer
different distros store network configurations in various places, but generally one of two locations contain scripts that are run when interfaces go down:
  1. /etc/sysconfig/network-scripts : Red HAt
  2. /etc/sysconfig/network-scripts/ifcfg-eno1 : Ubuntu
`ip addr`
`sudo dhclient` : turn on the DHCP client and get a new address from the server
`sudo dhclient -r` : _release_ the IP address currently assigned and get a new one
`sudo systemctl restart network[.service]` : restart networking stack
`sudo service network restart` : restart networking stack (sysvinit)
Network configuration files are stored in various places, depending on distribution:
  - `/etc/sysconfig/network-scripts/` : directory containing various configuration files and scripts in Red Hat systemd
  - `/etc/network/` or `/etc/netplan/` : file called `99_config.yaml` in Ubuntu
  - `/etc/resolv.conf` : global DNS settings
  - `/etc/network` : global network settings
  - `/etc/hosts` : global hostnames
`sudo netplan apply` : apply network configuration changes in Ubuntu
`sudo hostnamectl set-hostname hostname` : permanently change hostname to {hostname} (stored in `/etc/hostname`)
`nmcli` : NetworkManager provides a CLI for consistent network configuration across a system
`nmcli device status` : display devices and status: "unmanaged" means NetworkManager isn't controlling it; on Ubuntu more devices may appear as unmanaged because Netplan is controlling them
`nmcli device show ens01` : show settings for network interface {ens01}
`nmcli connection edit ens01` : configure settings for network interface {ens01} in an interactive shell
### NetworkManager commands
`set connection.autoconnect yes`
`set ipv4.method manual`
`set ipv4.addr 192.168.0.2/24`
`set ipv4.gateway 192.168.0.1`
`save`
`save persistent`
`sudo nmcli connection reload`

## xk0004-28 Troubleshooting network connections
`ping` : utility to check network connections
`tracepath` : successor to `traceroute` which allows you to check IP addresses of each hop point on the way to a remote host. It is blocked by many ISPs because it is a newer tool, whereas traceroute is allowed because it is more established
Pinging loopback device (`lo`) allows you to see if the network driver is working properly. Pinging gateway (hop #1 on `traceroute` output) allows you to check connection between network adapter and router.
`nslookup host` : perform lookup on {host}, returning IP address
`dig` : returns actual response returned from server
`ip link` : show current link status (MAC addresses only)
`ip route` : display routing table
`ss -atp` : display all sessions, filtering to just TCP that are actively listening
`ss -tp` : see any active connection
`ss --route` : routing table, similar to `ip route`
`ss --program` : show programs that have open ports
`tcpdump` : allows inspection of actual IP packets, although WireShark is a better, GUI-based alternative (not installed on Manjaro by default)
`nc` : netcat utility (GNU and OpenBSD versions available, not installed by default)
`nc cnn.com 80` : connect to host cnn.com on port 80

## xk0004-31 Managing software with apt
## xk0004-32 Managing software with yum/DNF
## xk0004-33 Building from source
## xk0004-35 Linux security best practices, 1
## xk0004-36 Linux security best practices, 2
## xk0004-37 Securing apps with SELinux
## xk0004-38 Securing apps with AppArmor
## xk0004-39 Filtering traffic with firewalld
## xk0004-40 Filtering traffic with iptables
## xk0004-41 Backup and restore data

## xk0004-42 Configuring bash
Login scripts don't just apply to bash and will apply to all user logins, except for those in the user's home directory: 
  - `/etc/bashrc` functions and aliases
  - `/etc/profile` 
  - `/etc/profile.d/*` 
  - `~/.profile` 
  - `~/.bash_profile`
Bash configuration files:
  - `/etc/bashrc`
  - `~/.bashrc`
`set -o allexport` : make all variables global (not recommended)
Shell scripts can be refactored as functions in the .bashrc file. To make these functions available to all users, a function can be placed within the `/etc/bashrc` or in the `/etc/skel/.bashrc` which will be used as the template for all new users' profiles

## xk0004-43 Writing a bash script
## xk0004-44 Scheduling tasks, 1
## xk0004-45 Scheduling tasks, 2
## xk0004-46 Version control with git
## xk0004-47 Installing CentOS, 1
## xk0004-48 Installing CentOS, 2
## xk0004-49 Installing Ubuntu

