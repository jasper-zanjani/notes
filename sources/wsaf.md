# Windows Server 2016 Administration Fundamentals, by Bekim Dauti

## Introducing Windows Server
- Topics: networking concepts, Windows Server overview, WS2016 editions

Windows Server 2016 editions
  - Datacenter
  - Standard
  - Essentials

## Installing Windows Server
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

## Post-Installation Tasks in Windows Server

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

## Directory Services in Windows Server

Term|Abbreviation|Definition
---|---
Backup Domain Controller|BDC|in Windows NT, domain controllers other than the Primary Domain Controller
Child domain||
Domain||logical grouping of users, computers, peripherals, network services, and security settings
Domain Controller|DC|server responsible for securely authenticating requests for accessing resources in an organization's domain
Forest||collection of trees
Primary Domain Controller|PDC|in Windows NT, the single domain controller per domain
Tree||collection of one or more domains, linked through transitive trust

Snap-in|Executable|Description
Active Directory Administrative Center|dsac.exe|one-stop-shop for managing Windows Server Directory Services
Active Directory Users and Computers|dsa.msc|manage users, computers, and relevant information
Active Directory Domains and Trusts|domain.msc|manage domains trusts, and relevant information
Active Directory Sites and Services|dssite.msc|manage replication and services between sites
Active Directory Module for Windows PowerShell||used to manage the Windows Server's directory services through cmdlets

## Group Policy
A __group__ is a collection of __Active Directory objects__, understood as representing users, computers, peripheral devices, and network services. A __Group Policy__ is the best option offered by Microsoft to set up restrictions on computers and users, and can be understood as templates that enable sysadmins to control what users can and cannot do on AD objects. __Group Policy Objects (GPO)__ are collections of configured parameters that show how computers will look and behave for a certain group of users.
GPOs are assigned in the following order:
  - Local
  - Site
  - Domain
  - OU
GPOs assigned to __computer accounts__ take effect when the computers are turned on, but those assigned to __user accounts__ take effect upon login.

## Virtualization
