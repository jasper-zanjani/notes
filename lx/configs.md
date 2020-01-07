# Linux configuration files
Home subdirectory           | Config files sorted alphabetically
---                         | ---
.                           | [.forward][.forward] [.mailrc](#mailrc) mtab [xorg.conf][xorg.conf]
.gnupg/                     | [pubring.gpg][.gnupg/pubring.gpg]
.ssh/                       | [known_hosts][.ssh/known_hosts] 
[.vim/colors/]              |

/#  | /etc config files sorted alphabetically
--- | ---
A   | [aliases][/etc/aliases] anacrontab
C   | [cmd.allow](commands/README.md#xinetd) [cmd.deny](commands/README.md#xinetd)
[`cron`](commands/README.md#crontab) | cron.allow cron.deny cron.daily cron.hourly cron.weekly cron.monthly crontab **cron.d/**
F   | [files.dns][/etc/files.dns] [fstab][/etc/fstab]
G   | [group][/etc/group]
H   | [hostname][/etc/hostname] [hosts][/etc/hosts]
I   | [inittab][/etc/inittab]
L   | ld.so.conf [login.defs][/etc/login.defs] [logrotate.conf][/etc/logrotate.conf] [lsb-release][/etc/lsb-release]
M   | [mtab][/etc/mtab]
N   | [network][/etc/network] [nsswitch.conf][/etc/nsswitch.conf] ntp.conf
P   | passwd
R   | [resolv.conf][/etc/resolv.conf]
S   | [services][/etc/services] [shadow][/etc/shadow] [sudoers](#etcsudoers)
X   | [xinetd.conf][/etc/xinetd.conf]
Y   | [yum.conf][/etc/yum.conf]

/etc subdirectory                             | Config files sorted alphabetically
---                                           | ---
apt/                                          | [sources.list][/etc/apt/sources.list] [**sources.list.d/**][/etc/apt/sources.list.d/]
default/                                      | [useradd][/etc/default/useradd]
[hotplug/usb/][/etc/hotplug/usb/]             |
[init.d/][/etc/init.d/]                       |
[ld.so.conf.d/][/etc/ld.so.conf.d/]           |
lightdm/                                      | lightdm.conf users.conf
lightdm.conf.d/                               | 
lvm                                           | [.cache][/etc/lvm/.cache]
mail/                                         | [sendmail.mc][/etc/mail/sendmail.mc] [sendmail.cf][/etc/mail/sendmail.cf]
modprobe.d/                                   | 
postfix/                                      | [main.cf]
rc.d/                                         | [rc.sysinit][/etc/rc.d/rc.sysinit]
samba/                                        | [smb.conf][/etc/samba/smb.conf]
selinux/                                      | config
[skel/][/etc/skel/]                           | 
sources.list.d/                               | 
ssh/                                          | ssh_config sshd_config
ssmtp/                                        | [ssmtp.conf][/etc/ssmtp/ssmtp.conf]
sysconfig/                                    | [desktop][/etc/sysconfig/desktop] iptables **network-scripts/**
syslog-ng/                                    | [syslog-ng.conf][/etc/syslog-ng/syslog-ng.conf]
[systemd/system/][/etc/systemd/system/]       |
udev/                                         | [hwdb.bin][/etc/udev/hwdb.bin]
X11/                                          | **xdm/**&zwnj;xdm-config 
[xinet.d/][/etc/xinetd/]                      | 
[yum.repos.d/][/etc/yum.repos.d/]             | 

Other directories                             | Config filenames sorted alphabetically
---                                           | ---
/boot/grub/                                   | [grub.cfg][/boot/grub/grub.cfg]
[/lib/systemd/system/][/lib/systemd/system/]  | 
/var/log/                                     | [**audit/**&zwnj;audit.log][/var/log/audit/audit.log] [dmesg][/var/log/dmesg]
[/var/spool/cron/][/var/spool/cron/]           | 
[/usr/local/lib/systemd/system/](#systemd-service-files) | 
/usr/share/config/kdm/                        | [kdmrc][/usr/share/config/kdm/kdmrc]
[/usr/share/lightdm/lightdm.conf.d/][/usr/share/lightdm/lightdm.conf.d/] | 
/usr/share/hwdata/                            | [pci.ids][/usr/share/hwdata/pci.ids] [pci.ids.gz][/usr/share/hwdata/pci.ids]

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

### /etc/postfix/main.cf
[Postfix](commands/mail.md#postfix) config 

Set e-mail domain name [^][Eckert]
```cfg
mydomain = sample.com
```
Set local access to domain name [^][Eckert]
```cfg
myorigin = $mydomain
```
Configure postfix to listen for email on all interfaces [^][Eckert]
```cfg
inet_interfaces = all
```
Configure destination domain for email [^][Eckert]
```cfg
mydestination = $myhostname, localhost.$mydomain, localhost, $mydomain
```
Trust email from computers on the local network [^][Eckert]
```cfg
mynetworks_style = class
```
---

[.forward]: # "Forwarding to only one address"
[.gnupg/pubring.gpg]: # "Default storage for public `gpg` keyrings"
[.ssh/known_hosts]: # "Public keys of SSH hosts"
[xorg.conf]: # "User config which overrides system defaults"
[.vim/colors/]: ../text/vim.md "Contains custom color schemes for vim"

[/dev]: # "Virtual filesystem containing device files, used to access physical and virtual devices"
[/etc/aliases]: # "Systemwide email aliases"
[/etc/apt/sources.list]: #etcaptsourceslist
[/etc/apt/sources.list.d/]: # "Directory containing additional repository definitions"
[/etc/default/useradd]: #etcdefaultuseradd
[/etc/files.dns]: # "NIS+ servers for Solaris servers"
[/etc/fstab]: # "Filesystems to be mounted by the system at boot"
[/etc/group]: #etcgroup "Colon-delimited file describing group membership"
[/etc/hostname]: # "contains hostname"
[/etc/hosts]: # "Global hostnames"
[/etc/hotplug/usb/]: # "Location of scripts executed when a hotplug device is inserted"
[/etc/init.d/]: # "sysvinit scripts run during startup and shutdown"
[/etc/inittab]: # "initialization table"
[/etc/ld.so.conf.d/]: # "Configs that establish pathnames where shared libraries may be found"
[/etc/login.defs]: # "Default configuration values for useradd, userdel, usermod, and groupadd"
[/etc/logrotate.conf]: commands/README.md#logrotate
[/etc/lsb-release]: #lsb-release "Ubuntu version"
[/etc/lvm/.cache]: # "Default location of LVM cache"
[/etc/mail/sendmail.mc]: # "Sendmail config which is compiled to sendmail.cf"
[/etc/mail/sendmail.cf]: # "Sendmail config which is compiled from sendmail.mc"
[/etc/mtab]: # "Updated dynamically with information about currently mounted filesystems"
[/etc/network]: # "Global network settings"
[/etc/nsswitch.conf]: # "Controls lookup system beyond just DNS"
[/etc/postfix/main.cf]: #etcpostfixmaincf "Postfix config"
[/etc/rc.d/rc.sysinit]: # "First script run by init"
[/etc/resolv.conf]: # "Nameserver definitions (maximum of 6 domains with total of 256 characters)"
[/etc/samba/smb.conf]: # "Samba configuration file"
[/etc/services]: # "Used to resolve port numbers"
[/etc/shadow]: #etcshadow "Colon-delimited file containing password hashes for every user listed in /etc/passwd"
[/etc/skel/]: # "Default configs for new users"
[/etc/ssmtp/ssmtp.conf]: #etcssmtpssmtpconf
[/etc/sysconfig/desktop]: #etcsysconfigdesktop "Specify display manager and desktops on Red Hat"
[/etc/syslog-ng/syslog-ng.conf]: #syslog-ng
[/etc/systemd/system/]: #systemd-service-files "systemd service files"
[/etc/udev/hwdb.bin]: # "udev hardware database"
[/etc/xinetd/]: commands/README.md#xinetd
[/etc/xinetd.conf]: commands/README.md#xinetd "Master xinetd configuration file"
[/etc/yum.conf]: #etcyumconf
[/etc/yum.repos.d/]: # "Repository definitions with filenames that follow the pattern \"*.repo\""

[/lib/systemd/system/]: # "directory containing unit configs"
[/usr/share/config/kdm/kdmrc]: # "KDM config"
[/usr/share/lightdm/lightdm.conf.d/]: # "lightdm configs, whose filenames follow the pattern \"50-*.conf\""
[/usr/share/hwdata/pci.ids]: commands/README.md#lspci "PCI device names displayed by lspci"
[/var/log/dmesg]: # "Kernel ring buffer information"
[/var/log/audit/audit.log]: # "Audit file for SELinux, SSH"
[/var/spool/cron/]: # "Contains user crontables"
[/boot/grub/grub.cfg]: # "GRUB config file"

---

[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."