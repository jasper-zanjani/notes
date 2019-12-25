# Active Directory

#### Table of Contents, 4th edition
1. [A brief introduction](#history "Reviews the evolution of the Microsoft NOS and some of the major features and benefits of Active Directory.") &bull; [LDAP](#ldap "LDAP originated in 1993 as a lighter-weight alternative to X.500, but it did not gain traction until its third major version was released in 1997.") [WinNT](#windows-nt "Microsoft's first NOS was WinNT 3.0, combining features of LAN Manager protocols and OS/2 (1990).") [WS 2003](#windows-server-2003 "The concept of mixed and native operation modes introduced in Windows Server 2000 was further refined into that of domain and forest functional levels in Windows Server 2003.") [WS 2008](#windows-server-2008 "Windows Server 2008 introduced RODCs and Server Core.")
2. [Active Directory fundamentals](#active-directory-fundamentals "Provides a high-level look at how objects are stored in Active Directory and explains some of the internal structures and concepts that it relies on.") &bull; [Objects](#objects "Active Directory objects can be either leaf nodes or containers and are stored in a DIT file.") [Uniquely identifying objects](#objects "GUIDs and distinguished names are used to uniquely identify objects in Active Directory.")
3. [Naming contexts and application partisions](# "Reviews the predefined Naming Contexts within Active Directory, what is contained within each, and the purpose of Application Partitions") &bull; 
4. [Active Directory Schema](# "Gives you information on how the blueprint for each object and each object's attributes are stored in Active Directory.")
5. [Site topology and replication](# "Details how the actual replication process for data takes place between domain controllers.")
6. [Active Directory and DNS](# "Describes the importance of the Domain Name System (DNS) and what it is used for within Active Directory.")
7. [Read-Only Domain Controllers](# "Describes the deployment and operation of Read-Only Domain Controllers (RODCs).") &bull; [RODC][RODC]
8. [Group Policy primer](# "Gives you a detailed introduction to the capabilities of Group Policy Objects and how to manage them.")
9.  [Fine-grained password policies](# "Comprehensive coverage of how to design, implement, and manage fine-grained password policies.")
10. [Designing the namespace](# "Introduces the steps and techniques involved in properly preparing a design that reduces the number of domains and increases administrative control through the use of Organizational Units.")
11. [Creating a site topology](# "Shows you how to design a representation of your physical inrastructure within Active Diretory to gain very fine-grained control over intrasite and intersite replication.")
12. [Designing organization-wide group policies](# "Explains how Group Policy Objects function in Active Directory and how you can properly design an Active Directory structure to make the most effective use of these functions.")
13. [Active Dirctory Security: permissions and auditing](# "Describes how you can design effective security f0or all areas of your Active Directory, in terms of both access to objects and their properties; includes information on how to design effective security access logginging in any areas you choose.")
14. [Designing and implementing Schema extensions](# "Covers procedures for extending the classes and attributes in the Active Directory schema.")
15. [Backup, recovery, and maintenance](# "Describes how you can backup and restore Active Directory down to the object level or the entire directory.")
16. [Upgrading to Windows Server 2003](# "Outlines how you can upgrade your existing Active Directory infrastructure to Windows Server 2003.")
17. [Upgrading to Windows Server 2003 R2](# "Outlines the process to upgrade your existing Active Directory to Windows Server 2003 R2.")
18. [Upgrading to Windows Server 2008](# "Outlines the process to upgrade your existing Active Directory to Windows Server 2008.")
19. [Integrating Microsoft Exchange](# "Covers some of the important Active Directory-related issues when implementing Microsoft Exchange.")
20. [Active Directory Lightweight Directory Service (a.k.a. ADAM)](# "Introduces Active Directory Lightweight Directory Services (AD LDS, formerly ADAM).") [AD LDS][AD LDS]
21. [Scripting with ADSI](# "Introduces ADSI scripting by leading you through a series of step-by-step examples.")
22. [IADs and the Property Cache](# "Delves into the concept of the property cache used extensively by ADSI and shows you how to properly manipulate any attribute of any object within it.")
23. [Using ADO for searching](# "Demonstrates how to make use of a technology normally reserved for databases and now extended to allow rapid searching for objects in Active Directory.")
24. [Users and groups](# "Gives you the lowdown on how to rapidly create users and groups, giving them whatever attributes you desire.")
25. [Permissions and auditing](# "Describes how each object contains its own list of permissions and auditing entries that governs how it can be accessed and how access is logged.")
26. [Extending the Schema and the Active Directory snap-ins](# "Covers the creation of new classes and attributes programmatically in the schema, and modification of the existing Active Directory snap-ins to perform additional customized functions.")
27. [Scripting with WMI](# "Gives a quick overview of WMI and goes through several examples for managing a system, including services, the registry, and the event log. Accessing AD with WMI is also covered, along with the TrustMon and Replication WMI Providers.")
28. [Scripting DNS](# "Describes how to manipulate DNS server configuration, zones, and resource records with the WMI DNS Provider.")
29. [Programming the Directory with the .NET framework](# "Starts off by providing some background information on the .NET Framework and then dives into several examples using the System.DirectoryServices namespaces with VB.NET.")
30. [PowerShell Basics](# "Provides a jumpstart to Windows PowerShell and a quick reference for PowerShell scripting concepts.") &bull; 
31. [Scripting Active Directory with PowerShell](# "Describes how to manage and manipulate Active Directory using Windows PowerShell.")
32. [Scripting Basic Exchange 2003 tasks](# "Tackles common Active Directory-related user and group management tasks for Microsoft Exchange 2000/2003.")
33. [Scripting Basic Exchange 2007 tasks](# "Tackles common Active Directory-related tasks for Microsoft Exchange 2007 using Windows PowerShell.")

#### Table of Contents, 5th edition
1. A brief introduction
2. Active Directory fundamentals
3. Active Directory management tools
4. Naming contexts and application partitions
5. Active Directory Schema
6. Site topology and Active Directory replication
7. Searching Active Directory
8. Active Directory and DNS
9. Domain Controllers
10. Authentication and security protocols
11. Group Policy Primer
12. Fine-grained password policies
13. Designing the Active Directory structure
14. Creating a site topology
15. Planning for Group Policy
16. Active Directory Security: permissions and auditing
17. Designing and implementing Schema extensions
18. Backup, recovery, and maintenance
19. Upgrading Active Directory
20. Active Directory Lightweight Directory Services
21. Active Directory Federation Services

## History
#### LDAP
LDAP originated in 1993 as a lighter-weight alternative to [X.500](#glossary "ITU and ISO-developed series of directory service standards based on OSI protocol stack; superceded by LDAP"), but it did not gain traction until its third major version was released in 1997.

#### Windows NT
Active Directory, like its predecessor WinNT, provides directory services; [`dcpromo.exe`](#glossary "wizard that promotes a member server to domain controller") can be used to promote and demote domain controllers.\
Microsoft's first [NOS](#glossary "networked environment in which various types of resources, such as user, group, and computer accounts, are stored in a central repository that is controlled by administrators and accessible to end users") was WinNT 3.0, combining features of LAN Manager protocols and OS/2 (1990). NT allowed administrative delegation only at the domain, but Active Directory allows administrators to define administrative boundaries at the forest, domain, or Organizational Unit.\
In Active Directory, all domains within a forest trust each other via **transitive trust**, which results in a [**Complete-trust**](#glossary "Windows NT domain model where any domain could create accounts, and each could access shared resources in any other domain") model within the forest. Domain models available in NT included [Single-domain](#glossary "Windows NT domain model with only one domain and no trusts"), 
[Single-master](#glossary "Windows NT domain model with a single user (or account) domain and multiple resource domains, each of which had one-way trusts with the user domain"), and [Multimaster](#glossary "Windows NT domain model with multiple user domains (each of which having two-way trust with the others), and multiple resource domains (each of which had one-way trust with every user domain); each trust had to be manually set") [[^][Desmond2009]: 8-9]

Active Directory Schemas are [extensible](#glossary "schema to which new object types may be added"), whereas NT schemas were not.

Feature         | WinNT         | Active Directory
---             | ---           | ---
Name resolution | [WINS](#glossary "obsolete system that resolves NetBIOS names to IP addresses on Windows networks; required by Windows NT") | DNS
Database        | [SAM](#glossary "\"Security Accounts Manager\", NT database with a maximum recommended size of 40 MB") | [ESE](#glossary "\"Extensible Storage Engine\", Exchange database which provided the basis for Active Directory, developed to hold millions of objects with a maximum database size of 16 TB")

#### Windows Server 2003
The concept of [mixed](#glossary "Windows 2000 operation mode that allows Win2k and WinNT domain controllers to coexist, but does not support universal or nested groups") and [native](#glossary "Windows 2000 operation mode that offers support for universal groups, nested groups, and transitive trust relationships but no support for WinNT domain controllers") operation modes introduced in Windows Server 2000 was further refined into that of domain and forest [functional levels](#functional-levels "determines available Active Directory domain or forest capabilities") in Windows Server 2003. [[^][Desmond2009]: 10]\
Windows Server 2003 introduced several optional components: [ADAM][ADAM], [ADFS](#glossary "\"Active Directory Federated Services\", standards-based technology that enables distributed identification, authentication, and authorization across organizational and platform boundaries"), and [IMU](#glossary "\"Identity Management for Unix\", manage user accounts and passwords on Windows and Unix via NIS; automatically synchronize passwords between Windows and Unix"). [[^][Desmond2009]: 14]

#### Windows Server 2008
Windows Server 2008 introduced [**RODC**][RODC]s and **Server Core**.

## Active Directory fundamentals
#### Objects
Active Directory objects can be either [leaf node](#glossary "also 'non-container', Active Directory object which does not contain any other objects")s or [container](#glossary "Active Directory object which contains other objects")s and are stored in a [DIT](#glossary "\"Directory Information Tree\", ESE database file that stores Active Directory objects in flat database rows and columns") file.\
[GUID](#glossary "\"Globally Unique Identifier\", 128-bit number assigned to objects by the system at the time of their creation; Microsoft implementation of the UUID concept")s and
[distinguished names](#distinguished-names "(DN), hierarchical paths used to uniquely reference any object in LDAP or Active Directory") are used to uniquely identify objects in Active Directory. [[^][Desmond2009]: 17-19]

#### Distinuished name
Distinguished names for AD objects are normally represented as a string of comma-delimited prefix-name pairs separated by `=`. The DN of `mycorp.com` would look like:
```
dc=mycorp,dc=com
```
Active Directory supports the [`CN`](#distinguished-name "LDAPv3 attribute prefix for common names"), [`L`](#distinguished-name "LDAPv3 attribute prefix for locality names"), [`O`](#distinguished-name "LDAPv3 attribute prefix for organization names"), [`OU`](#distinguished-name "LDAPv3 attribute prefix for organizational unit names"), [`C`](#distinguished-name "LDAPv3 attribute prefix for country names"), and [`DC`](#distinguished-name "LDAPv3 attribute prefix for domain components") prefixes.
[RDN](#distinguished-name "\"relative distinguished name\", name used to uniquely reference an object within its parent container in the directory")s must be unique within the container in which they exist. [[^][Desmond2009]: 19-20]

#### Domain
A [DC](#domain "\"domain controller\", server that responds to security authentication requests within a Windows Server domain") can be authoritative for one and only one domain. [Domain tree](#domain "series of domains connected together hierarchically, using a contiguous naming scheme")s ease management and access to resources. [[^][Desmond2009]: 21]
#### Forests
#### Organizational Units
#### GC
[Global Catalog](#gc "read-only catalog of all objects in a forest which contains a subset of attributes for each object; used to perform forest-wide searches") is accessible via LDAP over port 3268. [[^][Desmond2009]: 25]

#### FSMO
[FSMO](#fsmo "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles include [Schema Master](#fsmo "forest-wide domain controller role allowing changes to be made to the Active Directory Schema"), [Domain Naming Master](#fsmo "forest-wide domain controller role that controls changes to the forest-wide namespace"), [PDC Emulator](#fsmo "\"Primary Domain Controller Emulator\", domain-wide domain controller role replicates the Windows NT SAM database to Windows NT 4.0 and Windows 3.51 BDCs"), [RID Master](#fsmo "\"Relative-Identifier Master\", domain-wide domain controller role that maintains a pool of unique RID values to ensure that all SIDs in a domain are unique"), and [Infrastructure Master](#fsmo "domain-wide domain controller role that maintains references to objects in other domains ('phantoms')").
#### Time synchronization
#### Functional levels
Functional levels could not be downgraded to a lower number once set until WS 2008 R2.

#### SID
A Windows SID is generally composed of 2 fixed fields and up to 15 additional fields, all separated by dashes:
```
S-v-id-s1-s2-s3-s4-...-s15
```
Fixed fields:
- `v` is always `1`
- `id` is called the **identifier authority** and can have various values:
  - `0` "NULL"
  - `1` "World"
  - `2` "Local"
  - `5` "NT Authority

Well-known SIDs
- `S-1-5-10` NT Authority/Self
- `S-1-1-0` Everyone

The fields `s1`-`s15` are called **sub-authorities** and are optional, and most SIDs only have a few of them populated. The last sub-identifier is called the **RID** and is the value that a domain or computer increments to create unique SIDs.\
Well-known RIDs
- `500` built-in administrator account
- `514` Readers
- `513` Users
- `512` Administrators

## RODC
## AD LDS
AD LDS (previously known as [ADAM](#ad-lds "\"Active Directory Application Mode\", standalone LDAP service similar to full Active Directory, but without DNS, Group Policy, or Kerberos requirements (ref. AD LDS)")) offers a pared-down version of AD that is easy to set up and tear down. It was first released in November 2003 and offers security benefits because it doesn't enable so many services by default. It was renamed AD LDS with the release of Windows Server 2008. [[^][Desmond2009]: 457-458]\

Differences between AD and AD LDS
- AD LDS is a standalone application run from a `dsamain.exe` process (rather than `lsass.exe`), which means it can be started or stopped on demand without rebooting and multiple instances can be run.
- AD LDS lacks the [global catalog](#gc "read-only catalog of all objects in a forest which contains a subset of attributes for each object; used to perform forest-wide searches") functionality (removing [NSPI](# "\"Name Service Provider Interface\", feature supported by Active Directory's global catalog") and [AB](# "\"Address Book\", feature supported by Active Directory's global catalog") as well)

Feature         | AD LDS        | Active Directory
---             | ---           | ---
LDAP port       | Configurable  | Static
Resource location | `serviceConnectionPoint` objects | SRV DNS records
Global catalog  | No            | Yes
Schema          | 44 classes and 268 attributes | 
[SID][SID]      | `S-v-id-s1-s2-s3-...-s15` | `S-v-id1-id2-r1-r2-r3-r4`
Service account | `NT AUTHORITY\NetworkService` | `LocalSystem`

## Index

#### PowerShell cmdlets
\#      | PowerShell cmdlets (nouns sorted alphabetically)
---     | ---
C       | **`CliXml`** [`Export`][Export-CliXml] [`Import`][Import-CliXml] &bull; **`Command`** [`Get`][Get-Command] &bull; **`Csv`** [`Export`][Export-Csv] [`Import`][Import-Csv]
E       | **`ExecutionPolicy`** [`Set`][Set-ExecutionPolicy]
H       | **`Help`** [`Get`][Get-Help]
L       | **`List`** [`Format`][Format-List] **`Location`** [`Set`][Set-Location]
M       | **`Member`** [`Get`][Get-Member]
N       | **`Null`** [`Out`][Out-Null]
O       | **`Object`** [`ForEach`][ForEach-Object] [`Where`][Where-Object]
P       | **`PSSnapin`** [`Add`][Add-PSSnapin] [`Get`][Get-PSSnapin]

#### Windows objects
\#      | Windows objects
---     | ---
D       | [`domainDNS`](# "class from which application partition objects must be derived")
S       | [`serviceConnectionPoint`][SCP]

#### LDAP controls
\#      | LDAP controls
---     | ---
L       | [`LDAP_SERVER_SEARCH_OPTIONS_OID`](# "control that enables full instance search functionality on AD LDS")
S       | [`SERVER_SEARCH_FLAG_PHANTOM_ROOT`](# "control that enables full instance search functionality on AD LDS")


[Desmond2009]: # "Desmond, Brian et al. _Active Directory_. O'Reilly Media, 2009."
[Desmond2013]: # "Desmond, Brian et al. _Active Directory_. O'Reilly Media, 2013."

[AD LDS]: #ad-lds "\"Active Directory Lightweight Directory Services\", standalone LDAP service similar to full Active Directory, but without DNS, Group Policy, or Kerberos requirements (previously known as ADAM)"
[RODC]: #rodc "\"Read-Only Domain Controller\", do not allow writes and do not store passwords or other secrets by default; adds security to DCs in locations that are less physically secure"
[SCP]: #ad-lds "\"serviceConnectionPoint\", object that AD LDS can publish, usually under the computer object on which the service is installed, that maintains key pieces about the AD LDS installation in the `keywords` and `serviceBindingInformation` attributes"
[SID]: #sid "\"Security Identifier\", unique, variable-length identifier used to identify a trustee or security principal, composed of 2 fixed fields and 15 additional fields, all separated by dashes"

[Add-PSSnapin]: # "Load a given list of snap-ins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) either by name or via the pipeline - last supported in PowerShell 5.1"
[Export-CliXml]: ../win/ps.md#export-clixml "Serialize a PowerShell object as a Common Language Infrastructure (CLI) XML file"
[Export-Csv]: ../win/ps.md#export-csv "Export PowerShell objects to CSV"
[ForEach-Object]: ../win/ps.md#filters "(alias: %)"
[Format-List]: ../win/ps.md#format-list "Display output in list style (alias: fl)"
[Format-Table]: ../win/ps.md#format-table "Display output in table style (alias: ft)"
[Get-Command]: ../win/ps.md#get-command "Display all installed commands, including aliases, applications, filters, functions, and scripts (alias: gcm)"
[Get-Help]: ../win/ps.md#get-help "Display help file for cmdlets"
[Get-Member]: ../win/ps.md#get-member "Display properties and methods of a PowerShell object (alias: gm)"
[Get-PSSnapin]: # "Display currently loaded snapins (.NET assemblies containing a collection of cmdlets and/or providers for use within PowerShell) - last supported in PowerShell 5.1"
[Import-Csv]: ../win/ps.md#import-csv "Import CSV files as PowerShell objects"
[Import-CliXml]: ../win/ps.md#import-clixml "Import a Common Language Infrastructure (CLI) XML file with data that represents Microsoft .NET Framework objects and create PowerShell objects from it"
[Out-Null]: ../win/ps.md#out-null "Dispose of information piped to it, in lieu of displaying it"
[Set-Location]: ../win/ps.md#set-location "Set present working directory (alias: cd)"
[Set-ExecutionPolicy]: ../win/ps.md#set-executionpolicy "Change PowerShell execution policy for Windows computers (Windows only)"
[Where-Object]: ../win/ps.md#filters "(alias: ?)"