# Windows Server 2016 Administration Fundamentals, by Bekim Dauti

## 1 Introducing Windows Server
- Topics: networking concepts, Windows Server overview, WS2016 editions

Windows Server 2016 editions
  - Datacenter
  - Standard
  - Essentials

## 2 Installing Windows Server
- Topics: clean installation vs. upgrade, unattended installations

Installation options
  - __Desktop Experience__ (GUI)
  - __Server Core__ managed locally through Windows PowerShell or remotely through Server Manager
  - __Nano Server__: replacement for Server Core that takes up even less hardware resources with no local login capabilities

Term|Abbreviation|Definition
---|---
Assessment and Deployment Kit|ADK|tool that automates desktop and server deployments
Microsoft Deployment Toolkit|MDT|tool that automates desktop and server deployments
Preboot Execution Environment|PXE|required by WDS installation
Windows Deployment Service|WDS|installation over the network

## 3 Post-Installation Tasks in Windows Server

### Device drivers
device driver: program that acts as a translator between computer hardware and an operating system
PnP: Plug and Play|stsarted as a joint project between Intel and Microsoft
C:\Windows\System32\DriverStore: location of DriverStore

Computer devices:
  - __Internal device__ located within computer case
  - __External device__ connected to the computer case, constituting the whole computer system
  - __Peripheral device__ co-located with the computer but not an essential part of the system
  - __Network device__ peripheral device connected over a network cable
- Accessing devices through Devices and device drivers through Device Manager
- Installing, updating, removing, uninstalling, disabling, and rolling back device drivers

### Registry and services
Windows Registry is the heart of the Windows OS, and services are the background programs that keep applications and utilities alive.

##### Registry
Accessing, modifying, renaming, deleting, 
Registry key|Description
---|---
`HKEY_CLASSES_ROOT`|information on installed applications and their extensions
`HKEY_CURRENT_USER`|user currently logged-in
`HKEY_LOCAL_MACHINE`|information specific to the local computer
`HKEY_USERS`|information on logged user profiles
`HKEY_CURRENT_CONFIG`|information gathered during boot

##### Services
__Windows Services Control Manager__
  - Service startup types
    - Automatic
    - Automatic (delayed start)
    - Manual
    - Disable
  - Run As settings (Log On tab)
    - __Local System__ : built-in account with the most privileges in a Windows OS, also known as superuser, more powerful than an admin account
    - __NT Authority\Local Service__ : built-in account with the same privileges as a member of Users
    - __NT Authority\NetworkService__ : built-in account that has more privileges than members of Users
  - Recovery options (Recovery tab)
  - Start, stop, restart services (right-click dialog menu)

### Initial server configuration
The following configurations:
  - Server name
  - Joining a name
  - Enabling remote desktop
  - Setting up IP address
  - Checking for updates
  - Changing time zone
  - Activating Windows Server 2016
Two methods of configuration, depending on Windows Server 2016 edition:
  - __Server Manager__ in Desktop Experience
  - __Server Configuration (sconfig.cmd)__ in Server Core

## 4 Directory Services in Windows Server

### Understanding Active Directory Infrastructure

Snap-in|Executable|Description
Active Directory Administrative Center|dsac.exe|one-stop-shop for managing Windows Server Directory Services
Active Directory Users and Computers|dsa.msc|manage users, computers, and relevant information
Active Directory Domains and Trusts|domain.msc|manage domains trusts, and relevant information
Active Directory Sites and Services|dssite.msc|manage replication and services between sites
Active Directory Module for Windows PowerShell||used to manage the Windows Server's directory services through cmdlets

Term|Abbreviation|Definition
---|---
Backup Domain Controller|BDC|in Windows NT, domain controllers other than the Primary Domain Controller
Child domain||
Domain||logical grouping of users, computers, peripherals, network services, and security settings
Domain Controller|DC|server responsible for securely authenticating requests for accessing resources in an organization's domain
Forest||collection of trees
Primary Domain Controller|PDC|in Windows NT, the single domain controller per domain
Tree||collection of one or more domains, linked through transitive trust

### Understanding Domain Name System (DNS)

### Understanding organizational units and containers

Default containers created after promoting a server to domain controller:
  - Computers
  - Domain Controllers
  - ForeignSecurityPrincipals
  - Keys
  - LostAndFound
  - Managed Service Accounts
  - Program Data
  - Users

### Understanding accounts and groups
  - __Accounts__ are used to access network services
  - __Groups__ are collections of __Active Directory objects__, understood as representing users, computers, peripheral devices, and network services, and are used to facilitate the process of assigning rights and permissions

#### Accounts
  - __Domain account__ refers to an Active Directory __user__ (added to __Users__ container of  __AD Users and Computers__) or __computer__ (added to __Computers__ container)
  - __Local account__ refers to a local user, whose information is stored in the local SAM file (added through __Computer Management__)

#### User profiles
  - __Local__ user profile is stored on a local computer and created when the user __first logs in__
  - __Roaming__ user profile is copied and stored in a network share
  - __Mandatory__ user profile is like a roaming user profile except that changes are never saved

#### Groups
2 types of group:
  - __Security__ groups are explicitly used to assign permissions to shared resources on a network
  - __Distribution__ groups are used exclusively for email

3 group __scopes__:
  - __Domain local__ groups include accounts, other domain local groups, global groups, and universal groups from the parent's domain local group domain
  - __Global__ groups include accounts and other global groups from the parent's global group domain
  - __Universal__ groups include accounts, global groups, and universal groups from __any__ domain in the forest where a universal group belongs


## 6 Group Policy
A __group__ is a collection of __Active Directory objects__, understood as representing users, computers, peripheral devices, and network services. A __Group Policy__ is the best option offered by Microsoft to set up restrictions on computers and users, and can be understood as templates that enable sysadmins to control what users can and cannot do on AD objects. __Group Policy Objects (GPO)__ are collections of configured parameters that show how computers will look and behave for a certain group of users.
GPOs are assigned in the following order:
  - Local
  - Site
  - Domain
  - OU
GPOs assigned to __computer accounts__ take effect when the computers are turned on, but those assigned to __user accounts__ take effect upon login.

## 7 Virtualization
3 types of virtual switch available in Hyper-V
  - __External__ switch, which binds the physical network adapter so that virtual machines can access the physical network
  - __Internal__ switch, usable only by virtual machines and the physical server
  - __Private__ switch, used only by the virtual machines that run on the physical server

## 9 Tuning and maintaining Windows Server

### Performance counters
__Performance Monitor__ allows you to collect __Counters__ into a __Data Collector Set__, which is logged into C:\PerfLogs
