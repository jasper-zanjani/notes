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

<!-- Active Directory -->
[adfind]: #adfind '```&#10;adfind&#10;```&#10;Command-line utility that can be used to query Active Directory attributes&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 53'
[adprep]:         #adprep                         '```&#10;C:\>adprep&#10;```&#10;Prepare Active Directory for Windows Server upgrades&#10;Must be run on the Infrastructure Master role owner with the flag `/domainprep`.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 29'

<!-- `cmd` commands -->
[arp]:            #arp                            '```&#10;C:\>arp&#10;```&#10;Display and modify the IP-to-MAC address translation tables used by ARP'
[bcdedit]:        #bcdedit                        '```&#10;C:\>bcdedit&#10;```&#10;Boot configuration data editor'
[bootrec]:        #bootrec                        '```&#10;C:\>bootrec&#10;```&#10;Windows Recovery Environment command that repairs a system partition'
[cscript]:        #cscript                        '```&#10;C:\>cscript&#10;```&#10;Starts a script so that it runs in a command-line environment'
[diskpart]:       #diskpart                       '```&#10;C:\>diskpart&#10;```&#10;Text-mode command interpreter used to convert disk types, create partitions and volumes, and configure RAID&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 141'
[dism.exe]: #dism.exe '```&#10;C:\>dism.exe&#10;```&#10;"Deployment Image Servicing and Management", enables modification of VHD and Windows Imaging files while they are offline&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 70'
[hostname]:       #hostname                       '```&#10;C:\>hostname&#10;C:\>HOSTNAME.exe&#10;```&#10;Display computer name'
[ipconfig]:       #ipconfig                       '```&#10;C:\>ipconfig&#10;```&#10;Display TCP/IP configuration'
[logoff]:         #logoff                         '```&#10;C:\>logoff&#10;```&#10;Log out'
[msiexec]:        #msiexec                        '```&#10;C:\>msiexec&#10;```&#10;Provides the means to install, modify, and perform operations on Windows Installer from the command line'
[ms-settings:]: #settings '```&#10;ms-settings:&#10;```&#10;Special protocol which can be used to open Settings pages and other Modern apps which have well known URIs'
[nbtstat]:        #nbtstat                        '```&#10;C:\>nbtstat&#10;```&#10;Display status of NetBIOS'
[netsh]:          #netsh                          '```&#10;C:\>netsh&#10;```&#10;"Network services shell", command-line utility that allows you to manage the configuration of various network services on local and remote computers.&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 297'
[ntdsutil]:       #ntdsutil                       '```&#10;C:\>ntdsutil&#10;```&#10;Used to transfer FSMO roles between domain controllers'
[regsvr32]: #regsvr32 ''
[sfc]:            #sfc                            '```&#10;C:\>sfc&#10;C:\>sfc /scannow&#10;```&#10;Scan and verify protected system files&#10;Stanek, William R. _Microsoft Windows Command-Line_.: 373'
[slmgr]:          #slmgr                          '```&#10;C:\>slmgr&#10;```&#10;Windows software licensing management tool'
[systeminfo]:     #systeminfo                     '```&#10;C:\>systeminfo&#10;```&#10;Shows system information about the machine, including installed hotfixes and patches'
[winver]:         #winver                                             '```&#10;C:\>winver&#10;```&#10;Display the "About Windows" dialog box, including Windows version and build number'
[wmic]:           #wmic                           '```&#10;C:\>wmic&#10;```&#10;WMI command-line (WMIC) utility provides a command-line interface for WMI.'

<!-- Powershell commands -->
[Add-Computer]:                                      pwsh.md#add-computer                               '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Get-ChildItem]:                                     pwsh.md#get-childitem                              '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir&#10;PS C:\> gci&#10;PS C:\> ls&#10;```&#10;Get items in one or more locations'
[Get-ComputerInfo]: #get-computerinfo '```&#10;PS C:\> Get-ComputerInfo&#10;PS C:\> gin&#10;```&#10;Retrieve a consolidated object of system and operating system properties&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[Invoke-GPUpdate]:                                   pwsh.md#invoke-gpupdate                            '```&#10;Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'
[Write-Host]: #write-host '```&#10;PS C:\> Write-Host&#10;```&#10;Write customized output to a host (equivalent to `echo`).'

<!-- Linux commands -->
[grep]: https://github.com/jasper-zanjani/notes/blob/master/lx/commands/README.md#grep '```&#10;$ grep&#10;```&#10;Search `$FILES` for lines containing a match to regex `$PATTERN`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 126'
[lx echo]:                        #echo                                       '```&#10;$ echo&#10;```&#10;Write `$STRING` to STDOUT&#10;Robbins, Arnold. _Bash Pocket Reference_. O\'Reilly: 2016.: 88'

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

###### Concepts
**U** 
[UWP][UWP]

## Command Prompt
[`arp`][arp] 
[`bcdedit`][bcdedit] 
[`bootrec`][bootrec]
[`cscript`][cscript] 
`dir`<sup>[pwsh>][Get-ChildItem]</sup>
[`diskpart`][diskpart] 
[`echo`](#echo) <sup>[lx][lx echo] [pwsh][Write-Host]</sup>
`findstr`<sup>[lx][grep]</sup>
`gpupdate`<sup>[pwsh][Invoke-GPUpdate]</sup>
[`hostname`][hostname]<sup>[pwsh][Get-ComputerInfo]</sup>
[`ipconfig`][ipconfig]
[`logoff`][logoff]
[`ms-settings:`][ms-settings:]
[`nbtstat`][nbtstat] [`netsh`](#netsh) 
[`ntdsutil`][ntdsutil]
[`regsvr32`][regsvr32]
[`route`](#route)
[`sfc`][sfc] [`shutdown`](#shutdown) 
[`slmgr`][slmgr] 
[`systeminfo`][systeminfo]
[`tracert`](#tracert) 
[`traceroute`](#tracert)
[`winrm`](#winrm) 
[`winver`][winver]
[`wmic`][wmic]

###### Active Directory
[`adprep`][adprep] 
[`adfind`][adfind]
[`dsquery`][dsquery]

###### Control Panel
[`access`][access.cpl] 
[`appwiz`][appwiz.cpl] 
[`desk`][desk.cpl] 
[`findfast`][findfast.cpl] 
[`inetcpl`][inetcpl.cpl] 
[`intl`][intl.cpl] 
[`joy`][joy.cpl]
[`main`][main.cpl] 
[`mlcfg32`][mlcfg32.cpl] 
[`mmsys`][mmsys.cpl]
[`ncpa`][ncpa.cpl]
[`sysdm`][sysdm.cpl]
[`timedate`][timedate.cpl]
[`wgpocpl`][wgpocpl.cpl]

###### Variables
[USERPROFILE]: #variables '```&#10;C:\> echo %USERPROFILE%&#10;```&#10;Location of profile directory of current user (i.e. "C:\Users\jsmith")'
[USERNAME]: #variables '```&#10;C:\> echo %USERNAME%&#10;```&#10;Name of current user (i.e. "jsmith").'
[APPDATA]: #variables '```&#10;C:\> echo %APPDATA%&#10;```&#10;The file-system directory that serves as a common repository for application-specific data (i.e. "C:\Users\jsmith\AppData\Roaming").'
[LOCALAPPDATA]: #variables '```&#10;C:\> echo %LOCALAPPDATA%&#10;```&#10;The file-system directory that serves as a data repository for local, non-roaming applications (i.e. "C:\Users\jsmith\AppData\Local").'

[`USERPROFILE`][USERPROFILE] 
[`USERNAME`][USERNAME] 
[`APPDATA`][APPDATA] 
[`LOCALAPPDATA`][LOCALAPPDATA] 

###### `adfind`
Query the schema version associated with Active Directory <sup>[Desmond][Desmond2009]: 53</sup>
```cmd
adfind -schema -s base objectVersion
```

###### `adprep`
Prepare Active Directory for Windows Server upgrades. Must be run on the Infrastructure Master role owner with the flag `/domainprep`. <sup>[Desmond][Desmond2009]: 29</sup>
###### `arp`
<!-- `arp` options -->
[arp /&#97;]:                     #arp                           '```&#10;C:\>arp /a&#10;```&#10;Display both the IP and MAC addresses and whether they are dynamic or static entries '
[arp /&#115;]:                    #arp                           '```&#10;C:\>arp /s&#10;```&#10;Manually add a static entry to the cache'
[arp /&#100;]:                    #arp                           '```&#10;C:\>arp /d&#10;```&#10;Delete an entry from the cache'

<code>&nbsp;</code> [`a`][arp /&#97;] <code>&nbsp;</code> <code>&nbsp;</code> [`d`][arp /&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][arp /&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

###### `bcdedit`
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
###### `bootrec`
Windows Recovery Environment command that repairs a system partition

Use when boot sector not found
```cmd
bootrec /fixboot
```
Use when BCD file has been corrupted
```cmd
bootrec /rebuildbcd
```
###### `diskpart`
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

###### `dism.exe`
[dism.exe /Add-Driver]: #dism.exe '```&#10;C:\>dism.exe /Add-Driver&#10;```&#10;&#10;Equivalent to `Add-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Add-Package]: #dism.exe '```&#10;C:\>dism.exe /Add-Package&#10;```&#10;&#10;Equivalent to `Add-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Add-ProvisionedAppxPackage]: #dism.exe '```&#10;C:\>dism.exe /Add-ProvisionedAppxPackage&#10;```&#10;&#10;Equivalent to `Add-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Append-Image]: #dism.exe '```&#10;C:\>dism.exe /Append-Image&#10;```&#10;&#10;Equivalent to `Add-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Apply-Image]: #dism.exe '```&#10;C:\>dism.exe /Apply-Image&#10;```&#10;&#10;Equivalent to `Expand-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Apply-Unattend]: #dism.exe '```&#10;C:\>dism.exe /Apply-Unattend&#10;```&#10;&#10;Equivalent to `Apply-WindowsUnattend`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Capture-Image]: #dism.exe '```&#10;C:\>dism.exe /Capture-Image&#10;```&#10;&#10;Equivalent to `New-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Commit-Image]: #dism.exe '```&#10;C:\>dism.exe /Commit-Image&#10;```&#10;&#10;Equivalent to `Save-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Disable-Feature]: #dism.exe '```&#10;C:\>dism.exe /Disable-Feature&#10;```&#10;&#10;Equivalent to `Disable-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Enable-Feature]: #dism.exe '```&#10;C:\>dism.exe /Enable-Feature&#10;```&#10;&#10;Equivalent to `Enable-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Export-Driver]: #dism.exe '```&#10;C:\>dism.exe /Export-Driver&#10;```&#10;&#10;Equivalent to `Export-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Export-Image]: #dism.exe '```&#10;C:\>dism.exe /Export-Image&#10;```&#10;&#10;Equivalent to `Export-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Driverinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Driverinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsDriver -Driver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Drivers]: #dism.exe '```&#10;C:\>dism.exe /Get-Drivers&#10;```&#10;&#10;Equivalent to `Get-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Featureinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Featureinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsOptionalFeature -FeatureName`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Features]: #dism.exe '```&#10;C:\>dism.exe /Get-Features&#10;```&#10;&#10;Equivalent to `Get-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-ImageInfo]: #dism.exe '```&#10;C:\>dism.exe /Get-ImageInfo&#10;```&#10;&#10;Equivalent to `Get-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-MountedImageInfo]: #dism.exe '```&#10;C:\>dism.exe /Get-MountedImageInfo&#10;```&#10;&#10;Equivalent to `Get-WindowsImage -Mounted`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Packageinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Packageinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsPackage -PackagePath` or `Get-WindowsPackage -PackageName`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Packages]: #dism.exe '```&#10;C:\>dism.exe /Get-Packages&#10;```&#10;&#10;Equivalent to `Get-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-ProvisionedAppxPackages]: #dism.exe '```&#10;C:\>dism.exe /Get-ProvisionedAppxPackages&#10;```&#10;&#10;Equivalent to `Get-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /List-Image]: #dism.exe '```&#10;C:\>dism.exe /List-Image&#10;```&#10;&#10;Equivalent to `Get-WindowsImageontent`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remount-Image]: #dism.exe '```&#10;C:\>dism.exe /Remount-Image&#10;```&#10;&#10;Equivalent to `Mount-WindowsImage -Remount`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Driver]: #dism.exe '```&#10;C:\>dism.exe /Remove-Driver&#10;```&#10;&#10;Equivalent to `Remove-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Image]: #dism.exe '```&#10;C:\>dism.exe /Remove-Image&#10;```&#10;&#10;Equivalent to `Remove-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Package]: #dism.exe '```&#10;C:\>dism.exe /Remove-Package&#10;```&#10;&#10;Equivalent to `Remove-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-ProvisionedAppxPackage]: #dism.exe '```&#10;C:\>dism.exe /Remove-ProvisionedAppxPackage&#10;```&#10;&#10;Equivalent to `Remove-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Set-ProvisionedAppxDataFile]: #dism.exe '```&#10;C:\>dism.exe /Set-ProvisionedAppxDataFile&#10;```&#10;&#10;Equivalent to `Set-AppXProvisionedDataFile`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Unmount-Image]: #dism.exe '```&#10;C:\>dism.exe /Unmount-Image&#10;```&#10;&#10;Equivalent to `Dismount-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'

[`Add-Driver`][dism.exe /Add-Driver]
[`Add-Package`][dism.exe /Add-Package]
[`Add-ProvisionedAppxPackage`][dism.exe /Add-ProvisionedAppxPackage]
[`Append-Image`][dism.exe /Append-Image]
[`Apply-Image`][dism.exe /Apply-Image]
[`Apply-Unattend`][dism.exe /Apply-Unattend]
[`Capture-Image`][dism.exe /Capture-Image]
[`Commit-Image`][dism.exe /Commit-Image]
[`Disable-Feature`][dism.exe /Disable-Feature]
[`Enable-Feature`][dism.exe /Enable-Feature]
[`Export-Driver`][dism.exe /Export-Driver]
[`Export-Image`][dism.exe /Export-Image]
[`Get-Driverinfo`][dism.exe /Get-Driverinfo]
[`Get-Drivers`][dism.exe /Get-Drivers]
[`Get-Featureinfo`][dism.exe /Get-Featureinfo]
[`Get-Features`][dism.exe /Get-Features]
[`Get-ImageInfo`][dism.exe /Get-ImageInfo]
[`Get-MountedImageInfo`][dism.exe /Get-MountedImageInfo]
[`Get-Packageinfo`][dism.exe /Get-Packageinfo]
[`Get-Packages`][dism.exe /Get-Packages]
[`Get-ProvisionedAppxPackages`][dism.exe /Get-ProvisionedAppxPackages]
[`List-Image`][dism.exe /List-Image]
[`Remount-Image`][dism.exe /Remount-Image]
[`Remove-Driver`][dism.exe /Remove-Driver]
[`Remove-Image`][dism.exe /Remove-Image]
[`Remove-Package`][dism.exe /Remove-Package]
[`Remove-ProvisionedAppxPackage`][dism.exe /Remove-ProvisionedAppxPackage]
[`Set-ProvisionedAppxDataFile`][dism.exe /Set-ProvisionedAppxDataFile]
[`Unmount-Image`][dism.exe /Unmount-Image]


Mount an image <sup>[Zacker][Zacker]: 71</sup>
```cmd
dism /mount-image /imagefile:$FILENAME /index:$N /name:$IMAGENAME /mountdir:$PATH
```
Add a driver to an image file that you have already mounted <sup>[Zacker][Zacker]: 72</sup>
```cmd
dism /image:$FOLDERNAME /add-driver /driver:$DRIVERNAME /recurse
```
Commit changes and unmount the image <sup>[Zacker][Zacker]: 75</sup>
```cmd
dism /unmount-image /mountdir:c:\mount /commit
```
Determine exact name of Windows features that can be enabled and disabled <sup>[Zacker][Zacker]: 75</sup>
```cmd
dism /image:c:\mount /get-features
```
###### `dsquery`
Find the Active Directory Schema version from the command-line <sup>[nolabnoparty.com](https://nolabnoparty.com/en/finding-active-directory-schema-version/ "Finding the Active Directory schema version") [pwsh](https://github.com/jasper-zanjani/notes/tree/primary/70-740/pwsh.md#get-adobject "Get-ADObject")</sup>
```cmd
dsquery * cn=schema,cn=configuration,dc=domain,dc=com -scope base -attr objectVersion"
```

###### `ipconfig`
`all` `flushdns` `renew`

###### `msiexec`
<!-- `msiexec` commands -->
[msiexec /&#105;]:              #msiexec                       '```&#10;C:\>msiexec /i&#10;```&#10;Install or configure a product'
[msiexec /&#113;]:              #msiexec                       '```&#10;C:\>msiexec /q&#10;C:\>msiexec /qn&#10;```&#10;Set user interface level to "no UI"'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`i`][msiexec /&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`q`][msiexec /&#113;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [<sup>ref</sup>][https://docs.microsoft.com/en-us/windows/win32/msi/command-line-options]

###### `nbtstat`
<!-- `nbtstat` commands -->
[nbtstat /&#97;]:               #nbtstat                       '```&#10;C:\>nbtstat /a&#10;```&#10;Display NetBIOS name table of `$HOST` (NetBIOS name)'
[nbtstat /&#65;]:               #nbtstat                       '```&#10;C:\>nbtstat /A&#10;```&#10;Display NetBIOS name table of `$HOST` (IP address)'
[nbtstat /&#110;]:              #nbtstat                       '```&#10;C:\>nbtstat /n&#10;```&#10;Display local NetBIOS name table on Windows device'
[nbtstat /&#114;]:              #nbtstat                       '```&#10;C:\>nbtstat /r&#10;```&#10;Display NetBIOS resolution and registration statistics'
[nbtstat /&#82;]:               #nbtstat                       '```&#10;C:\>nbtstat /R&#10;```&#10;Purge NetBIOS name table cache and reload the `LMHOSTS` file into memory'
[nbtstat /&#83;]:               #nbtstat                       '```&#10;C:\>nbtstat /S&#10;```&#10;Display NetBIOS sessions table'
[nbtstat /&#115;]:              #nbtstat                       '```&#10;C:\>nbtstat /s&#10;```&#10;Display NetBIOS sessions table, attempting to resolve remote IP addresses to hostnames'

<code>&nbsp;</code>   [`a`][nbtstat /&#97;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`n`][nbtstat /&#110;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`r`][nbtstat /&#114;] [`s`][nbtstat /&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;[`A`][nbtstat /&#65;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`R`][nbtstat /&#82;] [`S`][nbtstat /&#83;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

###### `netdom`
Alternative to [`Add-Computer`][Add-Computer] PowerShell cmdlet [<sup>Zacker: 21</sup>][Zacker]

Rename a computer
```
netdom renamecomputer %computername% /newname: newcomputername
```
Join a computer to a domain
```
netdom join %computername% /domain: domainname /userd: username /password:*
```
###### `netsh`
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
###### `ntdsutil`
Used to transfer [FSMO](# "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles between domain controllers. [<sup>Desmond: 30</sup>][Desmond2009]

###### `regsvr32`
Register a DLL dependency in order to enable the Active Directory Schema MMC snap-in on a DC <sup>[Desmond][Desmond2009]: 54</sup>
```cmd
regsvr32 schmmgmt.dll
```

###### `route`
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
###### Settings
[ms-settings:about]: #settings '```&#10;ms-settings:about&#10;```&#10;Open About page in Settings on Windows 10'
[ms-settings:activation]: #settings '```&#10;ms-settings:activation&#10;```&#10;Open Activation page in Settings on Windows 10'
[ms-settings:apps-volume]: #settings '```&#10;ms-settings:apps-volume&#10;```&#10;Open App volume and device preferences page in Settings on Windows 10'
[ms-settings:appsfeatures]: #settings '```&#10;ms-settings:appsfeatures&#10;```&#10;Open Apps & Features page in Settings on Windows 10'
[ms-settings:appsforwebsites]: #settings '```&#10;ms-settings:appsforwebsites&#10;```&#10;Open Apps for websites page in Settings on Windows 10'
[ms-settings:assignedaccess]: #settings '```&#10;ms-settings:assignedaccess&#10;```&#10;Open Set up a kiosk page in Settings on Windows 10'
[ms-settings:autoplay]: #settings '```&#10;ms-settings:autoplay&#10;```&#10;Open AutoPlay page in Settings on Windows 10'
[ms-settings:backup]: #settings '```&#10;ms-settings:backup&#10;```&#10;Open Backup page in Settings on Windows 10'
[ms-settings:batterysaver]: #settings '```&#10;ms-settings:batterysaver&#10;```&#10;Open Battery Saver page in Settings on Windows 10'
[ms-settings:bluetooth]: #settings '```&#10;ms-settings:bluetooth&#10;```&#10;Open Bluetooth page in Settings on Windows 10'
[ms-settings:camera]: #settings '```&#10;ms-settings:camera&#10;```&#10;Open Default camera page in Settings on Windows 10'
[ms-settings:clipboard]: #settings '```&#10;ms-settings:clipboard&#10;```&#10;Open Clipboard page in Settings on Windows 10'
[ms-settings:colors]: #settings '```&#10;ms-settings:colors&#10;```&#10;Open Colors page in Settings on Windows 10'
[ms-settings:connecteddevices]: #settings '```&#10;ms-settings:connecteddevices&#10;```&#10;Open Connected devices page in Settings on Windows 10'
[ms-settings:cortana]: #settings '```&#10;ms-settings:cortana&#10;```&#10;Open Talk to Cortana page in Settings on Windows 10'
[ms-settings:crossdevice]: #settings '```&#10;ms-settings:crossdevice&#10;```&#10;Open Shared experiences page in Settings on Windows 10'
[ms-settings:datausage]: #settings '```&#10;ms-settings:datausage&#10;```&#10;Open Data usage page in Settings on Windows 10'
[ms-settings:dateandtime]: #settings '```&#10;ms-settings:dateandtime&#10;```&#10;Open Date & time page in Settings on Windows 10'
[ms-settings:defaultapps]: #settings '```&#10;ms-settings:defaultapps&#10;```&#10;Open Default apps page in Settings on Windows 10'
[ms-settings:delivery-optimization]: #settings '```&#10;ms-settings:delivery-optimization&#10;```&#10;Open Delivery Optimization page in Settings on Windows 10'
[ms-settings:developers]: #settings '```&#10;ms-settings:developers&#10;```&#10;Open For developers page in Settings on Windows 10'
[ms-settings:deviceencryption]: #settings '```&#10;ms-settings:deviceencryption&#10;```&#10;Open Encryption page in Settings on Windows 10'
[ms-settings:devices-touchpad]: #settings '```&#10;ms-settings:devices-touchpad&#10;```&#10;Open Touchpad page in Settings on Windows 10'
[ms-settings:display]: #settings '```&#10;ms-settings:display&#10;```&#10;Open Display page in Settings on Windows 10'
[ms-settings:easeofaccess-display]: #settings '```&#10;ms-settings:easeofaccess-display&#10;```&#10;Open Display page in Settings on Windows 10'
[ms-settings:emailandaccounts]: #settings '```&#10;ms-settings:emailandaccounts&#10;```&#10;Open Email & app accounts page in Settings on Windows 10'
[ms-settings:findmydevice]: #settings '```&#10;ms-settings:findmydevice&#10;```&#10;Open Find My Device page in Settings on Windows 10'
[ms-settings:fonts]: #settings '```&#10;ms-settings:fonts&#10;```&#10;Open Fonts page in Settings on Windows 10'
[ms-settings:keyboard]: #settings '```&#10;ms-settings:keyboard&#10;```&#10;Open Language page in Settings on Windows 10'
[ms-settings:lockscreen]: #settings '```&#10;ms-settings:lockscreen&#10;```&#10;Open Lockscreen page in Settings on Windows 10'
[ms-settings:maps]: #settings '```&#10;ms-settings:maps&#10;```&#10;Open Offline maps page in Settings on Windows 10'
[ms-settings:messaging]: #settings '```&#10;ms-settings:messaging&#10;```&#10;Open Messaging page in Settings on Windows 10'
[ms-settings:mobile-devices]: #settings '```&#10;ms-settings:mobile-devices&#10;```&#10;Open Your phone page in Settings on Windows 10'
[ms-settings:mousetouchpad]: #settings '```&#10;ms-settings:mousetouchpad&#10;```&#10;Open Mouse & touchpad page in Settings on Windows 10'
[ms-settings:multitasking]: #settings '```&#10;ms-settings:multitasking&#10;```&#10;Open Multitasking page in Settings on Windows 10'
[ms-settings:network]: #settings '```&#10;ms-settings:network&#10;```&#10;Open Status page in Settings on Windows 10'
[ms-settings:network-wifi]: #settings '```&#10;ms-settings:network-wifi&#10;```&#10;Open Wi-Fi page in Settings on Windows 10'
[ms-settings:nfctransactions]: #settings '```&#10;ms-settings:nfctransactions&#10;```&#10;Open NFC page in Settings on Windows 10'
[ms-settings:nightlight]: #settings '```&#10;ms-settings:nightlight&#10;```&#10;Open Night light settings page in Settings on Windows 10'
[ms-settings:notifications]: #settings '```&#10;ms-settings:notifications&#10;```&#10;Open Notifications & actions page in Settings on Windows 10'
[ms-settings:optionalfeatures]: #settings '```&#10;ms-settings:optionalfeatures&#10;```&#10;Open Optional features page in Settings on Windows 10'
[ms-settings:otherusers]: #settings '```&#10;ms-settings:otherusers&#10;```&#10;Open Family & other people page in Settings on Windows 10'
[ms-settings:pen]: #settings '```&#10;ms-settings:pen&#10;```&#10;Open Pen & Windows Ink page in Settings on Windows 10'
[ms-settings:personalization]: #settings '```&#10;ms-settings:personalization&#10;```&#10;Open Personalization (category) page in Settings on Windows 10'
[ms-settings:personalization-background]: #settings '```&#10;ms-settings:personalization-background&#10;```&#10;Open Background page in Settings on Windows 10'
[ms-settings:personalization-colors]: #settings '```&#10;ms-settings:personalization-colors&#10;```&#10;Open Colors page in Settings on Windows 10'
[ms-settings:personalization-start]: #settings '```&#10;ms-settings:personalization-start&#10;```&#10;Open Start page in Settings on Windows 10'
[ms-settings:personalization-start-places]: #settings '```&#10;ms-settings:personalization-start-places&#10;```&#10;Open Choose which folders appear on Start page in Settings on Windows 10'
[ms-settings:phone]: #settings '```&#10;ms-settings:phone&#10;```&#10;Open Phone page in Settings on Windows 10'
[ms-settings:powersleep]: #settings '```&#10;ms-settings:powersleep&#10;```&#10;Open Power & sleep page in Settings on Windows 10'
[ms-settings:printers]: #settings '```&#10;ms-settings:printers&#10;```&#10;Open Printers & scanners page in Settings on Windows 10'
[ms-settings:privacy]: #settings '```&#10;ms-settings:privacy&#10;```&#10;Open Privacy page in Settings on Windows 10'
[ms-settings:project]: #settings '```&#10;ms-settings:project&#10;```&#10;Open Projecting to this PC page in Settings on Windows 10'
[ms-settings:proximity]: #settings '```&#10;ms-settings:proximity&#10;```&#10;Open Proximity page in Settings on Windows 10'
[ms-settings:quiethours]: #settings '```&#10;ms-settings:quiethours&#10;```&#10;Open Focus assist page in Settings on Windows 10'
[ms-settings:quietmomentsgame]: #settings '```&#10;ms-settings:quietmomentsgame&#10;```&#10;Open Playing a game full screen page in Settings on Windows 10'
[ms-settings:quietmomentspresentation]: #settings '```&#10;ms-settings:quietmomentspresentation&#10;```&#10;Open Duplicating my display page in Settings on Windows 10'
[ms-settings:quietmomentsscheduled]: #settings '```&#10;ms-settings:quietmomentsscheduled&#10;```&#10;Open During these hours page in Settings on Windows 10'
[ms-settings:recovery]: #settings '```&#10;ms-settings:recovery&#10;```&#10;Open Recovery page in Settings on Windows 10'
[ms-settings:regionformatting]: #settings '```&#10;ms-settings:regionformatting&#10;```&#10;Open Region page in Settings on Windows 10'
[ms-settings:regionlanguage]: #settings '```&#10;ms-settings:regionlanguage&#10;```&#10;Open Region & language page in Settings on Windows 10'
[ms-settings:remotedesktop]: #settings '```&#10;ms-settings:remotedesktop&#10;```&#10;Open Remote Desktop page in Settings on Windows 10'
[ms-settings:savelocations]: #settings '```&#10;ms-settings:savelocations&#10;```&#10;Open Default Save Locations page in Settings on Windows 10'
[ms-settings:screenrotation]: #settings '```&#10;ms-settings:screenrotation&#10;```&#10;Open Display page in Settings on Windows 10'
[ms-settings:signinoptions]: #settings '```&#10;ms-settings:signinoptions&#10;```&#10;Open Sign-in options page in Settings on Windows 10'
[ms-settings:signinoptions-launchfaceenrollment]: #settings '```&#10;ms-settings:signinoptions-launchfaceenrollment&#10;```&#10;Open Windows Hello setup page in Settings on Windows 10'
[ms-settings:sound]: #settings '```&#10;ms-settings:sound&#10;```&#10;Open Sound page in Settings on Windows 10'
[ms-settings:speech]: #settings '```&#10;ms-settings:speech&#10;```&#10;Open Speech page in Settings on Windows 10'
[ms-settings:speech]: #settings '```&#10;ms-settings:speech&#10;```&#10;Open Speech page in Settings on Windows 10'
[ms-settings:startupapps]: #settings '```&#10;ms-settings:startupapps&#10;```&#10;Open Startup apps page in Settings on Windows 10'
[ms-settings:storagepolicies]: #settings '```&#10;ms-settings:storagepolicies&#10;```&#10;Open Storage Sense page in Settings on Windows 10'
[ms-settings:storagesense]: #settings '```&#10;ms-settings:storagesense&#10;```&#10;Open Storage Sense page in Settings on Windows 10'
[ms-settings:surfacehub-accounts]: #settings '```&#10;ms-settings:surfacehub-accounts&#10;```&#10;Open Accounts page in Settings on Windows 10'
[ms-settings:surfacehub-calling]: #settings '```&#10;ms-settings:surfacehub-calling&#10;```&#10;Open Team Conferencing page in Settings on Windows 10'
[ms-settings:surfacehub-devicemanagenent]: #settings '```&#10;ms-settings:surfacehub-devicemanagenent&#10;```&#10;Open Team device management page in Settings on Windows 10'
[ms-settings:surfacehub-sessioncleanup]: #settings '```&#10;ms-settings:surfacehub-sessioncleanup&#10;```&#10;Open Session cleanup page in Settings on Windows 10'
[ms-settings:surfacehub-welcome]: #settings '```&#10;ms-settings:surfacehub-welcome&#10;```&#10;Open Welcome screen page in Settings on Windows 10'
[ms-settings:sync]: #settings '```&#10;ms-settings:sync&#10;```&#10;Open Sync your settings page in Settings on Windows 10'
[ms-settings:tabletmode]: #settings '```&#10;ms-settings:tabletmode&#10;```&#10;Open Tablet mode page in Settings on Windows 10'
[ms-settings:taskbar]: #settings '```&#10;ms-settings:taskbar&#10;```&#10;Open Taskbar page in Settings on Windows 10'
[ms-settings:themes]: #settings '```&#10;ms-settings:themes&#10;```&#10;Open Themes page in Settings on Windows 10'
[ms-settings:troubleshoot]: #settings '```&#10;ms-settings:troubleshoot&#10;```&#10;Open Troubleshoot page in Settings on Windows 10'
[ms-settings:typing]: #settings '```&#10;ms-settings:typing&#10;```&#10;Open Typing page in Settings on Windows 10'
[ms-settings:usb]: #settings '```&#10;ms-settings:usb&#10;```&#10;Open USB page in Settings on Windows 10'
[ms-settings:videoplayback]: #settings '```&#10;ms-settings:videoplayback&#10;```&#10;Open Video playback page in Settings on Windows 10'
[ms-settings:wheel]: #settings '```&#10;ms-settings:wheel&#10;```&#10;Open Wheel page in Settings on Windows 10'
[ms-settings:windowsdefender]: #settings '```&#10;ms-settings:windowsdefender&#10;```&#10;Open Windows Security page in Settings on Windows 10'
[ms-settings:windowsinsider]: #settings '```&#10;ms-settings:windowsinsider&#10;```&#10;Open Windows Insider Program page in Settings on Windows 10'
[ms-settings:windowsupdate]: #settings '```&#10;ms-settings:windowsupdate&#10;```&#10;Open Windows Update page in Settings on Windows 10'
[ms-settings:workplace]: #settings '```&#10;ms-settings:workplace&#10;```&#10;Open Access work or school page in Settings on Windows 10'
[ms-settings:yourinfo]: #settings '```&#10;ms-settings:yourinfo&#10;```&#10;Open Your info page in Settings on Windows 10'


[`about`][ms-settings:about]
[`activation`][ms-settings:activation]
[`apps-volume`][ms-settings:apps-volume]
[`appsfeatures`][ms-settings:appsfeatures]
[`appsforwebsites`][ms-settings:appsforwebsites]
[`assignedaccess`][ms-settings:assignedaccess]
[`autoplay`][ms-settings:autoplay]
[`backup`][ms-settings:backup]
[`batterysaver`][ms-settings:batterysaver]
[`bluetooth`][ms-settings:bluetooth]
[`camera`][ms-settings:camera]
[`clipboard`][ms-settings:clipboard]
[`colors`][ms-settings:colors]
[`connecteddevices`][ms-settings:connecteddevices]
[`cortana`][ms-settings:cortana]
[`crossdevice`][ms-settings:crossdevice]
[`datausage`][ms-settings:datausage]
[`dateandtime`][ms-settings:dateandtime]
[`defaultapps`][ms-settings:defaultapps]
[`delivery-optimization`][ms-settings:delivery-optimization]
[`developers`][ms-settings:developers]
[`deviceencryption`][ms-settings:deviceencryption]
[`devices-touchpad`][ms-settings:devices-touchpad]
[`display`][ms-settings:display]
[`easeofaccess-display`][ms-settings:easeofaccess-display]
[`emailandaccounts`][ms-settings:emailandaccounts]
[`findmydevice`][ms-settings:findmydevice]
[`fonts`][ms-settings:fonts]
[`keyboard`][ms-settings:keyboard]
[`lockscreen`][ms-settings:lockscreen]
[`maps`][ms-settings:maps]
[`messaging`][ms-settings:messaging]
[`mobile-devices`][ms-settings:mobile-devices]
[`mousetouchpad`][ms-settings:mousetouchpad]
[`multitasking`][ms-settings:multitasking]
[`network`][ms-settings:network]
[`network-wifi`][ms-settings:network-wifi]
[`nfctransactions`][ms-settings:nfctransactions]
[`nightlight`][ms-settings:nightlight]
[`notifications`][ms-settings:notifications]
[`optionalfeatures`][ms-settings:optionalfeatures]
[`otherusers`][ms-settings:otherusers]
[`pen`][ms-settings:pen]
[`personalization`][ms-settings:personalization]
[`personalization-background`][ms-settings:personalization-background]
[`personalization-colors`][ms-settings:personalization-colors]
[`personalization-start`][ms-settings:personalization-start]
[`personalization-start-places`][ms-settings:personalization-start-places]
[`phone`][ms-settings:phone]
[`powersleep`][ms-settings:powersleep]
[`printers`][ms-settings:printers]
[`privacy`][ms-settings:privacy]
[`project`][ms-settings:project]
[`proximity`][ms-settings:proximity]
[`quiethours`][ms-settings:quiethours]
[`quietmomentsgame`][ms-settings:quietmomentsgame]
[`quietmomentspresentation`][ms-settings:quietmomentspresentation]
[`quietmomentsscheduled`][ms-settings:quietmomentsscheduled]
[`recovery`][ms-settings:recovery]
[`regionformatting`][ms-settings:regionformatting]
[`regionlanguage`][ms-settings:regionlanguage]
[`remotedesktop`][ms-settings:remotedesktop]
[`savelocations`][ms-settings:savelocations]
[`screenrotation`][ms-settings:screenrotation]
[`signinoptions`][ms-settings:signinoptions]
[`signinoptions-launchfaceenrollment`][ms-settings:signinoptions-launchfaceenrollment]
[`sound`][ms-settings:sound]
[`speech`][ms-settings:speech]
[`speech`][ms-settings:speech]
[`startupapps`][ms-settings:startupapps]
[`storagepolicies`][ms-settings:storagepolicies]
[`storagesense`][ms-settings:storagesense]
[`surfacehub-accounts`][ms-settings:surfacehub-accounts]
[`surfacehub-calling`][ms-settings:surfacehub-calling]
[`surfacehub-devicemanagenent`][ms-settings:surfacehub-devicemanagenent]
[`surfacehub-sessioncleanup`][ms-settings:surfacehub-sessioncleanup]
[`surfacehub-welcome`][ms-settings:surfacehub-welcome]
[`sync`][ms-settings:sync]
[`tabletmode`][ms-settings:tabletmode]
[`taskbar`][ms-settings:taskbar]
[`themes`][ms-settings:themes]
[`troubleshoot`][ms-settings:troubleshoot]
[`typing`][ms-settings:typing]
[`usb`][ms-settings:usb]
[`videoplayback`][ms-settings:videoplayback]
[`wheel`][ms-settings:wheel]
[`windowsdefender`][ms-settings:windowsdefender]
[`windowsinsider`][ms-settings:windowsinsider]
[`windowsupdate`][ms-settings:windowsupdate]
[`workplace`][ms-settings:workplace]
[`yourinfo`][ms-settings:yourinfo]

###### `sfc`
<!-- `sfc` commands -->
[sfc /scannow]:                   #sfc                           '```&#10;C:\>sfc /scannow&#10;```&#10;Scan all protected system files, and replace corrupted files with a cached copy that is located in a compressed folder at %WinDir%\System32\dllcache'

[`scannow`][sfc /scannow]

###### `shutdown`
Immediate restart [<sup>Practice Lab</sup>][pl:Sec+]
```cmd
shutdown /r /t 0
```
###### `slmgr`
[slmgr /dli]:                     #slmgr                         '```&#10;C:\> slmgr /dli&#10;```&#10;Display very basic license and activation information about the current system in a dialog box'
[slmgr /dlv]:                     #slmgr                         '```&#10;C:\> slmgr /dlv&#10;```&#10;Display more detailed license information, including activation ID, installation ID, and other details'
[slmgr /xpr]:                     #slmgr                         '```&#10;C:\> slmgr /xpr&#10;```&#10;Display activation status or expiration date of current license'
[slmgr /upk]:                     #slmgr                         '```&#10;C:\> slmgr /upk&#10;```&#10;Remove the product key, placing Windows in an unactivated, unlicensed state (after restart)'
[slmgr /ipk]:                     #slmgr                         '```&#10;C:\> slmgr /ipk&#10;```&#10;Replace product key, equivalent to changing product key in Activation screen in Settings'
[slmgr /ato]:                     #slmgr                         '```&#10;C:\> slmgr /ato&#10;```&#10;Force Windows to attempt an online activation, either with Microsoft servers or with the KMS server on the local network'
[slmgr /rearm]:                   #slmgr                         '```&#10;C:\> slmgr /rearm&#10;```&#10;Reset activation timer to extend trial period. Each usage reduces the "rearm count" (ref. `/dlv`)'

[`ato`][slmgr /ato]
[`dli`][slmgr /dli]
[`dlv`][slmgr /dlv]
[`ipk`][slmgr /ipk]
[`rearm`][slmgr /rearm]
[`upk`][slmgr /upk]
[`xpr`][slmgr /xpr]

###### `tracert`
On Windows, this command is aliased to `traceroute` which is the Linux command. [<sup>Lammle: 112<sup>][Lammle]

Option  | Effect
:---    | :---
`-6`    | IPv6, aliased to `traceroute6`
###### `winrm`
List all WinRM listeners  
```cmd
winrm enumerate winrm/config/listener
```
Display WinRM configuration
```cmd
winrm get winrm/config
```
###### `winver`

###### `wmic`
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
