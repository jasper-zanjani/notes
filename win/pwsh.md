[3]: ../sources/az-103.md "Michael Washam, Jonathan Tuliani, and Scott Hoag. _Exam Ref AZ-103 Microsoft Azure Administrator_."
[4]: https://www.techrepublic.com/article/how-to-use-wget-to-download-web-based-packages-on-windows/#ftag=RSS56d97e7 "techrepublic.com - How to use Wget to download web-based packages on Windows."
[5]: http://www.powertheshell.com/topic/learnpowershell/firststeps/psversion/ "powertheshell.com - Check PowerShell Version"
[6]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-6 "Microsoft Docs - About Comparison Operators"
[7]: https://mathieubuisson.github.io/powershell-linux-bash/ "mathieubuisson.github.io - PowerShell equivalents for common Linux/bash commands"
[8]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_functions?view=powershell-6 "Microsoft Docs - About Functions"
[9]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/select-object?view=powershell-6 "Microsoft Docs - Select-Object"
[10]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_commonparameters?view=powershell-6 "Microsoft Docs - About CommonParameters"
[11]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_parameters_default_values?view=powershell-6 "Microsoft Docs - About Parameters Default Values"
[12]: https://mikefrobbins.com/2019/08/01/whats-in-your-powershell-psdefaultparametervalues-preference-variable/ "mikefrobbins.com - What's in your PowerShell `$PSDefaultParameterValues` Preference Variable?"
[13]: https://adamtheautomator.com/powershell-copy-to-clipboard/ "adamtheautomater.com - Using PowerShell to Copy to the Clipboard"
[14]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-6 "Microsoft Docs - About Automatic Variables"
[https://ridicurious.com/2019/07/29/3-ways-to-unzip-compressed-files-using-powershell/]: https://ridicurious.com/2019/07/29/3-ways-to-unzip-compressed-files-using-powershell/ "ridicurious.com - 3 ways to unzip compressed files using PowerShell"
[https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]: https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/ "SumTips.com - Manage disk partitions with Windows PowerShell"
[https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps '"Get-SmbOpenFile". _Microsoft Docs_.'
[https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps '"Close-SmbOpenFile". _Microsoft Docs_.'
[https://www.thewindowsclub.com/find-windows-product-key]:  https://www.thewindowsclub.com/find-windows-product-key "TheWindowsClub: \"How to find Windows Product Key using Command Prompt or PowerShell\""
[https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7]: https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7 "Working with Registry Entries"
[https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7]: https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7 "Working with Registry Keys"
[https://adamtheautomator.com/powershell-random-password/]: https://adamtheautomator.com/powershell-random-password/ "How to Generate a Random Password with PowerShell"
[https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]: https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/

[ADAC]:   https://github.com/jasper-zanjani/notes/master/sources/adac.md "Berkouwer, Sander. _Active Directory Administration Cookbook_."
[WSAC]:   https://github.com/jasper-zanjani/notes/master/sources/wsac.md "Krause, Jordan. _Windows Server 2016 Administration Cookbook_."
[IMWS]:   https://github.com/jasper-zanjani/notes/master/sources/imws.md "McCabe, John. _Introduction to Microsoft Windows Server 2016_."
[Zacker]: https://github.com/jasper-zanjani/notes/master/certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."
[Jones]:  https://subscription.packtpub.com/video/virtualization_and_cloud/9781789616385 "Jones, Joshua B. _Hands-On Powershell for Active Directory_. PacktPub: 2018."

<!-- Powershell automatic variables -->
[&#36;_]:                                            #variables                                            '```&#10;PS C:\> &#36;_&#10;PS C:\> $PSItem&#10;```&#10;Pipeline object'
[&#36;?]:                                            #variables                                            '```&#10;PS C:\> &#36;?&#10;```&#10;Execution status of the last operation'
[&#36;^]:                                            #variables                                            '```&#10;PS C:\> &#36;^&#10;```&#10;First token in the last line received by the session'
[&#36;&#36;]:                                        #variables                                        '```&#10;PS C:\> &#36;&#36;&#10;```&#10;Last token in the last line received by the session'
[$args]:                                             #variables                                    '```&#10;PS C:\> $args&#10;```&#10;Array of values for undeclared parameters passed to a function, script or script block'
[$HOME]:                                             #variables                                    '```&#10;PS C:\> $HOME&#10;```&#10;Full path of the home directory of the user'
[$IsLinux]:                                          #variables                                    '```&#10;PS C:\> $IsLinux&#10;```&#10;Contains `$True` if the current session is running on a Linux operating system'
[$IsMacOS]:                                          #variables                                    '```&#10;PS C:\> $IsMacOS&#10;```&#10;Contains `$True` if the current session is running on an OS X operating system'
[$IsWindows]:                                        #variables                                    '```&#10;PS C:\> $IsWindows&#10;```&#10;Contains `$True` if the current session is running on a Windows operating system'
[$PID]:                                              #variables                                    '```&#10;PS C:\> $PID&#10;```&#10;Contains process identifier (PID) of the process that is hosting the current PowerShell session'
[$PSCulture]:                                        #variables                                    '```&#10;PS C:\> $PSCulture&#10;```&#10;Name of the culture currently in use in the operating system'
[$PSVersionTable]:                                   #variables                                    '```&#10;PS C:\> $PSVersionTable&#10;```&#10;Read-only hash table that displays details about the version of PowerShell that is running in the current session'
[$PWD]:                                              #variables                                    '```&#10;PS C:\> $PWD&#10;```&#10;Path object that represents the full path of the current directory'

[Add-Computer]:                                      #add-computer                                 "`Add-Computer` &#10; Join a computer to a domain"
[Add-Content]:                                       #add-content                                  "`Add-Content`"
[Add-DhcpServerInDC]:                                #add-dhcpserverindc                           "`Add-DhcpServerInDC`"
[Add-DhcpServerv4Scope]:                             #add-dhcpserverv4scope                        "`Add-DhcpServerv4Scope` &#10; Add an IPv4 scope on the DHCP server service."
[Add-DistributionGroupMember]:                       #add-distributiongroupmember                  "`Add-DistributionGroupMember`&#10;Add a single recipient to distribution groups and mail-enabled security groups"
[Add-PSSnapin]:                                      #add-pssnapin                                 "`Add-PSSnapin` (alias: `asnp`) &#10; Load a given list of snap-ins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) either by name or via the pipeline - last supported in PowerShell 5.1"
[Add-Type]:                                          #add-type                                     '`Add-Type`&#10;Add a.NET Framework type (a class) to a Windows PowerShell session'
[Add-WindowsFeature]:                                #install-windowsfeature                       '`Add-WindowsFeature` (alias: `Install-WindowsFeature`)'
[Checkpoint-VM]:                                     #checkpoint-vm                                '`Checkpoint-VM`&#10;Creates a checkpoint of a virtual machine.'
[Clear-Host]:                                        #clear-host                                   "`Clear-Host`"
[Close-SmbOpenFile]:                                 #close-smbopenfile                            '`Close-SmbOpenFile`&#10;Close a file that is open by one of the clients of the SMB server&#10;"Close-SmbOpenFile". _Microsoft Docs_.'
[Compress-Archive]:                                  #compress-archive                             "`Compress-Archive`"
[Copy-Item]:                                         #copy-item                                    "`Copy-Item`"
[Disconnect-PSSession]:                              #disconnect-pssession                         "`Disconnect-PSSession` (alias: `dnsn`) &#10; Terminate a remote PowerShell session begun with `New-PSSession`"
[Enable-PSRemoting]:                                 #enable-psremoting                            "`Enable-PSRemoting` &#10; Allow remote PowerShell management"
[Enable-WindowsOptionalFeature]:                     #enable-windowsoptionalfeature                "`Enable-WindowsOptionalFeature` &#10; Enable or restore an optional feature in a Windows image"
[Enter-PSSession]:                                   #enter-pssession                              "`Enter-PSSession` (alias: `etsn`) &#10; Interact with the specified PowerShell session"
[Exit-PSSession]:                                    #exit-pssession                               "`Exit-PSSession` (alias: `exsn`) &#10; End an interactive session with a remote computer"
[Expand-Archive]:                                    #expand-archive                               "`Expand-Archive` &#10; Decompress archives"
[Export-Alias]:                                      #export-alias                                 "`Export-Alias` (alias: `epal`) &#10; Export information about currently defined aliases to a file."
[Export-CliXml]:                                     #export-clixml                                "`Export-CliXml` &#10; Serialize a PowerShell object as a Common Language Infrastructure (CLI) XML file"
[Export-Csv]:                                        #export-csv                                   "`Export-Csv` &#10; Export PowerShell objects to CSV"
[ForEach-Object]:                                    #filters                                      "`ForEach-Object` (alias: `%`, `foreach`) &#10; Perform an operation against each item in a collection of input objects."
[Format-List]:                                       #output-formatting                            "`Format-List` (alias: `fl`) &#10; Display output in list style"
[Format-Table]:                                      #output-formatting                            "`Format-Table` (alias: `ft`) &#10; Display output in table style"
[Format-Volume]:                                     #format-volume                                     '```&#10;PS C:\>Format-Volume&#10;```&#10;Formats one or more existing volumes or a new volume on an existing partition.&#10;The Format-Volume cmdlet formats one or more existing volumes, or a new volume on an existing partition. This cmdlet returns the object representing the volume that was just formatted, with all properties updated to reflect the format operation.'
[Get-Alias]:                                         #get-alias                                    "`Get-Alias` (alias `gal`) &#10; Display aliases"
[Get-ChildItem]:                                     #get-childitem                                '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir&#10;PS C:\> gci&#10;PS C:\> ls&#10;```&#10;Get items in one or more locations'
[Get-Clipboard]:                                     #get-clipboard                                "`Get-Clipboard` (alias: `gcb`) &#10; Display items in clipboard"
[Get-Command]:                                       #get-command                                  "`Get-Command` (alias: `gcm`) &#10; Display all installed commands, including aliases, applications, filters, functions, and scripts (alias: gcm)"
[Get-Content]:                                       #get-content                                  "`Get-Content` (alias: `cat`, `gc`, `type`)"
[Get-Credential]:                                    #credentials                                  "`Get-Credential`"
[Get-Disk]:                                          #get-disk                                     "`Get-Disk`"
[Get-DistributionGroupMember]:                       #get-distributiongroupmember                  "Get-DistributionGroupMember&#10;View members of distribution groups and mail-enabled security groups"
[Get-Help]:                                          #get-help                                     "`Get-Help` &#10; Display help file for cmdlets"
[Get-History]:                                       #get-history                                  "`Get-History` (alias: `ghy`, `h`, `history`) &#10; Display history of inputted commands for the current session"
[Get-Item]:                                          #get-item                                     "`Get-Item`"
[Get-Location]:                                      #get-location                                 "`Get-Location`"
[Get-Member]:                                        #get-member                                   "`Get-Member` (alias: `gm`) &#10; Display properties and methods of a PowerShell object"
[Get-Module]:                                        #get-module                                   "`Get-Module` (alias: `gmo`) &#10; Display currently loaded PowerShell modules"
[Get-NetAdapter]:                                    #get-netadapter                               "`Get-NetAdapter` &#10; Display available network interfaces"
[Get-NetFirewallRule]:                               #get-netfirewallrule                          "`Get-NetFirewallRule`"
[Get-PSDrive]:                                       #get-psdrive                                  "`Get-PSDrive` (alias: `gdr`) &#10; Display mapped drives"
[Get-PSReadlineOption]:                              #get-psreadlineoption                         "`Get-PSReadlineOption`"
[Get-PSSession]:                                     #get-pssession                                "`Get-PSSession` (alias: `gsn`) &#10; Get the Windows PowerShell sessions on local and remote computers"
[Get-PSSnapin]:                                      #get-pssnapin                                 "`Get-PSSnapin` (alias: `gsnp`) &#10; Display currently loaded snapins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) - last supported in PowerShell 5.1"
[Get-Partition]:                                     #get-partition                                "`Get-Partition`"
[Get-Process]:                                       #get-process                                  "`Get-Process` (alias: `gps`, `ps`) &#10; Display running processes"
[Get-Service]:                                       #get-service                                  "`Get-Service` (alias: `gsv`) &#10; Display services"
[Get-SmbOpenFile]:                                   #get-smbopenfile                              '`Get-SmbOpenFile`&#10;Retrieves basic information about the files that are open on behalf of the clients of the Server Message Block (SMB) server&#10;"Get-SmbOpenFile". _Microsoft Docs_.'
[Get-WMIObject]:                                     #get-wmiobject                                "`Get-WMIObject`"
[Get-WindowsFeature]:                                #get-windowsfeature                           "`Get-WindowsFeature`"
[Import-CliXml]:                                     #import-clixml                                "`Import-CliXml` &#10; Import a Common Language Infrastructure (CLI) XML file with data that represents Microsoft .NET Framework objects and create PowerShell objects from it"
[Import-Csv]:                                        #import-csv                                   "`Import-Csv` (alias: `ipcsv`) &#10; Import CSV files as PowerShell objects"
[Import-Module]:                                     #import-module                                "`Import-Module` (alias: `ipmo`) &#10; Manually import a module, rather than waiting for it to load dynamically when using one of its cmdlets"
[Install-Module]:                                    #install-module                               "`Install-Module`"
[Install-WindowsFeature]:                            #install-windowsfeature                       "`Install-WindowsFeature` (alias: `Add-WindowsFeature`) &#10; Install one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2"
[Invoke-GPUpdate]:                                   #invoke-gpupdate                              '```&#10;Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'
[Invoke-WebRequest]:                                 #invoke-webrequest                            "`Invoke-WebRequest`"
[New-Alias]:                                         #new-alias                                    "`New-Alias` (alias: `nal`) &#10; Create a new alias"
[New-Guid]:                                          #new-guid                                     "`New-Guid`"
[New-Item]:                                          #new-item                                     "`New-Item`"
[New-NetFirewallRule]:                               #new-netfirewallrule                          "`New-NetFirewallRule`"
[New-NetIpAddress]:                                  #new-netipaddress                             "`New-NetIpAddress` &#10; Manually configure network interface, if a DHCP server is unavailable"
[New-Object]:                                        #new-object                                   '```&#10;PS C:\> New-Object&#10;```&#10;Creates an instance of a Microsoft .NET Framework or COM object'
[New-PSSession]:                                     #new-pssession                                "`New-PSSession` (`nsn`) &#10; Start a new remote PowerShell session with a remote computer"
[New-Partition]:                                     #new-partition                                "`New-Partition`"
[New-SmbShare]:                                      #new-smbshare                                 "`New-SmbShare`"
[Out-Null]:                                          #out-null                                     "`Out-Null` &#10; Delete output instead of sending it down the pipeline"
[Remove-Item]:                                       #remove-item                                  "`Remove-Item` (alias: `rm`, `ri`, `rmdir`, `rd`, `del`)"
[Remove-Partition]:                                  #remove-partition                             "`Remove-Partition`"
[Rename-Computer]:                                   #rename-computer                              "`Rename-Computer`"
[Resolve-DNSName]:                                   #resolve-dnsname                              '`Resolve-DNSName`&#10;...&#10;MeasureUp Practice Lab: Security+'
[Restart-Computer]:                                  #restart-computer                             "`Restart-Computer`"
[Search-ADAccount]:                                  #search-adaccount                             "`Search-ADAccount`"
[Select-Object]:                                     #filters                                      "`Select-Object` (alias: `sc`&#10; Select object or object properties"
[Set-Alias]:                                         #set-alias                                    "`Set-Alias`"
[Set-Clipboard]:                                     #set-clipboard                                "`Set-Clipboard (alias: `scb`): &#10; Set the current Windows clipboard entry"
[Set-DhcpServerv4OptionValue]:                       #set-dhcpserverv4optionvalue                  "`Set-DhcpServerv4OptionValue`"
[Set-DnsClientServerAddress]:                        #set-dnsclientserveraddress                   "`Set-DnsClientServerAddress` &#10; Set DNS server addresses associated with the TCP/IP properties on an interface"
[Set-ExecutionPolicy]:                               #set-executionpolicy                          "`Set-ExecutionPolicy` &#10; Change user preference for the Windows PowerShell execution policy"
[Set-Location]:                                      #set-location                                 "`Set-Location` (alias: `cd`, `sl`, `chdir`) &#10; Set present working directory"
[Set-NetFirewallRule]:                               #set-netfirewallrule                          "`Set-NetFirewallRule`"
[Set-PSReadlineOption]:                              #set-psreadlineoption                         "`Set-PSReadlineOption`"
[Set-Service]:                                       #set-service                                       '```&#10;PS C:\> Set-Service&#10;```&#10;Starts, stops, and suspends a service, and changes its properties'
[Start-DscConfiguration]:                            #start-dscconfiguration                       "`Start-DscConfiguration` (alias: `sacfg`) &#10; Apply configuration to nodes"
[Start-Job]:                                         #start-job                                    "`Start-Job` (alias: `sajb`)"
[Start-Service]:                                     #start-service                                "`Start-Service` (alias: `sasv`) &#10; Start one or more stopped services"
[Stop-Computer]:                                     #stop-computer                                "`Stop-Computer`"
[Stop-Service]:                                      #stop-service                                 "```&#10;PS C:\> Stop-Service&#10;PS C:\> spsv&#10;```&#10;Stop one or more services"
[Update-DistributionGroupMember]:                    #update-distributiongroupmember               "`Update-DistributionGroupMember`&#10;Replace all members of distribution groups and mail-enabled security groups"
[Update-Help]:                                       #update-help                                  "`Update-Help` &#10; Download help files"
[Where-Object]:                                      #filters                                      "`Where-Object` (alias: `?`, `where`) &#10; Select objects from a collection based on their property values"
[Write-Host]:                                        #write-host                                   "`Write-Host`"
[Write-Output]:                                      #write-output                                 "`Write-Output` (alias: `echo`, `write`) &#10; Send the specified objects to the next command in the pipeline. If the command is the last command in the pipeline, the objects are displayed in the console."
[Measure-Object]:              #measure-object                 '```&#10;PS C:\> Measure-Object&#10;```&#10;Calculates the numeric properties of objects, and the characters, words, and lines in string objects, such as files of text.&#10;"Measure-Object". Microsoft Powershell documentation.'

<!-- Active Directory cmdlets -->
[Add-ADPrincipalGroupMembership]:                    #add-adprincipalgroupmembership               "`Add-ADPrincipalGroupMembership` &#10; Add a member to one or more Active Directory groups"
[New-ADOrganizationalUnit]:                          #new-adorganizationalunit                     "`New-ADOrganizationalUnit`"
[New-ADUser]:                                        #new-aduser                                   "`New-ADUser` &#10; Create a new Active Directory user"
[Install-ADDSDomainController]:                      #install-addsdomaincontroller                 '`Install-ADDSDomainController`&#10;Installs a new domain controller in an Active Directory domain'
[Install-ADDSDomain]:                                #install-addsdomain                           "`Install-ADDSDomain`"
[Install-ADDSForest]:                                #install-addsforest                           "`Install-ADDSForest`"
[Get-ADDSForest]:                                    #get-addsforest                               "`Get-ADDSForest`"
[Get-ADOrganizationalUnit]:                          #get-adorganizationalunit                     "`Get-ADOrganizationalUnit`"
[Get-ADPrincipalGroupMembership]:                    #get-adprincipalgroupmembership               "`Get-ADPrincipalGroupMembership` &#10; Get the Active Directory groups that have a specified user, computer, group, or service account"
[Get-ADUser]:                                        #get-aduser                                   "`Get-ADUser` &#10; Get one or more Active Directory Users"
[Set-ADAccountPassword]:                             #set-adaccountpassword                        "`Set-ADAccountPassword`"
[Set-ADObject]:                                      #set-adobject                                 "`Set-ADObject`"
[Set-ADOrganizationalUnit]:                          #set-adorganizationalunit                     "`Set-ADOrganizationalUnit`"
[Uninstall-ADDSDomainController]:                    #uninstall-addsdomaincontroller               "`Uninstall-ADDSDomainController`"
[Unlock-ADAccount]:                                  #unlock-adaccount                             "`Unlock-ADAccount`"
[Remove-ADOrganizationalUnit]:                       #remove-adorganizationalunit                  "`Remove-ADOrganizationalUnit`"

<!-- Network cmdlets -->
[Get-NetIpConfiguration]:                            #get-netipconfiguration                            '```&#10;PS C:\> Get-NetIpConfiguration&#10;PS C:\> gip&#10;```&#10;Produce output similar to `ipconfig`'

<!-- Hyper-V cmdlets -->
[Add-VMSwitch]:                                      # '`Add-VMSwitch`&#10;Adds a virtual switch to an Ethernet resource pool.'
[Compare-VM]:                                        #compare-vm                                   '`Compare-VM`&#10;Compares a virtual machine and a virtual machine host for compatibility, returning a compatibility report.'
[Debug-VM]:                                          #debug-vm                                     '`Debug-VM`&#10;Debugs a virtual machine.'
[Export-VM]:                                         #export-vm                                    '`Export-VM`&#10;Exports a virtual machine to disk.'
[Get-VMSwitch]:                                      # '`Get-VMSwitch`&#10;Gets virtual switches from one or more virtual Hyper-V hosts.'
[Get-VM]:                                            #get-vm                                       '`Get-VM`&#10;Gets the virtual machines from one or more Hyper-V hosts.'
[Import-VM]:                                         #import-vm                                    '`Import-VM`&#10;Imports a virtual machine from a file.'
[Measure-VM]:                                        #measure-vm                                   '`Measure-VM`&#10;Reports resource utilization data for one or more virtual machines.'
[Move-VM]:                                           #move-vm                                      '`Move-VM`&#10;Moves a virtual machine to a new Hyper-V host.'
[New-VMSwitch]:                                      # '`New-VMSwitch`&#10;Creates a new virtual switch on one or more virtual machine hosts.'
[New-VMSwitch]:                                      #new-vmswitch                                 "`New-VMSwitch`"
[New-VM]:                                            #new-vm                                       '`New-VM`&#10;Creates a new virtual machine.'
[Remove-VMSwitch]:                                   # '`Remove-VMSwitch`&#10;Deletes a virtual switch.'
[Remove-VM]:                                         #remove-vm                                    '`Remove-VM`&#10;Deletes a virtual machine.'
[Rename-VMSwitch]:                                   # '`Rename-VMSwitch`&#10;Renames a virtual switch.'
[Rename-VM]:                                         #rename-vm                                    '`Rename-VM`&#10;Renames a virtual machine.'
[Repair-VM]:                                         #repair-vm                                    '`Repair-VM`&#10;Repairs one or more virtual machines.'
[Restart-VM]:                                        #restart-vm                                   '`Restart-VM`&#10;Restarts a virtual machine.'
[Resume-VM]:                                         #resume-vm                                    '`Resume-VM`&#10;Resumes a suspended (paused) virtual machine.'
[Save-VM]:                                           #save-vm                                      '`Save-VM`&#10;Saves a virtual machine.'
[Set-VMFirmware]:                                    #set-vmfirmware                               "`Set-VMFirmware` &#10;  "
[Set-VMMemory]:                                      #set-vmmemory                                 "`Set-VMMemory`"
[Set-VMNetworkAdapter]:                              #set-vmnetworkadapter                         "`Set-VMNetworkAdapter`"
[Set-VMProcessor]:                                   #set-vmprocessor                              "`Set-VMProcessor`"
[Set-VMSwitch]:                                      # '`Set-VMSwitch`&#10;Configures a virtual switch.'
[Set-VM]:                                            #set-vm                                       '`Set-VM`&#10;Configures a virtual machine.'
[Start-VM]:                                          #start-vm                                     '`Start-VM`&#10;Starts a virtual machine.'
[Stop-VM]:                                           #stop-vm                                      '`Stop-VM`&#10;Shuts down, turns off, or saves a virtual machine.'
[Suspend-VM]:                                        #suspend-vm                                   '`Suspend-VM`&#10;Suspends, or pauses, a virtual machine.'

<!-- Windows Server Migration tools -->
[Export-SmigServerSetting]:    #export-smigserversetting       '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-SmigServerFeature]:       #get-smigserverfeature          '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Import-SmigServerSetting]:    #import-smigserversetting       '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Receive-SmigServerData]:      #receive-smigserverdata         '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Send-SmigServerData]:         #send-smigserverdata            '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'

# PowerShell

###### Tasks
[**Remove Registry keys**][Remove-Item] &bull;
[**Clear out `%temp%` folder**][Remove-Item] &bull;
[Generate password](#generate-password) &bull;
[Credentials](#credentials) &bull;
[Formatting output](#output-formatting) &bull;
[Hash tables](#hash-tables) &bull;
[Manipulating files](#file-manipulation) &bull;
[Text-to-speech](#text-to-speech) &bull;
[New domain controller](#new-domain-controller) &bull;
[Set new Registry keys](#registry) &bull;

###### Cmdlet verbs
[`a`](# "`Add-`") [`ap`](# "`Approve-`&#10;Confirms or agrees to the status of a resource or process.") 
[`as`](# "`Assert-`&#10;Affirms the state of a resource.") 
[`ba`](# "`Backup-`&#10;Stores data by replicating it.") 
[`bd`](# "`Build-`&#10;Creates an artifact (usually a binary or document) out of some set of input files (usually source code or declarative documents)") 
[`bl`](# "`Block-`&#10;Restricts access to a resource. This verb is paired with Unblock.") 
[`cc`](# "`Connect-`&#10;Creates a link between a source and a destination. This verb is paired with Disconnect.") 
[`cf`](# "`Convertfrom-`&#10;Converts one primary type of input (the cmdlet noun indicates the input) to one or more supported output types.") 
[`ch`](# "`Checkpoint-`&#10;Creates a snapshot of the current state of the data or of its configuration.") 
[`cm`](# "`Compress-`&#10;Compacts the data of a resource. Pairs with Expand.") 
[`cn`](# "`Confirm-`&#10;Acknowledges, verifies, or validates the state of a resource or process.") 
[`cp`](# "`Complete-`&#10;Concludes an operation.&#10;---&#10;`Copy-`&#10;Copies a resource to another name or to another container. For example, the Copy-Item cmdlet that is used to access stored data copies an item from one location in the data store to another location.") 
[`cr`](# "`Compare-`&#10;Evaluates the data from one resource against the data from another resource.") 
[`cs`](# "`Close-`") 
[`ct`](# "`Convertto-`&#10;Converts from one or more types of input to a primary output type (the cmdlet noun indicates the output type).") 
[`cv`](# "`Convert-`&#10;Changes the data from one representation to another when the cmdlet supports bidirectional conversion or when the cmdlet supports conversion between multiple data types.") 
[`d`](# "`Disable-`&#10;Configures a resource to an unavailable or inactive state. For example, the Disable-PSBreakpoint cmdlet makes a breakpoint inactive. This verb is paired with Enable.") 
[`db`](# "`Debug-`&#10;Examines a resource to diagnose operational problems.") 
[`dc`](# "`Disconnect-`&#10;Breaks the link between a source and a destination. This verb is paired with Connect.") 
[`dm`](# "`Dismount-`&#10;Detaches a named entity from a location. This verb is paired with Mount.") 
[`dn`](# "`Deny-`&#10;Refuses, objects, blocks, or opposes the state of a resource or process.") 
[`dp`](# "`Deploy-`&#10;Sends an application, website, or solution to a remote target[s] in such a way that a consumer of that solution can access it after deployment is complete") 
[`e`](# "`Enable-`&#10;Configures a resource to an available or active state. For example, the Enable-PSBreakpoint cmdlet makes a breakpoint active. This verb is paired with Disable.") 
[`ed`](# "`Edit-`&#10;Modifies existing data by adding or removing content.") 
[`en`](# "`Expand-`&#10;Restores the data of a resource that has been compressed to its original state. This verb is paired with Compress.") 
[`ep`](# "`Export-`&#10;Encapsulates the primary input into a persistent data store, such as a file, or into an interchange format. This verb is paired with Import.") 
[`et`](# "`Enter-`") 
[`ex`](# "`Exit-`") 
[`f`](# "`Format-`") 
[`g`](# "`g`") 
[`gp`](# "`Group-`&#10;Arranges or associates one or more resources.") 
[`gr`](# "`Grant-`&#10;Allows access to a resource. This verb is paired with Revoke.") 
[`h`](# "`Hide-`") 
[`i`](# "`Invoke-`&#10;Performs an action, such as running a command or a method.") 
[`in`](# "`Initialize-`&#10;Prepares a resource for use, and sets it to a default state.") 
[`ip`](# "`Import-`&#10;Creates a resource from data that is stored in a persistent data store (such as a file) or in an interchange format. For example, the Import-CSV cmdlet imports data from a comma-separated value (CSV) file to objects that can be used by other cmdlets. This verb is paired with Export.") 
[`is`](# "`Install-`&#10;Places a resource in a location, and optionally initializes it. This verb is paired with Uninstall.") 
[`j`](# "`Join-`") 
[`l`](# "`Limit-`&#10;Applies constraints to a resource.") 
[`lk`](# "`Lock-`") 
[`m`](# "`Move`") 
[`mg`](# "`Merge-`&#10;Creates a single resource from multiple resources.") 
[`ms`](# "`Measure-`&#10;Identifies resources that are consumed by a specified operation, or retrieves statistics about a resource.") 
[`mt`](# "`Mount-`&#10;Attaches a named entity to a location. This verb is paired with Dismount.") 
[`n`](# "`New-`&#10;Creates a resource. (The `Set-` verb can also be used when creating a resource that includes data, such as the `Set-Variable` cmdlet.)") 
[`o`](# "`Out-`&#10;Sends data out of the environment. For example, the Out-Printer cmdlet sends data to a printer.") 
[`op`](# "`Open-`") 
[`om`](# "`Optimize-`") 
[`pb`](# "`Publish-`&#10;Makes a resource available to others. This verb is paired with Unpublish.") 
[`pi`](# "`Ping-`&#10;Use the Test verb.") 
[`pop`](# "`Pop-`") 
[`pt`](# "`Protect-`&#10;Safeguards a resource from attack or loss. This verb is paired with Unprotect.") 
[`pu`](# "`Push-`") 
[`r`](# "`Remove-`") 
[`rc`](# "`Receive-`&#10;Accepts information sent from a source. This verb is paired with Send.") 
[`rd`](# "`Read-`&#10;Acquires information from a source. This verb is paired with Write.") 
[`re`](# "`Redo-`") 
[`rg`](# "`Register-`&#10;Creates an entry for a resource in a repository such as a database. This verb is paired with Unregister.") 
[`rk`](# "`Revoke-`&#10;Specifies an action that does not allow access to a resource. This verb is paired with Grant.") 
[`rn`](# "`Rename-`") 
[`rp`](# "`Repair-`&#10;Restores a resource to a usable condition") 
[`rq`](# "`Request-`&#10;Asks for a resource or asks for permissions.") 
[`rr`](# "`Restore-`&#10;Sets a resource to a predefined state, such as a state set by Checkpoint. For example, the Restore-Computer cmdlet starts a system restore on the local computer.") 
[`rs`](# "`Reset`") 
[`rt`](# "`Restart-`&#10;Stops an operation and then starts it again. For example, the Restart-Service cmdlet stops and then starts a service.") 
[`ru`](# "`Resume-`&#10;Starts an operation that has been suspended. For example, the Resume-Service cmdlet starts a service that has been suspended. This verb is paired with Suspend.") 
[`rv`](# "`Resolve-`&#10;Maps a shorthand representation of a resource to a more complete representation.")
[`s`](# "`Set-`") 
[`sa`](# "`Start-`&#10;Initiates an operation. For example, the Start-Service cmdlet starts a service. This verb is paired with Stop.") 
[`sb`](# "`Submit-`&#10;Presents a resource for approval.") 
[`sc`](# "`Select-`") 
[`sd`](# "`Send-`&#10;Delivers information to a destination. This verb is paired with Receive.") 
[`sh`](# "`Show-`") 
[`sk`](# "`Skip-`") 
[`sl`](# "`Split-`") 
[`sp`](# "`Stop-`&#10;Discontinues an activity. This verb is paired with Start.") 
[`sr`](# "`Search-`") 
[`ss`](# "`Suspend-`&#10;Pauses an activity. For example, the Suspend-Service cmdlet pauses a service. This verb is paired with Resume.") 
[`st`](# "`Step-`") 
[`sv`](# "`Save-`&#10;Preserves data to avoid loss.") 
[`sw`](# "`Switch-`") 
[`sy`](# "`Sync-`&#10;Assures that two or more resources are in the same state.") 
[`t`](# "`Test-`&#10;Verifies the operation or consistency of a resource.") 
[`tr`](# "`Trace-`&#10;Tracks the activities of a resource.") 
[`u`](# "`Use-`&#10;Uses or includes a resource to do something.") 
[`ub`](# "`Unpublish-`&#10;Makes a resource unavailable to others. This verb is paired with Publish.") 
[`ud`](# "`Update-`&#10;Brings a resource up-to-date to maintain its state, accuracy, conformance, or compliance. For example, the Update-FormatData cmdlet updates and adds formatting files to the current PowerShell console.") 
[`uk`](# "`Unlock-`") 
[`ul`](# "`Unblock-`&#10;Removes restrictions to a resource. This verb is paired with Block.") [`un`](# "`Undo-`") 
[`up`](# "`Unprotect-`&#10;Removes safeguards from a resource that were added to prevent it from attack or loss. This verb is paired with Protect.") 
[`ur`](# "`Unregister-`&#10;Removes the entry for a resource from a repository. This verb is paired with Register.") 
[`us`](# "`Uninstall-`&#10;Removes a resource from an indicated location. This verb is paired with Install.")
[`w`](# "`Wait-`&#10;Pauses an operation until a specified event occurs. For example, the Wait-Job cmdlet pauses operations until one or more of the background jobs are complete.") 
[`wc`](# "`Watch-`") 
[`wr`](# "`Write-`&#10;Adds information to a target. This verb is paired with Read.") 

###### Cmdlets
**A**  `Alias`&nbsp;[`ep`][Export-Alias]&nbsp;[`g`][Get-Alias]&nbsp;[`n`][New-Alias]&nbsp;[`s`][Set-Alias]&nbsp; `Archive`&nbsp;[`cm`][Compress-Archive]&nbsp;[`en`][Expand-Archive] `ADAccount`&nbsp;[`sr`][Search-ADAccount]&nbsp;[`uk`][Unlock-ADAccount]&nbsp; `ADAccountPassword`&nbsp;[`s`][Set-ADAccountPassword]&nbsp; `ADDSDomain`&nbsp;[`is`][Install-ADDSDomain]&nbsp; `ADDSDomainController`&nbsp;[`is`][Install-ADDSDomainController]&nbsp;[`us`][Uninstall-ADDSDomainController]&nbsp; `ADDSForest`&nbsp;[`g`][Get-ADDSForest]&nbsp;[`is`][Install-ADDSForest]&nbsp; `ADObject` [`s`][Set-ADObject]&nbsp; `ADOrganizationalUnit`&nbsp;[`g`][Get-ADOrganizationalUnit]&nbsp;[`n`][New-ADOrganizationalUnit]&nbsp;[`r`][Remove-ADOrganizationalUnit]&nbsp;[`s`][Set-ADOrganizationalUnit]&nbsp; `ADPrincipalGroupMembership`&nbsp;[`a`][Add-ADPrincipalGroupMembership]&nbsp;[`g`][Get-ADPrincipalGroupMembership]&nbsp; `ADUser`&nbsp;[`g`][Get-ADUser]&nbsp;[`n`][New-ADUser] 
**C** `ChildItem`&nbsp;[`g`][Get-ChildItem]&nbsp; `Clipboard`&nbsp;[`g`][Get-Clipboard]&nbsp;[`s`][Set-Clipboard]&nbsp; `Computer`&nbsp;[`a`][Add-Computer]&nbsp;[`rn`][Rename-Computer]&nbsp;[`rt`][Restart-Computer]&nbsp;[`sp`][Stop-Computer]&nbsp; `Content`&nbsp;[`a`][Add-Content]&nbsp; `Credential` [`g`][Get-Credential]  `Csv` [`ep`][Export-Csv] [`ip`][Import-Csv] **D** `Disk` [`g`][Get-Disk] `DistributionGroupMember` [`a`][Add-DistributionGroupMember] [`g`][Get-DistributionGroupMember] [`ud`][Update-DistributionGroupMember]  `DNSClientServerAddress` [`s`][Set-DnsClientServerAddress] `DNSName`&nbsp;[`rv`][Resolve-DNSName] `DhcpServerInDC` [`a`][Add-DhcpServerInDC] `DhcpServerV4Scope` [`a`][Add-DhcpServerv4Scope] `DhcpServerv4OptionValue` [`s`][Set-DhcpServerv4OptionValue]
**E** `ExecutionPolicy` [`s`][Set-ExecutionPolicy] 
**G** `GPUpdate` [`i`][Invoke-GPUpdate] `Guid` [`n`][New-Guid] `Help` [`g`][Get-Help] [`ud`][Update-Help] 
**I** `Item` [`cp`][Copy-Item] [`g`][Get-Item] [`n`][New-Item] [`r`][Remove-Item] 
**L** `List` [`f`][Format-List] `Location` [`g`][Get-Location] [`s`][Set-Location] 
**M** `Module`&nbsp;[`ip`][Import-Module]&nbsp;[`is`][Install-Module] 
**N** `NetAdapter` [`g`][Get-NetAdapter] `NetFirewallRule` [`g`][Get-NetFirewallRule] [`n`][New-NetFirewallRule] [`s`][Set-NetFirewallRule] `NetIpAddress` [`n`][New-NetIpAddress] `NetIpConfiguration` [`g`][Get-NetIpConfiguration] `Null` [`o`][Out-Null] 
**O** `Object` [`ForEach`][ForEach-Object] [`n`][New-Object] [`sc`][Select-Object] [`Where`][Where-Object]  `Output` [`wr`][Write-Output] 
**P** `Partition` [`g`][Get-Partition] [`n`][New-Partition] [`r`][Remove-Partition]  `PSReadlineOption` [`g`][Get-PSReadlineOption] [`s`][Set-PSReadlineOption] `PSSession` [`dc`][Disconnect-PSSession] [`et`][Enter-PSSession] [`ex`][Exit-PSSession] [`g`][Get-PSSession] [`n`][New-PSSession] 
**S** `Service` [`g`][Get-Service] [`s`][Set-Service] [`sa`][Start-Service] [`sp`][Stop-Service] `SmbOpenFile` [`cs`][Close-SmbOpenFile] [`g`][Get-SmbOpenFile] `SmbShare` [`n`][New-SmbShare] `SmigServer` [`Export-SmigServerSetting`][Export-SmigServerSetting] [`Get-SmigServerFeature`][Get-SmigServerFeature] [`Import-SmigServerSetting`][Import-SmigServerSetting] [`Receive-SmigServerData`][Receive-SmigServerData] [`Send-SmigServerData`][Send-SmigServerData] **T** `Table` [`f`][Format-Table] `Type` [`a`][Add-Type] 
**V** `VM` [`cr`][Compare-VM] [`db`][Debug-VM] [`ep`][Export-VM] [`g`][Get-VM] [`ip`][Import-VM] [`m`][Move-VM] [`ms`][Measure-VM] [`n`][New-VM] [`r`][Remove-VM] [`rn`][Rename-VM] [`rt`][Restart-VM] [`ru`][Resume-VM] [`s`][Set-VM] [`sa`][Start-VM] [`sp`][Stop-VM] [`ss`][Suspend-VM] [`sv`][Save-VM] `VMFirmware` [`s`][Set-VMFirmware]  `VMMemory` [`s`][Set-VMMemory] `VMNetworkAdapter` [`s`][Set-VMNetworkAdapter] `VMProcessor` [`s`][Set-VMProcessor]  `VMSwitch` [`n`][New-VMSwitch]  `Volume` [`f`][Format-Volume] 
**W** `WebRequest` [`Invoke`][Invoke-WebRequest] `WindowsFeature` [`a`][Add-WindowsFeature] [`g`][Get-WindowsFeature] [`is`][Install-WindowsFeature] `WindowsOptionalFeature` [`e`][Enable-WindowsOptionalFeature] `WMIObject` [`g`][Get-WMIObject]

###### Bash equivalents
[`$!`][&#36;&#36;] [`!$`][&#36;&#36;] [`$?`][&#36;?] [`&`][Start-Job] [`>>`][Add-Content] 
[`alias`][New-Alias] [`awk`][Select-Object] 
`bzip2` 
[`cat`][Get-Content] [`cd`][Set-Location] [`cp`][Copy-Item] 
[`echo`][Write-Host] &bull; [`find`][Get-ChildItem] &bull; [`grep`][Where-Object] 
[`less`](#out-host "`Out-Host -Paging`") [`ls`][Get-ChildItem] &bull; 
[`man`][Get-Help] [`mkdir`](#new-item "`New-Item -ItemType Directory`") [`more`](#out-host "`Out-Host -Paging`")
[`print`][Write-Host] [`printf`][Write-Host] [`pwd`][Get-Location]
[`reset`][Clear-Host] [`rm`][Remove-Item]
[`sed`][Select-Object] [`shutdown`][Stop-Computer] [`-r`][Restart-Computer]
[`tail`][Get-Content] [`touch`][New-Item]
[`uniq`](#select-object "`Select-Object -Unique`")
[`wc`][Measure-Object] [`which`][Get-Command]

#### Topics
**Clipboard**  [`Get-Clipboard`](#get-clipboard) [`New-Guid`](#new-guid) [`Set-Clipboard`](#set-clipboard) [`Write-Output`](#write-output)
**Disk management** [`Format-Volume`](#format-volume) [`Get-Disk`](#get-disk) [`Get-Partition`](#get-partition) [`New-Partition`](#new-partition) [`Remove-Partition`](#remove-partition)
**Environment** [`Get-Module`][Get-Module] [`Import-Module`][Import-Module] [`Set-ExecutionPolicy`][Set-ExecutionPolicy] [`Set-Location`][Set-Location]
**Filters** [`Where-Object`][Where-Object] [`Select-Object`][Select-Object] [`Select-String`](#filters) [`Out-GridView`](#filters) [`ForEach-Object`][ForEach-Object]
**Firewall** [`Get-NetFirewallRule`](#get-netfirewallrule) [`New-NetFirewallRule`](#new-netfirewallrule) [`Set-NetFirewallRule`](#set-netfirewallrule)
**Formatting** [`Format-List`][Format-List] [`Format-Table`][Format-Table] [`Format-Wide`](#output-formatting)
**Hyper-V**  [`New-VMSwitch`][New-VMSwitch] [`Set-VMFirmware`][Set-VMFirmware] [`Set-VMMemory`](#set-vmmemory) [`Set-VMNetworkAdapter`](#set-vmnetworkadapter) [`Set-VMProcessor`](#set-vmprocessor)
**O365** `DistributionGroupMember` [`a`][Add-DistributionGroupMember] [`g`][Get-DistributionGroupMember] [`ud`][Update-DistributionGroupMember]
**Remote administration** [`Enable-PSRemoting`][Enable-PSRemoting] [`Invoke-Command`](#invoke-command) `PSSession` [`dc`][Disconnect-PSSession] [`et`][Enter-PSSession] [`ex`](#exit-pssession) [`g`](#get-pssession) [`n`][New-PSSession]
**System administration** [`Get-Alias`][Get-Alias] [`Get-Command`][Get-Command] [`Get-Help`][Get-Help] [`Get-History`][Get-History] [`Get-Module`][Get-Module] `Get-Process` `Get-PSDrive` [`Get-Service`][Get-Service] [`Update-Help`][Update-Help]

#### Variables
[`$_`][&#36;_] [`$?`][&#36;?] [`$^`][&#36;^] [`$$`][&#36;&#36;] 
[`$args`][$args] 
[`$HOME`][$HOME] 
[`$IsLinux`][$IsLinux] [`$IsMacOS`][$IsMacOS] [`$IsWindows`][$IsWindows] 
[`$PID`][$PID] [`$PSCulture`][$PSCulture] [`$PSVersionTable`][$PSVersionTable] [`$PWD`][$PWD]

## Syntax
The `Throw` keyword generates a terminating error

#### Variables
**Automatic variables** are variables that store state information for PowerShell and are created and maintained by Powershell.

Variables can be typed by preceding their identifier with the datatype in brackets
```powershell
[double]$Price
[int]$Quantity
[string]$Description
```
Compatible data can be **cast** or converted by simply specifying the type in an assignment, but when the data cannot be converted the interpreter will throw an error.
```powershell
$Number = [int]'04'
$FailedCast = [int]'Hello'
```

#### Profiles
Syntax                            | Effect
:---                              | :---
`$profile`                        | display file of current profile
`$profile.CurrentUserCurrentHost` | %UserProfile%\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
`$profile.CurrentUserAllHosts`    | %UserProfile%\Documents\WindowsPowerShell\profile.ps1
`$profile.AllUsersAllHosts`       | %windir%\System32\WindowsPowerShell\v1.0\profile.ps1
`$profile.AllUsersCurrentHost`    | %windir%\System32\WindowsPowerShell\v1.0\Microsoft.PowerShell_profile.ps1

#### Comparison operators
Syntax          | Effect
---             | ---
`-like`         | wildcard pattern
`-match`        | regex pattern
`-is`           | type comparison

Syntax                        | Effect
:---                          | :---
`Get-Alias Definition -eq Get-ChildItem`|display items that point to `Get-ChildItem`
`Get-Command \| measure`      | piping to `measure` is similar to `wc`, will count lines
`Get-Command -Module ActiveDirectory`|display cmdlets available under a specified module
`Get-Command *smb*`           | use a wildcard
`Get-Module -ListAvailable`   | display installed PowerShell modules
`Invoke-History`              | run a command from the history
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter` |edit an existing alias
`New-PSDrive -Name scripts -PSProvider FileSystem -Root "C:\Scripts"`|map a directory to a drive
`Remove-PSDrive -Name scripts`|remove a drive

Common Parameter        | Alias   | Effect
---                     | ---     | ---
`-Debug`                | `-db`   | display programmer-level detail about command operation
`-ErrorAction`          |         | determine how the cmdlet responds to a non-terminating error
`-ErrorVariable`        | `-ev`   | store errors in specified variable
`-InformationAction`    | `-infa` | specify action to take at occurrences of `Write-Information` command
`-InformationVariable`  | `-iv`   | store information message passed from `Write-Information` cmdlet
`-OutVariable`          | `-ov`   | store output objects from the command in the specified variable
`-OutBuffer`            | `-ob`   | determine number of objects to accumulate in a buffer before any objects are sent through the pipeline
`-PipelineVariable`     | `-pv`   | store value of the current pipeline element in specified variable
`-Verbose`              | `-vb`   | display detailed operation done by the command
`-WarningAction`        | `-wa`   | specify action to take on occurrence of `Write-Warning` cmdlet
`-WarningVariable`      | `-wv`   | store warnings about the command in a variable
`-WhatIf`               | `-wi`   | display a message describing the effect of the command, instead of actually executing it
`-Confirm`              | `-cf`   | prompt for confirmation before executing the command

#### Filters
Filtering results can be done with 5 commands:
- `Where-Object` (aliased to `where` and `?`): the most commonly used such command
- `Select-Object` (aliased to `sc`ed to specify specific columns of information to be displayed
- `Select-String` (aliased to `sls`)
- `Out-GridView`
- `ForEach-Object` (aliased to `foreach` and `%`) There are two different ways to construct a `ForEach-Object` statement:
  1. __Script block__, within which the variable `$_` represents the current object
  2. __Operation statement__, more naturalistic, where you specify a property value or call a method.

### Scripting
Functions are declared with the following syntax
```powershell
function Start-PSAdmin {
  Start-Process PowerShell -Verb RunAs
}
```
Single-line comments are preceded by `#`. But block quotes can be created by enclosing them between `<#` and `#>`.\
__Positional parameters__ can be referenced using the built-in array `args`, which contains all arguments passed to the function on invocation.
```powershell
function Get-LargeFiles {
  Get-ChildItem C:\Users\Michael\Documents |
  where {$_.Length -gt $args[0] and !$_PSIscontainer} |
  Sort-Object Length -Descending
}
```
__Named parameters__ can be declared in one of two ways. One, within the function body using the `param` keyword, followed by the name of the variable representing the parameter's value, enclosed in `$(...)`:
```powershell
function Get-LargeFiles {
  param ($Size)
  Get-ChildItem C:\Users\Michael\Documents |
  where {$_.Length -gt $Size -and !$_.PSIsContainer} |
  Sort-Object Length -Descending
}
```
An alternative way is directly after the function name, with each parameter separated by a comma.
```powershell
function Get-LargeFiles($Size) {
  Get-ChildItem C:\Users\Michael\Documents |
  where {$_.Length -gt $Size -and !$_.PSIsContainer} |
  Sort-Object Length -Descending
}
```
Default values for parameters can be specified by placing them within the parentheses
```powershell
function Get-LargeFiles {
  param ($Size=2000)
  Get-ChildItem C:\Users\Michael\Documents |
  where {$_.Length -gt $Size -and !$_.PSIsContainer} |
  Sort-Object Length -Descending
}
```
The name of the variable becomes the named parameter used when invoking the function
```powershell
Get-LargeFiles -Size 2000
```
__Data typing__ can be performed by preceding the named parameter with `[int]`, for example. This simplifies data validation and also serves to document your code.
```powershell
function Get-LargeFiles {
  param ([int]$Size=2000)
  Get-ChildItem C:\Users\Michael\Documents |
  where {$_.Length -gt $Size -and !$_.PSIsContainer} |
  Sort-Object Length -Descending
}
```
__Switch parameters__ are declared with a special syntax, such that `[switch]` precedes the dollar sign.
```powershell
function Switch-Item {
  param ([switch]$on)
  if ($on) { "Switch on" }
  else { "Switch off" }
}
```
Passing the option `-on` to the function on invocation will produce the output:
```
Switch on
```
Omitting the option:
```
Switch off
```
Boolean values can be explicitly set upon invocation using this syntax:
```powershell
Switch-Item -on:$false
```
Which will produce the output:
```
Switch off
```
__Mandatory parameters__ are declared by preceding the parameter name with `[Parameter(Mandatory=$true)]`. 
```powershell
```
### Control flow
```powershell
if ($condition) {
  ...
}
```
```powershell
switch ($reference) {
  $value1 { ... }
  $value2 { ... }
}
```
### Loops
Pipeline is the defining feature of PowerShell, which allows it to break apart composite objects and act on each element with the `ForEach-Object` cmdlet.
```powershell
1..5 | ForEach-Object {$_ + 2} # => @(3,4,5,6,7)
```
When values are stored in a variable at the end of a pipeline, it will create an array. `while` and `do while` loops are available, as well as `until` and `do until` loops which operate so long as their condition is **false**.
```powershell
$Values = while ($true) {(++$Tick); if ($Tick -gt 2) { break } } # => @(1,2,3)
$Values = do { 'eat me!' } while ($false) # => @('eat me!')
```

## Cmdlets
### `Add-ADPrincipalGroupMembership`
```powershell
Add-ADPrincipalGroupMembership -Identity "CN=SysAdmin,CN=Users,DC=corp,DC=packtlab,DC=com" -MemberOf "CN=Enterprise Admins,CN=Users,DC=corp,DC=packtlab,DC=com","CN=Domain Admins,CN=Users,DC=corp,DC=packtlab,DC=com"
```
### `Add-Computer`
Join a computer to a domain [<sup>Zacker: 20</sup>][Zacker]

Option  | Description
---     | ---
`Credential`
`DomainName`
`NewName`

Rename a computer and join it to a domain
```powershell
Add-Computer -DomainName adatum.com -NewName ServerB -Credential adatum\administrator
```
Join a new computer to a domain
```powershell
Add-Computer -Domain 'officeprodemoco.onmicrosoft.com' -Restart
New-ADComputer -Name "O365-CL93"
```
Joining many computers using a .csv file
```powershell
New-ADComputer -Name "O365-CL93"
$List = "C:\Labfiles\computers.csv"
$OU = "OU=office365,DC=officeprodemoco,DC=onmicrosoft,DC=com"
Import-Csv -path $List | ForEach-Object {New-ADComputer -Name $_.Name -Path $OU}
```
Verify a computer has connected to a domain
Check "Organization" in Windows about page, or navigate to Control PAnel > System and Security > System and examine the **Computer name, domain, and workgroup settings**, where the domain can be seen.
### `Add-DhcpServerInDC`
[<sup>ref</sup>][Jones]
```powershell
Add-DhcpServerInDC -DnsName dc.corp.packtlab.com
```
### `Add-DhcpServerv4Scope`
[<sup>ref</sup>][Jones]
```powershell
Add-DhcpServerv4Scope -Name "PacktLabNet" -StartRange 10.0.0.50 -EndRange 10.0.0.100 -SubnetMask 255.255.255.0
```
### `Add-DistributionGroupMember`

Parameter | Effect
---       | ---
`Identity`| Specifies the group that you want to modify. You can use any value that uniquely identifies the group (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).
`Member`  | Specifies the recipient that you want to add to the group. A member can be any mail-enabled recipient in your organization. You can use any value that uniquely identifies the recipient (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).
### `Add-PSSnapin`
### `Add-Type`
Generate a random password 20 characters long [<sup>ref</sup>][https://adamtheautomator.com/powershell-random-password/]
```powershell
Add-Type -AssemblyName 'System.Web'
[System.Web.Security.Membership]::GeneratePassword(20, 3)
```
### `Close-SmbOpenFile`
Close an open file [<sup>ref</sup>][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]
```powershell
Close-SmbOpenFile -FileId 4415226383589
```
Close open files for a session [<sup>ref</sup>][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]
```powershell
Close-SmbOpenFile -SessionId 4415226380393
```
### `Disconnect-PSSession`
Terminate a remote PowerShell session begun with [`New-PSSession`][New-PSSession] [<sup>Zacker: 22</sup>][Zacker]
### `Enable-PSRemoting`
### `Enable-WindowsOptionalFeature`
Enable a feature in the currently running operating system [<sup>ref</sup>](https://docs.microsoft.com/en-us/powershell/module/dism/enable-windowsoptionalfeature?view=win10-ps&redirectedfrom=MSDN "Microsoft Docs: \"Enable-WindowsOptionalFeature\"")
```powershell
Enable-WindowsOptionalFeature -Online -FeatureName "Hearts" -All
```
Enable WSL [<sup>ref</sup>](https://www.reddit.com/r/bashonubuntuonwindows/comments/7smf9m/help_wsl_wont_activate_on_my_freshly_installed/ "Reddit: \"[help] WSL won't activate on my freshly installed Windows 10 version 1709\"")
```powershell
Enable-WindowsOptionalFeature -online -FeatureName Microsoft-Windows-Subsystem-Linux
```
### `Enter-PSSession`
Interact with the specified PowerShell session
```powershell
Enter-PSSession -id 1
```
Start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
```powershell
Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey
```
### `Exit-PSSession`
Exit a remote PowerShell session [<sup>Zacker: 22</sup>][Zacker]
End the PowerShell session with the specified computer
```powershell
Exit-PSSession -ComputerName demodc
```
### `Expand-Archive`
Decompress archives
```powershell
Expand-Archive
```
### `Export-Alias`
Export session aliases to a ".ps1" file
```powershell
Export-Alias -Path alias.ps1 -As Script
```
### `Export-CliXml`
### `Export-Csv`
### `Format-Volume`
Full format of specified drive [<sup>ref</sup>][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]
```powershell
Format-Volume -DriveLetter S -FileSystem FAT32 -NewFileSystemLabel SumTips -Full
```
### `Get-ADForest`
Display installed forests
```powershell
Get-ADForest | select -ExpandProperty domains
```
### `Get-ADOrganizationalUnit`
Display OUs, confirming deletion has taken place
```powershell
Get-ADOrganizationalUnit  -filter * | ft
```
### `Get-ADPrincipalGroupMembership`
[<sup>ref</sup>][Jones]
```powershell
Get-ADPrincipalGroupMembership sysadmin
```
### `Get-ADUser`
Display information for Active Directory user `mike`
```powershell
Get-ADUser -Identity mike
```
Display Protection from Accidental Deletion
```powershell
Get-ADUser -Filter *  -Properties ProtectedFromAccidentalDeletion
  -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  `
```
Display information on user, confirming successful creation
```powershell
Get-ADUser "Marty McFly" | Select-Object Name
```
### `Get-Alias`
Display aliases
```powershell
Get-Alias
```
Display items that point to `Get-ChildItem`
```powershell
Get-Alias -Definition Get-ChildItem
```
### `Get-ChildItem`
### `Get-Clipboard`
Interpret items in clipboard as files
```powershell
Get-Clipboard -Format FileDropList
```
Retrieve various properties of an image in clipboard
```powershell
Get-Clipboard -Format Image
```
### `Get-Command`
### `Get-Content`
Make a PowerShell object from a JSON file
```powershell
Get-Content -Path file.json | ConvertFrom-Json
```
### `Get-Disk`
### `Get-Help`
\#    | Options
---   | ---
**A-Z** | [`-Detailed`](#get-help "`Get-Help -Detailed`&#10;Display detailed help for a command") [`-Examples`](#get-help "`Get-Help -Examples`&#10;Display usage examples") [`-Full`](#get-help "`Get-Help -Full`&#10;Display entire help file for a command") [`-Online`](#get-help "`Get-Help -Online`&#10;Navigate to online help page for a command") [`-ShowWindow`](#get-help "`Get-Help -ShowWindow`&#10;Display help output in a window") 
### `Get-Member`
### `Get-Module`
### `Get-NetAdapter`
Display available network interfaces [<sup>Zacker: 19</sup>][Zacker]

Option  | Description
---     | ---
...
### `Get-NetFirewallRule`
Display all firewall rules
```powershell
Get-NetFirewallRule
```
Display active firewall rules for inbound connections
```powershell
Get-NetFirewallRule -Enabled True -Direction Inbound
```
Display programs associated with firewall rules
```powershell
Get-NetFirewallRule | %{$_.Name; $_ | Get-NetFirewallApplicationFilter}
```
### `Get-Partition`
Display a list of existing partitions, their drive letters, and the disk they are associated with [<sup>Sum Tips</sup>][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]
```powershell
Get-Disk | Get-Partition
```
### `Get-PSReadlineOption`
Display options available in the module
```powershell
Get-PSReadlineOption
```
### `Get-PSSession`
Display PowerShell sessions
```powershell
Get-PSSession
```
### `Get-Service`
Display status of &lt;WinRM&gt; service
```powershell
Get-Service WinRM
```
```powershell
gsv winrm
```
### `Get-SmbOpenFile`
Get information about an opened file [<sup>ref</sup>][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]
```powershell
Get-SmbOpenFile -FileId 4415226383569 | Select-Object -Property *
```
Example output:
```
ClientComputerName    : 192.168.102.14 
ClientUserName        : Contoso\Contoso-HV2$ 
ClusterNodeName       : Contoso-FS2 
ContinuouslyAvailable : True 
Encrypted             : False 
FileId                : 4415226383569 
Locks                 : 1 
Path                  : C:\ClusterStorage\Volume2\VMS\VM4.VHDX 
Permissions           : 1179785 
ScopeName             : Contoso-SO 
SessionId             : 4415226380393 
ShareRelativePath     : VM4.VHDX 
PSComputerName        : 
CimClass              : ROOT/Microsoft/Windows/SMB:MSFT_SmbOpenFile 
CimInstanceProperties : {ClientComputerName, ClientUserName, ClusterNodeName, ContinuouslyAvailable...} 
CimSystemProperties   : Microsoft.Management.Infrastructure.CimSystemProperties
```
Get information about a file opened for an SMB client [<sup>MS Docs</sup>][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]
```powershell
Get-SmbOpenFile -SessionId 4415226380393
```
Example output:
```
FileId              SessionId           Path                ShareRelativePath   ClientComputerName  ClientUserName 
------              ---------           ----                -----------------   ------------------  -------------- 
4415226383517       4415226380393       C:\ClusterStorag... VM4\VIRTUAL MACH... 192.168.102.14      Contoso\Contoso-HV2$ 
4415226383521       4415226380393       C:\ClusterStorag... VM4\Virtual Mach... 192.168.102.14      Contoso\Contoso-HV2$ 
4415226383529       4415226380393       C:\ClusterStorag... VM4\Virtual Mach... 192.168.102.14      Contoso\Contoso-HV2$ 
4415226383569       4415226380393       C:\ClusterStorag... VM4.VHDX            192.168.102.14      Contoso\Contoso-HV2$ 
4415226383589       4415226380393       C:\ClusterStorag... VM4.VHDX            192.168.102.14      Contoso\Contoso-HV2$
```
### `Get-WindowsFeature`
Display installable Windows roles, role services, and features
Display a branching view of available Windows roles, role services, and features
```powershell
Get-WindowsFeature
```
### `Get-WmiObject`
View system uptime
```powershell
Get-WmiObject -Win32_OperatingSystem -ComputerName localhost |
Select-Object -Property @{n="Last Boot Time";e={[Management.ManagementDateTimeConvert]::ToDateTime($_.LastBootUpTime)}}
```
Display Windows activation key [<sup>ref</sup>][https://www.thewindowsclub.com/find-windows-product-key]
```powershell
(Get-WmiObject -query ‘select * from SoftwareLicensingService’).OA3xOriginalProductKey
```
### `Import-CliXml`
### `Import-Csv`
Add a CSV full of users
```powershell
Import-Csv users.csv | foreach { New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -Enabled $True -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) }
``` 
### `Import-Module`
Import `SmbShare` module
```powershell
Import-Module SmbShare
```
### `Install-ADDSForest`
Add a new forest
```powershell
# This will prompt for safe mode administrator password
Install-ADDSForest -DomainName example.com -InstallDNS
```
If the system fails to automatically create a NetBIOS name, it can be manually specified with the named parameter `-DomainNetbiosName`
### `Install-ADDSDomain`
Add a new domain
`Install-ADDSDomain` only requires the following two parameters:
  - `-NewDomainName` if the value set for `-DomainType` is set to `ChildDomain` (which it is by default), a single label domain name can be used.
  - `ParentDomainName` the name of an existing parent domain
```powershell
Install-ADDSDomain -NewDomainName hq -ParentDomainName pythagoras.net
```
```powershell
Install-ADDSDomain -Credential (Get-Credential CORP\EnterpriseAdmin1) -NewDomainName child -ParentDomainName corp.contoso.com -InstallDNS -CreateDNSDelegation -DomainMode Win2003 -ReplicationSourceDC DC1.corp.contoso.com -SiteName Houston -DatabasePath "D:\NTDS" -SYSVOLPath "D:\SYSVOL" -LogPath "E:\Logs" -NoRebootOnCompletion
```
### `Install-Module`
Install the `Az` module
```powershell
Install-Module -Name Az -AllowClobber
```
### `Install-WindowsFeature`
[Install-WindowsFeature -Name]:      #Install-WindowsFeature        '```&#10;PS C:\> Install-WindowsFeature -Name&#10;```&#10;&#10;Values can include:&#10;  - "`AD-Domain-Services"&#10;  - "Hyper-V"&#10;  - "RSAT-ADDS"&#10;  - "Web-WebServer"'

&nbsp;  | Options
---     | ---
&nbsp;  | [**`Name`**][Install-WindowsFeature -Name] `IncludeAllSubFeature` `IncludeManamgentTools`


Install Windows features and roles [<sup>Zacker: 15-16</sup>][Zacker]

Install a feature
```powershell
Install-WindowsFeature -Name $featurename -IncludeAllSubFeature -IncludeManagementTools
```
Remote Server Adminstration Tools for PowerShell
```powershell
Install-WindowsFeature -Name RSAT-ADDS -IncludeAllSubFeature
```
Install Hyper-V
```powershell
Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart
```
Install Web Server [<sup>ref</sup>][Jones]
```powershell
Install-WindowsFeature web-webserver -IncludeManagementTools
```
```powershell
Install-WindowsFeature Web-Server,Web-Common-Http,Web-Mgmt-Console -Restart
```
Create a domain controller
```powershell
Install-WindowsFeature AD-Domain-Services -IncludeManagementTools
```
Create a DHCP server [<sup>ref</sup>][Jones]
```powershell
Install-WindowsFeature DHCP -IncludeManagementTools
```
Install Windows Server Migration Tools [<sup>Zacker: 33</sup>][Zacker]
```powershell
Install-WindowsFeature Migration
```
### `Invoke-Command`
Execute the commands in the block on the machines specified
```powershell
Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}
```
### `Invoke-WebRequest`
Download a file over HTTP/HTTPS
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -OutFile \\path\to\local\file
```
Resume a partial download
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -Resume -Outfile \\path\to\local\file
```
Transfer a file over FTP/SFTP
```powershell
Invoke-WebRequest ftp://ftp.example.com/file -Outfile C:\path\to\file -Credential ftpuseraccount
```
Resolve shortened URLs
```powershell
$Uri = 'short-url/extension' 
$Web = Invoke-WebRequest -Uri 
$Uri -UseBasicParsing  $Web.BaseResponse.ResponseUri.AbsoluteUri
```
Scrape links from a website
```powershell
(Invoke-WebRequest -Uri "https://techrepublic.com").Links.Href
```
Request data from a website impersonating a browser
```powershell
Invoke-WebRequest -Uri http://microsoft.com -UserAgent ([Microsoft.PowerShell.Commands.PSUserAgent]::Chrome)
```
### `New-ADComputer`
### `New-ADOrganizationalUnit`
Create a new Organizational Unit
```powershell
New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey
```
### `New-ADUser`
[Jones][Jones]
```powershell
New-ADUser -SamAccountNAme SysAdmin -AccountPassword (Read-Host 'Set user password' -AsSecureString) -Name "SysAdmin" -Enabled $true -PAsswordNeverExpires $true -ChangePasswordAtLogon $false
```
Create a new user (disabled by default)
```powershell
New-ADUser -Name "Walter Mitty"
```
Users are disabled by default, so you must enable them by setting the `-Enabled` switch parameter:
```powershell
New-ADUser -Name "Marty McFly" -Enabled $true -GivenName "Martin" -Surname "McFly" -AccountPassword ( ConvertTo-SecureString "P@ssw0rd!" -AsPlainText -Force) 
```
### `New-Alias`
Establish a new alias
```powershell
New-Alias ip Get-NetIPAddress
```
### `New-Guid`
Generate a GUID
```powershell
New-Guid
(New-Guid).Guid | clip
```
### `New-Item`
```powershell
New-NetIPAddress 10.0.0.3 -InterfaceAlias "Ethernet' -PrefixLength 24
```
### `New-NetFirewallRule`
Set a new firewall rule for incoming WinRM connections
```powershell
New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
```
### `New-NetIpAddress`
Manually configure network interface, if a DHCP server is unavailable [<sup>Zacker: 19</sup>][Zacker]

Option            | Description
---               | ---
`DefaultGateway`  | Specifies IP address of local router that computer should use to access other networks
`InterfaceIndex`  | Identifies adapter to be configured using interface numbers as displayed by [`Get-NetAdapter`](#get-netadapter)
`IpAddress`       | Specifies IP address to be assigned to adapter
`PrefixLength`    | Specifies subnet mask value

Configure the Domain Controller in a new corporate intranet [<sup>ref</sup>][Jones]
```powershell
New-NetIPAddress 10.0.0.1 -InterfaceAlias "Ethernet" -PrefixLength 24
```
Configure the application server in a new corporate intranet [<sup>ref</sup>][Jones]
```powershell
New-NetIpAddress 10.0.0.3 -InterfaceAlias "Ethernet" -PrefixLength 24
```
Configure a network adapter 
```powershell
New-NetIpAddress -InterfaceIndex 6 -IpAddress 192.168.0.200 -PrefixLength 24 -DefaultGateway 192.168.0.1
```
### `New-Partition`
Use all available size for a new partition [<sup>ref</sup>][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]
```powershell
New-Partition -DiskNumber 1 -UseMaximumSize
```
Automatically assign a drive letter
```powershell
New-Partition -DiskNumber 1 -UseMaximumSize -AssignDriveLetter
```
### `New-PSSession`
Option  | Description
---     | ---
`-ComputerName`

Manage a Windows Server remotely [Zacker: 21][Zacker]
```powershell
New-PSSession -ComputerName rtmsvrd
```
Start a new PowerShell session, connecting to the specified computer
```powershell
New-PSSession -ComputerName core02
```
### `New-SmbShare`
[`New-SmbShare`][New-SmbShare]
```powershell
New-SmbShare -Name files -Path C:\networkfiles -ChangeAccess CORP\SysAdmin
```
### `New-VMSwitch`
Turn on NAT on the nested Hyper-V VM
```powershell
New-VMSwitch -name VMNAT -SwitchType Internal
New-NetNAT -Name LocalNAT -InternalIPInterfaceAddressPrefix "192.168.100.0/24"
```
### `Out-Null`
### `Remove-ADOrganizationalUnit`
Remove an OU
```powershell
Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False
```
### `Rename-Computer`
Rename computer
### `Restart-Computer`
Restart computer
### `Remove-Item`
Remove Microsoft Office identities 
```powershell
Remove-Item HKCU:\Software\Microsoft\Office\16.0\Common\Identity\Identities\*
```
Clear `%temp%` folder
```powershell
Remove-Item -Recurse $Env:temp
```
### `Remove-Partition`
Remove a partition [<sup>ref</sup>][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]
```powershell
Remove-Partition -DiskNumber 1 -PartitionNumber 1
```
Remove a partition without confirmation
```powershell
Remove-Partition -DiskNumber 1 -PartitionNumber 1 -Confirm:$false
```
### `Resolve-DNSNAme`
```pwsh
Resolve-DNSName -Name secure.practicelabs.com.trustanchors -Type dnskey -Server plabdm01
```
### `Search-ADAccount`

Option                        | Effect
:---                          | :---
`-AccountDisabled`            | filter disabled accounts
`-AccountExpired`             | filter expired accounts
`-ComputersOnly`              | filter computer accounts
`-LockedOut`                  | filter locked out accounts
`-PasswordExpired`            | filter accounts with expired passwords
`-PasswordNeverExpires`       | filter accounts with passwords that will never expire
`-UsersOnly`                  | filter users

Display accounts that have been inactive for the last 90 days
```powershell
Search-ADAccount -AccountInactive -TimeSpan 90.00:00:00
```
Display accounts expiring on a particular date
```powershell
Search-ADAccount -AccountExpiring -DateTime "3/18/2019"
``` 
### `Set-ADAccountPassword`
Reset password
```powershell
Set-ADAccountPassword -Identity MBentley -Reset -NewPassword (ConvertTo-SecureString -AsPlainText "What is 255.255.255.240" -Force`)
```
### `Set-ADObject`
Protect users in a specified OU from accidental deletion
```powershell
Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" ` | 
Set-ADObject -ProtectedFromAccidentalDeletion $true
```
### `Set-ADOrganizationalUnit`
Remove accidental deletion protection
```powershell
Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" 
```
### `Set-Alias`
Edit an existing alias
```powershell
Set-Alias ip Get-NetAdapter
```
### `Set-Clipboard`
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
With `Append` switch parameter, items can be added without clearing the clipboard:
```powershell
Write-Output 'Hello' | Set-Clipboard -Append
```
### `Set-DhcpServerv4OptionValue`
[<sup>ref</sup>][Jones]
```powershell
Set-DhcpServerv4OptionValue -DnsDomain corp.packtlab.com -DnsServer 10.0.0.1
```
### `Set-DnsClientServerAddress`
Configure DNS server addresses [<sup>ref</sup>][Zacker]

Parameter           | Description
---                 | ---
`-InterfaceAlias`   |
`-InterfaceIndex`   |
`-ServerAddresses`  |

Configure DNS server address for a DC on a new corporate intranet [<sup>ref</sup>][Jones]
```powershell
Set-DnsClientServerAddress -InterfaceAlias "Ethernet" -ServerAddresses 127.0.0.1
```
Configure DNS server address for an application server on a new corporate intranet [<sup>ref</sup>][Jones]
```powershell
Set-DnsClientServerAddress -InterfaceAlias "Ethernet" -ServerAddresses 10.0.0.1
```
Configure DNS server addresses [<sup>ref</sup>][Zacker]
```powershell
Set-DnsClientServerAddress -InterfaceIndex 6 -ServerAddresses ("192.168.0.1", "192.168.0.2")
```
### `Set-ExecutionPolicy`
### `Set-Location`
### `Set-NetFirewallRule`
Set firewall rule for COM+ Network Access (DCOM-In)
```powershell
Set-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In -Enabled True
```
Set firewall rule for Remote Event Log Management (NP-In)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-In-TCP -Enabled True
```
Set firewall rule for Remote Event Log Management (RPC)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-NP-In-TCP -Enabled True
```
Set firewall rule for Remote Event Log Management (RPC-EPMAP)
```powershell
Set-NetFirewallRule -name RemoteEventLogSvc-RPCSS-TCP -Enabled True
```
### `Set-PSReadlineOption`
Set history to only save unique commands
```powershell
Set-PSReadlineOption -HistoryNoDuplicates:$true
```
Enable bash-like ambiguous command completion, where tab brings up a menu of matches
```powershell
Set-PSReadlineOption -EditMode Emacs
```
Change `<Tab>` behavior back to default for PowerShell
```powershell
Set-PSReadlineOption -EditMode Windows
```
### `Set-VMFirmware`
Enable secure boot on Generation 2 Linux VMs [<sup>ref</sup>][IMWS]
```powershell
Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority
```
### `Set-VMMemory`
Disable dynamic memory on a virtual host (nested virtualization)
```powershell
Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false
```
### `Set-VMNetworkAdapter`
Turn on MAC address spoofing on a virtual host (nested virtualization)
```powershell
Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On
```
### `Set-VMProcessor`
Configure 2 virtual processors on a virtual host (nested virtualization)
```powershell
Set-VMProcessor -VMName SVR01 -Count 2
```
### `Start-DscConfiguration`
Used to erect a **push architecture** in [DSC](dsc.md). [<sup>Zacker: 27</sup>][Zacker]

Option  | Description
---     | ---
`-Path`
### `Set-Service`
```powershell
Set-Service WtcOtg -StartupType Disabled
```
### `Start-Service`
Start the `WinRM` service
```powershell
sasv winrm
```
### `Stop-Service`
Stop the WebTitan service
```powershell
Stop-Service WtcOtg
```
### `Uninstall-ADDSDomainController`
Demote a domain controller (consummate with uninstalling the AD Domain Controller role)
```powershell
# When removing the last domain controller of a domain, additional options need to be specified that result in the obliteration of the domain, its forest, and associated data.
Uninstall-ADDSDomainController -LocalAdministratorPassword (ConvertTo-SecureString $pw -AsPlainText -Force) -LastDomainControllerInDomain -RemoveApplicationPartitions
```
### `Unlock-ADAccount`
Unlock account
```powershell
Unlock-ADAccount -identity wbryan
```
### `Update-Help`
Download help files
### `Write-Output`
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
Create a text file [<sup>ref</sup>][Jones]
```powershell
Write-Output "This is a test network file." -Path | Out-File C:\networkfiles\test.txt
```

## Tasks
#### Computer information
Display computer name [<sup>ref</sup>][https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]
```powershell
$env:computername
```
#### Generate password
Generate a random password 20 characters long [<sup>ref</sup>][https://adamtheautomator.com/powershell-random-password/]
```powershell
Add-Type -AssemblyName 'System.Web'
[System.Web.Security.Membership]::GeneratePassword(20, 3)
```
#### Credentials
Credentials can be stored in a variable and built interactively with `Get-Credential`
```powershell
$cred = Get-Credential
```
A credential can be built piecemeal by first securely saving a password with `ConvertTo-SecureString`
```powershell
$pw = ConvertTo-SecureString "Password" -AsPlainText -Force
```
Then construct the credential by using `New-Object`
```powershell
$cred = New-Object System.Management.Automation.PSCredential ("FullerP", $pw)
```
#### Output formatting
Change output format to `Format-Wide`
```powershell
Get-Service | Format-Wide
```
Change output format to be a single column
```powershell
Get-Service | Format-Wide -Column 1
```
Change output to display the `DisplayName` property
```powershell
Get-Service | Format-Wide -Property DisplayName
```
Display output as a list with properties listed next to values
```powershell
Get-Service | Format-List
```
Display all properties
```powershell
Get-Service | Format-List -Property *
```
Display only specified properties
```powershell
Get-Service | fl -Property Status,StartType,DisplayName
```
Display all properties
```powershell
Get-Service | Format-Table -Property *
```
Group by `Status`, but the output will be confused because it was not sorted
```powershell
Get-Service | Format-Table -Property DisplayName,StartType,Status -GroupBy Status
```
Sort list of services
```powershell
Get-Service | Sort-Object
```
Group by `Status` after sorting
```powershell 
 Get-Service | Sort-Object -Property Status | Format-Table -Property DisplayName,StartType,Status -GroupBy Status
```
Will produce an error because `Write-Host` expects a single object
```powershell
Get-Service | Write-Host
```
Loop through each object in output of `Get-Service` and send the `name` field to `Write-Host`
```powershell
Get-Service | ForEach-Object {Write-Host $_.name}
```
#### File manipulation
Create a new file in the current working directory named `filename`
```powershell
New-Item -ItemType File -Name filename
```
Append `content` to `file`
```powershell
Add-Content C:\path\to\file $content
```
#### Hash tables
**Hash tables** (equivalent to Python dictionaries) can be built with hash literals:
```powershell
$hashtable = @{
  Apple = 'red'
  Orange = 'orange'
  Eggplant = 'purple'
}
```
Each line in a hash literal is a separate statement, that needs to be separated by semicolons when written in-line:
```powershell
$hashtable = @{ Apple = 'red'; Orange = 'orange'; Eggplant = 'purple' }
```
The Hashtable method `Add()` can also be used:
```powershell
$hashtable = @{}
$hashtable.Add('Apple','red')
$hashtable.Add('Orange','orange')
$hashtable.Add('Kiwi','green')
```
Like dicts in Python, copying a hash table is merely a reference or shallow copy:
```powershell
$hashtable1 = $hashtable
$hashtable1['Apple'] = 'rainbow'
$hashtable['Apple'] # => rainbow
```
But a deep copy or "clone" can be made:
```powershell
$hashtable2 = $hashtable.Clone()
```
Like in Python, the keys and values can be retrieved with methods (properties in PowerShell)
```powershell
$hashtable.Keys # => @('Apple','Orange','Kiwi')
$hashtable.Values # => @('red','orange','green')
```
Unlike Python, a hash table can be made ordered, changing its data type:
```powershell
$Hashtable = [ordered]@{One = 1; Two = 2; Three = 3; Four = 4}
$Hashtable.GetType().Name # => OrderedDictionary
```
Measuring length:
```powershell
$Hashtable.Count
```
Removing keys:
```powershell
$Hashtable.Remove('One')
```
#### Registry
Fix Windows Search bar [<sup>ref</sup>][https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7] [<sup>MS Docs</sup>][https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7]
```powershell
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search\BingSearchEnabled
Set-Item $$ 0
Set-ItemProperty -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Search -Name CortanaConsent -Value 0
```
#### New domain controller
[<sup>Jones</sup>][Jones]
```powershell
Install-WindowsFeature AD-Domain-Services,DHCP -IncludeManagementTools
Install-ADDSForest -DomainName corp.packtlab.com
Add-DhcpServerv4Scope -Name "PacktLabNet" -StartRange 10.0.0.50 -EndRange 10.0.0.100 -SubnetMask 255.255.255.0
Set-DhcpServerv4OptionValue -DnsDomain corp.packtlab.com
Add-DhcpServerInDC -DnsName dc.corp.packtlab.com
New-AdUser -SamAccountName SysAdmin -AccountPassword (Read-Host "Set user password" -AsSecureString) -Name "SysAdmin" -Enabled $true -PasswordNeverExpires $true -ChangePasswordAtLogon $false
Add-ADPrincipalGroupMembership -Identity "CN=SysAdmin,CN=Users,DC=corp,DC=packtlab,DC=com","CN=Domain Admins,CN=Users,DC=corp,DC=packtlab,DC=com"
Get-ADPrincipalGroupMembership sysadmin
```
#### Text-to-speech
Initialize text-to-speech object [<sup>ref</sup>](https://www.scriptinglibrary.com/languages/powershell/powershell-text-to-speech/ "Powershell: Text To Speech in 3 lines of code")
```powershell
Add-Type –AssemblyName System.Speech
$tts = New-Object –TypeName System.Speech.Synthesis.SpeechSynthesizer
$tts.Speak('Hello, World!')
```
List available voices
```powershell
Foreach ($voice in $SpeechSynthesizer.GetInstalledVoices()){
    $Voice.VoiceInfo | Select-Object Gender, Name, Culture, Description
}
```
Change voice
```powershell
$tts.SelectVoice("Microsoft Zira Desktop")
$tts.Speak('Hello, World!')
```
Set output to WAV file [<sup>ref</sup>](https://thinkpowershell.com/create-cortana-audio-files-from-text-using-powershell/ "Create Cortana Audio Files From Text Using PowerShell")
```powershell
$WavFileOut = Join-Path -Path $env:USERPROFILE -ChildPath "Desktop\thinkpowershell-demo.wav"
$SpeechSynthesizer.SetOutputToWaveFile($WavFileOut)
```

