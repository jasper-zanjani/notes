# [Windows Server Administration Fundamentals](https://app.itpro.tv/course-library/mta-server1/overview-mcsa-windows-81-70692/)

## [Overview](https://app.itpro.tv/course-library/mta-server1/overview-mcsa-windows-81-70692/)
The MTA is a suitable starting point for IT professionals.

## [Understand device drivers](https://app.itpro.tv/course-library/mta-server1/understand-device-drivers/)
A driver is software that allows use of hardware
Methods for installing new drivers:
  - Driver Installation > Allow non administrators to install drivers for these device setup classes
  - Preload drivers in the Driver Store, making it available for any user to install : `pnputil -a C:\path\to\driver`
  - Require signed drivers, or sign it yourself, but the certificate has to be added to the __trusted root__.
Disabling a device and removing a device: 
  - `pnputil -d` to remove a driver from the store 
  - `pnputil -f -d` force removal of the package and delete it
  - Device Manager
Updating a driver will require a restart since drivers are loaded on boot
  - Device Manager > Update driver button
  - Setup executable
Driver rollback
  - Device manager > Roll Back Driver
Interrupt requests (IRQ)
  - handled dynamically by the system
  - Visible in Resources tab in Device Manager

## Understand services
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/understand-services/)

### Managing services
Administrative Tools > Services
  - Available services, only some of which are started
  - 4 states: Started (running), Starting (loading up), Paused (temporarily halted), Stopped
  - Startup type: Manual, Auto, Automatic Delayed Start, Disabled
  - Various options for failure: Restart Service, Restart Computer, etc
  - Log On tab controls account used to determine services' access to resources: Local System (equivalent to Admin, most powerful level of access), Local Service (moderate level of access to resources, similar to User, but no network access), and Network Service
### Creating a Managed Service Account
__Managed Service Accounts__: Windows manages password changes for service accounts; they can only be used on a single server, but Group Managed Accounts were released in 2012.

Step | Effect
:--- | :---
Active Directory Module for Windows Powershell
`New-ADServiceAccount -SamAccountName WebSvc` | prompts for Name
`Add-ADComputerServiceAccount -Identity dc01 -ServiceAccount websvc` | add account to list of service accounts on machine
`Install-AdServiceAccount -Identity websvc` | install the account and tell the system to start using it. Adding "\websvc$" in This Account" under Log On tab for the service with nothing in the password fields will now tie that account to the service.

## Server installation options
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/server-installation-options/)
### Licenses
3 main licenses available for Microsoft Server 2008:
  1. Enterprise (no longer available for recent editions)
  2. Datacenter
  3. Standard

### Partitioning
Installations are typically of 2 types:
  1. Upgrade (not recommended)
  2. Clean install

Installations can be attended or unattended (requiring an XML format __answer file__)

### Windows Deployment Services
Automated way to get Windows Server installed on a machine. A reference machine is __sysprepped__, whereby uniquely identifying information is destroyed, and the resulting generalized image is loaded to a deployment server, which can then serve the image to various other servers.

## Server installation options, part 2
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/server-install-options-2/)
- Topics: BIOS menu, Safe Mode, etc
"Core" is equivalent to headless mode

### sconfig 
Server configurator: Terminal-based menu-driven system for configuring server

### Firmware and BIOS upgrades

## Identify Application Servers
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/identify-application-servers/)
There are a variety of servers that are individual Microsoft products that require their own licenses:
  - Exchange : email server
  - Microsoft SQL Server
  - Sharepoint
  - System Center Operations Manager : deploy, configure, manage, and monitor operations, services, devices, and applications of enterprise systems through a single console
  - Forefront Threat Management Gateway (Forefront TMG), formerly Microsoft Internet Security and Acceleration Server (ISA Server) : network router, firewall, VPN server, and web cache

Other services are known as roles and can be run without any additional cost:
  - DNS server

## Web servers
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/web-servers/)
Internet Information Services (IIS) Role is used to administer web servers
Add web server role
  - Server Manager > Add Roles Wizard
Individual sites are managed from within the IIS Manager
Custom ports and protocol types can be changed by navigating to Actions > Edit Site > Bindings... SSL requires a certificate (> Server Certificates), which is available in the dropdown in Bindings...

Custom certificates have the filename extension .pfx. When installing it, it should be placed into the Trusted Root Certification Authorities directory

## Remote access
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/remote-access2/)
Remote desktop and Remote assistance allow access to the entire desktop
Remote Server Administration Tools (RSAT) allow tailored access to administrative consoles have to be installed separately from a special binary.

Add installed RSAT tools: Programs and Features > Turn Windows features on or off > Remote Server Administration tools > Role Administration Tools > DNS

Remote Desktop Gateway required for people to remote into their work computer (on a private LAN) from the Internet
From Remote Desktop Connection > Advanced tab > Connect from anywhere > Use these RD Gateway server settings, etc.

VPN is effectively the same as adding your remote host to the corporate network, like connecting a long Ethernet cable to the host network router

## File and print services
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/file-print-services/)

### Printers
Local printers can be shared over the network, in which case the local host connected to the printer becomes the print server
For network printers, a print server has to be set up using the __Print and Document Services__ role, and they must be listed in __Active Directory__
Web-based interfaces to printers (Internet Printing or Internet Printing Protocol) are also possible, if enable, by navigating to the server's name + "/printers"
Printer pools take multiple printers and treat them as a single logical printer, providing scalability and fault tolerance. They must all be the same printer, or at least use the same driver. 
Print Management > Printers > Ports > Enable print pooling

### Auditing
Permissions are over an object; rights are system-wide. Group Policy Management Editor > Computer Configuration > Policies > Windows Settings > Security Settings > Local Policies > Audit Policy

Event Viewer > Windows Logs > Security displays results of audit


## Server virtualization
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/server-virtualization/)
Hyper-V is Microsoft's hypervisor, which allows multiple virtual servers to share the same hardware. It is a Type I hypervisor, superior to a Type II like VirtualBox

A Virtual Hard Drive (VHD) is a hard drive that is treated like a hard drive. Two main formats: VHD and VHDX, differentiated mostly by size limitation. 
3 types of virtual hard disks:
  1. Fixed size: entire drive is provisioned from the start, in a contiguous block that is good for performance
  2. Dynamically expanding, where the file is resized according to contents, which is good for testing but suffers from performance issues because the system must continously reprovision additional space as it is used
  3. Differencing, which establishes a parent VHD which can be shared with children, to produce variations, again at a performance cost

### Checkpoints
__Checkpoints__ are save states that represent snapshots of the system at points in time

### Physical to virtual, vice versa
`disk2vhd` tool allows you to make a VHD from a bootable physical drive. VHD disks can also be treated as bootable hard drives by the BIOS.

## Active Directory accounts and groupd
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/accounts/)
__Domain accounts__ refer to accounts created in Active Directory, requiring a __domain controller__. This allows a user to logon to any of an organization's machines, with the credentials and management rights being centrally managed. 

__Local accounts__, by contrast, are machine-dependent with user accounts stored in a SAM file.


## Active Directory Infrastructure
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/ad-infrastructure/)
Install Active Directory Users and Computers as a role. AD database is stored C:\Windows\NTDS\ntds.dit
C:\Windows\SYSVOL is where group policy information is stored
New domain controllers will copy the AD database from the first, and changes ripple across all child domain controllers automatically, the same "tree" within the "forest". These form __contiguous namespaces__.

Domain admins have complete control over domains, but enterprise admins have control oer all domains within the forest.
New users are added according to a __schema__, which is shared amongst a forest. This means schemas can only be edited by enterprise admins, since they are shared across an entire enterprise.

ntds.dit is divided up into three partitions:
  1. Schema : similar to Registry of a Windows computer, replicated across all domain controllers in enterprise
  2. Configuration : replicated across all domain controllers in enterprise
  3. Domain

Active Directory has a __multiple-master__ principle, where there is more than one writable copy of the database, with some exceptions. The __Schema master__ is the only writable copy of the Schema. The __Domain Naming master__ similarly is the single writable copy of the Domain Naming partition of the Directory. __PDC Emulator__ is responsible for password changes and time synchronization. Primary Domain Controller (PDC) represents the single writable copy on the enterprise. __RID Master__, __Relative identifiers__, __Security identifiers__

Within __sites__ (a way to define areas of the network that have high-speed, reliable connectivity, typically co-located), replication occurs almost immediately; outside of them, replication can be controlled by admins.

## Group Policy
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/policy/)
__Centralized Configuration Management (CCM)__ 
Local policy is applied first, then site, domain, and OU, in order. The end-result is called the __Resultant Set of Policy (RSOP)__
__Group Policy Management__ is MMC used to manage group policy
Group policies cannot be linked to containers, only OUs.
`gpupdate /force` refresh group policies after a change, if you don't want to wait for 90-120 minute refresh cycle

## Storage
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/storage-technologies/)
  - Local storage
    - IDE or Parallel ATA devices (2 for each of 2 channels, for a total of 4 drives)
    - Serial ATA
    - SCSI
  - Network storage
    - Network Attached Storage (NAS)
    - Storage Area Network (SAN) enterprise-level performance with devices operating on fiberoptic cable and prices in the tens or hundreds of thousands of dollars
    - iSCSI "poor man's SAN", takes advantage of existing infrastructure. In WS2008 requires a virtual hard drive to be set up.
    - NFS Windows Server supports Network File System (NFS) used by Unix servers.

## Understanding RAID
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/understanding-raid/)
__Redundant Array of Independent Disks (RAID)__
  - RAID 0 : striping
  - RAID 1 : mirror
  - RAID 5 : striping with parity (one disk in any array can be lost)
  - RAID 10: striping across mirrored sets
Software RAID disks for all modes except 10 can be configured in Computer Management

## Disk types
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/disk-types/)
Filesystems: NTFS, REFS, FAT32
"Basic" disk type = MBR
"Dynamic" disk types = GPT
__Spanned volumes__ require dynamic disks and can stitch together a single lettered drive from multiple disparate sections of multiple drives. It is not recommended to keep data on such volumes long-term because you have more than one point of failure; any of the constituent drives failing will result in the whole volume being lost.
__Mount points__ allow you to avoid using another drive letter; it is another option that can be used when creating a new volume
__Virtual Hard Drive (VHD)__ is a file that is treated as a hard drive, used primarily with VMs.
__Distributed filesystem__ is shared by more than one machine. 

## Server Components
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/disk-types/)

## Performance monitoring
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/performance-monitoring/)
Task Manager > Performance
Ending process is like SIGKILL, ending application is like SIGQUIT
Resource Monitor is like task manager on steroids
Performance monitor allows fine-grained monitoring of performance by choosing Counters

## [Logs and alerts](https://app.itpro.tv/course-library/mta-server1/logs-alerts/)

## [Startup Process](https://app.itpro.tv/course-library/mta-server1/startup-process/)
Basic boot process has changed since 2008. After POST, control is eventually handed over to the bootloader located in the __Master Boot Record (MBR)__, BOOTMGR.exe (which has replaced the older NTLDR), which looks for the active partition, then winload.exe  which loads the specific version of Windows. On resume, control is handed to winresume.exe.

For the exam:
  - BIOS
  - Significance of the boot sector: Master Boot Record (MBR)
  - Bootloader (winload.exe)

__Directory Service Restore Mode (DSRM)__ is the equivalent to Safe Mode for Active Directory.

`bcdedit /set safeboot dsrepair` (24:00) enter DSRM on reboot from the command line
`bcdedit /deletevalue safeboot` remove safe boot option, allowing normal boot on restart

## Business continuity
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/business-continuity2/) 
Ensuring continuous operations in the face of foreseeable technical failures.

### Disaster recovery
  - Backups: Windows Backup (not installed by default, nor is it reliable at the enterprise level; will be installed as yet another tool in Administrative tools)
  - Cold/Warm/Hot sites:
    - Cold sites are cheap to maintain, but take longer to restore because there is no infrastructure for immediate resumption of operations
    - Warm sites have equipment, power connections, internet connectivity, with some backups, but recovery would not be immediate
    - Hot sites offer almost immediate resumption of operations, at the greatest cost

### Business continuity
Business continuity in the face of foreseeable technical failures basically devolves to clusters of servers providing redundancy in the case of technical failure of one or more nodes, in addition to __data redundancy__ and __uninterruptible power supplies__.

### Active Directory
Active Directory Domain Controllers generally bring newly restored replication partners up to speed automatically, __except__ in the case of __deleted Objects__. Because the deletion date is more recent than the restoration's date, the restored Object will be immediately deleted, unless you do an __Authoritative Restore__, which will allows an administrator to mark an Object to be maintained.

## Understanding updates
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/understanding-updates/)
Updates are more involved in a server environment than in a desktop environment. Updates are necessary because they typically patch known security holes, or add desired functionality. __Windows Server Update Services (WSUS)__ (in Administrative Tools) allows administrators to run their own update servers, to make sure updates are administered in a way that suits the enterprise's systems.

## Troubleshooting methods
- Source: [itp](https://app.itpro.tv/course-library/mta-server1/troubleshooting-methods/)
Often, reimaging a computer is easier than trying to chase down an elusive issue. 

### Troubleshooting methodologies
  1. __Systematic__ approach, similar to that described in the A+ certification, where a methodical predetermined set of steps is followed despite a person's hunch (appropriate for inexperienced people).
  2. __Specific__ approach where methodical approach is foregone when the troubleshooter's intuition and experience point them in a particular direction (suitable for experienced troubleshooters).

### Troubleshooting tools
  - Performance Monitor
  - Event Viewer

### Event Viewer subscriptions
`winrm quickconfig` run on clients that are reporting to collector
`wecutil qc` 
Collector's computer account (that is, the computer itself), needs to be added to Local Admins Group
