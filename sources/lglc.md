# Linux+ Guide to Linux Certification 3rd ed., by Jason W. Eckert

##  1 Introduction to Linux
Operating systems
Linux operating system
  - Versions of Linux
  - Identifying kernel versions
  - Licensing Linux
  - Linux advantages
History of Linux
  - UNIX
  - Hacker culture
  - Linux
Linux distributions
Common uses of Linux
  - Internet servers
  - File and print servers
  - Application servers
  - Supercomputers
  - Scientific/engineering workstations
  - Office/personal workstations

##  2 Linux Installation and usage
Installing Linux
  - Preparing for installation
  - Installation methods
  - Performing the installation
Basic Linux usage
  - Shells, terminals, and the kernel
  - Basic shell commands
  - Shell metacharacters
  - Getting command help
  - Shutting down the Linux system

##  3 Exploring Linux filesystems
Linux directory structure
  - Changing directories
Viewing files and directories
  - File types
  - Filenames
  - Listing files
  - Wildcard metacharacters
Displaying the contents of text files
Displaying the contents of binary files
Searching for text within files
  - Regular expressions
  - `grep`
Editing text files
  - `vi` editor
  - Other common text editors
Topics: cat, cd, grep, egrep, fgrep, file, less, ll, ls, more, nano, od, pwd, strings, tac, tail, vi

##  4 Linux filesystem management
Filesystem Hierarchy Standard : /bin, /boot, /dev, /etc, /home, /lib, /media, /mnt, /opt, /proc, /root, /sbin, /tmp, /usr, /usr/local, /var
Managing files and directories
Finding files
Linking files
File and directory permissions
  - File and directory ownership
  - Managing file and directory permissions
  - Default permissions
  - Special permissions
Topics: chgrp, chmod, chown, cp, ln, locate, rm, rmdir, touch, umask

##  5 Linux filesystem administration
/dev directory
Filesystems
  - Filesystem types
  - Mounting
Working with floppy disks
Working with CDs, DVDs, and ISO images
Working with hard disks
  - Standard hard disk partitioning
  - Working with standard hard disk partitions
  - Working with the LVM
Working with USB and FireWire-based storage devices
Monitoring filesystems
Hard disk quotas
Files: /etc/fstab, /etc/mtab, /proc/devices, 
Topics: /dev/MAKEDEV, cfdisk, df, du, edquota, fdisk, fsck, fuser, lvcreate, lvdisplay, lvextend, lvscan, mkfs, mkisofs, mknod, mkswap, mount, pvcreate, pvdisplay, pvscan, quota, quotaoff, quotaon, repquota, swapon, swapoff, tune2fs, umount, vgcreate, vgdisplay, vgextend, vgscan

##  6 Advanced installation
Advanced storage configuration
  - SCSI hard disk configuration
  - RAID configuration
Installation methods
  - CD Installation
  - USB Flash Drive installation
  - Hard disk installation
  - Network-based installation
Automating Linux installations
Troubleshooting installations
  - Problems starting the installation
  - Problems during installation
  - Problems after installation
Topics: dd 

##  7 Working with the bash shell
Command input and output
  - Redirection
  - Pipes
Shell variables
  - Environment variables
  - User-defined variables
  - Other variables
  - Environment files
Shell scripts
Escape sequences
  - Reading standard input
  - Decision constructs
  - Loop constructs
Topics: alias, awk, echo, env, export, grep, read, sed, set, sort, tee, tr

##  8 System initialization and X Windows
Boot process
Boot loaders
  - GRUB
  - LILO
  - Dual booting Linux
Linux initialization
  - Runlevels
  - /etc/inittab file
  - Runtime configuration scripts
  - Configuring daemon startup
X Windows system
  - Linux GUI components
  - Starting and stopping X Windows
Configuring X Windows
Topics: grub-install, grub-md5-crypt, init, lilo, runlevel, service, system-config-display, system-config-keyboard, telinit, .dmrc, .xinitrc, /boot/grub/grub.conf, /etc/inittab, /etc/lilo.conf, /etc/rc.d/rc.local, /etc/rc.d/rc.sysinit, /etc/rc.d/init.d, /etc/rc.d/rc*.d

##  9 Managing Linux processes
Linux processes
Viewing processes
Killing processes
Process execution
Running processes in the background
Process priorities
Scheduling commands
  - Scheduling commands with `atd`
  - Scheduling commands with the `cron` daemon
Topics: at, atd, bg, crontab, fg, jobs, killall, kill, nice, ps, pstree, renice, top, /etc/at.allow, /etc/at.deny, /etc/cron.allow, /etc/cron.d, /etc/cron.deny, /etc/crontab, /var/spool/at, /var/spool/cron

## 10 Common administrative tasks
### Printer administration
#### Common Unix printing system
#### Managing print jobs
#### LPD Printing system
#### Configuring printers

### Log file administration
Information and error messages recorded by daemons are called _log files__ and typically stored in _/var/log_

#### System log daemon `rsyslogd`
Creates a socket for other system processes to write to at /dev/log. Any information written there is saved in the appropriate log file according to entries in /etc/rsyslog.conf
/etc/rsyslog.conf : whitespace-delimited config file that contains General Directives to control general logging behavior
`facility.priority /var/log/logfile` : general pattern; whitespace delimited
`kern.warning       /var/log/logfile` : log kernel messages with a priority of warning and higher
`kern.=warning      /var/log/logfile` : log only kernel messages with a priority of warning
`kern.*             /var/log/logfile` : log all error messages from the kernel
`kern.*;kern.!=warn /var/log/logfile` : specify multiple facilities and priorities by delimiting each with a semicolon
`facility.priority @hostname:portnumber` : also possible; remote host must have the UDP and TCP protocol listeners uncommented, to listen on port 514 (default syslogd port)
`$ModLoad imuxsock.so` : provide support for local system logging (`logger` command)
`$ModLoad imklog.so` : provide kernel logging support (previously done by `rklogd`)
`$ModLoad immark.so` : provide --MARK-- message capability
`$ModLoad imudp.so` \ `$UDPServerRun 514` : provide UDP syslog reception
`$ModLoad imtcp.so` \ `$InputTCPServerRun 514` : provide TCP syslog reception
`*.info;mail.none;news.none;authrpriv.none;cron.none /var/log/messages` : log anything of level info or higher
`authpriv.*         /var/log/secure` : authpriv file has restricted access
`mail.*             -/var/log/maillog` : log all mail messages in one place
`cron.*             /var/log/cron`
`*.emerg            *` : everybody gets emergency messages

#### Managing log files
`>/var/log/messages` clear a log without deleting it, in order to preserve pemrmissions
/etc/logrotate.conf : config file for `logrotate`, overriden by files in /etc/logrotate.d/ 
`weekly` : rotate log files weekly
`monthly` : rotate log files monthly
`rotate 4` : keep 4 weeks worth of backlogs
`notifempty` : do not rotate if empty
`create` : create new (empty) log files after rotating old ones
`create 0664 root utmp` : new log file has permissions rw-rw-r-- with owner root and group utmp
`minsize 1M` : rotation only occurs when log file has a size greater than 1MB
`dateext` : use date as suffix of the rotated file
`compress` : compress log files
`delaycompress` : compress old files, but only on the next rotation
`rotate 1` : only one old log file is kept
`include /etc/logrotate.d` : RPM packages drop log rotation information into /etc/logrotate.d/
`/var/log/btmp { ... }` : individual log files can have settings that override the general directives
### Administering users and groups
#### Creating user accounts
#### Modifying user accounts
#### Deleting user accounts
#### Managing groups
Topics: cancel, chage, chfn, chsh, cupsaccept, cupsd, cupsdisable, cupsenable, cupsreject, groupadd, groupdel, groupmod, groups, id, logrotate, lpadmin, lpc, lp, lpq, lpr, lprm, lpstat, newgrp, passwd, pwconv, pwunconv, useradd, userdel, usermod, /etc/cups/cupsd.conf, /etc/cups/printers.conf, /etc/default/useradd, /etc/group, /etc/login.defs, /etc/logrotate.conf, /etc/passwd, /etc/shadow, /etc/skel, /etc/syslog.conf, /var/log 

## 11 Compression, system backup, and software installation
### File compression
`compress` : one of the oldest compression tools available to Unix-like systems, uses Adaptive Lempel-Ziv (LZW) coding with an average compression ratio of 40-50%, appends ".Z" to filenames of inputfiles
`compress -v file1 file2`
`zcat` : display contents of files compressed with `compress` or `gzip` (also `zmore`, `zless`)
`uncompress` : decompress files compressed with `compressed`
`gzip` : utility that uses Lempel-Ziv compression algorithm (LZ77) with an average compression ratio of 60-70%, appends ".gz" filename extension
`gzip -d archive` : decompress {archive} (same as `gunzip archive`)
`bzip2` :  utility that uses Burrows-Wheeler Block Sorting Huffman Coding algorithm, with an average compression ratio of 50-75% (`zcat`, `zmore`, and `zless` cannot be used with compressed archives), with a default filename extension of ".bz2"
`bzcat` : display contents of bz2 files (also `bzmore`, `bzless`)
`bunzip2`
### System backup
`tar` : one of the oldest backup utilities
  - `cpio` utility
  - `dump`/`restore` utility
  - Burning software
### Software installation
  - Compiling source code into programs
  - Installing programs using RPM: `rpm` and `yum` package management tools (dpkg and apt are only tangentially covered in a single Note)
Topics: *sum (sha1sum, etc), bunzip2, bzcat, bzip2, bzless, bzmore, compress, cpio, dump, gcc, gzip, gunzip, restore, rpm, tar, uncompress, yum, zcat, zless, zmore, /etc/dumpdates

## 12 Network configuration
Networks
TCP/IP protocol
  - IPv4 protocol
  - IPv6 protocol
Configuring a network interface
Configuring a PPP interface
Name resolution
Routing
Network services
Remote administration
  - Telnet
  - Remote commands
  - Secure shell (ssh)
  - Remote X Windows
  - Virtual Network Computing (VNC)
Topics: hostname, ifconfig, insmod, ip, lsmod, modprobe, ping, rsh, rlogin, rcp, rmmod, route, ssh, telnet, traceroute, vncpasswd, vncviewer, whois

## 13 Configuring network services
Infrastructure services
  - DHCP
  - DNS
  - NTP
  - NIS
Web services
File sharing services
  - Samba
  - NFS
  - FTP
E-mail services
  - Working with `sendmail`
  - Working with `postfix`
Database services
  - Configuring PostgreSQL
  - Configuring PostgreSQL databases
Topics: ab, apachectl, curl, ftp, hwclock, mail, newaliases, nmblookup, ntpdate, ntpq, smbclient, smbpasswd, tzselect

## 14 Troubleshooting, performance, and security
Troubleshooting methodology
Resolving common system problems
  - Hardware-related problems
  - Software-related problems
  - User interface-related problems
Performance monitoring
  - Monitoring performance with `sysstat` utilities
  - Other performance monitoring utilities
Security
  - Securing the local computer
  - Protecting against network attacks
  - Using encryption to protect network data
  - Detecting intrusion
Topics: /etc/ld.so.cache, /etc/ld.so.conf, free, gpg, iostat, iptables, ldconfig, ldd, logger, lsof, lspci, lsusb, mpstat, nmap, nohup, sestatus, ssh-add, sar, su, sudo, sudo, ulimit, vmstat

##  A Certification
##  B GNU General Public License
##  C Finding Linux resources on the Internet
