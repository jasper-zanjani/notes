# Windows Server

## Certification exams

| Number           | Title                                                      |
| :--------------- | :--------------------------------------------------------- |
| [70-740](70-740) | Installation, storage and Compute with Windows Server 2016 |
| [70-741](70-741) | Networking with Windows Server 2016                        |
| [70-742](70-742) | Identity with Windows Server 2016                          |

Find notes on labs [here](Labs).  

## Installation


Windows Server 2016 installations are determined by the most suitable installation method, option, and edition.

- **Installation methods**: 
    - An **upgrade** is an installation performed in-place with existing data intact and is opposed to a **clean installation**. 
    - A **migration** is a clean installation with old data transferred over.
Migrations are facilitated by [Powershell][Windows Server Migration Tools] and [command prompt][SmigDeploy.exe] tools
- **Installation options** include Desktop Experience, [Server Core][Server Core], and [Nano Server][Nano Server].
- The most important **installation edition** is **Windows Server 2016 Datacenter edition**, which is the only edition to have several important features that figure prominently in the exam.
    - [Storage Spaces Direct][S2D], 
    - [Storage Replica][Storage Replica]
    - [Shielded VMs][shielded virtual machines]
    - [Network controller][network controller].
- Various other installation options exist, including: Windows Server 2016 [Standard][Windows Server 2016 Standard], [Essentials][Windows Server 2016 Essentials], [Multipoint Premium][Windows Server 2016 MultiPoint Premium Server], [Storage][Windows Storage Server 2016], and [Hyper-V][Windows Hyper-V Server 2016] editions.

Server installations are also influenced by choice of [ **activation model** ](#activation). 

### Licensing

**Servicing channels** provide a way of separating users into deployment groups for feature and quality updates.

- **Semi-Annual Channel** - previously known as **Current Branch for Business (CBB)** - features updates twice a year.
It is more appropriate for non-infrastructure workloads that can be deployed through automation.
- **Long Term Servicing Channel (LTSC)** has a minimum servicing lifetime of 10 years and was designed to be used only for specialized devices such as those that control medical equipment or ATM machines, receiving new feature releases every 2-3 years

#### Server Core

Installing the Windows Server 2016 Server Core foregoes the possibility of later switching back to Desktop Experience, as had been possible in previous editions. 
Notably, WDS is incompatible with Server Core installations.

Server Core installations can be managed with a GUI with the use of **MMC snap-ins**. 
Because MMC is reliant on **Distributed Component Object Model (DCOM)** technology, firewall rules have to be enabled to allow DCOM traffic (ref. `Set-NetFirewallRule`).

#### Nano Server

[Nano Server]: #nano-server 'Nano Server&#10;Headless Windows Server installation option with no local user interface, no 32-bit application support, and only basic configuration controls. Administration requires remote WinRM connections and WMI tools&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 42'
[Powershell Core]: #nano-server 'Powershell Core&#10;subset of Powershell Desktop, omitting many of its features&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 57'

[Nano Server][Nano Server], a new installation option introduced in Windows Server 2016, provides a much smaller footprint and attack surface than even Server Core, but supports only some roles and features.
Installation is done by building a VHD image via PowerShell on another computer.
That VHD is then deployed as a VM or used as a boot drive for a physical server.

Booting a Nano Server VM produces a text-based interface called the **Nano Server Recovery Console**, a menu system that allows configuration of static network options (DHCP is enabled by default).
The DNS server may not be configured interactively, but must be specified when building the image with the `Ipv4Dns` parameter.

If a Nano Server is domain-joined a remote Powershell session will authenticate via Kerberos. If not, its name or IP address must be added to the Trusted Hosts list.

The Windows Server 2016 installation media contains a NanoServer directory, from which the **NanoServerImageGenerator** Powershell module must be imported.
It also contains a Packages subdirectory, with CAB files containing roles and features that correspond to named parameters or packages that are specified as values to the `Packages` named parameter when building a Nano Server image.

| Cmdlet                                                                                                                   | Description                                                        |
| :----------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------- |
| [Edit-NanoServerImage](https://docs.microsoft.com/en-us/powershell/module/NanoServerImageGenerator/Edit-NanoServerImage) | Add a role or feature to an existing Nano Server VHD file          |
| [New-NanoServerImage](https://docs.microsoft.com/en-us/powershell/module/NanoServerImageGenerator/New-NanoServerImage)   | Used to create a Nano Server VHD file for Nano Server installation |



### Activation

Server installations are influenced by choice of activation model. 
[MAK][MAK] is suitable for small networks, but large enterprises may opt for [KMS][KMS].
- **MAK** activations are subdivided into [Independent][MAK Independent] and [Proxy][MAK Proxy], based on whether or not a [VAMT][VAMT] is used.
- **KMS** activations, which distribute [GVLK][GVLK]s, are valid for a [period of time][Activation validity interval] and require the installation of a [role][Volume Activation Services] and [management tools][Volume Activation Tools].
KMS operates on TCP port 1688.
- [**AVMA**][AVMA] simplifies the process of activating Hyper-V VMs running Windows Server 2012 or 2016.

[**Active Directory-based activation**][Active Directory-based activation] is an alternative for enterprises who opt to activate licenses through the existing AD DS domain infrastructure.

Any domain-joined computers running a supported OS with a GVLK will be activated automatically and transparently.
The domain must be extended to the Windows Server 2012 R2 or higher schema level, and a **KMS host key** must be added using the VAMT.
After Microsoft verifies the KMS host key, client computers are activated by receiving an activation object from the DC. <sup>[MS Docs](https://docs.microsoft.com/en-us/windows/deployment/volume-activation/activate-using-active-directory-based-activation-client)</sup>



### Images

Many enterprises have begun virtualizing their server environments to take advantage of the many cost, reliability, and performance benefits that this change creates.

Migrations should start with systems that are peripheral to main business interests before moving on to those that are more vital.
A carefully documented protocol should be developed to facilitate the conversion of physical hard disks to VHDs for use in Hyper-V guests.
Supported guest OSes include Linux and FreeBSD.

The **Microsoft Assessment and Planning (MAP) Toolkit** is a free software tool that intelligently constructs a database of the hardware, software, and performance of computers on a network to plan for an operating system upgrade or virtualization.
MAP supports the following discovery methods:

- Active Directory Domain Services
- Windows networking protocols
- System Center Configuration Manager
- IP address range scanning
- Computer names entered manually or imported from a file

Server Core relies on the command-line for system maintenance, including updates which must be installed directly to the image using `dism.exe` or equivalent Powershell commands.

## Containers

Containers run applications in an **isolated namespace**, meaning it only has access to resources that are made available to it by the container runtime.
**Resource governance** means that a container has access only to a specified number of processor cycles, system memory, and other resources.
Containers allow applications to be packaged with their dependencies in **container images**, which will run the same regardless of underlying operating system or infrastructure and are downloaded from **container registries** like **Docker Hub**.
Container registries are not to be confused with **repositories**, which are subcomponents of registries.
Windows Server 2016 suports **Windows Server Containers** and **Hyper-V Containers**, which create a separate copy of the operating system kernel for each container.

The "Containers" feature must be installed on Windows Server 2016 hosts, and to create Hyper-V containers the Hyper-V role must also be installed (although the Hyper-V management tools are not necessary if VMs are not going to created).
Windows container hosts need to have Windows installed to C:.

Nano Server once could serve as Docker hosts, but no longer; Nano Servers are now intended to be deployed as containers themselves.
The [Powershell Docker module](https://github.com/microsoft/Docker-PowerShell "PowerShell for Docker") has been deprecated for years.

Docker has several options for containers to store files in a persistent manner:
- **Volumes** are stored in a part of the host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Docker).
- **Bind mounts** may be stored anywhere on the host system and are specified by [`docker run --volume`][docker run -&#118;].
- **`tmpfs` mounts** are stored in the host system's memory only, and are available only on Linux.

## DNS

### Installation
DNS server role requiremenets:
- Statically assigned IP
- Signed-in user must be member of local Administrators group

There are several recommended DNS deployment scenarios, all of which involve installing DNS on a [ Server Core ](Server-Core) or [ Nano Server ](Nano-Server) instance.
This is because these installation options offer a reduced attack surface, a reduced resource footprint, and reduced patching requirements.
- **DNS on DC**: 
All DNS features are available and supports AD-integrated, primary, secondary, and stub zones.
- **DNS on RODC**: 
Passes DNS zone updates to a writeable DC
- **DNS on standalone member server**: 
Supports **file-based** primary, secondary, and stub zones but requiring zone replication 
because there is no integration over AD.

### Nano Server
Installing DNS on a running Nano Server image requires running [`Install-NanoServerPackage`](NanoServerPackage) as well as enabling the "DNS-Server-Full-Role" optional feature using `Enable-WindowsOptionalFeature`.

As of early 2017, Nano Server only supported a few roles, including [DNS](DNS), but was only able to do so with some limitations
- Nano Server can only support file-based DNS and cannot host AD-integrated zones.
- Nano Server only supports the [Semi-Annual servicing channel](Servicing-Channels) license.
- Nano Server is not suitable for primary zones, only caching-only, forwarder, or secondary zone DNS servers

### Zones

**Zones** can be considered one or more DNS domains or subdomains, associated with **zone files**, which compose the DNS database itself and contain two types of entries:

- **Parser commands**, which provide shorthand ways to enter records: `$ORIGIN`, `$INCLUDE`, and `$TTL`
- **Resource records** are whitespace delimited text files with columns for name, time to live, class, type, and data

The copies of zone files local to individual DNS servers can be **primary** (read/write) or **secondary** (read-only).
A primary zone is a writable copy of a DNS zone that exists on a DNS server.
A secondary zone is a read-only replica of a primary zone and necessitates the presence of a primary zone for the same zone.
Defining a secondary zone via PowerShell requires specifying that zone's `MasterServers`.

In Windows Server, zone files can also be integrated with Active Directory, making what is called an **Active Directory Integrated Zone**.
These allow **multi-master zones**, meaning any DC can process zone updates and the zone can be replicated to any DC in the domain or forest.

An AD-integrated zone can be specified by passing the `ReplicationScope` parameter to the [`Add-DnsServerPrimaryZone`](dnsserver) cmdlet.

**Stub zones** contains only name server (NS) records of another zone, but unlike a forwarder is able to update when name servers in a target zone change.

**Reverse Lookup zones** are used to resolve IP addresses to FQDNs.
Reverse lookup zones for public IP address space are often administered by ISPs, and they are useful in spam filtering to double-check the source domain name with the IP address.

**GlobalNames zones** provide "single label name resolution" (as opposed to a FQDN) and are intended to replace WINS servers.

### Query traffic

The process of resolving a query by querying other DNS servers is called **recursion**.
Recursion can be disabled outright but Windows Server 2016 supports **recursion scopes** which will allow recursion to be disabled unless certain conditions are met (such as receiving the request on a particular interface).

There are two types of query in the context of recursion:
- **Recursive query** sent by the petitioner: that is, the original query which begins recursion.
- **Iterative query**: individual queries sent out to authoritative name servers in order to resolve a recursive query.

**Root hints** are preconfigured root servers that are necessary to begin the recursion process.
The DNS Server service stores root hints in `%systemroot%\System32\dns\CACHE.DNS`.
These can be edited through the GUI or by using the PowerShell commands `Add-`, `Import-`, `Remove-`, and `Set-DnsServerRootHint`. 

**Forwarding** of a request occurs when a petitioned DNS server is unable to resolve the query because it is both:
- Non-authoritative for the specified zone, and
- Does not have the response cached.

Two actions are possible when forwarding:
- Configure a DNS server only to respond to queries it can satisfy by referencing locally-stored zone information, forwarding all other requests.
- Configure forwarding for specific zones through **conditional forwarding**

A secondary zone is not to be confused with **delegation**, where a DNS server delegates authority over part of its namespace (i.e. a subdomain) to one or more other servers.

Windows Server 2016 supports a DNS **GlobalNames** zone meant to supercede WINS, which served a role similar to DNS for the old NetBIOS naming standard.
NetBIOS names use a nonhierarchical structure (i.e. are a single name and not divisible into sub-domains) based on a name up to 16 characters long (although the 16th character defines a particular service running on the host defined by the previous 15).
An organization must share a single GlobalNames zone, which must be created in PowerShell manually.

### Resource records 

**Zone scavenging** allows servers with stale records to remove them.
This feature is disabled by default, but can be set at the server or zone level.

| Type  | Description                                                                                        |
| :---- | :------------------------------------------------------------------------------------------------- |
| A     | IPv4 address record                                                                                |
| AAAA  | IPv6 address record                                                                                |
| CNAME | Hostname or alias for hosts in the domain                                                          |
| MX    | Where mail for the domain should be delivered                                                      |
| NS    | Name servers                                                                                       |
| PTR   | Reverse lookup                                                                                     |
| SOA   | Each zone contains a single SOA record                                                             |
| SRV   | Generalized service location record, used for newer protocols instead of protocol-specific records |
| TXT   | Typically holds machine-readable data                                                              |


### Security

- [DNSSEC](#dnssec) offers security features using public key certificates.
- A **socket pool** can be used to configure the DNS server to use a random source port when issuing DNS queries.
- **Response rate limiting** can pose a defense against DNS DoS attacks by ignoring potentially malicious, repetitive requests.
- **DNS-based Authentication of Named Entities (DANE)** is supported by Windows Server 2016 to reduce man-in-the-middle attacks.
DANE works by informing DNS clients requesting records from the domain which Certification Authoority they must expect digital certificates to be issued from.

### Policies

**Zone transfer policies** can prevent or allow zone transfers to any server, to name servers, or to servers specified by FQDN or IP address.
DNS Policy is a new feature in Windows Server 2016 that can control DNS server behavior depending on certain criteria.

These criteria include:

- Client subnet
- Recursion scope
- Zone scope

### DNSSEC

DNSSEC is a security setting for DNS that enables all DNS records in a zone to be digitally signed by a **trust anchor** which validates DNSKEY resource records.
Root and top-level domain zones already have trust anchors configured and merely have to have it enabled.

To implement trust anchors:
- A TrustAnchors zone must be created, which will store public keys associated with specific zones.
A trust anchor from the secured zone must be created on every DNS server that hosts the zone.
- A **Name Resolution Policy Table (NRPT)** GPO must be created (Windows Settings\Name Resolution Policy)
This option can require DNSSEC based on computer name prefix or suffix, FQDN, or subnet.
- **DNSSEC key master** is a special DNS server that generates and manages signing keys for DNSSEC protected zones.
DANE allows you to publish certificate information within the DNS zone, rather than one of the thousands of trusted CAs.
This protects against rogue/compromised CAs issuing illegitimate TLS certificates.

Two cryptographic keys:
- **Zone Signing Key (ZSK)** signs zone data including individual resource records other than DNSKEY.
It is also used to create the KSK.
- **Key Signing Key (KSK)** is used to sign all DNSKEY records at the zone root.

DNSSEC record types:
- **RRSIG** "resource record signature" each of which matches and provides a signature for an existing record in a zone
- **NSEC** proves nonexistence of a record
- **NSEC3** NSEC replacement that prevents zone walking
- **NSEC3PARAM** specifies the NSEC3 records included in response for DNS names that don't exist
- **DNSKEY** stores public key used to verify a signature
- **DS** delegation signer records secure delegations

## DSC

IaaS management of servers is possible with **Desired State Configuration (DSC)**, a feature of Windows PowerShell where script files stored on a central server can apply specific a specific configuration to nodes.
These scripts are **idempotent**, meaning that they can be applied repeatedly without generating errors.

The DSC model is composed of phases
1. **Authoring** Phase, where MOF definitions are created
2. **Staging** Phase, where declarative MOFs are staged and a Configuration calculated per node
3. **"Make It So"** Phase, where declarative Configurations are implemented through imperative providers

Components of DSC scripts include:
- **Local Configuration Manager**: engine running on the client system that received configurations from the DSC server and applies them to the target.
- **Node block** specifies the names of **target** computers.
- **Resource block** specifies settings or components and the values that the configuration script should assign to them.

DSC configurations can be deployed in two different **refresh modes** 

| ![](/img/pullmodel.png)                                                                                                       | ![](/img/pushmodel.png)                                                                                                                                                                                                                        |
| ---------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Pull architecture**: target LCM periodically retrieves configuration from a **Pull Server**, which consolidates MOF files. | **Push architecture**: configuration is sent to target in response to explicit invocation of [`Start-DSCConfiguration`](https://docs.microsoft.com/en-us/powershell/module/psdesiredstateconfiguration/Start-DscConfiguration) on the server. |

LCM has to be [configured](#tasks "Set LCM to push mode") to accept Configurations of either refresh mode.


#### Tasks


Set LCM to push mode
```powershell
[DSCLocalConfigurationManager()]
Configuration LCMConfig 
{
  Node localhost 
  {
    Settings 
    {
      RefreshMode = 'Push'
    }
  }
}
```

Install Telnet client
```powershell
Configuration InstallTelnetLocal { 
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Node localhost 
  {
    WindowsOptionalFeature InstallTelnet 
    {
      Name = "Telnet-Client"
      Ensure = "Present"
    }
  }
}
```

Install WSL
```powershell
Configuration InstallWSLLocal { 
  Import-DscResource -ModuleName 'PSDesiredStateConfiguration'
  Node localhost   
  {
    WindowsOptionalFeature InstallWSL     
    {
      Name = "Microsoft-Windows-Subsystem-Linux"
      Ensure = "Present" 
    }
  }
}
```


## Failover clusters

[failover cluster]: #high-availability 'failover cluster&#10;group of two or more computers, physical or virtual, running the same application that functions as a single entity to provide high availability, scalability, and fault tolerance&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 311'
[CNO]: #failover-clustering 'cluster name object (CNO)&#10;Computer object in Active Directory associated with a failover cluster&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 313'
[SoFS]: # 'Scale-Out File Server (SoFS)&#10;clustered role that is designed to provide highly available storage for applications, like Hyper-V and SQL Server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 337'
[Add-ClusterScaleOutFileServer]: #add-clusterscaleoutfileserver '```&#10;PS C:\> Add-ClusterScaleOutFileServer&#10;```&#10;Install the Scale-out File Server role&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 339'
[guest failover cluster]: #failover-clustering 'guest failover cluster&#10;consists solely of VMs running on a single Hyper-V host server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 341'
[witness]: #high-availability 'witness&#10;resource that casts a vote for the continued operation of a cluster&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 318'
[quorum]: #high-availability 'quorum&#10;provides each node and witness in a cluster with a vote, to prevent a cluster from developing split-brain&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 317'
[Active Directory-detached cluster]: #high-availability 'Active Directory-detached cluster&#10;Cluster whose nodes are joined to a domain but which is not associated with a cluster name object (CNO) in AD&#10;In such a cluster, the name of the cluster and nodes must be registered in DNS, but the nodes still must be joined to an AD DS domain.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 337'
[New-Cluster]: #new-cluster '```&#10;PS> New-Cluster&#10;```&#10;Create a new failover cluster&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 337'

[Failover clusters][failover cluster] are composed of computers called **nodes** and can be created using [`New-Cluster`][New-Cluster].
which typically possess a secondary network adapter, used for cluster communications. 

Before Windows Server 2016, all cluster nodes had to belong to the same domain, but now this is but one of several possible cluster types called a **single-domain** cluster.
A failover cluster can also be **multi-domain**, or **workgroup**, depending on how or if the servers are joined to domains.
A cluster can also be [detached][Active Directory-detached cluster] from AD, even though its nodes are joined.

A cluster whose servers are joined to a single domain is typically associated with a [cluster name object][CNO] in Active Directory, which serves as its **administrative access point**.
A workgroup cluster or a detached cluster need to have the cluster's network name registered in DNS as its administrative access point, which can be specified in Powershell with the `AdministrativeAccessPoint` named parameter.
Additionally, on a workgroup cluster the same local administrator account must be created on every node, preferably the builtin Administrator account, although a different account can be configured if a particular Registry key is [created][New-ItemProperty] on each node.

Nodes that are domain-joined support CredSSP or Kerberos authentication, but workgroup nodes support NTLM authentication only.

Three types of [**witness**][witness] resources can help to ensure a [**quorum**][quorum] takes place in clusters. 
This is necessary to prevent a **split-brain** situation, where communication failures between nodes cause separate segments of the clusters to continue operating independently of each other.
A witness is created when a cluster has an even number of nodes, and only one can be configured. <sup>[pwsh][Set-ClusterQuorum]
- **Disk witness**: dedicated disk in shared storage that contains a copy of the cluster database
- **File Share witness**: SMB file share containing a Witness.log file with information about the cluster
- **Cloud witness**: blob stored in Azure

[**Scale-out File Server (SoFS)**][SoFS] is a clustered role providing highly available storage to cluster nodes.
SoFS ensures continuous availability in the case of a node failure.
Using SoFS, multiple nodes can also access the same block of storage at the same time, and for this reason is is an **active/active** or **dual active** system, as opposed to one where only one node provides accessible shares, or an **active/passive** system. 

SoFS is specifically recommended for use on Hyper-V and SQL Server clusters and can be installed with [`Add-ClusterScaleOutFileServer`][Add-ClusterScaleOutFileServer].

SoFS shares are created with the [`New-SmbShare`][New-SmbShare] PowerShell cmdlet.
SoFS shares are located on **Cluster Shared Volumes (CSV)**, a shared disk containing an NTFS or ReFS volume that is made accessible for read and write operations by all nodes within a failover cluster.

CSVs solved a historical problem with using NTFS volumes with VMs in previous versions of Windows Server.
NTFS is designed to be accessed by only one operating system instance at a time.
In Windows Server 2008 and earlier, this meant that only one node could access a disk at a time, which had to be mounted and dismounted for every VM.

The solution was to create a pseudo-file system called **CSVFS**, sitting on top of NTFS, that enables multiple drives to modify a disk's content at the same time, but restricting access to the metada to the owner or **coordinator**.
The **coordinator node** refers to the cluster node where NTFS for the clustered CSV disk is mounted, any other node is called a **Data Server (DS)**.

VM resiliency can be configured by adjusting settings in response to changes in VM state:
- **Unmonitored**: VM owning a role is not being monitored by the Cluster Service
- **Isolated**: Node is not currently an active member of the cluster, but still possess the role
- **Quarantine**: Node has been drained of its roles and removed from the cluster for a specified length of time.

**Cluster Operating System Rolling Upgrade** is a new feature that reduces downtime by making it possible for a cluster to have nodes running both Windows Server 2012 R2 and Window Server 2016.
Using this feature, nodes can be brought down for an upgrade.

When [Storage Spaces][Storage Spaces] is combined with a failover cluster, the solution is known as **Clustered Storage Spaces**.

### High availability

[Hyper-V Replica]: #high-availability 'Hyper-V Replica&#10;feature of the Hyper-V role that allows creation of a replica of VMs on a Hyper-V server to another server, locally or remote&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 297'
[replica server]: #high-availability 'replica server&#10;term used to designate the destination server in a failover solution&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 299'
[Shared Nothing Live Migration]: #high-availability 'Shared Nothing Live Migration&#10;migration of VM data, memory, and system state to another host&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 307'
[Live Migration]: #high-availability 'Live Migration&#10;migration of VM state and live memory contents to another host, but not its data&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 303'
[Storage Migration]: #high-availability 'Storage Migration&#10;migration of VM virtual hard disk files to another host, but not its memory and system state&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 371'
[site-aware failover cluster]: #high-availability 'site-aware failover cluster&#10;Contains fault domains based on the values of a site property configured for each node, which are used to determine its behavior during failovers and other role transfers&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 366'
[failover affinity]: #high-availability 'failover affinity&#10;Behavior of a site-aware failover cluster where failover occurs to a node at another site only when all the nodes in the original site are found to be unavailable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 366'
[node fairness]: #high-availability 'node fairness&#10;Balances distribution of VMs on cluster nodes&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 366'

[**Hyper-V Replica**][Hyper-V Replica] allows simple failover to occur between Hyper-V hosts, without the need for a cluster.
To configure a simple **one-way** failover solution using Hyper-V Replica, configure the **destination** VM as a [**replica server**][replica server], either in Hyper-V Manager or PowerShell. <sup>[`Set-VMReplicationServer`][Set-VMReplicationServer] [lab](#hyper-v-replica-lab)</sup>
The destination host must also have firewall ports opened corresponding to the authentication method chosen.
The source VM, which is to be replicated, must have its options configured through the **Enable Replication wizard**. <sup>[`Enable-VMReplication`][Enable-VMReplication]</sup>
To use Hyper-V Replica as a (two-way) failover solution, configure both VMs as replica servers.

Migrations can take place one of three methods:
- [**Live Migration**][Live Migration] moves only the system state and live memory contents, not data files.
Live migration requires that the hosts be, if not clustered, at least part of the same (or a trusted) domain.
Live Migration requires that VHD files be placed on shared storage and both hosts have appropriate permissions to access said storage.
An unpopulated VM is created on the destination with the same resources as the source before transferring memory pages. 
Once the servers have an identical memory state, the source VM is suspended and the destination takes over. 
Hyper-V  notifies the network switch of the change, diverting network traffic to the destination. 
Authentication can be made by [CredSSP][CredSSP] or Kerberos.

[Add-ClusterVirtualMachineRole]: #add-clustervirtualmachinerole '```&#10;[PS] Add-ClusterVirtualMachineRole&#10;```&#10;Creates a clustered virtual machine, that is, a virtual machine that can be failed over if necessary to a different server in the failover cluster.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 304'

When a Hyper-V cluster is created, the Failover Cluster Manager launches the High Availability Wizard, which configures the VM to support Live Migration. 
The same thing can be done with the PowerShell cmdlet [`Add-ClusterVirtualMachineRole`][Add-ClusterVirtualMachineRole].

Additionally, using Kerberos authentication for live migration requires **constrained delegation**, which enables a server to act on behalf of a user for only certain defined services.
This must be configured within **Active Directory Users and Computers**, by opening the Properties of the source Computer object, and changing the setting under the **Delegation** tab.
  - An additional, outdated method of migration is **quick migration**, which was present in Windows Server prior to the introduction of live migration and persists in Windows Server 2016 for backward compatibility.
A quick migration involves pausing the VM, saving its state, moving the VM to the new owner, and starting it again.
A quick migration always involves a short period of VM downtime.

- [**Shared Nothing Live Migration**][Shared Nothing Live Migration] requires that source and destination VMs be members of the same (or trusted) domain, and source and domain servers must be running the same processor family (Intel or AMD) and linked by an Ethernet network running a minimum of 1 Gbps. 
Additionally, both Hyper-V hosts must be running idential virtual switches that use the same name; otherwise the migration process will be interrupted to prompt the operator to select a switch on the destination server. 
The process of migrating is almost identical to a Live Migration, except that you select the "Move the Virtual Machine's Data To a Single Location" option on the Choose Move Options page of the Move Wizard.
- [**Storage Migration**][Storage Migration] works by first creating new VHDs on the destination corresponding to those on the source server.
While the source server continues to operate using local files, Hyper-V begins mirroring disk writes to the destination server and begins a single-pass copy of the source disks to the destination begins, skipping blocks that have already been copied.
Once the copy has completed, the VM begins working from the destination server and the source files are deleted.
For a VM that is shut off, storage migration is equivalent to simply copying files from source to destination.

[Site-aware][site-aware failover cluster] clusters have [failover affinity][failover affinity].
[Node fairnes][node fairness] evalutes memory and CPU loads on cluster nodes over time.


### Cluster management

**VM Monitoring** allows specific services to be restarted or failed-over when a problem occurs.
To use VM Monitoring:
- The guest must be joined to the same domain as the host
- The host administrator must be a member of the guest's local Administrators group
- And Windows Firewall rules in the **Virtual Machine Monitoring group** must be enabled.

The service can then be monitored using [`Add-ClusterVMMonitoredItem`][Add-ClusterVMMonitoredItem].

### Migration
[quick migration]: #moving-cluster-vms 'quick migration&#10;move a running or stopped VM after what is usually a brief pause by first copying the memory of the VM to disk and then from the disk to the destination&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 370'

VMs can be moved from node to node of a cluster using [live][Live Migration], [storage][Storage Migration], or [quick][quick migration] migrations.

VM **network health protection** is a feature (enabled by default) that detects whether a VM on a cluster node has a functional connection to a designated network.
If not, the cluster live migrates the VM role to another node that does have such a connection.
This setting can be controlled in **Hyper-V Manager** > VM Settings > Advanced Features > **Protected network**


## GPO

[DFS]: #31-gpo-creation-and-management 'Distributed File System (DFS)&#10;suite of client and server services that allow an organization using Microsoft Windows servers to organize many distributed SMB file shares into a distributed file system&#10;"Universal Windows Platform apps". _Wikipedia_.'
[scoping]: # 'scoping&#10;Process of determining which computers and users are impacted by the settings in a GPO&#10;Warren, Andrew. _Exam Ref 70-742: Identity with Windows Server 2016_. 2017.: 161'

**Group Policy Objects (GPO)** facilitate the uniform administration of large numbers of users and computers.
GPOs can be **local** or **domain-based**.

Local GPOs come in several varieties, applied in the following order (last takes highest precedence):
- **Local Group Policy** applied to computers
- **Administrators and Non-Administrators Local Group Policy** applied to users based on their membership in local **Administrators** group.
- **User-specific Local Group Policy**:

Domain-based GPOs consist of two components a [**container**][Group Policy container] and a [**template**][Group Policy template].
These are stored in different locations and replicated by different means.
- Containers define the fundamental attributes of a GPO, each of which is assigned a GUID, and are stored in the AD DS database and replicated to other domain controllers using intrasite or intersite AD DS replication schedule.
- Templates, a collection of files and folders that define the actual GPO settings, are stored in the `SYSVOL` shared folder (`%SystemRoot%\SYSVOL\Domain\Poligicies\{GUID}`) on all DCs.
`SYSVOL` replication is handled by the **[DFS][DFS] Replication Agent** since Windows Server 2008.

A GPO consists of 2 top-level nodes:
- **Computer Configuration** contains settings that are applied to computer objects to which the GPO is linked
- **User Configuration** containers user-related settings, applied when a user signs in and thereafter and automatically refreshed every 90-120 minutes

Beneath **each** of these nodes are folders that group settings
- **Software Settings**
- **Windows Settings** allows basic configuration for computers or users
- **Administrative Templates** contains Registry settings that control user, computer, and app behavior and settings, grouped logically into folders

Although domain controllers store and serve GPOs, the client computer itself must request and apply the GPOs using the **Group Policy Client** service.
**Client-side extensions** process the GPOs once downloaded

**Starter GPOs** are intended for use in large organizations with a proliferation of GPOs that share settings.
Starter GPOs can be imported from, and exported to, a .CAB file.

Once a GPO is created it must be **linked** to a **container object** in AD DS for it to apply to objects, a process known as [**scoping**][scoping].
GPOs can be linked to Sites, Domains, and OUs.
If multiple GPOs are linked to the same container, the **link order** must be configured.

There are 2 default GPOs in an AD DS domain, which can be reset using arguments to the `dcgpofix` command.
- Default Domain Policy, linked to the domain object
- Default Domain Controllers Policy, linked to the Domain Controllers OU

Although it is possible to link the same GPO to multiple containers, it is recommended to **import** (i.e. copy) a GPO from another domain.
This process effecitvely restores the settings of another GPO into a newly created GPO, which is then linked to another container.


## Hyper-V

[Hyper-V][Hyper-V] is a Type I hypervisor and role that allows a Windows Server 2016 **host** to create VMs, called **guests**.
In Type I virtualization, the hypervisor forms an abstraction layer that interacts directly with the host hardware.
In this model, the individual environments created by the hypervisor, including the host operating system and guest VMs, are called [partitions][partition].

Hyper-V Server, a free product available for download is limited to the command-line Server Core interface, however it does include `Sconfig` to aid configuration.

Hyper-V can be managed remotely using the GUI (Hyper-V Manager, `hyper-v-tools`), or Powershell (`hyper-v-powershell`).
Authentication can be via Kerberos or **Credential Security Support Provider (CredSSP)**, which must be enabled on both server and client.

PowerShell remoting
- **Explicit remoting** involves opening a PowerShell session to a remote session
- **Implicit remoting** involves running a cmdlet specifying the `ComputerName` parameter.
**PowerShell Direct** allows easy remoting to VMs by using the `-VmName` Powershell parameter using a PowerShell session.

[Nested virtualization][Nested virtualization] is a new capability where a virtual host running Windows Server 2016 on a physical host also running Windows Server 2016 can host nested VMs.

### Host configuration

[Hyper-V][Hyper-V] is a Type I hypervisor and role that allows a Windows Server 2016 **host** to create VMs, called **guests**.
In Type I virtualization, the hypervisor forms an abstraction layer that interacts directly with the host hardware.
In this model, the individual environments created by the hypervisor, including the host operating system and guest VMs, are called [partitions][partition].

Hyper-V Server, a free product available for download is limited to the command-line Server Core interface, however it does include `Sconfig` to aid configuration.

Hyper-V can be managed remotely using the GUI (Hyper-V Manager, `hyper-v-tools`), or Powershell (`hyper-v-powershell`).
Authentication can be via Kerberos or **Credential Security Support Provider (CredSSP)**, which must be enabled on both server and client.

PowerShell remoting
- **Explicit remoting** involves opening a PowerShell session to a remote session
- **Implicit remoting** involves running a cmdlet specifying the `ComputerName` parameter.
**PowerShell Direct** allows easy remoting to VMs by using the `-VmName` Powershell parameter using a PowerShell session.

[Nested virtualization][Nested virtualization] is a new capability where a virtual host running Windows Server 2016 on a physical host also running Windows Server 2016 can host nested VMs.


### Networking

<!-- Concepts -->
[external virtual switch]: #hyper-v-networking 'external virtual switch&#10;bound to networking protocol stack in the host operating system and connected to a physical network interface adapter on the host, allowing VMs to access the network to which the physical adapter is connected&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[internal virtual switch]: #hyper-v-networking 'internal virtual switch&#10;Bound to a separate instance of the networking protocol stack in the host operating system, independent from the physical network interface adapter and its connected network, it allows VMs to access the virtual network, including the host operating system.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[legacy network adapter]: #hyper-v-networking 'legacy network adapter&#10;Also "emulated network adapter", one of two types of virtual network adapter supported by Generation 1 VMs in Hyper-V, which makes calls directly to the hypervisor.&#10;Generation 1 VMs could not boot from PXE without a legacy network adapter, however their performance is worse than that of synthetic network adapters.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 248'
[Microsoft Network Adapter Multiplexor Driver]: #hyper-v-networking 'Microsoft Network Adapter Multiplexor Driver&#10;Network component installed after configuring a NIC team in Window Server 2016&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 249'
[private virtual switch]: #hyper-v-networking 'private virtual switch&#10;Exists only in the Hyper-V server and is accessible only to the VMs running on it, and is inaccessible to the host operating system itself.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 241'
[RDMA]: #hyper-v-networking 'Remote Direct Memory Access (RDMA)&#10;network adapter technology and network transmission method that can send large amounts of data with low latency and without processor intervention&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'
[SET]: #hyper-v-networking 'Switch Embedded Teaming (SET)&#10;Hyper-V-only variation of NIC teaming that is implemented wholly within a virtual switch&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'
[synthetic network adapter]: #hyper-v-networking 'synthetic network adapter&#10;One of two types of virtual network adapter supported by Generation 1 VMs in Hyper-V, which does not correspond to a real-world product.&#10;Hyper-V synthetic network adapters communicate with the host operating system through the VMBus&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 247'
[VMQ]: #hyper-v-networking 'Virtual Machine Queue (VMQ)&#10;Network performance enhancement feature enabled by Windows Server 2016 automatically when it detects physical network adapters that run at 10 Gbps or faster. &#10;Physical network adapter that support VMQ filters inbound packets based on the destination address and then forwards queues for each to the host operating system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 251'
[LACP]: # 'Link Aggregation Control Protocol (LACP)&#10;common aggregation protocol that allows multiple physical ports to be bound together&#10;Dulaney, Emmett. _CompTIA Network+ N10-007 Exam Cram, 6th Edition_.: 121'


<!-- Powershell cmdlets-->
[Enable-NetAdapterRdma]: #enable-netadapterrdma '```&#10;PS C:\> Enable-NetAdapterRdma&#10;```&#10;Enable RDMA on adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'
[Enable-NetAdapterVmq]: #enable-netadaptervmq '```&#10;PS C:\> Enable-NetAdapterVmq&#10;```&#10;Enable VMQ on a specific adapter&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Get-NetAdapterRdma]: #get-netadapterrdma '```&#10;PS C:\> Get-NetAdapterRdma&#10;```&#10;Display the current RDMA status of network adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 254'
[Get-NetAdapterVmq]: #get-netadaptervmq '```&#10;PS C:\> Get-NetAdapterVmq&#10;```&#10;Discover whether physical network adapters support VMQ&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Get-NetAdapterVmqQueue]: #get-netadaptervmqqueue '```&#10;PS C:\> Get-NetAdapterVmqQueue&#10;```&#10;See which VMQ queries are assigned to which processors&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 252'
[Set-NetAdapterVmq]: #set-netadaptervmq '```&#10;PS C:\> Set-NetAdapterVmq&#10;```&#10;Modify default VMQ settings&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 253'

Virtual switches can be [external][external virtual switch], [internal][internal virtual switch], or [private][private virtual switch] (in order of decreasing access).
Up to 8 network adapters can be [added][Add-VMNetworkAdapter] to a Windows Server 2016 Hyper-V VM.

Hyper-V maintains a pool of MAC addresses which are assigned to virtual network adapters as they are created.
Hyper-V MAC addresses begin with `00-15-5D`, followed by the last two bytes of the IP address assigned to the server's physical network adapter (i.e. last two octets), then a final byte.

Generation 1 VMs supported [synthetic][synthetic network adapter] and [legacy][legacy network adapter] virtual network adapters, but in Generation 2 VMs only synthetic adapters are used.
Generation 1 VMs can only boot from network (PXE) when using a legacy adapter.

Physical hosts running Windows Server 2016 can support teams of up to 32 NICs, but Hyper-V VMs are limited to teams of two.
The team must first be configured in the host operating system and appears as a single [interface][Microsoft Network Adapter Multiplexor Driver] in the Virtual Switch Manager.
High-performance [embedded teaming][SET], reliant on [RDMA][RDMA], can only be configured with [Powershell](PowerShell#create-a-virtual-switch-with-set-enabled).
- **Teaming Mode** 
  - **Switch Independent**: switch is unaware of presence of NIC team and does not load balance to members; Windows is performing the teaming
  - **Switch Dependent**: switch determines how to distribute inbound network traffic; only supported by specialty hardware
    - **Static Teaming**: switch and host are manually configured (typically supported by server-class switches)
    - [**Link Aggregation Control Protocol (LACP)**][LACP]: dynamically identifies links that are connected between the host and the switch
- **Load Balancing Mode**
  - **Address Hash**: a hash is created based on address components of the packet, which is used to reasonably balance adapters
  - **Hyper-V Port**: NIC teams configured on Hyper-V hosts give VMs independent MAC addresses
  - **Dynamic**: outbound loads are distributed based on a hash of the TCP ports and IP addresses

[Virtual machine queuing][VMQ] will enhance performance if a physical host [supports][Get-NetAdapterVmq] it and it is [enabled][Enable-NetAdapterVmq].

Bandwidth management is achieved by setting limits on the virtual network adapter, in the GUI or in [Powershell][Set-VMNetworkAdapter].



### Storage

[checkpoint]: #hyper-v-storage 'checkpoint&#10;Captured image of the state, data, and hardware configuration of a virtual machine at a specific moment in time.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 228'
[production checkpoint]: #hyper-v-storage 'production checkpoint&#10;Feature of Windows Server 2016 Hyper-V that uses the Volume Shadow Copy Service in Windows or File System Freeze in Linux to create a snapshot of the data of a VM without saving memory state.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 230'
[differencing disk]: #hyper-v-storage 'differencing disk&#10;Paired with a baseline virtual disk image to preserve it in its original state.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 223'
[VHD set]: #hyper-v-storage 'VHD set&#10;Shared virtual drive option new in Windows Server 2016, that allows resizing, migration, backup, and replication from the host server, none of which are possible with shared VHDX files.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 222'
[pass-through disk]: #hyper-v-storage 'pass-through disk&#10;virtual disk that points to a virtual disk&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 225'


The New Virtual Machine Wizard presents different options for Generation 1 vs. Generation 2 VMs.
- **Generation 1** VMs provide two IDE controllers, which host the hard drive and a DVD drive, and an unpopulated SCSI controller which can host additional disks.
- **Generation 2** VMs, however, have only a single SCSI controller, which hosts all virtual drives.

A new VHD can be created using 
- Hyper-V Manager through the New Virtual Hard Disk Wizard
- Disk Management (`diskmgmt.msc`), however the option to create a [differencing][differencing disk] disk is not available, nor can specific block or sector size be specified
- PowerShell

Shared virtual disk files are preferably created as [VHD sets][VHD set].
[Pass-through][pass-through disk] disks make exclusive use of a physical disk. <sup>[pwsh](PowerShell#pass-through-disk)</sup>

[**Standard checkpoints**][checkpoint] (previously known as "snapshots" in Windows Server 2012 and before) with the extensions AVHD or AVHDX save the state, data, and hardware configuration of a VM.
They are recommended for development and testing but are not a replacement for backup software nor recommended for production environmentsj, because restoring them in a production environment will interrupt running services.
[**Production checkpoints**][production checkpoint] do not save memory state, but use **Volume Shadow Copy Service** (Windows) or **File System Freeze** (Linux) inside the guest to create "point in time" images of the VM.


### Shielded VMs

[Shielded VMs]: # 'Shielded Virtual Machine&#10;Windows Server 2016 Datacenter edition feature that provides VMs with protection from compromised administrators that have access to the Hyper-V host computer by encrypting the VM state and virtual disks&#10;A shielded VM is a generation 2 VM that has a virtual TPM, is encrypted using BitLocker, and can run only on healthy and approved hosts in a guarded fabric.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 6'
[guarded host]: # 'Guarded host&#10;Windows Server 2016 Datacenter edition Hyper-V host that can run shielded VMs only if it can prove that it is running in a known, trusted state to the HGS.'

> Shielded VMs are a feature exclusive to the Datacenter Edition of Windows Server 2016.

As a result of increased virtualization, physical servers that were once secured physically were migrated to Hyper-V hosts that are less secure because they are accessible to **fabric administrators**.
[**Shielded VMs**][Shielded VMs] were introduced to protect **tenant workloads** from inspection, theft, and tampering as a result of being run on potentially compromised hosts.

A security concept closely associated to shielded VMs is the **guarded fabric**, which is a collection of nodes cooperating to protect shielded Hyper-V guests. The guarded fabric consists of:
- **Host Guardian Service (HGS)** utilizes **remote attestation** to confirm that a node is trusted; if so, it releases a key enabling the shielded VM to be started. HGS is typically a cluster of 3 nodes.
- [**Guarded hosts**][guarded host]: Windows Server 2016 Datacenter edition Hyper-V hosts that can run shielded VMs only if they can prove they are running in a known, trusted state to the Host Guardian Service.
- Shielded VMs

In a production environment, a **fabric manager** like _Virtual Machine Manager_ would be used to deploy shielded VMs (which are signified by a shield icon).

Shielded VMs must run Windows (8+) or Windows Server (2012+), although Linux shielded VMs are now also supported since version Windows Server version 1709.

Shielded VMs are produced by a three-stage process (VHD -> Shielded template -> Shielded VMs)
1. **Preparation**: Install and configure an OS onto a virtual disk file
2. **Templatization**: Convert virtual disk file into a **shielded template**
3. **Provisioning**: Create one or more shielded VMs from the shielded template

Configure HGS in its own new forest <sup>[YouTube](https://youtu.be/DQI3PX0PEAc)</sup>
```powershell
Install-WindowsFeature HostGuardianServiceRole -Restart
Install-HgsServer -HgsDomainName 'savtechhgs.net' -SafeModeAdministratorPassword $adminPassword -Restart
```

**Shielding Data** is created and owned by tenant VM owners and contains secrets needed to create shielded VMs that must be protected from the fabric admin.

Resources:

- [Intro to shielded VMs](https://youtu.be/Vp5E1-4Ks8E)
- [Create a shielded VM using Powershell](https://docs.microsoft.com/en-us/windows-server/security/guarded-fabric-shielded-vm/guarded-fabric-create-a-shielded-vm-using-powershell)
- [Linux Shielded VM How To](https://github.com/Microsoft/lsvmtools/blob/master/doc/LSVM_How_To.pdf)
- [Shielded VM Demonstration and Quick Setup](https://youtu.be/DQI3PX0PEAc)
- [Guarded Fabric Deployment Guide for Windows Server 2016](https://gallery.technet.microsoft.com/Shielded-VMs-and-Guarded-98d2b045)
- [Deploying Shielded VMs and a Guarded Fabric with Windows Server 2016](https://youtu.be/B2vFrdXd5jg)

#### Attestation

There are [two modes](https://docs.microsoft.com/en-us/windows-server/security/guarded-fabric-shielded-vm/guarded-fabric-and-shielded-vms) of **attestation** supported by HGS: 

- **Hardware-trusted attestation**Hardware-trusted attestation mode [requires](https://youtu.be/B2vFrdXd5jg?t=375): 
    - **Measured boot**: TPMv2 to seal software and hardware configuration details measured at boot
    - **Code integrity enforcement** to strictly define permissible software
    - **Platform Identity Verification**: Active Directory is not sufficient to identify the host. Rather, an identity key rooted in the host TPM is used for identity.
- **Remote attestation** based on asymmetric key pairs
- <strike>**Admin-trusted attestation**</strike> was previously based on guarded host membership in a designated AD DS security group, but is deprecated beginning with Windows Server 2019.
    - Host identity is [verified]](https://youtu.be/B2vFrdXd5jg?t=525) by checking security group permission
    - **No** Measured Boot or Code Integrity Validation
    - Intended to aid transition to Hardware-trusted attestation mode for hosts produced before TPMv2


### VM configuration

[NUMA]: #vm-configuration 'Non-Uniform Memory Access (NUMA)&#10;system architecture used to increase memory efficiency in computers with multiple processors by dividing logical processors and memory into NUMA nodes, with each node containing one or more logical processors and the region of memory closest to them&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 189'
[NUMA ratio]: #vm-configuration 'NUMA ratio&#10;difference between accessing local and remote memory for any processor&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 189'
[Smart paging]: #vm-configuration 'Smart paging&#10;Hyper-V feature that enables the host server to compensate when its memory is overcommitted by using disk space for memory paging only during the boot sequence&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 192'
[Resource metering]: #vm-configuration 'Resource metering&#10;Hyper-V feature that makes it possible to track the resources a VM uses as it operates&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 193'
[DDA]: #vm-configuration 'Discrete Device Assignment (DDA)&#10;Hyper-V feature that enables passthrough of any PCI Express device, including GPUs or network adapters&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 212'
[Integration Services]: #vm-configuration 'Integration Services&#10;software package containing drivers and other components that runs on a guest operating system, enabling it to communicate with the Hyper-V host server&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 195'
[LIS]: #vm-configuration 'Linux Integration Services (LIS)&#10;Linux driver for Hyper-V specific devices&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 204'
[Secure Boot]: #vm-configuration 'Secure Boot&#10;UEFI feature that ensures components loaded during the boot sequence have been digitally signed, and therefore trusted by the computer manufacturer&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 205'
[Enhanced session mode]: # 'Enhanced session mode&#10;Hyper-V feature available when the host and guest are both running a recent version of Windows, whereby a VM being accessed through VMConnect can utilize resources on the host.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 200'

[Set-VMMemory]: #set-vmmemory '```&#10;[PS] Set-VMMemory&#10;```&#10;Configures the memory of a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 185'

VMs are associated with a variety of file types:

| Extension   | Description                 |
| :---------- | :-------------------------- |
| .vmc        | XML-format VM configuration |
| .vhd, .vhdx | Virtual hard disks          |
| .vsv        | Saved-state files           |

VMs can be created in Hyper-V, and a machine's RAM can even be changed dynamically.

Hyper-V guests can take advantage of a suite of features to enhance performance and functionality.
- Virtualization of [NUMA][NUMA] architecture
- [Smart paging][Smart paging] for when VMs that use dynamic memory restart and temporarily need more memory than is available on the host, for example at boot
- [Monitoring][resource metering] resource usage, to minimize cost overruns when guests run in the cloud
- Disk and GPU passthrough, and other PCI-x devices, with [DDA][DDA] <sup>[pwsh](PowerShell#implement-dda)</sup>
- [Increased performance][Enhanced session mode] of interactive sessions that use [VMConnect][VMConnect.exe]

Microsoft supports some Linux distributions, like Ubuntu, with built-in [Linux][LIS] [Integration Services][Integration Services], which improve performance by providing custom drivers to interface with Hyper-V.
Some distributions like CentOS and Oracle come with integrated LIS packages, but free LIS packages provided by Microsoft for download from the Microsoft Download Center support additional features and come with the additional benefit of being versioned.
These packages are provided as tarballs or ISO images, and must be loaded directly into the running guest operating system.
FreeBSD has included full support for FreeBSD Integration Services (BIS) since version 10.

[Set-VMFirmware]: #set-vmfirmware '```&#10;[PS] Set-VMFirmware&#10;```&#10;Sets the firmware configuration of a virtual machine.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 208'

[Secure Boot][Secure Boot] has to be disabled when loading Hyper-V VMs running Linux distributions, since UEFI does not have certificates for non-Windows operating systems by default. 
Some distributions supported by Microsoft do have certificates in the [UEFI Certificate Authority][Set-VMFirmware].

Different versions of Hyper-V create VMs associated with that version (Windows Server 2016 uses Hyper-V 8.0).
VMs created by older versions of Hyper-V can be [updated][Update-VMVersion], but once updated they may no longer run on a host of a previous version.

Importing an exported VM can be done in three ways: 
- **Register**: exported files are left as-is and the guest's ID is maintained; 
- **Restore**: exported files copied to the host's default locations or ones that are otherwise specified; ID is maintained
- **Copy**: exported files are copied; new ID generated

PXE boot is supported in two scenarios:
- Generation 1 VMs with a [**legacy**][legacy network adapter] virtual network adapter support PXE boot (but not [**synthetic**][synthetic network adapter]). Generation 1 VMs are limited to 2 TB in size and do not support many of the advanced features that Generation 2 VMs do. But PXE Boot remains one of the primary reasons to continue using a Generation 1 VM.
- Generation 2 VMs with a synthetic network adapter also support PXE boot. would also support bandwidth management and VMQ.

Generation 2 VMs also do not support 32-bit OSes, including:
- Windows Server 2008, R2
- Windows 7
- Older Linux distros
- FreeBSD (all)

VMs cannot be upgraded from Generation 1 to Generation 2 easily, although a script named `Convert-VMGeneration` was once provided by Microsoft and can still be found.
But the VM's **version**, referring to the version of Hyper-V used to create it, **can** be upgraded with [ `Upgrade-VMVersion` ](Hyper-V).


## Monitoring

**Performance Monitor** is a program that allows realtime monitoring of hundreds of different system performance statistics, called **performance counters**.
Counters can be viewed in several ways, including line graph, histogram bar graph, and report views.
Every counter added to a graph is associated with a computer, a **performance object** (hardware or software component to be monitored), a performance counter (statistic), and an instance.

A **data collector set** captures counter statistics for later review.
A single data collector set can gather performance counter data from multiple VMs.
Event trace data cannot be combined with performance data in the same data collector set.
Expiration dates can be set for data collector sets, but if actively collecting data the expiration date will not stop collection.

A **performance alert** is a type of data collector set that can track system performance and log events in the application event log.

**Alerts** can be triggered when a **performance counter** value exceeds a certain threshold.
Only members of the local groups **Administrators** and **Performance Log Users** can create alerts, but the **Log on as a batch user** right must be granted to members of Performance Log Users.

A **hard fault** occurs when data is swapped between memory and disk.

### Performance counters

[Processor: % Processor Time]: #performance-counters 'Processor: % Processor Time&#10;Percentage of time that the processor is busy, a basic measure of computer activity&#10;85% or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 434'
[Processor: Interrupts/Sec]: #performance-counters 'Processor: Interrupts/Sec&#10;Number of hardware interrupts processor is servicing each second&#10;Must be baselined&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 435'
[System: Processor Queue Length]: #performance-counters 'System: Processor Queue Length&#10;Number of program threads waiting to be executed by the processor&#10;2 or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 434'
[Server Work Queues: Queue Length]: #performance-counters 'Server Work Queues: Queue Length&#10;Number of requests waiting to use a specific processor&#10;4 or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 434'
[Memory: Page Faults/Sec]: #performance-counters 'Memory: Page Faults/Sec&#10;Number of times per second that the code or data needed for processing is not found in memory&#10;5 or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 435'
[Memory: Pages/Sec]: #performance-counters 'Memory: Pages/Sec&#10;Number of times per second that required information was not in RAM and had to be accessed from disk or had to be written to disk to make room in RAM&#10;20 or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 435'
[Memory: Available MBytes]: #performance-counters 'Memory: Available MBytes&#10;Amount of available physical memory in MB&#10;At least 5% of physical memory is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[Memory: Committed Bytes]: #performance-counters 'Memory: Committed Bytes&#10;Amount of virtual memory that has space reserved on the disk paging file&#10;Should always be less than the amount of physical RAM&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[Memory: Pool Non-Paged Bytes]: #performance-counters 'Memory: Pool Non-Paged Bytes&#10;Size of an area in memory used by the operating system for objects that cannot be written to disk&#10;Should be stable, unless directly associated with increased server activity&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[PhysicalDisk: Disk Bytes/Sec]: #performance-counters 'PhysicalDisk: Disk Bytes/Sec&#10;Average number of bytes transferred to or from the disk each second&#10;Should be compared to baseline&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[PhysicalDisk: Avg. Disk Bytes/Transfer]: #performance-counters 'PhysicalDisk: Avg. Disk Bytes/Transfer&#10;Average number of bytes transferred during read and write operations&#10;Should be compared to baseline&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[PhysicalDisk: Current Disk Queue Length]: #performance-counters 'PhysicalDisk: Current Disk Queue Length&#10;Number of pending disk read or write requests&#10;2 or less per disk spindle are acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 436'
[PhysicalDisk: % Disk Time]: #performance-counters 'PhysicalDisk: % Disk Time&#10;Percentage of time that the disk drive is busy&#10;90% or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 437'
[LogicalDisk: % Free Space]: #performance-counters 'LogicalDisk: % Free Space&#10;Percentage of free space on the disk&#10;20% or greater is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 437'
[Network Interface: Bytes Total/Sec]: #performance-counters 'Network Interface: Bytes Total/Sec&#10;Number of bytes sent and received per second by the selected network interface adapter&#10;Should be compared to baseline&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 437'
[Network Interface: Output Queue Length]: #performance-counters 'Network Interface: Output Queue Length&#10;Number of packets waiting to be transmitted by the network interface adapter&#10;2 or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 437'
[Server: Bytes Total/Sec]: #performance-counters 'Server: Bytes Total/Sec&#10;Total number of bytes sent and received by the server over all network interfaces&#10;50% of total bandwidth capacity or less is acceptable&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 437'

| Counter                                                                            | Acceptable values         |
| ---------------------------------------------------------------------------------- | ------------------------- |
| [Processor: % Processor Time][Processor: % Processor Time]                         | &lt;85%                   |
| [Processor: Interrupts/Sec][Processor: Interrupts/Sec]                             | cf. baseline              |
| [System: Processor Queue Length][System: Processor Queue Length]                   | &lt;2                     |
| [Server Work Queues: Queue Length][Server Work Queues: Queue Length]               | &lt;4                     |
| [Memory: Page Faults/Sec][Memory: Page Faults/Sec]                                 | &lt;5                     |
| [Memory: Pages/Sec][Memory: Pages/Sec]                                             | &lt;20                    |
| [Memory: Available MBytes][Memory: Available MBytes]                               | &gt;5% of physical memory |
| [Memory: Committed Bytes][Memory: Committed Bytes]                                 | &lt; physical memory      |
| [Memory: Pool Non-Paged Bytes][Memory: Pool Non-Paged Bytes]                       | Stable                    |
| [PhysicalDisk: Disk Bytes/Sec][PhysicalDisk: Disk Bytes/Sec]                       | cf. baseline              |
| [PhysicalDisk: Avg. Disk Bytes/Transfer][PhysicalDisk: Avg. Disk Bytes/Transfer]   | cf. baseline              |
| [PhysicalDisk: Current Disk Queue Length][PhysicalDisk: Current Disk Queue Length] | &lt;2 per spindle         |
| [PhysicalDisk: % Disk Time][PhysicalDisk: % Disk Time]                             | &lt;90%                   |
| [LogicalDisk: % Free Space][LogicalDisk: % Free Space]                             | &gt;20%                   |
| [Network Interface: Bytes Total/Sec][Network Interface: Bytes Total/Sec]           | cf. baseline              |
| [Network Interface: Output Queue Length][Network Interface: Output Queue Length]   | &lt;2                     |
| [Server: Bytes Total/Sec][Server: Bytes Total/Sec]                                 | 50% of total bandwidth    |


## Network Load Balancing

[drain on shutdown]: #nlb 'drain on shutdown&#10;feature of Windows Server 2016 Failover Clustering which automatically live migrates all roles on a node before shutting down the system&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 374'

Cluster VMs can be configured to [drain][drain on shutdown] their workloads to other nodes when being shutdown using `Suspend-ClusterNode`

NLB Clusters are made of **hosts**, while Failover Clusters are made of **nodes**.

NLB **port rules** control how the cluster functions and are defined by two operational parameters:

- **Affinity**: associate client requests to cluster hosts. 
When no affinity is specified, all network requests are load-balanced across the cluster without regard to their source.
- **Filtering mode**: specify how the cluster handles traffic described by port range and protocols; can be single or multiple hosts.

When a port rule is not configured, the default host will receive all network traffic.

Windows Server NLB Clusters can be upgraded to Windows Server 2016 in two ways:
- **Rolling** upgrade brings only a single host down at a time, upgrading it before adding it and proceeding to the next one
- **Simultaneous** upgrade brings the entire NLB cluster goes down

NLB clusters have a **Cluster Operation Mode** setting specifying what kind of TCP/IP traffic the cluster hosts should use
- **Unicast**: NLB replaces the MAC address on the interface with the cluster's virtual MAC address, causing traffic to go to all hosts. 
Cluster hosts are prevented from communicating with each other in this mode.
In this case, a **second network adapter** must be installed in order to facilitate normal communication between NLB cluster hosts.
- **Multicast**: NLB adds a multicast MAC address to the network interface on each host that does not replace the original.

## Storage
[block]: #disks-and-volumes 'allocation unit (block)&#10;smallest amount of disk space that the computer can allocate when storing a file (sometimes incorrectly called a "sector")&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[sector]: #disks-and-volumes 'sector&#10;subdivision of a track, traditionally 512 bytes (Advanced Format disks use 4,096-byte sectors)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[slack space]: #disks-and-volumes 'slack space&#10;space left over when a file occupies only part of a block&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[VHD]: #disks-and-volumes 'VHD&#10;"Virtual Hard Disk", virtual hard disk image format and file name extension supported by Windows Server.&#10;VHD images are limited to a maximum size of 2 TB and are compatible with servers running Windows Server 2008 or later, or workstations running Windows 7 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'
[VHDX]: #disks-and-volumes 'VHDX&#10;Newer hard disk image format and file name extension.&#10;VHDX image files can be as large as 64 TB, and they also support 4 KB logical sector sizes to provide compatibility with 4 KB native drives. VHDX files can be read only by servers running Windows Server 2012 or later or workstations running Windows 8 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'
[NTFS]: #disks-and-volumes 'NT File System (NTFS)&#10;Default file system for Windows Server since 1993.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 93'
[ReFS]: #disks-and-volumes 'Resilient File System (ReFS)&#10;New file system that uses checksums to protect volume metadata and supports the same system of permissions as NTFS; intended for use in Storage Spaces pools.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 94'
[MBR]: #images 'Master Boot Record (MBR)&#10;Older partition table type introduced in 1983 that is still common, despite its limitations.&#10;MBR partitions supports volumes up to 2 TB in size with up to 4 primary partitions.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 85'
[GPT]: #images 'GUID partition table (GPT)&#10;Newer partition table type, introduced in the late 1990s, but not supported in Windows prior to Windows Server 2008 and Windows Vista.&#10;The GPT specification supports an unlimited number of partitions on volumes up to 18 exabytes.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 86'

Every track of a hard drive platter is split into disk [sectors][sector], traditionally 512 bytes.
A [block][block] is commonly called an "allocation unit" in Windows, but also commonly called a cluster.
Storage left over unused in partially unused [blocks][block] is known as [slack space][slack space].

A new disk must first be **initialized**, that is, a **partition table** style must be chosen:
- [GPT][GPT]: 128 partitions per disk, maximum volume size of 18 exabytes (2<sup>60</sup> bytes). Booting from a GPT drive is not possible  unless the computer architecture supports EFI-based boot partitions.
- [MBR][MBR]: older format that is commonly used for removable media, supporting volumes up to 2 TB with up to 4 **primary partitions**, although a common workaround is to make one of these partitions an **extended partition**, which can be be further subdivided into logical drives

Mounting a **partition** as a single filesystem produces a **volume**, although the distinction can often be lost.
The exception would be a case where a volume spans multiple partitions or physical disks, as is possible with software RAID.

**Virtual hard disks** can be created with [Powershell][New-VHD] or in `diskmgmt.msc` and come in two formats:
- [VHD][VHD]
- [VHDX][VHDX]

Only 2 filesystem options are available for modern servers:
- [NTFS][NTFS] supports volumes up to 16 TB with the default 4 KB allocation unit size (but 256 TB with the 64 KB allocation unit size) and is required by some Windows Server services like **AD DS**, **File Replication Service**, **Volume Shadow Copy Service**, and **Distributed File System**
- [ReFS][ReFs] uses the same system of permissions as NTFS and offers error checking and repair capabilities that NTFS does not, but it does not support NTFS features like file compression, **Encrypted File System**, and disk quotas. ReFS supports a maximum file size of 16 exabytes and volumes up to **1 yobibyte** (2<sup>80</sup> bytes)

Software RAID can be implemented by creating **Spanned**, **Striped**, or **RAID-5** volumes in `diskmgmt.msc`.
A more modern and preferred technique is to create **storage pools** in  [Storage Spaces][Storage Spaces].

### Dedup

[Data deduplication]: # 'Data deduplication&#10;role service in Windows Server 2016 that conserves storage space on an NTFS volume by locating redundant data and storing only one copy of that data instead of multiple copies; ReFS support was introduced with Windows Server version 1709&#10;Data deduplication replaces the earlier Single Instance Store (SIS) technology in earlier versions of Windows Server.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 155'
[chunk store]: # 'chunk store&#10;separate area of the disk where unique chunks are kept&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 158'
[reparse point]: # 'reparse point&#10;special tag that replaces the location of a chunk that already exists in the store&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 158'
[churn]: # 'churn&#10;accumulation of unoptimized files due to the workload of the volume&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 158'
[garbage collection]: # 'garbage collection&#10;job that searches the chunk store for chunks that no longer have reparse points associatd with them, typically due to modified or deleted files&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 158'
[integrity scrubbing]: # 'integrity scrubbing&#10;job that searches for damage or corruption in the chunk store, replacing missing data with mirror or parity data&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 158'
[unoptimization]: # 'unoptimization&#10;job that restores all of the optimized files on a volume to their original states, disabling Data Deduplication for that volume in the process&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 159'

[**Data deduplication**][Data deduplication] ("dedup") is a role service that conserves storage space by storing only one copy of redundant chunks of files.
Data duplication is appropriate to specific workloads, like backup volumes and file servers.
It is not appropriate for database storage or operating system data or boot volumes.
> Data deduplication **had required NTFS**, although ReFS is supported since 1709.

[Enable-DedupVolume]: PowerShell#enable-dedupvolume '```&#10;Enable-DedupVolume&#10;```&#10;Enables data deduplication on one or more volumes.'

Data deduplication runs as a low-priority background process when the system is idle, by default; however its behavior can be [configured][Enable-DedupVolume] based on its intended usage.
Deduplication works by scanning files, and breaking them into unique **chunks** of various sizes that are collected in a [chunk store][chunk store].
The original locations of chunks are replaced by [reparse points][reparse point].
When a file is recently written, it is written in the standard, unoptimized form; the accumulation of such files is known as [churn][churn].
Other jobs associated with deduplication include [garbage collection][garbage collection], [integrity scrubbing][integrity scrubbing], and (when disabling deduplication) [unoptimization][unoptimization].

There are several deployment scenarios considered for data deduplication:
- **General purpose file servers** Users often store multiple copies of the same, or similar, documents and files. Up to 30-50% of this space can be reclaimed using deduplication.
- **Virtualized Desktop Infrastructre (VDI) deployments** Virtual hard disks that are used for remote desktops are essentially identical. Data Deduplication can also amelioriate the drop in storage performance when many users simultaneously log in at the start of the day, called a **VDI boot storm**.
- **Backup** snapshots are an ideal deployment scenario because of the data is so duplicative.

Deduplication is especially useful for disk drive backups, since snapshots typically differ little from each other.

### File shares

Windows Server 2016 supports file shares via two protocols, both of which require the `fs-fileserver` role service:
- **SMB**, long the standard for Windows networks
- **NFS**, typically used in Linux, requires the installation of `fs-nfs-service` role service

**BranchCache** enables client computers at remote locations to cache files accessed from shares, so that other computers at the same location can access them.
Install the `FS-BranchCache` feature and enable the `File and Printer Sharing` and `Branchcache - Hosted Cache Server (uses HTTPS)` firewall display groups.


### Media

[block]: #disks-and-volumes 'allocation unit (block)&#10;smallest amount of disk space that the computer can allocate when storing a file (sometimes incorrectly called a "sector")&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[sector]: #disks-and-volumes 'sector&#10;subdivision of a track, traditionally 512 bytes (Advanced Format disks use 4,096-byte sectors)&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[slack space]: #disks-and-volumes 'slack space&#10;space left over when a file occupies only part of a block&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 82'
[VHD]: #disks-and-volumes 'VHD&#10;"Virtual Hard Disk", virtual hard disk image format and file name extension supported by Windows Server.&#10;VHD images are limited to a maximum size of 2 TB and are compatible with servers running Windows Server 2008 or later, or workstations running Windows 7 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'
[VHDX]: #disks-and-volumes 'VHDX&#10;Newer hard disk image format and file name extension.&#10;VHDX image files can be as large as 64 TB, and they also support 4 KB logical sector sizes to provide compatibility with 4 KB native drives. VHDX files can be read only by servers running Windows Server 2012 or later or workstations running Windows 8 or later.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 88'
[NTFS]: #disks-and-volumes 'NT File System (NTFS)&#10;Default file system for Windows Server since 1993.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 93'
[ReFS]: #disks-and-volumes 'Resilient File System (ReFS)&#10;New file system that uses checksums to protect volume metadata and supports the same system of permissions as NTFS; intended for use in Storage Spaces pools.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 94'
[MBR]: #images 'Master Boot Record (MBR)&#10;Older partition table type introduced in 1983 that is still common, despite its limitations.&#10;MBR partitions supports volumes up to 2 TB in size with up to 4 primary partitions.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 85'
[GPT]: #images 'GUID partition table (GPT)&#10;Newer partition table type, introduced in the late 1990s, but not supported in Windows prior to Windows Server 2008 and Windows Vista.&#10;The GPT specification supports an unlimited number of partitions on volumes up to 18 exabytes.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 86'

Every track of a hard drive platter is split into disk [sectors][sector], traditionally 512 bytes.
A [block][block] is commonly called an "allocation unit" in Windows, but also commonly called a cluster.
Storage left over unused in partially unused [blocks][block] is known as [slack space][slack space].

A new disk must first be **initialized**, that is, a **partition table** style must be chosen:
- [GPT][GPT]: 128 partitions per disk, maximum volume size of 18 exabytes (2<sup>60</sup> bytes). Booting from a GPT drive is not possible  unless the computer architecture supports EFI-based boot partitions.
- [MBR][MBR]: older format that is commonly used for removable media, supporting volumes up to 2 TB with up to 4 **primary partitions**, although a common workaround is to make one of these partitions an **extended partition**, which can be be further subdivided into logical drives

Mounting a **partition** as a single filesystem produces a **volume**, although the distinction can often be lost.
The exception would be a case where a volume spans multiple partitions or physical disks, as is possible with software RAID.

**Virtual hard disks** can be created with [Powershell][New-VHD] or in `diskmgmt.msc` and come in two formats:
- [VHD][VHD]
- [VHDX][VHDX]

Only 2 filesystem options are available for modern servers:
- [NTFS][NTFS] supports volumes up to 16 TB with the default 4 KB allocation unit size (but 256 TB with the 64 KB allocation unit size) and is required by some Windows Server services like **AD DS**, **File Replication Service**, **Volume Shadow Copy Service**, and **Distributed File System**
- [ReFS][ReFs] uses the same system of permissions as NTFS and offers error checking and repair capabilities that NTFS does not, but it does not support NTFS features like file compression, **Encrypted File System**, and disk quotas. ReFS supports a maximum file size of 16 exabytes and volumes up to **1 yobibyte** (2<sup>80</sup> bytes)

Software RAID can be implemented by creating **Spanned**, **Striped**, or **RAID-5** volumes in `diskmgmt.msc`.
A more modern and preferred technique is to create **storage pools** in  [Storage Spaces][Storage Spaces].


### S2D

[hyper-converged S2D scenario]: # 'hyper-converged S2D scenario&#10;combines S2D with Hyper-V in a single cluster&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 357'
[disaggregated S2D scenario]: # 'disaggregated S2D scenario&#10;has two distinct clusters: a Scale-out File Server cluster that uses S2D to provide the storage for the second, a Hyper-V cluster hosting VMs&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 355'

Although a cluster can normally be created in the GUI **Failover Cluster Manager**, in order to use **Storage Spaces Direct** the system must be prevented from automatically creating storage, which necessitates creation in PowerShell with the `NoStorage` switch parameter, and then S2D must be enabled using `Enable-ClusterStorageSpacesDirect`.
This command scans all cluster nodes for **local, unpartitioned disks**, which are added to a single storage pool and classified by media type in order to use the fastest disks for caching.

The recommended drive configuration for a node in an S2D cluster is a minimum of six drives, with at least 2 SSDs and at least 4 HDDs, with no RAID or other intelligence that cannot be disabled.

Caching is configured automatically, depending on the combination of drives present
- **NVMe + SSD**: NVMe drives are configured as a **write-only** cache for the SSD drives
- **NVMe + HDD**: NVMe drives are read/write cache
- **NVME + SSD + HDD**: NVME are write-only for the SSD drives and read/write for HDD drives
- **SSD + HDD**: SSD drives are read/write cache

Microsoft defined two deployment scenarios for Storage Spaces Direct:
- [**Disaggregated**][disaggregated S2D scenario] which creates two separate clusters, one of which is a [Scale-out File Server][SoFS] dedicated to storage, essentially functioning as a SAN.
This solution requires the [DCB][DCB] role for traffic management.
At least two 10Gbps Ethernet adapters are recommended per node, preferably adapters that use RDMA.
- [**Hyper-converged**][hyper-converged S2D scenario], where a single cluster node hosts VMs and storage.
This solution is much less expensive because it requires less hardware and generates much less network traffic, but storage and compute can't scale independently:
adding a node to storage necessarily entails adding one to the Hyper-V hosts, and vice versa.

### Storage Replica

Storage Replica supports one-way replication between standalone servers, between clusters, and between storage devices within an [**asymmetric (stretch) cluster**][asymmetric cluster].
- **Synchronous** replication is possible when the replicated volumes can mirror data immediately, ensuring no data loss in case of failover
- **Asynchronous** replication is preferable when the replication partner is located over a WAN link

Storage Replica improves on DFS Replication, which is exclusively asynchronous and file-based, by using SMBv3 (port 445).
Storage Replica requires two virtual disks, one for logs and one for data, which are the same size for each replication partner, and all the physical disks must use the same sector size.



## WSUS

**Windows Server Update Services (WSUS)** can be configured from the command-line with wsusutil.exe.

There are 5 basic WSUS architecture configurations

- **Single** WSUS Server downloads updates from Microsoft Update, and all the computers on the network download updates from it. A single server can usupport up to 25,000 clients.
- **Replica** WSUS Servers: a central WSUS server downloads from Microsoft Update, and after approval the updates are distributed to **downstream servers** at remote locations.
- **Autonomous** WSUS Servers: a central WSUS server downloads from Microsoft Update, all of which are distributed to remote servers; each remote site's administrators are individually responsible for evaluating and approving updates.
- **Low-bandwidth** WSUS Servers at remote sites download only the list of approved updates, which are then retrieved from Microsoft Update over the Internet, minimizing WAN traffic.
- **Disconnected** WSUS Servers have updates imported from offline media (DVD-ROMs, portable drives, etc), utilizing no WAN or Internet bandwidth whatsoever.

When a computer first communicates with a WSUS server, it is added to the All Computers and and Unassigned Computers group automatically, which is created by default.

## Windows Server Backup

To back up a VM without any downtime, **integration services** must be installed and enabled, and all disks must be basic disks formatted with **NTFS**.

**Windows Server Backup**
- **System state** includes boot files, Active Directory files, `SYSVOL` (when run on a DC), the registry, and other data.
- **System reserved** is a special partition containing Boot Manager and Boot Configuration data.

## Executables

#### adfind

Query the schema version associated with Active Directory <sup>[Desmond][Desmond2009]: 53</sup>
```cmd
adfind -schema -s base objectVersion
```

#### adprep

Prepare Active Directory for Windows Server upgrades. Must be run on the Infrastructure Master role owner with the flag `/domainprep`. <sup>[Desmond][Desmond2009]: 29</sup>

#### arp

<!-- `arp` options -->
[arp /&#97;]:  #arp '```&#10;C:\>arp /a&#10;```&#10;Display both the IP and MAC addresses and whether they are dynamic or static entries '
[arp /&#115;]: #arp '```&#10;C:\>arp /s&#10;```&#10;Manually add a static entry to the cache'
[arp /&#100;]: #arp '```&#10;C:\>arp /d&#10;```&#10;Delete an entry from the cache'

<code>&nbsp;</code> [`a`][arp /&#97;] <code>&nbsp;</code> <code>&nbsp;</code> [`d`][arp /&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][arp /&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

#### bcdedit

Change Windows bootloader to Linux, while dual booting
```cmd
::Manjaro
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi

::Fedora
bcdedit /set {bootmgr} path \EFI\fedora\shim.efi
```
Enable or disable **Test Signing Mode** [<sup>ref</sup>](https://www.howtogeek.com/167723/how-to-disable-driver-signature-verification-on-64-bit-windows-8.1-so-that-you-can-install-unsigned-drivers/ "howtogeek.com - 'How to disable driver signature verification on 64-bit Windows 8.1 so that you can install unsigned drivers'")
```cmd
bcdedit /set testsign on
bcdedit /set testsign off
```

#### bootrec

Windows Recovery Environment command that repairs a system partition

Use when boot sector not found
```cmd
bootrec /fixboot
```
Use when BCD file has been corrupted
```cmd
bootrec /rebuildbcd
```

#### cmdkey

[cmdkey /add]: #cmdkey '```&#10;C:\>cmdkey /add&#10;```&#10;Add a user name and password to the list'
[cmdkey /generic]: #cmdkey '```&#10;C:\>cmdkey /generic&#10;```&#10;Add generic credentials to the list'
[cmdkey /smartcard]: #cmdkey '```&#10;C:\>cmdkey /smartcard&#10;```&#10;Retrieves the credential from a smart card'
[cmdkey /user]: #cmdkey '```&#10;C:\>cmdkey /user&#10;```&#10;Specify user or account name to store with this entry.'
[cmdkey /pass]: #cmdkey '```&#10;C:\>cmdkey /pass&#10;```&#10;Specify password to store with this entry'
[cmdkey /delete]: #cmdkey '```&#10;C:\>cmdkey /delete&#10;```&#10;Delete a user name and password from the list.'
[cmdkey /list]: #cmdkey '```&#10;C:\>cmdkey /list&#10;```&#10;Display the list of stored user names and credentials.'

[`add`][cmdkey /add]
[`delete`][cmdkey /delete]
[`generic`][cmdkey /generic]
[`list`][cmdkey /list]
[`pass`][cmdkey /pass]
[`smartcard`][cmdkey /smartcard]
[`user`][cmdkey /user]

Add a user name and password for user `Mikedan` to access computer `Server01` with the password `Kleo` <sup>[docs.microsoft.com](https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/cmdkey "cmdkey")
```cmd
cmdkey /add:server01 /user:mikedan /pass:Kleo
```

#### [dism](https://docs.microsoft.com/en-us/windows-hardware/manufacture/desktop/dism-image-management-command-line-options-s14)

[dism.exe /Add-Driver]: #dism.exe '```&#10;C:\>dism.exe /Add-Driver&#10;```&#10;&#10;Equivalent to `Add-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Add-Package]: #dism.exe '```&#10;C:\>dism.exe /Add-Package&#10;```&#10;&#10;Equivalent to `Add-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Add-ProvisionedAppxPackage]: #dism.exe '```&#10;C:\>dism.exe /Add-ProvisionedAppxPackage&#10;```&#10;&#10;Equivalent to `Add-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Append-Image]: #dism.exe '```&#10;C:\>dism.exe /Append-Image&#10;```&#10;&#10;Equivalent to `Add-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Apply-Image]: #dism.exe '```&#10;C:\>dism.exe /Apply-Image&#10;```&#10;&#10;Equivalent to `Expand-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Apply-Unattend]: #dism.exe '```&#10;C:\>dism.exe /Apply-Unattend&#10;```&#10;&#10;Equivalent to `Apply-WindowsUnattend`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Capture-Image]: #dism.exe '```&#10;C:\>dism.exe /Capture-Image&#10;```&#10;&#10;Equivalent to `New-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Commit-Image]: #dism.exe '```&#10;C:\>dism.exe /Commit-Image&#10;```&#10;&#10;Equivalent to `Save-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Disable-Feature]: #dism.exe '```&#10;C:\>dism.exe /Disable-Feature&#10;```&#10;&#10;Equivalent to `Disable-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Enable-Feature]: #dism.exe '```&#10;C:\>dism.exe /Enable-Feature&#10;```&#10;&#10;Equivalent to `Enable-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Export-Driver]: #dism.exe '```&#10;C:\>dism.exe /Export-Driver&#10;```&#10;&#10;Equivalent to `Export-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Export-Image]: #dism.exe '```&#10;C:\>dism.exe /Export-Image&#10;```&#10;&#10;Equivalent to `Export-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Driverinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Driverinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsDriver -Driver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Drivers]: #dism.exe '```&#10;C:\>dism.exe /Get-Drivers&#10;```&#10;&#10;Equivalent to `Get-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Featureinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Featureinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsOptionalFeature -FeatureName`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Features]: #dism.exe '```&#10;C:\>dism.exe /Get-Features&#10;```&#10;&#10;Equivalent to `Get-WindowsOptionalFeature`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-ImageInfo]: #dism.exe '```&#10;C:\>dism.exe /Get-ImageInfo&#10;```&#10;&#10;Equivalent to `Get-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-MountedImageInfo]: #dism.exe '```&#10;C:\>dism.exe /Get-MountedImageInfo&#10;```&#10;&#10;Equivalent to `Get-WindowsImage -Mounted`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Packageinfo]: #dism.exe '```&#10;C:\>dism.exe /Get-Packageinfo&#10;```&#10;&#10;Equivalent to `Get-WindowsPackage -PackagePath` or `Get-WindowsPackage -PackageName`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-Packages]: #dism.exe '```&#10;C:\>dism.exe /Get-Packages&#10;```&#10;&#10;Equivalent to `Get-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Get-ProvisionedAppxPackages]: #dism.exe '```&#10;C:\>dism.exe /Get-ProvisionedAppxPackages&#10;```&#10;&#10;Equivalent to `Get-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /List-Image]: #dism.exe '```&#10;C:\>dism.exe /List-Image&#10;```&#10;&#10;Equivalent to `Get-WindowsImageontent`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remount-Image]: #dism.exe '```&#10;C:\>dism.exe /Remount-Image&#10;```&#10;&#10;Equivalent to `Mount-WindowsImage -Remount`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Driver]: #dism.exe '```&#10;C:\>dism.exe /Remove-Driver&#10;```&#10;&#10;Equivalent to `Remove-WindowsDriver`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Image]: #dism.exe '```&#10;C:\>dism.exe /Remove-Image&#10;```&#10;&#10;Equivalent to `Remove-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-Package]: #dism.exe '```&#10;C:\>dism.exe /Remove-Package&#10;```&#10;&#10;Equivalent to `Remove-WindowsPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Remove-ProvisionedAppxPackage]: #dism.exe '```&#10;C:\>dism.exe /Remove-ProvisionedAppxPackage&#10;```&#10;&#10;Equivalent to `Remove-AppxProvisionedPackage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Set-ProvisionedAppxDataFile]: #dism.exe '```&#10;C:\>dism.exe /Set-ProvisionedAppxDataFile&#10;```&#10;&#10;Equivalent to `Set-AppXProvisionedDataFile`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'
[dism.exe /Unmount-Image]: #dism.exe '```&#10;C:\>dism.exe /Unmount-Image&#10;```&#10;&#10;Equivalent to `Dismount-WindowsImage`&#10;Sobell, Mark. _Practical Guide to Linux_. 2017.: 77'

[`Add-Driver`][dism.exe /Add-Driver]
[`Add-Package`][dism.exe /Add-Package]
[`Add-ProvisionedAppxPackage`][dism.exe /Add-ProvisionedAppxPackage]
[`Append-Image`][dism.exe /Append-Image]
[`Apply-Image`][dism.exe /Apply-Image]
[`Apply-Unattend`][dism.exe /Apply-Unattend]
[`Capture-Image`][dism.exe /Capture-Image]
`Cleanup-Image`
[`Commit-Image`][dism.exe /Commit-Image]
[`Disable-Feature`][dism.exe /Disable-Feature]
[`Enable-Feature`][dism.exe /Enable-Feature]
[`Export-Driver`][dism.exe /Export-Driver]
[`Export-Image`][dism.exe /Export-Image]
[`Get-Driverinfo`][dism.exe /Get-Driverinfo]
[`Get-Drivers`][dism.exe /Get-Drivers]
[`Get-Featureinfo`][dism.exe /Get-Featureinfo]
[`Get-Features`][dism.exe /Get-Features]
[`Get-ImageInfo`][dism.exe /Get-ImageInfo]
[`Get-MountedImageInfo`][dism.exe /Get-MountedImageInfo]
[`Get-Packageinfo`][dism.exe /Get-Packageinfo]
[`Get-Packages`][dism.exe /Get-Packages]
[`Get-ProvisionedAppxPackages`][dism.exe /Get-ProvisionedAppxPackages]
[`List-Image`][dism.exe /List-Image]
[`Remount-Image`][dism.exe /Remount-Image]
[`Remove-Driver`][dism.exe /Remove-Driver]
[`Remove-Image`][dism.exe /Remove-Image]
[`Remove-Package`][dism.exe /Remove-Package]
[`Remove-ProvisionedAppxPackage`][dism.exe /Remove-ProvisionedAppxPackage]
[`Set-ProvisionedAppxDataFile`][dism.exe /Set-ProvisionedAppxDataFile]
[`Unmount-Image`][dism.exe /Unmount-Image]


Mount an image <sup>[Zacker][Zacker]: 71</sup>
```cmd
dism /mount-image /imagefile:$FILENAME /index:$N /name:$IMAGENAME /mountdir:$PATH
```
Practice Labs
```cmd
dism /mount-wim /wimfile:c:\images\install.wim /index:1 /mountdir:c:\mount
```
Add a driver to an image file that you have already mounted <sup>[Zacker][Zacker]: 72</sup>
```cmd
dism /image:$FOLDERNAME /add-driver /driver:$DRIVERNAME /recurse
```
Commit changes and unmount the image <sup>[Zacker][Zacker]: 75</sup>
```cmd
dism /unmount-image /mountdir:c:\mount /commit
```
Determine exact name of Windows features that can be enabled and disabled <sup>[Zacker][Zacker]: 75</sup>
```cmd
dism /image:c:\mount /get-features
```
Scan an image, checking for corruption
```cmd
dism /Online /Cleanup-Image /ScanHealth
```
Check an image to see whether any corruption has been detected
```cmd
dism /Online /Cleanup-Image /CheckHealth
```
Repair an offline dicsk using a mounted image as a repair source
```cmd
dism /Image:C:\offline /Cleanup-Image /RestoreHealth /Source:C:\test\mount\windows
```
Zacker: 71-75
```cmd
dism /mount-image /imagefile:C:\images\install.wim /index:1 /mountdir:C:\mount
dism /add-package /image:C:\mount /packagepath:C:\updates
dism /add-driver /image:C:\mount /driver:C:\drivers\display.driver\nv_dispi.inf
dism /commit-image /image:C:\mount
dism /unmount-image /image:C:\mount
```

#### djoin

Perform an offline domain join for a Nano Server <sup>Zacker: 46</sup>
```cmd
djoin /provision /domain practicelabs /machine PLABNANOSRV01 /savefile .\odjblob
```
Load the `odjblob` file created offline on the Nano Server.
```cmd
djoin /requestodj /loadfile c:\odjblob /windowspath c:\windows /localos
```


#### dnscmd

Replicate an AD-integrated DNS zone to specific DCs <sup>[ref](# "PluralSight 70-741 course: 027. Primary Zones and Active Directory integrated zones")
```cmd
dnscmd . /CreateDirectoryPartition FQDN
```
Enable GlobalNames zone support
```cmd
dnscmd <servername> /config /enableglobalnamessupport 1
```
Observe status of socket pool
```cmd
dnscmd /info /socketpoolsize
``` 
Configure DNS socket pool size (0 through 10,000)
```cmd
dnscmd /Config /SocketPoolSize <value>
```


#### dsquery

Find the Active Directory Schema version from the command-line <sup>[ref](https://nolabnoparty.com/en/finding-active-directory-schema-version/ "Finding the Active Directory schema version") [pwsh](https://github.com/jasper-zanjani/notes/tree/primary/70-740/PowerShell#get-adobject "Get-ADObject")</sup>

```cmd
dsquery * cn=schema,cn=configuration,dc=domain,dc=com -scope base -attr objectVersion"
```

#### net
Map a network location to a drive letter <sup>[Practice Lab][pl:70-740]</sup>
```cmd
net use x: \\192.168.0.35\c$
```
Stop/start a service
```cmd
net stop dns
net start dns
```

#### netdom

Rename a computer
```
netdom renamecomputer %computername% /newname: newcomputername
```
Join a computer to a domain <sup>cf. `Add-Computer`, Zacker: 21</sup>
```
netdom join %computername% /domain: domainname /userd: username /password:*
```

#### netsh

Enable port forwarding ("`portproxy`") to a WSL2 distribution ([src](https://docs.microsoft.com/en-us/windows/wsl/compare-versions#accessing-a-wsl-2-distribution-from-your-local-area-network-lan))
```cmd
netsh interface portproxy add v4tov4 listenaddress=0.0.0.0 listenport=2222 connectaddress=172.23.129.80 connectport=2222
```
Configure DNS to be dynamically assigned
```cmd
netsh interface ip set dns "Wi-Fi" dhcp
```
Delete Wi-Fi profiles
```cmd
netsh wlan delete profile name=*
```
Turn off Windows firewall
```cmd
netsh advfirewall set allprofiles state off
```
Enable firewall rule group 
```cmd
netsh advfirewall firewall set rule group=”File and Printer Sharing” new enable=yes
```
Show Wi-Fi passwords ([src](https://helpdeskgeek.com/how-to/find-the-wifi-password-in-windows-10-using-cmd/ "Find the WiFi Password in Windows 10 Using CMD")
```cmd
netsh wlan show profile wifi key=clear
```
Check/reset WinHTTP proxy 
```cmd
netsh winhttp show proxy
netsh winhttp reset proxy
```
#### ntdsutil
Used to transfer [FSMO](# "\"Flexible Single Master Operator\", server that is master for a particular role or function") roles between domain controllers. [<sup>Desmond: 30</sup>][Desmond2009]

#### regsvr32
Register a DLL dependency in order to enable the Active Directory Schema MMC snap-in on a DC <sup>[Desmond][Desmond2009]: 54</sup>
```cmd
regsvr32 schmmgmt.dll
```

#### route
[route /&#112;]:                #route                         '```&#10;C:\>route /p&#10;```&#10;Make a route persistent&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route print]:                    #route                         '```&#10;C:\>route print&#10;```&#10;Display routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route add]:                      #route                         '```&#10;C:\>route add&#10;```&#10;Add a route to the routing table&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route change]:                   #route                         '```&#10;C:\>route change&#10;```&#10;Modify an existing route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'
[route delete]:                   #route                         '```&#10;C:\>route delete&#10;```&#10;Delete a route&#10;Lammle, Todd. _CompTIA Network+ Study Guide: Exam N10-005_. 2012.: 539'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][route /&#112;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br> [`print`][route print] [`add`][route add] [`change`][route change] [`delete`][route delete]

Basic usage
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```
#### runas
[runas /profile]: #runas '```&#10;C:\>runas /profile&#10;```&#10;Load user profile (default).'
[runas /no profile]: #runas '```&#10;C:\>runas /no profile&#10;```&#10;Specify that user profile is not to be loaded.'
[runas /env]: #runas '```&#10;C:\>runas /env&#10;```&#10;Specify that the current network environment be used instead of the local environment of the user.'
[runas /netonly]: #runas '```&#10;C:\>runas /netonly&#10;```&#10;Indicate that the user information specified is for remote access only'
[runas /savecred]: #runas '```&#10;C:\>runas /savecred&#10;```&#10;Indicate if credentials have been previously saved by this user'
[runas /smartcard]: #runas '```&#10;C:\>runas /smartcard&#10;```&#10;Retrieve the credential from a smart card'
[runas /showtrustlevels]: #runas '```&#10;C:\>runas /showtrustlevels&#10;```&#10;Display the trust levels that can be used as arguments to `/trustlevel`'
[runas /trustlevel]: #runas '```&#10;C:\>runas /trustlevel&#10;```&#10;Specify the level of authorization at which the application is to run'
[runas /user:]: #runas '```&#10;C:\>runas /user: $USER "$PROGRAM"&#10;```&#10;Specify the name of the user account under which to run the program'

[`env`][runas /env]
[`netonly`][runas /netonly]
[`profile`][runas /profile]/[`no profile`][runas /no profile]
[`savecred`][runas /savecred]
[`showtrustlevels`][runas /showtrustlevels]
[`smartcard`][runas /smartcard]
[`trustlevel`][runas /trustlevel]
[`user:`][runas /user:]

#### Settings
[ms-settings:about]: #settings '```&#10;C:\>start ms-settings:about&#10;```&#10;Open About page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:activation]: #settings '```&#10;C:\>start ms-settings:activation&#10;```&#10;Open Activation page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:apps-volume]: #settings '```&#10;C:\>start ms-settings:apps-volume&#10;```&#10;Open App volume and device preferences page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:appsfeatures]: #settings '```&#10;C:\>start ms-settings:appsfeatures&#10;```&#10;Open Apps & Features page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:appsforwebsites]: #settings '```&#10;C:\>start ms-settings:appsforwebsites&#10;```&#10;Open Apps for websites page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:assignedaccess]: #settings '```&#10;C:\>start ms-settings:assignedaccess&#10;```&#10;Open Set up a kiosk page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:autoplay]: #settings '```&#10;C:\>start ms-settings:autoplay&#10;```&#10;Open AutoPlay page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:backup]: #settings '```&#10;C:\>start ms-settings:backup&#10;```&#10;Open Backup page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:batterysaver]: #settings '```&#10;C:\>start ms-settings:batterysaver&#10;```&#10;Open Battery Saver page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:bluetooth]: #settings '```&#10;C:\>start ms-settings:bluetooth&#10;```&#10;Open Bluetooth page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:camera]: #settings '```&#10;C:\>start ms-settings:camera&#10;```&#10;Open Default camera page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:clipboard]: #settings '```&#10;C:\>start ms-settings:clipboard&#10;```&#10;Open Clipboard page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:colors]: #settings '```&#10;C:\>start ms-settings:colors&#10;```&#10;Open Colors page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:connecteddevices]: #settings '```&#10;C:\>start ms-settings:connecteddevices&#10;```&#10;Open Connected devices page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:cortana]: #settings '```&#10;C:\>start ms-settings:cortana&#10;```&#10;Open Talk to Cortana page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:crossdevice]: #settings '```&#10;C:\>start ms-settings:crossdevice&#10;```&#10;Open Shared experiences page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:datausage]: #settings '```&#10;C:\>start ms-settings:datausage&#10;```&#10;Open Data usage page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:dateandtime]: #settings '```&#10;C:\>start ms-settings:dateandtime&#10;```&#10;Open Date & time page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:defaultapps]: #settings '```&#10;C:\>start ms-settings:defaultapps&#10;```&#10;Open Default apps page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:delivery-optimization]: #settings '```&#10;C:\>start ms-settings:delivery-optimization&#10;```&#10;Open Delivery Optimization page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:developers]: #settings '```&#10;C:\>start ms-settings:developers&#10;```&#10;Open For developers page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:deviceencryption]: #settings '```&#10;C:\>start ms-settings:deviceencryption&#10;```&#10;Open Encryption page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:devices-touchpad]: #settings '```&#10;C:\>start ms-settings:devices-touchpad&#10;```&#10;Open Touchpad page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:display]: #settings '```&#10;C:\>start ms-settings:display&#10;```&#10;Open Display page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:easeofaccess-display]: #settings '```&#10;C:\>start ms-settings:easeofaccess-display&#10;```&#10;Open Display page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:emailandaccounts]: #settings '```&#10;C:\>start ms-settings:emailandaccounts&#10;```&#10;Open Email & app accounts page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:findmydevice]: #settings '```&#10;C:\>start ms-settings:findmydevice&#10;```&#10;Open Find My Device page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:fonts]: #settings '```&#10;C:\>start ms-settings:fonts&#10;```&#10;Open Fonts page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:keyboard]: #settings '```&#10;C:\>start ms-settings:keyboard&#10;```&#10;Open Language page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:lockscreen]: #settings '```&#10;C:\>start ms-settings:lockscreen&#10;```&#10;Open Lockscreen page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:maps]: #settings '```&#10;C:\>start ms-settings:maps&#10;```&#10;Open Offline maps page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:messaging]: #settings '```&#10;C:\>start ms-settings:messaging&#10;```&#10;Open Messaging page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:mobile-devices]: #settings '```&#10;C:\>start ms-settings:mobile-devices&#10;```&#10;Open Your phone page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:mousetouchpad]: #settings '```&#10;C:\>start ms-settings:mousetouchpad&#10;```&#10;Open Mouse & touchpad page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:multitasking]: #settings '```&#10;C:\>start ms-settings:multitasking&#10;```&#10;Open Multitasking page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:network]: #settings '```&#10;C:\>start ms-settings:network&#10;```&#10;Open Status page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:network-wifi]: #settings '```&#10;C:\>start ms-settings:network-wifi&#10;```&#10;Open Wi-Fi page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:nfctransactions]: #settings '```&#10;C:\>start ms-settings:nfctransactions&#10;```&#10;Open NFC page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:nightlight]: #settings '```&#10;C:\>start ms-settings:nightlight&#10;```&#10;Open Night light settings page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:notifications]: #settings '```&#10;C:\>start ms-settings:notifications&#10;```&#10;Open Notifications & actions page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:optionalfeatures]: #settings '```&#10;C:\>start ms-settings:optionalfeatures&#10;```&#10;Open Optional features page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:otherusers]: #settings '```&#10;C:\>start ms-settings:otherusers&#10;```&#10;Open Family & other people page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:pen]: #settings '```&#10;C:\>start ms-settings:pen&#10;```&#10;Open Pen & Windows Ink page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:personalization]: #settings '```&#10;C:\>start ms-settings:personalization&#10;```&#10;Open Personalization (category) page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:personalization-background]: #settings '```&#10;C:\>start ms-settings:personalization-background&#10;```&#10;Open Background page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:personalization-colors]: #settings '```&#10;C:\>start ms-settings:personalization-colors&#10;```&#10;Open Colors page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:personalization-start]: #settings '```&#10;C:\>start ms-settings:personalization-start&#10;```&#10;Open Start page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:personalization-start-places]: #settings '```&#10;C:\>start ms-settings:personalization-start-places&#10;```&#10;Open Choose which folders appear on Start page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:phone]: #settings '```&#10;C:\>start ms-settings:phone&#10;```&#10;Open Phone page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:powersleep]: #settings '```&#10;C:\>start ms-settings:powersleep&#10;```&#10;Open Power & sleep page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:printers]: #settings '```&#10;C:\>start ms-settings:printers&#10;```&#10;Open Printers & scanners page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:privacy]: #settings '```&#10;C:\>start ms-settings:privacy&#10;```&#10;Open Privacy page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:project]: #settings '```&#10;C:\>start ms-settings:project&#10;```&#10;Open Projecting to this PC page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:proximity]: #settings '```&#10;C:\>start ms-settings:proximity&#10;```&#10;Open Proximity page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:quiethours]: #settings '```&#10;C:\>start ms-settings:quiethours&#10;```&#10;Open Focus assist page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:quietmomentsgame]: #settings '```&#10;C:\>start ms-settings:quietmomentsgame&#10;```&#10;Open Playing a game full screen page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:quietmomentspresentation]: #settings '```&#10;C:\>start ms-settings:quietmomentspresentation&#10;```&#10;Open Duplicating my display page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:quietmomentsscheduled]: #settings '```&#10;C:\>start ms-settings:quietmomentsscheduled&#10;```&#10;Open During these hours page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:recovery]: #settings '```&#10;C:\>start ms-settings:recovery&#10;```&#10;Open Recovery page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:regionformatting]: #settings '```&#10;C:\>start ms-settings:regionformatting&#10;```&#10;Open Region page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:regionlanguage]: #settings '```&#10;C:\>start ms-settings:regionlanguage&#10;```&#10;Open Region & language page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:remotedesktop]: #settings '```&#10;C:\>start ms-settings:remotedesktop&#10;```&#10;Open Remote Desktop page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:savelocations]: #settings '```&#10;C:\>start ms-settings:savelocations&#10;```&#10;Open Default Save Locations page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:screenrotation]: #settings '```&#10;C:\>start ms-settings:screenrotation&#10;```&#10;Open Display page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:signinoptions]: #settings '```&#10;C:\>start ms-settings:signinoptions&#10;```&#10;Open Sign-in options page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:signinoptions-launchfaceenrollment]: #settings '```&#10;C:\>start ms-settings:signinoptions-launchfaceenrollment&#10;```&#10;Open Windows Hello setup page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:sound]: #settings '```&#10;C:\>start ms-settings:sound&#10;```&#10;Open Sound page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:speech]: #settings '```&#10;C:\>start ms-settings:speech&#10;```&#10;Open Speech page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:speech]: #settings '```&#10;C:\>start ms-settings:speech&#10;```&#10;Open Speech page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:startupapps]: #settings '```&#10;C:\>start ms-settings:startupapps&#10;```&#10;Open Startup apps page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:storagepolicies]: #settings '```&#10;C:\>start ms-settings:storagepolicies&#10;```&#10;Open Storage Sense page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:storagesense]: #settings '```&#10;C:\>start ms-settings:storagesense&#10;```&#10;Open Storage Sense page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:surfacehub-accounts]: #settings '```&#10;C:\>start ms-settings:surfacehub-accounts&#10;```&#10;Open Accounts page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:surfacehub-calling]: #settings '```&#10;C:\>start ms-settings:surfacehub-calling&#10;```&#10;Open Team Conferencing page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:surfacehub-devicemanagenent]: #settings '```&#10;C:\>start ms-settings:surfacehub-devicemanagenent&#10;```&#10;Open Team device management page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:surfacehub-sessioncleanup]: #settings '```&#10;C:\>start ms-settings:surfacehub-sessioncleanup&#10;```&#10;Open Session cleanup page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:surfacehub-welcome]: #settings '```&#10;C:\>start ms-settings:surfacehub-welcome&#10;```&#10;Open Welcome screen page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:sync]: #settings '```&#10;C:\>start ms-settings:sync&#10;```&#10;Open Sync your settings page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:tabletmode]: #settings '```&#10;C:\>start ms-settings:tabletmode&#10;```&#10;Open Tablet mode page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:taskbar]: #settings '```&#10;C:\>start ms-settings:taskbar&#10;```&#10;Open Taskbar page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:themes]: #settings '```&#10;C:\>start ms-settings:themes&#10;```&#10;Open Themes page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:troubleshoot]: #settings '```&#10;C:\>start ms-settings:troubleshoot&#10;```&#10;Open Troubleshoot page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:typing]: #settings '```&#10;C:\>start ms-settings:typing&#10;```&#10;Open Typing page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:usb]: #settings '```&#10;C:\>start ms-settings:usb&#10;```&#10;Open USB page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:videoplayback]: #settings '```&#10;C:\>start ms-settings:videoplayback&#10;```&#10;Open Video playback page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:wheel]: #settings '```&#10;C:\>start ms-settings:wheel&#10;```&#10;Open Wheel page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:windowsdefender]: #settings '```&#10;C:\>start ms-settings:windowsdefender&#10;```&#10;Open Windows Security page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:windowsinsider]: #settings '```&#10;C:\>start ms-settings:windowsinsider&#10;```&#10;Open Windows Insider Program page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:windowsupdate]: #settings '```&#10;C:\>start ms-settings:windowsupdate&#10;```&#10;Open Windows Update page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:workplace]: #settings '```&#10;C:\>start ms-settings:workplace&#10;```&#10;Open Access work or school page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'
[ms-settings:yourinfo]: #settings '```&#10;C:\>start ms-settings:yourinfo&#10;```&#10;Open Your info page in Settings on Windows 10&#10;"Launch the Windows Settings app." Microsoft Docs.'

[**`appsfeatures`**][ms-settings:appsfeatures]
[**`personalization`**][ms-settings:personalization]
[**`printers`**][ms-settings:printers]
[**`windowsupdate`**][ms-settings:windowsupdate]

[about][ms-settings:about]
[activation][ms-settings:activation]
[apps-volume][ms-settings:apps-volume]
[appsforwebsites][ms-settings:appsforwebsites]
[assignedaccess][ms-settings:assignedaccess]
[autoplay][ms-settings:autoplay]
[backup][ms-settings:backup]
[batterysaver][ms-settings:batterysaver]
[bluetooth][ms-settings:bluetooth]
[camera][ms-settings:camera]
[clipboard][ms-settings:clipboard]
[colors][ms-settings:colors]
[connecteddevices][ms-settings:connecteddevices]
[cortana][ms-settings:cortana]
[crossdevice][ms-settings:crossdevice]
[datausage][ms-settings:datausage]
[dateandtime][ms-settings:dateandtime]
[defaultapps][ms-settings:defaultapps]
[delivery-optimization][ms-settings:delivery-optimization]
[developers][ms-settings:developers]
[deviceencryption][ms-settings:deviceencryption]
[devices-touchpad][ms-settings:devices-touchpad]
[display][ms-settings:display]
[easeofaccess-display][ms-settings:easeofaccess-display]
[emailandaccounts][ms-settings:emailandaccounts]
[findmydevice][ms-settings:findmydevice]
[fonts][ms-settings:fonts]
[keyboard][ms-settings:keyboard]
[lockscreen][ms-settings:lockscreen]
[maps][ms-settings:maps]
[messaging][ms-settings:messaging]
[mobile-devices][ms-settings:mobile-devices]
[mousetouchpad][ms-settings:mousetouchpad]
[multitasking][ms-settings:multitasking]
[network][ms-settings:network]
[network-wifi][ms-settings:network-wifi]
[nfctransactions][ms-settings:nfctransactions]
[nightlight][ms-settings:nightlight]
[notifications][ms-settings:notifications]
[optionalfeatures][ms-settings:optionalfeatures]
[otherusers][ms-settings:otherusers]
[pen][ms-settings:pen]
[personalization-background][ms-settings:personalization-background]
[personalization-colors][ms-settings:personalization-colors]
[personalization-start][ms-settings:personalization-start]
[personalization-start-places][ms-settings:personalization-start-places]
[phone][ms-settings:phone]
[powersleep][ms-settings:powersleep]
[privacy][ms-settings:privacy]
[project][ms-settings:project]
[proximity][ms-settings:proximity]
[quiethours][ms-settings:quiethours]
[quietmomentsgame][ms-settings:quietmomentsgame]
[quietmomentspresentation][ms-settings:quietmomentspresentation]
[quietmomentsscheduled][ms-settings:quietmomentsscheduled]
[recovery][ms-settings:recovery]
[regionformatting][ms-settings:regionformatting]
[regionlanguage][ms-settings:regionlanguage]
[remotedesktop][ms-settings:remotedesktop]
[savelocations][ms-settings:savelocations]
[screenrotation][ms-settings:screenrotation]
[signinoptions][ms-settings:signinoptions]
[signinoptions-launchfaceenrollment][ms-settings:signinoptions-launchfaceenrollment]
[sound][ms-settings:sound]
[speech][ms-settings:speech]
[speech][ms-settings:speech]
[startupapps][ms-settings:startupapps]
[storagepolicies][ms-settings:storagepolicies]
[storagesense][ms-settings:storagesense]
[surfacehub-accounts][ms-settings:surfacehub-accounts]
[surfacehub-calling][ms-settings:surfacehub-calling]
[surfacehub-devicemanagenent][ms-settings:surfacehub-devicemanagenent]
[surfacehub-sessioncleanup][ms-settings:surfacehub-sessioncleanup]
[surfacehub-welcome][ms-settings:surfacehub-welcome]
[sync][ms-settings:sync]
[tabletmode][ms-settings:tabletmode]
[taskbar][ms-settings:taskbar]
[themes][ms-settings:themes]
[troubleshoot][ms-settings:troubleshoot]
[typing][ms-settings:typing]
[usb][ms-settings:usb]
[videoplayback][ms-settings:videoplayback]
[wheel][ms-settings:wheel]
[windowsdefender][ms-settings:windowsdefender]
[windowsinsider][ms-settings:windowsinsider]
[workplace][ms-settings:workplace]
[yourinfo][ms-settings:yourinfo]

#### sfc
```cmd
sfc /scannow
```

#### shutdown
Immediate restart
```cmd
shutdown /r /t 0
```
Log off
```cmd
shutdown /L
```
#### slmgr
[slmgr /dli]: #slmgr.vbs '```&#10;C:\> slmgr /dli&#10;```&#10;Display very basic license and activation information about the current system in a dialog box'
[slmgr /dlv]: #slmgr.vbs '```&#10;C:\> slmgr /dlv&#10;```&#10;Display more detailed license information, including activation ID, installation ID, and other details'
[slmgr /xpr]: #slmgr.vbs '```&#10;C:\> slmgr /xpr&#10;```&#10;Display activation status or expiration date of current license'
[slmgr /upk]: #slmgr.vbs '```&#10;C:\> slmgr /upk&#10;```&#10;Remove the product key, placing Windows in an unactivated, unlicensed state (after restart)'
[slmgr /ipk]: #slmgr.vbs '```&#10;C:\> slmgr /ipk&#10;```&#10;Replace product key, equivalent to changing product key in Activation screen in Settings'
[slmgr /ato]: #slmgr.vbs '```&#10;C:\> slmgr /ato&#10;```&#10;Force Windows to attempt an online activation, either with Microsoft servers or with the KMS server on the local network'
[slmgr /rearm]: #slmgr.vbs '```&#10;C:\> slmgr /rearm&#10;```&#10;Reset activation timer to extend trial period. Each usage reduces the "rearm count" (ref. `/dlv`)'

[`ato`][slmgr /ato]
[`dli`][slmgr /dli]
[`dlv`][slmgr /dlv]
[`ipk`][slmgr /ipk]
[`rearm`][slmgr /rearm]
[`upk`][slmgr /upk]
[`xpr`][slmgr /xpr]

#### sysdm

[sysdm.cpl ,3]: #sysdm '```&#10;C:\>sysdm.cpl ,3&#10;```&#10;Open System Properties directly to Advanced tab'
[sysdm.cpl ,2]: #sysdm '```&#10;C:\>sysdm.cpl ,2&#10;```&#10;Open System Properties directly to Hardware tab'
[sysdm.cpl ,4]: #sysdm '```&#10;C:\>sysdm.cpl ,4&#10;```&#10;Open System Properties directly to System Protection tab'
[sysdm.cpl ,5]: #sysdm '```&#10;C:\>sysdm.cpl ,5&#10;```&#10;Open System Properties directly to Remote tab'

[`2`][sysdm.cpl ,2]
[**`3`**][sysdm.cpl ,3]
[`4`][sysdm.cpl ,4]
[`5`][sysdm.cpl ,5]

#### tracert

On Windows, this command is aliased to `traceroute` which is the Linux command. <sup>[Lammle][Lammle]: 112</sup>


#### wbadmin
[wbadmin-enable-backup]: #wbadmin '```&#10;wbadmin enable backup &#10;```&#10;Configures and enables a regularly scheduled backup.'
[wbadmin-start-backup]: #wbadmin '```&#10;wbadmin start backup &#10;```&#10;Runs a one-time backup. If used with no parameters, uses the settings from the daily backup schedule.'
[wbadmin-get-versions]: #wbadmin '```&#10;wbadmin get versions &#10;```&#10;Lists details of backups recoverable from the local computer or, if another location is specified, from another computer.'
[wbadmin-get-items]: #wbadmin '```&#10;wbadmin get items &#10;```&#10;Lists the items included in a backup.'
[wbadmin-start-recovery]: #wbadmin '```&#10;wbadmin start recovery &#10;```&#10;Runs a recovery of the volumes, applications, files, or folders specified.'
[wbadmin-start-systemstaterecovery]: #wbadmin '```&#10;wbadmin start systemstaterecovery &#10;```&#10;Runs a system state recovery.'

[`enable backup`][wbadmin-enable-backup]
[`get items`][wbadmin-get-items]
[`get versions`][wbadmin-get-versions]
[`start backup`][wbadmin-start-backup]
[`start recovery`][wbadmin-start-recovery]
[`start systemstaterecovery`][wbadmin-start-systemstaterecovery]

`-backupTarget`
`-hyperv`
`-vsscopy`|`-vssFull`

Backup the entire drive, excluding some VMs
```cmd
wbadmin enable backup -backupTarget \\backups\hostdr\temp\ -include:c: -exclude: C:\VMs\VM1.vhdx, C:\VMs\VMAR.vhd -vsscopy -quiet
```

[Zacker][Zacker]: 325-326
```cmd
wbadmin get versions
wbadmin get items -version: 11/14/2016:05:09
wbadmin start recovery -itemtype:app items:cluster -version:01/01/2008-00:00
```
[Zacker][Zacker]: 422
```cmd
wbadmin start systemstaterecovery -version:11/27/2016-11:07
wbadmin get versions
```

#### wdsutil
`initialize-server`
`remInst`

```cmd
wdsutil /initialize-server /remInst:"D:\RemoteInstall"
```
#### winrm
`enumerate`
`get`

List all WinRM listeners  
```cmd
winrm enumerate winrm/config/listener
```
Display WinRM configuration
```cmd
winrm get winrm/config
```
Add an address to Trusted Hosts list <sup>[Zacker][Zacker]: 56</sup>
```cmd
winrm set winrm/config/client @{TrustedHosts="192.168.10.41"}
```
#### winver
#### wmic
[`bios`](#wmic-bios)
`logicaldisk`
`memorychip`
[`os`](#wmic-os)
`path`

Recover Windows product key <sup>[fossbytes.com][https://fossbytes.com/how-to-find-windows-product-key-lost-cmd-powershell-registry/]</sup>
```cmd
wmic path softwarelicensingservice get OA3xOriginalProductKey
```
Display information about installed RAM
```cmd
wmic memorychip list full
```
List all objects of type `Win32_LogicalDisk` using that class's alias `logicaldisk`. <sup>[Desmond][Desmond2009]: 642 [pwsh](PowerShell '```&#10;PS C:\> Get-WmiObject -query "SELECT * FROM Win32_LogicalDisk"&#10;PS C:\> gwmi -q "select * from win32_logicaldisk"&#10;```') </sup>
```cmd
wmic logicaldisk list brief
```
##### wmic bios
Recover serial number of a Lenovo laptop <sup>[pcsupport.lenovo.com][https://pcsupport.lenovo.com/us/en/solutions/find-product-name]</sup>
```cmd
wmic bios get serialnumber
```
Display BIOS version
```cmd
wmic bios get biosversion
```
##### wmic os
Display operating system architecture
```cmd
wmic os get osarchitecture
```
Display operating system type (48 is Windows 10)
```cmd
wmic os get operatingsystemsku
```
#### [wsl][msdocs:wsl.exe]

[wsl.exe -&#108;]: #wsl '```&#10;> wsl.exe -l&#10;> wsl.exe --list&#10;```&#10;List distributions'
[wsl.exe -&#116;]: #wsl '```&#10;> wsl.exe -t $distro&#10;> wsl.exe --terminate $distro&#10;```&#10;Terminate the specified distribution'
[wsl.exe -&#115;]: #wsl '```&#10;> wsl.exe -s $distro&#10;> wsl.exe --set-default $distro&#10;```&#10;Set the distribution as the default'
[wsl.exe --set-default-version]: #wsl.exe '```&#10;> wsl.exe --set-default-version 2&#10;```&#10;Set the version of any new distribution installed to WSL 2'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][wsl.exe -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][wsl.exe -&#115;] [`t`][wsl.exe -&#116;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>\
`export`
`import`
[`set-default-version`][wsl.exe --set-default-version]

#### [wsusutil]][msdocs:wsusutil.exe]

Specify a location for downloaded updates<sup>[Zacker][Zacker]: 393</sup>
```cmd
C:\Program Files\Update Services\Tools\wsusutil.exe postinstall content_dir=d:\wsus
```
Specify SQL server, when not using the default WID database
```cmd
C:\Program Files\Update Services\Tools\wsusutil.exe postinstall sql_instance_name="db1\sqlinstance1"- content_dir=d:\wsus
```

#### wt

[wt -&#112;]: #wt '```&#10;C:\>wt -&#112;&#10;C:\>wt -p "Ubuntu-18.04"&#10;```&#10;Specify the Windows Terminal profile that should be opened'
[wt -&#100;]: #wt '```&#10;C:\>wt -&#100;&#10;C:\>wt -d E:\ &#10;```&#10;Specify the directory used as the starting directory for the console'
[wt --split-pane]: #wt '```&#10;C:\>wt --split-pane&#10;```&#10;Open a new tab, but in a split pane'
[wt --focus-tab]: #wt '```&#10;C:\>wt --focus-tab&#10;```&#10;Specify what tab should gain focus when opened'


<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][wt -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][wt -&#112;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <br> 
[`split-pane`][wt --split-pane]
[`focus-tab`][wt --focus-tab]

Open the default Windows Terminal profile and also an Ubuntu WSL tab <sup>[bleepingcomputer.com][https://www.bleepingcomputer.com/news/microsoft/windows-terminal-09-released-with-command-line-arguments-and-more/]</sup>
```cmd
wt; new-tab -p "Ubuntu-18.04"
```
Open a split pane of the default profile in the D:\ folder and the `cmd` profile in the E:\ folder <sup>[bleepingcomputer.com][https://www.bleepingcomputer.com/news/microsoft/windows-terminal-09-released-with-command-line-arguments-and-more/]</sup>
```cmd
wt -d d:\ ; split-pane -p "cmd" -d e:
```
Open the default profile and an Ubuntu WSL profile, but with the first tab focused <sup>[bleepingcomputer.com][https://www.bleepingcomputer.com/news/microsoft/windows-terminal-09-released-with-command-line-arguments-and-more/]</sup>
```cmd
wt ; new-tab -p "Ubuntu-18.04"; focus-tab -t0
```

#### xcopy

Copy from one directory to another <sup>[Practice Lab][pl:70-740]</sup>
```cmd
xcopy /s c:\inetpub\wwwroot c:\nlbport
```

## Glossary

#### JEA

**Just Enough Administration (JEA)** allows special remote sessions that limit which cmdlets and parameters can be used in a remote PowerShell session.
These are implemented as **restricted endpoints**, to which only members of a specific security group can gain access.
This offers a way to administer remote servers and move away from the traditional method using RDP.

















[AVMA]: #upgrade-and-migration 'Automatic Virtual Machine Activation (AVMA)&#10;Simplifies the process of activating VMs created on Hyper-V servers, whereby a binding is created between the host server and the activation mechanism on each VM, which are activated automatically and remain so.&#10;Requires Datacenter Edition of WS 2016 or WS 2012 R2 on the host server and a specific key, depending on the version of Windows Server on the VM.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 41'
[Activation threshold]: #upgrade-and-migration 'Activation threshold&#10;Minimum of 25 workstation systems or five server systems as clients for KMS&#10;KMS hosts maintain a cache of the 50 most recent workstation requests, and KMS activations expire every 180 days (ref Activation validity interval). &#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 36'
[Activation validity interval]: #upgrade-and-migration 'Activation validity interval&#10;180 days for KMS activations, although clients attempt to renew every 7 days&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 37'
[Active Directory-based activation]: #upgrade-and-migration 'Active Directory-based activation&#10;Use of AD DS for communication and data storage instead of a KMS host&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 39'
[DSC]: #upgrade-and-migration 'Desired State Configuration (DSC)&#10;Windows PowerShell feature that uses script files stored on a central server to apply, monitor, and maintain a specific configuration&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 26'
[GVLK]: #upgrade-and-migration 'generic volume licensing key (GVLK)&#10;Can be used to configure KMS clients that are not KMS clients by default, like those with retail, MAK, or KMS host licenses&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 39'
[KMS]: #upgrade-and-migration 'Key Management Service (KMS)&#10;Client/server application that enables client computers to activate their license doperating system products by communicating with a KMS host computer on the local network (suitable for large networks).&#10;Requires a minimum of 25 workstations (ref Activation threshold) and uses TCP port 1688. KMS hosts create an SRV resource record on DNS to identify it.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 35'
[MAK Independent]: #upgrade-and-migration 'MAK Independent&#10;each computer using the MAK must perform an individual activation with Microsoft over the Internet or by telephone&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 36'
[MAK Proxy]: #upgrade-and-migration 'MAK Proxy&#10;VMAT collects installation IDs from target computers, activates them all at once, then receives and deploys confirmation IDs from Microsoft back to targets&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 36'
[MAK]: #upgrade-and-migration 'Multiple activation key (MAK)&#10;Product key that can be used to activate multiple Windows systems (suitable for small networks).&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 35'
[S2D]: #storage-spaces-direct 'Storage Spaces Direct (S2D)&#10;Windows Server 2016 Datacenter edition feature that enables administrators to use relatively inexpensive drive arrays to create high-availability storage solutions, implementing JBOD&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[Storage Replica]: #server-storage 'Storage Replica&#10;Windows Server 2016 Datacenter edition feature that provides storage-agnostic, synchronous or asynchronous volume replication between local or remote servers, using SMBv3&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 6'
[VAMT]: #upgrade-and-migration 'Volume Activation Management Tool (VAMT)&#10;Collects installation IDs from target computers, sending them to Microsoft using a single connection and receiving confirmation IDs in return, which are deployed to targets.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 35'
[Volume Activation Services]: #upgrade-and-migration 'Volume Activation Services&#10;Windows Server role that must be added before installing a KMS host&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 37'
[Volume Activation Tools]: #upgrade-and-migration 'Volume Activation Tools&#10;&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 37'
[Volume Licensing Services]: #upgrade-and-migration 'Volume Licensing Services&#10;Windows Server role that must be added before being able to use Active Directory-based activation&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 40'
[WDS]: #upgrade-and-migration 'Windows Deployment Services (WDS)&#10;Role included with Windows server 2016 which can deploy disk image files to clients on the network automatically.&#10;Used to deploy operating systems en masse.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 11'
[Windows Hyper-V Server 2016]: #upgrade-and-migration 'Windows Hyper-V Server 2016&#10;Free hypervisor-only download that hosts VMs.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[Windows Server 2016 Datacenter]: #upgrade-and-migration 'Windows Server 2016 Datacenter&#10;Edition that allows unlimited number of operating system environments or Hyper-V containers and includes Storage Spaces Direct, Storage Replica, shielded VMs, and a new networking stack with additional virtualization options&#10;Intended for large and powerful servers in a highly virtualized environment.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 4'
[Windows Server 2016 Essentials]: #upgrade-and-migration 'Windows Server 2016 Essentials&#10;Edition that is limited to one OSE and a maximum of 25 users and 50 devices and excludes the Server Core installation option&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[Windows Server 2016 MultiPoint Premium Server]: #upgrade-and-migration 'Windows Server 2016 MultiPoint Premium Server&#10;Academic edition that enables multiple users to access a single server installation&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[Windows Server 2016 Standard]: #upgrade-and-migration 'Windows Server 2016 Standard&#10;Edition that allows for two operating system environments, but lacks the storage and networking features included in Datacenter.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[Windows Server Migration Tools]: #upgrade-and-migration 'Windows Server Migration Tools&#10;Five Windows Powershell cmdlets that enable administrators to migrate certain roles between servers&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 33'
[Windows Storage Server 2016]: #upgrade-and-migration 'Windows Storage Server 2016&#10;Bundled as part of a dedicated storage hardware solution&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 5'
[network controller]: #upgrade-and-migration 'network controller&#10;Windows Server 2016 Datacenter edition feature that provides a central automation point for network infrastructure configuration, monitoring, and troubleshooting&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 6'
[shielded virtual machines]: #upgrade-and-migration 'shielded virtual machines&#10;Windows Server 2016 Datacenter edition feature that provides VMs with protection from compromised administrators that have access to the Hyper-V host computer by encrypting the VM state and virtual disks&#10;A shielded VM is a generation 2 VM that has a virtual TPM, is encrypted using BitLocker, and can run only on healthy and approved hosts in a guarded fabric.&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 6'


[https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/]: https://sumtips.com/tips-n-tricks/manage-disk-partitions-with-windows-powershell/ "SumTips.com - Manage disk partitions with Windows PowerShell"
[https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/get-smbopenfile?view=win10-ps '"Get-SmbOpenFile". _Microsoft Docs_.'
[https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps]: https://docs.microsoft.com/en-us/powershell/module/smbshare/close-smbopenfile?view=win10-ps '"Close-SmbOpenFile". _Microsoft Docs_.'
[https://www.thewindowsclub.com/find-windows-product-key]:  https://www.thewindowsclub.com/find-windows-product-key "TheWindowsClub: \"How to find Windows Product Key using Command Prompt or PowerShell\""
[https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7]: https://docs.microsoft.com/en-us/powershell/scripting/samples/working-with-registry-entries?view=powershell-7 "Working with Registry Entries"
[https://adamtheautomator.com/powershell-random-password/]: https://adamtheautomator.com/powershell-random-password/ "How to Generate a Random Password with PowerShell"
[https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/]: https://devblogs.microsoft.com/scripting/powertip-use-powershell-to-get-computer-name/

[ADAC]:   https://github.com/jasper-zanjani/notes/master/sources/adac.md "Berkouwer, Sander. _Active Directory Administration Cookbook_."
[IMWS]:   https://github.com/jasper-zanjani/notes/master/sources/imws.md "McCabe, John. _Introduction to Microsoft Windows Server 2016_."
[Jones]:  https://subscription.packtpub.com/video/virtualization_and_cloud/9781789616385 "Jones, Joshua B. _Hands-On Powershell for Active Directory_. PacktPub: 2018."
[WSAC]:   https://github.com/jasper-zanjani/notes/master/sources/wsac.md "Krause, Jordan. _Windows Server 2016 Administration Cookbook_."
[Zacker]: # "Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017."
[Warren]: # 'Warren, Andrew. _Exam Ref 70-742: Identity with Windows Server 2016_. 2017.'
[Holmes]: # 'Holmes, Lee. _Windows PowerShell Cookbook_. O\'Reilly Media, 2013.'
[SOPR]: https://leanpub.com/secretsofpowershellremoting 'Don Jones et al. _Secrets of Powershell Remoting_. '
[mu:70-740]: # 'MeasureUp Practice Test. _Installation, Storage and Compute with Windows Server 2016 (70-740)_.'
[pl:70-740]: # 'MeasureUp Practice Lab: Installation, Storage and Compute with Windows Server 2016 (70-740)'
