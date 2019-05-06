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


### Creating filesystems
`mkfs` tool used to make file systems
  - `-t ext4` specify "type", ext4 or xfs
  - `mkfs.ext4 partition` format {partition} with the ext4 file system
  - /etc/mkfs

`mkswap partition`
: make swap partition out of {partition} (15:00)
`swapon partition`
: tell system to use {partition} as swap partition

### Changing partitions after creation
`e2label partition Storage` 
: label ext {partition} "Storage" (18:40)
`xfs_admin -L Storage partition` 
: label xfs {partition} "Storage"
`resize4fs` 
: resize filesystems

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
`lvcreate -L size vg -n name`
: create logical volume of size {size} from volume group {vg} with the name {name}
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

## xk0004 Filesystem Hierarchy Standard (FHS)
## xk0004 Editing files with vi, 1
## xk0004 Editing files with vi, 2
## xk0004 Working with files
## xk0004 Locating files
## xk0004 Searching with grep
## xk0004 Manipulating text
## xk0004 Managing kernel modules
## xk0004 Managing the Linux boot process
## xk0004 Graphical user interfaces
## xk0004 Managing services with systemd
## xk0004 Managing services with sysvinit
## xk0004 Troubleshooting services, 1
## xk0004 Troubleshooting services, 2
## xk0004 Configuring hardware
## xk0004 Supporting printers
## xk0004 Understanding TCP/IP
## xk0004 Configure networking
## xk0004 Troubleshooting network connections
## xk0004 Managing software with apt
## xk0004 Managing software with yum/DNF
## xk0004 Building from source
## xk0004 Linux security best practices, 1
## xk0004 Linux security best practices, 2
## xk0004 Securing apps with SELinux
## xk0004 Securing apps with AppArmor
## xk0004 Filtering traffic with firewalld
## xk0004 Filtering traffic with iptables
## xk0004 Backup and restore data
## xk0004 Configuring bash
## xk0004 Writing a bash script
## xk0004 Scheduling tasks, 1
## xk0004 Scheduling tasks, 2
## xk0004 Version control with git
## xk0004 Installing CentOS, 1
## xk0004 Installing CentOS, 2
## xk0004 Installing Ubuntu

