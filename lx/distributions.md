# Linux distributions
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
Linux distribution backed by Intel, which also backed 4 similar Linux distros in the past 
## Fedora CoreOS
**CoreOS** is a Fedora edition built specifically for running containerized workloads securely and at scale. Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime.\
CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.\
CoreOS automatically installs upgrades automatically without user intervention, although they can be stopped if a problem is found.
## Kali Linux

Pentesting tool     | Description
:---                | :---
[nmap](commands/README.md#nmap) | 
Lynis               | security auditing, compliance testing
WPScan              | WordPress security auditing tool
Aircrack-ng         | monitor and compromise WiFi networks
Hydra               | crack login/password pairs
Wireshark           | network analyzer
Metasploit Framework| penetration testing framework
Skipfish            | web application scanner
Maltego             | data mining
Nessus              | paid tool to find vulnerabilities
Burp Suite Scanner  | GUI-based web application security scanner
BeEF                | assess security of a web browser
Apktool             | reverse engineer Android apps
sqlmap              | exploit SQL injection flaws
John the Ripper     | crack passwords
Snort               | traffic analysis and packet logging
Autopsy Forensic Browser | digital forensics
King Phisher        | simulate phishing attacks
Nikto               | web server scanner
Yersinia            | Perform Layer 2 attacks
Social Engineering Toolkit (SET) |

## Windows Subsystem for Linux
**Windows Subsystem for Linux (WSL)** is shipped with Windows and tied to the Windows release cycle. Windows ships from a single massive codebase, of which WSL is part. WSL was written mostly in C and and has 3 million monthly active users.[[4](#sources)]\
WSL implements **user services** to connect to WSL distros and to run Windows-native applications like CMD.exe. WSL implements a **9P Protocol** file server to provide seamless integration of the virtualized Linux filesystem and that of the Windows host.[[4](#sources)]\
In version 1, WSL worked under a **translation architecture** where system calls were translated to NT kernel calls. This meant that applications that used system calls that were newer or more difficult to implement, like GUI applications or Docker, did not run on v1. But WSL2 shifted to a **lighweight virtualization** model using the Linux kernel. Now Docker runs on WSL2 and GUI applications can run by using an X server.[[4](#sources)]\
WSL v1 is available on Azure VMs if **nested virtualization** is enabled. WSL2 support is forthcoming.[[4](#sources)]

## Sources
1. Clear Linux segment. [Linux Unplugged](../sources/README.md#lu-289)
2. "Introducing Fedora CoreOS". [Fedora Magazine](https://fedoramagazine.org/introducing-fedora-coreos/): 2019/07/24.
3. "21 Best Kali Linux Tools for Hacking and Penetration Testing". [ItsFOSS](https://itsfoss.com/best-kali-linux-tools/)
4. "Craig Loewen on the Windows Subsystem for Linux story". [ADP 57](../sources/README.md#adp-57): 2019/10/07.