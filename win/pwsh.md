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
[mu:70-740]: # 'MeasureUp Practice Test. _Installation, Storage and Compute with Windows Server 2016 (70-740)_.'
[pl:70-740]: # 'MeasureUp Practice Lab: Installation, Storage and Compute with Windows Server 2016 (70-740)'

# Contents
- [**Modules**](#modules)
- [**Tasks**](#tasks)

<!--
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

### Bash equivalents
[`$!`][&#36;&#36;]/[`!$`][&#36;&#36;] 
[`$?`][&#36;?] 
[`&`][Start-Job] 
[`>>`][Add-Content] 
[`alias`][New-Alias] 
[`awk`][Select-Object] 
[`basename`][Get-Item]
`bzip2` 
[`cat`][Get-Content] 
[`cd`][Set-Location] 
[`cp`][Copy-Item] 
[`dirname`][Get-Item]
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
[`sed`][Where-Object] 
[`shutdown`][Stop-Computer][` -r`][Restart-Computer]
[`tail`][Get-Content] 
[`touch`][New-Item]
[`uniq`][Select-Object]
[`wc`][Measure-Object] 
[`which`][Get-Command]
-->

### Modules
[`dhcpserver`](#dhcpserver)
[`diagnostics`](#microsoftpowershelldiagnostics)
[`dnsclient`](#dnsclient)
[`netadapter`](#netadapter)
[`netconnection`](#netconnection)
[`netsecurity`](#netsecurity)
[`nettcpip`](#nettcpip)
[`packagemanagement`](#packagemanagement)
[`psdesiredconfiguration`](#psdesiredstateconfiguration)
[`smbshare`](#smbshare)
[`storage`](#storage)
[`utility`](#microsoftpowershellutility)
[`wsman.management`](#microsoftpowershellwsmanmanagement)

**Windows Server modules**
[`addsadministartion`](#addsadministration)
[`dcbqos`](#dcbqos)
[`deduplication`](#deduplication)
[`defender`](#defender)
[`failoverclusters`](#failoverclusters)
[`hyper-v`](#hyper-v)
[`iscsi`](#iscsi)
[`iscsitarget`](#iscsitarget)
[`dism`](#dism)
[`nanoserverimagegenerator`](#nanoserverimagegenerator)
[`netqos`](#netqos)
[`networkbalancingclusters`](#networkloadbalancingclusters)
[`servermanager`](#servermanager)
[`servermigration`](#servermigration)
[`storagereplica`](#storagereplica)
[`virtualmachinemanager`](#virtualmachinemanager)
[`windowsserverbackup`](#windowsserverbackup)

#### addsadministration
[msdocs:Disable-ADAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Disable-ADAccount "Disable-ADAccount documentation"
[msdocs:Enable-ADAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Enable-ADAccount "Enable-ADAccount documentation"
[msdocs:Search-ADAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Search-ADAccount "Search-ADAccount documentation"
[msdocs:Unlock-ADAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Unlock-ADAccount "Unlock-ADAccount documentation"
[msdocs:Set-ADAccountAuthenticationPolicySilo]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAccountAuthenticationPolicySilo "Set-ADAccountAuthenticationPolicySilo documentation"
[msdocs:Get-ADAccountAuthorizationGroup]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADAccountAuthorizationGroup "Get-ADAccountAuthorizationGroup documentation"
[msdocs:Set-ADAccountControl]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAccountControl "Set-ADAccountControl documentation"
[msdocs:Clear-ADAccountExpiration]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Clear-ADAccountExpiration "Clear-ADAccountExpiration documentation"
[msdocs:Set-ADAccountExpiration]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAccountExpiration "Set-ADAccountExpiration documentation"
[msdocs:Set-ADAccountPassword]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAccountPassword "Set-ADAccountPassword documentation"
[msdocs:Get-ADAccountResultantPasswordReplicationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADAccountResultantPasswordReplicationPolicy "Get-ADAccountResultantPasswordReplicationPolicy documentation"
[msdocs:Get-ADAuthenticationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADAuthenticationPolicy "Get-ADAuthenticationPolicy documentation"
[msdocs:New-ADAuthenticationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADAuthenticationPolicy "New-ADAuthenticationPolicy documentation"
[msdocs:Remove-ADAuthenticationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADAuthenticationPolicy "Remove-ADAuthenticationPolicy documentation"
[msdocs:Set-ADAuthenticationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAuthenticationPolicy "Set-ADAuthenticationPolicy documentation"
[msdocs:Show-ADAuthenticationPolicyExpression]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Show-ADAuthenticationPolicyExpression "Show-ADAuthenticationPolicyExpression documentation"
[msdocs:Get-ADAuthenticationPolicySilo]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADAuthenticationPolicySilo "Get-ADAuthenticationPolicySilo documentation"
[msdocs:New-ADAuthenticationPolicySilo]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADAuthenticationPolicySilo "New-ADAuthenticationPolicySilo documentation"
[msdocs:Remove-ADAuthenticationPolicySilo]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADAuthenticationPolicySilo "Remove-ADAuthenticationPolicySilo documentation"
[msdocs:Set-ADAuthenticationPolicySilo]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADAuthenticationPolicySilo "Set-ADAuthenticationPolicySilo documentation"
[msdocs:Grant-ADAuthenticationPolicySiloAccess]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Grant-ADAuthenticationPolicySiloAccess "Grant-ADAuthenticationPolicySiloAccess documentation"
[msdocs:Revoke-ADAuthenticationPolicySiloAccess]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Revoke-ADAuthenticationPolicySiloAccess "Revoke-ADAuthenticationPolicySiloAccess documentation"
[msdocs:Get-ADCentralAccessPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADCentralAccessPolicy "Get-ADCentralAccessPolicy documentation"
[msdocs:New-ADCentralAccessPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADCentralAccessPolicy "New-ADCentralAccessPolicy documentation"
[msdocs:Remove-ADCentralAccessPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADCentralAccessPolicy "Remove-ADCentralAccessPolicy documentation"
[msdocs:Set-ADCentralAccessPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADCentralAccessPolicy "Set-ADCentralAccessPolicy documentation"
[msdocs:Add-ADCentralAccessPolicyMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADCentralAccessPolicyMember "Add-ADCentralAccessPolicyMember documentation"
[msdocs:Remove-ADCentralAccessPolicyMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADCentralAccessPolicyMember "Remove-ADCentralAccessPolicyMember documentation"
[msdocs:Get-ADCentralAccessRule]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADCentralAccessRule "Get-ADCentralAccessRule documentation"
[msdocs:New-ADCentralAccessRule]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADCentralAccessRule "New-ADCentralAccessRule documentation"
[msdocs:Remove-ADCentralAccessRule]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADCentralAccessRule "Remove-ADCentralAccessRule documentation"
[msdocs:Set-ADCentralAccessRule]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADCentralAccessRule "Set-ADCentralAccessRule documentation"
[msdocs:Clear-ADClaimTransformLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Clear-ADClaimTransformLink "Clear-ADClaimTransformLink documentation"
[msdocs:Set-ADClaimTransformLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADClaimTransformLink "Set-ADClaimTransformLink documentation"
[msdocs:Get-ADClaimTransformPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADClaimTransformPolicy "Get-ADClaimTransformPolicy documentation"
[msdocs:New-ADClaimTransformPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADClaimTransformPolicy "New-ADClaimTransformPolicy documentation"
[msdocs:Remove-ADClaimTransformPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADClaimTransformPolicy "Remove-ADClaimTransformPolicy documentation"
[msdocs:Set-ADClaimTransformPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADClaimTransformPolicy "Set-ADClaimTransformPolicy documentation"
[msdocs:Get-ADClaimType]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADClaimType "Get-ADClaimType documentation"
[msdocs:New-ADClaimType]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADClaimType "New-ADClaimType documentation"
[msdocs:Remove-ADClaimType]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADClaimType "Remove-ADClaimType documentation"
[msdocs:Set-ADClaimType]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADClaimType "Set-ADClaimType documentation"
[msdocs:Get-ADComputer]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADComputer "Get-ADComputer documentation"
[msdocs:New-ADComputer]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADComputer "New-ADComputer documentation"
[msdocs:Remove-ADComputer]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADComputer "Remove-ADComputer documentation"
[msdocs:Set-ADComputer]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADComputer "Set-ADComputer documentation"
[msdocs:Add-ADComputerServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADComputerServiceAccount "Add-ADComputerServiceAccount documentation"
[msdocs:Get-ADComputerServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADComputerServiceAccount "Get-ADComputerServiceAccount documentation"
[msdocs:Remove-ADComputerServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADComputerServiceAccount "Remove-ADComputerServiceAccount documentation"
[msdocs:New-ADDCCloneConfigFile]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADDCCloneConfigFile "New-ADDCCloneConfigFile documentation"
[msdocs:Get-ADDCCloningExcludedApplicationList]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDCCloningExcludedApplicationList "Get-ADDCCloningExcludedApplicationList documentation"
[msdocs:Get-ADDefaultDomainPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDefaultDomainPasswordPolicy "Get-ADDefaultDomainPasswordPolicy documentation"
[msdocs:Set-ADDefaultDomainPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADDefaultDomainPasswordPolicy "Set-ADDefaultDomainPasswordPolicy documentation"
[msdocs:Move-ADDirectoryServer]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Move-ADDirectoryServer "Move-ADDirectoryServer documentation"
[msdocs:Move-ADDirectoryServerOperationMasterRole]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Move-ADDirectoryServerOperationMasterRole "Move-ADDirectoryServerOperationMasterRole documentation"
[msdocs:Get-ADDomain]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDomain "Get-ADDomain documentation"
[msdocs:Set-ADDomain]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADDomain "Set-ADDomain documentation"
[msdocs:Get-ADDomainController]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDomainController "Get-ADDomainController documentation"
[msdocs:Add-ADDomainControllerPasswordReplicationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADDomainControllerPasswordReplicationPolicy "Add-ADDomainControllerPasswordReplicationPolicy documentation"
[msdocs:Get-ADDomainControllerPasswordReplicationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDomainControllerPasswordReplicationPolicy "Get-ADDomainControllerPasswordReplicationPolicy documentation"
[msdocs:Remove-ADDomainControllerPasswordReplicationPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADDomainControllerPasswordReplicationPolicy "Remove-ADDomainControllerPasswordReplicationPolicy documentation"
[msdocs:Get-ADDomainControllerPasswordReplicationPolicyUsage]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADDomainControllerPasswordReplicationPolicyUsage "Get-ADDomainControllerPasswordReplicationPolicyUsage documentation"
[msdocs:Set-ADDomainMode]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADDomainMode "Set-ADDomainMode documentation"
[msdocs:Get-ADFineGrainedPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADFineGrainedPasswordPolicy "Get-ADFineGrainedPasswordPolicy documentation"
[msdocs:New-ADFineGrainedPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADFineGrainedPasswordPolicy "New-ADFineGrainedPasswordPolicy documentation"
[msdocs:Remove-ADFineGrainedPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADFineGrainedPasswordPolicy "Remove-ADFineGrainedPasswordPolicy documentation"
[msdocs:Set-ADFineGrainedPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADFineGrainedPasswordPolicy "Set-ADFineGrainedPasswordPolicy documentation"
[msdocs:Add-ADFineGrainedPasswordPolicySubject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADFineGrainedPasswordPolicySubject "Add-ADFineGrainedPasswordPolicySubject documentation"
[msdocs:Get-ADFineGrainedPasswordPolicySubject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADFineGrainedPasswordPolicySubject "Get-ADFineGrainedPasswordPolicySubject documentation"
[msdocs:Remove-ADFineGrainedPasswordPolicySubject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADFineGrainedPasswordPolicySubject "Remove-ADFineGrainedPasswordPolicySubject documentation"
[msdocs:Get-ADForest]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADForest "Get-ADForest documentation"
[msdocs:Set-ADForest]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADForest "Set-ADForest documentation"
[msdocs:Set-ADForestMode]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADForestMode "Set-ADForestMode documentation"
[msdocs:Get-ADGroup]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADGroup "Get-ADGroup documentation"
[msdocs:New-ADGroup]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADGroup "New-ADGroup documentation"
[msdocs:Remove-ADGroup]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADGroup "Remove-ADGroup documentation"
[msdocs:Set-ADGroup]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADGroup "Set-ADGroup documentation"
[msdocs:Add-ADGroupMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADGroupMember "Add-ADGroupMember documentation"
[msdocs:Get-ADGroupMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADGroupMember "Get-ADGroupMember documentation"
[msdocs:Remove-ADGroupMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADGroupMember "Remove-ADGroupMember documentation"
[msdocs:Move-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Move-ADObject "Move-ADObject documentation"
[msdocs:New-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADObject "New-ADObject documentation"
[msdocs:Remove-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADObject "Remove-ADObject documentation"
[msdocs:Rename-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Rename-ADObject "Rename-ADObject documentation"
[msdocs:Restore-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Restore-ADObject "Restore-ADObject documentation"
[msdocs:Set-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADObject "Set-ADObject documentation"
[msdocs:Sync-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Sync-ADObject "Sync-ADObject documentation"
[msdocs:Get-ADObject]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADObject "Get-ADObject documentation"
[msdocs:Disable-ADOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Disable-ADOptionalFeature "Disable-ADOptionalFeature documentation"
[msdocs:Enable-ADOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Enable-ADOptionalFeature "Enable-ADOptionalFeature documentation"
[msdocs:Get-ADOptionalFeature]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADOptionalFeature "Get-ADOptionalFeature documentation"
[msdocs:Get-ADOrganizationalUnit]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADOrganizationalUnit "Get-ADOrganizationalUnit documentation"
[msdocs:New-ADOrganizationalUnit]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADOrganizationalUnit "New-ADOrganizationalUnit documentation"
[msdocs:Remove-ADOrganizationalUnit]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADOrganizationalUnit "Remove-ADOrganizationalUnit documentation"
[msdocs:Set-ADOrganizationalUnit]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADOrganizationalUnit "Set-ADOrganizationalUnit documentation"
[msdocs:Add-ADPrincipalGroupMembership]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADPrincipalGroupMembership "Add-ADPrincipalGroupMembership documentation"
[msdocs:Get-ADPrincipalGroupMembership]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADPrincipalGroupMembership "Get-ADPrincipalGroupMembership documentation"
[msdocs:Remove-ADPrincipalGroupMembership]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADPrincipalGroupMembership "Remove-ADPrincipalGroupMembership documentation"
[msdocs:Get-ADReplicationAttributeMetadata]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationAttributeMetadata "Get-ADReplicationAttributeMetadata documentation"
[msdocs:Get-ADReplicationConnection]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationConnection "Get-ADReplicationConnection documentation"
[msdocs:Set-ADReplicationConnection]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADReplicationConnection "Set-ADReplicationConnection documentation"
[msdocs:Get-ADReplicationFailure]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationFailure "Get-ADReplicationFailure documentation"
[msdocs:Get-ADReplicationPartnerMetadata]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationPartnerMetadata "Get-ADReplicationPartnerMetadata documentation"
[msdocs:Get-ADReplicationQueueOperation]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationQueueOperation "Get-ADReplicationQueueOperation documentation"
[msdocs:Get-ADReplicationSite]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationSite "Get-ADReplicationSite documentation"
[msdocs:New-ADReplicationSite]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADReplicationSite "New-ADReplicationSite documentation"
[msdocs:Remove-ADReplicationSite]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADReplicationSite "Remove-ADReplicationSite documentation"
[msdocs:Set-ADReplicationSite]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADReplicationSite "Set-ADReplicationSite documentation"
[msdocs:Get-ADReplicationSiteLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationSiteLink "Get-ADReplicationSiteLink documentation"
[msdocs:New-ADReplicationSiteLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADReplicationSiteLink "New-ADReplicationSiteLink documentation"
[msdocs:Remove-ADReplicationSiteLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADReplicationSiteLink "Remove-ADReplicationSiteLink documentation"
[msdocs:Set-ADReplicationSiteLink]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADReplicationSiteLink "Set-ADReplicationSiteLink documentation"
[msdocs:Get-ADReplicationSiteLinkBridge]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationSiteLinkBridge "Get-ADReplicationSiteLinkBridge documentation"
[msdocs:New-ADReplicationSiteLinkBridge]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADReplicationSiteLinkBridge "New-ADReplicationSiteLinkBridge documentation"
[msdocs:Remove-ADReplicationSiteLinkBridge]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADReplicationSiteLinkBridge "Remove-ADReplicationSiteLinkBridge documentation"
[msdocs:Set-ADReplicationSiteLinkBridge]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADReplicationSiteLinkBridge "Set-ADReplicationSiteLinkBridge documentation"
[msdocs:Get-ADReplicationSubnet]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationSubnet "Get-ADReplicationSubnet documentation"
[msdocs:New-ADReplicationSubnet]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADReplicationSubnet "New-ADReplicationSubnet documentation"
[msdocs:Remove-ADReplicationSubnet]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADReplicationSubnet "Remove-ADReplicationSubnet documentation"
[msdocs:Set-ADReplicationSubnet]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADReplicationSubnet "Set-ADReplicationSubnet documentation"
[msdocs:Get-ADReplicationUpToDatenessVectorTable]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADReplicationUpToDatenessVectorTable "Get-ADReplicationUpToDatenessVectorTable documentation"
[msdocs:Get-ADResourceProperty]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADResourceProperty "Get-ADResourceProperty documentation"
[msdocs:New-ADResourceProperty]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADResourceProperty "New-ADResourceProperty documentation"
[msdocs:Remove-ADResourceProperty]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADResourceProperty "Remove-ADResourceProperty documentation"
[msdocs:Set-ADResourceProperty]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADResourceProperty "Set-ADResourceProperty documentation"
[msdocs:Get-ADResourcePropertyList]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADResourcePropertyList "Get-ADResourcePropertyList documentation"
[msdocs:New-ADResourcePropertyList]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADResourcePropertyList "New-ADResourcePropertyList documentation"
[msdocs:Remove-ADResourcePropertyList]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADResourcePropertyList "Remove-ADResourcePropertyList documentation"
[msdocs:Set-ADResourcePropertyList]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADResourcePropertyList "Set-ADResourcePropertyList documentation"
[msdocs:Add-ADResourcePropertyListMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Add-ADResourcePropertyListMember "Add-ADResourcePropertyListMember documentation"
[msdocs:Remove-ADResourcePropertyListMember]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADResourcePropertyListMember "Remove-ADResourcePropertyListMember documentation"
[msdocs:Get-ADResourcePropertyValueType]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADResourcePropertyValueType "Get-ADResourcePropertyValueType documentation"
[msdocs:Get-ADRootDSE]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADRootDSE "Get-ADRootDSE documentation"
[msdocs:Get-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADServiceAccount "Get-ADServiceAccount documentation"
[msdocs:Install-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Install-ADServiceAccount "Install-ADServiceAccount documentation"
[msdocs:New-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADServiceAccount "New-ADServiceAccount documentation"
[msdocs:Remove-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADServiceAccount "Remove-ADServiceAccount documentation"
[msdocs:Set-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADServiceAccount "Set-ADServiceAccount documentation"
[msdocs:Test-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Test-ADServiceAccount "Test-ADServiceAccount documentation"
[msdocs:Uninstall-ADServiceAccount]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Uninstall-ADServiceAccount "Uninstall-ADServiceAccount documentation"
[msdocs:Reset-ADServiceAccountPassword]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Reset-ADServiceAccountPassword "Reset-ADServiceAccountPassword documentation"
[msdocs:Get-ADTrust]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADTrust "Get-ADTrust documentation"
[msdocs:Get-ADUser]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADUser "Get-ADUser documentation"
[msdocs:New-ADUser]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/New-ADUser "New-ADUser documentation"
[msdocs:Remove-ADUser]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Remove-ADUser "Remove-ADUser documentation"
[msdocs:Set-ADUser]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Set-ADUser "Set-ADUser documentation"
[msdocs:Get-ADUserResultantPasswordPolicy]: https://docs.microsoft.com/en-us/powershell/module/addsadministration/Get-ADUserResultantPasswordPolicy "Get-ADUserResultantPasswordPolicy documentation"

[Disable-ADAccount]: #disable-adaccount '```&#10;[PS] Disable-ADAccount&#10;```&#10;Disables an Active Directory account.'
[Enable-ADAccount]: #enable-adaccount '```&#10;[PS] Enable-ADAccount&#10;```&#10;Enables an Active Directory account.'
[Search-ADAccount]: #search-adaccount '```&#10;[PS] Search-ADAccount&#10;```&#10;Gets Active Directory user, computer, or service accounts.'
[Unlock-ADAccount]: #unlock-adaccount '```&#10;[PS] Unlock-ADAccount&#10;```&#10;Unlocks an Active Directory account.'
[Set-ADAccountAuthenticationPolicySilo]: #set-adaccountauthenticationpolicysilo '```&#10;[PS] Set-ADAccountAuthenticationPolicySilo&#10;```&#10;Modifies the authentication policy or authentication policy silo of an account.'
[Get-ADAccountAuthorizationGroup]: #get-adaccountauthorizationgroup '```&#10;[PS] Get-ADAccountAuthorizationGroup&#10;```&#10;Gets the accounts token group information.'
[Set-ADAccountControl]: #set-adaccountcontrol '```&#10;[PS] Set-ADAccountControl&#10;```&#10;Modifies user account control (UAC) values for an Active Directory account.'
[Clear-ADAccountExpiration]: #clear-adaccountexpiration '```&#10;[PS] Clear-ADAccountExpiration&#10;```&#10;Clears the expiration date for an Active Directory account.'
[Set-ADAccountExpiration]: #set-adaccountexpiration '```&#10;[PS] Set-ADAccountExpiration&#10;```&#10;Sets the expiration date for an Active Directory account.'
[Set-ADAccountPassword]: #set-adaccountpassword '```&#10;[PS] Set-ADAccountPassword&#10;```&#10;Modifies the password of an Active Directory account.'
[Get-ADAccountResultantPasswordReplicationPolicy]: #get-adaccountresultantpasswordreplicationpolicy '```&#10;[PS] Get-ADAccountResultantPasswordReplicationPolicy&#10;```&#10;Gets the resultant password replication policy for an Active Directory account.'
[Get-ADAuthenticationPolicy]: #get-adauthenticationpolicy '```&#10;[PS] Get-ADAuthenticationPolicy&#10;```&#10;Gets one or more Active Directory Domain Services authentication policies.'
[New-ADAuthenticationPolicy]: #new-adauthenticationpolicy '```&#10;[PS] New-ADAuthenticationPolicy&#10;```&#10;Creates an Active Directory Domain Services authentication policy object.'
[Remove-ADAuthenticationPolicy]: #remove-adauthenticationpolicy '```&#10;[PS] Remove-ADAuthenticationPolicy&#10;```&#10;Removes an Active Directory Domain Services authentication policy object.'
[Set-ADAuthenticationPolicy]: #set-adauthenticationpolicy '```&#10;[PS] Set-ADAuthenticationPolicy&#10;```&#10;Modifies an Active Directory Domain Services authentication policy object.'
[Show-ADAuthenticationPolicyExpression]: #show-adauthenticationpolicyexpression '```&#10;[PS] Show-ADAuthenticationPolicyExpression&#10;```&#10;Displays the Edit Access Control Conditions window update or create security descriptor definition language (SDDL) security descriptors.'
[Get-ADAuthenticationPolicySilo]: #get-adauthenticationpolicysilo '```&#10;[PS] Get-ADAuthenticationPolicySilo&#10;```&#10;Gets one or more Active Directory Domain Services authentication policy silos.'
[New-ADAuthenticationPolicySilo]: #new-adauthenticationpolicysilo '```&#10;[PS] New-ADAuthenticationPolicySilo&#10;```&#10;Creates an Active Directory Domain Services authentication policy silo object.'
[Remove-ADAuthenticationPolicySilo]: #remove-adauthenticationpolicysilo '```&#10;[PS] Remove-ADAuthenticationPolicySilo&#10;```&#10;Removes an Active Directory Domain Services authentication policy silo object.'
[Set-ADAuthenticationPolicySilo]: #set-adauthenticationpolicysilo '```&#10;[PS] Set-ADAuthenticationPolicySilo&#10;```&#10;Modifies an Active Directory Domain Services authentication policy silo object.'
[Grant-ADAuthenticationPolicySiloAccess]: #grant-adauthenticationpolicysiloaccess '```&#10;[PS] Grant-ADAuthenticationPolicySiloAccess&#10;```&#10;Grants permission to join an authentication policy silo.'
[Revoke-ADAuthenticationPolicySiloAccess]: #revoke-adauthenticationpolicysiloaccess '```&#10;[PS] Revoke-ADAuthenticationPolicySiloAccess&#10;```&#10;Revokes membership in an authentication policy silo for the specified account.'
[Get-ADCentralAccessPolicy]: #get-adcentralaccesspolicy '```&#10;[PS] Get-ADCentralAccessPolicy&#10;```&#10;Retrieves central access policies from Active Directory.'
[New-ADCentralAccessPolicy]: #new-adcentralaccesspolicy '```&#10;[PS] New-ADCentralAccessPolicy&#10;```&#10;Creates a new central access policy in Active Directory containing a set of central access rules.'
[Remove-ADCentralAccessPolicy]: #remove-adcentralaccesspolicy '```&#10;[PS] Remove-ADCentralAccessPolicy&#10;```&#10;Removes a central access policy from Active Directory.'
[Set-ADCentralAccessPolicy]: #set-adcentralaccesspolicy '```&#10;[PS] Set-ADCentralAccessPolicy&#10;```&#10;Modifies a central access policy in Active Directory.'
[Add-ADCentralAccessPolicyMember]: #add-adcentralaccesspolicymember '```&#10;[PS] Add-ADCentralAccessPolicyMember&#10;```&#10;Adds central access rules to a central access policy in Active Directory.'
[Remove-ADCentralAccessPolicyMember]: #remove-adcentralaccesspolicymember '```&#10;[PS] Remove-ADCentralAccessPolicyMember&#10;```&#10;Removes central access rules from a central access policy in Active Directory.'
[Get-ADCentralAccessRule]: #get-adcentralaccessrule '```&#10;[PS] Get-ADCentralAccessRule&#10;```&#10;Retrieves central access rules from Active Directory.'
[New-ADCentralAccessRule]: #new-adcentralaccessrule '```&#10;[PS] New-ADCentralAccessRule&#10;```&#10;Creates a central access rule in Active Directory.'
[Remove-ADCentralAccessRule]: #remove-adcentralaccessrule '```&#10;[PS] Remove-ADCentralAccessRule&#10;```&#10;Removes a central access rule from Active Directory.'
[Set-ADCentralAccessRule]: #set-adcentralaccessrule '```&#10;[PS] Set-ADCentralAccessRule&#10;```&#10;Modifies a central access rule in Active Directory.'
[Clear-ADClaimTransformLink]: #clear-adclaimtransformlink '```&#10;[PS] Clear-ADClaimTransformLink&#10;```&#10;Removes a claims transformation from being applied to one or more cross-forest trust relationships in Active Directory.'
[Set-ADClaimTransformLink]: #set-adclaimtransformlink '```&#10;[PS] Set-ADClaimTransformLink&#10;```&#10;Applies a claims transformation to one or more cross-forest trust relationships in Active Directory.'
[Get-ADClaimTransformPolicy]: #get-adclaimtransformpolicy '```&#10;[PS] Get-ADClaimTransformPolicy&#10;```&#10;Returns one or more Active Directory claim transform objects based on a specified filter.'
[New-ADClaimTransformPolicy]: #new-adclaimtransformpolicy '```&#10;[PS] New-ADClaimTransformPolicy&#10;```&#10;Creates a new claim transformation policy object in Active Directory.'
[Remove-ADClaimTransformPolicy]: #remove-adclaimtransformpolicy '```&#10;[PS] Remove-ADClaimTransformPolicy&#10;```&#10;Removes a claim transformation policy object from Active Directory.'
[Set-ADClaimTransformPolicy]: #set-adclaimtransformpolicy '```&#10;[PS] Set-ADClaimTransformPolicy&#10;```&#10;Sets the properties of a claims transformation policy in Active Directory.'
[Get-ADClaimType]: #get-adclaimtype '```&#10;[PS] Get-ADClaimType&#10;```&#10;Returns a claim type from Active Directory.'
[New-ADClaimType]: #new-adclaimtype '```&#10;[PS] New-ADClaimType&#10;```&#10;Creates a new claim type in Active Directory.'
[Remove-ADClaimType]: #remove-adclaimtype '```&#10;[PS] Remove-ADClaimType&#10;```&#10;Removes a claim type from Active Directory.'
[Set-ADClaimType]: #set-adclaimtype '```&#10;[PS] Set-ADClaimType&#10;```&#10;Modify a claim type in Active Directory.'
[Get-ADComputer]: #get-adcomputer '```&#10;[PS] Get-ADComputer&#10;```&#10;Gets one or more Active Directory computers.'
[New-ADComputer]: #new-adcomputer '```&#10;[PS] New-ADComputer&#10;```&#10;Creates a new Active Directory computer object.'
[Remove-ADComputer]: #remove-adcomputer '```&#10;[PS] Remove-ADComputer&#10;```&#10;Removes an Active Directory computer.'
[Set-ADComputer]: #set-adcomputer '```&#10;[PS] Set-ADComputer&#10;```&#10;Modifies an Active Directory computer object.'
[Add-ADComputerServiceAccount]: #add-adcomputerserviceaccount '```&#10;[PS] Add-ADComputerServiceAccount&#10;```&#10;Adds one or more service accounts to an Active Directory computer.'
[Get-ADComputerServiceAccount]: #get-adcomputerserviceaccount '```&#10;[PS] Get-ADComputerServiceAccount&#10;```&#10;Gets the service accounts hosted by a computer.'
[Remove-ADComputerServiceAccount]: #remove-adcomputerserviceaccount '```&#10;[PS] Remove-ADComputerServiceAccount&#10;```&#10;Removes one or more service accounts from a computer.'
[New-ADDCCloneConfigFile]: #new-addccloneconfigfile '```&#10;[PS] New-ADDCCloneConfigFile&#10;```&#10;Performs prerequisite checks for cloning a domain controller and generates a clone configuration file if all checks succeed.'
[Get-ADDCCloningExcludedApplicationList]: #get-addccloningexcludedapplicationlist '```&#10;[PS] Get-ADDCCloningExcludedApplicationList&#10;```&#10;Gets a list of installed programs and services present on this domain controller that are not in the default or user defined inclusion list.'
[Get-ADDefaultDomainPasswordPolicy]: #get-addefaultdomainpasswordpolicy '```&#10;[PS] Get-ADDefaultDomainPasswordPolicy&#10;```&#10;Gets the default password policy for an Active Directory domain.'
[Set-ADDefaultDomainPasswordPolicy]: #set-addefaultdomainpasswordpolicy '```&#10;[PS] Set-ADDefaultDomainPasswordPolicy&#10;```&#10;Modifies the default password policy for an Active Directory domain.'
[Move-ADDirectoryServer]: #move-addirectoryserver '```&#10;[PS] Move-ADDirectoryServer&#10;```&#10;Moves a directory server in Active Directory to a new site.'
[Move-ADDirectoryServerOperationMasterRole]: #move-addirectoryserveroperationmasterrole '```&#10;[PS] Move-ADDirectoryServerOperationMasterRole&#10;```&#10;Moves operation master roles to an Active Directory directory server.'
[Get-ADDomain]: #get-addomain '```&#10;[PS] Get-ADDomain&#10;```&#10;Gets an Active Directory domain.'
[Set-ADDomain]: #set-addomain '```&#10;[PS] Set-ADDomain&#10;```&#10;Modifies an Active Directory domain.'
[Get-ADDomainController]: #get-addomaincontroller '```&#10;[PS] Get-ADDomainController&#10;```&#10;Gets one or more Active Directory domain controllers based on discoverable services criteria, search parameters or by providing a domain controller identifier, such as the NetBIOS name.'
[Add-ADDomainControllerPasswordReplicationPolicy]: #add-addomaincontrollerpasswordreplicationpolicy '```&#10;[PS] Add-ADDomainControllerPasswordReplicationPolicy&#10;```&#10;Adds users, computers, and groups to the allowed or denied list of a read-only domain controller password replication policy.'
[Get-ADDomainControllerPasswordReplicationPolicy]: #get-addomaincontrollerpasswordreplicationpolicy '```&#10;[PS] Get-ADDomainControllerPasswordReplicationPolicy&#10;```&#10;Gets the members of the allowed list or denied list of the password replication policy of a read-only domain controller.'
[Remove-ADDomainControllerPasswordReplicationPolicy]: #remove-addomaincontrollerpasswordreplicationpolicy '```&#10;[PS] Remove-ADDomainControllerPasswordReplicationPolicy&#10;```&#10;Removes users, computers, and groups from the allowed or denied list of a read-only domain controller password replication policy.'
[Get-ADDomainControllerPasswordReplicationPolicyUsage]: #get-addomaincontrollerpasswordreplicationpolicyusage '```&#10;[PS] Get-ADDomainControllerPasswordReplicationPolicyUsage&#10;```&#10;Gets the Active Directory accounts that are authenticated by a read-only domain controller or that are in the revealed list of the domain controller.'
[Set-ADDomainMode]: #set-addomainmode '```&#10;[PS] Set-ADDomainMode&#10;```&#10;Sets the domain mode for an Active Directory domain.'
[Get-ADFineGrainedPasswordPolicy]: #get-adfinegrainedpasswordpolicy '```&#10;[PS] Get-ADFineGrainedPasswordPolicy&#10;```&#10;Gets one or more Active Directory fine-grained password policies.'
[New-ADFineGrainedPasswordPolicy]: #new-adfinegrainedpasswordpolicy '```&#10;[PS] New-ADFineGrainedPasswordPolicy&#10;```&#10;Creates a new Active Directory fine-grained password policy.'
[Remove-ADFineGrainedPasswordPolicy]: #remove-adfinegrainedpasswordpolicy '```&#10;[PS] Remove-ADFineGrainedPasswordPolicy&#10;```&#10;Removes an Active Directory fine-grained password policy.'
[Set-ADFineGrainedPasswordPolicy]: #set-adfinegrainedpasswordpolicy '```&#10;[PS] Set-ADFineGrainedPasswordPolicy&#10;```&#10;Modifies an Active Directory fine-grained password policy.'
[Add-ADFineGrainedPasswordPolicySubject]: #add-adfinegrainedpasswordpolicysubject '```&#10;[PS] Add-ADFineGrainedPasswordPolicySubject&#10;```&#10;Applies a fine-grained password policy to one or more users and groups.'
[Get-ADFineGrainedPasswordPolicySubject]: #get-adfinegrainedpasswordpolicysubject '```&#10;[PS] Get-ADFineGrainedPasswordPolicySubject&#10;```&#10;Gets the users and groups to which a fine-grained password policy is applied.'
[Remove-ADFineGrainedPasswordPolicySubject]: #remove-adfinegrainedpasswordpolicysubject '```&#10;[PS] Remove-ADFineGrainedPasswordPolicySubject&#10;```&#10;Removes one or more users from a fine-grained password policy.'
[Get-ADForest]: #get-adforest '```&#10;[PS] Get-ADForest&#10;```&#10;Gets an Active Directory forest.'
[Set-ADForest]: #set-adforest '```&#10;[PS] Set-ADForest&#10;```&#10;Modifies an Active Directory forest.'
[Set-ADForestMode]: #set-adforestmode '```&#10;[PS] Set-ADForestMode&#10;```&#10;Sets the forest mode for an Active Directory forest.'
[Get-ADGroup]: #get-adgroup '```&#10;[PS] Get-ADGroup&#10;```&#10;Gets one or more Active Directory groups.'
[New-ADGroup]: #new-adgroup '```&#10;[PS] New-ADGroup&#10;```&#10;Creates an Active Directory group.'
[Remove-ADGroup]: #remove-adgroup '```&#10;[PS] Remove-ADGroup&#10;```&#10;Removes an Active Directory group.'
[Set-ADGroup]: #set-adgroup '```&#10;[PS] Set-ADGroup&#10;```&#10;Modifies an Active Directory group.'
[Add-ADGroupMember]: #add-adgroupmember '```&#10;[PS] Add-ADGroupMember&#10;```&#10;Adds one or more members to an Active Directory group.'
[Get-ADGroupMember]: #get-adgroupmember '```&#10;[PS] Get-ADGroupMember&#10;```&#10;Gets the members of an Active Directory group.'
[Remove-ADGroupMember]: #remove-adgroupmember '```&#10;[PS] Remove-ADGroupMember&#10;```&#10;Removes one or more members from an Active Directory group.'
[Move-ADObject]: #move-adobject '```&#10;[PS] Move-ADObject&#10;```&#10;Moves an Active Directory object or a container of objects to a different container or domain.'
[New-ADObject]: #new-adobject '```&#10;[PS] New-ADObject&#10;```&#10;Creates an Active Directory object.'
[Remove-ADObject]: #remove-adobject '```&#10;[PS] Remove-ADObject&#10;```&#10;Removes an Active Directory object.'
[Rename-ADObject]: #rename-adobject '```&#10;[PS] Rename-ADObject&#10;```&#10;Changes the name of an Active Directory object.'
[Restore-ADObject]: #restore-adobject '```&#10;[PS] Restore-ADObject&#10;```&#10;Restores an Active Directory object.'
[Set-ADObject]: #set-adobject '```&#10;[PS] Set-ADObject&#10;```&#10;Modifies an Active Directory object.'
[Sync-ADObject]: #sync-adobject '```&#10;[PS] Sync-ADObject&#10;```&#10;Replicates a single object between any two domain controllers that have partitions in common.'
[Get-ADObject]: #get-adobject '```&#10;[PS] Get-ADObject&#10;```&#10;Gets one or more Active Directory objects.'
[Disable-ADOptionalFeature]: #disable-adoptionalfeature '```&#10;[PS] Disable-ADOptionalFeature&#10;```&#10;Disables an Active Directory optional feature.'
[Enable-ADOptionalFeature]: #enable-adoptionalfeature '```&#10;[PS] Enable-ADOptionalFeature&#10;```&#10;Enables an Active Directory optional feature.'
[Get-ADOptionalFeature]: #get-adoptionalfeature '```&#10;[PS] Get-ADOptionalFeature&#10;```&#10;Gets one or more Active Directory optional features.'
[Get-ADOrganizationalUnit]: #get-adorganizationalunit '```&#10;[PS] Get-ADOrganizationalUnit&#10;```&#10;Gets one or more Active Directory organizational units.'
[New-ADOrganizationalUnit]: #new-adorganizationalunit '```&#10;[PS] New-ADOrganizationalUnit&#10;```&#10;Creates an Active Directory organizational unit.'
[Remove-ADOrganizationalUnit]: #remove-adorganizationalunit '```&#10;[PS] Remove-ADOrganizationalUnit&#10;```&#10;Removes an Active Directory organizational unit.'
[Set-ADOrganizationalUnit]: #set-adorganizationalunit '```&#10;[PS] Set-ADOrganizationalUnit&#10;```&#10;Modifies an Active Directory organizational unit.'
[Add-ADPrincipalGroupMembership]: #add-adprincipalgroupmembership '```&#10;[PS] Add-ADPrincipalGroupMembership&#10;```&#10;Adds a member to one or more Active Directory groups.'
[Get-ADPrincipalGroupMembership]: #get-adprincipalgroupmembership '```&#10;[PS] Get-ADPrincipalGroupMembership&#10;```&#10;Gets the Active Directory groups that have a specified user, computer, group, or service account.'
[Remove-ADPrincipalGroupMembership]: #remove-adprincipalgroupmembership '```&#10;[PS] Remove-ADPrincipalGroupMembership&#10;```&#10;Removes a member from one or more Active Directory groups.'
[Get-ADReplicationAttributeMetadata]: #get-adreplicationattributemetadata '```&#10;[PS] Get-ADReplicationAttributeMetadata&#10;```&#10;Gets the replication metadata for one or more Active Directory replication partners.'
[Get-ADReplicationConnection]: #get-adreplicationconnection '```&#10;[PS] Get-ADReplicationConnection&#10;```&#10;Returns a specific Active Directory replication connection or a set of AD replication connection objects based on a specified filter.'
[Set-ADReplicationConnection]: #set-adreplicationconnection '```&#10;[PS] Set-ADReplicationConnection&#10;```&#10;Sets properties on Active Directory replication connections.'
[Get-ADReplicationFailure]: #get-adreplicationfailure '```&#10;[PS] Get-ADReplicationFailure&#10;```&#10;Returns a collection of data describing an Active Directory replication failure.'
[Get-ADReplicationPartnerMetadata]: #get-adreplicationpartnermetadata '```&#10;[PS] Get-ADReplicationPartnerMetadata&#10;```&#10;Returns the replication metadata for a set of one or more replication partners.'
[Get-ADReplicationQueueOperation]: #get-adreplicationqueueoperation '```&#10;[PS] Get-ADReplicationQueueOperation&#10;```&#10;Returns the contents of the replication queue for a specified server.'
[Get-ADReplicationSite]: #get-adreplicationsite '```&#10;[PS] Get-ADReplicationSite&#10;```&#10;Returns a specific Active Directory replication site or a set of replication site objects based on a specified filter.'
[New-ADReplicationSite]: #new-adreplicationsite '```&#10;[PS] New-ADReplicationSite&#10;```&#10;Creates an Active Directory replication site in the directory.'
[Remove-ADReplicationSite]: #remove-adreplicationsite '```&#10;[PS] Remove-ADReplicationSite&#10;```&#10;Deletes the specified replication site object from Active Directory.'
[Set-ADReplicationSite]: #set-adreplicationsite '```&#10;[PS] Set-ADReplicationSite&#10;```&#10;Sets the replication properties for an Active Directory site.'
[Get-ADReplicationSiteLink]: #get-adreplicationsitelink '```&#10;[PS] Get-ADReplicationSiteLink&#10;```&#10;Returns a specific Active Directory site link or a set of site links based on a specified filter.'
[New-ADReplicationSiteLink]: #new-adreplicationsitelink '```&#10;[PS] New-ADReplicationSiteLink&#10;```&#10;Creates a new Active Directory site link for in managing replication.'
[Remove-ADReplicationSiteLink]: #remove-adreplicationsitelink '```&#10;[PS] Remove-ADReplicationSiteLink&#10;```&#10;Deletes an Active Directory site link used to manage replication.'
[Set-ADReplicationSiteLink]: #set-adreplicationsitelink '```&#10;[PS] Set-ADReplicationSiteLink&#10;```&#10;Sets the properties for an Active Directory site link.'
[Get-ADReplicationSiteLinkBridge]: #get-adreplicationsitelinkbridge '```&#10;[PS] Get-ADReplicationSiteLinkBridge&#10;```&#10;Gets a specific Active Directory site link bridge or a set of site link bridge objects based on a specified filter.'
[New-ADReplicationSiteLinkBridge]: #new-adreplicationsitelinkbridge '```&#10;[PS] New-ADReplicationSiteLinkBridge&#10;```&#10;Creates a site link bridge in Active Directory for replication.'
[Remove-ADReplicationSiteLinkBridge]: #remove-adreplicationsitelinkbridge '```&#10;[PS] Remove-ADReplicationSiteLinkBridge&#10;```&#10;Deletes a replication site link bridge from Active Directory.'
[Set-ADReplicationSiteLinkBridge]: #set-adreplicationsitelinkbridge '```&#10;[PS] Set-ADReplicationSiteLinkBridge&#10;```&#10;Sets the properties of a replication site link bridge in Active Directory.'
[Get-ADReplicationSubnet]: #get-adreplicationsubnet '```&#10;[PS] Get-ADReplicationSubnet&#10;```&#10;Gets one or more Active Directory subnets.'
[New-ADReplicationSubnet]: #new-adreplicationsubnet '```&#10;[PS] New-ADReplicationSubnet&#10;```&#10;Creates an Active Directory replication subnet object.'
[Remove-ADReplicationSubnet]: #remove-adreplicationsubnet '```&#10;[PS] Remove-ADReplicationSubnet&#10;```&#10;Deletes the specified Active Directory replication subnet object from the directory.'
[Set-ADReplicationSubnet]: #set-adreplicationsubnet '```&#10;[PS] Set-ADReplicationSubnet&#10;```&#10;Sets the properties of an Active Directory replication subnet object.'
[Get-ADReplicationUpToDatenessVectorTable]: #get-adreplicationuptodatenessvectortable '```&#10;[PS] Get-ADReplicationUpToDatenessVectorTable&#10;```&#10;Displays the highest Update Sequence Number (USN) for the specified domain controller.'
[Get-ADResourceProperty]: #get-adresourceproperty '```&#10;[PS] Get-ADResourceProperty&#10;```&#10;Gets one or more resource properties.'
[New-ADResourceProperty]: #new-adresourceproperty '```&#10;[PS] New-ADResourceProperty&#10;```&#10;Creates a resource property in Active Directory.'
[Remove-ADResourceProperty]: #remove-adresourceproperty '```&#10;[PS] Remove-ADResourceProperty&#10;```&#10;Removes a resource property from Active Directory.'
[Set-ADResourceProperty]: #set-adresourceproperty '```&#10;[PS] Set-ADResourceProperty&#10;```&#10;Modifies a resource property in Active Directory.'
[Get-ADResourcePropertyList]: #get-adresourcepropertylist '```&#10;[PS] Get-ADResourcePropertyList&#10;```&#10;Gets resource property lists from Active Directory.'
[New-ADResourcePropertyList]: #new-adresourcepropertylist '```&#10;[PS] New-ADResourcePropertyList&#10;```&#10;Creates a resource property list in Active Directory.'
[Remove-ADResourcePropertyList]: #remove-adresourcepropertylist '```&#10;[PS] Remove-ADResourcePropertyList&#10;```&#10;Removes one or more resource property lists from Active Directory.'
[Set-ADResourcePropertyList]: #set-adresourcepropertylist '```&#10;[PS] Set-ADResourcePropertyList&#10;```&#10;Modifies a resource property list in Active Directory.'
[Add-ADResourcePropertyListMember]: #add-adresourcepropertylistmember '```&#10;[PS] Add-ADResourcePropertyListMember&#10;```&#10;Adds one or more resource properties to a resource property list in Active Directory.'
[Remove-ADResourcePropertyListMember]: #remove-adresourcepropertylistmember '```&#10;[PS] Remove-ADResourcePropertyListMember&#10;```&#10;Removes one or more resource properties from a resource property list in Active Directory.'
[Get-ADResourcePropertyValueType]: #get-adresourcepropertyvaluetype '```&#10;[PS] Get-ADResourcePropertyValueType&#10;```&#10;Gets a resource property value type from Active Directory.'
[Get-ADRootDSE]: #get-adrootdse '```&#10;[PS] Get-ADRootDSE&#10;```&#10;Gets the root of a directory server information tree.'
[Get-ADServiceAccount]: #get-adserviceaccount '```&#10;[PS] Get-ADServiceAccount&#10;```&#10;Gets one or more Active Directory managed service accounts or group managed service accounts.'
[Install-ADServiceAccount]: #install-adserviceaccount '```&#10;[PS] Install-ADServiceAccount&#10;```&#10;Installs an Active Directory managed service account on a computer or caches a group managed service account on a computer.'
[New-ADServiceAccount]: #new-adserviceaccount '```&#10;[PS] New-ADServiceAccount&#10;```&#10;Creates a new Active Directory managed service account or group managed service account object.'
[Remove-ADServiceAccount]: #remove-adserviceaccount '```&#10;[PS] Remove-ADServiceAccount&#10;```&#10;Removes an Active Directory managed service account or group managed service account object.'
[Set-ADServiceAccount]: #set-adserviceaccount '```&#10;[PS] Set-ADServiceAccount&#10;```&#10;Modifies an Active Directory managed service account or group managed service account object.'
[Test-ADServiceAccount]: #test-adserviceaccount '```&#10;[PS] Test-ADServiceAccount&#10;```&#10;Tests a managed service account from a computer.'
[Uninstall-ADServiceAccount]: #uninstall-adserviceaccount '```&#10;[PS] Uninstall-ADServiceAccount&#10;```&#10;Uninstalls an Active Directory managed service account from a computer or removes a cached group managed service account from a computer.'
[Reset-ADServiceAccountPassword]: #reset-adserviceaccountpassword '```&#10;[PS] Reset-ADServiceAccountPassword&#10;```&#10;Resets the password for a standalone managed service account.'
[Get-ADTrust]: #get-adtrust '```&#10;[PS] Get-ADTrust&#10;```&#10;Gets all trusted domain objects in the directory.'
[Get-ADUser]: #get-aduser '```&#10;[PS] Get-ADUser&#10;```&#10;Gets one or more Active Directory users.'
[New-ADUser]: #new-aduser '```&#10;[PS] New-ADUser&#10;```&#10;Creates an Active Directory user.'
[Remove-ADUser]: #remove-aduser '```&#10;[PS] Remove-ADUser&#10;```&#10;Removes an Active Directory user.'
[Set-ADUser]: #set-aduser '```&#10;[PS] Set-ADUser&#10;```&#10;Modifies an Active Directory user.'
[Get-ADUserResultantPasswordPolicy]: #get-aduserresultantpasswordpolicy '```&#10;[PS] Get-ADUserResultantPasswordPolicy&#10;```&#10;Gets the resultant password policy for a user.'

- ADAccount
[`Disable`][Disable-ADAccount]<sup>[?][msdocs:Disable-ADAccount]</sup>
[`Enable`][Enable-ADAccount]<sup>[?][msdocs:Enable-ADAccount]</sup>
[`Search`][Search-ADAccount]<sup>[?][msdocs:Search-ADAccount]</sup>
[`Unlock`][Unlock-ADAccount]<sup>[?][msdocs:Unlock-ADAccount]</sup>
- ADAccountPassword
[`Set`][Set-ADAccountPassword]<sup>[?][msdocs:Set-ADAccountPassword]</sup>
- ADForest
[`Get`][Get-ADForest]<sup>[?][msdocs:Get-ADForest]</sup>
[`Set`][Set-ADForest]<sup>[?][msdocs:Set-ADForest]</sup>
- ADGroup
[`Get`][Get-ADGroup]<sup>[?][msdocs:Get-ADGroup]</sup>
[`New`][New-ADGroup]<sup>[?][msdocs:New-ADGroup]</sup>
[`Remove`][Remove-ADGroup]<sup>[?][msdocs:Remove-ADGroup]</sup>
[`Set`][Set-ADGroup]<sup>[?][msdocs:Set-ADGroup]</sup>
- ADGroupMember
[`Add`][Add-ADGroupMember]<sup>[?][msdocs:Add-ADGroupMember]</sup>
[`Get`][Get-ADGroupMember]<sup>[?][msdocs:Get-ADGroupMember]</sup>
[`Remove`][Remove-ADGroupMember]<sup>[?][msdocs:Remove-ADGroupMember]</sup>
- ADObject
[`Move`][Move-ADObject]<sup>[?][msdocs:Move-ADObject]</sup>
[`New`][New-ADObject]<sup>[?][msdocs:New-ADObject]</sup>
[`Remove`][Remove-ADObject]<sup>[?][msdocs:Remove-ADObject]</sup>
[`Rename`][Rename-ADObject]<sup>[?][msdocs:Rename-ADObject]</sup>
[`Restore`][Restore-ADObject]<sup>[?][msdocs:Restore-ADObject]</sup>
[`Set`][Set-ADObject]<sup>[?][msdocs:Set-ADObject]</sup>
[`Sync`][Sync-ADObject]<sup>[?][msdocs:Sync-ADObject]</sup>
- ADOrganizationalUnit
[`Get`][Get-ADOrganizationalUnit]<sup>[?][msdocs:Get-ADOrganizationalUnit]</sup>
[`New`][New-ADOrganizationalUnit]<sup>[?][msdocs:New-ADOrganizationalUnit]</sup>
[`Remove`][Remove-ADOrganizationalUnit]<sup>[?][msdocs:Remove-ADOrganizationalUnit]</sup>
[`Set`][Set-ADOrganizationalUnit]<sup>[?][msdocs:Set-ADOrganizationalUnit]</sup>
- ADPrincipalGroupMembership
[`Add`][Add-ADPrincipalGroupMembership]<sup>[?][msdocs:Add-ADPrincipalGroupMembership]</sup>
[`Get`][Get-ADPrincipalGroupMembership]<sup>[?][msdocs:Get-ADPrincipalGroupMembership]</sup>
[`Remove`][Remove-ADPrincipalGroupMembership]<sup>[?][msdocs:Remove-ADPrincipalGroupMembership]</sup>
- ADUser
[`Get`][Get-ADUser]<sup>[?][msdocs:Get-ADUser]</sup>
[`New`][New-ADUser]<sup>[?][msdocs:New-ADUser]</sup>
[`Remove`][Remove-ADUser]<sup>[?][msdocs:Remove-ADUser]</sup>
[`Set`][Set-ADUser]<sup>[?][msdocs:Set-ADUser]</sup>
#### dcbqos
[msdocs:Enable-NetQosFlowControl]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Enable-NetQosFlowControl "Enable-NetQosFlowControl"
[msdocs:Disable-NetQosFlowControl]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Disable-NetQosFlowControl "Disable-NetQosFlowControl"
[msdocs:Get-NetQosDcbxSetting]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Get-NetQosDcbxSetting "Get-NetQosDcbxSetting"
[msdocs:Get-NetQosFlowControl]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Get-NetQosFlowControl "Get-NetQosFlowControl"
[msdocs:Get-NetQosTrafficClass]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Get-NetQosTrafficClass "Get-NetQosTrafficClass"
[msdocs:New-NetQosTrafficClass]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/New-NetQosTrafficClass "New-NetQosTrafficClass"
[msdocs:Remove-NetQosTrafficClass]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Remove-NetQosTrafficClass "Remove-NetQosTrafficClass"
[msdocs:Set-NetQosDcbxSetting]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Set-NetQosDcbxSetting "Set-NetQosDcbxSetting"
[msdocs:Set-NetQosFlowControl]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Set-NetQosFlowControl "Set-NetQosFlowControl"
[msdocs:Set-NetQosTrafficClass]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Set-NetQosTrafficClass "Set-NetQosTrafficClass"
[msdocs:Switch-NetQosDcbxSetting]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Switch-NetQosDcbxSetting "Switch-NetQosDcbxSetting"
[msdocs:Switch-NetQosFlowControl]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Switch-NetQosFlowControl "Switch-NetQosFlowControl"
[msdocs:Switch-NetQosTrafficClass]: https://docs.microsoft.com/en-us/powershell/module/dcbqos/Switch-NetQosTrafficClass "Switch-NetQosTrafficClass"

[Get-NetQosDcbxSetting]: #get-netqosdcbxsetting '```&#10;Get-NetQosDcbxSetting&#10;```&#10;Gets data center bridging exchange settings.'
[Set-NetQosDcbxSetting]: #set-netqosdcbxsetting '```&#10;Set-NetQosDcbxSetting&#10;```&#10;Sets the data center bridging exchange settings.'
[Switch-NetQosDcbxSetting]: #switch-netqosdcbxsetting '```&#10;Switch-NetQosDcbxSetting&#10;```&#10;'
[Enable-NetQosFlowControl]: #enable-netqosflowcontrol '```&#10;Enable-NetQosFlowControl&#10;```&#10;Enables link level flow control based on the IEEE 802.1p priority.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 145'
[Disable-NetQosFlowControl]: #disable-netqosflowcontrol '```&#10;Disable-NetQosFlowControl&#10;```&#10;Disables link level flow control based on the IEEE 802.1p priority.'
[Get-NetQosFlowControl]: #get-netqosflowcontrol '```&#10;Get-NetQosFlowControl&#10;```&#10;Gets the priority-based flow control settings.'
[Set-NetQosFlowControl]: #set-netqosflowcontrol '```&#10;Set-NetQosFlowControl&#10;```&#10;Sets the flow control settings.'
[Switch-NetQosFlowControl]: #switch-netqosflowcontrol '```&#10;Switch-NetQosFlowControl&#10;```&#10;'
[Get-NetQosTrafficClass]: #get-netqostrafficclass '```&#10;Get-NetQosTrafficClass&#10;```&#10;Gets the traffic class settings.'
[New-NetQosTrafficClass]: #new-netqostrafficclass '```&#10;New-NetQosTrafficClass&#10;```&#10;Creates a traffic class.'
[Remove-NetQosTrafficClass]: #remove-netqostrafficclass '```&#10;Remove-NetQosTrafficClass&#10;```&#10;Removes a traffic class.'
[Set-NetQosTrafficClass]: #set-netqostrafficclass '```&#10;Set-NetQosTrafficClass&#10;```&#10;Sets the traffic class settings.'
[Switch-NetQosTrafficClass]: #switch-netqostrafficclass '```&#10;Switch-NetQosTrafficClass&#10;```&#10;'

- NetQoSDcbxSetting 
`Get`<sup>[?][msdocs:Get-NetQosDcbxSetting]</sup>
[`Set`][Set-NetQosDcbxSetting]<sup>[?][msdocs:Set-NetQosDcbxSetting]</sup>
`Switch`<sup>[?][msdocs:Switch-NetQosDcbxSetting]</sup>
- NetQoSFlowControl
`Enable`<sup>[?][msdocs:Enable-NetQosFlowControl]</sup>
`Disable`<sup>[?][msdocs:Disable-NetQosFlowControl]</sup>
`Get`<sup>[?][msdocs:Get-NetQosFlowControl]</sup>
`Set`<sup>[?][msdocs:Set-NetQosFlowControl]</sup>
`Switch`<sup>[?][msdocs:Switch-NetQosFlowControl]</sup>
- NetQoSTrafficClass
`Get`<sup>[?][msdocs:Get-NetQosTrafficClass]</sup>
`New`<sup>[?][msdocs:New-NetQosTrafficClass]</sup>
`Remove`<sup>[?][msdocs:Remove-NetQosTrafficClass]</sup>
`Set`<sup>[?][msdocs:Set-NetQosTrafficClass]</sup>
`Switch`<sup>[?][msdocs:Switch-NetQosTrafficClass]</sup>
#### deduplication
[msdocs:Disable-DedupVolume]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Disable-DedupVolume "Disable-DedupVolume"
[msdocs:Enable-DedupVolume]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Enable-DedupVolume "Enable-DedupVolume"
[msdocs:Expand-DedupFile]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Expand-DedupFile "Expand-DedupFile"
[msdocs:Get-DedupJob]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Get-DedupJob "Get-DedupJob"
[msdocs:Get-DedupMetadata]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Get-DedupMetadata "Get-DedupMetadata"
[msdocs:Get-DedupSchedule]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Get-DedupSchedule "Get-DedupSchedule"
[msdocs:Get-DedupStatus]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Get-DedupStatus "Get-DedupStatus"
[msdocs:Get-DedupVolume]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Get-DedupVolume "Get-DedupVolume"
[msdocs:Measure-DedupFileMetadata]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Measure-DedupFileMetadata "Measure-DedupFileMetadata"
[msdocs:New-DedupSchedule]: https://docs.microsoft.com/en-us/powershell/module/deduplication/New-DedupSchedule "New-DedupSchedule"
[msdocs:Remove-DedupSchedule]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Remove-DedupSchedule "Remove-DedupSchedule"
[msdocs:Set-DedupSchedule]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Set-DedupSchedule "Set-DedupSchedule"
[msdocs:Set-DedupVolume]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Set-DedupVolume "Set-DedupVolume"
[msdocs:Start-DedupJob]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Start-DedupJob "Start-DedupJob"
[msdocs:Stop-DedupJob]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Stop-DedupJob "Stop-DedupJob"
[msdocs:Update-DedupStatus]: https://docs.microsoft.com/en-us/powershell/module/deduplication/Update-DedupStatus "Update-DedupStatus"

[Expand-DedupFile]: #expand-dedupfile '```&#10;Expand-DedupFile&#10;```&#10;Expands an optimized file into its original location.'
[Measure-DedupFileMetadata]: #measure-dedupfilemetadata '```&#10;Measure-DedupFileMetadata&#10;```&#10;Measures potential disk space on a volume.'
[Get-DedupJob]: #get-dedupjob '```&#10;Get-DedupJob&#10;```&#10;Returns status and information for currently running or queued deduplication jobs.'
[Start-DedupJob]: #start-dedupjob '```&#10;Start-DedupJob&#10;```&#10;Starts a data deduplication job.'
[Stop-DedupJob]: #stop-dedupjob '```&#10;Stop-DedupJob&#10;```&#10;Cancels one or more specified data deduplication jobs.'
[Get-DedupMetadata]: #get-dedupmetadata '```&#10;Get-DedupMetadata&#10;```&#10;Returns metadata for volumes that have data deduplication metadata.'
[Get-DedupSchedule]: #get-dedupschedule '```&#10;Get-DedupSchedule&#10;```&#10;Returns the deduplication job schedule defined on the computer.'
[New-DedupSchedule]: #new-dedupschedule '```&#10;New-DedupSchedule&#10;```&#10;Creates a data deduplication schedule.'
[Remove-DedupSchedule]: #remove-dedupschedule '```&#10;Remove-DedupSchedule&#10;```&#10;Deletes a deduplication schedule.'
[Set-DedupSchedule]: #set-dedupschedule '```&#10;Set-DedupSchedule&#10;```&#10;Changes configuration settings for data deduplication schedules.'
[Get-DedupStatus]: #get-dedupstatus '```&#10;Get-DedupStatus&#10;```&#10;Returns deduplication status for volumes that have data deduplication metadata.'
[Update-DedupStatus]: #update-dedupstatus '```&#10;Update-DedupStatus&#10;```&#10;Scans volumes for fresh data deduplication savings.'
[Disable-DedupVolume]: #disable-dedupvolume '```&#10;Disable-DedupVolume&#10;```&#10;Disables data deduplication activity on one or more volumes.'
[Enable-DedupVolume]: #enable-dedupvolume '```&#10;Enable-DedupVolume&#10;```&#10;Enables data deduplication on one or more volumes.'
[Get-DedupVolume]: #get-dedupvolume '```&#10;Get-DedupVolume&#10;```&#10;Returns deduplication volumes that have data deduplication metadata.'
[Set-DedupVolume]: #set-dedupvolume '```&#10;Set-DedupVolume&#10;```&#10;Changes data deduplication settings on one or more volumes.'

- DedupVolume [Disable][Disable-DedupVolume]<sup>[?][msdocs:Disable-DedupVolume]</sup> [Enable][Enable-DedupVolume]<sup>[?][msdocs:Enable-DedupVolume]</sup>
#### defender
[msdocs:Add-MpPreference]: https://docs.microsoft.com/en-us/powershell/module/defender/Add-MpPreference "Add-MpPreference"
[msdocs:Get-MpComputerStatus]: https://docs.microsoft.com/en-us/powershell/module/defender/Get-MpComputerStatus "Get-MpComputerStatus"
[msdocs:Get-MpPreference]: https://docs.microsoft.com/en-us/powershell/module/defender/Get-MpPreference "Get-MpPreference"
[msdocs:Get-MpThreat]: https://docs.microsoft.com/en-us/powershell/module/defender/Get-MpThreat "Get-MpThreat"
[msdocs:Get-MpThreatCatalog]: https://docs.microsoft.com/en-us/powershell/module/defender/Get-MpThreatCatalog "Get-MpThreatCatalog"
[msdocs:Get-MpThreatDetection]: https://docs.microsoft.com/en-us/powershell/module/defender/Get-MpThreatDetection "Get-MpThreatDetection"
[msdocs:Remove-MpPreference]: https://docs.microsoft.com/en-us/powershell/module/defender/Remove-MpPreference "Remove-MpPreference"
[msdocs:Remove-MpThreat]: https://docs.microsoft.com/en-us/powershell/module/defender/Remove-MpThreat "Remove-MpThreat"
[msdocs:Set-MpPreference]: https://docs.microsoft.com/en-us/powershell/module/defender/Set-MpPreference "Set-MpPreference"
[msdocs:Start-MpScan]: https://docs.microsoft.com/en-us/powershell/module/defender/Start-MpScan "Start-MpScan"
[msdocs:Start-MpWDOScan]: https://docs.microsoft.com/en-us/powershell/module/defender/Start-MpWDOScan "Start-MpWDOScan"
[msdocs:Update-MpSignature]: https://docs.microsoft.com/en-us/powershell/module/defender/Update-MpSignature "Update-MpSignature"

[Add-MpPreference]: #add-mppreference '```&#10;Add-MpPreference&#10;```&#10;Modifies settings for Windows Defender.'
[Get-MpComputerStatus]: #get-mpcomputerstatus '```&#10;Get-MpComputerStatus&#10;```&#10;Gets the status of antimalware software on the computer.'
[Get-MpPreference]: #get-mppreference '```&#10;Get-MpPreference&#10;```&#10;Gets preferences for the Windows Defender scans and updates.'
[Get-MpThreat]: #get-mpthreat '```&#10;Get-MpThreat&#10;```&#10;Gets the history of threats detected on the computer.'
[Get-MpThreatCatalog]: #get-mpthreatcatalog '```&#10;Get-MpThreatCatalog&#10;```&#10;Gets known threats from the definitions catalog.'
[Get-MpThreatDetection]: #get-mpthreatdetection '```&#10;Get-MpThreatDetection&#10;```&#10;Gets active and past malware threats that Windows Defender detected.'
[Remove-MpPreference]: #remove-mppreference '```&#10;Remove-MpPreference&#10;```&#10;Removes exclusions or default actions.'
[Remove-MpThreat]: #remove-mpthreat '```&#10;Remove-MpThreat&#10;```&#10;Removes active threats from a computer.'
[Set-MpPreference]: #set-mppreference '```&#10;Set-MpPreference&#10;```&#10;Configures preferences for Windows Defender scans and updates.'
[Start-MpScan]: #start-mpscan '```&#10;Start-MpScan&#10;```&#10;Starts a scan on a computer.'
[Start-MpWDOScan]: #start-mpwdoscan '```&#10;Start-MpWDOScan&#10;```&#10;Starts a Windows Defender offline scan.'
[Update-MpSignature]: #update-mpsignature '```&#10;Update-MpSignature&#10;```&#10;Updates the antimalware definitions on a computer.'

- MpScan [`Start`][Start-MpScan]<sup>[?][msdocs:Start-MpScan]</sup>
- MpThreat [`Get`][Get-MpThreat]<sup>[?][msdocs:Get-MpThreat]</sup> [`Remove`][Remove-MpThreat]<sup>[?][msdocs:Remove-MpThreat]</sup>
#### dism
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

[Add-AppxProvisionedPackage]: #add-appxprovisionedpackage '```&#10;PS C:\> Add-AppxProvisionedPackage&#10;```&#10;Adds an app package (.appx) that will install for each new user to a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsCapability]: #add-windowscapability '```&#10;PS C:\> Add-WindowsCapability&#10;```&#10;Installs a Windows capability package on the specified operating system image.'
[Add-WindowsDriver]: #add-windowsdriver '```&#10;PS C:\> Add-WindowsDriver&#10;```&#10;Adds a driver to an offline Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-Drive`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsImage]: #add-windowsimage '```&#10;PS C:\> Add-WindowsImage&#10;```&#10;Adds an additional image to an existing image (.wim) file.&#10;Equivalent to `dism.exe /Append-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Add-WindowsPackage]: #add-windowspackage '```&#10;PS C:\> Add-WindowsPackage&#10;```&#10;Adds a single .cab or .msu file to a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Add-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Clear-WindowsCorruptMountPoint]: #clear-windowscorruptmountpoint '```&#10;PS C:\> Clear-WindowsCorruptMountPoint&#10;```&#10;Deletes all of the resources associated with a mounted image that has been corrupted.'
[Disable-WindowsOptionalFeature]: #disable-windowsoptionalfeature '```&#10;PS C:\> Disable-WindowsOptionalFeature&#10;```&#10;Disables a feature in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Disable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Dismount-WindowsImage]: #dismount-windowsimage '```&#10;PS C:\> Dismount-WindowsImage&#10;```&#10;Dismounts a Windows image from the directory it is mapped to.&#10;Equivalent to `Dism.exe /Unmount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Enable-WindowsOptionalFeature]: #enable-windowsoptionalfeature '```&#10;PS C:\> Enable-WindowsOptionalFeature&#10;```&#10;Enable or restore an optional feature in a Windows image&#10;Equivalent to `Dism.exe /Image:foldername /Enable-Feature`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Expand-WindowsCustomDataImage]: #expand-windowscustomdataimage '```&#10;PS C:\> Expand-WindowsCustomDataImage&#10;```&#10;Expands a custom data image.'
[Expand-WindowsImage]: #expand-windowsimage '```&#10;PS C:\> Expand-WindowsImage&#10;```&#10;Applies an image to a specified location.&#10;Equivalent to `Dism.exe /Apply-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsDriver]: #export-windowsdriver '```&#10;PS C:\> Export-WindowsDriver&#10;```&#10;Exports all third-party drivers from a Windows image to a destination folder.&#10;Equivalent to `Dism.exe /Image:foldername /Export-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Export-WindowsImage]: #export-windowsimage '```&#10;PS C:\> Export-WindowsImage&#10;```&#10;Exports a copy of the specified image to another image file.&#10;Equivalent to `Dism.exe /Export-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-AppxProvisionedPackage]: #get-appxprovisionedpackage '```&#10;PS C:\> Get-AppxProvisionedPackage&#10;```&#10;Gets information about app packages (.appx) in an image that will be installed for each new user.&#10;Equivalent to `Dism.exe /Image:foldername /Get-ProvisionedAppxPackages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WIMBootEntry]: #get-wimbootentry '```&#10;PS C:\> Get-WIMBootEntry&#10;```&#10;Displays the Windows image file boot (WIMBoot) configuration entries for a specified disk volume.'
[Get-WindowsCapability]: #get-windowscapability '```&#10;PS C:\> Get-WindowsCapability&#10;```&#10;Gets Windows capabilities for an image or a running operating system.'
[Get-WindowsDriver]: #get-windowsdriver '```&#10;PS C:\> Get-WindowsDriver&#10;```&#10;Displays information about drivers in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Drivers`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsEdition]: #get-windowsedition '```&#10;PS C:\> Get-WindowsEdition&#10;```&#10;Gets edition information about a Windows image.'
[Get-WindowsImage]: #get-windowsimage '```&#10;PS C:\> Get-WindowsImage&#10;```&#10;Gets information about a Windows image in a WIM or VHD file.&#10;Equivalent to `Dism.exe /Get-ImageInfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsImageContent]: #get-windowsimagecontent '```&#10;PS C:\> Get-WindowsImageContent&#10;```&#10;Displays a list of the files and folders in a specified image.&#10;Equivalent to `Dism.exe /List-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsOptionalFeature]: #get-windowsoptionalfeature '```&#10;PS C:\> Get-WindowsOptionalFeature&#10;```&#10;Gets information about optional features in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Features`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsPackage]: #get-windowspackage '```&#10;PS C:\> Get-WindowsPackage&#10;```&#10;Gets information about packages in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packages`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Get-WindowsReservedStorageState]: #get-windowsreservedstoragestate '```&#10;PS C:\> Get-WindowsReservedStorageState&#10;```&#10;Gets the reserved storage state of the image.'
[Mount-WindowsImage]: #mount-windowsimage '```&#10;PS C:\> Mount-WindowsImage&#10;```&#10;Mounts a Windows image in a WIM or VHD file to a directory on the local computer.&#10;Equivalent to `Dism.exe /Mount-image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[New-WindowsCustomImage]: #new-windowscustomimage '```&#10;PS C:\> New-WindowsCustomImage&#10;```&#10;Captures an image of customized or serviced Windows components on a Windows Image File Boot (WIMBoot) configured device.'
[New-WindowsImage]: #new-windowsimage '```&#10;PS C:\> New-WindowsImage&#10;```&#10;Captures an image of a drive to a new WIM file.&#10;Equivalent to `Dism.exe /Capture-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Optimize-WindowsImage]: #optimize-windowsimage '```&#10;PS C:\> Optimize-WindowsImage&#10;```&#10;Configures a Windows image with specified optimizations.'
[Remove-AppxProvisionedPackage]: #remove-appxprovisionedpackage '```&#10;PS C:\> Remove-AppxProvisionedPackage&#10;```&#10;Removes an app package (.appx) from a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-ProvisionedAppxPackage`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsCapability]: #remove-windowscapability '```&#10;PS C:\> Remove-WindowsCapability&#10;```&#10;Uninstalls a Windows capability package from an image.'
[Remove-WindowsDriver]: #remove-windowsdriver '```&#10;PS C:\> Remove-WindowsDriver&#10;```&#10;Removes a driver from an offline Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Driver`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Remove-WindowsImage]: #remove-windowsimage '```&#10;PS C:\> Remove-WindowsImage&#10;```&#10;Deletes the specified volume image from a WIM file that has multiple volume images.&#10;Equivalent to `Dism.exe /Remove-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Remove-WindowsPackage]: #remove-windowspackage '```&#10;PS C:\> Remove-WindowsPackage&#10;```&#10;Removes a package from a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Remove-Package`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Repair-WindowsImage]: #repair-windowsimage '```&#10;PS C:\> Repair-WindowsImage&#10;```&#10;Repairs a Windows image in a WIM or VHD file.'
[Save-WindowsImage]: #save-windowsimage '```&#10;PS C:\> Save-WindowsImage&#10;```&#10;Applies changes made to a mounted image to its WIM or VHD file.&#10;Equivalent to `Dism.exe /Commit-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Set-AppxProvisionedDataFile]: #set-appxprovisioneddatafile '```&#10;PS C:\> Set-AppxProvisionedDataFile&#10;```&#10;Adds custom data into the specified app (.appx) package that has been provisioned in a Windows image.&#10;Equivalent to `Dism.exe /Image:foldername /Set-ProvisionedAppxDataFile`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[Set-WindowsEdition]: #set-windowsedition '```&#10;PS C:\> Set-WindowsEdition&#10;```&#10;Changes a Windows image to a higher edition.'
[Set-WindowsProductKey]: #set-windowsproductkey '```&#10;PS C:\> Set-WindowsProductKey&#10;```&#10;Sets the product key for the Windows image.'
[Set-WindowsReservedStorageState]: #set-windowsreservedstoragestate '```&#10;PS C:\> Set-WindowsReservedStorageState&#10;```&#10;Sets the reserved storage state of the image.'
[Split-WindowsImage]: #split-windowsimage '```&#10;PS C:\> Split-WindowsImage&#10;```&#10;Splits an existing .wim file into multiple read-only split .wim files.'
[Update-WIMBootEntry]: #update-wimbootentry '```&#10;PS C:\> Update-WIMBootEntry&#10;```&#10;Updates the Windows image file boot (WIMBoot) configuration entry, associated with either the specified data source ID, the renamed image file path or the moved image file path.'
[Use-WindowsUnattend]: #use-windowsunattend '```&#10;PS C:\> Use-WindowsUnattend&#10;```&#10;Applies an unattended answer file to a Windows image.'


<code>WIMBootEntry&nbsp;[g][Get-WIMBootEntry]&nbsp;[u][Update-WIMBootEntry]</code>
**`AppxProvisioned`**
<code>DataFile&nbsp;[s][Set-AppxProvisionedDataFile]</code> 
<code>Package&nbsp;[a][Add-AppxProvisionedPackage]&nbsp;[g][Get-AppxProvisionedPackage]&nbsp;[r][Remove-AppxProvisionedPackage]</code> 
**`Windows`**
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
#### failoverclusters
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

<!-- Failover clusters -->
[Add-ClusterCheckpoint]: #add-clustercheckpoint '```&#10;PS C:\> Add-ClusterCheckpoint&#10;```&#10;Adds a cryptographic key checkpoint or registry checkpoint for a resource.'
[Add-ClusterGenericScriptRole]: #add-clustergenericscriptrole '```&#10;PS C:\> Add-ClusterGenericScriptRole&#10;```&#10;Configures an application controlled by a script that runs in Windows Script Host, within a failover cluster.'
[Add-ClusterGenericServiceRole]: #add-clustergenericservicerole '```&#10;PS C:\> Add-ClusterGenericServiceRole&#10;```&#10;Configures high availability for a service that was not originally designed to run in a failover cluster.'
[Add-ClusterGroupSetDependency]: #add-clustergroupsetdependency '```&#10;PS C:\> Add-ClusterGroupSetDependency&#10;```&#10;Adds a dependency to a cluster set.'
[Add-ClusterGroupToSet]: #add-clustergrouptoset '```&#10;PS C:\> Add-ClusterGroupToSet&#10;```&#10;Adds a group to a set.'
[Add-ClusteriSCSITargetServerRole]: #add-clusteriscsitargetserverrole '```&#10;PS C:\> Add-ClusteriSCSITargetServerRole&#10;```&#10;Creates a highly available iSCSI Target server.'
[Add-ClusterResourceType]: #add-clusterresourcetype '```&#10;PS C:\> Add-ClusterResourceType&#10;```&#10;Adds a resource type to a failover cluster, and specifies information such as the dynamic-link library (DLL) to use with that resource type.'
[Add-ClusterScaleOutFileServer]: #add-clusterscaleoutfileserver '```&#10;PS C:\> Add-ClusterScaleOutFileServer&#10;```&#10;Install the Scale-out File Server role&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 339'
[Add-ClusterScaleOutFileServerRole]: #add-clusterscaleoutfileserverrole '```&#10;PS C:\> Add-ClusterScaleOutFileServerRole&#10;```&#10;Creates a clustered file server for scale-out application data.'
[Add-ClusterServerRole]: #add-clusterserverrole '```&#10;PS C:\> Add-ClusterServerRole&#10;```&#10;Add the cluster server role to a server'
[Clear-ClusterDiskReservation]: #clear-clusterdiskreservation '```&#10;PS C:\> Clear-ClusterDiskReservation&#10;```&#10;Clears the persistent reservation on a disk in a failover cluster.'
[Clear-ClusterNode]: #clear-clusternode '```&#10;PS C:\> Clear-ClusterNode&#10;```&#10;Clears the cluster configuration from a node that was evicted from a failover cluster.'
[Disable-ClusterStorageSpacesDirect]: #disable-clusterstoragespacesdirect '```&#10;PS C:\> Disable-ClusterStorageSpacesDirect&#10;```&#10;Disables S2D.'
[Add-ClusterDisk]: #add-clusterdisk '```&#10;PS C:\> Add-ClusterDisk&#10;```&#10;Allow an admin to add a new disk to a failover cluster'
[Add-ClusterFileServerRole]: #add-clusterfileserverrole '```&#10;PS C:\> Add-ClusterFileServerRole&#10;```&#10;This command allows an admin to create a clustered file server'
[Add-ClusterGenericApplicationRole]: #add-clustergenericapplicationrole '```&#10;PS C:\> Add-ClusterGenericApplicationRole&#10;```&#10;Configures an application in the generic application role, providing high availability for an application not designed for use in a failover cluster.'
[Get-ClusterAvailableDisk]: #get-clusteravailabledisk '```&#10;PS C:\> Get-ClusterAvailableDisk&#10;```&#10;Gets information about the disks that can support Failover Clustering and are visible to all nodes, but are not yet part of the set of clustered disks.'
[Get-ClusterCheckpoint]: #get-clustercheckpoint '```&#10;PS C:\> Get-ClusterCheckpoint&#10;```&#10;Retrieves a cryptographic key checkpoint or registry checkpoint for a resource.'
[Get-ClusterDiagnosticInfo]: #get-clusterdiagnosticinfo '```&#10;PS C:\> Get-ClusterDiagnosticInfo&#10;```&#10;Gets diagnostics for a cluster a cluster that contains VMs and produces a zip file containing the data.'
[Get-ClusterFaultDomain]: #get-clusterfaultdomain '```&#10;PS C:\> Get-ClusterFaultDomain&#10;```&#10;Gets the cluster fault domains in a cluster.'
[Get-ClusterFaultDomainXML]: #get-clusterfaultdomainxml '```&#10;PS C:\> Get-ClusterFaultDomainXML&#10;```&#10;Gets the fault domain as an XML string.'
[Get-ClusterGroup]: #get-clustergroup '```&#10;PS C:\> Get-ClusterGroup&#10;```&#10;Gets information about one or more clustered roles (resource groups) in a failover cluster.'
[Get-ClusterGroupSet]: #get-clustergroupset '```&#10;PS C:\> Get-ClusterGroupSet&#10;```&#10;Gets the group sets in the cluster.'
[Get-ClusterGroupSetDependency]: #get-clustergroupsetdependency '```&#10;PS C:\> Get-ClusterGroupSetDependency&#10;```&#10;Gets the cluster group sets based on dependency relationships.'
[Get-ClusterLog]: #get-clusterlog '```&#10;PS C:\> Get-ClusterLog&#10;```&#10;Creates a log file for all nodes, or a specific a node, in a failover cluster.'
[Get-ClusterNetwork]: #get-clusternetwork '```&#10;PS C:\> Get-ClusterNetwork&#10;```&#10;Gets information about one or more networks in a failover cluster.'
[Get-ClusterNetworkInterface]: #get-clusternetworkinterface '```&#10;PS C:\> Get-ClusterNetworkInterface&#10;```&#10;Gets information about one or more network adapters in a failover cluster.'
[Add-ClusterGroup]: #add-clustergroup '```&#10;PS C:\> Add-ClusterGroup&#10;```&#10;Allow an admin to add a resource group to the failover cluster'
[Add-ClusterNode]: #add-clusternode '```&#10;PS C:\> Add-ClusterNode&#10;```&#10;Allow an admin to add a node to a failover cluster'
[Get-ClusterOwnerNode]: #get-clusterownernode '```&#10;PS C:\> Get-ClusterOwnerNode&#10;```&#10;Gets information about which nodes can own a resource in a failover cluster or information about the order of preference among owner nodes for a clustered role.'
[Get-ClusterParameter]: #get-clusterparameter '```&#10;PS C:\> Get-ClusterParameter&#10;```&#10;Gets detailed information about an object in a failover cluster, such as a cluster resource.'
[Add-ClusterResource]: #add-clusterresource '```&#10;PS C:\> Add-ClusterResource&#10;```&#10;Allow an admin to add a resource to a failover cluster'
[Add-ClusterResourceDependency]: #add-clusterresourcedependency '```&#10;PS C:\> Add-ClusterResourceDependency&#10;```&#10;Add a resource dependency to a failover cluster'
[Get-ClusterResource]: #get-clusterresource '```&#10;PS C:\> Get-ClusterResource&#10;```&#10;Gets information about one or more resources in a failover cluster.'
[Get-ClusterResourceDependency]: #get-clusterresourcedependency '```&#10;PS C:\> Get-ClusterResourceDependency&#10;```&#10;Gets information about the dependencies that have been configured between clustered resources in a failover cluster.'
[Get-ClusterResourceDependencyReport]: #get-clusterresourcedependencyreport '```&#10;PS C:\> Get-ClusterResourceDependencyReport&#10;```&#10;Generates a report that lists the dependencies between resources in a failover cluster.'
[Get-ClusterResourceType]: #get-clusterresourcetype '```&#10;PS C:\> Get-ClusterResourceType&#10;```&#10;Gets information about one or more resource types in a failover cluster.'
[Get-ClusterSharedVolume]: #get-clustersharedvolume '```&#10;PS C:\> Get-ClusterSharedVolume&#10;```&#10;Gets information about Cluster Shared Volumes in a failover cluster.'
[Get-ClusterSharedVolumeState]: #get-clustersharedvolumestate '```&#10;PS C:\> Get-ClusterSharedVolumeState&#10;```&#10;Gets the state of Cluster Shared Volumes in a cluster.'
[Get-ClusterStorageSpacesDirect]: #get-clusterstoragespacesdirect '```&#10;PS C:\> Get-ClusterStorageSpacesDirect&#10;```&#10;Gets the S2D settings from a cluster.'
[Get-ClusterVMMonitoredItem]: #get-clustervmmonitoreditem '```&#10;PS C:\> Get-ClusterVMMonitoredItem&#10;```&#10;Gets the list of services and events currently being monitored in the virtual machine.'
[Grant-ClusterAccess]: #grant-clusteraccess '```&#10;PS C:\> Grant-ClusterAccess&#10;```&#10;Grants access to a failover cluster, either full access or read-only access.'
[Move-ClusterGroup]: #move-clustergroup '```&#10;PS C:\> Move-ClusterGroup&#10;```&#10;Moves a clustered role (a resource group) from one node to another in a failover cluster.'
[Move-ClusterResource]: #move-clusterresource '```&#10;PS C:\> Move-ClusterResource&#10;```&#10;Moves a clustered resource from one clustered role to another within a failover cluster.'
[Move-ClusterSharedVolume]: #move-clustersharedvolume '```&#10;PS C:\> Move-ClusterSharedVolume&#10;```&#10;Moves a Cluster Shared Volume (CSV) to ownership by a different node in a failover cluster.'
[Move-ClusterVirtualMachineRole]: #move-clustervirtualmachinerole '```&#10;PS C:\> Move-ClusterVirtualMachineRole&#10;```&#10;Moves the ownership of a clustered virtual machine to a different node.'
[Add-ClusterSharedVolume]: #add-clustersharedvolume '```&#10;PS C:\> Add-ClusterSharedVolume&#10;```&#10;Makes a volume available in Cluster Shared Volumes in a failover cluster.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 153'
[Add-ClusterVirtualMachineRole]: #add-clustervirtualmachinerole '```&#10;PS C:\> Add-ClusterVirtualMachineRole&#10;```&#10;Creates a clustered virtual machine, that is, a virtual machine that can be failed over if necessary to a different server in the failover cluster.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 304'
[New-ClusterFaultDomain]: #new-clusterfaultdomain '```&#10;PS C:\> New-ClusterFaultDomain&#10;```&#10;Creates a fault domain in the cluster.'
[New-ClusterGroupSet]: #new-clustergroupset '```&#10;PS C:\> New-ClusterGroupSet&#10;```&#10;Create a names set of groups in the cluster.'
[New-ClusterNameAccount]: #new-clusternameaccount '```&#10;PS C:\> New-ClusterNameAccount&#10;```&#10;Creates a cluster name account in Active Directory Domain Services.'
[Add-ClusterVMMonitoredItem]: #add-clustervmmonitoreditem '```&#10;PS C:\> Add-ClusterVMMonitoredItem&#10;```&#10;Configures monitoring for a service or an Event Tracing for Windows (ETW) event so that it is monitored on a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 362'
[Block-ClusterAccess]: #block-clusteraccess '```&#10;PS C:\> Block-ClusterAccess&#10;```&#10;Block the specified users from accessing a cluster'
[Enable-ClusterStorageSpacesDirect]: #enable-clusterstoragespacesdirect '```&#10;PS C:\> Enable-ClusterStorageSpacesDirect&#10;```&#10;Enables S2D.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 354'
[Get-Cluster]: #get-cluster '```&#10;PS C:\> Get-Cluster&#10;```&#10;Display information about a failover cluster'
[Remove-ClusterCheckpoint]: #remove-clustercheckpoint '```&#10;PS C:\> Remove-ClusterCheckpoint&#10;```&#10;Removes a cryptographic key checkpoint or registry checkpoint for a resource.'
[Remove-ClusterFaultDomain]: #remove-clusterfaultdomain '```&#10;PS C:\> Remove-ClusterFaultDomain&#10;```&#10;Removes a fault domain.'
[Remove-ClusterGroup]: #remove-clustergroup '```&#10;PS C:\> Remove-ClusterGroup&#10;```&#10;Removes a clustered role, also called a resource group, from a failover cluster.'
[Remove-ClusterGroupFromSet]: #remove-clustergroupfromset '```&#10;PS C:\> Remove-ClusterGroupFromSet&#10;```&#10;Removes a group from a set.'
[Remove-ClusterGroupSet]: #remove-clustergroupset '```&#10;PS C:\> Remove-ClusterGroupSet&#10;```&#10;Removes a group set from the cluster.'
[Remove-ClusterGroupSetDependency]: #remove-clustergroupsetdependency '```&#10;PS C:\> Remove-ClusterGroupSetDependency&#10;```&#10;Removes a dependency from a group set.'
[Get-ClusterAccess]: #get-clusteraccess '```&#10;PS C:\> Get-ClusterAccess&#10;```&#10;Display permissions for a failover cluster'
[Get-ClusterNode]: #get-clusternode '```&#10;PS C:\> Get-ClusterNode&#10;```&#10;Display information about the servers in a failover cluster'
[Remove-ClusterResource]: #remove-clusterresource '```&#10;PS C:\> Remove-ClusterResource&#10;```&#10;Removes a clustered resource from the failover cluster.'
[Remove-ClusterResourceDependency]: #remove-clusterresourcedependency '```&#10;PS C:\> Remove-ClusterResourceDependency&#10;```&#10;Removes a dependency between two resources in a clustered role within a failover cluster.'
[Remove-ClusterResourceType]: #remove-clusterresourcetype '```&#10;PS C:\> Remove-ClusterResourceType&#10;```&#10;Removes a resource type from a failover cluster.'
[Remove-ClusterSharedVolume]: #remove-clustersharedvolume '```&#10;PS C:\> Remove-ClusterSharedVolume&#10;```&#10;Removes a volume from the Cluster Shared Volumes in a failover cluster, and places it in Available Storage in the cluster.'
[Remove-ClusterVMMonitoredItem]: #remove-clustervmmonitoreditem '```&#10;PS C:\> Remove-ClusterVMMonitoredItem&#10;```&#10;Removes monitoring of a service or event that is currently being monitored on a virtual machine.'
[Repair-ClusterStorageSpacesDirect]: #repair-clusterstoragespacesdirect '```&#10;PS C:\> Repair-ClusterStorageSpacesDirect&#10;```&#10;Repairs S2D disks.'
[Reset-ClusterVMMonitoredState]: #reset-clustervmmonitoredstate '```&#10;PS C:\> Reset-ClusterVMMonitoredState&#10;```&#10;Resets the Application Critical state of a virtual machine, so that the virtual machine is no longer marked as being in a critical state in the cluster.'
[Resume-ClusterNode]: #resume-clusternode '```&#10;PS C:\> Resume-ClusterNode&#10;```&#10;Resumes a node from the paused state or brings back drained workloads to the node or both.'
[Resume-ClusterResource]: #resume-clusterresource '```&#10;PS C:\> Resume-ClusterResource&#10;```&#10;Turns off maintenance for a disk resource or Cluster Shared Volume within a failover cluster.'
[Set-ClusterFaultDomain]: #set-clusterfaultdomain '```&#10;PS C:\> Set-ClusterFaultDomain&#10;```&#10;Update an existing cluster fault domain.'
[Set-ClusterFaultDomainXML]: #set-clusterfaultdomainxml '```&#10;PS C:\> Set-ClusterFaultDomainXML&#10;```&#10;Sets the cluster fault domain using XML.'
[Set-ClusterGroupSet]: #set-clustergroupset '```&#10;PS C:\> Set-ClusterGroupSet&#10;```&#10;Updates a cluster group set.'
[Set-ClusterLog]: #set-clusterlog '```&#10;PS C:\> Set-ClusterLog&#10;```&#10;Sets the size and level of detail for the cluster log.'
[Set-ClusterOwnerNode]: #set-clusterownernode '```&#10;PS C:\> Set-ClusterOwnerNode&#10;```&#10;Specifies which nodes can own a resource in a failover cluster or specifies the order of preference among owner nodes for a clustered role, or resource group.'
[Set-ClusterParameter]: #set-clusterparameter '```&#10;PS C:\> Set-ClusterParameter&#10;```&#10;Controls specific properties of an object in a failover cluster, such as a resource, a group, or a network.'
[Set-ClusterQuorum]: #set-clusterquorum '```&#10;PS C:\> Set-ClusterQuorum&#10;```&#10;Configures quorum options for a failover cluster.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 318'
[Set-ClusterResourceDependency]: #set-clusterresourcedependency '```&#10;PS C:\> Set-ClusterResourceDependency&#10;```&#10;Specifies the resources that a particular resource depends on within a failover cluster.'
[Set-ClusterStorageSpacesDirect]: #set-clusterstoragespacesdirect '```&#10;PS C:\> Set-ClusterStorageSpacesDirect&#10;```&#10;Sets S2D cache parameters.'
[Set-ClusterStorageSpacesDirectDisk]: #set-clusterstoragespacesdirectdisk '```&#10;PS C:\> Set-ClusterStorageSpacesDirectDisk&#10;```&#10;Configures the system to enable S2D to claim or not claim specific physical disks.'
[Get-ClusterQuorum]: #get-clusterquorum '```&#10;PS C:\> Get-ClusterQuorum&#10;```&#10;Display cluster quorum in a cluster'
[New-Cluster]: #new-cluster '```&#10;PS C:\> New-Cluster&#10;```&#10;Create a new failover cluster&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 337'
[Start-ClusterGroup]: #start-clustergroup '```&#10;PS C:\> Start-ClusterGroup&#10;```&#10;Starts one or more clustered roles, also known as resource groups, on a failover cluster.'
[Start-ClusterNode]: #start-clusternode '```&#10;PS C:\> Start-ClusterNode&#10;```&#10;Starts the Cluster service on a node in a failover cluster.'
[Start-ClusterResource]: #start-clusterresource '```&#10;PS C:\> Start-ClusterResource&#10;```&#10;Brings a resource online in a failover cluster.'
[Remove-Cluster]: #remove-cluster '```&#10;PS C:\> Remove-Cluster&#10;```&#10;Remove a failover cluster'
[Remove-ClusterAccess]: #remove-clusteraccess '```&#10;PS C:\> Remove-ClusterAccess&#10;```&#10;Remove user access from the cluster'
[Stop-ClusterGroup]: #stop-clustergroup '```&#10;PS C:\> Stop-ClusterGroup&#10;```&#10;Stops one or more clustered roles on a failover cluster.'
[Remove-ClusterNode]: #remove-clusternode '```&#10;PS C:\> Remove-ClusterNode&#10;```&#10;Remove a node from a failover cluster'
[Start-Cluster]: #start-cluster '```&#10;PS C:\> Start-Cluster&#10;```&#10;Start the Cluster service on all nodes'
[Stop-ClusterResource]: #stop-clusterresource '```&#10;PS C:\> Stop-ClusterResource&#10;```&#10;Takes a resource offline in a failover cluster.'
[Stop-Cluster]: #stop-cluster '```&#10;PS C:\> Stop-Cluster&#10;```&#10;Stop the Cluster service on all nodes'
[Stop-ClusterNode]: #stop-clusternode '```&#10;PS C:\> Stop-ClusterNode&#10;```&#10;Stop the Cluster service on a node'
[Suspend-ClusterResource]: #suspend-clusterresource '```&#10;PS C:\> Suspend-ClusterResource&#10;```&#10;Turns on maintenance for a disk resource or CSV so that you can run a disk maintenance tool without triggering failover.'
[Suspend-ClusterNode]: #suspend-clusternode '```&#10;PS C:\> Suspend-ClusterNode&#10;```&#10;Pause the activity of a failover cluster node&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 374'
[Test-Cluster]: #test-cluster '```&#10;PS C:\> Test-Cluster&#10;```&#10;Complete validation tests for a cluster'
[Test-ClusterResourceFailure]: #test-clusterresourcefailure '```&#10;PS C:\> Test-ClusterResourceFailure&#10;```&#10;Simulates a failure of a cluster resource.'
[Update-ClusterFunctionalLevel]: #update-clusterfunctionallevel '```&#10;PS C:\> Update-ClusterFunctionalLevel&#10;```&#10;Updates the functional level of a mixed-version cluster.'
[Update-ClusterIPResource]: #update-clusteripresource '```&#10;PS C:\> Update-ClusterIPResource&#10;```&#10;Renews or releases the DHCP lease for an IP address resource in a failover cluster.'
[Update-ClusterNetworkNameResource]: #update-clusternetworknameresource '```&#10;PS C:\> Update-ClusterNetworkNameResource&#10;```&#10;Registers existing Network Name resources with a DNS server in a way that does not interrupt cluster availability.'
[Update-ClusterVirtualMachineConfiguration]: #update-clustervirtualmachineconfiguration '```&#10;PS C:\> Update-ClusterVirtualMachineConfiguration&#10;```&#10;Refreshes the configuration of a clustered virtual machine within a failover cluster.'

[**`Cluster`**](#failover-clusters)
<code>&nbsp;[g][Get-Cluster][?][msdocs:Get-Cluster]&nbsp;[n][New-Cluster][?][msdocs:New-Cluster]&nbsp;[r][Remove-Cluster][?][msdocs:Remove-Cluster]&nbsp;[sa][Start-Cluster][?][msdocs:Start-Cluster]&nbsp;[sp][Stop-Cluster][?][msdocs:Stop-Cluster]&nbsp;[t][Test-Cluster][?][msdocs:Test-Cluster]</code>
<code>Access&nbsp;&nbsp;[gr][Grant-ClusterAccess][?][msdocs:Grant-ClusterAccess]&nbsp;[bl][Block-ClusterAccess][?][msdocs:Block-ClusterAccess]&nbsp;[g][Get-ClusterAccess][?][msdocs:Get-ClusterAccess]&nbsp;[r][Remove-ClusterAccess][?][msdocs:Remove-ClusterAccess]</code>
<code>Disk&nbsp;[a][Add-ClusterDisk]</code>
<code>FaultDomain&nbsp;[n][New-ClusterFaultDomain][^][msdocs:New-ClusterFaultDomain]&nbsp;[s][Set-ClusterFaultDomain][^][msdocs:Set-ClusterFaultDomain]</code>
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
<code>VirtualMachineRole&nbsp;[m][Move-ClusterVirtualMachineRole][?][msdocs:Move-ClusterVirtualMachineRole]&nbsp;[a][Add-ClusterVirtualMachineRole][?][msdocs:Add-ClusterVirtualMachineRole]</code>
<code>VMMonitoredItem&nbsp;[g][Get-ClusterVMMonitoredItem][?][msdocs:Get-ClusterVMMonitoredItem]&nbsp;[a][Add-ClusterVMMonitoredItem][?][msdocs:Add-ClusterVMMonitoredItem]&nbsp;[r][Remove-ClusterVMMonitoredItem][?][msdocs:Remove-ClusterVMMonitoredItem]</code>

#### storage
[msdocs:Get-DedupProperties]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-DedupProperties "Get-DedupProperties documentation"
[msdocs:Clear-Disk]: https://docs.microsoft.com/en-us/powershell/module/storage/Clear-Disk "Clear-Disk documentation"
[msdocs:Get-Disk]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-Disk "Get-Disk documentation"
[msdocs:Initialize-Disk]: https://docs.microsoft.com/en-us/powershell/module/storage/Initialize-Disk "Initialize-Disk documentation"
[msdocs:Set-Disk]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-Disk "Set-Disk documentation"
[msdocs:Update-Disk]: https://docs.microsoft.com/en-us/powershell/module/storage/Update-Disk "Update-Disk documentation"
[msdocs:Dismount-DiskImage]: https://docs.microsoft.com/en-us/powershell/module/storage/Dismount-DiskImage "Dismount-DiskImage documentation"
[msdocs:Get-DiskImage]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-DiskImage "Get-DiskImage documentation"
[msdocs:Mount-DiskImage]: https://docs.microsoft.com/en-us/powershell/module/storage/Mount-DiskImage "Mount-DiskImage documentation"
[msdocs:Get-DiskStorageNodeView]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-DiskStorageNodeView "Get-DiskStorageNodeView documentation"
[msdocs:Get-FileIntegrity]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-FileIntegrity "Get-FileIntegrity documentation"
[msdocs:Repair-FileIntegrity]: https://docs.microsoft.com/en-us/powershell/module/storage/Repair-FileIntegrity "Repair-FileIntegrity documentation"
[msdocs:Set-FileIntegrity]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-FileIntegrity "Set-FileIntegrity documentation"
[msdocs:Debug-FileShare]: https://docs.microsoft.com/en-us/powershell/module/storage/Debug-FileShare "Debug-FileShare documentation"
[msdocs:Get-FileShare]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-FileShare "Get-FileShare documentation"
[msdocs:New-FileShare]: https://docs.microsoft.com/en-us/powershell/module/storage/New-FileShare "New-FileShare documentation"
[msdocs:Remove-FileShare]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-FileShare "Remove-FileShare documentation"
[msdocs:Set-FileShare]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-FileShare "Set-FileShare documentation"
[msdocs:Block-FileShareAccess]: https://docs.microsoft.com/en-us/powershell/module/storage/Block-FileShareAccess "Block-FileShareAccess documentation"
[msdocs:Grant-FileShareAccess]: https://docs.microsoft.com/en-us/powershell/module/storage/Grant-FileShareAccess "Grant-FileShareAccess documentation"
[msdocs:Revoke-FileShareAccess]: https://docs.microsoft.com/en-us/powershell/module/storage/Revoke-FileShareAccess "Revoke-FileShareAccess documentation"
[msdocs:Unblock-FileShareAccess]: https://docs.microsoft.com/en-us/powershell/module/storage/Unblock-FileShareAccess "Unblock-FileShareAccess documentation"
[msdocs:Get-FileShareAccessControlEntry]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-FileShareAccessControlEntry "Get-FileShareAccessControlEntry documentation"
[msdocs:Set-FileStorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-FileStorageTier "Set-FileStorageTier documentation"
[msdocs:Clear-FileStorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Clear-FileStorageTier "Clear-FileStorageTier documentation"
[msdocs:Get-FileStorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-FileStorageTier "Get-FileStorageTier documentation"
[msdocs:Update-HostStorageCache]: https://docs.microsoft.com/en-us/powershell/module/storage/Update-HostStorageCache "Update-HostStorageCache documentation"
[msdocs:Get-InitiatorId]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-InitiatorId "Get-InitiatorId documentation"
[msdocs:Remove-InitiatorId]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-InitiatorId "Remove-InitiatorId documentation"
[msdocs:Remove-InitiatorIdFromMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-InitiatorIdFromMaskingSet "Remove-InitiatorIdFromMaskingSet documentation"
[msdocs:Add-InitiatorIdToMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Add-InitiatorIdToMaskingSet "Add-InitiatorIdToMaskingSet documentation"
[msdocs:Get-InitiatorPort]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-InitiatorPort "Get-InitiatorPort documentation"
[msdocs:Set-InitiatorPort]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-InitiatorPort "Set-InitiatorPort documentation"
[msdocs:Get-MaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-MaskingSet "Get-MaskingSet documentation"
[msdocs:New-MaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/New-MaskingSet "New-MaskingSet documentation"
[msdocs:Remove-MaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-MaskingSet "Remove-MaskingSet documentation"
[msdocs:Rename-MaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Rename-MaskingSet "Rename-MaskingSet documentation"
[msdocs:Get-OffloadDataTransferSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-OffloadDataTransferSetting "Get-OffloadDataTransferSetting documentation"
[msdocs:Get-Partition]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-Partition "Get-Partition documentation"
[msdocs:New-Partition]: https://docs.microsoft.com/en-us/powershell/module/storage/New-Partition "New-Partition documentation"
[msdocs:Remove-Partition]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-Partition "Remove-Partition documentation"
[msdocs:Resize-Partition]: https://docs.microsoft.com/en-us/powershell/module/storage/Resize-Partition "Resize-Partition documentation"
[msdocs:Set-Partition]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-Partition "Set-Partition documentation"
[msdocs:Add-PartitionAccessPath]: https://docs.microsoft.com/en-us/powershell/module/storage/Add-PartitionAccessPath "Add-PartitionAccessPath documentation"
[msdocs:Remove-PartitionAccessPath]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-PartitionAccessPath "Remove-PartitionAccessPath documentation"
[msdocs:Get-PartitionSupportedSize]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-PartitionSupportedSize "Get-PartitionSupportedSize documentation"
[msdocs:Add-PhysicalDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Add-PhysicalDisk "Add-PhysicalDisk documentation"
[msdocs:Get-PhysicalDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-PhysicalDisk "Get-PhysicalDisk documentation"
[msdocs:Remove-PhysicalDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-PhysicalDisk "Remove-PhysicalDisk documentation"
[msdocs:Reset-PhysicalDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Reset-PhysicalDisk "Reset-PhysicalDisk documentation"
[msdocs:Set-PhysicalDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-PhysicalDisk "Set-PhysicalDisk documentation"
[msdocs:Disable-PhysicalDiskIdentification]: https://docs.microsoft.com/en-us/powershell/module/storage/Disable-PhysicalDiskIdentification "Disable-PhysicalDiskIdentification documentation"
[msdocs:Enable-PhysicalDiskIdentification]: https://docs.microsoft.com/en-us/powershell/module/storage/Enable-PhysicalDiskIdentification "Enable-PhysicalDiskIdentification documentation"
[msdocs:Get-PhysicalDiskStorageNodeView]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-PhysicalDiskStorageNodeView "Get-PhysicalDiskStorageNodeView documentation"
[msdocs:Get-PhysicalExtent]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-PhysicalExtent "Get-PhysicalExtent documentation"
[msdocs:Get-PhysicalExtentAssociation]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-PhysicalExtentAssociation "Get-PhysicalExtentAssociation documentation"
[msdocs:Get-ResiliencySetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-ResiliencySetting "Get-ResiliencySetting documentation"
[msdocs:Set-ResiliencySetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-ResiliencySetting "Set-ResiliencySetting documentation"
[msdocs:Get-StorageAdvancedProperty]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageAdvancedProperty "Get-StorageAdvancedProperty documentation"
[msdocs:Get-StorageDiagnosticInfo]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageDiagnosticInfo "Get-StorageDiagnosticInfo documentation"
[msdocs:Start-StorageDiagnosticLog]: https://docs.microsoft.com/en-us/powershell/module/storage/Start-StorageDiagnosticLog "Start-StorageDiagnosticLog documentation"
[msdocs:Stop-StorageDiagnosticLog]: https://docs.microsoft.com/en-us/powershell/module/storage/Stop-StorageDiagnosticLog "Stop-StorageDiagnosticLog documentation"
[msdocs:Get-StorageEnclosure]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageEnclosure "Get-StorageEnclosure documentation"
[msdocs:Disable-StorageEnclosureIdentification]: https://docs.microsoft.com/en-us/powershell/module/storage/Disable-StorageEnclosureIdentification "Disable-StorageEnclosureIdentification documentation"
[msdocs:Enable-StorageEnclosureIdentification]: https://docs.microsoft.com/en-us/powershell/module/storage/Enable-StorageEnclosureIdentification "Enable-StorageEnclosureIdentification documentation"
[msdocs:Get-StorageEnclosureStorageNodeView]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageEnclosureStorageNodeView "Get-StorageEnclosureStorageNodeView documentation"
[msdocs:Get-StorageEnclosureVendorData]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageEnclosureVendorData "Get-StorageEnclosureVendorData documentation"
[msdocs:Get-StorageFaultDomain]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageFaultDomain "Get-StorageFaultDomain documentation"
[msdocs:Get-StorageFileServer]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageFileServer "Get-StorageFileServer documentation"
[msdocs:New-StorageFileServer]: https://docs.microsoft.com/en-us/powershell/module/storage/New-StorageFileServer "New-StorageFileServer documentation"
[msdocs:Remove-StorageFileServer]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-StorageFileServer "Remove-StorageFileServer documentation"
[msdocs:Set-StorageFileServer]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageFileServer "Set-StorageFileServer documentation"
[msdocs:Update-StorageFirmware]: https://docs.microsoft.com/en-us/powershell/module/storage/Update-StorageFirmware "Update-StorageFirmware documentation"
[msdocs:Get-StorageFirmwareInformation]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageFirmwareInformation "Get-StorageFirmwareInformation documentation"
[msdocs:Get-StorageHealthAction]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageHealthAction "Get-StorageHealthAction documentation"
[msdocs:Get-StorageHealthReport]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageHealthReport "Get-StorageHealthReport documentation"
[msdocs:Get-StorageHealthSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageHealthSetting "Get-StorageHealthSetting documentation"
[msdocs:Remove-StorageHealthSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-StorageHealthSetting "Remove-StorageHealthSetting documentation"
[msdocs:Set-StorageHealthSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageHealthSetting "Set-StorageHealthSetting documentation"
[msdocs:Disable-StorageHighAvailability]: https://docs.microsoft.com/en-us/powershell/module/storage/Disable-StorageHighAvailability "Disable-StorageHighAvailability documentation"
[msdocs:Enable-StorageHighAvailability]: https://docs.microsoft.com/en-us/powershell/module/storage/Enable-StorageHighAvailability "Enable-StorageHighAvailability documentation"
[msdocs:Get-StorageJob]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageJob "Get-StorageJob documentation"
[msdocs:Stop-StorageJob]: https://docs.microsoft.com/en-us/powershell/module/storage/Stop-StorageJob "Stop-StorageJob documentation"
[msdocs:Disable-StorageMaintenanceMode]: https://docs.microsoft.com/en-us/powershell/module/storage/Disable-StorageMaintenanceMode "Disable-StorageMaintenanceMode documentation"
[msdocs:Enable-StorageMaintenanceMode]: https://docs.microsoft.com/en-us/powershell/module/storage/Enable-StorageMaintenanceMode "Enable-StorageMaintenanceMode documentation"
[msdocs:Get-StorageNode]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageNode "Get-StorageNode documentation"
[msdocs:Get-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StoragePool "Get-StoragePool documentation"
[msdocs:New-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/New-StoragePool "New-StoragePool documentation"
[msdocs:Optimize-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/Optimize-StoragePool "Optimize-StoragePool documentation"
[msdocs:Remove-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-StoragePool "Remove-StoragePool documentation"
[msdocs:Set-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StoragePool "Set-StoragePool documentation"
[msdocs:Update-StoragePool]: https://docs.microsoft.com/en-us/powershell/module/storage/Update-StoragePool "Update-StoragePool documentation"
[msdocs:Get-StorageProvider]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageProvider "Get-StorageProvider documentation"
[msdocs:Set-StorageProvider]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageProvider "Set-StorageProvider documentation"
[msdocs:Update-StorageProviderCache]: https://docs.microsoft.com/en-us/powershell/module/storage/Update-StorageProviderCache "Update-StorageProviderCache documentation"
[msdocs:Get-StorageReliabilityCounter]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageReliabilityCounter "Get-StorageReliabilityCounter documentation"
[msdocs:Reset-StorageReliabilityCounter]: https://docs.microsoft.com/en-us/powershell/module/storage/Reset-StorageReliabilityCounter "Reset-StorageReliabilityCounter documentation"
[msdocs:Get-StorageSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageSetting "Get-StorageSetting documentation"
[msdocs:Set-StorageSetting]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageSetting "Set-StorageSetting documentation"
[msdocs:Debug-StorageSubSystem]: https://docs.microsoft.com/en-us/powershell/module/storage/Debug-StorageSubSystem "Debug-StorageSubSystem documentation"
[msdocs:Get-StorageSubsystem]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageSubsystem "Get-StorageSubsystem documentation"
[msdocs:Register-StorageSubsystem]: https://docs.microsoft.com/en-us/powershell/module/storage/Register-StorageSubsystem "Register-StorageSubsystem documentation"
[msdocs:Set-StorageSubsystem]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageSubsystem "Set-StorageSubsystem documentation"
[msdocs:Unregister-StorageSubsystem]: https://docs.microsoft.com/en-us/powershell/module/storage/Unregister-StorageSubsystem "Unregister-StorageSubsystem documentation"
[msdocs:New-StorageSubsystemVirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/New-StorageSubsystemVirtualDisk "New-StorageSubsystemVirtualDisk documentation"
[msdocs:Get-StorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageTier "Get-StorageTier documentation"
[msdocs:New-StorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/New-StorageTier "New-StorageTier documentation"
[msdocs:Remove-StorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-StorageTier "Remove-StorageTier documentation"
[msdocs:Resize-StorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Resize-StorageTier "Resize-StorageTier documentation"
[msdocs:Set-StorageTier]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-StorageTier "Set-StorageTier documentation"
[msdocs:Get-StorageTierSupportedSize]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-StorageTierSupportedSize "Get-StorageTierSupportedSize documentation"
[msdocs:Get-SupportedClusterSizes]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-SupportedClusterSizes "Get-SupportedClusterSizes documentation"
[msdocs:Get-SupportedFileSystems]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-SupportedFileSystems "Get-SupportedFileSystems documentation"
[msdocs:Get-TargetPort]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-TargetPort "Get-TargetPort documentation"
[msdocs:Get-TargetPortal]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-TargetPortal "Get-TargetPortal documentation"
[msdocs:Remove-TargetPortFromMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-TargetPortFromMaskingSet "Remove-TargetPortFromMaskingSet documentation"
[msdocs:Add-TargetPortToMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Add-TargetPortToMaskingSet "Add-TargetPortToMaskingSet documentation"
[msdocs:Connect-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Connect-VirtualDisk "Connect-VirtualDisk documentation"
[msdocs:Disconnect-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Disconnect-VirtualDisk "Disconnect-VirtualDisk documentation"
[msdocs:Get-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-VirtualDisk "Get-VirtualDisk documentation"
[msdocs:Hide-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Hide-VirtualDisk "Hide-VirtualDisk documentation"
[msdocs:New-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/New-VirtualDisk "New-VirtualDisk documentation"
[msdocs:Remove-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-VirtualDisk "Remove-VirtualDisk documentation"
[msdocs:Repair-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Repair-VirtualDisk "Repair-VirtualDisk documentation"
[msdocs:Resize-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Resize-VirtualDisk "Resize-VirtualDisk documentation"
[msdocs:Set-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-VirtualDisk "Set-VirtualDisk documentation"
[msdocs:Show-VirtualDisk]: https://docs.microsoft.com/en-us/powershell/module/storage/Show-VirtualDisk "Show-VirtualDisk documentation"
[msdocs:New-VirtualDiskClone]: https://docs.microsoft.com/en-us/powershell/module/storage/New-VirtualDiskClone "New-VirtualDiskClone documentation"
[msdocs:Remove-VirtualDiskFromMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Remove-VirtualDiskFromMaskingSet "Remove-VirtualDiskFromMaskingSet documentation"
[msdocs:New-VirtualDiskSnapshot]: https://docs.microsoft.com/en-us/powershell/module/storage/New-VirtualDiskSnapshot "New-VirtualDiskSnapshot documentation"
[msdocs:Get-VirtualDiskSupportedSize]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-VirtualDiskSupportedSize "Get-VirtualDiskSupportedSize documentation"
[msdocs:Add-VirtualDiskToMaskingSet]: https://docs.microsoft.com/en-us/powershell/module/storage/Add-VirtualDiskToMaskingSet "Add-VirtualDiskToMaskingSet documentation"
[msdocs:Debug-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Debug-Volume "Debug-Volume documentation"
[msdocs:Format-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Format-Volume "Format-Volume documentation"
[msdocs:Get-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-Volume "Get-Volume documentation"
[msdocs:New-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/New-Volume "New-Volume documentation"
[msdocs:Optimize-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Optimize-Volume "Optimize-Volume documentation"
[msdocs:Repair-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Repair-Volume "Repair-Volume documentation"
[msdocs:Set-Volume]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-Volume "Set-Volume documentation"
[msdocs:Write-VolumeCache]: https://docs.microsoft.com/en-us/powershell/module/storage/Write-VolumeCache "Write-VolumeCache documentation"
[msdocs:Get-VolumeCorruptionCount]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-VolumeCorruptionCount "Get-VolumeCorruptionCount documentation"
[msdocs:Get-VolumeScrubPolicy]: https://docs.microsoft.com/en-us/powershell/module/storage/Get-VolumeScrubPolicy "Get-VolumeScrubPolicy documentation"
[msdocs:Set-VolumeScrubPolicy]: https://docs.microsoft.com/en-us/powershell/module/storage/Set-VolumeScrubPolicy "Set-VolumeScrubPolicy documentation"


[Get-DedupProperties]: #get-dedupproperties '```&#10;Get-DedupProperties&#10;```&#10;Gets Data Deduplication information.'
[Clear-Disk]: #clear-disk '```&#10;Clear-Disk&#10;```&#10;Cleans a disk by removing all partition information and un-initializing it, erasing all data on the disk.'
[Get-Disk]: #get-disk '```&#10;Get-Disk&#10;```&#10;Gets one or more disks visible to the operating system.'
[Initialize-Disk]: #initialize-disk '```&#10;Initialize-Disk&#10;```&#10;Initializes a RAW disk for first time use, enabling the disk to be formatted and used to store data.'
[Set-Disk]: #set-disk '```&#10;Set-Disk&#10;```&#10;Takes a Disk object or unique disk identifiers and a set of attributes, and updates the physical disk on the system.'
[Update-Disk]: #update-disk '```&#10;Update-Disk&#10;```&#10;Updates cached information about the specified Disk object only'
[Dismount-DiskImage]: #dismount-diskimage '```&#10;Dismount-DiskImage&#10;```&#10;Dismounts a disk image (virtual hard disk or ISO) so that it can no longer be accessed as a disk.'
[Get-DiskImage]: #get-diskimage '```&#10;Get-DiskImage&#10;```&#10;Gets one or more disk image objects (virtual hard disk or ISO).'
[Mount-DiskImage]: #mount-diskimage '```&#10;Mount-DiskImage&#10;```&#10;Mounts a previously created disk image (virtual hard disk or ISO), making it appear as a normal disk.'
[Get-DiskStorageNodeView]: #get-diskstoragenodeview '```&#10;Get-DiskStorageNodeView&#10;```&#10;Gets the view of a disk from a storage node.'
[Get-FileIntegrity]: #get-fileintegrity '```&#10;Get-FileIntegrity&#10;```&#10;Gets integrity information for a file on an ReFS volume.'
[Repair-FileIntegrity]: #repair-fileintegrity '```&#10;Repair-FileIntegrity&#10;```&#10;Repairs a corrupted file on an NTFS or ReFS volume.'
[Set-FileIntegrity]: #set-fileintegrity '```&#10;Set-FileIntegrity&#10;```&#10;Sets integrity for a file on an ReFS volume.'
[Debug-FileShare]: #debug-fileshare '```&#10;Debug-FileShare&#10;```&#10;Finds problems with a file share and recommends solutions.'
[Get-FileShare]: #get-fileshare '```&#10;Get-FileShare&#10;```&#10;Retrieves file share objects and their properties.'
[New-FileShare]: #new-fileshare '```&#10;New-FileShare&#10;```&#10;Creates an access point for a remote file share.'
[Remove-FileShare]: #remove-fileshare '```&#10;Remove-FileShare&#10;```&#10;Removes a file share.'
[Set-FileShare]: #set-fileshare '```&#10;Set-FileShare&#10;```&#10;Modifies a file share.'
[Block-FileShareAccess]: #block-fileshareaccess '```&#10;Block-FileShareAccess&#10;```&#10;Blocks access to a file share.'
[Grant-FileShareAccess]: #grant-fileshareaccess '```&#10;Grant-FileShareAccess&#10;```&#10;Grants access to a file share.'
[Revoke-FileShareAccess]: #revoke-fileshareaccess '```&#10;Revoke-FileShareAccess&#10;```&#10;Revokes access to a file share.'
[Unblock-FileShareAccess]: #unblock-fileshareaccess '```&#10;Unblock-FileShareAccess&#10;```&#10;Unblocks access to a file share.'
[Get-FileShareAccessControlEntry]: #get-fileshareaccesscontrolentry '```&#10;Get-FileShareAccessControlEntry&#10;```&#10;Retrieves an access control entry for the share corresponding to a single account.'
[Set-FileStorageTier]: #set-filestoragetier '```&#10;Set-FileStorageTier&#10;```&#10;Assign a file to a storage tier&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 133'
[Clear-FileStorageTier]: #clear-filestoragetier '```&#10;Clear-FileStorageTier&#10;```&#10;Unpins a file from the specified storage tier.'
[Get-FileStorageTier]: #get-filestoragetier '```&#10;Get-FileStorageTier&#10;```&#10;Gets the files assigned to a Storage tier on a volume, and their status.'
[Update-HostStorageCache]: #update-hoststoragecache '```&#10;Update-HostStorageCache&#10;```&#10;Initiates an update on the host storage cache to reflect the current status of storage.'
[Get-InitiatorId]: #get-initiatorid '```&#10;Get-InitiatorId&#10;```&#10;Gets the InitiatorID objects for the specified iSCSI initiators.'
[Remove-InitiatorId]: #remove-initiatorid '```&#10;Remove-InitiatorId&#10;```&#10;Removes an initiator identifier (ID).'
[Remove-InitiatorIdFromMaskingSet]: #remove-initiatoridfrommaskingset '```&#10;Remove-InitiatorIdFromMaskingSet&#10;```&#10;Removes an initiator identifier (ID) from a masking set.'
[Add-InitiatorIdToMaskingSet]: #add-initiatoridtomaskingset '```&#10;Add-InitiatorIdToMaskingSet&#10;```&#10;Adds an initiator ID to an existing masking set, granting the host associated with the initiator ID access to the virtual disk and target port resources defined in the masking set.'
[Get-InitiatorPort]: #get-initiatorport '```&#10;Get-InitiatorPort&#10;```&#10;Gets one or more host bus adapter (HBA) initiator ports.'
[Set-InitiatorPort]: #set-initiatorport '```&#10;Set-InitiatorPort&#10;```&#10;Sets properties on the InitiatorPort object.'
[Get-MaskingSet]: #get-maskingset '```&#10;Get-MaskingSet&#10;```&#10;Gets masking sets.'
[New-MaskingSet]: #new-maskingset '```&#10;New-MaskingSet&#10;```&#10;Creates a new masking set.'
[Remove-MaskingSet]: #remove-maskingset '```&#10;Remove-MaskingSet&#10;```&#10;Removes a masking set.'
[Rename-MaskingSet]: #rename-maskingset '```&#10;Rename-MaskingSet&#10;```&#10;Renames an existing masking set.'
[Get-OffloadDataTransferSetting]: #get-offloaddatatransfersetting '```&#10;Get-OffloadDataTransferSetting&#10;```&#10;Returns offloaded data transfer (ODX) settings for the specified subsystem.'
[Get-Partition]: #get-partition '```&#10;Get-Partition&#10;```&#10;Returns a list of all partition objects visible on all disks, or optionally a filtered list using specified parameters.'
[New-Partition]: #new-partition '```&#10;New-Partition&#10;```&#10;Creates a new partition on an existing Disk object.'
[Remove-Partition]: #remove-partition '```&#10;Remove-Partition&#10;```&#10;Deletes the specified Partition object on an existing disk and any underlying Volume objects.'
[Resize-Partition]: #resize-partition '```&#10;Resize-Partition&#10;```&#10;Resizes a partition and the underlying file system.'
[Set-Partition]: #set-partition '```&#10;Set-Partition&#10;```&#10;Sets attributes of a partition, such as active, read-only, and offline states.'
[Add-PartitionAccessPath]: #add-partitionaccesspath '```&#10;Add-PartitionAccessPath&#10;```&#10;Adds an access path such as a drive letter or folder to a partition.'
[Remove-PartitionAccessPath]: #remove-partitionaccesspath '```&#10;Remove-PartitionAccessPath&#10;```&#10;Removes an access path such as a drive letter or folder from a partition.'
[Get-PartitionSupportedSize]: #get-partitionsupportedsize '```&#10;Get-PartitionSupportedSize&#10;```&#10;Returns information on supported partition sizes for the specified Disk object.'
[Add-PhysicalDisk]: #add-physicaldisk '```&#10;Add-PhysicalDisk&#10;```&#10;Adds a physical disk to the specified storage pool or manually assigns a physical disk to a specific virtual disk.'
[Get-PhysicalDisk]: #get-physicaldisk '```&#10;Get-PhysicalDisk&#10;```&#10;Gets a list of all PhysicalDisk objects visible across any available Storage Management Providers, or optionally a filtered list.'
[Remove-PhysicalDisk]: #remove-physicaldisk '```&#10;Remove-PhysicalDisk&#10;```&#10;Removes a physical disk from a specified storage pool.'
[Reset-PhysicalDisk]: #reset-physicaldisk '```&#10;Reset-PhysicalDisk&#10;```&#10;Resets the status of a physical disk.'
[Set-PhysicalDisk]: #set-physicaldisk '```&#10;Set-PhysicalDisk&#10;```&#10;Sets attributes on a specific physical disk.'
[Disable-PhysicalDiskIdentification]: #disable-physicaldiskidentification '```&#10;Disable-PhysicalDiskIdentification&#10;```&#10;Turns off the identification LED on the specified physical disk.'
[Enable-PhysicalDiskIdentification]: #enable-physicaldiskidentification '```&#10;Enable-PhysicalDiskIdentification&#10;```&#10;Enables the identification LED on the specified physical disk.'
[Get-PhysicalDiskStorageNodeView]: #get-physicaldiskstoragenodeview '```&#10;Get-PhysicalDiskStorageNodeView&#10;```&#10;Gets the node view of a physical disk.'
[Get-PhysicalExtent]: #get-physicalextent '```&#10;Get-PhysicalExtent&#10;```&#10;Gets physical allocations for a physical disk, storage tier, or virtual disk.'
[Get-PhysicalExtentAssociation]: #get-physicalextentassociation '```&#10;Get-PhysicalExtentAssociation&#10;```&#10;Gets the physical disk, storage tier, or virtual disk that is associated with a physical extent.'
[Get-ResiliencySetting]: #get-resiliencysetting '```&#10;Get-ResiliencySetting&#10;```&#10;Gets the resiliency settings (also known as storage layouts) available for creating virtual disks on the specified storage subsystem.'
[Set-ResiliencySetting]: #set-resiliencysetting '```&#10;Set-ResiliencySetting&#10;```&#10;Modifies the properties of the specified resiliency setting name.'
[Get-StorageAdvancedProperty]: #get-storageadvancedproperty '```&#10;Get-StorageAdvancedProperty&#10;```&#10;Gets the advanced properties on a storage device.'
[Get-StorageDiagnosticInfo]: #get-storagediagnosticinfo '```&#10;Get-StorageDiagnosticInfo&#10;```&#10;Gets Storage diagnostic information.'
[Start-StorageDiagnosticLog]: #start-storagediagnosticlog '```&#10;Start-StorageDiagnosticLog&#10;```&#10;Starts Storage diagnostic logging.'
[Stop-StorageDiagnosticLog]: #stop-storagediagnosticlog '```&#10;Stop-StorageDiagnosticLog&#10;```&#10;Stops a Storage diagnostic log.'
[Get-StorageEnclosure]: #get-storageenclosure '```&#10;Get-StorageEnclosure&#10;```&#10;Gets storage enclosures.'
[Disable-StorageEnclosureIdentification]: #disable-storageenclosureidentification '```&#10;Disable-StorageEnclosureIdentification&#10;```&#10;Turns off the identification LED on a storage enclosure or the slots for individual disks.'
[Enable-StorageEnclosureIdentification]: #enable-storageenclosureidentification '```&#10;Enable-StorageEnclosureIdentification&#10;```&#10;Enables the identification LED on a storage enclosure or the slots for individual disks.'
[Get-StorageEnclosureStorageNodeView]: #get-storageenclosurestoragenodeview '```&#10;Get-StorageEnclosureStorageNodeView&#10;```&#10;Gets the node view of a Storage enclosure.'
[Get-StorageEnclosureVendorData]: #get-storageenclosurevendordata '```&#10;Get-StorageEnclosureVendorData&#10;```&#10;Gets vendor-specific data for an enclosure.'
[Get-StorageFaultDomain]: #get-storagefaultdomain '```&#10;Get-StorageFaultDomain&#10;```&#10;Gets a Storage fault domain object.'
[Get-StorageFileServer]: #get-storagefileserver '```&#10;Get-StorageFileServer&#10;```&#10;Gets a storage file server.'
[New-StorageFileServer]: #new-storagefileserver '```&#10;New-StorageFileServer&#10;```&#10;Creates a storage file server.'
[Remove-StorageFileServer]: #remove-storagefileserver '```&#10;Remove-StorageFileServer&#10;```&#10;Removes a file server.'
[Set-StorageFileServer]: #set-storagefileserver '```&#10;Set-StorageFileServer&#10;```&#10;Modifies a storage file server.'
[Update-StorageFirmware]: #update-storagefirmware '```&#10;Update-StorageFirmware&#10;```&#10;Updates the firmware on a storage device.'
[Get-StorageFirmwareInformation]: #get-storagefirmwareinformation '```&#10;Get-StorageFirmwareInformation&#10;```&#10;Gets information about firmware on a storage object.'
[Get-StorageHealthAction]: #get-storagehealthaction '```&#10;Get-StorageHealthAction&#10;```&#10;Gets health-related system activities.'
[Get-StorageHealthReport]: #get-storagehealthreport '```&#10;Get-StorageHealthReport&#10;```&#10;Gets a storage health report.'
[Get-StorageHealthSetting]: #get-storagehealthsetting '```&#10;Get-StorageHealthSetting&#10;```&#10;Gets storage health service settings.'
[Remove-StorageHealthSetting]: #remove-storagehealthsetting '```&#10;Remove-StorageHealthSetting&#10;```&#10;Removes a storage health service setting.'
[Set-StorageHealthSetting]: #set-storagehealthsetting '```&#10;Set-StorageHealthSetting&#10;```&#10;Modifies a storage health service setting.'
[Disable-StorageHighAvailability]: #disable-storagehighavailability '```&#10;Disable-StorageHighAvailability&#10;```&#10;Disables a Storage resource.'
[Enable-StorageHighAvailability]: #enable-storagehighavailability '```&#10;Enable-StorageHighAvailability&#10;```&#10;Enables a disk to be added to the failover cluster.'
[Get-StorageJob]: #get-storagejob '```&#10;Get-StorageJob&#10;```&#10;Returns information about long-running Storage module jobs, such as a repair task.'
[Stop-StorageJob]: #stop-storagejob '```&#10;Stop-StorageJob&#10;```&#10;Stops storage job.'
[Disable-StorageMaintenanceMode]: #disable-storagemaintenancemode '```&#10;Disable-StorageMaintenanceMode&#10;```&#10;Disables storage maintenance mode on a fault domain.'
[Enable-StorageMaintenanceMode]: #enable-storagemaintenancemode '```&#10;Enable-StorageMaintenanceMode&#10;```&#10;Enables storage maintenance mode on a device.'
[Get-StorageNode]: #get-storagenode '```&#10;Get-StorageNode&#10;```&#10;Gets storage nodes.'
[Get-StoragePool]: #get-storagepool '```&#10;Get-StoragePool&#10;```&#10;Gets a specific storage pool, or a set of StoragePool objects either from all storage subsystems across all storage providers, or optionally a filtered subset based on specific parameters.'
[New-StoragePool]: #new-storagepool '```&#10;New-StoragePool&#10;```&#10;Creates a new storage pool using a group of physical disks.'
[Optimize-StoragePool]: #optimize-storagepool '```&#10;Optimize-StoragePool&#10;```&#10;Optimizes a Storage pool.'
[Remove-StoragePool]: #remove-storagepool '```&#10;Remove-StoragePool&#10;```&#10;Deletes a storage pool and associated VirtualDisk objects.'
[Set-StoragePool]: #set-storagepool '```&#10;Set-StoragePool&#10;```&#10;Modifies the properties of the specified storage pool.'
[Update-StoragePool]: #update-storagepool '```&#10;Update-StoragePool&#10;```&#10;Updates the metadata of a Windows Server 2012 R2 storage pool.'
[Get-StorageProvider]: #get-storageprovider '```&#10;Get-StorageProvider&#10;```&#10;Returns a list of the storage providers available on the local computer.'
[Set-StorageProvider]: #set-storageprovider '```&#10;Set-StorageProvider&#10;```&#10;Modifies whether to enable the SMP provider cache.'
[Update-StorageProviderCache]: #update-storageprovidercache '```&#10;Update-StorageProviderCache&#10;```&#10;Updates the cache of the service for a particular provider and associated child objects.'
[Get-StorageReliabilityCounter]: #get-storagereliabilitycounter '```&#10;Get-StorageReliabilityCounter&#10;```&#10;Gets storage reliability counters.'
[Reset-StorageReliabilityCounter]: #reset-storagereliabilitycounter '```&#10;Reset-StorageReliabilityCounter&#10;```&#10;Resets storage reliability counters for a disk.'
[Get-StorageSetting]: #get-storagesetting '```&#10;Get-StorageSetting&#10;```&#10;Gets a StorageSetting object.'
[Set-StorageSetting]: #set-storagesetting '```&#10;Set-StorageSetting&#10;```&#10;Adjusts or configures current storage settings of the StorageSetting object.'
[Debug-StorageSubSystem]: #debug-storagesubsystem '```&#10;Debug-StorageSubSystem&#10;```&#10;Finds problems with a storage subsystem and recommends solutions.'
[Get-StorageSubsystem]: #get-storagesubsystem '```&#10;Get-StorageSubsystem&#10;```&#10;Gets one or more StorageSubsystem objects.'
[Register-StorageSubsystem]: #register-storagesubsystem '```&#10;Register-StorageSubsystem&#10;```&#10;Connects to storage subsystems on a remote computer.'
[Set-StorageSubsystem]: #set-storagesubsystem '```&#10;Set-StorageSubsystem&#10;```&#10;Modifies the properties of a StorageSubsystem object.'
[Unregister-StorageSubsystem]: #unregister-storagesubsystem '```&#10;Unregister-StorageSubsystem&#10;```&#10;Disconnects from storage subsystems on a remote computer.'
[New-StorageSubsystemVirtualDisk]: #new-storagesubsystemvirtualdisk '```&#10;New-StorageSubsystemVirtualDisk&#10;```&#10;Allows the creation of a VirtualDisk object on a storage subsystem that does not support creation of storage pools.'
[Get-StorageTier]: #get-storagetier '```&#10;Get-StorageTier&#10;```&#10;Gets storage tiers on Windows Storage subsystems.'
[New-StorageTier]: #new-storagetier '```&#10;New-StorageTier&#10;```&#10;Creates a storage tier.'
[Remove-StorageTier]: #remove-storagetier '```&#10;Remove-StorageTier&#10;```&#10;Removes storage tiers from a storage pool.'
[Resize-StorageTier]: #resize-storagetier '```&#10;Resize-StorageTier&#10;```&#10;Increases the size of storage tiers.'
[Set-StorageTier]: #set-storagetier '```&#10;Set-StorageTier&#10;```&#10;Modifies a storage tier.'
[Get-StorageTierSupportedSize]: #get-storagetiersupportedsize '```&#10;Get-StorageTierSupportedSize&#10;```&#10;Gets the minimum and maximum possible sizes of a storage tier.'
[Get-SupportedClusterSizes]: #get-supportedclustersizes '```&#10;Get-SupportedClusterSizes&#10;```&#10;Gets the supported cluster sizes.'
[Get-SupportedFileSystems]: #get-supportedfilesystems '```&#10;Get-SupportedFileSystems&#10;```&#10;Gets the file system choices for a specified volume.'
[Get-TargetPort]: #get-targetport '```&#10;Get-TargetPort&#10;```&#10;Returns a TargetPort object associated with a specific port address and connection type.'
[Get-TargetPortal]: #get-targetportal '```&#10;Get-TargetPortal&#10;```&#10;Returns a TargetPortal object.'
[Remove-TargetPortFromMaskingSet]: #remove-targetportfrommaskingset '```&#10;Remove-TargetPortFromMaskingSet&#10;```&#10;Removes a specified target port from a masking set.'
[Add-TargetPortToMaskingSet]: #add-targetporttomaskingset '```&#10;Add-TargetPortToMaskingSet&#10;```&#10;Adds one or more target ports to a specified masking set, allowing a connection between the target ports, and any virtual disks and initiator IDs that the masking set contains.'
[Connect-VirtualDisk]: #connect-virtualdisk '```&#10;Connect-VirtualDisk&#10;```&#10;Connects a disconnected virtual disk to the specified computer when using the Windows Storage subsystem.'
[Disconnect-VirtualDisk]: #disconnect-virtualdisk '```&#10;Disconnect-VirtualDisk&#10;```&#10;Disconnects a virtual disk from the specified computer, revoking access to the virtual disk.'
[Get-VirtualDisk]: #get-virtualdisk '```&#10;Get-VirtualDisk&#10;```&#10;Returns a list of VirtualDisk objects, across all storage pools, across all providers, or optionally a filtered subset based on provided criteria.'
[Hide-VirtualDisk]: #hide-virtualdisk '```&#10;Hide-VirtualDisk&#10;```&#10;Hides the virtual disk from the host when the Storage Management Provider in use does not support masking sets.'
[New-VirtualDisk]: #new-virtualdisk '```&#10;New-VirtualDisk&#10;```&#10;Creates a new virtual disk in the specified storage pool.'
[Remove-VirtualDisk]: #remove-virtualdisk '```&#10;Remove-VirtualDisk&#10;```&#10;Deletes an existing virtual disk and reclaims the used space for use by other virtual disks in the same storage pool.'
[Repair-VirtualDisk]: #repair-virtualdisk '```&#10;Repair-VirtualDisk&#10;```&#10;Performs repairs on a virtual disk that is unhealthy.'
[Resize-VirtualDisk]: #resize-virtualdisk '```&#10;Resize-VirtualDisk&#10;```&#10;Resizes an existing virtual disk to be larger or smaller.'
[Set-VirtualDisk]: #set-virtualdisk '```&#10;Set-VirtualDisk&#10;```&#10;Modifies the attributes of an existing virtual disk.'
[Show-VirtualDisk]: #show-virtualdisk '```&#10;Show-VirtualDisk&#10;```&#10;Makes a virtual disk available to a host.'
[New-VirtualDiskClone]: #new-virtualdiskclone '```&#10;New-VirtualDiskClone&#10;```&#10;Creates a new clone of a specified virtual disk.'
[Remove-VirtualDiskFromMaskingSet]: #remove-virtualdiskfrommaskingset '```&#10;Remove-VirtualDiskFromMaskingSet&#10;```&#10;Removes a virtual disk from a specified masking set to block access to the virtual disk by an InitiatorIds object defined in the masking set.'
[New-VirtualDiskSnapshot]: #new-virtualdisksnapshot '```&#10;New-VirtualDiskSnapshot&#10;```&#10;Creates a new snapshot of the specified virtual disk.'
[Get-VirtualDiskSupportedSize]: #get-virtualdisksupportedsize '```&#10;Get-VirtualDiskSupportedSize&#10;```&#10;Returns all sizes supported by a storage pool for virtual disk creation based on the specified resiliency setting name.'
[Add-VirtualDiskToMaskingSet]: #add-virtualdisktomaskingset '```&#10;Add-VirtualDiskToMaskingSet&#10;```&#10;Adds a virtual disk to a specified masking set and grants access to the virtual disk to all initiator IDs defined in the masking set.'
[Debug-Volume]: #debug-volume '```&#10;Debug-Volume&#10;```&#10;Finds problems with a volume and recommends solutions.'
[Format-Volume]: #format-volume '```&#10;Format-Volume&#10;```&#10;Formats one or more existing volumes or a new volume on an existing partition.'
[Get-Volume]: #get-volume '```&#10;Get-Volume&#10;```&#10;Gets the specified Volume object, or all Volume objects if no filter is provided.'
[New-Volume]: #new-volume '```&#10;New-Volume&#10;```&#10;Creates a volume with the specified file system.'
[Optimize-Volume]: #optimize-volume '```&#10;Optimize-Volume&#10;```&#10;Optimizes a volume.'
[Repair-Volume]: #repair-volume '```&#10;Repair-Volume&#10;```&#10;Performs repairs on a volume.'
[Set-Volume]: #set-volume '```&#10;Set-Volume&#10;```&#10;Sets or changes the file system label of an existing volume.'
[Write-VolumeCache]: #write-volumecache '```&#10;Write-VolumeCache&#10;```&#10;Writes the file system cache to disk.'
[Get-VolumeCorruptionCount]: #get-volumecorruptioncount '```&#10;Get-VolumeCorruptionCount&#10;```&#10;Gets a count of the file system errors on the NTFS volume.'
[Get-VolumeScrubPolicy]: #get-volumescrubpolicy '```&#10;Get-VolumeScrubPolicy&#10;```&#10;Gets the status of the volume scrub policy.'
[Set-VolumeScrubPolicy]: #set-volumescrubpolicy '```&#10;Set-VolumeScrubPolicy&#10;```&#10;Sets the status of the volume scrub policy.'

- Disk
[`Clear`][Clear-Disk]<sup>[?][msdocs:Clear-Disk]</sup>
[`Get`][Get-Disk]<sup>[?][msdocs:Get-Disk]</sup>
[`Initialize`][Initialize-Disk]<sup>[?][msdocs:Initialize-Disk]</sup>
[`Set`][Set-Disk]<sup>[?][msdocs:Set-Disk]</sup>
[`Update`][Update-Disk]<sup>[?][msdocs:Update-Disk]</sup>
- FileShare
[`Debug`][Debug-FileShare]<sup>[?][msdocs:Debug-FileShare]</sup>
[`Get`][Get-FileShare]<sup>[?][msdocs:Get-FileShare]</sup>
[`New`][New-FileShare]<sup>[?][msdocs:New-FileShare]</sup>
[`Remove`][Remove-FileShare]<sup>[?][msdocs:Remove-FileShare]</sup>
[`Set`][Set-FileShare]<sup>[?][msdocs:Set-FileShare]</sup>
- Partition
[`Get`][Get-Partition]<sup>[?][msdocs:Get-Partition]</sup>
[`New`][New-Partition]<sup>[?][msdocs:New-Partition]</sup>
[`Remove`][Remove-Partition]<sup>[?][msdocs:Remove-Partition]</sup>
[`Resize`][Resize-Partition]<sup>[?][msdocs:Resize-Partition]</sup>
[`Set`][Set-Partition]<sup>[?][msdocs:Set-Partition]</sup>
- PhysicalDisk
[`Add`][Add-PhysicalDisk]<sup>[?][msdocs:Add-PhysicalDisk]</sup>
[`Get`][Get-PhysicalDisk]<sup>[?][msdocs:Get-PhysicalDisk]</sup>
[`Remove`][Remove-PhysicalDisk]<sup>[?][msdocs:Remove-PhysicalDisk]</sup>
[`Reset`][Reset-PhysicalDisk]<sup>[?][msdocs:Reset-PhysicalDisk]</sup>
[`Set`][Set-PhysicalDisk]<sup>[?][msdocs:Set-PhysicalDisk]</sup>
- Volume
[`Debug`][Debug-Volume]<sup>[?][msdocs:Debug-Volume]</sup>
[`Format`][Format-Volume]<sup>[?][msdocs:Format-Volume]</sup>
[`Get`][Get-Volume]<sup>[?][msdocs:Get-Volume]</sup>
[`New`][New-Volume]<sup>[?][msdocs:New-Volume]</sup>
[`Optimize`][Optimize-Volume]<sup>[?][msdocs:Optimize-Volume]</sup>
[`Repair`][Repair-Volume]<sup>[?][msdocs:Repair-Volume]</sup>
[`Set`][Set-Volume]<sup>[?][msdocs:Set-Volume]</sup>
#### dhcpserver
[Add-DhcpServerInDC]: #add-dhcpserverindc '```&#10;[PS] Add-DhcpServerInDC&#10;```&#10;Adds the computer that runs the DHCP server service to the list of authorized DHCP server services in Active Directory.'
[Add-DhcpServerv4Scope]: #add-dhcpserverv4scope '```&#10;[PS] Add-DhcpServerv4Scope&#10;```&#10;Adds an IPv4 scope on the DHCP server service.'
[Set-DhcpServerv4OptionValue]: #set-dhcpserverv4optionvalue '```&#10;[PS] Set-DhcpServerv4OptionValue&#10;```&#10;Sets an IPv4 option value at the server, scope, or reservation level.'

[msdocs:Add-DhcpServerInDC]: https://docs.microsoft.com/en-us/powershell/module/DhcpServer/Add-DhcpServerInDC "Add-DhcpServerInDC documentation"
[msdocs:Add-DhcpServerv4Scope]: https://docs.microsoft.com/en-us/powershell/module/DhcpServer/Add-DhcpServerv4Scope "Add-DhcpServerv4Scope documentation"
[msdocs:Set-DhcpServerv4OptionValue]: https://docs.microsoft.com/en-us/powershell/module/DhcpServer/Set-DhcpServerv4OptionValue "Set-DhcpServerv4OptionValue documentation"

- DHCPServerInDC 
[`Add`][Add-DhcpServerInDC]<sup>[?][msdocs:Add-DhcpServerInDC]</sup>
- DHCPServerv4Scope 
[`Add`][Add-DhcpServerv4Scope]<sup>[?][msdocs:Add-DhcpServerv4Scope]</sup>
- DHCPServerv4OptionValue 
[`Set`][Set-DhcpServerv4OptionValue]<sup>[?][msdocs:Set-DhcpServerv4OptionValue]</sup>

#### dnsclient
[Get-DnsClientServerAddress]: #get-dnsclientserveraddress '```&#10;[PS] Get-DnsClientServerAddress&#10;```&#10;Gets DNS server IP addresses from the TCP/IP properties on an interface.'
[Set-DnsClientServerAddress]: #set-dnsclientserveraddress '```&#10;[PS] Set-DnsClientServerAddress&#10;```&#10;Set DNS server addresses associated with the TCP/IP properties on an interface&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 20'
[Resolve-DnsName]: #resolve-dnsname '```&#10;[PS] Resolve-DnsName&#10;```&#10;Performs a DNS name query resolution for the specified name.'

[msdocs:Get-DnsClientServerAddress]: https://docs.microsoft.com/en-us/powershell/module/dnsclient/Get-DnsClientServerAddress "Get-DnsClientServerAddress"
[msdocs:Set-DnsClientServerAddress]: https://docs.microsoft.com/en-us/powershell/module/dnsclient/Set-DnsClientServerAddress "Set-DnsClientServerAddress"
[msdocs:Resolve-DnsName]: https://docs.microsoft.com/en-us/powershell/module/dnsclient/Resolve-DnsName "Resolve-DnsName"

- DnsClientServerAddress
[`Get`][Get-DnsClientServerAddress]<sup>[?][msdocs:Get-DnsClientServerAddress]</sup>
[`Set`][Set-DnsClientServerAddress]<sup>[?][msdocs:Set-DnsClientServerAddress]</sup>
- DnsName
[`Resolve`][Resolve-DnsName]<sup>[?][msdocs:Resolve-DnsName]</sup>
#### grouppolicy
[Backup-GPO]: #backup-gpo '```&#10;[PS] Backup-GPO&#10;```&#10;Backs up one GPO or all the GPOs in a domain.'
[Copy-GPO]: #copy-gpo '```&#10;[PS] Copy-GPO&#10;```&#10;Copies a GPO.'
[Get-GPInheritance]: #get-gpinheritance '```&#10;[PS] Get-GPInheritance&#10;```&#10;Gets Group Policy inheritance information for a specified domain or OU.'
[Get-GPO]: #get-gpo '```&#10;[PS] Get-GPO&#10;```&#10;Gets one GPO or all the GPOs in a domain.'
[Get-GPOReport]: #get-gporeport '```&#10;[PS] Get-GPOReport&#10;```&#10;Generates a report either in XML or HTML format for a specified GPO or for all GPOs in a domain.'
[Get-GPPermission]: #get-gppermission '```&#10;[PS] Get-GPPermission&#10;```&#10;Gets the permission level for one or more security principals on a specified GPO.'
[Get-GPPrefRegistryValue]: #get-gpprefregistryvalue '```&#10;[PS] Get-GPPrefRegistryValue&#10;```&#10;Gets one or more Registry preference items under either Computer Configuration or User Configuration in a GPO.'
[Get-GPRegistryValue]: #get-gpregistryvalue '```&#10;[PS] Get-GPRegistryValue&#10;```&#10;Gets one or more registry-based policy settings under either Computer Configuration or User Configuration in a GPO.'
[Get-GPResultantSetOfPolicy]: #get-gpresultantsetofpolicy '```&#10;[PS] Get-GPResultantSetOfPolicy&#10;```&#10;Gets and writes the RSoP information for a user, a computer, or both to a file.'
[Get-GPStarterGPO]: #get-gpstartergpo '```&#10;[PS] Get-GPStarterGPO&#10;```&#10;Gets one Starter GPO or all Starter GPOs in a domain.'
[Import-GPO]: #import-gpo '```&#10;[PS] Import-GPO&#10;```&#10;Imports the Group Policy settings from a backed-up GPO into a specified GPO.'
[Invoke-GPUpdate]: #invoke-gpupdate '```&#10;[PS] Invoke-GPUpdate&#10;```&#10;Schedules a remote Group Policy refresh on the specified computer.'
[New-GPLink]: #new-gplink '```&#10;[PS] New-GPLink&#10;```&#10;Links a GPO to a site, domain, or OU.'
[New-GPO]: #new-gpo '```&#10;[PS] New-GPO&#10;```&#10;Creates a GPO.'
[New-GPStarterGPO]: #new-gpstartergpo '```&#10;[PS] New-GPStarterGPO&#10;```&#10;Creates a Starter GPO.'
[Remove-GPLink]: #remove-gplink '```&#10;[PS] Remove-GPLink&#10;```&#10;Removes a GPO link from a site, domain or OU.'
[Remove-GPO]: #remove-gpo '```&#10;[PS] Remove-GPO&#10;```&#10;Removes a GPO.'
[Remove-GPPrefRegistryValue]: #remove-gpprefregistryvalue '```&#10;[PS] Remove-GPPrefRegistryValue&#10;```&#10;Removes one or more Registry preference items from either Computer Configuration or User Configuration in a GPO.'
[Remove-GPRegistryValue]: #remove-gpregistryvalue '```&#10;[PS] Remove-GPRegistryValue&#10;```&#10;Removes one or more registry-based policy settings from either Computer Configuration or User Configuration in a GPO.'
[Rename-GPO]: #rename-gpo '```&#10;[PS] Rename-GPO&#10;```&#10;Assigns a new display name to a GPO.'
[Restore-GPO]: #restore-gpo '```&#10;[PS] Restore-GPO&#10;```&#10;Restores one GPO or all GPOs in a domain from one or more GPO backup files.'
[Set-GPInheritance]: #set-gpinheritance '```&#10;[PS] Set-GPInheritance&#10;```&#10;Blocks or unblocks inheritance for a specified domain or organizational unit.'
[Set-GPLink]: #set-gplink '```&#10;[PS] Set-GPLink&#10;```&#10;Sets the properties of the specified GPO link.'
[Set-GPPermission]: #set-gppermission '```&#10;[PS] Set-GPPermission&#10;```&#10;Grants a level of permissions to a security principal for one GPO or all the GPOs in a domain.'
[Set-GPPrefRegistryValue]: #set-gpprefregistryvalue '```&#10;[PS] Set-GPPrefRegistryValue&#10;```&#10;Configures a Registry preference item under either Computer Configuration or User Configuration in a GPO.'
[Set-GPRegistryValue]: #set-gpregistryvalue '```&#10;[PS] Set-GPRegistryValue&#10;```&#10;Configures one or more registry-based policy settings under either Computer Configuration or User Configuration in a GPO.'

[msdocs:Backup-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Backup-GPO "Backup-GPO documentation"
[msdocs:Copy-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Copy-GPO "Copy-GPO documentation"
[msdocs:Get-GPInheritance]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPInheritance "Get-GPInheritance documentation"
[msdocs:Get-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPO "Get-GPO documentation"
[msdocs:Get-GPOReport]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPOReport "Get-GPOReport documentation"
[msdocs:Get-GPPermission]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPPermission "Get-GPPermission documentation"
[msdocs:Get-GPPrefRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPPrefRegistryValue "Get-GPPrefRegistryValue documentation"
[msdocs:Get-GPRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPRegistryValue "Get-GPRegistryValue documentation"
[msdocs:Get-GPResultantSetOfPolicy]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPResultantSetOfPolicy "Get-GPResultantSetOfPolicy documentation"
[msdocs:Get-GPStarterGPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Get-GPStarterGPO "Get-GPStarterGPO documentation"
[msdocs:Import-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Import-GPO "Import-GPO documentation"
[msdocs:Invoke-GPUpdate]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Invoke-GPUpdate "Invoke-GPUpdate documentation"
[msdocs:New-GPLink]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/New-GPLink "New-GPLink documentation"
[msdocs:New-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/New-GPO "New-GPO documentation"
[msdocs:New-GPStarterGPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/New-GPStarterGPO "New-GPStarterGPO documentation"
[msdocs:Remove-GPLink]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Remove-GPLink "Remove-GPLink documentation"
[msdocs:Remove-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Remove-GPO "Remove-GPO documentation"
[msdocs:Remove-GPPrefRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Remove-GPPrefRegistryValue "Remove-GPPrefRegistryValue documentation"
[msdocs:Remove-GPRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Remove-GPRegistryValue "Remove-GPRegistryValue documentation"
[msdocs:Rename-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Rename-GPO "Rename-GPO documentation"
[msdocs:Restore-GPO]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Restore-GPO "Restore-GPO documentation"
[msdocs:Set-GPInheritance]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Set-GPInheritance "Set-GPInheritance documentation"
[msdocs:Set-GPLink]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Set-GPLink "Set-GPLink documentation"
[msdocs:Set-GPPermission]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Set-GPPermission "Set-GPPermission documentation"
[msdocs:Set-GPPrefRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Set-GPPrefRegistryValue "Set-GPPrefRegistryValue documentation"
[msdocs:Set-GPRegistryValue]: https://docs.microsoft.com/en-us/powershell/module/GroupPolicy/Set-GPRegistryValue "Set-GPRegistryValue documentation"

- GPUpdate [`Invoke`][Invoke-GPUpdate]<sup>[?][msdocs:Invoke-GPUpdate]</sup>
#### hyper-v
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

[Convert-VHD]: #convert-vhd '```&#10;[PS] Convert-VHD&#10;```&#10;Converts the format, version type, and block size of a virtual hard disk file.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Dismount-VHD]: #dismount-vhd '```&#10;[PS] Dismount-VHD&#10;```&#10;Dismounts a virtual hard disk.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 92'
[Get-VHD]: #get-vhd '```&#10;[PS] Get-VHD&#10;```&#10;Gets the virtual hard disk object associated with a virtual hard disk.'
[Merge-VHD]: #merge-vhd '```&#10;[PS] Merge-VHD&#10;```&#10;Merges virtual hard disks.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Mount-VHD]: #mount-vhd '```&#10;[PS] Mount-VHD&#10;```&#10;Mounts one or more virtual hard disks.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 92'
[New-VHD]: #new-vhd '```&#10;[PS] New-VHD&#10;```&#10;Creates one or more new virtual hard disks.'
[Optimize-VHD]: #optimize-vhd '```&#10;[PS] Optimize-VHD&#10;```&#10;Optimizes the allocation of space used by virtual hard disk files, except for fixed virtual hard disks.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Resize-VHD]: #resize-vhd '```&#10;[PS] Resize-VHD&#10;```&#10;Resizes a virtual hard disk.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Set-VHD]: #set-vhd '```&#10;[PS] Set-VHD&#10;```&#10;Sets properties associated with a virtual hard disk.'
[Test-VHD]: #test-vhd '```&#10;[PS] Test-VHD&#10;```&#10;Tests a virtual hard disk for any problems that would make it unusable.'
[New-VHD]: #new-vhd '```&#10;[PS] New-VHD&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 90, 219, 223'
[Checkpoint-VM]: #checkpoint-vm '```&#10;[PS] Checkpoint-VM&#10;```&#10;Creates a checkpoint of a virtual machine.'
[Compare-VM]: #compare-vm '```&#10;[PS] Compare-VM&#10;```&#10;Compares a virtual machine and a virtual machine host for compatibility, returning a compatibility report.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'
[Debug-VM]: #debug-vm '```&#10;[PS] Debug-VM&#10;```&#10;Debugs a virtual machine.'
[Export-VM]: #export-vm '```&#10;[PS] Export-VM&#10;```&#10;Exports a virtual machine to disk.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 210'
[Get-VM]: #get-vm '```&#10;[PS] Get-VM&#10;```&#10;Gets the virtual machines from one or more Hyper-V hosts.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 177'
[Import-VM]: #import-vm '```&#10;[PS] Import-VM&#10;```&#10;Imports a virtual machine from a file.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 211'
[Measure-VM]: #measure-vm '```&#10;[PS] Measure-VM&#10;```&#10;Reports resource utilization data for one or more virtual machines.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 194, 234-235'
[Move-VM]: #move-vm '```&#10;[PS] Move-VM&#10;```&#10;Moves a virtual machine to a new Hyper-V host.'
[New-VM]: #new-vm '```&#10;[PS] New-VM&#10;```&#10;Creates a new virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 47, 184, 197'
[Optimize-VM]: #optimize-vm '```&#10;[PS] Optimize-VM&#10;```&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[Remove-VM]: #remove-vm '```&#10;[PS] Remove-VM&#10;```&#10;Deletes a virtual machine.'
[Rename-VM]: #rename-vm '```&#10;[PS] Rename-VM&#10;```&#10;Renames a virtual machine.'
[Repair-VM]: #repair-vm '```&#10;[PS] Repair-VM&#10;```&#10;Repairs one or more virtual machines.'
[Restart-VM]: #restart-vm '```&#10;[PS] Restart-VM&#10;```&#10;Restarts a virtual machine.'
[Resume-VM]: #resume-vm '```&#10;[PS] Resume-VM&#10;```&#10;Resumes a suspended (paused) virtual machine.'
[Save-VM]: #save-vm '```&#10;[PS] Save-VM&#10;```&#10;Saves a virtual machine.'
[Set-VM]: #set-vm '```&#10;[PS] Set-VM&#10;```&#10;Configures a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 231'
[Start-VM]: #start-vm '```&#10;[PS] Start-VM&#10;```&#10;Starts a virtual machine.'
[Stop-VM]: #stop-vm '```&#10;[PS] Stop-VM&#10;```&#10;Shuts down, turns off, or saves a virtual machine.'
[Suspend-VM]: #suspend-vm '```&#10;[PS] Suspend-VM&#10;```&#10;Suspends, or pauses, a virtual machine.'
[Get-VMBios]: #get-vmbios '```&#10;[PS] Get-VMBios&#10;```&#10;Gets the BIOS of a virtual machine or snapshot.'
[Set-VMBios]: #set-vmbios '```&#10;[PS] Set-VMBios&#10;```&#10;Configures the BIOS of a Generation 1 virtual machine.'
[Get-VMComPort]: #get-vmcomport '```&#10;[PS] Get-VMComPort&#10;```&#10;Gets the COM ports of a virtual machine or snapshot.'
[Set-VMComPort]: #set-vmcomport '```&#10;[PS] Set-VMComPort&#10;```&#10;Configures the COM port of a virtual machine.'
[Get-VMConnectAccess]: #get-vmconnectaccess '```&#10;[PS] Get-VMConnectAccess&#10;```&#10;Gets entries showing users and the virtual machines to which they can connect on one or more Hyper-V hosts.'
[Grant-VMConnectAccess]: #grant-vmconnectaccess '```&#10;[PS] Grant-VMConnectAccess&#10;```&#10;Grants a user or users access to connect to a virtual machine or machines.'
[Revoke-VMConnectAccess]: #revoke-vmconnectaccess '```&#10;[PS] Revoke-VMConnectAccess&#10;```&#10;Revokes access for one or more users to connect to a one or more virtual machines.'
[Disable-VMConsoleSupport]: #disable-vmconsolesupport '```&#10;[PS] Disable-VMConsoleSupport&#10;```&#10;Disables keyboard, video, and mouse for virtual machines.'
[Enable-VMConsoleSupport]: #enable-vmconsolesupport '```&#10;[PS] Enable-VMConsoleSupport&#10;```&#10;Enables keyboard, video, and mouse for virtual machines.'
[Add-VMDvdDrive]: #add-vmdvddrive '```&#10;[PS] Add-VMDvdDrive&#10;```&#10;Adds a DVD drive to a virtual machine.'
[Get-VMDvdDrive]: #get-vmdvddrive '```&#10;[PS] Get-VMDvdDrive&#10;```&#10;Gets the DVD drives attached to a virtual machine or snapshot.'
[Remove-VMDvdDrive]: #remove-vmdvddrive '```&#10;[PS] Remove-VMDvdDrive&#10;```&#10;Deletes a DVD drive from a virtual machine.'
[Set-VMDvdDrive]: #set-vmdvddrive '```&#10;[PS] Set-VMDvdDrive&#10;```&#10;Configures a virtual DVD drive.'
[Disable-VMEventing]: #disable-vmeventing '```&#10;[PS] Disable-VMEventing&#10;```&#10;Disables virtual machine eventing.'
[Enable-VMEventing]: #enable-vmeventing '```&#10;[PS] Enable-VMEventing&#10;```&#10;Enables virtual machine eventing.'
[Complete-VMFailover]: #complete-vmfailover '```&#10;[PS] Complete-VMFailover&#10;```&#10;Completes the failover process of a VM on the Replica server.'
[Start-VMFailover]: #start-vmfailover '```&#10;[PS] Start-VMFailover&#10;```&#10;Starts failover on a virtual machine.'
[Stop-VMFailover]: #stop-vmfailover '```&#10;[PS] Stop-VMFailover&#10;```&#10;Stops failover of a virtual machine.'
[Add-VMFibreChannelHba]: #add-vmfibrechannelhba '```&#10;[PS] Add-VMFibreChannelHba&#10;```&#10;Adds a virtual Fibre Channel host bus adapter to a virtual machine.'
[Get-VMFibreChannelHba]: #get-vmfibrechannelhba '```&#10;[PS] Get-VMFibreChannelHba&#10;```&#10;Gets the Fibre Channel host bus adapters associated with one or more virtual machines.'
[Remove-VMFibreChannelHba]: #remove-vmfibrechannelhba '```&#10;[PS] Remove-VMFibreChannelHba&#10;```&#10;Removes a Fibre Channel host bus adapter from a virtual machine.'
[Set-VMFibreChannelHba]: #set-vmfibrechannelhba '```&#10;[PS] Set-VMFibreChannelHba&#10;```&#10;Configures a Fibre Channel host bus adapter on a virtual machine.'
[Copy-VMFile]: #copy-vmfile '```&#10;[PS] Copy-VMFile&#10;```&#10;Copies a file to a virtual machine.'
[Get-VMFirmware]: #get-vmfirmware '```&#10;[PS] Get-VMFirmware&#10;```&#10;Gets the firmware configuration of a virtual machine.'
[Set-VMFirmware]: #set-vmfirmware '```&#10;[PS] Set-VMFirmware&#10;```&#10;Sets the firmware configuration of a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 208'
[Get-VMFloppyDiskDrive]: #get-vmfloppydiskdrive '```&#10;[PS] Get-VMFloppyDiskDrive&#10;```&#10;Gets the floppy disk drives of a virtual machine or snapshot.'
[Set-VMFloppyDiskDrive]: #set-vmfloppydiskdrive '```&#10;[PS] Set-VMFloppyDiskDrive&#10;```&#10;Configures a virtual floppy disk drive.'
[Get-VMGroup]: #get-vmgroup '```&#10;[PS] Get-VMGroup&#10;```&#10;Gets virtual machine groups.'
[New-VMGroup]: #new-vmgroup '```&#10;[PS] New-VMGroup&#10;```&#10;Creates a virtual machine group.'
[Remove-VMGroup]: #remove-vmgroup '```&#10;[PS] Remove-VMGroup&#10;```&#10;Removes a virtual machine group.'
[Rename-VMGroup]: #rename-vmgroup '```&#10;[PS] Rename-VMGroup&#10;```&#10;Renames virtual machine groups.'
[Add-VMGroupMember]: #add-vmgroupmember '```&#10;[PS] Add-VMGroupMember&#10;```&#10;Adds group members to a virtual machine group.'
[Remove-VMGroupMember]: #remove-vmgroupmember '```&#10;[PS] Remove-VMGroupMember&#10;```&#10;Removes members from a virtual machine group.'
[Add-VMHardDiskDrive]: #add-vmharddiskdrive '```&#10;[PS] Add-VMHardDiskDrive&#10;```&#10;Adds a hard disk drive to a virtual machine.'
[Get-VMHardDiskDrive]: #get-vmharddiskdrive '```&#10;[PS] Get-VMHardDiskDrive&#10;```&#10;Gets the virtual hard disk drives attached to one or more virtual machines.'
[Remove-VMHardDiskDrive]: #remove-vmharddiskdrive '```&#10;[PS] Remove-VMHardDiskDrive&#10;```&#10;Deletes a hard disk drive from a virtual machine.'
[Set-VMHardDiskDrive]: #set-vmharddiskdrive '```&#10;[PS] Set-VMHardDiskDrive&#10;```&#10;Configures a virtual hard disk.'
[Get-VMHost]: #get-vmhost '```&#10;[PS] Get-VMHost&#10;```&#10;Gets a Hyper-V host.'
[Set-VMHost]: #set-vmhost '```&#10;[PS] Set-VMHost&#10;```&#10;Configure a Hyper-V host'
[Get-VMHostCluster]: #get-vmhostcluster '```&#10;[PS] Get-VMHostCluster&#10;```&#10;Gets virtual machine host clusters.'
[Set-VMHostCluster]: #set-vmhostcluster '```&#10;[PS] Set-VMHostCluster&#10;```&#10;Configures a virtual machine host cluster.'
[Get-VMHostNumaNode]: #get-vmhostnumanode '```&#10;[PS] Get-VMHostNumaNode&#10;```&#10;Gets the NUMA topology of a virtual machine host.'
[Get-VMHostNumaNodeStatus]: #get-vmhostnumanodestatus '```&#10;[PS] Get-VMHostNumaNodeStatus&#10;```&#10;Gets the status of the virtual machines on the non-uniform memory access (NUMA) nodes of a virtual machine host or hosts.'
[Get-VMHostSupportedVersion]: #get-vmhostsupportedversion '```&#10;[PS] Get-VMHostSupportedVersion&#10;```&#10;Returns a list of virtual machine configuration versions that are supported on a host.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 209'
[Get-VMIdeController]: #get-vmidecontroller '```&#10;[PS] Get-VMIdeController&#10;```&#10;Gets the IDE controllers of a virtual machine or snapshot.'
[Import-VMInitialReplication]: #import-vminitialreplication '```&#10;[PS] Import-VMInitialReplication&#10;```&#10;Imports initial replication files for a Replica virtual machine to complete the initial replication when using external media as the source.'
[Start-VMInitialReplication]: #start-vminitialreplication '```&#10;[PS] Start-VMInitialReplication&#10;```&#10;Starts replication of a virtual machine.'
[Stop-VMInitialReplication]: #stop-vminitialreplication '```&#10;[PS] Stop-VMInitialReplication&#10;```&#10;Stops an ongoing initial replication.'
[Disable-VMIntegrationService]: #disable-vmintegrationservice '```&#10;[PS] Disable-VMIntegrationService&#10;```&#10;Disables an integration service on a virtual machine.'
[Enable-VMIntegrationService]: #enable-vmintegrationservice '```&#10;[PS] Enable-VMIntegrationService&#10;```&#10;Enables an integration service on a virtual machine.'
[Get-VMIntegrationService]: #get-vmintegrationservice '```&#10;[PS] Get-VMIntegrationService&#10;```&#10;Gets the integration services of a virtual machine or snapshot.'
[Get-VMKeyProtector]: #get-vmkeyprotector '```&#10;[PS] Get-VMKeyProtector&#10;```&#10;Retrieves a key protector for a virtual machine.'
[Set-VMKeyProtector]: #set-vmkeyprotector '```&#10;[PS] Set-VMKeyProtector&#10;```&#10;Configures a key protector for a virtual machine.'
[Get-VMMemory]: #get-vmmemory '```&#10;[PS] Get-VMMemory&#10;```&#10;Gets the memory of a virtual machine or snapshot.'
[Set-VMMemory]: #set-vmmemory '```&#10;[PS] Set-VMMemory&#10;```&#10;Configures the memory of a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 185'
[Disable-VMMigration]: #disable-vmmigration '```&#10;[PS] Disable-VMMigration&#10;```&#10;Disables migration on one or more virtual machine hosts.'
[Enable-VMMigration]: #enable-vmmigration '```&#10;[PS] Enable-VMMigration&#10;```&#10;Enables migration on one or more virtual machine hosts.'
[Add-VMMigrationNetwork]: #add-vmmigrationnetwork '```&#10;[PS] Add-VMMigrationNetwork&#10;```&#10;Adds a network for virtual machine migration on one or more virtual machine hosts.'
[Get-VMMigrationNetwork]: #get-vmmigrationnetwork '```&#10;[PS] Get-VMMigrationNetwork&#10;```&#10;Gets the networks added for migration to one or more virtual machine hosts.'
[Remove-VMMigrationNetwork]: #remove-vmmigrationnetwork '```&#10;[PS] Remove-VMMigrationNetwork&#10;```&#10;Removes a network from use with migration.'
[Set-VMMigrationNetwork]: #set-vmmigrationnetwork '```&#10;[PS] Set-VMMigrationNetwork&#10;```&#10;Sets the subnet, subnet mask, and/or priority of a migration network.'
[Add-VMNetworkAdapter]: #add-vmnetworkadapter '```&#10;[PS] Add-VMNetworkAdapter&#10;```&#10;Adds a virtual network adapter to a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 237'
[Connect-VMNetworkAdapter]: #connect-vmnetworkadapter '```&#10;[PS] Connect-VMNetworkAdapter&#10;```&#10;Connects a virtual network adapter to a virtual switch.'
[Disconnect-VMNetworkAdapter]: #disconnect-vmnetworkadapter '```&#10;[PS] Disconnect-VMNetworkAdapter&#10;```&#10;Disconnects a virtual network adapter from a virtual switch or Ethernet resource pool.'
[Get-VMNetworkAdapter]: #get-vmnetworkadapter '```&#10;[PS] Get-VMNetworkAdapter&#10;```&#10;Gets the virtual network adapters of a virtual machine, snapshot, management operating system, or of a virtual machine and management operating system.'
[Remove-VMNetworkAdapter]: #remove-vmnetworkadapter '```&#10;[PS] Remove-VMNetworkAdapter&#10;```&#10;Removes one or more virtual network adapters from a virtual machine.'
[Rename-VMNetworkAdapter]: #rename-vmnetworkadapter '```&#10;[PS] Rename-VMNetworkAdapter&#10;```&#10;Renames a virtual network adapter on a virtual machine or on the management operating system.'
[Set-VMNetworkAdapter]: #set-vmnetworkadapter '```&#10;[PS] Set-VMNetworkAdapter&#10;```&#10;Configures features of the virtual network adapter in a virtual machine or the management operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 255'
[Test-VMNetworkAdapter]: #test-vmnetworkadapter '```&#10;[PS] Test-VMNetworkAdapter&#10;```&#10;Tests connectivity between virtual machines.'
[Add-VMNetworkAdapterAcl]: #add-vmnetworkadapteracl '```&#10;[PS] Add-VMNetworkAdapterAcl&#10;```&#10;Creates an ACL to apply to the traffic through a virtual machine network adapter.'
[Get-VMNetworkAdapterAcl]: #get-vmnetworkadapteracl '```&#10;[PS] Get-VMNetworkAdapterAcl&#10;```&#10;Gets the ACLs configured for a virtual machine network adapter.'
[Remove-VMNetworkAdapterAcl]: #remove-vmnetworkadapteracl '```&#10;[PS] Remove-VMNetworkAdapterAcl&#10;```&#10;Removes an ACL applied to the traffic through a virtual network adapter.'
[Add-VMNetworkAdapterExtendedAcl]: #add-vmnetworkadapterextendedacl '```&#10;[PS] Add-VMNetworkAdapterExtendedAcl&#10;```&#10;Creates an extended ACL for a virtual network adapter.'
[Get-VMNetworkAdapterExtendedAcl]: #get-vmnetworkadapterextendedacl '```&#10;[PS] Get-VMNetworkAdapterExtendedAcl&#10;```&#10;Gets extended ACLs configured for a virtual network adapter.'
[Remove-VMNetworkAdapterExtendedAcl]: #remove-vmnetworkadapterextendedacl '```&#10;[PS] Remove-VMNetworkAdapterExtendedAcl&#10;```&#10;Removes an extended ACL for a virtual network adapter.'
[Get-VMNetworkAdapterFailoverConfiguration]: #get-vmnetworkadapterfailoverconfiguration '```&#10;[PS] Get-VMNetworkAdapterFailoverConfiguration&#10;```&#10;Gets the IP address of a virtual network adapter configured to be used when a virtual machine fails over.'
[Set-VMNetworkAdapterFailoverConfiguration]: #set-vmnetworkadapterfailoverconfiguration '```&#10;[PS] Set-VMNetworkAdapterFailoverConfiguration&#10;```&#10;Configures the IP address of a virtual network adapter to be used when a virtual machine fails over.'
[Get-VmNetworkAdapterIsolation]: #get-vmnetworkadapterisolation '```&#10;[PS] Get-VmNetworkAdapterIsolation&#10;```&#10;Gets isolation settings for a virtual network adapter.'
[Set-VmNetworkAdapterIsolation]: #set-vmnetworkadapterisolation '```&#10;[PS] Set-VmNetworkAdapterIsolation&#10;```&#10;Modifies isolation settings for a virtual network adapter.'
[Add-VmNetworkAdapterRoutingDomainMapping]: #add-vmnetworkadapterroutingdomainmapping '```&#10;[PS] Add-VmNetworkAdapterRoutingDomainMapping&#10;```&#10;Adds a routing domain and virtual subnets to a virtual network adapter.'
[Get-VMNetworkAdapterRoutingDomainMapping]: #get-vmnetworkadapterroutingdomainmapping '```&#10;[PS] Get-VMNetworkAdapterRoutingDomainMapping&#10;```&#10;Gets members of a routing domain.'
[Remove-VMNetworkAdapterRoutingDomainMapping]: #remove-vmnetworkadapterroutingdomainmapping '```&#10;[PS] Remove-VMNetworkAdapterRoutingDomainMapping&#10;```&#10;Removes a routing domain from a virtual network adapter.'
[Set-VmNetworkAdapterRoutingDomainMapping]: #set-vmnetworkadapterroutingdomainmapping '```&#10;[PS] Set-VmNetworkAdapterRoutingDomainMapping&#10;```&#10;Sets virtual subnets on a routing domain.'
[Get-VMNetworkAdapterTeamMapping]: #get-vmnetworkadapterteammapping '```&#10;[PS] Get-VMNetworkAdapterTeamMapping&#10;```&#10;'
[Remove-VMNetworkAdapterTeamMapping]: #remove-vmnetworkadapterteammapping '```&#10;[PS] Remove-VMNetworkAdapterTeamMapping&#10;```&#10;'
[Set-VMNetworkAdapterTeamMapping]: #set-vmnetworkadapterteammapping '```&#10;[PS] Set-VMNetworkAdapterTeamMapping&#10;```&#10;'
[Get-VMNetworkAdapterVlan]: #get-vmnetworkadaptervlan '```&#10;[PS] Get-VMNetworkAdapterVlan&#10;```&#10;Gets the virtual LAN settings configured on a virtual network adapter.'
[Set-VMNetworkAdapterVlan]: #set-vmnetworkadaptervlan '```&#10;[PS] Set-VMNetworkAdapterVlan&#10;```&#10;Configures the virtual LAN settings for the traffic through a virtual network adapter.'
[Get-VMProcessor]: #get-vmprocessor '```&#10;[PS] Get-VMProcessor&#10;```&#10;Gets the processor of a virtual machine or snapshot.'
[Set-VMProcessor]: #set-vmprocessor '```&#10;[PS] Set-VMProcessor&#10;```&#10;Configures one or more processors of a virtual machine.'
[Add-VMRemoteFx3dVideoAdapter]: #add-vmremotefx3dvideoadapter '```&#10;[PS] Add-VMRemoteFx3dVideoAdapter&#10;```&#10;Adds a RemoteFX video adapter in a virtual machine.'
[Get-VMRemoteFx3dVideoAdapter]: #get-vmremotefx3dvideoadapter '```&#10;[PS] Get-VMRemoteFx3dVideoAdapter&#10;```&#10;Gets the RemoteFX video adapter of a virtual machine or snapshot.'
[Remove-VMRemoteFx3dVideoAdapter]: #remove-vmremotefx3dvideoadapter '```&#10;[PS] Remove-VMRemoteFx3dVideoAdapter&#10;```&#10;Removes a RemoteFX 3D video adapter from a virtual machine.'
[Set-VMRemoteFx3dVideoAdapter]: #set-vmremotefx3dvideoadapter '```&#10;[PS] Set-VMRemoteFx3dVideoAdapter&#10;```&#10;Configures the RemoteFX 3D video adapter of a virtual machine.'
[Disable-VMRemoteFXPhysicalVideoAdapter]: #disable-vmremotefxphysicalvideoadapter '```&#10;[PS] Disable-VMRemoteFXPhysicalVideoAdapter&#10;```&#10;Disables one or more RemoteFX physical video adapters from use with RemoteFX-enabled virtual machines.'
[Enable-VMRemoteFXPhysicalVideoAdapter]: #enable-vmremotefxphysicalvideoadapter '```&#10;[PS] Enable-VMRemoteFXPhysicalVideoAdapter&#10;```&#10;Enables one or more RemoteFX physical video adapters for use with RemoteFX-enabled virtual machines.'
[Get-VMRemoteFXPhysicalVideoAdapter]: #get-vmremotefxphysicalvideoadapter '```&#10;[PS] Get-VMRemoteFXPhysicalVideoAdapter&#10;```&#10;Gets the RemoteFX physical graphics adapters on one or more Hyper-V hosts.'
[Enable-VMReplication]: #enable-vmreplication '```&#10;[PS] Enable-VMReplication&#10;```&#10;Enables replication of a virtual machine.'
[Get-VMReplication]: #get-vmreplication '```&#10;[PS] Get-VMReplication&#10;```&#10;Gets the replication settings for a virtual machine.'
[Measure-VMReplication]: #measure-vmreplication '```&#10;[PS] Measure-VMReplication&#10;```&#10;Gets replication statistics and information associated with a virtual machine.'
[Remove-VMReplication]: #remove-vmreplication '```&#10;[PS] Remove-VMReplication&#10;```&#10;Removes the replication relationship of a virtual machine.'
[Resume-VMReplication]: #resume-vmreplication '```&#10;[PS] Resume-VMReplication&#10;```&#10;Resumes a virtual machine replication that is in a state of Paused, Error, Resynchronization Required, or Suspended.'
[Set-VMReplication]: #set-vmreplication '```&#10;[PS] Set-VMReplication&#10;```&#10;Modifies the replication settings of a virtual machine.'
[Stop-VMReplication]: #stop-vmreplication '```&#10;[PS] Stop-VMReplication&#10;```&#10;Cancels an ongoing virtual machine resynchronization.'
[Suspend-VMReplication]: #suspend-vmreplication '```&#10;[PS] Suspend-VMReplication&#10;```&#10;Suspends replication of a virtual machine.'
[Get-VMReplicationAuthorizationEntry]: #get-vmreplicationauthorizationentry '```&#10;[PS] Get-VMReplicationAuthorizationEntry&#10;```&#10;Gets the authorization entries of a Replica server.'
[New-VMReplicationAuthorizationEntry]: #new-vmreplicationauthorizationentry '```&#10;[PS] New-VMReplicationAuthorizationEntry&#10;```&#10;Creates a new authorization entry that allows one or more primary servers to replicate data to a specified Replica server.'
[Remove-VMReplicationAuthorizationEntry]: #remove-vmreplicationauthorizationentry '```&#10;[PS] Remove-VMReplicationAuthorizationEntry&#10;```&#10;Removes an authorization entry from a Replica server.'
[Set-VMReplicationAuthorizationEntry]: #set-vmreplicationauthorizationentry '```&#10;[PS] Set-VMReplicationAuthorizationEntry&#10;```&#10;Modifies an authorization entry on a Replica server.'
[Test-VMReplicationConnection]: #test-vmreplicationconnection '```&#10;[PS] Test-VMReplicationConnection&#10;```&#10;Tests the connection between a primary server and a Replica server.'
[Get-VMReplicationServer]: #get-vmreplicationserver '```&#10;[PS] Get-VMReplicationServer&#10;```&#10;Gets the replication and authentication settings of a Replica server.'
[Set-VmReplicationServer]: #set-vmreplicationserver '```&#10;[PS] Set-VmReplicationServer&#10;```&#10;Configure a host as a Replica server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 300'
[Reset-VMReplicationStatistics]: #reset-vmreplicationstatistics '```&#10;[PS] Reset-VMReplicationStatistics&#10;```&#10;Resets the replication statistics of a virtual machine.'
[Disable-VMResourceMetering]: #disable-vmresourcemetering '```&#10;[PS] Disable-VMResourceMetering&#10;```&#10;Disables collection of resource utilization data for a virtual machine or resource pool.'
[Enable-VMResourceMetering]: #enable-vmresourcemetering '```&#10;[PS] Enable-VMResourceMetering&#10;```&#10;Collects resource utilization data for a virtual machine or resource pool.'
[Reset-VMResourceMetering]: #reset-vmresourcemetering '```&#10;[PS] Reset-VMResourceMetering&#10;```&#10;Resets the resource utilization data collected by Hyper-V resource metering.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 195'
[Get-VMResourcePool]: #get-vmresourcepool '```&#10;[PS] Get-VMResourcePool&#10;```&#10;Gets the resource pools on one or more virtual machine hosts.'
[Measure-VMResourcePool]: #measure-vmresourcepool '```&#10;[PS] Measure-VMResourcePool&#10;```&#10;Reports resource utilization data for one or more resource pools.'
[New-VMResourcePool]: #new-vmresourcepool '```&#10;[PS] New-VMResourcePool&#10;```&#10;Creates a resource pool.'
[Remove-VMResourcePool]: #remove-vmresourcepool '```&#10;[PS] Remove-VMResourcePool&#10;```&#10;Deletes a resource pool from one or more virtual machine hosts.'
[Rename-VMResourcePool]: #rename-vmresourcepool '```&#10;[PS] Rename-VMResourcePool&#10;```&#10;Renames a resource pool on one or more Hyper-V hosts.'
[Set-VMResourcePool]: #set-vmresourcepool '```&#10;[PS] Set-VMResourcePool&#10;```&#10;Sets the parent resource pool for a selected resource pool.'
[Connect-VMSan]: #connect-vmsan '```&#10;[PS] Connect-VMSan&#10;```&#10;Associates a host bus adapter with a virtual storage area network (SAN).'
[Disconnect-VMSan]: #disconnect-vmsan '```&#10;[PS] Disconnect-VMSan&#10;```&#10;Removes a host bus adapter from a virtual storage area network (SAN).'
[Get-VMSan]: #get-vmsan '```&#10;[PS] Get-VMSan&#10;```&#10;Gets the available virtual machine storage area networks on a Hyper-V host or hosts.'
[New-VMSan]: #new-vmsan '```&#10;[PS] New-VMSan&#10;```&#10;Creates a new virtual storage area network (SAN) on a Hyper-V host.'
[Remove-VMSan]: #remove-vmsan '```&#10;[PS] Remove-VMSan&#10;```&#10;Removes a virtual storage area network (SAN) from a Hyper-V host.'
[Rename-VMSan]: #rename-vmsan '```&#10;[PS] Rename-VMSan&#10;```&#10;Renames a virtual storage area network (SAN).'
[Set-VMSan]: #set-vmsan '```&#10;[PS] Set-VMSan&#10;```&#10;Configures a virtual storage area network (SAN) on one or more Hyper-V hosts.'
[Remove-VMSavedState]: #remove-vmsavedstate '```&#10;[PS] Remove-VMSavedState&#10;```&#10;Deletes the saved state of a saved virtual machine.'
[Add-VMScsiController]: #add-vmscsicontroller '```&#10;[PS] Add-VMScsiController&#10;```&#10;Adds a SCSI controller in a virtual machine.'
[Get-VMScsiController]: #get-vmscsicontroller '```&#10;[PS] Get-VMScsiController&#10;```&#10;Gets the SCSI controllers of a virtual machine or snapshot.'
[Remove-VMScsiController]: #remove-vmscsicontroller '```&#10;[PS] Remove-VMScsiController&#10;```&#10;Removes a SCSI controller from a virtual machine.'
[Get-VMSecurity]: #get-vmsecurity '```&#10;[PS] Get-VMSecurity&#10;```&#10;Gets security information about a virtual machine.'
[Set-VMSecurity]: #set-vmsecurity '```&#10;[PS] Set-VMSecurity&#10;```&#10;Configures security settings for a virtual machine.'
[Set-VMSecurityPolicy]: #set-vmsecuritypolicy '```&#10;[PS] Set-VMSecurityPolicy&#10;```&#10;Configures the security policy for a virtual machine.'
[Export-VMSnapshot]: #export-vmsnapshot '```&#10;[PS] Export-VMSnapshot&#10;```&#10;Exports a virtual machine checkpoint to disk.'
[Get-VMSnapshot]: #get-vmsnapshot '```&#10;[PS] Get-VMSnapshot&#10;```&#10;Gets the checkpoints associated with a virtual machine or checkpoint.'
[Remove-VMSnapshot]: #remove-vmsnapshot '```&#10;[PS] Remove-VMSnapshot&#10;```&#10;Deletes a virtual machine checkpoint.'
[Rename-VMSnapshot]: #rename-vmsnapshot '```&#10;[PS] Rename-VMSnapshot&#10;```&#10;Renames a virtual machine checkpoint.'
[Restore-VMSnapshot]: #restore-vmsnapshot '```&#10;[PS] Restore-VMSnapshot&#10;```&#10;Restores a virtual machine checkpoint.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 230'
[Move-VMStorage]: #move-vmstorage '```&#10;[PS] Move-VMStorage&#10;```&#10;Moves the storage of a virtual machine.'
[Add-VMStoragePath]: #add-vmstoragepath '```&#10;[PS] Add-VMStoragePath&#10;```&#10;Adds a path to a storage resource pool.'
[Get-VMStoragePath]: #get-vmstoragepath '```&#10;[PS] Get-VMStoragePath&#10;```&#10;Gets the storage paths in a storage resource pool.'
[Remove-VMStoragePath]: #remove-vmstoragepath '```&#10;[PS] Remove-VMStoragePath&#10;```&#10;Removes a path from a storage resource pool.'
[Add-VMSwitch]: #add-vmswitch '```&#10;[PS] Add-VMSwitch&#10;```&#10;Adds a virtual switch to an Ethernet resource pool.'
[Get-VMSwitch]: #get-vmswitch '```&#10;[PS] Get-VMSwitch&#10;```&#10;Gets virtual switches from one or more virtual Hyper-V hosts.'
[New-VMSwitch]: #new-vmswitch '```&#10;[PS] New-VMSwitch&#10;```&#10;Creates a new virtual switch on one or more virtual machine hosts.'
[Remove-VMSwitch]: #remove-vmswitch '```&#10;[PS] Remove-VMSwitch&#10;```&#10;Deletes a virtual switch.'
[Rename-VMSwitch]: #rename-vmswitch '```&#10;[PS] Rename-VMSwitch&#10;```&#10;Renames a virtual switch.'
[Set-VMSwitch]: #set-vmswitch '```&#10;[PS] Set-VMSwitch&#10;```&#10;Configures a virtual switch.'
[Disable-VMSwitchExtension]: #disable-vmswitchextension '```&#10;[PS] Disable-VMSwitchExtension&#10;```&#10;Disables one or more extensions on one or more virtual switches.'
[Enable-VMSwitchExtension]: #enable-vmswitchextension '```&#10;[PS] Enable-VMSwitchExtension&#10;```&#10;Enables one or more extensions on one or more switches.'
[Get-VMSwitchExtension]: #get-vmswitchextension '```&#10;[PS] Get-VMSwitchExtension&#10;```&#10;Gets the extensions on one or more virtual switches.'
[Get-VMSwitchExtensionPortData]: #get-vmswitchextensionportdata '```&#10;[PS] Get-VMSwitchExtensionPortData&#10;```&#10;Retrieves the status of a virtual switch extension feature applied to a virtual network adapter.'
[Add-VMSwitchExtensionPortFeature]: #add-vmswitchextensionportfeature '```&#10;[PS] Add-VMSwitchExtensionPortFeature&#10;```&#10;Adds a feature to a virtual network adapter.'
[Get-VMSwitchExtensionPortFeature]: #get-vmswitchextensionportfeature '```&#10;[PS] Get-VMSwitchExtensionPortFeature&#10;```&#10;Gets the features configured on a virtual network adapter.'
[Remove-VMSwitchExtensionPortFeature]: #remove-vmswitchextensionportfeature '```&#10;[PS] Remove-VMSwitchExtensionPortFeature&#10;```&#10;Removes a feature from a virtual network adapter.'
[Set-VMSwitchExtensionPortFeature]: #set-vmswitchextensionportfeature '```&#10;[PS] Set-VMSwitchExtensionPortFeature&#10;```&#10;Configures a feature on a virtual network adapter.'
[Get-VMSwitchExtensionSwitchData]: #get-vmswitchextensionswitchdata '```&#10;[PS] Get-VMSwitchExtensionSwitchData&#10;```&#10;Gets the status of a virtual switch extension feature applied on a virtual switch.'
[Add-VMSwitchExtensionSwitchFeature]: #add-vmswitchextensionswitchfeature '```&#10;[PS] Add-VMSwitchExtensionSwitchFeature&#10;```&#10;Adds a feature to a virtual switch.'
[Get-VMSwitchExtensionSwitchFeature]: #get-vmswitchextensionswitchfeature '```&#10;[PS] Get-VMSwitchExtensionSwitchFeature&#10;```&#10;Gets the features configured on a virtual switch.'
[Remove-VMSwitchExtensionSwitchFeature]: #remove-vmswitchextensionswitchfeature '```&#10;[PS] Remove-VMSwitchExtensionSwitchFeature&#10;```&#10;Removes a feature from a virtual switch.'
[Set-VMSwitchExtensionSwitchFeature]: #set-vmswitchextensionswitchfeature '```&#10;[PS] Set-VMSwitchExtensionSwitchFeature&#10;```&#10;Configures a feature on a virtual switch.'
[Get-VMSwitchTeam]: #get-vmswitchteam '```&#10;[PS] Get-VMSwitchTeam&#10;```&#10;Gets virtual switch teams from Hyper-V hosts.'
[Set-VMSwitchTeam]: #set-vmswitchteam '```&#10;[PS] Set-VMSwitchTeam&#10;```&#10;Configures a virtual switch team.'
[Add-VMSwitchTeamMember]: #add-vmswitchteammember '```&#10;[PS] Add-VMSwitchTeamMember&#10;```&#10;Adds members to a virtual switch team.'
[Remove-VMSwitchTeamMember]: #remove-vmswitchteammember '```&#10;[PS] Remove-VMSwitchTeamMember&#10;```&#10;Removes a member from a virtual machine switch team.'
[Get-VMSystemSwitchExtension]: #get-vmsystemswitchextension '```&#10;[PS] Get-VMSystemSwitchExtension&#10;```&#10;Gets the switch extensions installed on a virtual machine host.'
[Get-VMSystemSwitchExtensionPortFeature]: #get-vmsystemswitchextensionportfeature '```&#10;[PS] Get-VMSystemSwitchExtensionPortFeature&#10;```&#10;Gets the port-level features supported by virtual switch extensions on one or more Hyper-V hosts.'
[Get-VMSystemSwitchExtensionSwitchFeature]: #get-vmsystemswitchextensionswitchfeature '```&#10;[PS] Get-VMSystemSwitchExtensionSwitchFeature&#10;```&#10;Gets the switch-level features on one or more Hyper-V hosts.'
[Disable-VMTPM]: #disable-vmtpm '```&#10;[PS] Disable-VMTPM&#10;```&#10;Disables TPM functionality on a virtual machine.'
[Enable-VMTPM]: #enable-vmtpm '```&#10;[PS] Enable-VMTPM&#10;```&#10;Enables TPM functionality on a virtual machine.'
[Start-VMTrace]: #start-vmtrace '```&#10;[PS] Start-VMTrace&#10;```&#10;Starts tracing to a file.'
[Stop-VMTrace]: #stop-vmtrace '```&#10;[PS] Stop-VMTrace&#10;```&#10;Stops tracing to file.'
[Update-VMVersion]: #update-vmversion '```&#10;[PS] Update-VMVersion&#10;```&#10;Updates the version of virtual machines.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 209'
[Get-VMVideo]: #get-vmvideo '```&#10;[PS] Get-VMVideo&#10;```&#10;Gets video settings for virtual machines.'
[Set-VMVideo]: #set-vmvideo '```&#10;[PS] Set-VMVideo&#10;```&#10;Configures video settings for virtual machines.'

[msdocs:Convert-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Convert-VHD "Convert-VHD"
[msdocs:Dismount-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Dismount-VHD "Dismount-VHD"
[msdocs:Merge-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Merge-VHD "Merge-VHD"
[msdocs:Mount-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Mount-VHD "Mount-VHD"
[msdocs:Optimize-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Optimize-VHD "Optimize-VHD"
[msdocs:Resize-VHD]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Resize-VHD "Resize-VHD"

[Restore-VMSnapshot]: #restore-vmsnapshot '```&#10;PS C:\> Restore-VMSnapshot&#10;```&#10;Restores a virtual machine checkpoint.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 230'
[msdocs:Restore-VMSnapshot]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/Restore-VMSnapshot "Restore-VMSnapshot"

- VHD
[`Convert`][Convert-VHD]<sup>[?][msdocs:Convert-VHD]</sup>
[`Dismount`][Dismount-VHD]<sup>[?][msdocs:Dismount-VHD]</sup>
[`Merge`][Merge-VHD]<sup>[?][msdocs:Merge-VHD]</sup>
[`Mount`][Mount-VHD]<sup>[?][msdocs:Mount-VHD]</sup>
[`New`][New-VHD]<sup>[?][msdocs:New-VHD]</sup>
[`Optimize`][Optimize-VHD]<sup>[?][msdocs:Optimize-VHD]</sup>
[`Resize`][Resize-VHD]<sup>[?][msdocs:Resize-VHD]</sup>
- VM
[`Checkpoint`][Checkpoint-VM]<sup>[?][msdocs:Checkpoint-VM]</sup>
[`Compare`][Compare-VM]<sup>[?][msdocs:Compare-VM]</sup>
[`Debug`][Debug-VM]<sup>[?][msdocs:Debug-VM]</sup>
[`Export`][Export-VM]<sup>[?][msdocs:Export-VM]</sup>
[`Get`][Get-VM]<sup>[?][msdocs:Get-VM]</sup>
[`Import`][Import-VM]<sup>[?][msdocs:Import-VM]</sup>
[`Measure`][Measure-VM]<sup>[?][msdocs:Measure-VM]</sup>
[`Move`][Move-VM]<sup>[?][msdocs:Move-VM]</sup>
[`New`][New-VM]<sup>[?][msdocs:New-VM]</sup>
[`Optimize`][Optimize-VM]<sup>[?][msdocs:Optimize-VM]</sup>
[`Remove`][Remove-VM]<sup>[?][msdocs:Remove-VM]</sup>
[`Rename`][Rename-VM]<sup>[?][msdocs:Rename-VM]</sup>
[`Repair`][Repair-VM]<sup>[?][msdocs:Repair-VM]</sup>
[`Restart`][Restart-VM]<sup>[?][msdocs:Restart-VM]</sup>
[`Resume`][Resume-VM]<sup>[?][msdocs:Resume-VM]</sup>
[`Save`][Save-VM]<sup>[?][msdocs:Save-VM]</sup>
[`Set`][Set-VM]<sup>[?][msdocs:Set-VM]</sup>
[`Start`][Start-VM]<sup>[?][msdocs:Start-VM]</sup>
[`Stop`][Stop-VM]<sup>[?][msdocs:Stop-VM]</sup>
[`Suspend`][Suspend-VM]<sup>[?][msdocs:Suspend-VM]</sup>
- VMDvdDrive
[`Add`][Add-VMDvdDrive]<sup>[?][msdocs:Add-VMDvdDrive]</sup>
[`Get`][Get-VMDvdDrive]<sup>[?][msdocs:Get-VMDvdDrive]</sup>
[`Remove`][Remove-VMDvdDrive]<sup>[?][msdocs:Remove-VMDvdDrive]</sup>
[`Set`][Set-VMDvdDrive]<sup>[?][msdocs:Set-VMDvdDrive]</sup>
- VMFirmware
[`Set`][Set-VMFirmware]
- VMFibreChannelHba
[`Add`][Add-VMFibreChannelHba]<sup>[?][msdocs:Add-VMFibreChannelHba]</sup>
[`Get`][Get-VMFibreChannelHba]<sup>[?][msdocs:Get-VMFibreChannelHba]</sup>
[`Remove`][Remove-VMFibreChannelHba]<sup>[?][msdocs:Remove-VMFibreChannelHba]</sup>
[`Set`][Set-VMFibreChannelHba]<sup>[?][msdocs:Set-VMFibreChannelHba]</sup>
- VMHardDiskDrive
[`Add`][Add-VMHardDiskDrive]<sup>[?][msdocs:Add-VMHardDiskDrive]</sup>
[`Get`][Get-VMHardDiskDrive]<sup>[?][msdocs:Get-VMHardDiskDrive]</sup>
[`Remove`][Remove-VMHardDiskDrive]<sup>[?][msdocs:Remove-VMHardDiskDrive]</sup>
[`Set`][Set-VMHardDiskDrive]<sup>[?][msdocs:Set-VMHardDiskDrive]</sup>
- VMHost
[`Get`][Get-VMHost]<sup>[?][msdocs:Get-VMHost]</sup>
[`Set`][Set-VMHost]<sup>[?][msdocs:Set-VMHost]</sup>
- VMMemory
[`Get`][Get-VMMemory]<sup>[?][msdocs:Get-VMMemory]</sup>
[`Set`][Set-VMMemory]<sup>[?][msdocs:Set-VMMemory]</sup>
- VMNetworkAdapter
[`Add`][Add-VMNetworkAdapter]<sup>[?][msdocs:Add-VMNetworkAdapter]</sup>
[`Connect`][Connect-VMNetworkAdapter]<sup>[?][msdocs:Connect-VMNetworkAdapter]</sup>
[`Disconnect`][Disconnect-VMNetworkAdapter]<sup>[?][msdocs:Disconnect-VMNetworkAdapter]</sup>
[`Get`][Get-VMNetworkAdapter]<sup>[?][msdocs:Get-VMNetworkAdapter]</sup>
[`Remove`][Remove-VMNetworkAdapter]<sup>[?][msdocs:Remove-VMNetworkAdapter]</sup>
[`Rename`][Rename-VMNetworkAdapter]<sup>[?][msdocs:Rename-VMNetworkAdapter]</sup>
[`Set`][Set-VMNetworkAdapter]<sup>[?][msdocs:Set-VMNetworkAdapter]</sup>
[`Test`][Test-VMNetworkAdapter]<sup>[?][msdocs:Test-VMNetworkAdapter]</sup>
- VMProcessor
[`Get`][Get-VMProcessor]<sup>[?][msdocs:Get-VMProcessor]</sup>
[`Set`][Set-VMProcessor]<sup>[?][msdocs:Set-VMProcessor]</sup>
- VMSaN
[`Connect`][Connect-VMSan]<sup>[?][msdocs:Connect-VMSan]</sup>
[`Disconnect`][Disconnect-VMSan]<sup>[?][msdocs:Disconnect-VMSan]</sup>
[`Get`][Get-VMSan]<sup>[?][msdocs:Get-VMSan]</sup>
[`New`][New-VMSan]<sup>[?][msdocs:New-VMSan]</sup>
[`Remove`][Remove-VMSan]<sup>[?][msdocs:Remove-VMSan]</sup>
[`Rename`][Rename-VMSan]<sup>[?][msdocs:Rename-VMSan]</sup>
[`Set`][Set-VMSan]<sup>[?][msdocs:Set-VMSan]</sup>
- VMSnapshot
[`Restore`][Restore-VMSnapshot]<sup>[?][msdocs:Restore-VMSnapshot</sup>
- VMSwitch
[`Add`][Add-VMSwitch]<sup>[?][msdocs:Add-VMSwitch]</sup>
[`Get`][Get-VMSwitch]<sup>[?][msdocs:Get-VMSwitch]</sup>
[`New`][New-VMSwitch]<sup>[?][msdocs:New-VMSwitch]</sup>
[`Remove`][Remove-VMSwitch]<sup>[?][msdocs:Remove-VMSwitch]</sup>
[`Rename`][Rename-VMSwitch]<sup>[?][msdocs:Rename-VMSwitch]</sup>
[`Set`][Set-VMSwitch]<sup>[?][msdocs:Set-VMSwitch]</sup>
- VMVersion
[`Update`][Update-VMVersion]<sup>[?][msdocs:Update-VMVersion]</sup>

#### iscsi
[msdocs:Connect-IscsiTarget]: https://docs.microsoft.com/en-us/powershell/module/iscsi/Connect-IscsiTarget "Connect-IscsiTarget documentation"
[msdocs:New-IscsiTargetPortal]: https://docs.microsoft.com/en-us/powershell/module/iscsi/New-IscsiTargetPortal "New-IscsiTargetPortal documentation"

[Connect-IscsiTarget]: #connect-iscsitarget '```&#10;[PS] Connect-IscsiTarget&#10;```&#10;Establishes a connection between the local iSCSI initiator and an iSCSI target device.'
[New-IscsiTargetPortal]: #new-iscsitargetportal '```&#10;[PS] New-IscsiTargetPortal&#10;```&#10;Configures an iSCSI target portal.'

- iSCSITarget
[`Connect`][Connect-IscsiTarget]<sup>[?][msdocs:Connect-IscsiTarget]</sup>
- iSCSITargetPortal
[`New`][New-IscsiTargetPortal]<sup>[?][msdocs:New-IscsiTargetPortal]</sup>

#### iscsitarget
[msdocs:New-IscsiServerTarget]: https://docs.microsoft.com/en-us/powershell/module/IscsiTarget/New-IscsiServerTarget "New-IscsiServerTarget documentation"
[msdocs:Add-IscsiVirtualDiskTargetMapping]: https://docs.microsoft.com/en-us/powershell/module/IscsiTarget/Add-IscsiVirtualDiskTargetMapping "Add-IscsiVirtualDiskTargetMapping documentation"

[New-IscsiServerTarget]: #new-iscsiservertarget '```&#10;[PS] New-IscsiServerTarget&#10;```&#10;Creates a new iSCSI Target object with the specified name.'
[Add-IscsiVirtualDiskTargetMapping]: #add-iscsivirtualdisktargetmapping '```&#10;[PS] Add-IscsiVirtualDiskTargetMapping&#10;```&#10;Assigns a virtual disk to an iSCSI target.'

- iSCSIServerTarget 
[`New`][New-IscsiServerTarget]<sup>[?][msdocs:New-IscsiServerTarget]</sup>
- iSCSIVirtualDiskTargetMapping
[`Add`][Add-IscsiVirtualDiskTargetMapping]<sup>[?][msdocs:Add-IscsiVirtualDiskTargetMapping]</sup>

#### Microsoft.Powershell.Diagnostics
[Get-WinEvent]: #get-winevent '```&#10;[PS] Get-WinEvent&#10;```&#10;Gets events from event logs and event tracing log files on local and remote computers.'
[New-WinEvent]: #new-winevent '```&#10;[PS] New-WinEvent&#10;```&#10;Creates an ETW event for the specified event provider.'
[Get-Counter]: #get-counter '```&#10;[PS] Get-Counter&#10;```&#10;Gets performance counter data from local and remote computers.'

[msdocs:Get-WinEvent]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Diagnostics/Get-WinEvent "Get-WinEvent"
[msdocs:New-WinEvent]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Diagnostics/New-WinEvent "New-WinEvent"
[msdocs:Get-Counter]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Diagnostics/Get-Counter "Get-Counter"

- Counter [`Get`][Get-Counter]<sup>[?][msdocs:Get-Counter]</sup>
#### Microsoft.Powershell.LocalAccounts
[msdocs:Add-LocalGroupMember]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Add-LocalGroupMember "Add-LocalGroupMember"
[msdocs:Get-LocalGroupMember]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Get-LocalGroupMember "Get-LocalGroupMember"
[msdocs:Remove-LocalGroupMember]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Remove-LocalGroupMember "Remove-LocalGroupMember"
[msdocs:Disable-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Disable-LocalUser "Disable-LocalUser"
[msdocs:Enable-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Enable-LocalUser "Enable-LocalUser"
[msdocs:Get-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Get-LocalUser "Get-LocalUser"
[msdocs:New-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/New-LocalUser "New-LocalUser"
[msdocs:Remove-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Remove-LocalUser "Remove-LocalUser"
[msdocs:Rename-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Rename-LocalUser "Rename-LocalUser"
[msdocs:Set-LocalUser]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.LocalAccounts/Set-LocalUser "Set-LocalUser"

[Add-LocalGroupMember]: #add-localgroupmember '```&#10;[PS] Add-LocalGroupMember&#10;```&#10;Add members to a local group'
[Get-LocalGroupMember]: #get-localgroupmember '```&#10;[PS] Get-LocalGroupMember&#10;```&#10;Display members of a local group'
[Remove-LocalGroupMember]: #remove-localgroupmember '```&#10;[PS] Remove-LocalGroupMember&#10;```&#10;Remove members from a local group'
[Disable-LocalUser]: #disable-localuser '```&#10;[PS] Disable-LocalUser&#10;[PS] dlu&#10;```&#10;Disable a local user account'
[Enable-LocalUser]: #enable-localuser '```&#10;[PS] Enable-LocalUser&#10;[PS] elu&#10;```&#10;Enable a local user account'
[Get-LocalUser]: #get-localuser '```&#10;[PS] Get-LocalUser&#10;[PS] glu&#10;```&#10;Display local user account'
[New-LocalUser]: #new-localuser '```&#10;[PS] New-LocalUser&#10;[PS] nlu&#10;```&#10;Create a local user account'
[Remove-LocalUser]: #remove-localuser '```&#10;[PS] Remove-LocalUser&#10;[PS] rlu&#10;```&#10;Delete a local user account'
[Rename-LocalUser]: #rename-localuser '```&#10;[PS] Rename-LocalUser&#10;[PS] rnlu&#10;```&#10;Delete local user account'
[Set-LocalUser]: #set-localuser '```&#10;[PS] Set-LocalUser&#10;[PS] slu&#10;```&#10;Modify a local user account'

- LocalGroupMember
[`Add`][Add-LocalGroupMember]<sup>[?][msdocs:Add-LocalGroupMember]</sup>
[`Get`][Get-LocalGroupMember]<sup>[?][msdocs:Get-LocalGroupMember]</sup>
[`Remove`][Remove-LocalGroupMember]<sup>[?][msdocs:Remove-LocalGroupMember]</sup>
- LocalUser
[`Disable`][Disable-LocalUser]<sup>[?][msdocs:Disable-LocalUser]</sup>
[`Enable`][Enable-LocalUser]<sup>[?][msdocs:Enable-LocalUser]</sup>
[`Get`][Get-LocalUser]<sup>[?][msdocs:Get-LocalUser]</sup>
[`New`][New-LocalUser]<sup>[?][msdocs:New-LocalUser]</sup>
[`Remove`][Remove-LocalUser]<sup>[?][msdocs:Remove-LocalUser]</sup>
[`Rename`][Rename-LocalUser]<sup>[?][msdocs:Rename-LocalUser]</sup>
[`Set`][Set-LocalUser]<sup>[?][msdocs:Set-LocalUser]</sup>
#### Microsoft.Powershell.Management
[msdocs:Get-ChildItem]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-ChildItem "Get-ChildItem"
[msdocs:Get-Clipboard]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Clipboard "Get-Clipboard documentation"
[msdocs:Set-Clipboard]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-Clipboard "Set-Clipboard documentation"
[msdocs:Rename-Computer]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Rename-Computer "Rename-Computer documentation"
[msdocs:Restart-Computer]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Restart-Computer "Restart-Computer documentation"
[msdocs:Stop-Computer]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Stop-Computer "Stop-Computer documentation"
[msdocs:Get-ComputerInfo]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-ComputerInfo "Get-ComputerInfo documentation"
[msdocs:Test-Connection]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Test-Connection "Test-Connection documentation"
[msdocs:Add-Content]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Add-Content "Add-Content documentation"
[msdocs:Clear-Content]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Clear-Content "Clear-Content documentation"
[msdocs:Get-Content]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Content "Get-Content documentation"
[msdocs:Set-Content]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-Content "Set-Content documentation"
[msdocs:Clear-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Clear-EventLog "Clear-EventLog documentation"
[msdocs:Get-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-EventLog "Get-EventLog documentation"
[msdocs:Limit-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Limit-EventLog "Limit-EventLog documentation"
[msdocs:New-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/New-EventLog "New-EventLog documentation"
[msdocs:Remove-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Remove-EventLog "Remove-EventLog documentation"
[msdocs:Show-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Show-EventLog "Show-EventLog documentation"
[msdocs:Write-EventLog]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Write-EventLog "Write-EventLog documentation"
[msdocs:Get-HotFix]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-HotFix "Get-HotFix documentation"
[msdocs:Clear-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Clear-Item "Clear-Item documentation"
[msdocs:Copy-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Copy-Item "Copy-Item documentation"
[msdocs:Get-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Item "Get-Item documentation"
[msdocs:Invoke-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Invoke-Item "Invoke-Item documentation"
[msdocs:Move-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Move-Item "Move-Item documentation"
[msdocs:New-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/New-Item "New-Item documentation"
[msdocs:Remove-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Remove-Item "Remove-Item documentation"
[msdocs:Rename-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Rename-Item "Rename-Item documentation"
[msdocs:Set-Item]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-Item "Set-Item documentation"
[msdocs:Clear-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Clear-ItemProperty "Clear-ItemProperty documentation"
[msdocs:Copy-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Copy-ItemProperty "Copy-ItemProperty documentation"
[msdocs:Get-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-ItemProperty "Get-ItemProperty documentation"
[msdocs:Move-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Move-ItemProperty "Move-ItemProperty documentation"
[msdocs:New-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/New-ItemProperty "New-ItemProperty documentation"
[msdocs:Remove-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Remove-ItemProperty "Remove-ItemProperty documentation"
[msdocs:Rename-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Rename-ItemProperty "Rename-ItemProperty documentation"
[msdocs:Set-ItemProperty]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-ItemProperty "Set-ItemProperty documentation"
[msdocs:Get-ItemPropertyValue]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-ItemPropertyValue "Get-ItemPropertyValue documentation"
[msdocs:Get-Location]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Location "Get-Location documentation"
[msdocs:Pop-Location]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Pop-Location "Pop-Location documentation"
[msdocs:Push-Location]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Push-Location "Push-Location documentation"
[msdocs:Set-Location]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-Location "Set-Location documentation"
[msdocs:Convert-Path]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Convert-Path "Convert-Path documentation"
[msdocs:Join-Path]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Join-Path "Join-Path documentation"
[msdocs:Resolve-Path]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Resolve-Path "Resolve-Path documentation"
[msdocs:Split-Path]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Split-Path "Split-Path documentation"
[msdocs:Test-Path]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Test-Path "Test-Path documentation"
[msdocs:Get-Process]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Process "Get-Process documentation"
[msdocs:Debug-Process]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Debug-Process "Debug-Process documentation"
[msdocs:Start-Process]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Start-Process "Start-Process documentation"
[msdocs:Stop-Process]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Stop-Process "Stop-Process documentation"
[msdocs:Wait-Process]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Wait-Process "Wait-Process documentation"
[msdocs:Get-PSDrive]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-PSDrive "Get-PSDrive documentation"
[msdocs:New-PSDrive]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/New-PSDrive "New-PSDrive documentation"
[msdocs:Remove-PSDrive]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Remove-PSDrive "Remove-PSDrive documentation"
[msdocs:Get-PSProvider]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-PSProvider "Get-PSProvider documentation"
[msdocs:Clear-RecycleBin]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Clear-RecycleBin "Clear-RecycleBin documentation"
[msdocs:Get-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-Service "Get-Service documentation"
[msdocs:New-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/New-Service "New-Service documentation"
[msdocs:Remove-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Remove-Service "Remove-Service documentation"
[msdocs:Restart-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Restart-Service "Restart-Service documentation"
[msdocs:Resume-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Resume-Service "Resume-Service documentation"
[msdocs:Set-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-Service "Set-Service documentation"
[msdocs:Start-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Start-Service "Start-Service documentation"
[msdocs:Stop-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Stop-Service "Stop-Service documentation"
[msdocs:Suspend-Service]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Suspend-Service "Suspend-Service documentation"
[msdocs:Get-TimeZone]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Get-TimeZone "Get-TimeZone documentation"
[msdocs:Set-TimeZone]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Set-TimeZone "Set-TimeZone documentation"
[msdocs:Complete-Transaction]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Complete-Transaction "Complete-Transaction documentation"
[msdocs:Start-Transaction]: https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/Start-Transaction "Start-Transaction documentation"
[msdocs:Get-WMIObject]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.PowerShell.Management/Get-WMIObject "Get-WMIObject documentation"

[Get-ChildItem]: #get-childitem '```&#10;[PS] Get-ChildItem&#10;[PS] dir gci ls&#10;```&#10;Gets the items and child items in one or more specified locations.'
[Get-Clipboard]: #get-clipboard '```&#10;[PS] Get-Clipboard&#10;[PS] gcb&#10;```&#10;Gets the contents of the clipboard. [!NOTE] > On Linux, this cmdlet requires the xclip utility to be in the path.'
[Set-Clipboard]: #set-clipboard '```&#10;[PS] Set-Clipboard&#10;[PS] scb&#10;```&#10;Sets the contents of the clipboard.'
[Rename-Computer]: #rename-computer '```&#10;[PS] Rename-Computer&#10;```&#10;Renames a computer.'
[Restart-Computer]: #restart-computer '```&#10;[PS] Restart-Computer&#10;```&#10;Restarts the operating system on local and remote computers.'
[Stop-Computer]: #stop-computer '```&#10;[PS] Stop-Computer&#10;```&#10;Stops (shuts down) local and remote computers.'
[Get-ComputerInfo]: #get-computerinfo '```&#10;[PS] Get-ComputerInfo&#10;[PS] gin&#10;```&#10;Gets a consolidated object of system and operating system properties.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[Test-Connection]: #test-connection '```&#10;[PS] Test-Connection&#10;```&#10;Sends ICMP echo request packets, or pings, to one or more computers.'
[Add-Content]: #add-content '```&#10;[PS] Add-Content&#10;[PS] ac&#10;```&#10;Add content, such as words or data, to a file'
[Clear-Content]: #clear-content '```&#10;[PS] Clear-Content&#10;```&#10;Deletes the contents of an item, but does not delete the item.'
[Get-Content]: #get-content '```&#10;[PS] Get-Content&#10;[PS] gc&#10;```&#10;Gets the content of the item at the specified location.'
[Set-Content]: #set-content '```&#10;[PS] Set-Content&#10;```&#10;Writes new content or replaces existing content in a file.'
[Clear-EventLog]: #clear-eventlog '```&#10;[PS] Clear-EventLog&#10;```&#10;Clears all entries from specified event logs on the local or remote computers.'
[Get-EventLog]: #get-eventlog '```&#10;[PS] Get-EventLog&#10;```&#10;Gets the events in an event log, or a list of the event logs, on the local computer or remote computers.'
[Limit-EventLog]: #limit-eventlog '```&#10;[PS] Limit-EventLog&#10;```&#10;Sets the event log properties that limit the size of the event log and the age of its entries.'
[New-EventLog]: #new-eventlog '```&#10;[PS] New-EventLog&#10;```&#10;Creates a new event log and a new event source on a local or remote computer.'
[Remove-EventLog]: #remove-eventlog '```&#10;[PS] Remove-EventLog&#10;```&#10;Deletes an event log or unregisters an event source.'
[Show-EventLog]: #show-eventlog '```&#10;[PS] Show-EventLog&#10;```&#10;Displays the event logs of the local or a remote computer in Event Viewer.'
[Write-EventLog]: #write-eventlog '```&#10;[PS] Write-EventLog&#10;```&#10;Writes an event to an event log.'
[Get-HotFix]: #get-hotfix '```&#10;[PS] Get-HotFix&#10;```&#10;Gets the hotfixes that are installed on local or remote computers.'
[Clear-Item]: #clear-item '```&#10;[PS] Clear-Item&#10;```&#10;Clears the contents of an item, but does not delete the item.'
[Copy-Item]: #copy-item '```&#10;[PS] Copy-Item&#10;[PS] cpi&#10;```&#10;Copies an item from one location to another.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 180'
[Get-Item]: #get-item '```&#10;[PS] Get-Item&#10;[PS] gi&#10;```&#10;Gets the item at the specified location.'
[Invoke-Item]: #invoke-item '```&#10;[PS] Invoke-Item&#10;```&#10;Performs the default action on the specified item.'
[Move-Item]: #move-item '```&#10;[PS] Move-Item&#10;```&#10;Moves an item from one location to another.'
[New-Item]: #new-item '```&#10;[PS] New-Item&#10;[PS] ni&#10;```&#10;Create a new item and set its value. The type of item created depends on the context.'
[Remove-Item]: #remove-item '```&#10;[PS] Remove-Item&#10;[PS] ri&#10;```&#10;Deletes the specified items.'
[Rename-Item]: #rename-item '```&#10;[PS] Rename-Item&#10;```&#10;Renames an item in a PowerShell provider namespace.'
[Set-Item]: #set-item '```&#10;[PS] Set-Item&#10;[PS] si&#10;```&#10;Changes the value of an item to the value specified in the command.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 56'
[Clear-ItemProperty]: #clear-itemproperty '```&#10;[PS] Clear-ItemProperty&#10;```&#10;Clears the value of a property but does not delete the property.'
[Copy-ItemProperty]: #copy-itemproperty '```&#10;[PS] Copy-ItemProperty&#10;```&#10;Copies a property and value from a specified location to another location.'
[Get-ItemProperty]: #get-itemproperty '```&#10;[PS] Get-ItemProperty&#10;```&#10;Gets the properties of a specified item.'
[Move-ItemProperty]: #move-itemproperty '```&#10;[PS] Move-ItemProperty&#10;```&#10;Moves a property from one location to another.'
[New-ItemProperty]: #new-itemproperty '```&#10;[PS] New-ItemProperty&#10;```&#10;Creates a new property for an item and sets its value.'
[Remove-ItemProperty]: #remove-itemproperty '```&#10;[PS] Remove-ItemProperty&#10;```&#10;Deletes the property and its value from an item.'
[Rename-ItemProperty]: #rename-itemproperty '```&#10;[PS] Rename-ItemProperty&#10;```&#10;Renames a property of an item.'
[Set-ItemProperty]: #set-itemproperty '```&#10;[PS] Set-ItemProperty&#10;```&#10;Creates or changes the value of a property of an item.'
[Get-ItemPropertyValue]: #get-itempropertyvalue '```&#10;[PS] Get-ItemPropertyValue&#10;```&#10;Gets the value for one or more properties of a specified item.'
[Get-Location]: #get-location '```&#10;[PS] Get-Location&#10;```&#10;Gets information about the current working location or a location stack.'
[Pop-Location]: #pop-location '```&#10;[PS] Pop-Location&#10;```&#10;Changes the current location to the location most recently pushed onto the stack.'
[Push-Location]: #push-location '```&#10;[PS] Push-Location&#10;```&#10;Adds the current location to the top of a location stack.'
[Set-Location]: #set-location '```&#10;[PS] Set-Location&#10;[PS] sl&#10;```&#10;Sets the current working location to a specified location.'
[Convert-Path]: #convert-path '```&#10;[PS] Convert-Path&#10;```&#10;Converts a path from a PowerShell path to a PowerShell provider path.'
[Join-Path]: #join-path '```&#10;[PS] Join-Path&#10;```&#10;Combines a path and a child path into a single path.'
[Resolve-Path]: #resolve-path '```&#10;[PS] Resolve-Path&#10;```&#10;Resolves the wildcard characters in a path, and displays the path contents.'
[Split-Path]: #split-path '```&#10;[PS] Split-Path&#10;```&#10;Returns the specified part of a path.'
[Test-Path]: #test-path '```&#10;[PS] Test-Path&#10;```&#10;Determines whether all elements of a path exist.'
[Get-Process]: #get-process '```&#10;[PS] Get-Process&#10;[PS] gps&#10;```&#10;Display running processes'
[Debug-Process]: #debug-process '```&#10;[PS] Debug-Process&#10;```&#10;Debugs one or more processes running on the local computer.'
[Start-Process]: #start-process '```&#10;[PS] Start-Process&#10;[PS] saps&#10;```&#10;Start one or more processes on the local computer.'
[Stop-Process]: #stop-process '```&#10;[PS] Stop-Process&#10;[PS] spps&#10;```&#10;Stop one or more running processes'
[Wait-Process]: #wait-process '```&#10;[PS] Wait-Process&#10;```&#10;Waits for the processes to be stopped before accepting more input.'
[Get-PSDrive]: #get-psdrive '```&#10;[PS] Get-PSDrive&#10;[PS] gdr&#10;```&#10;Gets drives in the current session.'
[New-PSDrive]: #new-psdrive '```&#10;[PS] New-PSDrive&#10;[PS] ndr&#10;```&#10;Creates temporary and persistent mapped network drives.'
[Remove-PSDrive]: #remove-psdrive '```&#10;[PS] Remove-PSDrive&#10;[PS] rdr&#10;```&#10;Deletes temporary PowerShell drives and disconnects mapped network drives.'
[Get-PSProvider]: #get-psprovider '```&#10;[PS] Get-PSProvider&#10;```&#10;Gets information about the specified PowerShell provider.'
[Clear-RecycleBin]: #clear-recyclebin '```&#10;[PS] Clear-RecycleBin&#10;```&#10;Clears the contents of a recycle bin.'
[Get-Service]: #get-service '```&#10;[PS] Get-Service&#10;[PS] gsv&#10;```&#10;Display services'
[New-Service]: #new-service '```&#10;[PS] New-Service&#10;```&#10;Creates a new Windows service.'
[Remove-Service]: #remove-service '```&#10;[PS] Remove-Service&#10;```&#10;Removes a Windows service.'
[Restart-Service]: #restart-service '```&#10;[PS] Restart-Service&#10;```&#10;Stops and then starts one or more services.'
[Resume-Service]: #resume-service '```&#10;[PS] Resume-Service&#10;```&#10;Resumes one or more suspended (paused) services.'
[Set-Service]: #set-service '```&#10;[PS] Set-Service&#10;```&#10;Starts, stops, and suspends a service, and changes its properties'
[Start-Service]: #start-service '```&#10;[PS] Start-Service&#10;[PS] sasv&#10;```&#10;Start one or more stopped services'
[Stop-Service]: #stop-service '```&#10;[PS] Stop-Service&#10;[PS] spsv&#10;```&#10;Stop one or more services'
[Suspend-Service]: #suspend-service '```&#10;[PS] Suspend-Service&#10;```&#10;Suspends (pauses) one or more running services.'
[Get-TimeZone]: #get-timezone '```&#10;[PS] Get-TimeZone&#10;```&#10;Gets the current time zone or a list of available time zones.'
[Set-TimeZone]: #set-timezone '```&#10;[PS] Set-TimeZone&#10;```&#10;Sets the system time zone to a specified time zone.'
[Complete-Transaction]: #complete-transaction '```&#10;[PS] Complete-Transaction&#10;```&#10;Commit the transaction'
[Start-Transaction]: #start-transaction '```&#10;[PS] Start-Transaction&#10;```&#10;Start a new transaction'
[Get-WMIObject]: #get-wmiobject '```&#10;[PS] Get-WMIObject&#10;[PS] gwmi&#10;```&#10;Gets instances of Windows Management Instrumentation (WMI) classes or information about the available classes.&#10;Superseded by `Get-CimInstance` since Powershell 3.0'

- ChildItem
[`Get`][Get-ChildItem]<sup>[?][msdocs:Get-ChildItem]</sup>
- Clipboard
[`Get`][Get-Clipboard]<sup>[?][msdocs:Get-Clipboard]</sup>
[`Set`][Set-Clipboard]<sup>[?][msdocs:Set-Clipboard]</sup>
- Computer
[`Rename`][Rename-Computer]<sup>[?][msdocs:Rename-Computer]</sup>
[`Restart`][Restart-Computer]<sup>[?][msdocs:Restart-Computer]</sup>
[`Stop`][Stop-Computer]<sup>[?][msdocs:Stop-Computer]</sup>
- ComputerInfo
[`Get`][Get-ComputerInfo]<sup>[?][msdocs:Get-ComputerInfo]</sup>
- Connection
[`Test`][Test-Connection]<sup>[?][msdocs:Test-Connection]</sup>
- Content
[`Add`][Add-Content]<sup>[?][msdocs:Add-Content]</sup>
[`Clear`][Clear-Content]<sup>[?][msdocs:Clear-Content]</sup>
[`Get`][Get-Content]<sup>[?][msdocs:Get-Content]</sup>
[`Set`][Set-Content]<sup>[?][msdocs:Set-Content]</sup>
- EventLog
[`Clear`][Clear-EventLog]<sup>[?][msdocs:Clear-EventLog]</sup>
[`Get`][Get-EventLog]<sup>[?][msdocs:Get-EventLog]</sup>
[`Limit`][Limit-EventLog]<sup>[?][msdocs:Limit-EventLog]</sup>
[`New`][New-EventLog]<sup>[?][msdocs:New-EventLog]</sup>
[`Remove`][Remove-EventLog]<sup>[?][msdocs:Remove-EventLog]</sup>
[`Show`][Show-EventLog]<sup>[?][msdocs:Show-EventLog]</sup>
[`Write`][Write-EventLog]<sup>[?][msdocs:Write-EventLog]</sup>
- Item
[`Clear`][Clear-Item]<sup>[?][msdocs:Clear-Item]</sup>
[`Copy`][Copy-Item]<sup>[?][msdocs:Copy-Item]</sup>
[`Get`][Get-Item]<sup>[?][msdocs:Get-Item]</sup>
[`Invoke`][Invoke-Item]<sup>[?][msdocs:Invoke-Item]</sup>
[`Move`][Move-Item]<sup>[?][msdocs:Move-Item]</sup>
[`New`][New-Item]<sup>[?][msdocs:New-Item]</sup>
[`Remove`][Remove-Item]<sup>[?][msdocs:Remove-Item]</sup>
[`Rename`][Rename-Item]<sup>[?][msdocs:Rename-Item]</sup>
[`Set`][Set-Item]<sup>[?][msdocs:Set-Item]</sup>
- ItemProperty
[`Clear`][Clear-ItemProperty]<sup>[?][msdocs:Clear-ItemProperty]</sup>
[`Copy`][Copy-ItemProperty]<sup>[?][msdocs:Copy-ItemProperty]</sup>
[`Get`][Get-ItemProperty]<sup>[?][msdocs:Get-ItemProperty]</sup>
[`Move`][Move-ItemProperty]<sup>[?][msdocs:Move-ItemProperty]</sup>
[`New`][New-ItemProperty]<sup>[?][msdocs:New-ItemProperty]</sup>
[`Remove`][Remove-ItemProperty]<sup>[?][msdocs:Remove-ItemProperty]</sup>
[`Rename`][Rename-ItemProperty]<sup>[?][msdocs:Rename-ItemProperty]</sup>
[`Set`][Set-ItemProperty]<sup>[?][msdocs:Set-ItemProperty]</sup>
- Location
[`Get`][Get-Location]<sup>[?][msdocs:Get-Location]</sup>
[`Pop`][Pop-Location]<sup>[?][msdocs:Pop-Location]</sup>
[`Push`][Push-Location]<sup>[?][msdocs:Push-Location]</sup>
[`Set`][Set-Location]<sup>[?][msdocs:Set-Location]</sup>
- Path
[`Convert`][Convert-Path]<sup>[?][msdocs:Convert-Path]</sup>
[`Join`][Join-Path]<sup>[?][msdocs:Join-Path]</sup>
[`Resolve`][Resolve-Path]<sup>[?][msdocs:Resolve-Path]</sup>
[`Split`][Split-Path]<sup>[?][msdocs:Split-Path]</sup>
[`Test`][Test-Path]<sup>[?][msdocs:Test-Path]</sup>
- Process
[`Get`][Get-Process]<sup>[?][msdocs:Get-Process]</sup>
[`Debug`][Debug-Process]<sup>[?][msdocs:Debug-Process]</sup>
[`Start`][Start-Process]<sup>[?][msdocs:Start-Process]</sup>
[`Stop`][Stop-Process]<sup>[?][msdocs:Stop-Process]</sup>
[`Wait`][Wait-Process]<sup>[?][msdocs:Wait-Process]</sup>
- PSDrive
[`Get`][Get-PSDrive]<sup>[?][msdocs:Get-PSDrive]</sup>
[`New`][New-PSDrive]<sup>[?][msdocs:New-PSDrive]</sup>
[`Remove`][Remove-PSDrive]<sup>[?][msdocs:Remove-PSDrive]</sup>
- RecycleBin
[`Clear`][Clear-RecycleBin]<sup>[?][msdocs:Clear-RecycleBin]</sup>
- Service
[`Get`][Get-Service]<sup>[?][msdocs:Get-Service]</sup>
[`New`][New-Service]<sup>[?][msdocs:New-Service]</sup>
[`Remove`][Remove-Service]<sup>[?][msdocs:Remove-Service]</sup>
[`Restart`][Restart-Service]<sup>[?][msdocs:Restart-Service]</sup>
[`Resume`][Resume-Service]<sup>[?][msdocs:Resume-Service]</sup>
[`Set`][Set-Service]<sup>[?][msdocs:Set-Service]</sup>
[`Start`][Start-Service]<sup>[?][msdocs:Start-Service]</sup>
[`Stop`][Stop-Service]<sup>[?][msdocs:Stop-Service]</sup>
[`Suspend`][Suspend-Service]<sup>[?][msdocs:Suspend-Service]</sup>
- Transaction
[`Complete`][Complete-Transaction]<sup>[?][msdocs:Complete-Transaction]</sup>
[`Start`][Start-Transaction]<sup>[?][msdocs:Start-Transaction]</sup>
- WMIObject
[`Get`][Get-WMIObject]<sup>[?][msdocs:Get-WMIObject]</sup>
#### Microsoft.Powershell.Utility
[msdocs:Export-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Export-Alias "Export-Alias documentation"
[msdocs:Get-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Alias "Get-Alias documentation"
[msdocs:Import-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-Alias "Import-Alias documentation"
[msdocs:New-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-Alias "New-Alias documentation"
[msdocs:Remove-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Remove-Alias "Remove-Alias documentation"
[msdocs:Set-Alias]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-Alias "Set-Alias documentation"
[msdocs:Export-Clixml]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Export-Clixml "Export-Clixml documentation"
[msdocs:Import-Clixml]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-Clixml "Import-Clixml documentation"
[msdocs:Measure-Command]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Measure-Command "Measure-Command documentation"
[msdocs:Show-Command]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Show-Command "Show-Command documentation"
[msdocs:Trace-Command]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Trace-Command "Trace-Command documentation"
[msdocs:ConvertFrom-Csv]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertFrom-Csv "ConvertFrom-Csv documentation"
[msdocs:ConvertTo-Csv]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertTo-Csv "ConvertTo-Csv documentation"
[msdocs:Export-Csv]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Export-Csv "Export-Csv documentation"
[msdocs:Import-Csv]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-Csv "Import-Csv documentation"
[msdocs:Get-Culture]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Culture "Get-Culture documentation"
[msdocs:Format-Custom]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Format-Custom "Format-Custom documentation"
[msdocs:Get-Date]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Date "Get-Date documentation"
[msdocs:Set-Date]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-Date "Set-Date documentation"
[msdocs:Write-Debug]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Debug "Write-Debug documentation"
[msdocs:Wait-Debugger]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Wait-Debugger "Wait-Debugger documentation"
[msdocs:Register-EngineEvent]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Register-EngineEvent "Register-EngineEvent documentation"
[msdocs:Get-Error]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Error "Get-Error documentation"
[msdocs:Write-Error]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Error "Write-Error documentation"
[msdocs:Get-Event]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Event "Get-Event documentation"
[msdocs:New-Event]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-Event "New-Event documentation"
[msdocs:Remove-Event]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Remove-Event "Remove-Event documentation"
[msdocs:Unregister-Event]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Unregister-Event "Unregister-Event documentation"
[msdocs:Wait-Event]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Wait-Event "Wait-Event documentation"
[msdocs:Get-EventSubscriber]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-EventSubscriber "Get-EventSubscriber documentation"
[msdocs:Invoke-Expression]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Invoke-Expression "Invoke-Expression documentation"
[msdocs:Out-File]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Out-File "Out-File documentation"
[msdocs:Unblock-File]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Unblock-File "Unblock-File documentation"
[msdocs:Get-FileHash]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-FileHash "Get-FileHash documentation"
[msdocs:Export-FormatData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Export-FormatData "Export-FormatData documentation"
[msdocs:Get-FormatData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-FormatData "Get-FormatData documentation"
[msdocs:Update-FormatData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Update-FormatData "Update-FormatData documentation"
[msdocs:Out-GridView]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Out-GridView "Out-GridView documentation"
[msdocs:New-Guid]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-Guid "New-Guid documentation"
[msdocs:Format-Hex]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Format-Hex "Format-Hex documentation"
[msdocs:Get-Host]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Host "Get-Host documentation"
[msdocs:Read-Host]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Read-Host "Read-Host documentation"
[msdocs:Write-Host]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Host "Write-Host documentation"
[msdocs:ConvertTo-Html]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertTo-Html "ConvertTo-Html documentation"
[msdocs:Write-Information]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Information "Write-Information documentation"
[msdocs:ConvertFrom-Json]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertFrom-Json "ConvertFrom-Json documentation"
[msdocs:ConvertTo-Json]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertTo-Json "ConvertTo-Json documentation"
[msdocs:Test-Json]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Test-Json "Test-Json documentation"
[msdocs:Format-List]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Format-List "Format-List documentation"
[msdocs:Update-List]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Update-List "Update-List documentation"
[msdocs:Import-LocalizedData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-LocalizedData "Import-LocalizedData documentation"
[msdocs:Send-MailMessage]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Send-MailMessage "Send-MailMessage documentation"
[msdocs:ConvertFrom-Markdown]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertFrom-Markdown "ConvertFrom-Markdown documentation"
[msdocs:Show-Markdown]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Show-Markdown "Show-Markdown documentation"
[msdocs:Get-MarkdownOption]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-MarkdownOption "Get-MarkdownOption documentation"
[msdocs:Set-MarkdownOption]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-MarkdownOption "Set-MarkdownOption documentation"
[msdocs:Get-Member]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Member "Get-Member documentation"
[msdocs:Add-Member]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Add-Member "Add-Member documentation"
[msdocs:Measure-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Measure-Object "Measure-Object documentation"
[msdocs:New-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-Object "New-Object documentation"
[msdocs:Compare-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Compare-Object "Compare-Object documentation"
[msdocs:Group-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Group-Object "Group-Object documentation"
[msdocs:Sort-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Sort-Object "Sort-Object documentation"
[msdocs:Tee-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Tee-Object "Tee-Object documentation"
[msdocs:Select-Object]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Select-Object "Select-Object documentation"
[msdocs:Register-ObjectEvent]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Register-ObjectEvent "Register-ObjectEvent"
[msdocs:Write-Output]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Output "Write-Output"
[msdocs:Import-PowerShellDataFile]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-PowerShellDataFile "Import-PowerShellDataFile"
[msdocs:Out-Printer]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Out-Printer "Out-Printer"
[msdocs:Write-Progress]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Progress "Write-Progress"
[msdocs:Disable-PSBreakpoint]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Disable-PSBreakpoint "Disable-PSBreakpoint"
[msdocs:Enable-PSBreakpoint]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Enable-PSBreakpoint "Enable-PSBreakpoint"
[msdocs:Get-PSBreakpoint]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-PSBreakpoint "Get-PSBreakpoint"
[msdocs:Remove-PSBreakpoint]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Remove-PSBreakpoint "Remove-PSBreakpoint"
[msdocs:Set-PSBreakpoint]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-PSBreakpoint "Set-PSBreakpoint"
[msdocs:Get-PSCallStack]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-PSCallStack "Get-PSCallStack"
[msdocs:Export-PSSession]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Export-PSSession "Export-PSSession"
[msdocs:Import-PSSession]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Import-PSSession "Import-PSSession"
[msdocs:Get-Random]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Random "Get-Random"
[msdocs:Invoke-RestMethod]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Invoke-RestMethod "Invoke-RestMethod"
[msdocs:Debug-Runspace]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Debug-Runspace "Debug-Runspace"
[msdocs:Get-Runspace]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Runspace "Get-Runspace"
[msdocs:Disable-RunspaceDebug]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Disable-RunspaceDebug "Disable-RunspaceDebug"
[msdocs:Enable-RunspaceDebug]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Enable-RunspaceDebug "Enable-RunspaceDebug"
[msdocs:Get-RunspaceDebug]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-RunspaceDebug "Get-RunspaceDebug"
[msdocs:ConvertFrom-SddlString]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertFrom-SddlString "ConvertFrom-SddlString"
[msdocs:Start-Sleep]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Start-Sleep "Start-Sleep"
[msdocs:Join-String]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Join-String "Join-String"
[msdocs:Out-String]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Out-String "Out-String"
[msdocs:Select-String]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Select-String "Select-String"
[msdocs:ConvertFrom-StringData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertFrom-StringData "ConvertFrom-StringData"
[msdocs:Format-Table]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Format-Table "Format-Table"
[msdocs:New-TemporaryFile]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-TemporaryFile "New-TemporaryFile"
[msdocs:New-TimeSpan]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-TimeSpan "New-TimeSpan"
[msdocs:Get-TraceSource]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-TraceSource "Get-TraceSource"
[msdocs:Set-TraceSource]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-TraceSource "Set-TraceSource"
[msdocs:Add-Type]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Add-Type "Add-Type"
[msdocs:Get-TypeData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-TypeData "Get-TypeData"
[msdocs:Remove-TypeData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Remove-TypeData "Remove-TypeData"
[msdocs:Update-TypeData]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Update-TypeData "Update-TypeData"
[msdocs:Get-UICulture]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-UICulture "Get-UICulture"
[msdocs:Get-Unique]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Unique "Get-Unique"
[msdocs:Get-Uptime]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Uptime "Get-Uptime"
[msdocs:Clear-Variable]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Clear-Variable "Clear-Variable"
[msdocs:Get-Variable]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Variable "Get-Variable"
[msdocs:New-Variable]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/New-Variable "New-Variable"
[msdocs:Remove-Variable]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Remove-Variable "Remove-Variable"
[msdocs:Set-Variable]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Set-Variable "Set-Variable"
[msdocs:Get-Verb]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Get-Verb "Get-Verb"
[msdocs:Write-Verbose]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Verbose "Write-Verbose"
[msdocs:Write-Warning]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Write-Warning "Write-Warning"
[msdocs:Invoke-WebRequest]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Invoke-WebRequest "Invoke-WebRequest"
[msdocs:Format-Wide]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Format-Wide "Format-Wide"
[msdocs:ConvertTo-Xml]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/ConvertTo-Xml "ConvertTo-Xml"
[msdocs:Select-Xml]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.Powershell.Utility/Select-Xml "Select-Xml"

[Export-Alias]: #export-alias '```&#10;[PS] Export-Alias&#10;[PS] epal&#10;```&#10;Exports information about currently defined aliases to a file.'
[Get-Alias]: #get-alias '```&#10;[PS] Get-Alias&#10;[PS] gal&#10;```&#10;Gets the aliases for the current session.'
[Import-Alias]: #import-alias '```&#10;[PS] Import-Alias&#10;```&#10;Imports an alias list from a file.'
[New-Alias]: #new-alias '```&#10;[PS] New-Alias&#10;[PS] nal&#10;```&#10;Creates a new alias.'
[Remove-Alias]: #remove-alias '```&#10;[PS] Remove-Alias&#10;```&#10;Remove an alias from the current session.'
[Set-Alias]: #set-alias '```&#10;[PS] Set-Alias&#10;```&#10;Creates or changes an alias for a cmdlet or other command in the current PowerShell session.'
[Export-Clixml]: #export-clixml '```&#10;[PS] Export-Clixml&#10;```&#10;Creates an XML-based representation of an object or objects and stores it in a file.'
[Import-Clixml]: #import-clixml '```&#10;[PS] Import-Clixml&#10;```&#10;Imports a CLIXML file and creates corresponding objects in PowerShell.'
[Measure-Command]: #measure-command '```&#10;[PS] Measure-Command&#10;```&#10;Measures the time it takes to run script blocks and cmdlets.'
[Show-Command]: #show-command '```&#10;[PS] Show-Command&#10;```&#10;Displays PowerShell command information in a graphical window.'
[Trace-Command]: #trace-command '```&#10;[PS] Trace-Command&#10;```&#10;Configures and starts a trace of the specified expression or command.'
[ConvertFrom-Csv]: #convertfrom-csv '```&#10;[PS] ConvertFrom-Csv&#10;```&#10;Converts object properties in comma-separated value (CSV) format into CSV versions of the original objects.'
[ConvertTo-Csv]: #convertto-csv '```&#10;[PS] ConvertTo-Csv&#10;```&#10;Converts objects into a series of character-separated value (CSV) strings.'
[Export-Csv]: #export-csv '```&#10;[PS] Export-Csv&#10;```&#10;Converts objects into a series of comma-separated value (CSV) strings and saves the strings to a file.'
[Import-Csv]: #import-csv '```&#10;[PS] Import-Csv&#10;[PS] ipcsv&#10;```&#10;Creates table-like custom objects from the items in a comma-separated value (CSV) file.'
[Get-Culture]: #get-culture '```&#10;[PS] Get-Culture&#10;```&#10;Gets the current culture set in the operating system.'
[Format-Custom]: #format-custom '```&#10;[PS] Format-Custom&#10;```&#10;Uses a customized view to format the output.'
[Get-Date]: #get-date '```&#10;[PS] Get-Date&#10;```&#10;Gets the current date and time.'
[Set-Date]: #set-date '```&#10;[PS] Set-Date&#10;```&#10;Changes the system time on the computer to a time that you specify.'
[Write-Debug]: #write-debug '```&#10;[PS] Write-Debug&#10;```&#10;Writes a debug message to the console.'
[Wait-Debugger]: #wait-debugger '```&#10;[PS] Wait-Debugger&#10;```&#10;Stops a script in the debugger before running the next statement in the script.'
[Register-EngineEvent]: #register-engineevent '```&#10;[PS] Register-EngineEvent&#10;```&#10;Subscribes to events that are generated by the PowerShell engine and by the New-Event cmdlet.'
[Get-Error]: #get-error '```&#10;[PS] Get-Error&#10;```&#10;Gets and displays the most recent error messages from the current session.'
[Write-Error]: #write-error '```&#10;[PS] Write-Error&#10;```&#10;Writes an object to the error stream.'
[Get-Event]: #get-event '```&#10;[PS] Get-Event&#10;```&#10;Gets the events in the event queue.'
[New-Event]: #new-event '```&#10;[PS] New-Event&#10;```&#10;Creates a new event.'
[Remove-Event]: #remove-event '```&#10;[PS] Remove-Event&#10;```&#10;Deletes events from the event queue.'
[Unregister-Event]: #unregister-event '```&#10;[PS] Unregister-Event&#10;```&#10;Cancels an event subscription.'
[Wait-Event]: #wait-event '```&#10;[PS] Wait-Event&#10;```&#10;Waits until a particular event is raised before continuing to run.'
[Get-EventSubscriber]: #get-eventsubscriber '```&#10;[PS] Get-EventSubscriber&#10;```&#10;Gets the event subscribers in the current session.'
[Invoke-Expression]: #invoke-expression '```&#10;[PS] Invoke-Expression&#10;```&#10;Runs commands or expressions on the local computer.'
[Out-File]: #out-file '```&#10;[PS] Out-File&#10;```&#10;Sends output to a file.'
[Unblock-File]: #unblock-file '```&#10;[PS] Unblock-File&#10;```&#10;Unblocks files that were downloaded from the Internet.'
[Get-FileHash]: #get-filehash '```&#10;[PS] Get-FileHash&#10;```&#10;Computes the hash value for a file by using a specified hash algorithm.'
[Export-FormatData]: #export-formatdata '```&#10;[PS] Export-FormatData&#10;```&#10;Saves formatting data from the current session in a formatting file.'
[Get-FormatData]: #get-formatdata '```&#10;[PS] Get-FormatData&#10;```&#10;Gets the formatting data in the current session.'
[Update-FormatData]: #update-formatdata '```&#10;[PS] Update-FormatData&#10;```&#10;Updates the formatting data in the current session.'
[Out-GridView]: #out-gridview '```&#10;[PS] Out-GridView&#10;```&#10;Sends output to an interactive table in a separate window.'
[New-Guid]: #new-guid '```&#10;[PS] New-Guid&#10;```&#10;Creates a GUID.'
[Format-Hex]: #format-hex '```&#10;[PS] Format-Hex&#10;```&#10;Displays a file or other input as hexadecimal.'
[Get-Host]: #get-host '```&#10;[PS] Get-Host&#10;```&#10;Gets an object that represents the current host program.'
[Read-Host]: #read-host '```&#10;[PS] Read-Host&#10;```&#10;Reads a line of input from the console.'
[Write-Host]: #write-host '```&#10;[PS] Write-Host&#10;```&#10;Writes customized output to a host.'
[ConvertTo-Html]: #convertto-html '```&#10;[PS] ConvertTo-Html&#10;```&#10;Converts Microsoft .NET Framework objects into HTML that can be displayed in a Web browser.'
[Write-Information]: #write-information '```&#10;[PS] Write-Information&#10;```&#10;Specifies how PowerShell handles information stream data for a command.'
[ConvertFrom-Json]: #convertfrom-json '```&#10;[PS] ConvertFrom-Json&#10;```&#10;Converts a JSON-formatted string to a custom object or a hash table.'
[ConvertTo-Json]: #convertto-json '```&#10;[PS] ConvertTo-Json&#10;```&#10;Converts an object to a JSON-formatted string.'
[Test-Json]: #test-json '```&#10;[PS] Test-Json&#10;```&#10;Tests whether a string is a valid JSON document'
[Format-List]: #format-list '```&#10;[PS] Format-List&#10;[PS] fl&#10;```&#10;Formats the output as a list of properties in which each property appears on a new line.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 161'
[Update-List]: #update-list '```&#10;[PS] Update-List&#10;```&#10;Adds items to and removes items from a property value that contains a collection of objects.'
[Import-LocalizedData]: #import-localizeddata '```&#10;[PS] Import-LocalizedData&#10;```&#10;Imports language-specific data into scripts and functions based on the UI culture that is selected for the operating system.'
[Send-MailMessage]: #send-mailmessage '```&#10;[PS] Send-MailMessage&#10;```&#10;Sends an email message.'
[ConvertFrom-Markdown]: #convertfrom-markdown '```&#10;[PS] ConvertFrom-Markdown&#10;```&#10;Convert the contents of a string or a file to a MarkdownInfo object.'
[Show-Markdown]: #show-markdown '```&#10;[PS] Show-Markdown&#10;```&#10;Shows a Markdown file or string in the console in a friendly way using VT100 escape sequences or in a browser using HTML.'
[Get-MarkdownOption]: #get-markdownoption '```&#10;[PS] Get-MarkdownOption&#10;```&#10;Returns the current colors and styles used for rendering Markdown content in the console.'
[Set-MarkdownOption]: #set-markdownoption '```&#10;[PS] Set-MarkdownOption&#10;```&#10;Sets the colors and styles used for rendering Markdown content in the console.'
[Get-Member]: #get-member '```&#10;[PS] Get-Member&#10;[PS] gm&#10;```&#10;Gets the properties and methods of objects.'
[Add-Member]: #add-member '```&#10;[PS] Add-Member&#10;```&#10;Adds custom properties and methods to an instance of a PowerShell object.'
[Measure-Object]: #measure-object '```&#10;[PS] Measure-Object&#10;[PS] measure&#10;```&#10;Calculates the numeric properties of objects, and the characters, words, and lines in string objects, such as files of text.'
[New-Object]: #new-object '```&#10;[PS] New-Object&#10;```&#10;Creates an instance of a Microsoft .NET Framework or COM object.'
[Compare-Object]: #compare-object '```&#10;[PS] Compare-Object&#10;```&#10;Compares two sets of objects.'
[Group-Object]: #group-object '```&#10;[PS] Group-Object&#10;```&#10;Groups objects that contain the same value for specified properties.'
[Sort-Object]: #sort-object '```&#10;[PS] Sort-Object&#10;```&#10;Sorts objects by property values.'
[Tee-Object]: #tee-object '```&#10;[PS] Tee-Object&#10;```&#10;Saves command output in a file or variable and also sends it down the pipeline.'
[Select-Object]: #select-object '```&#10;[PS] Select-Object&#10;[PS] select&#10;```&#10;Selects objects or object properties.'
[Register-ObjectEvent]: #register-objectevent '```&#10;[PS] Register-ObjectEvent&#10;```&#10;Subscribes to the events that are generated by a Microsoft .NET Framework object.'
[Write-Output]: #write-output '```&#10;[PS] Write-Output&#10;[PS] echo write&#10;```&#10;Sends the specified objects to the next command in the pipeline. If the command is the last command in the pipeline, the objects are displayed in the console.'
[Import-PowerShellDataFile]: #import-powershelldatafile '```&#10;[PS] Import-PowerShellDataFile&#10;```&#10;Imports values from a .PSD1 file without invoking its contents.'
[Out-Printer]: #out-printer '```&#10;[PS] Out-Printer&#10;```&#10;Sends output to a printer.'
[Write-Progress]: #write-progress '```&#10;[PS] Write-Progress&#10;```&#10;Displays a progress bar within a PowerShell command window.'
[Disable-PSBreakpoint]: #disable-psbreakpoint '```&#10;[PS] Disable-PSBreakpoint&#10;```&#10;Disables the breakpoints in the current console.'
[Enable-PSBreakpoint]: #enable-psbreakpoint '```&#10;[PS] Enable-PSBreakpoint&#10;```&#10;Enables the breakpoints in the current console.'
[Get-PSBreakpoint]: #get-psbreakpoint '```&#10;[PS] Get-PSBreakpoint&#10;```&#10;Gets the breakpoints that are set in the current session.'
[Remove-PSBreakpoint]: #remove-psbreakpoint '```&#10;[PS] Remove-PSBreakpoint&#10;```&#10;Deletes breakpoints from the current console.'
[Set-PSBreakpoint]: #set-psbreakpoint '```&#10;[PS] Set-PSBreakpoint&#10;```&#10;Sets a breakpoint on a line, command, or variable.'
[Get-PSCallStack]: #get-pscallstack '```&#10;[PS] Get-PSCallStack&#10;```&#10;Displays the current call stack.'
[Export-PSSession]: #export-pssession '```&#10;[PS] Export-PSSession&#10;```&#10;Exports commands from another session and saves them in a PowerShell module.'
[Import-PSSession]: #import-pssession '```&#10;[PS] Import-PSSession&#10;```&#10;Imports commands from another session into the current session.'
[Get-Random]: #get-random '```&#10;[PS] Get-Random&#10;```&#10;Gets a random number, or selects objects randomly from a collection.'
[Invoke-RestMethod]: #invoke-restmethod '```&#10;[PS] Invoke-RestMethod&#10;```&#10;Sends an HTTP or HTTPS request to a RESTful web service.'
[Debug-Runspace]: #debug-runspace '```&#10;[PS] Debug-Runspace&#10;```&#10;Starts an interactive debugging session with a runspace.'
[Get-Runspace]: #get-runspace '```&#10;[PS] Get-Runspace&#10;```&#10;Gets active runspaces within a PowerShellhost process.'
[Disable-RunspaceDebug]: #disable-runspacedebug '```&#10;[PS] Disable-RunspaceDebug&#10;```&#10;Disables debugging on one or more runspaces, and releases any pending debugger stop.'
[Enable-RunspaceDebug]: #enable-runspacedebug '```&#10;[PS] Enable-RunspaceDebug&#10;```&#10;Enables debugging on runspaces where any breakpoint is preserved until a debugger is attached.'
[Get-RunspaceDebug]: #get-runspacedebug '```&#10;[PS] Get-RunspaceDebug&#10;```&#10;Shows runspace debugging options.'
[ConvertFrom-SddlString]: #convertfrom-sddlstring '```&#10;[PS] ConvertFrom-SddlString&#10;```&#10;Converts a SDDL string to a custom object.'
[Start-Sleep]: #start-sleep '```&#10;[PS] Start-Sleep&#10;```&#10;Suspends the activity in a script or session for the specified period of time.'
[Join-String]: #join-string '```&#10;[PS] Join-String&#10;```&#10;Combines objects from the pipeline into a single string.'
[Out-String]: #out-string '```&#10;[PS] Out-String&#10;```&#10;Sends objects to the host as a series of strings.'
[Select-String]: #select-string '```&#10;[PS] Select-String&#10;```&#10;Finds text in strings and files.'
[ConvertFrom-StringData]: #convertfrom-stringdata '```&#10;[PS] ConvertFrom-StringData&#10;```&#10;Converts a string containing one or more key and value pairs to a hash table.'
[Format-Table]: #format-table '```&#10;[PS] Format-Table&#10;[PS] ft&#10;```&#10;Formats the output as a table.'
[New-TemporaryFile]: #new-temporaryfile '```&#10;[PS] New-TemporaryFile&#10;```&#10;Creates a temporary file.'
[New-TimeSpan]: #new-timespan '```&#10;[PS] New-TimeSpan&#10;```&#10;Creates a TimeSpan object.'
[Get-TraceSource]: #get-tracesource '```&#10;[PS] Get-TraceSource&#10;```&#10;Gets PowerShell components that are instrumented for tracing.'
[Set-TraceSource]: #set-tracesource '```&#10;[PS] Set-TraceSource&#10;```&#10;Configures, starts, and stops a trace of PowerShell components.'
[Add-Type]: #add-type '```&#10;[PS] Add-Type&#10;```&#10;Adds a Microsoft .NET Core class to a PowerShell session.'
[Get-TypeData]: #get-typedata '```&#10;[PS] Get-TypeData&#10;```&#10;Gets the extended type data in the current session.'
[Remove-TypeData]: #remove-typedata '```&#10;[PS] Remove-TypeData&#10;```&#10;Deletes extended types from the current session.'
[Update-TypeData]: #update-typedata '```&#10;[PS] Update-TypeData&#10;```&#10;Updates the extended type data in the session.'
[Get-UICulture]: #get-uiculture '```&#10;[PS] Get-UICulture&#10;```&#10;Gets the current UI culture settings in the operating system.'
[Get-Unique]: #get-unique '```&#10;[PS] Get-Unique&#10;```&#10;Returns unique items from a sorted list.'
[Get-Uptime]: #get-uptime '```&#10;[PS] Get-Uptime&#10;```&#10;Get the TimeSpan since last boot.'
[Clear-Variable]: #clear-variable '```&#10;[PS] Clear-Variable&#10;```&#10;Deletes the value of a variable.'
[Get-Variable]: #get-variable '```&#10;[PS] Get-Variable&#10;```&#10;Gets the variables in the current console.'
[New-Variable]: #new-variable '```&#10;[PS] New-Variable&#10;```&#10;Creates a new variable.'
[Remove-Variable]: #remove-variable '```&#10;[PS] Remove-Variable&#10;```&#10;Deletes a variable and its value.'
[Set-Variable]: #set-variable '```&#10;[PS] Set-Variable&#10;```&#10;Sets the value of a variable. Creates the variable if one with the requested name does not exist.'
[Get-Verb]: #get-verb '```&#10;[PS] Get-Verb&#10;```&#10;Gets approved PowerShell verbs.'
[Write-Verbose]: #write-verbose '```&#10;[PS] Write-Verbose&#10;```&#10;Writes text to the verbose message stream.'
[Write-Warning]: #write-warning '```&#10;[PS] Write-Warning&#10;```&#10;Writes a warning message.'
[Invoke-WebRequest]: #invoke-webrequest '```&#10;[PS] Invoke-WebRequest&#10;```&#10;Gets content from a web page on the internet.'
[Format-Wide]: #format-wide '```&#10;[PS] Format-Wide&#10;```&#10;Formats objects as a wide table that displays only one property of each object.'
[ConvertTo-Xml]: #convertto-xml '```&#10;[PS] ConvertTo-Xml&#10;```&#10;Creates an XML-based representation of an object.'
[Select-Xml]: #select-xml '```&#10;[PS] Select-Xml&#10;```&#10;Finds text in an XML string or document.'

- Alias
[`Export`][Export-Alias]<sup>[?][msdocs:Export-Alias]</sup>
[`Get`][Get-Alias]<sup>[?][msdocs:Get-Alias]</sup>
[`Import`][Import-Alias]<sup>[?][msdocs:Import-Alias]</sup>
[`New`][New-Alias]<sup>[?][msdocs:New-Alias]</sup>
[`Remove`][Remove-Alias]<sup>[?][msdocs:Remove-Alias]</sup>
[`Set`][Set-Alias]<sup>[?][msdocs:Set-Alias]</sup>
- CliXml
[`Export`][Export-Clixml]<sup>[?][msdocs:Export-Clixml]</sup>
[`Import`][Import-Clixml]<sup>[?][msdocs:Import-Clixml]</sup>
- Date
[`Get`][Get-Date]<sup>[?][msdocs:Get-Date]</sup>
[`Set`][Set-Date]<sup>[?][msdocs:Set-Date]</sup>
- Event 
[`Get`][Get-Event]<sup>[?][msdocs:Get-Event]</sup>
[`New`][New-Event]<sup>[?][msdocs:New-Event]</sup>
[`Remove`][Remove-Event]<sup>[?][msdocs:Remove-Event]</sup>
[`Unregister`][Unregister-Event]<sup>[?][msdocs:Unregister-Event]</sup>
[`Wait`][Wait-Event]<sup>[?][msdocs:Wait-Event]</sup>
- Format-
[`Custom`][Format-Custom]<sup>[?][msdocs:Format-Custom]</sup>
[`Hex`][Format-Hex]<sup>[?][msdocs:Format-Hex]</sup>
[`List`][Format-List]<sup>[?][msdocs:Format-List]</sup>
[`Table`][Format-Table]<sup>[?][msdocs:Format-Table]</sup>
[`Wide`][Format-Wide]<sup>[?][msdocs:Format-Wide]</sup>
- GUID
[`New`][New-Guid]<sup>[?][msdocs:New-Guid]</sup>
- JSON
[`ConvertFrom`][ConvertFrom-Json]<sup>[?][msdocs:ConvertFrom-Json]</sup>
[`ConvertTo`][ConvertTo-Json]<sup>[?][msdocs:ConvertTo-Json]</sup>
- Markdown
[`ConvertFrom`][ConvertFrom-Markdown]<sup>[?][msdocs:ConvertFrom-Markdown]</sup>
[`Show`][Show-Markdown]<sup>[?][msdocs:Show-Markdown]</sup>
- Random
[`Get`][Get-Random]<sup>[?][msdocs:Get-Random]</sup>
- WebRequest
[`Invoke`][Invoke-WebRequest]<sup>[?][msdocs:Invoke-WebRequest]</sup>
- XML
[`ConvertTo`][ConvertTo-Xml]<sup>[?][msdocs:ConvertTo-Xml]</sup>
[`Select`][Select-Xml]<sup>[?][msdocs:Select-Xml]</sup>
#### Microsoft.Powershell.WSMan.Management
[msdocs:Enable-WSManCredSSP]: https://docs.microsoft.com/en-us/powershell/module/Microsoft.WSMan.Management/Enable-WSManCredSSP "Enable-WSManCredSSP documentation"
[Enable-WSManCredSSP]: #enable-wsmancredssp '```&#10;[PS] Enable-WSManCredSSP&#10;```&#10;Enable the use of CredSSP for authentication between hosts in different domains&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 176'

- WSManCredSSP
[`Enable`][Enable-WSManCredSSP]<sup>[?][msdocs:Enable-WSManCredSSP]</sup>
#### netadapter
[Disable-NetAdapter]: #disable-netadapter '```&#10;[PS] Disable-NetAdapter&#10;```&#10;Disables a network adapter.'
[Enable-NetAdapter]: #enable-netadapter '```&#10;[PS] Enable-NetAdapter&#10;```&#10;Enables a network adapter.'
[Get-NetAdapter]: #get-netadapter '```&#10;[PS] Get-NetAdapter&#10;```&#10;Gets the basic network adapter properties.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 19'
[Enable-NetAdapterRdma]: #enable-netadapterrdma '```&#10;[PS] Enable-NetAdapterRdma&#10;```&#10;Enables RDMA on a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'
[Get-NetAdapterRdma]: #get-netadapterrdma '```&#10;[PS] Get-NetAdapterRdma&#10;```&#10;Gets the RDMA properties for a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'
[Enable-NetAdapterVmq]: #enable-netadaptervmq '```&#10;[PS] Enable-NetAdapterVmq&#10;```&#10;Enables VMQ on a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Get-NetAdapterVmq]: #get-netadaptervmq '```&#10;[PS] Get-NetAdapterVmq&#10;```&#10;Gets the VMQ properties of a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Set-NetAdapterVmq]: #set-netadaptervmq '```&#10;[PS] Set-NetAdapterVmq&#10;```&#10;Sets the VMQ properties of a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'
[Get-NetAdapterVmqQueue]: #get-netadaptervmqqueue '```&#10;[PS] Get-NetAdapterVmqQueue&#10;```&#10;Gets the VMQs allocated on a network adapter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'

[msdocs:Disable-NetAdapter]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Disable-NetAdapter "Disable-NetAdapter documentation"
[msdocs:Enable-NetAdapter]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Enable-NetAdapter "Enable-NetAdapter documentation"
[msdocs:Enable-NetAdapterRdma]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Enable-NetAdapterRdma "Enable-NetAdapterRdma documentation"
[msdocs:Get-NetAdapterRdma]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Get-NetAdapterRdma "Get-NetAdapterRdma documentation"
[msdocs:Get-NetAdapter]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Get-NetAdapter "Get-NetAdapter documentation"
[msdocs:Enable-NetAdapterVmq]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Enable-NetAdapterVmq "Enable-NetAdapterVmq documentation"
[msdocs:Get-NetAdapterVmq]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Get-NetAdapterVmq "Get-NetAdapterVmq documentation"
[msdocs:Set-NetAdapterVmq]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Set-NetAdapterVmq "Set-NetAdapterVmq documentation"
[msdocs:Get-NetAdapterVmqQueue]: https://docs.microsoft.com/en-us/powershell/module/netadapter/Get-NetAdapterVmqQueue "Get-NetAdapterVmqQueue documentation"

- NetAdapter 
[`Disable`][Disable-NetAdapter]<sup>[?][msdocs:Disable-NetAdapter]</sup> 
[`Enable`][Enable-NetAdapter]<sup>[?][msdocs:Enable-NetAdapter]</sup>
[`Get`][Get-NetAdapter]<sup>[?][msdocs:Get-NetAdapter]</sup>
- NetAdapterRdma 
[`Enable`][Enable-NetAdapterRdma]<sup>[?][msdocs:Enable-NetAdapterRdma]</sup> 
[`Get`][Get-NetAdapterRdma]<sup>[?][msdocs:Get-NetAdapterRdma]</sup>
- NetAdapterVmq
[`Enable`][Enable-NetAdapterVmq]<sup>[?][msdocs:Enable-NetAdapterVmq]</sup>
[`Get`][Get-NetAdapterVmq]<sup>[?][msdocs:Get-NetAdapterVmq]</sup>
[`Set`][Set-NetAdapterVmq]<sup>[?][msdocs:Set-NetAdapterVmq]</sup>
- NetAdapterVmqQueue
[`Get`][Get-NetAdapterVmqQueue]<sup>[?][msdocs:Get-NetAdapterVmqQueue]</sup>

#### netconnection
[msdocs:Get-NetConnectionProfile]: https://docs.microsoft.com/en-us/powershell/module/netconnection/Get-NetConnectionProfile "Get-NetConnectionProfile documentation"
[msdocs:Set-NetConnectionProfile]: https://docs.microsoft.com/en-us/powershell/module/netconnection/Set-NetConnectionProfile "Set-NetConnectionProfile documentation"

[Get-NetConnectionProfile]: #get-netconnectionprofile '```&#10;[PS] Get-NetConnectionProfile&#10;```&#10;Gets a connection profile.'
[Set-NetConnectionProfile]: #set-netconnectionprofile '```&#10;[PS] Set-NetConnectionProfile&#10;```&#10;Changes the network category of a connection profile.'

- NetConnectionProfile [`Get`][Get-NetConnectionProfile]<sup>[?][msdocs:Get-NetConnectionProfile]</sup> [`Set`][Set-NetConnectionProfile]<sup>[?][msdocs:Set-NetConnectionProfile]</sup>

#### netsecurity
[Copy-NetFirewallRule]: #copy-netfirewallrule '```&#10;[PS] Copy-NetFirewallRule&#10;```&#10;Copies an entire firewall rule, and associated filters, to the same or to a different policy store.'
[Disable-NetFirewallRule]: #disable-netfirewallrule '```&#10;[PS] Disable-NetFirewallRule&#10;```&#10;Disables a firewall rule.'
[Enable-NetFirewallRule]: #enable-netfirewallrule '```&#10;[PS] Enable-NetFirewallRule&#10;```&#10;Enables a previously disabled firewall rule.'
[Get-NetFirewallRule]: #get-netfirewallrule '```&#10;[PS] Get-NetFirewallRule&#10;```&#10;Retrieves firewall rules from the target computer.'
[New-NetFirewallRule]: #new-netfirewallrule '```&#10;[PS] New-NetFirewallRule&#10;```&#10;Creates a new inbound or outbound firewall rule and adds the rule to the target computer.'
[Remove-NetFirewallRule]: #remove-netfirewallrule '```&#10;[PS] Remove-NetFirewallRule&#10;```&#10;Deletes one or more firewall rules that match the specified criteria.'
[Rename-NetFirewallRule]: #rename-netfirewallrule '```&#10;[PS] Rename-NetFirewallRule&#10;```&#10;Renames a single IPsec rule.'
[Set-NetFirewallRule]: #set-netfirewallrule '```&#10;[PS] Set-NetFirewallRule&#10;```&#10;Modifies existing firewall rules.'
[Show-NetFirewallRule]: #show-netfirewallrule '```&#10;[PS] Show-NetFirewallRule&#10;```&#10;Displays all of the existing IPsec rules and associated objects in a fully expanded view.'

[msdocs:Copy-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Copy-NetFirewallRule "Copy-NetFirewallRule documentation"
[msdocs:Disable-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Disable-NetFirewallRule "Disable-NetFirewallRule documentation"
[msdocs:Enable-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Enable-NetFirewallRule "Enable-NetFirewallRule documentation"
[msdocs:Get-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Get-NetFirewallRule "Get-NetFirewallRule documentation"
[msdocs:New-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/New-NetFirewallRule "New-NetFirewallRule documentation"
[msdocs:Remove-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Remove-NetFirewallRule "Remove-NetFirewallRule documentation"
[msdocs:Rename-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Rename-NetFirewallRule "Rename-NetFirewallRule documentation"
[msdocs:Set-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Set-NetFirewallRule "Set-NetFirewallRule documentation"
[msdocs:Show-NetFirewallRule]: https://docs.microsoft.com/en-us/powershell/module/NetSecurity/Show-NetFirewallRule "Show-NetFirewallRule documentation"

- NetFirewallRule 
[`Copy`][Copy-NetFirewallRule]<sup>[?][msdocs:Copy-NetFirewallRule]</sup>
[`Disable`][Disable-NetFirewallRule]<sup>[?][msdocs:Disable-NetFirewallRule]</sup>
[`Enable`][Enable-NetFirewallRule]<sup>[?][msdocs:Enable-NetFirewallRule]</sup>
[`Get`][Get-NetFirewallRule]<sup>[?][msdocs:Get-NetFirewallRule]</sup>
[`New`][New-NetFirewallRule]<sup>[?][msdocs:New-NetFirewallRule]</sup>
[`Remove`][Remove-NetFirewallRule]<sup>[?][msdocs:Remove-NetFirewallRule]</sup>
[`Rename`][Rename-NetFirewallRule]<sup>[?][msdocs:Rename-NetFirewallRule]</sup>
[`Set`][Set-NetFirewallRule]<sup>[?][msdocs:Set-NetFirewallRule]</sup>
[`Show`][Show-NetFirewallRule]<sup>[?][msdocs:Show-NetFirewallRule]</sup>

#### nettcpip
[msdocs:Get-NetIPAddress]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/Get-NetIPAddress "Get-NetIPAddress"
[msdocs:New-NetIPAddress]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/New-NetIPAddress "New-NetIPAddress"
[msdocs:Remove-NetIPAddress]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/Remove-NetIPAddress "Remove-NetIPAddress"
[msdocs:Set-NetIPAddress]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/Set-NetIPAddress "Set-NetIPAddress"
[msdocs:Get-NetIPInterface]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/Get-NetIPInterface "Get-NetIPInterface"
[msdocs:Set-NetIPInterface]: https://docs.microsoft.com/en-us/powershell/module/nettcpip/Set-NetIPInterface "Set-NetIPInterface"

[Get-NetIPAddress]: #get-netipaddress '```&#10;PS C:\> Get-NetIPAddress&#10;```&#10;Gets the IP address configuration.'
[New-NetIPAddress]: #new-netipaddress '```&#10;PS C:\> New-NetIPAddress&#10;```&#10;Creates and configures an IP address.'
[Remove-NetIPAddress]: #remove-netipaddress '```&#10;PS C:\> Remove-NetIPAddress&#10;```&#10;Removes an IP address and its configuration.'
[Set-NetIPAddress]: #set-netipaddress '```&#10;PS C:\> Set-NetIPAddress&#10;```&#10;Modifies the configuration of an IP address.'
[Get-NetIPInterface]: #get-netipinterface '```&#10;PS C:\> Get-NetIPInterface&#10;```&#10;Gets an IP interface.'
[Set-NetIPInterface]: #set-netipinterface '```&#10;PS C:\> Set-NetIPInterface&#10;```&#10;Modifies an IP interface.'

- NetIPAddress
[`Get`][Get-NetIPAddress]<sup>[?][msdocs:Get-NetIPAddress]</sup>
[`New`][New-NetIPAddress]<sup>[?][msdocs:New-NetIPAddress]</sup>
[`Remove`][Remove-NetIPAddress]<sup>[?][msdocs:Remove-NetIPAddress]</sup>
[`Set`][Set-NetIPAddress]<sup>[?][msdocs:Set-NetIPAddress]</sup>
- NetIPInterface
[`Get`][Get-NetIPInterface]<sup>[?][msdocs:Get-NetIPInterface]</sup>
[`Set`][Set-NetIPInterface]<sup>[?][msdocs:Set-NetIPInterface]</sup>

#### nanoserverimagegenerator
[msdocs:Edit-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/NanoServerImageGenerator/Edit-NanoServerImage "Edit-NanoServerImage documentation"
[msdocs:New-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/NanoServerImageGenerator/New-NanoServerImage "New-NanoServerImage documentation"

[Edit-NanoServerImage]: #edit-nanoserverimage '```&#10;[PS] Edit-NanoServerImage&#10;```&#10;Add a role or feature to an existing Nano Server VHD file&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 49'
[New-NanoServerImage]: #new-nanoserverimage '```&#10;[PS] New-NanoServerImage&#10;New-NanoServerImage -DeploymentType guest|host -Edition standard|datacenter -MediaPath root -TargetPath $PATH -ComputerName $NAME&#10;```&#10;Used to create a Nano Server VHD file for Nano Server installation&#10;Required parameters:&#10;  `DeploymentType` specified whether the image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;  `Edition` specifies whether to install the Standard or Datacenter edition of Nano Server&#10;  `MediaPath` specifies the path to the root of the WS2016 installation disk or mounted image&#10;  `BasePath` specifies a path on the local system where the cmdlet creates a copy of the installation files from the location specified in `MediaPath`&#10;  `TargetPath` specifies the full path and filename of the new image to be created with the filename extension (".vhd" or ".vhdx") specifying Generation 1 or Generation 2 image.&#10;  `ComputerName` specifies the computer name that should be assigned to the new image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'

- NanoServerImage
[`Edit`][Edit-NanoServerImage]<sup>[?][msdocs:Edit-NanoServerImage]</sup>
[`New`][New-NanoServerImage]<sup>[?][msdocs:New-NanoServerImage]</sup>

#### netqos
[msdocs:Get-NetQosPolicy]: https://docs.microsoft.com/en-us/powershell/module/netqos/Get-NetQosPolicy "Get-NetQosPolicy"
[msdocs:New-NetQosPolicy]: https://docs.microsoft.com/en-us/powershell/module/netqos/New-NetQosPolicy "New-NetQosPolicy"
[msdocs:Remove-NetQosPolicy]: https://docs.microsoft.com/en-us/powershell/module/netqos/Remove-NetQosPolicy "Remove-NetQosPolicy"
[msdocs:Set-NetQosPolicy]: https://docs.microsoft.com/en-us/powershell/module/netqos/Set-NetQosPolicy "Set-NetQosPolicy"

[Get-NetQosPolicy]: #get-netqospolicy '```&#10;[PS] Get-NetQosPolicy&#10;```&#10;Retrieves network Quality of Service (QoS) policies.'
[New-NetQosPolicy]: #new-netqospolicy '```&#10;[PS] New-NetQosPolicy&#10;```&#10;Creates a new network QoS policy.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 144'
[Remove-NetQosPolicy]: #remove-netqospolicy '```&#10;[PS] Remove-NetQosPolicy&#10;```&#10;Removes a network Quality of Service (QoS) policy.'
[Set-NetQosPolicy]: #set-netqospolicy '```&#10;[PS] Set-NetQosPolicy&#10;```&#10;Updates the QoS policy settings.'

- NetQos
[`Get`][Get-NetQosPolicy]<sup>[?][msdocs:Get-NetQosPolicy]</sup>
[`New`][New-NetQosPolicy]<sup>[?][msdocs:New-NetQosPolicy]</sup>
[`Remove`][Remove-NetQosPolicy]<sup>[?][msdocs:Remove-NetQosPolicy]</sup>
[`Set`][Set-NetQosPolicy]<sup>[?][msdocs:Set-NetQosPolicy]</sup>
#### networkloadbalancingclusters
[Get-NlbCluster]: #get-nlbcluster '```&#10;[PS] Get-NlbCluster&#10;```&#10;Gets information about the NLB cluster object that is queried by the caller.'
[Set-NlbClusterPortRule]: #set-nlbclusterportrule '```&#10;[PS] Set-NlbClusterPortRule&#10;```&#10;Edits the port rules for a NLB cluster.'
[Add-NlbClusterPortRule]: #add-nlbclusterportrule '```&#10;[PS] Add-NlbClusterPortRule&#10;```&#10;Adds a new port rule to a Network Load Balancing (NLB) cluster.'

[msdocs:Add-NlbClusterPortRule]: https://docs.microsoft.com/en-us/powershell/module/networkloadbalancingclusters/Add-NlbClusterPortRule "Add-NlbClusterPortRule"
[msdocs:Get-NlbCluster]: https://docs.microsoft.com/en-us/powershell/module/networkloadbalancingclusters/Get-NlbCluster "Get-NlbCluster"
[msdocs:Set-NlbClusterPortRule]: https://docs.microsoft.com/en-us/powershell/module/networkloadbalancingclusters/Set-NlbClusterPortRule "Set-NlbClusterPortRule"

- NLBCluster 
[`Get`][Get-NlbCluster]<sup>[?][msdocs:Get-NlbCluster]</sup>
- NLBClusterPortRule
[`Add`][Add-NlbClusterPortRule]<sup>[?][msdocs:Add-NlbClusterPortRule]</sup>
[`Set`][Set-NlbClusterPortRule]<sup>[?][msdocs:Set-NlbClusterPortRule]</sup>
#### PackageManagement
[msdocs:Find-Package]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Find-Package "Find-Package"
[msdocs:Get-Package]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Get-Package "Get-Package"
[msdocs:Install-Package]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Install-Package "Install-Package"
[msdocs:Save-Package]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Save-Package "Save-Package"
[msdocs:Uninstall-Package]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Uninstall-Package "Uninstall-Package"
[msdocs:Find-PackageProvider]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Find-PackageProvider "Find-PackageProvider"
[msdocs:Get-PackageProvider]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Get-PackageProvider "Get-PackageProvider"
[msdocs:Import-PackageProvider]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Import-PackageProvider "Import-PackageProvider"
[msdocs:Install-PackageProvider]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Install-PackageProvider "Install-PackageProvider"
[msdocs:Get-PackageSource]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Get-PackageSource "Get-PackageSource"
[msdocs:Register-PackageSource]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Register-PackageSource "Register-PackageSource"
[msdocs:Set-PackageSource]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Set-PackageSource "Set-PackageSource"
[msdocs:Unregister-PackageSource]: https://docs.microsoft.com/en-us/powershell/module/PackageManagement/Unregister-PackageSource "Unregister-PackageSource"

[Find-Package]: #find-package '```&#10;PS C:\> Find-Package&#10;```&#10;Finds software packages in available package sources.'
[Find-PackageProvider]: #find-packageprovider '```&#10;PS C:\> Find-PackageProvider&#10;```&#10;Returns a list of Package Management package providers available for installation.'
[Get-Package]: #get-package '```&#10;PS C:\> Get-Package&#10;```&#10;Returns a list of all software packages that have been installed by using Package Management.'
[Get-PackageProvider]: #get-packageprovider '```&#10;PS C:\> Get-PackageProvider&#10;```&#10;Returns a list of package providers that are connected to Package Management.'
[Get-PackageSource]: #get-packagesource '```&#10;PS C:\> Get-PackageSource&#10;```&#10;Gets a list of package sources that are registered for a package provider.'
[Import-PackageProvider]: #import-packageprovider '```&#10;PS C:\> Import-PackageProvider&#10;```&#10;Adds Package Management package providers to the current session.'
[Install-Package]: #install-package '```&#10;PS C:\> Install-Package&#10;```&#10;Installs one or more software packages.'
[Install-PackageProvider]: #install-packageprovider '```&#10;PS C:\> Install-PackageProvider&#10;```&#10;Installs one or more Package Management package providers.'
[Register-PackageSource]: #register-packagesource '```&#10;PS C:\> Register-PackageSource&#10;```&#10;Adds a package source for a specified package provider.'
[Save-Package]: #save-package '```&#10;PS C:\> Save-Package&#10;```&#10;Saves packages to the local computer without installing them.'
[Set-PackageSource]: #set-packagesource '```&#10;PS C:\> Set-PackageSource&#10;```&#10;Replaces a package source for a specified package provider.'
[Uninstall-Package]: #uninstall-package '```&#10;PS C:\> Uninstall-Package&#10;```&#10;Uninstalls one or more software packages.'
[Unregister-PackageSource]: #unregister-packagesource '```&#10;PS C:\> Unregister-PackageSource&#10;```&#10;Removes a registered package source.'

- Package
<code>&nbsp;[ep][Find-Package][?][msdocs:Find-Package]&nbsp;[g][Get-Package][?][msdocs:Get-Package]&nbsp;[is][Install-Package][?][msdocs:Install-Package]&nbsp;[sv][Save-Package][?][msdocs:Save-Package]&nbsp;[us][Uninstall-Package][?][msdocs:Uninstall-Package]</code>
<code>Provider&nbsp;[ep][Find-PackageProvider][?][msdocs:Find-PackageProvider]&nbsp;[g][Get-PackageProvider][?][msdocs:Get-PackageProvider]&nbsp;[ip][Import-PackageProvider][?][msdocs:Import-PackageProvider]&nbsp;[is][Install-PackageProvider][?][msdocs:Install-PackageProvider]</code>
<code>Source&nbsp;[g][Get-PackageSource][?][msdocs:Get-PackageSource]&nbsp;[rg][Register-PackageSource][?][msdocs:Register-PackageSource]&nbsp;[s][Set-PackageSource][?][msdocs:Set-PackageSource]&nbsp;[ur][Unregister-PackageSource][?][msdocs:Unregister-PackageSource]</code>
#### psdesiredstateconfiguration
[msdocs:New-DSCCheckSum]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/New-DSCCheckSum "New-DSCCheckSum"
[msdocs:Get-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Get-DscConfiguration "Get-DscConfiguration"
[msdocs:Publish-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Publish-DscConfiguration "Publish-DscConfiguration"
[msdocs:Restore-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Restore-DscConfiguration "Restore-DscConfiguration"
[msdocs:Start-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Start-DscConfiguration "Start-DscConfiguration"
[msdocs:Stop-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Stop-DscConfiguration "Stop-DscConfiguration"
[msdocs:Test-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Test-DscConfiguration "Test-DscConfiguration"
[msdocs:Update-DscConfiguration]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Update-DscConfiguration "Update-DscConfiguration"
[msdocs:Remove-DscConfigurationDocument]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Remove-DscConfigurationDocument "Remove-DscConfigurationDocument"
[msdocs:Get-DscConfigurationStatus]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Get-DscConfigurationStatus "Get-DscConfigurationStatus"
[msdocs:Disable-DscDebug]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Disable-DscDebug "Disable-DscDebug"
[msdocs:Enable-DscDebug]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Enable-DscDebug "Enable-DscDebug"
[msdocs:Get-DscLocalConfigurationManager]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Get-DscLocalConfigurationManager "Get-DscLocalConfigurationManager"
[msdocs:Set-DscLocalConfigurationManager]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Set-DscLocalConfigurationManager "Set-DscLocalConfigurationManager"
[msdocs:Get-DscResource]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Get-DscResource "Get-DscResource"
[msdocs:Invoke-DscResource]: https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Invoke-DscResource "Invoke-DscResource"

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

**`DSC`**
<code>CheckSum&nbsp;[n][New-DscCheckSum]</code>
<code>Configuration&nbsp;[g][Get-DscConfiguration]&nbsp;[pb][Publish-DscConfiguration]&nbsp;[rr][Restore-DscConfiguration]&nbsp;[sa][Start-DscConfiguration]&nbsp;[sp][Stop-DscConfiguration]&nbsp;[t][Test-DscConfiguration]&nbsp;[u][Update-DscConfiguration]</code>
<code>ConfigurationDocument&nbsp;[r][Remove-DscConfigurationDocument]</code>
<code>ConfigurationStatus&nbsp;[g][Get-DscConfigurationStatus]</code>
<code>Debug&nbsp;[d][Disable-DscDebug]&nbsp;[e][Enable-DscDebug]</code>
<code>LocalConfigurationManager&nbsp;[g][Get-DscLocalConfigurationManager]&nbsp;[s][Set-DscLocalConfigurationManager]</code>
<code>Resource&nbsp;[g][Get-DscResource]&nbsp;[i][Invoke-DscResource]</code>
#### servermanager
[Disable-ServerManagerStandardUserRemoting]: #disable-servermanagerstandarduserremoting '```&#10;Disable-ServerManagerStandardUserRemoting&#10;```&#10;Disables access for specified standard users to event, service, performance counter, and role and feature inventory data that is collected by Server Manager for a server.'
[Enable-ServerManagerStandardUserRemoting]: #enable-servermanagerstandarduserremoting '```&#10;Enable-ServerManagerStandardUserRemoting&#10;```&#10;Provides one or more standard, non-Administrator users access to event, service, performance counter, and role and feature inventory data for a server that you are managing by using Server Manager.'
[Get-WindowsFeature]: #get-windowsfeature '```&#10;Get-WindowsFeature&#10;```&#10;Gets information about Windows Server roles, role services, and features that are available for installation and installed on a specified server.'
[Install-WindowsFeature]: #install-windowsfeature '```&#10;Install-WindowsFeature&#10;```&#10;Installs one or more roles, role services, or features on either the local or a specified remote server that is running Windows Server 2012 R2.'
[Uninstall-WindowsFeature]: #uninstall-windowsfeature '```&#10;Uninstall-WindowsFeature&#10;```&#10;Uninstalls specified Windows Server roles, role services, and features from a computer that is running Windows Server 2012 R2.'

[msdocs:Disable-ServerManagerStandardUserRemoting]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Disable-ServerManagerStandardUserRemoting "Disable-ServerManagerStandardUserRemoting"
[msdocs:Enable-ServerManagerStandardUserRemoting]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Enable-ServerManagerStandardUserRemoting "Enable-ServerManagerStandardUserRemoting"
[msdocs:Get-WindowsFeature]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Get-WindowsFeature "Get-WindowsFeature"
[msdocs:Install-WindowsFeature]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Install-WindowsFeature "Install-WindowsFeature"
[msdocs:Uninstall-WindowsFeature]: https://docs.microsoft.com/en-us/powershell/module/servermanager/Uninstall-WindowsFeature "Uninstall-WindowsFeature"

<code>WindowsFeature&nbsp;[g][Get-WindowsFeature][?][msdocs:Get-WindowsFeature]&nbsp;[is][Install-WindowsFeature][?][msdocs:Install-WindowsFeature]&nbsp;[us][Uninstall-WindowsFeature][?][msdocs:Uninstall-WindowsFeature]</code>
#### servermigration
[msdocs:Receive-SmigServerData]: https://docs.microsoft.com/en-us/powershell/module/ServerMigration/Receive-SmigServerData "Receive-SmigServerData"
[msdocs:Send-SmigServerData]: https://docs.microsoft.com/en-us/powershell/module/ServerMigration/Send-SmigServerData "Send-SmigServerData"
[msdocs:Get-SmigServerFeature]: https://docs.microsoft.com/en-us/powershell/module/ServerMigration/Get-SmigServerFeature "Get-SmigServerFeature"
[msdocs:Export-SmigServerSetting]: https://docs.microsoft.com/en-us/powershell/module/ServerMigration/Export-SmigServerSetting "Export-SmigServerSetting"
[msdocs:Import-SmigServerSetting]: https://docs.microsoft.com/en-us/powershell/module/ServerMigration/Import-SmigServerSetting "Import-SmigServerSetting"

[Receive-SmigServerData]: #receive-smigserverdata '```&#10;PS C:\> Receive-SmigServerData&#10;```&#10;Enable a destination server to receive migrated files, folders, permissions, and share properties from a source server (`Send-SmigServerData` cmdlet must be running on the source server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Send-SmigServerData]: #send-smigserverdata '```&#10;PS C:\> Send-SmigServerData&#10;```&#10;Migrate files, folders, permissions, and share properties from a source server to a destination server (`Receive-SmigServerData` cmdlet must be running on the destination server at the same time)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Get-SmigServerFeature]: #get-smigserverfeature '```&#10;PS C:\> Get-SmigServerFeature&#10;```&#10;Display a list of Windows features that can be migrated from the local server or ffrom a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Export-SmigServerSetting]: #export-smigserversetting '```&#10;PS C:\> Export-SmigServerSetting&#10;```&#10;Export certain Windows features and operating system settings to a migration store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Import-SmigServerSetting]: #import-smigserversetting '```&#10;PS C:\> Import-SmigServerSetting&#10;```&#10;Import certain Windows features and operating system settings from a migration store and apply them to the local server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'

**`SmigServer`**
- SmigServerData [`Receive`][Receive-SmigServerData]<sup>[?][msdocs:Receive-SmigServerData]</sup> [`Send`][Send-SmigServerData]<sup>[?][msdocs:Send-SmigServerData]</sup>
- SmigServerFeature ['Get'][Get-SmigServerFeature]<sup>[?][msdocs:Get-SmigServerFeature]</sup>
- SmigServerSetting ['Export'][Export-SmigServerSetting]<sup>[?][msdocs:Export-SmigServerSetting]</sup> [`Import`][Import-SmigServerSetting]<sup>[?][msdocs:Import-SmigServerSetting]</sup>
#### smbshare
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
#### storagereplica
[msdocs:Get-SRAccess]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Get-SRAccess "Get-SRAccess"
[msdocs:Grant-SRAccess]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Grant-SRAccess "Grant-SRAccess"
[msdocs:Revoke-SRAccess]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Revoke-SRAccess "Revoke-SRAccess"
[msdocs:Export-SRConfiguration]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Export-SRConfiguration "Export-SRConfiguration"
[msdocs:Get-SRDelegation]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Get-SRDelegation "Get-SRDelegation"
[msdocs:Grant-SRDelegation]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Grant-SRDelegation "Grant-SRDelegation"
[msdocs:Revoke-SRDelegation]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Revoke-SRDelegation "Revoke-SRDelegation"
[msdocs:Get-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Get-SRGroup "Get-SRGroup"
[msdocs:New-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/New-SRGroup "New-SRGroup"
[msdocs:Remove-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Remove-SRGroup "Remove-SRGroup"
[msdocs:Set-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Set-SRGroup "Set-SRGroup"
[msdocs:Suspend-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Suspend-SRGroup "Suspend-SRGroup"
[msdocs:Sync-SRGroup]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Sync-SRGroup "Sync-SRGroup"
[msdocs:Clear-SRMetadata]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Clear-SRMetadata "Clear-SRMetadata"
[msdocs:Get-SRNetworkConstraint]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Get-SRNetworkConstraint "Get-SRNetworkConstraint"
[msdocs:Remove-SRNetworkConstraint]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Remove-SRNetworkConstraint "Remove-SRNetworkConstraint"
[msdocs:Set-SRNetworkConstraint]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Set-SRNetworkConstraint "Set-SRNetworkConstraint"
[msdocs:Get-SRPartnership]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Get-SRPartnership "Get-SRPartnership"
[msdocs:New-SRPartnership]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/New-SRPartnership "New-SRPartnership"
[msdocs:Remove-SRPartnership]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Remove-SRPartnership "Remove-SRPartnership"
[msdocs:Set-SRPartnership]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Set-SRPartnership "Set-SRPartnership"
[msdocs:Test-SRTopology]: https://docs.microsoft.com/en-us/powershell/module/storagereplica/Test-SRTopology "Test-SRTopology"

[Clear-SRMetadata]: #clear-srmetadata '```&#10;Clear-SRMetadata&#10;```&#10;Removes unreferenced Storage Replica metadata.'
[Export-SRConfiguration]: #export-srconfiguration '```&#10;Export-SRConfiguration&#10;```&#10;Exports replication configuration to a Windows PowerShell script.'
[Get-SRAccess]: #get-sraccess '```&#10;Get-SRAccess&#10;```&#10;Gets security access between failover clusters.'
[Get-SRDelegation]: #get-srdelegation '```&#10;Get-SRDelegation&#10;```&#10;Gets security delegation on a Storage Replica server.'
[Get-SRGroup]: #get-srgroup '```&#10;Get-SRGroup&#10;```&#10;Gets replication groups.'
[Get-SRNetworkConstraint]: #get-srnetworkconstraint '```&#10;Get-SRNetworkConstraint&#10;```&#10;Gets replication network constraints for Storage Replica partnerships.'
[Get-SRPartnership]: #get-srpartnership '```&#10;Get-SRPartnership&#10;```&#10;Gets replication partnerships.'
[Grant-SRAccess]: #grant-sraccess '```&#10;Grant-SRAccess&#10;```&#10;Grants security access between failover clusters to enable replication.'
[Grant-SRDelegation]: #grant-srdelegation '```&#10;Grant-SRDelegation&#10;```&#10;Creates a security delegation on a Storage Replica server.'
[New-SRGroup]: #new-srgroup '```&#10;New-SRGroup&#10;```&#10;Creates a replication group.'
[New-SRPartnership]: #new-srpartnership '```&#10;New-SRPartnership&#10;```&#10;Creates a replication partnership between two replication groups.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 151'
[Remove-SRGroup]: #remove-srgroup '```&#10;Remove-SRGroup&#10;```&#10;Removes a replication group.'
[Remove-SRNetworkConstraint]: #remove-srnetworkconstraint '```&#10;Remove-SRNetworkConstraint&#10;```&#10;Removes all existing replication network constraints.'
[Remove-SRPartnership]: #remove-srpartnership '```&#10;Remove-SRPartnership&#10;```&#10;Removes a replication partnership.'
[Revoke-SRAccess]: #revoke-sraccess '```&#10;Revoke-SRAccess&#10;```&#10;Revokes security access between failover clusters that allowed replication.'
[Revoke-SRDelegation]: #revoke-srdelegation '```&#10;Revoke-SRDelegation&#10;```&#10;Revokes a security delegation on a Storage Replica server.'
[Set-SRGroup]: #set-srgroup '```&#10;Set-SRGroup&#10;```&#10;Modifies settings of a replication group.'
[Set-SRNetworkConstraint]: #set-srnetworkconstraint '```&#10;Set-SRNetworkConstraint&#10;```&#10;Creates or modifies a replication network constraint for servers and partnerships.'
[Set-SRPartnership]: #set-srpartnership '```&#10;Set-SRPartnership&#10;```&#10;Modifies a replication partnership between two replication groups.'
[Suspend-SRGroup]: #suspend-srgroup '```&#10;Suspend-SRGroup&#10;```&#10;Pauses replication for a replication group.'
[Sync-SRGroup]: #sync-srgroup '```&#10;Sync-SRGroup&#10;```&#10;Starts or resumes replication for a replication group.'
[Test-SRTopology]: #test-srtopology '```&#10;Test-SRTopology&#10;```&#10;Validates a potential replication partnership.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 151'

<code>SRAccess&nbsp;[g][Get-SRAccess]&nbsp;[gr][Grant-SRAccess]&nbsp;[rk][Revoke-SRAccess]</code>
<code>SRConfiguration&nbsp;[ep][Export-SRConfiguration]</code>
<code>SRDelegation&nbsp;[g][Get-SRDelegation]&nbsp;[gr][Grant-SRDelegation]&nbsp;[rk][Revoke-SRDelegation]</code>
<code>SRGroup&nbsp;[g][Get-SRGroup]&nbsp;[n][New-SRGroup]&nbsp;[r][Remove-SRGroup]&nbsp;[s][Set-SRGroup]&nbsp;[ss][Suspend-SRGroup]&nbsp;[sy][Sync-SRGroup]</code>
<code>SRMetadata&nbsp;[ch][Clear-SRMetadata]</code>
<code>SRNetworkConstraint&nbsp;[g][Get-SRNetworkConstraint]&nbsp;[r][Remove-SRNetworkConstraint]&nbsp;[s][Set-SRNetworkConstraint]</code>
<code>SRPartnership&nbsp;[g][Get-SRPartnership]&nbsp;[n][New-SRPartnership]&nbsp;[r][Remove-SRPartnership]&nbsp;[s][Set-SRPartnership]</code>
<code>SRTopology&nbsp;[t][Test-SRTopology]</code>

#### VirtualMachineManager
[Set-SCVirtualMachine]: #set-scvirtualmachine '```&#10;[PS] Set-SCVirtualMachine&#10;```&#10;Changes properties of a virtual machine managed by VMM.'
[msdocs:Set-SCVirtualMachine]: https://docs.microsoft.com/en-us/powershell/module/VirtualMachineManager/Set-SCVirtualMachine "Set-SCVirtualMachine"

- SCVirtualMachine [`Set`][Set-SCVirtualMachine]<sup>[?][msdocs:Set-SCVirtualMachine]</sup>
#### windowsserverbackup
[Add-WBBackupTarget]: #add-wbbackuptarget '```&#10;Add-WBBackupTarget&#10;```&#10;Adds a backup target to a backup policy.'
[Add-WBBareMetalRecovery]: #add-wbbaremetalrecovery '```&#10;Add-WBBareMetalRecovery&#10;```&#10;Adds items to a backup policy so that backups that use the policy can perform bare metal recoveries.'
[Add-WBFileSpec]: #add-wbfilespec '```&#10;Add-WBFileSpec&#10;```&#10;Adds a backup file specification to a backup policy.'
[Add-WBSystemState]: #add-wbsystemstate '```&#10;Add-WBSystemState&#10;```&#10;Adds the system state components to the backup policy.'
[Add-WBVirtualMachine]: #add-wbvirtualmachine '```&#10;Add-WBVirtualMachine&#10;```&#10;Adds a list of virtual machines to the backup policy.'
[Add-WBVolume]: #add-wbvolume '```&#10;Add-WBVolume&#10;```&#10;Adds the list of source volumes to the backup policy.'
[Get-WBBackupSet]: #get-wbbackupset '```&#10;Get-WBBackupSet&#10;```&#10;Gets backups for a server from a location that you specify.'
[Get-WBBackupTarget]: #get-wbbackuptarget '```&#10;Get-WBBackupTarget&#10;```&#10;Gets backup storage locations that you specified as part of a backup policy.'
[Get-WBBackupVolumeBrowsePath]: #get-wbbackupvolumebrowsepath '```&#10;Get-WBBackupVolumeBrowsePath&#10;```&#10;Mounts a volume inside a backup so that you can browse the files on the volume.'
[Get-WBBareMetalRecovery]: #get-wbbaremetalrecovery '```&#10;Get-WBBareMetalRecovery&#10;```&#10;Indicates whether or not a backup policy can perform bare metal recoveries from backups.'
[Get-WBDisk]: #get-wbdisk '```&#10;Get-WBDisk&#10;```&#10;Gets a list of internal and external disks that are online for the local computer.'
[Get-WBFileSpec]: #get-wbfilespec '```&#10;Get-WBFileSpec&#10;```&#10;Gets the list of backup file specifications associated with a backup policy.'
[Get-WBJob]: #get-wbjob '```&#10;Get-WBJob&#10;```&#10;Gets the current backup operation.'
[Get-WBPerformanceConfiguration]: #get-wbperformanceconfiguration '```&#10;Get-WBPerformanceConfiguration&#10;```&#10;Retrieves the current volume backup performance settings.'
[Get-WBPolicy]: #get-wbpolicy '```&#10;Get-WBPolicy&#10;```&#10;Retrieves the current backup policy for the computer.'
[Get-WBSchedule]: #get-wbschedule '```&#10;Get-WBSchedule&#10;```&#10;Retrieves the current schedule for backups.'
[Get-WBSummary]: #get-wbsummary '```&#10;Get-WBSummary&#10;```&#10;Retrieves the history of backup operations on the computer.'
[Get-WBSystemState]: #get-wbsystemstate '```&#10;Get-WBSystemState&#10;```&#10;Gets a Boolean value that indicates whether system state recovery was added to the backup policy.'
[Get-WBVirtualMachine]: #get-wbvirtualmachine '```&#10;Get-WBVirtualMachine&#10;```&#10;Gets all virtual machines and components from the backup policy.'
[Get-WBVolume]: #get-wbvolume '```&#10;Get-WBVolume&#10;```&#10;Retrieves a list of volumes.'
[Get-WBVssBackupOption]: #get-wbvssbackupoption '```&#10;Get-WBVssBackupOption&#10;```&#10;Retrieves a VSS setting from the backup policy.'
[New-WBBackupTarget]: #new-wbbackuptarget '```&#10;New-WBBackupTarget&#10;```&#10;Creates a backup target object.'
[New-WBFileSpec]: #new-wbfilespec '```&#10;New-WBFileSpec&#10;```&#10;Creates a backup file specification.'
[New-WBPolicy]: #new-wbpolicy '```&#10;New-WBPolicy&#10;```&#10;Creates a backup policy object.'
[Remove-WBBackupSet]: #remove-wbbackupset '```&#10;Remove-WBBackupSet&#10;```&#10;Deletes backups from a target catalog, a system catalog, or both.'
[Remove-WBBackupTarget]: #remove-wbbackuptarget '```&#10;Remove-WBBackupTarget&#10;```&#10;Removes backup storage locations from a backup policy.'
[Remove-WBBareMetalRecovery]: #remove-wbbaremetalrecovery '```&#10;Remove-WBBareMetalRecovery&#10;```&#10;Removes a request to include items that implement bare metal recovery from the current backup policy.'
[Remove-WBCatalog]: #remove-wbcatalog '```&#10;Remove-WBCatalog&#10;```&#10;Removes the backup catalog from the local computer.'
[Remove-WBFileSpec]: #remove-wbfilespec '```&#10;Remove-WBFileSpec&#10;```&#10;Removes a backup file specification from a backup policy.'
[Remove-WBPolicy]: #remove-wbpolicy '```&#10;Remove-WBPolicy&#10;```&#10;Removes the backup policy.'
[Remove-WBSystemState]: #remove-wbsystemstate '```&#10;Remove-WBSystemState&#10;```&#10;Removes the system state components from the backup policy.'
[Remove-WBVirtualMachine]: #remove-wbvirtualmachine '```&#10;Remove-WBVirtualMachine&#10;```&#10;Removes the list of virtual machines from the backup policy.'
[Remove-WBVolume]: #remove-wbvolume '```&#10;Remove-WBVolume&#10;```&#10;Removes the volume from the backup policy.'
[Restore-WBCatalog]: #restore-wbcatalog '```&#10;Restore-WBCatalog&#10;```&#10;Recovers a backup catalog for the local computer from a storage location.'
[Resume-WBBackup]: #resume-wbbackup '```&#10;Resume-WBBackup&#10;```&#10;Resumes a backup operation to a removable device after you add media to the device.'
[Resume-WBVolumeRecovery]: #resume-wbvolumerecovery '```&#10;Resume-WBVolumeRecovery&#10;```&#10;Resumes a volume recovery operation from a removable device and specific media.'
[Set-WBPerformanceConfiguration]: #set-wbperformanceconfiguration '```&#10;Set-WBPerformanceConfiguration&#10;```&#10;Sets the current volume backup performance settings.'
[Set-WBPolicy]: #set-wbpolicy '```&#10;Set-WBPolicy&#10;```&#10;Sets the backup policy for scheduled backups.'
[Set-WBSchedule]: #set-wbschedule '```&#10;Set-WBSchedule&#10;```&#10;Sets the current schedule for backups.'
[Set-WBVssBackupOption]: #set-wbvssbackupoption '```&#10;Set-WBVssBackupOption&#10;```&#10;Sets a value that determines the VSS setting in the backup policy.'
[Start-WBApplicationRecovery]: #start-wbapplicationrecovery '```&#10;Start-WBApplicationRecovery&#10;```&#10;Starts an application recovery operation.'
[Start-WBBackup]: #start-wbbackup '```&#10;Start-WBBackup&#10;```&#10;Starts a one-time backup operation.'
[Start-WBFileRecovery]: #start-wbfilerecovery '```&#10;Start-WBFileRecovery&#10;```&#10;Starts a file recovery operation.'
[Start-WBHyperVRecovery]: #start-wbhypervrecovery '```&#10;Start-WBHyperVRecovery&#10;```&#10;Starts recovery of a hv_win8_2 virtual machine.'
[Start-WBSystemStateRecovery]: #start-wbsystemstaterecovery '```&#10;Start-WBSystemStateRecovery&#10;```&#10;Starts a system state recovery operation.'
[Start-WBVolumeRecovery]: #start-wbvolumerecovery '```&#10;Start-WBVolumeRecovery&#10;```&#10;Starts a volume recovery operation.'
[Stop-WBJob]: #stop-wbjob '```&#10;Stop-WBJob&#10;```&#10;Stops the current backup or recovery job.'

[msdocs:Add-WBBackupTarget]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBBackupTarget "Add-WBBackupTarget"
[msdocs:Add-WBBareMetalRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBBareMetalRecovery "Add-WBBareMetalRecovery"
[msdocs:Add-WBFileSpec]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBFileSpec "Add-WBFileSpec"
[msdocs:Add-WBSystemState]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBSystemState "Add-WBSystemState"
[msdocs:Add-WBVirtualMachine]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBVirtualMachine "Add-WBVirtualMachine"
[msdocs:Add-WBVolume]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Add-WBVolume "Add-WBVolume"
[msdocs:Get-WBBackupSet]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBBackupSet "Get-WBBackupSet"
[msdocs:Get-WBBackupTarget]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBBackupTarget "Get-WBBackupTarget"
[msdocs:Get-WBBackupVolumeBrowsePath]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBBackupVolumeBrowsePath "Get-WBBackupVolumeBrowsePath"
[msdocs:Get-WBBareMetalRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBBareMetalRecovery "Get-WBBareMetalRecovery"
[msdocs:Get-WBDisk]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBDisk "Get-WBDisk"
[msdocs:Get-WBFileSpec]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBFileSpec "Get-WBFileSpec"
[msdocs:Get-WBJob]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBJob "Get-WBJob"
[msdocs:Get-WBPerformanceConfiguration]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBPerformanceConfiguration "Get-WBPerformanceConfiguration"
[msdocs:Get-WBPolicy]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBPolicy "Get-WBPolicy"
[msdocs:Get-WBSchedule]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBSchedule "Get-WBSchedule"
[msdocs:Get-WBSummary]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBSummary "Get-WBSummary"
[msdocs:Get-WBSystemState]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBSystemState "Get-WBSystemState"
[msdocs:Get-WBVirtualMachine]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBVirtualMachine "Get-WBVirtualMachine"
[msdocs:Get-WBVolume]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBVolume "Get-WBVolume"
[msdocs:Get-WBVssBackupOption]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Get-WBVssBackupOption "Get-WBVssBackupOption"
[msdocs:New-WBBackupTarget]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/New-WBBackupTarget "New-WBBackupTarget"
[msdocs:New-WBFileSpec]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/New-WBFileSpec "New-WBFileSpec"
[msdocs:New-WBPolicy]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/New-WBPolicy "New-WBPolicy"
[msdocs:Remove-WBBackupSet]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBBackupSet "Remove-WBBackupSet"
[msdocs:Remove-WBBackupTarget]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBBackupTarget "Remove-WBBackupTarget"
[msdocs:Remove-WBBareMetalRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBBareMetalRecovery "Remove-WBBareMetalRecovery"
[msdocs:Remove-WBCatalog]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBCatalog "Remove-WBCatalog"
[msdocs:Remove-WBFileSpec]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBFileSpec "Remove-WBFileSpec"
[msdocs:Remove-WBPolicy]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBPolicy "Remove-WBPolicy"
[msdocs:Remove-WBSystemState]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBSystemState "Remove-WBSystemState"
[msdocs:Remove-WBVirtualMachine]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBVirtualMachine "Remove-WBVirtualMachine"
[msdocs:Remove-WBVolume]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Remove-WBVolume "Remove-WBVolume"
[msdocs:Restore-WBCatalog]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Restore-WBCatalog "Restore-WBCatalog"
[msdocs:Resume-WBBackup]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Resume-WBBackup "Resume-WBBackup"
[msdocs:Resume-WBVolumeRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Resume-WBVolumeRecovery "Resume-WBVolumeRecovery"
[msdocs:Set-WBPerformanceConfiguration]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Set-WBPerformanceConfiguration "Set-WBPerformanceConfiguration"
[msdocs:Set-WBPolicy]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Set-WBPolicy "Set-WBPolicy"
[msdocs:Set-WBSchedule]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Set-WBSchedule "Set-WBSchedule"
[msdocs:Set-WBVssBackupOption]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Set-WBVssBackupOption "Set-WBVssBackupOption"
[msdocs:Start-WBApplicationRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBApplicationRecovery "Start-WBApplicationRecovery"
[msdocs:Start-WBBackup]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBBackup "Start-WBBackup"
[msdocs:Start-WBFileRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBFileRecovery "Start-WBFileRecovery"
[msdocs:Start-WBHyperVRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBHyperVRecovery "Start-WBHyperVRecovery"
[msdocs:Start-WBSystemStateRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBSystemStateRecovery "Start-WBSystemStateRecovery"
[msdocs:Start-WBVolumeRecovery]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Start-WBVolumeRecovery "Start-WBVolumeRecovery"
[msdocs:Stop-WBJob]: https://docs.microsoft.com/en-us/powershell/module/windowsserverbackup/Stop-WBJob "Stop-WBJob"

**`WB`**
<code>Policy&nbsp;[g][Get-WBPolicy][?][msdocs:Get-WBPolicy]&nbsp;[n][New-WBPolicy][?][msdocs:New-WBPolicy]&nbsp;[r][Remove-WBPolicy][?][msdocs:Remove-WBPolicy]&nbsp;[s][Set-WBPolicy][?][msdocs:Set-WBPolicy]</code>
<code>VirtualMachine&nbsp;[a][Add-WBVirtualMachine][?][msdocs:Add-WBVirtualMachine]&nbsp;[g][Get-WBVirtualMachine][?][msdocs:Get-WBVirtualMachine]&nbsp;[r][Remove-WBVirtualMachine][?][msdocs:Remove-WBVirtualMachine]</code>
<code>Volume&nbsp;[a][Add-WBVolume][?][msdocs:Add-WBVolume]&nbsp;[g][Get-WBVolume][?][msdocs:Get-WBVolume]&nbsp;[r][Remove-WBVolume][?][msdocs:Remove-WBVolume]</code>
# Syntax
#### Control flow
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
#### Keywords
The `Throw` keyword generates a terminating error
#### Variables
##### Automatic variables
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

##### Environment variables
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
#### Filters
Filtering results can be done with 5 commands:
- `Where-Object` (aliased to `where` and `?`): the most commonly used such command
- `Select-Object` (aliased to `sc`ed to specify specific columns of information to be displayed
- `Select-String` (aliased to `sls`)
- `ForEach-Object` (aliased to `foreach` and `%`) There are two different ways to construct a `ForEach-Object` statement:
  1. __Script block__, within which the variable `$_` represents the current object
  2. __Operation statement__, more naturalistic, where you specify a property value or call a method.
#### Scripting
Use comment-based help in the form of a specially formatted docstring with special markers that help the shell parse it when running `Get-Help`
```powershell
<#
.SYNOPSIS
This script coordinates the process of creating new employees

.DESCRIPTION
This script creates new users in Active Directory...

.PARAMETER UserName
The official logon name for the user...

.PARAMETER HomeServer
The server name where the user's home folder will live...
#>
```
Provide copious examples after `.EXAMPLE` with an explanation following
```powershell
<#
.EXAMPLE
New-CorpEmployee -UserName John-Doe -HomeServer HOMESERVER1
This example creates a single new employee...
#>
```
Instead of using backticks to manually break long lines, use a parameter object and the `@` splat operator.
```powershell
$params = @{'ComputerName' = $computer
            'Class'         = 'Wind32_LogicalDisk'
            'DriveType'     = $drivetype
            'ErrorAction'   =  'Stop'}
$disks = Get-WmiObject @params
```
Attach common parameters to a custom function by placing the `[CmdletBinding()]` within the body of a function. This allows use of options like `-Verbose` or `-Debug` with custom functions.
Now, using `Write-Verbose` and `Write-Debug` serve the dual purpose of outputting additional information at the time of execution, when needed, as well as documentation.

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
#### Loops
Pipeline is the defining feature of PowerShell, which allows it to break apart composite objects and act on each element with the `ForEach-Object` cmdlet.
```powershell
1..5 | ForEach-Object {$_ + 2} # => @(3,4,5,6,7)
```
When values are stored in a variable at the end of a pipeline, it will create an array. `while` and `do while` loops are available, as well as `until` and `do until` loops which operate so long as their condition is **false**.
```powershell
$Values = while ($true) {(++$Tick); if ($Tick -gt 2) { break } } # => @(1,2,3)
$Values = do { 'eat me!' } while ($false) # => @('eat me!')
```
# Cmdlets
##### New-ADUser
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
##### Get-ADUser
Retrieve `LogonWorkstations` property, which is not included in the default object returned by the command
```powershell
Get-ADUSer $user -Properties LogonWorkstations
```
Filter all accounts with `LogonWorkstations` set to something
```powershell
Get-ADUser -Filter * -Properties LogonWorkstations |? LogonWorkstations -ne $null
```
##### Set-ADUser
Clear value of `LogonWorkstations` property
```powershell
Set-ADUser $user -LogonWorkstations $null
```
##### Search-ADAccount
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
##### Unlock-ADAccount
Unlock account
```powershell
Unlock-ADAccount -identity wbryan
```
##### Set-ADAccountPassword
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
##### Add-ADGroupMember
[Add a member to a group](#add-a-member-to-a-group)
##### Get-ADObject
Display version of Active Directory schema <sup>[nolabnoparty.com](https://nolabnoparty.com/en/finding-active-directory-schema-version/ "Finding the Active Directory schema version")</sup>
```powershell
Get-ADObject "cn=schema,cn=configuration,dc=domain,dc=com" -properties objectversion
```
##### Set-ADObject
Protect users in a specified OU from accidental deletion
```powershell
Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" ` | 
Set-ADObject -ProtectedFromAccidentalDeletion $true
```
##### Get-ADOrganizationalUnit
Display OUs, confirming deletion has taken place
```powershell
Get-ADOrganizationalUnit  -filter * | ft
```
##### New-ADOrganizationalUnit
Create a new Organizational Unit
```powershell
New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey
```
##### Remove-ADOrganizationalUnit
Remove an OU
```powershell
Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False
```
##### Set-ADOrganizationalUnit
Remove accidental deletion protection
```powershell
Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" 
```
##### Install-ADDSForest
Add a new forest
```powershell
# This will prompt for safe mode administrator password
Install-ADDSForest -DomainName example.com -InstallDNS
```
If the system fails to automatically create a NetBIOS name, it can be manually specified with the named parameter `-DomainNetbiosName`
##### Install-ADDSDomain
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
##### Uninstall-ADDSDomainController
Demote a domain controller (consummate with uninstalling the AD Domain Controller role)
```powershell
# When removing the last domain controller of a domain, additional options need to be specified that result in the obliteration of the domain, its forest, and associated data.
Uninstall-ADDSDomainController -LocalAdministratorPassword (ConvertTo-SecureString $pw -AsPlainText -Force) -LastDomainControllerInDomain -RemoveApplicationPartitions
```
##### New-ADComputer
##### Add-ADPrincipalGroupMembership
```powershell
Add-ADPrincipalGroupMembership -Identity "CN=SysAdmin,CN=Users,DC=corp,DC=packtlab,DC=com" -MemberOf "CN=Enterprise Admins,CN=Users,DC=corp,DC=packtlab,DC=com","CN=Domain Admins,CN=Users,DC=corp,DC=packtlab,DC=com"
```
##### Get-ADForest
Display installed forests
```powershell
Get-ADForest | select -ExpandProperty domains
```
##### Get-ADPrincipalGroupMembership
<sup>[Jones][Jones]</sup>

```powershell
Get-ADPrincipalGroupMembership sysadmin
```
##### Get-ADUser
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
##### Add-DistributionGroupMember
[Add-DistributionGroupMember -Identity]: #Add-DistributionGroupMember '```&#10;PS C:\> Add-DistributionGroupMember -IdentityIdentity&#10;```&#10;Specifies the group that you want to modify. You can use any value that uniquely identifies the group (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).'
[Add-DistributionGroupMember -Member]: #Add-DistributionGroupMember '```&#10;PS C:\> Add-DistributionGroupMember -MemberMember&#10;```&#10;Specifies the recipient that you want to add to the group. A member can be any mail-enabled recipient in your organization. You can use any value that uniquely identifies the recipient (including Name, Alias, Distinguished name, Canonical name, Email address, or GUID).'

[`Identity`][Add-DistributionGroupMember -Identity]
[`Member`][Add-DistributionGroupMember -Member]

##### Export-Alias
Export session aliases to a ".ps1" file
```powershell
Export-Alias -Path alias.ps1 -As Script
```
##### Get-Alias
Display aliases
```powershell
Get-Alias
```
Display items that point to `Get-ChildItem`
```powershell
Get-Alias -Definition Get-ChildItem
```
##### New-Alias
Establish a new alias
```powershell
New-Alias ip Get-NetIPAddress
```
##### Set-Alias
Edit an existing alias
```powershell
Set-Alias ip Get-NetAdapter
```
##### Get-Clipboard
Interpret items in clipboard as files
```powershell
Get-Clipboard -Format FileDropList
```
Retrieve various properties of an image in clipboard
```powershell
Get-Clipboard -Format Image
```
##### Set-Clipboard
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
With `Append` switch parameter, items can be added without clearing the clipboard:
```powershell
Write-Output 'Hello' | Set-Clipboard -Append
```
##### Add-Computer
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
##### Rename-Computer
Rename computer
##### Restart-Computer
Restart computer
##### Get-ChildItem
##### Get-Command
Display source code of a function <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_functions "About Functions"</sup>
```powershell
(Get-Command mkdir).Definition
```
##### Invoke-Command
[Invoke-Command -ThrottleLimit]: #Invoke-Command '```&#10;PS C:\> Invoke-Command -ThrottleLimit&#10;```&#10;Specify the maximum number of concurrent connections that can be established to run the command (32 by default)'
[Invoke-Command -ScriptBlock]: #Invoke-Command '```&#10;PS C:\> Invoke-Command -ScriptBlock&#10;```&#10;Specify commands to run'

[`ScriptBlock`][Invoke-Command -ScriptBlock]
[`ThrottleLimit`][Invoke-Command -ThrottleLimit]

Execute the commands in the block on the machines specified
```powershell
Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}
```
##### Get-ComputerInfo
Display computer name <sup>[cmd](README.md#hostname)</sup>
```powershell
Get-ComputerInfo -Property CsName
gin.CsName
```
##### Get-Help
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
##### Update-Help
Download help files
##### Write-Host
`BackgroundColor`
`ForegroundColor`

Exclusively used for drawing text on the screen.

##### Import-Module
Import `SmbShare` module
```powershell
Import-Module SmbShare
```
##### Install-Module
Install the `Az` module
```powershell
Install-Module -Name Az -AllowClobber
```
##### Write-Output
Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
Create a text file <sup>[Jones][Jones]</sup>
```powershell
Write-Output "This is a test network file." -Path | Out-File C:\networkfiles\test.txt
```
##### New-PSDrive
Start a new PSDrive using the `HKEY_CLASSES_ROOT` Windows Registry hive <sup>[powershelleverydayfaq.blogspot.com](http://powershelleverydayfaq.blogspot.com/2012/06/how-to-query-hkeyclassesroot.html "How to query HKEY_CLASSES_ROOT")</sup>
```powershell
ndr -Name HKCR -PSProvider Registry -Root HKEY_CLASSES_ROOT
```
##### Get-PSReadlineOption
Display options available in the module
```powershell
Get-PSReadlineOption
```
##### Set-Partition
Change a drive letter
```powershell
Set-Partition -DriveLetter C -NewDriveLetter Z
```
##### Set-PSReadlineOption
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
##### Add-PSSnapin
##### Format-Table
`HideTableHeaders`

Display list of information without the headers (i.e. for copy-pasting)
```powershell
Get-Command -Module pswritehtml | Select-Object Name | Format-Table -HideTableHeaders | clip.exe
```
##### Add-Type
Generate a random password 20 characters long <sup>[adamtheautomator.com][https://adamtheautomator.com/powershell-random-password/]</sup>
```powershell
Add-Type -AssemblyName 'System.Web'
[System.Web.Security.Membership]::GeneratePassword(20, 3)
```
##### Get-NetConnectionProfile
```powershell
$NetworkProfile = Get-NetConnectionProfile -InterfaceAlias "Ethernet"
$NetworkProfile.NetworkCategory = "Public"
```
##### Set-NetConnectionProfile
```powershell
Set-NetConnectionOject -InputObject $NetworkProfile
```
##### Add-DhcpServerv4Scope
<sup>[Jones][Jones]</sup>

```powershell
Add-DhcpServerv4Scope -Name "PacktLabNet" -StartRange 10.0.0.50 -EndRange 10.0.0.100 -SubnetMask 255.255.255.0
```
##### Add-DhcpServerInDC
<sup>[Jones][Jones]</sup>

```powershell
Add-DhcpServerInDC -DnsName dc.corp.packtlab.com
```
##### Set-DhcpServerv4OptionValue
<sup>[Jones][Jones]</sup>

```powershell
Set-DhcpServerv4OptionValue -DnsDomain corp.packtlab.com -DnsServer 10.0.0.1
```
##### Set-DnsClientServerAddress
**`InterfaceAlias`**
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
##### Resolve-DnsName
```powershell
Resolve-DNSName -Name secure.practicelabs.com.trustanchors -Type dnskey -Server plabdm01
```
##### Get-NetAdapter
Display available network interfaces <sup>[Zacker][Zacker]: 19</sup>
##### Enable-NetFirewallRule
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
Enable-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In, RemoteEventLogSvc-In-TCP, RemoteEventLogSvc-NP-In-TCP, RemoteEventLogSvc-RPCSS-In-TCP
```
##### Get-NetFirewallRule
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
##### New-NetFirewallRule
Set a new firewall rule for incoming WinRM connections
```powershell
New-NetFirewallRule -DisplayName "WinRMHTTP" -Direction Inbound -LocalPort 5985 -Protocol TCP -Action Allow
```
##### Set-NetFirewallRule
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

##### New-NetIpAddress
[New-NetIpAddress -DefaultGateway]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -DefaultGateway&#10;```&#10;Specify IP address of local router that computer should use to access other networks'
[New-NetIpAddress -InterfaceIndex]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -InterfaceIndex&#10;```&#10;Specify adapter to be configured using interface numbers as displayed by `Get-NetAdapter`'
[New-NetIpAddress -IpAddress]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -IpAddress&#10;```&#10;Specify IP address to be assigned to adapter'
[New-NetIpAddress -PrefixLength]: #New-NetIpAddress '```&#10;PS C:\> New-NetIpAddress -PrefixLength&#10;```&#10;Specify subnet mask value'

[**`IpAddress`**][New-NetIpAddress -IpAddress]
[`DefaultGateway`][New-NetIpAddress -DefaultGateway]
[`InterfaceIndex`][New-NetIpAddress -InterfaceIndex]
[`PrefixLength`][New-NetIpAddress -PrefixLength]
`UseBasicParsing`

Configure the Domain Controller in a new corporate intranet <sup>[Jones][Jones]</sup>
```powershell
New-NetIPAddress 10.0.0.1 -InterfaceAlias "Ethernet" -PrefixLength 24
```
Configure a network adapter 
```powershell
New-NetIpAddress -InterfaceIndex 6 -IpAddress 192.168.0.200 -PrefixLength 24 -DefaultGateway 192.168.0.1
```
##### Set-NetIpInterface
Enable DHCP <sup>[4sysops.com](https://4sysops.com/archives/set-an-ip-address-and-configure-dhcp-with-powershell/ "Set an IP address and configure DHCP with Powershell")</sup>
```powershell
Set-NetIPInterface -InterfaceAlias 'Ethernet 2' -Dhcp Enabled
```
##### Invoke-WebRequest
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
##### Install-Package
Download and install **Docker Engine - Enterprise** (not supported on Windows 10 clients) <sup>[Zacker][Zacker]: 266</sup>
```powershell
Install-Package docker -ProviderName dockermsftprovider
```
##### Install-PackageProvider
Install [NuGet][NuGet]
```powershell
Install-PackageProvider -Name NuGet
```
Since April 3, 2020 the minimum TLS version was raised on the provider lookup site. <sup>[stackoverflow.com](https://stackoverflow.com/questions/16657778/install-nuget-via-powershell-script/26421187 "Install NuGet via Powershell script")</sup>
```powershell
[System.Net.ServicePointManager]::SecurityProtocol=[System.Net.SecurityProtocolType]'Tls11,Tls12'
```
##### Optimize-VHD
Compact a VHD <sup>[Zacker][Zacker]: 228</sup>
```powershell
Optimize-VHD -Path $FILE -Mode full
```
##### Register-PackageSource
```powershell
Register-PackageSource -Name NuGet -Location https://www.nuget.org/api/v2 -ProviderName NuGet -Trusted
```
##### Start-Process
Run a program as admin
```powershell
Start-Process cmd -Verb runas
saps cmd -v runas
```
##### Enable-PSRemoting
`SkipNetworkProfileCheck`

##### Disconnect-PSSession
Terminate a remote PowerShell session begun with [`New-PSSession`][New-PSSession] <sup>[Zacker][Zacker]: 22</sup>
##### Dismount-VHD
Zacker: 225
```powershell
Dismount-VHD -Path $FILE
```
##### Enter-PSSession
`UseSSL`

Interact with the specified PowerShell session
```powershell
Enter-PSSession -id 1
```
Start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
```powershell
Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey
```
##### Exit-PSSession
Exit a remote PowerShell session <sup>[Zacker][Zacker]: 22</sup>
End the PowerShell session with the specified computer
```powershell
Exit-PSSession -ComputerName demodc
```
##### Get-PSSession
Display PowerShell sessions
```powershell
Get-PSSession
```
##### New-PSSession
`-ComputerName`

Manage a Windows Server remotely <sup>[Zacker][Zacker]: 21</sup>
```powershell
New-PSSession -ComputerName rtmsvrd
```
Start a new PowerShell session, connecting to the specified computer
```powershell
New-PSSession -ComputerName core02
```
##### Enable-WSManCredSSP
`Delegate`
`Role`

Tasks:
- [Enable CredSSP](#enable-credssp)

##### New-Volume
`FileSystem`
`ProvisioningType`
`ResiliencySettingName`

Create a virtual disk that uses parity resiliency and two tiers, with the default friendly names of Performance for SSDs and Capacity for HDDs <sup>[Zacker][Zacker]: 355</sup>
```powershell
New-Volume -StoragePool "s2d*" -FriendlyName vdisk1 -Filesystem csvfs_refs -ResiliencySettingName parity -StorageTiersFriendlyNames performance,capacity -StorageTierSizes 10gb,100gb
```
Create a VHD with a Mirror layout <sup>[Practice Lab][pl:70-740]</sup>
```powershell
New-Volume -StoragePoolFriendlyName “PLABDM01-SP1” -FriendlyName “Mirror1” -Size 6GB -ResiliencySettingName “Mirror” -FileSystem NTFS -AccessPath “M:” -ProvisioningType Thin
```
##### New-Website
[Practice Lab][pl:70-740]
```powershell
New-Website -Name nlbport -PhysicalPath "c:\nlbport" -Port 6789
```
##### Set-Disk
`IsOffline`
`IsReadOnly`

While configuring a [pass-through disk](#pass-through-disk)
```powershell
Set-Disk -Number 3 -IsOffline $false
```
##### New-Partition
Create a new partition mounted to F: using the ReFS filesystem <sup>[Practice Lab][pl:70-740]</sup>
```powershell
New-Partition -DiskNumber 3 -UseMaximumSize -DriveLetter F | Format-Volume -NewFileSystemLabel “PLABS-Test” -FileSystem ReFS
```
##### Enable-DedupVolume
[Enable-DedupVolume -UsageType]: #enable-dedupvolume '```&#10;PS C:\> Enable-DedupVolume -UsageType&#10;```&#10;Specifies the expected type of workload for the volume&#10;Acceptables values include:&#10;  - `Default`: Equivalent to "General Purpose File Server" in the GUI. This configures deduplication to be suitable to typical file server functions, like shared folders, Work Folders, and Folder Redirection.&#10;  - `HyperV`: Equivalent to "Virtual Desktop Infrastructure (VDI) Server" in the GUI. This configures Deduplication to occur in the background, with in-use and partial files optimized.&#10;  - `Backup`: Equivalent to "Virtualized Backup Server" in the GUI. Intended for use with backup applications, like Microsoft DPM. Deduplication is a priority process, and in-use files are optimized.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 156'

[`UsageType`][Enable-DedupVolume -UsageType]

Enable deduplication <sup>[Zacker][Zacker]: 157</sup>
```powershell
Enable-DedupVolume -Volume "e:" -UsageType default
Enable-DedupVolume -Volume "\\?\\volume{26a21bda-a627-11d7-9931-806e6f6e6963}" -UsageType backup
```
##### Set-SRPartnership
Reverse the direction of storage replica, in a case where the source goes down <sup>[MeasureUp][mu:70-740]</sup>
```powershell
Set-SRPartnership -NewSourceComputerName $replica -SourceRGName $replicarg -DestinationComputerName $src -DestinationRGName $srcrg
```
##### Expand-Archive
Decompress archives
```powershell
Expand-Archive
```
##### Export-CliXml
##### Import-CliXml
##### Add-Content
Append a line to the `hosts` file
```powershell
Add-Content -Path C:\Windows\System32\drivers\etc\hosts -Value "76.184.117.203 mohsen"
ac $Env:windir\System32\drivers\etc\hosts "76.184.117.203 mohsen"
```
##### Get-Content
Make a PowerShell object from a JSON file
```powershell
Get-Content -Path file.json | ConvertFrom-Json
```
##### Export-Csv
##### Import-Csv
Add a CSV full of users
```powershell
Import-Csv users.csv | foreach { New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -Enabled $True -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) }
```
##### Convert-VHD
Convert a fixed VHD to a dynamic VHDX <sup>[Zacker][Zacker]: 228</sup>
```powershell
Convert-VHD -Path $OLDFILE -DestinationPath $NEWFILE -VHDType dynamic
```
##### Copy-Item
Copy files to and from an open Powershell session <sup>[Zacker][Zacker]: 180</sup>
```powershell
Copy-Item -ToSession (Get-PSSession) -Path C:\temp\file.txt -Destination C:\users
Copy-Item -FromSession (Get-PSSession) -Path C:\users\file.txt -Destination C:\temp
```
##### Get-Item
Equivalents to bash `basename` and `dirname` <sup>[stackoverflow](https://stackoverflow.com/questions/12503871/removing-path-and-extension-from-filename-in-powershell "Removing path and extension from filename in powershell")</sup>
```powershell
(Get-Item $path).Basename
(Get-Item $path).DirectoryName
```
##### New-Item
[New-Item &#84;]: #New-Item '```&#10;PS C:\> New-Item Type&#10;PS C:\> New-Item -ItemType&#10;```&#10;&#10;Specify the provider-specified type of the new item; values depend on the context.'

`Name`
[`Type`][New-Item &#84;]
`Value`

Create a folder
```powershell
New-Item -ItemType "directory" Folder
ni -Type "directory" Folder
```
##### Remove-Item
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
##### Set-Item
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
##### New-ItemProperty
Create a Registry key in order to use a local user account that is not the builtin Administrator account in order to manage a single domain cluster <sup>[Zacker][Zacker]: 315</sup>
```powershell
New-ItemProperty -Path HKLM:\Software\Microsoft\Windows\currentversion\policies\system -Name LocalAccountTokenFilterPolicy -Value 1
```
##### Measure-VM
**`VMName`**


##### Select-Object
Create a custom property <sup>[Pfeiffer](https://portal.cloudskills.io/products/azure-powershell-the-ultimate-beginners-course/categories/2529580/posts/8443858 "Azure PowerShell course") </sup>
```powershell
Get-AzVM | Select-Object Name,@{Name="DataDiskCount"; Expression={$_.StorageProfile.DataDisks.count}}
```
##### Where-Object
##### Mount-VHD
Tasks:
- [VHDX file](#vhdx-file)

Mount a VHD or VHDX file <sup>[Zacker][Zacker]: 92, 225</sup>
```powershell
Mount-VHD -Path $file
```
##### New-VHD
[New-VHD -Differencing]: #New-VHD '```&#10;[PS] New-VHD -Differencing&#10;```&#10;Specify that a new differencing disk is to be created'

[`Differencing`][New-VHD -Differencing]
`Dynamic`
`Fixed`
`LogicalSectorSizeBytes`
`ParentPath`
`SizeBytes`

Tasks:
- [VHDX file](#vhdx-file)

[Zacker][Zacker]: 219
```powershell
New-VHD -Path c:\diskfile.vhdx -Fixed -SizeBytes 500gb -LogicalSectorSizeBytes 4096
```
```powershell
New-VHD -Path C:\Data\disk1.vhdx -SizeBytes 256GB -Dynamic 
```
Differencing disk <sup>[Practice Lab][pl:70-740]</sup>
```powershell
New-VHD -Path 'D:\Virtual Machines\PLAB2.vhdx' -Differencing -ParentPath 'C:\Users\Public\Documents\Hyper-V\Virtual hard disks\PLABWIN102.vhdx'
```
##### Export-VM
Export a VM <sup>[Zacker][Zacker]: 373</sup>
```powershell
Export-Vm -Name clustervm1 -Path D:\vm
```
##### Import-VM
[Import-VM -Copy]: #import-vm '```&#10;PS C:\> Import-VM -Copy&#10;```&#10;Specifies that the import VM should be copied to host default locations of the host, as opposed to registering the virtual machine in-place.&#10;Equivalent to the "Restore" GUI option.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 211'
[Import-VM -GenerateNewId]: #import-vm '```&#10;PS C:\> Import-VM -GenerateNewId&#10;```&#10;Specifies that the imported virtual machine should be copied and given a new unique identifier.&#10;Equivalent to the "Copy" GUI option&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'

[`Copy`][Import-VM -Copy]
[`GenerateNewId`][Import-VM -GenerateNewId]

Import a VM into the Hyper-V host <sup>[Zacker][Zacker]: 373</sup>
```powershell
Import-VM -Path "D:\vm\virtual machines\5ae40946-3a98-428e-8c83-081a3c68d18c.xml" -Copy -GenerateNewId
```
##### Initialize-Disk
**Initializing** a disk means selecting a MBR or GPT partition style.
```powershell
Initialize-Disk -Number 1 -PartitionStyle MBR

```
##### Move-VM
Perform a live migraiton <sup>[Zacker][Zacker]: 307</sup>
```powershell
Move-VM -VM server1 -DestinationHost hyper2
```
##### New-VM
**`Name`**
**`MemoryStartupBytes`**
**`Generation`**
`NewVHDPath`
`NewVHDSizeBytes`
`SwitchName`
`VHDPath`

Tasks:
- [VM with installation media](#create-vm-with-installation-media)

Create a Nano Server VM from an image file <sup>[Zacker][Zacker]: 47</sup>
```powershell
New-VM -Name "nano2" -Generation 2 -MemoryStartupBytes 1GB -VHDPath "F:\hyper-v\virtual hard disks\nano2.vhdx"
```
##### Set-VM
[Set-VM -CheckpointType]: #Set-VM '```&#10;PS C:\> Set-VM -CheckpointType&#10;```&#10;Configure the type of checkpoints created by Hyper-V'

[`CheckpointType`][Set-VM -CheckpointType]
`StaticMemory`

Disable dynamic memory <sup>[MeasureUp][mu:70-740]</sup>
```powershell
Set-VM -StaticMemory
```
##### Set-VMDvdDrive
Tasks:
- [Create VM with installation media](#create-vm-with-installation-media)
##### Set-VMHost
[Set-VMHost -VirtualMachinePath]: #Set-VMHost '```&#10;PS C:\> Set-VMHost -VirtualMachinePath&#10;```&#10;Specify the default folder to store virtual machine configuration files on the Hyper-V host'
[Set-VMHost -VirtualHardDiskPath]: #Set-VMHost '```&#10;PS C:\> Set-VMHost -VirtualHardDiskPath&#10;```&#10;Specify the default folder to store virtual hard disks on the Hyper-V host.'

[`VirtualHardDiskPath`][Set-VMHost -VirtualHardDiskPath]
[`VirtualMachinePath`][Set-VMHost -VirtualMachinePath]

```powershell
Set-VMHost -VirtualHardDiskPath 'D:\vms\Virtual Hard Disks' -VirtualMachinePath 'D:\vms\Virtual Machines'
```
##### Set-VMFirmware
[Set-VMFirmware -SecureBootTemplate]: #set-vmfirmware '```&#10;PS C:\> Set-VMFirmware -SecureBootTemplate&#10;```&#10;Specifies the name of the secure boot template. If secure boot is enabled, you must have a valid secure boot template for the guest operating system to start.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 208'

[`SecureBootTemplate`][Set-VMFirmware -SecureBootTemplate]

Select Secure Boot template in order to load supported Linux distributions <sup>[IMWS][IMWS]; [Zacker][Zacker]: 208</sup>
```powershell
Set-VMFirmware vmname -SecureBootTemplate MicrosoftUEFICertificateAuthority
```
##### Set-VMMemory
Tasks:
- [Implement nested virtualization](#implement-nested-virtualization)
##### Set-VMProcessor
- [Implement nested virtualization](#implement-nested-virtualization)
##### Set-VMReplicationServer
Configure a server's replica configuration <sup>[Zacker][Zacker]: 300</sup>
```powershell
Set-VmReplicationServer -ReplicationEnabled $true -AllowedAuthenticationType kerberos -ReplicationAllowedFromAnyServer $true -DefaultStorageLocation D:\replicas
```
[external virtual switch]: # 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[internal virtual switch]: # 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[private virtual switch]: # 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'

Virtual switches can be [external][external virtual switch], [internal][internal virtual switch], or [private][private virtual switch] (in order of decreasing access). <sup>[Zacker][Zacker]: 241</sup>
##### New-VMSwitch
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
##### Set-VMSwitch
[Set-VMSwitch -AllowManagementOS]: #Set-VMSwitch '```&#10;PS C:\> Set-VMSwitch -AllowManagementOS&#10;```&#10;Specify whether host can access the physical network adapter to which the virtual switch is bound'

[`AllowManagementOS`][Set-VMSwitch -AllowManagementOS]
##### Add-VMHardDiskDrive
[Add-VMHardDiskDrive -ControllerType]: #add-vmharddiskdrive '```&#10;[PS] Add-VMHardDiskDrive -ControllerType&#10;```&#10;Specify type of controller to which the hard disk is to be added'

**`VMName`**
**[`ControllerType`][Add-VMHarddDiskDrive -ControllerType]**
`DiskNumber`
`VMName`

While configuring a [pass-through disk](#pass-through-disk)
```powershell
Add-VMHardDiskDrive -VMName server1 -ControllerType scsi -DiskNumber 2
```
##### Add-VMNetworkAdapter
[Add-VMNetworkAdapter -IsLegacy]: #add-vmnetworkadapter '```&#10;PS C:\> Add-VMNetworkAdapter -IsLegacy&#10;```&#10;Specify a legacy adapter'

[`IsLegacy`][Add-VMNetworkAdapter -IsLegacy]

Create a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Add-VMNetworkAdapter -VMName server1 -SwitchName private1
```
##### Remove-VMNetworkAdapter
[msdocs:Remove-VMNetworkAdapter]: https://docs.microsoft.com/en-us/powershell/module/hyper-v/remove-vmnetworkadapter "Remove-VMNetworkAdapter"

Remove a network adapter <sup>[Zacker][Zacker]: 237</sup>
```powershell
Remove-VMNetworkAdapter -VMName server1 -VMNetworkAdapter nic1
```
##### Set-VMNetworkAdapter
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
##### New-EventLog
```powershell
New-EventLog -LogName application -Source MyCustomApp
```
##### Write-EventLog
```powershell
Write-EventLog -LogName application -Source MyCustomApp -EventId 911 -Message 'Automated process failed, please contact the administrator.'
```
##### New-Guid
Generate a GUID
```powershell
New-Guid
(New-Guid).Guid | clip
```
[msdocs:Edit-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/nanoserverimagegenerator/Edit-nanoserverimage "Edit-NanoServerImage"
[msdocs:New-NanoServerImage]: https://docs.microsoft.com/en-us/powershell/module/nanoserverimagegenerator/new-nanoserverimage "New-NanoServerImage"

Options for configuring a network adapter

`InterfaceNameOrIndex`
`Ipv4Address`

##### Edit-NanoServerImage
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
##### New-NanoServerImage
[New-NanoServerImage -BasePath]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -BasePath&#10;```&#10;Path on the local system where the cmdlet cdreates a copy of the installation files from the location specified in `-MediaPath`.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -ComputerName]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -ComputerName&#10;```&#10;Computer name that should be assigned to the new image.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -Containers]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Containers&#10;```&#10;Add the Containers package, including host support for Windows Containers&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 265'
[New-NanoServerImage -DeploymentType]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -DeploymentType&#10;```&#10;Whether image file should be used on a Hyper-V VM ("Guest") or a physical server ("Host")&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -Edition]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Edition&#10;```&#10;""Standard"" or ""Datacenter"" edition of Nano Server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -InterfaceNameOrIndex]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -InterfaceNameOrIndex&#10;```&#10;Identify interface to which other settings should be applied&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Address]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Address&#10;```&#10;Specify static IPv4 address to be assigned to the interface specified by `InterfaceNameOrIndex` parameter&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Dns]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Dns&#10;```&#10;Specify IP address of DNS server&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4Gateway]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4Gateway&#10;```&#10;Specify IP address of a router on the local network where the IP address specified in `Ipv4Address` is located, providing access to other networks&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -Ipv4SubnetMask]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -Ipv4SubnetMask&#10;```&#10;Specify subnet mask value associated with the IP address specified in `Ipv4Address`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 51'
[New-NanoServerImage -MediaPath]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -MediaPath&#10;```&#10;Path to the root of the WS2016 installation disk or mounted image&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'
[New-NanoServerImage -TargetPath]: #New-NanoServerImage '```&#10;PS C:\> New-NanoServerImage -TargetPath&#10;```&#10;Full path and filename of the new image to be created, including the filename extension which specifies whether the new image should be Generation 1 (".vhd") or Generation 2 (".vhdx").&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 44'

[`BasePath`][New-NanoServerImage -BasePath]
[`ComputerName`][New-NanoServerImage -ComputerName]
[`Containers`][New-NanoServerImage -Containers]
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
Container host <sup>[Zacker][Zacker]: 264</sup>
```powershell
New-NanoServerImage -DeploymentType guest -Edition Datacenter -MediaPath D:\ -TargetPath C:\Nano\nano1.vhdx -Computername nano1 -DomainName contoso -Containers
```
##### Get-Service
Display status of &lt;WinRM&gt; service
```powershell
Get-Service WinRM
gsv winrm
```
##### Set-Service
```powershell
Set-Service WtcOtg -StartupType Disabled
```
##### Start-Service
Start the `WinRM` service
```powershell
sasv winrm
```
##### Stop-Service
Stop the WebTitan service
```powershell
Stop-Service WtcOtg
```
##### Get-WmiObject
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
##### Get-WindowsFeature
Display installable Windows roles, role services, and features
Display a branching view of available Windows roles, role services, and features
```powershell
Get-WindowsFeature
```
##### Install-WindowsFeature
[Install-WindowsFeature -Name]: #Install-WindowsFeature '```&#10;PS C:\> Install-WindowsFeature -Name&#10;```&#10;&#10;Values can include:&#10;  - "`AD-Domain-Services"&#10;  - "Hyper-V"&#10;  - "RSAT-ADDS"&#10;  - "Web-WebServer"'

[**`Name`**][Install-WindowsFeature -Name] 
`IncludeAllSubFeature` 
`IncludeManamgentTools`
`Restart`
`VHD`

Install Hyper-V Powershell module <sup>[Zacker][Zacker]: 90</sup>
```powershell
Install-WindowsFeature -Name hyper-v-powershell
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
Install WSUS <sup>[Zacker][Zacker]: 393</sup>
```powershell
Install-WindowsFeature -Name updateservices -IncludeManagementTools

# Using a separate SQL server
Install-WindowsFeature -Name updateservices,updateservices-db -IncludeManagementTools
```
Install a Windows role or feature to an offline virtual disk <sup>Zacker: 225</sup>
```powershell
Install-WindowsFeature -VHD $FILE -Name web-server -IncludeManagementTools
```
##### Start-DscConfiguration
`-Path`

Used to erect a **push architecture** in [DSC](dsc.md). <sup>[Zacker][Zacker]: 27</sup>
##### Set-NetQosDcbxSetting
Set the DCBX Willing bit to false, enabling the CNA to receive only local configuration settings, namely those created with subsequent `DcbQos` cmdlets <sup>[Zacker][Zacker]: 143</sup>
```powershell
Set-NetQosDcbxSetting -Willing 0
```
##### New-SRPartnership
Establish the actual replication partnership between the source and the destination servers <sup>[Zacker][Zacker]: 154</sup>
```powershell
New-SRPartnership -SourceComputerName servera -SourceRgName group1 -SourceVolumeName f: -SourceLogVolumeName e: -DestinationComputerName serverb -DestinationRgName group2 -DestinationVolumeName f: -DestinationLogVolumeName e:
```
##### Test-SRTopology
```powershell
Test-SRTopology -SourceComputerName servera -SourceVolumeName f: -SourceLogVolumeName e: -DestinationComputerName serverb -DestinationVolumeName f: -DestinationLogVolumeName e: -DurationInMinutes 30 -ResultPath c:\temp
```
##### Add-WindowsDriver
DISM only supports .inf driver files
##### Get-WindowsImage
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
##### Mount-WindowsImage
[Mount-WindowsImage -Remount]: #Mount-WindowsImage '```&#10;PS C:\> Mount-WindowsImage -Remount&#10;```&#10;&#10;Equivalent to `Dism.exe /Remount-Image`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'

[`Remount`][Mount-WindowsImage -Remount]
##### Enable-VMResourceMetering
**`VMName`**

##### Enable-WindowsOptionalFeature
Enable a feature in the currently running operating system <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/dism/enable-windowsoptionalfeature?view=win10-ps&redirectedfrom=MSDN "Microsoft Docs: \"Enable-WindowsOptionalFeature\"")</sup>
```powershell
Enable-WindowsOptionalFeature -Online -FeatureName "Hearts" -All
```
Enable WSL <sup>[Reddit](https://www.reddit.com/r/bashonubuntuonwindows/comments/7smf9m/help_wsl_wont_activate_on_my_freshly_installed/ "Reddit: \"[help] WSL won't activate on my freshly installed Windows 10 version 1709\"")</sup>
```powershell
Enable-WindowsOptionalFeature -online -FeatureName Microsoft-Windows-Subsystem-Linux
```
##### Get-WindowsOptionalFeature
[Get-WindowsOptionalFeature -FeatureName]: #Get-WindowsOptionalFeature '```&#10;PS C:\> Get-WindowsOptionalFeature -FeatureName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Featureinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 78'
[`FeatureName`][Get-WindowsOptionalFeature -FeatureName]
##### Get-WindowsPackage
[Get-WindowsPackage -PackagePath]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackagePath&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[Get-WindowsPackage -PackageName]: #Get-WindowsPackage '```&#10;PS C:\> Get-WindowsPackage -PackageName&#10;```&#10;&#10;Equivalent to `Dism.exe /Image:foldername /Get-Packageinfo`&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 77'
[`PackageName`][Get-WindowsPackage -PackageName] 
[`PackagePath`][Get-WindowsPackage -PackagePath]
##### New-Cluster
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

##### Suspend-ClusterNode
Pause a node and move ("drain") its workloads with `-Drain`. <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/powershell/module/failoverclusters/suspend-clusternode "Suspend-ClusterNode")
```powershell
Suspend-ClusterNode -Name "node1" -Target "node2" -Drain
```
##### Set-ClusterQuorum
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
##### Add-ClusterScaleOutFileServer
Install the Scale-out File Server role <sup>[Zacker][Zacker]: 339</sup>
```powershell
Add-ClusterScaleOutFileServer
```
##### Add-ClusterSharedVolume
Zacker: 336
```powershell
Add-ClusterSharedVolume -Name "Cluster disk 5"
```
##### Enable-ClusterStorageSpacesDirect
Add storage to a failover cluster [created][New-Cluster] with the `-NoStorage` option <sup>[Zacker][Zacker]: 354</sup>
```powershell
Enable-ClusterStorageSpacesDirect
```
##### Close-SmbOpenFile
Close an open file <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -FileId 4415226383589
```
Close open files for a session <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]</sup>
```powershell
Close-SmbOpenFile -SessionId 4415226380393
```
##### Get-SmbOpenFile
Get information about an opened file <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -FileId 4415226383569 | Select-Object -Property *
```
Get information about a file opened for an SMB client <sup>[MS Docs][https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]</sup>
```powershell
Get-SmbOpenFile -SessionId 4415226380393
```
##### Close-SmbSession
```powershell
Close-SmbSession -SessionId 154618822713
```
##### Get-SmbSession
##### New-SmbShare
```powershell
New-SmbShare -Name files -Path C:\networkfiles -ChangeAccess CORP\SysAdmin
```
Create a new share with the `Allow Full Control` permission granted to the `Everyone` special identity <sup>[Zacker][Zacker]: 106</sup>
```powershell
New-SmbShare -Name Data -Path C:\Docs -FullAccess Everyone
```
##### Resize-VHD
[Resize-VHD -ToMinimumSize]: #Resize-VHD '```&#10;[PS] Resize-VHD -ToMinimumSize&#10;```&#10;Specify that the virtual hard disk is to be resized to its minimum possible size&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'

[`ToMinimumSize`][Resize-VHD -ToMinimumSize]
##### Merge-VHD
Merge a differencing disk into its parent disk <sup>[Zacker][Zacker]: 228</sup>
```powershell
Merge-VHD -Path $OLDFILE -DestinationPath $NEWFILE
```
##### Restore-VMSnapshot
Apply a checkpoint <sup>[Zacker][Zacker]: 230</sup>
```powershell
Restore-VMCheckpoint -Name checkpoint1 -VMName server1
```
##### Add-NlbClusterPortRule
Create a cluster port rule that ensures that all SSL traffic for a network client computer is routed to the same cluster host after making an initial connection. <sup>[MeasureUp][mu:70-740]</sup>
```powershell
Get-NlbCluster | Add-NlbClusterPortRule -StartPort 443 -EndPort 443 -Affinity Single
```
##### New-ClusterFaultDomain
Tasks:
- [Configure a site-aware failover cluster](#site-aware-failover-cluster)

##### Set-ClusterFaultDomain
Tasks:
- [Configure a site-aware failover cluster](#site-aware-failover-cluster)
##### Set-SCVirtualMachine
`DynamicMemoryEnabled`
`MemoryMB`

Disable dynamic memory on a VM <sup>[MeasureUp][mu:70-740]</sup>
```powershell
Set-SCVirtualMachine -DynamicMemoryEnabled $false
```
Increase the amount of running memory for a VM without dynamic memory enabled
```powershell
Set-SCVirtualMachine -VM (Get-SCVirtualMachine -Name "DataServ") -MemoryMB 2048
```
##### New-IscsiVirtualDisk
`Fixed`
`Path`
`SizeBytes`

```powershell
New-IscsiVirtualDisk -Fixed -SizeBytes 500mb -Path 'C:\QuorumHD.vhdx'
```
##### New-IscsiServerTarget
```powershell
New-IscsiServerTarget -TargetName PLABDC01 -InitiatorId @("DNSName:plabdm01.practicelabs.com","plabsa01.practicelabs.com")
```
##### New-VMSAN
**`Name`**

```powershell
New-VMSan "PLABS-Fc"
```
##### Add-VMFibreChannelHBA
**`VMName`**
**`SANName`**

```powershell
Add-VMFibreChannelHBA PLABDC02 "PLABS-Fc"
```
# Concepts
[endpoint]: # 'endpoint&#10;a particular configuration item in WinRM, representing a specific application for which WinRM can receive traffic'
[explicit remoting]: # 'explicit remoting&#10;opening a temporary or persistent Powershell session to a remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 176'
[external virtual switch]: # 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[implicit remoting]: # 'implicit remoting&#10;running a cmdlet specifying the `ComputerName` parameter, which directs its function to the remote system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 177'
[internal virtual switch]: # 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[listener]: # 'listener&#10;configuration item in WinRM representing the ability of the service to accept incoming network traffic, associated with a TCP port number'
[NuGet]: # 'NuGet&#10;.NET package manager'
[private virtual switch]: # 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[remoting]: # 'remoting&#10;term applied to the use of WinRM in Powershell over port 5985 (or 5986 for HTTPS)'
[WinRM]: # 'Windows Remote Management (WinRM)&#10;Microsoft implementation of the WSMAN protocol, which handles communications and authentication for connections for many applications.&#10;Unlike MMCs, which are based on DCOM (legacy technology), WinRM is considered firewall-friendly and is the preferred option'

Concepts
- [NuGet][NuGet]

Powershell [remoting][remoting] can be done [explicitly][explicit remoting] or [implicitly][implicit remoting].
Explicit remoting is also 1-to-1 remoting, where an interactive Powershell prompt is brought up on a remote computer.
One-to-many or fan-out remoting is possible with implicit remoting, where a command is transmitted to many computers .
Remoting relies on [WinRM][WinRM], which is Microsoft's implementation of WSMAN. 

# Tasks
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
- [Set IP address to DHCP][Set-NetIpInterface]
- [Add a local user to administrators](#add-a-new-local-admin)
- [Install NuGet][Install-PackageProvider]
- [XML](#handle-xml-files)
- [Create a virtual switch with SET enabled](#create-a-virtual-switch-with-set-enabled)<sup>70-740</sup>
- [Implement nested virtualization](#implement-nested-virtualization)<sup>70-740</sup>
- [Enable CredSSP](#enable-credssp)<sup>70-740</sup>
- [Configure Server Core](#configure-server-core)<sup>70-740</sup>
- [Implement Discrete Device Assignment](#implement-dda)<sup>70-740</sup>
- [Create a S2D cluster](#configure-s2d-cluster)<sup>70-740</sup>
- [Configure a pass-through disk](#pass-through-disk)<sup>70-740</sup>
- [Create a VM, specifying installation media](#create-vm-with-installation-media)<sup>70-740</sup>

#### Computer information
Display computer name 
[<sup>devblogs.microsoft.com</sup>][https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]
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
Add-Computer -DomainName adatum.com -NewName Server8 -Credential adatum\administrator
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
Disable-PnpDevice -InstanceId                 # Remove host-installed drivers
Get-PnpDeviceProperty                         # Provide `InstanceId` and `KeyName` values in order to get value for `LocationPath` parameter in next command
Dismount-VmHostAssignableDevice -LocationPath # Remove the device from host control
Add-VMAssignableDevice -VM -LocationPath      # Attach the device to a guest
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
#### Install Docker Enterprise
[Zacker][Zacker]: 266
```powershell
Install-Module -Name dockermsftprovider -repository psgallery -force
Install-Package -Name docker -ProviderName dockermsftprovider
```
#### Handle XML files
Find a sample XML file [here](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ms762271(v=vs.85) "books.xml")

Assign the output of [`gc`][Get-Content] to a variable
```powershell
[xml]$xdoc = gc $xmlfile
```
The XML tree can be viewed in VS Code using the **XML Tools** extension.
The object itself can be treated as a first-class Powershell object using dot notation. <sup>[red-gate.com](https://www.red-gate.com/simple-talk/sysadmin/powershell/powershell-data-basics-xml/ "Powershell Data Basics: XML")</sup>
```powershell
$xdoc.catalog.book | Format-Table -Autosize
```
Arrays of elements can be accessed by their index
```powershell
$xdoc.catalog.book[0]
```
Nodes in the XML object can also be navigated using **XPath** notation with the `SelectNodes` and `SelectSingleNode` methods.
```powershell
$xdoc.SelectNodes('//author')
This produces the same output as the command above (in XPath nodes are 1-indexed).
```powershell
$xdoc.SelectSingleNode('//book[1]')
```
[`Select-Xml`][Select-Xml] wraps the returned XML node with additional metadata, including the pattern searched.
However, it can accept piped input.
```powershell
(Select-Xml -Xml $xdoc -Xpath '//book[1]').Node
($xml | Select-Xml -Xpath '//book[1]').Node
```
#### Update Server Core images
[MeasureUp Lab][pl:70-740]
```powershell
Mount-WindowsImage -ImagePath .\CoreServer.vhdx -Path .\MountDir -Index 1
Add-WindowsPackage -Path .\MountDir PackagePath C:\ServicingPackages_cabs
Dismount-WindowsImage -Path .\MountDir -Save
```
##### Pass-through disk
[Zacker][Zacker]: 226
```powershell
Set-Disk -Number 2 -IsOffline $true
Add-VMHardDiskDrive -VMName server1 -ControllerType scsi -DiskNumber 2
```
##### Site-aware failover cluster
Configure failover clusters for two offices <sup>[Zacker][Zacker]: 366</sup>
```powershell
New-ClusterFaultDomain -Name ny -Type site -Description "Primary" -Location "New York, NY"
New-ClusterFaultDomain -Name sf -Type site -Description "Secondary" -Location "San Francisco, CA"
Set-ClusterFaultDomain -Name node1 -Parent ny
Set-ClusterFaultDomain -Name node2 -Parent ny
Set-ClusterFaultDomain -Name node3 -Parent sf
Set-ClusterFaultDomain -Name node4 -Parent sf
```
##### Filter AD account information
```powershell
Get-aduser -filter {(SamAccountName -like "*CA0*")} -properties Displayname, SaMaccountName, Enabled, EmailAddress, proxyaddresses | 
Where {($_.EmailAddress -notlike "*@*")} | 
Where {($_.Enabled -eq $True)} | 
Select Displayname, SaMaccountName, Enabled, EmailAddress, @{L=’ProxyAddress_1'; E={$_.proxyaddresses[0]}}, @{L=’ProxyAddress_2'; E={$_.ProxyAddresses[1]}} | 
Export-csv .\usersnoemail2.csv -notypeinformation
```
##### Create VM with installation media
[Practice Lab][pl:70-740]
```powershell
New-VM PLABWIN102 1536mb 1 -SwitchName 'Private network 1' -NewVHDPath 'C:\Users\Public\Documents\Hyper-V\Virtual hard disks\PLABWIN102.vhdx' -NewVHDSizeBytes 127gb
Set-VMDvdDrive -VMName PLABWIN102 -Path C:\Users\Administrator.PRACTICELABS\Documents\Eval81.iso
```
#### Registry

Description | Affected key
---         | ---
Fix Windows Search bar <sup>[docs.microsoft.com][https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-keys?view=powershell-7]</sup> | HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search
Remove 3D Objects <sup>[howtogeek.com](https://www.howtogeek.com/331361/how-to-remove-the-3d-objects-folder-from-this-pc-on-windows-10/ "How to Remove “3D Objects” From This PC on Windows 10")</sup> | HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace
Display seconds in system clock <sup>[howtogeek.com](https://www.howtogeek.com/325096/how-to-make-windows-10s-taskbar-clock-display-seconds/ "How to Make Windows 10’s Taskbar Clock Display Seconds")</sup> | HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced
Disable Aero Shake <sup>[howtogeek.com](https://www.howtogeek.com/howto/windows-7/disable-aero-shake-in-windows-7/ "How to Stop Aero Shake from Minimizing Your Windows") | HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced

Remove **3D Objects** from **This PC** <sup>[howtogeek.com](https://www.howtogeek.com/331361/how-to-remove-the-3d-objects-folder-from-this-pc-on-windows-10/ "How to Remove “3D Objects” From This PC on Windows 10")</sup>
```powershell
Remove-Item 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace\{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}'
```
Add seconds to clock <sup>[howtogeek.com](https://www.howtogeek.com/325096/how-to-make-windows-10s-taskbar-clock-display-seconds/ "How to Make Windows 10’s Taskbar Clock Display Seconds")</sup>
```powershell
New-Item -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced -Name ShowSecondsInSystemClock -Value 1
Restart-Computer
```
```powershell
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search -Name BingSearchEnabled -Value 0
New-Item -Path HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Search -Name CortanaConsent -Value 0
```
Safely combine related registry modifications using [`Start-Transaction`][Start-Transaction] and [`Complete-Transaction`][Complete-Transaction] <sup>[Holmes][Holmes]: 604</sup>
```powershell
Start-Transaction
New-Item TempKey -UseTransaction
Complete-Transaction
```
