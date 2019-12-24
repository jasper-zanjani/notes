# Active Directory

#### Table of Contents
1. **A Brief Introduction**\
[**History**](#history) [LDAP](#ldap) &bull; **Windows NOSes** [WinNT](#windows-nt) [WS 2003](#windows-server-2003) [WS 2008](#windows-server-2008)
2. **Active Directory Fundamentals**\


### History
#### LDAP
LDAP originated in 1993 as a lighter-weight alternative to [**X.500**](#glossary "ITU and ISO-developed series of directory service standards based on OSI protocol stack; superceded by LDAP"), but it did not gain traction until its third major version was released in 1997.\


#### Windows NT
Active Directory, like its predecessor Windows NT, provides directory services; [**`dcpromo.exe`**](#glossary "wizard that promotes a member server to domain controller") can be used to promote and demote domain controllers.\
Microsoft's first [**NOS**](#glossary "networked environment in which various types of resources, such as user, group, and computer accounts, are stored in a central repository that is controlled by administrators and accessible to end users") was Windows NT 3.0, combining features of LAN Manager protocols and OS/2 (1990). NT allowed administrative delegation only at the domain, but Active Directory allows administrators to define administrative boundaries at the forest, domain, or Organizational Unit.\
In Active Directory, all domains within a forest trust each other via **transitive trust**, which results in a complete-trust model within the forest. Domain models available in NT [[Desmond][Desmond]: 8-9]
- **Complete-trust** any domain could create accounts, and each could access shared resources in any other domain
- **Multimaster** multiple user domains (each of which having two-way trust with the others), and multiple resource domains (each of which had one-way trust with every user domain); each trust had to be manually set
- **Single-master** a single user (or account) domain and multiple resource domains, each of which had one-way trusts with the user domain
- **Single-domain** only one domain and no trusts

Active Directory schemas are [**extensible**](#glossary "schema to which new object types may be added"), whereas NT schemas were not.

Feature         | Windows NT    | Active Directory
---             | ---           | ---
Name resolution | [**WINS**](#glossary "obsolete system that resolves NetBIOS names to IP addresses on Windows networks; required by Windows NT") | DNS
Database        | [**SAM**](#glossary "\"Security Accounts Manager\", NT database with a maximum recommended size of 40 MB") | [**ESE**](#glossary "\"Extensible Storage Engine\", Exchange database which provided the basis for Active Directory, developed to hold millions of objects with a maximum database size of 16 TB")

#### Windows Server 2003
Windows 2000 introduced the concept of [**mixed**](#glossary "Windows 2000 operation mode that allows Win2k and WinNT domain controllers to coexist, but does not support universal or nested groups") and [**native**](#glossary "Windows 2000 operation mode that offers support for universal groups, nested groups, and transitive trust relationships but no support for WinNT domain controllers") operation modes. In Windows Server 2003, this concept was further refined into that of domain and forest [**functional levels**](#glossary "determines available Active Directory domain or forest capabilities") [[Desmond][Desmond]: 10]\
Windows Server 2003 introduced several optional components: [**ADAM**](#glossary "\"Active Directory Application Mode\", standalone LDAP service that is Active Directory with NOS-specific components and requirements removed"), [**ADFS**](#glossary "\"Active Directory Federated Services\", standards-based technology that enables distributed identification, authentication, and authorization across organizational and platform boundaries"), and [**IMU**](#glossary "\"Identity Management for Unix\", manage user accounts and passwords on Windows and Unix via NIS; automatically synchronize passwords between Windows and Unix"). [[Desmond][Desmond]: 14]

#### Windows Server 2008
Windows Server 2008 introduced [**RODC**](#glossary "\"Read-Only Domain Controller\"")s and **Server Core**.


[Desmond]: Desmond, Brian et al. _Active Directory_. O'Reilly: 2009.