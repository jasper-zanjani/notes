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
[Holmes]: # 'Holmes, Lee. _Windows PowerShell Cookbook_. O\'Reilly Media, 2013.'

# PowerShell
## Contents
###### Tasks
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


#### Cmdlets
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
<code>Quorum&nbsp;[g][Get-ClusterQuorum]</code>
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
[Get-SmbClientConfiguration]: #get-smbclientconfiguration '```&#10;PS C:\> Get-SmbClientConfiguration&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 111'
[Close-SmbOpenFile]: #close-smbopenfile '```&#10;PS C:\> Close-SmbOpenFile&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Get-SmbOpenFile]: #get-smbopenfile '```&#10;PS C:\> Get-SmbOpenFile&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Set-SmbPathAcl]: #set-smbpathacl '```&#10;PS C:\> Set-SmbPathAcl&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 340'
[Set-SmbServerConfiguration]: #set-smbserverconfiguration '```&#10;PS C:\> Set-SmbServerConfiguration&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Close-SmbSession]: #close-smbsession '```&#10;PS C:\> Close-SmbSession&#10;```&#10;Ends forcibly the SMB session.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 107'
[Get-SmbSession]: #get-smbsession '```&#10;PS C:\> Get-SmbSession&#10;```&#10;Retrieves information about the SMB sessions that are currently established between the SMB server and the associated clients.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 107'
[New-SmbShare]: #new-smbshare '```&#10;PS C:\> New-SmbShare&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 106'
[Remove-SmbShare]: #remove-smbshare '```&#10;PS C:\> Remove-SmbShare&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Block-SmbShareAccess]: #block-smbshareaccess '```&#10;PS C:\> Block-SmbShareAccess&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Get-SmbShareAccess]: #get-smbshareaccess '```&#10;PS C:\> Get-SmbShareAccess&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 108'
[Grant-SmbShareAccess]: #grant-smbshareaccess '```&#10;PS C:\> Grant-SmbShareAccess&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Revoke-SmbShareAccess]: #revoke-smbshareaccess '```&#10;PS C:\> Revoke-SmbShareAccess&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Unblock-SmbShareAccess]: #unblock-smbshareaccess '```&#10;PS C:\> Unblock-SmbShareAccess&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 109'
[Close-SmbOpenFile]: #close-smbopenfile '```&#10;PS C:\> Close-SmbOpenFile&#10;```&#10;Close a file that is open by one of the clients of the SMB server&#10;"Close-SmbOpenFile". _Microsoft Docs_.'
[Get-SmbOpenFile]: #get-smbopenfile '```&#10;PS C:\> Get-SmbOpenFile&#10;```&#10;Retrieve basic information about the files that are open on behalf of the clients of the Server Message Block (SMB) server&#10;"Get-SmbOpenFile". _Microsoft Docs_.'
[New-SmbShare]: #new-smbshare '```&#10;PS C:\> New-SmbShare&#10;```&#10;'

[**Smb**](#smb)
<code>ClientConfiguration&nbsp;[g][Get-SmbClientConfiguration]</code>
<code>OpenFile&nbsp;[g][Get-SmbOpenFile]&nbsp;[cs][Close-SmbOpenFile]</code>
<code>ServerConfiguration&nbsp;g&nbsp;[s][Set-SmbServerConfiguration]</code>
<code>Session&nbsp;[cs][Close-SmbSession]&nbsp;[g][Get-SmbSession]</code>
<code>Share&nbsp;[n][New-SmbShare]&nbsp;[r][Remove-SmbShare]</code>
<code>ShareAccess&nbsp;[g][Get-SmbShareAccess]&nbsp;[bl][Block-SmbShareAccess]&nbsp;[gr][Grant-SmbShareAccess]&nbsp;[rk][Revoke-SmbShareAccess]&nbsp;[uk][Unblock-SmbShareAccess]</code>

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

<code>WebRequest&nbsp;[i][Invoke-WebRequest]</code>
**DNS**
<code>ClientServerAddress&nbsp;[s][Set-DnsClientServerAddress]</code> 
<code>Name&nbsp;[rv][Resolve-DNSName]</code> 
**DhcpServer**
<code>InDC [a][Add-DhcpServerInDC]</code> 
<code>V4Scope [a][Add-DhcpServerv4Scope]</code> 
<code>v4OptionValue [s][Set-DhcpServerv4OptionValue]</code> 
**Net**
<code>Adapter&nbsp;[g][Get-NetAdapter]</code>
<code>FirewallRule&nbsp;[e][Enable-NetFirewallRule]&nbsp;[g][Get-NetFirewallRule]&nbsp;[n][New-NetFirewallRule]&nbsp;[s][Set-NetFirewallRule]</code>
<code>IpAddress&nbsp;[n][New-NetIpAddress]</code>
<code>IpConfiguration&nbsp;[g][Get-NetIpConfiguration]</code>

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

##### Shell environment cmdlets
[Add-Computer]: #add-computer '```&#10;PS C:\> Add-Computer&#10;```&#10;Join a computer to a domain'
[Add-PSSnapin]: #add-pssnapin '```&#10;PS C:\> Add-PSSnapin&#10;PS C:\> asnp&#10;```&#10;Load a given list of snap-ins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) either by name or via the pipeline - last supported in PowerShell 5.1'
[Add-Type]: #add-type '```&#10;PS C:\> Add-Type&#10;```&#10;add a.NET Framework type (a class) to a Windows PowerShell session'
[Clear-Host]: #clear-host '```&#10;PS C:\> Clear-Host&#10;```&#10;'
[Disconnect-PSSession]: #disconnect-pssession '```&#10;PS C:\> Disconnect-PSSession&#10;PS C:\> dnsn&#10;```&#10;Terminate a remote PowerShell session begun with `New-PSSession`'
[Enable-PSRemoting]: #enable-psremoting '```&#10;PS C:\> Enable-PSRemoting&#10;```&#10;Allow remote Powershell management'
[Enter-PSSession]: #enter-pssession '```&#10;PS C:\> Enter-PSSession&#10;PS C:\> etsn&#10;```&#10;Interact with the specified PowerShell session'
[Exit-PSSession]: #exit-pssession '```&#10;PS C:\> Exit-PSSession&#10;PS C:\> exsn&#10;```&#10;End an interactive session with a remote computer'
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
[Get-PSSession]: #get-pssession '```&#10;PS C:\> Get-PSSession&#10;PS C:\> gsn&#10;```&#10;Get the Windows Powershell sessions on local and remote computers'
[Import-Module]: #import-module '```&#10;PS C:\> Import-Module&#10;PS C:\> ipmo&#10;```&#10;'
[Install-Module]: #install-module '```&#10;PS C:\> Install-Module&#10;```&#10;'
[New-Alias]: #new-alias '```&#10;PS C:\> New-Alias&#10;PS C:\> nal&#10;```&#10;Create a new alias'
[New-PSSession]: #new-pssession '```&#10;New-PSSession&#10;nsn&#10;```&#10;Start a new remote PowerShell session with a remote computer&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 21'
[Out-Host]: #out-host '```&#10;PS C:\> Out-Host&#10;PS C:\> oh&#10;```&#10;'
[Rename-Computer]: #rename-computer '```&#10;PS C:\> Rename-Computer&#10;```&#10;'
[Restart-Computer]: #restart-computer '```&#10;PS C:\> Restart-Computer&#10;```&#10;'
[Set-Alias]: #set-alias '```&#10;PS C:\> Set-Alias&#10;```&#10;'
[Set-Clipboard]: #set-clipboard '```&#10;PS C:\> Set-Clipboard&#10;PS C:\> scb&#10;```&#10;Set the current Windows clipboard entry'
[Set-ExecutionPolicy]: #set-executionpolicy '```&#10;PS C:\> Set-ExecutionPolicy&#10;```&#10;Change user preference for the Windows PowerShell execution policy'
[Set-Location]: #set-location '```&#10;PS C:\> Set-Location&#10;PS C:\> cd&#10;```&#10;Set present working directory'
[Set-PSReadlineOption]: #set-psreadlineoption '```&#10;PS C:\> Set-PSReadlineOption&#10;```&#10;'
[Start-DscConfiguration]: #start-dscconfiguration '```&#10;PS C:\> Start-DscConfiguration&#10;```&#10;Apply configuration to nodes&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 27'
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
<code>[Session](#pssession)&nbsp;[dc][Disconnect-PSSession] [et][Enter-PSSession] [ex][Exit-PSSession] [g][Get-PSSession] [n][New-PSSession]</code> 

##### Hyper-V cmdlets
<!-- Hyper-V cmdlets -->
[Add-VMNetworkAdapter]: #add-vmnetworkadapter '```&#10;PS C:\> Add-VMNetworkAdapter&#10;```&#10;Adds a virtual network adapter to a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 237'
[Add-VMSwitch]: # '`Add-VMSwitch`&#10;Adds a virtual switch to an Ethernet resource pool.'
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
[Get-VMSwitch]:                                      # '`Get-VMSwitch`&#10;Gets virtual switches from one or more virtual Hyper-V hosts.'
[Import-VM]: #import-vm '```&#10;PS C:\> Import-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 211'
[Measure-VM]: #measure-vm '```&#10;PS C:\> Measure-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 194, 234-235'
[Mount-VHD]: #mount-vhd '```&#10;Mount-VHD&#10;```&#10;Mounts one or more virtual hard disks.'
[Move-VM]:                                           #move-vm                                      '`Move-VM`&#10;Moves a virtual machine to a new Hyper-V host.'
[New-VHD]: #new-vhd '```&#10;New-VHD&#10;```&#10;Creates one or more new virtual hard disks.'
[New-VM]: #new-vm '```&#10;PS C:\> New-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 47, 184, 197'
[New-VMSwitch]: # '`New-VMSwitch`&#10;Creates a new virtual switch on one or more virtual machine hosts.'
[Optimize-VM]: #optimize-vm '```&#10;PS C:\> Optimize-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Remove-VM]: #remove-vm '`Remove-VM`&#10;Deletes a virtual machine.'
[Remove-VMNetworkAdapter]: #remove-vmnetworkadapter '```&#10;PS C:\> Remove-VMNetworkAdapter&#10;```&#10;Removes one or more virtual network adapters from a virtual machine.'
[Remove-VMSwitch]: # '`Remove-VMSwitch`&#10;Deletes a virtual switch.'
[Rename-VM]: #rename-vm                                    '`Rename-VM`&#10;Renames a virtual machine.'
[Rename-VMNetworkAdapter]: #rename-vmnetworkadapter '```&#10;PS C:\> Rename-VMNetworkAdapter&#10;```&#10;Renames a virtual network adapter on a virtual machine or on the management operating system.'
[Rename-VMSwitch]: # '`Rename-VMSwitch`&#10;Renames a virtual switch.'
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
[Set-VMSwitch]:                                      # '`Set-VMSwitch`&#10;Configures a virtual switch.'
[Start-VM]:                                          #start-vm                                     '`Start-VM`&#10;Starts a virtual machine.'
[Stop-VM]:                                           #stop-vm                                      '`Stop-VM`&#10;Shuts down, turns off, or saves a virtual machine.'
[Suspend-VM]:                                        #suspend-vm                                   '`Suspend-VM`&#10;Suspends, or pauses, a virtual machine.'
[Test-VMNetworkAdapter]: #test-vmnetworkadapter '```&#10;PS C:\> Test-VMNetworkAdapter&#10;```&#10;Tests connectivity between virtual machines.'
[Update-VMVersion]: #update-vmversion '```&#10;PS C:\> Update-VMVersion&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 209'


**VHD**
<code>[mt][Mount-VHD]&nbsp;[n][New-VHD]&nbsp;</code>
**VM**
<code>[cr][Compare-VM]&nbsp;[db][Debug-VM]&nbsp;[ep][Export-VM]&nbsp;[g][Get-VM]&nbsp;[ip][Import-VM]&nbsp;[m][Move-VM]&nbsp;[ms][Measure-VM]&nbsp;[n][New-VM]&nbsp;[r][Remove-VM]&nbsp;[rn][Rename-VM]&nbsp;[rt][Restart-VM]&nbsp;[ru][Resume-VM]&nbsp;[s][Set-VM]&nbsp;[sa][Start-VM]&nbsp;[sp][Stop-VM]&nbsp;[ss][Suspend-VM]&nbsp;[sv][Save-VM]</code>
<code>Firmware&nbsp;[s][Set-VMFirmware]</code> 
<code>Memory&nbsp;[s][Set-VMMemory]</code> 
<code>NetworkAdapter&nbsp;[a][Add-VMNetworkAdapter]&nbsp;[r][Remove-VMNetworkAdapter]&nbsp;[s][Set-VMNetworkAdapter]</code> 
<code>Processor&nbsp;[s][Set-VMProcessor]</code> 
<code>Switch&nbsp;[n][New-VMSwitch]</code> 

##### Server migration cmdlets
[Set-AppxProvisionedDataFile]: # '```&#10;PS C:\> Set-AppxProvisionedDataFile&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Set-ProvisionedAppxDataFile`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Add-AppxProvisionedPackage]: # '```&#10;PS C:\> Add-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-AppxProvisionedPackage]: # '```&#10;PS C:\> Get-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-ProvisionedAppxPackages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-AppxProvisionedPackage]: # '```&#10;PS C:\> Remove-AppxProvisionedPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Receive-SmigServerData]: #receive-smigserverdata '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Send-SmigServerData]: #send-smigserverdata '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-SmigServerFeature]: #get-smigserverfeature '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Export-SmigServerSetting]: #export-smigserversetting '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Import-SmigServerSetting]: #import-smigserversetting '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'

**AppxProvisioned**
<code>DataFile&nbsp;[s][Set-AppxProvisionedDataFile]</code> 
<code>Package&nbsp;[a][Add-AppxProvisionedPackage] [g][Get-AppxProvisionedPackage] [r][Remove-AppxProvisionedPackage]</code> 
**SmigServer** 
<code>Data [rc][Receive-SmigServerData] [sd][Send-SmigServerData]</code> 
<code>Feature [g][Get-SmigServerFeature]</code> 
<code>Setting [ex][Export-SmigServerSetting] [ip][Import-SmigServerSetting]</code>

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
[Add-WindowsDriver]: # '```&#10;PS C:\> Add-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-Drive`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsFeature]: #add-windowsfeature '```&#10;PS C:\> Add-WindowsFeature&#10;PS C:\> Install-WindowsFeature&#10;```&#10;Install one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2'
[Add-WindowsImage]: # '```&#10;PS C:\> Add-WindowsImage&#10;```&#10;&#10;Equivalent to `dism.exe /Append-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsPackage]: # '```&#10;PS C:\> Add-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Add-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Apply-WindowsUnattend]: # '```&#10;PS C:\> Apply-WindowsUnattend&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Apply-Unattend`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Disable-WindowsOptionalFeature]: # '```&#10;PS C:\> Disable-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Disable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Dismount-WindowsImage]: # '```&#10;PS C:\> Dismount-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Unmount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Edit-NanoServerImage]: #edit-nanoserverimage '```&#10;PS C:\> Edit-NanoServerImage&#10;```&#10;Add a role or feature to an existing Nano Server VHD file&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[Enable-WindowsOptionalFeature]: #enable-windowsoptionalfeature '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;Enable or restore an optional feature in a Windows image'
[Enable-WindowsOptionalFeature]: # '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Enable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Expand-WindowsImage]: # '```&#10;PS C:\> Expand-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Apply-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsDriver]: # '```&#10;PS C:\> Export-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Export-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsImage]: # '```&#10;PS C:\> Export-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Export-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsDriver]: # '```&#10;PS C:\> Get-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Drivers`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsFeature]: #get-windowsfeature '```&#10;PS C:\> Get-WindowsFeature&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 15'
[Get-WindowsImage]: # '```&#10;PS C:\> Get-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Get-ImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsImageContent]: # '```&#10;PS C:\> Get-WindowsImageContent&#10;```&#10;&#10;Equivalent to `Dism.exe /List-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsOptionalFeature]: # '```&#10;PS C:\> Get-WindowsOptionalFeature&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Features`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsPackage]: # '```&#10;PS C:\> Get-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WMIObject]: #get-wmiobject '```&#10;PS C:\> Get-WMIObject&#10;PS C:\> gwmi&#10;```&#10;Gets instances of Windows Management Instrumentation (WMI) classes or information about the available classes.&#10;Superseded by `Get-CimInstance` since Powershell 3.0'
[Install-WindowsFeature]: #install-windowsfeature '```&#10;PS C:\> Install-WindowsFeature&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 15, 171, 225, 377'
[Mount-WindowsImage]: # '```&#10;PS C:\> Mount-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Mount-image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[New-NanoServerImage]: #new-nanoserverimage '```&#10;PS C:\> New-NanoServerImage&#10;New-NanoServerImage -DeploymentType guest|host -Edition standard|datacenter -MediaPath root -TargetPath $PATH -ComputerName $NAME&#10;```&#10;Used to create a Nano Server VHD file for Nano Server installation&#10;Required parameters:&#10;  `DeploymentType` specified whether the image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;  `Edition` specifies whether to install the Standard or Datacenter edition of Nano Server&#10;  `MediaPath` specifies the path to the root of the WS2016 installation disk or mounted image&#10;  `BasePath` specifies a path on the local system where the cmdlet creates a copy of the installation files from the location specified in `MediaPath`&#10;  `TargetPath` specifies the full path and filename of the new image to be created with the filename extension (".vhd" or ".vhdx") specifying Generation 1 or Generation 2 image.&#10;  `ComputerName` specifies the computer name that should be assigned to the new image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-WindowsImage]: # '```&#10;PS C:\> New-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Capture-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-WindowsDriver]: # '```&#10;PS C:\> Remove-WindowsDriver&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsImage]: # '```&#10;PS C:\> Remove-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Remove-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-WindowsPackage]: # '```&#10;PS C:\> Remove-WindowsPackage&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Save-WindowsImage]: # '```&#10;PS C:\> Save-WindowsImage&#10;```&#10;&#10;Equivalent to `Dism.exe /Commit-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

<code>Guid&nbsp;n</code> 
<code>NanoServerImage&nbsp;[n][New-NanoServerImage] [e][Edit-NanoServerImage]</code> 
<code>WMIObject&nbsp;[g][Get-WMIObject]</code> 
**Windows**
<code>Driver&nbsp;[a][Add-WindowsDriver]&nbsp;[ep][Export-WindowsDriver]&nbsp;[g][Get-WindowsDriver]&nbsp;[r][Remove-WindowsDriver]</code> 
<code>Feature&nbsp;[a][Install-WindowsFeature]&nbsp;[g][Get-WindowsFeature]&nbsp;[is][Install-WindowsFeature]</code> 
<code>OptionalFeature&nbsp;[e][Enable-WindowsOptionalFeature]</code> 
<code>Image&nbsp;[a][Add-WindowsImage]&nbsp;[en][Expand-WindowsImage]&nbsp;[n][New-WindowsImage]&nbsp;[sv][Save-WindowsImage]&nbsp;[ep][Export-WindowsImage]&nbsp;[g][Get-WindowsImage]&nbsp;[mt][Mount-WindowsImage]&nbsp;[r][Remove-WindowsImage]&nbsp;[dm][Dismount-WindowsImage]</code>
<code>ImageContent&nbsp;[g][Get-WindowsImageContent]</code>
<code>OptionalFeature&nbsp;[d][Disable-WindowsOptionalFeature]&nbsp;[e][Enable-WindowsOptionalFeature]&nbsp;[g][Get-WindowsOptionalFeature]</code>
<code>Package&nbsp;[a][Add-WindowsPackage]&nbsp;[g][Get-WindowsPackage]&nbsp;[r][Remove-WindowsPackage]</code>
<code>Unattend&nbsp;[Apply][Apply-WindowsUnattend]</code>

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

##### Cmdlets covered in 70-740

## Syntax
The `Throw` keyword generates a terminating error

#### Variables
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
##### `DscConfiguration`
###### `Start-DscConfiguration`
Used to erect a **push architecture** in [DSC](dsc.md). <sup>[Zacker][Zacker]: 27</sup>

Option  | Description
---     | ---
`-Path`
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
##### `PSRemoting`
###### `Enable-PSRemoting`
##### `PSSession`
###### `Disconnect-PSSession`
Terminate a remote PowerShell session begun with [`New-PSSession`][New-PSSession] <sup>[Zacker][Zacker]: 22</sup>
###### `Enter-PSSession`
Interact with the specified PowerShell session
```powershell
Enter-PSSession -id 1
```
Start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
```powershell
Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey
```
###### `Exit-PSSession`
Exit a remote PowerShell session <sup>[Zacker][Zacker]: 22</sup>
End the PowerShell session with the specified computer
```powershell
Exit-PSSession -ComputerName demodc
```
###### `Get-PSSession`
Display PowerShell sessions
```powershell
Get-PSSession
```
###### `New-PSSession`
Option  | Description
---     | ---
`-ComputerName`

Manage a Windows Server remotely <sup>[Zacker][Zacker]: 21</sup>
```powershell
New-PSSession -ComputerName rtmsvrd
```
Start a new PowerShell session, connecting to the specified computer
```powershell
New-PSSession -ComputerName core02
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

Manually configure network interface, if a DHCP server is unavailable <sup>[Zacker][Zacker]: 19</sup>
```powershell
New-NetIPAddress 10.0.0.3 -InterfaceAlias "Ethernet' -PrefixLength 24
```
Configure the Domain Controller in a new corporate intranet <sup>[Jones][Jones]</sup>
```powershell
New-NetIPAddress 10.0.0.1 -InterfaceAlias "Ethernet" -PrefixLength 24
```
Configure the application server in a new corporate intranet <sup>[Jones][Jones]</sup>
```powershell
New-NetIpAddress 10.0.0.3 -InterfaceAlias "Ethernet" -PrefixLength 24
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
#### Process control
##### `Process`
###### `Start-Process`
Run a program as admin
```powershell
Start-Process cmd -Verb runas
saps cmd -v runas
```
#### Disks
##### `DedupVolume`
###### `Enable-DedupVolume`
Enable deduplication <sup>[Zacker][Zacker]: 157</sup>
```powershell
Enable-DedupVolume -Volume "e:" -UsageType default
Enable-DedupVolume -Volume "\\?\\volume{26a21bda-a627-11d7-9931-806e6f6e6963}" -UsageType backup
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
##### `Null`
###### `Out-Null`
#### Filters
##### `Object`
###### `Measure-Object`
###### `ForEach-Object`
###### `New-Object`
###### `Select-Object`
###### `Where-Object`

#### Hyper-V
##### `VHD`
###### `Mount-VHD`
- [VHDX file](#vhdx-file)

###### `New-VHD`
- [VHDX file](#vhdx-file)
##### `VM`
Install Hyper-V Powershell module <sup>[Zacker][Zacker]: 90</sup>
```powershell
Install-WindowsFeature -Name hyper-v-powershell
```
###### `Export-VM`
Export a VM <sup>[Zacker][Zacker]: 373</sup>
```powershell
Export-Vm -Name clustervm1 -Path D:\vm
```
###### `Import-VM`
Import a VM into the Hyper-V host <sup>[Zacker][Zacker]: 373</sup>
```powershell
Import-VM -Path "D:\vm\virtual machines\5ae40946-3a98-428e-8c83-081a3c68d18c.xml" -Copy -GenerateNewId
```
###### `Move-VM`
Perform a live migraiton <sup>[Zacker][Zacker]: 307</sup>
```powershell
Move-VM -VM server1 -DestinationHost hyper2
```
###### `New-VM`
Create a Nano Server VM from an image file <sup>[Zacker][Zacker]: 47</sup>
```powershell
New-VM -Name "nano2" -Generation 2 -MemoryStartupBytes 1GB -VHDPath "F:\hyper-v\virtual hard disks\nano2.vhdx"
```
###### `Set-VMFirmware`
Enable secure boot on Generation 2 Linux VMs <sup>[IMWS][IMWS]</sup>
```powershell
Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority
```
###### `Set-VMMemory`
Disable dynamic memory on a virtual host (nested virtualization)
```powershell
Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false
```
###### `Set-VMProcessor`
Configure 2 virtual processors on a virtual host (nested virtualization)
```powershell
Set-VMProcessor -VMName SVR01 -Count 2
```
###### `Set-VMReplicationServer`
Configure a server's replica configuration <sup>[Zacker][Zacker]: 300</sup>
```powershell
Set-VmReplicationServer -ReplicationEnabled $true -AllowedAuthenticationType kerberos -ReplicationAllowedFromAnyServer $true -DefaultStorageLocation D:\replicas
```
##### `VMSwitch`
###### `New-VMSwitch`
Create a new virtual switch <sup>[Zacker][Zacker]: 242</sup>
```powershell
New-VMSwitch -Name lan1 -NetAdapterName "Ethernet 2"
New-VMSwitch -Name private1 -SwitchType private
```
Turn on NAT on the nested Hyper-V VM
```powershell
New-VMSwitch -name VMNAT -SwitchType Internal
New-NetNAT -Name LocalNAT -InternalIPInterfaceAddressPrefix "192.168.100.0/24"
```
##### `VMNetworkAdapter`
###### `Add-VMNetworkAdapter`
Create a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Add-VMNetworkAdapter -VMName server1 -SwitchName private1
```
###### `Remove-VMNetworkAdapter`
Remove a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Remove-VMNetworkAdapter -VMName server1 -VMNetworkAdapter nic1
```
###### `Set-VMNetworkAdapter`
Turn on MAC address spoofing on a virtual host (nested virtualization)
```powershell
Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On
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
Options for configuring a network adapter

`InterfaceNameOrIndex`
`Ipv4Address`

###### `Edit-NanoServerImage`
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
###### `New-NanoServerImage`
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
##### `WindowsImage`
###### `Get-WindowsImage`
[Get-WindowsImage -Mounted]: #Get-WindowsImage '```&#10;PS C:\> Get-WindowsImage -Mounted&#10;```&#10;&#10;Equivalent to `Dism.exe /Get-MountedImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Mounted`][Get-WindowsImage -Mounted]
###### `Mount-WindowsImage`
[Mount-WindowsImage -Remount]: #Mount-WindowsImage '```&#10;PS C:\> Mount-WindowsImage -Remount&#10;```&#10;&#10;Equivalent to `Dism.exe /Remount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Remount`][Mount-WindowsImage -Remount]
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

Install a feature <sup>[Zacker][Zacker]: 15</sup>
```powershell
Install-WindowsFeature -Name $featurename -IncludeAllSubFeature -IncludeManagementTools

# Remote Server Adminstration Tools for PowerShell
Install-WindowsFeature -Name rsat-adds -IncludeAllSubFeature

# Install Hyper-V
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
##### `WindowsOptionalFeature`
###### `Enable-WindowsOptionalFeature`
Enable a feature in the currently running operating system <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/dism/enable-windowsoptionalfeature?view=win10-ps&redirectedfrom=MSDN "Microsoft Docs: \"Enable-WindowsOptionalFeature\"")</sup>
```powershell
Enable-WindowsOptionalFeature -Online -FeatureName "Hearts" -All
```
Enable WSL <sup>[Reddit](https://www.reddit.com/r/bashonubuntuonwindows/comments/7smf9m/help_wsl_wont_activate_on_my_freshly_installed/ "Reddit: \"[help] WSL won't activate on my freshly installed Windows 10 version 1709\"")</sup>
```powershell
Enable-WindowsOptionalFeature -online -FeatureName Microsoft-Windows-Subsystem-Linux
```
###### `Get-WindowsOptionalFeature`
[Get-WindowsOptionalFeature -FeatureName]: #Get-WindowsOptionalFeature '```&#10;PS C:\> Get-WindowsOptionalFeature -FeatureName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Featureinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[`FeatureName`][Get-WindowsOptionalFeature -FeatureName]
##### `WindowsPackage`
###### `Get-WindowsPackage`
[Get-WindowsPackage -PackagePath]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackagePath&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsPackage -PackageName]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackageName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[`PackageName`][Get-WindowsPackage -PackageName] 
[`PackagePath`][Get-WindowsPackage -PackagePath]
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

#### Failover clusters
##### `Cluster`
###### `New-Cluster`
Create an Active Directory-detached cluster <sup>[Zacker][Zacker]: 337</sup>
```powershell
New-Cluster cluster1 -Node node1,node2 -StaticAddress 10.0.0.1 -NoStorage -AdministrativeAccessPoint dns
```
Create a cluster, but prevent the system from automatically searching for and adding storage. <sup>[Zacker][Zacker]: 354</sup>
```powershell
New-Cluster -Name cluster1 -node server1,server2,server3,server4 -NoStorage
```
##### `ClusterNode`
###### `Suspend-ClusterNode`
Pause a node and move ("drain") its workloads with `-Drain`. <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/failoverclusters/suspend-clusternode "Suspend-ClusterNode")
```powershell
Suspend-ClusterNode -Name "node1" -Target "node2" -Drain
```
##### `ClusterScaleOutFileServer`
###### `Add-ClusterScaleOutFileServer`
Install the Scale-out File Server role <sup>[Zacker][Zacker]: 339</sup>
```powershell
Add-ClusterScaleOutFileServer
```
##### `ClusterStorageSpacesDirect`
###### `Enable-ClusterStorageSpacesDirect`
Add storage to a failover cluster [created][New-Cluster] with the `-NoStorage` option <sup>[Zacker][Zacker]: 354</sup>
```powershell
Enable-ClusterStorageSpacesDirect
```
#### File shares
##### `SmbOpenFile`
###### `Get-SmbOpenFile`
Get information about an opened file <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -FileId 4415226383569 | Select-Object -Property *
```
Get information about a file opened for an SMB client <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -SessionId 4415226380393
```
###### `Close-SmbOpenFile`
Close an open file <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -FileId 4415226383589
```
Close open files for a session <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -SessionId 4415226380393
```
##### `SmbShare`
###### `New-SmbShare`
```powershell
New-SmbShare -Name files -Path C:\networkfiles -ChangeAccess CORP\SysAdmin
```
Create a new share called `Data` from the `C:\Docs` folder with the `Allow Full Control` permission granted to the `Everyone` special identity <sup>[Zacker][Zacker]: 106</sup>
```powershell
New-SmbShare -Name Data -Path C:\Docs -FullAccess Everyone
```
##### `SmbSession`
###### `Close-SmbSession`
```powershell
Close-SmbSession -SessionId 154618822713
```
###### `Get-SmbSession`

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