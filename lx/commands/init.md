## Sysvinit
- **SystemVinit** is a daemon process which was used by most distros until recently. Processes started serially and synchronously, wasting system resources; for years, a common hack was to run services in the background, simulating a sort of parallel processing
- **Upstart** was developed by Canonical for Ubuntu, but abandoned in 2014. 
- [**Systemd**][SystemD] which starts processes in parallel has become de facto standard for all major Linux distributions

\#  | Commands sorted alphabetically
:---| :---
C   | `chkconfig`
I   | `init` `initctl`
R   | `runlevel`
S   | `service`
T   | `telinit`

### `chkconfig`
Turn services on or off for runlevels
Without arguments, `chkconfig` defaults to runlevels 3 or 5:
```sh
chkconfig
```
Display all services and runlevels
```sh
chkconfig --list
```
Turn {daemon} on for runlevels 3 and 5
```sh
chkconfig --level 35 daemon on
```
Turn {daemon} off
```sh
chkconfig daemon off
chkconfig NetworkManager off
```
Turn {daemon} service on
```sh
chkconfig daemon on
```

### `init`
Access different runlevels
```sh
init 
```
Switch to runlevel {n}
```sh
init n
init 6 # reboot
```

### `runlevel`
Show runlevel for system
```sh
runlevel 
```

### `service`
Restart network service 
```sh
service network restart
```
Check status of {daemon}
```sh
service daemon status
```
Stop {daemon}
```sh
service daemon stop
service mongodb stop
```

### `telinit`
Refresh system after changes to `/etc/inittab`
```sh
telinit 
```
Cause operation to not send any notice to logged-on users
```sh
telinit--no-wall
```


## Upstart
### `initctl`
Reload configuration files (on Upstart-controlled system)
```sh
initctl reload
```

[SystemD]: systemd.md "De facto standard init system for all major Linux distributions today"