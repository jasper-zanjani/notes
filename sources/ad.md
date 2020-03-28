# Active Directory
[adfind]: https://github.com/jasper-zanjani/notes/tree/primary/win/README.md#adfind '```&#10;adfind&#10;```&#10;Command-line utility that can be used to query Active Directory attributes&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 53'
[AD LDS]: #ad-lds 'Active Directory Lightweight Directory Services (AD LDS)&#10;standalone LDAP service similar to full Active Directory, but without DNS, Group Policy, or Kerberos requirements (previously known as Active Directory Application Mode "ADAM")&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 457'
[ADFS]: # 'Active Directory Federated Services (ADFS)&#10;standards-based technology that enables distributed identification, authentication, and authorization across organizational and platform boundaries; used by the Web Application Proxy role service of Remote Access role to authenticate corporate users to allow access to intranet web applications from the outside&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[AD]: # 'Active Directory (AD)&#10;Microsoft network operating system, built on top of Windows Server&#10;AD has origins in Windows NT 3.0, which combined features of the LAN Manager protocols with the OS/2 operating system.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 3'
[Complete-trust]: # 'Complete-trust&#10;Windows NT domain model where any domain could create accounts, and each could access shared resources in any other domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[DC]: # 'domain controller (DC)&#10;Server that responds to security authentication requests within a Windows Server domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[DIT]: # 'Directory Information Tree (DIT)&#10;ESE database file that stores Active Directory objects in flat database rows and columns&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[DN]: #distinguished-names 'distinguished name (DN)&#10;Hierarchical paths used to uniquely reference any object in LDAP or Active Directory which typically take the form of comma-delimited prefix-name pairs&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[Domain Naming Master]: # 'Domain Naming Master&#10;Forest-wide domain controller role that controls changes to the forest-wide namespace&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[ESE]: # 'Extensible Storage Engine (ESE)&#10;Exchange database which provided the basis for Active Directory, developed to hold millions of objects with a maximum database size of 16 TB&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[FSMO]: # 'Flexible Single Master Operator (FSMO)&#10;Role that a server may own in an Active Directory domain that makes it the master for a particular function or role.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[GC]: # 'Global Catalog (GC)&#10;Read-only catalog of all objects in an Active Directory forest, used to perform forest-wide searches.&#10;Accessible via LDAP over port 3268.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 25'
[GUID]: # 'Globally Unique Identifier (GUID)&#10;128-bit number assigned to Active Directory objects by the system at the time of their creation; Microsoft implementation of the UUID concept&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[IMU]: # 'Identity Management for Unix (IMU)&#10;manage user accounts and passwords on Windows and Unix via NIS; automatically synchronize passwords between Windows and Unix&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.'
[Infrastructure Master]: # 'Infrastructure Master&#10;Domain-wide domain controller role that maintains references to objects in other domains ("phantoms")&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 28'
[Multimaster]: # 'Multimaster&#10;Windows NT domain model with multiple user domains (each of which having two-way trust with the others), and multiple resource domains (each of which had one-way trust with every user domain); each trust had to be manually set&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[NTP]: # 'Network Time Protocol (NTP)&#10;facilitaties time synchronization&#10;Dulaney, Emmett. _CompTIA Network+ N10-007 Exam Cram, 6th Edition_.: 51-52'
[OU]: # 'organizational unit (OU)&#10;Primary container type used to house objects in Active Directory&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 24'
[PDC Emulator]: # 'PDC Emulator&#10;Domain-wide domain controller role that replicates the NT SAM database to NT 4.0 and Windows 3.51 BDCs&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[RID Master]: # 'RID Master&#10;Domain-wide domain controller role that maintains a pool of unique RID values to ensure that all SIDs in a domain are unique.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 27'
[SAM]: # 'Security Accounts Manager (SAM)&#10;Database used in Windows NT that had a maximum recommended size of 40 MB&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 7'
[Schema Master]: # 'Schema Master&#10;Forest-wide domain controller role allowing changes to be made to the Active Directory Schema&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 26'
[Single-domain]: # 'Single-domain&#10;Windows NT domain model with only one domain and no trusts&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[Single-master]: # 'Single-master&#10;Windows NT domain model with a single user (or account) domain and multiple resource domains, each of which had one-way trusts with the user domain&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 8'
[X.500]: # 'X.500&#10;ITU and ISO-developed series of directory service standards based on OSI protocol stack; superceded by LDAP&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 5'
[domain tree]: # 'domain tree&#10;series of domains connected together hierarchically using a contiguous naming scheme&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[forest trust]: # 'forest trust&#10;single transitive trust between two forest root domains&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 23'
[forest]: # 'forest&#10;collection of one or more domain trees which share a common Configuration container and Schema and are connected together through transitive trusts&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 21'
[simple trust]: # 'simple trust&#10;trust model used by Windows NT where every domain had to have a manually set trust relationship with any other domain (cf. "transitive trust")&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[transitive trust]: # 'transitive trust&#10;trust model used by Active Directory, whereby if A trusts B and B trusts C, then A also trusts C (cf "simple trust)&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 9'
[distribution group]: # 'distribution group&#10;Active Directory group type used for mailing lists&#10;If a group is of type distribution, its SID is not added to a user security token during logon, so it cannot be used for logon purposes.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 38'
[security group]: # 'security group&#10;&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 38'
[Domain Naming Context]: # 'Domain Naming Context&#10;contains data specific to the domain, like users, groups, and computers&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 43'
[Schema Naming Context]: # 'Schema Naming Context&#10;contains the set of object class and attribute definitions for the types of data that can be stored in AD&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 43'
[Configuration Naming Context]: # 'Configuration Naming Context&#10;contains data pertaining to the configuration of the forest, like naming contexts, LDAP policies, sites, subnets, and Microsoft Exchange&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 43'
[OID]: # 'Object Identifier (OID)&#10;Sequence of integers that describe the unique path to the branch holding any schema object.&#10;Root branches are globally unique and maintained by IANA. OID namespaces are known as Enterprise Numbers.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 55'
[identifier authority]: #sid 'identifier authority&#10;Component of a SID that follows `S-1` that uniquely identifies the authority involved&#10;Possible values include:&#10;  - 0, NULL&#10;  - 1, World&#10;  - 2, Local&#10;  - 5, NT Authority&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 28'
[sub-authority]: #sid 'sub-authority&#10;Component of a SID that follows the identifier authority, the last of which is called the RID.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 28'
[SID]: #sid 'security identifier (SID)&#10;A unique, variable-length identifier used to identify a trustee or security principal of the format `S-1-id-s1-s2-s3-...-s15`&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 28'
[NC]: # 'naming context (NC)&#10;data partition in Active Directory, each of which represents a different type of data&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 43'
[schema]: # 'schema&#10;blueprint for data storage in Active Directory&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 53'
[attribute]: # 'attribute&#10;defines the pieces of information that a class, and thus an instance of that class, can hold&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 53'
[syntax]: # 'syntax&#10;Define the type of data that can be placed into an Active Directory attribute&#10;For example, an attribute defined with a syntax of "Boolean" can store True, False, or null as its value.&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 53'
[site topology]: #site-topology 'site topology&#10;map that describes the network connectivity, Active Directory Replication guidelines, and locations for resources as it relates to the Active Directory forest&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 85'
[site]: #site-topology 'site&#10;a collection of well-connected AD subnets; typically used to group subnets together into a logical collection to help define replication flow and resource location boundaries&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 87'
[subnet]: #site-topology 'subnet&#10;portion of the IP space of a network&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 86'
[site link]: #site-topology 'site link&#10;defines what sites are connected to each other and the relative cost of the connection&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 89'
[connection object]: #site-topology 'connection object&#10;specifies which domain controllers replicate with which other domain controllers, how often, and which naming contexts are involved&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2009.: 92'

- Active Directory components
  - [Active Directory Lightweight Directory Services (AD LDS))][AD LDS] 
    - Instance
    - Configuration set
    - Replica
    - Partition/naming context
    - Application partition
    - Configuration partition
    - Schema partition
    - Bindable object
    - Bindable proxy object
  - [Active Directory Federated Services (ADFS)][ADFS] 
  - [Directory Information Tree (DIT)][DIT] 
  - [Extensible Storage Engine (ESE)][ESE] 
  - [Identity Management for Unix (IMU)][IMU] 
  - [Security Accounts Manager (SAM)][SAM]
  - [Global Catalog][GC]
- Active Directory concepts
  - [Domain Controller (DC)][DC]
  - [Distinguished Name (DN)][DN]
  - [domain tree][domain tree]
  - [forest][forest]
  - [organizational unit][OU]
  - Trust
    - [forest trust][forest trust]
    - [simple trust][simple trust] 
    - [transitive trust][transitive trust]
  - Domain models: 
    - [Multimaster][Multimaster]
    - [Single-domain][Single-domain] 
    - [Single-master][Single-master] 
    - [Complete trust][Complete-trust]
- Groups:
  - [Domain local][domain local group]
  - [Domain global][domain global group]
  - [Universal][universal group]
  - [Distribution][distribution group]
  - [Security][security group]
- [Schema][schema]
  - [attribute][attribute]
  - [syntax][syntax]
- [Site topology][site topology]
  - [site][site] 
  - [subnet][subnet] 
  - [site link][site link] 
  - [connection object][connection object] 

#### Table of Contents
###### 4th edition

<code> [01](#history "A brief introduction&#10;---&#10;Reviews the evolution of the Microsoft NOS and some of the major features and benefits of Active Directory.") </code>
<code> [02](#fundamentals "Active Directory fundamentals&#10;---&#10;Provides a high-level look at how objects are stored in Active Directory and explains some of the internal structures and concepts that it relies on.") </code>
<code> [03](#naming-contexts "Naming contexts and application partisions&#10;---&#10;Reviews the predefined Naming Contexts within Active Directory, what is contained within each, and the purpose of Application Partitions") </code>
<code> [04](#schema "Active Directory Schema&#10;---&#10;Gives you information on how the blueprint for each object and each object's attributes are stored in Active Directory.") </code>
<code> [05](#site-topology "Site topology and replication&#10;---&#10;Details how the actual replication process for data takes place between domain controllers.") </code>
<code> [06](# "Active Directory and DNS&#10;---&#10;Describes the importance of the Domain Name System (DNS) and what it is used for within Active Directory.") </code>
<code> [07](# "Read-Only Domain Controllers&#10;---&#10;Describes the deployment and operation of Read-Only Domain Controllers (RODCs).") </code>
<code> [08](# "Group Policy primer&#10;---&#10;Gives you a detailed introduction to the capabilities of Group Policy Objects and how to manage them.") </code>
<code> [09](# "Fine-grained password policies&#10;---&#10;Comprehensive coverage of how to design, implement, and manage fine-grained password policies.") </code>
<code> [10](# "Designing the namespace&#10;---&#10;Introduces the steps and techniques involved in properly preparing a design that reduces the number of domains and increases administrative control through the use of Organizational Units.") </code>
<code> [11](# "Creating a site topology&#10;---&#10;Shows you how to design a representation of your physical inrastructure within Active Diretory to gain very fine-grained control over intrasite and intersite replication.") </code>
<code> [12](# "Designing organization-wide group policies&#10;---&#10;Explains how Group Policy Objects function in Active Directory and how you can properly design an Active Directory structure to make the most effective use of these functions.") </code>
<code> [13](# "Active Dirctory Security: permissions and auditing&#10;---&#10;Describes how you can design effective security f0or all areas of your Active Directory, in terms of both access to objects and their properties; includes information on how to design effective security access logginging in any areas you choose.") </code>
<code> [14](# "Designing and implementing Schema extensions&#10;---&#10;Covers procedures for extending the classes and attributes in the Active Directory schema.") </code>
<code> [15](# "Backup, recovery, and maintenance&#10;---&#10;Describes how you can backup and restore Active Directory down to the object level or the entire directory.") </code>
<code> [16](# "Upgrading to Windows Server 2003&#10;---&#10;Outlines how you can upgrade your existing Active Directory infrastructure to Windows Server 2003.") </code>
<code> [17](# "Upgrading to Windows Server 2003 R2&#10;---&#10;Outlines the process to upgrade your existing Active Directory to Windows Server 2003 R2.") </code>
<code> [18](# "Upgrading to Windows Server 2008&#10;---&#10;Outlines the process to upgrade your existing Active Directory to Windows Server 2008.") </code>
<code> [19](# "Integrating Microsoft Exchange&#10;---&#10;Covers some of the important Active Directory-related issues when implementing Microsoft Exchange.") </code>
<code> [20](# "Active Directory Lightweight Directory Service (a.k.a. ADAM)&#10;---&#10;Introduces Active Directory Lightweight Directory Services (AD LDS, formerly ADAM).") </code>

<code> [21](# "Scripting with ADSI&#10;---&#10;Introduces ADSI scripting by leading you through a series of step-by-step examples.") </code>
<code> [22](# "IADs and the Property Cache&#10;---&#10;Delves into the concept of the property cache used extensively by ADSI and shows you how to properly manipulate any attribute of any object within it.") </code>
<code> [23](# "Using ADO for searching&#10;---&#10;Demonstrates how to make use of a technology normally reserved for databases and now extended to allow rapid searching for objects in Active Directory.") </code>
<code> [24](# "Users and groups&#10;---&#10;Gives you the lowdown on how to rapidly create users and groups, giving them whatever attributes you desire.") </code>
<code> [25](# "Permissions and auditing&#10;---&#10;Describes how each object contains its own list of permissions and auditing entries that governs how it can be accessed and how access is logged.") </code>
<code> [26](# "Extending the Schema and the Active Directory snap-ins&#10;---&#10;Covers the creation of new classes and attributes programmatically in the schema, and modification of the existing Active Directory snap-ins to perform additional customized functions.") </code>
<code> [27](# "Scripting with WMI&#10;---&#10;Gives a quick overview of WMI and goes through several examples for managing a system, including services, the registry, and the event log. Accessing AD with WMI is also covered, along with the TrustMon and Replication WMI Providers.") </code>
<code> [28](# "Scripting DNS&#10;---&#10;Describes how to manipulate DNS server configuration, zones, and resource records with the WMI DNS Provider.") </code>
<code> [29](# "Programming the Directory with the .NET framework&#10;---&#10;Starts off by providing some background information on the .NET Framework and then dives into several examples using the System.DirectoryServices namespaces with VB.NET.") </code>
<code> [30](# "PowerShell Basics&#10;---&#10;Provides a jumpstart to Windows PowerShell and a quick reference for PowerShell scripting concepts.")  </code>
<code> [31](# "Scripting Active Directory with PowerShell&#10;---&#10;Describes how to manage and manipulate Active Directory using Windows PowerShell.") </code>
<code> [32](# "Scripting Basic Exchange 2003 tasks&#10;---&#10;Tackles common Active Directory-related user and group management tasks for Microsoft Exchange 2000/2003.") </code>
<code> [33](# "Scripting Basic Exchange 2007 tasks&#10;---&#10;Tackles common Active Directory-related tasks for Microsoft Exchange 2007 using Windows PowerShell.") </code>


#### Fundamentals

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

###### Major components
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

Groups can have three different **scopes**:
- [Domain local][domain local group]
- [Domain global][domain global group]
- [Universal][universal group]

Groups and be of two **types**:
- [Distribution][distribution group]
- [Security][security group]

#### Naming contexts
Predefined [NCs][NC] within AD:
- [Domain Naming Context][Domain Naming Context] 
- [Schema Naming Context][Schema Naming Context] 
- [Configuration Naming Context][Configuration Naming Context] 

#### Schema
Each object in AD is an instance of a class defined in the [schema][schema].
The schema version can be queried from the command-line with [`adfind`][adfind]
[OID][OID]

###### SID
A Windows SID is generally composed of 2 fixed fields and up to 15 additional fields, all separated by dashes:

<code> S-v-[id][identifier authority]-[s1][sub-authority]-[s2][sub-authority]-[s3][sub-authority]-[s4][sub-authority]-[s5][sub-authority]-[s6][sub-authority]-[s7][sub-authority]-[s8][sub-authority]-[s9][sub-authority]-[s10][sub-authority]-[s11][sub-authority]-[s12][sub-authority]-[s13][sub-authority]-[s14][sub-authority]-[s15][sub-authority] </code>

#### AD LDS
[AD LDS][AD LDS] offers a pared-down version of AD that is easy to set up and tear down. It was first released in November 2003 as Active Directory Application Mode (ADAM) V1.0 and offers security benefits because it doesn't enable so many services by default. It was renamed AD LDS with the release of Windows Server 2008.

Differences between AD and AD LDS
- AD LDS is a standalone application run from a `dsamain.exe` process (rather than `lsass.exe`), which means it can be started or stopped on demand without rebooting and multiple instances can be run.
- AD LDS lacks the [global catalog](#gc "read-only catalog of all objects in a forest which contains a subset of attributes for each object; used to perform forest-wide searches") functionality (removing [NSPI](# "\"Name Service Provider Interface\", feature supported by Active Directory's global catalog") and [AB](# "\"Address Book\", feature supported by Active Directory's global catalog") as well)

#### Site topology
A [site topology][site topology] is a map of the [sites][site], [subnets][subnet], [site links][site link], site link bridges, and [connection objects][connection object] as it relates to a forest.
