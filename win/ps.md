# PowerShell

## Basic Syntax
  - Backtick (\`) is 

## Basic syntax and common tasks

Bash    | PowerShell | Notes
:---    | :---       | :---
\\      | \`         | used at the end of lines to allow multiline commands
`alias` | `Get-Alias`, `gal`; `New-Alias`, `nal`
`awk`   | 
`cat`   | `Get-Content`, `cat`, `gc`, `type` 
`cp`    | `Copy-Item`, `cp`, `cpi`, `copy`
`cd`    | `Set-Location`, `cd`, `sl`, `chdir`
`find`  | `Get-ChildItem -Recurse -File -Filter ...`
`grep`  | `Where-Object`, `where`, `?` | See __Filters__ below
`less`  | `Out-Host -Paging`, `oh -Paging`
`man`   | `Get-Help`
`more`  | rf. `less`
`ls`    | `Get-ChildItem`, `dir`, `gci`, `ls` 
`mkdir` | `New-Item`
`pwd`   | `Get-Location`, `gl`, `pwd`
`reset` | `Clear-Host`, `clear`, `cls` 
`rm`    | `Remove-Item`, `rm`, `ri`, `rmdir`, `rd`, `del`
`sed`   | `Select-Object`, `select` | See __Filters__ below
`tail`  | `Get-Content -Tail`
`touch` | `New-Item`

#### Filters
Filtering results can be done with 5 commands:
  - `Where-Object` (aliased to `where` and `?`): the most commonly used such command
  - `Select-Object` (aliased to `select`): used to specify specific columns of information to be displayed
  - `Select-String` (aliased to `sls`)
  - `ForEach-Object` (aliased to `foreach` and `%`)
  - `Out-GridView`

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

## Help commands

Syntax  | Effect
:--- | :---
`Get-Help cmd`              | display help file for {cmd}
`Get-Help cmd -Examples`    | display usage examples
`Get-Help cmd -Detailed`    | display detailed help for a command
`Get-Help cmd -Full`        | display entire help file for a command
`Get-Help cmd -Online`      | navigate to online help page for a command
`Get-Help cmd -ShowWindow`  | display help output in a window
`Update-Help`               | download help files

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
`Get-Alias -Definition Get-ChildItem`|display items that point to `Get-ChildItem`
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
`Install-Module -Name Az -AllowClobber` | Install the __Az__ module
`Import-Module SmbShare`|import module {SmbShare}


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

#### Display locked out accounts
```powershell
Search-ADAccount `
  -LockedOut`
```

#### Unlock account
```powershell
Unlock-ADAccount `
  -identity wbryan
```

### ADAccountPassword

#### Reset password

```powershell
Set-ADAccountPassword `
  -identity MBentley `
  -Reset `
  -NewPassword (`
    ConvertTo-SecureString `
      -AsPlainText "What is 255.255.255.240" `
      -Force`
  )
```

### ADOrganizationalUnit

#### Create a new Organizational Unit
```powershell
New-ADOrganizationalUnit `
  -Name GNV `
  -Credential officeprodemoco\joey
```

#### Remove accidental deletion protection
```powershell
Set-ADOrganizationalUnit `
  -Name GNV `
  -ProtectedFromAccidentalDeletion $False `
  -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" 
```

#### Remove an OU
```powershell
Remove-ADOrganizationalUnit `
  -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" `
  -confirm:$False
```

#### Display OUs, confirming deletion has taken place
```powershell
Get-ADOrganizationalUnit `
  -filter * `
  | FT
```

### Get-ADUser
#### Display information for Active Directory user {mike}
```powershell
Get-ADUser `
  -Identity mike
```

#### Display Protection from Accidental Deletion
```powershell
Get-ADUser `
  -Filter * `
  -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  `
  -Properties ProtectedFromAccidentalDeletion
```

#### Protect users in a specified OU from accidental deletion
```powershell
Get-ADUser `
  -Filter * `
  -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" `
  | Set-ADObject `
    -ProtectedFromAccidentalDeletion $true
```

### New-ADUser
#### Create a new user (disabled by default)
```powershell
New-ADUser `
  -Name "Walter Mitty"
```

#### Create a new user
```powershell
New-ADUser `
  -Name "Marty McFly" `
  -AccountPassword (`
    ConvertTo-SecureString "P@ssw0rd!" `
      -AsPlainText `
      -Force`
  ) `
  -Enabled $true `
  -GivenName "Martin" `
  -Surname "McFly"
```

#### Display information on user, confirming successful creation
```powershell
Get-ADUser "Marty McFly" `
  | Select-Object Name
```

#### Add a CSV full of users
```powershell
import-csv users.csv `
  | foreach { `
    New-ADUser `
      -SamAccountName $_.SAM `
      -GivenName $_.Last `
      -DisplayName $_.DisplayName `
      -Name $_.Name `
      -Description $_.Description `
      -AccountPassword ( `
        ConvertToSecureString $_.Password `
          -AsPlainText `
          -Force `
      ) `
      -Enabled $True `
  }`
```


## Network
#### Display IP configuration

```powershell
Get-IPAddress
```

#### Configure the machine to accept WS-Management requests from other machines

```powershell
winrm quickconfig
winrm qc
```

### NetFirewallRule
#### Set firewall rule for COM+ Network Access (DCOM-In)
```powershell
Set-NetFirewallRule `
  -name COMPlusNetworkAccess-DCOM-In `
  -Enabled True
```

#### Set firewall rule for Remote Event Log Management (NP-In)
```powershell
Set-NetFirewallRule `
  -name RemoteEventLogSvc-In-TCP `
  -Enabled True
```

#### Set firewall rule for Remote Event Log Management (RPC)
```powershell
Set-NetFirewallRule `
  -name RemoteEventLogSvc-NP-In-TCP `
  -Enabled True
```

#### Set firewall rule for Remote Event Log Management (RPC-EPMAP)
```powershell
Set-NetFirewallRule `
  -name RemoteEventLogSvc-RPCSS-TCP `
  -Enabled True
```

#### List all WinRM listeners  
```powershell
winrm enumerate winrm/config/listener
```

#### Display WinRM configuration
```powershell
winrm get winrm/config
```

#### Install Remote Server Adminstration Tools for PowerShell
```powershell
Install-WindowsFeature `
  -Name RSAT-ADDS `
  -IncludeAllSubFeature
```


## Web requests 

### Invoke-WebRequest

#### Download a file over HTTP/HTTPS

```powershell
Invoke-WebRequest `
  -Uri http://example.com/path/to/file `
  -OutFile \\path\to\local\file
```

#### Resume a partial download

```powershell
Invoke-WebRequest `
  -Uri http://example.com/path/to/file `
  -Resume `
  -Outfile \\path\to\local\file
```

#### Transfer a file over FTP/SFTP

```powershell
Invoke-WebRequest ftp://ftp.example.com/file `
  -Outfile C:\path\to\file `
  -Credential ftpuseraccount
```

#### Resolve shortened URLs

```powershell
$Uri = 'short-url/extension'  
$Web = Invoke-WebRequest -Uri 
$Uri -UseBasicParsing  $Web.BaseResponse.ResponseUri.AbsoluteUri
```

#### Scrape links from a website

```powershell
(Invoke-WebRequest `
  -Uri "https://techrepublic.com" `
).Links.Href
```

#### Request data from a website impersonating a browser

```powershell
Invoke-WebRequest `
  -Uri http://microsoft.com `
  -UserAgent ([Microsoft.PowerShell.Commands.PSUserAgent]::Chrome)
```

## Azure
#### Install the __Az__ module
```powershell
Install-Module  `
  -Name Az      `
  -AllowClobber
```

#### Create a VM
Where `$cred` was set with the username and password needed for the admin account:
```powershell
$cred = Get-Credential
```

```powershell
New-AzVM                                                              `
  -ResourceGroupName    "RG"                                          `
  -Name                 "VM"                                          `
  -Location             "EastUS"                                      `
  -VirtualNetworkName   "VN"                                          `
  -SubnetName           "SN"                                          `
  -SecurityGroupName    "SG"                                          `
  -PublicIpAddressName  "IP"                                          `
  -Credential           $cred
```

#### Connecting to a VM
WinRM access must be enabled on the target VM
```powershell
winrm quickconfig
```

Open port __5985__ to enable inbound WinRM connections from the Azure Portal

Context                           | Action  | Effect
:---                              | :---    | :---
Azure Portal                      | Select __Virtual machines__ blade | Enter __Virtual machines__ page
Virtual machines page             | Select VM to be modified | Enter __Virtual machine__ page
Virtual machine page              | Select _Settings_ > __Networking__  | Open __Network Interface__ page
Network interface page            | Click __Add inbound port rule__ button | Open __Add inbound security rule__ modal dialog box
Add inbound security rule dialog  | Click __Basic__ button at top of dialog, switching to basic mode. Enter "5985" into __Port ranges__ field | 


## Other commands

### PSReadlineOption
#### Display options available in the module
```powershell
Get-PSReadlineOption
```

#### Set history to only save unique commands
```powershell
Set-PSReadlineOption        `
  -HistoryNoDuplicates:$true
```
#### Enable bash-like ambiguous command completion, where tab brings up a menu of matches
```powershell
Set-PSReadlineOption        `
  -EditMode Emacs
```

#### Change &lt;Tab&gt; behavior back to default for PowerShell
```powershell
Set-PSReadlineOption        `
  -EditMode Windows
```

## Sources
  - "How to use Wget to download web-based packages on Windows." [TechRepublic](https://www.techrepublic.com/article/how-to-use-wget-to-download-web-based-packages-on-windows/#ftag=RSS56d97e7)
  - "Check PowerShell Version". [powertheshell.com](http://www.powertheshell.com/topic/learnpowershell/firststeps/psversion/)
  - "Enable-PSRemoting". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/enable-psremoting?view=powershell-6)
  - "Azure Az Module for Windows PowerShell, Core, and Cloud Shell Replaces Azure RM". [Petri](https://www.petri.com/azure-az-module-for-windows-powershell-core-and-cloud-shell-replaces-azurerm)
  - "Manage Azure IaaS virtual machines with Windows Admin Center". [Microsoft Docs](https://docs.microsoft.com/en-us/windows-server/manage/windows-admin-center/azure/manage-azure-vms)
  - "PowerShell Basics: Filtering Objects". [ITPro Today](https://www.itprotoday.com/powershell/powershell-basics-filtering-objects). 2013/07/25.
  - "PowerShell equivalents for common Linux/bash commands". [TheShellNut](https://mathieubuisson.github.io/powershell-linux-bash/). 2015/09/30.
