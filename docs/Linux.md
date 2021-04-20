# 🐧 Linux

## Audio

### ALSA

**Advanced Linux Sound Architecture (ALSA)** replaced the earlier "Open Sound System". ([src][Schatz])

ALSA kernel modules are designed to offer an interface that "corresponds to that of the hardware" to keep the modules simple, and similar cards will offer a similar interface. They offer two interfaces: **operational** and **configuration**

**Operational interface** through the `/dev/` tree, with 3 main types of devices
- **PCM** for recording or playing digitized sound samples
- **CTL** for manipulating the internal mixer and routing of the card
- **MIDI** to control the MIDI port, if it exists
- Optionally, **sequencer** devices may also exist if the card has a builtin sound synthesizer with an associated **timer** device

**Status and configuration interface** via the `/proc/asound/` tree (ref [`amixer`][amixer])

PCM devices come in two varieties: **output** and **input** and are numbered from 0, which is generally for analog multichannel sound.

Cards have input or output **sockets**, and the **mixer** is controlled by the CTL device and routes sound samples among devices and sockets.

Controls come in 3 types;
- **Playback** controls are associated with an output device or **copy (input-to-output)** routes
- **Capture** controls are associated with an input device or **copy (output-to-input)** routes
- **Feature** controls drive features of the card or mixer, usually just a switch to enable or disable the feature, though some also have levels. The **Master Volume** control is the most typical example, which allows control of the internal amplifier feature of the card. A more interesting example is that of a 3d spatializer that can be represented by a switch to enable or disable it as well as two levels.

Typical channel assignments
- **0**: front left
- **1**: front right
- **2**: rear left
- **3**: rear right

### PulseAudio

PulseAudio is a sound server for POSIX OSes and a fixture on many Linux distributions.

PulseAudio is built around **sources** and **sinks** (i.e. devices) connected to **source outputs** and **sink inputs** (streams)
- **Source** is an input device that produces samples, usually running a thread with its own event loop, generating sample chunks which are posted to all connected source outputs
- **Source output** is a recording stream which consumes samples from a source
- **Sink** is an output device that consumes samples, usually running a thread with its own event loop mixing sample chunks from connect sink inputs
- **Sink input** is a playback stream, connected to a sink and producing samples for it

## 🥾 Boot

Bootloaders like [**GRUB (GRand Unified Bootloader)**](GRUB) or **u-boot** turns on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem. 
**LILO (LInux LOader)** is also another bootloader that can be found on older Linux systems.

Microcontrollers may be listening when the system is nominally off; they typically have their own BIOS and kernels and are inaccessible from the main system:

- **Baseboard Management Controller (BMC)** responds to **wake-on-LAN (WOL)**
- **Intel Management Engine (IME)** `x86_64` software suite for remote management of systems; firmware is based on `Minix` and runs on the **Platform Controller Hub** processor, not the main CPU
- **System Management Mode (SMM)** launches UEFI software

**initrd** (Initial RAM disk) is a temporary file system that's loaded into memory when the system boots

Linux kernel is typically named **vmlinux** (or **vmlinuz** when compressed). Kernel ring buffer contains messages related to the Linux kernel. A ring buffer is a data structure that is always the same size; old messages are discarded as new ones come in, once the buffer is full. `dmesg` is used to see its contents, and the messages are also stored in `/var/log/dmesg`

### Init

**SystemD** was designed by a pair of Red Hat developers in 2010 to be a general purpose system manager.
It offers parallel execution, explicit dependencies between services, an escape from slow shell scripts, and per-daemon resource control and watchdogs.
It was intended to address multiple shortcomings with **SysVinit**, a daemon process which was used by most distros until recently. 

In SysVinit, processes started serially and synchronously, wasting time and system resources.
For years, a common hack was to run services in the background, simulating concurrency.

**Upstart** was another init system developed by Canonical for Ubuntu meant to replace SysVinit, but it was abandoned in 2014. 


SystemD introduces the concepts of [**Units**] which are subdivided into various unit types, each of which is associated with a filename extension.
[YouTube](https://youtu.be/NNgZXNQtil8 "We Need to Talk About Systemd: Boot Time Optimization for the New init daemon - Chris Simmonds, 2net") [Linode](https://www.linode.com/docs/quick-answers/linux-essentials/what-is-systemd/ "What is systemd?")

| [Targets][target] (SystemD) | Runlevels (System V Init) |
| --------------------------- | ------------------------- |
| poweroff.target           | 0                       |
| rescue.target             | 1                       |
| multi-user.target         | 3                       |
| graphical.target          | 5                       |
| reboot.target             | 6                       |
| emergency.target          | emergency               |

SystemD searches for units from most specific to most general.

- **/usr/lib/systemd/system**: default location where unit files are installed by packages
- **/run/systemd/system**: runtime configuration
- **/etc/systemd/system**: takes precedence over unit files located anywhere else


Associated programs:

=== "SystemD"

    - [hostnamectl][hostnamectl]
    - [journalctl][journalctl]
    - [localectl][localectl]
    - [loginctl][loginctl]
    - [systemctl][systemctl]
    - [systemd-delta][systemd-delta]
    - [timedatectl][timedatectl]

=== "SysVinit"

    - [chkconfig](chkconfig)
    - [init](init)
    - [runlevel](runlevel)
    - [service](service)
    - [telinit](telinit)

=== "Upstart"

    - [initctl](initctl)


## 💾 Disk


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

**B-Tree Filesystem "butter fs"** was adopted by SUSE Enterprise Linux, but support was dropped by Red Hat in 2017.



## Processes


A process runs in its own **user address space**, a protected space which can't be disturbed by other users
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


### Cgroups

**Control group (cgroups)** is a Linux kernel feature that isolates a collection of processes and is the concept behind [containers](Containers).

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

## Security

### Library injections

Similar to DLL files on Windows systems, .so ("shared object") library files on Linux allow code to be shared by various processes. They are vulnerable to injection attacks. One file in particular, **linux-vdso.so.1**, finds and locates other shared libraries and is mapped by the kernel into the address space of every process. This library-loading mechanism can be exploited through the use of the environment variable **`LD_PRELOAD`**, which is considered the most convenient way to load a shared library in a process at startup. If defined, this variable is read by the system and the library is loaded immediately after linux-vdso.so.1 into every process that is run. [^](https://www.networkworld.com/article/3404621/tracking-down-library-injections-on-linux.html "networkworld.com: \"Tracking down library injections on Linux\"")

This attack can be detected using the **[osquery](https://osquery.io/)** tool. This tool represents the system as a relational database which can then be queried, in particular against the **process_envs** table.

### SELinux



Display SELinux contexts for processes
```sh
ps auxZ
```
Display SELinux context for files
```sh
ls -Z
```

Associated programs:

- [chcon][chcon] 
- [getenforce][getenforce] 
- [getsebool][getsebool] 
- [restorecon][restorecon] 
- [semanage][semanage] 
- [sestatus][sestatus] 
- [setenforce][setenforce] 
- [setsebool][setsebool] 


### FACL

**Filesystem access control lists (FACL)** allow you to grant permissions to more than one group, i.e. in cases where more than one department of a corporation needs access to the same files.  They are made up of _access control entries_ (ACE). FACL permissions will be indicated in a `ls -l` command by the presence of a "+" after the symbolic notation for the traditional UGO permissions. **Acl** is a dependency of `systemd`.

To enable it, add ",acl" to options in `fstab` file, then mount/unmount disk. If enabling FACL on root partition, system has to be rebooted.

## Applications

### IRC

Connecting to Twitch requires the use of an OAuth token, which can only be granted by another web application. 
One such web application is made available [here](https://twitchapps.com/tmi/). 
The token obviates the need to specify a username, since the Twitch account's username is used.

- irc.chat.twitch.tv
- password must be oauth token (beginning with "oauth:")

There are many IRC clients available:

- [irssi](irssi)
- [weechat](weechat)


Resources:

- [Twitch IRC documentation](https://dev.twitch.tv/docs/irc/guide)


### Tiling window managers

[hObzf9ppODJU]: https://youtu.be/Obzf9ppODJU "YouTube - \"A Comprehensive Guide to Tiling Window Managers\" (DistroTube)"

Overview of tiling window managers: ([src][hObzf9ppODJU])

- [**i3**](i3) is perhaps the most popular tiling window manager, trending toward **manual** rather than **dynamic**. 
It is typically used with [polybar](polybar).
- **dwm** one of the oldest and lightest tiling window managers. 
Because suckless wants the source code not to exceed 2,000 lines of code, a lot of functionality is incorporated by means of "patches", which modify the source code using diff files. 
Workspaces are called **tags**. 
A window can be associated with more than one tag, placing it on more than one workspace. 
Each monitor has a separate pool of workspaces. 
- **xmonad** is a tiling window manager made especially difficult to configure because the program written in Haskell, as the config must be. 
All monitors share the same pool of workspaces.
Unusually for tiling window managers, when using multiple monitors, switching to another workspace actually switches the position of that workspace with the previous one. 
That is, the workspace that had previously been on the active monitor is sent to the workspace being called.
- **awesome** originated as a fork of [dwm](#dwm), it offers creature comforts that make it the easiest to adjust to as a new user of tiling window managers. 
It is written in Lua, as its config must be. 
Like dwm, each monitor has an independent pool of workspaces. 
- **herbstluft** has a single pool of workspaces that is shared across all monitors.
- **bspwm** ("Binary Space Partitioning Window Manager") uses tree partitioning as the logic for organizing tiles, with the default being the "dwindle" pattern. Like awesome, bspwm uses a shared pool of workspaces, but they are individually assigned to monitors in the configuration file.
Notably, it uses two config files: 
    - .bspwmrc which determines what programs to autoload but doesn't contain any key bindings
    - .sxhkdrc which uses a syntax similar to i3 or herbstluft.

Simulating a tiling window manager in KDE

1. Run Command > Run Command (Meta+R)
2. KDE Daemon > Launch Konsole (Meta+Return)
3. Desktop navigation keyboard shortcuts: KWin >
     - Switch to Desktop (Meta+Fkey)
     - Switch to Previous/Next Desktop (Meta + PgUp/PgDown)
     - Switch to Window Above/Below/to the Left/Right (Meta+ K/J/H/L)
     - Window to Desktop (Meta+Shift+Fkey)
     - Window to Previous/Next Desktop (Meta+Shift_PgUp/PgDown)
4. Panel screen edge -> top
5. Pager settings > General: Display only Desktop name
6. Configure Desktops
     - Change names of desktops to Font Awesome icons
     - Check "Show on-screen display when switching"

Key definitions are those provided in the output of `xmodmap`

`floating_modifier` : holding this key will allow windows to be dragged around with the mouse

Window splitting uses the convention opposite to that of vim:
- `split h` : split horizontally (to the right)
- `split v` : split vertically (down)




## Tasks

#### Custom resolution

Specify a custom resolution in a VM [github.io](https://stafwag.github.io/blog/blog/2018/04/22/high-screen-resolution-on-a-kvm-virtual-machine-with-qxl/ 'stafwag.github.io: "High screen resolution on a KVM virtual machine with QXL")
```sh
cvt 2560 1440
xrandr --newmode "2560x1440_60.00" 312.25 2560 2752 3024 3488  1440 1443 1448 1493 -hsync +vsync
xrandr --addmode Virtual-1 2560x1440_60.00
xrandr --output Virtual-1 --mode 2560x1440_60.0
```
#### X forwarding

```sh
ssh -Y user@host
```
Have remote system use local computer {me.luna.edu}'s X display
```sh
export DISPLAY=me.luna.edu:0
```

#### Install Samba
Install and configure Samba server [src][https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/]

Install `samba`
```sh
sudo apt install samba
```
Verify the samba service `smbd` is running
```sh
sudo systemctl status smbd
```
Configure Samba 
```sh
sudo mkdir /samba                   # Create a directory for the share
sudo chmod -R 0777 /samba
sudo chown -R nobody:nobody /samba  # Remove ownership
```
Open firewall rule
```sh
sudo firewall-cmd --permanent --add-service=samba
sudo firewall-cmd --reload
```
Configure Samba config file at [/etc/samba/smb.conf][/etc/samba/smb.conf]
```conf
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
Set up a Samba account for `$USER`
```sh
sudo smbpasswd -a $USER
```
Restart Samba service [vitux.com][https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/] [tecmint.com](https://www.tecmint.com/install-samba-on-rhel-8-for-file-sharing-on-windows/ "Install Samba4 on RHEL 8 for File Sharing on Windows")
```sh
sudo systemctl restart smbd.service
```
Install and configure Samba as a client
```sh
sudo apt install smbclient 
```
Access samba share at `$SHARE` at server `$HOST` using user credential `$USER`
```sh
sudo smbclient //$HOST/$USER -U $USER
```
This will display the Samba CLI
```
smb: \>
```

#### Diagnosing network problems

Test from the inside out, starting with the loopback

1. ping looback address, testing the TCP/IP stack
2. ping the hardware interface
3. ping another host on the network
4. ping the gateway
5. ping an IP address on the Internet
6. ping a hostname on the Internet

Display contents of a random file
```sh
ls | sort -R | sed 1q | xargs cat
```
Find out which commands you use most often
```sh
history | awk '{print $2' | sort | uniq -c | sort -rn | head
```
Count the number of occurrences of a string
```sh
| uniq -c | sort -
```
Change hostname 
```bash
sudo hostnamectl set-hostname newhostname
```
Check kernel version [linuxize.com](https://linuxize.com/post/how-to-check-the-kernel-version-in-linux/ "linuxize.com: \"How to check the Kernel version in Linux\"")
```bash
uname -srm
```
```bash
hostnamectl | grep "Kernel"
```
```bash
cat /proc/version
```


## 💿 Distributions


[LXF 258]: https://www.linuxformat.com/archives?issue=258 '"Linux distribution reviews: Clear Linux 31530" _Linux Format_ 258'

Fully-featured **desktop environments** are distinct from **window managers**, which are more focused in scope

### Alpine Linux

Security-oriented, lightweight Linux distribution used in containers and hardware.

### BSD
**Berkeley Software Distribution (BSD)** began in the 70s and was based on AT&T original code. First source distributions required user to purchase a source license from AT&T, since much of the BSD source was derivative of UNIX.

Berkeley finally released a "wholly-BSD" product as **Network Release 1** in 1989, which satisfied vendor demand for the TCP/IP networking code for PC.

Work immediately began to reconstruct the remaining functionality of UNIX, which was completed in Network Release 2, released in 1991, which was based entirely on Berkeley code. Eventually this resulted in the 386BSD distribution, which then spawned five interrelated BSD distros: BSDI (now Wind River), NetBSD, FreeBSD, OpenBSD, and Darwin/Mac OS X

**Unix System Laboratories (USL)** sued BSDI after BSDI attempted to market its product as a real UNIX, and other BSD distributions were affected by disputed code. Ultimately 3 out of the 18,000 files that made up the Network Release 2 distribution were removed, which became known as 4.4BSD-lite, released in 1994. This legal dispute was partly to blame for Linux's rapid ascent in popularity. ([src](https://web.archive.org/web/20060315152051/http://www.applelust.com/alust/terminal/archives/terminal041202.shtml))

### Clear Linux
Rolling release distro from Intel with a custom package management system based on **bundles**, collections of packages that contain everything an application requires, including dependencies. Clear's update process also has the ability to do **delta downloads**, preserving bandwidth. It does not provide access with unusual licenses, like ZFS, Chrome, or FFmpeg. ([src][LXF 258])

### Red Hat
After a shift in late 2020, CentOS Stream is no considered  upstream to RHEL (ahead by a point-release), but downstream from Fedora.

- **CentOS** is a community distribution of Linux that was created by Gregory Kurtzer in 2004 and acquired by Red Hat in 2014. It has traditionally been [considered](https://itsfoss.com/centos-stream-fiasco/) **downstream** to [RHEL](#rhel), incorporating changes to RHEL after a delay of several months. In fact, it is a rebuild of the publicly available **source RPMs (SRPMs)** of RHEL packages, which historically allowed CentOS maintainers to simply package and ship them [rebranded](https://fosspost.org/centos-project-suicide/).
For years, CentOS was the [distribution of choice](https://www.zdnet.com/article/red-hat-resets-centos-linux-and-users-are-angry/#ftag=RSSbaffb68) for experience Linux administrators who did not feel the need to pay for Red Hat's support.
In December 2020, Red Hat [announced](https://itsfoss.com/centos-stream-fiasco/) that CentOS 8 support will end at the end of 2021 (rather than 2029), while CentOS 7 will continue to be supported until 2024. This represented a shift in focus from CentOS Linux to [**CentOS Stream**](#centos-stream) and a change from a **fixed-release** (or "stable point release") to a **rolling-release** distribution model.
- **CentOS Stream** was [announced](https://itsfoss.com/centos-stream-fiasco/) in September 2019 as a distribution of CentOS maintained on a model previously misidentified as rolling-release but now described as "continuously delivered", organized into Streams. CentOS Stream [originated](https://linuxunplugged.com/383) in an effort to get more community participation in development of RHEL, rather than merely passive consumption.
- **Fedora** is a community distribution supported by Red Hat launched as "Fedora Core" in 2003. It has traditionally been [considered](https://itsfoss.com/centos-stream-fiasco/) as **upstream** to RHEL, serving as a testing ground for new features and improvements.
- **Fedora CoreOS** is a Fedora edition [built](https://fedoramagazine.org/introducing-fedora-coreos/ 'Fedora Magazine: "Introducing Fedora CoreOS"') specifically for running containerized workloads securely and at scale. Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime.
CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.
CoreOS automatically installs upgrades automatically without user intervention, although they can be stopped if a problem is found.
- **Red Hat Enterprise Linux (RHEL)** is Red Hat's commercial Linux distribution.

### SUSE

- **OpenSUSE Leap** is a rebuild of [SUSE Linux Enterprise Server](#sles), similar to how [CentOS](#centos) was historically a rebuild of RHEL.
- **SUSE Linux Enterprise Server (SLES)** ("slee") is SUSE's fixed-release distribution of Linux intended for enterprises, and as such is comparable to Red Hat's RHEL.

### WSL


**Windows Subsystem for Linux (WSL)** is shipped with Windows and tied to the Windows release cycle. Windows ships from a single massive codebase, of which WSL is part. WSL was written mostly in C and and has 3 million monthly active users. ([src](http://azuredevopspodcast.clear-measure.com/craig-loewen-on-the-windows-subsystem-for-linux-devops-story-episode-57 "Azure DevOps Podcast 57: Craig Loewen on the Windows Subsystem for Linux story"))

WSL implements **user services** to connect to WSL distros and to run Windows-native applications like CMD.exe. WSL implements a **9P Protocol** file server to provide seamless integration of the virtualized Linux filesystem and that of the Windows host.

WSL 1 worked under a **translation architecture** where system calls were translated to NT kernel calls. This meant that applications that used system calls that were newer or more difficult to implement, like GUI applications or Docker, did not run on v1. 

WSL2 shifted to a **lighweight virtualization** model using the Linux kernel. Now Docker runs on WSL2 and GUI applications can run by using an X server.

WSL v1 is available on Azure VMs if **nested virtualization** is enabled. WSL2 support is forthcoming.

VHDs for WSL distributions are available at `%LOCALAPPDATA%\Packages\<PackageFamilyName>\LocalState` where `<PackageFamilyName>` reflects the name of the Microsoft Store package of the distro, i.e.:
- CanonicalGroupLimited.Ubuntu20.04onWindows_79rhkp1fndgsc
- TheDebianProject.DebianGNULinux_76v4gfsz19hv4

Remove a WSL distribution
```sh
wsl.exe --unregister Ubuntu-20.04
```

By default, WSL appears to copy the Windows native hosts file at %SystemRoot%\System32\drivers\etc\hosts to the distro's /etc/hosts file.


Because WSL2 uses virtualized ethernet adapters with a unique IP address, using SSH is complicated.

1. You must use **`netsh`** to [forward requests](https://docs.microsoft.com/en-us/windows/wsl/compare-versions#accessing-a-wsl-2-distribution-from-your-local-area-network-lan) to a local port to WSL's address and port.
2. Windows Firewall must also allow connections to this port.
3. The WSL2 distro must also have the SSH daemon running, as normal.

--8<-- "includes/linux-defs.md"
--8<-- "includes/linux-links.md"