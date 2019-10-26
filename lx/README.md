# Linux
Table of contents
:---:
[Configs](configs.md) [Commands](commands.md#commands) [Tasks](commands.md#tasks) [Sources](sources.md)

Topic                           | Contents
:---                            | :---
Desktop environments            | [GNOME](gnome.md) [KDE](kde.md) [i3](i3.md)
Distributions                   | [Arch Linux](distributions.md#arch-linux) [BSD](distributions.md#bsd) [Clear Linux](distributions.md#clear-linux) [Fedora CoreOS](#distributions.md#fedora-coreos) [Kali Linux](distributions.md#kali-linux) [Mac OS X](macosx.md)
Others                          | [Boot sequence](#boot-sequence) [Runlevels](#runlevels) [X](X.md)

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
`**initrd**` (Initial RAM disk) is a temporary file system that's loaded into memory when the system boots
### Kernel
Linux kernel is typically named `**vmlinux**` or `**vmlinuz**` (when compressed). Kernel ring buffer contains messages related to the Linux kernel. A ring buffer is a data structure that is always the same size; old messages are discarded as new ones come in, once the buffer is full. `dmesg` is used to see its contents, and the messages are also stored in `/var/log/dmesg`
### init
`**sysvinit**` or "**SystemVinit**" is a daemon process which was used by most distros until recently.
  - processes started serially and synchronously, wasting system resources
  - for years, a common hack was to run services in the background, simulating a sort of parallel processing
**Upstart** was developed by Canonical for Ubuntu, but abandoned in 2014. 
**Systemd** which starts processes in parallel has become de facto standard for all major Linux distributions

### System logging
Traditionally, `syslogd` was the daemon in charge of this, but recently alternatives such as `rsyslog` and `syslog-ng` have emerged. 

## Processes
- every process has a parent; a process can **spawn** children
- a process runs in its own **user address space**, a protected space which can't be disturbed by other users
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
2. EXEC parent then overwrites this copy with the program that has to be executed which replaces or **overlays** the text and data areas as `exec()` system call
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
**inodes** "index node", data structure that stores all the information about a file except its name and data
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
**Filesystem access control lists (FACL)** allow you to grant permissions to more than one group, i.e. in cases where more than one department of a corporation needs access to the same files.  They are made up of _access control entries_ (ACE). FACL permissions will be indicated in a `ls -l` command by the presence of a "+" after the symbolic notation for the traditional UGO permissions. **Acl** is a dependency of `systemd`.
#### Enabling
add ",acl" to options in `fstab` file, then mount/unmount disk. If enabling FACL on root partition, system has to be rebooted.

