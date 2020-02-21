<!-- Sources -->
[ADP 57]: ../sources/README.md#adp-57 "Azure DevOps Podcast 57: \"Craig Loewen on the Windows Subsystem for Linux story\""
[LXF 258]: https://www.linuxformat.com/archives?issue=258 '"Linux distribution reviews: Clear Linux 31530" _Linux Format_ 258'

<!-- Definitions -->
[Alpine Linux]: #alpine-linux "Security-oriented, lightweight Linux distribution used in containers and hardware."
[Clear Linux]: #clear-linux "Rolling release distro from Intel with a custom package management system based on **bundles**, collections of packages that contain everything an application requires, including dependencies. Clear's update process also has the ability to do **delta downloads**, preserving bandwidth. It does not provide access with unusual licenses, like ZFS, Chrome, or FFmpeg."
[Fedora CoreOS]: #fedora-coreos "Fedora edition built for running containerized workloads securely and at scale. CoreOS systems are meant to be immutable, meaning they are only configured through the provisioning process and not modified in-place."
[WSL]: #windows-subsystem-for-linux "Linux virtual machine shipped with Windows with the ability to install several different distros."

<!-- Kali Linux -->
[Aircrack-ng]: #kali-linux 'Aircrack-ng&#10;Monitor and compromise WiFi networks'
[BeEF]: #kali-linux 'BeEF&#10;Assess security of a web browser'
[Apktool]: #kali-linux 'Apktool&#10;Reverse engineer Android apps'
[AFB]: #kali-linux 'Autopsy Forensic Browser (AFB)&#10;Digital forensics'
[Burp Suite Scanner]: #kali-linux 'Burp Suite Scanner&#10;GUI-based web application security scanner'
[Hydra]: #kali-linux 'Hydra&#10;Crack login/password pairs'
[John the Ripper]: #kali-linux 'John the Ripper&#10;Crack passwords'
[King Phisher]: #kali-linux 'King Phisher&#10;Simulate phishing attacks'
[Lynis]: #kali-linux 'Lynis&#10;Security auditing, compliance testing'
[Maltego]: #kali-linux 'Maltego&#10;Data mining'
[Metasploit Framework]: #kali-linux 'Metasploit Framework&#10;Penetration testing framework'
[Nessus]: #kali-linux 'Nessus&#10;Paid tool to find vulnerabilities'
[Nikto]: #kali-linux 'Nikto&#10;Web server scanner'
[SET]: #kali-linux 'Social Engineering Toolkit (SET)'
[Skipfish]: #kali-linux 'Skipfish&#10;Web application scanner'
[Snort]: #kali-linux 'Snort&#10;Traffic analysis and packet logging'
[Sqlmap]: #kali-linux 'Sqlmap&#10;Exploit SQL injection flaws'
[Wireshark]: #kali-linux 'Wireshark&#10;Network analyzer'
[WPScan]: #kali-linux 'WPScan&#10;WordPress security auditing tool'
[Yersinia]: #kali-linux 'Yersinia&#10;Perform Layer 2 attacks'

<!-- Windows Subsystem for Linux-->
[DrvFs]: #windows-subsystem-for-linux 'DrvFs&#10;Filesystem plugin to WSL that was designed to support interoperability between WSL and the Windows filesystem. DrvFs enables WSL to mount drives with supported file systems under /mnt, such as /mnt/c, /mnt/d, etc. &#10;"Chmod/Chown WSL Improvements". _Windows Command Line_. Microsoft: 01/12/2018.'
[lxss.sys]: #windows-subsystem-for-linux 'LXSS Manager service (lxss.sys)&#10;One of the WSL "pico drivers" that translates Linux syscalls to equivalent Windows NT calls. Where there is no reasonable mapping, lxss.sys must service the request directly.&#10;"WSL System calls". _Windows Subsystem for Linux_. Microsoft.'
[pico driver]: #windows-subsystem-for-linux 'pico driver&#10;Reference to lsxx.sys and lxcore.sys in WSL, responsible for handling Linux syscall requests in coordination with the NT kernel.&#10;"WSL System calls". _Windows Subsystem for Linux_. Microsoft.'
[VFS]: #windows-subsystem-for-linux 'Virtual File System (VFS)&#10;Abstraction of file system operations used by WSL, which provides an interface for user mode programs to interact with the file system and an interface that file systems have to implement.&#10;"WSL File System Support". _Windows Subsystem for Linux_. Microsoft: 06/15/2016.'
[VolFs]: #windows-subsystem-for-linux 'VolFs&#10;The primary file system used by WSL, which is used to store the Linux system files and the contents of the home directory.&#10;VolFs supports most features the Linux VFS provides, including Linux permissions, symbolic links, FIFOs, sockets, and device files.&#10;"WSL File System Support". _Windows Subsystem for Linux_. Microsoft: 06/15/2016.'

# Linux distributions
#### Distros
**A** 
[Alpine Linux][Alpine Linux] 
[Arch Linux](#arch-linux) 
**C** 
[Clear Linux][Clear Linux] 
[CoreOS][Fedora CoreOS] 
**K** 
[Kali Linux](#kali-linux) 
**W** 
[Windows Subsystem for Linux][WSL]
## Alpine Linux
Security-oriented, lightweight Linux distribution used in containers and hardware.
## Arch Linux
#### Install Arch Linux
Inspect available drives and partitions before/after inserting USB drive
```sh
lsblk
```
Mount ISO (`if`)to USB drive (`of`), with progress displayed
```sh
dd if=Downloads/archlinux-2018.03.01-x86_64.iso of=/dev/sdba status="progress"
```
Reboot from the USB drive. If there are values displayed a UEFI system is required and a different installation sequence is needed.
```sh
ls /sys/firmware/efi/efivars
```
Ensure an Ethernet internet connection  or `wi-fi menu` a valid Wi-Fi connection is present
```sh
timedatectl set-ntp true
```
Begin the process of partitioning the disk; enter the `fdisk` command prompt
```sh
fdisk /dev/sdb
```
Set up `ext4` filesystem on boot, root, and home partitions
```sh
mkfs.ext4 /dev/sdb1
mkfs.ext4 /dev/sdb3
mkfs.ext4 /dev/sdb4
```
Make the swap partition a swap drive
```sh
mkswap /dev/sdb2
swapon /dev/sdb2
```
Mount partitions
```sh
mount /dev/sdb3 /mnt
mkdir /mnt/home
mkdir /mnt/boot
mount /dev/sdb1 /mnt/boot
mount /dev/sdb4 /mnt/home
```
Install Arch Linux on the directory provided with the packages `base`, `base-devel` (which includes `sudo` and other development tools), `vim`
```sh
pacstrap /mnt base base-devel vim
```
Make an `fstab` file, taking all the drives mounted at that location, going off of UUIDs rather than the `sd` identifiers (which might change)
```sh
genfstab -U /mnt > /mnt/etc/fstab
```
Change root to new Arch Linux installation
```sh
arch-chroot /mnt
```
Install `networkmanager` which will allow Ethernet Internet connections upon reboot
```sh
pacman -S networkmanager
```
Tell SystemD to start NetworkManager upon login
```sh
systemctl enable NetworkManager
```
Install GRUB
```sh
pacman -S grub
```
Install GRUB as bootloader
```sh
grub-install --target=i386-pc /dev/sdb
```
Generate GRUB configuration
```sh
grub-mkconfig -o /boot/grub/grub.cfg
```
Set password for root
```sh
passwd
```
Uncomment the two lines referring to US English
```sh
vim /etc/locale.gen
```
Read that file and set locale
```sh
locale-gen
```
Set `LANG` language variable
```sh
echo "LANG=en-US.UTF-8" > /etc/locale.conf
```
Set timezone by making `localtime` a link to the correct timezone (this command is all that is required when resetting timezone during travel)
```sh
ln -sf /usr/share/zoneinfo/America/New_York /etc/localtime
```
Write new hostname
```sh
echo archizard > /etc/hostname
```
Return to USB shell
```sh
exit
```
Unmount hard drive for safety
```sh
umount -R /mnt
```
Reboot
```sh
reboot
```
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
## BSD
**Berkeley Software Distribution (BSD)** began in the 70s and was based on AT&T original code. First source distributions required user to purchase a source license from AT&T, since much of the BSD source was derivative of UNIX.

Berkeley finally released a "wholly-BSD" product as **Network Release 1** in 1989, which satisfied vendor demand for the TCP/IP networking code for PC.

Work immediately began to reconstruct the remaining functionality of UNIX, which was completed in Network Release 2, released in 1991, which was based entirely on Berkeley code. Eventually this resulted in the 386BSD distribution, which then spawned five interrelated BSD distros.
1. BSDI (now Wind River)
2. NetBSD
3. FreeBSD
4. OpenBSD
5. Darwin/Mac OS X

**Unix System Laboratories (USL)** sued BSDI after BSDI attempted to market its product as a real UNIX, and other BSD distributions were affected by disputed code. Ultimately 3 out of the 18,000 files that made up the Network Release 2 distribution were removed, which became known as 4.4BSD-lite, released in 1994. This legal dispute was partly to blame for Linux's rapid ascent in popularity.\
Source: [Article](https://web.archive.org/web/20060315152051/http://www.applelust.com/alust/terminal/archives/terminal041202.shtml)
## Clear Linux
Rolling release distro from Intel with a custom package management system based on **bundles**, collections of packages that contain everything an application requires, including dependencies. Clear's update process also has the ability to do **delta downloads**, preserving bandwidth. It does not provide access with unusual licenses, like ZFS, Chrome, or FFmpeg. [^][LXF 258]
## Fedora CoreOS
**CoreOS** is a Fedora edition built specifically for running containerized workloads securely and at scale. Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime. [^](https://fedoramagazine.org/introducing-fedora-coreos/ "Fedora Magazine: \"Introducing Fedora CoreOS\"")

CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.\
CoreOS automatically installs upgrades automatically without user intervention, although they can be stopped if a problem is found.
## Kali Linux

\#    | Pentesting tools [^](https://itsfoss.com/best-kali-linux-tools/ "ItsFOSS: \"21 Best Kali Linux Tools for Hacking and Penetration Testing\"")
---   | ---
A     | [Aircrack-ng][Aircrack-ng] [Apktool][Apktool] [Autopsy Forensic Browser][AFB]
B     | [BeEF][BeEF] [Burp Suite Scanner][Burp Suite Scanner]
H     | [Hydra][Hydra]
J     | [John the Ripper][John the Ripper]
K     | [King Phisher][King Phisher]
L     | [Lynis][Lynis]
M     | [Maltego][Maltego] [Metasploit][Metasploit Framework]
N     | [Nikto][Nikto]
S     | [SET][SET] [Skipfish][Skipfish] [Snort][Snort] [sqlmap][Sqlmap]
W     | [Wireshark][Wireshark] [WPScan][WPScan]
Y     | [Yersinia][Yersinia]
## Windows Subsystem for Linux
**Windows Subsystem for Linux (WSL)** is shipped with Windows and tied to the Windows release cycle. Windows ships from a single massive codebase, of which WSL is part. WSL was written mostly in C and and has 3 million monthly active users. [<sup>ADP 57</sup>][ADP 57]
#### Concepts
**D** 
[DrvFs][DrvFs] 
**L** 
[LXSS][lxss.sys]
**P** 
[pico drivers][pico driver]
**V** 
[VFS][VFS] 
[VolFs][VolFs]

WSL implements **user services** to connect to WSL distros and to run Windows-native applications like CMD.exe. WSL implements a **9P Protocol** file server to provide seamless integration of the virtualized Linux filesystem and that of the Windows host.

In version 1, WSL worked under a **translation architecture** where system calls were translated to NT kernel calls. This meant that applications that used system calls that were newer or more difficult to implement, like GUI applications or Docker, did not run on v1. But WSL2 shifted to a **lighweight virtualization** model using the Linux kernel. Now Docker runs on WSL2 and GUI applications can run by using an X server.

WSL v1 is available on Azure VMs if **nested virtualization** is enabled. WSL2 support is forthcoming.

## GNOME
Read: "How to type emoji in Linux". [opensource.com](https://opensource.com/article/19/10/how-type-emoji-linux)
### `gconf-editor`
GUI-based configuration editor for GNOME
### `gsettings`
Change function of Caps Lock key [^](https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland 'superuser.com - "How to remap CAPS LOCK on Wayland"')
```sh
gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
```
Change mouse cursor size to `$SIZE`, which can be one of the values 24 (default), 32, 48, 64, or 96. [^](https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/ "vitux.com: \"Change cursor size on Ubuntu through the command line\"")
```sh
gsettings set org.gnome.desktop.interface $SIZE
```
## Mac OS X
### iterm2
iterm2 can be configure as a **Guake**-style dropdown terminal:
[SuperUser.com](https://superuser.com/questions/951393/pin-os-x-terminal-window-always-on-top-in-macos-yosemite)
[Sharma Prakash](https://www.sharmaprakash.com.np/guake-like-dropdown-terminal-in-mac/#assign-hotkey)

### `open`
Open path in Finder
```
open path
```
Open an application from Terminal
```
open -a /Applications/application.app
```
### `screencapture`
Take a screenshot on Mac OS X [[48](sources.md)]

Option  | Effect
:---    | :---
`-c`    | send to clipboard
`-T $SECONDS` | take screenshot after `$SECONDS`
`-t $FORMAT`  | specify file `$FORMAT` (png by default)
`-x`    | take screenshot without shutter sound
## Fedora
Repos added
- RPM Fusion
  - `https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-31.noarch.rpm`
  - `https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-free-release-31.noarch.rpm`

Packages added:
- `snap`
- `breeze-cursor-theme`
- `f30-backgrounds-gnome` .. `f20-backgrounds-gnome`

Keyboard shortcuts:
- M+Enter: `terminal-gnome`
- M+F1, F2... workspaces

Icons: `Qogir`
## KDE
#### Appearance
- __Colors__ affects the appearance of text
- __Workspace Theme__ opens up several dialogs
  - __Look and Feel__ allows selection of Look and Feel Themes that affect window appearance
  - __Plasma theme__ appears to affect the appearance of widgets only
#### Comparison with other OSes
File dialogs have highly configurable views, with icon sizes scalable from 16 to 128 px and filenames available to the side or below the icon.
- A view similar to the Icons view in Mac OS X or the List view in Windows can be reproduced by setting View to the icon size to the minimum 16px and placing the filename to the side (`Icon Position` > `Next to file name`)
#### Wallpapers
Wallpaper types "Haenau" and "Hunyango" are QML (Qt Modeling Language) animated wallpapers that were introduced in Plasma 5.1 (2014)
#### Widgets
"Plasmoids" are dragged and dropped onto the Desktop, where they function as buttons. A long click will allow them to be moved, rotated, or resized. Each plasmoid can be configured with a keyboard shortcut. They occupy all virtual desktops.

One plasmoid in particular is the "Grouping Plasmoid", which allows other plasmoids to be placed within it, where they occupy separate tabs. 
#### Login manager
Workspace > Startup and Shutdown > Login Screen (SDDM)
The advanced tab allows you to select Mouse cursor theme and auto login of user and session type. These appear to affect specifically settings in /etc/sddm.conf (`Session=gnome-xorg` under `[Autologin]`)
#### Default shortcuts
Workspace > Shortcuts > Global Shortcuts
"Run Command" refers to `krunner`, a single-line application launcher similar to the Run command on Windows.
- __Alt-t__ : open a terminal window
#### Restarting KDE Plasma
Source: [Lifewire](https://www.lifewire.com/kubuntu-p2-2202573)

Restarting KDE Plasma 4
```sh
killall plasma-desktop
kstart plasma-desktop
```
Restarting KDE Plasma 5
```sh
killall plasmashell
kstart plasmashell
```
```sh
kquitapp5 plasmashell
kstart plasmashell
```
### `kquitapp`
Allows you to quit a dbus enabled application. Two options:

Specify service to be stopped
```sh
kquitapp --service
```
Specify path to dbus interface 
```sh
kquitapp --path
```