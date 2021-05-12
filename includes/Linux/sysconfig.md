# sysconfig

### /etc/sysconfig/desktop

Specify desktop environment and display manager on Red Hat.
```ini
DESKTOP="KDE"
DISPLAYMANAGER="KDE"
```
```ini
DESKTOP="XFCE"
DISPLAYMANAGER="XDM"
```
```ini
DESKTOP="Gnome"
DISPLAYMANAGER="GDM"
```

### /etc/sysconfig/network-scripts/

Directory containing file configurations for each network device you may have or want to add on your system [ref](https://web.mit.edu/rhel-doc/5/RHEL-5-manual/Deployment_Guide-en-US/s1-networkscripts-interfaces.html "Red Hat Documentation: 13.2. Interface Configuration Files")
```ini
DEVICE=eth0
IPADDR=208.164.186.1
NETMASK=255.255.255.0
NETWORK=208.164.186.0
BROADCAST=208.164.186.255
ONBOOT=yes
BOOTPROTO=none
USERCTL=no
```