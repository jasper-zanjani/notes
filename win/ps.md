# PowerShell
## Basic Syntax
### Syntax to research
#### `[?...]` 
From [AZ-103](../sources/az-103-tasks.md) 1.4c.09:
```powershell
groupid=$(az ad group list --query "[?displayName=='Cloud Admins'].objectId" -o tsv)
```
#### `::`
From "View system uptime" below:
```powershell
Select-Object -Property @{n="Last Boot Time";e={[Management.ManagementDateTimeConvert]::ToDateTime($_.LastBootUpTime)}}
```
#### `ForEach-Object`
See [4.4c.02](../sources/az-103-tasks.md)
### Automatic variables
**Automatic variables** are variables that store state information for PowerShell and are created and maintained by Powershell.

Syntax  | Effect
:---    | :---
`$$` | last token in the last line received by the session
`$?` | execution status of the last operation
`$^` | first token in the last line received by the session
`$_` | current object in the pipeline object
### Comparison operators
Syntax  | Effect
:---    | :---
`-eq`
`-ne`
`-gt`
`-ge`
`-lt`
`-le`
`-like` | wildcard pattern
`-notlike`
`-match` | regex pattern
`-notmatch`
`-contains`
`-notcontains`
`-in`
`-notin`
`-replace`
`-is`   | type comparison
`-isnot`
### Comparison with bash
Bash            | PowerShell | Notes
:---            | :---       | :---
\\              | \`         | used at the end of lines to allow multiline commands
`$!` `!$`       | `$$` | automatic variable referring to the last "token" (argument) in the previous command
`$?`            | `$?` | automatic variable containing the execution status of the previous command
`&`             | `Start-Job`,`sajb` | sends a process into the background
`>>`            | `Add-Content`, `ac`
`alias`         | `Get-Alias`, `gal`; `New-Alias`, `nal`
`awk`           | `Select-Object`, `select` | See __Filters__ below
`cat`           | `Get-Content`, `cat`, `gc`, `type` 
`cp`            | `Copy-Item`, `cp`, `cpi`, `copy`
`cd`            | `Set-Location`, `cd`, `sl`, `chdir`
`echo`          | `Write-Host`
`find`          | `Get-ChildItem -Recurse -File -Filter ...`
`grep`          | `Where-Object`, `where`, `?` | See __Filters__ below
`less` `more`   | `Out-Host -Paging`, `oh -Paging`
`man`           | `Get-Help`
`ls`            | `Get-ChildItem`, `dir`, `gci`, `ls` 
`mkdir`         | `New-Item -ItemType Directory`, `ni -ItemType Directory`
`print`         | `Write-Host`
`printf`        | `Write-Host`
`pwd`           | `Get-Location`, `gl`, `pwd`
`reset`         | `Clear-Host`, `clear`, `cls` 
`rm`            | `Remove-Item`, `rm`, `ri`, `rmdir`, `rd`, `del`
`sed`           | `Where-Object`, `where`, `?` | See __Filters__ below
`shutdown -r`   | `Restart-Computer`
`shutdown`      | `Stop-Computer`
`tail`          | `Get-Content -Tail`
`touch`         | `New-Item`
`uniq`          | `Select-Object -Unique`
### Filters
Filtering results can be done with 5 commands:
  - `Where-Object` (aliased to `where` and `?`): the most commonly used such command
  - `Select-Object` (aliased to `select`): used to specify specific columns of information to be displayed
  - `Select-String` (aliased to `sls`)
  - `ForEach-Object` (aliased to `foreach` and `%`)
  - `Out-GridView`
#### Foreach-Object
There are two different ways to construct a `ForEach-Object` statement:
  1. __Script block__, within which the variable `$_` represents the current object
  2. __Operation statement__, more naturalistic, where you specify a property value or call a method.

### Display basic system information
Syntax                        | Effect
:---                          | :---
`$PSDefaultParametersValues`  | hash table that specifies custom default values for any cmdlet or advanced function
`$PSVersionTable`             | display PowerShell version
`Get-Alias`                   | display aliases
`Get-Command`                 | display all installed commands, including aliases, applications, filters, functions, and scripts
`Get-Help cmd`                | display help file for {cmd}
`Get-History`                 | display history of inputted commands for the current session
`Get-Module`                  | display currently loaded PowerShell modules
`Get-Process`                 | display running processes
`Get-PSDrive`                 | display mapped drives
`Get-Services`                | display services
`Update-Help`                 | download help files

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

### Common parameters
Option                        | Effect
:---                          | :---
`-Debug`,`-db`                | display programmer-level detail about command operation
`-ErrorAction`                | determine how the cmdlet responds to a non-terminating error
`-ErrorVariable`,`-ev`        | store errors in specified variable
`-InformationAction`,`-infa`  | specify action to take at occurrences of `Write-Information` command
`-InformationVariable`,`-iv`  | store information message passed from `Write-Information` cmdlet
`-OutVariable`,`-ov`          | store output objects from the command in the specified variable
`-OutBuffer`,`-ob`            | determine number of objects to accumulate in a buffer before any objects are sent through the pipeline
`-PipelineVariable`,`-pv`     | store value of the current pipeline element in specified variable
`-Verbose`,`-vb`              | display detailed operation done by the command
`-WarningAction`,`-wa`        | specify action to take on occurrence of `Write-Warning` cmdlet
`-WarningVariable`,`-wv`      | store warnings about the command in a variable
`-WhatIf`,`-wi`               | display a message describing the effect of the command, instead of actually executing it
`-Confirm`,`-cf`              | prompt for confirmation before executing the command

### Help commands
Syntax  | Effect
:---    | :---
`Get-Help cmd`                | display help file for {cmd}
`Get-Help cmd -Examples`      | display usage examples
`Get-Help cmd -Detailed`      | display detailed help for a command
`Get-Help cmd -Full`          | display entire help file for a command
`Get-Help cmd -Online`        | navigate to online help page for a command
`Get-Help cmd -ShowWindow`    | display help output in a window
`Update-Help`                 | download help files

### Output formatting
Syntax  | Effect
:---    | :---
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

### File manipulation
Syntax  | Effect
:---    | :---
`New-Item -ItemType File -Name filename` | create a new file in the current working directory named &lt;filename&gt;
`Add-Content C:\path\to\file $content` | append &lt;content&gt; to &lt;file&gt;

#### Add-Content
Option                        | Mandatory | Position
:---                          | :---      | :---
`-Path`                       | ✔ | 0
`-Value`                      | ✔ | 1 

### Other syntax
**Hash tables** (equivalent to Python dictionaries) are declared with `@{...}` ([Source](../sources/az-103-tasks.md#11b7-remove-tags-from-a-resource-powershell/))
```powershell
Set-AzResourceGroup -Tag @{} -Name hrgroup 
```
### Defining functions
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
## Environment manipulation
### Alias
Syntax  | Effect
:---    | :---
`Get-Alias`                 | display aliases
`Get-Alias -Definition Get-ChildItem`|display items that point to `Get-ChildItem`
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter`|edit an existing alias
`Export-Alias -Path alias.ps1 -As Script`|export session aliases to a ".ps1" file
### Service
Syntax  | Effect
:---    | :---
`Start-Service WinRM`, `sasv winrm` | Start the &lt;WinRM&gt; service
`Stop-Service WinRM`, `spsv winrm`  | Stop the &lt;WinRM&gt; service
`Get-Service WinRM`, `gsv winrm`    | Display status of &lt;WinRM&gt; service
### Module
Modules are automatically imported, if available, when you run a command that belongs to one. Or you can manually import them.
Syntax  | Effect
:---    | :---
`Install-Module -Name Az -AllowClobber` | Install the __Az__ module
`Import-Module SmbShare`|import module {SmbShare}
### Profiles
Syntax  | Effect
:---    | :---
`$profile`|display file of current profile
`$profile.CurrentUserCurrentHost`| C:\Users\Michael\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
`$profile.CurrentUserAllHosts`|C:\Users\Michael\Documents\WindowsPowerShell\profile.ps1
`$profile.AllUsersAllHosts`|C:\Windows\System32\WindowsPowerShell\v1.0\profile.ps1
`$profile.AllUsersCurrentHost`|C:\Windows\System32\WindowsPowerShell\v1.0\Microsoft.PowerShell_profile.ps1
## Remote commands
Syntax  | Effect
:---    | :---
`Enable-PSRemoting`| allow remote PowerShell management
`Invoke-Command -ComputerName core01,core02 -Scriptblock {ipconfig /all}`|execute the commands in the block on the machines specified
`New-PSSession -ComputerName core02`|start a new PowerShell session, connecting to the specified computer
`Get-PSSession`|display PowerShell sessions
`Enter-PSSession -id 1`|interact with the specified PowerShell session
`Exit-PSSession -ComputerName demodc`|end the PowerShell session with the specified computer
`Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey`|start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.
## Hyper-V
#### Install Hyper-V from PowerShell command-line
```powershell
Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart
```
#### Disable dynamic memory on a virtual host (nested virtualization)
```powershell
Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false
```
#### Configure 2 virtual processors on a virtual host (nested virtualization)
```powershell
Set-VMProcessor -VMName SVR01 -Count 2
```
#### Turn on MAC address spoofing on a virtual host (nested virtualization)
```powershell
Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On
```
## Other commands
#### Display options available in the module
```powershell
Get-PSReadlineOption
```
#### Set history to only save unique commands
```powershell
Set-PSReadlineOption -HistoryNoDuplicates:$true
```
#### Enable bash-like ambiguous command completion, where tab brings up a menu of matches
```powershell
Set-PSReadlineOption -EditMode Emacs
```
#### Change &lt;Tab&gt; behavior back to default for PowerShell
```powershell
Set-PSReadlineOption -EditMode Windows
```
#### View system uptime
```powershell
Get-WmiObject -Win32_OperatingSystem -ComputerName localhost |
Select-Object -Property @{n="Last Boot Time";e={[Management.ManagementDateTimeConvert]::ToDateTime($_.LastBootUpTime)}}
```
#### Build a credential
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
### Clipboard
#### Copy text to clipboard
```powershell
Write-Output 'Hello' | Set-Clipboard
```
With `Append` switch parameter, items can be added without clearing the clipboard:
```powershell
Write-Output 'Hello' | Set-Clipboard -Append
```
#### Interrogate items in clipboard
Interpret items in clipboard as files
```powershell
Get-Clipboard -Format FileDropList
```
Retrieve various properties of an image in clipboard
```powershell
Get-Clipboard -Format Image
```

## Desired State Configuration (DSC) syntax

Syntax                                            | Effect
:---                                              | :---
Configuration                                     | precedes title of script, at top (e.g. `Configuration ContosoSimple`)
Ensure                                            | property within `WindowsFeature` that can be set to `Present` or `Absent` (e.g. `Ensure = "Present"`)
WindowsFeature                                    | declares code block representing a DSC resource to be installed (e.g. `WindowsFeature IIS`)

## Errors
The `Throw` keyword generates a temrinating error

## Glossary

Term | Definition | Source
:--- | :---       | :---
automatic variables | variables that store state information for PowerShell and are created and maintained by Powershell. | 14

## Sources
  1. Berkouwer, Sander. _Active Directory Administration Cookbook_. [ADAC](../sources/adac.md).
  2. Krause, Jordan. _Windows Server 2016 Administration Cookbook_. [WSAC](../sources/wsac.md).
  3. Michael Washam, Jonathan Tuliani, and Scott Hoag. _Exam Ref AZ-103 Microsoft Azure Administrator_. [AZ-103](../sources/az-103.md)
  4. "How to use Wget to download web-based packages on Windows." [TechRepublic](https://www.techrepublic.com/article/how-to-use-wget-to-download-web-based-packages-on-windows/#ftag=RSS56d97e7): 2019/06/26.
  5. "Check PowerShell Version". [powertheshell.com](http://www.powertheshell.com/topic/learnpowershell/firststeps/psversion/)
  6. "About Comparison Operators". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-6): 2019/01/17.
  7. "PowerShell equivalents for common Linux/bash commands". [TheShellNut](https://mathieubuisson.github.io/powershell-linux-bash/): 2015/09/30.
  8. "About Functions". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_functions?view=powershell-6): 2019/02/26.
  9. "Select-Object". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/select-object?view=powershell-6)
  10. "About CommonParameters". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_commonparameters?view=powershell-6): 2019/05/27.
  11. "About Parameters Default Values". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_parameters_default_values?view=powershell-6): 2019/05/30.
  12. "What's in your PowerShell `$PSDefaultParameterValues` Preference Variable?". [mikefrobbins.com](https://mikefrobbins.com/2019/08/01/whats-in-your-powershell-psdefaultparametervalues-preference-variable/): 2019/08/01.
  13. "Using PowerShell to Copy to the Clipboard". [adamtheautomater.com](https://adamtheautomator.com/powershell-copy-to-clipboard/): 2019/08/01.
  14. "About Automatic Variables". [Microsoft Docs](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-6): 2019/02/26.