Configure iptables to start on boot and start it immediately
```sh
systemctl enable --now iptables
```
Disable `$SERVICE`, ensuring it does not run on boot
```sh
systemctl disable $SERVICE
```
Change signal type sent to process to be killed
```sh
systemctl kill -s
```
Equivalent to `chkconfig --list`
```sh
systemctl list-unit-files --type=service
```
Prevent firewalld from being started inadvertently by another process
```sh
systemctl mask firewalld
```
Restart `iptables.service`
```sh
systemctl restart iptables
```
Configure system to boot to a [GUI](#targets)
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
Suspend the system
```sh
systemctl suspend
```
Change target to runlevel emergency
```sh
systemctl isolate emergency.target
```
Enable systemd service for newly-installed `$DISPLAYMANAGER`; may require disabling previous display manager first
```sh
systemctl enable $DISPLAYMANAGER.service -f
```
