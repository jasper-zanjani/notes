# Command Prompt

\#    | Commands sorted alphabetically
---   | ---
A-Z   | [`arp`](#arp) [`bcdedit`](#bcdedit) [`bootrec`](#bootrec) [`ipconfig`](#ipconfig) [`nbtstat`](#nbtstat) [`netsh`](#netsh) [`route`](#route) [`systeminfo`](#systeminfo) [`tracert`](#tracert) [`traceroute`](#tracert) [`winrm`](#winrm)

### `arp`
Used to view and work with the IP adress to MAC address resolution cache.

Option  | Effect
:---    | :---
`-a`    | Display both the IP and MAC addresses and whether they are dynamic or static entries [[1](#sources): 436]
`-s`    | manually add a static entry to the cache
`-d`    | delete an entry from the cache

### `bcdedit`
Change Windows bootloader to Linux, while dual booting
```cmd
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi
```
Restore GRUB menu on a Fedora installation
```cmd
bcdedit /set {bootmgr} path \EFI\fedora\shim.efi
```
### `bootrec`
Windows Recovery Environment command that repairs a system partition
Use when boot sector not found
```
bootrec /fixboot
```
Use when BCD file has been corrupted
```
bootrec /rebuildbcd
```

### `ipconfig`

Option      | Effect
:---        | :---
`/all`
`/flushdns`
`/renew`

### `nbtstat`
Option      | Effect
:---        | :---
`-a $HOST`  | display NetBIOS name table of <code>$HOST</code> (NetBIOS name)
`-A $HOST`  | display NetBIOS name table of <code>$HOST</code> (IP address)
`-n`        | display local NetBIOS name table on Windows device
`-r`        | display NetBIOS resolution and registration statistics
`-R`        | purge NetBIOS name table cache and reload the LMHOSTS file into memory
`-S`        | display NetBIOS sessions table
`-s`        | display NetBIOS sessions table, attempting to resolve remote IP addresses to hostnames
\-          | [[Lammle](#sources): 540-6]

### `netsh`
Configure DNS to be dynamically assigned
```cmd
netsh interface ip set dns "Wi-Fi" dhcp
```
Delete Wi-Fi profiles
```cmd
netsh wlan delete profile name=*
```
Turn off Windows firewall
```cmd
netsh advfirewall set allprofiles state off
```

### `route`
Command  | Effect
:---     | :---
`print`  | display routing table
`add`    | add a route to the routing table
`change` | modify an existing route
`delete` | delete a route
\-       | [[Lammle](#sources): 539]

Option  | Effect
:---    | :---
`-p`    | make a route **p**ersistent

Basic syntax:
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```

### `systeminfo`
Shows system information about the machine, including installed hotfixes and patches

### `tracert`
On Windows, this command is aliased to `traceroute` which is the Linux command. [[1](#sources): 112]

Option  | Effect
:---    | :---
`-6`    | IPv6, aliased to `traceroute6`

### `winrm`
List all WinRM listeners  
```cmd
winrm enumerate winrm/config/listener
```
Display WinRM configuration
```cmd
winrm get winrm/config
```

## Sources
A. "Practice Lab: CompTIA Security+ (SY0-501)". [Web](https://pts.measureup.com/web/index.php#dashboard.php)

Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.
