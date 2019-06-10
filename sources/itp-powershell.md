# PowerShell course on [ITProTV](https://app.itpro.tv/course-library/powershell-2017/2017/)

## Getting Started
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017/)
##### History
  - 1.0 (2006) for XP, Vista, and Server 2003
  - 2.0 (2009) when it shipped pre-installed with Windows 7, Windows Server 2008, and was also downloadable for XP, Vista, Server 2003.
    - __Integrated Scripting Environment (ISE)__
  - 3.0 (2012) preinstalled with Windows 8, Server 2012, and also made available for Windows 7, Server 2008
    - online help system
    - IntelliSense for PowerShell ISE
  - 4.0 (2013)
    - Enhanced script security and debugging
  - 5.0 (2016)
    - Support for Chocolatey's repo-based package management
    - Extended support for (Layer 2) switch management
##### ISE and IntelliSense
##### Active Directory
Active Directory Administrative Center (which has taken over from the older Users and Computers), is actually executing PowerShell commands in the background

## Basic Syntax and Help
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-basic-syntaxhelp/)
Commands are known as __cmdlets__, organized in __modules__, typically a set of interrelated cmdlets. Cmdlets follow the format "Verb-Noun", where there are hundreds of nouns but only a few verbs. Modules used to have to be imported into a session before they can be used, but since 5.0 PowerShell will track down the module a typed command needs and will load it automatically. Modules can be included into profiles so that they can be loaded when the session starts as well.

Syntax|Effect
:---|:---
`Get-Module`|display loaded PowerShell modules
`Get-Module -ListAvailable`|display installed PowerShell modules
`Import-Module SmbShare`|import module <SmbShare>
`Get-Command | measure` | piping to `measure` is similar to `wc`, will count lines

## Basic Syntax and Help, Part 2
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-basic-syntaxhelp2/)

Syntax|Effect
:---|:---
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

## Command History and Aliases
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-command-historyaliases/)
PowerShell now maintains a history of inputted commands, enabled by the `PSReadline` module.  The maximum number of commands remembered and the location of the file where it is stored can be found in the output of `Get-PSReadlineOption`. 

Keyboard shortcut|Effect
:---|:---
F8| search the history for comands that __begin__ with the currently typed in letters
Ctrl-r| search history __backward__ for commands that match the currently typed in string anywhere
Ctrl-s| search history __forward__ for commands that match the currently typed in string anywhere

Syntax|Effect
:---|:---
`Get-History`|display history of inputted commands for the current session
`Invoke-History`|run a command from the history
`Get-PSReadlineOption`|display options available in the module
`Set-PSReadlineOption -HistoryNoDuplicates:$true`|set history to only save unique commands
`Set-PSReadlineOption -EditMode Emacs`|enable bash-like functionality where an incomplete command followed by <Tab> will produce a list of all matching commands
`Set-PSReadlineOption -EditMode Windows`|change <Tab> behavior back to default for PowerShell

## Command History and Aliases, part 2
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-command-historyaliases2/)
- Topics: Aliases

Syntax|Effect
:---  |:---
`Get-Process`|display running processes
`Clear-Host`|clear screen
`Get-Services`|display services
`Get-Alias`|display services
`Get-Alias -Definition -Get-ChildItem`|display items that point to `-Get-ChildItem`
`Get-IPAddress`|display IP configuration
`New-Alias ip Get-NetIPAddress`|establish a new alias
`Set-Alias ip Get-NetAdapter`|edit an existing alias
`Export-Alias -Path alias.ps1 -As Script`|export session aliases to a ".ps1" file

## Piping and Formatting
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-pipingformatting/)
The output of the previous command is stored in the variable `$_`; this is the mechanism that drives pipelining
Three main format options:
  1. __Format-Table__: default output format of commands like `Get-Service`
  2. __Format-List__
  3. __Format-Wide__

Syntax|Effect
:---  |:---
`Get-Service \| Sort-Object` | sort list of services
`Get-Serivce \| Write-Host` | will produce an error because `Write-Host` expects a single object
`Get-Service \| ForEach-Object {Write-Host $_.name}`| loop through each object in output of `Get-Service` and send the `name` field to `Write-Host`
`Get-Service \| Format-Wide` | change output format to `Format-Wide`
`Get-Service \| Format-Wide -Column 1` | change output format to be a single column
`Get-Service \| Format-Wide -Property DisplayName` | change output to display the `DisplayName` property
`Get-Service \| Format-List` | display output as a list with properties listed next to values
`Get-Service \| Format-List -Property *` | display all properties
`Get-Service \| fl -Property Status,StartType,DisplayName` | display only specified properties

## Piping and Formatting, part 2
- Soruce: [itp](https://app.itpro.tv/course-library/powershell-2017/2017-pipingformatting2/)
PowerShell will prioritize fields specified for output in the order indicated, such that the fields that come first are considered more important than later ones. If the last columna can't fit, it will be truncated.

Syntax|Effect
:---  |:---
`Get-Service \| Format-Table -Property *`|display all properties
`Get-Service \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status`, but the output will be confused because it was not sorted
`Get-Service \| Sort-Object -Property Status \| Format-Table -Property DisplayName,StartType,Status -GrouptBy Status`|group by `Status` after sorting

## Script Execution Policy
## Script Execution Policy, part 2

## Drives
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/power-shell-drives/)
PowerShell can treat not only filesystems as drives, but also Registry keys, as drives

Syntax|Effect
:---  |:---
`Get-PSDrive`|display mapped drives
`Set-Location`|change the present working directory (`cd` is an alias)
`New-PSDrive -Name scripts -PSProvider FileSystem -Root "C:\Scripts"`|map a directory to a drive
`Remove-PSDrive -Name scripts`|remove a drive

## Profiles
- Source: [itp](https://app.itpro.tv/course-library/powershell-2017/profiles/)
Edit appearance and behavior in Properties. 
Customizing profiles based on host can also be done with conditional statements.
```powershell
if ($host.Name -eq 'ConsoleHost')
{
# some commands
}
elseif ($host.Name -like '*ISE Host')
{
# other commands
}
```

Syntax|Effect
:---  |:---
`$profile`|display file of current profile
`$profile.CurrentUserCurrentHost`| C:\Users\Michael\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
`$profile.CurrentUserAllHosts`|C:\Users\Michael\Documents\WindowsPowerShell\profile.ps1
`$profile.AllUsersAllHosts`|C:\Windows\System32\WindowsPowerShell\v1.0\profile.ps1
`$profile.AllUsersCurrentHost`|C:\Windows\System32\WindowsPowerShell\v1.0\Microsoft.PowerShell_profile.ps1

