[systemctl daemon-reload]:                 #systemctl                     'Reload unit files and systemd configuration&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl disable]:                       #systemctl                     'Prevent `$UNIT` from activating at boot&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl enable]:                        #systemctl                     'Enable `$UNIT` to activate it at boot&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl isolate]:                       #systemctl                     'Change operating mode to `$TARGET`&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl kill]:                          #systemctl                     'Send a signal to units matching `$PATTERN`&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl list-unit-files]:               #systemctl                     '&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl list-units]:                    #systemctl                     'Show installed units; optionally matching `$PATTERN`&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl reboot]:                        #systemctl                     'Reboot the computer&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl restart]:                       #systemctl                     'Restart `$UNIT` immediately&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl start]:                         #systemctl                     'Activate `$UNIT` immediately&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl status]:                        #systemctl                     'Show status of `$UNIT` and recent log entries.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl stop]:                          #systemctl                     'Deactivate `$UNIT` immediately&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 47'
[systemctl mask]:                          #systemctl                     'Prevent `$UNIT` from being started inadvertently by another process'
[systemctl set-default]:                   #systemctl                     'Configure system to boot to operating mode indicated by `$TARGET`'
[systemctl get-default]:                   #systemctl                     'Display default operating mode'
[systemctl suspend]:                       #systemctl                     'Suspend the system'

[`daemon-reload`][systemctl daemon-reload] 
[`disable`][systemctl disable] 
[`enable`][systemctl enable] 
[`get-default`][systemctl get-default] 
[`isolate`][systemctl isolate] 
[`kill`][systemctl kill] 
[`list-unit-files`][systemctl list-unit-files] 
[`list-units`][systemctl list-units] 
[`mask`][systemctl mask] 
[`reboot`][systemctl reboot] 
[`restart`][systemctl restart] 
[`set-default`][systemctl set-default] 
[`start`][systemctl start] 
[`status`][systemctl status] 
[`stop`][systemctl stop] 
[`suspend`][systemctl suspend] 

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
Change target to runlevel emergency
```sh
systemctl isolate emergency.target
```
Enable systemd service for newly-installed `$DISPLAYMANAGER`; may require disabling previous display manager first
```sh
systemctl enable $DISPLAYMANAGER.service -f
```
### Service files

Creating a service file ([src](https://www.redhat.com/sysadmin/replacing-rclocal-systemd))
```ini
[Unit]
Description=Runs /usr/local/bin/mystartup.sh

[Service]
ExecStart=/usr/local/bin/mystartup.sh

[Install]
WantedBy=multi-user.target
```