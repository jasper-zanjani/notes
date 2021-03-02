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