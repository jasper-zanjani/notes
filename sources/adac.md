# Active Directory Administration Cookbook
> - [ ] 1. Optimizing Forests, Domains, and Trusts
> - [ ] 2. Managing Domain Controllers
> - [ ] 3. Managing Active Directory Roles and Features
> - [ ] 4. Managing Containers and Organizational Units
> - [ ] 5. Managing Active Directory Sites and Troubleshooting
> - [ ] 6. Managing Active Directory Users
> - [ ] 7. Managing Active Directory Groups
> - [ ] 8. Managing Active Directory Computers
> - [ ] 9. Getting the most out of Group Policy
> - [ ] 10. Securing Active Directory
> - [ ] 11. Managing Federation
> - [ ] 12. Handling Authentication in a Hybrid World (AD FS, PHS, PTA, and 3SO)
> - [ ] 13. Handling Synchronization in a Hybrid World (Azure AD Connect)
> - [ ] 14. Hardening Azure AD



## 1. Optimizing Forests, Domains, and Trusts
> - [x] 1.01 Choosing between a new domain or forest
> - [x] 1.02 Listing the domains in your forest
> - [ ] 1.03 Using adprep.exe to prepare for new Active Directory functionality
> - [ ] 1.04 Raising the domain functional level to Windows Server 2016
> - [ ] 1.05 Raising the forest functional level to Windows Server 2016
> - [ ] 1.06 Creating the right trust
> - [ ] 1.07 Verifying and resetting a trust
> - [ ] 1.08 Securing a trust
> - [ ] 1.09 Extending the schema
> - [ ] 1.10 Enabling the Active Directory Recycle Bin
> - [ ] 1.11 Managing UPN suffixes

#### 1.01 Choosing between a new domain or forest
#### 1.02 Listing the domains in your forest
This task requires the __Active Directory module__ for PowerShell to be installed.
```powershell
Install-WindowsFeature RSAT-AD-PowerShell -IncludeManagementTools
```

`Get-ADForest` is the command used to display forests:
```powershell
Get-ADForest | select -ExpandProperty domains
```

#### 1.03 Using adprep.exe to prepare for new Active Directory functionality
#### 1.04 Raising the domain functional level to Windows Server 2016
#### 1.05 Raising the forest functional level to Windows Server 2016
#### 1.06 Creating the right trust
#### 1.07 Verifying and resetting a trust
#### 1.08 Securing a trust
#### 1.09 Extending the schema
#### 1.10 Enabling the Active Directory Recycle Bin
#### 1.11 Managing UPN suffixes

## 2. Managing Domain Controllers
Domain controllers should:
  - Number at least 2 per AD domain
  - Not have any other responsibilities, to the extent practical

Dimensioning domain controllers:
  - Both DCs should be roughly comparable in capabilities
  - Ample provisioning of storage and, especially, RAM
  - Use a license that will allow full use of Microsoft's extended support for the intended life of the DC
  - Install Server Core
  - Install latest stable firmware
  - Use VM-GenerationID enabled virtualization platforms, so that you can take snapshots of DCs without compromising the AD database
Preconfigure servers after installation:
  - change hostname
  - Make sure Windows is activated
  - Update Windows Server
  - Configure the server with at least one static IPv4 or IPv6 address
  - Check for at least one connected LAN connection
  - Configure DNS naming resolution
  - Configure the pagefile correctly
  - Implement information security measures

> - [x] 2.01 Preparing a Windows Server to become a domain controller
> - [x] 2.02 Promoting a server to a domain controller
> - [ ] 2.03 Promoting a server to a read-only domain controller
> - [ ] 2.04 Using install from media
> - [ ] 2.05 Using domain controller cloning
> - [ ] 2.06 Determining whether a virtual domain controller has a VM-GenerationID
> - [ ] 2.07 Demoting a domain controller
> - [ ] 2.08 Demoting a domain controller forcefully
> - [ ] 2.09 Inventory domain controllers
> - [ ] 2.10 Decommissioning a compromised read-only domain controller

#### 2.02 Promoting a server to a domain controller
```powershell
Install-WindowsFeature AD-Domain-Service -IncludeManagementTools
Import-Module ADDSDeployment
```

3 cmdlets available for 3 different scenarios:

Syntax  | Effect
:---    | :---
`Install-ADDSForest` | Add a new forest
`Install-ADDSDomain` | Add a domain to an existing forest
`Install-ADDSDomainController` | Add a domain controller to an existing domain

#### 2.03 Promoting a server to a read-only domain controller
#### 2.04 Using install from media
#### 2.05 Using domain controller cloning
#### 2.06 Determining whether a virtual domain controller has a VM-GenerationID
#### 2.07 Demoting a domain controller
#### 2.08 Demoting a domain controller forcefully
#### 2.09 Inventory domain controllers
#### 2.10 Decommissioning a compromised read-only domain controller

## 3. Managing Active Directory Roles and Features
> - [ ] 3.1 About FSMO roles
> - [ ] 3.2 Querying FSMO role placement
> - [ ] 3.3 Transferring FSMO roles
> - [ ] 3.4 Seizing FSMO roles
> - [ ] 3.5 Configuring the Primary Domain Controller emulator to synchronize time with a reliable source
> - [ ] 3.6 Managing time synchronization for virtual domain controllers
> - [ ] 3.7 Managing global catalogs

#### 3.1 About FSMO roles
#### 3.2 Querying FSMO role placement
#### 3.3 Transferring FSMO roles
#### 3.4 Seizing FSMO roles
#### 3.5 Configuring the Primary Domain Controller emulator to synchronize time with a reliable source
#### 3.6 Managing time synchronization for virtual domain controllers
#### 3.7 Managing global catalogs

## 4. Managing Containers and Organizational Units
> - [ ] 4.1 Differences beween OUs and containers
> - [ ] 4.2 Creating an OU
> - [ ] 4.3 Deleting an OU
> - [ ] 4.4 Modifying an OU
> - [ ] 4.5 Delegating control of an OU
> - [ ] 4.6 Modifying the default location for new user and computer objects

#### 4.1 Differences beween OUs and containers
#### 4.2 Creating an OU
#### 4.3 Deleting an OU
#### 4.4 Modifying an OU
#### 4.5 Delegating control of an OU
#### 4.6 Modifying the default location for new user and computer objects

## 5. Managing Active Directory Sites and Troubleshooting
> - [ ] 5.01 What do Active Directory sites do?
> - [ ] 5.02 Creating a site
> - [ ] 5.03 Managing a site
> - [ ] 5.04 Managing subnets
> - [ ] 5.05 Creating a site link
> - [ ] 5.06 MAnaging a site link
> - [ ] 5.07 Modifying replication settings for a site link
> - [ ] 5.08 Creating a site link bridge
> - [ ] 5.09 Managing bridgehead servers
> - [ ] 5.10 MAnaging the Intersite Topology Generation and Knowledge Consistency Checker
> - [ ] 5.11 Managing universal group membership caching
> - [ ] 5.12 Working with repadmin.exe
> - [ ] 5.13 Forcing replication
> - [ ] 5.14 Managing inbound and outbound replication
> - [ ] 5.15 Modifying the tombstone lifetime period
> - [ ] 5.16 Managing strict replication consistency
> - [ ] 5.17 Upgrading SYSVOL replication from File Replication Service to Distributed File System REplication
> - [ ] 5.18 Checking for and remediating lingering objects

#### 5.01 What do Active Directory sites do?
#### 5.02 Creating a site
#### 5.03 Managing a site
#### 5.04 Managing subnets
#### 5.05 Creating a site link
#### 5.06 MAnaging a site link
#### 5.07 Modifying replication settings for a site link
#### 5.08 Creating a site link bridge
#### 5.09 Managing bridgehead servers
#### 5.10 MAnaging the Intersite Topology Generation and Knowledge Consistency Checker
#### 5.11 Managing universal group membership caching
#### 5.12 Working with repadmin.exe
#### 5.13 Forcing replication
#### 5.14 Managing inbound and outbound replication
#### 5.15 Modifying the tombstone lifetime period
#### 5.16 Managing strict replication consistency
#### 5.17 Upgrading SYSVOL replication from File Replication Service to Distributed File System REplication
#### 5.18 Checking for and remediating lingering objects

## 6. Managing Active Directory Users
> - [ ] 6.01 Creating a user
> - [ ] 6.02 Deleting a user
> - [ ] 6.03 Modifying several users at once
> - [ ] 6.04 Moving a user
> - [ ] 6.05 Renaming a user
> - [ ] 6.06 Enabling and disabling a user
> - [ ] 6.07 Finding locked-out users
> - [ ] 6.08 Unlocking a user
> - [ ] 6.09 Managing userAccountControl
> - [ ] 6.10 Using account expiration

#### 6.01 Creating a user
#### 6.02 Deleting a user
#### 6.03 Modifying several users at once
#### 6.04 Moving a user
#### 6.05 Renaming a user
#### 6.06 Enabling and disabling a user
#### 6.07 Finding locked-out users
#### 6.08 Unlocking a user
#### 6.09 Managing userAccountControl
#### 6.10 Using account expiration

## 7. Managing Active Directory Groups
> - [ ] 7.1 Creating a group
> - [ ] 7.2 Deleting a group
> - [ ] 7.3 Managing the direct members of a group
> - [ ] 7.4 Managing expiring group memberships
> - [ ] 7.5 Changing the scope or type of a group
> - [ ] 7.6 Viewing nested group memberships
> - [ ] 7.7 Finding empty groups

#### 7.1 Creating a group
#### 7.2 Deleting a group
#### 7.3 Managing the direct members of a group
#### 7.4 Managing expiring group memberships
#### 7.5 Changing the scope or type of a group
#### 7.6 Viewing nested group memberships
#### 7.7 Finding empty groups

## 8. Managing Active Directory Computers
> - [ ] 8.1 Creating a group
> - [ ] 8.2 Deleting a group
> - [ ] 8.3 Managing the direct members of a group
> - [ ] 8.4 Managing expiring group memberships
> - [ ] 8.5 Changing the scope or type of a group
> - [ ] 8.6 Viewing nested group memberships
> - [ ] 8.7 Finding empty groups

#### 8.1 Creating a group
#### 8.2 Deleting a group
#### 8.3 Managing the direct members of a group
#### 8.4 Managing expiring group memberships
#### 8.5 Changing the scope or type of a group
#### 8.6 Viewing nested group memberships
#### 8.7 Finding empty groups

## 9. Getting the most out of Group Policy
> - [ ] 9.01 Creating a Group Policy Object (GPO)
> - [ ] 9.02 Copying a GPO
> - [ ] 9.03 Deleting a GPO
> - [ ] 9.04 Modifying the settings of a GPO
> - [ ] 9.05 Assigning scripts
> - [ ] 9.06 Installing applications
> - [ ] 9.07 Linking a GPO to an OU
> - [ ] 9.08 BLocking inheritance of GPOs on an OU
> - [ ] 9.09 Enforcing the settings of a GPO Link
> - [ ] 9.10 Applying security filters
> - [ ] 9.11 Creating and applying WMI Filters
> - [ ] 9.12 Configuring loopback processing
> - [ ] 9.13 Restoring a default GPO
> - [ ] 9.14 Creating the Group Policy Central Store

#### 9.01 Creating a Group Policy Object (GPO)
#### 9.02 Copying a GPO
#### 9.03 Deleting a GPO
#### 9.04 Modifying the settings of a GPO
#### 9.05 Assigning scripts
#### 9.06 Installing applications
#### 9.07 Linking a GPO to an OU
#### 9.08 BLocking inheritance of GPOs on an OU
#### 9.09 Enforcing the settings of a GPO Link
#### 9.10 Applying security filters
#### 9.11 Creating and applying WMI Filters
#### 9.12 Configuring loopback processing
#### 9.13 Restoring a default GPO
#### 9.14 Creating the Group Policy Central Store

## 10. Securing Active Directory
> - [ ] 10.01 Applying fine-grained password and account lockout policies
> - [ ] 10.02 Backing up and restoring GPOs
> - [ ] 10.03 Backing up and restoring Active Directory
> - [ ] 10.04 Working with Active Directory snapshots
> - [ ] 10.05 Managing the DSRM passwords on domain controllers
> - [ ] 10.06 Implementing LAPS
> - [ ] 10.07 Managing deleted objects
> - [ ] 10.08 Working with group Managed Service Accounts
> - [ ] 10.09 Configuring the advanced security audit policy
> - [ ] 10.10 Resetting the KRBTGT secret
> - [ ] 10.11 Using SCW to secure domain controllers
> - [ ] 10.12 Leveraging the Protected Users group
> - [ ] 10.13 Putting authentication policies and authentication policy silos to good use
> - [ ] 10.14 Configuring Extranet Smart Lock-out

#### 10.01 Applying fine-grained password and account lockout policies
#### 10.02 Backing up and restoring GPOs
#### 10.03 Backing up and restoring Active Directory
#### 10.04 Working with Active Directory snapshots
#### 10.05 Managing the DSRM passwords on domain controllers
#### 10.06 Implementing LAPS
#### 10.07 Managing deleted objects
#### 10.08 Working with group Managed Service Accounts
#### 10.09 Configuring the advanced security audit policy
#### 10.10 Resetting the KRBTGT secret
#### 10.11 Using SCW to secure domain controllers
#### 10.12 Leveraging the Protected Users group
#### 10.13 Putting authentication policies and authentication policy silos to good use
#### 10.14 Configuring Extranet Smart Lock-out

## 11. Managing Federation
> - [ ] 11.01 Choosing the right AD FS farm deployment method
> - [ ] 11.02 Installing the AD FS server role
> - [ ] 11.03 Setting up an AD FS farm with Windows Internal Database
> - [ ] 11.04 Setting up an AD FS farm with SQL Server
> - [ ] 11.05 Adding additional AD FS servers to an AD FS farm
> - [ ] 11.06 Removing AD FS servers from an AD FS farm
> - [ ] 11.07 Creating a Relying Part Trust (RPT)
> - [ ] 11.08 Deleting an RPT
> - [ ] 11.09 Configuring branding
> - [ ] 11.10 Setting up a Web Application Proxy
> - [ ] 11.11 Decommissioning a Web Application Proxy

#### 11.01 Choosing the right AD FS farm deployment method
#### 11.02 Installing the AD FS server role
#### 11.03 Setting up an AD FS farm with Windows Internal Database
#### 11.04 Setting up an AD FS farm with SQL Server
#### 11.05 Adding additional AD FS servers to an AD FS farm
#### 11.06 Removing AD FS servers from an AD FS farm
#### 11.07 Creating a Relying Part Trust (RPT)
#### 11.08 Deleting an RPT
#### 11.09 Configuring branding
#### 11.10 Setting up a Web Application Proxy
#### 11.11 Decommissioning a Web Application Proxy

## 12. Handling Authentication in a Hybrid World (AD FS, PHS, PTA, and 3SO)
> - [ ] 12.1 Choosing the right authentication method
> - [ ] 12.2 Verifying your DNS domain name
> - [ ] 12.3 Implementing Password Hash Sync with Express settings
> - [ ] 12.4 Implementing Pass-through Authentication
> - [ ] 12.5 Implementing single sign-on to Office 365 using AD FS
> - [ ] 12.6 Managing AD FS with Azure AD Connect
> - [ ] 12.7 Implementing Azure Traffic MAnager for AD FS geo-redundancy
> - [ ] 12.8 Migrating from AD FS to Pass-through Authentication for single sign-on to Office 365
> - [ ] 12.9 Making Pass-through Authentication (geo)redundant

#### 12.1 Choosing the right authentication method
#### 12.2 Verifying your DNS domain name
#### 12.3 Implementing Password Hash Sync with Express settings
#### 12.4 Implementing Pass-through Authentication
#### 12.5 Implementing single sign-on to Office 365 using AD FS
#### 12.6 Managing AD FS with Azure AD Connect
#### 12.7 Implementing Azure Traffic MAnager for AD FS geo-redundancy
#### 12.8 Migrating from AD FS to Pass-through Authentication for single sign-on to Office 365
#### 12.9 Making Pass-through Authentication (geo)redundant

## 13. Handling Synchronization in a Hybrid World (Azure AD Connect)
> - [ ] 13.01 Choosing the right sourceAnchor
> - [ ] 13.02 Configuring a staging mode
> - [ ] 13.03 Switching to a staging mode server
> - [ ] 13.04 Configuring Domain and OU filtering
> - [ ] 13.05 Configuring Azure AD app and attribute filtering
> - [ ] 13.06 Configuring MinSync
> - [ ] 13.07 Configuring Hybrid Azure AD Join
> - [ ] 13.08 Configuring Device writeback
> - [ ] 13.09 Configuring Password writeback
> - [ ] 13.10 Configuring Group writeback
> - [ ] 13.11 Changing the passwords for Azure AD Connects service accounts

#### 13.01 Choosing the right sourceAnchor
#### 13.02 Configuring a staging mode
#### 13.03 Switching to a staging mode server
#### 13.04 Configuring Domain and OU filtering
#### 13.05 Configuring Azure AD app and attribute filtering
#### 13.06 Configuring MinSync
#### 13.07 Configuring Hybrid Azure AD Join
#### 13.08 Configuring Device writeback
#### 13.09 Configuring Password writeback
#### 13.10 Configuring Group writeback
#### 13.11 Changing the passwords for Azure AD Connects service accounts

## 14. Hardening Azure AD
> - [ ] 14.01 Setting the contact information
> - [ ] 14.02 Preventing non-privileged users from accessing the Azure portal
> - [ ] 14.03 Viewing all privileged users in Azure AD
> - [ ] 14.04 Preventing users from registering or consenting to apps
> - [ ] 14.05 Preventing users from inviting guests
> - [ ] 14.06 Configuring whitelisting or blacklisting for Azure AD B2B
> - [ ] 14.07 Configuring Azure AD Join and Azure AD Registration
> - [ ] 14.08 Configuring Intune auto-enrollment upon Azure AD Join
> - [ ] 14.09 Configuring baseline policiesConfiguring Conditional Access
> - [ ] 14.10 Accessing Azure AD Connect Health
> - [ ] 14.11 Configuring Azure AD Connect Health for AD Fs
> - [ ] 14.12 Configuring Azure AD Connect Health for AD DS
> - [ ] 14.13 Configuring Azure AD Privileged Identity Management
> - [ ] 14.14 Configuring Azure AD Identity Protection

#### 14.01 Setting the contact information
#### 14.02 Preventing non-privileged users from accessing the Azure portal
#### 14.03 Viewing all privileged users in Azure AD
#### 14.04 Preventing users from registering or consenting to apps
#### 14.05 Preventing users from inviting guests
#### 14.06 Configuring whitelisting or blacklisting for Azure AD B2B
#### 14.07 Configuring Azure AD Join and Azure AD Registration
#### 14.08 Configuring Intune auto-enrollment upon Azure AD Join
#### 14.09 Configuring baseline policiesConfiguring Conditional Access
#### 14.10 Accessing Azure AD Connect Health
#### 14.11 Configuring Azure AD Connect Health for AD Fs
#### 14.12 Configuring Azure AD Connect Health for AD DS
#### 14.13 Configuring Azure AD Privileged Identity Management
#### 14.14 Configuring Azure AD Identity Protection