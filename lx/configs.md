# Linux configuration files
Directory                   | Config files
---                         | ---
~                           | [.forward][.forward] [.mailrc](#mailrc)  mtab [xorg.conf][xorg.conf] 
~/.gnupg                    | [pubring.gpg][.gnupg/pubring.gpg] 
~/.ssh                      | [known_hosts][.ssh/known_hosts]
/etc                        | [aliases][/etc/aliases] anacrontab [cmd.allow](README.md#xinetd) [cmd.deny](README.md#xinetd) [files.dns](# "NIS+ servers for Solaris servers") [fstab][/etc/fstab] [group][/etc/group] [hostname][/etc/hostname] [hosts][/etc/hosts] ld.so.conf [**ld.so.conf.d**](# "Configs that establish pathnames where shared libraries may be found") [login.defs](# "Default configuration values for useradd, userdel, usermod, and groupadd") logrotate.conf [lsb-release](#etclsb-release) [mtab][/etc/mtab] [network][/etc/network] ntp.conf [nsswitch.conf](# "Controls lookup system beyond just DNS") passwd [resolv.conf][/etc/resolv.conf] [services](# "Used to resolve port numbers") [shadow][/etc/shadow] [sudoers](#etcsudoers) [yum.conf](#etcyumconf) <br> **modprobe.d/** [**skel/**][/etc/skel/] **sources.list.d** **yum.repos.d**
/etc/apt                    | [sources.list](#etcaptsourceslist) [**sources.list.d/**](# "Directory containing additional repository definitions")
/etc/default                | [useradd](#etcdefaultuseradd)
/etc/lightdm/               | lightdm.conf users.conf **lightdm.conf.d**
/etc/postfix/               | main.cf
/etc/samba                  | [smb.conf][/etc/samba/smb.conf]
/etc/selinux                | config
/etc/ssh/                   | ssh_config sshd_config
/etc/ssmtp/                 | [ssmtp.conf](#etcssmtpssmtpconf)
/etc/sysconfig              | [desktop](#etcsysconfigdesktop "Specify display manager and desktops on Red Hat") iptables **network-scripts**
/etc/systemd/               | [**system/**](#systemd-service-files "systemd service files")
/etc/X11/                   | **xdm/**&zwnj;xdm-config 

#### Contents
[/etc/cron.allow](#crontab)                                 | [`crontab`](commands.md#crontab)
[/etc/cron.deny](#crontab)                                  | [`crontab`](commands.md#crontab)
[/etc/cron.d/](#crontab)                                    | [`crontab`](commands.md#crontab)
[/etc/cron.daily](#crontab)                                 | [`crontab`](commands.md#crontab)
[/etc/cron.hourly](#crontab)                                | [`crontab`](commands.md#crontab)
[/etc/cron.weekly](#crontab)                                | [`crontab`](commands.md#crontab)
[/etc/cron.monthly](#crontab)                               | [`crontab`](commands.md#crontab)
[/etc/crontab](#crontab)                                    | [`crontab`](commands.md#crontab)
[/etc/default/useradd](#etcdefaultuseradd)                  | [useradd](commands.md#useradd)
/etc/hotplug/usb                                            | location of scripts executed when a hotplug device is inserted
/etc/init.d/                                                | [sysvinit](#sysvinit) scripts run during startup and shutdown
/etc/inittab                                                | initialization table
/etc/login.defs                                             | default configuration values for [useradd](#useradd), [userdel](#userdel), [usermod](#usermod), and [groupadd](#groupadd)
/etc/logrotate.conf                                         | [logrotate](commands.md#logrotate)
[/etc/lsb-release](#etclsb-release)                         | Ubuntu version<br/>[lsb_release](#lsb_release)
/etc/lvm/.cache                                             | default location of LVM cache
/etc/rc.d/rc.sysinit                                        | first script run by init
/etc/syslog-ng/syslog-ng.conf                               | [syslog-ng](#syslog-ng)
/etc/udev/hwdb.bin                                          | udev hardware database
[/etc/xinet.d/](#xinetd-configuration-files)                | directory of config files for [xinetd](commands.md#xinetd)
[/etc/xinetd.conf](#xinetd-configuration-files)             | master [xinetd](commands.md#xinetd) configuration
/etc/yum.repos.d/                                           | repository definitions with filenames that follow the pattern **\*.repo**


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
/boot/grub/grub.cfg                                         | GRUB2 bootloader

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
Directive             | Effect
---                   | ---
`@hourly`             | equivalent to `0 * * * *`
`@midnight` `@daily`  | equivalent to `0 0 * * *`
`@weekly`             | equivalent to `0 0 * * 0`
`@monthly`            | equivalent to `0 0 1 * *`
`@annually` `@yearly` | equivalent to `0 0 1 1 *`
`@reboot`             | run at startup

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

### /etc/shadow
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

### /etc/group
Colon-delimited file describing group membership
```
$GROUP:$PASSWORD:$GID:$USER1:$USER2:$USER3...
```

### /etc/resolv.conf
Use DNS queries prior to consulting /etc/hosts
```sh
nameserver dns
nameserver files
```

---

[.forward]: # "Forwarding to only one address"
[xorg.conf]: # "User config which overrides system defaults"
[/dev]: # "Virtual filesystem containing device files, used to access physical and virtual devices"
[/etc/aliases]: # "Systemwide email aliases"
[/etc/fstab]: # "Filesystems to be mounted by the system at boot"
[/etc/group]: #etcgroup "Colon-delimited file describing group membership"
[/etc/hostname]: # "contains hostname"
[/etc/hosts]: # "Global hostnames"
[/etc/mtab]: # "Updated dynamically with information about currently mounted filesystems"
[/etc/network]: # "Global network settings"
[/etc/resolv.conf]: # "Nameserver definitions (maximum of 6 domains with total of 256 characters)"
[/etc/samba/smb.conf]: # "Samba configuration file"
[/etc/shadow]: #etcshadow "Colon-delimited file containing password hashes for every user listed in /etc/passwd"
[/etc/skel/]: # "Default configs for new users"
[.gnupg/pubring.gpg]: # "Default storage for public `gpg` keyrings"
[.ssh/known_hosts]: # "Public keys of SSH hosts"