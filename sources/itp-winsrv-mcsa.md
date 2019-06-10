# MCSA Windows Server 2016 - 70-740

## Overview
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/overview-server2016-70740/)

## Planning a server installation
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server-2012-70410-2017/planningserver-installation-mcsa70410/)
Editions for Windows Server 2012 R2 (ca. 2017):
  - __Datacenter__: up to 64 processors including fault-tolerance features with unlimited amount of virtual machines
  - __Standard__ (replacing __Enterprise__): for non-virtualized or lightly virtualized environments
  - __Essentials__: limited to 1 physical or virtual server; lacks Core, Hyper-V, and Active Directory Federation Services
  - __Foundation__: only basic server features, such as file and print services with no virtualization rights

## Server Management Options
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/rolesfeatures-mcsa/)
Various ways of managing servers:
  - GUI tools
    - Server Manager
    - MMC snapins
    - Windows Admin Center
    - RSAT
  - PowerShell
    - firewall rules
    - WinRM quickconfig
    - `Enable-PSRemoting`
  - Command-line
    - WinRS
    - `netsh` for firewall rules

When you install RSAT, you have access to MMC snap-ins. In order to enable remote management of a server, firewall rules have to be modified.

__WinRM__ is Microsoft's implementation of the __WS-Management Protocol__. Unlike MMCs, which are based on DCOM (legacy technology), WinRM is considered firewall-friendly and is the preferred option, especially since its `quickconfig` makes setting up remote management easier

MMC snap-in|Rule group
:---|:---
Event Viewer|Remote Event Log Management
Services|Remote Service Management
Shared Folders|File and Printer Sharing
Task Scheduler|Performance Logs and Alerts, File and Printer Sharing
Disk Management|Remote Volume Management
Windows Firewall and Advanced Security|Windows Firewall Remote Management

Abbreviation|Expansion|Description
:---|:---|:---
DCOM|Distributed Component Object Model|Microsoft technology for communication between software components on networked computers which provides the communication infrastructure for __Microsoft COM+__ application servers.
MMC|Microsoft Management Console|component of Windows that hosts __snap-ins__, allowing multiple management tools to be accessed from the same interface. An example component is __Computer Management__.
RPC|Remote Procedure Call|protocol that one program can use to request a service from a program located on another network host without having to navigate that network
RSAT|Remote Server Administration Tools
WinRS|Windows Remote Shell
WinRM|Windows Remote Management


File|Description
:---|:---
winrm.exe|WinRM
wf.msc|Windows Defender Firewall with Advanced Security

PowerShell command|Effect
:---|:---
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

## Server Management Options, part 2
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/rolesfeatures2-mcsa/)


## Server Management Options, part 3
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/server-management-options3/)

__Windows Admin Center__ is a web-based interface

PowerShell command|Effect
:---|:---
`New-PSSession -ComputerName core02`|start a new PowerShell session, connecting to the specified computer
`Get-PSSession`|display PowerShell sessions
`Enter-PSSession -id 1`|interact with the specified PowerShell session
`Exit-PSSession -ComputerName demodc`|end the PowerShell session with the specified computer

## Hyper-V
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/hyperv-70740/)
Server Manager > Hyper-V Manager

PowerShell command|Effect
:---|:---
`Install-WindowsFeature -Name Hyper-V -IncludeAllSubFeature -IncludeManagementTools -Restart`|install Hyper-V from PowerShell command-line

## Hyper-V, part 2
- Source: [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/hyperv2-70740/)

Migrating virtual machines during a Hyper-V upgrade
  - __Export VMs from Hyper-V Manager__: will produce a VHD or VHDX file, with associated files
  - __Hyper-V Replica__: take a copy of a running VM
  - __Share Nothing Live Migration__

Delegating VM management
  - Use lusrmgr.msc Local Users and Groups to add users to Hyper-V Administrators
  - azman.msc Authorization Manager

Nested virtualization (VM hosting a VM)
  - Physical machine and virtual host must be running Server 2016
  - Physical processor must be Intel supporting VT-x Extended Page Tables (EPT) virtualization support
  - Before installing Hyper-V on the VM, the virtual processor must be provided access to the physical VT
  - Virtual Hyper-V host configuration:
    - Disable dynamic memory
    - Configure 2 virtual processors
    - Turn on MAC spoofing

Abbreviation|Expansion
:---|:---
EPT|Extended Page Tables

File|Description
:---|:---
lusrmgr.msc|Local Users and Groups
azman.msc|Authorization Manager

PowerShell command|Effect
:---|:---
`Set-VMMemory -VMName SRV01 -DynamicMemoryEnabled $false`|disable dynamic memory on a virtual host (nested virtualization)
`Set-VMProcessor -VMName SVR01 -Count 2`| configure 2 virtual processors on a virtual host (nested virtualization)
`Set-VMNetworkAdapter -VMName SVR01 -Name "NetworkAdapter" -MACAddressSpoofing On`|turn on MAC address spoofing on a virtual host (nested virtualization)

## Manage VMs with PowerShell Direct, part 3
- Source [itp](https://app.itpro.tv/course-library/mcsa-windows-server2016-70740-update/manage-vmspowershell-direct/)


