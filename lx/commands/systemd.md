# systemd

\#      | Commands sorted alphabetically
---     | ---
H       | [`hostnamectl`][hostnamectl]
J       | [`journalctl`][journalctl]
L       | [`localectl`][localectl] [`loginctl`][loginctl]
S       | [`systemctl`][systemctl] [`systemd-delta`][systemd-delta]
T       | [`timedatectl`][timedatectl]

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
Display the system clock, including local time, universal time, time zone, etc\
List timezones [^][49]
```sh
timedatectl list-timezones
```
Set timezone [^][49]
```sh
timedatectl set-timezone America/New_York
```
Synchronize over NTP using the `systemd-timesync` daemon (alternatively, use [`chrony`](README.md#chrony) [^][49]
```sh
timedatectl set-ntp true
```

[49]: https://devconnected.com/how-to-set-date-and-time-on-linux/ "devconnected.com: \"How to set date and time on Linux\""

[hostnamectl]: systemd.md#hostnamectl "Control the system hostname"
[journalctl]: systemd.md#journalctl "Query the systemd journal"
[localectl]: systemd.md#localectl "Control the system locale and keyboard layout settings"
[loginctl]: systemd.md#loginctl "Control the systemd login manager"
[systemctl]: systemd.md#systemctl "Control the systemd system and service manager"
[systemd-delta]: systemd.md#systemd-dela "Find overridden configuration files"
[timedatectl]: systemd.md#timedatectl "Control the system time and date"