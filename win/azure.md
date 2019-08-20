# Microsoft Azure
## Web Apps
__Web Apps__ represent Azure's __PaaS__ product. It is part of the __App Service__ family, which include:
  - Mobile Apps
  - API Apps
  - Logic Apps\
Each App Service resource is associated with a __service plan__, which defines the amount of resources available.\
Service plan tiers:
  - **Free/Shared**: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
  - **Basic**: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
  - **Standard**: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
  - **Premium**: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.
## Role assignments and classic administrators
VMs represent Azure's __IaaS__ product. Manage access to Azure resources using __role-based access control (RBAC)__. __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.
## Monitor
Monitor incorporates alerts and metrics
### Alerts
Alerts can have 3 states:
  - **New** and not reviewed
  - **Acknowledged** issue is being actioned by an admin
  - **Closed** issue that generated the alerts has been resolved and the alert has been marked as closed

Alerts can have two monitor conditions:
  - **Fired** when Azure generates an alert
  - **Resolved** when the underlying condition has been cleared

Alerts are centered around **alert rules**, which contain:
  - Name and description
  - Severity (0 to 4)
  - Target resource
  - Signal emitted by target
  - Conditional logic for alert
  - Action group, or what should happen when the alert rule condition is met

### Metrics
Metrics are of 2 types
  1. **Platform metrics** created by Azure resources and made available in Azure Monitor for queries and alerts
  2. **Application metrics** from **Application Insights**

Metrics can have up to 10 name-value pairs (dimensions) and have the following properties
  - **Time** value was collected
  - **Type** of measurement the value represents
  - **Resource** associated with the value
  - **Value**
## VMs
### Operating system images
VM images are captured from an existing VM that has been prepared (or "generalized"). This removes unique settings (hostname, security IDs, personal information, user accounts, domain join information, etc) but not customizations (software installations, patches, additional files, folders).\
2 methods of generalizing a VM:
  1. **sysprep.exe**
  2. **Microsoft Azure Linux Agent (waagent)**
2 types of VM image types
  1. **Managed** images (recommended), which remove the dependency of the VM to the image, at least within the same region. Copying a VM to another region still requires the managed image to be copied first.
  2. **Unmanaged** images, which required the VM to be created in the same storage account as that of the image. VM copies required the image to be copies first.
## VNets
**Virtual Networks** (VNets) created through Portal require at least one subnet.
### Subnets
Subnet names are immutable and must be unique within each VNet, and their IP ranges must be described using CIDR notation. They can only be deleted if empty.\
Azure will reserve **5** IP addresses from each subnet IP range.
  - First and last IP addresses in each subnet are reserved for network identification and broadcast
  - An additional three addresses at the start (bottom) of the range are reserved. (This means the smallest possible subnet is `/29`, providing 3 addresses for use)
  - e.g. the first available IP address in range `192.168.1.0/24` is `192.168.1.4`
## Azure blades
## Storage
4 storage services provided within each storage account:
  1. **Blobs** provides a highly scalable service for storing arbitrary data objects, such as text or binary data
  2. **Tables** provides a NoSQL-style store for storing structured data. Tables in Azure storage do not require a fixed schema, thus different entries in the same table can have different fields
  3. **Queues** provides reliable message queueing between application components
  4. **Files** provides managed file shares that can be used by VMs or on-premises servers\
3 types of storage blobs (type is set at creation and cannot be changed)
  1. **Block** blobs
  2. **Append** blobs
  3. **Page** blobs: used to store VHD files when deploying unmanaged disks (not recommended)\
Options that must be selected when creating a storage account:
  - Performance tier
    - **Standard** supports all storage services and uses magnetic disks to provide cost-efficient and reliable storage
    - **Premium** only supports page blobs with the locally-redundant (LRS) replication option, uses high-performance SSD disks\ 
  - Account kind (Both Blob and StorageV1 can be upgraded to StorageV2, a process which is irreversible)
    - **General-purpose V2**: only kind to support ZRS
    - **General-purpose V1**: does not support various access tiers.
    - **Blob storage**: specialized storage account used to store block and append blobs\
  - Replication option
    - **Locally-redundant storage (LRS)** makes 3 local sychronous (within a single datacenter) copies 
    - **Zone-redundant storage (ZRS)** makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at **Standard** performance tier only.
    - **Geographically-redundant storage (GRS)** makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
    - **Read-access geographically redundant storage (RA-GRS)** makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access\
  - Access tier\ 
    - **Hot** blob storage access tier optimized for the frequent access of objects in the storage account
    - **Cool** blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
    - **Archive** blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days. It is stored offline and can take up to 15 hours for it to be "rehydrated" to the Cool or Hot tier before it can be accessed.
    - **Premium** providing high-performance access for frequently-used data on SSD, only available from the **Block Blob** storage account type.\ 
## Azure blades
Blade                                   | Option                | Topics
:---                                    | :---                  | :---
Alerts                                  | New alert rule        | Create Alerts
                                        | Manage alert rules    | View existing alert rules
Import/Export Jobs                      |                       | Import and export data 
Log Analytics                           | Create                | Configure a new Log Analytics workspace
Metrics                                 | 
Monitor                                 | Alerts                | View alerts, Create Alerts, Manage Alert rules
                                        | Metrics               | View and create charts using metrics
Storage account                         | Firewalls and Virtual Networks |  Storage Firewall, allowing access to virtual networks
                                        | Access keys           | Access storage name and key
Subscription                            | Access Control (IAM)  | Assign subscription administrator permissions, including classic and RBAC roles
## Glossary

Term                                    | Definition  | Source
:---                                    | :---        | :---
action group                            | component of an alert rule that provides the definition for what will happen when the conditions of the alert rule are met | [A](#sources): 34
alert rule                              | criteria used to evaluate when an alert should be generated; targets resources in a single subscription | [A](#sources): 32, 41
append blob                             | blob type optimized for append operations, with no support for modification of existing blob contents, most commonly used for log files | [A](#sources): 130
blob storage                            | used for large-scale storage of arbitrary data objects, such as media files, log files, or other objects | [A](#sources): 129
block blob                              | blob type optimized for efficient uploads and downloads for video, image, and other general-purpose storage | [A](#sources): 130
container                               | subdivision of a storage account, in which blobs are stored; similar in concept to a hard drive in that they provide a storage space in which blobs can be organized in a directory structure | [A](#sources): 129
bring your own key (BYOK)               | act of importing keys to Azure Key Vault
endpoint                                | file servers and paths within the file server you want the sync group to sync with each other | [A](#sources):
forced tunneling                        | practice of overriding the default route sending 0.0.0.0/0-bound traffic to the Internet for the purpose of routing that traffic to an on-premises network security appliance | [A](#sources): 301
Hardware Security Modules (HSM)         | one of the ways keys in __Azure Key Vault__ can be protected
initiative assignment                   | tie **initiative definitions** to a specific scope | [A](#sources): 15 
initiative definition                   | package: **policy definitions** together | [A](#sources): 15
key rolling                             | regenerate one access key by switching applications to a second one before regenerating the first | [A](#sources): 114
logs                                    | numerical data or text
metrics                                 | numerical values output by resources and services within Azure | [A](#sources): 43
page blob                               | blob type optimized for random-access I/O, typically used to store VHD files when using unmanaged disks | [A](#sources): 130
policy assignment                       | part of policy implementation that ties a **policy definition** to a specific scope | [A](#sources): 15
policy definition                       | describes desired behavior for Azure resources at the time resources are created or updated | [A](#sources): 15
resource                                | manageable item that is available through Azure, including virtual machines, storage accounts, web apps, databases, and virtual networks | D, [A](#sources): 62
resource group                          | container that holds related resources for an Azure solution | [Azure Resource Manager overview](https://docs.microsoft.com/en-us/azure/azure-resource-manager/resource-group-overview)
resource provider                       | service that supplies Azure resources (e.g. `Microsoft.Compute`, `Microsoft.Insights`, `Microsoft.Storage`) | [Azure Resource Manager overview](https://docs.microsoft.com/en-us/azure/azure-resource-manager/resource-group-overview)
role                                    | definition of what action is allowed or denied to a **security principal** | [A](#sources): 85
role inheritance                        | process where child resources inherit the **role** assignments of parents | [A#sourcesrity principal                      | entities with access to Azure resources, i.e. users, groups, and service identities | [A](#sources): 85
soft delete                             | Storage account feature that allows you to save and recover data when blobs or blob snapshots are deleted even in the event of an overwrite | [A](#sources): 135
Desired State Configuration (DSC)       | a common Windows PowerShell extension for configuration management | A: 259

Azure feature                           | Description | Source
:---                                    | :---        | :---
Archive                                 | blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days.
async blob copy service                 | server-side based service that can copy files you specify from a source location to a destination in an Azure Storage account | [A](#sources): 124
Azure Activity Log                      | subscription level log that captures events from operational data to service health events for a subscription | [A](#sources): 119
Azure Resource Manager                  | service that manages and deploys resources in an Azure subscription, providing consistent capabilities and results across various such as the Portal, PowerShell, Azure CLI, REST APIs, and client SDKs ![Azure Resource Manager](https://docs.microsoft.com/en-us/azure/azure-resource-manager/media/resource-group-overview/consistent-management-layer.png)| [D](#sources)
Application Insights                    | service that can provide __application metrics__, if enabled and if the applications have been instrumented (now integrated into **Azure Monitor**) | [A](#sources): 44
Automation                              | allows you to build __runbooks__ that execute commands or scripts
Backup                                  | service that allows you to backup on-premises servers, cloud-based VMs, and virtualized workloads such as SQL Server and SharePoint to Microsoft Azure. | [A](#sources): 159
Backup Reports                          | provide data visualization from within Power BI from across Recovery Service vaults and Azure subscriptions to provide insight into backup activity | [A](#sources): 170
Backup Server                           | stand-alone service that is installed on a Windows Server operating system that stores backup data in a **Microsoft Azure Recovery Vault** | [A](#sources): 169, 271
BlobCache                               | multi-tier caching technology used on Azure VMs with SSDs; uses a combination of the RAM on the VM and local SSD | A: 201
Cloudyn                                 | service requiring separate registration that can track resource cost for Azure resources and resource usage for AWS and Azure. | [A](#sources): 60
Connection Monitor                      | a **Network Watcher** feature that provides ongoing connection monitoring between a VM or App Gateway and another endpoint | A: 385
Connection Troubleshoot                 | a **Network Watcher** feature that allows you to test connectivity between a VM or App Gateway and another endpoint | A: 384
Cool                                    | blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
Data Box                                | device that Microsoft will send to you that allows you to copy your data to it and then ship back to Microsoft for upload to Azure | [A](#sources): 129
Dependency Agent                        | one of the two agents required by **Service Map** | [A](#sources): 349
Enterprise Agreement 
ExpressRoute Monitor                    | one of the three **Network Performance Monitor** services that monitors end-to-end connectivity between on-premises network and Azure over ExpressRoute connections | [A](#sources): 369
File Service                            | fully managed file share service that offers endpoints for __SMB__ (__CIFS__) protocol | [A](#sources): 147
File Sync                               | extends Azure File Service to allow on-premises file server to be extended to Azure | [A](#sources): 152
File Sync agent                         | software that needs to be deployed on every server to be added to an **Azure File Sync** group | [A](#sources): 152
Functions                               | 
Geographically-redundant storage (GRS)  | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
Hot                                     | blob storage access tier optimized for the frequent access of objects in the storage account
Import and Export service               | allows you to ship data into or out of an Azure Storage account by physically shipping disks to an Azure datacenter | [A](#sources): 129
IP Flow Verify                          | a **Network Watcher** tool that provides a quick and easy way to test if a given network flow will be allowe4d into or out of a VM | A: 376
Key Vault                               | helps safeguard cryptographic keys and secrets used by cloud applications and services | [A](#sources): 114
Kusto                                   | query language comparable to SQL used by Log Analytics. Kusto queries use the pipe character to separate commands, always begin with a scope, are case-sensitive, and generate read-only requests so log entries are only deleted based on retention policy. | [A](#sources): 53
Locally-redundant storage (LRS)         | Storage replication option that makes 3 local synchronous (within a single datacenter) copies 
Log Analytics                           | facilitates collection, correlation, search, and action on log and performance data, organized in __workspaces__ (now being called **Azure Monitor logs** | [A](#sources): 47-48; 
Log Analytics (OMS) agent)              | agent required to be installed on a machine for it to report telemetry to Azure Log Analytics (previously known as __Microsoft Monitoring Agent__, now integrated into **Azure Monitor**)
Log Analytics workspace                 | where logs are collected and aggregated | [A](#sources): 48
Logic Apps
Microsoft Azure Recovery Services (MARS) agent | stand-alone agent used to protect files and folders; one of the various backup agents that can be used with **Azure Backup** | [A](#sources): 162
Microsoft Monitoring Agent (MMA)        | one of the two agents required by **Service Map** | [A](#sources): 349
Monitor                                 | "single pane of glass" to manage __metrics__, __logs__, and **alerts** from multiple subscriptions | [E](#sources)
Network Performance Monitor (NPM)       | network monitorign solution that offers three main services and a dashboard giving an overview of network status | [A](#sources): 368
Network Security Group (NSG)            | allow you to control which network flows are permitted into and out of your virtual networks and virtual machines | [A](#sources): 338
Network Topology                        | a **Network Watcher** view that provides a diagrammatic view of the resources in a virtual network as a quick and easy way to review network resources and manually check for misconfiguration | A: 380
Network Watcher                         | central hub for a wide range of network monitoring and diagnostic tools | A: 375
Next Hop                                | a **Network Watcher** view that provides a useful way to understand how a VM's outbound traffic is being directed | A: 377
Packet Captures                         | a **Network Watcher** tool that allows you to capture network packets entering or leaving VMs | A: 378
Performance Monitor                     | one of the three **Network Performance Monitor** services that monitors connectivity between various points in the network, both in Azure and on-premises; enables monitoring of packet loss and latency between endpoints | [A](#sources): 369
Policy                                  | service that can create, assign, and manage policies to enforce governance.
Read-access geographically redundant storage (RA-GRS) | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access
Recovery Services vault                 | the single resource that is provisioned for either **Azure Backup** or **Azure Site Recovery** | [A](#sources): 160
Resource                                | single service instance, which can be a virtual machine, a virtual network, a storage account, or any other Azure service | [A](#sources): 62
Resource group                          | logical group of resources | [A](#sources): 63
Resource group template                 | JSON file that allows you to declaratively describe a set of resources | [A](#sources): 100
Service Connectivity Monitor            | one of the three **Network Performance Monitor** services that monitors outbound connectivity from nodes on the network to any external service with an open TCP port | [A](#sources): 369
Service Map                             | Log Analytics solution that helps you document network flows from a running application and provides rich reporting of dependencies and network flows; installs two agents on each server: **Microsoft Monitoring Agent** and **Dependency Agent** | [A](#sources): 349
Shared Access Signature (SAS) token     | query string parameter appended to the full URI of a storage resource | [A](#sources): 118
Storage Explorer                        | cross-platform application designed to help you quickly manage one or more Azure storage accounts that supports all storage services and CosmosDB and Azure Data Lake Storage services
VMSnapshot                              | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup | [A](#sources): 270
VMSnapshotLinux                         | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup | [A](#sources): 270
VPN Troubleshoot                        | a **Network Watcher** feature that provides automated diagnostics of Azure VPN gateways and connections | A: 381
Zone-redundant storage (ZRS)            | Storage replication option that makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at **Standard** performance tier only.
## Sources
A. Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref A Microsoft Azure Administrator_. [AZ-103](../sources/A.md)
B. Foulds, Iain. _Learn Azure in a Month of Lunches_. [LZML](../sources/README.md)
C. "Overview of alerts in Microsoft Azure". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/alerts-overview). 2018/01/27
D. "Azure Resource Manager overview". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-resource-manager/resource-group-overview)
E. "Azure Monitor terminology changes". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/terminology).