# Microsoft Azure

## Web Apps
__Web Apps__ represent Azure's __PaaS__ product. It is part of the __App Service__ family, which include:
  - Mobile Apps
  - API Apps
  - Logic Apps

Each App Service resource is associated with a __service plan__, which defines the amount of resources available.

Service plan tiers:
  - Free/Shared: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
  - Basic: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
  - Standard: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
  - Premium: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.
  
## Role assignments and classic administrators
VMs represent Azure's __IaaS__ product. Manage access to Azure resources using __role-based access control (RBAC)__. __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.

## Alerts
Alerts can have 3 states:
  - **New** and not reviewed
  - **Acknowledged** issue is being actioned by an admin
  - **Closed** issue that generated the alerts has been resolved and the alert has been marked as closed

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
append blob                             | blob type optimized for append operations, with no support for modification of existing blob contents, most commonly used for log files | [AZ-103](../sources/az-103.md): 130
blob storage                            | used for large-scale storage of arbitrary data objects, such as media files, log files, or other objects | [AZ-103](../sources/az-103.md): 129
block blob                              | blob type optimized for efficient uploads and downloads for video, image, and other general-purpose storage | [AZ-103](../sources/az-103.md): 130
container                               | subdivision of a storage account, in which blobs are stored; similar in concept to a hard drive in that they provide a storage space in which blobs can be organized in a directory structure | [AZ-103](../sources/az-103.md): 129
bring your own key (BYOK)               | act of importing keys to Azure Key Vault
endpoint                                | file servers and paths within the file server you want the sync group to sync with each other | [AZ-103](../sources/az-103.md):
forced tunneling                        | practice of overriding the default route sending 0.0.0.0/0-bound traffic to the Internet for the purpose of routing that traffic to an on-premises network security appliance | [AZ-103](../sources/az-103.md): 301
Hardware Security Modules (HSM)         | one of the ways keys in __Azure Key Vault__ can be protected
key rolling                             | regenerate one access key by switching applications to a second one before regenerating the first | [AZ-103](../sources/az-103.md): 114
logs                                    | numerical data or text
metrics                                 | numerical values output by resources and services within Azure | [AZ-103](../sources/az-103.md): 43
page blob                               | blob type optimized for random-access I/O, typically used to store VHD files when using unmanaged disks | [AZ-103](../sources/az-103.md): 130
role                                    | definition of what action is allowed or denied to a **security principal** | [AZ-103](../sources/az-103.md): 85
security principal                      | entities with access to Azure resources, i.e. users, groups, and service identities | [AZ-103](../sources/az-103.md): 85
soft delete                             | Storage account feature that allows you to save and recover data when blobs or blob snapshots are deleted even in the event of an overwrite | [AZ-103](../sources/az-103.md): 135
Desired State Configuration (DSC)       | a common Windows PowerShell extension for configuration management | AZ-103: 259

Azure feature                           | Description | Source
:---                                    | :---        | :---
Archive                                 | blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days.
async blob copy service                 | server-side based service that can copy files you specify from a source location to a destination in an Azure Storage account | [AZ-103](../sources/az-103.md): 124
Azure Activity Log                      | subscription level log that captures events from operational data to service health events for a subscription | [AZ-103](../sources/az-103.md): 119
Application Insights                    | service that can provide __application metrics__, if enabled and if the applications have been instrumented | [AZ-103](../sources/az-103.md): 44
Azure Automation                        | allows you to build __runbooks__ that execute commands or scripts
Azure Backup                            | service that allows you to backup on-premises servers, cloud-based VMs, and virtualized workloads such as SQL Server and SharePoint to Microsoft Azure. | [AZ-103](../sources/az-103.md): 159
Azure Backup Reports                    | provide data visualization from within Power BI from across Recovery Service vaults and Azure subscriptions to provide insight into backup activity | [AZ-103](../sources/az-103.md): 170
Azure Backup Server                     | stand-alone service that is installed on a Windows Server operating system that stores backup data in a **Microsoft Azure Recovery Vault** | [AZ-103](../sources/az-103.md): 169, 271
Azure Data Box                          | device that Microsoft will send to you that allows you to copy your data to it and then ship back to Microsoft for upload to Azure | [AZ-103](../sources/az-103.md): 129
Azure File Service                      | fully managed file share service that offers endpoints for __SMB__ (__CIFS__) protocol | [AZ-103](../sources/az-103.md): 147
Azure File Sync                         | extends Azure File Service to allow on-premises file server to be extended to Azure | [AZ-103](../sources/az-103.md): 152
Azure File Sync agent                   | software that needs to be deployed on every server to be added to an **Azure File Sync** group | [AZ-103](../sources/az-103.md): 152
Azure Functions
Azure Import and Export service         | allows you to ship data into or out of an Azure Storage account by physically shipping disks to an Azure datacenter | [AZ-103](../sources/az-103.md): 129
Azure Key Vault                         | helps safeguard cryptographic keys and secrets used by cloud applications and services | [AZ-103](../sources/az-103.md): 114
Azure Log Analytics (OMS) agent)        | agent required to be installed on a machine for it to report telemetry to Azure Log Analytics (previously known as __Microsoft Monitoring Agent__)
Azure Monitor                           | "single pane of glass" to manage __metrics__, __logs__, and **alerts** from multiple subscriptions
Azure Network Performance Monitor (NPM) | network monitorign solution that offers three main services and a dashboard giving an overview of network status | [AZ-103](../sources/az-103.md): 368
Azure Policy                            | service that can create, assign, and manage policies to enforce governance.
Azure Storage Explorer                  | cross-platform application designed to help you quickly manage one or more Azure storage accounts that supports all storage services and CosmosDB and Azure Data Lake Storage services
Cloudyn                                 | service requiring separate registration that can track resource cost for Azure resources and resource usage for AWS and Azure. | [AZ-103](../sources/az-103.md): 60
Connection Monitor                      | a **Network Watcher** feature that provides ongoing connection monitoring between a VM or App Gateway and another endpoint | AZ-103: 385
Connection Troubleshoot                 | a **Network Watcher** feature that allows you to test connectivity between a VM or App Gateway and another endpoint | AZ-103: 384
Cool                                    | blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
Dependency Agent                        | one of the two agents required by **Service Map** | [AZ-103](../sources/az-103.md): 349
Enterprise Agreement 
ExpressRoute Monitor                    | one of the three **Network Performance Monitor** services that monitors end-to-end connectivity between on-premises network and Azure over ExpressRoute connections | [AZ-103](../sources/az-103.md): 369
Geographically-redundant storage (GRS)  | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
Hot                                     | blob storage access tier optimized for the frequent access of objects in the storage account
IP Flow Verify                          | a **Network Watcher** tool that provides a quick and easy way to test if a given network flow will be allowe4d into or out of a VM | AZ-103: 376
Kusto                                   | query language comparable to SQL used by Log Analytics. Kusto queries use the pipe character to separate commands, always begin with a scope, are case-sensitive, and generate read-only requests so log entries are only deleted based on retention policy. | [AZ-103](../sources/az-103.md): 53
Locally-redundant storage (LRS)         | Storage replication option that makes 3 local synchronous (within a single datacenter) copies 
Log Analytics                           | facilitates collection, correlation, search, and action on log and performance data, organized in __workspaces__ | [AZ-103](../sources/az-103.md): 47-48.
Log Analytics workspace                 | where logs are collected and aggregated | [AZ-103](../sources/az-103.md): 48
Logic Apps
Microsoft Azure Recovery Services (MARS) agent | stand-alone agent used to protect files and folders; one of the various backup agents that can be used with **Azure Backup** | [AZ-103](../sources/az-103.md): 162
Microsoft Monitoring Agent (MMA)        | one of the two agents required by **Service Map** | [AZ-103](../sources/az-103.md): 349
Network Security Group (NSG)            | allow you to control which network flows are permitted into and out of your virtual networks and virtual machines | [AZ-103](../sources/az-103.md): 338
Network Topology                        | a **Network Watcher** view that provides a diagrammatic view of the resources in a virtual network as a quick and easy way to review network resources and manually check for misconfiguration | AZ-103: 380
Network Watcher                         | central hub for a wide range of network monitoring and diagnostic tools | AZ-103: 375
Next Hop                                | a **Network Watcher** view that provides a useful way to understand how a VM's outbound traffic is being directed | AZ-103: 377
Packet Captures                         | a **Network Watcher** tool that allows you to capture network packets entering or leaving VMs | AZ-103: 378
Performance Monitor                     | one of the three **Network Performance Monitor** services that monitors connectivity between various points in the network, both in Azure and on-premises; enables monitoring of packet loss and latency between endpoints | [AZ-103](../sources/az-103.md): 369
Read-access geographically redundant storage (RA-GRS) | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access
Recovery Services vault                 | the single resource that is provisioned for either **Azure Backup** or **Azure Site Recovery** | [AZ-103](../sources/az-103.md): 160
Resource                                | single service instance, which can be a virtual machine, a virtual network, a storage account, or any other Azure service | [AZ-103](../sources/az-103.md): 62
Resource group                          | logical group of resources | [AZ-103](../sources/az-103.md): 63
Resource group template                 | JSON file that allows you to declaratively describe a set of resources | [AZ-103](../sources/az-103.md): 100
Service Connectivity Monitor            | one of the three **Network Performance Monitor** services that monitors outbound connectivity from nodes on the network to any external service with an open TCP port | [AZ-103](../sources/az-103.md): 369
Service Map                             | Log Analytics solution that helps you document network flows from a running application and provides rich reporting of dependencies and network flows; installs two agents on each server: **Microsoft Monitoring Agent** and **Dependency Agent** | [AZ-103](../sources/az-103.md): 349
Shared Access Signature (SAS) token     | query string parameter appended to the full URI of a storage resource | [AZ-103](../sources/az-103.md): 118
VMSnapshot                              | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup | [AZ-103](../sources/az-103.md): 270
VMSnapshotLinux                         | extension automatically deployed by the Azure fabric controller to VMs while configuring backups through Azure Backup | [AZ-103](../sources/az-103.md): 270
VPN Troubleshoot                        | a **Network Watcher** feature that provides automated diagnostics of Azure VPN gateways and connections | AZ-103: 381
Zone-redundant storage (ZRS)            | Storage replication option that makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at **Standard** performance tier only.

## Sources
  - Foulds, Iain. _Learn Azure in a Month of Lunches_. [LZML](../sources/lzml.md)
  - Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref AZ-103 Microsoft Azure Administrator_. [AZ-103](../sources/az-103.md)
  - "Overview of alerts in Microsoft Azure". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/alerts-overview). 2018/01/27