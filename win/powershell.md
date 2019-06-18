# PowerShell

## Commands
Syntax | Effect | Source
:---  | :---    | :---
`Get-Module`|display loaded PowerShell modules
`Get-Module -ListAvailable`|display installed PowerShell modules
`Import-Module SmbShare`|import module <SmbShare>
`Get-Command \| measure` | piping to `measure` is similar to `wc`, will count lines
`Get-ADUser`|
`Get-Command -Module ActiveDirectory`|display cmdlets available under a specified module
`Get-Command *smb* `|use a wildcard
`Get-Help Add-Computer`|display help file for a command
`Get-Help Add-Computer -Examples`|display usage examples
`Get-Help Add-Computer -Details`|display detailed help for a command
`Get-Help Add-Computer -Full`|display entire help file for a command
`Get-Help Add-Computer -Online`|navigate to online help page for a command
`Get-Help Add-Computer -ShowWindow`|displays help output in a window
`Get-ADUser -Identity mike`|display information for Active Directory user <mike>
`Get-History`|display history of inputted commands for the current session
`Invoke-History`|run a command from the history
`Get-PSReadlineOption`|display options available in the module
`Set-PSReadlineOption -HistoryNoDuplicates:$true`|set history to only save unique commands
`Set-PSReadlineOption -EditMode Emacs`|enable bash-like functionality where an incomplete command followed by <Tab> will produce a list of all matching commands
`Set-PSReadlineOption -EditMode Windows`|change <Tab> behavior back to default for PowerShell
`Get-Process`|display running processes
`Clear-Host`|clear screen
`Get-Services`|display services
`Get-Alias`|display services
`Get-Alias -Definition -Get-ChildItem`|display items that point to `-Get-ChildItem`
`Get-IPAddress`|display IP configuration
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter`|edit an existing alias
`Export-Alias -Path alias.ps1 -As Script`|export session aliases to a ".ps1" file
`Get-Service \| Sort-Object` | sort list of services
`Get-Serivce \| Write-Host` | will produce an error because `Write-Host` expects a single object
`Get-Service \| ForEach-Object {Write-Host $_.name}`| loop through each object in output of `Get-Service` and send the `name` field to `Write-Host`
`Get-Service \| Format-Wide` | change output format to `Format-Wide`
`Get-Service \| Format-Wide -Column 1` | change output format to be a single column
`Get-Service \| Format-Wide -Property DisplayName` | change output to display the `DisplayName` property
`Get-Service \| Format-List` | display output as a list with properties listed next to values
`Get-Service \| Format-List -Property *` | display all properties
`Get-Service \| fl -Property Status,StartType,DisplayName` | display only specified properties
`Get-Service \| Format-Table -Property *`|display all properties
`Get-Service \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status`, but the output will be confused because it was not sorted
`Get-Service \| Sort-Object -Property Status \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status` after sorting
`Get-PSDrive`|display mapped drives
`Set-Location`|change the present working directory (`cd` is an alias)
`New-PSDrive -Name scripts -PSProvider FileSystem -Root "C:\Scripts"`|map a directory to a drive
`Remove-PSDrive -Name scripts`|remove a drive
`$profile`|display file of current profile
`$profile.CurrentUserCurrentHost`| C:\Users\Michael\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
`$profile.CurrentUserAllHosts`|C:\Users\Michael\Documents\WindowsPowerShell\profile.ps1
`$profile.AllUsersAllHosts`|C:\Windows\System32\WindowsPowerShell\v1.0\profile.ps1
`$profile.AllUsersCurrentHost`|C:\Windows\System32\WindowsPowerShell\v1.0\Microsoft.PowerShell_profile.ps1
`Stop-Service winrm`|stop the <winrm> service
`Get-Service winrm`|display status of <winrm> service
`winrm quickconfig`, `winrm qc`|configure the machine to accept WS-Management requests from other machines
`Enable-PSRemoting`|allow remote PowerShell management
`Set-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In -Enabled True`|set firewall rule for COM+ Network Access (DCOM-In)
`Set-NetFirewallRule -name RemoteEventLogSvc-In-TCP -Enabled True`|set firewall rule for Remote Event Log Management (NP-In)
`Set-NetFirewallRule -name RemoteEventLogSvc-NP-In-TCP -Enabled True`|set firewall rule for Remote Event Log Management (RPC)
`Set-NetFirewallRule -name RemoteEventLogSvc-RPCSS-TCP -Enabled True`|set firewall rule for Remote Event Log Management (RPC-EPMAP)
`winrm enumerate winrm/config/listener`|list all WinRM listeners  
`Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}`|execute the commands in the block on the machines specified
`New-PSSession -ComputerName core02`|start a new PowerShell session, connecting to the specified computer
`Get-PSSession`|display PowerShell sessions
`Enter-PSSession -id 1`|interact with the specified PowerShell session
`Exit-PSSession -ComputerName demodc`|end the PowerShell session with the specified computer
`Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart`|install Hyper-V from PowerShell command-line
`Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false`|disable dynamic memory on a virtual host (nested virtualization)
`Set-VMProcessor -VMName SVR01 -Count 2`| configure 2 virtual processors on a virtual host (nested virtualization)
`Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On`|turn on MAC address spoofing on a virtual host (nested virtualization)
`winrm get winrm/config`|display WinRM configuration
`Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey`|start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
`Install-WindowsFeature -Name RSAT-ADDS -IncludeAllSubFeature`|Install Remote Server Adminstration Tools for PowerShell
`New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey`|Create a new Organizational Unit
`Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" `| remove accidental deletion protection
`Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False`|remove an OU
`Get-ADOrganizationalUnit -filter * \| FT`|display OUs, confirming deletion has taken place
`New-ADUser -Name "Walter Mitty"`|create a new user (disabled by default)
`New-ADUser -Name "Marty McFly" -AccountPassword (ConvertTo-SecureString "P@ssw0rd!" -AsPlainText -Force) -Enabled $true -GivenName "Martin" -Surname "McFly"`|create a new user
`Get-ADUser "Marty McFly" \| Select-Object Name`|display information on user, confirming successful creation
`import-csv users.csv \| foreach {New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) -Enabled $True}`|add a CSV full of users
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" \| Set-ADObject -ProtectedFromAccidentalDeletion $true`|protect users in a specified OU from accidental deletion
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  -Properties ProtectedFromAccidentalDeletion`|Display Protection from Accidental Deletion
`Set-ADAccountPassword -identity MBentley -Reset -NewPassword (ConvertTo-SecureString -AsPlainText "What is 255.255.255.240" -Force)`|reset password
`Search-ADAccount -LockedOut`|display locked out accounts
`Unlock-ADAccount -identity wbryan`|unlock account
