# Windows Server 2016 Administration Cookbook, Jordan Krause

## Learning the interface

##### Shutting down or restarting the server

Type  | Description | Source
:---  | :---        | :---
gui   | Start > Power > Shut down | WSAC: 10
gui   | Start > Power > Restart | WSAC: 10
gui   | Start (right-click) > Shut down or sign out > Shut down 
gui   | Start (right-click) > Shut down or sign out > Restart | WSAC: 11
cmd   | `shutdown /s /t 0`  | WSAC: 11
cmd   | `shutdown /r /t 0`  | WSAC: 11
ps    | `Stop-Computer`     | [Link](https://www.computerperformance.co.uk/powershell/stop-computer/)
ps    | `Restart-Computer`  | [Link](https://www.computerperformance.co.uk/powershell/stop-computer/)

##### Launching Administrative Tools

Type  | Description | Source
:---  | :---        | :---
gui   | Server Manager > Tools | WSAC: 13
kb    | Win+x | WSAC: 15

##### Using the search function to launch applications quickly

Type  | Description | Source
:---  | :---        | :---
gui   | Taskbar Search | WSAF: 17
kb    | Win | WSAF: 18

##### Managing remote servers from a single pane with Server Manager

Type  | Description | Source
:---  | :---        | :---

##### Using PowerShell to accomplish any function in Windows Server
##### Installing a role or feature

Type  | Description | Source
:---  | :---        | :---
gui   | Server Manager > Add roles and features

##### Administering Server 2016 from a Windows 10 machine
##### Identifying useful keyboard shortcuts in Server 2016
##### Setting your PowerShell Execution Policy
##### Building and executing your first PowerShell script
##### Searching for PowerShell cmdlets with Get-Help

## Core Infrastructure Tasks

##### Configuring a combination Domain Controller, DNS server, and DHCP server

  1. Install __Active Directory Domain Services__, __DHCP Server__, and __DNS Server__
  2. Click "Promote this server to a domain controller"
  3. Select "Add a new forest", entering a vlaid fully-qualified domain name
  4. 
##### Adding a second Domain Controller

