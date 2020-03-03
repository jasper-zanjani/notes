
## Init systems
[SystemD]: systemd.md "De facto standard init system for all major Linux distributions today"

[`hostnamectl`][hostnamectl]
[`journalctl`][journalctl]
[`localectl`][localectl] 
[`loginctl`][loginctl]
[`systemctl`][systemctl] 
[`systemd-delta`][systemd-delta]
[`timedatectl`][timedatectl]

### `hostnamectl`
Permanently change hostname to `$HOSTNAME`
```sh
hostnamectl set-hostname $HOSTNAME
```
### `journalctl`
Show current disk usage of all journal files
```sh
journalctl --disk-usage
```
Continuously update the display as new log entries are created
```sh
journalctl -f
```
Display output in reverse (newest entries first)
```sh
journalctl -r
```
### `localectl`
Change locale to French
```sh
localectl set-locale LANG=fr_FR.utf8
```
### `loginctl`
Control the systemd login manager
### `systemctl`
Disable `$SERVICE`, ensuring it does not run on boot
```sh
systemctl disable service
systemctl disable NetworkManager.service
```
Make `$SERVICE` run on boot 
```sh
systemctl enable $SERVICE
```
Configure iptables to start on boot and start it immediately
```sh
systemctl enable --now iptables
```
Display default target (on a systemd-controlled system)
```sh
systemctl get-default 
```
Change signal type sent to process to be killed
```sh
systemctl kill -s
```
Equivalent to chkconfig --list
```sh
systemctl list-unit-files --type=service
```
List available service units
```sh
systemctl list-units
```
Prevent firewalld from being started inadvertently by another process
```sh
systemctl mask firewalld
```
Reboot the system
```sh
systemctl reboot
```
Restart `$SERVICE`
```sh
systemctl restart $SERVICE
systemctl restart iptables
systemctl restart network.service
```
Configure system to boot to a GUI
```sh
systemctl set-default graphical.target
```
Start `$SERVICE`
```sh
systemctl start $SERVICE
```
Check status of `$SERVICE`
```sh
systemctl status $SERVICE
sudo systemctl is-active $SERVICE
```
Terminate `$SERVICE`
```sh
systemctl stop $SERVICE
```
Stop `$SERVICE`
```sh
systemctl stop $SERVICE
```
Suspend the system
```sh
systemctl suspend
```

#### Runlevels
Runlevel                      | Description
---                           | ---
`poweroff.target`             | systemd equivalent to runlevel `0`
`rescue.target`               | systemd equivalent to runlevel `1`
`multi-user.target`           | systemd equivalent to runlevel `3`
`graphical.target`            | systemd equivalent to runlevel `5`
`reboot.target`               | systemd equivalent to runlevel `6`
`emergency.target`            | systemd equivalent to runlevel `emergency`

?
```sh
systemctl isolate --now service
```
Change target to runlevel emergency
```sh
systemctl isolate emergency.target
```
### `systemd-delta`
Show files that are overridden with systemd\
Display differences among files when they are overridden
```sh
systemd-delta --diff
```
### `timedatectl`
## Sysvinit
- **SystemVinit** is a daemon process which was used by most distros until recently. Processes started serially and synchronously, wasting system resources; for years, a common hack was to run services in the background, simulating a sort of parallel processing
- **Upstart** was developed by Canonical for Ubuntu, but abandoned in 2014. 
- [**Systemd**][SystemD] which starts processes in parallel has become de facto standard for all major Linux distributions

&nbsp;  | Commands
---     | ---
&nbsp;  | `chkconfig` &bull; `init` `initctl` &bull; `runlevel` &bull; `service` &bull; `telinit`

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