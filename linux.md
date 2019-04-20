# General topics

## Boot sequence
Microcontrollers that may be listening when the system is nominally off
  - Baseboard Management Controller (BMC)
    - responds to wake-on-LAN (WOL)
  - Intel Management Engine (IME)
    - `x86_64` software suite for remote management of systems
    - firmware is based on `Minix` and runs on the Platform Controller Hub processor, not the main CPU
System Management Mode (SMM) launches UEFI software
Bootloader like `grub` or `u-boot` turns on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem
  - `init` or "SystemVinit" is a daemon process which was used by most distros until recently
    - processes started serially and synchronously, wasting system resources
    - for years, a common hack was to run services in the background, simulating a sort of parallel processing
  - Upstart was developed in Ubuntu/GNU Linux, but abandoned in 2014
  - Systemd starts processes in parallel, has become de facto standard for all major Linux distributions

## Processes
- every process has a parent; a process can **spawn** children
- a process runs in its own _user address space_, a protected space which can't be disturbed by other users
- all processes on a Linux system are child processes of a common parent: the `init` process which is executed by the kernel at boot time (PID 1)
- every Linux process inherits the environment (PATH variable, etc) and other attributes of its parent process

### Segments
1. TEXT SEGMENT: executable code
2. DATA SEGMENT: variables and arrays the program uses during execution
3. USER SEGMENT: process attributes
  - process ID (PID)
  - real user ID of user who created it (stored in /etc/passwd)
  - real group ID
  - priority

### Phases of process creation
1. FORK copy process invoking it as `fork()`
2. EXEC parent then overwrites this copy with the program that has to be executed which replaces or _overlays_ the text and data areas as `exec()` system call
3. WAIT parent waits for SIGTERM signal which the child will send upon completion `wait()` system call

### Types of commands
1. Internal commands (`cd`, `echo`, etc. and variable assignments) do not spawn child processes
2. Shell scripts are executed by spawning a sub-shell, which becomes the script's parent
3. External commands are spawned as children of the parent as described above

### Running a process in the background
- `&`
- `nohup` logging out will not terminate child processes

### Low priority jobs
`nice`
: priorities range from 0-19 in `csh` (10 is default); higher values run at lower priority

`ps -l`
: view priorities of jobs

`nice -5 cmd &`
: run {cmd} at a higher priority

## Runlevels
`poweroff.target`
: systemd equivalent to runlevel 0

`rescue.target`
: systemd equivalent to runlevel 1

`multi-user.target`
: systemd equivalent to runlevel 3

`graphical.target`
: systemd equivalent to runlevel 5

`reboot.target`
: systemd equivalent to runlevel 6

`emergency.target`
: systemd equivalent to runlevel emergency

`systemctl isolate runlevel`
: change target to {runlevel}


## Control groups (cgroups)
- allow you to allocate resources (CPU time, system memory, network bandwidth, or combinations thereof) among user-defined groups of processes
- like processes, cgroups are hierarchical and inherit attributes from parents, but they from separate trees branching off from `subsystems` (also: `resource controller`, or just `controller`), each of which represent a single system resouce 
  - `blkio` sets limits on input/output access from block devices
  - `cpu` which provides access to the CPU
  - many more...
- different from `namespaces`
  - good for limiting the resources available to a container
  - `systemd` uses cgroups
  - first heard about in Linux Unplugged 289, in the context of Fedora supporting v2 whereas most userspace applications support v1

## Graphical environments
Fully-featured desktop environments are distinct from window managers, which are more focused in scope

## inodes
"index node", data structure that stores all the information about a file except its name and data

## Filesystems
Most modern Linux distributions use the `ext4` filesystem, which descends from `ext3` and `ext2`, and ultimately `ext`. Other filesystems in use include `btrfs`, `xfs`, and `zfs`
Source: [OpenSource.com](https://opensource.com/article/18/4/ext4-filesystem)

### ext
  - developed by Remy Card to address limitations in the MINIX filesystem, which was used to develop the first Linux kernel
  - could address up to 2GB of storage and handle 255-character filenames
  - had only one timestap per file

### ext2
  - developed by Remy Card only a year after `ext`'s release as a commercial-grade filesystem, influenced by BSD's Berkeley Fast File System
  - prone to corruption if the system crashed or lost power while data was being written; prone to performance losses due to fragmentation
  - quickly and widely adopted, and still used as a format for USB drives

### ext3
  - adopted by mainline Linux in 2001
  - uses `journaling`, whereby disk writes are stored as transactions in a special allocation, which allows a rebooted system to roll back incomplete transactions
  - 3 levels of journaling: `journal`, `ordered`, and `writeback`
    - `journal` lowest risk, writes both data and metadata to journal before commiting it to filesystem
    - `ordered` default mode in most Linux distros, writes metadata to journal but commits data directly to the filesystem
    - `writeback` least safe, metadata is journaled but data is not

### ext4
  - added to mainline Linux in 2008, developed by Theodore Ts'o
  - improves upon `ext3` but is still reliant on old technology

### ZFS
  - true next-generation filesystem with a problematic license
  - ZFS on Linux (ZOL) is considered the ugly stepchild of the ZFS community despite the fact that the Linux implementation has the most features and the most community support
  - ZFS is too tightly bound to the operation of the kernel to operate in true userspace, and that is why each implementation is different for operating systems 
  - LU: 284

### btrfs
B-Tree Filesystem "butter fs" was adopted by SUSE Enterprise Linux, but support was dropped by Red Hat in 2017

# Commands
`apt`
: Debian package manager

`apt list --upgradable`
: see upgradable packages

`apt update`
:

`apt upgrade`
:

`ethtool`
: interrogate settings of an Ethernet interface [Source](https://opensource.com/article/18/1/analyzing-linux-boot-process)

`groupadd`
:

`groupdel`
:

`pacman`
: package manager for Linux (src:`yt/-dEuXTMzRKs`)

`pacman Xx`
: commands typically come with uppercase major commands and lowercase subcommands

`pacman -Q`
: list all installed packages

`pacman -Q | wc -l`
: get number of total installed packages by counting the lines of output of `pacman -Q`

`pacman -Qe`
: list programs explicitly installed by user or program command

`pacman -Qeq`
: list only program names explicitly installed

`pacman -Qm`
: list programs only installed from AUR

`pacman -Qn`
: list programs only installed from main repositories

`pacman -Qdt`
: dependencies no longer needed (orphans)

`pacman -S emacs`
: typical syntax to install a package

`pacman -Sy`
: synchronize package database (equivalent to `apt-get update`)

`pacman -Su`
: update programs (equivalent to `apt-get upgrade`)

`pacman -Syu`
: sync package database (`Sy`) and upgrade all programs (`u`) (equivalent to `apt-get update && apt-get upgrade`)

`pacman -Syy`
: force double-check of repositories

`pacman -Syyuw`
: downloads programs but doesn't install them, for the option of manual installation

`pacman -R package`
: remove {package}, but leaving dependencies

`pacman -Rs package`
: remove a package as well as its dependencies

`pacman -Rns package`
: remove a package, dependencies, as well as config files

`passwd`
: give a user a password

`passwd luke`
: give user {luke} a password

`shuf -e one two three`
: shuffle items separated by a space

`shuf -n 1 cards.txt`
: shuffle items separated by newline [Source](https://shapeshed.com/unix-shuf/)

`useradd -m -g wheel luke`
: add user {luke} to group {wheel}

`userdel`
: 

## Directories
`/var/lib/pacman/`
: directory where `db.lck` file will be stored, which must be deleted occasionally when pacman is interrupted unexpectedly. this file is created to ensure that only one instance of pacman runs at any time

# Distributions

## Arch Linux

### Installation
1. `lsblk` inspect available drives and partitions before/after inserting USB drive
2. `dd if=Downloads/archlinux-2018.03.01-x86_64.iso of=/dev/sdba status="progress"` mount ISO (`if`)to USB drive (`of`), with progress displayed
3. reboot from the USB drive
4. `ls /sys/firmware/efi/efivars` if there are values displayed a UEFI system is required and a different installation sequence is needed
5. ensure an Ethernet internet connection  or `wi-fi menu` a valid Wi-Fi connection is present
6. `timedatectl set-ntp true`
7. `fdisk /dev/sdb` begin the process of partitioning the disk; enter the `fdisk` command prompt
   1. `d` delete partition
   2. `n` new partition, for boot partition
   3. `1` default for first new partition
   4. `<Enter>` default first sector
   5. `+200M`
   6. `Y` remove the signature of the previous partition
   7. repeat steps `7.2`-`7.6` for swap partition (1.5xTotal RAM e.g. `+12G`)
   8. repeat steps `7.2`-`7.6` for root partition (at least 15GB e.g. `+25G`)
   9. repeat steps `7.2`-`7.6` for home partition (remainder of hard drive, `<Enter>` for first and last sectors)
   10. `w` to write
8.  set up `ext4` filesystem on boot, root, and home partitions
    1.  `mkfs.ext4 /dev/sdb1`
    2.  `mkfs.ext4 /dev/sdb3`
    3.  `mkfs.ext4 /dev/sdb4`
9.  make the swap partition a swap drive
    1.  `mkswap /dev/sdb2`
    2.  `swapon /dev/sdb2`
10. mount partitions
    1.  `mount /dev/sdb3 /mnt` mount root partition
    2.  `mkdir /mnt/home` prepare `home` directory
    3.  `mkdir /mnt/boot` prepare `boot` directory
    4.  `mount /dev/sdb1 /mnt/boot`
    5.  `mount /dev/sdb4 /mnt/home`
11. `pacstrap /mnt base base-devel vim` install Arch Linux on the directory provided with the packages `base`, `base-devel` (which includes `sudo` and other development tools), `vim`
12. `genfstab -U /mnt > /mnt/etc/fstab` make an `fstab` file, taking all the drives mounted at that location, going off of UUIDs rather than the `sd` identifiers (which might change)
13. `arch-chroot /mnt` change root to new Arch Linux installation
14. `pacman -S networkmanager` install `networkmanager` which will allow Ethernet Internet connections upon reboot
15. `systemctl enable NetworkManager` tell SystemD to start NetworkManager upon login
16. `pacman -S grub` install GRUB
17. `grub-install --target=i386-pc /dev/sdb` install GRUB as bootloader
18. `grub-mkconfig -o /boot/grub/grub.cfg` generate GRUB configuration
19. `passwd` set password for root
20. `vim /etc/locale.gen` uncomment the two lines referring to US English
21. `locale-gen` read that file and set locale
22. `echo "LANG=en-US.UTF-8" > /etc/locale.conf` set `LANG` language variable
23. `ln -sf /usr/share/zoneinfo/America/New_York /etc/localtime` set timezone by making `localtime` a link to the correct timezone (this command is all that is required when resetting timezone during travel)
24. `echo archizard > /etc/hostname` write new hostname
25. `exit` return to USB shell
26. `umount -R /mnt` unmount hard drive for safety
27. `reboot`
### Graphical environments
  - Install `noto-fonts` and `ttf-linux-libertine` `ttf-inconsolata`
  - `~/.config/fontconfig/fonts.conf` XML file that defines fonts as serif, monospace, etc
### Example: installing `xfce4` desktop environment
  - `pacman -S xfce4`
  - `exec xfce4-session` to `~/.xinitrc`
### Installing user login screens
  `sudo pacman -S lightdm lightdm-gtk-greeter`
  `sudo systemctl enable lightdm.service`
### Potential problems
  - Ctrl+Alt+F2|F3|F4... bring up another TTY
  - Alt+LeftArrow|RightArrow navigate to adjacent TTY


# Manjaro
## Dual boot issues
### Changing boot
`bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi`
: change Windows bootloader to Manjaro, while dual booting

### Device driver update
`sudo mhwd -a pci nonfree 0300`
: command was run while troubleshooting black screen on startup

 
