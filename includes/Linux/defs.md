## 📘 Glossary

**address space**{: #address-space }
:   An **address space** consists of a set of pages in memory allocated to the process. (ULSAH: 90)


**Alpine Linux** :cd:
:   Security-oriented, lightweight Linux distribution used in containers and hardware.


**awesome**{: #awesome } :material-dock-window: [:material-play:][hObzf9ppODJU]
:   Originated as a fork of [dwm](#dwm), it offers creature comforts that make it the easiest to adjust to as a new user of tiling window managers. 
    It is written in Lua, as its config must be. 
    Like dwm, each monitor has an independent pool of workspaces. 

**bspwm** ("Binary Space Partitioning Window Manager") :material-dock-window: [:material-play:][hObzf9ppODJU]
:    Tiling window manager that uses tree partitioning as the logic for organizing tiles, with the default being the "dwindle" pattern. 
    Like [awesome](#awesome), bspwm uses a shared pool of workspaces, but they are individually assigned to monitors in the configuration file.
    
    Notably, it uses two config files: 
    
    - **.bspwmrc** which determines what programs to autoload but doesn't contain any key bindings
    - **.sxhkdrc** which uses a syntax similar to [i3](#i3) or herbstluft.



**Berkeley Software Distribution (BSD)**{: #bsd } :cd: began in the 70s and was based on AT&T original code. 
First source distributions required user to purchase a source license from AT&T, since much of the BSD source was derivative of UNIX.

Berkeley finally released a "wholly-BSD" product as **Network Release 1** in 1989, which satisfied vendor demand for the TCP/IP networking code for PC.

Work immediately began to reconstruct the remaining functionality of UNIX, which was completed in Network Release 2, released in 1991, which was based entirely on Berkeley code. Eventually this resulted in the 386BSD distribution, which then spawned five interrelated BSD distros: BSDI (now Wind River), NetBSD, FreeBSD, OpenBSD, and Darwin/Mac OS X

**Unix System Laboratories (USL)** sued BSDI after BSDI attempted to market its product as a real UNIX, and other BSD distributions were affected by disputed code. 
Ultimately 3 out of the 18,000 files that made up the Network Release 2 distribution were removed, which became known as BSD-lite, released in 1994. 
This legal dispute was partly to blame for Linux's rapid ascent in popularity. [<sup>:material-link:</sup>](https://web.archive.org/web/20060315152051/http://www.applelust.com/alust/terminal/archives/terminal041202.shtml)


**CentOS**{: #centos } :cd:
:   A community distribution of Linux that was created by Gregory Kurtzer in 2004 and acquired by [Red Hat](#rhel) in 2014. 
    It has traditionally been [considered <sup>:material-link:</sup>](https://itsfoss.com/centos-stream-fiasco/) **downstream** to [RHEL](#rhel), incorporating changes to RHEL after a delay of several months. 
    In fact, it is a rebuild of the publicly available **source RPMs (SRPMs)** of RHEL packages, which historically allowed CentOS maintainers to simply package and ship them [rebranded](https://fosspost.org/centos-project-suicide/).

    For years, CentOS was the [distribution of choice <sup>:material-link:</sup>](https://www.zdnet.com/article/red-hat-resets-centos-linux-and-users-are-angry/#ftag=RSSbaffb68) for experienced Linux administrators who did not feel the need to pay for Red Hat's support.
    In December 2020, Red Hat [announced](https://itsfoss.com/centos-stream-fiasco/) that CentOS 8 support will end at the end of 2021 (rather than 2029), while CentOS 7 will continue to be supported until 2024. 
    This represented a shift in focus from CentOS Linux to [**CentOS Stream**](#centos-stream) and a change from a **fixed-release** (or "stable point release") to a **rolling-release** distribution model.

**CentOS Stream**{: #centos-stream} :cd:
:   **CentOS Stream** was [announced](https://itsfoss.com/centos-stream-fiasco/) in September 2019 as a distribution of CentOS maintained on a model previously misidentified as rolling-release but now described as "continuously delivered", organized into Streams. 
    CentOS Stream [originated <sup>:material-link:</sup>](https://linuxunplugged.com/383) in an effort to get more community participation in development of RHEL, rather than merely passive consumption.



**Clear Linux**{: #clear-linux } :cd:
:   Rolling release distro from Intel with a custom package management system based on **bundles**, collections of packages that contain everything an application requires, including dependencies. 
    Clear's update process also has the ability to do **delta downloads**, preserving bandwidth. 
    It does not provide access with unusual licenses, like ZFS, Chrome, or FFmpeg. [:material-link:][LXF 258]

**display manager**{: #display-manager }
:   Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).


**dwm**{: #dwm } :material-dock-window: [:material-play:][hObzf9ppODJU]
:   One of the oldest and lightest tiling window managers. 
    Because suckless wants the source code not to exceed 2,000 lines of code, a lot of functionality is incorporated by means of **patches**, which modify the source code using diff files. 
    Workspaces are called **tags**. 
    A window can be associated with more than one tag, placing it on more than one workspace. 
    Each monitor has a separate pool of workspaces. 


**/etc/bluetooth/input.conf** :material-hammer-wrench:
:   Fix bluetooth mouse constantly disconnecting ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
    ```ini
    UserspaceHID=true
    ```

**/etc/bluetooth/main.conf** :material-hammer-wrench:
:   Power on Bluetooth adapter at startup ([src](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects 'Ask Ubuntu: "Bluetooth mouse constantly disconnects and reconnects"'))
    ```ini
    [Policy]
    AutoEnable=true
    ```

**/etc/group** :material-hammer-wrench:
:   Colon-delimited file describing group membership
    ```
    $GROUP:$PASSWORD:$GID:$USER1:$USER2:$USER3...
    ```
    /etc/resolv.conf
    Use DNS queries prior to consulting /etc/hosts
    ```sh
    nameserver dns
    nameserver files
    ```

**/etc/shadow** :material-hammer-wrench:
:   Colon-delimited file containing password hashes for every user listed in [/etc/passwd](#etc-passwd)
    ```
    $USERNAME:$PASSWORD:$LASTCHANGED:$MIN:$MAX:$WARN:$INACTIVE:$EXPIRE
    ```

    - **$USERNAME** Login name
    - **$PASSWORD** Encrypted password; dollar signs delimit encryption hash function ([`$1`](#etcshadow "MD5"), [`$2a`](#etcshadow "Blowfish"), [`$2y`](#etcshadow "Blowfish"), [`$5`](#etcshadow "SHA-256"), or [`$6`](#etcshaodw "SHA-512")), then salt, then hash value. After locking the account with `usermod -L`, an exclamation point `!` is placed in front of this field, making the password inoperable and locking the account.  When an account has not yet had a password set, this value is `!!`
    - **$LASTCHANGED** Days since 01/01/1970 that password was last changed
    - **$MIN** minimum number of days required between password changes
    - **$MAX** maximum number of days the password is valid before user is forced to change password
    - **$WARN** number of days the password is to expire that user is warned that password must be changed
    - **$INACTIVE** number of days after password expires that account is disabled
    - **$EXPIRE** days since 01/01/1970 that account is disabled



**Fedora**{: #fedora } :cd:
:   **Fedora** is a community distribution supported by Red Hat launched as "Fedora Core" in 2003. 
    It has traditionally been [considered :material-link:](https://itsfoss.com/centos-stream-fiasco/) as **upstream** to RHEL, serving as a testing ground for new features and improvements.

**Fedora CoreOS**{: #fedora-coreos } :cd:
:   **Fedora CoreOS** is a Fedora edition [built <sup>:material-link:</sup>](https://fedoramagazine.org/introducing-fedora-coreos/ 'Fedora Magazine: "Introducing Fedora CoreOS"') specifically for running containerized workloads securely and at scale. 
    Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime.
    CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. 
    All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.

    CoreOS automatically installs upgrades automatically without user intervention, although they can be stopped if a problem is found.



**herbstluft** :material-dock-window: [:material-play:][hObzf9ppODJU]
:   Tiling window manager with a single pool of workspaces that is shared across all monitors.


**i3**{: #i3 } :material-dock-window: [:material-play:][hObzf9ppODJU]
:   Perhaps the most popular tiling window manager, typically used with [polybar](polybar).

**initrd**{: #initrd } ("initial RAM disk")
:   A temporary file system that's loaded into memory when the system boots

**Mail Delivery Agent**{: #mda }
:   Service that downloads email from an MTA, such as procmail and fetchmail

**Mail Transfer Agent**{: #mta }
:   Email server, such as sendmail, postfix, smail, and qmail

**Mail User Agent**{: #mua }
:   Program that allows a user to view mail, such as mutt, pine, printmail, elm, mail, Thunderbird, Evolution, and Eudora

**Process**{: #process }
:   A process consists of an [address space](#address-space) and a set of data structures within the kernel. 

**qmail**{: #qmail }
:   MTA designed as a drop-in replacement for Sendmail, notable for being the first to be "security-aware". 
    Its various modular subcomponents run independently and are mutually untrustful. 
    It uses SMTP to exchange messages with other MTAs. 

    It was written by Dan Bernstein, a professor of mathematics famous for litigating against the US government with regard to export controls on encryption algorithms. 
    qmail was deprecated and removed from Arch repos in 2005.

**thread**{: #thread }
:   A **thread** is an execution context within a [process][#process].

**Red Hat**{: #rhel } :cd:
:   **Red Hat Enterprise Linux (RHEL)** is Red Hat's commercial Linux distribution.

    After a shift in late 2020, CentOS Stream is no considered  upstream to RHEL (ahead by a point-release), but rather downstream from Fedora.


**SUSE**{: #suse }
:   - **OpenSUSE Leap** is a rebuild of [SUSE Linux Enterprise Server](#sles), similar to how [CentOS](#centos) was historically a rebuild of RHEL.
    - **SUSE Linux Enterprise Server (SLES)** ("slee") is SUSE's fixed-release distribution of Linux intended for enterprises, and as such is comparable to Red Hat's RHEL.



#### WSL

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


**xmonad** :material-dock-window: [:material-play:][hObzf9ppODJU]
:   A tiling window manager made especially difficult to configure because the program and config is written in Haskell.
    All monitors share the same pool of workspaces.
    Unusually for tiling window managers, when using multiple monitors, switching to another workspace actually switches the position of that workspace with the previous one. 
    That is, the workspace that had previously been on the active monitor is sent to the workspace being called.


