# PowerShell

## Common Tasks

Syntax  | Effect 
:---    | :---
`Clear-Host`|clear screen
`Set-Location`|change the present working directory (`cd` is an alias)

## Display basic system information

Syntax  | Effect
:--- | :---
`Get-Alias`                 | display aliases
`Get-Command`               | display all installed commands, including aliases, applications, filters, functions, and scripts
`Get-Help cmd`              | display help file for {cmd}
`Get-History`               | display history of inputted commands for the current session
`Get-Module`                | display currently loaded PowerShell modules
`Get-Process`               | display running processes
`Get-PSDrive`               | display mapped drives
`Get-Services`              | display services
`$PSVersionTable`           | display PowerShell version
`Update-Help`               | download help files

### Further commands

Syntax  | Effect
:--- | :---
`Get-Alias -Definition -Get-ChildItem`|display items that point to `-Get-ChildItem`
`Get-Command \| measure`    | piping to `measure` is similar to `wc`, will count lines
`Get-Command -Module ActiveDirectory`|display cmdlets available under a specified module
`Get-Command *smb*`         | use a wildcard
`Get-Module -ListAvailable` | display installed PowerShell modules
`Invoke-History`            | run a command from the history
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter`|edit an existing alias
`New-PSDrive -Name scripts -PSProvider FileSystem -Root "C:\Scripts"`|map a directory to a drive
`Remove-PSDrive -Name scripts`|remove a drive

## Output formatting

Syntax  | Effect
:---  | :---
`Get-Service \| Format-Wide` | change output format to `Format-Wide`
`Get-Service \| Format-Wide -Column 1` | change output format to be a single column
`Get-Service \| Format-Wide -Property DisplayName` | change output to display the `DisplayName` property
`Get-Service \| Format-List` | display output as a list with properties listed next to values
`Get-Service \| Format-List -Property *` | display all properties
`Get-Service \| fl -Property Status,StartType,DisplayName` | display only specified properties
`Get-Service \| Format-Table -Property *`|display all properties
`Get-Service \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status`, but the output will be confused because it was not sorted
`Get-Service \| Sort-Object` | sort list of services
`Get-Service \| Sort-Object -Property Status \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status` after sorting
`Get-Serivce \| Write-Host` | will produce an error because `Write-Host` expects a single object
`Get-Service \| ForEach-Object {Write-Host $_.name}`| loop through each object in output of `Get-Service` and send the `name` field to `Write-Host`

## Aliases

Syntax  | Effect
:--- | :---
`Get-Alias`                 | display aliases
`Get-Alias -Definition -Get-ChildItem`|display items that point to `-Get-ChildItem`
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter`|edit an existing alias
`Export-Alias -Path alias.ps1 -As Script`|export session aliases to a ".ps1" file

## Services

Syntax  | Effect
:--- | :---
`Stop-Service winrm`        | stop the <winrm> service
`Get-Service winrm`         | display status of <winrm> service

## Modules

Syntax  | Effect
:--- | :---
`Import-Module SmbShare`|import module {SmbShare}

## Help commands

Syntax  | Effect
:--- | :---
`Get-Help cmd`              | display help file for {cmd}
`Get-Help cmd -Examples`    | display usage examples
`Get-Help cmd -Details`     | display detailed help for a command
`Get-Help cmd -Full`        | display entire help file for a command
`Get-Help cmd -Online`      | navigate to online help page for a command
`Get-Help cmd -ShowWindow`  | display help output in a window
`Update-Help`               | download help files

## Profiles

Syntax  | Effect
:--- | :---
`$profile`|display file of current profile
`$profile.CurrentUserCurrentHost`| C:\Users\Michael\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
`$profile.CurrentUserAllHosts`|C:\Users\Michael\Documents\WindowsPowerShell\profile.ps1
`$profile.AllUsersAllHosts`|C:\Windows\System32\WindowsPowerShell\v1.0\profile.ps1
`$profile.AllUsersCurrentHost`|C:\Windows\System32\WindowsPowerShell\v1.0\Microsoft.PowerShell_profile.ps1

## Remote commands

Syntax  | Effect
:--- | :---
`Enable-PSRemoting`| allow remote PowerShell management
`Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}`|execute the commands in the block on the machines specified
`New-PSSession -ComputerName core02`|start a new PowerShell session, connecting to the specified computer
`Get-PSSession`|display PowerShell sessions
`Enter-PSSession -id 1`|interact with the specified PowerShell session
`Exit-PSSession -ComputerName demodc`|end the PowerShell session with the specified computer
`Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey`|start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.

## Hyper-V

Syntax  | Effect
:--- | :---
`Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart`|install Hyper-V from PowerShell command-line
`Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false`|disable dynamic memory on a virtual host (nested virtualization)
`Set-VMProcessor -VMName SVR01 -Count 2`| configure 2 virtual processors on a virtual host (nested virtualization)
`Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On`|turn on MAC address spoofing on a virtual host (nested virtualization)

## Active Directory
### ADAccount

Syntax  | Effect
:--- | :---
`Search-ADAccount -LockedOut`|display locked out accounts
`Unlock-ADAccount -identity wbryan`|unlock account

### ADAccountPassword

Syntax  | Effect
:--- | :---
`Set-ADAccountPassword -identity MBentley -Reset -NewPassword (ConvertTo-SecureString -AsPlainText "What is 255.255.255.240" -Force)`|reset password

### ADOrganizationalUnit

Anki | Syntax  | Effect
:---  | :--- | :---
`New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey`|Create a new Organizational Unit
`Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" `| remove accidental deletion protection
`Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False`|remove an OU
`Get-ADOrganizationalUnit -filter * \| FT`|display OUs, confirming deletion has taken place

### ADUser

Anki | Syntax  | Effect
:---  | :--- | :---
`Get-ADUser`|
`Get-ADUser -Identity mike` | display information for Active Directory user {mike}
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  -Properties ProtectedFromAccidentalDeletion`|Display Protection from Accidental Deletion
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" \| Set-ADObject -ProtectedFromAccidentalDeletion $true`|protect users in a specified OU from accidental deletion
`New-ADUser -Name "Walter Mitty"`|create a new user (disabled by default)
`New-ADUser -Name "Marty McFly" -AccountPassword (ConvertTo-SecureString "P@ssw0rd!" -AsPlainText -Force) -Enabled $true -GivenName "Martin" -Surname "McFly"`|create a new user
`Get-ADUser "Marty McFly" \| Select-Object Name`|display information on user, confirming successful creation
`import-csv users.csv \| foreach {New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) -Enabled $True}`|add a CSV full of users


Anki | Syntax  | Effect
:---  | :--- | :---
`Get-IPAddress`|display IP configuration
`winrm quickconfig`, `winrm qc`|configure the machine to accept WS-Management requests from other machines
`Set-NetFirewallRule -name COMPlusNetworkAccess-DCOM-In -Enabled True`|set firewall rule for COM+ Network Access (DCOM-In)
`Set-NetFirewallRule -name RemoteEventLogSvc-In-TCP -Enabled True`|set firewall rule for Remote Event Log Management (NP-In)
`Set-NetFirewallRule -name RemoteEventLogSvc-NP-In-TCP -Enabled True`|set firewall rule for Remote Event Log Management (RPC)
`Set-NetFirewallRule -name RemoteEventLogSvc-RPCSS-TCP -Enabled True`|set firewall rule for Remote Event Log Management (RPC-EPMAP)
`winrm enumerate winrm/config/listener`|list all WinRM listeners  
`winrm get winrm/config`|display WinRM configuration
`Install-WindowsFeature -Name RSAT-ADDS -IncludeAllSubFeature`|Install Remote Server Adminstration Tools for PowerShell


## Web requests 

### Invoke-WebRequest

#### Download a file over HTTP/HTTPS
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -OutFile \\path\to\local\file
```

#### Resume a partial download
```powershell
Invoke-WebRequest -Uri http://example.com/path/to/file -Resume -Outfile \\path\to\local\file
```

#### Transfer a file over FTP/SFTP
```powershell
Invoke-WebRequest ftp://ftp.example.com/file -Outfile C:\path\to\file -Credential ftpuseraccount
```

#### Resolve shortened URLs

```powershell
$Uri = 'short-url/extension'  
$Web = Invoke-WebRequest -Uri 
$Uri -UseBasicParsing  $Web.BaseResponse.ResponseUri.AbsoluteUri
```

#### Scrape links from a website

```powershell
(Invoke-WebRequest -Uri "https://techrepublic.com").Links.Href
```

#### Request data from a website impersonating a browser

```powershell
Invoke-WebRequest -Uri http://microsoft.com -UserAgent ([Microsoft.PowerShell.Commands.PSUserAgent]::Chrome)
```

## Azure

:---  | :---

## Other commands


### PSReadlineOption

Syntax  | Effect
:---  | :---
`Get-PSReadlineOption`|display options available in the module
`Set-PSReadlineOption -HistoryNoDuplicates:$true`|set history to only save unique commands
`Set-PSReadlineOption -EditMode Emacs`|enable bash-like functionality where an incomplete command followed by <Tab> will produce a list of all matching commands
`Set-PSReadlineOption -EditMode Windows`|change <Tab> behavior back to default for PowerShell

## Sources
  - "How to use Wget to download web-based packages on Windows." [TechRepublic](https://www.techrepublic.com/article/how-to-use-wget-to-download-web-based-packages-on-windows/#ftag=RSS56d97e7)
  - "Check PowerShell Version". [powertheshell.com](http://www.powertheshell.com/topic/learnpowershell/firststeps/psversion/)
  - "Enable-PSRemoting". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/enable-psremoting?view=powershell-6)
