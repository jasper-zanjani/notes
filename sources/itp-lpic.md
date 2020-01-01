# CompTIA Linux+ powered by LPI (LX0-103-LX0-104) by ITProTV
Shells include [`bash`][bash], [`csh`]([)# "C Shell"), [`tcsh`](# "TENEX fork of `csh`"), and `dash` [^](# "Command Line basics")\
Commands: `cd`, `uname -a`, `pwd`, `echo`, `exit`, `logout`, `type`, `type -a`, `history`, `!!`. `history -c`
Keybindings; `^p`, `^r`, `^s`, `^g`, `^a`, `^e`, `^LeftArrow`, `^RightArrow`, `^k`, `^x`, `^t`

`cat`, `od`, `sort`, `split`, `tr`, `nl`, `cat -n`, `pr`, `head`, `tail`, `less`, `cut` [^](# "Streams, redirection, and pipes")

`grep`, `grep -E`, `sed` [^](# "Processing text")

## 08 Using RPM
Red Hat systems do their own thing. Other distributions based on Red Hat, like Fedora and CentOS, use Red Hat's package manager. In the days when all software was compiled by the end-user, Red Hat pioneered with the Red Hat Package Manager (RPM).  RPM can refer to the package manager as well as the packages themselves. RPM utility does not resolve dependencies.
RPM filenames have a structure: {name}-{version}-{build number}-{Red Hat version}-{processor architecture}.rpm. Some packages have "noarch" for processor architecture, meaning they are processor agnostic

`rpm -i package` : install {pkg} 
`rpm -U package` : update {pkg}, this command can also be used to install 
`rpm -Uvhi package` : `vh` gives *visual* indicators of progress, namely progress bars 
`rpm -qi package` : *query* for information about a package 
`rpm -e package` : remove or *erase* a package; won't touch installed dependencies 
`rpm --install gpgkeyurl` : install a GPG key from a package developer
`sudo rpm --import gpgkey.asc` : import {gpgkey}, adding it to GPG keychain
RPM files are CPIO archives, comparable to a ZIP or TAR file. Red Hat provides the application `rpm2cpio` to convert the file into a format which can then be extracted.
`rpm2cpio rpmfile > cpiofile` : convert {rpmfile} to CPIO format, saving to {cpiofile}
`cpio -i --make-directories < cpiofile` : extract {cpiofile}, preserving directories
`rpm2cpio rpmfile | cpio -i --make-directories` : convert {rpmfile} and extract it to the current directory
#### yum
Red Hat systems also have a second package manager called yum (Yellow Dog Update Manager, Yellow Dog was a variation of Red Hat for Power PC systems), which is more commonly used nowadays. It does track dependencies and removes them, if they are no longer used by an installed package. Repo files can be added in `/etc/yum.repos.d/`
`yum list package` : query for {package} on the repos
`yum info package` : information on an installed package
`yum install package` : install a package, including dependencies
`yum update package` | `yum upgrade package` 
### Files
`/etc/yum.repos.d/reponame.repo` : name of new yum repo {reponame}

## 09 Using Debian packages

### dpkg
Similar to RPM, it doesn't do dependency checking
`dpkg -I` : information about installable package
`dpkg -i | --install`
`dpkg --configure` : reconfigure an installed package
`dpkg -r | --remove`
`dpkg -P | --purge`
`dpkg --get-selections` : list installed packages
`dpkg -I | --info` : display information about installable package
`dpkg -l | --list` : list packages that match the specified search pattern
`dpkg -p` | `dpkg --print-avail` : info about installed packages
### apt
`apt-cache showpkg package`
`apt-cache stats`
`apt-cache unmet`
`apt-cache depends package`
`apt-cache rdepends package`
`apt-cache pkgnames searchexpression` : list installed packages that begin with the specified string
`apt-get update`
`apt-get upgrade`
`apt-get dist-upgrade`
`apt-get install`
`apt-get remove`
`apt-get -d/--downloadonly`: download but do not install
  - `-f/--fix-broken` : attempt to fix broken depend
  - `-q/--quiet` : no output or progress info
  - `-y/--yes/--assume-yes` : answer everything with yes
  - `--no-upgrade` do not upgrade if older version already installed
`dselect` : terminal menu-based interface for browsing through packages
`aptitude` : terinal and GUI-based interface for browsing through packages
Synaptic
### Files:
`/etc/apt/sources.list.d/` : directory containing APT repos

## 10 Managing shared libraries
Shared libraries avoid multiple versions and copies of the same libraries. The admin will have to deal with this when compiling software from source, such that a package manager is not available to automatically resolve dependencies. `ld` is the library daemon that manages shared libraries. Major versions of shared libraries are actually symlinks that point to the current version with the full semver number. Shared library files end in ".so" and can be found in subdirectories of folders like /usr/lib. References to earlier minor versions of the library will actually point to the up-to-date library by means of a symlink
`ldconfig -v` : see all shared libraries 
`ldd program` : display dependencies of a particular program

## 11 Managing processes
Topics: uname -n/--nodename, uname -v/--kernel-version, uname -a/--all, ps, top jobs, pgrep, jobs, fg, bg, nice, renice, kill, killall

## 12 Configuring hardware, 1
Hardware devices are mapped by Udev to /dev, and HAL populates the files with XML data. Dbus enables communication between HAL and the software process
Hardware drivers for Linux are actually kernel modules
### Commands
`dmesg` : shows all the messages displayed on boot: look for "error"
`modprobe module` : load kernel {module}
Topics: lsmod, dmesg, lspci, modprobe, rmmod
### Files
/etc/udev/rules.d : one of the folders Udev may have used in the past as a source for rules how to map hardware to files
/lib/udev/rules.d/ : rules Udev uses to map hardware to files
/proc/modules/ : virtual directory storing loaded modules (equivalent to `lsmod`)
/sys/bus/ : another directory where drivers are stored

## 13 Configuring hardware, 2
Redirecting video output to serial port (for headless servers) is an example task which exercises some of the topics that will be tested on the exam.
  1. Edit grub.conf, adding new tty "ttyS1"
  2. Register new tty in /etc/securetty by appending "ttyS1" to end of file
  3. Create /etc/init/ttys1.conf 
    ```
    start on runlevel [1345]
    stop on runlevel [S06]
    respawn
    instance /dev/ttyS1
    exec /sbin/agetty ttyS1 9600 vt100-nav # generate tty interface
    ```
  4. Modify /etc/inittab, changing default runlevel to 3: "id:3:initdefault:"
### Files
/boot/grub/grub.conf : add "serial --unit=1 --speed=9600" and "terminal --timeout=300 console serial" after "hiddenmenu"; add "console=tty0 console=ttyS1,9600n8" to kernel line
/etc/securetty : list of ttys
/etc/init/ : location of "ttys1.conf" which was created

## 14 Configuring hard disks
Three-step process for preparing a hard disk:
  1. Partition
  2. Format (filesystem)
  3. Mount
For some devices like CDs, the OS will automatically mount it, but if not you have to use the `mount` command
### Commands
`fdisk` : command-line partition creator for MBR disks
`partprobe` : force system to look for new partitions
`gdisk` : format partitions on GUID Partition Table (GPT) disks
  - `p` : print partition list
  - `l` : list available partition types
  - `n` : new partition
`parted` : for MBR, GPT, APM, and BSD
`GParted` : GUI-based tool for partitioning disks
`mkfs` : make filesystem wrapper for about a dozen other commands that apply filesystems to partitions (stored in both /usr/bin and /usr/sbin on Manjaro)
`mkfs -t ext4 /dev/sdb1` : form ext4 filesystem on /dev/sdb1 (28:00)
`mount /dev/cdrom /mnt/cdrom` : mount the CD drive to /mnt/cdrom
`df -h` : show drive utilization
### Files:
/etc/fstab : filesystem table, partitions need to be placed here to be permanent

## 15 Logical volume manager
Logical volumes can be resized, but the filesystem formatted upon it also needs to be resized when you add storage.
Topics: fdisk, pvcreate, pvdisplay, vgcreate, vgdisplay, lvcreate, mkfs, mount, partprobe, pvcreate, vgextend, lvresize, df -h, resize2fs, lvdisplay, lvremove, vgremove, pvremove
### Commands:
`pvcreate /dev/sdb /dev/sdc` : bring sdb and sdc into LVM (4:00)
`vgcreate vg1 /dev/sdb /dev/sdc` : create {vg1} from physical device paths (6:00); this creates "vg1" in /dev
`lvcreate -L 20G vg1 -n Marketing` : create logical volume 20 gigabytes in size from volume group {vg1} named "Market" (10:00); this creates a device named "dm-0" in /dev, and /dev/vg1/Marketing appears as a symlink to "dm-0" ; another symlink named "vg1-Marketing" appears in /dev/mapper
`mount /dev/vg1/Marketing /mnt/Marketing` : mount logical volume {Marketing} to /mnt/Marketing
`lvresize -L +16G /dev/vg1/Marketing` : resize logical volumes, adding 16 gigabytes to {Marketing}
`resize2fs /dev/vg1/Marketing` : resize ext filesystem on Marketing to fill up all unallocated space
`vgextend vg1 /dev/sdd` : add new drive {/dev/sdd} to existent volume group {vg1} 
`pvdisplay`
`vgdisplay`
`lvdisplay`

## 16 Filesystem health, 1
Mounts are only persistent after being registered in fstab
### Structure of fstab
each field is separated by whitespace
  - <filesystem> "UUID=..."; Five different ways drives can be identified; in GPT it is most commonly UUID or Label.
    1. Filename:  /dev/sda, /dev/sdb, etc
    2. Label:     LABEL=Sales
    3. UUID:      UUID=...  (UUIDs are preferable over filenames because filenames can change based on what happens during boot process)
    4. GPT Label: PARTLABEL=EFI
    5. GPT UUID:  PARTUUID=...
  - <mountpoint> "/boot/efi"
  - <type>  "vfat"
    - "auto" is also an option, but it is considered dangerous for writable hard disks
  - <options> "defaults,noatime"
    - auto/noauto: automatically mount at boot
    - user/nouser: allow non-root users to mount
    - exec/noexec: allow executables
    - ro: read-only
    - rw: read-write
    - sync/async: perform synchronous or asynchronous disk I/O operations
    - dev/nodev: allow block devices (i.e. /dev)
    - usrquota/grpquota: enable user or group quotas
    - suid: allow the use of SetUID and SetGID
    - defaults: equivalent to "rw,suid,dev,exec,auto,nouser,async"
  - <dump> "0" : once served as a flag to `dump` utility, no longer used
  - <pass> "2"
### Commands
`lsblk -f`: list UUID, Label, and filesystem type for non-GPT drives
`blkid` : list GPT UUID (PARTUUID), GPT Label (PARTLABEL) for GPT drives
`tune2fs -L Sales /dev/vg1/Sales` : assign label "Sales" to /dev/vg1/Sales
### Files
/etc/fstab : filesystem tab, format varies from distro to distro

## 17 Filesystem health, 2
### Commands
`dd if=/dev/zero of=/mnt/Accounting/file.bin count=1000` : fill up {file.bin} with a gigabyte of zeros
`du` : display disk usage of a file or folder
`du -ch path` : display human-readable sizes of subdirectories of {path}
`df` : display total disk utilization
`fsck` : check filesystem for errors, actually a wrapper for a suite of other filesystem checkers that are specific to filesystems; needs drive to be unmounted
`fsck -t ext3 /dev/sdc1` : check sdc1 with ext3 filesystem; if the filesystem specified is wrong it will raise an error
`mkfs` : frontend for format utilities
`mkfs -T filesystemtype` : specify {filesystemtype} of filesystem to be created
`debugfs` : creates a temporary filesystem that resides in RAM
`dumpe2fs` : print out detailed filesystem information
`dumpe2fs -h /dev/sda1`
`tune2fs` : tune the performance of a filesystem
`tune2fs -c 60 -i 6m /dev/sda1` : run `fsck` at intervals of 60 mounts or 6 months, whichever come first
`tune2fs -c 1 /dev/sda1` : run `fsck` on every boot
`tune2fs -L Storage /dev/sdb1` : assign label "Storage" to {/dev/sdb1}
`tune2fs -l /dev/sda1 | grep volume` : 
`tune2fs -j /dev/sdc1` : enable journaling, converting ext2 to ext3 (fstab filesystem value must be changed immediately so that the drive doesn't become corrupted on reboot

## 18 File management commands, 1
Topics; ls, cp, mv, rm, touch, tar, cpio, dd, mkdir, rmdir

## 19 File management commands, 2
Topics: find, cpio, |

## 20 Ownership and permissions
Topics: chgrp, chown, chmod

## 21 Disk quotas *
2 types of quotas:
  1. User quotas (`usrquota` in fstab)
  2. Group quotas (`grpquota` in fstab)
Quotas are usually assigned in block amounts (use `dumpe2fs` to find block size to estimate disk usage)
### Commands
`mount /dev/sdb1 /mnt/Sales -o defaults,usrquota,grpquota` remount the drive with usrquota and grpquota enabled (same as rebooting after changes to fstab)
`quota user` check quota status of {uwer}
`quotacheck` create the quota database
`quotacheck -cug /mnt/Sales` : `-c` create the database, `-u` user database, `-g` group database; these create "aquota.group" and "aquota.user" at the mount location
`quotaon -a` : turn on all quotas
`quotaon -u user` : turn on quotas for {user}
`quotacheck -avug`
`edquota -g`
`repquota -vsg /home` : `-s` human readable `-g` group
`repquota -vsu /home`
`quotaoff -a`
Topics: edquota, repquota, quotaon, quotaoff

## 22 Locating files
Topics: find, locate, whereis, which, type

## 23 Installing bootloaders, 1
Lots of variance between distros. Unlike BIOS, EFI isn't entirely loaded on a chip, but rather somewhere on the HDD. "Grand Unified Bootloader" has taken the mantle from LILO "Linux Loader". Secure Boot requires a digitally signed bootloader; in practice this means bootloaders approved by Microsoft, Canonical and Red Hat. Fortunately, most hardware allows a user to disable Secure Boot. GRUB is the main bootloader used by most major distributions today, taking the mantle from LILO
### GRUB installation commands
`grub-install /dev/sda` install GRUB from a live key to HDD (BIOS)
`efibootmgr -c -l \\EFI\\redhat\\grub.efi -L GRUB` : UEFI
### GRUB Legacy
`default=0 ` refers to first OS in the list of options
`timeout=n` number of seconds that allows for choice of alternative OS choice
`splashimage=(hd0,0)/grub/splash.xpm.gz` because udev hasn't run when the bootloader runs, the (hd0,0) refers to the first hard drive found
`hiddenmenu` menu only shown on keypress of Enter
`title OS...` menu option in bootloader
`rootnoverify (h1,0)` turn control over to another bootloader (for Windows)
`makeactive`
`chainloader +1`
### Files:
/boot/grub/grub2/grub.cfg config file used by GRUB2 (might also be in /boot/grub/)
/boot/grub/grub.conf config file used by GRUB Legacy (also menu.lst)

## 24 Installing bootloaders, 2
GRUB2: biggest change is GRUB2 uses a different config file (grub.cfg); can be in /boot/grub/ or in /boot/grub/grub2; most importantly, in GRUB2 the user is dissuaded from manually editing the config file, but rather to use the `grub2-mkconfig` utility (also `grub-mkconfig` on some systems, including Manjaro, or also `update-grub` `update-grub2`)
`menuentry` instead of "title" in GRUBv1
### Files:
/etc/default/grub default values for GRUB
/etc/grub.d/ directory containing logic that grub-mkconfig will use for all the various sections of the config file; these should be edited instead of directly editing grub.cfg

## 25 SysV initialization process

## 26 SystemD initialization process

## 27 Configuring X Windows, 1
GNOME is the most common desktop envirionment, used by Red Hat and Ubuntu. KDE was popular a few years ago, but distros have moved away from it despite the sponsorship of companies like Google. File managers are one of the key points of differentiation between DEs.
Components of desktop environments
  - Window manager
  - compositor actually generates the graphics
  - Windowing server, universally X
If converting a headless system to one with a GUI, you have to make sure to edit initialization settings (edit inittab or `systemctl set-default graphical.target`) to boot to a GUI
GDM and KDM are the login screens (23:00)
### Commands
`yum groupinstall "X Windows System" "KDE Desktop" "Fonts"`
`Xorg -configure`
`xwininfo` return geometry and other window information
`xdpyinfo` return display information
`gconf-editor` : configure GDM
### Files
/etc/sysconfig/desktop : specifies GDM or KDM (RH)
  - DESKTOP="KDE"
    DISPLAYMANAGER="KDE"
  - DESKTOP="XFCE"
    DISPLAYMANAGER="XDM"
  - DESKTOP="Gnome"
    DISPLAYMANAGER="GDM"
/usr/share/X11/xorg.conf.d/ : directory storing default system configuration files
$HOME/xorg.conf : user configuration file which will override the default
/etc/gdm/custom.conf : Gnome config
/usr/share/config/kdm/kdmrc : KDE config
/etc/X11/xdm/xdm-config : XFCE config
/usr/share/lightdm/lightdm.conf.d/*.conf : LightDM config
/etc/lightdm/lightdm.conf.d/*.conf : LightDM config
/etc/lightdm/lightdm.conf : LightDM config

## 28 Configuring X Windows, 2
Troubleshooting issues with graphical interfaces
LightDM : login screen used by Ubuntu
Configuring LightDM (28:00)
  1. Create /etc/lightdm/lightdm.conf.d/50-custom.conf
  2. "[SetDefaults]"
  3. "allow-guest=false" disable guest account
  4. "greeter-show-manual-login=true" allow users to type in their own username
### Commands
`Xorg -configure` : scans systems and attempts a best configuration; will generate $HOME/xorg.conf.new which is the resulting config file
`^A-<Backspace>` | `^A-x` : drop to CLI, depending on distro
`X` | `startx` : start GUI
`X -config $HOME/xorg.conf.new` : test the automatically generated config (8:00)
`gconf-editor` : GUI-based configuration editor for GNOME
`xwininfo` : CLI utility that will provide information about a window clicked, such as dimensions, position, etc (has to be installed)
`xdpyinfo` : show all information about display
### Files
/usr/share/config/kdm directory containing configuration files for KDE, including kdmrc (16:00)
/usr/share/lightdm/light.conf.d/ : directory containing configuration files for LightDM, all of their filenames begin with "50-" and end with ".conf" filename extension
/etc/lightdm : directory containing users.conf; you can create /lightdm.conf.d which can then contain additional config files which will be loaded as well

## 29 Remote access to X
X is made up of a server and a client, so remote connections are possible, although by default these connections are unencrypted. Using the technique of X forwarding, it is possible to encrypt these connections by using an SSH tunnel.
  1. Make sure X Windows accepts remote connections
  2. Make sure SSH supports the forwarding option
  3. SSH into the server with X forwarding (`-Y` option)
  4. Run programs remotely from within the SSH shell
### Commands
Add user {dpezet} to ACL
```sh
xhost si:localuser:dpezet
```
Allow clients from any host to connect (not unsafe if you use a firewall that allows only SSH)
```sh
xhost +
```
Establish an SSH connection
```sh
ssh dpezet@10.1.230.118
```
Allow X forwarding
```sh
ssh -Y dpezet@10.1.230.118
```
By default will display ":0", but after establishing an SSH connection with X 
```sh
echo $DISPLAY
```

### Files
/etc/ssh/ssh_config : System config file for SSH
  - "ForwardX11 no" will disallow X forwarding
  - "ForwardX11Trusted yes" will allow X forwarding if they have a certificat

## 30 X Accessibility
Various options are available for universal access to people who are disabled or impaired; many are available from the login screen.
  - on-screen keyboard
  - screen reader
  - screen magnifier
  - color contrast enhancement
  - text enlargment
  - sticky keys
  - ignore duplicate keypresses (Bounce Keys)
  - press and hold keys to accept them (Slow keys)

## 31 Localization
`locale` : produce all environment variables with current values; they may individually be reassigned to fine-tune system's localization
  - "LC_ALL" will override all others
`locale -a` : display all localizations currently supported by the system
`yum groupinstall french-support` : install support for French localizations
`iconv -f ASCII -t UTF-8 < input.txt > output.txt` convert files from one character set to another
`localectl` change system locale on systemd
`locale currency_symbol` display currency symbol for current system locale
`localectl set-locale LANG=fr_FR.utf8` change locale to French (requires reboot)
`tzselect` : select timezone
/etc/localtime links to a binary timezone in /usr/share/zoneinfo/...
`hwclock` BIOS clock
`hwclock --hctosys` set hardware clock to software clock
`hwclock --systohw` set software clock to hardware clock
`date` : verify locale change
`date -s "20 JUN 2016 12:00:00"` set software clock
/etc/ntp.conf : network time protocol config

## 32 Managing users and groups


## 33 System logging


## 34 System time


## 35 Scheduling jobs


## 36 Understanding TCP/IP, 1
IP addresses, classes, subnet masks, Private vs. public IPs, IPv6

## 37 Understanding TCP/IP, 2
TCP and UDP ports
`netstat -an` : show network traffic

## 38 Configuring networking
5 essential items of information needed for network communication:
  1. IP address
  2. Subnet mask
  3. Default gateway
  4. DNS servers
  5. Hostname (optional)
### Commands:
`ifconfig` : "interface configuration" (not on modern distros)
`ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0` : apply an IP address to the interface and bring it up (turn it on) (3:30)
`ifdown eth0` : bring interface {eth0} down (turn it off) (4:15), as long as NetworkManager isn't interfering (stop the service)
`ifup eth0` : bring interface {eth0} up
`ifconfig eth0 up|down` : bring interface {eth0} up|down
`ifconfig eth0 up 192.168.0.100 netmask 255.255.255.0`
`route add default gw 192.168.0.1`
`ifconfig`
`route-n`
`chkconfig NetworkManager off`
`service network restart` : restart network service
`systemctl restart network.service`
`chkconfig NetworkManager off` : Upstart
`systemctl disable NetworkManager.service` : 
`service NetworkManager stop`
`nslookup www.google.com` 
### Files:
/etc/services : enable, disable network services
/etc/sysconfig/network-scripts : directory containing network configuration files on Red Hat systems 
/etc/sysconfig/network-scripts/ifcfg-eth0:
  - "NM_CONTROLLED" refers to NetworkManager
  - "HWADDR" is MAC address
  - 'ONBOOT="yes"'
  - added 'BOOTPROTO="static"' (9:30)
  - added 'GATEWAY="10.1.230.1"' (10:00)
  - added 'NETMASK="255.255.255.0"'
/etc/sysconfig/network : file containing persistent central network configuration settings, such as hostname, and gateway if your system has more than one network adapter
/etc/network/interfaces : directory containing network configuration files on Debian systems 
/etc/hosts : overrides DNS for name lookups; IP address followed by hostnames, separated by whitespace
/etc/hostname : `hostname` is not normally persistent
/etc/resolv.conf : DNS servers
/etc/nsswitch.conf : controls lookup system beyond just DNS
/etc/files.dns : NIS+ servers for Solaris servers

## 39 Diagnosing networking, 1
You test from the inside out, starting with loopback address(ping yourself)
  1. ping loopback address (software, i.e. TCP/IP stack)
  2. ping interface (hardware)
  3. ping another host on the network
  4. ping gateway
  5. ping an IP address on the Internet
  6. ping a hostname
To troubleshoot DNS server
  1. examine /etc/resolv.conf
  2. run `dig` or `nslookup` (newer tool with cleaner output). `nslookup` also provides an interactive shell
### Commands
`ping` test server connectivity
`dig` perform a DNS lookup
`nslookup` perform a DNS lookup
  - `www.google.com`
  - `set type=any`
`host` perform a DNS lookup
`host www.google.com`
`traceroute` display the path to a host; outputs shortest time, longest time, then average
`tracepath` test connectivity along the path, doesn't show as much detail wrt time, so it may be faster
`telnet` unencrypted shell session
`ssh` encrypted shell session
`ftp` unencrypted file transfers
`ifconfig` display information about network interfaces
  - "RX packets" refers to received packets
  - "TX packets" transmitted
`route` display and manipulate the routing table (not installed on Manjaro by default)
`route -n` display routing table
`route add default gw 192.168.0.1` add a default gateway
`route del default gw 192.168.0.1` remove a default gateway
`route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.0.1` : give a particular network a different gateway
`netstat` display network connections (not installed on Manjaro by default)
`netstat -atp` all sessions
`netstat -tp` active sessions
`netstat --route` display routing table
`netstat --program` attempt ti display software using ports
`tcpdump -i eth0` all network data will be displayed to stdout

## 40 Diagnosing networking, 2
When `ifconfig` and `traceroute` are not preinstalled on a system, they must be installed
### Commands
`yum provide program` find packages that include {program}
`ip addr` display L3 data, including "prefixlen" (equivalent to subnet mask for IPv6)
`ip link` display L2 data (links)
`ip -s link` display statistics for links
`nc` allows testing on ports; ping only tests the ICMP ping protocol, not specific types of traffic
`nc google.com 80` enter interactive shell
  - `get` submit a GET request
### Files
/etc/resolv.conf
  - Often the culprit for bizarre DNS-related errors where the system seems to reach out to the wrong address, such as when repos seem not to be accessible
  - `order` syntax defines the order of search lookup; i.e. `order files,dns,nis` is default; `order files` will restrict lookup to information in files; `order dns,files` will lookup nameservers first, then lookup files

## 41 Managing the shell

## 42 Writing scripts

## 43 Managing email
Most distros come with services that will allow even desktop computers to become email servers
MTA (message transfer agent, i.e. SMTP) and MUA (mail user agent, POP3 or IMAP client)
### Commands
`mail` (23:00) not user-friendly
`mail -s "Test email" dpezet` : shell with prompt "& ", accepts message body interactively; `-s` subject; `.\n` ends the message
`mail -u root` : retrieve root mail
MTAs:
`sendmail` : no longer run because development fell off long ago
`postfix` : designed to replace `sendmail`
`exim`
`qmail`
`dovecot` secure IMAP server
`squirrelmail` `roundcube` webmail
### Files
/etc/postfix

## 44 Managing data with SQL
### Installation and setup commands
`yum install mariadb mariadb-server`
`systemctl enable --now mariadbd` 
`/usr/bin/mysql_secure_installation` configuration script settings: 
  - asks to set root password
  - remove anonymous users
  - disallow remote root login
  - remove test database
`mysql -u root -p` start a mariadb share
### MySQL commands
commands are called queries in MySQL, the command itself is capitalized by convention, and every query is terminated by a semicolon
`show databases;` : databases are collections of tables (like workbooks to sheets)
`create database company;`
`use company;` change database to be queried
`create table employees (id int NOT NULL AUTO_INCREMENT PRIMARY KEY firstname varchar(50), lastname varchar(50), department int);` creating tables is involved
`insert` add new row
`insert into employees (firstname, lastname, department) values ('Bob', 'Smith', '1'), ('John', 'Doe', '2'), ('Alan', 'Johnson', '1'), ('Alice', 'Smith', '2');`
`select` return values in a selected range of columns
`SELECT * FROM employees` will display all values 
`SELECT * FROM employees WHERE department LIKE 1;` => Bob Smith, Alan Johnson
`SELECT * FROM employees WHERE lastname LIKE 'S%';` lastname begins with "S"
`SELECT firstname,lastname FROM employees WHERE lastname LIKE 'S%';` : just first and last names of matches
`SELECT employees.firstname, employees.lastname, departments.name FROM employees JOIN departments ON employees.department=departments.id;`
`update` modify existing row
`UPDATE employees SET department='1' WHERE id='4';` update Alice's record to change the department from 2 to 1
`delete` remove a row

## 45 Printers and printing
CUPS printing system; when installing on a headless server printers must be installed using the PPD driver (copy into /etc/cups/ppd/)
### Commands:
`lp` : "line printer", used to print files
`lpadmin -h localhost -p Canon7065 -E -v socket://10.1.10.23 -P /etc/cups/ppd/CNADVC7055X1.PPD` create a virtual printer tied to an IP address that uses the specified PPD fileset up a network printer
`LPDEST=Canon7065`
`lpstat` view status of print job
`cancel` kill print jobs
### Files:
/etc/cups/ppd/ : contains ppd drivers
/etc/cups/cupsd.conf


## 46 Security administration, 1
`find / -perm +4000` | `find / -perm -u+s` audit system for files with suid bit set
`find / -perm +2000` | `find / -perm -g+s` audit system for files with sgid bit set
`netstat -tp` : display ports that are being listened to and associated programs
`netstat -atp`
`nmap host` utility useful to audit open ports; scan {host} remotely
`netstat -tp` examine programs and ports they are listening on
`ulimit` useful to place limits on users' access to computing resources (no longer used as it once was)
`ulimit -a` in order to be persistent, limits have to be stored in /etc/security/limits.confg

## 47 Security administration, 2
`sudo` users must be added to /etc/sudoers
`visudo`
`xinetd` handles various outdated services associated with service; unused services need to be turned off (called "reducing the attack surface")
`service --status-all` see status of all services (syvinit); turn off services
### Files:
/etc/xinetd.d/ : xinetd configs
/etc/xinetd.conf  : master xinetd configuration
/etc/cmd.allow /etc/cmd.deny : files that specify who is allowed to run a command/denied; they can be used to support/disallow TCP services

## 48 Securing data with GPG
PGP was bought by Semantec, and GNU has since released GPG, an open-source replacement. It requires a private key (for decryption) as well as a public one (sufficient for encryption)
`dd if=/dev/sda1 of=/dev/zero`: `/dev/null` won't actually do a disk write
`gpg --export --output ~/jdoe.pub` : export GPG public key
`gpg --import jdoe.pub` : import another person's public key
`gpg --list-key` will list available GPG keys
`gpg --encrypt -r jdoe@dplaptop.lab.itpro.tv ./file.txt` : email has to match that of the GPG key
`gpg file.txt` : decrypt file
### Files
/proc/sys/kernel/random/entropy_avail : to generate more entropy do disk activity

## 49 Securing data with SSH
Unencrypted shell sessions over telnet are no longer considered safe because the data is easily intercepted.
### Commands
`service --status-all | grep ssh` search for running SSH service on sysvinit
`systemctl | grep ssh` search for running SSH service on SSH
`ssh-keygen -t rsa1 -f /etc/ssh/ssh_host_key` generate private and public RSA keys for SSH
`ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key` generate private and public RSA keys
`ssh-keygen -t dsa -f /etc/ssh_ssh_host_dsa_key` generate private and public DSA keys
### Files
/etc/sysconfig/iptables : make sure SSH traffic is allowed through port 22
/etc/ssh/ directory containing private and public SSH keys (.pub)
/etc/.ssh/known_hosts contains IP address and alphanumeric public key

## 50 Securing data with SSH, 2
SSH is actually a tunneling protocol that runs a shell by default
`ssh -f dpezet@10.1.230.238 -L 60023:10.1.230.238:23 -N` 
  `-f` go to background just before command execution
  `-L` forward local port connections to a remote host
  `-N` do not create an interactive shell (i.e. create a tunnel)
`telnet 127.0.0.1 60023` : telnet to your own address at the given port


[bash]: commands/README.md#bash "Bourne Again Shell"