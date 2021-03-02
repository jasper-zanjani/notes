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

Bootloaders like [**GRUB (GRand Unified Bootloader)**](Linux/GRUB) or **u-boot** turns on power supplies and scans buses and interfaces to locate the kernel image and the root filesystem. 
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
| `poweroff.target`           | `0`                       |
| `rescue.target`             | `1`                       |
| `multi-user.target`         | `3`                       |
| `graphical.target`          | `5`                       |
| `reboot.target`             | `6`                       |
| `emergency.target`          | `emergency`               |

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

    - [chkconfig](Linux/chkconfig)
    - [init](Linux/init)
    - [runlevel](Linux/runlevel)
    - [service](Linux/service)
    - [telinit](Linux/telinit)

=== "Upstart"

    - [initctl](Linux/initctl)


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

- [irssi](Linux/irssi)
- [weechat](Linux/weechat)


Resources:

- [Twitch IRC documentation](https://dev.twitch.tv/docs/irc/guide)


### Tiling window managers

[hObzf9ppODJU]: https://youtu.be/Obzf9ppODJU "YouTube - \"A Comprehensive Guide to Tiling Window Managers\" (DistroTube)"

Overview of tiling window managers: ([src][hObzf9ppODJU])

- [**i3**](Linux/i3) is perhaps the most popular tiling window manager, trending toward **manual** rather than **dynamic**. 
It is typically used with [polybar](LInux/polybar).
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

1. You must use **`netsh`** to [forward requests](https://docs.microsoft.com/en-us/windows/wsl/compare-versions#accessing-a-wsl-2-distribution-from-your-local-area-network-lan) to a local port to the internal VM's address and port.
2. Windows Firewall must also allow connections to this port.
3. The WSL2 distro must also have the SSH daemon running, as normal.



## 📘 Glossary

[MDA]: #mda 'mail delivery agent (MDA)&#10;service that downloads email from an MTA, such as procmail and fetchmail&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 23'
[MTA]: #mta 'mail transfer agent (MTA)&#10;email server, such as sendmail, postfix, smail, and qmail&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 23'
[MUA]: #mua 'mail user agent (MUA)&#10;program that allows a user to view mail, such as mutt, pine, printmail, elm, mail, Thunderbird, Evolution, and Eudora&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 23'


#### address space

An **address space** consists of a set of pages in memory allocated to the process. (ULSAH: 90)

#### display manager

Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).

#### MDA

**Mail Delivery Agent (MDA)** - service that downloads email from an MTA, such as procmail and fetchmail

#### MTA

**Mail Transfer Agent (MTA)** - email server, such as sendmail, [postfix](Linux/postfix), smail, and qmail

#### MUA

**Mail User Agent (MUA)** - program that allows a user to view mail, such as mutt, pine, printmail, elm, mail, Thunderbird, Evolution, and Eudora


#### process

A **process** consists of an address space and a set of data structures within the kernel. 

#### qmail

[MTA][MTA] designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". 
Its various modular subcomponents run independently and are mutually untrustful. 
It uses SMTP to exchange messages with other MTAs. 

It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. 
qmail was deprecated and removed from Arch repos in 2005.

#### thread

A **thread** is an execution context within a process. (ULSAH: 91)


#### /etc/bluetooth/input.conf

Fix bluetooth mouse constantly disconnecting ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
```ini
UserspaceHID=true
```

#### /etc/bluetooth/main.conf

Power on Bluetooth adapter at startup ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
```ini
[Policy]
AutoEnable=true
```



#### /etc/group

Colon-delimited file describing group membership
```
$GROUP:$PASSWORD:$GID:$USER1:$USER2:$USER3...
```
/etc/resolv.conf
Use DNS queries prior to consulting /etc/hosts
```sh
nameserver dns
nameserver files
```

#### /etc/shadow

Colon-delimited file containing password hashes for every user listed in [/etc/passwd][/etc/passwd]
```
$USERNAME:$PASSWORD:$LASTCHANGED:$MIN:$MAX:$WARN:$INACTIVE:$EXPIRE
```

- `$USERNAME` Login name
- `$PASSWORD` Encrypted password; dollar signs delimit encryption hash function ([`$1`](#etcshadow "MD5"), [`$2a`](#etcshadow "Blowfish"), [`$2y`](#etcshadow "Blowfish"), [`$5`](#etcshadow "SHA-256"), or [`$6`](#etcshaodw "SHA-512")), then salt, then hash value. After locking the account with `usermod -L`, an exclamation point `!` is placed in front of this field, making the password inoperable and locking the account.  When an account has not yet had a password set, this value is `!!`
- `$LASTCHANGED` Days since 01/01/1970 that password was last changed
- `$MIN` minimum number of days required between password changes
- `$MAX` maximum number of days the password is valid before user is forced to change password
- `$WARN` number of days the password is to expire that user is warned that password must be changed
- `$INACTIVE` number of days after password expires that account is disabled
- `$EXPIRE` days since 01/01/1970 that account is disabled



[Schatz]: http://www.volkerschatz.com/noise/alsa.html "www.volkerschatz.com: \"A close look at ALSA\""
[alsamixer]: Linux/alsamixer 'Command-line mixer'
[amixer]: Linux/amixer 'Command-line mixer for ALSA sound card driver'
[speaker-test]: Linux/speaker-test 'Generates a tone that can be used to test the speakers of a computer'


[Alpine Linux]: #alpine-linux "Security-oriented, lightweight Linux distribution used in containers and hardware."
[CentOS]: https://centos.org 'CentOS&#10;Virtually identical to RHEL, but free of charge.&#10;The CentOS Project is owned by Red Hat and employs its lead developers.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 11'
[Clear Linux]: #clear-linux "Rolling release distro from Intel with a custom package management system based on **bundles**, collections of packages that contain everything an application requires, including dependencies. Clear's update process also has the ability to do **delta downloads**, preserving bandwidth. It does not provide access with unusual licenses, like ZFS, Chrome, or FFmpeg."
[Fedora CoreOS]: #fedora-coreos "Fedora edition built for running containerized workloads securely and at scale. CoreOS systems are meant to be immutable, meaning they are only configured through the provisioning process and not modified in-place."
[Fedora]: #fedora 'Fedora&#10;Used as the initial testbed for software and configuratiosn that later find their way to RHEL&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 11'
[WSL]: WSL "Linux virtual machine shipped with Windows with the ability to install several different distros."
[Yocto]: # 'Yocto&#10;Open-source project that facilitates the construction of custom Linux images for use in embedded and edge devices'
[aclocal]: Build#aclocal 'Place m4 macro definitions needed by `autoconf` into a single file. `aclocal` first scans for macro definitions in m4 files in its default directory (/usr/share/aclocal) and in the file acinclude.m4, then in the configure.ac file. IT generates an aclocal.m4 file that contains definitions of all m4 macros required by `autoconf`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[add-apt-repository]: Package-management#add-apt-repository ''
[adduser]: #adduser 'create a new user or update default new user information'
[alias]: #alias 'Assign a shorthand `$NAME` for `$CMD`, or display all aliases if not specified. (ref. `$BASH_ALIASES`)&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 74'
[alien]: Package-management#alien 'Convert between or install package types native to other distributions, including Red Hat .rpm, Stampede .slp, Slackware .tgz, and generic .tar.gz files.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 52'
[apropos]: #apropos 'Look up one or more `$KEYWORDS` in the online manpages (equivalent to `man -k`)'
[apt-cache]: Package-management#apt-cache 'Display package information regarding the package cache&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 81'
[apt-get]: Package-management#apt-get 'Part of the Advanced Package Tool (APT) management system.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 50'
[apt-key]: Package-management#apt-key 'Manage the list of keys used by apt for authentication.'
[apt]: Package-management#apt ''
[ar]: Archive#ar 'Maintain a group of files that are combined into a file archive. Used most commonly to create and update library files as used by `ld`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[as]: Build#as 'Generate an object file from each specified assembly language source file. Primarily intended to assemble the output of the GNU C compiler `gcc` for use by the linker `ld`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 18'
[at]: #at 'Schedule one or more commands to be executed at a specific time in the future.&#10;After specifying a future time on the command-line, the `at>` prompt appears, allowing you to specify a series of shell commands which can be terminated with Ctrl+D (EOF)&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 195'
[atq]: #atq ''
[atrm]: #atrm ''
[ausearch]: #ausearch 'Display audit logs'
[autoconf]: Build#autoconf 'Generate a configuration script from m4 macros defined in a template file, if given, or in a configure.ac or configure.in file in the CWD. The generated script is almost invariably called "configure".&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoheader]: Build#autoheader 'Generate a template file of C `#define` statements from m4 macros defined in a template file, if specified, or in configure.ac or configure.in in the CWD. The generated template file is almost invariably called config.h.in or config.hin&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 22'
[automake]: Build#automake 'Create GNU standards-compliant Makefile.in files from Makefile.am template files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 23'
[autoreconf]: Build#autoreconf 'Update configure scripts by running `autoconf`, `autoheader`, `aclocal`, `automake`, and `libtoolize` as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoscan]: Build#autoscan 'Create or maintain a preliminary configure.ac file named configure.scan based on source files in specified directory or CWD.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoupdate]: Build#autoupdate 'Update the configure template file or configure.ac if none is specified&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[bg]:   #bg 'Put current job or `$JOB` in the background&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 74'
[bg]: #bg 'Restart a suspended process in the background. Specify the number of the job according to the output of `jobs`, preceded by "%".&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 171'
[biff]: #biff 'Turn mail notifications on or off. With no arguments, `biff` indicates the current status&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 27'
[bind]: #bind 'Manage the readline library; nonoption arguments have the same form as in a .inputrc file.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 75'
[bison]: Build#bison 'Convert specified "file.y" containing a context-free grammar into tables for subsequent parsing while sending output to a new file named "file.c". Largely compatible with `yacc`, from which it derives its name.&#10;Originated as an adaptation of Bob Corbett\'s reimplementation of `yacc` which was distributed under the Berkeley license. Now maintained as a project of the FSF under a GPL license.'
[bmon]: #bmon 'Terminal-based graphical bandwidth monitor'
[bpftrace]: #bpftrace 'New open-source tracer for analyzing production performance problems and troubleshooting software&#10;"An introduction to `bpftrace` for Linux". _opensource.com_'
[brctl]: #brctl 'Create, modify, or view an Ethernet bridge, which connects separate networks into a single network from the perspective of users.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 27'
[break]: #break 'Exit from a `for`, `while`, `select`, or `until` loop.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 76'
[brew]: Package-management#brew ''
[builtin]: #builtin 'Run the shell built-in command `$CMD` with the optional given arguments `$ARGS`, bypassing functions and aliases.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 76'
[bzcat]: Archive#bzcat 'Page through .bz2 files'
[bzip2]: Archive#bzip2 'Compress or decompress archives using the Burrows-Wheeler block-sorting text-compression algorithm.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[bzless]: Archive#bzless 'Page through .bz2 files'
[bzmore]: Archive#bzmore 'Page through .bz2 files'
[caller]: #caller 'Print line number and source filename of the current function call or dot file&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 77'
[case]: #case 'Execute `$CMDS1` if `$VALUE` matches `$PATTERN1`, etc&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 77'
[cat]: #cat 'Display contents of text files&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[cc]: Build#cc 'Compile one or more C (.c), assembler (.s), ore preprocessed C (.i) source files. Automatically invokes the loader `ld`, unless `-c` is suplied. In some cases, `cc` generates an object file having a .o suffix and a corresponding root name. By default, output is placed in `"a.out"&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cd]:   #cd '&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 78'
[chage]: #chage 'Maintain the password aging limits on a user account&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 416'
[chattr]: #chattr 'Change file attributes&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 311-312'
[chcon]: #chcon 'Change context of a file or directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 207'
[chgrp]: #chgrp '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 155'
[chgrp]: #chgrp 'Change the group of one or more files, which can be a group ID number or a group name (located in "/etc/group"). You must own the file or be a privileged user to succeed with the command.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 34'
[chmod]: #chmod '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 159'
[chmod]: #chmod 'Change the access mode of one or more files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 35'
[chown]: #chown 'Change the ownership of one or more files, which can be either a user ID number or a login name (located in "/etc/passwd")&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 37'
[cksum]: #cksum 'Calculate and print a CRC sum for each file. The CRC algorithm is based on the polynomial used for Ethernet packets&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 38'
[cmp]: #cmp 'Compare `$FILE` with `$OTHER`, or STDIN if one or the other is not provided (cf. `comm` and `diff`). Exits with 0 if files are identical or 1 if they are not.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 39'
[comm]: #comm 'Compare lines common to the sorted files `$FILE` and `$OTHER`. Output is in 3 colums: lines unique to `$FILE`, lines unique to `$OTHER`, and lines common to both.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 39'
[command]: #command 'Execute `$CMD`, bypassing any aliases or functions that may be defined for it&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 79'
[compgen]: #compgen 'Generate possible completions for `$STRING`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 80'
[complete]: #complete 'Specify how to complete arguments for each `$CMD`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 80'
[compopt]: #compopt 'Modify existing compspecs for given `$CMD`, or for the currently executing completion when invoked without `$CMD`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 84'
[compress]: Archive#compress 'Compress and expand data&#10;Compress reduces the size of the named files using adaptive Lempel-Ziv coding. Whenever possible, each file is replaced by one with the extension .Z, while keeping the same ownership modes, access and modification times. If no files are specified, the standard input is compressed to the standard output. Compress will only attempt to compress regular files. In particular, it will ignore symbolic links. If a file has multiple hard links, compress will refuse to compress it unless the -f flag is given.'
[continue]: #continue 'Skip remaining commands in a `for`, `while`, `select`, or `until` loop, resuming the next iteration, or skipping `$N` nested loops&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 85'
[cp]: #cp 'Copy `$FILE` to `$PATH`. If `$PATH` is an existing file, it is overwritten. If the input is a directory use `-r`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 40'
[cpio]: Archive#cpio 'Create and extract archives, or copy files from one place to another - without compression. Each of the three control options (`-i`, `-o`, or `-p`) accepts different options.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 93'
[csplit]: #csplit 'Separate `$FILE` into sections and place sections in files named "xx00" through "xxn" (n < 100)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 46'
[ctags]: Build#ctags 'Create a list of function and macro names that are defined in the specified C, Pascal, FORTRAN, `yacc`, or `lex` source `$FILES`. Output is in three columns:&#10;  - `name`                function or macro name&#10;  - `file`                source file in which `name` is defined&#10;  - `context`             search pattern that shows the line of code containing `name`&#10;&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 48'
[curl]: #curl 'Noninteractively transfer data from a large number of protocols, including FTP, FTPS, HTTP, SCP, SFTP, SMB, SMBS, Telnet, and TFTP&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 90'
[cut]: #cut 'Select a list of columns or fields from one or more files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[cvt]: #cvt '&#10;Calculate VESA CVT mode lines'
[dar]: Archive#dar 'Backup tool that can make differential and incremental backups&#10;"`dar` manpage". _Ubuntu Manpage Repository_.'
[date]: #date 'Print the current date and time, specifying a format.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 51'
[dbus-monitor]: Kernel#dbus-monitor 'Monitor messages going through a D-Bus message bus'
[dd]: #dd 'Perform multiple operations related to backing up data and creating files. One common use is to make a backup of an entire drive.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 269'
[declare]: #declare 'Declare variables and manage their attributes&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 85'
[depmod]: Kernel#depmod 'Builds the modules.dep file, which contains module dependencies and is used by `modprobe` to determine which modules need to be loaded&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 15'
[df]: #df 'Display usage of partitions and logical devices&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 49'
[diff3]: #diff3 'Compare three files and report differences&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 63'
[diff]: #diff 'Report lines that differ between `$FILE` and `$OTHER`. Output consists of lines of context from each file, with `$FILE` text flagged by a "&lt;" and `$OTHER` text by a "&gt;". (cf. `cmp`, `comm`, `diff3`, `dircmp`, and `sdiff`).&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 58'
[dig]: #dig 'Query DNS servers&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 64'
[dirname]: #dirname 'Strip filename from `$PATH` (cf. `basename`)'
[dirs]: #dirs 'Print the directory stack managed by `pushd` and `popd`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 87'
[disown]: #disown 'Remove one or more `$JOB` from list of jobs managed by bash&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 87'
[dmesg]: Kernel#dmesg 'Display in-memory copy of the kernel ring buffer&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 178'
[dnf]: Package-management#dnf 'Package manager for Red Hat systems that supercedes `yum`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'
[do]:   #do 'Reserved word that precedes the command sequence in a `for`, `while`, `until`, or `select` statement&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 88'
[done]: #done 'Reserved word that ends a `for`, `while`, `until`, or `select` statement&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 88'
[dos2unix]: #dos2unix 'Convert files using the DOS extended character set to their ISO standard counterparts&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 66'
[dpkg-reconfigure]: Package-management#dpkg-reconfigure 'Run the configuration script that is typically installed as part of the installation process.&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 39'
[dpkg]: Package-management#dpkg 'Manage local Debian packages&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 39'
[dracut]: Kernel#dracut 'Executed by `mkinitrd` but rarely used manually&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 8'
[dselect]: Package-management#dselect 'Interactive, menu-driven frontend tool for `dpkg`, usually invoked without parameters. It allows you to interactively manage packages by selecting them for installation, removal, configuration, etc.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 51'
[du]: #du 'Display disk utilization information for `$DIRS`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 153'
[echo]: #echo 'Write `$STRING` to STDOUT&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 88'
[ed]: #ed 'Line-oriented text editor, superceded by `vi` and `ex`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 70'
[edquota]: #edquota 'Create or edit disk quota of `$USER`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 99'
[egrep]: #egrep 'Equivalent to `grep -E`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 128'
[enable]: #enable 'Enable or disable shell builtins, allowing an external version of a command like `echo` or `test` be used.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 89'
[env]: #env 'Display the current environment, or set them to a new value if specified.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 75'
[esac]: #esac 'Reserved word that ends a `case` statement&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 90'
[etags]: Build#etags 'Create a list of function and macro names defined in a programming source file, generating tags for use by `emacs`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 75'
[ethtool]: #ethtool 'Display and configure network device settings.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 22'
[eval]: #eval 'Execute `$ARGS` after first performing variable expansion.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 90'
[ex]: #ex 'Line-oriented text editor, a superset of `ed` and the root of `vi`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 78'
[exec]: #exec 'Execute `$CMD` in place of the current process.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 91'
[exif]: #exif 'View image metadata, producing columnar output'
[exim]: #exim ''
[exit]: #exit 'Exit a shell script with status `$N`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 92'
[expand]: #expand 'Convert Tabs to spaces&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 79'
[export]: #export 'Convert `$VAR` to a global variable&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 92'
[export]: #export 'Convert an existing local variable to an environment vairable&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 53'
[fallocate]: #fallocate 'Allocate and deallocate space to a file'
[false]: #false 'Built-in command that exits with a false return value.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 93'
[fc]:   #fc 'Display or edit commands in the history list&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 93'
[fg]:   #fg 'Bring `$JOB` to the foreground&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 95'
[fg]: #fg 'Place `$JOB` in the foreground&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 119'
[fgrep]: #fgrep 'Search one or more files for lines that match a literal, text-string `$PATTERN`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 82'
[fi]:   #fi 'Reserved word that ends an `if` statement&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 95'
[file]: #file 'View image metadata'
[find]: #find 'Search recursively through directory trees for files or directories that match certain characters, either printing the file or directory or performing other operations on matches&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 96'
[firewall-cmd]: #firewall-cmd 'In Red Hat systems, the successor to `iptables` and like it a frontend to the `netfilter` protocols; places network traffic into "zones". Commands have to be written twice: once to affect running config and again to have the change saved'
[flex]: #flex '"Fast Lexical Analyzer Generator", faster variant of `lex` translated into C by Vern Paxson&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 92'
[fmt]: #fmt 'Format text to a specified width by filling lines and removing newline characters&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 79'
[for]: bash#for 'For variable `$X`, do `$CMD`; if `$LIST` is omitted, use `$@`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 95'
[free]: #free 'Display amount of free and used memory&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[ftp]: #ftp 'Establish an interactive FTP connection with a host to transfer files interactively.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 378'
[function]: #function 'Define `$NAME` as a shell function&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 97'
[g++]: Build#g 'Invoke `gcc` with the options necessary to make it recognize C++.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 95'
[galliumos-repodist]: Package-management#galliumos-repodist 'Display all available GalliumOS repository distributions, along with their current configuration status for your machine.'
[gcc]: Build#gcc '"GNU Compiler Collection", formerly known as the "GNU C Compiler", compiles multiple languages to machine code.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 95'
[gcore]: Build#gcore 'Create a core image of each running process specified, which can be used with a debugger&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 98'
[gdb]: Build#gdb '"GNU DeBugger", allows you to step through the execution of a program in order to find the point at which it breaks&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 99'
[gem]: Package-management#gem ''
[getenforce]: #getenforce 'Determine the current SELinux mode&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 205'
[getfacl]: #getfacl 'Display the ACL of a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 199'
[getopts]: #getopts 'Process command-line arguments and check for legal options&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 97'
[getsebool]: #getsebool 'Display names and values of SELinux Booleans&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 206'
[gettext]: #gettext 'Translate `$STRING`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 99'
[glances]: #glances 'Cross-platform monitoring tool, written in Python&#10;Olushile, Paul. _Linux 5 Performance Monitoring and Tuning_.'
[gpasswd]: #gpasswd 'Interactively set the password for `$GROUP`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 326'
[gprof]: Build#gprof 'Display call-graph profile data of C programs'
[grep]: #grep 'Search `$FILES` for lines containing a match to regex `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[groff]: #groff 'Format documents to screen or for laser printing; GNU version of `troff`'
[groupadd]: #groupadd 'Add `$GROUP` to the system&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 325'
[groupdel]: #groupdel 'Delete `$GROUP` from the system&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 325'
[groupmod]: #groupmod 'Modify the parameters of `$GROUP`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 325'
[groups]: #groups 'Show the groups that `$USER` belongs to (default is effective user)'
[grub-install]: Boot#grub-install 'Install GRUB on the MBR of a hard drive&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 42'
[grub-mkconfig]: Boot# ""
[grub2-editenv]: Boot#grub2-editenv '```&#10;grub2-editenv&#10;```&#10;Manage the stored environment of GRUB&#10;"How to install the NVIDIA drivers on Fedora 31". Linuxconfig.org: 10/17/2019.'
[gunzip]: Archive#gunzip 'Identical to `gzip -d`, typically implemented as a link to `gzip`'
[gzcat]: Archive#gzcat 'Identical to `gzip -c`, typically implemented as a link to `gzip`'
[gzip]: Archive#gzip '"GNU Zip". Compress or decompress archives using the Lempel-Ziv (LZ77) compression algorithm.'
[hash]: #hash 'List the current set of hashed (previously found) commands&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 98'
[head]: #head 'Print the first few lines of one or more files&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 79'
[help]: #help 'Print usage information for each command that matches `$PATTERN` to STDOUT&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 99'
[history]: #history 'Display the contents of the history command list&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 57'
[history]: #history 'Print commands in the history list or manage the history file&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 100'
[host]: #host 'Perform simple DNS queries&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 20'
[hping3]: #hping3 'Active network smashing tool'
[hwclock]: #hwclock 'Access the BIOS clock&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 340'
[if]:   #if 'Begin a conditional statement&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 101'
[ifconfig]: #ifconfig 'Obsolete program that configures network interfaces&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 386'
[iftop]: #iftop 'Display network connections using the most bandwidth&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 281'
[ifup-wireless]: #ifup-wireless 'Configure wireless networks&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 28'
[insmod]: Kernel#insmod 'Insert a module into the running kernel&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 15'
[install]: #install 'Copy files while maintaining metadata'
[ip]: #ip 'Newer alternative to the old `ifconfig`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 21'
[iperf]: #iperf 'Create tests of the throughput between two systems, requiring setup on both client and server&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 281'
[ipset]: #ipset 'Create a "set" of IP addresses to which firewall rules can be applied&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 282'
[iscsiadm]: #iscsiadm 'Command-line utility allowing discovery and login to iSCSI targets'
[iw]: #iw 'Show or manipulate wireless devices and their configuration'
[iwconfig]: #iwconfig 'Display or set information about wireless network interfaces.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 25'
[iwlist]: #iwlist 'Get detailed wireless information about a wireless interface'
[jobs]: #jobs 'List active jobs&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 119'
[jobs]: #jobs 'List all running or stopped jobs, or list those specified by `$JOBS`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 102'
[join]: #join 'Print a line for each pair of input lines, one each from `$FILE` and `$OTHER`, that have identical join fields.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 80'
[journalctl]: Kernel#journalctl '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 219'
[kill]: #kill 'Send signals to processes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 116'
[kill]: #kill 'Terminate each specified PID&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 103'
[killall]: #killall 'Stop all processes of a given name&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 96'
[kinit]: #kinit 'Kerberos utility to obtain an individual ticket, which is then cached on the local system.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 239'
[klist]: #klist 'Display a list of cached Kerberos tickets&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 239'
[last]: #last 'Display history of successful logins'
[lastb]: #lastb 'Display failed login attempts&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 255'
[ldconfig]: Kernel#ldconfig 'Update the ld.so cache file with shared libraries specified on the command line in /usr/lib, /lib, directories found in /etc/ld.so.conf, and `$LIBDIRS`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 45'
[ldd]: Build#ldd 'List dynamic dependencies: shared objects that would be loaded if `$FILE` were executed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 115'
[less]: #less 'Pager&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 116'
[let]: #let 'Perform arithmetic as specified by one or more `$EXPRESSIONS`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 104'
[lex]: Build#lex 'Generate a lexical analysis program based on the regular expressions and C statements contained in one or more input files (also `flex`)&#10;Lexical analyzer generator written by Eric Schmidt&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 119'
[lilo]: Boot#lilo '`lilo` map installer reads a configuration file and writes a map file, which contains information needed by the boot loader to locate and launch Linux kernels or other operating systems.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 40'
[link]: #link 'Create a link between two files, similar to `ln` but with no error checking'
[ln]: #ln 'Create a link&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
[loadaverage]: #loadaverage 'Display system load average (cf. `uptime`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 291'
[local]: #local 'Declare local variables for use inside functions&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 105'
[locate]: #locate 'Search for files based on a database that is typically created daily.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 138'
[logger]: #logger 'Create a one-time file entry specified by the user&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 342'
[logout]: #logout 'Exit a login shell, executing ~/.bash_logout if it exists&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 105'
[logrotate]: #logrotate 'Rename ("rotate") log files on a cyclic basis using /etc/logrotate.conf to determine behavior&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 445'
[look]: #look 'Look through a sorted file and print all lines that begin with `$STRING`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 124'
[ls]: #ls 'List files in a directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 131'
[lsattr]: #lsattr 'Display the attributes for a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 311'
[lsb_release]: #lsb_release '&#10;Print distribution-specific information'
[lsmod]: Kernel#lsmod 'Display kernel modules that are loaded into memory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 11'
[lsns]: #lsns 'List existing namespaces. Namespace with which PIDs can also be accessed'
[lsof]: #lsof 'Display open files, open network ports, and network connections&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 303'
[mail]: #mail '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 222'
[mailmerge]: #mailmerge ''
[mailq]: #mailq '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 223'
[mailx]: #mailx ''
[make]: Build#make 'Utility for building and maintaining programs from source code using a makefile&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'
[makemap]: #makemap 'Execute after making a change to the `sendmail` access database /etc/access'
[man]: #man 'Discover additional information about a command&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 55'
[man]: #man 'Format and display system manual pages&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 75'
[mapfile]: #mapfile 'Read STDIN into `$ARRAY`, one line per element, or `$MAPFILE` shell variable if not specified&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 105'
[md5sum]: #md5sum 'Display MD5 checksum value for a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 275'
[mkdir]: #mkdir 'Create one or more directories&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 98'
[mkinitrd]: Kernel#mkinitrd 'Creates initramfs file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 8'
[mktemp]: #mktemp 'Create a temporary file or directory safely and print its name. These will not need to be manually cleaned up because they will be placed in the temporary directory /tmp'
[modinfo]: Kernel#modinfo 'Display information about a module from its `module_object_file`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 17'
[modprobe]: Kernel#modprobe 'Insert modules, like `insmod`. In fact, `modprobe` is a wrapper around `insmod` which provides additional functionality.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 18'
[more]: #more 'Display text one page at a time; superceded by `less`.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 116'
[mpstat]: #mpstat 'utility for monitoring CPU performance&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 635-637'
[msmtp]: #msmtp ''
[mtr]: #mtr 'Performs a `traceroute`-like operation every second&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 285'
[mv]: #mv 'Move or rename files and directories&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 98'
[netcat]: #netcat 'Versatile utility for TCP or UDP connections&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 284'
[netplan]: #netplan 'Ubuntu network configuration tool'
[netstat]: #netstat 'Print network connections, routing tables, interface statistics, masquerade connections, and multi-cast memberships&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[newaliases]: #newaliases '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 602'
[nice]: #nice 'Assign a nice number to a new process at start time.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 120'
[nl]: #nl 'Number the lines of files, which are concatenated in the output.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 81'
[nmap]: #nmap 'Probe a system for open ports&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 280'
[nmblookup]: #nmblookup 'Test NetBIOS name resolution&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 591'
[nmcli]: #nmcli 'Configure NetworkManager&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 26'
[nmtui]: #nmtui 'Provide a text-based to configure NetworkManager.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 27'
[nohup]: #nohup 'Run a command immune to hangups, with output to a non-TTY terminal.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 119'
[nohup]: #nohup 'Start a child process which will not end when the parent does.&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 92'
[nproc]: #nproc 'Display number of CPU processors or cores&#10;Olushile, Paul. _Linux 5 Performance Monitoring and Tuning_.'
[nslookup]: #nslookup 'Perform simple queries on DNS servers&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 19'
[ntpdate]: #ntpdate 'Set the time of the local system to match a remote NTP host&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 336'
[od]: #od 'Dump files in octal and other formats&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 82'
[pacman]: Package-management#pacman ''
[passwd]: #passwd 'Interactively set the password for `$USER`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 325'
[paste]: #paste 'Paste together corresponding lines of one or more files into vertical columns, similar to but simpler than `join`.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 83'
[pgrep]: #pgrep 'List PIDs associated with a program name, similar to `ps -e | grep`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 304'
[pidof]: #pidof 'Query system to discover the PID of any named application'
[pine]: #pine "\"Program for Internet news and email\", popular MUA during the 1990s which has since been replaced by Alpine."
[pine]: #pine '"Program for Internet news and email", popular MUA during the 1990s which has since been replaced by Alpine'
[ping]: #ping 'Verify a remote host can respond to a network&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 18'
[pip]: Package-management#pip ''
[pkill]: #pkill 'Kill a process by providing a process name, user name, or group name&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 305'
[popd]: #popd 'Pop the top directory off the directory stack and change to the new top directory&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 106'
[postalias]: #postalias '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 224'
[postfix]: #postfix ''
[postqueue]: #postqueue '```&#10;postqueue&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 224'
[pr]: #pr 'Convert a text file into a paginated, columnar version, with headers and page fills&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 84'
[printenv]: #printenv 'Display environment variables&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 331'
[printf]: #printf 'Formatted printing using escape sequences&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 107'
[ps]: #ps 'List processes that are running on the system&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 303'
[pstree]: #pstree 'Display a hierarchical list of processes in a tree format; handy for understanding how parent/child process relationships are setup&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 110'
[pushd]: #pushd 'Add `$PATH` to the directory state, or rotate it if none provided&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 108'
[pwd]: #pwd 'Display current working directory on STDOUT&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 108'
[pwd]: #pwd 'Display the current directory of the shell&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 54'
[qmail]: #qmail ''
[quota]: #quota 'Display quota limits on user or group&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 169'
[quotacheck]: #quotacheck 'Examine filesystems and compile quota databases&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 171'
[quotaoff]: #quotaoff 'Disable disk quotas on one or more filesystems&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 171'
[quotaon]: #quotaon 'Enable previously configure disk quotas on one or more filesystems&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 170'
[read]: #read 'Read one line from STDIN and assign each word to the corresonding `$VAR`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 109'
[readarray]: #readarray 'Identical to `mapfile`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 111'
[readonly]: #readonly 'Prevent specified shell variables $VAR1, $VAR2 from being assigned new values, optionally assigning initial values $VAL1, $VAL2&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 111'
[rename]: #rename 'Rename files using regex'
[renice]: #renice 'Alter the nice number of a running process&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 122'
[repquota]: #repquota 'Display quotas for an entire filesystem&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 101'
[restorecon]: #restorecon 'Reset default security context on a file or directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 207'
[return]: #return 'Use inside a function definition, exiting with status `$N`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 112'
[rfkill]: #rfkill 'tool for enabling and disabling wireless devices'
[rm]: #rm 'Delete one or more files from the filesystem&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 99'
[rmdir]: #rmdir 'Delete empty directories&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
[rmmod]: Kernel#rmmod 'Remove modules from the running kernel.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 16'
[route]: #route 'Display or modify routing table&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 21'
[rpm]: Package-management#rpm 'Install, upgrade, and remove .rpm packages&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 78'
[rsync]: #rsync 'Copy files remotely; used in situations where only updated files are to be transferred in order to preserve bandwidth.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 131'
[rsyslogd]: #rsyslogd 'Responsible for logging of application and system events&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 249'
[sar]: #sar 'Displays the same information as `iostat`, but displayed as it occurs over time (typically at 10-minute intervals)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 291'
[scp]: #scp 'Copy files to and from remote systems via `ssh`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 130'
[sed]: #sed '"Stream editor", powerful filtering program found on nearly every Unix system.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 128'
[select]: #select '&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 112'
[semanage]: #semanage 'Edit security contexts for files and ports&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 206'
[sendmail]: #sendmail ''
[sestatus]: #sestatus 'Display status of SELinux&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 205'
[set]: #set 'Print values of all variables known to the current shell.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 113'
[setenforce]: #setenforce 'Change SELinux mode&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 205'
[setfacl]: #setfacl 'Create an ACL on a file or directory.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 199'
[setsebool]: #setsebool 'Set an SELinux Boolean&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 206'
[setuid]: #setuid '"set-user identification": permission bit which, if set on an executable file, will ensure that the file is granted access based on the owner of the file, rather than the use who is running it'
[sftp]: #sftp 'Securely transfer files over ssh&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 274'
[shift]: #shift 'Shift positional arguments; intended for use in a loop.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 119'
[shopt]: #shopt 'Set or unset shell options.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 119'
[shuf]: #shuf 'Randomly permute input'
[sleep]: #sleep '```&#10;sleep $N&#10;```&#10;Wait `$N` seconds before executing another command'
[snap]: #snap '```&#10;snap&#10;```&#10;'
[sort]: #sort 'Sort text data&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 124'
[source]: #source 'Execute a bash script as if the commands within it were executed directly on the command line&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 332'
[source]: #source 'Read and execute a file in the current shell&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 120'
[split]: #split 'Split `$INFILE` into a specified number of line groups, named `$OUTFILE`aa, `$OUTFILE`ab, etc&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 86'
[ss]: #ss '```&#10;ss&#10;```&#10;Display socket information.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 25'
[ssh-add]: #ssh-add '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-add]: #ssh-add '```&#10;ssh-add&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-agent]: #ssh-agent '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-agent]: #ssh-agent '```&#10;ssh-agent&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-keygen]: #ssh-keygen '```&#10;ssh-keygen&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 267'
[ssh-keyscan]: #ssh-keyscan '...'
[ssh]: #ssh '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 266'
[ssh]: #ssh '```&#10;ssh&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 266'
[sshfs]: #sshfs '```&#10;sshfs&#10;```&#10;'
[stat]: #stat 'See inode information of a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 135'
[strace]: #system-calls 'debugging tool that displays a trace of all system calls made by a process&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 418'
[stty]: #stty '```&#10;stty&#10;```&#10;'
[su]: #su 'Allow a user to shift user accounts&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 209'
[su]: #su '```&#10;su&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 254'
[sudo]: #sudo '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 253'
[sudo]: #sudo '```&#10;sudo&#10;```&#10;Run commands as other users (typically as the root user).&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 209'
[sudoedit]: #sudoedit '```&#10;sudoedit&#10;```&#10;Edit a file using sudo&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 210'
[suspend]: #suspend 'Suspend the current shell, often used to stop an `su` command&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 120'
[sysbench]: #sysbench 'Multi-threaded benchmark tool for database systems'
[syslogd]: #syslogd 'Responsible for logging of application and system events&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 249'
[tac]: #tac 'Print text files to STDOUT with lines in reverse order&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 87'
[tail]: #tail 'Display the bottom part of text data.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 115'
[tar]: Archive#tar 'Merge multiple files into a single file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 268'
[tcpdump]: #tcpdump 'Inspect IP packets (Wireshark is a GUI-based alternative)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 282'
[tee]: #tee 'Send output to both STDOUT and to a file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 122'
[tee]: #tee '```&#10;tee&#10;```&#10;Send STDOUT to the terminal and to a file&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 86'
[telnet]: #telnet '```&#10;telnet&#10;```&#10;Establish a connection to a host.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 380'
[test]: #test 'Evaluate a condition and exit with status 0 if true, or with a nonzero exit status if false.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 120'
[time]: #time 'Determine how long it takes to run a command&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 302'
[time]: #time 'Execute `$CMD` and print the total elapsed time, user time, and system time (in seconds). Similar to external `time` command, except that this builtin version can also time other builtin commands and all commands in a pipeline.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 124'
[timedatectl]: #timedatectl 'Display system clock&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 71'
[times]: #times 'Print accumulated user and system process times for the shell and the processes it has run&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 125'
[top]: #top 'Display continuously updated display of processes similar to `ps`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 112'
[touch]: #touch 'Used to create empty files and to update modification and access timestamps of existing files.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 129'
[tr]: #tr 'Translate characters from one set to another&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 123'
[tracepath6]: #tracepath6 '```&#10;tracepath6&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 246'
[tracepath]: #tracepath '```&#10;tracepath&#10;```&#10;Similar to `traceroute`, but with fewer options and no requirement for superuser privileges&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 287'
[traceroute]: #traceroute '```&#10;traceroute&#10;```&#10;Follow the path a packet takes between two hosts&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 285'
[trap]: #trap 'Execute `$CMD` if any `$SIGNALS` are received&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 125'
[tree]: #tree 'Display contents of directories in a tree-like format'
[true]: #true 'Built-in command that exits with a true return value&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 127'
[tshark]: #tshark '```&#10;tshark&#10;```&#10;Wireshark terminal interface&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 283'
[tty]: #tty 'Determine terminal device file for current session&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 121'
[type]: #type 'Show whether each command name is an external command, a built-in command, an alias, shell keyword, or defined shell function&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 127'
[typeset]: #typeset 'Identical to `declare`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 128'
[tzconfig]: #tzconfig '```&#10;tzconfig&#10;```&#10;Set time zone by setting a symbolic link from /etc/localtime to a file in /usr/share/zoneinfo&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 330'
[tzselect]: #tzselect '```&#10;tzselect&#10;```&#10;Menu-based script that interactively determines appropriate value for `$TZ` environment variable&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 331'
[udevadm]: Kernel#udevadm 'Load new rules into kernel memory, or verify they have taken effect, after changing a udev rule.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 181'
[ufw]: Network#ufw 'Ubuntu firewall frontend'
[ulimit]: #ulimit '```&#10;ulimit $USER&#10;```&#10;Display or set a account limits of `$USER`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 201'
[umask]: #umask 'Set file creation mask to octal value `$MASK`, or display it if not provided.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 130'
[unalias]: #unalias 'Remove `$NAMES` from the alias list.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 130'
[uname]: #uname 'Print the current Unix system name&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 221'
[uncompress]: Archive#uncompress 'Aliased to `gunzip` on Ubuntu&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 480'
[unexpand]: #unexpand 'Convert spaces to tabs&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 89'
[uniq]: #uniq 'Write $INPUT to $OUTPUT, eliminating adjacent duplicate lines&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 89'
[unlink]: #unlink 'Does essentially what `rm` does, but in a subtly different way.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 135'
[unset]: #unset 'Erase definitions of functions or variables listed in `$NAMES`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 130'
[until]: #until 'Until `$CONDITION` is met, do `$CMDS`&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 131'
[unxz]: Archive#unxz 'Decompress an archive created with `xz`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[unzip]: Archive#unzip 'Decompress a .zip archive'
[update-grub]: Boot#update-grub 'Make changes take effect for a GRUB2 configuration change'
[updatedb]: #updatedb 'Refresh (or create) the `slocate` database at /var/lib/slocate/slocate.db&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 202'
[uptime]: #uptime 'Display current time, how long the system has been running, how many users are currently logged on, and the system load averages for the past 1, 5, and 15 minutes&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 114'
[useradd]: #useradd '```&#10;useradd $USER&#10;```&#10;Create the account `$USER` according to system defaults and specified options.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 323'
[userdel]: #userdel '```&#10;userdel $USER&#10;```&#10;Delete an existing user account&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 324'
[usermod]: #usermod '```&#10;usermod&#10;```&#10;Modify a user account&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
[visudo]: #visudo '```&#10;visudo&#10;```&#10;Safely edit the /etc/sudoers file'
[vmstat]: #vmstat 'provides more detail than `free`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 293'
[vncpasswd]: #vncpasswd '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 561'
[vncviewer]: #vncviewer '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 561'
[w]: #w '```&#10;w&#10;```&#10;Display output similar to that of `uptime` for all logged-in users&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 97'
[wait]: #wait 'Pause until the specified `$JOB`, which can be a job number or PID, completes, or until all background jobs complete if not provided.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 131'
[wall]: #wall '```&#10;wall&#10;```&#10;Broadcast a message to all users who are currently logged in&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 16'
[watch]: #watch '```&#10;watch&#10;```&#10;Repeat a command at regular intervals and watch its changing output'
[wc]: #wc 'Display number of lines, words, or characters of data.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 128'
[wget]: #wget 'Noninteractive tool to download files from remote systems via HTTP, HTTPS, or FTP.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 89'
[whatis]: #whatis '```&#10;whatis&#10;```&#10;Look up one or more commands in the online manpages and display a brief description'
[where]: #where '```&#10;where&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 167'
[whereis]: #whereis 'Search for binary executables, source code, and manual pages in standard locations as well as the PATH and `$MANPATH`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 139'
[whereis]: #whereis '```&#10;whereis&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 147'
[which]: #which 'Determine the location of `$CMD` and display its full path&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 200'
[which]: #which '```&#10;which&#10;```&#10;&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 147'
[while]: #while 'While `$CONDITION` is met, do `$CMDS`.&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 132'
[who]: #who '```&#10;who&#10;```&#10;Display currently users currently logged in&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 97'
[whoami]: #whoami '```&#10;whoami&#10;```&#10;Display effective user ID&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 96'
[whois]: #whois 'Determine domain ownership&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 287'
[x]: #x 'Start the graphical interface from the command-line'
[xargs]: #xargs '```&#10;xargs $CMD&#10;```&#10;Execute `$CMD` followed by optional arguments.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 107'
[xdpyinfo]: #xdpyinfo 'Show detailed information about display'
[xfs]: #xfs 'X fonts server; small daemon that sends fonts to clients on both local and remote systems.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 307'
[xgettext]: Build#xgettext 'Extract specially marked strings from C and C++ source files, placing them in a .po ("portable object" file for translation and compilation by `msgfmt`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 234'
[xhost]: #xhost 'Set access controls to X server'
[xinetd]: #xinetd 'Internet Super Daemon provided an alternate method of connecting to various outdated network services. Should be turned off nowadays.'
[xlsclients]: #xlsclients 'Determine what applications are running on the legacy X11 server provided with Wayland.'
[xmodmap]: #xmodmap 'Utility for modifying keymaps and pointer button mappings in X'
[xorg]: #xorg 'Full featured X server that was originally designed for UNIX and UNIX-like operating systems running on Intel x86 hardware'
[xrandr]: #xrandr 'Set size, orientation, and reflection of video output'
[xset]: #xset 'Set various user preference options of the display&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 307'
[xwininfo]: #xwininfo 'Utility that provides information about a clicked window, including dimensions, position, etc'
[xz]: Archive#xz 'Compress or decompress archives using the LZMA and LZMA2 compression methods.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 270'
[yacc]: Build#yacc '"yet another compiler-compiler", parser generator that converts a file containing a context-free LALR grmamar and converts it to tables for subsequent pasring, sending output to y.tab.c. Written between 1975 and 1978 by Stephen C. Johnson at Bell Labs.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 237'
[yay]: Package-management#yay ''
[yum]: Package-management#yum 'Package manager for Red Hat systems&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 83'
[yumdownloader]: Package-management#yumdownloader 'Download software packages without installing them&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 84'
[zcat]: Archive#zcat 'Uncompress one or more compressed files to STDOUT. On Linux, this program is the version related to `gzip`, which can decompress .Z and .gz files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 238'
[zip]: Archive#zip 'Merge multiple files into a single, compressed file&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 271'
[zipcloak]: Archive#zipcloak 'Password protect and encrypt zip files, equivalent to `zip --encrypt` or `zip -e`.&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 37'
[zipcmp]: Archive#zipcmp 'Compare files in zip archives (no man page or help option available).&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 37'
[zipdetails]: Archive#zipdetails ''
[zipgrep]: Archive#zipgrep 'Search for patterns within a zip archive.&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 37'
[zipinfo]: Archive#zipinfo 'Display the attributes of all the files in a zip archive, including permissions, name, date created, uncompressed and compressed file sizes, and percentage compression.&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 38'
[zipnote]: Archive#zipnote 'Read and edit comments in archives; particularly useful for changing filenames in an archive that start with "@home" in the comment&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 38'
[zipsplit]: Archive#zipsplit 'Divide existing archives into smaller ones, creating an index file to help reassemble them.&#10;_Linux Pro Magazine_. Issue 231. Feb 2020.: 38'
[zypper]: Package-management#zypper 'Package manager for SUSE with a syntax similar to that of `yum`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'
