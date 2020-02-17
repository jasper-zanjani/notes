[Desmond2009]: ../sources/ad.md "Desmond, Brian et al. _Active Directory_. O'Reilly Media, 2009."
[https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/]: https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/ "HowToGeek: \"How to Use Slmgr to Change, Remove, or Extend Your Windows License\""
[https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]: https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/ "FossBytes: \"How to find Windows 10 product key using CMD, PowerShell, and Windows Registry?\""
[https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11)]: https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11) "Microsoft Docs: \"Slmgr.vbs options for volume activation\""
[https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]: https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options "Microsoft Docs: \"Command-line options\""
[https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command]: https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command "Microsoft Support: \"How to run Control Panel tools by typing a command\""
[https://pcsupport.lenovo.com/us/en/solutions/find-product-name]: https://pcsupport.lenovo.com/us/en/solutions/find-product-name "Find my product or serial number - Windows OS Command Prompt (cmd.exe) prompt"
[pl:Sec+]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[Lammle]: ../certs/n10-007.md "Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012."
[Zacker]: ../certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."


<!-- `cmd` commands -->
[adprep]:                      #adprep                         '```&#10;C:\>adprep&#10;```&#10;Prepare Active Directory for Windows Server upgrades'
[arp]:                         #arp                            '```&#10;C:\>arp&#10;```&#10;Display and modify the IP-to-MAC address translation tables used by ARP'
[bcdedit]:                     #bcdedit                        '```&#10;C:\>bcdedit&#10;```&#10;Boot configuration data editor'
[cscript]:                     #cscript                        '```&#10;C:\>cscript&#10;```&#10;Starts a script so that it runs in a command-line environment'
[diskpart]:                    #diskpart                       '```&#10;C:\>diskpart&#10;```&#10;Text-mode command interpreter used to convert disk types, create partitions and volumes, and configure RAID&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[msiexec]:                     #msiexec                        '```&#10;C:\>msiexec&#10;```&#10;Provides the means to install, modify, and perform operations on Windows Installer from the command line'
[ntdsutil]:                    #ntdsutil                       '```&#10;C:\>ntdsutil&#10;```&#10;Used to transfer FSMO roles between domain controllers'
[sfc]:                         #sfc                            '```&#10;C:\>sfc&#10;C:\>sfc /scannow&#10;```&#10;Scan and verify protected system files&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 373'
[slmgr]:                       #slmgr                          '```&#10;C:\>slmgr&#10;```&#10;Windows software licensing management tool'
[systeminfo]:                  #systeminfo                     '```&#10;C:\>systeminfo&#10;```&#10;Shows system information about the machine, including installed hotfixes and patches'
[wmic]:                        #wmic                           '```&#10;C:\>wmic&#10;```&#10;WMI command-line (WMIC) utility provides a command-line interface for WMI.'

<!-- Powershell commands -->
[Add-Computer]:                                      pwsh.md#add-computer                               '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Get-ChildItem]:                                     pwsh.md#get-childitem                              '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir&#10;PS C:\> gci&#10;PS C:\> ls&#10;```&#10;Get items in one or more locations'
[Invoke-GPUpdate]:                                   pwsh.md#invoke-gpupdate                            '```&#10;Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'

<!-- Control Panel binaries -->
[access.cpl]:                                        #access.cpl                                        '```&#10;C:\> access.cpl&#10;```&#10;Accessibility Options'
[appwiz.cpl]:                                        #appwiz.cpl                                        '```&#10;C:\> appwiz.cpl&#10;```&#10;Add/Remove Programs'
[desk.cpl]:                                          #desk.cpl                                          '```&#10;C:\> desk.cpl&#10;```&#10;Display Properties'
[findfast.cpl]:                                      #findfast.cpl                                      '```&#10;C:\> findfast.cpl&#10;```&#10;FindFast'
[inetcpl.cpl]:                                       #inetcpl.cpl                                       '```&#10;C:\> inetcpl.cpl&#10;```&#10;Internet Properties'
[intl.cpl]:                                          #intl.cpl                                          '```&#10;C:\> intl.cpl&#10;```&#10;Regional Settings'
[joy.cpl]:                                           #joy.cpl                                           '```&#10;C:\> joy.cpl&#10;```&#10;Joystick Properties'
[main.cpl]:                                          #main.cpl                                          '```&#10;C:\> main.cpl&#10;```&#10;Mouse Properties'
[mlcfg32.cpl]:                                       #mlcfg32.cpl                                       '```&#10;C:\> mlcfg32.cpl&#10;```&#10;Microsoft Exchange (or Windows Messaging)'
[mmsys.cpl]:                                         #mmsys.cpl                                         '```&#10;C:\> mmsys.cpl&#10;```&#10;Sound Properties'
[ncpa.cpl]:                                          #ncpa.cpl                                          '```&#10;C:\> ncpa.cpl&#10;```&#10;Network Settings'
[sysdm.cpl]:                                         #sysdm.cpl                                         '```&#10;C:\> sysdm.cpl&#10;```&#10;System Properties'
[timedate.cpl]:                                      #timedate.cpl                                      '```&#10;C:\> timedate.cpl&#10;```&#10;Date/Time Properties'
[wgpocpl.cpl]:                                       #wgpocpl.cpl                                       '```&#10;C:\> wgpocpl.cpl&#10;```&#10;Microsoft Mail Post Office'

<!-- `arp` options -->
[arp /&#97;]:                     #arp                           '```&#10;C:\>arp /a&#10;```&#10;Display both the IP and MAC addresses and whether they are dynamic or static entries '
[arp /&#115;]:                    #arp                           '```&#10;C:\>arp /s&#10;```&#10;Manually add a static entry to the cache'
[arp /&#100;]:                    #arp                           '```&#10;C:\>arp /d&#10;```&#10;Delete an entry from the cache'

<!-- `diskpart` commands -->
[diskpart active]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> ACTIVE&#10;```&#10;On MBR disks, marks the partition with current focus as the active system partition, meaning it is the partition containing the operating system startup files&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart add]:                   #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> ADD DISK=n&#10;```&#10;Create a mirrored volume on the selected dynamic disk&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart assign]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> ASSIGN LETTER=x&#10;DISKPART> ASSIGN MOUNT=path&#10;```&#10;Assign a drive letter or mount point to the selected partition, logical drive, or volume. Takes parameters "LETTER=x" or "MOUNT=path"&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart automount]:             #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> AUTOMOUNT ENABLE&#10;DISKPART> AUTOMOUNT DISABLE&#10;DISKPART> AUTOMOUNT SCRUB&#10;```&#10;Control whether Windows automatically mounts new basic volumes that are added to the system and assigns them drive letters. Takes parameters "ENABLE", "DISABLE", or "SCRUB"&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart break]:                 #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> BREAK DISK=n&#10;DISKPART> BREAK DISK=n NOKEEP&#10;```&#10;Break a mirror set. Takes parameter "DISK=n"&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart clean]:                 #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> CLEAN&#10;DISKPART> CLEAN ALL&#10;```&#10;Remove all partition or volume formatting on the focused disk.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart convert]:               #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> CONVERT BASIC&#10;DISKPART> CONVERT DYNAMIC&#10;DISKPART> CONVERT GPT&#10;DISKPART> CONVERT MBR&#10;```&#10;Convert focused disk to basic/dynamic&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart create]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> CREATE PARTITION EFI&#10;DISKPART> CREATE PARTITION EXTENDED&#10;DISKPART> CREATE PARTITION LOGICAL&#10;DISKPART> CREATE PARTITION MSR&#10;DISKPART> CREATE PARTITION PRIMARY&#10;DISKPART> CREATE VOLUME SIMPLE&#10;DISKPART> CREATE VOLUME RAID&#10;DISKPART> CREATE VOLUME STRIPE&#10;```&#10;Create a partition or volume of a specific type&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart delete]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> DELETE&#10;```&#10;Delete the focused disk, partition, or volume&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart detail]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> DETAIL&#10;```&#10;Provide details about the focused disk, partition, or volume&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart exit]:                  #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> EXIT&#10;```&#10;Exit the DiskPart interpreter&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart extend]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> EXTEND SIZE=n DISK=n&#10;```&#10;Extend the simple volume on the selected disk or span the volume across multiple disks&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart gpt]:                   #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> GPT ATTRIBUTES=n&#10;```&#10;Change GPT attributes on the focused partition (Windows Server 2003 only)&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart help]:                  #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> HELP&#10;```&#10;Display a list of commands&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart import]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> IMPORT&#10;```&#10;Import a foreign disk&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart inactive]:              #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> INACTIVE&#10;```&#10;On MBR disks, mark the focused partition as inactive.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart list]:                  #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> LIST DISK&#10;DISKPART> LIST PARTITION&#10;DISKPART> LIST VOLUME&#10;```&#10;Display a list of disks or volumes and information about them, or a list of partitions on the focused disk.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart online]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> ONLINE&#10;```&#10;Bring the selected disk or volume online. Resynchronize the mirrored or focused RAID-5 volume.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart rem]:                   #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> REM Lorem ipsum&#10;```&#10;Mark the start of a comment in a DiskPart script&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart remove]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> REMOVE LETTER=x&#10;DISKPART> REMOVE MOUNT=path&#10;```&#10;Remove specified drive letter or mount point from the currently selected volume&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart repair]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> REPAIR DISK=n&#10;```&#10;Repair the focused RAID-5 volume by replacing the failed volume with the designated dynamic disk (Windows Server 2003 only)&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart rescan]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> RESCAN&#10;```&#10;Look for new disks that may have been added to the computer&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart retain]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> RETAIN&#10;```&#10;Prepare the selected simple volume to be used as the boot or system volume&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[diskpart select]:                #diskpart                      '```&#10;C:\> diskpart&#10;DISKPART> SELECT&#10;```&#10;Focus specified disk, partition, or volume&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'

<!-- `route` commands -->
[route print]:                    #route                         '```&#10;C:\>route print&#10;```&#10;Display routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route add]:                      #route                         '```&#10;C:\>route add&#10;```&#10;Add a route to the routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route change]:                   #route                         '```&#10;C:\>route change&#10;```&#10;Modify an existing route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route delete]:                   #route                         '```&#10;C:\>route delete&#10;```&#10;Delete a route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'

<!-- `route` options -->
[route /&#112;]:                #route                         '```&#10;C:\>route /p&#10;```&#10;Make a route persistent&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'

<!-- `sfc` commands -->
[sfc /scannow]:                   #sfc                           '```&#10;C:\>sfc /scannow&#10;```&#10;Scan all protected system files, and replace corrupted files with a cached copy that is located in a compressed folder at %WinDir%\System32\dllcache'

<!-- `slmgr` options -->
[slmgr /dli]:                     #slmgr                         '```&#10;C:\> slmgr /dli&#10;```&#10;Display very basic license and activation information about the current system in a dialog box'
[slmgr /dlv]:                     #slmgr                         '```&#10;C:\> slmgr /dlv&#10;```&#10;Display more detailed license information, including activation ID, installation ID, and other details'
[slmgr /xpr]:                     #slmgr                         '```&#10;C:\> slmgr /xpr&#10;```&#10;Display activation status or expiration date of current license'
[slmgr /upk]:                     #slmgr                         '```&#10;C:\> slmgr /upk&#10;```&#10;Remove the product key, placing Windows in an unactivated, unlicensed state (after restart)'
[slmgr /ipk]:                     #slmgr                         '```&#10;C:\> slmgr /ipk&#10;```&#10;Replace product key, equivalent to changing product key in Activation screen in Settings'
[slmgr /ato]:                     #slmgr                         '```&#10;C:\> slmgr /ato&#10;```&#10;Force Windows to attempt an online activation, either with Microsoft servers or with the KMS server on the local network'
[slmgr /rearm]:                   #slmgr                         '```&#10;C:\> slmgr /rearm&#10;```&#10;Reset activation timer to extend trial period. Each usage reduces the "rearm count" (ref. `/dlv`)'

# Command Prompt
&nbsp;  | Commands sorted alphabetically
---     | ---
A       | [`adprep`][adprep] [`arp`][arp] 
B       | [`bcdedit`][bcdedit] [`bootrec`](#bootrec)
C       | [`cscript`][cscript] 
D       | `dir`[<sup>pwsh</sup>][Get-ChildItem]  [`diskpart`][diskpart] 
G       | `gpupdate`[<sup>pwsh</sup>][Invoke-GPUpdate]
I       | [`ipconfig`](#ipconfig)
N       | [`nbtstat`](#nbtstat) [`netsh`](#netsh) [`ntdsutil`][ntdsutil]
R       | [`route`](#route)
S       | [`sfc`][sfc] [`shutdown`](#shutdown) [`slmgr`][slmgr] [`systeminfo`](#systeminfo)
T       | [`tracert`](#tracert) [`traceroute`](#tracert)
W       | [`winrm`](#winrm) [`wmic`][wmic]
Control Panel tools | [`access.cpl`][access.cpl] [`appwiz.cpl`][appwiz.cpl] &bull; [`desk.cpl`][desk.cpl] &bull; [`findfast.cpl`][findfast.cpl] &bull; [`inetcpl.cpl`][inetcpl.cpl] [`intl.cpl`][intl.cpl] &bull; [`joy.cpl`][joy.cpl] &bull; [`main.cpl`][main.cpl] [`mlcfg32.cpl`][mlcfg32.cpl] [`mmsys.cpl`][mmsys.cpl] &bull; [`ncpa.cpl`][ncpa.cpl] &bull; [`sysdm.cpl`][sysdm.cpl] &bull; [`timedate.cpl`][timedate.cpl] &bull; [`wgpocpl.cpl`][wgpocpl.cpl] [<sup>Microsoft</sup>][https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command]

### `adprep`
Prepare Active Directory for Windows Server upgrades. Must be run on the Infrastructure Master role owner with the flag `/domainprep`. [<sup>Desmond 2009: 29</sup>][Desmond2009]
### `arp`
Used to view and work with the IP adress to MAC address resolution cache.

&nbsp;  | Options
---     | ---
&nbsp;  | [`a`][arp /&#97;] [`d`][arp /&#100;] [`s`][arp /&#115;]

### `bcdedit`
Change Windows bootloader to Linux, while dual booting
```cmd
::Manjaro
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi

::Fedora
bcdedit /set {bootmgr} path \EFI\fedora\shim.efi
```
Enable or disable **Test Signing Mode** [<sup>Howtogeek</sup>](https://www.howtogeek.com/167723/how-to-disable-driver-signature-verification-on-64-bit-windows-8.1-so-that-you-can-install-unsigned-drivers/ "howtogeek.com - 'How to disable driver signature verification on 64-bit Windows 8.1 so that you can install unsigned drivers'")
```cmd
bcdedit /set testsign on
bcdedit /set testsign off
```
### `bootrec`
Windows Recovery Environment command that repairs a system partition

Use when boot sector not found
```cmd
bootrec /fixboot
```
Use when BCD file has been corrupted
```cmd
bootrec /rebuildbcd
```
### `diskpart`
\#      | Commands sorted alphabetically
---     | ---
A       | [`ACTIVE`][diskpart active] [`ADD`][diskpart add] [`ASSIGN`][diskpart assign] [`AUTOMOUNT`][diskpart automount] 
B       | [`BREAK`][diskpart break]
C       | [`CLEAN`][diskpart clean] [`CONVERT`][diskpart convert] [`CREATE`][diskpart create]
D       | [`DELETE`][diskpart delete] [`DETAIL`][diskpart detail]
E       | [`EXIT`][diskpart exit] [`EXTEND`][diskpart extend] 
G       | [`GPT`][diskpart gpt]
H       | [`HELP`][diskpart help] 
I       | [`IMPORT`][diskpart import] [`INACTIVE`][diskpart inactive]
L       | [`LIST`][diskpart list]
O       | [`ONLINE`][diskpart online]
R       | [`REM`][diskpart rem] [`REMOVE`][diskpart remove] [`REPAIR`][diskpart repair] [`RESCAN`][diskpart rescan] [`RETAIN`][diskpart retain]
S       | [`SELECT`][diskpart select]

### `ipconfig`
Option      | Effect
:---        | :---
`/all`
`/flushdns`
`/renew`
### `msiexec`
Option      | Effect [Microsoft Docs][https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]
---         | ---
`/i`        | Install or configure a product
`/q` `/qn`  | Set user interface level to "no UI"
### `nbtstat`
Option      | Effect [<sup>Lammle: 540-546</sup>][Lammle]
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
Alternative to [`Add-Computer`][Add-Computer] PowerShell cmdlet [<sup>Zacker: 21</sup>][Zacker]

Rename a computer
```
netdom renamecomputer %computername% /newname: newcomputername
```
Join a computer to a domain
```
netdom join %computername% /domain: domainname /userd: username /password:*
```
### `ntdsutil`
Used to transfer [FSMO](# "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles between domain controllers. [<sup>Desmond 2009: 30</sup>][Desmond2009]
### `route`

&nbsp;  | Commands
---     | ---
Commands  | [`print`][route print] [`add`][route add] [`change`][route change] [`delete`][route delete] 
Options | [`p`][route /&#112;]

Basic syntax:
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```
### `sfc`
[^](#)  | Options
---     | ---
&nbsp;  | [`scannow`][sfc /scannow]
### `shutdown`
Immediate restart [<sup>Practice Lab</sup>][pl:Sec+]
```cmd
shutdown /r /t 0
```
### `slmgr`
[^](#)  | Options [<sup>Howtogeek</sup>][https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/] [<sup>Microsoft Docs</sup>][https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11)]
---     | ---
&nbsp;  | [`ato`][slmgr /ato] [`dli`][slmgr /dli] [`dlv`][slmgr /dlv]  [`ipk`][slmgr /ipk]  [`rearm`][slmgr /rearm] [`upk`][slmgr /upk] [`xpr`][slmgr /xpr]

### `systeminfo`
Shows system information about the machine, including installed hotfixes and patches
### `tracert`
On Windows, this command is aliased to `traceroute` which is the Linux command. [Lammle p.112][Lammle]

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
Recover Windows product key [<sup>Fossbytes</sup>][https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]
```cmd
wmic path softwarelicensingservice get OA3xOriginalProductKey
```
Recover serial number of a Lenovo laptop [<sup>Lenovo</sup>][https://pcsupport.lenovo.com/us/en/solutions/find-product-name]
```cmd
wmic bios get serialnumber
```