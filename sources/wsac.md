# Windows Server 2016 Administration Cookbook, Jordan Krause
> - [ ] 1. Learning the interface
> - [ ] 2. Core infrastructure tasks
> - [ ] 3. Internet Information Services
> - [ ] 4. Remote Desktop Services
> - [ ] 5. Monitoring and backup

## Chapter 1: Learning the interface
> - [x] 1.01 Shutting down or restarting the server
> - [x] 1.02 Launching Administrative Tools
> - [x] 1.03 Using the search function to launch applications quickly
> - [ ] 1.04 Managing remote servers from a single pane with Server Manager
> - [x] 1.05 Using PowerShell to accomplish any function in Windows Server
> - [ ] 1.06 Installing a role or feature
> - [ ] 1.07 Administering Server 2016 from a Windows 10 machine
> - [ ] 1.08 Identifying useful keyboard shortcuts in Server 2016
> - [ ] 1.09 Setting your PowerShell Execution Policy
> - [ ] 1.10 Building and executing your first PowerShell script
> - [ ] 1.11 Searching for PowerShell cmdlets with Get-Help

#### 1.01 Shutting down or restarting the server

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

#### 1.02 Launching Administrative Tools

Type  | Description | Source
:---  | :---        | :---
gui   | Server Manager > Tools | WSAC: 13
kb    | Win+x | WSAC: 15

#### 1.03 Using the search function to launch applications quickly

Type  | Description | Source
:---  | :---        | :---
gui   | Taskbar Search | WSAF: 17
kb    | Win | WSAF: 18

#### 1.04 Managing remote servers from a single pane with Server Manager

Type  | Description | Source
:---  | :---        | :---

#### 1.05 Using PowerShell to accomplish any function in Windows Server
#### 1.06 Installing a role or feature

Type  | Description | Source
:---  | :---        | :---
gui   | Server Manager > Add roles and features

#### 1.07 Administering Server 2016 from a Windows 10 machine
#### 1.08 Identifying useful keyboard shortcuts in Server 2016
#### 1.09 Setting your PowerShell Execution Policy
#### 1.10 Building and executing your first PowerShell script
#### 1.11 Searching for PowerShell cmdlets with Get-Help

## Chapter 2: Core Infrastructure Tasks
> - [x] 2.01 Configuring a combination Domain Controller, DNS server, and DHCP server
> - [ ] 2.02 Adding a second Domain Controller
> - [ ] 2.03 Organizing your computers with Organizational Units
> - [ ] 2.04 Creating an A or AAAA record in DNS
> - [ ] 2.05 Creating and using a CNAME record in DNS
> - [ ] 2.06 Creating a DHCP scope to assign addresses to computers
> - [ ] 2.07 Creating a DHCP reservation for a specific server or resource
> - [x] 2.08 Pre-staging a computer account in Active Driectory
> - [ ] 2.09 Using PowerShell to create a new Active Directory user
> - [x] 2.10 Using PowerShell to view system uptime

#### 2.01 Configuring a combination Domain Controller, DNS server, and DHCP server

  1. Open __Server Manager__ and add new roles to be installed on the server: __Active Directory Domain Services__, __DHCP Server__, __DNS Server__
  2. Click on __Active Directory Domain Services__. When prompted to __Add Features__, do so.
  3. Click __Next__ through the next few screens, then __Install__
  4. Upon successful installation of the roles and features, the progress summary screen displays two links, including one that reads "Promote this server to a domain controller". Click it to promote the machine to DC.
  5. Select "Add a new forest", entering a valid fully-qualified domain name
  6. On the __Domain Controller Options__ screen, specify a DSRM password in case needed for Safe Mode recovery. 
  7. __NetBIOS__ and __Paths__ values can be left as default.
  8. The warnings and information messages on the __Review__ screen can be ignored, so long as the green check mark and the message "All prerequisite checks passed successfully'. Click __Install__.
  9. Restart.
  10. Upon restart, within Server Manager a notification will appear to __Complete DHCP configuration__. 
  11. Clicking through these steps is all that is needed.

#### 2.02 Adding a second Domain Controller
#### 2.03 Organizing your computers with Organizational Units
#### 2.04 Creating an A or AAAA record in DNS
#### 2.05 Creating and using a CNAME record in DNS
#### 2.06 Creating a DHCP scope to assign addresses to computers
#### 2.07 Creating a DHCP reservation for a specific server or resource
#### 2.08 Pre-staging a computer account in Active Driectory
Servers can sometimes be broken because they are immediately placed into the __Computers__ container upon joining a domain, but sometimes rules applied to this container can inadvertently break a new server (for example, by disabling Windows Firewall). __Pre-staging__ a server will make sure it joins the domain in the correct location.
  1. On a DC, open __Active Directory Users and Computers__
  2. Choose a location in which to place the computer, e.g. create a new OU.
  3. Right-click on the location and select __New__ > __Computer__ in the context menu.
  4. In the dialog box that appears, enter the name of the new server.
  5. Click __OK__
  6. Join the server with the matching name to the name, and it will be placed into the specified location.

#### 2.09 Using PowerShell to create a new Active Directory user
#### 2.10 Using PowerShell to view system uptime
```powershell
Get-WmiObject -Win32_OperatingSystem -ComputerName localhost |
Select-Object -Property @{n="Last Boot Time";e={[Management.ManagementDateTimeConvert]::ToDateTime($_.LastBootUpTime)}}
```

## Chapter 3: Internet Information Services
> - [x] 3.1 Installing the Web Server role with PowerShell
> - [ ] 3.2 Launching your first website
> - [ ] 3.3 Changing the port on which your website runs
> - [ ] 3.4 Adding encryption to your website
> - [ ] 3.5 Using a Certificate Signing Request to acquire your SSL certificate
> - [ ] 3.6 Moving an SSL certificate from one server to another
> - [ ] 3.7 Rebinding your renewed certificates automatically
> - [ ] 3.8 Hosting multiple websites on your IIS server
> - [ ] 3.9 Using host headers to manage multiple websites on a single IP address

#### 3.1 Installing the Web Server role with PowerShell
Display a branching view of available Windows roles, role services, and features
```powershell
Get-WindowsFeature
```
Install Web Server
```powershell
Install-WindowsFeature Web-Server,Web-Common-Http,Web-Mgmt-Console -Restart
```

#### 3.2 Launching your first website
#### 3.3 Changing the port on which your website runs
#### 3.4 Adding encryption to your website
#### 3.5 Using a Certificate Signing Request to acquire your SSL certificate
#### 3.6 Moving an SSL certificate from one server to another
#### 3.7 Rebinding your renewed certificates automatically
#### 3.8 Hosting multiple websites on your IIS server
#### 3.9 Using host headers to manage multiple websites on a single IP address
## Chapter 4: Remote Desktop Services
#### 4.1 Building a single server Remote Desktop Services environment
#### 4.2 Adding an additional RDSH server to your RDS environment
#### 4.3 Installing applications on a REmote Desktop Session Host server
#### 4.4 Disabling the redirection of local resources
#### 4.5 Shadowing another session in RDS
#### 4.6 Installing a printer driver to use with redirection
#### 4.7 Removing an RD Session Host server from use for maintenance
#### 4.8 Publishing WordPad with RemoteApp
#### 4.9 Tracking user logins with Logon/Logoff scripts
## Chapter 5: Monitoring and backup
#### 5.1 Using Server Manager as a quick monitoring tool
#### 5.2 Using the new Task Manager to its full potential
#### 5.3 Evaluating system performance with Windows Performance Monitor
#### 5.4 Using Format-List to modify PowerShell data output
#### 5.5 Configuring a full system backup using Windows Server Backup
#### 5.6 Recovering data from a Windows backup file
#### 5.7 Using IP Address MAnagement to keep track of your used IP addresses
#### 5.8 Checking for viruses in Windows Server 2016
## Chapter 6: Group Policy
#### 6.01 Creating and assigning a new Group Policy Object
#### 6.02 Mapping network drives with Group Policy
#### 6.03 Redirecting the My Documents folder to a network share
#### 6.04 Creating a VPN connection with Group Policy
#### 6.05 Creating a printer connection with Group Policy
#### 6.06 Using Group Policy to enforce an Internet proxy server
#### 6.07 Viewing the settings currently enabled inside a GPO
#### 6.08 Viewing the GPOs currently assigned to a computer]
#### 6.09 Backing up and restoring GPOs
#### 6.10 Plugging in ADMX and ADML templates 