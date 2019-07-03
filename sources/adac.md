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

> - [ ] 2.01 Preparing a Windows Server to become a domain controller
> - [ ] 2.02 Promoting a server to a domain controller
> - [ ] 2.03 Promoting a server to a read-only domain controller
> - [ ] 2.04 Using install from media
> - [ ] 2.05 Using domain controller cloning
> - [ ] 2.06 Determining whether a virtual domain controller has a VM-GenerationID
> - [ ] 2.07 Demoting a domain controller
> - [ ] 2.08 Demoting a domain controller forcefully
> - [ ] 2.09 Inventory domain controllers
> - [ ] 2.10 Decommissioning a compromised read-only domain controller

#### 2.02 Promoting a server to a domain controller


#### 2.03 Promoting a server to a read-only domain controller
#### 2.04 Using install from media
#### 2.05 Using domain controller cloning
#### 2.06 Determining whether a virtual domain controller has a VM-GenerationID
#### 2.07 Demoting a domain controller
#### 2.08 Demoting a domain controller forcefully
#### 2.09 Inventory domain controllers
#### 2.10 Decommissioning a compromised read-only domain controller


## 3. Managing Active Directory Roles and Features
## 4. Managing Containers and Organizational Units
## 5. Managing Active Directory Sites and Troubleshooting
## 6. Managing Active Directory Users
## 7. Managing Active Directory Groups
## 8. Managing Active Directory Computers
## 9. Getting the most out of Group Policy
## 10. Securing Active Directory
## 11. Managing Federation
## 12. Handling Authentication in a Hybrid World (AD FS, PHS, PTA, and 3SO)
## 13. Handling Synchronization in a Hybrid World (Azure AD Connect)
## 14. Hardening Azure AD
