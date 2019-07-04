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
## 9. Getting the most out of Group Policy
## 10. Securing Active Directory
## 11. Managing Federation
## 12. Handling Authentication in a Hybrid World (AD FS, PHS, PTA, and 3SO)
## 13. Handling Synchronization in a Hybrid World (Azure AD Connect)
## 14. Hardening Azure AD
