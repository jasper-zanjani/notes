# Linux configuration files
Config file                                                 | Description
:---                                                        | :---
.forward                                                    | forwarding to only one address
.gnupg/pubring.gpg                                          | default storage for public [gpg](#gpg) keyrings 
.ssh/known_hosts                                            | public keys of SSH hosts
.mailrc                                                     | 
xorg.conf                                                   | user config which overrides system defaults
/boot/grub/grub.cfg                                         | GRUB2 bootloader
/dev/                                                       | virtual filesystem containing device files, used to access physical and virtual devices
/etc/aliases                                                | systemwide email aliases
/etc/anacrontab
[/etc/apt/sources.list](#etcaptsourceslist)                 | APT repos <br/>`deb-src` is the prefix used to denote a Debian source repo
/etc/apt/sources.list.d/                                    | directory containing additional repository definitions
[/etc/cmd.allow](#xinetd-configuration-files)               | [xinetd](commands.md#xinetd)
[/etc/cmd.deny](#xinetd-configuration-files)                | [xinetd](commands.md#xinetd)
[/etc/cron.allow](#crontab)                                 | [`crontab`](commands.md#crontab)
[/etc/cron.deny](#crontab)                                  | [`crontab`](commands.md#crontab)
[/etc/cron.d/](#crontab)                                    | [`crontab`](commands.md#crontab)
[/etc/cron.daily](#crontab)                                 | [`crontab`](commands.md#crontab)
[/etc/cron.hourly](#crontab)                                | [`crontab`](commands.md#crontab)
[/etc/cron.weekly](#crontab)                                | [`crontab`](commands.md#crontab)
[/etc/cron.monthly](#crontab)                               | [`crontab`](commands.md#crontab)
[/etc/crontab](#crontab)                                    | [`crontab`](commands.md#crontab)
[/etc/default/useradd](#etcdefaultuseradd)                  | [useradd](commands.md#useradd)
/etc/files.dns                                              | NIS+ servers for Solaris servers
/etc/fstab                                                  | filesystems to be mounted by the system at boot
/etc/gdm/custom.conf                                        | GNOME config
/etc/group                                                  | colon-delimited values for groups<br/>**Format**:<br/>`name:password:GID:user1,user2,user3,...`
/etc/hosts                                                  | global hostnames
/etc/hotplug/usb                                            | location of scripts executed when a hotplug device is inserted
/etc/hostname                                               | contains hostname
/etc/init.d/                                                | [sysvinit](#sysvinit) scripts run during startup and shutdown
/etc/inittab                                                | initialization table
/etc/ld.so.conf.d/                                          | configs that establish pathnames where shared libraries may be found
/etc/lightdm/                                               | directory containing **users.conf**, and the subdirectory **lightdm.conf.d**, if created, the contents of which will be loaded as well
/etc/lightdm/lightdm.conf                                   | [lightdm](#lightdm) 
/etc/ld.so.conf                                             | [ldconfig](commands.md#ldconfig) 
/etc/login.defs                                             | default configuration values for [useradd](#useradd), [userdel](#userdel), [usermod](#usermod), and [groupadd](#groupadd)
/etc/logrotate.conf                                         | [logrotate](commands.md#logrotate)
[/etc/lsb-release](#etclsb-release)                         | Ubuntu version<br/>[lsb_release](#lsb_release)
/etc/lvm/.cache                                             | default location of LVM cache
/etc/modprobe.d/                                            | [modprobe](commands.md#modprobe)
/etc/mtab                                                   | updated dynamically with information about currently mounted filesystems
/etc/network                                                | global network settings
/etc/ntp.conf                                               | NTP config
/etc/nsswitch.conf                                          | controls lookup system beyond just DNS
/etc/passwd                                                 |
/etc/postfix/main.cf                                        | [`postfix`](commands.md#postfix)
/etc/rc.d/rc.sysinit                                        | first script run by init
/etc/resolv.conf                                            | nameserver definitions (maximum of 6 domains with total of 256 characters)
[/etc/samba/smb.conf](#etcsambasmbconf)                     | Samba configuration file
/etc/selinux/config                                         | [SELinux](#selinux)
/etc/services                                               | used to resolve port numbers
/etc/skel/                                                  | default configs for new users
/etc/ssh/ssh_config                                         | client config for ssh
/etc/ssh/sshd_config                                        | server configuration file for ssh
[/etc/ssmtp/ssmtp.conf](#etcssmtpssmtpconf)                 | [`ssmtp`](commands.md#ssmtp)
[/etc/sudoers](#etcsudoers)                                 | who has sudo access
[/etc/sysconfig/desktop](#etcsysconfigdesktop)              | Specify display manager and desktops on Red Hat
/etc/sysconfig/iptables                                     | [iptables](#iptables)
/etc/sysconfig/network-scripts/                             | directory containing network configs and scripts for Red Hat
/etc/syslog-ng/syslog-ng.conf                               | [syslog-ng](#syslog-ng)
/etc/systemd/system/                                        | [ SystemD service files ](#systemd-service-files), containing links to /usr/local
/etc/udev/hwdb.bin                                          | udev hardware database
/etc/X11/xdm/xdm-config                                     | XFCE config
[/etc/xinet.d/](#xinetd-configuration-files)                | directory of config files for [xinetd](commands.md#xinetd)
[/etc/xinetd.conf](#xinetd-configuration-files)             | master [xinetd](commands.md#xinetd) configuration
/etc/yum.repos.d/                                           | repository definitions with filenames that follow the pattern **\*.repo**
[/etc/yum.conf](#etcyumconf)                                | [yum](##### yum)
/lib/systemd/system/                                        | directory containing unit configs
/proc/                                                      | virtual filesystem providing information on processes, kernel features, and system hardware
/proc/loadavg                                               | virtual file that has information about load average for use in [`uptime`](#uptime)
/sys/                                                       | virtual filesystem that provides information on devices and buses that the kernel is aware of
/sys/block                                                  | block devices
/sys/bus                                                    | devices attached to system bus
/sys/bus/cpu                                                | CPUs
/sys/bus/cpu/devices                                        | USB devices
/sys/class/net                                              | network interface configuration files (or at least symlinks to them in other directories) in Manjaro<br/>similar to /etc/sysconfig/network-scripts/ in RHEL 
/sys/class/net/eth0/address                                 | MAC address of eth0
/usr/local/lib/systemd/system/                              | [SystemD service files](#systemd-service-files)
/usr/share/config/kdm/kdmrc                                 | KDM config
/usr/share/lightdm/lightdm.conf.d/                          | [lightdm](#lightdm) configs, all of whose filenames follow the pattern **50-\*.conf**
/usr/share/hwdata/pci.ids                                   | PCI device names displayed by [`lspci`](#lspci)
/usr/share/hwdata/pci.ids.gz                                | PCI device names displayed by [`lspci`](#lspci)
/var/log/dmesg                                              | kernel ring buffer information
/var/log/audit/audit.log                                    | audit file for SELinux
/var/spool/cron/                                            | contains user crontables

### SystemD service files
[[45](README.md#sources)]
```ini
[Unit]
Description=Runs /usr/local/bin/mystartup.sh

[Service]
ExecStart=/usr/local/bin/mystartup.sh

[Install]
WantedBy=multi-user.target
```

### .mailrc
```cfg
set sendmail="/usr/bin/msmtp"
set message-sendmail-extra-arguments="-a gmail"
```

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
MongoDB repo
```cfg
deb [ arch=amd64 ] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.2 multiverse 
```
Gcloud
```cfg
deb [signed-by=/usr/share/keyrings/cloud.google.gpg] http://packages.cloud.google.com/apt cloud-sdk main
```
"Trusty-security" repository containing [`mailx`](commands.md#mailx)
```cfg
deb http://security.ubuntu.com/ubuntu trusty-security main universe
```

### /etc/lsb-release
```conf
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=14.04
DISTRIB_CODENAME=trusty
DISTRIB_DESCRIPTION="Ubuntu 14.04.6 LTS"
```

### /etc/samba/smb.conf
[[40](#sources)]
```conf
[samba-share]
comment = Samba on Ubuntu
path = /samba
read only = no
browsable = yes
```
Configure anonymous unsecured file sharing on a shared directory [[41](#sources)]
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
Exclude packages from updates permanently
[[38](#sources)]
```ini
[main]
exclude=kernel* php*
```

### /etc/sudoers
Syntax  | Effect
:---    | :---
`linuxize ALL=/bin/mkdir`                 | allow sudo access to user `linuxize` only for command /bin/mkdir
`linuxize ALL=(ALL) NOPASSWD: ALL`        | allow user `linuxize` to run `sudo` commands without authenticating himself
`Defaults timestamp_timeout=10`           | change timeout to 10 minutes
`Defaults:linuxize timestamp_timeout=10`  | change timeout to 10 minutes only for user <linuxize>


### crontab
Directive | Effect
:--- | :---
`@hourly`|  equivalent to `0 * * * *`
`@midnight`, `@daily` | equivalent to `0 0 * * *`
`@weekly`|  equivalent to `0 0 * * 0`
`@monthly`|  equivalent to `0 0 1 * *`
`@annually`,  `@yearly`| equivalent to `0 0 1 1 *`
`@reboot`|  run at startup

Run /root/backup.sh at 0300 everyday
```sh
0 3 * * * /root/backup.sh
```
Run /path/to/script.sh at 16:30 on the 2nd of every month
```sh
30 16 2 * * /path/to/script.sh
```
Run /scripts/phpscript.php at 22:00 every weekday
```sh
0 22 * * 1-5 /scripts/phpscript.php
```
Run /path/to/perlscript.pl at 00:23, 02:23, and 04:23 everyday
```sh
23 0-23/2 * * * /path/to/perlscript.pl
```
Run `linuxcommand` at 04:05 every Sunday
```sh
5 4 * * sun /path/to/linuxcommand
```

Config files

