# 🐧 Linux

[**SystemD**](SystemD) is the de facto Linux **init**{: #init } system on modern distributions.

A **process**{: #process } runs in its own **user address space**, a protected space which can't be disturbed by other users
- all processes on a Linux system are child processes of a common parent: the `init` process which is executed by the kernel at boot time (PID 1)
- every Linux process inherits the environment (PATH variable, etc) and other attributes of its parent process

Every process has a parent; a process can **spawn** children in a process that is actually made of two separate system calls.

1. `FORK` copy process invoking it as `fork()`
2. `EXEC` parent then overwrites this copy with the program that has to be executed which replaces or **overlays** the text and data areas as `exec()` system call
3. `WAIT` parent waits for `SIGTERM` signal which the child will send upon completion `wait()` system call
4. **`TEXT SEGMENT`**: executable code
5. **`DATA SEGMENT`**: variables and arrays the program uses during execution
6. **`USER SEGMENT`**: process attributes
     - process ID (PID)
     - real user ID of user who created it (stored in /etc/passwd)
     - real group ID
     - priority

- Internal commands (`cd`, `echo`, etc. and variable assignments) do not spawn child processes
- Shell scripts are executed by spawning a sub-shell, which becomes the script's parent
- External commands are spawned as children of the parent as described above


**Control group (cgroups)**{: #cgroups } is a Linux kernel feature that isolates a collection of processes and is the concept behind [containers](/Containers).

- allow you to allocate resources (CPU time, system memory, network bandwidth, or combinations thereof) among user-defined groups of processes
- like processes, cgroups are hierarchical and inherit attributes from parents, but they from separate trees branching off from `subsystems` (also: `resource controller`, or just `controller`), each of which represent a single system resouce 
    - `blkio` sets limits on input/output access from block devices
    - `cpu` which provides access to the CPU
    - many more...
- different from `namespaces`
    - good for limiting the resources available to a container
    - `systemd` uses cgroups
    - first heard about in Linux Unplugged 289, in the context of Fedora supporting v2 whereas most userspace applications support v1

Process IDs in the same **namespace** can have access to one another, whereas those in different namespaces cannot. 
Spawning a process in a new namespace prevents it from seeing the host's context, so an interactive shell like `zsh` spawned in its own namespace will report its PID as `1`, even though the host will assign its own PID. 


Bootloaders like [**GRUB (GRand Unified Bootloader)**](GRUB) or **u-boot** turns on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem. 
**LILO (LInux LOader)** is also another bootloader that can be found on older Linux systems.

Microcontrollers may be listening when the system is nominally off; they typically have their own BIOS and kernels and are inaccessible from the main system:

- **Baseboard Management Controller (BMC)** responds to **wake-on-LAN (WOL)**
- **Intel Management Engine (IME)** `x86_64` software suite for remote management of systems; firmware is based on `Minix` and runs on the **Platform Controller Hub** processor, not the main CPU
- **System Management Mode (SMM)** launches UEFI software

Linux kernel is typically named **vmlinux** (or **vmlinuz** when compressed). Kernel ring buffer contains messages related to the Linux kernel. A ring buffer is a data structure that is always the same size; old messages are discarded as new ones come in, once the buffer is full. `dmesg` is used to see its contents, and the messages are also stored in `/var/log/dmesg`


**Index node (inode)** is a data structure that stores all the information about a file except its name and data
Most modern Linux distributions use the `ext4` filesystem, which descends from `ext3` and `ext2`, and ultimately `ext`. Other filesystems in use include `btrfs`, `xfs`, and `zfs`
Source: [ref](https://opensource.com/article/18/4/ext4-filesystem "opensource.com: \"Understanding Linux filesystems: ext4 and beyond\"")

**Extended File System** was first implemented in 1992 by Remy Card to address limitations in the MINIX filesystem, which was used to develop the first Linux kernel. It could address up to 2GB of storage and handle 255-character filenames and had only one timestap per file.

- **ext2** was developed by Remy Card only a year after `ext`'s release as a commercial-grade filesystem, influenced by BSD's Berkeley Fast File System. It was prone to corruption if the system crashed or lost power while data was being written and performance losses due to fragmentation. Nevertheless, it was quickly and widely adopted, and still used as a format for USB drives.
- **ext3** was adopted by mainline Linux in 2001 and uses **journaling**, whereby disk writes are stored as transactions in a special allocation, which allows a rebooted system to roll back incomplete transactions. 3 journaling modes: [journal](#ext "lowest risk journaling mode in ext3, writes both data and metadata to journal before commiting it to filesystem"), [ordered](#ext "default journaling mode in ext3, writes metadata to journal but commits data directly to the filesystem"), and [writeback](#ext "least safe journaling mode in ext3, metadata is journaled but data is not")
- **ext4** was added to mainline Linux in 2008, developed by Theodore Ts'o, and improves upon `ext3` but is still reliant on old technology.

**ZFS** is a true next-generation filesystem with a problematic license.
**ZFS on Linux (ZOL)** is considered the ugly stepchild of the ZFS community despite the fact that the Linux implementation has the most features and the most community support.
ZFS is too tightly bound to the operation of the kernel to operate in true userspace, and that is why each implementation is different for operating systems.

**B-Tree Filesystem "butter fs"** was adopted by [SUSE Enterprise Linux](#suse), but support was dropped by Red Hat in 2017.


## Security

Similar to DLL files on Windows systems, .so ("shared object") library files on Linux allow code to be shared by various processes. 
They are vulnerable to **injection attacks**. 

One file in particular, **linux-vdso.so.1**, finds and locates other shared libraries and is mapped by the kernel into the address space of every process. 
This library-loading mechanism can be exploited through the use of the environment variable **`LD_PRELOAD`**, which is considered the most convenient way to load a shared library in a process at startup. 
If defined, this variable is read by the system and the library is loaded immediately after linux-vdso.so.1 into every process that is run. [<sup>:material-link:</sup>](https://www.networkworld.com/article/3404621/tracking-down-library-injections-on-linux.html "networkworld.com: \"Tracking down library injections on Linux\"")

This attack can be detected using the **[osquery <sup>:material-link:</sup>](https://osquery.io/)** tool. 
This tool represents the system as a relational database which can then be queried, in particular against the **process_envs** table.


**Filesystem access control lists (FACL)**{: #facl } allow you to grant permissions to more than one group, i.e. in cases where more than one department of a corporation needs access to the same files.  
They are made up of _access control entries_ (ACE). 
FACL permissions will be indicated in a `ls -l` command by the presence of a "+" after the symbolic notation for the traditional UGO permissions. 
**Acl** is a dependency of `systemd`.

To enable it, add ",acl" to options in `fstab` file, then mount/unmount disk. If enabling FACL on root partition, system has to be rebooted.


--8<-- "includes/Linux/abbrs.md"

--8<-- "includes/Linux/defs.md"

--8<-- "includes/Linux/links.md"