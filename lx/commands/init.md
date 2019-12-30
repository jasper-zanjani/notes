
## Sysvinit
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