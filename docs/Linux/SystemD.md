# SystemD

**SystemD** is the de facto Linux init system since it has replaced the earlier **Sysvinit** in almost all Linux distributions of note a few years ago. 

In SysVinit, processes started serially and synchronously, wasting time and system resources.
For years, a common hack was to run services in the background, simulating concurrency.

**Upstart** was another init system developed by Canonical for Ubuntu meant to replace SysVinit, but it was abandoned in 2014. 

It was designed by a pair of Red Hat developers in 2010 to be a general purpose system manager.
It offers parallel execution, explicit dependencies between services, an escape from slow shell scripts, and per-daemon resource control and watchdogs.

SystemD organizes resources into **units**, which can be managed by daemons and manipulated by SystemD utilities.
Unit files are case-sensitive .ini files organized into sections.
Unit files can be found in several directories:

- **/lib/systemd/system** where the system's copy of unit files are placed by default
- **/etc/systemd/system** where unit files override the system default
- **/run/systemd/system** where run-time unit definitions are found and given a higher priority than the system default in /lib but lower than that in /etc. These unit files are created dynamically and lost on reboot.

Unit files come in many different types which can be identified by their filename extension (i.e. **.service**, **target**, etc.).

The first section found in most unit files is the **[Unit]** section, which may contain the following directives:

- **Description**

**Service files** are a type of unit file which have replaced earlier init scripts and describe how to manage a service or application on the server.

Create a service file [<sup>:material-redhat:</sup>](https://www.redhat.com/sysadmin/replacing-rclocal-systemd)
```ini
[Unit]
Description=Runs /usr/local/bin/mystartup.sh

[Service]
ExecStart=/usr/local/bin/mystartup.sh

[Install]
WantedBy=multi-user.target
```

**Target files** are equivalent to SysVInit runlevels.

| Target            | Runlevel  |
| ----------------- | --------- |
| poweroff.target   | 0         |
| rescue.target     | 1         |
| multi-user.target | 3         |
| graphical.target  | 5         |
| reboot.target     | 6         |
| emergency.target  | emergency |


--8<-- "includes/Linux/systemctl.md"

#### Others

- [hostnamectl][hostnamectl]
- [journalctl][journalctl]
- [localectl][localectl]
- [loginctl][loginctl]
- [systemd-delta][systemd-delta]
- [timedatectl][timedatectl]