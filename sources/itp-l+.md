# CompTIA Linux+ (XK0-004) by ITPro.TV

## 01 Overview
Five domains of exam
  1. Hardware and system configuration
  2. System operation and maintenance
  3. Securty
  4. Linux troubleshooting and diagnostics
  5. Automating and scripting

## 02 Introduction to Linux
  - Historical background on development of Linux: Linux Torvalds, ca. 1991
  - Distinction between operating system and kernel
  - Lineage of distributions: CentOS from Red Hat, Ubuntu from Debian
  - Linux+ exam covers Ubuntu and CentOS

## 03 Linux Command Line
  - Access to command-line via 
    1) Boot direct to console
    2) Terminal software (XTERM, Konsole, Gnome Terminal, etc)
  - /bin/sh generally links to another shell, /bin/bash on CentOS and /bin/dash on Ubuntu
  - Execute commands in CLI by using _commands_ and _options_ or arguments
  - Common commands: ls, mkdir, cd, pwd, echo, touch, cp
  - Edit and view text files: cat, more/less, vim, nano, gedit
  - Tab auto-complete

## 04 Super user privileges
  - `su` substitute user
  - `su -` switch to root, including normal environment
  - `su username` login as {username}
  - `sudo cmd` execute {cmd} as root (password cached for 5 minutes by default)
  - `visudo` view and edit sudoers
  - `%techsupport localhost=/sbin/mount /mnt/cdrom, /sbin/umount /mnt/cdrom` example...
  - `sudoedit`

## 05 Managing users
  - `useradd username` add {username}
  - `useradd jdoe -c "John Doe" -e 2019/12/31 -s /bin/dash -d /home/john_doe` : `-c` add full name in the comment field ; `-e` expiration date ; `-a` default shell ; `-d` home directory
  - `usermod`
  - `usermod -l old new` rename user {old} to {new}
  - `usermod -L` lock account
  - `usermod -U` unlock account
  - `usermod -a -G group` add to {group}
  - `chsh` change shell
  - `chsh /bin/nologin` prevent an account from logging in interactively
  - `passwd username` set password for {username}
  - `chage` view or modify expiration
  - `chage -m days` minimum {days}
  - `chage -M days` maximum {days}
  - `chage -E date` expiry {date}
  - `chage -W days` warn {days} before expiration

## 06 Managing groups
  - `groupadd`
  - `groupdel`
  - `groupmod -n group new` rename {group} to {new}
  - `gpasswd -a user group` add {user} to {group}
  - `gpasswd -d user group` remove {user} from {group}
  - `gpasswd -A user group` add {user} as admin of {group}
  - `newgrp group` change context temporarily
  - `chgrp group`
  - `chown group`
  - `groups user` see group membership of {user}
  - /etc/group

## 07 Managing file permission
## 08 Advanced permissions
Topics: getfacl setfacl
  - `setfacl -m` : modify
  - `setfacl -s` : set
  - `setfacl -x` : remove
  - `tune2fs`

## 09  Partitioning disks
`fdisk`
`gdisk`

## 10 Linux filesystems
Two main choices for Linux: ext (long history) and xfs (Red Hat)
Filesystems must be mounted before they can be used
### Commands: 
`mkfs` : tool used to make file systems
`mkfs -t ext4` : specify "type", ext4 or xfs
`mkfs.ext4 partition` : format {partition} with the ext4 file system
`e2label partition Storage` : label ext {partition} "Storage" (18:40)
`xfs_admin -L Storage partition` : label xfs {partition} "Storage"
`resize4fs` : resize filesystems
`tune` : commands in /usr/sbin
`tune2fs` : change behaviors of ext file systems
`mkswap partition` : make swap partition out of {partition} (15:00)
`swapon partition` : tell system to use {partition} as swap partition
`mount [-alsvw] [-t fstype] [-o options] device mountpoint` : mount {device} to {mountpoint} (20:00)
`mount -a` mount all filesystems in /etc/fstab
`mount -r` mount as "read-only"
`mount -w` mount as "read-write"
`mount -t` specify filesystem type
`mount -o` specify additional options
`umount device mountpoint` : unmount {device}
`vifs` : safely edit /etc/fstab
`lsblk -v` | `blkid` : find UUID of block devices
### Files:
/etc/mkfs
/mount : mount point
/mnt : older conventional mount point
/etc/fstab : mounts must be registered here before they can become permanent

## 11 Logical volume manager (LVM)
Procedure to create logical volums
  1. Create physical volumes (`pvcreate`)
  2. Create a volume group from physical volumes (`vgcreate`)
  3. Creage logical volume from a volume group (`lvcreate`)
`pvcreate /dev/sdb1 /dev/sdc1` : create physical volumes from /dev/sdb1 and /dev/sdc1, two disks which already have a single partition on them each (not filesystem; MBR or GPT doesn't matter)
`pvdisplay` | `pvs` : verify creation of LVM
`vgcreate vg1 /dev/sdb1 /dev/sdc1` : create volume group {vg1} from {*devices}
`vgdisplay` | `vgs`
`lvcreate -L 20G vg -n Marketing` : create logical volume of size {size} from volume group {vg} with the name {name}
`lvdisplay` | `lvs`
```bash
mkfs.ext4 /dev/vg1/lv1
mount /dev/vg1/lv1 path
```
: Logical volumes are formatted and mounted like regular disks
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

## 12 Filesystem Hierarchy Standard (FHS)
### Applications
/bin: essential user command binaries, available to all users
/sbin: system binaries, required for system to boot (linked to /usr/sbin in RHEL)
/usr/bin: most user commands
/usr/sbin: non-essential system binaries
/opt : software not included with installation
### Other key folders:
/boot: boot files and Linux kernel
/dev: device nodes representing hardware
/etc: configuration files
/mnt: temporary mount points for media
/proc: virtual file system containing data files for processes on the system
/sys: virtual file system containing data for hotplug devices (rf. /proc)
/usr: contains binaries and data shareable between users
Topics: which whereis locate find 

## 13-14 Editing files with vi
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

## 15 Working with files
`ls`
`ls -l` list view
`ls -a` all files
`ls -h` human-readable file sizes
`cat`
`more`
`less`
`head -n 5`
`tail -f`
`touch`
`cp -R` recursive
`mv`
`rm -r`
`mkdir`
`rmdir`

## 16 Locating files
`find path expression`
`find path -perm` permission mode (e.g. `-perm +rwx`, `-perm -rwx`)
`find path -size` file size (e.g. `-size 2M`, `-size 2c`, `-size +20M`)
`find path -group` `-gid` (e.g. `find / -group dpezet`)
`find path -user` `-uid` (e.g. `find /home/dpezet -user dpezet`)
`find path -maxdepth n` maximum search depth of {n} (e.g. `find / -maxdepth 6 -name README.txt`)
`locate` : e.g. `locate README`
`whereis` : `whereis ls`
`which` : `which xterm`
`type` : `type cat` | `type -a ls`

## 17 Searching with grep
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

## 18 Manipulating text
`echo`
`printf`
`wc`
`wc -c` display byte count
`wc -m` display character count
`wc -l` newline count
`wc -w` word count
`sort`
`sort -t` delimiter
`sort -r` reverse sort order (descending)
`sort -k` column number
`sort -k 2 -t, ./cal-2019.txt` : sort by column 2 in comma-delimited {cal-2019.txt}
`cut`
`cut -c` character number to extract
`cut -f` field number to extract
`cut -d` delimiter
`cut -f 2 -d, ./cal-2019.txt`
`diff`
`diff -i` case-insensitive
`diff -w` ignore whitespace
`diff -c` list of differences with three lines of context
`diff dracula.txt kermit.txt`
`awk`
`sed`

## 21 Managing kernel modules
kernels interact with the hardware, including RAM and file storage, and manage resources
kernelspace programs, such as systemd services, are privileged and have access to everything. But Linux's stability is thanks in large part to the Linux kernel's 
monolithic kernels are fast
Topics: modprobe, insmod, rmmod, lsmod, modinfo

## 20 Managing the Linux boot process


## 22 Graphical user interfaces
X.org Server
Alternatives to X include VNC and RDP, but X can be faster because the desktop is rendered natively on the client. But the connection is unencrypted, so typically the X session is built on top of an SSH tunnel when working remotely.
Wayland combines X Server and Compositor, default in Fedora
X Clients include GNOME, MATE, and KDE Plasma

## 25 Managing services with systemd
Systemd replaces the old _sysvinit_ init daemon, and all major distros use systemd by default, with the exception of Slackware. Systemd systems can be identified by the presence of the `/lib/systemd/systemd` executable, although `/sbin/init` which is conventionally indicative of sysvinit, may be present as a symlink to the systemd executable to maintain backwards compatibility.
`/lib/systemd/system/` contains _unit files_, text files with filenames ending in ".target" (runlevels), ".socket" (network port that allows applications to talk to one another via network connections), ".mount" (mount locations of disks, obviating the need for the `fstab` file, if so desired). They can be changed, but when they are updated by the system, user changes will be overwritten. User modifications should be placed in `/etc/systemd/system/` to override the settings in `/lib`.
Targets are like collections of files, they contain "Requires" and "Wants" fields which refer to other .target and .service files. The "Wants" field indicates services which must be kept running as a dependency, while the "After" field specifies services to be run along with the service in question.
When a package is removed, its unit file is also removed, when using a package file.  Unit files are needed for software that runs in the background and may not be created for software intended to be run interactively, but even some services that don't start automatically may still not create them. 
`systemctl enable/disable` commands actually create symlinks in unit files for various runlevels

## 23 Managing services with sysvinit
sysvinit is not a binary executable, but rather a system of scripts. Amazon Web Services uses Amazon Linux, which is based off of CentOS 6, which used Sysvinit. `/sbin/init` is typically the hallmark of sysvinit, but in modern systems it is actually symlinked to systemd
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

## 23 Troubleshooting services, 1
`top`
`ps aux`
`systemd-analyze blame`
`lsof`

## 24 Troubleshooting services, 2
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

## 25 Supporting printers
Most Linux distros handle printing the same way, a situation which was not always this way. When Apple switched to BSD, they open-sourced the printing solution (CUPS) which greatly benefited the situation for Linux printer drivers. CUPS is typically accessed through a web interface
Printer driver files are PPD files 
`lpadmin`

## 26 Understanding TCP/IP
`ip addr` : newer command, replacing `ifconfig`, that shows network adapters and associated ip addresses
DHCP IP assignment process (DORA): Discover Offer Response Accept
Although fake IPs can be used privately by using a router that does Network Address Translation, hiding it from the Internet, but IEEE has reserved 3 ranges of IP addresses that can be used privately.
  - Class C: 192.168.x.x/24
  - Class B: 172.16.x.x - 172.31.x.x/16
  - Class A: 10.x.x.x/8
`nslookup site` : retrieve IP number of {site}
`ss` : "socket statistics"
`ss -an` : do _name_-lookups and display _all_ information

## 27 Configure networking
### Commands
`ip` : is the successor to the old commands `ifconfig` and `route` which isn't even installed on newer systems by default
`ip route` : see routing information
`ip addr`
`sudo dhclient` : turn on the DHCP client and get a new address from the server
`sudo dhclient -r` : _release_ the IP address currently assigned and get a new one
`sudo systemctl restart network[.service]` : restart networking stack
`sudo service network restart` : restart networking stack (sysvinit)
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
### Files
different distros store network configurations in various places, but generally one of two locations contain scripts that are run when interfaces go down:
  1. /etc/sysconfig/network-scripts : Red HAt
  2. /etc/sysconfig/network-scripts/ifcfg-eno1 : Ubuntu
/etc/sysconfig/network-scripts/ : directory containing various configuration files and scripts in Red Hat systemd
/etc/network/ or /etc/netplan/ : file called `99_config.yaml` in Ubuntu
/etc/resolv.conf : global DNS settings
/etc/network : global network settings
/etc/hosts : global hostnames

## 28 Troubleshooting network connections
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

## 31 Managing software with apt
### Commands
`apt-get` and  `apt-cache` are outdated commands that have been wrapped up in the new `apt`
`apt` : combines functionality of `apt-get` and `apt-cache`
`apt install package`
`apt install file` : useful as a replacement for `dpkg`, because `apt` will install dependencies from repos, if available
`apt update` : update the cache
`apt upgrade` : update all packages
`apt remove package` : remove {package}
`apt list searchexpression` : look for packages with {searchexpression}
`apt search`
`apt dist-upgrade` : upgrade distribution (Ubuntu patches)
`sudo apt-key add keyfile` : add GPG {keyfile} while adding a repo
### Files
/etc/apt/sources.list : file containing information on repos

## 32 Managing software with yum/DNF
`yum` "Yellowdog Update Manager"
`dnf` : "Dandified YUM", with basic syntax identical to `yum` but fully documented API and better dependency handling 
New repo definitions are added as text files. Use `yum` to install `rpm` packages so that it installs missing dependencies from the repos. For security, download GPG public keys to the home drive and add them to your GPG keychain so that you can use them to verify packages downloaded from repo mirrors. Unlike `apt`, `yum`'s `update` command updates the package database, upgrades software, and upgrades distribution software all at the same time.
### Commands
  - `yum list httpd` : list matching packages
  - `yum search httpd` : search by keyword
  - `yum info httpd` : display information about a package
  - `sudo yum update -y` : upgrade installed packages
  - `dnf remove httpd` : remove package
  - `dnf autoremove`
  - `yum erase package`
  - `sudo rpm --import gpgkey.asc` : import {gpgkey}, adding it to GPG keychain
### Files
/etc/yum.repos.d/ : directory containing initial location of repository definitions ("webmin.repo")
/etc/dnf/dnf.conf : eventual destination of repository definitions

## 33 Building from source
The `make` utility compiles into a `/run` folder
### Commands
  - `make`
  - `make config`
  - `make clean linux-x86-64` : compile for particular architecture
  - `sudo make install` : move executables and configuration folders into appropriate system folders

## 35 Linux security best practices, 1
CIA Triad: any security adjustment should improve at least one element
  - Confidentiality
  - Integrity
  - Availability
File and access auditing
### Commands:
  - `yum install audit` install audit package
  - `systemctl enable auditd` enable audit daemon
  - `ausearch --start today --loginuid 500`
  - `aureport --start 04/14/2019 00:00:00 --end 04/15/2019 00:00:00`
  - `shred -v --iterations=n` : write random data to an unmounted disk, for {n} passes
  - `cryptsetup --verbose --verify-passphrase luksFormat /dev/sdb1` : incorporate full-disk encryption on /dev/sdb1 `--verify-passphrase` forces it to ask for a passphrase twice
  - `cryptsetup luksOpen /dev/sdb1 storage1` : assign virtual name "storage1' to encrypted disk /dev/sdb1
  - `mkfs.xfs /dev/mapper/storage1`
  - `mount /dev/mapper/storage1 /mnt/storage1`
### Files
/etc/audit/audit.rules
/var/log/audit/audit.log

## 36 Linux security best practices, 2
Hardening SSH; default installs neglect some security considerations in order to enhance compatibility for general users. Security has to be considered on both client and server
  1. Obfuscate SSH port number (not effective)
  2. Remove support for SSHv1
  3. Delete existing keys and generate new SSH keys
    1. Delete keys
    2. Stop SSH service
    3. Rebuild the RSA key with the correct filename
    4. Rebuild the ECDSA key
    5. Restart the SSH service
When SSH connects, it typically produces two hashes of the ECDSA key fingerprint.
Copy user's known_hosts_ to /etc/skel/ to ensure new users have access to the fingerprints that you trust
### Commands:
  - `sudo systemctl stop sshd` : stop SSH service
  - `sudo ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key` : rebuild the RSA key; don't enter a passphrase
  - `sudo ssh-keygen -t ed25519 -f /etc/ssh/ssh_host_ed25519_key`
  - `sudo ssh-keygen -t ecdsa -f /etc/ssh/ssh_host_ecdsa_key`
  - `ssh-keyscan 127.0.0.1` display the public key of a host
  - `ssh-keyscan 127.0.0.1 >> ~/.ssh/known_hosts` append public key of a host to the known_hosts file
  - `ssh-keygen -lf /etc/ssh/ssh_host_ecdsa_key.pub` : generate a fingerprint from the public key (SHA256 by default)
  - `ssh-keygen -lf /etc/ssh/ssh_host_ecdsa_key.pub -E sha512` : generate a SHA512 fingerprint from the public key
  - `ssh-keygen -lf /etc/ssh/ssh_host_ecdsa_key.pub -E md5` : generate a MD5 fingerprint from the public key (MD5 is no longer recommended)
  - `ssh -1 dpezet@127.0.0.1` : request a SSHv1 connection
  `-2` v2 only 
  `-4` IPv4 only
  `-6` IPv6 only
### Files:
/etc/ssh/ssh_config : client config
  - "StrictHostKeyChecking" require the host's key be documented in the known_hosts file
/etc/ssh/sshd_config : server config
  - "Port 13386" open a nonstandard port number for SSH
  - "Protocol 2" specify SSHv2 and reject SSHv1 which is no longer secure because it uses password key lengths that are short enough to be brute-forced (might be a redundant change)
/etc/ssh/ssh_host_..._key : private keys
/etc/ssh/ssh_host_..._key.pub : public keys
$HOME/.ssh/known_hosts : contains public keys of every host connected to

## 37 Securing apps with SELinux
"Security Enhanced Linux", developed by NSA, is a system that puts walls around everything an application can do by putting mandatory access controls. It allows fine-grained control of an application's reach into the filesystem and TCP/IP stack.
SE Linux Modes:
  1. Enforcing: Access in violation of ACL is blocked
  2. Permissive: Access not conforming to ACL is logged; handy for development
  3. Disabled: ACL is not applied
### Commands:
  - `sestatus` : see if you have SELinux installed
  - `setenforce enforcing|1|permissive|0` : change mode of SELinux
  - `ls -lZ` : display SELinux contexts for files
  - `ps auxZ` : display SELinux contexts for processes
  - `chcon -Rv --type=httpd_sys_content_t /website` : "change context" for website directory
  - `restorecon -Rv /website` : restore security context default in the policy
  - `sudo yum install policycoreutils-python` : install policy toolkit
  - `semanage fcontext -a -t httpd_sys_content_t /website` : amend policy to add a file context 
  - `semanage port -a -t http_port_t -p tcp 8080` : add a port context
  - `semanage port -l` : display all ports with attached types
### Files:
/etc/selinux/config
  - "SELINUX=enforcing" if changed to "permissive", it would be placed in "permissive" mode upon reboot
  - "SELINUXTYPE=targed"
/var/log/audit/audit.log : SELinux's audit file

## 38 Securing apps with AppArmor
AppArmor is a competitor to SELinux that creates profiles that focuses on individual apps.
### Commands
`apt install apparmor-utils`
`apparmor_status`
`apt policy apparmor`
### Files
/etc/apparmor.d/ contains files corresponsding to pathnames with slashes replaced by periods

## 39 Filtering traffic with firewalld
firewalld took over from iptables during the transition from sysvinit to systemd in RH systems. Like iptables, firewalld uses the netfilter protocols. It works by placing network traffic into zones, and often commands have to be written twice: once to affect running configuration and again to store the change to disk.
### Commands:
  - `sudo firewall-cmd --state` confirm firewalld is running
  - `firewall-cmd --get-default-zone` display the default zone
  - `firewall-cmd --get-active-zones` zones that actually have an interface attached
  - `firewall-cmd --new-zone=testlab` firewalld will demand the additional option `--permanent` meaning the change will be written to disk
  - `firewall-cmd --reload` load running configuration from disk
  - `firewall-cmd --get-services` display names of all available services
  - `firewall-cmd --add-service=ftp --permanent; firewalld-cmd --add-service=ftp`
  - `firewall-cmd --list-services` display services loaded in memory
    - `--remove-service`
    - `--add-port=8080/tcp` add nonstandard port
    - `--add-port=50000-60000/udp` add a range of nonstandard ports
    - `--list-ports` see approved port numbers
### Files:
/etc/sysconfig/network-scripts/ifcfg-ens33 : interface settings
/usr/lib/firewalld/services : display .xml files that define services
  - "ZONE=public" firewalld zone

## 40 Filtering traffic with iptables
iptables is one of the most popular firewalls used in Linux. Like firewalld, it is really a frontend for the netfilters service. 
Rules are defined by identification and one of 3 actions:
  - ACCEPT
  - REJECT
  - DROP useful in DDoS attacks, to prevent profusion of outbound messages
  - LOG is used in conjunction with one of the 3 main actions
Chains: places where rules can be placed
  - INPUT : best place to filter incoming traffic
  - OUTPUT
  - FORWARD
### Commands:
  - `iptables --list` can be deceiving because the iptables utilities will respond even if the service is not running
  - `systemctl stop firewalld` firewalld has to be stopped before iptables can be started.
  - `systemctl mask firewalld` prevent firewalld from being started inadvertently by another process; better than `disable`
  - `systemctl enable --now iptables`
  - `iptables --list-rules` display rules as written on disk
  - `iptables -A INPUT -p tcp --dport 80 -j ACCEPT` accept TCP traffic to port 80; this rule will appear in the list of rules (`iptables --list`)
  - `iptables -A INPUT -p tcp --dport ssh -s 10.0.222.222 -j ACCEPT` accept SSH traffic from a particular source
  - `iptables-save` display what the running configuration would look like if written to disk; must be redirected to a file
  - `iptables -F` reload configuration file
  - `systemctl restart iptables`
  - `iptables -vnL --line` show statistics for configuration lines
  - `watch -n 0.5 iptables -vnL` will update twice a second, producing a sort of dashboard
### Files:
/etc/sysconfig/iptables : location of saved configu

## 41 Backup and restore data
### Commands:
  - `tar cvzf backup.tgz ~/Documents`
  - `tar xvzf ~/Documents/ backup.tgz`
  - `dar` "disk archiver", replaces `tar`
  - `dar -R ~/Documents -c full.bak` create a full backup of {~/Documents}
  - `dar -R ~/Documents -c diff1.bak -A full.bak` create a differential backup (every differential backup takes the full backup as reference
  - `dar -R ~/Documents -c incr1.bak -A full.bak` create incremental backups
  - `dar -x full.bak; dar -x incr1.bak -w` : restore backups
  - `dd if=/dev/sda of=/dev/sdb`
Topics: mirrorvg, scp, sftp, rsync

## 42 Configuring bash
### Commands
`set -o allexport` : make all variables global (not recommended)
### Files
Login scripts don't just apply to bash and will apply to all user logins, except for those in the user's home directory: 
/etc/bashrc functions and aliases
/etc/profile 
/etc/profile.d/* 
~/.profile 
~/.bash_profile
Bash configuration files:
/etc/bashrc
~/.bashrc
Shell scripts can be refactored as functions in the .bashrc file. To make these functions available to all users, a function can be placed within the `/etc/bashrc` or in the `/etc/skel/.bashrc` which will be used as the template for all new users' profiles

## 43 Writing a bash script

## 44 Scheduling tasks, 1
  - `at` schedules one-time tasks using an interactive shell
  - `cron` schedules recurring tasks

### Commands:
  - `at` : execute a command at a particular time, one-time
  - `at 3 PM Fri /home/dpezet/backupdb.sh`
  - /bin/bash: : command not found
  - `atrm 3` : remove job number 3
  - `cron` : execute recurring tasks at a predetermined time
  - `crontab -e` : edit user cron table (file is stored as `/var/spool/cron/user`)
  - `crontab -eu user` : edit {user}'s user cron table
  - `anacron` : tool that will run jobs that were missed if the system was turned off, according to rules set in `/etc/anacrontab`
### Files:
#### at config files
If the following two files don't exist, only root is allowed access to `cron`
/etc/at.allow : any user listed will be allowed to use `at`
/etc/at.deny : any user listed will _not_ be allowed to use `at`
#### cron config files
If the following two files don't exist, only root is allowed access to `cron`
/etc/cron.allow
/etc/cron.deny
/etc/crontab : contains scheduling in a unique format (`m h d M D username command` where m is minute, h is hour, d is day of month (1-31), M is month (1-12), and D is day of week (0-6 where Sunday is 0, or sun, mon, tue, etc...)
  - `53 23 * * * root /usr/lib64/sa/sa2 -A` : run a task at 11:23
  - `*/10 * * * * root /usr/lib64/sa/sa1 1 1` : run a task every ten minutes
/etc/cron.d/
/etc/cron.hourly/
/etc/cron.daily/
/etc/cron.weekly/
/etc/cron.monthly/
/var/spool/cron/ : directory containing user cron tables for individual users
/etc/anacrontab : table of anacron jobs

## 45 Scheduling tasks, 2

## 46 Version control with git
  - `git clone`
  - `git config --global user.email "you@example.com"`
  - `git config --global user.name "Your name"`
  - `git init`
  - `git status`
  - `git add`
  - `git commit -m -m "Commit message"`
  - `git log`
  - `git branch` : list branches
  - `git checkout -b` : create a branch
  - `git checkout master; git merge; git status` : switch back to master and resync

## 47 Installing CentOS, 1
CentOS (Community Enterprise Operating System) recompiled, debranded version of RHEL. Many in CentOS community are actually RH employees. CentOS serves as a kind of proving ground for the full enterprise version of Red Hat.  RHEL (Red Hat Enterprise Linux) costs a few hundred dollars a year, including support.  
(CentOS Homepage)[https://www.centos.org/] lists recommended requirements for CentOS: 392MB of RAM for command-line only, 512 MB for graphical install.  
GNOME desktop environment is the one that you have to be familiar with for the purpose of the exam 
Standard system security profile
## 48 Installing CentOS, 2
## 49 Installing Ubuntu

