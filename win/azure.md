# Microsoft Azure

## Web Apps
__Web Apps__ represent Azure's __PaaS__ product. It is part of the __App Service__ family.

Other __App Service__ family members:
  - Mobile Apps
  - API Apps
  - Logic Apps

Each App Service resource is associated with a __service plan__, which defines the amount of resources available.

Service plan tiers:
  - Free/Shared: uses a shared infrastructure with minimal storage. No options for deploying different staged versions, routing of traffic, or backups
  - Basic: Dedicated compute for app, including avaiilability of SSL and manual scaling of app instance number.
  - Standard: Daily backups, automatic scaling of app instances, deployment slots, and user routing with Traffic Manager
  - Premium: more frequent backups, increased storage, and greater number of deployment slots and instance scaling options.
  
## Storage


## Role assignments and classic administrators
VMs represent Azure's __IaaS__ product.
Manage access to Azure resources using __role-based access control (RBAC)__. __Service Administrator__ and __Co-Administrator__ are legacy roles used with the classic deployment model.

## Alerts
Alerts can have 3 states:
  - **New** and not reviewed
  - **Acknowledged** issue is being actioned by an admin
  - **Closed** issue that generated the alerts has been resolved and the alert has been marked as closed

##### Sources
  - "Overview of alerts in Microsoft Azure". [Microsoft Docs](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/alerts-overview). 2018/01/27
  - Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref AZ-103 Microsoft Azure Administrator_. [sources/az-103.md](../sources/az-103.md): 31-40.

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
append blob                             | blob type optimized for append operations, with no support for modification of existing blob contents, most commonly used for log files | [az-103.md](../sources/az-103.md): 130
blob storage                            | used for large-scale storage of arbitrary data objects, such as media files, log files, or other objects | [az-103.md](../sources/az-103.md): 129
block blob                              | blob type optimized for efficient uploads and downloads for video, image, and other general-purpose storage | [az-103.md](../sources/az-103.md): 130
container                               | subdivision of a storage account, in which blobs are stored; similar in concept to a hard drive in that they provide a storage space in which blobs can be organized in a directory structure | [az-103.md](../sources/az-103.md): 129
bring your own key (BYOK)               | act of importing keys to Azure Key Vault
Hardware Security Modules (HSM)         | one of the ways keys in __Azure Key Vault__ can be protected
key rolling                             | regenerate one access key by switching applications to a second one before regenerating the first | [az-103.md](../sources/az-103.md): 114
logs                                    | numerical data or text
metrics                                 | numerical values output by resources and services within Azure | [az-103.md](../sources/az-103.md): 43
page blob                               | blob type optimized for random-access I/O, typically used to store VHD files when using unmanaged disks | [az-103.md](../sources/az-103.md): 130
soft delete                             | Storage account feature that allows you to save and recover data when blobs or blob snapshots are deleted even in the event of an overwrite | [az-103.md](../sources/az-103.md): 135

Azure feature                           | Description | Source
:---                                    | :---        | :---
async blob copy service                 | server-side based service that can copy files you specify from a source location to a destination in an Azure Storage account | [az-103.md](../sources/az-103.md): 124
Azure Activity Log                      | subscription level log that captures events from operational data to service health events for a subscription | [az-103.md](../sources/az-103.md): 119
Application Insights                    | service that can provide __application metrics__, if enabled and if the applications have been instrumented | [az-103.md](../sources/az-103.md): 44
Azure Automation                        | allows you to build __runbooks__ that execute commands or scripts
Azure Data Box                          | device that Microsoft will send to you that allows you to copy your data to it and then ship back to Microsoft for upload to Azure | [az-103.md](../sources/az-103.md): 129
Azure File Service                      | fully managed file share service that offers endpoints for __SMB__ (__CIFS__) protocol | [az-103.md](../sources/az-103.md): 147
Azure Functions
Azure Import and Export service         | allows you to ship data into or out of an Azure Storage account by physically shipping disks to an Azure datacenter | [az-103.md](../sources/az-103.md): 129
Azure Key Vault                         | helps safeguard cryptographic keys and secrets used by cloud applications and services | [az-103.md](../sources/az-103.md): 114
Azure Log Analytics (OMS) agent)        | agent required to be installed on a machine for it to report telemetry to Azure Log Analytics (previously known as __Microsoft Monitoring Agent__)
Azure Monitor                           | "single pane of glass" to manage __metrics__, __logs__, and **alerts** from multiple subscriptions
Azure Policy                            | service that can create, assign, and manage policies to enforce governance.
Azure Storage Explorer                  | cross-platform application designed to help you quickly manage one or more Azure storage accounts that supports all storage services and CosmosDB and Azure Data Lake Storage services
Cloudyn                                 | service requiring separate registration that can track resource cost for Azure resources and resource usage for AWS and Azure. | [az-103.md](../sources/az-103.md): 60
Enterprise Agreement 
ExpressRoute                            | 
Kusto                                   | query language comparable to SQL used by Log Analytics. Kusto queries use the pipe character to separate commands, always begin with a scope, are case-sensitive, and generate read-only requests so log entries are only deleted based on retention policy. | [az-103.md](../sources/az-103.md): 53
Log Analytics                           | facilitates collection, correlation, search, and action on log and performance data, organized in __workspaces__ | [az-103.md](../sources/az-103.md): 47-48.
Log Analytics workspace                 | where logs are collected and aggregated | [az-103.md](../sources/az-103.md): 48
Logic Apps
Resource                                | single service instance, which can be a virtual machine, a virtual network, a storage account, or any toher Azure service | [az-103.md](../sources/az-103.md): 62
Resource group                          | logical group of resources | [az-103.md](../sources/az-103.md): 63
Resource group template                 | JSON file that allows you to declaratively describe a set of resources | [az-103.md](../sources/az-103.md): 100
Shared Access Signature (SAS) token     | query string parameter appended to the full URI of a storage resource | [az-103.md](../sources/az-103.md): 118
Locally-redundant storage (LRS)         | Storage replication option that makes 3 local synchronous (within a single datacenter) copies 
Zone-redundant storage (ZRS)            | Storage replication option that makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at **Standard** performance tier only.
Geographically-redundant storage (GRS)  | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
Read-access geographically redundant storage (RA-GRS) | Storage replication option that makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access
Hot                                     | blob storage access tier optimized for the frequent access of objects in the storage account
Cool                                    | blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
Archive                                 | blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days.


## Sources
  - Foulds, Iain. _Learn Azure in a Month of Lunches_. [sources/lzml.md](../sources/lzml.md)
  - Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref AZ-103 Microsoft Azure Administrator_. [sources/az-103.md](../sources/az-103.md)