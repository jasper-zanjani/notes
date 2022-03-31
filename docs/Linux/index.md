# Overview

[**SystemD**](SystemD) is the de facto Linux **init**{: #init } system on modern distributions.

A **process**{: #process } runs in its own **user address space**, a protected space which can't be disturbed by other users
- all processes on a Linux system are child processes of a common parent: the `init` process which is executed by the kernel at boot time (PID 1)
- every Linux process inherits the environment (PATH variable, etc) and other attributes of its parent process

Every process has a parent; a process can **spawn** children in a process that is actually made of two separate system calls.

- Internal commands (`cd`, `echo`, etc. and variable assignments) do not spawn child processes
- Shell scripts are executed by spawning a sub-shell, which becomes the script's parent
- External commands are spawned as children of the parent as described above


**Control group (cgroups)**{: #cgroups } is a Linux kernel feature that isolates a collection of processes and is the concept behind [containers](Containers).

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


## Security

Similar to DLL files on Windows systems, **.so** ("shared object") library files on Linux allow code to be shared by various processes. 
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


--8<-- "includes/Linux/defs.md"

--8<-- "includes/Linux/links.md"

## Tasks



--8<-- "includes/Linux/Tasks/custom-resolution.md"

--8<-- "includes/Linux/Tasks/hdd-serial-numbers.md"

--8<-- "includes/Linux/Tasks/KDE-tiling-window-manager.md"

--8<-- "includes/Linux/Tasks/etc.md"

--8<-- "includes/Linux/Tasks/NFS.md"

--8<-- "includes/Linux/Tasks/X-forwarding.md"

--8<-- "includes/Linux/Tasks/GRUB-rescue-prompt.md"

### Tiling window managers

- **i3**{: #i3 } is perhaps the most popular tiling window manager, typically used with polybar.
- **awesome**{: #awesome } is written and configured in Lua. It originated as a fork of [**dwm**](#dwm), it offers creature comforts that make it the easiest for neophytes to tiling window managers.
- **bspwm** ("Binary Space Partitioning Window Manager") uses tree partitioning as the logic for organizing tiles, with the default being the "dwindle" pattern. 
Notably, it uses two config files: 
    - **.bspwmrc** which determines what programs to autoload but doesn't contain any key bindings
    - **.sxhkdrc** which uses a syntax similar to [i3](#i3) or herbstluft.
- **dwm**{: #dwm }: One of the oldest and lightest tiling window managers. 
Because Suckless wants the source code not to exceed 2,000 lines of code, a lot of functionality is incorporated by means of **patches**, which modify the source code using diff files. 
- **herbstluft** has a single pool of workspaces that is shared across all monitors.
- **xmonad** is written and configured in Haskell, making it challenging to configure.

All window managers place an INI-format .desktop file in **/usr/share/xsessions/**.
```ini title="xmonad.desktop"
[Desktop Entry]
Name=xmonad
Comment=Tiling window manager
Exec=xmonad-start
Terminal=false

[Window Manager]
SessionManaged=true
```


--8<-- "includes/Linux/Tasks/Xmonad.md"

## Commands


### System administration

--8<-- "includes/Linux/Commands/chage.md"

--8<-- "includes/Linux/Commands/chgrp.md"

--8<-- "includes/Linux/Commands/chmod.md"

--8<-- "includes/Linux/Commands/chown.md"

--8<-- "includes/Linux/Commands/chpass.md"

--8<-- "includes/Linux/Commands/rename.md"

--8<-- "includes/Linux/Commands/sudo.md"

--8<-- "includes/Linux/Commands/sysctl.md"

### Process management

--8<-- "includes/Linux/Commands/chrt.md"

--8<-- "includes/Linux/Commands/nice.md"

--8<-- "includes/Linux/Commands/ps.md"

--8<-- "includes/Linux/Commands/taskset.md"
