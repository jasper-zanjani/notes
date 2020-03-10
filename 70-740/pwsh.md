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
[IMWS]:   https://github.com/jasper-zanjani/notes/master/sources/imws.md "McCabe, John. _Introduction to Microsoft Windows Server 2016_."
[Jones]:  https://subscription.packtpub.com/video/virtualization_and_cloud/9781789616385 "Jones, Joshua B. _Hands-On Powershell for Active Directory_. PacktPub: 2018."
[WSAC]:   https://github.com/jasper-zanjani/notes/master/sources/wsac.md "Krause, Jordan. _Windows Server 2016 Administration Cookbook_."
[Zacker]: https://github.com/jasper-zanjani/notes/master/certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."

<!-- Powershell automatic variables -->
[&#36;_]:                                            #variables                                    '```&#10;PS C:\> &#36;_&#10;PS C:\> $PSItem&#10;```&#10;Pipeline object'
[&#36;?]:                                            #variables                                    '```&#10;PS C:\> &#36;?&#10;```&#10;Execution status of the last operation'
[&#36;^]:                                            #variables                                    '```&#10;PS C:\> &#36;^&#10;```&#10;First token in the last line received by the session'
[&#36;&#36;]:                                        #variables                                    '```&#10;PS C:\> &#36;&#36;&#10;```&#10;Last token in the last line received by the session'
[$args]:                                             #variables                                    '```&#10;PS C:\> $args&#10;```&#10;Array of values for undeclared parameters passed to a function, script or script block'
[$HOME]:                                             #variables                                    '```&#10;PS C:\> $HOME&#10;```&#10;Full path of the home directory of the user'
[$IsLinux]:                                          #variables                                    '```&#10;PS C:\> $IsLinux&#10;```&#10;Contains `$True` if the current session is running on a Linux operating system'
[$IsMacOS]:                                          #variables                                    '```&#10;PS C:\> $IsMacOS&#10;```&#10;Contains `$True` if the current session is running on an OS X operating system'
[$IsWindows]:                                        #variables                                    '```&#10;PS C:\> $IsWindows&#10;```&#10;Contains `$True` if the current session is running on a Windows operating system'
[$PID]:                                              #variables                                    '```&#10;PS C:\> $PID&#10;```&#10;Contains process identifier (PID) of the process that is hosting the current PowerShell session'
[$PSCulture]:                                        #variables                                    '```&#10;PS C:\> $PSCulture&#10;```&#10;Name of the culture currently in use in the operating system'
[$PSVersionTable]:                                   #variables                                    '```&#10;PS C:\> $PSVersionTable&#10;```&#10;Read-only hash table that displays details about the version of PowerShell that is running in the current session'
[$PWD]:                                              #variables                                    '```&#10;PS C:\> $PWD&#10;```&#10;Path object that represents the full path of the current directory'

[Add-Computer]:                                      #add-computer                                      '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Add-Content]:                                       #add-content                                       '```&#10;PS C:\> Add-Content&#10;```&#10;'
[Add-DhcpServerInDC]:                                #add-dhcpserverindc                                '```&#10;PS C:\> Add-DhcpServerInDC&#10;```&#10;'
[Add-DhcpServerv4Scope]:                             #add-dhcpserverv4scope                             '```&#10;PS C:\> Add-DhcpServerv4Scope&#10;```&#10;Add an IPv4 scope on the DHCP server service.'
[Add-DistributionGroupMember]:                       #add-distributiongroupmember                       '```&#10;PS C:\> Add-DistributionGroupMember&#10;```&#10;Add a single recipient to distribution groups and mail-enabled security groups'
[Add-PSSnapin]:                                   #add-pssnapin                                      '```&#10;PS C:\> Add-PSSnapin&#10;PS C:\> asnp&#10;```&#10;Load a given list of snap-ins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) either by name or via the pipeline - last supported in PowerShell 5.1'
[Add-Type]:                                       #add-type                                          '```&#10;PS C:\> Add-Type&#10;```&#10;add a.NET Framework type (a class) to a Windows PowerShell session'
[Add-WindowsFeature]:                             #add-windowsfeature                                '```&#10;PS C:\> Add-WindowsFeature&#10;PS C:\> Install-WindowsFeature&#10;```&#10;Install one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2'
[Clear-Host]:                                     #clear-host                                        '```&#10;PS C:\> Clear-Host&#10;```&#10;'
[Clear-Host]:                                     #clear-host                                        '```&#10;PS C:\> Clear-Host&#10;```&#10;'
[Close-SmbOpenFile]:                              #close-smbopenfile                                 '```&#10;PS C:\> Close-SmbOpenFile&#10;```&#10;Close a file that is open by one of the clients of the SMB server'
[Close-SmbOpenFile]:                              #close-smbopenfile                                 '```&#10;PS C:\> Close-SmbOpenFile&#10;```&#10;Close a file that is open by one of the clients of the SMB server'
[Close-SmbOpenFile]:                              close-smbopenfile#close-smbopenfile                '```&#10;PS C:\> Close-SmbOpenFile&#10;```&#10;Close a file that is open by one of the clients of the SMB server&#10;"Close-SmbOpenFile". _Microsoft Docs_.'
[Compress-Archive]:                               #compress-archive                                  '```&#10;PS C:\> Compress-Archive&#10;```&#10;'
[Copy-Item]:                                      #copy-item                                         '```&#10;PS C:\> Copy-Item&#10;```&#10;'
[Disconnect-PSSession]:                           #disconnect-pssession                              '```&#10;PS C:\> Disconnect-PSSession&#10;PS C:\> dnsn&#10;```&#10;Terminate a remote PowerShell session begun with `New-PSSession`'
[Enable-PSRemoting]:                              #enable-psremoting                                 '```&#10;PS C:\> Enable-PSRemoting&#10;```&#10;Allow remote Powershell management'
[Enable-WindowsOptionalFeature]:                  #enable-windowsoptionalfeature                     '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;Enable or restore an optional feature in a Windows image'
[Enter-PSSession]:                                #enter-pssession                                   '```&#10;PS C:\> Enter-PSSession&#10;PS C:\> etsn&#10;```&#10;Interact with the specified PowerShell session'
[Exit-PSSession]:                                 #exit-pssession                                    '```&#10;PS C:\> Exit-PSSession&#10;PS C:\> exsn&#10;```&#10;End an interactive session with a remote computer'
[Expand-Archive]:                                 #expand-archive                                    '```&#10;PS C:\> Expand-Archive&#10;```&#10;Decompress archives'
[Export-Alias]:                                   #export-alias                                      '```&#10;PS C:\> Export-Alias&#10;PS C:\> epal&#10;```&#10;Export information about currently defined aliases to a file.'
[Export-CliXml]:                                  #export-clixml                                     '```&#10;PS C:\> Export-CliXml&#10;```&#10;Serialize a PowerShell object as a Common Language Infrastructure (CLI) XML file'
[Export-Csv]:                                     #export-csv                                        '```&#10;PS C:\> Export-Csv&#10;```&#10;Export PowerShell objects to CSV'
[Export-SmigServerSetting]:                       #export-smigserversetting                          '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[ForEach-Object]:                               #foreach-object                                    '```&#10;PS C:\> ForEach-Object&#10;PS C:\> %&#10;PS C:\> foreach&#10;```&#10;Perform an operation against each item in a collection of input objects.'
[Format-List]:                                 #format-list                                       '```&#10;PS C:\> Format-List&#10;PS C:\> fl&#10;```&#10;'
[Format-Table]:                                #format-table                                      '```&#10;PS C:\> Format-Table&#10;PS C:\> ft&#10;```&#10;'
[Format-Volume]:                                  #format-volume                                     '```&#10;PS C:\> Format-Volume&#10;```&#10;Formats one or more existing volumes or a new volume on an existing partition.&#10;The Format-Volume cmdlet formats one or more existing volumes, or a new volume on an existing partition. This cmdlet returns the object representing the volume that was just formatted, with all properties updated to reflect the format operation.'
[Get-Alias]:                                   #get-alias                                         '```&#10;PS C:\> Get-Alias&#10;PS C:\> gal&#10;```&#10;Display aliases'
[Get-ChildItem]:                               #get-childitem                                     '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir&#10;PS C:\> gci&#10;PS C:\> ls&#10;```&#10;Get items in one or more locations'
[Get-Clipboard]:                               #get-clipboard                                     '```&#10;PS C:\> Get-Clipboard&#10;PS C:\> gcb&#10;```&#10;Display items in clipboard'
[Get-Command]:                                 #get-command                                       '```&#10;PS C:\> Get-Command&#10;PS C:\> gcm&#10;```&#10;Display all installed commands, including aliases, applications, filters, functions, and scripts'
[Get-Content]:                                  #get-content                                       '```&#10;PS C:\> Get-Content&#10;PS C:\> cat&#10;PS C:\> gc&#10;PS C:\> type&#10;```&#10;'
[Get-Credential]:                                 #get-credential                                    '```&#10;PS C:\> Get-Credential&#10;```&#10;'
[Get-Disk]:                                       #get-disk                                          '```&#10;PS C:\> Get-Disk&#10;```&#10;'
[Get-DistributionGroupMember]:                    #get-distributiongroupmember                       '```&#10;PS C:\> Get-DistributionGroupMember&#10;```&#10;View members of distribution groups and mail-enabled security groups'
[Get-Help]:                                       #get-help                                          '```&#10;PS C:\> Get-Help&#10;```&#10;Display help file for cmdlets'
[Get-History]:                                 #get-history                                       '```&#10;PS C:\> Get-History&#10;PS C:\> h&#10;PS C:\> history&#10;PS C:\> ghy&#10;```&#10;Display history of inputted commands'
[Get-Item]:                                       #get-item                                          '```&#10;PS C:\> Get-Item&#10;```&#10;'
[Get-Location]:                                   #get-location                                      '```&#10;PS C:\> Get-Location&#10;```&#10;'
[Get-Member]:                                  #get-member                                        '```&#10;PS C:\> Get-Member&#10;PS C:\> gm&#10;```&#10;Display properties and methods of a Powershell object'
[Get-Module]:                                  #get-module                                        '```&#10;PS C:\> Get-Module&#10;PS C:\> gmo&#10;```&#10;Display currently loaded Powershell modules'
[Get-NetAdapter]:                                 #get-netadapter                                    '```&#10;PS C:\> Get-NetAdapter&#10;```&#10;Display available network interfaces'
[Get-NetFirewallRule]:                            #get-netfirewallrule                               '```&#10;PS C:\> Get-NetFirewallRule&#10;```&#10;'
[Get-NetIpConfiguration]:                      #get-netipconfiguration                            '```&#10;PS C:\> Get-NetIpConfiguration&#10;PS C:\> gip&#10;```&#10;Produce output similar to `ipconfig`'
[Get-PSDrive]:                                 #get-psdrive                                       '```&#10;PS C:\> Get-PSDrive&#10;PS C:\> gdr&#10;```&#10;Display mapped drives'
[Get-PSReadlineOption]:                           #get-psreadlineoption                              '```&#10;PS C:\> Get-PSReadlineOption&#10;```&#10;'
[Get-PSSession]:                               #get-pssession                                     '```&#10;PS C:\> Get-PSSession&#10;PS C:\> gsn&#10;```&#10;Get the Windows Powershell sessions on local and remote computers'
[Get-Partition]:                                  #get-partition                                     '```&#10;PS C:\> Get-Partition&#10;```&#10;'
[Get-Process]:                                 #get-process                                       '```&#10;PS C:\> Get-Process&#10;PS C:\> gps ps&#10;```&#10;Display running processes'
[Get-Service]:                                 #get-service                                       '```&#10;PS C:\> Get-Service&#10;PS C:\> gsv&#10;```&#10;Display services'
[Get-SmbOpenFile]:                                get-smbopenfile#get-smbopenfile                    '```&#10;PS C:\> Get-SmbOpenFile&#10;```&#10;Retrieve basic information about the files that are open on behalf of the clients of the Server Message Block (SMB) server&#10;"Get-SmbOpenFile". _Microsoft Docs_.'
[Get-SmigServerFeature]:                          #get-smigserverfeature                             '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-WMIObject]:                                  #get-wmiobject                                     '```&#10;PS C:\> Get-WMIObject&#10;```&#10;'
[Get-WindowsFeature]:                             #get-windowsfeature                                '```&#10;PS C:\> Get-WindowsFeature&#10;```&#10;'
[Import-CliXml]:                                  #import-clixml                                     '```&#10;PS C:\> Import-CliXml&#10;```&#10;Import a Common Language Infrastructure (CLI) XML file with data that represents Microsoft .NET Framework objects and create PowerShell objects from it'
[Import-Csv]:                                  #import-csv                                        '```&#10;PS C:\> Import-Csv&#10;PS C:\> ipcsv&#10;```&#10;'
[Import-Module]:                               #import-module                                     '```&#10;PS C:\> Import-Module&#10;PS C:\> ipmo&#10;```&#10;'
[Import-SmigServerSetting]:                       #import-smigserversetting                          '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Install-Module]:                                 #install-module                                    '```&#10;PS C:\> Install-Module&#10;```&#10;'
[Invoke-GPUpdate]:                                #invoke-gpupdate                                   '```&#10;PS C:\> Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'
[Invoke-WebRequest]:                              #invoke-webrequest                                 '```&#10;PS C:\> Invoke-WebRequest&#10;```&#10;'
[Measure-Object]:                                 #measure-object                                    '```&#10;PS C:\> Measure-Object&#10;```&#10;Calculates the numeric properties of objects, and the characters, words, and lines in string objects, such as files of text.'
[New-Alias]:                                   #new-alias                                         '```&#10;PS C:\> New-Alias&#10;PS C:\> nal&#10;```&#10;Create a new alias'
[New-Guid]:                                       #new-guid                                          '```&#10;PS C:\> New-Guid&#10;```&#10;'
[New-Item]:                                       #new-item                                          '```&#10;PS C:\> New-Item&#10;```&#10;'
[New-NetFirewallRule]:                            #new-netfirewallrule                               '```&#10;PS C:\> New-NetFirewallRule&#10;```&#10;'
[New-NetIpAddress]:                               #new-netipaddress                                  '```&#10;PS C:\> New-NetIpAddress&#10;```&#10;Manually configure network interface, if a DHCP server is unavailable'
[New-Object]:                                     #new-object                                        '```&#10;PS C:\> New-Object&#10;```&#10;Create an instance of a Microsoft .NET Framework or COM object'
[New-PSSession]:                               #new-pssession                                     '```&#10;PS C:\> New-PSSession&#10;PS C:\> nsn&#10;```&#10;Start a new remote PowerShell session with a remote computer'
[New-PSSession]:                               #new-pssession                                     '```&#10;PS C:\> New-PSSession&#10;PS C:\> nsn&#10;```&#10;Start a new remote PowerShell session with a remote computer'
[New-Partition]:                                  #new-partition                                     '```&#10;PS C:\> New-Partition&#10;```&#10;'
[New-SmbShare]:                                   #new-smbshare                                      '```&#10;PS C:\> New-SmbShare&#10;```&#10;'
[New-VFD]:                                        #new-vfd                                           '```&#10;PS C:\> New-VFD&#10;```&#10;Creates a virtual floppy disk.'
[Out-Null]:                                       #out-null                                          '```&#10;PS C:\> Out-Null&#10;```&#10;Delete output instead of sending it down the pipeline'
[Receive-SmigServerData]:                         #receive-smigserverdata                            '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Remove-Item]:                                 #remove-item                                       '```&#10;PS C:\> Remove-Item&#10;PS C:\> rm&#10;PS C:\> ri&#10;PS C:\> rmdir&#10;PS C:\> rd&#10;PS C:\> del&#10;```&#10;'
[Remove-Partition]:                               #remove-partition                                  '```&#10;PS C:\> Remove-Partition&#10;```&#10;'
[Rename-Computer]:                                #rename-computer                                   '```&#10;PS C:\> Rename-Computer&#10;```&#10;'
[Resolve-DNSName]:                                #resolve-dnsname                                   '```&#10;PS C:\> Resolve-DNSName&#10;```&#10;...&#10;MeasureUp Practice Lab: Security+'
[Restart-Computer]:                               #restart-computer                                  '```&#10;PS C:\> Restart-Computer&#10;```&#10;'
[Select-Object]:                               #select-object                                     '```&#10;PS C:\> Select-Object&#10;PS C:\> sc&#10;```&#10;Select object or object properties'
[Send-SmigServerData]:                            #send-smigserverdata                               '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Set-Alias]:                                      #set-alias                                         '```&#10;PS C:\> Set-Alias&#10;```&#10;'
[Set-Clipboard]:                               #set-clipboard                                     '```&#10;PS C:\> Set-Clipboard&#10;PS C:\> scb&#10;```&#10;Set the current Windows clipboard entry'
[Set-DhcpServerv4OptionValue]:                    #set-dhcpserverv4optionvalue                       '```&#10;PS C:\> Set-DhcpServerv4OptionValue&#10;```&#10;'
[Set-DnsClientServerAddress]:                     #set-dnsclientserveraddress                        '```&#10;PS C:\> Set-DnsClientServerAddress&#10;```&#10;Set DNS server addresses associated with the TCP/IP properties on an interface'
[Set-ExecutionPolicy]:                            #set-executionpolicy                               '```&#10;PS C:\> Set-ExecutionPolicy&#10;```&#10;Change user preference for the Windows PowerShell execution policy'
[Set-Location]:                                 #set-location                                      '```&#10;PS C:\> Set-Location&#10;PS C:\> cd&#10;```&#10;Set present working directory'
[Set-NetFirewallRule]:                            #set-netfirewallrule                               '```&#10;PS C:\> Set-NetFirewallRule&#10;```&#10;'
[Set-PSReadlineOption]:                           #set-psreadlineoption                              '```&#10;PS C:\> Set-PSReadlineOption&#10;```&#10;'
[Set-Service]:                                    #set-service                                       '```&#10;PS C:\> Set-Service&#10;```&#10;Starts, stops, and suspends a service, and changes its properties'
[Start-DscConfiguration]:                      #start-dscconfiguration                            '```&#10;PS C:\> Start-DscConfiguration&#10;PS C:\> sacfg&#10;```&#10;Apply configuration to nodes'
[Start-Job]:                                   #start-job                                         '```&#10;PS C:\> Start-Job&#10;PS C:\> sajb&#10;```&#10;'
[Start-Service]:                               #start-service                                     '```&#10;PS C:\> Start-Service&#10;PS C:\> sasv&#10;```&#10;Start one or more stopped services'
[Stop-Computer]:                                  #stop-computer                                     '```&#10;PS C:\> Stop-Computer&#10;```&#10;'
[Stop-Service]:                                #stop-service                                      '```&#10;PS C:\> Stop-Service&#10;PS C:\> spsv&#10;```&#10;Stop one or more services'
[Update-DistributionGroupMember]:                 #update-distributiongroupmember                    '```&#10;PS C:\> Update-DistributionGroupMember&#10;```&#10;Replace all members of distribution groups and mail-enabled security groups'
[Update-Help]:                                    #update-help                                       '```&#10;PS C:\> Update-Help&#10;```&#10;Download help files'
[Where-Object]:                                 #where-object                                      '```&#10;PS C:\> Where-Object&#10;PS C:\> ?&#10;PS C:\> where&#10;```&#10;Select objects from a collection based on their property values'
[Write-Host]:                                     #write-host                                        '```&#10;PS C:\> Write-Host&#10;```&#10;'
[Write-Output]:                                #write-output                                      '```&#10;PS C:\> Write-Output&#10;PS C:\> echo&#10;PS C:\> write&#10;```&#10;Send the specified objects to the next command in the pipeline. If the command is the last command in the pipeline, the objects are displayed in the console'



[Search-ADAccount]:                                  #search-adaccount                             "`Search-ADAccount`"
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
[Search-ADAccount]:                                  #search-adaccount                             "`Search-ADAccount`"
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
[Checkpoint-VM]:                                     #checkpoint-vm                                '`Checkpoint-VM`&#10;Creates a checkpoint of a virtual machine.'
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

<!-- Cmdlets from 70-740 -->
[Export-SmigServerSetting]:    #export-smigserversetting       '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-SmigServerFeature]:       #get-smigserverfeature          '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Import-SmigServerSetting]:    #import-smigserversetting       '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Receive-SmigServerData]:      #receive-smigserverdata         '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Send-SmigServerData]:         #send-smigserverdata            '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[New-NanoServerImage]: #nanoserverimage '```&#10;PS C:\> New-NanoServerImage&#10;PS C:\> New-NanoServerImage -DeploymentType guest|host -Edition standard|datacenter -MediaPath root -TargetPath $PATH -ComputerName $NAME&#10;```&#10;Used to create a Nano Server VHD file for Nano Server installation&#10;Required parameters:&#10;  `DeploymentType` specified whether the image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;  `Edition` specifies whether to install the Standard or Datacenter edition of Nano Server&#10;  `MediaPath` specifies the path to the root of the WS2016 installation disk or mounted image&#10;  `BasePath` specifies a path on the local system where the cmdlet creates a copy of the installation files from the location specified in `MediaPath`&#10;  `TargetPath` specifies the full path and filename of the new image to be created with the filename extension (".vhd" or ".vhdx") specifying Generation 1 or Generation 2 image.&#10;  `ComputerName` specifies the computer name that should be assigned to the new image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[Edit-NanoServerImage]: #nanoserverimage '```&#10;PS C:\> Edit-NanoServerImage&#10;```&#10;Add a role or feature to an existing Nano Server VHD file&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Add-AppxProvisionedPackage]: #add-appxprovisionedpackage '```&#10;PS C:\> Add-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsDriver]: #add-windowsdriver '```&#10;PS C:\> Add-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-Drive`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsImage]: #add-windowsimage '```&#10;PS C:\> Add-WindowsImage&#10;```&#10;&#10;Equivalent to `dism.exe /Append-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsPackage]: #add-windowspackage '```&#10;PS C:\> Add-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Apply-WindowsUnattend]: #apply-windowsunattend '```&#10;PS C:\> Apply-WindowsUnattend&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Apply-Unattend`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Disable-WindowsOptionalFeature]: #disable-windowsoptionalfeature '```&#10;PS C:\> Disable-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Disable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Dismount-WindowsImage]: #dismount-windowsimage '```&#10;PS C:\> Dismount-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Unmount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Enable-WindowsOptionalFeature]: #enable-windowsoptionalfeature '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Enable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Expand-WindowsImage]: #expand-windowsimage '```&#10;PS C:\> Expand-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Apply-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsDriver]: #export-windowsdriver '```&#10;PS C:\> Export-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Export-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsImage]: #export-windowsimage '```&#10;PS C:\> Export-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Export-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-AppxProvisionedPackage]: #get-appxprovisionedpackage '```&#10;PS C:\> Get-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-ProvisionedAppxPackages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsDriver]: #get-windowsdriver '```&#10;PS C:\> Get-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Drivers`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsImage]: #get-windowsimage '```&#10;PS C:\> Get-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Get-ImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsImageContent]: #get-windowsimagecontent '```&#10;PS C:\> Get-WindowsImageContent&#10;```&#10;&#10;Equivalent to `Dism.exe /List-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsOptionalFeature]: #get-windowsoptionalfeature '```&#10;PS C:\> Get-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Features`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsPackage]: #get-windowspackage '```&#10;PS C:\> Get-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Mount-WindowsImage]: #mount-windowsimage '```&#10;PS C:\> Mount-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Mount-image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[New-WindowsImage]: #new-windowsimage '```&#10;PS C:\> New-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Capture-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-AppxProvisionedPackage]: #remove-appxprovisionedpackage '```&#10;PS C:\> Remove-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsDriver]: #remove-windowsdriver '```&#10;PS C:\> Remove-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsImage]: #remove-windowsimage '```&#10;PS C:\> Remove-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Remove-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-WindowsPackage]: #remove-windowspackage '```&#10;PS C:\> Remove-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Save-WindowsImage]: #save-windowsimage '```&#10;PS C:\> Save-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Commit-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Set-AppxProvisionedDataFile]: #set-appxprovisioneddatafile '```&#10;PS C:\> Set-AppxProvisionedDataFile&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Set-ProvisionedAppxDataFile`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'

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
[`a`  ](#cmdlet-verbs  "```&#10;PS C:\> Add-&#10;```") [`ap`](# "`Approve-`&#10;Confirms or agrees to the status of a resource or process.") 
[`as` ](#cmdlet-verbs  "```&#10;PS C:\> Assert-&#10;```&#10;Affirms the state of a resource.") 
[`ba` ](#cmdlet-verbs  "```&#10;PS C:\> Backup-&#10;```&#10;Stores data by replicating it.") 
[`bd` ](#cmdlet-verbs  "```&#10;PS C:\> Build-&#10;```&#10;Creates an artifact (usually a binary or document) out of some set of input files (usually source code or declarative documents)") 
[`bl` ](#cmdlet-verbs  "```&#10;PS C:\> Block-&#10;```&#10;Restricts access to a resource. This verb is paired with Unblock.") 
[`cc` ](#cmdlet-verbs  "```&#10;PS C:\> Connect-&#10;```&#10;Creates a link between a source and a destination. This verb is paired with Disconnect.") 
[`cf` ](#cmdlet-verbs  "```&#10;PS C:\> Convertfrom-&#10;```&#10;Converts one primary type of input (the cmdlet noun indicates the input) to one or more supported output types.") 
[`ch` ](#cmdlet-verbs  "```&#10;PS C:\> Checkpoint-&#10;```&#10;Creates a snapshot of the current state of the data or of its configuration.") 
[`cm` ](#cmdlet-verbs  "```&#10;PS C:\> Compress-&#10;```&#10;Compacts the data of a resource. Pairs with Expand.") 
[`cn` ](#cmdlet-verbs  "```&#10;PS C:\> Confirm-&#10;```&#10;Acknowledges, verifies, or validates the state of a resource or process.") 
[`cp` ](#cmdlet-verbs  "```&#10;PS C:\> Complete-&#10;```&#10;Concludes an operation.&#10;---&#10;`Copy-`&#10;Copies a resource to another name or to another container. For example, the Copy-Item cmdlet that is used to access stored data copies an item from one location in the data store to another location.") 
[`cr` ](#cmdlet-verbs  "```&#10;PS C:\> Compare-&#10;```&#10;Evaluates the data from one resource against the data from another resource.") 
[`cs` ](#cmdlet-verbs  "```&#10;PS C:\> Close-&#10;```") 
[`ct` ](#cmdlet-verbs  "```&#10;PS C:\> Convertto-&#10;```&#10;Converts from one or more types of input to a primary output type (the cmdlet noun indicates the output type).") 
[`cv` ](#cmdlet-verbs  "```&#10;PS C:\> Convert-&#10;```&#10;Changes the data from one representation to another when the cmdlet supports bidirectional conversion or when the cmdlet supports conversion between multiple data types.") 
[`d`  ](#cmdlet-verbs  "```&#10;PS C:\> Disable-&#10;```&#10;Configures a resource to an unavailable or inactive state. For example, the Disable-PSBreakpoint cmdlet makes a breakpoint inactive. This verb is paired with Enable.") 
[`db` ](#cmdlet-verbs  "```&#10;PS C:\> Debug-&#10;```&#10;Examines a resource to diagnose operational problems.") 
[`dc` ](#cmdlet-verbs  "```&#10;PS C:\> Disconnect-&#10;```&#10;Breaks the link between a source and a destination. This verb is paired with Connect.") 
[`dm` ](#cmdlet-verbs  "```&#10;PS C:\> Dismount-&#10;```&#10;Detaches a named entity from a location. This verb is paired with Mount.") 
[`dn` ](#cmdlet-verbs  "```&#10;PS C:\> Deny-&#10;```&#10;Refuses, objects, blocks, or opposes the state of a resource or process.") 
[`dp` ](#cmdlet-verbs  "```&#10;PS C:\> Deploy-&#10;```&#10;Sends an application, website, or solution to a remote target[s] in such a way that a consumer of that solution can access it after deployment is complete") 
[`e`  ](#cmdlet-verbs  "```&#10;PS C:\> Enable-&#10;```&#10;Configures a resource to an available or active state. For example, the Enable-PSBreakpoint cmdlet makes a breakpoint active. This verb is paired with Disable.") 
[`ed` ](#cmdlet-verbs  "```&#10;PS C:\> Edit-&#10;```&#10;Modifies existing data by adding or removing content.") 
[`en` ](#cmdlet-verbs  "```&#10;PS C:\> Expand-&#10;```&#10;Restores the data of a resource that has been compressed to its original state. This verb is paired with Compress.") 
[`ep` ](#cmdlet-verbs  "```&#10;PS C:\> Export-&#10;```&#10;Encapsulates the primary input into a persistent data store, such as a file, or into an interchange format. This verb is paired with Import.") 
[`et` ](#cmdlet-verbs  "```&#10;PS C:\> Enter-&#10;```") 
[`ex` ](#cmdlet-verbs  "```&#10;PS C:\> Exit-&#10;```") 
[`f`  ](#cmdlet-verbs  "```&#10;PS C:\> Format-&#10;```") 
[`g`  ](#cmdlet-verbs  "```&#10;PS C:\> Get-&#10;``") 
[`gp` ](#cmdlet-verbs  "```&#10;PS C:\> Group-&#10;```&#10;Arranges or associates one or more resources.") 
[`gr` ](#cmdlet-verbs  "```&#10;PS C:\> Grant-&#10;```&#10;Allows access to a resource. This verb is paired with Revoke.") 
[`h`  ](#cmdlet-verbs  "```&#10;PS C:\> Hide-&#10;```") 
[`i`  ](#cmdlet-verbs  "```&#10;PS C:\> Invoke-&#10;```&#10;Performs an action, such as running a command or a method.") 
[`in` ](#cmdlet-verbs  "```&#10;PS C:\> Initialize-&#10;```&#10;Prepares a resource for use, and sets it to a default state.") 
[`ip` ](#cmdlet-verbs  "```&#10;PS C:\> Import-&#10;```&#10;Creates a resource from data that is stored in a persistent data store (such as a file) or in an interchange format. For example, the Import-CSV cmdlet imports data from a comma-separated value (CSV) file to objects that can be used by other cmdlets. This verb is paired with Export.") 
[`is` ](#cmdlet-verbs  "```&#10;PS C:\> Install-&#10;```&#10;Places a resource in a location, and optionally initializes it. This verb is paired with Uninstall.") 
[`j`  ](#cmdlet-verbs  "```&#10;PS C:\> Join-&#10;```") 
[`l`  ](#cmdlet-verbs  "```&#10;PS C:\> Limit-&#10;```&#10;Applies constraints to a resource.") 
[`lk` ](#cmdlet-verbs  "```&#10;PS C:\> Lock-&#10;```") 
[`m`  ](#cmdlet-verbs  "```&#10;PS C:\> Move`&#10;``") 
[`mg` ](#cmdlet-verbs  "```&#10;PS C:\> Merge-&#10;```&#10;Creates a single resource from multiple resources.") 
[`ms` ](#cmdlet-verbs  "```&#10;PS C:\> Measure-&#10;```&#10;Identifies resources that are consumed by a specified operation, or retrieves statistics about a resource.") 
[`mt` ](#cmdlet-verbs  "```&#10;PS C:\> Mount-&#10;```&#10;Attaches a named entity to a location. This verb is paired with Dismount.") 
[`n`  ](#cmdlet-verbs  "```&#10;PS C:\> New-&#10;```&#10;Creates a resource. (The `Set-` verb can also be used when creating a resource that includes data, such as the `Set-Variable` cmdlet.)") 
[`o`  ](#cmdlet-verbs  "```&#10;PS C:\> Out-&#10;```&#10;Sends data out of the environment. For example, the Out-Printer cmdlet sends data to a printer.") 
[`op` ](#cmdlet-verbs  "```&#10;PS C:\> Open-&#10;```") 
[`om` ](#cmdlet-verbs  "```&#10;PS C:\> Optimize-&#10;```") 
[`pb` ](#cmdlet-verbs  "```&#10;PS C:\> Publish-&#10;```&#10;Makes a resource available to others. This verb is paired with Unpublish.") 
[`pi` ](#cmdlet-verbs  "```&#10;PS C:\> Ping-&#10;```&#10;Use the Test verb.") 
[`pop`](#cmdlet-verbs  "```&#10;PS C:\> Pop-&#10;```") 
[`pt` ](#cmdlet-verbs  "```&#10;PS C:\> Protect-&#10;```&#10;Safeguards a resource from attack or loss. This verb is paired with Unprotect.") 
[`pu` ](#cmdlet-verbs  "```&#10;PS C:\> Push-&#10;```") 
[`r`  ](#cmdlet-verbs  "```&#10;PS C:\> Remove-&#10;```") 
[`rc` ](#cmdlet-verbs  "```&#10;PS C:\> Receive-&#10;```&#10;Accepts information sent from a source. This verb is paired with Send.") 
[`rd` ](#cmdlet-verbs  "```&#10;PS C:\> Read-&#10;```&#10;Acquires information from a source. This verb is paired with Write.") 
[`re` ](#cmdlet-verbs  "```&#10;PS C:\> Redo-&#10;```") 
[`rg` ](#cmdlet-verbs  "```&#10;PS C:\> Register-&#10;```&#10;Creates an entry for a resource in a repository such as a database. This verb is paired with Unregister.") 
[`rk` ](#cmdlet-verbs  "```&#10;PS C:\> Revoke-&#10;```&#10;Specifies an action that does not allow access to a resource. This verb is paired with Grant.") 
[`rn` ](#cmdlet-verbs  "```&#10;PS C:\> Rename-&#10;```") 
[`rp` ](#cmdlet-verbs  "```&#10;PS C:\> Repair-&#10;```&#10;Restores a resource to a usable condition") 
[`rq` ](#cmdlet-verbs  "```&#10;PS C:\> Request-&#10;```&#10;Asks for a resource or asks for permissions.") 
[`rr` ](#cmdlet-verbs  "```&#10;PS C:\> Restore-&#10;```&#10;Sets a resource to a predefined state, such as a state set by Checkpoint. For example, the Restore-Computer cmdlet starts a system restore on the local computer.") 
[`rs` ](#cmdlet-verbs  "```&#10;PS C:\> Reset`&#10;``") 
[`rt` ](#cmdlet-verbs  "```&#10;PS C:\> Restart-&#10;```&#10;Stops an operation and then starts it again. For example, the Restart-Service cmdlet stops and then starts a service.") 
[`ru` ](#cmdlet-verbs  "```&#10;PS C:\> Resume-&#10;```&#10;Starts an operation that has been suspended. For example, the Resume-Service cmdlet starts a service that has been suspended. This verb is paired with Suspend.") 
[`rv` ](#cmdlet-verbs  "```&#10;PS C:\> Resolve-&#10;```&#10;Maps a shorthand representation of a resource to a more complete representation.")
[`s`  ](#cmdlet-verbs  "```&#10;PS C:\> Set-&#10;```") 
[`sa` ](#cmdlet-verbs  "```&#10;PS C:\> Start-&#10;```&#10;Initiates an operation. For example, the Start-Service cmdlet starts a service. This verb is paired with Stop.") 
[`sb` ](#cmdlet-verbs  "```&#10;PS C:\> Submit-&#10;```&#10;Presents a resource for approval.") 
[`sc` ](#cmdlet-verbs  "```&#10;PS C:\> Select-&#10;```") 
[`sd` ](#cmdlet-verbs  "```&#10;PS C:\> Send-&#10;```&#10;Delivers information to a destination. This verb is paired with Receive.") 
[`sh` ](#cmdlet-verbs  "```&#10;PS C:\> Show-&#10;```") 
[`sk` ](#cmdlet-verbs  "```&#10;PS C:\> Skip-&#10;```") 
[`sl` ](#cmdlet-verbs  "```&#10;PS C:\> Split-&#10;```") 
[`sp` ](#cmdlet-verbs  "```&#10;PS C:\> Stop-&#10;```&#10;Discontinues an activity. This verb is paired with Start.") 
[`sr` ](#cmdlet-verbs  "```&#10;PS C:\> Search-&#10;```") 
[`ss` ](#cmdlet-verbs  "```&#10;PS C:\> Suspend-&#10;```&#10;Pauses an activity. For example, the Suspend-Service cmdlet pauses a service. This verb is paired with Resume.") 
[`st` ](#cmdlet-verbs  "```&#10;PS C:\> Step-&#10;```") 
[`sv` ](#cmdlet-verbs  "```&#10;PS C:\> Save-&#10;```&#10;Preserves data to avoid loss.") 
[`sw` ](#cmdlet-verbs  "```&#10;PS C:\> Switch-&#10;```") 
[`sy` ](#cmdlet-verbs  "```&#10;PS C:\> Sync-&#10;```&#10;Assures that two or more resources are in the same state.") 
[`t`  ](#cmdlet-verbs  "```&#10;PS C:\> Test-&#10;```&#10;Verifies the operation or consistency of a resource.") 
[`tr` ](#cmdlet-verbs  "```&#10;PS C:\> Trace-&#10;```&#10;Tracks the activities of a resource.") 
[`u`  ](#cmdlet-verbs  "```&#10;PS C:\> Use-&#10;```&#10;Uses or includes a resource to do something.") 
[`ub` ](#cmdlet-verbs  "```&#10;PS C:\> Unpublish-&#10;```&#10;Makes a resource unavailable to others. This verb is paired with Publish.") 
[`ud` ](#cmdlet-verbs  "```&#10;PS C:\> Update-&#10;```&#10;Brings a resource up-to-date to maintain its state, accuracy, conformance, or compliance. For example, the Update-FormatData cmdlet updates and adds formatting files to the current PowerShell console.") 
[`uk` ](#cmdlet-verbs  "```&#10;PS C:\> Unlock-&#10;```") 
[`ul` ](#cmdlet-verbs  "```&#10;PS C:\> Unblock-&#10;```&#10;Removes restrictions to a resource. This verb is paired with Block.") [`un`](# "`Undo-`") 
[`up` ](#cmdlet-verbs  "```&#10;PS C:\> Unprotect-&#10;```&#10;Removes safeguards from a resource that were added to prevent it from attack or loss. This verb is paired with Protect.") 
[`ur` ](#cmdlet-verbs  "```&#10;PS C:\> Unregister-&#10;```&#10;Removes the entry for a resource from a repository. This verb is paired with Register.") 
[`us` ](#cmdlet-verbs  "```&#10;PS C:\> Uninstall-&#10;```&#10;Removes a resource from an indicated location. This verb is paired with Install.")
[`w`  ](#cmdlet-verbs  "```&#10;PS C:\> Wait-&#10;```&#10;Pauses an operation until a specified event occurs. For example, the Wait-Job cmdlet pauses operations until one or more of the background jobs are complete.") 
[`wc` ](#cmdlet-verbs  "```&#10;PS C:\> Watch-&#10;```") 
[`wr` ](#cmdlet-verbs  "```&#10;PS C:\> Write-&#10;```&#10;Adds information to a target. This verb is paired with Read.") 

###### Cmdlets
**`Alias`**&nbsp;[`ep`][Export-Alias]&nbsp;[`g`][Get-Alias]&nbsp;[`n`][New-Alias]&nbsp;[`s`][Set-Alias]&nbsp; 
**`Archive`**&nbsp;[`cm`][Compress-Archive]&nbsp;[`en`][Expand-Archive] 
**`AD`**
`Account`&nbsp;[`sr`][Search-ADAccount]&nbsp;[`uk`][Unlock-ADAccount]&nbsp; 
`AccountPassword`&nbsp;[`s`][Set-ADAccountPassword]&nbsp; 
`Object` [`s`][Set-ADObject]&nbsp; 
`OrganizationalUnit`&nbsp;[`g`][Get-ADOrganizationalUnit]&nbsp;[`n`][New-ADOrganizationalUnit]&nbsp;[`r`][Remove-ADOrganizationalUnit]&nbsp;[`s`][Set-ADOrganizationalUnit]&nbsp; 
`PrincipalGroupMembership`&nbsp;[`a`][Add-ADPrincipalGroupMembership]&nbsp;[`g`][Get-ADPrincipalGroupMembership]&nbsp; 
`User`&nbsp;[`g`][Get-ADUser]&nbsp;[`n`][New-ADUser] 
**`ADDS`**
`Domain`&nbsp;[`is`][Install-ADDSDomain]&nbsp; 
`DomainController`&nbsp;[`is`][Install-ADDSDomainController]&nbsp;[`us`][Uninstall-ADDSDomainController]&nbsp; 
`Forest`&nbsp;[`g`][Get-ADDSForest]&nbsp;[`is`][Install-ADDSForest]&nbsp; 
**`ChildItem`**&nbsp;[`g`][Get-ChildItem]&nbsp; 
**`Clipboard`**&nbsp;[`g`][Get-Clipboard]&nbsp;[`s`][Set-Clipboard]&nbsp; 
**`Computer`**&nbsp;[`a`][Add-Computer]&nbsp;[`rn`][Rename-Computer]&nbsp;[`rt`][Restart-Computer]&nbsp;[`sp`][Stop-Computer]&nbsp; 
**`Content`**&nbsp;[`a`][Add-Content]&nbsp; 
**`Credential`** [`g`][Get-Credential] 
**`Csv`**&nbsp;[`ep`][Export-Csv] [`ip`][Import-Csv] 
**`Disk`** [`g`][Get-Disk] 
**`DistributionGroupMember`**&nbsp;[`a`][Add-DistributionGroupMember]&nbsp;[`g`][Get-DistributionGroupMember]&nbsp;[`ud`][Update-DistributionGroupMember] 
**`DNS`**
`ClientServerAddress` [`s`][Set-DnsClientServerAddress] 
`Name`&nbsp;[`rv`][Resolve-DNSName] 
**`DhcpServer`**
`InDC` [`a`][Add-DhcpServerInDC] 
`V4Scope` [`a`][Add-DhcpServerv4Scope] 
`v4OptionValue` [`s`][Set-DhcpServerv4OptionValue]
**`ExecutionPolicy`**&nbsp;[`s`][Set-ExecutionPolicy] 
**`GPUpdate`**&nbsp;[`i`][Invoke-GPUpdate] 
**`Guid`**&nbsp;[`n`][New-Guid] 
**`Help`**&nbsp;[`g`][Get-Help] [`ud`][Update-Help] 
**`History`**&nbsp;[`g`][Get-History]
**`Item`**&nbsp;[`cp`][Copy-Item] [`g`][Get-Item] [`n`][New-Item] [`r`][Remove-Item] 
**`List`**&nbsp;[`f`][Format-List] 
**`Location`**&nbsp;[`g`][Get-Location] [`s`][Set-Location] 
**`Module`**&nbsp;[`ip`][Import-Module]&nbsp;[`is`][Install-Module] 
**`NanoServerImage`** [`n`][New-NanoServerImage] [`e`][Edit-NanoServerImage]
**`NetAdapter`**&nbsp;[`g`][Get-NetAdapter] 
**`NetFirewallRule`**&nbsp;[`g`][Get-NetFirewallRule] [`n`][New-NetFirewallRule] [`s`][Set-NetFirewallRule] 
**`NetIpAddress`**&nbsp;[`n`][New-NetIpAddress] 
**`NetIpConfiguration`**&nbsp;[`g`][Get-NetIpConfiguration] 
**`Null`**&nbsp;[`o`][Out-Null] 
**`Object`**&nbsp;[`ForEach`][ForEach-Object] [`n`][New-Object] [`sc`][Select-Object] [`w`][Where-Object] 
**`Output`**&nbsp;[`wr`][Write-Output] 
**`Partition`**&nbsp;[`g`][Get-Partition] [`n`][New-Partition] [`r`][Remove-Partition] 
**`PS`**
`ReadlineOption` [`g`][Get-PSReadlineOption] [`s`][Set-PSReadlineOption] 
`Session` [`dc`][Disconnect-PSSession] [`et`][Enter-PSSession] [`ex`][Exit-PSSession] [`g`][Get-PSSession] [`n`][New-PSSession] 
**`Service`** [`g`][Get-Service] [`s`][Set-Service] [`sa`][Start-Service] [`sp`][Stop-Service] 
**`SmbOpenFile`** [`cs`][Close-SmbOpenFile] [`g`][Get-SmbOpenFile] 
**`SmbShare`** [`n`][New-SmbShare] 
**`SmigServer`** 
`Data` [`rc`][Receive-SmigServerData] [`sd`][Send-SmigServerData] 
`Feature` [`g`][Get-SmigServerFeature]
`Setting` [`ex`][Export-SmigServerSetting] [`ip`][Import-SmigServerSetting] 
**`Table`** [`f`][Format-Table] 
**`Type`** [`a`][Add-Type] 
**`VM`**&nbsp;[`cr`][Compare-VM] [`db`][Debug-VM] [`ep`][Export-VM] [`g`][Get-VM] [`ip`][Import-VM] [`m`][Move-VM] [`ms`][Measure-VM] [`n`][New-VM] [`r`][Remove-VM] [`rn`][Rename-VM] [`rt`][Restart-VM] [`ru`][Resume-VM] [`s`][Set-VM] [`sa`][Start-VM] [`sp`][Stop-VM] [`ss`][Suspend-VM] [`sv`][Save-VM] 
`Firmware` [`s`][Set-VMFirmware] 
`Memory` [`s`][Set-VMMemory] 
`NetworkAdapter` [`s`][Set-VMNetworkAdapter] 
`Processor` [`s`][Set-VMProcessor] 
`Switch` [`n`][New-VMSwitch] 
**`Volume`** [`f`][Format-Volume] 
**`WebRequest`**&nbsp;[`Invoke`][Invoke-WebRequest] 
**`WMIObject`**&nbsp;[`g`][Get-WMIObject]
**`AppxProvisioned`** `DataFile`[`s`][Set-AppxProvisionedDataFile] `Package`[`a`][Add-AppxProvisionedPackage] [`g`][Get-AppxProvisionedPackage] [`r`][Remove-AppxProvisionedPackage] 
**`WindowsDriver`** [`a`][Add-WindowsDriver] [`ep`][Export-WindowsDriver] [`g`][Get-WindowsDriver] [`r`][Remove-WindowsDriver] 
**`WindowsFeature`** `Feature`&nbsp;[`a`][Add-WindowsFeature] [`g`][Get-WindowsFeature] `OptionalFeature`&nbsp;[`e`][Enable-WindowsOptionalFeature] 
**`WindowsImage`** [`a`][Add-WindowsImage] [`en`][Expand-WindowsImage] [`n`][New-WindowsImage] [`sv`][Save-WindowsImage] [`ep`][Export-WindowsImage] [`g`][Get-WindowsImage] [`mt`][Mount-WindowsImage] [`r`][Remove-WindowsImage] [`dm`][Dismount-WindowsImage] `Content` [`g`][Get-WindowsImageContent] 
**`WindowsOptionalFeature`** [`d`][Disable-WindowsOptionalFeature] [`e`][Enable-WindowsOptionalFeature] [`g`][Get-WindowsOptionalFeature] **`WindowsPackage`**[`a`][Add-WindowsPackage]  [`g`][Get-WindowsPackage] [`r`][Remove-WindowsPackage] 
**`WindowsUnattend`** [`Apply`][Apply-WindowsUnattend] 

###### Bash equivalents
[`$!`][&#36;&#36;] 
[`!$`][&#36;&#36;] 
[`$?`][&#36;?] 
[`&`][Start-Job] 
[`>>`][Add-Content] 
[`alias`][New-Alias] 
[`awk`][Select-Object] 
`bzip2` 
[`cat`][Get-Content] 
[`cd`][Set-Location] 
[`cp`][Copy-Item] 
[`echo`][Write-Host] 
[`find`][Get-ChildItem] 
[`grep`][Where-Object] 
[`less`](#out-host "`Out-Host -Paging`") 
[`ls`][Get-ChildItem] &bull; 
[`man`][Get-Help] 
[`mkdir`](#new-item "`New-Item -ItemType Directory`") 
[`more`](#out-host "`Out-Host -Paging`")
[`print`][Write-Host] 
[`printf`][Write-Host] 
[`pwd`][Get-Location]
[`reset`][Clear-Host] 
[`rm`][Remove-Item]
[`sed`][Select-Object] 
[`shutdown`][Stop-Computer][` -r`][Restart-Computer]
[`tail`][Get-Content] 
[`touch`][New-Item]
[`uniq`](#select-object "`Select-Object -Unique`")
[`wc`][Measure-Object] [`which`][Get-Command]

###### Variables
[`$_`][&#36;_] 
[`$?`][&#36;?] 
[`$^`][&#36;^] 
[`$$`][&#36;&#36;] 
[`$args`][$args] 
[`$HOME`][$HOME] 
[`$IsLinux`][$IsLinux] 
[`$IsMacOS`][$IsMacOS] 
[`$IsWindows`][$IsWindows] 
[`$PID`][$PID] 
[`$PSCulture`][$PSCulture] 
[`$PSVersionTable`][$PSVersionTable] 
[`$PWD`][$PWD]

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
### `NanoServerImage`
Options for configuring a network adapter

`InterfaceNameOrIndex`
`Ipv4Address`

#### `Edit-NanoServerImage`
[Edit-NanoServerImage -BasePath]:        #Edit-NanoServerImage          '```&#10;PS C:\> Edit-NanoServerImage -BasePath&#10;```&#10;Path on the local system where you have previously created a copy of the Nano Server installation files using `New-NanoServerImage -BasePath`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Edit-NanoServerImage -TargetPath]:        #Edit-NanoServerImage          '```&#10;PS C:\> Edit-NanoServerImage -TargetPath&#10;```&#10;Full path and filename of an existing Nano Server image to be modified&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Edit-NanoServerImage -Packages]:        #Edit-NanoServerImage          '```&#10;PS C:\> Edit-NanoServerImage -Packages&#10;```&#10;Nano Center packages to be installed to the image file specified in `-TargetPath`.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Edit-NanoServerImage -InterfaceNameOrIndex]: #Edit-NanoServerImage '```&#10;PS C:\> Edit-NanoServerImage -InterfaceNameOrIndex&#10;```&#10;Identify interface to which other settings should be applied&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[Edit-NanoServerImage -Ipv4Address]: #Edit-NanoServerImage '```&#10;PS C:\> Edit-NanoServerImage -Ipv4Address&#10;```&#10;Specify static IPv4 address to be assigned to the interface specified by `InterfaceNameOrIndex` parameter&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[Edit-NanoServerImage -Ipv4SubnetMask]: #Edit-NanoServerImage '```&#10;PS C:\> Edit-NanoServerImage -Ipv4SubnetMask&#10;```&#10;Specify subnet mask value associated with the IP address specified in `Ipv4Address`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[Edit-NanoServerImage -Ipv4Gateway]: #Edit-NanoServerImage '```&#10;PS C:\> Edit-NanoServerImage -Ipv4Gateway&#10;```&#10;Specify IP address of a router on the local network where the IP address specified in `Ipv4Address` is located, providing access to other networks&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[Edit-NanoServerImage -Ipv4Dns]: #Edit-NanoServerImage '```&#10;PS C:\> Edit-NanoServerImage -Ipv4Dns&#10;```&#10;Specify IP address of DNS server&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'

[`InterfaceNameOrIndex`][Edit-NanoServerImage -InterfaceNameOrIndex]
[`Ipv4Address`][Edit-NanoServerImage -Ipv4Address]
[`Ipv4SubnetMask`][Edit-NanoServerImage -Ipv4SubnetMask]
[`Ipv4Gateway`][Edit-NanoServerImage -Ipv4Gateway]
[`Ipv4Dns`][Edit-NanoServerImage -Ipv4Dns]
[`BasePath`][Edit-NanoServerImage -BasePath]
[`TargetPath`][Edit-NanoServerImage -TargetPath]
[`Packages`][Edit-NanoServerImage -Packages]

Add the Web Server (IIS) role to an image file. <sup>[Zacker][Zacker]: 49</sup>
```powershell
Edit-NanoServerImage -BasePath C:\nanoserver\base -TargetPAth C:\nanoserver\nano1.vhdx -Packages microsoft-nanoserver-iis-package
```
#### `New-NanoServerImage`
[New-NanoServerImage -DeploymentType]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -DeploymentType&#10;```&#10;Whether image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -Edition]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -Edition&#10;```&#10;""Standard"" or ""Datacenter"" edition of Nano Server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -MediaPath]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -MediaPath&#10;```&#10;Path to the root of the WS2016 installation disk or mounted image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -BasePath]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -BasePath&#10;```&#10;Path on the local system where the cmdlet cdreates a copy of the installation files from the location specified in `-MediaPath`.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -TargetPath]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -TargetPath&#10;```&#10;Full path and filename of the new image to be created, including the filename extension which specifies whether the new image should be Generation 1 (".vhd") or Generation 2 (".vhdx").&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -ComputerName]:         #New-NanoServerImage           '```&#10;PS C:\> New-NanoServerImage -ComputerName&#10;```&#10;Computer name that should be assigned to the new image.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -InterfaceNameOrIndex]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -InterfaceNameOrIndex&#10;```&#10;Identify interface to which other settings should be applied&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Address]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Address&#10;```&#10;Specify static IPv4 address to be assigned to the interface specified by `InterfaceNameOrIndex` parameter&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4SubnetMask]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4SubnetMask&#10;```&#10;Specify subnet mask value associated with the IP address specified in `Ipv4Address`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Gateway]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Gateway&#10;```&#10;Specify IP address of a router on the local network where the IP address specified in `Ipv4Address` is located, providing access to other networks&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Dns]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Dns&#10;```&#10;Specify IP address of DNS server&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'

[`BasePath`][New-NanoServerImage -BasePath]
[`ComputerName`][New-NanoServerImage -ComputerName]
[`DeploymentType`][New-NanoServerImage -DeploymentType]
[`Edition`][New-NanoServerImage -Edition]
[`InterfaceNameOrIndex`][New-NanoServerImage -InterfaceNameOrIndex]
[`Ipv4Address`][New-NanoServerImage -Ipv4Address]
[`Ipv4Dns`][New-NanoServerImage -Ipv4Dns]
[`Ipv4Gateway`][New-NanoServerImage -Ipv4Gateway]
[`Ipv4SubnetMask`][New-NanoServerImage -Ipv4SubnetMask]
[`MediaPath`][New-NanoServerImage -MediaPath]
[`TargetPath`][New-NanoServerImage -TargetPath]

Create a new Nano Server image with a static IP <sup>[Zacker][Zacker]: 52</sup>
```powershell
New-NanoServerImage -DeploymentType Guest -Edition Standard -MediaPath D:\ -TargetPath C:\temp\nanoserver4.vhdx -ComputerName nano4 -Domain contoso.com -InterfaceNameorIndex ethernet -Ipv4Address 192.168.10.41 -Ipv4SubnetMask 255.255.255.0 -Ipv4Gateway 192.168.10.1 -Ipv4Dns 192.168.10.2
```

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
### `Get-ComputerInfo`
Equivalent to output of [`HOSTNAME.exe`](README.md#hostname)
```pwsh
(Get-ComputerInfo).CsName
```
### `Get-Content`
Make a PowerShell object from a JSON file
```powershell
Get-Content -Path file.json | ConvertFrom-Json
```
### `Get-Disk`
### `Get-Help`
[Get-Help -Detailed]:           #Get-Help                      '```&#10;PS C:\> Get-Help -Detailed&#10;```&#10;Display detailed help for a command'
[Get-Help -Examples]:           #Get-Help                      '```&#10;PS C:\> Get-Help -Examples&#10;```&#10;Display usage examples'
[Get-Help -Online]:             #Get-Help                      '```&#10;PS C:\> Get-Help -Online&#10;```&#10;Navigate to online help page for a command.'
[Get-Help -ShowWindow]:         #Get-Help                      '```&#10;PS C:\> Get-Help -ShowWindow&#10;```&#10;Display help output in a window.'
[Get-Help -Full]:               #Get-Help                      '```&#10;PS C:\> Get-Help -Full&#10;```&#10;Display entire help file for a command'

[`Detailed`][Get-Help -Detailed]
[`Examples`][Get-Help -Examples]
[`Full`][Get-Help -Full]
[`Online`][Get-Help -Online]
[`ShowWindow`][Get-Help -ShowWindow]

### `Get-Member`
### `Get-Module`
### `Get-NetAdapter`
Display available network interfaces [<sup>Zacker: 19</sup>][Zacker]

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
### `Get-WindowsImage`
[Get-WindowsImage -Mounted]: #Get-WindowsImage '```&#10;PS C:\> Get-WindowsImage -Mounted&#10;```&#10;&#10;Equivalent to `Dism.exe /Get-MountedImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Mounted`][Get-WindowsImage -Mounted]

### `Get-WindowsOptionalFeature`
[Get-WindowsOptionalFeature -FeatureName]: #Get-WindowsOptionalFeature '```&#10;PS C:\> Get-WindowsOptionalFeature -FeatureName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Featureinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[`FeatureName`][Get-WindowsOptionalFeature -FeatureName]
### `Get-WindowsPackage`
[Get-WindowsPackage -PackagePath]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackagePath&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsPackage -PackageName]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackageName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[`PackageName`][Get-WindowsPackage -PackageName] 
[`PackagePath`][Get-WindowsPackage -PackagePath]
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
### `Mount-WindowsImage`
[Mount-WindowsImage -Remount]: #Mount-WindowsImage '```&#10;PS C:\> Mount-WindowsImage -Remount&#10;```&#10;&#10;Equivalent to `Dism.exe /Remount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Remount`][Mount-WindowsImage -Remount]

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
### `Item`
#### `New-Item`
```powershell
New-NetIPAddress 10.0.0.3 -InterfaceAlias "Ethernet' -PrefixLength 24
```
#### `Set-Item`
Add an IP address to the Trusted Hosts list, bypassing the use of Kerberos to authenticate the session <sup>[Zacker][Zacker]: 56</sup>
```powershell
Set-Item wsman:\localhost\client\trustedhosts "192.168.10.41"
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
### `New-VM`
Create a Nano Server VM from an image file [<sup>Zacker: 47</sup>][Zacker]
```powershell
New-VM -Name "nano2" -Generation 2 -MemoryStartupBytes 1GB -VHDPath "F:\hyper-v\virtual hard disks\nano2.vhdx"
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

