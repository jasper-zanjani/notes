# Learning PowerShell

## Understanding important PowerShell concepts 
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/understanding-important-powershell-concepts?view=powershell-6)
  - __Output is object-based__: output of commands is not merely the text displayed on screen
  - __Commands are extensible__: custom-made tools can be integrated into Help; native PowerShell commands are called _cmdlets_ ("command-lets")
  - __PowerShell handles console input and display__: common parameters like `-?` are handled automatically
  - __PowerShell uses some C# syntax__

## Learning PowerShell command names] 
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/learning-powershell-names?view=powershell-6)
PowerShell cmdlets use __verb-noun names__ and __standard parameters__ to reduce the difficulty of memorizing commands, which is the main barrier to entry for other shell environments. PowerShell also offers explicit guidance on __recommended parameter names__.
##### Common parameters
In particular the `-?` parameter on any cmdlet will display help for it, and will the cmdlet will not execute.
  - `WhatIf`
  - `Confirm`
  - `Verbose`
  - `Debug`
  - `Warn`
  - `ErrorAction`
  - `ErrorVariable`
  - `OutVariable`
  - `OutBuffer`

## Using familiar command names
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/using-familiar-command-names?view=powershell-6)
Common Unix and Command Prompt commands have __aliases__ built into PowerShell.  Additionally common nouns and verbs are also aliased:
Abbreviation | Noun or Verb
:--- | :---
`g`|`Get`
`s`|`Set`
`i`|`Item`
`l`|`Location`
`cm`|`Command`
`al`|`Alias`

Alias | Full command
:---|:---
`gi`|`Get-Item`
`si`|`Set-Item`
`gl`|`Get-Location`
`sl`|`Set-Location`
`gcm`|`Get-Command`
`gal`|`Get-Alias`

New aliases can be created with `Set-Alias` command
```powershell
Set-Alias -Name gi -Value Get-Item
```

## Getting detailed help information
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/getting-detailed-help-information?view=powershell-6)
The `Get-Help` cmdlet can be used to get help on a command, or the `-?` parameter
```powershell
Get-Help Get-ChildItem
Get-ChildItem -?
```
To display one page of each Help article at a time, use the `help` function or its alias `man`
```powershell
man Get-ChildItem
help Get-ChildItem
```
Various options can be used to modify the output of `Get-Help`
Option|Effect
:---|:---
`-Detailed`|display detailed information
`-Full`|display all content in the Help article
`-Parameter *`|display information on all parameters
`-Examples`|display usage examples

```powershell
Get-Help Get-ChildItem -Detailed
Get-Help Get-ChildItem -Full
Get-Help Get-ChildItem -Parameter *
Get-Help Get-ChildItem -Examples
```

## Getting information about commands
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/getting-information-about-commands?view=powershell-6)
`Get-Command` |displays commands that are available in the current session

Option|Effect
:---|:---
`*`|get all commands in the session
`-CommandType Alias`|display command aliases
`-CommandType Function`|display functions
`-CommandType Script`|display scripts in PowerShell's search path

## Using variables to store objects
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/using-variables-to-store-objects?view=powershell-6)
Variables are dereferenced by preceding the identifier with `$`, just as in other shells. Environment variables, available in a drive named `env:` do not work with the standard `*-Variable` cmdlets.

Syntax|Effect
:---  |:---
`$loc`| Declare a variable
`$loc = Get-Location`|Assign a value to a variable
`$loc | Get-Member -MemberType Property`| Display information about the contents of a variable 
`Get-Command -Noun Variable | Format-Table -Property Name,Definition -AutoSize -Wrap`| See a complete listing of commands to manipulate variables
`Remove-Variable -Name * -Force -ErrorAction SilentlyContinue`| Remove variables
`Get-Variable`|Display PowerShell system variables
`env:SystemRoot`|display the value of the `%SystemRoot%` environment variable
`env:LIB_PATH='/usr/local/lib'`|environment variables have to be prefixed with `env:` when being assigned new values

## Understanding the PowerShell pipeline
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/understanding-the-powershell-pipeline?view=powershell-6)
Because output is actually an object, piping ("pipelining") is more intuitive than in  other shells.
Syntax|Effect
:---  |:---
`Get-ChildItem -Path C:\WINDOWS\System32 \| Out-Host -Paging`|force a page-by-page display of output from another command

## More PowerShell learning
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/more-powershell-learning?view=powershell-6)

## Writing portable modules
- Source: [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/writing-portable-modules?view=powershell-6)

## PowerShell remoting
  - Running remote commands [md](https://docs.microsoft.com/en-us/powershell/scripting/learn/remoting/running-remote-commands?view=powershell-6)
  - PowerShell remoting over SSH
  - WS-Management (`WSMan`) remoting in PowerShell Core
  - WinRM Security
  - Making the second hop in PowerShell remoting
