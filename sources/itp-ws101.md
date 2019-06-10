# Windows Server 101

## Active Directory Basic Administration
- Source: [itp](https://app.itpro.tv/course-library/server-101/active-directory-basic-administration-server101/)

Term|Abbreviation|Definition
---|---|---
domain||an administrative boundary for Active Directory (usually symbolized by a triangle)
forest||security boundary for Active Directory

Not many people are meant to be able to log into a Domain Controller: only domain admins. Make sure __Remote Management__ is __Enabled__ in Server Manager. The easiest way to administer remotely is via PowerShell, but RSAT is an alternative that is based on GUI. Best practice is to configure a server and then leave it alone, and this is especially recommended with the Domain Controller since it is a critical piece of infrastructure. Remotely logging in with Remote Desktop is also good because it prevents multiple connections at the same time (Remote Desktop has a maximum of 2 concurrent connections). Remote management is strongly recommended because of the need to maintain a small attack surface for this critical server.

PowerShell|Effect
---|---
`winrm get winrm/config`|display WinRM configuration
`Enter-PSSession -ComputerName o365-dc01 -Credential officeprodemoco\joey`|start and enter a new PS session to specified computer with provided credentials. This will change the prompt to show the name of the remote machine in brackets.

## Active Directory Basic Administration, part 2
- Source: [itp](https://app.itpro.tv/course-library/server-101/active-directory-basic-administration2/)

__Organizational Units (OU)__ are not about categorization but about __administrative delegation__. By default, new OUs are protected from accidental deletion through AD Users and Computers

PowerShell|Effect
---|---
`Install-WindowsFeature -Name RSAT-ADDS -IncludeAllSubFeature`|Install Remote Server Adminstration Tools for PowerShell
`New-ADOrganizationalUnit -Name GNV -Credential officeprodemoco\joey`|Create a new Organizational Unit
`Set-ADOrganizationalUnit -Name GNV -ProtectedFromAccidentalDeletion $False -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" `| remove accidental deletion protection
`Remove-ADOrganizationalUnit -Identity "OU=GNV, DC=officeprodemoco, DC=onmicrosoft, DC=com" -confirm:$False`|remove an OU
`Get-ADOrganizationalUnit -filter * \| FT`|display OUs, confirming deletion has taken place

## Create User Accounts
- Source: [itp](https://app.itpro.tv/course-library/server-101/create-user-accounts-server101/)
New users can be added through the GUI in AD Users and Computers. Remember to Run as Administrator only when doing work that requires those privileges to reduce the attack surface.

PowerShell|Effect
---|---
`New-ADUser -Name "Walter Mitty"`|create a new user (disabled by default)
`New-ADUser -Name "Marty McFly" -AccountPassword (ConvertTo-SecureString "P@ssw0rd!" -AsPlainText -Force) -Enabled $true -GivenName "Martin" -Surname "McFly"`|create a new user
`Get-ADUser "Marty McFly" \| Select-Object Name`|display information on user, confirming successful creation
`import-csv users.csv \| foreach {New-ADUser -SamAccountName $_.SAM -GivenName $_.Last -DisplayName $_.DisplayName -Name $_.Name -Description $_.Description -AccountPassword (ConvertToSecureString $_.Password -AsPlainText -Force) -Enabled $True}`|add a CSV full of users

## Create User Accounts, part 2
- Source: [itp](https://app.itpro.tv/course-library/server-101/create-user-accounts2/)

PowerShell|Effect
---|---
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com" \| Set-ADObject -ProtectedFromAccidentalDeletion $true`|protect users in a specified OU from accidental deletion
`Get-ADUser -Filter * -SearchBase "OU=RoadCrew,OU=office365,DC=officeprodemoco,DC=com,DC=onmicrosoft"  -Properties ProtectedFromAccidentalDeletion`|Display Protection from Accidental Deletion

## Managing User Accounts
- Source: [itp](https://app.itpro.tv/course-library/server-101/managing-user-accounts-server101/)

PowerShell|Effect
---|---
`Set-ADAccountPassword -identity MBentley -Reset -NewPassword (ConvertTo-SecureString -AsPlainText "What is 255.255.255.240" -Force)`|reset password
`Search-ADAccount -LockedOut`|display locked out accounts
`Unlock-ADAccount -identity wbryan`|unlock account
