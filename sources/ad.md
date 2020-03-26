# Active Directory
[AD]: # 'Active Directory (AD)&#10;Microsoft network operating system, built on top of Windows Server&#10;AD has origins in Windows NT 3.0, which combined features of the LAN Manager protocols with the OS/2 operating system.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 3'
[X.500]: # 'X.500&#10;ITU and ISO-developed series of directory service standards based on OSI protocol stack; superceded by LDAP&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 5'
[SAM]: # 'Security Accounts Manager (SAM)&#10;Database used in Windows NT that had a maximum recommended size of 40 MB&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 7'
[ESE]: # 'Extensible Storage Engine (ESE)&#10;Exchange database which provided the basis for Active Directory, developed to hold millions of objects with a maximum database size of 16 TB&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[simple trust]: # 'simple trust&#10;trust model used by Windows NT where every domain had to have a manually set trust relationship with any other domain (cf. "transitive trust")&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[transitive trust]: # 'transitive trust&#10;trust model used by Active Directory, whereby if A trusts B and B trusts C, then A also trusts C (cf "simple trust)&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[ADAM]: #ad-lds 'Active Directory Application Mode (ADAM)&#10;standalone LDAP service similar to full Active Directory, but without DNS, Group Policy, or Kerberos requirements (ref. AD LDS)&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[ADFS]: # 'Active Directory Federated Services (ADFS)&#10;standards-based technology that enables distributed identification, authentication, and authorization across organizational and platform boundaries; used by the Web Application Proxy role service of Remote Access role to authenticate corporate users to allow access to intranet web applications from the outside&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[IMU]: # 'Identity Management for Unix (IMU)&#10;manage user accounts and passwords on Windows and Unix via NIS; automatically synchronize passwords between Windows and Unix&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[DIT]: # 'Directory Information Tree (DIT)&#10;ESE database file that stores Active Directory objects in flat database rows and columns&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[Multimaster]: # 'Multimaster&#10;Windows NT domain model with multiple user domains (each of which having two-way trust with the others), and multiple resource domains (each of which had one-way trust with every user domain); each trust had to be manually set&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[Single-domain]: # 'Single-domain&#10;Windows NT domain model with only one domain and no trusts&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[Single-master]: # 'Single-master&#10;Windows NT domain model with a single user (or account) domain and multiple resource domains, each of which had one-way trusts with the user domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[Complete-trust]: # 'Complete-trust&#10;Windows NT domain model where any domain could create accounts, and each could access shared resources in any other domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[GUID]: # 'Globally Unique Identifier (GUID)&#10;128-bit number assigned to Active Directory objects by the system at the time of their creation; Microsoft implementation of the UUID concept&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[DN]: #distinguished-names 'distinguished name (DN)&#10;Hierarchical paths used to uniquely reference any object in LDAP or Active Directory which typically take the form of comma-delimited prefix-name pairs&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[DC]: # 'domain controller (DC)&#10;Server that responds to security authentication requests within a Windows Server domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[domain tree]: # 'domain tree&#10;series of domains connected together hierarchically using a contiguous naming scheme&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[forest]: # 'forest&#10;collection of one or more domain trees which share a common Configuration container and Schema and are connected together through transitive trusts&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[forest trust]: # 'forest trust&#10;single transitive trust between two forest root domains&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 23'
[OU]: # 'organizational unit (OU)&#10;Primary container type used to house objects in Active Directory&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 24'
[GC]: # 'Global Catalog (GC)&#10;Read-only catalog of all objects in an Active Directory forest, used to perform forest-wide searches.&#10;Accessible via LDAP over port 3268.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 25'
[FSMO]: # 'Flexible Single Master Operator (FSMO)&#10;Role that a server may own in an Active Directory domain that makes it the master for a particular function or role.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[Schema Master]: # 'Schema Master&#10;Forest-wide domain controller role allowing changes to be made to the Active Directory Schema&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[Domain Naming Master]: # 'Domain Naming Master&#10;Forest-wide domain controller role that controls changes to the forest-wide namespace&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[PDC Emulator]: # 'PDC Emulator&#10;Domain-wide domain controller role that replicates the NT SAM database to NT 4.0 and Windows 3.51 BDCs&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[RID Master]: # 'RID Master&#10;Domain-wide domain controller role that maintains a pool of unique RID values to ensure that all SIDs in a domain are unique.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 27'
[Infrastructure Master]: # 'Infrastructure Master&#10;Domain-wide domain controller role that maintains references to objects in other domains ("phantoms")&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 28'
[NTP]: # 'Network Time Protocol (NTP)&#10;facilitaties time synchronization&#10;Dulaney, Emmett. _CompTIA Network+ N10-007 Exam Cram, 6th Edition_.: 51-52'

#### Active Directory Fundamentals
- [Active Directory Application Mode (ADAM)][ADAM] 
- [Active Directory Federated Services (ADFS)][ADFS] 
- [Directory Information Tree (DIT)][DIT] 
- [Extensible Storage Engine (ESE)][ESE] 
- [Identity Management for Unix (IMU)][IMU] 
- [Security Accounts Manager (SAM)][SAM]
- [Domain Controller (DC)][DC]
- [Distinguished Name (DN)][DN]
- [domain tree][domain tree]
- [X.500][X.500]
- [forest][forest]
- [forest trust][forest trust]
- [simple trust][simple trust] 
- [transitive trust][transitive trust]
- Domain models: 
  - [Multimaster][Multimaster]
  - [Single-domain][Single-domain] 
  - [Single-master][Single-master] 
  - [Complete trust][Complete-trust]
- [organizational unit][OU]
- [Global Catalog][GC]

###### History
[Active Directory][AD] has its origins in 1990 when Microsoft released Windows NT 3.0, its first Network Operating System (NOS).
Limitations of NT led Microsoft to rearchitect their solution based on LDAP, a directory service that originated in 1993 as a lighter-weight alternative to [X.500][X.500].

Feature         | NT  | [AD][AD]
---             | --- | ---
Database        | [SAM][SAM] | [ESE][ESE]
Trust           | [Simple][simple trust] | [Transitive][transitive trust]
Domain models   | [Multimaster][Multimaster] [Single-domain][Single-domain] [Single-master][Single-master] [Complete trust][Complete-trust] | [Complete trust][Complete-trust]
Name resolution | [WINS](#glossary "obsolete system that resolves NetBIOS names to IP addresses on Windows networks; required by Windows NT") | DNS
Schemas         | Not extensible | Extensible

AD objects, which can be **containers** or **non-containers** (leaf nodes), are stored in a [DIT][DIT] file. 
Each object is identified by a [GUID][GUID] but also commonly referred to by [distinguished name][DN] (i.e. `dc=mycorp,dc=com`)

Active Directory's structure is based on the concept of a **domain**, based on the following components:
- Hierarchical structure of containers and objects based on [X.500][X.500]
- DNS domain name
- Security service to provide AAA
- Policies to restrict functionality for users or machines

Domains can be organized into [domain trees][domain tree], and domain trees can be organized into [forests][forest].

The most common container type is the [OU][OU].
[Global Catalog][GC] can be used to search for AD objects.

[FSMO][FSMO] roles include:
- [Schema Master][Schema Master]
- [Domain Naming Master][Domain Naming Master]
- [PDC Emulator][PDC Emulator]
- [RID Master][RID Master]
- [Infrastructure Master][Infrastructure Master]

Because Kerberos, which underlies AD, is sensitive to time differences all computers on a domain must have clocks synchronized to within 5 minutes.
[NTP][NTP] can be useful for this.

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

