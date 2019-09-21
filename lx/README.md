# Linux
Table of contents
:---:
[Configs](lx-configs.md) 
[Commands](lx-cmds.md#commands) 
[Tasks](lx-cmds.md#tasks) 
[Glossary](lx-cmds.md#glossary) 
[Sources](lx-cmds.md#sources)

Topic                           | Contents
:---                            | :---
Desktop environments            | [KDE](kde.md) [i3](i3.md)
Distros                         | [Arch Linux](lx-distros.md#arch-linux) [BSD](bsd.md) [Clear Linux](lx-distros.md#clear-linux) [Fedora CoreOS](#lx-distros.md#fedora-coreos) [Kali Linux](lx-distros.md#kali-linux) [Mac OS X](macosx.md)
Others                          | [X](X.md)

## Boot sequence
### Microcontrollers
Microcontrollers that may be listening when the system is nominally off; they typically have their own BIOS and kernels and are inaccessible from the main system
  - Baseboard Management Controller (BMC) responds to wake-on-LAN (WOL)
  - Intel Management Engine (IME)
    - `x86_64` software suite for remote management of systems
    - firmware is based on `Minix` and runs on the Platform Controller Hub processor, not the main CPU
System Management Mode (SMM) launches UEFI software
### Bootloaders
Bootloaders like GRUB (GRand Unified Bootloader) or _u-boot_ turns on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem. LILO (LInux LOader) is also another bootloader that can be found on older Linux systems (LALOS)
#### Change Windows bootloader to Linux, while dual booting
```cmd
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi
```
### Initial RAM Disk
_initrd_ (Initial RAM disk) is a temporary file system that's loaded into memory when the system boots
### Kernel
Linux kernel is typically named _vmlinux_ or _vmlinuz_ (when compressed). Kernel ring buffer contains messages related to the Linux kernel. A ring buffer is a data structure that is always the same size; old messages are discarded as new ones come in, once the buffer is full. `dmesg` is used to see its contents, and the messages are also stored in `/var/log/dmesg`
### init
`sysvinit` or "SystemVinit" is a daemon process which was used by most distros until recently.
  - processes started serially and synchronously, wasting system resources
  - for years, a common hack was to run services in the background, simulating a sort of parallel processing
_Upstart_ was developed in Ubuntu/GNU Linux, but abandoned in 2014. _Systemd_ starts processes in parallel, has become de facto standard for all major Linux distributions
### System logging
Linux uses the _syslog_ system that allows programs and applications to generate messages that can be captured by the system logger, eliminating the need for each and every application to have its own logging capability. The syslog standard uses _facilities_ and _severities_ to categorize message, each of which is labeled with a _facility code_ and _severity level_.\
Traditionally, `syslogd` was the daemon in charge of this, but recently alternatives such as `rsyslog` and `syslog-ng` have emerged. 
## Processes
- every process has a parent; a process can *spawn* children
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
`nice` : priorities range from 0-19 in `csh` (10 is default); higher values run at lower priority
`ps -l` : view priorities of jobs
`nice -5 cmd &` : run {cmd} at a higher priority
## Runlevels
`poweroff.target` : systemd equivalent to runlevel 0
`rescue.target` : systemd equivalent to runlevel 1
`multi-user.target` : systemd equivalent to runlevel 3
`graphical.target` : systemd equivalent to runlevel 5
`reboot.target` : systemd equivalent to runlevel 6
`emergency.target` : systemd equivalent to runlevel emergency
`systemctl isolate runlevel` : change target to {runlevel}
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
## Filesystems
_inodes_ "index node", data structure that stores all the information about a file except its name and data
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
## Filesystem access control lists
_Filesystem access control lists (FACL)_ allow you to grant permissions to more than one group, i.e. in cases where more than one department of a corporation needs access to the same files.  They are made up of _access control entries_ (ACE). FACL permissions will be indicated in a `ls -l` command by the presence of a "+" after the symbolic notation for the traditional UGO permissions. _Acl_ is a dependency of systemd.
### Enabling
add ",acl" to options in `fstab` file, then mount/unmount disk. If enabling FACL on root partition, system has to be rebooted.
### Commands
`getfacl file`: display FACL permissions of {file} (xk0004-08: 7:00)
`setfacl`: configure FACL permissions; (xk0004-08: 9:00)
  `-m` modify; 
  `-s` overwriting or _setting_
  `setfacl -m o::rwx file4.txt`: add file4.txt read access to "other" 
  `setfacl -m u:zach:rw file4.txt`: add user {zach} to list of users of file4.txt

## Glossary
Name                            | Description
:---                            | :---
Akira                           | design tool; alternative to `Sketch` and `Adobe XD`
Ardour                          | edit multiple audio tracks [[1](#sources)]
Audacity                        | process and edit audio files [[1](#sources)]
Bentoo Linux                    | Linux distribution made as a version of Funtoo which is easier to install
bro                             | alternative to man 
btrfs                           | B-Tree File System or "butter FS": file system was adopted by SUSE Enterprise Linux, but support was dropped by Red Hat in 2017
cheat                           | alternative to man 
Click                           | Python package that uses decorators to create command-line interfaces
Clonezilla                      | open-source software package for disk imaging and cloning; started as an alternative to the commercial software package Norton Ghost | DL: 111
coreboot                        | open-source firmware | [[LS](../sources/README.md)]
eta                             | command-line tool that draws a progress bar for long-running processes 
rdesktop                        | command-line utility for initiating a REmote Desktop Protocol connection with a Windows host [[4](#sources)]
Rosegarden                      | read and edit notations, MIDI files [[1](#sources)]
Timeshift                       | backup utility that can capture the entire drive as a snapshot [[2](#sources)]
darktable                       | open-source photography workflow application; more involved than `digikam` [[LU](../sources/README.md): 289]
digikam                         | open-source image organizer and tag editor; switched from `Exiv2` to `QtAV` for video support; written in C++ [[LU](../sources/README.md): 289]
dmenu                           | dynamic menu for X11; originally designed for `dwm`
dolphin                         | KDE file manager [[LCL](../sources/READMe.md): 27]
dwm                             | window manager written in C that needs to be recompiled when you change configuration
enlightenment                   | stacking window manager for X Window System 
Endlessh                        | SSH tarpit that sends an endless SSH banner to keep malicious SSH clients locked up for long periods of time
exa                             | open-source replacement for `ls`, with additional options
ext4                            | filesystem adopted by Linux in 2008; developed by Theodore Ts'o
feh                             | X11 image viewer 
Fedora                          | Linux distribution available in 3 flavors: Server, Workstation, and Cloud; Default desktop environment: GNOME; Default user interface: GNOME Shell; Package management system: RPM 
Fedora CoreOS Config (.fcc)     | YAML file that specifies the desired configuration of a CoreOS machine. It is converted to an **Ignition config** file using the **Fedore CoreOS Config Transpiler**  [[5](#sources)]
Fedora CoreOS Config Transpiler (FCCT) | utility used to generate an **Ignition config** file from a **Fedora CoreOS Config** file [[5](#sources), [6](#sources)]
Funtoo Linux                    | Linux distribution also made by Daniel Robbins | 
hexchat                         | open-source IRC client typically preinstalled with Linux distros | DL: 112
Ignition Config (.ign)          | configuration file generated by the **Fedora CoreOS Config Transpiler** from a **Fedora CoreOS Config** file to provision a CoreOS system [[6](#sources)]
Flameshot                       | open-source screenshot tool with convenient options for graphical editing [[DL](../sources/README.md): 110]
flatpak                         | building and distributing desktop applications on Linux 
flowblade                       | open-source video editor [[LU](../sources/README.md): 295]

geary                           | GUI email application for GNOME 3 | [[LU](../sources/README.md): 289]
Gentoo                          | Linux distribution for which the source code is compiled locally according to the user's preferences, optimizing the distro to the specific computer; started by Daniel Robbins | 
Glimpse                         | GIMP fork [[24](#sources)] [Web](https://getglimpse.app/) [Twitter](https://twitter.com/glimpse_editor) [Github](https://github.com/glimpse-editor/)
GNOME                           | desktop environment; unique among desktop environments for being single-threaded process and thus susceptible to catastrophic crashes [[DL](../sources/README.md): 110]
gopass                          | command-line password manager 
gparted                         | partition editor; graphical frontend to GNU Parted
htop                            | interactive process viewer 
immutable infrastructure        | a machine that is not modified **in-place**, but configured only through the provisioning process | 5
iptables                        | userspace utility program that allows a sysadmin to configure tables provided by the Linux kernel firewall; `iptables` applies to IPv4; `ip6tables` to IPv6; `arptables` to ARP; `ebtables` to Ethernet frames
Kali Linux                      | Linux distribution which is the most popular one for ethical hacking and pentesting; based on Debian; installable on a banana board (Raspberry Pi) | DL: 110
KDE                             | desktop environment [[DL](../sources/README.md): 105]
kpcli                           | command-line version of `keepass` or `keepassx` 
libcgroup                       | easiest way to work with cgroups on Red Hat Linux; `cgconfig` service installed with libcgroup package
lightdm                         | user login screen
Lightworks                      | video editor [[DL](../sources/README.md): 105]
Linux Multimedia Studio (LMMS)  | alternative to Frooty Loops [[1](#sources)]
Lubuntu                         | Ubuntu flavor using the LXQt desktop environment | 
lynx                            | open-source terminal-based web browser | DT
Minix                           | POSIX-compliant Unix-like OS based on a microkernel architecture; although the source code was released in print form (in 1987), the license cost $69, which was included in the cost of the book; had its own filesystem which could handle filenames up to 14 characters and address 64MB of storage; developed by Andrew Tannenbaum for teaching; used by Linus Torvalds to develop the original Linux kernel | 
Mixxx                           | DJ software, including BPM, key detection, sync, effects  [[1](#sources)]
MPlayer                         | multimedia player with support for streaming online radio  [[3](#sources)]
MuseScore                       | arrange a musical score  [[1](#sources)]
Matrix                          | open standard for messaging; integrates with and bridges to IRC and other protocols, potentially consolidating the fractured landscape of messaging on Linux [[DL](../sources/README.md#destination-linux): 110]
MyPy                            | most common Python static type checker
Nautilus                        | file manager used by default in GNOME
Nemo                            | file manager used by default in Budgie
netcat                          | open-source tool (which replaces and refines the features of another, older, identically-named program) which facilitates TCP/IP connections and requests | DT
netdata                         | open-source real-time performance and health monitor
nm-applet                       | network manager
nnn                             | terminal-based file browser; written in Python
OBS                             | open-source live video streaming production software which has become the de facto standard; alternative to WireCast | DL: 111
pacman                          | package manager for Arch Linux | 
Parted Magic                    | commercial Linux distribution with data recovery and disk partitioning tools; started as a free alternative to the commercial software package "Partition Magic" | DL: 111
PDF Chain                       | graphical utility which works as a wrapper to common `PDFtk` commands; allows user to merge PDFs, extract pages, and add watermarks | OSc
PDF-Shuffler                    | graphical utility to move pages around in a PDF file | OSc
Pi MusicBox                     | turns Raspberry Pi into a standalone streaming music player | 
pitivi                          | buggy video editing application still in beta; written in Python | OSc
Plasma                          | KDE desktop environment | DL: 110
prepros                         | GUI  commercial CSS compiler | 
Qt                              | open-source widget toolkit for creating GUIs and cross-platform applications; `GTK+` is an alternative | 
QtAV                            | multimedia playback framework based on `Qt` and `FFmpeg`; directly uses ffmpeg codecs; alternative to `Exiv2` [[LU](../sources/README.md): 289]
qtile                           | tiling window manager written and configured in Python used by Luke Smith; abandoned by DT in 2019 after a few weeks of use 
ranger                          | file manager
rxvt-unicode                    | terminal emulator
shorewall                       | open-source command-line firewall tool for Linux; works off plaintext configuration files; more user-friendly than `iptables`; alternative: `FireHOL` [[LU](../sources/README.md): 289]
snapcraft                       | platform to allow high-frequency updates of applications; developed by Canonical; uses YAML format; written in Go, C
solVItaire                      | terminal-based solitarie game that uses vim key bindings
st                              | "simple terminal"; suckless terminal emulator
surf                            | suckless web browser
sxiv                            | suckless image viewer
systemctl                       | main command used to inspect and control `systemd`
systemd                         | suite of basic building blocks for a Linux system
termite                         | terminal disfavored by Distro Tube
Thunar                          | file manager used by XFCE
Tilix                           | tiling terminal emulator; GTK3 [[DL](../sources/README.md): 104]
Titan                           | command-line password manager and file encryption tool; stores passwords in an encrypted SQLite database 
tldr                            | alternative to man
tutanota                        | encrypted open-source email service
Ubuntu Touch                    | open-source operating system for mobile devices [[DL](../sources/README.md): 104]
urxvt                           | terminal favored by Distro Tube
vifm                            | file manager; lacks image previews and file icons
Wasmer                          | Python module that allows Python to run web assembly
Wayland                         | intended to be a successor to X [[DL](../sources/README.md): 110]
wine                            | method of running Windows applications on linux which is faster than a virtual machine or emulator
xfce4                           | desktop environment
xorg                            | X.org server
Xubuntu                         | Linux distribution based on Ubuntu which uses the XFCE desktop environment
YaST                            | package manager and configuration tool for openSUSE and SUSE Linux Enterprise; "Yet Another Setup Tool" [[LU](../sources/README.md): 289]
yum                             | package management tool for Red Hat Enterprise Linux
Youtube-dl                      | command-line utility for downloading YouTube videos [[3](#sources)]
ZFS                             | Zettabyte File System: next-generation filesystem with a problematic license by Oracle [[LU](../sources/README.md): 284]
ZynAddSubFX                     | LMMS plugin, used with synthesizers [[1](#sources)]
## Sources
  1. "7 Open Source Software Related To Music". [Fosslicious](https://www.fosslicious.com/2019/01/7-open-source-software-related-to-music.html): 2019/01/02.
  2. "How to create snapshots on Linux with Timeshift". [TechRepublic](https://www.techrepublic.com/article/how-to-create-snapshots-on-linux-with-timeshift/#ftag=RSS56d97e7)
  3. "Music and video at the Linux terminal". [Red Hat](https://www.redhat.com/sysadmin/music-video-linux-terminal?sc_cid=70160000001273HAAQ): 2019/06/25.
  4. "rdesktop - A RDP Client to Connect Windows Desktop from Linux". [TecMint](https://www.tecmint.com/rdesktop-connect-windows-desktop-from-linux/): 2019/07/09.
  5. "Introducing Fedora CoreOS". [Fedora Magazine](https://fedoramagazine.org/introducing-fedora-coreos/): 2019/07/24.  
  6. "Fedora CoreOS - Getting Started". [Fedora Documentation](https://docs.fedoraproject.org/en-US/fedora-coreos/getting-started/): 
  7. "Easy Academic References on the Command Line". [YouTube](https://youtu.be/ksAfmJfdub0) 
  8. "Yakuake scripting". [coderwall.com](https://coderwall.com/p/kq9ghg/yakuake-scripting)
  9. "Moving files on Linux without [ `mv` ](#mv)". [opensource.com](https://opensource.com/article/19/8/moving-files-linux-without-mv): 2019/08/19.
  10. "Linux and Unix [`shuf`](#shuf) command tutorial with examples". [shapeshed.com](https://shapeshed.com/unix-shuf/): 2016/08/09.
  11. "Linux [ `sfdisk` ](#sfdisk) command". [ComputerHope](https://www.computerhope.com/unix/sfdisk.htm): 2019/05/04.
  12. "8 [`Partx`](#partx) Command Usage Examples in Linux". [TecMint](https://www.tecmint.com/partx-command-in-linux-with-examples/)
  13. "How to use the [ `stat` ](#stat) command: 2-Minute Linux Tips". [NetworkWorld](https://www.networkworld.com/video/96327/how-to-use-the-stat-command-2-minute-linux-tips#tk.rss_linux)
  14. "8 Netcat ([ `nc` ](#nc)) Command with Examples". [TecMint](https://www.tecmint.com/netcat-nc-command-examples/): 2019/08/09.
  15. "Bite Size Networking". [wizardzines.com](https://wizardzines.com/zines/bite-size-networking/)
  16. "How to use the [`nmcli`](#nmcli) command: Linux Tip" [networkworld.com](https://www.networkworld.com/video/94347/how-to-use-the-nmcli-command-linux-tip#tk.rss_linux)
  17. "[ `nslookup` ](#nslookup) Command: 7 Practical Examples" [linuxhandbook.com](https://linuxhandbook.com/nslookup-command/)
  18. "How to use the [`nslookup`](#nslookup) command". [NetworkWorld](https://www.networkworld.com/video/95669/how-to-use-the-nslookup-command-2-minute-linux-tip#tk.rss_linux)
  19. "An introduction to [ `bpftrace` ](#bpftrace) for Linux". [opensource.com](https://opensource.com/article/19/8/introduction-bpftrace): 2019/08/19.
  20. "Six practical use cases for [ `nmap` ](#nmap)". [Red Hat](https://www.redhat.com/sysadmin/use-cases-nmap): 2019/08/19.
  21. "How to convert documents to PDF format on the Ubuntu Command Line". [vitux.com](https://vitux.com/how-to-convert-documents-to-pdf-format-on-the-ubuntu-command-line/).
  22. "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)
  23. Cannon, Jason. [*Command Line Kung Fu.*](../sources/clkf.md)
  24. "Someone forked GIMP into Glimpse because gimp is an offensive word". [It's FOSS](https://itsfoss.com/gimp-fork-glimpse/): 2019/08/27.
  25. "Send Emails From Linux Terminal Using [`SSMTP`](#ssmtp)". [linuxhandbook.com](https://linuxhandbook.com/linux-send-email-ssmtp/)
  26. "Linux Mail Server Postfix Architecture" [YouTube](https://youtu.be/qhA8HuJBa64)
  27. "Qmail deprecation" [archlinux.org](https://www.archlinux.org/news/qmail-deprecation/)
  28. "[`free`](#free) Command in Linux Explained With Examples". [linuxhandbook.com](https://linuxhandbook.com/free-command/)
  29. "The [ `mktemp` ](#mktemp) Command Tutorial With examples". [OSTechnix](https://www.ostechnix.com/the-mktemp-command-tutorial-with-examples-for-beginners/)
  30. "How to move a file in Linux". [opensource.com](https://opensource.com/article/19/8/moving-files-linux-depth): 2019/08/22.
  31. "How to view image metadata". [OSTechNix](https://www.ostechnix.com/how-to-view-image-metadata-on-linux/): 2019/08/26.
  32. "Introduction to the Linux [`chown`](#chown) command". [opensource.com](https://opensource.com/article/19/8/linux-chown-command): 2019/08/26.
  33. "How to [`rename`](#rename) a group of files on Linux". [NetworkWorld](https://www.networkworld.com/article/3433865/how-to-rename-a-group-of-files-on-linux.html#tk.rss_linux): 2019/08/26.
  34. "How to use Tig to browse Git logs". [opensource.com](https://opensource.com/article/19/6/what-tig) 
  35. "CompTIA Linux+ powered by LPI". ITProTV. [itp-lpic.md](../sources/itp-lpic.md)
  36. "Unix as a Second Language: The [`touch`](#touch) command". [Network World](https://www.networkworld.com/article/3435279/unix-as-a-second-language-the-touch-command.html#tk.rss_linux).
  37. "20 Linux [YUM](#yum) (Yellowdog Update, Modified) Commands for Package Management". [TecMint](https://www.tecmint.com/20-linux-yum-yellowdog-updater-modified-commands-for-package-mangement/). 2012/08/11.
  38. "Three ways to exclude specific packages from [`yum`](#yum) update". [2daygeek.com](https://www.2daygeek.com/redhat-centos-yum-update-exclude-specific-packages/): 2019/08/28.
  39. "How to install and use [`sosreport`](#sosreport) on Ubuntu". [howtoforge.com](https://www.howtoforge.com/how-to-install-and-use-sosreport-on-ubuntu-1804/).
  40. "How to Install and Configure Samba on Ubuntu". [vitux.com](https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/).
  41. "Install Samba4 on RHEL 8 for File Sharing on Windows". [Web](https://www.tecmint.com/install-samba-on-rhel-8-for-file-sharing-on-windows/): 2019/06/12.