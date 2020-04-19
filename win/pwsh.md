[https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]: https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/ "SumTips.com - Manage disk partitions with Windows PowerShell"
[https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps '"Get-SmbOpenFile". _Microsoft Docs_.'
[https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps '"Close-SmbOpenFile". _Microsoft Docs_.'
[https://www.thewindowsclub.com/find-windows-product-key]:  https://www.thewindowsclub.com/find-windows-product-key "TheWindowsClub: \"How to find Windows Product Key using Command Prompt or PowerShell\""
[https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7]: https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7 "Working with Registry Entries"
[https://adamtheautomator.com/powershell-random-password/]: https://adamtheautomator.com/powershell-random-password/ "How to Generate a Random Password with PowerShell"
[https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]: https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/

[ADAC]:   https://github.com/jasper-zanjani/notes/master/sources/adac.md "Berkouwer, Sander. _Active Directory Administration Cookbook_."
[IMWS]:   https://github.com/jasper-zanjani/notes/master/sources/imws.md "McCabe, John. _Introduction to Microsoft Windows Server 2016_."
[Jones]:  https://subscription.packtpub.com/video/virtualization_and_cloud/9781789616385 "Jones, Joshua B. _Hands-On Powershell for Active Directory_. PacktPub: 2018."
[WSAC]:   https://github.com/jasper-zanjani/notes/master/sources/wsac.md "Krause, Jordan. _Windows Server 2016 Administration Cookbook_."
[Zacker]: https://github.com/jasper-zanjani/notes/master/certs/70-740.md "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."
[Holmes]: # 'Holmes, Lee. _Windows PowerShell Cookbook_. O\'Reilly Media, 2013.'
[SOPR]: https://leanpub.com/secretsofpowershellremoting 'Don Jones et al. _Secrets of Powershell Remoting_. '



# PowerShell
## Contents
### Concepts
##### Remoting
[WinRM]: # 'Windows Remote Management (WinRM)&#10;Microsoft implementation of the WSMAN protocol, which handles communications and authentication for connections for many applications.&#10;Unlike MMCs, which are based on DCOM (legacy technology), WinRM is considered firewall-friendly and is the preferred option'
[remoting]: # 'remoting&#10;term applied to the use of WinRM in Powershell over port 5985 (or 5986 for HTTPS)'
[endpoint]: # 'endpoint&#10;a particular configuration item in WinRM, representing a specific application for which WinRM can receive traffic'
[listener]: # 'listener&#10;configuration item in WinRM representing the ability of the service to accept incoming network traffic, associated with a TCP port number'
[explicit remoting]: # 'explicit remoting&#10;opening a temporary or persistent Powershell session to a remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 176'
[implicit remoting]: # 'implicit remoting&#10;running a cmdlet specifying the `ComputerName` parameter, which directs its function to the remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 177'

[external virtual switch]: # 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[internal virtual switch]: # 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[private virtual switch]: # 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'

Powershell [remoting][remoting] can be done [explicitly][explicit remoting] or [implicitly][implicit remoting].
Explicit remoting is also 1-to-1 remoting, where an interactive Powershell prompt is brought up on a remote computer.
One-to-many or fan-out remoting is possible with implicit remoting, where a command is transmitted to many computers 
Remoting relies on [WinRM][WinRM], which is Microsoft's implementation of WSMAN. 


### Tasks
- [**Display computer name**][Get-ComputerInfo]
- [**Remove Registry keys**][Remove-Item]
- [**Clear out `%temp%` folder**][Remove-Item]
- [**Reset AD user's password**][Set-ADAccountPassword]
- [**Generate password**](#generate-password)
- [Run `cmd` as admin][Start-Process]
- [Add a member to a group](#add-a-member-to-a-group)
- [Credentials](#credentials)
- [Formatting output](#output-formatting)
- [Hash tables](#hash-tables)
- [Manipulating files](#file-manipulation)
- [Text-to-speech](#text-to-speech)
- [New domain controller](#new-domain-controller)
- [Set new Registry keys](#registry)
- [Create a new VHDX file, mount and initialize it, and create and format a partition within it](#vhdx-file)
- [Restart Wi-Fi adapter](#restart-wi-fi-adapter)
- [Safely combine related Registry modifications](#registry)
- [Set DNS server to DHCP][Set-DnsClientServerAddress]
- [Add a local user to administrators](#add-a-new-local-admin)

##### 70-740 tasks
- [Create a virtual switch with SET enabled](#create-a-virtual-switch-with-set-enabled)
- [Implement nested virtualization](#implement-nested-virtualization)
- [Enable CredSSP](#enable-credssp)
- [Configure Server Core](#configure-server-core)
- [Implement Discrete Device Assignment](#implement-dda)
- [Create a S2D cluster](#configure-s2d-cluster)

### Cmdlets
##### Cmdlet verbs
[<code>&nbsp;a</code>](#cmdlet-verbs  "```&#10;PS C:\> Add-&#10;```") 
[`ap`](#cmdlet-verbs "`Approve-`&#10;Confirms or agrees to the status of a resource or process.") 
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
[<code>&nbsp;d</code>](#cmdlet-verbs  "```&#10;PS C:\> Disable-&#10;```&#10;Configures a resource to an unavailable or inactive state. For example, the Disable-PSBreakpoint cmdlet makes a breakpoint inactive. This verb is paired with Enable.") 
[`db` ](#cmdlet-verbs  "```&#10;PS C:\> Debug-&#10;```&#10;Examines a resource to diagnose operational problems.") 
[`dc` ](#cmdlet-verbs  "```&#10;PS C:\> Disconnect-&#10;```&#10;Breaks the link between a source and a destination. This verb is paired with Connect.") 
[`dm` ](#cmdlet-verbs  "```&#10;PS C:\> Dismount-&#10;```&#10;Detaches a named entity from a location. This verb is paired with Mount.") 
[`dn` ](#cmdlet-verbs  "```&#10;PS C:\> Deny-&#10;```&#10;Refuses, objects, blocks, or opposes the state of a resource or process.") 
[`dp` ](#cmdlet-verbs  "```&#10;PS C:\> Deploy-&#10;```&#10;Sends an application, website, or solution to a remote target[s] in such a way that a consumer of that solution can access it after deployment is complete") 
[<code>&nbsp;e</code>](#cmdlet-verbs  "```&#10;PS C:\> Enable-&#10;```&#10;Configures a resource to an available or active state. For example, the Enable-PSBreakpoint cmdlet makes a breakpoint active. This verb is paired with Disable.") 
[`ed` ](#cmdlet-verbs  "```&#10;PS C:\> Edit-&#10;```&#10;Modifies existing data by adding or removing content.") 
[`en` ](#cmdlet-verbs  "```&#10;PS C:\> Expand-&#10;```&#10;Restores the data of a resource that has been compressed to its original state. This verb is paired with Compress.") 
[`ep` ](#cmdlet-verbs  "```&#10;PS C:\> Export-&#10;```&#10;Encapsulates the primary input into a persistent data store, such as a file, or into an interchange format. This verb is paired with Import.") 
[`et` ](#cmdlet-verbs  "```&#10;PS C:\> Enter-&#10;```") 
[`ex` ](#cmdlet-verbs  "```&#10;PS C:\> Exit-&#10;```") 
[<code>&nbsp;f</code>](#cmdlet-verbs  "```&#10;PS C:\> Format-&#10;```") 
[<code>&nbsp;g</code>](#cmdlet-verbs  "```&#10;PS C:\> Get-&#10;``") 
[`gp` ](#cmdlet-verbs  "```&#10;PS C:\> Group-&#10;```&#10;Arranges or associates one or more resources.") 
[`gr` ](#cmdlet-verbs  "```&#10;PS C:\> Grant-&#10;```&#10;Allows access to a resource. This verb is paired with Revoke.") 
[<code>&nbsp;h</code>](#cmdlet-verbs  "```&#10;PS C:\> Hide-&#10;```") 
[<code>&nbsp;i</code>](#cmdlet-verbs  "```&#10;PS C:\> Invoke-&#10;```&#10;Performs an action, such as running a command or a method.") 
[`in` ](#cmdlet-verbs  "```&#10;PS C:\> Initialize-&#10;```&#10;Prepares a resource for use, and sets it to a default state.") 
[`ip` ](#cmdlet-verbs  "```&#10;PS C:\> Import-&#10;```&#10;Creates a resource from data that is stored in a persistent data store (such as a file) or in an interchange format. For example, the Import-CSV cmdlet imports data from a comma-separated value (CSV) file to objects that can be used by other cmdlets. This verb is paired with Export.") 
[`is` ](#cmdlet-verbs  "```&#10;PS C:\> Install-&#10;```&#10;Places a resource in a location, and optionally initializes it. This verb is paired with Uninstall.") 
[<code>&nbsp;j</code>](#cmdlet-verbs  "```&#10;PS C:\> Join-&#10;```") 
[<code>&nbsp;l</code>](#cmdlet-verbs  "```&#10;PS C:\> Limit-&#10;```&#10;Applies constraints to a resource.") 
[`lk` ](#cmdlet-verbs  "```&#10;PS C:\> Lock-&#10;```") 
[<code>&nbsp;m</code>](#cmdlet-verbs  "```&#10;PS C:\> Move`&#10;``") 
[`mg` ](#cmdlet-verbs  "```&#10;PS C:\> Merge-&#10;```&#10;Creates a single resource from multiple resources.") 
[`ms` ](#cmdlet-verbs  "```&#10;PS C:\> Measure-&#10;```&#10;Identifies resources that are consumed by a specified operation, or retrieves statistics about a resource.") 
[`mt` ](#cmdlet-verbs  "```&#10;PS C:\> Mount-&#10;```&#10;Attaches a named entity to a location. This verb is paired with Dismount.") 
[<code>&nbsp;n</code>](#cmdlet-verbs  "```&#10;PS C:\> New-&#10;```&#10;Creates a resource. (The `Set-` verb can also be used when creating a resource that includes data, such as the `Set-Variable` cmdlet.)") 
[<code>&nbsp;o</code>](#cmdlet-verbs  "```&#10;PS C:\> Out-&#10;```&#10;Sends data out of the environment. For example, the Out-Printer cmdlet sends data to a printer.") 
[`op` ](#cmdlet-verbs  "```&#10;PS C:\> Open-&#10;```") 
[`om` ](#cmdlet-verbs  "```&#10;PS C:\> Optimize-&#10;```") 
[`pb` ](#cmdlet-verbs  "```&#10;PS C:\> Publish-&#10;```&#10;Makes a resource available to others. This verb is paired with Unpublish.") 
[`pi` ](#cmdlet-verbs  "```&#10;PS C:\> Ping-&#10;```&#10;Use the Test verb.") 
[`pt` ](#cmdlet-verbs  "```&#10;PS C:\> Protect-&#10;```&#10;Safeguards a resource from attack or loss. This verb is paired with Unprotect.") 
[`pu` ](#cmdlet-verbs  "```&#10;PS C:\> Push-&#10;```") 
[<code>&nbsp;r</code>](#cmdlet-verbs  "```&#10;PS C:\> Remove-&#10;```") 
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
[<code>&nbsp;s</code>](#cmdlet-verbs  "```&#10;PS C:\> Set-&#10;```") 
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
[<code>&nbsp;t</code>](#cmdlet-verbs  "```&#10;PS C:\> Test-&#10;```&#10;Verifies the operation or consistency of a resource.") 
[`tr` ](#cmdlet-verbs  "```&#10;PS C:\> Trace-&#10;```&#10;Tracks the activities of a resource.") 
[<code>&nbsp;u</code>](#cmdlet-verbs  "```&#10;PS C:\> Use-&#10;```&#10;Uses or includes a resource to do something.") 
[`ub` ](#cmdlet-verbs  "```&#10;PS C:\> Unpublish-&#10;```&#10;Makes a resource unavailable to others. This verb is paired with Publish.") 
[`ud` ](#cmdlet-verbs  "```&#10;PS C:\> Update-&#10;```&#10;Brings a resource up-to-date to maintain its state, accuracy, conformance, or compliance. For example, the Update-FormatData cmdlet updates and adds formatting files to the current PowerShell console.") 
[`uk` ](#cmdlet-verbs  "```&#10;PS C:\> Unlock-&#10;```") 
[`ul` ](#cmdlet-verbs  "```&#10;PS C:\> Unblock-&#10;```&#10;Removes restrictions to a resource. This verb is paired with Block.") 
[`un`](#cmdlet-verbs "`Undo-`") 
[`up` ](#cmdlet-verbs  "```&#10;PS C:\> Unprotect-&#10;```&#10;Removes safeguards from a resource that were added to prevent it from attack or loss. This verb is paired with Protect.") 
[`ur` ](#cmdlet-verbs  "```&#10;PS C:\> Unregister-&#10;```&#10;Removes the entry for a resource from a repository. This verb is paired with Register.") 
[`us` ](#cmdlet-verbs  "```&#10;PS C:\> Uninstall-&#10;```&#10;Removes a resource from an indicated location. This verb is paired with Install.")
[<code>&nbsp;w</code>](#cmdlet-verbs  "```&#10;PS C:\> Wait-&#10;```&#10;Pauses an operation until a specified event occurs. For example, the Wait-Job cmdlet pauses operations until one or more of the background jobs are complete.") 
[`wc` ](#cmdlet-verbs  "```&#10;PS C:\> Watch-&#10;```") 
[`wr` ](#cmdlet-verbs  "```&#10;PS C:\> Write-&#10;```&#10;Adds information to a target. This verb is paired with Read.") 

##### Active Directory cmdlets
<!-- Active Directory cmdlets -->
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
[Set-ADAccountPassword]: #set-adaccountpassword '```&#10;PS C:\> Set-ADAccountPassword&#10;```&#10;'
[Get-ADObject]: #get-adobject '```&#10;PS C:\> Get-ADObject&#10;```&#10;Get one or more Active Directory objects'
[Set-ADObject]:                                      #set-adobject                                 "`Set-ADObject`"
[Set-ADOrganizationalUnit]:                          #set-adorganizationalunit                     "`Set-ADOrganizationalUnit`"
[Uninstall-ADDSDomainController]:                    #uninstall-addsdomaincontroller               "`Uninstall-ADDSDomainController`"
[Unlock-ADAccount]:                                  #unlock-adaccount                             "`Unlock-ADAccount`"
[Remove-ADOrganizationalUnit]:                       #remove-adorganizationalunit                  "`Remove-ADOrganizationalUnit`"
[Install-ADDSDomainController]: #install-addsdomaincontroller '```&#10;PS C:\> Install-ADDSDomainController&#10;```&#10;Installs a new domain controller in an Active Directory domain'
[Invoke-GPUpdate]: #invoke-gpupdate '```&#10;PS C:\> Invoke-GPUpdate&#10;```&#10;Schedule a remote Group Policy refresh on the specified host'
[Add-DistributionGroupMember]: #add-distributiongroupmember '```&#10;PS C:\> Add-DistributionGroupMember&#10;```&#10;Add a single recipient to distribution groups and mail-enabled security groups'
[Get-DistributionGroupMember]: #get-distributiongroupmember '```&#10;PS C:\> Get-DistributionGroupMember&#10;```&#10;View members of distribution groups and mail-enabled security groups'
[Update-DistributionGroupMember]: #update-distributiongroupmember '```&#10;PS C:\> Update-DistributionGroupMember&#10;```&#10;Replace all members of distribution groups and mail-enabled security groups'
[Add-ADGroupMember]: #add-adgroupmember '```&#10;Add-ADGroupMember&#10;```&#10;Add one or more members to an AD group&#10;Microsoft Docs. "Add-ADGroupMember".'

<code>DistributionGroupMember&nbsp;[a][Add-DistributionGroupMember]&nbsp;[g][Get-DistributionGroupMember]&nbsp;[ud][Update-DistributionGroupMember] </code> 
<code>GPUpdate&nbsp;[i][Invoke-GPUpdate]</code> 
[**AD**](#active-directory)
<code>Account&nbsp;[sr][Search-ADAccount]&nbsp;[uk][Unlock-ADAccount]&nbsp;</code> 
<code>AccountPassword&nbsp;[s][Set-ADAccountPassword]&nbsp;</code> 
<code>GroupMember&nbsp;[a][Add-ADGroupMember]</code>
<code>Object&nbsp;[g][Get-ADObject]&nbsp;[s][Set-ADObject]&nbsp;</code> 
<code>OrganizationalUnit&nbsp;[g][Get-ADOrganizationalUnit]&nbsp;[n][New-ADOrganizationalUnit]&nbsp;[r][Remove-ADOrganizationalUnit]&nbsp;[s][Set-ADOrganizationalUnit]&nbsp;</code> 
<code>PrincipalGroupMembership&nbsp;[a][Add-ADPrincipalGroupMembership]&nbsp;[g][Get-ADPrincipalGroupMembership]&nbsp;</code>
<code>User&nbsp;[g][Get-ADUser]&nbsp;[n][New-ADUser]&nbsp;[s][Set-ADUser]</code>
**ADDS**
<code>Domain&nbsp;[`is`][Install-ADDSDomain]</code>
<code>DomainController&nbsp;[is][Install-ADDSDomainController]&nbsp;[us][Uninstall-ADDSDomainController]</code>
<code>Forest&nbsp;[g][Get-ADDSForest]&nbsp;[is][Install-ADDSForest]&nbsp;</code>

##### Failover cluster cmdlets
<!-- Failover clusters -->
[Add-ClusterDisk]: #add-clusterdisk '```&#10;PS C:\> Add-ClusterDisk&#10;```&#10;Allow an admin to add a new disk to a failover cluster'
[Add-ClusterFileServerRole]: #add-clusterfileserverrole '```&#10;PS C:\> Add-ClusterFileServerRole&#10;```&#10;This command allows an admin to create a clustered file server'
[Add-ClusterGenericApplicationRole]: #add-clustergenericapplicationrole '```&#10;PS C:\> Add-ClusterGenericApplicationRole&#10;```&#10;Configures an application in the generic application role, providing high availability for an application not designed for use in a failover cluster.'
[Add-ClusterGroup]: #add-clustergroup '```&#10;PS C:\> Add-ClusterGroup&#10;```&#10;Allow an admin to add a resource group to the failover cluster'
[Add-ClusterNode]: #add-clusternode '```&#10;PS C:\> Add-ClusterNode&#10;```&#10;Allow an admin to add a node to a failover cluster'
[Add-ClusterResource]: #add-clusterresource '```&#10;PS C:\> Add-ClusterResource&#10;```&#10;Allow an admin to add a resource to a failover cluster'
[Add-ClusterResourceDependency]: #add-clusterresourcedependency '```&#10;PS C:\> Add-ClusterResourceDependency&#10;```&#10;Add a resource dependency to a failover cluster'
[Add-ClusterServerRole]: #add-clusterserverrole '```&#10;PS C:\> Add-ClusterServerRole&#10;```&#10;Add the cluster server role to a server'
[Block-ClusterAccess]: #block-clusteraccess '```&#10;PS C:\> Block-ClusterAccess&#10;```&#10;Block the specified users from accessing a cluster'
[Get-Cluster]: #get-cluster '```&#10;PS C:\> Get-Cluster&#10;```&#10;Display information about a failover cluster'
[Get-ClusterAccess]: #get-clusteraccess '```&#10;PS C:\> Get-ClusterAccess&#10;```&#10;Display permissions for a failover cluster'
[Get-ClusterNode]: #get-clusternode '```&#10;PS C:\> Get-ClusterNode&#10;```&#10;Display information about the servers in a failover cluster'
[Get-ClusterQuorum]: #get-clusterquorum '```&#10;PS C:\> Get-ClusterQuorum&#10;```&#10;Display cluster quorum in a cluster'
[New-Cluster]: #new-cluster '```&#10;PS C:\> New-Cluster&#10;```&#10;Create a new failover cluster'
[Remove-Cluster]: #remove-cluster '```&#10;PS C:\> Remove-Cluster&#10;```&#10;Remove a failover cluster'
[Remove-ClusterAccess]: #remove-clusteraccess '```&#10;PS C:\> Remove-ClusterAccess&#10;```&#10;Remove user access from the cluster'
[Remove-ClusterNode]: #remove-clusternode '```&#10;PS C:\> Remove-ClusterNode&#10;```&#10;Remove a node from a failover cluster'
[Set-ClusterQuorum]: #set-clusterquorum '```&#10;PS C:\> Set-ClusterQuorum&#10;```&#10;Configures quorum options for a failover cluster.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 318'
[Start-Cluster]: #start-cluster '```&#10;PS C:\> Start-Cluster&#10;```&#10;Start the Cluster service on all nodes'
[Stop-Cluster]: #stop-cluster '```&#10;PS C:\> Stop-Cluster&#10;```&#10;Stop the Cluster service on all nodes'
[Stop-ClusterNode]: #stop-clusternode '```&#10;PS C:\> Stop-ClusterNode&#10;```&#10;Stop the Cluster service on a node'
[Test-Cluster]: #test-cluster '```&#10;PS C:\> Test-Cluster&#10;```&#10;Complete validation tests for a cluster'
[Add-ClusterScaleOutFileServer]: #add-clusterscaleoutfileserver '```&#10;PS C:\> Add-ClusterScaleOutFileServer&#10;```&#10;Install the Scale-out File Server role&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 339'
[Suspend-ClusterNode]: #suspend-clusternode '```&#10;PS C:\> Suspend-ClusterNode&#10;```&#10;Pause the activity of a failover cluster node&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 374'
[Enable-ClusterStorageSpacesDirect]: #enable-clusterstoragespacesdirect '```&#10;PS C:\> Enable-ClusterStorageSpacesDirect&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 354'

[**Cluster**](#failover-clusters)
<code>[g][Get-Cluster]&nbsp;[n][New-Cluster]&nbsp;[r][Remove-Cluster]&nbsp;[sa][Start-Cluster]&nbsp;[sp][Stop-Cluster]&nbsp;[t][Test-Cluster]</code>
<code>Access&nbsp;[b][Block-ClusterAccess]&nbsp;[g][Get-ClusterAccess]&nbsp;[r][Remove-ClusterAccess]</code>
<code>Disk&nbsp;[a][Add-ClusterDisk]</code>
<code>FileServerRole&nbsp;[a][Add-ClusterFileServerRole]</code>
<code>GenericApplicationRole&nbsp;[a][Add-ClusterGenericApplicationRole]</code>
<code>Group&nbsp;[a][Add-ClusterGroup]</code>
<code>Node&nbsp;[a][Add-ClusterNode]&nbsp;[g][Get-ClusterNode]&nbsp;[r][Remove-ClusterNode]&nbsp;[sp][Stop-ClusterNode]&nbsp;[ss][Suspend-ClusterNode]</code>
<code>Quorum&nbsp;[g][Get-ClusterQuorum]&nbsp;[s][Set-ClusterQuorum]</code>
<code>Resource&nbsp;[a][Add-ClusterResource]</code>
<code>ResourceDependency&nbsp;[a][Add-ClusterResourceDependency]</code>
<code>ScaleOutFileServer&nbsp;[a][Add-ClusterScaleOutFileServer]</code>
<code>ServerRole&nbsp;[a][Add-ClusterServerRole]</code>
<code>SharedVolume&nbsp;a</code>
<code>StorageSpacesDirect&nbsp;[e][Enable-ClusterStorageSpacesDirect]</code>
<code>VirtualMachineRole&nbsp;a</code>
<code>VMMonitoredItem&nbsp;a</code>

##### Disk-related cmdlets
[Enable-DedupVolume]: #enable-dedupvolume '```&#10;PS C:\> Enable-DedupVolume&#10;```&#10;Enable deduplication for a volume&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 157'
[Set-Disk]: #set-disk '```&#10;PS C:\> Set-Disk&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 226'
[Mount-DiskImage]: #mount-diskimage '```&#10;PS C:\> Mount-DiskImage&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 92'
[Format-Volume]: #format-volume '```&#10;PS C:\> Format-Volume&#10;```&#10;Formats one or more existing volumes or a new volume on an existing partition.&#10;The Format-Volume cmdlet formats one or more existing volumes, or a new volume on an existing partition. This cmdlet returns the object representing the volume that was just formatted, with all properties updated to reflect the format operation.'
[Get-Disk]: #get-disk '```&#10;PS C:\> Get-Disk&#10;```&#10;'
[New-Partition]: #new-partition '```&#10;PS C:\> New-Partition&#10;```&#10;'
[Remove-Partition]: #remove-partition '```&#10;PS C:\> Remove-Partition&#10;```&#10;'
[Get-Partition]: #get-partition '```&#10;PS C:\> Get-Partition&#10;```&#10;'
[New-Volume]: #new-volume '```&#10;PS C:\> New-Volume&#10;```&#10;Create a volume with the specified file system'
[Get-PSDrive]: #get-psdrive '```&#10;PS C:\> Get-PSDrive&#10;PS C:\> gdr&#10;```&#10;Display mapped drives'
[New-PSDrive]: #new-psdrive '```&#10;PS C:\> New-PSDrive&#10;PS C:\> ndr&#10;```&#10;Create temporary and persistent mapped network drives.'
[Remove-PSDrive]: #remove-psdrive '```&#10;PS C:\> Remove-PSDrive&#10;PS C:\> rdr&#10;```&#10;Delete temporary PowerShell drives and disconnect mapped network drives'

[**Disks**](#disks)
<code>DedupVolume&nbsp;[en][Enable-DedupVolume]</code>
<code>Disk&nbsp;[g][Get-Disk]</code> 
<code>Partition&nbsp;f&nbsp;[g][Get-Partition] [n][New-Partition] [r][Remove-Partition]</code> 
<code>Volume&nbsp;[f][Format-Volume]&nbsp;[n][New-Volume]</code> 
<code>**PSDrive**&nbsp;[g][Get-PSDrive]&nbsp;[n][New-PSDrive]&nbsp;[r][Remove-PSDrive]</code>

##### File cmdlets
[Add-Content]: #add-content '```&#10;PS C:\> Add-Content&#10;PS C:\> ac&#10;```&#10;Append content, such as words or data, to a file'
[Get-Content]: #get-content '```&#10;PS C:\> Get-Content&#10;PS C:\> gc&#10;```&#10;Get the content of a file'
[Copy-Item]: #copy-item '```&#10;PS C:\> Copy-Item&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 180'
[Set-Item]: #set-item '```&#10;PS C:\> Set-Item&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 56'
[Compress-Archive]: #compress-archive '```&#10;PS C:\> Compress-Archive&#10;```&#10;'
[Copy-Item]: #copy-item '```&#10;PS C:\> Copy-Item&#10;```&#10;'
[Expand-Archive]: #expand-archive '```&#10;PS C:\> Expand-Archive&#10;```&#10;Decompress archives'
[Export-Csv]: #export-csv '```&#10;PS C:\> Export-Csv&#10;```&#10;Export PowerShell objects to CSV'
[Get-Item]: #get-item '```&#10;PS C:\> Get-Item&#10;```&#10;'
[Import-Csv]: #import-csv '```&#10;PS C:\> Import-Csv&#10;PS C:\> ipcsv&#10;```&#10;'
[New-Item]: #new-item '```&#10;PS C:\> New-Item&#10;PS C:\> ni&#10;```&#10;Create a new item and set its value. The type of item created depends on the context.'
[Out-Null]: #out-null '```&#10;PS C:\> Out-Null&#10;```&#10;Delete output instead of sending it down the pipeline'
[Remove-Item]: #remove-item '```&#10;PS C:\> Remove-Item&#10;PS C:\> rm ri rmdir rd del&#10;```&#10;'
[Set-FileStorageTier]: #set-filestoragetier '```&#10;Set-FileStorageTier&#10;```&#10;Assign a file to a storage tier&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 133'

<code>Archive&nbsp;[cm][Compress-Archive]&nbsp;[en][Expand-Archive]</code> 
<code>Content&nbsp;[a][Add-Content]&nbsp;[g][Get-Content]</code> 
<code>Csv&nbsp;[ep][Export-Csv]&nbsp;[ip][Import-Csv]</code> 
<code>FileStorageTier&nbsp;[s][Set-FileStorageTier]</code>
<code>Item&nbsp;[cp][Copy-Item]&nbsp;[g][Get-Item]&nbsp;[n][New-Item]&nbsp;[r][Remove-Item] </code>
<code>Null&nbsp;[o][Out-Null]</code> 

##### File share cmdlets
[Get-SmbBandwidthLimit]: #get-smbbandwidthlimit '```&#10;Get-SmbBandwidthLimit&#10;```&#10;Gets the list of SMB bandwidth caps for each traffic category.'
[Remove-SmbBandwidthLimit]: #remove-smbbandwidthlimit '```&#10;Remove-SmbBandwidthLimit&#10;```&#10;Removes SMB bandwidth caps.'
[Set-SmbBandwidthLimit]: #set-smbbandwidthlimit '```&#10;Set-SmbBandwidthLimit&#10;```&#10;Adds an SMB bandwidth cap.'
[Get-SmbClientConfiguration]: #get-smbclientconfiguration '```&#10;Get-SmbClientConfiguration&#10;```&#10;Retrieves the SMB client configuration.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 111'
[Set-SmbClientConfiguration]: #set-smbclientconfiguration '```&#10;Set-SmbClientConfiguration&#10;```&#10;Sets the SMB client configuration.'
[Get-SmbClientNetworkInterface]: #get-smbclientnetworkinterface '```&#10;Get-SmbClientNetworkInterface&#10;```&#10;Retrieves the network interfaces used by the SMB client.'
[Get-SmbConnection]: #get-smbconnection '```&#10;Get-SmbConnection&#10;```&#10;Retrieves the connections established from the SMB client to the SMB servers.'
[Disable-SmbDelegation]: #disable-smbdelegation '```&#10;Disable-SmbDelegation&#10;```&#10;Disables a constrained delegation authorization for an SMB client and server.'
[Enable-SmbDelegation]: #enable-smbdelegation '```&#10;Enable-SmbDelegation&#10;```&#10;Enables a constrained delegation authorization for an SMB client and server.'
[Get-SmbDelegation]: #get-smbdelegation '```&#10;Get-SmbDelegation&#10;```&#10;Gets the constrained delegation authorizations for an SMB client.'
[Get-SmbMapping]: #get-smbmapping '```&#10;Get-SmbMapping&#10;```&#10;Retrieves the SMB client directory mappings created for a server.'
[New-SmbMapping]: #new-smbmapping '```&#10;New-SmbMapping&#10;```&#10;Creates an SMB mapping.'
[Remove-SmbMapping]: #remove-smbmapping '```&#10;Remove-SmbMapping&#10;```&#10;Removes the SMB mapping to an SMB share.'
[Get-SmbMultichannelConnection]: #get-smbmultichannelconnection '```&#10;Get-SmbMultichannelConnection&#10;```&#10;Retrieves the SMB connections made between the SMB client network interfaces and the SMB server network interfaces.'
[Update-SmbMultichannelConnection]: #update-smbmultichannelconnection '```&#10;Update-SmbMultichannelConnection&#10;```&#10;Forces the SMB client to update the multi-channel-related information.'
[Get-SmbMultichannelConstraint]: #get-smbmultichannelconstraint '```&#10;Get-SmbMultichannelConstraint&#10;```&#10;Retrieves the constraints that define how the SMB client uses network interfaces to connect to the servers.'
[New-SmbMultichannelConstraint]: #new-smbmultichannelconstraint '```&#10;New-SmbMultichannelConstraint&#10;```&#10;Creates an SMB multi-channel constraint for the specified server.'
[Remove-SmbMultichannelConstraint]: #remove-smbmultichannelconstraint '```&#10;Remove-SmbMultichannelConstraint&#10;```&#10;Removes SMB multi-channel constraints.'
[Close-SmbOpenFile]: #close-smbopenfile '```&#10;Close-SmbOpenFile&#10;```&#10;Close a file that is open by one of the clients of the SMB server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Get-SmbOpenFile]: #get-smbopenfile '```&#10;Get-SmbOpenFile&#10;```&#10;Retrieve basic information about the files that are open on behalf of the clients of the Server Message Block (SMB) server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Set-SmbPathAcl]: #set-smbpathacl '```&#10;Set-SmbPathAcl&#10;```&#10;Sets the ACL for the file system folder to match the ACL used by an SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 340'
[Get-SmbServerConfiguration]: #get-smbserverconfiguration '```&#10;Get-SmbServerConfiguration&#10;```&#10;Retrieves the SMB server configuration.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Set-SmbServerConfiguration]: #set-smbserverconfiguration '```&#10;Set-SmbServerConfiguration&#10;```&#10;Sets the SMB Service configuration.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Get-SmbServerNetworkInterface]: #get-smbservernetworkinterface '```&#10;Get-SmbServerNetworkInterface&#10;```&#10;Retrieves the network interfaces used by the SMB server.'
[Close-SmbSession]: #close-smbsession '```&#10;Close-SmbSession&#10;```&#10;Ends forcibly the SMB session.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 107'
[Get-SmbSession]: #get-smbsession '```&#10;Get-SmbSession&#10;```&#10;Retrieves information about the SMB sessions that are currently established between the SMB server and the associated clients.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 107'
[New-SmbShare]: #new-smbshare '```&#10;New-SmbShare&#10;```&#10;Creates an SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 106'
[Remove-SmbShare]: #remove-smbshare '```&#10;Remove-SmbShare&#10;```&#10;Deletes the specified SMB shares.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Get-SmbShare]: #get-smbshare '```&#10;Get-SmbShare&#10;```&#10;Retrieves the SMB shares on the computer.'
[Set-SmbShare]: #set-smbshare '```&#10;Set-SmbShare&#10;```&#10;Modifies the properties of the SMB share.'
[Block-SmbShareAccess]: #block-smbshareaccess '```&#10;Block-SmbShareAccess&#10;```&#10;Adds a deny ACE for a trustee to the security descriptor of the SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Get-SmbShareAccess]: #get-smbshareaccess '```&#10;Get-SmbShareAccess&#10;```&#10;Retrieves the ACL of the SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Grant-SmbShareAccess]: #grant-smbshareaccess '```&#10;Grant-SmbShareAccess&#10;```&#10;Adds an allow ACE for a trustee to the security descriptor of the SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Revoke-SmbShareAccess]: #revoke-smbshareaccess '```&#10;Revoke-SmbShareAccess&#10;```&#10;Removes all of the allow ACEs for a trustee from the security descriptor of the SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Unblock-SmbShareAccess]: #unblock-smbshareaccess '```&#10;Unblock-SmbShareAccess&#10;```&#10;Removes all of the deny ACEs for the trustee from the security descriptor of the SMB share.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'

[**Smb**](#smb)
<code>BandwidthLimit
&nbsp;[g][Get-SmbBandwidthLimit]
&nbsp;[r][Remove-SmbBandwidthLimit]
&nbsp;[s][Set-SmbBandwidthLimit] </code>
<code>ClientConfiguration
&nbsp;[g][Get-SmbClientConfiguration] 
&nbsp;[s][Set-SmbClientConfiguration] </code>
<code>ClientNetworkInterface
&nbsp;[g][Get-SmbClientNetworkInterface] </code>
<code>Connection
&nbsp;[g][Get-SmbConnection] </code>
<code>Delegation
&nbsp;[d][Disable-SmbDelegation] 
&nbsp;[e][Enable-SmbDelegation] 
&nbsp;[g][Get-SmbDelegation] </code>
<code>Mapping
&nbsp;[g][Get-SmbMapping] 
&nbsp;[n][New-SmbMapping] 
&nbsp;[r][Remove-SmbMapping] </code>
<code>MultiChannel
&nbsp;[g][Get-SmbMultichannelConnection] 
&nbsp;[ud][Update-SmbMultichannelConnection] 
&nbsp;[g][Get-SmbMultichannelConstraint] 
&nbsp;[n][New-SmbMultichannelConstraint] 
&nbsp;[r][Remove-SmbMultichannelConstraint] </code>
<code>OpenFile&nbsp;[g][Get-SmbOpenFile]&nbsp;[cs][Close-SmbOpenFile]</code>
<code>PathAcl
&nbsp;[s][Set-SmbPathAcl] </code>
<code>ServerConfiguration
&nbsp;[g][Get-SmbServerConfiguration] 
&nbsp;[s][Set-SmbServerConfiguration] </code>
<code>ServerNetworkInterface
&nbsp;[g][Get-SmbServerNetworkInterface] </code>
<code>Session
&nbsp;[ch][Close-SmbSession] 
&nbsp;[g][Get-SmbSession] </code>
<code>Share
&nbsp;[n][New-SmbShare] 
&nbsp;[r][Remove-SmbShare] </code>
<code>ShareAccess
&nbsp;[bl][Block-SmbShareAccess] 
&nbsp;[g][Get-SmbShareAccess] 
&nbsp;[gr][Grant-SmbShareAccess] 
&nbsp;[rk][Revoke-SmbShareAccess] 
&nbsp;[ul][Unblock-SmbShareAccess] </code>

##### Network-related cmdlets
[Add-DhcpServerInDC]: #add-dhcpserverindc '```&#10;PS C:\> Add-DhcpServerInDC&#10;```&#10;'
[Add-DhcpServerv4Scope]: #add-dhcpserverv4scope '```&#10;PS C:\> Add-DhcpServerv4Scope&#10;```&#10;Add an IPv4 scope on the DHCP server service.'
[Enable-NetFirewallRule]: #enable-netfirewallrule '```&#10;PS C:\> Enable-NetFirewallRule&#10;```&#10;Enable a previously disabled Windows Firewall rule'
[Get-NetAdapter]: #get-netadapter '```&#10;PS C:\> Get-NetAdapter&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 19'
[Get-NetAdapter]: #get-netadapter '```&#10;PS C:\> Get-NetAdapter&#10;```&#10;Display available network interfaces'
[Get-NetAdapterVmqQueue]: #get-netadaptervmqqueue '```&#10;PS C:\> Get-NetAdapterVmqQueue&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Get-NetFirewallRule]: #get-netfirewallrule '```&#10;PS C:\> Get-NetFirewallRule&#10;```&#10;'
[Get-NetIpConfiguration]: #get-netipconfiguration '```&#10;PS C:\> Get-NetIpConfiguration&#10;PS C:\> gip&#10;```&#10;Produce output similar to `ipconfig`'
[Invoke-WebRequest]: #invoke-webrequest '```&#10;PS C:\> Invoke-WebRequest&#10;PS C:\> iwr&#10;```&#10;'
[New-NetFirewallRule]: #new-netfirewallrule '```&#10;PS C:\> New-NetFirewallRule&#10;```&#10;'
[New-NetIpAddress]: #new-netipaddress '```&#10;PS C:\> New-NetIpAddress&#10;```&#10;Manually configure network interface, if a DHCP server is unavailable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 19'
[New-NetQosPolicy]: #new-netqospolicy '```&#10;PS C:\> New-NetQosPolicy&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 144'
[New-NetQosTrafficClass]: #new-netqostrafficclass '```&#10;PS C:\> New-NetQosTrafficClass&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 144'
[Resolve-DNSName]: #resolve-dnsname '```&#10;PS C:\> Resolve-DNSName&#10;```&#10;...&#10;MeasureUp Practice Lab: Security+'
[Set-DhcpServerv4OptionValue]: #set-dhcpserverv4optionvalue '```&#10;PS C:\> Set-DhcpServerv4OptionValue&#10;```&#10;'
[Set-DnsClientServerAddress]: #set-dnsclientserveraddress '```&#10;PS C:\> Set-DnsClientServerAddress&#10;```&#10;Set DNS server addresses associated with the TCP/IP properties on an interface&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 20'
[Set-NetAdapterVmq]: #set-netadaptervmq '```&#10;PS C:\> Set-NetAdapterVmq&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'
[Set-NetFirewallRule]: #set-netfirewallrule '```&#10;PS C:\> Set-NetFirewallRule&#10;```&#10;'
[Set-NetQoSbcdxSetting]: #set-netqosbcdxsetting '```&#10;PS C:\> Set-NetQoSbcdxSetting&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 143'

[Enable-NetAdapterVmq]: #enable-netadaptervmq '```&#10;PS C:\> Enable-NetAdapterVmq&#10;```&#10;Enable VMQ on a specific adapter&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Get-NetAdapterVmq]: #get-netadaptervmq '```&#10;PS C:\> Get-NetAdapterVmq&#10;```&#10;Discover whether physical network adapters support VMQ&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Set-NetAdapterVmq]: #set-netadaptervmq '```&#10;PS C:\> Set-NetAdapterVmq&#10;```&#10;Modify default VMQ settings&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'
[Get-NetAdapterVmqQueue]: #get-netadaptervmqqueue '```&#10;PS C:\> Get-NetAdapterVmqQueue&#10;```&#10;See which VMQ queries are assigned to which processors&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'

[Get-NetAdapterRdma]: #get-netadapterrdma '```&#10;PS C:\> Get-NetAdapterRdma&#10;```&#10;Display the current RDMA status of network adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'
[Enable-NetAdapterRdma]: #enable-netadapterrdma '```&#10;PS C:\> Enable-NetAdapterRdma&#10;```&#10;Enable RDMA on adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'

[Set-NetConnectionProfile]: #set-netconnectionprofile '```&#10;Set-NetConnectionProfile&#10;```&#10;Changes the network category of a connection profile. '

<code>NetConnectionProfile&nbsp;[g][Get-NetConnectionProfile]&nbsp;[s][Set-NetConnectionProfile]</code>
<code>NetFirewallRule&nbsp;[e][Enable-NetFirewallRule]&nbsp;[g][Get-NetFirewallRule]&nbsp;[n][New-NetFirewallRule]&nbsp;[s][Set-NetFirewallRule]</code>
<code>WebRequest&nbsp;[i][Invoke-WebRequest]</code>
**DNS**
<code>ClientServerAddress&nbsp;[s][Set-DnsClientServerAddress]</code> 
<code>Name&nbsp;[rv][Resolve-DNSName]</code> 
**DhcpServer**
<code>InDC [a][Add-DhcpServerInDC]</code> 
<code>V4Scope [a][Add-DhcpServerv4Scope]</code> 
<code>v4OptionValue [s][Set-DhcpServerv4OptionValue]</code> 
**NetAdapter**
<code>[g][Get-NetAdapter]</code>
<code>Rdma&nbsp;[g][Get-NetAdapterRdma]&nbsp;[e][Enable-NetAdapterRdma]</code>
<code>Vmq&nbsp;[e][Enable-NetAdapterVmq]&nbsp;[g][Get-NetAdapterVmq]&nbsp;[s][Set-NetAdapterVmq]</code>
<code>VmqQueue&nbsp;[g][Get-NetAdapterVmqQueue]</code>
**NetIp**
<code>Address&nbsp;[n][New-NetIpAddress]</code>
<code>Configuration&nbsp;[g][Get-NetIpConfiguration]</code>

##### Process control cmdlets
[Get-Process]: #get-process '```&#10;PS C:\> Get-Process&#10;PS C:\> gps&#10;```&#10;Display running processes'
[Start-Process]: #start-process '```&#10;PS C:\> Start-Process&#10;PS C:\> saps&#10;```&#10;Start one or more processes on the local computer.'
[Stop-Process]: #stop-process '```&#10;PS C:\> Stop-Process&#10;PS C:\> spps&#10;```&#10;Stop one or more running processes'
[Get-Service]: #get-service '```&#10;PS C:\> Get-Service&#10;PS C:\> gsv&#10;```&#10;Display services'
[Set-Service]: #set-service '```&#10;PS C:\> Set-Service&#10;```&#10;Starts, stops, and suspends a service, and changes its properties'
[Start-Service]: #start-service '```&#10;PS C:\> Start-Service&#10;PS C:\> sasv&#10;```&#10;Start one or more stopped services'
[Stop-Service]: #stop-service '```&#10;PS C:\> Stop-Service&#10;PS C:\> spsv&#10;```&#10;Stop one or more services'

<code>Process&nbsp;[g][Get-Process]&nbsp;[sa][Start-Process]&nbsp;[sp][Stop-Process]</code>
<code>Service&nbsp;[g][Get-Service]&nbsp;[s][Set-Service]&nbsp;[sa][Start-Service]&nbsp;[sp][Stop-Service]</code> 

##### Remote administration
[Enable-WSManCredSSP]: #enable-wsmancredssp '```&#10;PS C:\> Enable-WSManCredSSP&#10;```&#10;Enable the use of CredSSP for authentication between hosts in different domains&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 176'
[Disconnect-PSSession]: #disconnect-pssession '```&#10;PS C:\> Disconnect-PSSession&#10;PS C:\> dnsn&#10;```&#10;Terminate a remote PowerShell session begun with `New-PSSession`'
[Enable-PSRemoting]: #enable-psremoting '```&#10;PS C:\> Enable-PSRemoting&#10;```&#10;Allow remote Powershell management'
[Enter-PSSession]: #enter-pssession '```&#10;PS C:\> Enter-PSSession&#10;PS C:\> etsn&#10;```&#10;Interact with the specified PowerShell session'
[Exit-PSSession]: #exit-pssession '```&#10;PS C:\> Exit-PSSession&#10;PS C:\> exsn&#10;```&#10;End an interactive session with a remote computer'
[New-PSSession]: #new-pssession '```&#10;New-PSSession&#10;nsn&#10;```&#10;Start a new remote PowerShell session with a remote computer&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 21'
[Get-PSSession]: #get-pssession '```&#10;PS C:\> Get-PSSession&#10;PS C:\> gsn&#10;```&#10;Get the Windows Powershell sessions on local and remote computers'

<code>[Session](#pssession)&nbsp;[cc][Connect-PSSession]&nbsp;[dc][Disconnect-PSSession]&nbsp;[et][Enter-PSSession]&nbsp;[ex][Exit-PSSession]&nbsp;[g][Get-PSSession]&nbsp;[n][New-PSSession]</code> 
<code>WSManCredSSP&nbsp;[e][Enable-WSManCredSSP]</code>

##### Shell environment cmdlets

[Add-Computer]: #add-computer '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Add-PSSnapin]: #add-pssnapin '```&#10;PS C:\> Add-PSSnapin&#10;PS C:\> asnp&#10;```&#10;Load a given list of snap-ins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) either by name or via the pipeline - last supported in PowerShell 5.1'
[Add-Type]: #add-type '```&#10;PS C:\> Add-Type&#10;```&#10;add a.NET Framework type (a class) to a Windows PowerShell session'
[Clear-Host]: #clear-host '```&#10;PS C:\> Clear-Host&#10;```&#10;'
[Export-Alias]: #export-alias '```&#10;PS C:\> Export-Alias&#10;PS C:\> epal&#10;```&#10;Export information about currently defined aliases to a file.'
[Get-Alias]: #get-alias '```&#10;PS C:\> Get-Alias&#10;PS C:\> gal&#10;```&#10;Display aliases'
[Get-ChildItem]: #get-childitem '```&#10;PS C:\> Get-ChildItem&#10;PS C:\> dir gci ls&#10;```&#10;Get items in one or more locations'
[Get-Clipboard]: #get-clipboard '```&#10;PS C:\> Get-Clipboard&#10;PS C:\> gcb&#10;```&#10;Display items in clipboard'
[Get-Command]: #get-command '```&#10;PS C:\> Get-Command&#10;PS C:\> gcm&#10;```&#10;Display all installed commands, including aliases, applications, filters, functions, and scripts'
[Get-Help]: #get-help '```&#10;PS C:\> Get-Help&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 21'
[Get-Help]: #get-help '```&#10;PS C:\> Get-Help&#10;```&#10;Display help file for cmdlets'
[Get-Location]: #get-location '```&#10;PS C:\> Get-Location&#10;```&#10;'
[Get-Member]: #get-member '```&#10;PS C:\> Get-Member&#10;PS C:\> gm&#10;```&#10;Display properties and methods of a Powershell object'
[Get-Module]: #get-module '```&#10;PS C:\> Get-Module&#10;PS C:\> gmo&#10;```&#10;Display currently loaded Powershell modules'
[Get-PSReadlineOption]: #get-psreadlineoption '```&#10;PS C:\> Get-PSReadlineOption&#10;```&#10;'
[Import-Module]: #import-module '```&#10;PS C:\> Import-Module&#10;PS C:\> ipmo&#10;```&#10;'
[Install-Module]: #install-module '```&#10;PS C:\> Install-Module&#10;```&#10;'
[New-Alias]: #new-alias '```&#10;PS C:\> New-Alias&#10;PS C:\> nal&#10;```&#10;Create a new alias'
[Out-Host]: #out-host '```&#10;PS C:\> Out-Host&#10;PS C:\> oh&#10;```&#10;'
[Rename-Computer]: #rename-computer '```&#10;PS C:\> Rename-Computer&#10;```&#10;'
[Restart-Computer]: #restart-computer '```&#10;PS C:\> Restart-Computer&#10;```&#10;'
[Set-Alias]: #set-alias '```&#10;PS C:\> Set-Alias&#10;```&#10;'
[Set-Clipboard]: #set-clipboard '```&#10;PS C:\> Set-Clipboard&#10;PS C:\> scb&#10;```&#10;Set the current Windows clipboard entry'
[Set-ExecutionPolicy]: #set-executionpolicy '```&#10;PS C:\> Set-ExecutionPolicy&#10;```&#10;Change user preference for the Windows PowerShell execution policy'
[Set-Location]: #set-location '```&#10;PS C:\> Set-Location&#10;PS C:\> cd&#10;```&#10;Set present working directory'
[Set-PSReadlineOption]: #set-psreadlineoption '```&#10;PS C:\> Set-PSReadlineOption&#10;```&#10;'
[Stop-Computer]: #stop-computer '```&#10;PS C:\> Stop-Computer&#10;```&#10;'
[Update-Help]: #update-help '```&#10;PS C:\> Update-Help&#10;```&#10;Download help files'
[Write-Host]: #write-host '```&#10;PS C:\> Write-Host&#10;```&#10;Write customized output to a host (equivalent to `echo`).'
[Write-Output]: #write-output '```&#10;PS C:\> Write-Output&#10;PS C:\> echo write&#10;```&#10;Send the specified objects to the next command in the pipeline. If the command is the last command in the pipeline, the objects are displayed in the console'
[Get-ComputerInfo]: #get-computerinfo '```&#10;PS C:\> Get-ComputerInfo&#10;PS C:\> gin&#10;```&#10;Retrieve a consolidated object of system and operating system properties&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[New-Object]: #new-object '```&#10;New-Object&#10;```&#10;Create an instance of a Microsoft .NET Framework or COM object'
[Start-Transaction]: #start-transaction '```&#10;Start-Transaction&#10;```&#10;Start a new transaction'
[Complete-Transaction]: #complete-transaction '```&#10;Complete-Transaction&#10;```&#10;Commit the transaction'
[Start-Job]: #start-job '```&#10;Start-Job&#10;sajb&#10;```&#10;Start a background job'

[Measure-Object]: #measure-object '```&#10;PS C:\> Measure-Object&#10;PS C:\> measure&#10;```&#10;Calculates the numeric properties of objects, and the characters, words, and lines in string objects, such as files of text.'
[ForEach-Object]: #foreach-object '```&#10;PS C:\> ForEach-Object&#10;PS C:\> %&#10;```&#10;Perform an operation against each item in a collection of input objects.'
[New-Object]: #new-object '```&#10;PS C:\> New-Object&#10;```&#10;Create an instance of a Microsoft .NET Framework or COM object'
[Select-Object]: #select-object '```&#10;PS C:\> Select-Object&#10;PS C:\> select&#10;```&#10;Select object or object properties'
[Where-Object]: #where-object '```&#10;PS C:\> Where-Object&#10;PS C:\> ?&#10;```&#10;Select objects from a collection based on their property values'

<code>Alias&nbsp;[ep][Export-Alias]&nbsp;[g][Get-Alias]&nbsp;[n][New-Alias]&nbsp;[s][Set-Alias]</code> 
<code>ChildItem&nbsp;[g][Get-ChildItem]</code> 
<code>Clipboard&nbsp;[g][Get-Clipboard]&nbsp;[s][Set-Clipboard]</code> 
<code>Computer&nbsp;[a][Add-Computer]&nbsp;[rn][Rename-Computer]&nbsp;[rt][Restart-Computer]&nbsp;[sp][Stop-Computer]</code> 
<code>Credential [g][Get-Credential]</code> 
<code>ExecutionPolicy&nbsp;[s][Set-ExecutionPolicy]</code> 
<code>Help&nbsp;[g][Get-Help]&nbsp;[ud][Update-Help]</code> 
<code>History&nbsp;[g][Get-History]</code> 
<code>Host&nbsp;[oh][Out-Host]&nbsp;[rd][Read-Host]&nbsp;[wr][Write-Host]</code>
<code>Job&nbsp;[sa][Start-Job]</code>
<code>List&nbsp;[f][Format-List]</code> 
<code>Location&nbsp;[g][Get-Location] [s][Set-Location]</code> 
<code>Module&nbsp;[ip][Import-Module]&nbsp;[is][Install-Module]</code> 
<code>Object&nbsp;[%][ForEach-Object]&nbsp;[?][Where-Object]&nbsp;[ms][Measure-Object]&nbsp;[n][New-Object]&nbsp;[sc][Select-Object]</code>
<code>Output&nbsp;[wr][Write-Output]</code> 
<code>PSRemoting&nbsp;[en]</code>
<code>Table&nbsp;[f][Format-Table]</code> 
<code>Transaction&nbsp;[sa][Start-Transaction]&nbsp;[cp][Complete-Transaction]</code>
<code>Type&nbsp;[a][Add-Type]</code> 
**PS**
<code>ReadlineOption&nbsp;[g][Get-PSReadlineOption] [s][Set-PSReadlineOption]</code> 

##### Hyper-V cmdlets
<!-- Hyper-V cmdlets -->
[Add-VMNetworkAdapter]: #add-vmnetworkadapter '```&#10;PS C:\> Add-VMNetworkAdapter&#10;```&#10;Adds a virtual network adapter to a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 237'
[Checkpoint-VM]: #checkpoint-vm '`Checkpoint-VM`&#10;Creates a checkpoint of a virtual machine.'
[Compare-VM]: #compare-vm '```&#10;PS C:\> Compare-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'
[Connect-VMNetworkAdapter]: #connect-vmnetworkadapter '```&#10;PS C:\> Connect-VMNetworkAdapter&#10;```&#10;Connects a virtual network adapter to a virtual switch.'
[Debug-VM]:                                          #debug-vm                                     '`Debug-VM`&#10;Debugs a virtual machine.'
[Disconnect-VMNetworkAdapter]: #disconnect-vmnetworkadapter '```&#10;PS C:\> Disconnect-VMNetworkAdapter&#10;```&#10;Disconnects a virtual network adapter from a virtual switch or Ethernet resource pool.'
[Export-VM]: #export-vm '```&#10;PS C:\> Export-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 210'
[Get-VM]: #get-vm '```&#10;PS C:\> Get-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 177'
[Get-VMHostSupportedVersion]: #get-vmhostsupportedversion '```&#10;PS C:\> Get-VMHostSupportedVersion&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 209'
[Get-VMNetworkAdapter]: #get-vmnetworkadapter '```&#10;PS C:\> Get-VMNetworkAdapter&#10;```&#10;Gets the virtual network adapters of a virtual machine, snapshot, management operating system, or of a virtual machine and management operating system.'
[Get-VMProcessor]: #get-vmprocessor '```&#10;PS C:\> Get-VMProcessor&#10;```&#10;Gets the processor of a virtual machine or snapshot.'
[Import-VM]: #import-vm '```&#10;PS C:\> Import-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 211'
[Measure-VM]: #measure-vm '```&#10;PS C:\> Measure-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 194, 234-235'
[Mount-VHD]: #mount-vhd '```&#10;Mount-VHD&#10;```&#10;Mounts one or more virtual hard disks.'
[Move-VM]:                                           #move-vm                                      '`Move-VM`&#10;Moves a virtual machine to a new Hyper-V host.'
[New-VHD]: #new-vhd '```&#10;New-VHD&#10;```&#10;Creates one or more new virtual hard disks.'
[New-VM]: #new-vm '```&#10;PS C:\> New-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 47, 184, 197'
[Optimize-VM]: #optimize-vm '```&#10;PS C:\> Optimize-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Remove-VM]: #remove-vm '`Remove-VM`&#10;Deletes a virtual machine.'
[Remove-VMNetworkAdapter]: #remove-vmnetworkadapter '```&#10;PS C:\> Remove-VMNetworkAdapter&#10;```&#10;Removes one or more virtual network adapters from a virtual machine.'
[Rename-VM]: #rename-vm                                    '`Rename-VM`&#10;Renames a virtual machine.'
[Rename-VMNetworkAdapter]: #rename-vmnetworkadapter '```&#10;PS C:\> Rename-VMNetworkAdapter&#10;```&#10;Renames a virtual network adapter on a virtual machine or on the management operating system.'
[Repair-VM]: #repair-vm                                    '`Repair-VM`&#10;Repairs one or more virtual machines.'
[Reset-VMResourceMetering]: #reset-vmresourcemetering '```&#10;PS C:\> Reset-VMResourceMetering&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 195'
[Restart-VM]: #restart-vm '`Restart-VM`&#10;Restarts a virtual machine.'
[Resume-VM]: #resume-vm '`Resume-VM`&#10;Resumes a suspended (paused) virtual machine.'
[Save-VM]: #save-vm '`Save-VM`&#10;Saves a virtual machine.'
[Set-VM]: #set-vm '```&#10;PS C:\> Set-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 231'
[Set-VMFirmware]: #set-vmfirmware '```&#10;PS C:\> Set-VMFirmware&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 208'
[Set-VMMemory]: #set-vmmemory '```&#10;PS C:\> Set-VMMemory&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 185'
[Set-VMNetworkAdapter]: #set-vmnetworkadapter '```&#10;PS C:\> Set-VMNetworkAdapter&#10;```&#10;Configures features of the virtual network adapter in a virtual machine or the management operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 255'
[Set-VMProcessor]: #set-vmprocessor '```&#10;PS C:\> Set-VMProcessor&#10;```&#10;Configures one or more processors of a virtual machine.'
[Set-VmReplicationServer]: #set-vmreplicationserver '```&#10;PS C:\> Set-VmReplicationServer&#10;```&#10;Configure a host as a Replica server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 300'
[Start-VM]:                                          #start-vm                                     '`Start-VM`&#10;Starts a virtual machine.'
[Stop-VM]:                                           #stop-vm                                      '`Stop-VM`&#10;Shuts down, turns off, or saves a virtual machine.'
[Suspend-VM]:                                        #suspend-vm                                   '`Suspend-VM`&#10;Suspends, or pauses, a virtual machine.'
[Test-VMNetworkAdapter]: #test-vmnetworkadapter '```&#10;PS C:\> Test-VMNetworkAdapter&#10;```&#10;Tests connectivity between virtual machines.'
[Update-VMVersion]: #update-vmversion '```&#10;PS C:\> Update-VMVersion&#10;```&#10;Updates the version of virtual machines.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 209'
[Set-VMHost]: #set-vmhost '```&#10;Set-VMHost&#10;```&#10;Configure a Hyper-V host'

[Add-VMSwitch]: #add-vmswitch '```&#10;PS C:\> Add-VMSwitch&#10;```&#10;Adds a virtual switch to an Ethernet resource pool.'
[Get-VMSwitch]: #get-vmswitch '```&#10;PS C:\> Get-VMSwitch&#10;```&#10;Gets virtual switches from one or more virtual Hyper-V hosts.'
[New-VMSwitch]: #new-vmswitch '```&#10;PS C:\> New-VMSwitch&#10;```&#10;Creates a new virtual switch on one or more virtual machine hosts.'
[Remove-VMSwitch]: #remove-vmswitch '```&#10;PS C:\> Remove-VMSwitch&#10;```&#10;Deletes a virtual switch.'
[Rename-VMSwitch]: #rename-vmswitch '```&#10;PS C:\> Rename-VMSwitch&#10;```&#10;Renames a virtual switch.'
[Set-VMSwitch]: #set-vmswitch '```&#10;PS C:\> Set-VMSwitch&#10;```&#10;Configures a virtual switch.'

**VHD**
<code>[mt][Mount-VHD]&nbsp;[n][New-VHD]&nbsp;</code>
**VM**
<code>[cr][Compare-VM]&nbsp;[db][Debug-VM]&nbsp;[ep][Export-VM]&nbsp;[g][Get-VM]&nbsp;[ip][Import-VM]&nbsp;[m][Move-VM]&nbsp;[ms][Measure-VM]&nbsp;[n][New-VM]&nbsp;[r][Remove-VM]&nbsp;[rn][Rename-VM]&nbsp;[rt][Restart-VM]&nbsp;[ru][Resume-VM]&nbsp;[s][Set-VM]&nbsp;[sa][Start-VM]&nbsp;[sp][Stop-VM]&nbsp;[ss][Suspend-VM]&nbsp;[sv][Save-VM]</code>
<code>Firmware&nbsp;[s][Set-VMFirmware]</code> 
<code>Host&nbsp;[s][Set-VMHost]</code>
<code>Memory&nbsp;[s][Set-VMMemory]</code> 
<code>NetworkAdapter&nbsp;[a][Add-VMNetworkAdapter]&nbsp;[r][Remove-VMNetworkAdapter]&nbsp;[s][Set-VMNetworkAdapter]</code> 
<code>Processor&nbsp;[s][Set-VMProcessor]</code> 
<code>Switch&nbsp;[a][Add-VMSwitch]&nbsp;[g][Get-VMSwitch]&nbsp;[n][New-VMSwitch]&nbsp;[r][Remove-VMSwitch]&nbsp;[rn][Rename-VMSwitch]&nbsp;[s][Set-VMSwitch]&nbsp; </code>
<code>Version&nbsp;[u][Update-VMVersion]</code> 

##### Windows Server
[Receive-SmigServerData]: #receive-smigserverdata '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Send-SmigServerData]: #send-smigserverdata '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-SmigServerFeature]: #get-smigserverfeature '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Export-SmigServerSetting]: #export-smigserversetting '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Import-SmigServerSetting]: #import-smigserversetting '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'

<!-- DISM module -->
[Set-AppxProvisionedDataFile]: #set-appxprovisioneddatafile '```&#10;PS C:\> Set-AppxProvisionedDataFile&#10;```&#10;Adds custom data into the specified app (.appx) package that has been provisioned in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Set-ProvisionedAppxDataFile`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Add-AppxProvisionedPackage]: #add-appxprovisionedpackage '```&#10;PS C:\> Add-AppxProvisionedPackage&#10;```&#10;Adds an app package (.appx) that will install for each new user to a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-AppxProvisionedPackage]: #get-appxprovisionedpackage '```&#10;PS C:\> Get-AppxProvisionedPackage&#10;```&#10;Gets information about app packages (.appx) in an image that will be installed for each new user.&#10;Equivalent to `Dism.exe /Image:foldername /Get-ProvisionedAppxPackages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-AppxProvisionedPackage]: #remove-appxprovisionedpackage '```&#10;PS C:\> Remove-AppxProvisionedPackage&#10;```&#10;Removes an app package (.appx) from a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WIMBootEntry]: #get-wimbootentry '```&#10;PS C:\> Get-WIMBootEntry&#10;```&#10;Displays the Windows image file boot (WIMBoot) configuration entries for a specified disk volume.'
[Update-WIMBootEntry]: #update-wimbootentry '```&#10;PS C:\> Update-WIMBootEntry&#10;```&#10;Updates the Windows image file boot (WIMBoot) configuration entry, associated with either the specified data source ID, the renamed image file path or the moved image file path.'
[Add-WindowsCapability]: #add-windowscapability '```&#10;PS C:\> Add-WindowsCapability&#10;```&#10;Installs a Windows capability package on the specified operating system image.'
[Get-WindowsCapability]: #get-windowscapability '```&#10;PS C:\> Get-WindowsCapability&#10;```&#10;Gets Windows capabilities for an image or a running operating system.'
[Remove-WindowsCapability]: #remove-windowscapability '```&#10;PS C:\> Remove-WindowsCapability&#10;```&#10;Uninstalls a Windows capability package from an image.'
[Clear-WindowsCorruptMountPoint]: #clear-windowscorruptmountpoint '```&#10;PS C:\> Clear-WindowsCorruptMountPoint&#10;```&#10;Deletes all of the resources associated with a mounted image that has been corrupted.'
[Expand-WindowsCustomDataImage]: #expand-windowscustomdataimage '```&#10;PS C:\> Expand-WindowsCustomDataImage&#10;```&#10;Expands a custom data image.'
[New-WindowsCustomImage]: #new-windowscustomimage '```&#10;PS C:\> New-WindowsCustomImage&#10;```&#10;Captures an image of customized or serviced Windows components on a Windows Image File Boot (WIMBoot) configured device.'
[Add-WindowsDriver]: #add-windowsdriver '```&#10;PS C:\> Add-WindowsDriver&#10;```&#10;Adds a driver to an offline Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-Drive`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsDriver]: #export-windowsdriver '```&#10;PS C:\> Export-WindowsDriver&#10;```&#10;Exports all third-party drivers from a Windows image to a destination folder.&#10;Equivalent to `Dism.exe /Image:foldername /Export-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsDriver]: #get-windowsdriver '```&#10;PS C:\> Get-WindowsDriver&#10;```&#10;Displays information about drivers in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Drivers`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsDriver]: #remove-windowsdriver '```&#10;PS C:\> Remove-WindowsDriver&#10;```&#10;Removes a driver from an offline Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsEdition]: #get-windowsedition '```&#10;PS C:\> Get-WindowsEdition&#10;```&#10;Gets edition information about a Windows image.'
[Set-WindowsEdition]: #set-windowsedition '```&#10;PS C:\> Set-WindowsEdition&#10;```&#10;Changes a Windows image to a higher edition.'
[Add-WindowsImage]: #add-windowsimage '```&#10;PS C:\> Add-WindowsImage&#10;```&#10;Adds an additional image to an existing image (.wim) file.&#10;Equivalent to `dism.exe /Append-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Dismount-WindowsImage]: #dismount-windowsimage '```&#10;PS C:\> Dismount-WindowsImage&#10;```&#10;Dismounts a Windows image from the directory it is mapped to.&#10;Equivalent to `Dism.exe /Unmount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Expand-WindowsImage]: #expand-windowsimage '```&#10;PS C:\> Expand-WindowsImage&#10;```&#10;Applies an image to a specified location.&#10;Equivalent to `Dism.exe /Apply-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsImage]: #export-windowsimage '```&#10;PS C:\> Export-WindowsImage&#10;```&#10;Exports a copy of the specified image to another image file.&#10;Equivalent to `Dism.exe /Export-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsImage]: #get-windowsimage '```&#10;PS C:\> Get-WindowsImage&#10;```&#10;Gets information about a Windows image in a WIM or VHD file.&#10;Equivalent to `Dism.exe /Get-ImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Mount-WindowsImage]: #mount-windowsimage '```&#10;PS C:\> Mount-WindowsImage&#10;```&#10;Mounts a Windows image in a WIM or VHD file to a directory on the local computer.&#10;Equivalent to `Dism.exe /Mount-image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[New-WindowsImage]: #new-windowsimage '```&#10;PS C:\> New-WindowsImage&#10;```&#10;Captures an image of a drive to a new WIM file.&#10;Equivalent to `Dism.exe /Capture-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-WindowsImage]: #remove-windowsimage '```&#10;PS C:\> Remove-WindowsImage&#10;```&#10;Deletes the specified volume image from a WIM file that has multiple volume images.&#10;Equivalent to `Dism.exe /Remove-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Save-WindowsImage]: #save-windowsimage '```&#10;PS C:\> Save-WindowsImage&#10;```&#10;Applies changes made to a mounted image to its WIM or VHD file.&#10;Equivalent to `Dism.exe /Commit-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Optimize-WindowsImage]: #optimize-windowsimage '```&#10;PS C:\> Optimize-WindowsImage&#10;```&#10;Configures a Windows image with specified optimizations.'
[Repair-WindowsImage]: #repair-windowsimage '```&#10;PS C:\> Repair-WindowsImage&#10;```&#10;Repairs a Windows image in a WIM or VHD file.'
[Split-WindowsImage]: #split-windowsimage '```&#10;PS C:\> Split-WindowsImage&#10;```&#10;Splits an existing .wim file into multiple read-only split .wim files.'
[Get-WindowsImageContent]: #get-windowsimagecontent '```&#10;PS C:\> Get-WindowsImageContent&#10;```&#10;Displays a list of the files and folders in a specified image.&#10;Equivalent to `Dism.exe /List-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Disable-WindowsOptionalFeature]: #disable-windowsoptionalfeature '```&#10;PS C:\> Disable-WindowsOptionalFeature&#10;```&#10;Disables a feature in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Disable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Enable-WindowsOptionalFeature]: #enable-windowsoptionalfeature '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;Enable or restore an optional feature in a Windows image&#10;Equivalent to `Dism.exe /Image:foldername /Enable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsOptionalFeature]: #get-windowsoptionalfeature '```&#10;PS C:\> Get-WindowsOptionalFeature&#10;```&#10;Gets information about optional features in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Features`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Add-WindowsPackage]: #add-windowspackage '```&#10;PS C:\> Add-WindowsPackage&#10;```&#10;Adds a single .cab or .msu file to a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsPackage]: #get-windowspackage '```&#10;PS C:\> Get-WindowsPackage&#10;```&#10;Gets information about packages in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsPackage]: #remove-windowspackage '```&#10;PS C:\> Remove-WindowsPackage&#10;```&#10;Removes a package from a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Set-WindowsProductKey]: #set-windowsproductkey '```&#10;PS C:\> Set-WindowsProductKey&#10;```&#10;Sets the product key for the Windows image.'
[Get-WindowsReservedStorageState]: #get-windowsreservedstoragestate '```&#10;PS C:\> Get-WindowsReservedStorageState&#10;```&#10;Gets the reserved storage state of the image.'
[Set-WindowsReservedStorageState]: #set-windowsreservedstoragestate '```&#10;PS C:\> Set-WindowsReservedStorageState&#10;```&#10;Sets the reserved storage state of the image.'
[Use-WindowsUnattend]: #use-windowsunattend '```&#10;PS C:\> Use-WindowsUnattend&#10;```&#10;Applies an unattended answer file to a Windows image.'

<!-- DSC -->
[New-DSCCheckSum]: #new-dscchecksum '```&#10;PS C:\> New-DSCCheckSum&#10;```&#10;Creates checksum files for DSC documents and DSC resources.'
[Get-DscConfiguration]: #get-dscconfiguration '```&#10;Get-DscConfiguration&#10;```&#10;Gets the current configuration of the nodes.'
[Publish-DscConfiguration]: #publish-dscconfiguration '```&#10;Publish-DscConfiguration&#10;```&#10;Publishes a DSC configuration to a set of computers.'
[Restore-DscConfiguration]: #restore-dscconfiguration '```&#10;Restore-DscConfiguration&#10;```&#10;Reapplies the previous configuration for the node.'
[Start-DscConfiguration]: #start-dscconfiguration '```&#10;Start-DscConfiguration&#10;```&#10;Apply configuration to nodes&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 27'
[Stop-DscConfiguration]: #stop-dscconfiguration '```&#10;Stop-DscConfiguration&#10;```&#10;Stops a running configuration.'
[Test-DscConfiguration]: #test-dscconfiguration '```&#10;Test-DscConfiguration&#10;```&#10;Tests whether the actual configuration on the nodes matches the desired configuration.'
[Update-DscConfiguration]: #update-dscconfiguration '```&#10;Update-DscConfiguration&#10;```&#10;Checks the pull server for an updated configuration and applies it.'
[Remove-DscConfigurationDocument]: #remove-dscconfigurationdocument '```&#10;Remove-DscConfigurationDocument&#10;```&#10;Removes a configuration document from the DSC configuration store.'
[Get-DscConfigurationStatus]: #get-dscconfigurationstatus '```&#10;Get-DscConfigurationStatus&#10;```&#10;Retrieves data about completed configuration runs.'
[Disable-DscDebug]: #disable-dscdebug '```&#10;Disable-DscDebug&#10;```&#10;Stops debugging of DSC resources.'
[Enable-DscDebug]: #enable-dscdebug '```&#10;Enable-DscDebug&#10;```&#10;Starts debugging of all DSC resources.'
[Get-DscLocalConfigurationManager]: #get-dsclocalconfigurationmanager '```&#10;Get-DscLocalConfigurationManager&#10;```&#10;Gets LCM settings and states for the node.'
[Set-DscLocalConfigurationManager]: #set-dsclocalconfigurationmanager '```&#10;Set-DscLocalConfigurationManager&#10;```&#10;Applies LCM settings to nodes.'
[Get-DscResource]: #get-dscresource '```&#10;Get-DscResource&#10;```&#10;Gets the DSC resources present on the computer.'
[Invoke-DscResource]: #invoke-dscresource '```&#10;Invoke-DscResource&#10;```&#10;Runs a method of a specified DSC resource.'

<code>WIMBootEntry&nbsp;[g][Get-WIMBootEntry]&nbsp;[u][Update-WIMBootEntry]</code>
**AppxProvisioned**
<code>DataFile&nbsp;[s][Set-AppxProvisionedDataFile]</code> 
<code>Package&nbsp;[a][Add-AppxProvisionedPackage]&nbsp;[g][Get-AppxProvisionedPackage]&nbsp;[r][Remove-AppxProvisionedPackage]</code> 
**DSC**
<code>CheckSum&nbsp;[n][New-DscCheckSum]</code>
<code>Configuration&nbsp;[g][Get-DscConfiguration]&nbsp;[pb][Publish-DscConfiguration]&nbsp;[rr][Restore-DscConfiguration]&nbsp;[sa][Start-DscConfiguration]&nbsp;[sp][Stop-DscConfiguration]&nbsp;[t][Test-DscConfiguration]&nbsp;[u][Update-DscConfiguration]</code>
<code>ConfigurationDocument&nbsp;[r][Remove-DscConfigurationDocument]</code>
<code>ConfigurationStatus&nbsp;[g][Get-DscConfigurationStatus]</code>
<code>Debug&nbsp;[d][Disable-DscDebug]&nbsp;[e][Enable-DscDebug]</code>
<code>LocalConfigurationManager&nbsp;[g][Get-DscLocalConfigurationManager]&nbsp;[s][Set-DscLocalConfigurationManager]</code>
<code>Resource&nbsp;[g][Get-DscResource]&nbsp;[i][Invoke-DscResource]</code>
**SmigServer** 
<code>Data [rc][Receive-SmigServerData] [sd][Send-SmigServerData]</code> 
<code>Feature [g][Get-SmigServerFeature]</code> 
<code>Setting [ex][Export-SmigServerSetting] [ip][Import-SmigServerSetting]</code>
**Windows**
<code>Capability&nbsp;[a][Add-WindowsCapability]&nbsp;[g][Get-WindowsCapability]&nbsp;[r][Remove-WindowsCapability]</code>
<code>CorruptMountPoint&nbsp;[c][Clear-WindowsCorruptMountPoint]</code>
<code>CustomDataImage&nbsp;[en][Expand-WindowsCustomDataImage]</code>
<code>CustomImage&nbsp;[n][New-WindowsCustomImage]</code>
<code>Driver&nbsp;[a][Add-WindowsDriver]&nbsp;[ep][Export-WindowsDriver]&nbsp;[g][Get-WindowsDriver]&nbsp;[r][Remove-WindowsDriver]</code> 
<code>Edition&nbsp;[g][Get-WindowsEdition]&nbsp;[s][Set-WindowsEdition]</code>
<code>Image&nbsp;[a][Add-WindowsImage]&nbsp;[dm][Dismount-WindowsImage]&nbsp;[en][Expand-WindowsImage]&nbsp;[ep][Export-windowsImage]&nbsp;[n][New-WindowsImage]&nbsp;[sv][Save-WindowsImage]&nbsp;[ep][Export-WindowsImage]&nbsp;[g][Get-WindowsImage]&nbsp;[mt][Mount-WindowsImage]&nbsp;[n][New-WindowsImage]&nbsp;[om][Optimize-WindowsImage]&nbsp;[rp][Repair-WindowsImage]&nbsp;[r][Remove-WindowsImage]&nbsp;[sl][Split-WindowsImage]</code>
<code>ImageContent&nbsp;[g][Get-WindowsImageContent]</code>
<code>OptionalFeature&nbsp;[d][Disable-WindowsOptionalFeature]&nbsp;[e][Enable-WindowsOptionalFeature]&nbsp;[g][Get-WindowsOptionalFeature]</code>
<code>Package&nbsp;[a][Add-WindowsPackage]&nbsp;[g][Get-WindowsPackage]&nbsp;[r][Remove-WindowsPackage]</code>
<code>ProductKey&nbsp;[s][Set-WindowsProductKey]</code>
<code>ReservedStorageState&nbsp;[g][Get-WindowsReservedStorageState]&nbsp;[s][Set-WindowsReservedStorageState]</code>
<code>Unattend&nbsp;[u][Use-WindowsUnattend]</code>

##### System administration cmdlets
[Disable-LocalUser]: #disable-localuser '```&#10;PS C:\> Disable-LocalUser&#10;PS C:\> dlu&#10;```&#10;Disable a local user account'
[Enable-LocalUser]: #enable-localuser '```&#10;PS C:\> Enable-LocalUser&#10;PS C:\> elu&#10;```&#10;Enable a local user account'
[Get-LocalUser]: #get-localuser '```&#10;PS C:\> Get-LocalUser&#10;PS C:\> glu&#10;```&#10;Display local user account'
[New-LocalUser]: #new-localuser '```&#10;PS C:\> New-LocalUser&#10;PS C:\> nlu&#10;```&#10;Create a local user account'
[Remove-LocalUser]: #remove-localuser '```&#10;PS C:\> Remove-LocalUser&#10;PS C:\> rlu&#10;```&#10;Delete a local user account'
[Rename-LocalUser]: #rename-localuser '```&#10;PS C:\> Rename-LocalUser&#10;PS C:\> rnlu&#10;```&#10;Delete local user account'
[Set-LocalUser]: #set-localuser '```&#10;PS C:\> Set-LocalUser&#10;PS C:\> slu&#10;```&#10;Modify a local user account'

[Add-LocalGroupMember]: #add-localgroupmember '```&#10;PS C:\> Add-LocalGroupMember&#10;```&#10;Add members to a local group'
[Get-LocalGroupMember]: #get-localgroupmember '```&#10;PS C:\> Get-LocalGroupMember&#10;```&#10;Display members of a local group'
[Remove-LocalGroupMember]: #remove-localgroupmember '```&#10;PS C:\> Remove-LocalGroupMember&#10;```&#10;Remove members from a local group'

<code>LocalGroupMember&nbsp;[g][Get-LocalGroupMember]&nbsp;[a][Add-LocalGroupMember]&nbsp;[r][Remove-LocalGroupMember]</code>
<code>LocalUser&nbsp;[g][Get-LocalUser]&nbsp;[n][New-LocalUser]&nbsp;[r][Remove-LocalUser]&nbsp;[s][Set-LocalUser]&nbsp;[e][Enable-LocalUser]&nbsp;[d][Disable-LocalUser]&nbsp;[rn][Rename-LocalUser]</code>

##### Windows objects cmdlets
[Add-WindowsFeature]: #add-windowsfeature '```&#10;PS C:\> Add-WindowsFeature&#10;PS C:\> Install-WindowsFeature&#10;```&#10;Install one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2'
[Edit-NanoServerImage]: #edit-nanoserverimage '```&#10;PS C:\> Edit-NanoServerImage&#10;```&#10;Add a role or feature to an existing Nano Server VHD file&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Get-WindowsFeature]: #get-windowsfeature '```&#10;PS C:\> Get-WindowsFeature&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 15'
[Get-WMIObject]: #get-wmiobject '```&#10;PS C:\> Get-WMIObject&#10;PS C:\> gwmi&#10;```&#10;Gets instances of Windows Management Instrumentation (WMI) classes or information about the available classes.&#10;Superseded by `Get-CimInstance` since Powershell 3.0'
[Install-WindowsFeature]: #install-windowsfeature '```&#10;PS C:\> Install-WindowsFeature&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 15, 171, 225, 377'
[New-NanoServerImage]: #new-nanoserverimage '```&#10;PS C:\> New-NanoServerImage&#10;New-NanoServerImage -DeploymentType guest|host -Edition standard|datacenter -MediaPath root -TargetPath $PATH -ComputerName $NAME&#10;```&#10;Used to create a Nano Server VHD file for Nano Server installation&#10;Required parameters:&#10;  `DeploymentType` specified whether the image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;  `Edition` specifies whether to install the Standard or Datacenter edition of Nano Server&#10;  `MediaPath` specifies the path to the root of the WS2016 installation disk or mounted image&#10;  `BasePath` specifies a path on the local system where the cmdlet creates a copy of the installation files from the location specified in `MediaPath`&#10;  `TargetPath` specifies the full path and filename of the new image to be created with the filename extension (".vhd" or ".vhdx") specifying Generation 1 or Generation 2 image.&#10;  `ComputerName` specifies the computer name that should be assigned to the new image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'

<code>Guid&nbsp;n</code> 
<code>NanoServerImage&nbsp;[n][New-NanoServerImage] [e][Edit-NanoServerImage]</code> 
<code>WMIObject&nbsp;[g][Get-WMIObject]</code> 
**Windows**
<code>Feature&nbsp;[a][Install-WindowsFeature]&nbsp;[g][Get-WindowsFeature]&nbsp;[is][Install-WindowsFeature]</code> 



##### Bash equivalents
[`$!`][&#36;&#36;]/[`!$`][&#36;&#36;] 
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
[`ls`][Get-ChildItem] 
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

## Syntax
### Keywords
The `Throw` keyword generates a terminating error

### Variables
###### Automatic variables
[Automatic variable]: #automatic-variables 'Automatic variable&#10;Variables that store state information for PowerShell and are created and maintained by Powershell.'

[Automatic][Automatic variable] variables are equivalent to environment variables in Linux and also prefixed with `$`.

<!-- Powershell automatic variables -->
[&#36;_]: #variables '```&#10;PS C:\> &#36;_&#10;PS C:\> $PSItem&#10;```&#10;Pipeline object'
[&#36;?]: #variables '```&#10;PS C:\> &#36;?&#10;```&#10;Execution status of the last operation'
[&#36;^]: #variables '```&#10;PS C:\> &#36;^&#10;```&#10;First token in the last line received by the session'
[&#36;&#36;]: #variables '```&#10;PS C:\> &#36;&#36;&#10;```&#10;Last token in the last line received by the session'
[$args]: #variables '```&#10;PS C:\> $args&#10;```&#10;Array of values for undeclared parameters passed to a function, script or script block'
[$HOME]: #variables '```&#10;PS C:\> $HOME&#10;```&#10;Full path of the home directory of the user'
[$IsLinux]: #variables '```&#10;PS C:\> $IsLinux&#10;```&#10;Contains `$True` if the current session is running on a Linux operating system'
[$IsMacOS]: #variables '```&#10;PS C:\> $IsMacOS&#10;```&#10;Contains `$True` if the current session is running on an OS X operating system'
[$IsWindows]: #variables '```&#10;PS C:\> $IsWindows&#10;```&#10;Contains `$True` if the current session is running on a Windows operating system'
[$PID]: #variables '```&#10;PS C:\> $PID&#10;```&#10;Contains process identifier (PID) of the process that is hosting the current PowerShell session'
[$PSCulture]: #variables '```&#10;PS C:\> $PSCulture&#10;```&#10;Name of the culture currently in use in the operating system'
[$PSHome]: #variables '```&#10;PS C:\> Write-Host $$PSHome&#10;```&#10;Full path of installation directory for Windows Powershell (typically %windir%\System32\WindowsPowerShell\v1.0)'
[$PSVersionTable]: #variables '```&#10;PS C:\> $PSVersionTable&#10;```&#10;Read-only hash table that displays details about the version of PowerShell that is running in the current session'
[$PWD]: #variables '```&#10;PS C:\> $PWD&#10;```&#10;Path object that represents the full path of the current directory'
[$profile.CurrentUserCurrentHost]: #variables '```&#10;PS C:\> Write-Host $profile.CurrentUserCurrentHost&#10;PS C:\> Write-Host $profile&#10;```&#10;Filename of current profile (typically %USERPROFILE%\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1)&#10;Microsoft Docs. "About Profiles"'
[$profile.CurrentUserAllHosts]: #variables '```&#10;PS C:\> Write-Host $profile.CurrentUserAllHosts&#10;```&#10;Typically %USERPROFILE%\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1&#10;Microsoft Docs. "About Profiles"'
[$profile.AllUsersAllHosts]: #variables '```&#10;PS C:\> Write-Host $profile.AllUsersAllHosts&#10;```&#10;Typically $PSHome\profile.ps1'
[$profile.AllUsersCurrentHost]: #variables '```&#10;PS C:\> Write-Host $profile.AllUsersCurrentHost&#10;```&#10;Typically $PSHome\Microsoft.PowerShell_profile.ps1'
[$PSHome]: #variables '```&#10;PS C:\> Write-Host $$PSHome&#10;```&#10;Full path of installation directory for Windows Powershell (typically %windir%\System32\WindowsPowerShell\v1.0)'

[` $_`][&#36;_] 
[` $?`][&#36;?] 
[` $^`][&#36;^] 
[` $$`][&#36;&#36;] 
[` $args`][$args] 
[` $HOME`][$HOME] 
[` $IsLinux`][$IsLinux] 
[` $IsMacOS`][$IsMacOS] 
[` $IsWindows`][$IsWindows] 
[` $PID`][$PID] 
[` $PSCulture`][$PSCulture] 
[` $PSHome`][$PSHOME]
[` $PSVersionTable`][$PSVersionTable] 
[` $PWD`][$PWD]

**` $profile`**
[`AllUsersAllHosts`][ $profile.AllUsersAllHosts] 
[`AllUsersCurrentHost`][ $profile.AllUsersCurrentHost] 
[`CurrentUserAllHosts`][ $profile.CurrentUserAllHosts] 
[`CurrentUserCurrentHost`][ $profile.CurrentUserCurrentHost] 

###### Environment variables
Windows environment variables are actually accessed with the syntax `$Env:var`.

[USERPROFILE]: #variables '```&#10;PS C:\> Write-Host $Env:USERPROFILE&#10;```&#10;Location of profile directory of current user (i.e. "C:\Users\jsmith")'
[USERNAME]: #variables '```&#10;PS C:\> Write-Host $Env:USERNAME&#10;```&#10;Name of current user (i.e. "jsmith").'
[APPDATA]: #variables '```&#10;PS C:\> Write-Host $Env:APPDATA&#10;```&#10;The file-system directory that serves as a common repository for application-specific data (i.e. "C:\Users\jsmith\AppData\Roaming").'
[LOCALAPPDATA]: #variables '```&#10;PS C:\> Write-Host $Env:LOCALAPPDATA&#10;```&#10;The file-system directory that serves as a data repository for local, non-roaming applications (i.e. "C:\Users\jsmith\AppData\Local").'
[WINDIR]: #variables '```&#10;PS C:\> Write-Host $Env:WINDIR&#10;```&#10;Windows folder in the system drive'

[`APPDATA`][APPDATA]
[`LOCALAPPDATA`][LOCALAPPDATA] 
[`USERNAME`][USERNAME] 
[`USERPROFILE`][USERPROFILE] 
[`WINDIR`][WINDIR]

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

#### Operators
Syntax          | Effect
---             | ---
`-like`         | wildcard pattern
`-match`        | regex pattern
`-is`           | type comparison

### Filters
Filtering results can be done with 5 commands:
- `Where-Object` (aliased to `where` and `?`): the most commonly used such command
- `Select-Object` (aliased to `sc`ed to specify specific columns of information to be displayed
- `Select-String` (aliased to `sls`)
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

### Cmdlets
#### Active Directory
##### `ADUser`
###### `New-ADUser`
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
###### `Get-ADUser`
Retrieve `LogonWorkstations` property, which is not included in the default object returned by the command
```powershell
Get-ADUSer $user -Properties LogonWorkstations
```
Filter all accounts with `LogonWorkstations` set to something
```powershell
Get-ADUser -Filter * -Properties LogonWorkstations |? LogonWorkstations -ne $null
```
###### `Set-ADUser`
Clear value of `LogonWorkstations` property
```powershell
Set-ADUser $user -LogonWorkstations $null
```
##### `ADAccount`
###### `Search-ADAccount`
[Search-ADAccount -AccountDisabled]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -AccountDisabledAccountDisabled&#10;```&#10;Filter disabled accounts'
[Search-ADAccount -AccountExpired]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -AccountExpiredAccountExpired&#10;```&#10;Filter expired accounts'
[Search-ADAccount -ComputersOnly]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -ComputersOnlyComputersOnly&#10;```&#10;Filter computer accounts'
[Search-ADAccount -LockedOut]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -LockedOutLockedOut&#10;```&#10;Filter locked out accounts'
[Search-ADAccount -PasswordExpired]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -PasswordExpiredPasswordExpired&#10;```&#10;Filter accounts with expired passwords'
[Search-ADAccount -PasswordNeverExpires]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -PasswordNeverExpiresPasswordNeverExpires&#10;```&#10;Filter accounts with passwords that will never expire'
[Search-ADAccount -UsersOnly]: #Search-ADAccount '```&#10;PS C:\> Search-ADAccount -UsersOnlyUsersOnly&#10;```&#10;Filter users'

[`AccountDisabled`][Search-ADAccount -AccountDisabled]
[`AccountExpired`][Search-ADAccount -AccountExpired]
[`ComputersOnly`][Search-ADAccount -ComputersOnly]
[`LockedOut`][Search-ADAccount -LockedOut]
[`PasswordExpired`][Search-ADAccount -PasswordExpired]
[`PasswordNeverExpires`][Search-ADAccount -PasswordNeverExpires]
[`UsersOnly`][Search-ADAccount -UsersOnly]

Display accounts that have been inactive for the last 90 days
```powershell
Search-ADAccount -AccountInactive -TimeSpan 90.00:00:00
```
Display accounts expiring on a particular date
```powershell
Search-ADAccount -AccountExpiring -DateTime "3/18/2019"
```
###### `Unlock-ADAccount`
Unlock account
```powershell
Unlock-ADAccount -identity wbryan
```
###### `Set-ADAccountPassword`
[Set-ADAccountPassword -Identity]: #Set-ADAccountPassword '```&#10;PS C:\> Set-ADAccountPassword -IdentityIdentity&#10;```&#10;Specify an Active Directory user object.'
[Set-ADAccountPassword -Reset]: #Set-ADAccountPassword '```&#10;PS C:\> Set-ADAccountPassword -ResetReset&#10;```&#10;Specify to reset the password on an account (requires `NewPassword`)'
[Set-ADAccountPassword -NewPassword]: #Set-ADAccountPassword '```&#10;PS C:\> Set-ADAccountPassword -NewPasswordNewPassword&#10;```&#10;Specify a new password value'

[**`Identity`**][Set-Adaccountpassword -identity] 
[`NewPassword`][Set-ADAccountPassword -NewPassword]
[`Reset`][Set-ADAccountPassword -Reset]


Reset password
```powershell
Set-ADAccountPassword -Identity MBentley -Reset -NewPassword (ConvertTo-SecureString -AsPlainText "What is 255.255.255.240" -Force)
```
##### `ADGroupMember`
###### `Add-ADGroupMember`
[Add a member to a group](#add-a-member-to-a-group)
##### `ADObject`
###### `Get-ADObject`
Display version of Active Directory schema <sup>[nolabnoparty.com](https://nolabnoparty.com/en/finding-active-directory-schema-version/ "Finding the Active Directory schema version")</sup>
```powershell
Get-ADObject "cn=schema,cn=configuration,dc=domain,dc=com" -properties objectversion
```
###### `Set-ADObject`
Protect users in a specified OU from accidental deletion
```powershell
Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" ` | 
Set-ADObject -ProtectedFromAccidentalDeletion $true
```
##### `ADOrganizationalUnit`
###### `Get-ADOrganizationalUnit`
Display OUs, confirming deletion has taken place
```powershell
Get-ADOrganizationalUnit  -filter * | ft
```
###### `New-ADOrganizationalUnit`
Create a new Organizational Unit
```powershell
New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey
```
###### `Remove-ADOrganizationalUnit`
Remove an OU
```powershell
Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False
```
###### `Set-ADOrganizationalUnit`
Remove accidental deletion protection
```powershell
Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" 
```
##### `ADDSForest`
###### `Install-ADDSForest`
Add a new forest
```powershell
# This will prompt for safe mode administrator password
Install-ADDSForest -DomainName example.com -InstallDNS
```
If the system fails to automatically create a NetBIOS name, it can be manually specified with the named parameter `-DomainNetbiosName`
##### `ADDSDomain`
###### `Install-ADDSDomain`
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
###### `Uninstall-ADDSDomainController`
Demote a domain controller (consummate with uninstalling the AD Domain Controller role)
```powershell
# When removing the last domain controller of a domain, additional options need to be specified that result in the obliteration of the domain, its forest, and associated data.
Uninstall-ADDSDomainController -LocalAdministratorPassword (ConvertTo-SecureString $pw -AsPlainText -Force) -LastDomainControllerInDomain -RemoveApplicationPartitions
```
##### `ADComputer`
###### `New-ADComputer`
##### `ADPrincipalGroupMembership`
###### `Add-ADPrincipalGroupMembership`
```powershell
Add-ADPrincipalGroupMembership -Identity "CN=SysAdmin,CN=Users,DC=corp,DC=packtlab,DC=com" -MemberOf "CN=Enterprise Admins,CN=Users,DC=corp,DC=packtlab,DC=com","CN=Domain Admins,CN=Users,DC=corp,DC=packtlab,DC=com"
```
##### `ADForest`
###### `Get-ADForest`
Display installed forests
```powershell
Get-ADForest | select -ExpandProperty domains
```
###### `Get-ADPrincipalGroupMembership`
<sup>[Jones][Jones]</sup>

```powershell
Get-ADPrincipalGroupMembership sysadmin
```
##### `ADUser`
###### `Get-ADUser`
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
##### `DistributionGroupMember`
###### `Add-DistributionGroupMember`
[Add-DistributionGroupMember -Identity]: #Add-DistributionGroupMember '```&#10;PS C:\> Add-DistributionGroupMember -IdentityIdentity&#10;```&#10;Specifies the group that you want to modify. You can use any value that uniquely identifies the group (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).'
[Add-DistributionGroupMember -Member]: #Add-DistributionGroupMember '```&#10;PS C:\> Add-DistributionGroupMember -MemberMember&#10;```&#10;Specifies the recipient that you want to add to the group. A member can be any mail-enabled recipient in your organization. You can use any value that uniquely identifies the recipient (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).'

[`Identity`][Add-DistributionGroupMember -Identity]
[`Member`][Add-DistributionGroupMember -Member]

#### Commands and Powershell environment
##### `Alias`
###### `Export-Alias`
Export session aliases to a ".ps1" file
```powershell
Export-Alias -Path alias.ps1 -As Script
```
###### `Get-Alias`
Display aliases
```powershell
Get-Alias
```
Display items that point to `Get-ChildItem`
```powershell
Get-Alias -Definition Get-ChildItem
```
###### `New-Alias`
Establish a new alias
```powershell
New-Alias ip Get-NetIPAddress
```
###### `Set-Alias`
Edit an existing alias
```powershell
Set-Alias ip Get-NetAdapter
```
##### `Clipboard`
###### `Get-Clipboard`
Interpret items in clipboard as files
```powershell
Get-Clipboard -Format FileDropList
```
Retrieve various properties of an image in clipboard
```powershell
Get-Clipboard -Format Image
```
###### `Set-Clipboard`
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
With `Append` switch parameter, items can be added without clearing the clipboard:
```powershell
Write-Output 'Hello' | Set-Clipboard -Append
```
##### `Computer`
###### `Add-Computer`
[Add-Computer -NewName]: #add-computer '```&#10;PS C:\> Add-Computer -NewNameNewName&#10;```&#10;Specify a computer name that you want to assign to the computer&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 20'
[Add-Computer -DomainName]: #Add-Computer '```&#10;PS C:\> Add-Computer -DomainNameDomainName&#10;```&#10;Specify the name of the domain that you want the computer to join&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 20'
[Add-Computer -Credential]: #Add-Computer '```&#10;PS C:\> Add-Computer -CredentialCredential&#10;```&#10;Specify the domain and account names for a domain user with domain join privileges&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 20'

[`NewName`][Add-Computer -NewName]
[`DomainName`][Add-Computer -DomainName]
[`Credential`][Add-Computer -Credential]

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
###### `Rename-Computer`
Rename computer
###### `Restart-Computer`
Restart computer
##### `ChildItem`
###### `Get-ChildItem`
##### `Command`
###### `Get-Command`
Display source code of a function <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_functions "About Functions"</sup>
```powershell
(Get-Command mkdir).Definition
```
###### `Invoke-Command`
[Invoke-Command -ThrottleLimit]: #Invoke-Command '```&#10;PS C:\> Invoke-Command -ThrottleLimit&#10;```&#10;Specify the maximum number of concurrent connections that can be established to run the command (32 by default)'
[Invoke-Command -ScriptBlock]: #Invoke-Command '```&#10;PS C:\> Invoke-Command -ScriptBlock&#10;```&#10;Specify commands to run'

[`ScriptBlock`][Invoke-Command -ScriptBlock]
[`ThrottleLimit`][Invoke-Command -ThrottleLimit]

Execute the commands in the block on the machines specified
```powershell
Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}
```
##### `ComputerInfo`
###### `Get-ComputerInfo`
Display computer name <sup>[cmd](README.md#hostname)</sup>
```powershell
Get-ComputerInfo -Property CsName
gin.CsName
```
##### `ExecutionPolicy
###### `Set-ExecutionPolicy`
##### `Help`
###### `Get-Help`
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
###### `Update-Help`
Download help files
##### `Host`
###### `Out-Host`
###### `Read-Host`
###### `Write-Host`
##### `Location`
###### `Set-Location`
##### `Member`
###### `Get-Member`
##### `Module`
###### `Get-Module`
###### `Import-Module`
Import `SmbShare` module
```powershell
Import-Module SmbShare
```
###### `Install-Module`
Install the `Az` module
```powershell
Install-Module -Name Az -AllowClobber
```
##### `Output`
###### `Write-Output`
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
Create a text file <sup>[Jones][Jones]</sup>
```powershell
Write-Output "This is a test network file." -Path | Out-File C:\networkfiles\test.txt
```
##### `PSDrive`
###### `New-PSDrive`
Start a new PSDrive using the `HKEY_CLASSES_ROOT` Windows Registry hive <sup>[powershelleverydayfaq.blogspot.com](http://powershelleverydayfaq.blogspot.com/2012/06/how-to-query-hkeyclassesroot.html "How to query HKEY_CLASSES_ROOT")</sup>
```powershell
ndr -Name HKCR -PSProvider Registry -Root HKEY_CLASSES_ROOT
```
##### `PSReadlineOption`
###### `Get-PSReadlineOption`
Display options available in the module
```powershell
Get-PSReadlineOption
```
###### `Set-PSReadlineOption`
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
##### `PSSnapin`
###### `Add-PSSnapin`
##### `Type`
###### `Add-Type`
Generate a random password 20 characters long <sup>[adamtheautomator.com][https://adamtheautomator.com/powershell-random-password/]</sup>
```powershell
Add-Type -AssemblyName 'System.Web'
[System.Web.Security.Membership]::GeneratePassword(20, 3)
```
#### Networking
##### `Dhcp`
###### `Add-DhcpServerv4Scope`
<sup>[Jones][Jones]</sup>

```powershell
Add-DhcpServerv4Scope -Name "PacktLabNet" -StartRange 10.0.0.50 -EndRange 10.0.0.100 -SubnetMask 255.255.255.0
```
###### `Add-DhcpServerInDC`
<sup>[Jones][Jones]</sup>

```powershell
Add-DhcpServerInDC -DnsName dc.corp.packtlab.com
```
###### `Set-DhcpServerv4OptionValue`
<sup>[Jones][Jones]</sup>

```powershell
Set-DhcpServerv4OptionValue -DnsDomain corp.packtlab.com -DnsServer 10.0.0.1
```
##### `DnsClientServerAddress`
###### `Set-DnsClientServerAddress`
`InterfaceAlias`
`InterfaceIndex`
`ResetServerAddresses`
`ServerAddresses`

Configure DNS server address for a DC on a new corporate intranet <sup>[Jones][Jones]</sup>
```powershell
Set-DnsClientServerAddress -InterfaceAlias "Ethernet" -ServerAddresses 127.0.0.1
```
Configure DNS server addresses for a network interface while setting up Server Core<sup>[Zacker][Zacker]: 20</sup>
```powershell
Set-DnsClientServerAddress -InterfaceIndex 6 -ServerAddresses ("192.168.0.1", "192.168.0.2")
```
Set an interface to get its DNS server from DHCP <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/dnsclient/set-dnsclientserveraddress "Set-DnsClientServerAddress")
```powershell
Set-DnsClientServerAddress -InterfaceIndex 12 -ResetServerAddresses
```
##### `DnsName`
###### `Resolve-DnsName`
```powershell
Resolve-DNSName -Name secure.practicelabs.com.trustanchors -Type dnskey -Server plabdm01
```
##### `NetAdapter`
###### `Get-NetAdapter`
Display available network interfaces <sup>[Zacker][Zacker]: 19</sup>
##### `NetFirewallRule`
###### `Enable-NetFirewallRule`
Configure the firewall to allow Hyper-V replication <sup>[Zacker][Zacker]: 301</sup>
```powershell
Enable-NetFirewallRule -DisplayName "hyper-v replica http listener (tcp-in)"
Enable-NetFirewallRule -DisplayName "hyper-v replica https listener (tcp-in)"
```
Configure firewall to allow remote administration using MMC snap-ins
```powershell
Enable-NetFirewallRule -DisplayGroup "Remote Administration"
```
```powershell
Enable-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In
Enable-NetFirewallRule -name RemoteEventLogSvc-In-TCP
Enable-NetFirewallRule -name RemoteEventLogSvc-NP-In-TCP
Enable-NetFirewallRule -name RemoteEventLogSvc-RPCSS-In-TCP
```
###### `Get-NetFirewallRule`
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
###### `New-NetFirewallRule`
Set a new firewall rule for incoming WinRM connections
```powershell
New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
```
###### `Set-NetFirewallRule`
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

##### `NetIpAddress`
###### `New-NetIpAddress`
[New-NetIpAddress -DefaultGateway]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -DefaultGateway&#10;```&#10;Specify IP address of local router that computer should use to access other networks'
[New-NetIpAddress -InterfaceIndex]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -InterfaceIndex&#10;```&#10;Specify adapter to be configured using interface numbers as displayed by `Get-NetAdapter`'
[New-NetIpAddress -IpAddress]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -IpAddress&#10;```&#10;Specify IP address to be assigned to adapter'
[New-NetIpAddress -PrefixLength]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -PrefixLength&#10;```&#10;Specify subnet mask value'

[`DefaultGateway`][New-NetIpAddress -DefaultGateway]
[`InterfaceIndex`][New-NetIpAddress -InterfaceIndex]
[`IpAddress`][New-NetIpAddress -IpAddress]
[`PrefixLength`][New-NetIpAddress -PrefixLength]

Configure the Domain Controller in a new corporate intranet <sup>[Jones][Jones]</sup>
```powershell
New-NetIPAddress 10.0.0.1 -InterfaceAlias "Ethernet" -PrefixLength 24
```
Configure a network adapter 
```powershell
New-NetIpAddress -InterfaceIndex 6 -IpAddress 192.168.0.200 -PrefixLength 24 -DefaultGateway 192.168.0.1
```
##### `WebRequest`
###### `Invoke-WebRequest`
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
Trigger Azure Automation runbook by POSTing a JSON file to a configured webhook 
```powershell
$uri = "https://s4events.azure-automation.net/webhooks?token=1xc1iDzrkLc7Wqot341GzameBhYavv0msLwkQQo%2bB88%3d"

$vms  = @(
  @{ Name="web1";ResourceGroup="webservers"},
  @{ Name="web2";ResourceGroup="webservers"}
)

$body = ConvertTo-Json -InputObject $vms
$header = @{ message="Started by Mike Pfeiffer"}

Invoke-WebRequest -Method Post -Uri $uri -Body $body -Headers $header
```
#### Process control
##### `Process`
###### `Start-Process`
Run a program as admin
```powershell
Start-Process cmd -Verb runas
saps cmd -v runas
```
#### Remote administration
##### `PSRemoting`
###### `Enable-PSRemoting`
`SkipNetworkProfileCheck`

##### `PSSession`
[msdocs:Connect-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Connect-pssession "Connect-PSSession"
[msdocs:Disconnect-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Disconnect-pssession "Disconnect-PSSession"
[msdocs:Enter-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/enter-pssession "Enter-PSSession"
[msdocs:Exit-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Exit-pssession "Exit-PSSession"
[msdocs:Get-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Get-pssession "Get-PSSession"
[msdocs:New-PSSession]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/New-pssession "New-PSSession"

###### `Connect-PSSession`[^][msdocs:Connect-PSSession]
###### `Disconnect-PSSession`[^][msdocs:Disconnect-PSSession]
Terminate a remote PowerShell session begun with [`New-PSSession`][New-PSSession] <sup>[Zacker][Zacker]: 22</sup>
###### `Enter-PSSession`[^][msdocs:Enter-PSSession]
`UseSSL`

Interact with the specified PowerShell session
```powershell
Enter-PSSession -id 1
```
Start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
```powershell
Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey
```
###### `Exit-PSSession`[^][msdocs:Exit-PSSession]
Exit a remote PowerShell session <sup>[Zacker][Zacker]: 22</sup>
End the PowerShell session with the specified computer
```powershell
Exit-PSSession -ComputerName demodc
```
###### `Get-PSSession`[^][msdocs:Get-PSSession]
Display PowerShell sessions
```powershell
Get-PSSession
```
###### `New-PSSession`[^][msdocs:New-PSSession]
`-ComputerName`

Manage a Windows Server remotely <sup>[Zacker][Zacker]: 21</sup>
```powershell
New-PSSession -ComputerName rtmsvrd
```
Start a new PowerShell session, connecting to the specified computer
```powershell
New-PSSession -ComputerName core02
```
##### `PSSessionConfiguration`

[msdocs:New-PSSessionConfigurationFile]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/new-pssessionconfigurationfile "New-PSSessionConfigurationFile"
[msdocs:Register-PSSessionConfiguration]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/register-pssessionconfiguration "Register-PSSessionConfiguration"
[msdocs:Set-PSSessionConfiguration]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Set-pssessionconfiguration "Set-PSSessionConfiguration"
[msdocs:Get-PSSessionConfiguration]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Get-pssessionconfiguration "Get-PSSessionConfiguration"

###### `Get-PSSessionConfiguration`[^][msdocs:Get-PSSessionConfiguration]
###### `Register-PSSessionConfiguration`[^][msdocs:Register-PSSessionConfiguration]
###### `Set-PSSessionConfiguration`[^][msdocs:Set-PSSessionConfiguration]
###### `New-PSSessionConfigurationFile`[^][New-PSSessionConfigurationFile]

##### `WSManCredSSP`
[msdocs:Enable-WSManCredSSP]: https://docs.microsoft.com/en-us/powershell/module/microsoft.wsman.management/enable-wsmancredssp "Enable-WSManCredSSP"

###### `Enable-WSManCredSSP`[^][msdocs:Enable-WSManCredSSP]
`Delegate`
`Role`

Tasks:
- [Enable CredSSP](#enable-credssp)



#### Disks
###### `Get-DedupProperties`[^][msdocs:Get-DedupProperties]
###### `Clear-Disk`[^][msdocs:Clear-Disk]
###### `Get-Disk`[^][msdocs:Get-Disk]
###### `Initialize-Disk`[^][msdocs:Initialize-Disk]
###### `Set-Disk`[^][msdocs:Set-Disk]
###### `Update-Disk`[^][msdocs:Update-Disk]
###### `Dismount-DiskImage`[^][msdocs:Dismount-DiskImage]
###### `Get-DiskImage`[^][msdocs:Get-DiskImage]
###### `Mount-DiskImage`[^][msdocs:Mount-DiskImage]
###### `Get-DiskStorageNodeView`[^][msdocs:Get-DiskStorageNodeView]
###### `Get-FileIntegrity`[^][msdocs:Get-FileIntegrity]
###### `Repair-FileIntegrity`[^][msdocs:Repair-FileIntegrity]
###### `Set-FileIntegrity`[^][msdocs:Set-FileIntegrity]
###### `Debug-FileShare`[^][msdocs:Debug-FileShare]
###### `Get-FileShare`[^][msdocs:Get-FileShare]
###### `New-FileShare`[^][msdocs:New-FileShare]
###### `Remove-FileShare`[^][msdocs:Remove-FileShare]
###### `Set-FileShare`[^][msdocs:Set-FileShare]
###### `Block-FileShareAccess`[^][msdocs:Block-FileShareAccess]
###### `Grant-FileShareAccess`[^][msdocs:Grant-FileShareAccess]
###### `Revoke-FileShareAccess`[^][msdocs:Revoke-FileShareAccess]
###### `Unblock-FileShareAccess`[^][msdocs:Unblock-FileShareAccess]
###### `Get-FileShareAccessControlEntry`[^][msdocs:Get-FileShareAccessControlEntry]
###### `Set-FileStorageTier`[^][msdocs:Set-FileStorageTier]
###### `Clear-FileStorageTier`[^][msdocs:Clear-FileStorageTier]
###### `Get-FileStorageTier`[^][msdocs:Get-FileStorageTier]
###### `Update-HostStorageCache`[^][msdocs:Update-HostStorageCache]
###### `Get-InitiatorId`[^][msdocs:Get-InitiatorId]
###### `Remove-InitiatorId`[^][msdocs:Remove-InitiatorId]
###### `Remove-InitiatorIdFromMaskingSet`[^][msdocs:Remove-InitiatorIdFromMaskingSet]
###### `Add-InitiatorIdToMaskingSet`[^][msdocs:Add-InitiatorIdToMaskingSet]
###### `Get-InitiatorPort`[^][msdocs:Get-InitiatorPort]
###### `Set-InitiatorPort`[^][msdocs:Set-InitiatorPort]
###### `Get-MaskingSet`[^][msdocs:Get-MaskingSet]
###### `New-MaskingSet`[^][msdocs:New-MaskingSet]
###### `Remove-MaskingSet`[^][msdocs:Remove-MaskingSet]
###### `Rename-MaskingSet`[^][msdocs:Rename-MaskingSet]
###### `Get-OffloadDataTransferSetting`[^][msdocs:Get-OffloadDataTransferSetting]
###### `Get-Partition`[^][msdocs:Get-Partition]
###### `New-Partition`[^][msdocs:New-Partition]
###### `Remove-Partition`[^][msdocs:Remove-Partition]
###### `Resize-Partition`[^][msdocs:Resize-Partition]
###### `Set-Partition`[^][msdocs:Set-Partition]
###### `Add-PartitionAccessPath`[^][msdocs:Add-PartitionAccessPath]
###### `Remove-PartitionAccessPath`[^][msdocs:Remove-PartitionAccessPath]
###### `Get-PartitionSupportedSize`[^][msdocs:Get-PartitionSupportedSize]
###### `Add-PhysicalDisk`[^][msdocs:Add-PhysicalDisk]
###### `Get-PhysicalDisk`[^][msdocs:Get-PhysicalDisk]
###### `Remove-PhysicalDisk`[^][msdocs:Remove-PhysicalDisk]
###### `Reset-PhysicalDisk`[^][msdocs:Reset-PhysicalDisk]
###### `Set-PhysicalDisk`[^][msdocs:Set-PhysicalDisk]
###### `Disable-PhysicalDiskIdentification`[^][msdocs:Disable-PhysicalDiskIdentification]
###### `Enable-PhysicalDiskIdentification`[^][msdocs:Enable-PhysicalDiskIdentification]
###### `Get-PhysicalDiskStorageNodeView`[^][msdocs:Get-PhysicalDiskStorageNodeView]
###### `Get-PhysicalExtent`[^][msdocs:Get-PhysicalExtent]
###### `Get-PhysicalExtentAssociation`[^][msdocs:Get-PhysicalExtentAssociation]
###### `Get-ResiliencySetting`[^][msdocs:Get-ResiliencySetting]
###### `Set-ResiliencySetting`[^][msdocs:Set-ResiliencySetting]
###### `Get-StorageAdvancedProperty`[^][msdocs:Get-StorageAdvancedProperty]
###### `Get-StorageDiagnosticInfo`[^][msdocs:Get-StorageDiagnosticInfo]
###### `Start-StorageDiagnosticLog`[^][msdocs:Start-StorageDiagnosticLog]
###### `Stop-StorageDiagnosticLog`[^][msdocs:Stop-StorageDiagnosticLog]
###### `Get-StorageEnclosure`[^][msdocs:Get-StorageEnclosure]
###### `Disable-StorageEnclosureIdentification`[^][msdocs:Disable-StorageEnclosureIdentification]
###### `Enable-StorageEnclosureIdentification`[^][msdocs:Enable-StorageEnclosureIdentification]
###### `Get-StorageEnclosureStorageNodeView`[^][msdocs:Get-StorageEnclosureStorageNodeView]
###### `Get-StorageEnclosureVendorData`[^][msdocs:Get-StorageEnclosureVendorData]
###### `Get-StorageFaultDomain`[^][msdocs:Get-StorageFaultDomain]
###### `Get-StorageFileServer`[^][msdocs:Get-StorageFileServer]
###### `New-StorageFileServer`[^][msdocs:New-StorageFileServer]
###### `Remove-StorageFileServer`[^][msdocs:Remove-StorageFileServer]
###### `Set-StorageFileServer`[^][msdocs:Set-StorageFileServer]
###### `Update-StorageFirmware`[^][msdocs:Update-StorageFirmware]
###### `Get-StorageFirmwareInformation`[^][msdocs:Get-StorageFirmwareInformation]
###### `Get-StorageHealthAction`[^][msdocs:Get-StorageHealthAction]
###### `Get-StorageHealthReport`[^][msdocs:Get-StorageHealthReport]
###### `Get-StorageHealthSetting`[^][msdocs:Get-StorageHealthSetting]
###### `Remove-StorageHealthSetting`[^][msdocs:Remove-StorageHealthSetting]
###### `Set-StorageHealthSetting`[^][msdocs:Set-StorageHealthSetting]
###### `Disable-StorageHighAvailability`[^][msdocs:Disable-StorageHighAvailability]
###### `Enable-StorageHighAvailability`[^][msdocs:Enable-StorageHighAvailability]
###### `Get-StorageJob`[^][msdocs:Get-StorageJob]
###### `Stop-StorageJob`[^][msdocs:Stop-StorageJob]
###### `Disable-StorageMaintenanceMode`[^][msdocs:Disable-StorageMaintenanceMode]
###### `Enable-StorageMaintenanceMode`[^][msdocs:Enable-StorageMaintenanceMode]
###### `Get-StorageNode`[^][msdocs:Get-StorageNode]
###### `Get-StoragePool`[^][msdocs:Get-StoragePool]
###### `New-StoragePool`[^][msdocs:New-StoragePool]
###### `Optimize-StoragePool`[^][msdocs:Optimize-StoragePool]
###### `Remove-StoragePool`[^][msdocs:Remove-StoragePool]
###### `Set-StoragePool`[^][msdocs:Set-StoragePool]
###### `Update-StoragePool`[^][msdocs:Update-StoragePool]
###### `Get-StorageProvider`[^][msdocs:Get-StorageProvider]
###### `Set-StorageProvider`[^][msdocs:Set-StorageProvider]
###### `Update-StorageProviderCache`[^][msdocs:Update-StorageProviderCache]
###### `Get-StorageReliabilityCounter`[^][msdocs:Get-StorageReliabilityCounter]
###### `Reset-StorageReliabilityCounter`[^][msdocs:Reset-StorageReliabilityCounter]
###### `Get-StorageSetting`[^][msdocs:Get-StorageSetting]
###### `Set-StorageSetting`[^][msdocs:Set-StorageSetting]
###### `Debug-StorageSubSystem`[^][msdocs:Debug-StorageSubSystem]
###### `Get-StorageSubsystem`[^][msdocs:Get-StorageSubsystem]
###### `Register-StorageSubsystem`[^][msdocs:Register-StorageSubsystem]
###### `Set-StorageSubsystem`[^][msdocs:Set-StorageSubsystem]
###### `Unregister-StorageSubsystem`[^][msdocs:Unregister-StorageSubsystem]
###### `New-StorageSubsystemVirtualDisk`[^][msdocs:New-StorageSubsystemVirtualDisk]
###### `Get-StorageTier`[^][msdocs:Get-StorageTier]
###### `New-StorageTier`[^][msdocs:New-StorageTier]
###### `Remove-StorageTier`[^][msdocs:Remove-StorageTier]
###### `Resize-StorageTier`[^][msdocs:Resize-StorageTier]
###### `Set-StorageTier`[^][msdocs:Set-StorageTier]
###### `Get-StorageTierSupportedSize`[^][msdocs:Get-StorageTierSupportedSize]
###### `Get-SupportedClusterSizes`[^][msdocs:Get-SupportedClusterSizes]
###### `Get-SupportedFileSystems`[^][msdocs:Get-SupportedFileSystems]
###### `Get-TargetPort`[^][msdocs:Get-TargetPort]
###### `Get-TargetPortal`[^][msdocs:Get-TargetPortal]
###### `Remove-TargetPortFromMaskingSet`[^][msdocs:Remove-TargetPortFromMaskingSet]
###### `Add-TargetPortToMaskingSet`[^][msdocs:Add-TargetPortToMaskingSet]
###### `Connect-VirtualDisk`[^][msdocs:Connect-VirtualDisk]
###### `Disconnect-VirtualDisk`[^][msdocs:Disconnect-VirtualDisk]
###### `Get-VirtualDisk`[^][msdocs:Get-VirtualDisk]
###### `Hide-VirtualDisk`[^][msdocs:Hide-VirtualDisk]
###### `New-VirtualDisk`[^][msdocs:New-VirtualDisk]
###### `Remove-VirtualDisk`[^][msdocs:Remove-VirtualDisk]
###### `Repair-VirtualDisk`[^][msdocs:Repair-VirtualDisk]
###### `Resize-VirtualDisk`[^][msdocs:Resize-VirtualDisk]
###### `Set-VirtualDisk`[^][msdocs:Set-VirtualDisk]
###### `Show-VirtualDisk`[^][msdocs:Show-VirtualDisk]
###### `New-VirtualDiskClone`[^][msdocs:New-VirtualDiskClone]
###### `Remove-VirtualDiskFromMaskingSet`[^][msdocs:Remove-VirtualDiskFromMaskingSet]
###### `New-VirtualDiskSnapshot`[^][msdocs:New-VirtualDiskSnapshot]
###### `Get-VirtualDiskSupportedSize`[^][msdocs:Get-VirtualDiskSupportedSize]
###### `Add-VirtualDiskToMaskingSet`[^][msdocs:Add-VirtualDiskToMaskingSet]
###### `Debug-Volume`[^][msdocs:Debug-Volume]
###### `Format-Volume`[^][msdocs:Format-Volume]
###### `Get-Volume`[^][msdocs:Get-Volume]
###### `New-Volume`[^][msdocs:New-Volume]
###### `Optimize-Volume`[^][msdocs:Optimize-Volume]
###### `Repair-Volume`[^][msdocs:Repair-Volume]
###### `Set-Volume`[^][msdocs:Set-Volume]
###### `Write-VolumeCache`[^][msdocs:Write-VolumeCache]
###### `Get-VolumeCorruptionCount`[^][msdocs:Get-VolumeCorruptionCount]
###### `Get-VolumeScrubPolicy`[^][msdocs:Get-VolumeScrubPolicy]
###### `Set-VolumeScrubPolicy`[^][msdocs:Set-VolumeScrubPolicy]


##### `DedupVolume`
###### `Enable-DedupVolume`
Enable deduplication <sup>[Zacker][Zacker]: 157</sup>
```powershell
Enable-DedupVolume -Volume "e:" -UsageType default
Enable-DedupVolume -Volume "\\?\\volume{26a21bda-a627-11d7-9931-806e6f6e6963}" -UsageType backup
```
##### `DiskImage`
###### `Mount-DiskImage`
Mount a VHD or VHDX file <sup>[Zacker][Zacker]: 92</sup>
```powershell
Mount-DiskImage -ImagePath $file
```
##### `Partition`
###### `Get-Partition`
Display a list of existing partitions, their drive letters, and the disk they are associated with <sup>[sumtips.com][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]</sup>
```powershell
Get-Disk | Get-Partition
```
###### `New-Partition`
Use all available size for a new partition <sup>[sumtips.com][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]</sup>
```powershell
New-Partition -DiskNumber 1 -UseMaximumSize
```
Automatically assign a drive letter
```powershell
New-Partition -DiskNumber 1 -UseMaximumSize -AssignDriveLetter
```
###### `Remove-Partition`
Remove a partition <sup>[sumtips.com][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]</sup>
```powershell
Remove-Partition -DiskNumber 1 -PartitionNumber 1
```
Remove a partition without confirmation
```powershell
Remove-Partition -DiskNumber 1 -PartitionNumber 1 -Confirm:$false
```
##### `Volume`
###### `Format-Volume`
Full format of specified drive <sup>[sumtips.com][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]</sup>
```powershell
Format-Volume -DriveLetter S -FileSystem FAT32 -NewFileSystemLabel SumTips -Full
```
###### `New-Volume`
Create a virtual disk that uses parity resiliency and two tiers, with the default friendly names of Performance for SSDs and Capacity for HDDs <sup>[Zacker][Zacker]: 355</sup>
```powershell
New-Volume -StoragePool "s2d*" -FriendlyName vdisk1 -Filesystem csvfs_refs -ResiliencySettingName parity -StorageTiersFriendlyNames performance,capacity -StorageTierSizes 10gb,100gb
```
##### `Disk`
###### `Get-Disk`
Display a list of existing partitions, their drive letters, and the disk they are associated with <sup>[sumtips.com][https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]</sup>
```powershell
Get-Disk | Get-Partition
```
#### Files
##### `Archive`
###### `Compress-Archive`
###### `Expand-Archive`
Decompress archives
```powershell
Expand-Archive
```
##### `CliXml`
###### `Export-CliXml`
###### `Import-CliXml`
##### `Content`
###### `Add-Content`
Append a line to the `hosts` file
```powershell
Add-Content -Path C:\Windows\System32\drivers\etc\hosts -Value "76.184.117.203 mohsen"
ac $Env:windir\System32\drivers\etc\hosts "76.184.117.203 mohsen"
```
###### `Get-Content`
Make a PowerShell object from a JSON file
```powershell
Get-Content -Path file.json | ConvertFrom-Json
```
##### `Csv`
###### `Export-Csv`
###### `Import-Csv`
Add a CSV full of users
```powershell
Import-Csv users.csv | foreach { New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -Enabled $True -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) }
```
##### `Item`
###### `Copy-Item`
Copy files to and from an open Powershell session <sup>[Zacker][Zacker]: 180</sup>
```powershell
Copy-Item -ToSession (Get-PSSession) -Path C:\temp\file.txt -Destination C:\users
Copy-Item -FromSession (Get-PSSession) -Path C:\users\file.txt -Destination C:\temp
```
###### `Get-Item`
###### `New-Item`
[New-Item &#84;]: #New-Item '```&#10;PS C:\> New-Item Type&#10;PS C:\> New-Item -ItemType&#10;```&#10;&#10;Specify the provider-specified type of the new item; values depend on the context.'

`Name`
[`Type`][New-Item &#84;]
`Value`

Create a folder
```powershell
New-Item -ItemType "directory" Folder
ni -Type "directory" Folder
```
###### `Remove-Item`
Clear Windows Temp folder, suppressing errors
```powershell
ri -r $Env:temp -ea 0
Remove-Item -Recurse $Env:temp -ErrorAction 'silentlycontinue'
```
Remove Microsoft Office identities from Registry
```powershell
Remove-Item HKCU:\Software\Microsoft\Office\16.0\Common\Identity\Identities\*
```
Clear Teams cache <sup>[commsverse.blog](https://commsverse.blog/2018/09/28/clear-the-microsoft-teams-client-cache/ "Clear the Microsoft Teams client cache")</sup>
```powershell
Remove-Item $env:APPDATA"\Microsoft\teams\application cache\cache", $env:APPDATA"\Microsoft\teams\blob_storage", $env:APPDATA"\Microsoft\teams\databases", $env:APPDATA"\Microsoft\teams\cache", $env:APPDATA"\Microsoft\teams\gpucache", $env:APPDATA"\Microsoft\teams\Local Storage", $env:APPDATA"\Microsoft\teams\Indexeddb", $env:APPDATA"\Microsoft\teams\tmp" -Recurse -ErrorAction "silentlycontinue"
```
###### `Set-Item`
Add an IP address to the Trusted Hosts list, bypassing the use of Kerberos to authenticate the session <sup>[Zacker][Zacker]: 56</sup>
```powershell
Set-Item wsman:\localhost\client\trustedhosts "192.168.10.41"
```
Enable CredSSP on the local computer <sup>[Jones][SOPR]: 50</sup>
```powershell
Set-Item WSMAN:\localhost\client\auth\credssp -value $true
```
Enable CredSSP on the intermediate server when attempting to make the "second hop" <sup>[Jones][SOPR]: 50</sup>
```powershell
Set-Item WSMAN:\localhost\service\auth\credssp -value $true
```
##### `ItemProperty`
###### `New-ItemProperty`
Create a Registry key in order to use a local user account that is not the builtin Administrator account in order to manage a single domain cluster <sup>[Zacker][Zacker]: 315</sup>
```powershell
New-ItemProperty -Path HKLM:\Software\Microsoft\Windows\currentversion\policies\system -Name LocalAccountTokenFilterPolicy -Value 1
```
##### `Null`
###### `Out-Null`
#### Filters
##### `Object`
[msdocs:ForEach-Object]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/foreach-object "ForEach-Object"
[msdocs:Select-Object]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Select-object "Select-Object"
[msdocs:Measure-Object]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Measure-object "Measure-Object"
[msdocs:New-Object]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/New-object "New-Object"
[msdocs:Where-Object]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/Where-object "Where-Object"

###### `Measure-Object`[^][msdocs:Measure-Object]
###### `ForEach-Object`[^][msdocs:ForEach-Object]
###### `New-Object`[^][msdocs:New-Object]
###### `Select-Object`[^][msdocs:Select-Object]
Create a custom property <sup>[Pfeiffer](https://portal.cloudskills.io/products/azure-powershell-the-ultimate-beginners-course/categories/2529580/posts/8443858 "Azure PowerShell course") </sup>
```powershell
Get-AzVM | Select-Object Name,@{Name="DataDiskCount"; Expression={$_.StorageProfile.DataDisks.count}}
```
###### `Where-Object`[^][msdocs:Where-Object]
#### Hyper-V
[msdocs:Add-VMDvdDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMDvdDrive "Add-VMDvdDrive"
[msdocs:Add-VMFibreChannelHba]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMFibreChannelHba "Add-VMFibreChannelHba"
[msdocs:Add-VMGroupMember]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMGroupMember "Add-VMGroupMember"
[msdocs:Add-VMHardDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMHardDiskDrive "Add-VMHardDiskDrive"
[msdocs:Add-VMMigrationNetwork]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMMigrationNetwork "Add-VMMigrationNetwork"
[msdocs:Add-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMNetworkAdapter "Add-VMNetworkAdapter"
[msdocs:Add-VMNetworkAdapterAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMNetworkAdapterAcl "Add-VMNetworkAdapterAcl"
[msdocs:Add-VMNetworkAdapterExtendedAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMNetworkAdapterExtendedAcl "Add-VMNetworkAdapterExtendedAcl"
[msdocs:Add-VmNetworkAdapterRoutingDomainMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VmNetworkAdapterRoutingDomainMapping "Add-VmNetworkAdapterRoutingDomainMapping"
[msdocs:Add-VMRemoteFx3dVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMRemoteFx3dVideoAdapter "Add-VMRemoteFx3dVideoAdapter"
[msdocs:Add-VMScsiController]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMScsiController "Add-VMScsiController"
[msdocs:Add-VMStoragePath]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMStoragePath "Add-VMStoragePath"
[msdocs:Add-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMSwitch "Add-VMSwitch"
[msdocs:Add-VMSwitchExtensionPortFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMSwitchExtensionPortFeature "Add-VMSwitchExtensionPortFeature"
[msdocs:Add-VMSwitchExtensionSwitchFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMSwitchExtensionSwitchFeature "Add-VMSwitchExtensionSwitchFeature"
[msdocs:Add-VMSwitchTeamMember]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Add-VMSwitchTeamMember "Add-VMSwitchTeamMember"
[msdocs:Checkpoint-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Checkpoint-VM "Checkpoint-VM"
[msdocs:Compare-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Compare-VM "Compare-VM"
[msdocs:Complete-VMFailover]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Complete-VMFailover "Complete-VMFailover"
[msdocs:Connect-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Connect-VMNetworkAdapter "Connect-VMNetworkAdapter"
[msdocs:Connect-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Connect-VMSan "Connect-VMSan"
[msdocs:Copy-VMFile]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Copy-VMFile "Copy-VMFile"
[msdocs:Debug-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Debug-VM "Debug-VM"
[msdocs:Disable-VMConsoleSupport]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMConsoleSupport "Disable-VMConsoleSupport"
[msdocs:Disable-VMEventing]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMEventing "Disable-VMEventing"
[msdocs:Disable-VMIntegrationService]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMIntegrationService "Disable-VMIntegrationService"
[msdocs:Disable-VMMigration]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMMigration "Disable-VMMigration"
[msdocs:Disable-VMRemoteFXPhysicalVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMRemoteFXPhysicalVideoAdapter "Disable-VMRemoteFXPhysicalVideoAdapter"
[msdocs:Disable-VMResourceMetering]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMResourceMetering "Disable-VMResourceMetering"
[msdocs:Disable-VMSwitchExtension]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMSwitchExtension "Disable-VMSwitchExtension"
[msdocs:Disable-VMTPM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disable-VMTPM "Disable-VMTPM"
[msdocs:Disconnect-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disconnect-VMNetworkAdapter "Disconnect-VMNetworkAdapter"
[msdocs:Disconnect-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Disconnect-VMSan "Disconnect-VMSan"
[msdocs:Enable-VMConsoleSupport]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMConsoleSupport "Enable-VMConsoleSupport"
[msdocs:Enable-VMEventing]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMEventing "Enable-VMEventing"
[msdocs:Enable-VMIntegrationService]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMIntegrationService "Enable-VMIntegrationService"
[msdocs:Enable-VMMigration]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMMigration "Enable-VMMigration"
[msdocs:Enable-VMRemoteFXPhysicalVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMRemoteFXPhysicalVideoAdapter "Enable-VMRemoteFXPhysicalVideoAdapter"
[msdocs:Enable-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMReplication "Enable-VMReplication"
[msdocs:Enable-VMResourceMetering]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMResourceMetering "Enable-VMResourceMetering"
[msdocs:Enable-VMSwitchExtension]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMSwitchExtension "Enable-VMSwitchExtension"
[msdocs:Enable-VMTPM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Enable-VMTPM "Enable-VMTPM"
[msdocs:Export-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Export-VM "Export-VM"
[msdocs:Export-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Export-VMSnapshot "Export-VMSnapshot"
[msdocs:Get-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VM "Get-VM"
[msdocs:Get-VMBios]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMBios "Get-VMBios"
[msdocs:Get-VMComPort]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMComPort "Get-VMComPort"
[msdocs:Get-VMConnectAccess]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMConnectAccess "Get-VMConnectAccess"
[msdocs:Get-VMDvdDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMDvdDrive "Get-VMDvdDrive"
[msdocs:Get-VMFibreChannelHba]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMFibreChannelHba "Get-VMFibreChannelHba"
[msdocs:Get-VMFirmware]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMFirmware "Get-VMFirmware"
[msdocs:Get-VMFloppyDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMFloppyDiskDrive "Get-VMFloppyDiskDrive"
[msdocs:Get-VMGroup]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMGroup "Get-VMGroup"
[msdocs:Get-VMHardDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHardDiskDrive "Get-VMHardDiskDrive"
[msdocs:Get-VMHost]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHost "Get-VMHost"
[msdocs:Get-VMHostCluster]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHostCluster "Get-VMHostCluster"
[msdocs:Get-VMHostNumaNode]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHostNumaNode "Get-VMHostNumaNode"
[msdocs:Get-VMHostNumaNodeStatus]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHostNumaNodeStatus "Get-VMHostNumaNodeStatus"
[msdocs:Get-VMHostSupportedVersion]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMHostSupportedVersion "Get-VMHostSupportedVersion"
[msdocs:Get-VMIdeController]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMIdeController "Get-VMIdeController"
[msdocs:Get-VMIntegrationService]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMIntegrationService "Get-VMIntegrationService"
[msdocs:Get-VMKeyProtector]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMKeyProtector "Get-VMKeyProtector"
[msdocs:Get-VMMemory]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMMemory "Get-VMMemory"
[msdocs:Get-VMMigrationNetwork]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMMigrationNetwork "Get-VMMigrationNetwork"
[msdocs:Get-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapter "Get-VMNetworkAdapter"
[msdocs:Get-VMNetworkAdapterAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterAcl "Get-VMNetworkAdapterAcl"
[msdocs:Get-VMNetworkAdapterExtendedAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterExtendedAcl "Get-VMNetworkAdapterExtendedAcl"
[msdocs:Get-VMNetworkAdapterFailoverConfiguration]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterFailoverConfiguration "Get-VMNetworkAdapterFailoverConfiguration"
[msdocs:Get-VmNetworkAdapterIsolation]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VmNetworkAdapterIsolation "Get-VmNetworkAdapterIsolation"
[msdocs:Get-VMNetworkAdapterRoutingDomainMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterRoutingDomainMapping "Get-VMNetworkAdapterRoutingDomainMapping"
[msdocs:Get-VMNetworkAdapterTeamMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterTeamMapping "Get-VMNetworkAdapterTeamMapping"
[msdocs:Get-VMNetworkAdapterVlan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMNetworkAdapterVlan "Get-VMNetworkAdapterVlan"
[msdocs:Get-VMProcessor]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMProcessor "Get-VMProcessor"
[msdocs:Get-VMRemoteFx3dVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMRemoteFx3dVideoAdapter "Get-VMRemoteFx3dVideoAdapter"
[msdocs:Get-VMRemoteFXPhysicalVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMRemoteFXPhysicalVideoAdapter "Get-VMRemoteFXPhysicalVideoAdapter"
[msdocs:Get-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMReplication "Get-VMReplication"
[msdocs:Get-VMReplicationAuthorizationEntry]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMReplicationAuthorizationEntry "Get-VMReplicationAuthorizationEntry"
[msdocs:Get-VMReplicationServer]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMReplicationServer "Get-VMReplicationServer"
[msdocs:Get-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMResourcePool "Get-VMResourcePool"
[msdocs:Get-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSan "Get-VMSan"
[msdocs:Get-VMScsiController]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMScsiController "Get-VMScsiController"
[msdocs:Get-VMSecurity]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSecurity "Get-VMSecurity"
[msdocs:Get-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSnapshot "Get-VMSnapshot"
[msdocs:Get-VMStoragePath]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMStoragePath "Get-VMStoragePath"
[msdocs:Get-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitch "Get-VMSwitch"
[msdocs:Get-VMSwitchExtension]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchExtension "Get-VMSwitchExtension"
[msdocs:Get-VMSwitchExtensionPortData]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchExtensionPortData "Get-VMSwitchExtensionPortData"
[msdocs:Get-VMSwitchExtensionPortFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchExtensionPortFeature "Get-VMSwitchExtensionPortFeature"
[msdocs:Get-VMSwitchExtensionSwitchData]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchExtensionSwitchData "Get-VMSwitchExtensionSwitchData"
[msdocs:Get-VMSwitchExtensionSwitchFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchExtensionSwitchFeature "Get-VMSwitchExtensionSwitchFeature"
[msdocs:Get-VMSwitchTeam]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSwitchTeam "Get-VMSwitchTeam"
[msdocs:Get-VMSystemSwitchExtension]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSystemSwitchExtension "Get-VMSystemSwitchExtension"
[msdocs:Get-VMSystemSwitchExtensionPortFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSystemSwitchExtensionPortFeature "Get-VMSystemSwitchExtensionPortFeature"
[msdocs:Get-VMSystemSwitchExtensionSwitchFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMSystemSwitchExtensionSwitchFeature "Get-VMSystemSwitchExtensionSwitchFeature"
[msdocs:Get-VMVideo]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Get-VMVideo "Get-VMVideo"
[msdocs:Grant-VMConnectAccess]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Grant-VMConnectAccess "Grant-VMConnectAccess"
[msdocs:Import-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Import-VM "Import-VM"
[msdocs:Import-VMInitialReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Import-VMInitialReplication "Import-VMInitialReplication"
[msdocs:Measure-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Measure-VM "Measure-VM"
[msdocs:Measure-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Measure-VMReplication "Measure-VMReplication"
[msdocs:Measure-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Measure-VMResourcePool "Measure-VMResourcePool"
[msdocs:Move-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Move-VM "Move-VM"
[msdocs:Move-VMStorage]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Move-VMStorage "Move-VMStorage"
[msdocs:New-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VM "New-VM"
[msdocs:New-VMGroup]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VMGroup "New-VMGroup"
[msdocs:New-VMReplicationAuthorizationEntry]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VMReplicationAuthorizationEntry "New-VMReplicationAuthorizationEntry"
[msdocs:New-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VMResourcePool "New-VMResourcePool"
[msdocs:New-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VMSan "New-VMSan"
[msdocs:New-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/New-VMSwitch "New-VMSwitch"
[msdocs:Optimize-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Optimize-VM "Optimize-VM"
[msdocs:Remove-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VM "Remove-VM"
[msdocs:Remove-VMDvdDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMDvdDrive "Remove-VMDvdDrive"
[msdocs:Remove-VMFibreChannelHba]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMFibreChannelHba "Remove-VMFibreChannelHba"
[msdocs:Remove-VMGroup]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMGroup "Remove-VMGroup"
[msdocs:Remove-VMGroupMember]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMGroupMember "Remove-VMGroupMember"
[msdocs:Remove-VMHardDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMHardDiskDrive "Remove-VMHardDiskDrive"
[msdocs:Remove-VMMigrationNetwork]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMMigrationNetwork "Remove-VMMigrationNetwork"
[msdocs:Remove-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMNetworkAdapter "Remove-VMNetworkAdapter"
[msdocs:Remove-VMNetworkAdapterAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMNetworkAdapterAcl "Remove-VMNetworkAdapterAcl"
[msdocs:Remove-VMNetworkAdapterExtendedAcl]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMNetworkAdapterExtendedAcl "Remove-VMNetworkAdapterExtendedAcl"
[msdocs:Remove-VMNetworkAdapterRoutingDomainMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMNetworkAdapterRoutingDomainMapping "Remove-VMNetworkAdapterRoutingDomainMapping"
[msdocs:Remove-VMNetworkAdapterTeamMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMNetworkAdapterTeamMapping "Remove-VMNetworkAdapterTeamMapping"
[msdocs:Remove-VMRemoteFx3dVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMRemoteFx3dVideoAdapter "Remove-VMRemoteFx3dVideoAdapter"
[msdocs:Remove-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMReplication "Remove-VMReplication"
[msdocs:Remove-VMReplicationAuthorizationEntry]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMReplicationAuthorizationEntry "Remove-VMReplicationAuthorizationEntry"
[msdocs:Remove-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMResourcePool "Remove-VMResourcePool"
[msdocs:Remove-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSan "Remove-VMSan"
[msdocs:Remove-VMSavedState]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSavedState "Remove-VMSavedState"
[msdocs:Remove-VMScsiController]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMScsiController "Remove-VMScsiController"
[msdocs:Remove-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSnapshot "Remove-VMSnapshot"
[msdocs:Remove-VMStoragePath]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMStoragePath "Remove-VMStoragePath"
[msdocs:Remove-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSwitch "Remove-VMSwitch"
[msdocs:Remove-VMSwitchExtensionPortFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSwitchExtensionPortFeature "Remove-VMSwitchExtensionPortFeature"
[msdocs:Remove-VMSwitchExtensionSwitchFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSwitchExtensionSwitchFeature "Remove-VMSwitchExtensionSwitchFeature"
[msdocs:Remove-VMSwitchTeamMember]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Remove-VMSwitchTeamMember "Remove-VMSwitchTeamMember"
[msdocs:Rename-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VM "Rename-VM"
[msdocs:Rename-VMGroup]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMGroup "Rename-VMGroup"
[msdocs:Rename-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMNetworkAdapter "Rename-VMNetworkAdapter"
[msdocs:Rename-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMResourcePool "Rename-VMResourcePool"
[msdocs:Rename-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMSan "Rename-VMSan"
[msdocs:Rename-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMSnapshot "Rename-VMSnapshot"
[msdocs:Rename-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Rename-VMSwitch "Rename-VMSwitch"
[msdocs:Repair-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Repair-VM "Repair-VM"
[msdocs:Reset-VMReplicationStatistics]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Reset-VMReplicationStatistics "Reset-VMReplicationStatistics"
[msdocs:Reset-VMResourceMetering]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Reset-VMResourceMetering "Reset-VMResourceMetering"
[msdocs:Restart-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Restart-VM "Restart-VM"
[msdocs:Restore-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Restore-VMSnapshot "Restore-VMSnapshot"
[msdocs:Resume-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Resume-VM "Resume-VM"
[msdocs:Resume-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Resume-VMReplication "Resume-VMReplication"
[msdocs:Revoke-VMConnectAccess]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Revoke-VMConnectAccess "Revoke-VMConnectAccess"
[msdocs:Save-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Save-VM "Save-VM"
[msdocs:Set-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VM "Set-VM"
[msdocs:Set-VMBios]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMBios "Set-VMBios"
[msdocs:Set-VMComPort]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMComPort "Set-VMComPort"
[msdocs:Set-VMDvdDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMDvdDrive "Set-VMDvdDrive"
[msdocs:Set-VMFibreChannelHba]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMFibreChannelHba "Set-VMFibreChannelHba"
[msdocs:Set-VMFirmware]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMFirmware "Set-VMFirmware"
[msdocs:Set-VMFloppyDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMFloppyDiskDrive "Set-VMFloppyDiskDrive"
[msdocs:Set-VMHardDiskDrive]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMHardDiskDrive "Set-VMHardDiskDrive"
[msdocs:Set-VMHost]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMHost "Set-VMHost"
[msdocs:Set-VMHostCluster]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMHostCluster "Set-VMHostCluster"
[msdocs:Set-VMKeyProtector]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMKeyProtector "Set-VMKeyProtector"
[msdocs:Set-VMMemory]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMMemory "Set-VMMemory"
[msdocs:Set-VMMigrationNetwork]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMMigrationNetwork "Set-VMMigrationNetwork"
[msdocs:Set-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMNetworkAdapter "Set-VMNetworkAdapter"
[msdocs:Set-VMNetworkAdapterFailoverConfiguration]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMNetworkAdapterFailoverConfiguration "Set-VMNetworkAdapterFailoverConfiguration"
[msdocs:Set-VmNetworkAdapterIsolation]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VmNetworkAdapterIsolation "Set-VmNetworkAdapterIsolation"
[msdocs:Set-VmNetworkAdapterRoutingDomainMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VmNetworkAdapterRoutingDomainMapping "Set-VmNetworkAdapterRoutingDomainMapping"
[msdocs:Set-VMNetworkAdapterTeamMapping]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMNetworkAdapterTeamMapping "Set-VMNetworkAdapterTeamMapping"
[msdocs:Set-VMNetworkAdapterVlan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMNetworkAdapterVlan "Set-VMNetworkAdapterVlan"
[msdocs:Set-VMProcessor]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMProcessor "Set-VMProcessor"
[msdocs:Set-VMRemoteFx3dVideoAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMRemoteFx3dVideoAdapter "Set-VMRemoteFx3dVideoAdapter"
[msdocs:Set-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMReplication "Set-VMReplication"
[msdocs:Set-VMReplicationAuthorizationEntry]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMReplicationAuthorizationEntry "Set-VMReplicationAuthorizationEntry"
[msdocs:Set-VmReplicationServer]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VmReplicationServer "Set-VmReplicationServer"
[msdocs:Set-VMResourcePool]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMResourcePool "Set-VMResourcePool"
[msdocs:Set-VMSan]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSan "Set-VMSan"
[msdocs:Set-VMSecurity]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSecurity "Set-VMSecurity"
[msdocs:Set-VMSecurityPolicy]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSecurityPolicy "Set-VMSecurityPolicy"
[msdocs:Set-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSwitch "Set-VMSwitch"
[msdocs:Set-VMSwitchExtensionPortFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSwitchExtensionPortFeature "Set-VMSwitchExtensionPortFeature"
[msdocs:Set-VMSwitchExtensionSwitchFeature]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSwitchExtensionSwitchFeature "Set-VMSwitchExtensionSwitchFeature"
[msdocs:Set-VMSwitchTeam]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMSwitchTeam "Set-VMSwitchTeam"
[msdocs:Set-VMVideo]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Set-VMVideo "Set-VMVideo"
[msdocs:Start-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Start-VM "Start-VM"
[msdocs:Start-VMFailover]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Start-VMFailover "Start-VMFailover"
[msdocs:Start-VMInitialReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Start-VMInitialReplication "Start-VMInitialReplication"
[msdocs:Start-VMTrace]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Start-VMTrace "Start-VMTrace"
[msdocs:Stop-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Stop-VM "Stop-VM"
[msdocs:Stop-VMFailover]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Stop-VMFailover "Stop-VMFailover"
[msdocs:Stop-VMInitialReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Stop-VMInitialReplication "Stop-VMInitialReplication"
[msdocs:Stop-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Stop-VMReplication "Stop-VMReplication"
[msdocs:Stop-VMTrace]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Stop-VMTrace "Stop-VMTrace"
[msdocs:Suspend-VM]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Suspend-VM "Suspend-VM"
[msdocs:Suspend-VMReplication]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Suspend-VMReplication "Suspend-VMReplication"
[msdocs:Test-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Test-VMNetworkAdapter "Test-VMNetworkAdapter"
[msdocs:Test-VMReplicationConnection]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Test-VMReplicationConnection "Test-VMReplicationConnection"
[msdocs:Update-VMVersion]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Update-VMVersion "Update-VMVersion"


Install Hyper-V Powershell module <sup>[Zacker][Zacker]: 90</sup>
```powershell
Install-WindowsFeature -Name hyper-v-powershell
```

##### `VHD`
###### `Mount-VHD`
Tasks:
- [VHDX file](#vhdx-file)

Mount a VHD or VHDX file <sup>[Zacker][Zacker]: 92</sup>
```powershell
Mount-VHD -Path $file
```
###### `New-VHD`
Tasks:
- [VHDX file](#vhdx-file)
##### `VM`

###### `Compare-VM`[^][msdocs:Compare-VM]
###### `Export-VM`[^][msdocs:Export-VM]
Export a VM <sup>[Zacker][Zacker]: 373</sup>
```powershell
Export-Vm -Name clustervm1 -Path D:\vm
```
###### `Get-VM`[^][msdocs:Get-VM]
###### `Import-VM`[^][msdocs:Import-VM]
[Import-VM -Copy]: #import-vm '```&#10;PS C:\> Import-VM -Copy&#10;```&#10;Specifies that the import VM should be copied to host default locations of the host, as opposed to registering the virtual machine in-place.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 211'
[Import-VM -GenerateNewId]: #import-vm '```&#10;PS C:\> Import-VM -GenerateNewId&#10;```&#10;Specifies that the imported virtual machine should be copied and given a new unique identifier.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'

[`Copy`][Import-VM -Copy]
[`GenerateNewId`][Import-VM -GenerateNewId]

Import a VM into the Hyper-V host <sup>[Zacker][Zacker]: 373</sup>
```powershell
Import-VM -Path "D:\vm\virtual machines\5ae40946-3a98-428e-8c83-081a3c68d18c.xml" -Copy -GenerateNewId
```
###### `Measure-VM`[^][msdocs:Measure-VM]
###### `Move-VM`[^][msdocs:Move-VM]
Perform a live migraiton <sup>[Zacker][Zacker]: 307</sup>
```powershell
Move-VM -VM server1 -DestinationHost hyper2
```
###### `New-VM`[^][msdocs:New-VM]
[New-VM -Generation]: #new-vm '```&#10;PS C:\> New-VM -Generation&#10;```&#10;Specify generation of VM (1 or 2)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 197'

[`Generation`][New-VM -Generation]

Create a Nano Server VM from an image file <sup>[Zacker][Zacker]: 47</sup>
```powershell
New-VM -Name "nano2" -Generation 2 -MemoryStartupBytes 1GB -VHDPath "F:\hyper-v\virtual hard disks\nano2.vhdx"
```
###### `Remove-VM`[^][msdocs:Remove-VM]
###### `Rename-VM`[^][msdocs:Rename-VM]
###### `Restart-VM`[^][msdocs:Restart-VM]
###### `Resume-VM`[^][msdocs:Resume-VM]
###### `Save-VM`[^][msdocs:Save-VM]
###### `Set-VM`[^][msdocs:Set-VM]
###### `Start-VM`[^][msdocs:Start-VM]
###### `Stop-VM`[^][msdocs:Stop-VM]
###### `Suspend-VM`[^][msdocs:Suspend-VM]
##### `VMHost`
###### `Set-VMHost`
[Set-VMHost -VirtualMachinePath]: #Set-VMHost '```&#10;PS C:\> Set-VMHost -VirtualMachinePath&#10;```&#10;Specify the default folder to store virtual machine configuration files on the Hyper-V host'
[Set-VMHost -VirtualHardDiskPath]: #Set-VMHost '```&#10;PS C:\> Set-VMHost -VirtualHardDiskPath&#10;```&#10;Specify the default folder to store virtual hard disks on the Hyper-V host.'

[`VirtualHardDiskPath`][Set-VMHost -VirtualHardDiskPath]
[`VirtualMachinePath`][Set-VMHost -VirtualMachinePath]

```powershell
Set-VMHost -VirtualHardDiskPath 'D:\vms\Virtual Hard Disks' -VirtualMachinePath 'D:\vms\Virtual Machines'
```
###### `Set-VMFirmware`[^][msdocs:Set-VMFirmware]
[Set-VMFirmware -SecureBootTemplate]: #set-vmfirmware '```&#10;PS C:\> Set-VMFirmware -SecureBootTemplate&#10;```&#10;Specifies the name of the secure boot template. If secure boot is enabled, you must have a valid secure boot template for the guest operating system to start.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 208'

[`SecureBootTemplate`][Set-VMFirmware -SecureBootTemplate]

Select Secure Boot template in order to load supported Linux distributions <sup>[IMWS][IMWS]; [Zacker][Zacker]: 208</sup>
```powershell
Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority
```
###### `Set-VMMemory`
Tasks:
- [Implement nested virtualization](#implement-nested-virtualization)

###### `Set-VMProcessor`
- [Implement nested virtualization](#implement-nested-virtualization)
##### `VMReplicationServer`
###### `Set-VMReplicationServer`
Configure a server's replica configuration <sup>[Zacker][Zacker]: 300</sup>
```powershell
Set-VmReplicationServer -ReplicationEnabled $true -AllowedAuthenticationType kerberos -ReplicationAllowedFromAnyServer $true -DefaultStorageLocation D:\replicas
```
##### `VMSwitch`
[msdocs:Set-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/set-vmswitch "Set-VMSwitch"
[msdocs:New-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/new-vmswitch "New-VMSwitch"
[msdocs:Get-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/get-vmswitch "Get-VMSwitch"
[msdocs:Add-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/add-vmswitch "Add-VMSwitch"
[msdocs:Remove-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/remove-vmswitch "Remove-VMSwitch"
[msdocs:Rename-VMSwitch]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/rename-vmswitch "Rename-VMSwitch"

[external virtual switch]: # 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[internal virtual switch]: # 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[private virtual switch]: # 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'

Virtual switches can be [external][external virtual switch], [internal][internal virtual switch], or [private][private virtual switch] (in order of decreasing access). <sup>[Zacker][Zacker]: 241</sup>

###### `Add-VMSwitch`[^][msdocs:Add-VMSwitch]
###### `Get-VMSwitch`[^][msdocs:Get-VMSwitch]
###### `New-VMSwitch`[^][msdocs:New-VMSwitch]
[New-VMSwitch -AllowManagementOS]: #New-VMSwitch '```&#10;PS C:\> New-VMSwitch -AllowManagementOS&#10;```&#10;Specify whether host can access the physical network adapter to which the virtual switch is bound'
[New-VMSwitch -EnableEmbeddedTeaming]: #New-VMSwitch '```&#10;PS C:\> New-VMSwitch -EnableEmbeddedTeaming&#10;```&#10;Enable teaming for the specified virtual switch'

[`AllowManagementOS`][New-VMSwitch -AllowManagementOS]
[`EnableEmbeddedTeaming`][New-VMSwitch -EnableEmbeddedTeaming]

Tasks:
- [Create a virtual switch with SET enabled](#create-a-virtual-switch-with-set-enabled)

Create a new virtual switch <sup>[Zacker][Zacker]: 242</sup>
```powershell
New-VMSwitch -Name lan1 -NetAdapterName "Ethernet 2"
New-VMSwitch -Name private1 -SwitchType private
```
Turn on NAT on a nested Hyper-V VM
```powershell
New-VMSwitch -name VMNAT -SwitchType Internal
New-NetNAT -Name LocalNAT -InternalIPInterfaceAddressPrefix "192.168.100.0/24"
```
###### `Remove-VMSwitch`[^][msdocs:Remove-VMSwitch]
###### `Rename-VMSwitch`[^][msdocs:Rename-VMSwitch]
###### `Set-VMSwitch`[^][msdocs:Set-VMSwitch]
[Set-VMSwitch -AllowManagementOS]: #Set-VMSwitch '```&#10;PS C:\> Set-VMSwitch -AllowManagementOS&#10;```&#10;Specify whether host can access the physical network adapter to which the virtual switch is bound'

[`AllowManagementOS`][Set-VMSwitch -AllowManagementOS]

##### `VMNetworkAdapter`
###### `Add-VMNetworkAdapter`[^][msdocs:Add-VMNetworkAdapter]
[Add-VMNetworkAdapter -IsLegacy]: #add-vmnetworkadapter '```&#10;PS C:\> Add-VMNetworkAdapter -IsLegacy&#10;```&#10;Specify a legacy adapter'

[`IsLegacy`][Add-VMNetworkAdapter -IsLegacy]

Create a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Add-VMNetworkAdapter -VMName server1 -SwitchName private1
```
###### `Remove-VMNetworkAdapter`[^][msdocs:Remove-VMNetworkAdapter]
[msdocs:Remove-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/remove-vmnetworkadapter "Remove-VMNetworkAdapter"

Remove a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Remove-VMNetworkAdapter -VMName server1 -VMNetworkAdapter nic1
```
###### `Set-VMNetworkAdapter`[^][msdocs:Set-VMNetworkAdapter]
[msdocs:Set-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/set-vmnetworkadapter "Set-VMNetworkAdapter"

[Set-VMNetworkAdapter -MinimumBandwidthWeight]: #Set-VMNetworkAdapter '```&#10;PS C:\> Set-VMNetworkAdapter -MinimumBandwidthWeight&#10;```&#10;Specify how much bandwidth to allocate to the specified virtual network adapter relative to others on the same switch (value ranges 1-100)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 256'
[Set-VMNetworkAdapter -MinimumBandwidthAbsolute]: #Set-VMNetworkAdapter '```&#10;PS C:\> Set-VMNetworkAdapter -MinimumBandwidthAbsolute&#10;```&#10;Specify the minimum bandwidth allocated to an adapter, ensuring it is not denied access when others contend for bandwidth.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 255'
[Set-VMNetworkAdapter -MaximumBandwidth]: #Set-VMNetworkAdapter '```&#10;PS C:\> Set-VMNetworkAdapter -MaximumBandwidth&#10;```&#10;Specify the maximum bandwidth available to an adapter; must not exceed the actual bandwidth provided by the physical network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 255'

`MACAddressSpoofing`
[`MaximumBandwidth`][Set-VMNetworkAdapter -MaximumBandwidth]
[`MinimumBandwidthAbsolute`][Set-VMNetworkAdapter -MinimumBandwidthAbsolute]
[`MinimumBandwidthWeight`][Set-VMNetworkAdapter -MinimumBandwidthWeight]

Tasks:
- [Implement nested virtualization](#implement-nested-virtualization)

Set bandwidth limits on a virtual network adapter <sup>[Zacker][Zacker]: 256</sup>
```powershell
Set-VMNetworkAdapter -VMName server1 -Name nic1 -MinimumBandwidthWeight
```
#### System administration
##### `LocalGroupMember`
###### `Add-LocalGroupMember`
###### `Get-LocalGroupMember`
###### `Remove-LocalGroupMember`
##### `LocalUser`
###### `Get-LocalUser`
###### `New-LocalUser`
###### `Remove-LocalUser`
###### `Disable-LocalUser`
###### `Enable-LocalUser`
###### `Rename-LocalUser`
###### `Set-LocalUser`
#### Windows objects
##### `Guid`
###### `New-Guid`
Generate a GUID
```powershell
New-Guid
(New-Guid).Guid | clip
```
##### `NanoServerImage`
[msdocs:Edit-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/nanoserverimagegenerator/Edit-nanoserverimage "Edit-NanoServerImage"
[msdocs:New-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/nanoserverimagegenerator/new-nanoserverimage "New-NanoServerImage"


Options for configuring a network adapter

`InterfaceNameOrIndex`
`Ipv4Address`

###### `Edit-NanoServerImage`[^][Edit-NanoServerImage]

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
###### `New-NanoServerImage`[^][msdocs:New-NanoServerImage]

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
##### `Service`
###### `Get-Service`
Display status of &lt;WinRM&gt; service
```powershell
Get-Service WinRM
gsv winrm
```
###### `Set-Service`
```powershell
Set-Service WtcOtg -StartupType Disabled
```
###### `Start-Service`
Start the `WinRM` service
```powershell
sasv winrm
```
###### `Stop-Service`
Stop the WebTitan service
```powershell
Stop-Service WtcOtg
```
##### `WmiObject`
###### `Get-WmiObject`
View system uptime
```powershell
Get-WmiObject -Win32_OperatingSystem -ComputerName localhost |
Select-Object -Property @{n="Last Boot Time";e={[Management.ManagementDateTimeConvert]::ToDateTime($_.LastBootUpTime)}}
```
Display Windows activation key <sup>[thewindowsclub.com][https://www.thewindowsclub.com/find-windows-product-key]</sup>
```powershell
(Get-WmiObject -query ‘select * from SoftwareLicensingService’).OA3xOriginalProductKey
```
Get Wireless network adapter
```powershell
Get-WmiObject -Class Win32_NetworkAdapter | Where-Object {$_.Name -like "*Wireless*"}
```
Display all objects of type `Win32_LogicalDisk` <sup>[YouTube](https://youtu.be/Qy0c_9peoac "Windows PowerShell Fundamentals Chapter 07 - WMI and PowerShell") [cmd](README.md '```&#10;C:\>wmic logicaldisk list brief&#10;```')</sup>
```powershell
Get-WmiObject -Query "SELECT * FROM Win32_LogicalDisk"
gwmi -q "select * from win32_logicaldisk"
```


##### `WindowsFeature`
###### `Get-WindowsFeature`
Display installable Windows roles, role services, and features
Display a branching view of available Windows roles, role services, and features
```powershell
Get-WindowsFeature
```
###### `Install-WindowsFeature`
[Install-WindowsFeature -Name]: #Install-WindowsFeature '```&#10;PS C:\> Install-WindowsFeature -Name&#10;```&#10;&#10;Values can include:&#10;  - "`AD-Domain-Services"&#10;  - "Hyper-V"&#10;  - "RSAT-ADDS"&#10;  - "Web-WebServer"'

[**`Name`**][Install-WindowsFeature -Name] 
`IncludeAllSubFeature` 
`IncludeManamgentTools`
`Restart`

Install a feature <sup>[Zacker][Zacker]: 15</sup>
```powershell
Install-WindowsFeature -Name $featurename -IncludeAllSubFeature -IncludeManagementTools
```
Install Remote Server Adminstration Tools for PowerShell
```powershell
Install-WindowsFeature -Name rsat-adds -IncludeAllSubFeature
```
Install Hyper-V
```powershell
Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart
```
Install Web Server <sup>[Jones][Jones]</sup>
```powershell
Install-WindowsFeature web-webserver -IncludeManagementTools
Install-WindowsFeature Web-Server,Web-Common-Http,Web-Mgmt-Console -Restart
```
Create a domain controller
```powershell
Install-WindowsFeature AD-Domain-Services -IncludeManagementTools
```
Create a DHCP server <sup>[Jones][Jones]</sup>
```powershell
Install-WindowsFeature DHCP -IncludeManagementTools
```
Install Windows Server Migration Tools <sup>[Zacker][Zacker]: 33</sup>
```powershell
Install-WindowsFeature Migration
```
#### Windows Server
<!-- dism -->
[msdocs:Set-AppxProvisionedDataFile]: https://docs.microsoft.com/en-us/powershell/module/dism/Set-AppxProvisionedDataFile "Set-AppxProvisionedDataFile"
[msdocs:Add-AppxProvisionedPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Add-AppxProvisionedPackage "Add-AppxProvisionedPackage"
[msdocs:Get-AppxProvisionedPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-AppxProvisionedPackage "Get-AppxProvisionedPackage"
[msdocs:Remove-AppxProvisionedPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Remove-AppxProvisionedPackage "Remove-AppxProvisionedPackage"
[msdocs:Get-WIMBootEntry]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WIMBootEntry "Get-WIMBootEntry"
[msdocs:Update-WIMBootEntry]: https://docs.microsoft.com/en-us/powershell/module/dism/Update-WIMBootEntry "Update-WIMBootEntry"
[msdocs:Add-WindowsCapability]: https://docs.microsoft.com/en-us/powershell/module/dism/Add-WindowsCapability "Add-WindowsCapability"
[msdocs:Get-WindowsCapability]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsCapability "Get-WindowsCapability"
[msdocs:Remove-WindowsCapability]: https://docs.microsoft.com/en-us/powershell/module/dism/Remove-WindowsCapability "Remove-WindowsCapability"
[msdocs:Clear-WindowsCorruptMountPoint]: https://docs.microsoft.com/en-us/powershell/module/dism/Clear-WindowsCorruptMountPoint "Clear-WindowsCorruptMountPoint"
[msdocs:Expand-WindowsCustomDataImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Expand-WindowsCustomDataImage "Expand-WindowsCustomDataImage"
[msdocs:New-WindowsCustomImage]: https://docs.microsoft.com/en-us/powershell/module/dism/New-WindowsCustomImage "New-WindowsCustomImage"
[msdocs:Add-WindowsDriver]: https://docs.microsoft.com/en-us/powershell/module/dism/Add-WindowsDriver "Add-WindowsDriver"
[msdocs:Export-WindowsDriver]: https://docs.microsoft.com/en-us/powershell/module/dism/Export-WindowsDriver "Export-WindowsDriver"
[msdocs:Get-WindowsDriver]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsDriver "Get-WindowsDriver"
[msdocs:Remove-WindowsDriver]: https://docs.microsoft.com/en-us/powershell/module/dism/Remove-WindowsDriver "Remove-WindowsDriver"
[msdocs:Get-WindowsEdition]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsEdition "Get-WindowsEdition"
[msdocs:Set-WindowsEdition]: https://docs.microsoft.com/en-us/powershell/module/dism/Set-WindowsEdition "Set-WindowsEdition"
[msdocs:Add-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Add-WindowsImage "Add-WindowsImage"
[msdocs:Dismount-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Dismount-WindowsImage "Dismount-WindowsImage"
[msdocs:Expand-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Expand-WindowsImage "Expand-WindowsImage"
[msdocs:Export-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Export-WindowsImage "Export-WindowsImage"
[msdocs:Get-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsImage "Get-WindowsImage"
[msdocs:Mount-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Mount-WindowsImage "Mount-WindowsImage"
[msdocs:New-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/New-WindowsImage "New-WindowsImage"
[msdocs:Remove-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Remove-WindowsImage "Remove-WindowsImage"
[msdocs:Save-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Save-WindowsImage "Save-WindowsImage"
[msdocs:Optimize-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Optimize-WindowsImage "Optimize-WindowsImage"
[msdocs:Repair-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Repair-WindowsImage "Repair-WindowsImage"
[msdocs:Split-WindowsImage]: https://docs.microsoft.com/en-us/powershell/module/dism/Split-WindowsImage "Split-WindowsImage"
[msdocs:Get-WindowsImageContent]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsImageContent "Get-WindowsImageContent"
[msdocs:Disable-WindowsOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/dism/Disable-WindowsOptionalFeature "Disable-WindowsOptionalFeature"
[msdocs:Enable-WindowsOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/dism/Enable-WindowsOptionalFeature "Enable-WindowsOptionalFeature"
[msdocs:Get-WindowsOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsOptionalFeature "Get-WindowsOptionalFeature"
[msdocs:Add-WindowsPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Add-WindowsPackage "Add-WindowsPackage"
[msdocs:Get-WindowsPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsPackage "Get-WindowsPackage"
[msdocs:Remove-WindowsPackage]: https://docs.microsoft.com/en-us/powershell/module/dism/Remove-WindowsPackage "Remove-WindowsPackage"
[msdocs:Set-WindowsProductKey]: https://docs.microsoft.com/en-us/powershell/module/dism/Set-WindowsProductKey "Set-WindowsProductKey"
[msdocs:Get-WindowsReservedStorageState]: https://docs.microsoft.com/en-us/powershell/module/dism/Get-WindowsReservedStorageState "Get-WindowsReservedStorageState"
[msdocs:Set-WindowsReservedStorageState]: https://docs.microsoft.com/en-us/powershell/module/dism/Set-WindowsReservedStorageState "Set-WindowsReservedStorageState"
[msdocs:Use-WindowsUnattend]: https://docs.microsoft.com/en-us/powershell/module/dism/Use-WindowsUnattend "Use-WindowsUnattend"

##### `Appx`
###### `Set-AppxProvisionedDataFile`[^][msdocs:Set-AppxProvisionedDataFile]
###### `Add-AppxProvisionedPackage`[^][msdocs:Add-AppxProvisionedPackage]
###### `Get-AppxProvisionedPackage`[^][msdocs:Get-AppxProvisionedPackage]
###### `Remove-AppxProvisionedPackage`[^][msdocs:Remove-AppxProvisionedPackage]
##### `DscConfiguration`
###### `Get-DscConfiguration`[^][msdocs:Get-DscConfiguration]"
###### `Publish-DscConfiguration`[^][msdocs:Publish-DscConfiguration]
###### `Restore-DscConfiguration`[^][msdocs:Restore-DscConfiguration]
###### `Start-DscConfiguration`[^][msdocs:Start-DscConfiguration]
Used to erect a **push architecture** in [DSC](dsc.md). <sup>[Zacker][Zacker]: 27</sup>

Option  | Description
---     | ---
`-Path`
###### `Stop-DscConfiguration`[^][msdocs:Stop-DscConfiguration]
###### `Test-DscConfiguration`[^][msdocs:Test-DscConfiguration]
###### `Update-DscConfiguration`[^][msdocs:Update-DscConfiguration]
##### `DscConfigurationDocument`
###### `Remove-DscConfigurationDocument`[^][msdocs:Remove-DscConfigurationDocument]
##### `DscConfigurationStatus`
###### `Get-DscConfigurationStatus`[^][msdocs:Get-DscConfigurationStatus]
##### `DscDebug`
###### `Disable-DscDebug`[^][msdocs:Disable-DscDebug]
###### `Enable-DscDebug`[^][msdocs:Enable-DscDebug]
##### `DscLocalConfigurationManager`
###### `Get-DscLocalConfigurationManager`[^][msdocs:Get-DscLocalConfigurationManager]
###### `Set-DscLocalConfigurationManager`[^][msdocs:Set-DscLocalConfigurationManager]
##### `DscResource`
###### `Get-DscResource`[^][msdocs:Get-DscResource]
###### `Invoke-DscResource`[^][msdocs:Invoke-DscResource]

##### `WIM`
###### `Get-WIMBootEntry`[^][msdocs:Get-WIMBootEntry]
###### `Update-WIMBootEntry`[^][msdocs:Update-WIMBootEntry]
##### `WindowsC`
###### `Add-WindowsCapability`[^][msdocs:Add-WindowsCapability]
###### `Get-WindowsCapability`[^][msdocs:Get-WindowsCapability]
###### `Remove-WindowsCapability`[^][msdocs:Remove-WindowsCapability]
###### `Clear-WindowsCorruptMountPoint`[^][msdocs:Clear-WindowsCorruptMountPoint]
###### `Expand-WindowsCustomDataImage`[^][msdocs:Expand-WindowsCustomDataImage]
###### `New-WindowsCustomImage`[^][msdocs:New-WindowsCustomImage]
##### `WindowsDriver`
###### `Add-WindowsDriver`[^][msdocs:Add-WindowsDriver]
DISM only supports .inf driver files
###### `Export-WindowsDriver`[^][msdocs:Export-WindowsDriver]
###### `Get-WindowsDriver`[^][msdocs:Get-WindowsDriver]
###### `Remove-WindowsDriver`[^][msdocs:Remove-WindowsDriver]
##### `WindowsEdition`
###### `Get-WindowsEdition`[^][msdocs:Get-WindowsEdition]
###### `Set-WindowsEdition`[^][msdocs:Set-WindowsEdition]

##### `WindowsImage`
###### `Add-WindowsImage`[^][msdocs:Add-WindowsImage]
###### `Dismount-WindowsImage`[^][msdocs:Dismount-WindowsImage]
###### `Expand-WindowsImage`[^][msdocs:Expand-WindowsImage]
###### `Export-WindowsImage`[^][msdocs:Export-WindowsImage]
###### `Get-WindowsImage`[^][msdocs:Get-WindowsImage]
[Get-WindowsImage -Mounted]: #Get-WindowsImage '```&#10;PS C:\> Get-WindowsImage -Mounted&#10;```&#10;&#10;Equivalent to `Dism.exe /Get-MountedImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsImage -ImagePath]: #get-windowsimage '```&#10;PS C:\> Get-WindowsImage -ImagePath&#10;```&#10;Specifies the location of a WIM or VHD file'
[Get-WindowsImage -Index]: #get-windowsimage '```&#10;PS C:\> Get-WindowsImage -Index&#10;```&#10;Specifies the index number of a Windows image in a WIM or VHD file. For a VHD file, the Index must be 1.'

[`ImagePath`][Get-WindowsImage -ImagePath]
[`Index`][Get-WindowsImage -Index]
[`Mounted`][Get-WindowsImage -Mounted]

Find Windows Server 2016 images included in G:\images\WS2016.WIM
```powershell
Get-WindowsImage -ImagePath G:\images\WS2016.WIM
```

###### `Mount-WindowsImage`[^][msdocs:Mount-WindowsImage]
[Mount-WindowsImage -Remount]: #Mount-WindowsImage '```&#10;PS C:\> Mount-WindowsImage -Remount&#10;```&#10;&#10;Equivalent to `Dism.exe /Remount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Remount`][Mount-WindowsImage -Remount]
###### `New-WindowsImage`[^][msdocs:New-WindowsImage]
###### `Remove-WindowsImage`[^][msdocs:Remove-WindowsImage]
###### `Save-WindowsImage`[^][msdocs:Save-WindowsImage]
###### `Optimize-WindowsImage`[^][msdocs:Optimize-WindowsImage]
###### `Repair-WindowsImage`[^][msdocs:Repair-WindowsImage]
###### `Split-WindowsImage`[^][msdocs:Split-WindowsImage]
###### `Get-WindowsImageContent`[^][msdocs:Get-WindowsImageContent]

##### `WindowsOptionalFeature`
###### `Disable-WindowsOptionalFeature`[^][msdocs:Disable-WindowsOptionalFeature]
###### `Enable-WindowsOptionalFeature`[^][msdocs:Enable-WindowsOptionalFeature]
Enable a feature in the currently running operating system <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/dism/enable-windowsoptionalfeature?view=win10-ps&redirectedfrom=MSDN "Microsoft Docs: \"Enable-WindowsOptionalFeature\"")</sup>
```powershell
Enable-WindowsOptionalFeature -Online -FeatureName "Hearts" -All
```
Enable WSL <sup>[Reddit](https://www.reddit.com/r/bashonubuntuonwindows/comments/7smf9m/help_wsl_wont_activate_on_my_freshly_installed/ "Reddit: \"[help] WSL won't activate on my freshly installed Windows 10 version 1709\"")</sup>
```powershell
Enable-WindowsOptionalFeature -online -FeatureName Microsoft-Windows-Subsystem-Linux
```
###### `Get-WindowsOptionalFeature`[^][msdocs:Get-WindowsOptionalFeature]
[Get-WindowsOptionalFeature -FeatureName]: #Get-WindowsOptionalFeature '```&#10;PS C:\> Get-WindowsOptionalFeature -FeatureName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Featureinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[`FeatureName`][Get-WindowsOptionalFeature -FeatureName]
##### `WindowsPackage`
###### `Add-WindowsPackage`[^][msdocs:Add-WindowsPackage]
###### `Get-WindowsPackage`[^][msdocs:Get-WindowsPackage]
[Get-WindowsPackage -PackagePath]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackagePath&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsPackage -PackageName]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackageName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[`PackageName`][Get-WindowsPackage -PackageName] 
[`PackagePath`][Get-WindowsPackage -PackagePath]
###### `Remove-WindowsPackage`[^][msdocs:Remove-WindowsPackage]
###### `Set-WindowsProductKey`[^][msdocs:Set-WindowsProductKey]
###### `Get-WindowsReservedStorageState`[^][msdocs:Get-WindowsReservedStorageState]
###### `Set-WindowsReservedStorageState`[^][msdocs:Set-WindowsReservedStorageState]
###### `Use-WindowsUnattend`[^][msdocs:Use-WindowsUnattend]

#### Failover clusters
[msdocs:Add-ClusterCheckpoint]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterCheckpoint "Add-ClusterCheckpoint"
[msdocs:Add-ClusterGenericScriptRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGenericScriptRole "Add-ClusterGenericScriptRole"
[msdocs:Add-ClusterGenericServiceRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGenericServiceRole "Add-ClusterGenericServiceRole"
[msdocs:Add-ClusterGroupSetDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGroupSetDependency "Add-ClusterGroupSetDependency"
[msdocs:Add-ClusterGroupToSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGroupToSet "Add-ClusterGroupToSet"
[msdocs:Add-ClusteriSCSITargetServerRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusteriSCSITargetServerRole "Add-ClusteriSCSITargetServerRole"
[msdocs:Add-ClusterResourceType]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterResourceType "Add-ClusterResourceType"
[msdocs:Add-ClusterScaleOutFileServer]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterScaleOutFileServer "Add-ClusterScaleOutFileServer"
[msdocs:Add-ClusterScaleOutFileServerRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterScaleOutFileServerRole "Add-ClusterScaleOutFileServerRole"
[msdocs:Add-ClusterServerRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterServerRole "Add-ClusterServerRole"
[msdocs:Clear-ClusterDiskReservation]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Clear-ClusterDiskReservation "Clear-ClusterDiskReservation"
[msdocs:Clear-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Clear-ClusterNode "Clear-ClusterNode"
[msdocs:Disable-ClusterStorageSpacesDirect]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Disable-ClusterStorageSpacesDirect "Disable-ClusterStorageSpacesDirect"
[msdocs:Add-ClusterDisk]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterDisk "Add-ClusterDisk"
[msdocs:Add-ClusterFileServerRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterFileServerRole "Add-ClusterFileServerRole"
[msdocs:Add-ClusterGenericApplicationRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGenericApplicationRole "Add-ClusterGenericApplicationRole"
[msdocs:Get-ClusterAvailableDisk]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterAvailableDisk "Get-ClusterAvailableDisk"
[msdocs:Get-ClusterCheckpoint]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterCheckpoint "Get-ClusterCheckpoint"
[msdocs:Get-ClusterDiagnosticInfo]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterDiagnosticInfo "Get-ClusterDiagnosticInfo"
[msdocs:Get-ClusterFaultDomain]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterFaultDomain "Get-ClusterFaultDomain"
[msdocs:Get-ClusterFaultDomainXML]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterFaultDomainXML "Get-ClusterFaultDomainXML"
[msdocs:Get-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterGroup "Get-ClusterGroup"
[msdocs:Get-ClusterGroupSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterGroupSet "Get-ClusterGroupSet"
[msdocs:Get-ClusterGroupSetDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterGroupSetDependency "Get-ClusterGroupSetDependency"
[msdocs:Get-ClusterLog]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterLog "Get-ClusterLog"
[msdocs:Get-ClusterNetwork]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterNetwork "Get-ClusterNetwork"
[msdocs:Get-ClusterNetworkInterface]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterNetworkInterface "Get-ClusterNetworkInterface"
[msdocs:Add-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterGroup "Add-ClusterGroup"
[msdocs:Add-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterNode "Add-ClusterNode"
[msdocs:Get-ClusterOwnerNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterOwnerNode "Get-ClusterOwnerNode"
[msdocs:Get-ClusterParameter]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterParameter "Get-ClusterParameter"
[msdocs:Add-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterResource "Add-ClusterResource"
[msdocs:Add-ClusterResourceDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterResourceDependency "Add-ClusterResourceDependency"
[msdocs:Get-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterResource "Get-ClusterResource"
[msdocs:Get-ClusterResourceDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterResourceDependency "Get-ClusterResourceDependency"
[msdocs:Get-ClusterResourceDependencyReport]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterResourceDependencyReport "Get-ClusterResourceDependencyReport"
[msdocs:Get-ClusterResourceType]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterResourceType "Get-ClusterResourceType"
[msdocs:Get-ClusterSharedVolume]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterSharedVolume "Get-ClusterSharedVolume"
[msdocs:Get-ClusterSharedVolumeState]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterSharedVolumeState "Get-ClusterSharedVolumeState"
[msdocs:Get-ClusterStorageSpacesDirect]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterStorageSpacesDirect "Get-ClusterStorageSpacesDirect"
[msdocs:Get-ClusterVMMonitoredItem]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterVMMonitoredItem "Get-ClusterVMMonitoredItem"
[msdocs:Grant-ClusterAccess]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Grant-ClusterAccess "Grant-ClusterAccess"
[msdocs:Move-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Move-ClusterGroup "Move-ClusterGroup"
[msdocs:Move-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Move-ClusterResource "Move-ClusterResource"
[msdocs:Move-ClusterSharedVolume]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Move-ClusterSharedVolume "Move-ClusterSharedVolume"
[msdocs:Move-ClusterVirtualMachineRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Move-ClusterVirtualMachineRole "Move-ClusterVirtualMachineRole"
[msdocs:Add-ClusterSharedVolume]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterSharedVolume "Add-ClusterSharedVolume"
[msdocs:Add-ClusterVirtualMachineRole]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterVirtualMachineRole "Add-ClusterVirtualMachineRole"
[msdocs:New-ClusterFaultDomain]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/New-ClusterFaultDomain "New-ClusterFaultDomain"
[msdocs:New-ClusterGroupSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/New-ClusterGroupSet "New-ClusterGroupSet"
[msdocs:New-ClusterNameAccount]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/New-ClusterNameAccount "New-ClusterNameAccount"
[msdocs:Add-ClusterVMMonitoredItem]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Add-ClusterVMMonitoredItem "Add-ClusterVMMonitoredItem"
[msdocs:Block-ClusterAccess]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Block-ClusterAccess "Block-ClusterAccess"
[msdocs:Enable-ClusterStorageSpacesDirect]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Enable-ClusterStorageSpacesDirect "Enable-ClusterStorageSpacesDirect"
[msdocs:Get-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-Cluster "Get-Cluster"
[msdocs:Remove-ClusterCheckpoint]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterCheckpoint "Remove-ClusterCheckpoint"
[msdocs:Remove-ClusterFaultDomain]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterFaultDomain "Remove-ClusterFaultDomain"
[msdocs:Remove-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterGroup "Remove-ClusterGroup"
[msdocs:Remove-ClusterGroupFromSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterGroupFromSet "Remove-ClusterGroupFromSet"
[msdocs:Remove-ClusterGroupSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterGroupSet "Remove-ClusterGroupSet"
[msdocs:Remove-ClusterGroupSetDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterGroupSetDependency "Remove-ClusterGroupSetDependency"
[msdocs:Get-ClusterAccess]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterAccess "Get-ClusterAccess"
[msdocs:Get-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterNode "Get-ClusterNode"
[msdocs:Remove-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterResource "Remove-ClusterResource"
[msdocs:Remove-ClusterResourceDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterResourceDependency "Remove-ClusterResourceDependency"
[msdocs:Remove-ClusterResourceType]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterResourceType "Remove-ClusterResourceType"
[msdocs:Remove-ClusterSharedVolume]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterSharedVolume "Remove-ClusterSharedVolume"
[msdocs:Remove-ClusterVMMonitoredItem]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterVMMonitoredItem "Remove-ClusterVMMonitoredItem"
[msdocs:Repair-ClusterStorageSpacesDirect]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Repair-ClusterStorageSpacesDirect "Repair-ClusterStorageSpacesDirect"
[msdocs:Reset-ClusterVMMonitoredState]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Reset-ClusterVMMonitoredState "Reset-ClusterVMMonitoredState"
[msdocs:Resume-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Resume-ClusterNode "Resume-ClusterNode"
[msdocs:Resume-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Resume-ClusterResource "Resume-ClusterResource"
[msdocs:Set-ClusterFaultDomain]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterFaultDomain "Set-ClusterFaultDomain"
[msdocs:Set-ClusterFaultDomainXML]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterFaultDomainXML "Set-ClusterFaultDomainXML"
[msdocs:Set-ClusterGroupSet]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterGroupSet "Set-ClusterGroupSet"
[msdocs:Set-ClusterLog]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterLog "Set-ClusterLog"
[msdocs:Set-ClusterOwnerNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterOwnerNode "Set-ClusterOwnerNode"
[msdocs:Set-ClusterParameter]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterParameter "Set-ClusterParameter"
[msdocs:Set-ClusterQuorum]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterQuorum "Set-ClusterQuorum"
[msdocs:Set-ClusterResourceDependency]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterResourceDependency "Set-ClusterResourceDependency"
[msdocs:Set-ClusterStorageSpacesDirect]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterStorageSpacesDirect "Set-ClusterStorageSpacesDirect"
[msdocs:Set-ClusterStorageSpacesDirectDisk]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Set-ClusterStorageSpacesDirectDisk "Set-ClusterStorageSpacesDirectDisk"
[msdocs:Get-ClusterQuorum]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Get-ClusterQuorum "Get-ClusterQuorum"
[msdocs:New-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/New-Cluster "New-Cluster"
[msdocs:Start-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Start-ClusterGroup "Start-ClusterGroup"
[msdocs:Start-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Start-ClusterNode "Start-ClusterNode"
[msdocs:Start-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Start-ClusterResource "Start-ClusterResource"
[msdocs:Remove-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-Cluster "Remove-Cluster"
[msdocs:Remove-ClusterAccess]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterAccess "Remove-ClusterAccess"
[msdocs:Stop-ClusterGroup]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Stop-ClusterGroup "Stop-ClusterGroup"
[msdocs:Remove-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Remove-ClusterNode "Remove-ClusterNode"
[msdocs:Start-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Start-Cluster "Start-Cluster"
[msdocs:Stop-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Stop-ClusterResource "Stop-ClusterResource"
[msdocs:Stop-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Stop-Cluster "Stop-Cluster"
[msdocs:Stop-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Stop-ClusterNode "Stop-ClusterNode"
[msdocs:Suspend-ClusterResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Suspend-ClusterResource "Suspend-ClusterResource"
[msdocs:Suspend-ClusterNode]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Suspend-ClusterNode "Suspend-ClusterNode"
[msdocs:Test-Cluster]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Test-Cluster "Test-Cluster"
[msdocs:Test-ClusterResourceFailure]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Test-ClusterResourceFailure "Test-ClusterResourceFailure"
[msdocs:Update-ClusterFunctionalLevel]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Update-ClusterFunctionalLevel "Update-ClusterFunctionalLevel"
[msdocs:Update-ClusterIPResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Update-ClusterIPResource "Update-ClusterIPResource"
[msdocs:Update-ClusterNetworkNameResource]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Update-ClusterNetworkNameResource "Update-ClusterNetworkNameResource"
[msdocs:Update-ClusterVirtualMachineConfiguration]: https://docs.microsoft.com/en-us/powershell/module/failoverclusters/Update-ClusterVirtualMachineConfiguration "Update-ClusterVirtualMachineConfiguration"


##### `Cluster`
###### `New-Cluster`[^][msdocs:New-Cluster]
[New-Cluster -NoStorage]: #new-cluster '```&#10;PS C:\> New-Cluster -NoStorage&#10;```&#10;Specifies that shared storage is ignored during the cluster creation. The cluster created at the end of the operation will not have shared storage. Shared storage can later be added by piping the ClusterDiskInfo object from the Get-ClusterAvailableDisk cmdlet into the Add-ClusterDisk cmdlet.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 354'
[New-Cluster -AdministrativeAccessPoint]: #new-cluster '```&#10;PS C:\> New-Cluster -AdministrativeAccessPoint&#10;```&#10;Specifies the type of administrative access point that the cmdlet creates for the cluster (ActiveDirectoryAndDns, Dns, or None)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 337'

[`AdministrativeAccessPoint`][New-Cluster -AdministrativeAccessPoint]
[`NoStorage`][New-Cluster -NoStorage]
`StaticAddress`

Tasks:
- [Create a S2D cluster](#configure-s2d-cluster)

Create a cluster which will be assigned a dynamic address <sup>[Zacker][Zacker]: 313</sup>
```powershell
New-Cluster -Name cluster1 -Node server1,server2
```
Create a cluster which will be assigned a static address <sup>[Zacker][Zacker]: 313</sup>
```powershell
New-Cluster -Name cluster1 -Node server1,server2 -StaticAddress 10.0.0.3
```
Create an Active Directory-detached cluster <sup>[Zacker][Zacker]: 337</sup>
```powershell
New-Cluster -Name cluster1 -Node server1,server2 -StaticAddress 10.0.0.1 -NoStorage -AdministrativeAccessPoint dns
```

##### `ClusterNode`
###### `Suspend-ClusterNode`[^][msdocs:Suspend-ClusterNode]
Pause a node and move ("drain") its workloads with `-Drain`. <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/failoverclusters/suspend-clusternode "Suspend-ClusterNode")
```powershell
Suspend-ClusterNode -Name "node1" -Target "node2" -Drain
```
##### `ClusterQuorum`
###### `Set-ClusterQuorum`[^][msdocs:Set-ClusterQuorum]
`CloudWitness`
`NodeMajority`
`NodeAndDiskMajority`

Configure the quorum to use a node majority, with no witness <sup>[Zacker][Zacker]: 320</sup>
```powershell
Set-ClusterQuorum -Cluster cluster1 -NodeMajority
```
Configure the quorum with votes from each node and a disk witness.
```powershell
Set-ClusterQuorum -Cluster cluster1 -NodeAndDiskMajority "cluster disk 1"
```
No quorum vote
```powershell
(Get-ClusterNode clusternode1).nodeweight=0
```
Configure a cloud witness <sup>[Zacker][Zacker]: 348</sup>
```powershell
Set-ClusterQuorum -CloudWitness -AccountName clusterstorage1 -AccessKey $accesskey
```
##### `ClusterScaleOutFileServer`
###### `Add-ClusterScaleOutFileServer`[^][msdocs:Add-ClusterScaleOutFileServer]
Install the Scale-out File Server role <sup>[Zacker][Zacker]: 339</sup>
```powershell
Add-ClusterScaleOutFileServer
```
##### `ClusterStorageSpacesDirect`
###### `Enable-ClusterStorageSpacesDirect`[^][msdocs:Enable-ClusterStorageSpacesDirect]
Add storage to a failover cluster [created][New-Cluster] with the `-NoStorage` option <sup>[Zacker][Zacker]: 354</sup>
```powershell
Enable-ClusterStorageSpacesDirect
```
#### File shares
[msdocs:Block-SmbShareAccess]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Block-SmbShareAccess "Block-SmbShareAccess"
[msdocs:Close-SmbOpenFile]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Close-SmbOpenFile "Close-SmbOpenFile"
[msdocs:Close-SmbSession]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Close-SmbSession "Close-SmbSession"
[msdocs:Get-SmbClientConfiguration]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbClientConfiguration "Get-SmbClientConfiguration"
[msdocs:Get-SmbOpenFile]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbOpenFile "Get-SmbOpenFile"
[msdocs:Get-SmbServerConfiguration]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbServerConfiguration "Get-SmbServerConfiguration"
[msdocs:Get-SmbSession]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbSession "Get-SmbSession"
[msdocs:Get-SmbShareAccess]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbShareAccess "Get-SmbShareAccess"
[msdocs:Grant-SmbShareAccess]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Grant-SmbShareAccess "Grant-SmbShareAccess"
[msdocs:New-SmbShare]: https://docs.microsoft.com/en-us/powershell/module/smbshare/New-SmbShare "New-SmbShare"
[msdocs:Remove-SmbShare]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Remove-SmbShare "Remove-SmbShare"
[msdocs:Revoke-SmbShareAccess]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Revoke-SmbShareAccess "Revoke-SmbShareAccess"
[msdocs:Set-SmbPathAcl]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Set-SmbPathAcl "Set-SmbPathAcl"
[msdocs:Set-SmbServerConfiguration]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Set-SmbServerConfiguration "Set-SmbServerConfiguration"
[msdocs:Unblock-SmbShareAccess]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Unblock-SmbShareAccess "Unblock-SmbShareAccess"
[msdocs:Disable-SmbDelegation]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Disable-SmbDelegation "Disable-SmbDelegation"
[msdocs:Enable-SmbDelegation]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Enable-SmbDelegation "Enable-SmbDelegation"
[msdocs:Get-SmbBandwidthLimit]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbBandwidthLimit "Get-SmbBandwidthLimit"
[msdocs:Get-SmbClientNetworkInterface]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbClientNetworkInterface "Get-SmbClientNetworkInterface"
[msdocs:Get-SmbConnection]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbConnection "Get-SmbConnection"
[msdocs:Get-SmbDelegation]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbDelegation "Get-SmbDelegation"
[msdocs:Get-SmbMapping]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbMapping "Get-SmbMapping"
[msdocs:Get-SmbMultichannelConnection]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbMultichannelConnection "Get-SmbMultichannelConnection"
[msdocs:Get-SmbMultichannelConstraint]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbMultichannelConstraint "Get-SmbMultichannelConstraint"
[msdocs:Get-SmbServerNetworkInterface]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbServerNetworkInterface "Get-SmbServerNetworkInterface"
[msdocs:Get-SmbShare]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Get-SmbShare "Get-SmbShare"
[msdocs:New-SmbMapping]: https://docs.microsoft.com/en-us/powershell/module/smbshare/New-SmbMapping "New-SmbMapping"
[msdocs:New-SmbMultichannelConstraint]: https://docs.microsoft.com/en-us/powershell/module/smbshare/New-SmbMultichannelConstraint "New-SmbMultichannelConstraint"
[msdocs:Remove-SmbBandwidthLimit]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Remove-SmbBandwidthLimit "Remove-SmbBandwidthLimit"
[msdocs:Remove-SmbMapping]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Remove-SmbMapping "Remove-SmbMapping"
[msdocs:Remove-SmbMultichannelConstraint]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Remove-SmbMultichannelConstraint "Remove-SmbMultichannelConstraint"
[msdocs:Set-SmbBandwidthLimit]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Set-SmbBandwidthLimit "Set-SmbBandwidthLimit"
[msdocs:Set-SmbClientConfiguration]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Set-SmbClientConfiguration "Set-SmbClientConfiguration"
[msdocs:Set-SmbShare]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Set-SmbShare "Set-SmbShare"
[msdocs:Update-SmbMultichannelConnection]: https://docs.microsoft.com/en-us/powershell/module/smbshare/Update-SmbMultichannelConnection "Update-SmbMultichannelConnection"

##### `SmbBandwidthLimit`
###### `Get-SmbBandwidthLimit`[^][msdocs:Get-SmbBandwidthLimit]
###### `Remove-SmbBandwidthLimit`[^][msdocs:Remove-SmbBandwidthLimit]
###### `Set-SmbBandwidthLimit`[^][msdocs:Set-SmbBandwidthLimit]
##### `SmbClientConfiguration`
###### `Get-SmbClientConfiguration`[^][msdocs:Get-SmbClientConfiguration]
###### `Set-SmbClientConfiguration`[^][msdocs:Set-SmbClientConfiguration]
##### `SmbClientNetworkInterface`
###### `Get-SmbClientNetworkInterface`[^][msdocs:Get-SmbClientNetworkInterface]
##### `SmbConnection`
###### `Get-SmbConnection`[^][msdocs:Get-SmbConnection]
##### `SmbDelegation`
###### `Disable-SmbDelegation`[^][msdocs:Disable-SmbDelegation]
###### `Enable-SmbDelegation`[^][msdocs:Enable-SmbDelegation]
###### `Get-SmbDelegation`[^][msdocs:Get-SmbDelegation]
##### `SmbMapping`
###### `Get-SmbMapping`[^][msdocs:Get-SmbMapping]
###### `New-SmbMapping`[^][msdocs:New-SmbMapping]
###### `Remove-SmbMapping`[^][msdocs:Remove-SmbMapping]
##### `SmbMultiChannel`
###### `Get-SmbMultichannelConnection`[^][msdocs:Get-SmbMultichannelConnection]
###### `Update-SmbMultichannelConnection`[^][msdocs:Update-SmbMultichannelConnection]
###### `Get-SmbMultichannelConstraint`[^][msdocs:Get-SmbMultichannelConstraint]
###### `New-SmbMultichannelConstraint`[^][msdocs:New-SmbMultichannelConstraint]
###### `Remove-SmbMultichannelConstraint`[^][msdocs:Remove-SmbMultichannelConstraint]
##### `SmbOpenFile`
###### `Close-SmbOpenFile`[^][msdocs:Close-SmbOpenFile]
Close an open file <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -FileId 4415226383589
```
Close open files for a session <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -SessionId 4415226380393
```
###### `Get-SmbOpenFile`[^][msdocs:Get-SmbOpenFile]
Get information about an opened file <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -FileId 4415226383569 | Select-Object -Property *
```
Get information about a file opened for an SMB client <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -SessionId 4415226380393
```
###### `Set-SmbPathAcl`[^][msdocs:Set-SmbPathAcl]
###### `Get-SmbServerConfiguration`[^][msdocs:Get-SmbServerConfiguration]
###### `Set-SmbServerConfiguration`[^][msdocs:Set-SmbServerConfiguration]
###### `Get-SmbServerNetworkInterface`[^][msdocs:Get-SmbServerNetworkInterface]
##### `SmbSession`
###### `Close-SmbSession`[^][msdocs:Close-SmbSession]
```powershell
Close-SmbSession -SessionId 154618822713
```
###### `Get-SmbSession`[^][msdocs:Get-SmbSession]
##### `SmbShare`
###### `New-SmbShare`[^][msdocs:New-SmbShare]
```powershell
New-SmbShare -Name files -Path C:\networkfiles -ChangeAccess CORP\SysAdmin
```
Create a new share with the `Allow Full Control` permission granted to the `Everyone` special identity <sup>[Zacker][Zacker]: 106</sup>
```powershell
New-SmbShare -Name Data -Path C:\Docs -FullAccess Everyone
```
###### `Remove-SmbShare`[^][msdocs:Remove-SmbShare]
###### `Get-SmbShare`[^][msdocs:Get-SmbShare]
###### `Set-SmbShare`[^][msdocs:Set-SmbShare]
##### `SmbShareAccess`
###### `Block-SmbShareAccess`[^][msdocs:Block-SmbShareAccess]
###### `Get-SmbShareAccess`[^][msdocs:Get-SmbShareAccess]
###### `Grant-SmbShareAccess`[^][msdocs:Grant-SmbShareAccess]
###### `Revoke-SmbShareAccess`[^][msdocs:Revoke-SmbShareAccess]
###### `Unblock-SmbShareAccess`[^][msdocs:Unblock-SmbShareAccess]

## Tasks
#### Computer information
Display computer name <sup>[devblogs.microsoft.com][https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]</sup>
```powershell
Get-ComputerInfo -Property CsName
gin.CsName
$Env:computername
```
#### Generate password
Generate a random password 20 characters long <sup>[adamtheautomator.com][https://adamtheautomator.com/powershell-random-password/]</sup>
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
Fix Windows Search bar <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7]</sup>
```powershell
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search\BingSearchEnabled
Set-Item $$ 0
Set-ItemProperty -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Search -Name CortanaConsent -Value 0
```
Safely combine related registry modifications using [`Start-Transaction`][Start-Transaction] and [`Complete-Transaction`][Complete-Transaction] <sup>[Holmes][Holmes]: 604</sup>
```powershell
Start-Transaction
New-Item TempKey -UseTransaction
Complete-Transaction
```
#### New domain controller
<sup>[Jones][Jones]</sup>
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
Initialize text-to-speech object <sup>[scriptinglibrary.com](https://www.scriptinglibrary.com/languages/powershell/powershell-text-to-speech/ "Powershell: Text To Speech in 3 lines of code")</sup>
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
Set output to WAV file <sup>[thinkpowershell.com](https://thinkpowershell.com/create-cortana-audio-files-from-text-using-powershell/ "Create Cortana Audio Files From Text Using PowerShell")</sup>
```powershell
$WavFileOut = Join-Path -Path $env:USERPROFILE -ChildPath "Desktop\thinkpowershell-demo.wav"
$SpeechSynthesizer.SetOutputToWaveFile($WavFileOut)
```
#### VHDX file
[VHDX]: # 'VHDX&#10;Newer hard disk image format and file name extension.&#10;VHDX image files can be as large as 64 TB, and they also support 4 KB logical sector sizes to provide compatibility with 4 KB native drives. VHDX files can be read only by servers running Windows Server 2012 or later or workstations running Windows 8 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'

Create a new 256 GB dynamic [VHDX][VHDX] file, mount it, initialize it, and create and format the partition <sup>[Zacker][Zacker]: 91</sup>
```powershell
New-VHD -Path C:\Data\disk1.vhdx -SizeBytes 256GB -Dynamic | 
Mount-VHD -Passthru |
Initialize-Disk -PassThru |
New-Partition -DriveLetter X -UseMaximumSize | 
Format-Volume -Filesystem ntfs -FileSystemLabel data1 -Confirm:$False -Force
```
#### Restart Wi-Fi adapter
```powershell
$adaptor = Get-WmiObject -Class Win32_NetworkAdapter | Where-Object {$_.Name -like "*Wireless*"}
$adaptor.Disable()
$adaptor.Enable()
```
#### Add a member to a group
```powershell
Add-ADGroupMember -Identity $group -Members $user1,$user2
```
#### Add a new local admin
```powershell
nlu ansible
Add-LocalGroupMember Administrators ansible
```
#### Configure secure remoting using a self-signed certificate
#### Create a virtual switch with SET enabled
[SET]: 70-740.md#hyper-v-networking 'Switch Embedded Teaming (SET)&#10;Hyper-V-only variation of NIC teaming that is implemented wholly within a virtual switch&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'

Create a virtual switch with [SET][SET] enabled. <sup>[Zacker][Zacker]: 254</sup>
```powershell
New-VMSwitch -Name SETSwitch -NetAdapterName "nic1","nic2" -EnableEmbeddedTeaming $true
```
Add new virtual network adapters to VMs
```powershell
Add-VMNetworkAdapter -VMName server1 -SwitchName setswitch -Name set1
```
Enable RDMA with [`Get-`][Get-NetAdapterRdma] and [`Enable-NetAdapterRdma`][Enable-NetAdapterRdma].
#### Implement nested virtualization
Both the physical host and the nested virtual host must be running Windows Server 2016, but before installing Hyper-V on the nested host, the following configurations must be made. <sup>[Zacker][Zacker]: 181</sup>

Provide nested host's processor with access to virtualization technology on the physical host
```powershell
Set-VMProcessor -VMName server1 -ExposeVirtualizationExtensions $true
```
Disable dynamic memory
```powershell
Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false
```
Configure 2 virtual processors
```powershell
Set-VMProcessor -VMName SVR01 -Count 2
```
Turn on MAC address spoofing
```powershell
Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On
```
#### Enable CredSSP
On the remote (managed) server <sup>[Zacker][Zacker]: 176</sup>
```powershell
Enable-PSRemoting
Enable-WSManCredSSP
```
Add the fully-qualified domain name of the Hyper-V server to be managed to the local system's WSMan trusted hosts list
```powershell
Set-Item WSMan:\localhost\client\trustedhosts -Value "hypervserver.domain.com"
```
Enable the use of CredSSP on the client 
```powershell
Enable-WSManCredSSP -Role client -DelegateComputer "hypervserver.domain.com"
```
#### Configure Server Core
Manually configure network interface, if a DHCP server is unavailable <sup>[Zacker][Zacker]: 19</sup>
```powershell
New-NetIPAddress 10.0.0.3 -InterfaceAlias "Ethernet' -PrefixLength 24
```
Configure the DNS server addresses for the adapter
```powershell
Set-DnsClientServerAddress -InterfaceIndex 6 -ServerAddresses ("192.168.0.1","192.168.0.2")
```
Rename the computer and join it to a domain
```powershell
Add-Computer -DomainNAme adatum.com -NewName Server8 -Credential adatum\administrator
```
#### Update Server Core image
```powershell
Mount-WindowsImage -ImagePath .\CoreServer.vhdx -Path .\MountDir -Index 1
Add-WindowsPackage -Path .\MountDir -PackagePath C:\ServicingPackages_cabs
Dismount-WindowsImage -Path .\MountDir -Save
```
#### Implement DDA
[DDA]: 70-740.md#vm-configuration 'Discrete Device Assignment (DDA)&#10;Hyper-V feature that enables passthrough of any PCI Express device, including GPUs or network adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'

[Discrete Device Assignment (DDA)][DDA] begins with finding the Instance ID of the device needed to be passed through. <sup>[Zacker][Zacker]: 212</sup>
```powershell
Get-PnpDevice -PresentOnly
```
Remove host-installed drivers
```powershell
Disable-PnpDevice -InstanceId
```
Provide `InstanceId` and `KeyName` values in order to get value for `LocationPath` parameter in next command
```powershell
Get-PnpDeviceProperty
```
Remove the device from host control
```powershell
Dismount-VmHostAssignableDevice -LocationPath
```
Attach the device to a guest
```powershell
Add-VMAssignableDevice -VM -LocationPath
```
#### Configure live migration
Live migration is possible between Hyper-V hosts that are not clustered, but they must be within the same (or trusted) domains. <sup>[Zacker][Zacker]</sup>
```powershell
Enable-VMMigration
Set-VMMigrationNetwork 192.168.4.0
Set-VMHost -VirtualMachineMigrationAuthenticationType Kerberos
Set-VMHost -VirtualMachineMigrationPerformanceOption smbtransport
```
#### Configure S2D cluster
```powershell
New-Cluster -Name cluster1 -node server1,server2,server3,server4 -NoStorage
Enable-ClusterStorageSpacesDirect
```