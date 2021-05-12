[rfkill block]:                         #rfkill                        'Disable specified devices'
[rfkill list]:                          #rfkill                        'List the current state of all available devices using `rfkill`'
[rfkill unblock]:                       #rfkill                        'Enable specified device'

[`block`][rfkill block] 
[`list`][rfkill list] 
[`unblock`][rfkill unblock] 

Tool for enabling and disabling wireless devices

Unblock Bluetooth, if it is blocked [ref][https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]
```sh
rfkill unblock bluetooth
```