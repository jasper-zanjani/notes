# Windows Server 2016 Administration Cookbook, Jordan Krause

## Chapter 1: Learning the interface

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

## Chapter 2: Core Infrastructure Tasks

##### Configuring a combination Domain Controller, DNS server, and DHCP server

  1. Install __Active Directory Domain Services__, __DHCP Server__, and __DNS Server__
  2. Click "Promote this server to a domain controller"
  3. Select "Add a new forest", entering a vlaid fully-qualified domain name
  4. 
##### Adding a second Domain Controller

##### Organizing your computers with Organizational Units
##### Creating an A or AAAA record in DNS
##### Creating and using a CNAME record in DNS
##### Creating a DHCP scope to assign addresses to computers
##### Creating a DHCP reservation for a specific server or resource
##### Pre-staging a computer account in Active Driectory
##### Using PowerShell to create a new Active Directory user
##### Using PowerShell to view system uptime

## Chapter 3: Internet Information Services
##### Installing the Web Server role with PowerShell
##### Launching your first website
##### Changing the port on which your website runs
##### Adding encryption to your website
##### Using a Certificate Signing Request to acquire your SSL certificate
##### Moving an SSL certificate from one server to another
##### Rebinding your renewed certificates automatically
##### Hosting multiple websites on your IIS server
##### Using host headers to manage multiple websites on a single IP address


## Chapter 4: Remote Desktop Services
##### Building a single server Remote Desktop Services environment
##### Adding an additional RDSH server to your RDS environment
##### Installing applications on a REmote Desktop Session Host server
##### Disabling the redirection of local resources
##### Shadowing another session in RDS
##### Installing a printer driver to use with redirection
##### Removing an RD Session Host server from use for maintenance
##### Publishing WordPad with RemoteApp
##### Tracking user logins with Logon/Logoff scripts

## Chapter 5: Monitoring and backup
##### Using Server Manager as a quick monitoring tool
##### Using the new Task Manager to its full potential
##### Evaluating system performance with Windows Performance Monitor
##### Using Format-List to modify PowerShell data output
##### Configuring a full system backup using Windows Server Backup
##### Recovering data from a Windows backup file
##### Using IP Address MAnagement to keep track of your used IP addresses
##### Checking for viruses in Windows Server 2016

## Chapter 6: Group Policy
##### Creating and assigning a new Group Policy Object
##### Mapping network drives with Group Policy
##### Redirecting the My Documents folder to a network share
##### Creating a VPN connection with Group Policy
##### Creating a printer connection with Group Policy
##### Using Group Policy to enforce an Internet proxy server
##### Viewing the settings currently enabled inside a GPO
##### Viewing the GPOs currently assigned to a computer]
##### Backing up and restoring GPOs
##### Plugging in ADMX and ADML templates