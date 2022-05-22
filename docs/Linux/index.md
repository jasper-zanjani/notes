# Overview

[**SystemD**](SystemD) is the de facto Linux **init**{: #init } system on modern distributions.

A **process**{: #process } runs in its own **user address space**, a protected space which can't be disturbed by other users

- all processes on a Linux system are child processes of a common parent: the **init** process which is executed by the kernel at boot time (PID 1)
- every Linux process inherits the environment (PATH variable, etc) and other attributes of its parent process

Every process has a parent; a process can **spawn** children in a process that is actually made of two separate system calls.

- Shell-internal commands (**cd**, **echo**, etc. and variable assignments) do not spawn child processes
- Shell scripts are executed by spawning a sub-shell, which becomes the script's parent
- External commands are spawned as children of the parent as described above

Bootloaders like [**GRUB (GRand Unified Bootloader)**](GRUB) or **u-boot** turn on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem. 
**LILO (LInux LOader)** is also another bootloader that can be found on older Linux systems.

Microcontrollers may be listening when the system is nominally off; they typically have their own BIOS and kernels and are inaccessible from the main system:

- **Baseboard Management Controller (BMC)** responds to **wake-on-LAN (WOL)**
- **Intel Management Engine (IME)** `x86_64` software suite for remote management of systems; firmware is based on `Minix` and runs on the **Platform Controller Hub** processor, not the main CPU
- **System Management Mode (SMM)** launches UEFI software

Linux kernel is typically named **vmlinux** (or **vmlinuz** when compressed). Kernel ring buffer contains messages related to the Linux kernel. A ring buffer is a data structure that is always the same size; old messages are discarded as new ones come in, once the buffer is full. `dmesg` is used to see its contents, and the messages are also stored in `/var/log/dmesg`

Kernel **modules** can be loaded, listed, or removed from the running kernel.


## Security

Similar to DLL files on Windows systems, **.so** ("shared object") library files on Linux allow code to be shared by various processes. 
They are vulnerable to **injection attacks**. 

??? info "Library injection vulnerability"

    One file in particular, **linux-vdso.so.1**, finds and locates other shared libraries and is mapped by the kernel into the address space of every process. 
    This library-loading mechanism can be exploited through the use of the environment variable **`LD_PRELOAD`**, which is considered the most convenient way to load a shared library in a process at startup. 
    If defined, this variable is read by the system and the library is loaded [immediately](https://www.networkworld.com/article/3404621/tracking-down-library-injections-on-linux.html) after linux-vdso.so.1 into every process that is run. 

    This attack can be detected using the [**osquery**](https://osquery.io/) tool. 
    This tool represents the system as a relational database which can then be queried, in particular against the **process\_envs** table.


**Filesystem access control lists (FACL)**{: #facl } allow you to grant permissions to more than one group, i.e. in cases where more than one department of a corporation needs access to the same files.  
They are made up of _access control entries_ (ACE). 
FACL permissions will be indicated in a `ls -l` command by the presence of a "+" after the symbolic notation for the traditional UGO permissions. 
**Acl** is a dependency of `systemd`.

To enable it, add ",acl" to options in `fstab` file, then mount/unmount disk. If enabling FACL on root partition, system has to be rebooted.


--8<-- "includes/Linux/defs.md"

--8<-- "includes/Linux/links.md"

## Tasks

--8<--
includes/Linux/Tasks/custom-resolution.md
includes/Linux/Tasks/hdd-serial-numbers.md
includes/Linux/Tasks/KDE-tiling-window-manager.md
includes/Linux/Tasks/etc.md
includes/Linux/Tasks/NFS.md
includes/Linux/Tasks/X-forwarding.md
includes/Linux/Tasks/GRUB-rescue-prompt.md
--8<--

## Commands

### System administration

--8<--
includes/Linux/Commands/chage.md
includes/Linux/Commands/chgrp.md
includes/Linux/Commands/chmod.md
includes/Linux/Commands/chown.md
includes/Linux/Commands/chpass.md
includes/Linux/Commands/rename.md
includes/Linux/Commands/sudo.md
includes/Linux/Commands/sysctl.md
--8<--

### Process management

--8<--
includes/Linux/Commands/chrt.md
includes/Linux/Commands/nice.md
includes/Linux/Commands/ps.md
includes/Linux/Commands/taskset.md
--8<--
