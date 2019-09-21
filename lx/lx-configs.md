# Linux configuration files
Config file                       | Description
:---                              | :---
$HOME/.forward                    | forwarding to only one address
$HOME/.gnupg/pubring.gpg          | default storage for public [gpg](#gpg) keyrings 
$HOME/.ssh/known_hosts            | public keys of SSH hosts
$HOME/xorg.conf                   | user config which overrides system defaults
/boot/grub/grub.cfg               | GRUB2 bootloader
/dev/                             | virtual filesystem containing device files, used to access physical and virtual devices
/etc/aliases                      | systemwide email aliases
[/etc/apt/sources.list](#etcaptsourceslist)             | APT repos <br/>`deb-src` is the prefix used to denote a Debian source repo
/etc/apt/sources.list.d/          | directory containing additional repository definitions
[/etc/cmd.allow](#xinetd-configuration-files)                    | [xinetd](#xinetd)
[/etc/cmd.deny](#xinetd-configuration-files)                     | [xinetd](#xinetd)
[/etc/default/useradd](#etcdefaultuseradd) | [useradd](#useradd)
/etc/files.dns                    | NIS+ servers for Solaris servers
/etc/fstab                        | filesystems to be mounted by the system at boot
/etc/gdm/custom.conf              | GNOME config
/etc/group                        | colon-delimited values for groups<br/>**Format**:<br/>`name:password:GID:user1,user2,user3,...`
/etc/hosts                        | global hostnames
/etc/hotplug/usb                  | location of scripts executed when a hotplug device is inserted
/etc/hostname                     | contains hostname
/etc/init.d/                      | [sysvinit](#sysvinit) scripts run during startup and shutdown
/etc/inittab                      | initialization table
/etc/ld.so.conf.d/                | configs that establish pathnames where shared libraries may be found
/etc/lightdm/                     | directory containing **users.conf**, and the subdirectory **lightdm.conf.d**, if created, the contents of which will be loaded as well
/etc/lightdm/lightdm.conf         | [lightdm](#lightdm) 
/etc/ld.so.conf                   | [ldconfig](#ldconfig) 
/etc/login.defs                   | default configuration values for [useradd](#useradd), [userdel](#userdel), [usermod](#usermod), and [groupadd](#groupadd)
/etc/logrotate.conf               | [logrotate](#logrotate)
[/etc/lsb-release](#etclsb-release)  | Ubuntu version<br/>[lsb_release](#lsb_release)
/etc/lvm/.cache                   | default location of LVM cache
/etc/modprobe.d/                  | [modprobe](#modprobe)
/etc/mtab                         | updated dynamically with information about currently mounted filesystems
/etc/network                      | global network settings
/etc/ntp.conf                     | NTP config
/etc/nsswitch.conf                | controls lookup system beyond just DNS
/etc/passwd                       |
/etc/postfix/main.cf              | [postfix](#postfix)
/etc/rc.d/rc.sysinit              | first script run by init
/etc/resolv.conf                  | nameserver definitions (maximum of 6 domains with total of 256 characters)
[/etc/samba/smb.conf](#etcsambasmbconf)| Samba configuration file
/etc/selinux/config               | [SELinux](#selinux)
/etc/services                     | used to resolve port numbers
/etc/skel/                        | default configs for new users
/etc/ssh/ssh_config               | client config for ssh
/etc/ssh/sshd_config              | server configuration file for ssh
[/etc/ssmtp/ssmtp.conf](#etcssmtpssmtpconf)    | [ssmtp](#ssmtp)
/etc/sudoers                      | who has sudo access
[/etc/sysconfig/desktop](#etcsysconfigdesktop) | Specify display manager and desktops on Red Hat
/etc/sysconfig/iptables           | [iptables](#iptables)
/etc/sysconfig/network-scripts/   | directory containing network configs and scripts for Red Hat
/etc/syslog-ng/syslog-ng.conf     | [syslog-ng](#syslog-ng)
/etc/udev/hwdb.bin                | udev hardware database
/etc/X11/xdm/xdm-config           | XFCE config
[/etc/xinet.d/](#xinetd-configuration-files)                     | directory of config files for [xinetd](#xinetd)
[/etc/xinetd.conf](#xinetd-configuration-files)                  | master [xinetd](#xinetd) configuration
/etc/yum.repos.d/                 | repository definitions with filenames that follow the pattern **\*.repo**
[/etc/yum.conf](#etcyumconf)      | [yum](#yum)
/lib/systemd/system/              | directory containing unit configs
/proc/                            | virtual filesystem providing information on processes, kernel features, and system hardware
/proc/loadavg                     | virtual file that has information about load average for use in [`uptime`](#uptime)
/var/log/dmesg                    | kernel ring buffer information
/var/log/audit/audit.log          | audit file for SELinux
/sys/                             | virtual filesystem that provides information on devices and buses that the kernel is aware of
/sys/block                        | block devices
/sys/bus                          | devices attached to system bus
/sys/bus/cpu                      | CPUs
/sys/bus/cpu/devices              | USB devices
/sys/class/net                    | network interface configuration files (or at least symlinks to them in other directories) in Manjaro<br/>similar to /etc/sysconfig/network-scripts/ in RHEL 
/sys/class/net/eth0/address       | MAC address of eth0
/usr/share/config/kdm/kdmrc       | KDM config
/usr/share/lightdm/lightdm.conf.d/ | [lightdm](#lightdm) configs, all of whose filenames follow the pattern **50-\*.conf**
/usr/share/hwdata/pci.ids         | PCI device names displayed by [`lspci`](#lspci)
/usr/share/hwdata/pci.ids.gz      | PCI device names displayed by [`lspci`](#lspci)
### /etc/default/useradd
Default values for account creation. Properties: `EXPIRE`, `GROUP`, `HOME`, `INACTIVE`, `SHELL`, `SKEL`

### /etc/apt/sources.list
Repos used in [`apt`](#apt) package manager are listed in files with the URL preceded by `deb` (`deb-src` used to be used).
```cfg
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic main restricted
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic-updates main restricted
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic universe
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic-updates universe
```
#### MongoDB repo
```cfg
deb [ arch=amd64 ] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.2 multiverse 
```
#### gcloud
```cfg
deb [signed-by=/usr/share/keyrings/cloud.google.gpg] http://packages.cloud.google.com/apt cloud-sdk main
```
### /etc/lsb-release
```conf
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=14.04
DISTRIB_CODENAME=trusty
DISTRIB_DESCRIPTION="Ubuntu 14.04.6 LTS"
```
### /etc/samba/smb.conf
```conf
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
[[40](#sources)]
#### Configure anonymous unsecured file sharing on a shared directory
```conf
[global]
workgroup = WORKGROUP
netbios name = rhel
security = user
...
[Anonymous]
comment = Anonymous File Server Share
path = /srv/samba/anonymous
browsable =yes
writable = yes
guest ok = yes
read only = no
force user = nobody
```
[[41](#sources)]
### /etc/sysconfig/desktop
Specify desktop environment and display manager on Red Hat.
```conf
DESKTOP="KDE"
DISPLAYMANAGER="KDE"
```
```conf
DESKTOP="XFCE"
DISPLAYMANAGER="XDM"
```
```conf
DESKTOP="Gnome"
DISPLAYMANAGER="GDM"
```
### /etc/ssmtp/ssmtp.conf
```ini
mailhub=smtp.gmail.com:587
UseTLS=YES
UseSTARTTLS=YES
```
### /etc/yum.conf
#### Exclude packages from updates permanently
[[38](#sources)]
```ini
[main]
exclude=kernel* php*
```