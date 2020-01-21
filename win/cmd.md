# Command Prompt
\#      | Commands sorted alphabetically
---     | ---
**A-C** | [`adprep`][adprep] [`arp`](#arp) &bull; [`bcdedit`][bcdedit] [`bootrec`](#bootrec) &bull; [`cscript`][cscript]
I       | [`ipconfig`](#ipconfig) 
N       | [`nbtstat`](#nbtstat) [`netsh`](#netsh) [`ntdsutil`](#ntdsutil "Used to transfer FSMO roles between domain controllers")
R       | [`route`](#route) 
S       | [`shutdown`](#shutdown) [`slmgr`][slmgr] [`systeminfo`](#systeminfo) 
T       | [`tracert`](#tracert) [`traceroute`](#tracert) 
W       | [`winrm`](#winrm) [`wmic`][wmic]
### `adprep`
Prepare Active Directory for Windows Server upgrades. Must be run on the Infrastructure Master role owner with the flag `/domainprep`. [[^][Desmond2009]: 29]
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
Change Windows bootloader to Linux, while dual booting (Fedora)
```cmd
bcdedit /set {bootmgr} path \EFI\fedora\shim.efi
```
Change Windows bootloader to Linux, while dual booting (Manjaro)
```cmd
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi
```
Enable **Test Signing Mode** [^](https://www.howtogeek.com/167723/how-to-disable-driver-signature-verification-on-64-bit-windows-8.1-so-that-you-can-install-unsigned-drivers/ "howtogeek.com - 'How to disable driver signature verification on 64-bit Windows 8.1 so that you can install unsigned drivers'")
```cmd
bcdedit /set testsign on
```
Disable **Test Signing Mode** [^](https://www.howtogeek.com/167723/how-to-disable-driver-signature-verification-on-64-bit-windows-8.1-so-that-you-can-install-unsigned-drivers/ "howtogeek.com - 'How to disable driver signature verification on 64-bit Windows 8.1 so that you can install unsigned drivers'")
```cmd
bcdedit /set testsign off
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
### `msiexec`
Option  | Effect [^][https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]
---     | ---
`/i`    | Install or configure a product
`/q` `/qn | Set user interface level to "no UI"


### `nbtstat`
Option      | Effect [[^][Lammle]: 540-6]
:---        | :---
`-a $HOST`  | display NetBIOS name table of <code>$HOST</code> (NetBIOS name)
`-A $HOST`  | display NetBIOS name table of <code>$HOST</code> (IP address)
`-n`        | display local NetBIOS name table on Windows device
`-r`        | display NetBIOS resolution and registration statistics
`-R`        | purge NetBIOS name table cache and reload the LMHOSTS file into memory
`-S`        | display NetBIOS sessions table
`-s`        | display NetBIOS sessions table, attempting to resolve remote IP addresses to hostnames
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
### `netdom`
Alternative to [`Add-Computer`](pwsh.md#add-computer) PowerShell cmdlet [[^][Zacker]: 21]

Rename a computer
```
netdom renamecomputer %computername% /newname: newcomputername
```
Join a computer to a domain
```
netdom join %computername% /domain: domainname /userd: username /password:*
```
### `ntdsutil`
Used to transfer [FSMO](# "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles between domain controllers. [[^][Desmond2009]: 30]
### `route`
Command  | Effect [[^][Lammle]: 539]
:---     | :---
`print`  | display routing table
`add`    | add a route to the routing table
`change` | modify an existing route
`delete` | delete a route

Option  | Effect
:---    | :---
`-p`    | make a route **p**ersistent

Basic syntax:
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```
### `shutdown`
Immediate restart [^][Lab]
```cmd
shutdown /r /t 0
```
### `slmgr`
Option  | Effect [^][https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/] [MS Docs][https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11)]
---     | ---
`/dli`  | Display very basic license and activation information about the current system in a dialog box 
`/dlv`  | Display more detailed license information, including activation ID, installation ID, and other details 
`/xpr`  | Display activation status or expiration date of current license
`/upk`  | Remove the product key, placing Windows in an unactivated, unlicensed state (after restart)
`/ipk`  | Replace product key, equivalent to changing product key in Activation screen in Settings
`/ato`  | Force Windows to attempt an online activation, either with Microsoft servers or with the KMS server on the local network
`/rearm`| Reset activation timer to extend trial period. Each usage reduces the "rearm count" (ref. `/dlv`)
### `systeminfo`
Shows system information about the machine, including installed hotfixes and patches
### `tracert`
On Windows, this command is aliased to `traceroute` which is the Linux command. [[^][Lammle]: 112]

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
### `wmic`
Recover Windows product key [^][https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]
```cmd
wmic path softwarelicensingservice get OA3xOriginalProductKey
```
## 

[https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/]: https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/ "How to Use Slmgr to Change, Remove, or Extend Your Windows License"
[https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]: https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/ "How to find Windows 10 product key using CMD, PowerShell, and Windows Registry?"
[https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11)]: https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11) "Slmgr.vbs options for volume activation"
[https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]: https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options "Command-line options"

[Lab]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[Lammle]: ../certs/n10-007.md "Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012."
[Desmond2009]: ../sources/ad.md "Desmond, Brian et al. _Active Directory_. O'Reilly Media, 2009."
[Zacker]: ../certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

[adprep]:                                            #adprep                                            '`adprep`&#10;Prepare Active Directory for Windows Server upgrades'
[bcdedit]:                                           #bcdedit                                           '`bcdedit`&#10;Boot configuration data editor'
[cscript]:                                           #cscript                                           '`cscript`&#10;Starts a script so that it runs in a command-line environment'
[msiexec]:                                           #msiexec                                           '`msiexec`&#10;Provides the means to install, modify, and perform operations on Windows Installer from the command line'
[slmgr]:                                             #slmgr                                             '`slmgr`&#10;Windows software licensing management tool'