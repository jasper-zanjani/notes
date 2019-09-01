# PowerShell commands for Active Directory
#### Create a domain controller
```powershell
Install-WindowsFeature AD-Domain-Services -IncludeManagementTools
Import-Module ADDSDeployment
```
3 cmdlets available for 3 different scenarios:\
Syntax                          | Effect
:---                            | :---
`Install-ADDSForest`            | Add a new forest
`Install-ADDSDomain`            | Add a domain to an existing forest
`Install-ADDSDomainController`  | Add a domain controller to an existing domain
#### Add a new forest
```powershell
# This will prompt for safe mode administrator password
Install-ADDSForest -DomainName example.com -InstallDNS
```
If the system fails to automatically create a NetBIOS name, it can be manually specified with the named parameter `-DomainNetbiosName`
#### Display installed forests
```powershell
Get-ADForest | select -ExpandProperty domains
```
#### Add a new domain
`Install-ADDSDomain` only requires the following two parameters:
  - `-NewDomainName` if the value set for `-DomainType` is set to `ChildDomain` (which it is by default), a single label domain name can be used.
  - `ParentDomainName` the name of an existing parent domain
```powershell
Install-ADDSDomain -NewDomainName hq -ParentDomainName pythagoras.net
```
```powershell
Install-ADDSDomain -Credential (Get-Credential CORP\EnterpriseAdmin1) -NewDomainName child -ParentDomainName corp.contoso.com -InstallDNS -CreateDNSDelegation -DomainMode Win2003 -ReplicationSourceDC DC1.corp.contoso.com -SiteName Houston -DatabasePath "D:\NTDS" -SYSVOLPath "D:\SYSVOL" -LogPath "E:\Logs" -NoRebootOnCompletion
```
#### Demote a domain controller
Demotion of a DC is consummate with uninstalling the AD Domain Controller role.
```powershell
# When removing the last domain controller of a domain, additional options need to be specified that result in the obliteration of the domain, its forest, and associated data.
Uninstall-ADDSDomainController -LocalAdministratorPassword (ConvertTo-SecureString $pw -AsPlainText -Force) -LastDomainControllerInDomain -RemoveApplicationPartitions
```
#### Join a new computer to a domain
[[1](#sources)]
```powershell
Add-Computer -Domain 'officeprodemoco.onmicrosoft.com' -Restart
New-ADComputer -Name "O365-CL93"

# Joining many computers using a .csv file
New-ADComputer -Name "O365-CL93"
$List = "C:\Labfiles\computers.csv"
$OU = "OU=office365,DC=officeprodemoco,DC=onmicrosoft,DC=com"
Import-Csv -path $List | ForEach-Object {New-ADComputer -Name $_.Name -Path $OU}
```
#### Verify a computer has connected to a domain
Check "Organization" in Windows about page, or navigate to Control PAnel > System and Security > System and examine the **Computer name, domain, and workgroup settings**, where the domain can be seen.
#### Create a new user (disabled by default)
```powershell
New-ADUser -Name "Walter Mitty"

# Users are disabled by default, so you must enable them by setting the `-Enabled` switch parameter:
New-ADUser -Name "Marty McFly" -Enabled $true -GivenName "Martin" -Surname "McFly" -AccountPassword ( ConvertTo-SecureString "P@ssw0rd!" -AsPlainText -Force) 
```
#### Unlock account
```powershell
Unlock-ADAccount -identity wbryan
```
#### Reset password
```powershell
Set-ADAccountPassword -Identity MBentley -Reset -NewPassword (ConvertTo-SecureString `
  -AsPlainText "What is 255.255.255.240" -Force`)
```
#### Create a new Organizational Unit
```powershell
New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey
```
#### Remove accidental deletion protection
```powershell
Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False `
  -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" 
```
#### Remove an OU
```powershell
Remove-ADOrganizationalUnit `
  -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False
```
#### Display OUs, confirming deletion has taken place
```powershell
Get-ADOrganizationalUnit  -filter * | ft
```
#### Display information for Active Directory user {mike}
```powershell
Get-ADUser -Identity mike
```
#### Display Protection from Accidental Deletion
```powershell
Get-ADUser -Filter *  -Properties ProtectedFromAccidentalDeletion
  -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  `
```
#### Protect users in a specified OU from accidental deletion
```powershell
Get-ADUser -Filter * `
  -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" ` | 
Set-ADObject -ProtectedFromAccidentalDeletion $true
```
#### Display information on user, confirming successful creation
```powershell
Get-ADUser "Marty McFly" | Select-Object Name
```
#### Add a CSV full of users
```powershell
import-csv users.csv | 
foreach { New-ADUser `
  -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName `
  -Name $_.Name -Description $_.Description -Enabled $True `
  -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) }
``` 
#### Display installable Windows roles, role services, and features
Display a branching view of available Windows roles, role services, and features
```powershell
Get-WindowsFeature
```
#### Install Web Server
Install Web Server
```powershell
Install-WindowsFeature Web-Server,Web-Common-Http,Web-Mgmt-Console -Restart
```
### Search-ADAccount
Option                    | Effect
:---                      | :---
AccountDisabled           | filter disabled accounts
AccountExpired            | filter expired accounts
ComputersOnly             | filter computer accounts
LockedOut                 | filter locked out accounts
PasswordExpired           | filter accounts with expired passwords
PasswordNeverExpires      | filter accounts with passwords that will never expire
UsersOnly                 | filter users
#### Display accounts that have been inactive for the last 90 days
```powershell
Search-ADAccount -AccountInactive -TimeSpan 90.00:00:00
```
#### Display accounts expiring on a particular date
```powershell
Search-ADAccount -AccountExpiring -DateTime "3/18/2019"
``` 
## Commands



## Sources
  1. "Managing AD Computer Accounts Part 2". _Windows Server 101_. [ITPro.TV](../sources/README.md)