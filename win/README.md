<!-- Sources -->
[https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/]: https://www.howtogeek.com/245445/how-to-use-slmgr-to-change-remove-or-extend-your-windows-license/ "HowToGeek: \"How to Use Slmgr to Change, Remove, or Extend Your Windows License\""
[https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]: https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/ "FossBytes: \"How to find Windows 10 product key using CMD, PowerShell, and Windows Registry?\""
[https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11)]: https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-r2-and-2012/dn502540(v%3Dws.11) "Microsoft Docs: \"Slmgr.vbs options for volume activation\""
[https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]: https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options "Microsoft Docs: \"Command-line options\""
[https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command]: https://support.microsoft.com/en-us/help/192806/how-to-run-control-panel-tools-by-typing-a-command "Microsoft Support: \"How to run Control Panel tools by typing a command\""
[https://pcsupport.lenovo.com/us/en/solutions/find-product-name]: https://pcsupport.lenovo.com/us/en/solutions/find-product-name "Find my product or serial number - Windows OS Command Prompt (cmd.exe) prompt"
[Desmond2009]: https://github.com/jasper-zanjani/notes/master/sources/ad.md "Desmond, Brian et al. _Active Directory_. O'Reilly Media, 2009."
[pl:Sec+]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[Lammle]: https://github.com/jasper-zanjani/notes/master/certs/n10-007.md "Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012."
[Zacker]: https://github.com/jasper-zanjani/notes/master/certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

<!-- Concepts -->
[UWP]: #uwp 'Universal Windows Platform (UWP)&#10;Universal Windows Platform provides a common app platform on every device that runs Windows 10, and UWP apps are primarily associated with the Microsoft Store.&#10;"Universal Windows Platform apps". _Wikipedia_.'

<!-- `cmd` commands -->
[adprep]:         #adprep                         '```&#10;C:\>adprep&#10;```&#10;Prepare Active Directory for Windows Server upgrades&#10;Must be run on the Infrastructure Master role owner with the flag `/domainprep`.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 29'
[arp]:            #arp                            '```&#10;C:\>arp&#10;```&#10;Display and modify the IP-to-MAC address translation tables used by ARP'
[bcdedit]:        #bcdedit                        '```&#10;C:\>bcdedit&#10;```&#10;Boot configuration data editor'
[bootrec]:        #bootrec                        '```&#10;C:\>bootrec&#10;```&#10;Windows Recovery Environment command that repairs a system partition'
[cscript]:        #cscript                        '```&#10;C:\>cscript&#10;```&#10;Starts a script so that it runs in a command-line environment'
[diskpart]:       #diskpart                       '```&#10;C:\>diskpart&#10;```&#10;Text-mode command interpreter used to convert disk types, create partitions and volumes, and configure RAID&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[hostname]:       #hostname                       '```&#10;C:\>hostname&#10;C:\>HOSTNAME.exe&#10;```&#10;Display computer name'
[ipconfig]:       #ipconfig                       '```&#10;C:\>ipconfig&#10;```&#10;Display TCP/IP configuration'
[logoff]:         #logoff                         '```&#10;C:\>logoff&#10;```&#10;Log out'
[msiexec]:        #msiexec                        '```&#10;C:\>msiexec&#10;```&#10;Provides the means to install, modify, and perform operations on Windows Installer from the command line'
[nbtstat]:        #nbtstat                        '```&#10;C:\>nbtstat&#10;```&#10;Display status of NetBIOS'
[netsh]:          #netsh                          '```&#10;C:\>netsh&#10;```&#10;"Network services shell", command-line utility that allows you to manage the configuration of various network services on local and remote computers.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 297'
[ntdsutil]:       #ntdsutil                       '```&#10;C:\>ntdsutil&#10;```&#10;Used to transfer FSMO roles between domain controllers'
[sfc]:            #sfc                            '```&#10;C:\>sfc&#10;C:\>sfc /scannow&#10;```&#10;Scan and verify protected system files&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 373'
[slmgr]:          #slmgr                          '```&#10;C:\>slmgr&#10;```&#10;Windows software licensing management tool'
[systeminfo]:     #systeminfo                     '```&#10;C:\>systeminfo&#10;```&#10;Shows system information about the machine, including installed hotfixes and patches'
[winver]:         #winver                                             '```&#10;C:\>winver&#10;```&#10;Display the "About Windows" dialog box, including Windows version and build number'
[wmic]:           #wmic                           '```&#10;C:\>wmic&#10;```&#10;WMI command-line (WMIC) utility provides a command-line interface for WMI.'

<!-- Powershell commands -->
[Add-Computer]:                                      pwsh.md#add-computer                               '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Get-ChildItem]:                                     pwsh.md#get-childitem                              '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir&#10;PS C:\> gci&#10;PS C:\> ls&#10;```&#10;Get items in one or more locations'
[Invoke-GPUpdate]:                                   pwsh.md#invoke-gpupdate                            '```&#10;Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'

<!-- Linux commands -->
[grep]: https://github.com/jasper-zanjani/notes/blob/master/lx/commands/README.md#grep '```&#10;$ grep&#10;```&#10;Search `$FILES` for lines containing a match to regex `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'

<!-- Control Panel binaries -->
[access.cpl]:     #access.cpl           '```&#10;C:\> access.cpl&#10;```&#10;Accessibility Options'
[appwiz.cpl]:     #appwiz.cpl           '```&#10;C:\> appwiz.cpl&#10;```&#10;Add/Remove Programs'
[desk.cpl]:       #desk.cpl             '```&#10;C:\> desk.cpl&#10;```&#10;Display Properties'
[findfast.cpl]:   #findfast.cpl         '```&#10;C:\> findfast.cpl&#10;```&#10;FindFast'
[inetcpl.cpl]:    #inetcpl.cpl          '```&#10;C:\> inetcpl.cpl&#10;```&#10;Internet Properties'
[intl.cpl]:       #intl.cpl             '```&#10;C:\> intl.cpl&#10;```&#10;Regional Settings'
[joy.cpl]:        #joy.cpl              '```&#10;C:\> joy.cpl&#10;```&#10;Joystick Properties'
[main.cpl]:       #main.cpl             '```&#10;C:\> main.cpl&#10;```&#10;Mouse Properties'
[mlcfg32.cpl]:    #mlcfg32.cpl          '```&#10;C:\> mlcfg32.cpl&#10;```&#10;Microsoft Exchange (or Windows Messaging)'
[mmsys.cpl]:      #mmsys.cpl            '```&#10;C:\> mmsys.cpl&#10;```&#10;Sound Properties'
[ncpa.cpl]:       #ncpa.cpl             '```&#10;C:\> ncpa.cpl&#10;```&#10;Network Settings'
[sysdm.cpl]:      #sysdm.cpl            '```&#10;C:\> sysdm.cpl&#10;```&#10;System Properties'
[timedate.cpl]:   #timedate.cpl         '```&#10;C:\> timedate.cpl&#10;```&#10;Date/Time Properties'
[wgpocpl.cpl]:    #wgpocpl.cpl          '```&#10;C:\> wgpocpl.cpl&#10;```&#10;Microsoft Mail Post Office'

# Microsoft Windows

Topics
---
[Desired State Configuration](dsc.md) &bull; [Powershell](pwsh.md)

#### Concepts
**U** 
[UWP][UWP]

## Command Prompt

[`access`][access.cpl] 
[`adprep`][adprep] 
[`appwiz.cpl`][appwiz.cpl] 
[`arp`][arp] 
[`bcdedit`][bcdedit] 
[`bootrec`][bootrec]
[`cscript`][cscript] 
[`desk`][desk.cpl] 
`dir`[<sup>pwsh</sup>][Get-ChildItem] 
[`diskpart`][diskpart] 
[`findfast.cpl`][findfast.cpl] 
`findstr`[<sup>lx</sup>][grep]
`gpupdate`[<sup>pwsh</sup>][Invoke-GPUpdate]
[`hostname`][hostname][<sup>pwsh</sup>](pwsh.md#get-computerinfo "```&#10;PS C:\> (Get-ComputerInfo).CsName&#10;```")
[`inetcpl.cpl`][inetcpl.cpl] 
[`intl.cpl`][intl.cpl] 
[`ipconfig`][ipconfig]
[`joy.cpl`][joy.cpl]
[`logoff`][logoff]
[`main`][main.cpl] 
[`mlcfg32.cpl`][mlcfg32.cpl] 
[`mmsys`][mmsys.cpl]
[`nbtstat`][nbtstat] [`netsh`](#netsh) 
[`ncpa`][ncpa.cpl]
[`ntdsutil`][ntdsutil]
[`route`](#route)
[`sfc`][sfc] [`shutdown`](#shutdown) 
[`slmgr`][slmgr] 
[`sysdm.cpl`][sysdm.cpl]
[`systeminfo`][systeminfo]
[`timedate.cpl`][timedate.cpl]
[`tracert`](#tracert) 
[`traceroute`](#tracert)
[`wgpocpl.cpl`][wgpocpl.cpl]
[`winrm`](#winrm) 
[`winver`][winver]
[`wmic`][wmic]

### `adprep`
Prepare Active Directory for Windows Server upgrades. Must be run on the Infrastructure Master role owner with the flag `/domainprep`. [<sup>Desmond 2009: 29</sup>][Desmond2009]
### `arp`
<!-- `arp` options -->
[arp /&#97;]:                     #arp                           '```&#10;C:\>arp /a&#10;```&#10;Display both the IP and MAC addresses and whether they are dynamic or static entries '
[arp /&#115;]:                    #arp                           '```&#10;C:\>arp /s&#10;```&#10;Manually add a static entry to the cache'
[arp /&#100;]:                    #arp                           '```&#10;C:\>arp /d&#10;```&#10;Delete an entry from the cache'

<code>&nbsp;</code> [`a`][arp /&#97;] <code>&nbsp;</code> <code>&nbsp;</code> [`d`][arp /&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][arp /&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 
### `bcdedit`
Change Windows bootloader to Linux, while dual booting
```cmd
::Manjaro
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi

::Fedora
bcdedit /set {bootmgr} path \EFI\fedora\shim.efi
```
Enable or disable **Test Signing Mode** [<sup>ref</sup>](https://www.howtogeek.com/167723/how-to-disable-driver-signature-verification-on-64-bit-windows-8.1-so-that-you-can-install-unsigned-drivers/ "howtogeek.com - 'How to disable driver signature verification on 64-bit Windows 8.1 so that you can install unsigned drivers'")
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

[`ACTIVE`][diskpart ACTIVE] 
[`ADD`][diskpart ADD] 
[`ASSIGN`][diskpart ASSIGN] 
[`AUTOMOUNT`][diskpart AUTOMOUNT] 
[`BREAK`][diskpart BREAK] 
[`CLEAN`][diskpart CLEAN] 
[`CONVERT`][diskpart CONVERT] 
[`CREATE`][diskpart CREATE] 
[`DELETE`][diskpart DELETE] 
[`DETAIL`][diskpart DETAIL] 
[`EXIT`][diskpart EXIT] 
[`EXTEND`][diskpart EXTEND] 
[`GPT`][diskpart GPT] 
[`HELP`][diskpart HELP] 
[`IMPORT`][diskpart IMPORT] 
[`INACTIVE`][diskpart INACTIVE] 
[`LIST`][diskpart LIST] 
[`ONLINE`][diskpart ONLINE] 
[`REM`][diskpart REM] 
[`REMOVE`][diskpart REMOVE] 
[`REPAIR`][diskpart REPAIR] 
[`RESCAN`][diskpart RESCAN] 
[`RETAIN`][diskpart RETAIN] 
[`SELECT`][diskpart SELECT] 

### `ipconfig`
`all` `flushdns` `renew`

### `msiexec`
<!-- `msiexec` commands -->
[msiexec /&#105;]:              #msiexec                       '```&#10;C:\>msiexec /i&#10;```&#10;Install or configure a product'
[msiexec /&#113;]:              #msiexec                       '```&#10;C:\>msiexec /q&#10;C:\>msiexec /qn&#10;```&#10;Set user interface level to "no UI"'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`i`][msiexec /&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`q`][msiexec /&#113;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [<sup>ref</sup>][https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]

### `nbtstat`
<!-- `nbtstat` commands -->
[nbtstat /&#97;]:               #nbtstat                       '```&#10;C:\>nbtstat /a&#10;```&#10;Display NetBIOS name table of `$HOST` (NetBIOS name)'
[nbtstat /&#65;]:               #nbtstat                       '```&#10;C:\>nbtstat /A&#10;```&#10;Display NetBIOS name table of `$HOST` (IP address)'
[nbtstat /&#110;]:              #nbtstat                       '```&#10;C:\>nbtstat /n&#10;```&#10;Display local NetBIOS name table on Windows device'
[nbtstat /&#114;]:              #nbtstat                       '```&#10;C:\>nbtstat /r&#10;```&#10;Display NetBIOS resolution and registration statistics'
[nbtstat /&#82;]:               #nbtstat                       '```&#10;C:\>nbtstat /R&#10;```&#10;Purge NetBIOS name table cache and reload the `LMHOSTS` file into memory'
[nbtstat /&#83;]:               #nbtstat                       '```&#10;C:\>nbtstat /S&#10;```&#10;Display NetBIOS sessions table'
[nbtstat /&#115;]:              #nbtstat                       '```&#10;C:\>nbtstat /s&#10;```&#10;Display NetBIOS sessions table, attempting to resolve remote IP addresses to hostnames'

<code>&nbsp;</code>   [`a`][nbtstat /&#97;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`n`][nbtstat /&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][nbtstat /&#114;] [`s`][nbtstat /&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;[`A`][nbtstat /&#65;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`R`][nbtstat /&#82;] [`S`][nbtstat /&#83;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

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
### `netsh`
[netsh aaaa]:                     #netsh                         '```&#10;C:\>netsh aaaa&#10;C:\>netsh&#10;netsh>aaaa&#10;```&#10;Authentication, authorization, accounting, and auditing; context used to view and work with the AAAA database used by the Internet Authentication Service and the Routing and Remote Access Service&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 297'
[netsh bridge]:                   #netsh                         '```&#10;C:\>netsh bridge&#10;C:\>netsh&#10;netsh>bridge&#10;```&#10;L3 compatibilty mode for network bridges&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh dhcp]:                     #netsh                         '```&#10;C:\>netsh dhcp&#10;C:\>netsh&#10;netsh>dhcp&#10;```&#10;DHCP servers&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 297'
[netsh diag]:                     #netsh                         '```&#10;C:\>netsh diag&#10;C:\>netsh&#10;netsh>diag&#10;```&#10;Network service parameters&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 297'
[netsh interface ip]:             #netsh                         '```&#10;C:\>netsh interface ip&#10;C:\>netsh&#10;netsh>interface ip&#10;```&#10;TCP/IP network configuration of a computer&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh interface ipv6]:           #netsh                         '```&#10;C:\>netsh interface ipv6&#10;C:\>netsh&#10;netsh>interface ipv6&#10;```&#10;IPv6 network configuration of a computer&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh interface portproxy]:      #netsh                         '```&#10;C:\>netsh interface portproxy&#10;C:\>netsh&#10;netsh>interface portproxy&#10;```&#10;Manage proxies between IPv4 and IPv6 networks&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh ipsec]:                    #netsh                         '```&#10;C:\>netsh ipsec&#10;C:\>netsh&#10;netsh>ipsec&#10;```&#10;IPsec&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh ras]:                      #netsh                         '```&#10;C:\>netsh ras&#10;C:\>netsh&#10;netsh>ras&#10;```&#10;Remote Access Server (RAS) configurations&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh routing]:                  #netsh                         '```&#10;C:\>netsh routing&#10;C:\>netsh&#10;netsh>routing&#10;```&#10;Routing servers&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh rpc]:                      #netsh                         '```&#10;C:\>netsh rpc&#10;C:\>netsh&#10;netsh>rpc&#10;```&#10;Remote procedure call (RPC) helper&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'
[netsh wins]:                     #netsh                         '```&#10;C:\>netsh wins&#10;C:\>netsh&#10;netsh>wins&#10;```&#10;WINS, used to view and manage NetBIOS resolution for pre-Windows 2000 computers&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 298'

[`aaaa`][netsh aaaa] 
[`bridge`][netsh bridge] 
[`dhcp`][netsh dhcp] 
[`diag`][netsh diag] 
[`interface ip`][netsh interface ip] 
[`interface ipv6`][netsh interface ipv6] 
[`interface portproxy`][netsh interface portproxy] 
[`ipsec`][netsh ipsec] 
[`ras`][netsh ras] 
[`routing`][netsh routing] 
[`rpc`][netsh rpc] 
[`wins`][netsh wins] 
`wlan`

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
Show Wi-Fi passwords <sup>[helpdeskgeek.com](https://helpdeskgeek.com/how-to/find-the-wifi-password-in-windows-10-using-cmd/ "Find the WiFi Password in Windows 10 Using CMD")</sup>
```cmd
netsh wlan show profile wifi key=clear
```
### `ntdsutil`
Used to transfer [FSMO](# "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles between domain controllers. [<sup>Desmond: 30</sup>][Desmond2009]
### `route`
<!-- `route` options -->
[route /&#112;]:                #route                         '```&#10;C:\>route /p&#10;```&#10;Make a route persistent&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
<!-- `route` commands -->
[route print]:                    #route                         '```&#10;C:\>route print&#10;```&#10;Display routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route add]:                      #route                         '```&#10;C:\>route add&#10;```&#10;Add a route to the routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route change]:                   #route                         '```&#10;C:\>route change&#10;```&#10;Modify an existing route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route delete]:                   #route                         '```&#10;C:\>route delete&#10;```&#10;Delete a route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][route /&#112;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br> [`print`][route print] [`add`][route add] [`change`][route change] [`delete`][route delete]

Basic usage
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```
### `sfc`
<!-- `sfc` commands -->
[sfc /scannow]:                   #sfc                           '```&#10;C:\>sfc /scannow&#10;```&#10;Scan all protected system files, and replace corrupted files with a cached copy that is located in a compressed folder at %WinDir%\System32\dllcache'

[`scannow`][sfc /scannow]

### `shutdown`
Immediate restart [<sup>Practice Lab</sup>][pl:Sec+]
```cmd
shutdown /r /t 0
```
### `slmgr`
[slmgr /dli]:                     #slmgr                         '```&#10;C:\> slmgr /dli&#10;```&#10;Display very basic license and activation information about the current system in a dialog box'
[slmgr /dlv]:                     #slmgr                         '```&#10;C:\> slmgr /dlv&#10;```&#10;Display more detailed license information, including activation ID, installation ID, and other details'
[slmgr /xpr]:                     #slmgr                         '```&#10;C:\> slmgr /xpr&#10;```&#10;Display activation status or expiration date of current license'
[slmgr /upk]:                     #slmgr                         '```&#10;C:\> slmgr /upk&#10;```&#10;Remove the product key, placing Windows in an unactivated, unlicensed state (after restart)'
[slmgr /ipk]:                     #slmgr                         '```&#10;C:\> slmgr /ipk&#10;```&#10;Replace product key, equivalent to changing product key in Activation screen in Settings'
[slmgr /ato]:                     #slmgr                         '```&#10;C:\> slmgr /ato&#10;```&#10;Force Windows to attempt an online activation, either with Microsoft servers or with the KMS server on the local network'
[slmgr /rearm]:                   #slmgr                         '```&#10;C:\> slmgr /rearm&#10;```&#10;Reset activation timer to extend trial period. Each usage reduces the "rearm count" (ref. `/dlv`)'

[`dli`][slmgr /dli]
[`dlv`][slmgr /dlv]
[`xpr`][slmgr /xpr]
[`upk`][slmgr /upk]
[`ipk`][slmgr /ipk]
[`ato`][slmgr /ato]
[`rearm`][slmgr /rearm]

### `tracert`
On Windows, this command is aliased to `traceroute` which is the Linux command. [<sup>Lammle: 112<sup>][Lammle]

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
### `winver`

### `wmic`
Recover Windows product key [<sup>ref</sup>][https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]
```cmd
wmic path softwarelicensingservice get OA3xOriginalProductKey
```
Recover serial number of a Lenovo laptop [<sup>ref</sup>][https://pcsupport.lenovo.com/us/en/solutions/find-product-name]
```cmd
wmic bios get serialnumber
```
Display BIOS version
```cmd
wmic bios get biosversion
```
Display information about installed RAM
```cmd
wmic memorychip list full
```

#### FancyZones
[Tutorial](https://www.youtube.com/watch?v=rTtGzZYAXgY) [Web](https://insider.windows.com/en-us/articles/announcing-the-first-preview-and-code-release-of-powertoys/) [GitHub](https://github.com/microsoft/PowerToys/tree/master/src/modules/fancyzones)

#### UWP
UWP apps **adaptively** adjust UI elements to fit all Windows 10 devices. The **Fluent Design System** provides guidelines to provide a consistent and beautiful appearance to UWP apps. [^](https://docs.microsoft.com/en-us/windows/uwp/design/basics/design-and-ui-intro "Microsoft Docs: \"Introduction to UWP app design\"") Interesting new applications are not being developed on UWP, which does not bode well for the future of Windows as a consumer desktop computer platform. [^](https://mspoweruser.com/uwp-is-dead-because-windows-apps-are-dead/ "mspoweruser.com: \"UWP is dead because Windows apps are dead\"")
