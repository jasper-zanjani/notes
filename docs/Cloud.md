# ☁&#xfe0f; Cloud

Links TODO:

- Glacier
- Google Cloud Storage (GCS)
- gcloud
- gsutil


Beginning in 2000, Amazon began developing Merchant.com, a planned e-commerce service that was intended to be the base upon which other enterprises would develop online shopping sites.
At the time, Amazon's development environment was a jumbled mess, and in the effort to consolidate and organize the enterprise into a set of well-documented APIs.

Despite these changes, software development remained sluggish, and an investigation discovered that individual teams were procuring storage, compute, and database resources independently.
AWS originated out of the effort to consolidate these resources across the enterprise and remove this bottleneck.

Azure was announced in 2008 and publicly released in 2010 after earlier experiments in cloud computing like Whitehorse and RedDog. 
In fact, references to the "classic" model predating the Azure Resource Manager (ARM) actually refer to RedDog: the "classic" portal was also known as "RedDog Front-End".



| Service            | Azure                                                                                                                                                | AWS                                                                                                                                                                                                                                 | GCP                                                                                                                                                                                                                                                                |
| ------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Administration** |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| CLI                | Azure CLI [📄](https://docs.microsoft.com/en-us/cli/azure/)<br>Azure PowerShell [📄](https://docs.microsoft.com/en-us/powershell/azure/)               | AWS CLI [🏠](https://aws.amazon.com/cli/) [📄](https://awscli.amazonaws.com/v2/documentation/api/latest/reference/index.html) [💾](https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html)<br>AWS Tools for PowerShell | [gcloud][gcloud] [📄](https://cloud.google.com/sdk/gcloud/reference) [💾](https://cloud.google.com/sdk/docs/quickstart)<br>[gsutil][gsutil] [📄](https://cloud.google.com/storage/docs/gsutil)<br>[cbt][cbt] [📄](https://cloud.google.com/bigtable/docs/cbt-overview) |
| **Compute**        |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| IaaS               | [Azure VMs](#azure-vms) [🏠](https://azure.microsoft.com/en-us/services/virtual-machines/)                                                            | [EC2][EC2] [🏠](https://aws.amazon.com/ec2)                                                                                                                                                                                          | Compute Engine [🏠](https://cloud.google.com/compute)                                                                                                                                                                                                               |
| PaaS               | [App Service][App Service]  [🏠](https://azure.microsoft.com/en-us/services/app-service/)                                                             | [Elastic Beanstalk][Elastic Beanstalk] [🏠](https://aws.amazon.com/elasticbeanstalk/) [📄](https://docs.aws.amazon.com/elastic-beanstalk/index.html)                                                                                  | [App Engine][App Engine] [🏠](https://cloud.google.com/appengine)                                                                                                                                                                                                   |
| Containers         | [ACI][ACI] [🏠](https://azure.microsoft.com/en-us/services/container-instances/) [📄](https://docs.microsoft.com/en-us/azure/container-instances/)     | [ECS][ECS] [🏠](https://aws.amazon.com/ecs) [📄](https://aws.amazon.com/ecs/resources/)                                                                                                                                               |                                                                                                                                                                                                                                                                    |
| Kubernetes         | [AKS][AKS] [🏠](https://azure.microsoft.com/en-us/services/kubernetes-service/) [📄](https://docs.microsoft.com/en-us/azure/aks/)                      | [EKS][EKS] [🏠](https://aws.amazon.com/eks) [📄](https://docs.aws.amazon.com/eks)                                                                                                                                                     | [GKE][GKE] [🏠](https://cloud.google.com/kubernetes-engine)                                                                                                                                                                                                         |
| Serverless         | [Functions][Azure Functions] [🏠](https://azure.microsoft.com/en-us/services/functions/) [📄](https://docs.microsoft.com/en-us/azure/azure-functions/) |                                                                                                                                                                                                                                     | [Cloud Functions][Cloud Functions] [🏠](https://cloud.google.com/functions)<br>[Cloud Run][Cloud Run] [🏠](https://cloud.google.com/run)                                                                                                                             |
| 💾 **Storage**      | Storage accounts                                                                                                                                     | [S3][S3]                                                                                                                                                                                                                            | [Cloud Storage][Cloud Storage] [🏠](https://cloud.google.com/storage)                                                                                                                                                                                               |
| Archive            |                                                                                                                                                      | [Glacier][Glacier]                                                                                                                                                                                                                  |                                                                                                                                                                                                                                                                    |
| Backups            |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| Physical media     |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| **Network**        |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| [DNS](#dns)        | [Azure DNS](#azure-dns) [🏠](https://azure.microsoft.com/en-us/services/dns/) [📄](https://docs.microsoft.com/en-us/azure/dns/)                        | [Route 53](#route-53)   [🏠](https://aws.amazon.com/route53/) [📄](https://docs.aws.amazon.com/route53/?id=docs_gateway)                                                                                                              | Cloud DNS [🏠](https://cloud.google.com/dns) [📄](https://cloud.google.com/)                                                                                                                                                                                         |
| **Development**    |                                                                                                                                                      |                                                                                                                                                                                                                                     |                                                                                                                                                                                                                                                                    |
| [NoSQL](#nosql)    | [CosmosDB](#cosmosdb)                                                                                                                                | [DynamoDB](#dynamodb)                                                                                                                                                                                                               | [Firestore][Firestore]<br>[BigTable][BigTable]<br>[Spanner][Spanner]                                                                                                                                                                                               |
| Private git repo   | Azure Devops                                                                                                                                         | [CodeCommit][CodeCommit]                                                                                                                                                                                                            |                                                                                                                                                                                                                                                                    |
| Build              | GitHub Actions                                                                                                                                       | [CodeBuild][CodeBuild]                                                                                                                                                                                                              |                                                                                                                                                                                                                                                                    |
| CI/CD              | Azure Devops                                                                                                                                         | [CodeCommit][CodeCommit]<br>[CodeDeploy][CodeDeploy]<br>[CodePipeline][CodePipeline]                                                                                                                                                |                                                                                                                                                                                                                                                                    |
| **Big Data**       | Data Lake Analytics<br>Data Lake Store                                                                                                               | [Redshift][Redshift]<br>[Athena][Athena] [🏠](https://aws.amazon.com/athena)                                                                                                                                                         | [BigQuery][Bigquery]<br>[Dataprep][Dataprep]                                                                                                                                                                                                                       |
| Streaming data     | Event Hubs<br>Service Bus<br>Stream Analytics                                                                                                        | Kinesis<br>[Athena][Athena]                                                                                                                                                                                                         | DataFlow<br>Pub/Sub                                                                                                                                                                                                                                                |
| Batch processing   | HDInsight<br>Batch                                                                                                                                   | Elastic MapReduce<br>Batch                                                                                                                                                                                                          | Dataflow<br>Dataproc                                                                                                                                                                                                                                               |



## 🛠&#xfe0f; Administration




- GCP
    - [CLI for GCP](https://www.youtube.com/watch?v=D0x6B-4oUNM 'YouTube - Getting started: CLI for GCP')


### 💰 Cost management

Azure **quotas** apply to subscriptions and are implemented with [tags](#tags).

- **Resource quotas** trigger [alarms](#alarms) when resource creation and consumption hit a threshold. These are not to be confused with **resource limits** which can stop resources from being created, whereas quotas can not.
- **Spending quotas** trigger alarms when spending has reached a threshold.

Azure **budgets** can be viewed and administered in the **Cost Management + Billing** blade. 
Users must have at least the [**Reader**](RBAC#roles) role at the subscription scope to view, and Contributor to create and manage, budgets. 



### 🔒 Locks

Azure **resource locks** are used to apply restrictions across **all users and roles** and can be applied at subscription, resource group, or resource scopes. 

- **CanNotDelete**
- **ReadOnly** effectively restricts all authorized users to the permissions granted by the [**Reader**](RBAC#roles) role
    - Storage account keys of a locked storage account cannot be listed because the list keys operation is handled through a POST request
    - Visual Studio Server Explorer will not be able to display files for a locked App Service resource, because that interaction requires write access
    - VMs in a locked resource group will not be able to be started or restarted, because those operations require a POST request

All child resources of the scope at which a lock is applied inherit the lock. A CanNotDelete lock applied to a DNS A record would also prevent the deletion of the DNS zone that the record resides in, as well as the resource group the zone resides in.

Of the [builtin roles](Azure-IAM#roles), only two have access to the `Microsoft.Authorization/*` or `Microsoft.Authorization/locks/*` actions required to create or delete locks:

- Owner
- User Access Administrator

Resource locks apply to the management plane of Azure, specifically operations sent to https://management.azure.com

Managed applications create two resource groups to implement locks:

- One resource group to contain an overview of the service, which isn't locked
- Another resource group containing the infrastructure for the service, which is locked


Sources:

- 📄 [Move resources to a new resource group or subscription](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/move-resource-group-and-subscription)
- Some services have limitations or requirements when moving resources between groups ([src](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/move-support-resources "Move operation support for resources"))
- Source and destination subscriptions must be within the same [AAD][Azure AD] tenant
- Destination subscription must be registered for the resource provider of the resource being moved
- Account moving the resources must have at least the following permissions:
    - Microsoft.Resources/subscriptions/resourceGroups/moveResources/action
    - Microsoft.Resources/subscriptions/resourceGroups/write


### IAM


**Roles** are collections of permissions

- **Primitive roles** are basic privileges that can be applied to most resources and include Owner, Editor, and Viewer
- **Predefined roles** are specific to GCP products. For example, App Engine roles include:

Resources

- [Group membership and hierarchy](https://www.youtube.com/watch?v=b33-gN0lidA&t=77s 'YouTube - Group membership and hierarchy')

### Infrastructure

All cloud providers divide their global services into a hierarchy of geographically defined **regions**, each of which is in turn divided into **availability zones** (what AWS calls its Global Infrastructure).

Azure datacenters contain multiple availability zones, and every Azure region has at least **three** availability zones.

Azure services are also divided into **geographies**, generally coterminous with countries.
Azure geographies are further divided into **regional pairs**. Each regional pair receives rolling updates one member at a time.

Most services are regionally based, meaning the underlying hardware of that service's instance will exist in only a single Region.
Some regions, like **AWS GovCloud**, have restricted access.

Some AWS resources, however, are technically running on hardware that exists in a single Region, but presented as global. 

Resources

- [Services available on Free Tier](https://aws.amazon.com/free/?all-free-tier.sort-by=item.additionalFields.SortRank&all-free-tier.sort-order=asc)


### 👁&#xfe0f; Monitoring

- Azure
    - [Azure Monitor](#monitor)
    - [Network Performance Monitor](#npm)
    - [Network Watcher](#network-watcher)
- AWS
    - [Cloudwatch][CloudWatch]
- GCP    
    - [Stackdriver][Stackdriver]
    - [Trace][Trace]


### Resources

Cloud providers exhibit some variety in how resources can be organized.

Any Azure resource can only exist in a single **resource group**, which can contain resources from any region or subscription.
However, resource groups may not contain other resource groups.
AWS does not appear to have an equivalent method of organizing resources.

GCP **projects** are equivalent to Azure resource groups, in that they are containers for and direct parents to resources.
However, projects can be placed within **folders**, which do support nested hierarchies.

Azure **subscriptions** can be organized into **Management Groups**, and they **can** be nested in a hierarchy of management groups up to a maximum depth of six levels.
In AWS the **Organizational Unit (OU)**, which can organize **user accounts** (subscriptions) and the resources they contain in a nested hierarchy, appears to be equivalent.

A pattern common to Azure is that of a service being implemented in two resource types, one of which determines important configuration settings shared by all instances of the service which are contained within it.
This is the case for [storage accounts](#storage-accounts), [App Service][App Service], Azure Data Explorer clusters, etc.

| [Azure](https://docs.microsoft.com/en-us/azure/cloud-adoption-framework/ready/azure-setup-guide/organize-resources?tabs=AzureManagementGroupsAndHierarchy) | [AWS](https://docs.aws.amazon.com/organizations/latest/userguide/orgs_getting-started_concepts.html) | GCP          | Description                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- | ------------ | ----------------------------------------------------------------------------- |
| Tenant                                                                                                                                                     | Organization                                                                                         | Organization | Corresponds to a company or organization                                      |
| &nbsp;                                                                                                                                                     | Root                                                                                                 | &nbsp;       | Parent container for all accounts in an Organization                          |
| Management group                                                                                                                                           | Organizational Unit                                                                                  | &nbsp;       | Logical container for user accounts and the resources created by that user    |
| Subscription                                                                                                                                               | User account                                                                                         | ?            | ...                                                                           |
| &nbsp;                                                                                                                                                     | &nbsp;                                                                                               | Folder       | Organize resources and their parents in a nested hierarchy                    |
| Resource group                                                                                                                                             | &nbsp;                                                                                               | Project      | Logical container that is the direct parent to any resource, tied to a Region |
| Tag                                                                                                                                                        | Tag                                                                                                  | Label        | Key-value pairs that are used to organize resources                           | s |



The **resource hierarchy** organizes GCP resources in 3 levels below Domain

- **Domain**
    - **Organization** corresponds to a company or organization. A single **cloud identity** is associated with a single organization and can have **super admins**

**Billing Account** tracks charges and billing account admins can set budgets.

**Payments Profile** is a Google-level resource that is used to pay for all Google services.


### 🛠&#xfe0f; Support

AWS offers various support plan tiers that provide 24/7 email, chat, and phone access to AWS cloud support engineers.

- Basic Support Plan
- Developer Support Plan (greater of $29 or 3% of monthly account usage)
- Business Support Plan
- Enterprise Support Plan (>$15,000/mo.) offers a **Technical Account Manager (TAM)**, a dedicated guide and advocate

AWS documentation is available in several places:

- [AWS documentation](https://docs.aws.amazon.com)
- [AWS Knowledge Center](https://aws.amazon.com/premiumsupport/knowledge-center) is a sprawling FAQ
- [AWS security resources](https://aws.amazon.com/security/security-resources)
- [AWS forums](https://forums.aws.amazon.com)
- Professional Services team makes white papers and webinars publicly available

### Tags

Azure tags:

- Tag **names** have a limit of 512 characters (128 characters for storage accounts) 
- Tag **values** have a limit of 256 characters. 
- Resources and resource groups are limited to **15** tags. 
- VMs cannot exceed 2048 characters for all tag names and values combined. 

### Infrastructure as Code

All cloud providers support ways of provisioning resources declaratively. 
Azure [ARM][ARM] templates are JSON, but [Bicep][Bicep] is a domain-specific language and command-line utility that can be used to generate templates from simpler, YAML-like syntax.

## 🖥&#xfe0f; Compute

### IaaS

AWS also offers configuration management services like [OpsWorks][OpsWorks] and [Systems Manager][Systems Manager]

### Containers

- ▶ [Build and package container artifacts](https://www.youtube.com/watch?v=ysjCt3tNyV0 'YouTube - Getting started: Build and package container artifacts')
- ▶ [Private container registry](https://www.youtube.com/watch?v=s46l_PmXBAQ 'YouTube - Getting started: Private container registry/storage')

### Serverless

- AWS
    - [Lambda][Lambda]
- GCP
    - 

## 💾 Storage

### Archive

### Backups

[**Azure Backup**](#azure-backup) are integrated into Portal and clickable from the VM blade. 
You have to specify a **Recovery Services vault** and a **Backup policy**. 
The policy can specify frequency of backups, and other settings. Using Backup service costs $10 per VM plus the cost of used storage.

2 methods to restore data after backing up a VM to Azure Backup:

1. Restore a recovery point as a new VM
2. Restore access to files only

### Physical media

- Azure
    - [Import/Export Service](#importexport-service)
    - [Data Box](#data-box)
- AWS
    - [Snowball](#snowball)
- GCP
    - GCS Transfer appliance
    
    ▶ [Uploading files to GCS](https://youtu.be/nmZxfuFIP08 "YouTube - Uploading files to GCS (Cloud Storage Bytes)")

## 🏢 Networking

In Azure, a **Virtual Network (VNet)** consists of one or more IP ranges and exists within a single subscription and region.

Every VNet must have at least one subnet with an IP range that is a subset of that of the parent VNet.
The smallest possible CIDR range is 29, providing 3 addresses for use.
Azure reserves 5 IP addresses from each subnet IP range:
- The first and last IP addresses in each subnet are reserved for network identification and broadcast. 
- An additional three addresses at the start (bottom) of the range are reserved. 

For example, the first available IP address in range `192.168.1.0/24` is `192.168.1.4`.

Subnet names are immutable and must be unique within each VNet.
Subnets span Availability Zones and can only be deleted if empty.

**VNet peering** allows VMs in two separate virtual networks to communicate directly using their private IP addresses. It is not required for the peered networks to be in the same region (**Global VNet peering**), subscription, or tenant.
But cross-tenant peering is only possible via Azure CLI, PowerShell, or ARM templates, **not** the Portal.

> VNet peering has to be disabled before moving a VNet, and a VNet can **only** be moved within the same subscription.

- No gateways are required for peering, although each peering is one-way and not transitive (i.e. VNet A can be peered to both VNets B and C, allowing traffic to/from both. But without a peering directly between B and C they will not be able to communicate to each other.)
- There is a maximum of 100 peering connections per VNet
- Peerings cannot be moved to another resource group or subscription, so they must be disabled before moving peered VNets.

Before the introduction of peering, virtual networks were connected using S2S VPN or by connecting to the same ExpressRoute circuit.

**Service endpoints** facilitate restricting traffic from Azure services. 
**Service endpoint policies** allow restricting traffic to the granularity of individual Azure service instances.

**Virtual private cloud (VPC)** is a virtual network that is logically isolated from other VPCs.
Default VPCs have the range 172.31.0.0/16, but any value between 16 and 28 can be chosen for the size of the range.

A VPC is defined by a range of IP addresses and must have at least one subnet.
A subnet exists only within a single Availability Zone, and its range must be a subset of that of the parent VPC.

An **internet gateway** is a VPC resource that allows EC2 instances to obtain a public IP address and access the Internet.
In order to access the Internet, instances must be in a **public subnet**, one that contains a default route to the VPC's internet gateway.

**Security groups** are similar to firewall rules that regulate inbound and outbound traffic of an instance.
Outbound traffic is unrestricted by default, and every VPC contains a default security group.

A **network access control lists (NACLs)**, also like a firewall, contains inbound and outbound rules but operates on the subnet.
By default, a NACL allows all inbound and outbound traffic.

VPCs can be connected by means of a VPC **peering connection**.
VPCs can be peered across regions.

**ExpressRoute** is the main service used to connect Azure to on-premises networks, although P2S and S2S VPNs are also options.
**Direct Connect** provides dedicated network connectivity to an AWS VPC through links offered through [APN](#apn) partners.

### User-defined routes

In Azure, a **virtual appliance** refers to a VM running a network application like a load-balancer, firewall, or router. 
**Service chaining** refers to the process of deploying a network virtual appliance (NVA) into a hub network to route traffic between spokes using [**user-defined routes (UDR)**](#create-user-defined-routes). 
This is a method of reducing the complexity of pairing between individual spoke networks in complex hub-and-spoke architectures. <sup>AZ-103: 309</sup>

- In such a deployment, the peerings must be set to **Allow Forwarded Traffic**.

Alternatively, two peered networks can share a single virtual network gateway, say to connect to an external network.

- The pairing connection **to** the network that contains the gateway must be set to **Use Remote Gateways**
- The pairing connection **from** the network containing the gateway must be set to **Allow Gateway Transit**


### Network security

Azure **Network Security Groups (NSGs)** are assocated with **network interfaces** and contain an arbitrary number of **security rules**.
Each rule has the following properties:

- **Name**
- **Priority**: number between 100 and 4096, lower numbers indicate a higher priority
- **Source or destination**: IP address, CIDR block, service tag, or application security group
- **Protocol**: `TCP`, `UDP`, `ICMP`, or `Any`
- **Direction**: Inbound or outbound
- **Port range**; 
- **Action**: allow or deny

**Service tags** represent a group of IP address prefixes managed by Microsoft available for use in NSG rules:

- **`VirtualNetwork`**: all CIDR ranges defined for the virtual network, all connected on-premises address spaces, peered VNets or VNets connected to a VNET gateway
- **`AzureLoadBalancer`**: Virtual IP address of the host where Azure's health probes originate
- **`Internet`**: IP address space that is outside the virtual network
- **`AzureCloud*`**: IP address space for Azure, including all datacenter public IP addresses
- **`AzureTrafficManager*`**: IP address space for the Azure Traffic Manager probe IP addresses
- **`Storage`**:

NSG **flow logging** ,which saves the 5-tuple of all packets, is available as a low-cost way to monitor traffic. Flow logs record all IP flows going in and out of an NSG and are collected per NSG rule. They are charged per GB of logs collected and include a free tier of 5 GB/month.

### DNS


### CDN

Users can use Azure CDN as a cache, reducing load from website. 
Content is cached by the CDN until its **time-to-live (TTL)** elapses, which can be controlled in the HTTP response from the origin server.

Permanently removing content from the CDN requires it be first removed from the origin servers, meaning if the content is in a storage account it should be set to private or deleted from the storage, or the container itself should be deleted. 
Cached copies may remain in the CDN endpoint until the TTL has expired, unless it is **purged**.

There are 4 pricing tiers available within Azure CDN:

- **Azure CDN Standard from Microsoft** does not offer **dynamic site acceleration (DSA)** (cf. Azure Front Door Service)
- **Azure CDN Standard from Akamai**
- **Azure CDN Standard from Verizon**
- **Azure CDN Premium from Verizon**, for which caching is configured using a rules engine.

- AWS
    - CloudFront
- GCP
    - CDN

### Load-balancing

- Azure
    - Load Balancer
    - Application Gateway
- AWS
    - Elastic Load Balancer
- GCP
    - Load balancing


## 👨‍💻 Development

### NoSQL

NoSQL databases differ from **relational databases** in that they do not obey the principle of data **normalization**.
That is, the same data can be stored in more than one place.

This is an advantage for databases that are optimized for reads as opposed to writes, because fewer queries are needed to retrieve information.
However, when changing information that is duplicated in several places, write operations will be more laborious and prone to error.
NoSQL databases are also **horizontally scalable** because the information can be sharded horizontally more easily than relational database, which are only **vertically scalable** (meaning scaling them requires larger and larger computers) and can only be sharded vertically. ([src](https://youtu.be/v_hR4K4auoQ?t=620 "YouTube - What is a NoSQL Database? How is Cloud Firestore structured? | Get to Know Cloud Firestore #1"))

## Big Data

## 📘 Glossary

#### APN

Amazon Partner Network

#### App Engine

App Engine allows developers to deploy applications developed in popular programming languages to a serverless environment.
It is available in two environment types:

- **Standard** where the application is run in a sandbox and isolated from the underlying server's OS.
- **Flexible** where Docker containers are run in the environment, useful when third-party software or libraries are needed.

Resources

- ▶ [App Engine in a minute](https://youtu.be/Xuf3J6SKVV0 "YouTube - App Engine in a minute")
- ▶ [Get to know GAE](https://youtu.be/2PRciDpqpko "YouTube - Get to know Google App Engine") 
- ▶ [Introduction App Engine's new Python 3 runtime](https://youtu.be/qeSpDwA2qcU)

#### App Service

![](/img/az-app-service.png)

An **App Service plan** resource determines the billable compute resources available for the App Services applications managed by it.
A plan acts as a container for multiple web applications sharing the same server farm ("workers"), and for this reason Windows and Linux apps can't be mixed in the same App Service plan.
"Web app" is the legacy name for Azure **App Service**.

> App Service SSL certificates need to be deleted from each App Service before moving it to a new resource group.

Resources

- 💰 [Pricing](https://azure.microsoft.com/en-us/pricing/details/app-service/windows/)
- 📄 [Tutorial: build and run a custom image in Azure App Service](https://docs.microsoft.com/en-us/azure/app-service/tutorial-custom-container?pivots=container-linux)
- 📄 [Create an App Service app with deployment from GitHub using Azure CLI](https://docs.microsoft.com/en-us/azure/app-service/scripts/cli-deploy-github?toc=/cli/azure/toc.json)
- 📄 [Create a web app with continuous deployment from GitHub](https://docs.microsoft.com/en-us/azure/app-service/scripts/powershell-continuous-deployment-github?toc=/powershell/module/toc.json)
- 📄 [What is Azure Front Door?](https://docs.microsoft.com/en-us/azure/frontdoor/front-door-overview)
- 📄 Create a Front Door - [PowerShell](https://docs.microsoft.com/en-us/azure/frontdoor/quickstart-create-front-door-powershell)

#### Application Gateway

**Azure Application Gateway** is used to load balance a large-scale set using more than 100 instances in place of [**Azure Load Balancer**](Azure-Load-Balancer). <sup>AZ-103: p. 223</sup>

Application Gateway supports **session affinity** to save user state using browser cookies.

Unlike Azure Load Balancer, which operates at OSI layer 4 and has limited security capabilities, Application Gateway operates at OSI layer 7 and provides Web Application Firewall (WAF) functioanlity to block attacks like SQL injection, cross-site scripting, and header injection. HTTPS is also only available with layer 7 load balancers like Application Gateway.

#### Athena

**Athena** is a serverless AWS service that allows SQL queries to be run against data stored in a [S3][S3] bucket.
Athena works closely with [AWS Glue][AWS Glue] to extract schema information and crawl data sources.
Before running for the first time, you must provide a path to a S3 bucket to store query results.

Sources:

- ▶ [How to use SQL to query S3 files with AWS Athena](https://youtu.be/M5ptG0YaqAs)

#### AWS CLI

AWS CLI is version 1 is maintained for legacy compatibility purposes.

#### AWS Developer Tools

A collection of tools that provide CI services:

- [CodeCommit][CodeCommit]
- [CodeBuild][CodeBuild]
- [CodeDeploy][CodeDeploy]
- [CodePipeline][CodePipeline]

#### AWS Glue



#### AzCopy

**AzCopy** can be used to copy files to File storage.

#### Azure Bastion

**Azure Bastion** is a PaaS service deployed within a VNet that allows connectivity to a VM from the Portal. Once deployed in a VNet, RDP/SSH is available to all VMs in that VNet. This session is streamed to your local device over an HTMLS session using the browser.
- It is not deployed per VM, but once per VNet to its **own dedicated subnet**, at least /27 or larger
- No public IP is necessary on the VM, the connection from Bastion to the VM is to the private IP. However, the Bastion itself does require a public IP.
- Bastion can now span peered VNets

IPv6 support is limited in Azure. 
IPv6 addresses are not added to VMs by default and  must be explicitly defined by adding an endpoint to each VM to be using it. 
Routing by IPv6 is also not supported, so load balancers have to be deployed.

Sources

- ▶ [Azure Virtual Network Overview](https://youtu.be/7rzawA--r20)
- 📄 [Azure Bastion](https://docs.microsoft.com/en-us/azure/bastion/bastion-overview)
- 📄 [Introduction to flow logging for NSGs](https://docs.microsoft.com/en-us/azure/network-watcher/network-watcher-nsg-flow-logging-overview)

#### Bicep

[**Project Bicep**](https://github.com/Azure/bicep) is a domain-specific language and command-line utility that can be used to generate [ARM][ARM] templates.

▶ [Project Bicep – Next generation ARM Templates](https://youtu.be/wkQIyenVfxc)

#### Azure Container Instances

**Azure Container Instances (ACI)** allows a simpler way of running isolated containers in smaller-scale deployments than [Azure Kubernetes Service][AKS].

The top-level resource in ACI is the **container group**, a collection of containers that get scheduled on the same host machine. 
These containers share a lifecycle, resources, local network, and storage volumes, and is equivalent to a Kubernetes pod. 
Container groups can be deployed to a subnet that already hosts a container group or an empty one, but it may not be deployed to a subnet that already has other resources like VMs.

Resources

- 📄 [What is Azure Container Instances?](https://docs.microsoft.com/en-us/azure/container-instances/container-instances-overview)
- 📄 [Container groups in ACI](https://docs.microsoft.com/en-us/azure/container-instances/container-instances-container-groups)

#### Azure Data Explorer

#### Azure DevOps

Azure DevOps used to be known as **Visual Studio Team Services** and **Team Foundation Server**.

Sources

- ▶ [DevOps Training Workshop](https://www.youtube.com/watch?v=H-R2bCXfz8I "Intro to Azure DevOps - Source Control, CI/CD, Automation, and more") [YouTube](https://youtu.be/Ruj_govRRa8 "DevOps Training Workshop")

Install DevOps CLI
```sh
az extension add --name azure-devops
```

#### Azure DNS

**Azure DNS** supports private zones, which provide name resolution for VMs on a VNet and between VNets without having to create a custom DNS solution.

Time-to-live for DNS record sets is provided in seconds.


Azure DNS **alias records** allow other Azure resources to be referenced from the DNS zone, rather than static IP addresses or domain names. 
This allows these records to be automatically updated or deleted when the underlying Azure resource is changed.

- An **A alias record set** is a special type of record set that allows you to create an alternative name for a record set in your domain zone or for resources in your subscription.
- A **CNAME alias record set** can only point to another CNAME record set. Custom domains can be used by implementing **CNAME** DNS records, which are used in DNS to map alias domain names to the "canonical" name.

Sources

- 📄 [Azure DNS alias records overview](https://docs.microsoft.com/en-us/azure/dns/dns-alias)

#### Azure File Service

**Azure File Service** allows you to create one or more file shares in the cloud (up to 5 TB per share), similar to a regular Windows File Server. 
It supports the SMB protocol, so you can connect directly to a file share from outside of Azure, if traffic to port 445 is allowed through the LAN and ISP. It can also be mapped within Windows.

A clever use of a file share is as persistent storage for the Azure Cloud Shell. [src](https://portal.cloudskills.io/products/azure-administrator-az-104-exam-prep-course/categories/2692678/posts/8980122 "Configure Azure Files and Azure Blob Storage 32:00")

#### Azure File Sync

**Azure File Sync** extends Azure File Service to allow on-premises file services to be extended to Azure while maintaining performance and compatibility, communicating over TCP 443 over SSL, and **not** IPSec. 

Use cases include:

- Replace on-premises file servers
- Easily replicate data on-premises to make it available during lift-and-shift migrations
- Simply cloud development and management

Azure File Sync works using an **Azure File Sync agent**, available as an [MSI package](https://www.microsoft.com/en-us/download/details.aspx?id=57159) for Windows Server 2012R2, 2016, and 2019, to **register** file servers as endpoints to an **Azure File Sync Group**. 
After installation, Azure credentials for a subscription must be provided. <sup>AZ-103: 153</sup>

In order to create an Azure File Sync, first a **Storage Sync Service** resource must be created, which works like a container to hold one or more **sync groups**. 
Every sync group has only a single **cloud endpoint**, referring to a storage account, but can have more than one **server endpoint**. 
Any server can only be registered to a single Storage Sync Service, and servers synced to different Storage Sync Service resources cannot sync with each other.

**Cloud tiering** is an optional feature in Azure File Sync in which frequently accessed files are cached in the on-prem file servers, while less commonly accessed files are **tiered** to Azure Files. This is done by enabling Cloud Tiering, then selecting a **free space policy**, a percentage which indicates the amount of free space to maintain on the server endpoint's volume. When a user does access one of these tiered files, that file is downloaded to the on-prem cache and made available locally from that point on. This frees up local storage.

- Cloud tiering **cannot** be used with server endpoints on the system volume
- Although server endpoints can be configured with different free space policies, the most restrictive setting takes effect
- For tiered files, the file will be partially downloaded as needed
- Although a mount point can be a server endpoint, there can be no mount points **inside** a server endpoint

When a filename collision occurs between the file share and file server, the file on the server has its filename appended with the server's name.

#### Azure Policy

**Azure Policy** is a service that can create, assign, and manage policies to enforce governance. Policy definitions, authored in JSON, implement policy by describing desired behavior for Azure resources when they are created or updated. <sup>AZ-103: p. 72</sup>

To implement policy, a **policy definition** is created first, then a **policy assignment** assigns it to a scope. Policy definitions can be packaged together using **initiative definitions** and applied to a scope using **initiative assignments**

[RBAC roles](RBAC#roles) **deny by default and allow explicitly**. But Azure Policy **allows by default and denies explicitly**

Policies can be applied at the **management group**, **subscription**, or **resource group** scope, with all child resources and resource groups being affected.

Every policy definition has a single **effect**, which includes:

- **Audit**: create a warning event in the log
- **Modify**: used to add, update, or remove properties or tags on a resource during creation or update.
- Append
- AuditIfNotExists
- Deny
- DeployIfNotExists
- Disabled

The order of evaluation of effects is: Disabled, Append, Deny, Audit ("DADA")

Sources

- 📄 [What is Azure Policy?](https://docs.microsoft.com/en-us/azure/governance/policy/overview)
- 📄 [Azure Policy Samples](https://github.com/Azure/azure-policy)
- 📄 [Understand Azure Policy effects](https://docs.microsoft.com/en-us/azure/governance/policy/concepts/effects)

#### Azure VMs

**Virtual Machines** represent Azure's IaaS offering.

A **dedicated host group** has to be [created](#dedicated-host) and placed in a resource group and associated with a location and availability zone and assigned a fault domain. A host then has to be created, a size specified, and associated with a host group. Any VM intended to run on the host has to be created in the same location and availability zone and associated with the host in the **Advanced** tab.

Azure **spot instances** are available at deep discounts.

3 types of disk are available to Azure VMs:

- Operating System Disk (OS Disk)
- Temporary Disk
- Data Disk

Azure VM image types include:

- **Managed** images (recommended), which remove the dependency of the VM to the image, at least within the same region. 
Copying a VM to another region still requires the managed image to be copied first.
- **Unmanaged** images, which required the VM to be created in the same storage account as that of the image. 
VM copies required the image to be copies first.

VM images are captured from an existing VM that has been **generalized** (prepared), removing unique settings (hostname, security IDs, personal information, user accounts, domain join information, etc) but not customizations (software installations, patches, additional files, folders), using `sysprep.exe` for Windows machines or Microsoft Azure Linux Agent (`waagent`) for Linux machines.

VM images in AWS are called **Amazon Machine Images (AMI)**.

#### Azure VPN

**Virtual network gateways** in Azure are of two types: **VPN gateways** and **ExpressRoute gateways**.
Any virtual network can have only a single gateway of each type.

**VPN gateways** send encrypted traffic between the virtual network and an on-premises location. VPN Gateways must be deployed into their own dedicated subnet (named **"GatewaySubnet"**) with a minimum size of CIDR /29, although a CIDR /27 address block is recommended. VPN connections between an on-premises network and a VNet are only possible if the network ranges do not overlap.

VPN gateways can be classified by the topology of the connection:

- [**Site-to-Site (S2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#S2S) connections require an on-premises **VPN device** associated with a public IP address.
- [**Multi-Site**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#Multi) connections require a **RouteBased** VPN type. 
- [**Point-to-Site (P2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#P2S) allows individual computers to securely connect to a VNet without need for a VPN device, which is useful for telecommuting, and can use SSTP, OpenVPN, or IKEv2. There are several [authentication](#authentication) considerations.
- [**VNet-to-VNet**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#V2V) connections are also possible, but VNet [peering](VNet#peering) may be preferable if the virtual networks meet certain requirements.

=== "Site-to-Site"


    ![](/img/vpngateway-site-to-site-connection-diagram.png)



=== "Multi-Site"

    ![](/img/vpngateway-multisite-connection-diagram.png)


=== "Point-to-Site"


    ![](/img/point-to-site.png)


=== "VNet-to-VNet"


    ![](/img/vpngateway-vnet-to-vnet-connection-diagram.png)



VPN gateways can also be classified on [VPN type](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#vpntype). 

- **Route-based VPNs** (previously called "dynamic routing gateways") require routes to be defined in a routing table to direct packets into tunnel interfaces.
- **Policy-based VPNs** (previously called "static routing gateways" in the classic deployment model) can only be used on the Basic gateway SKU and offer only a single S2S tunnel.

=== "Route-based"


    ![](/img/routebasedmultisite.png)


=== "Policy-based"


    ![](/img/policybasedmultisite.png)


There is a profusion of [Gateway SKUs](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#gwsku) that determine the maximum connections, throughput, and availability of other features like BGP and zone-redundancy available for each topology.


Every Azure VPN gateway consists of two instances in an active-standby configuration. During failover, a brief interruption of 10-15 seconds for planned maintenance or up to 60-90 seconds in the case of unplanned disruption, may occur.
But the gateway can be configured to be **active-active**, which will establish S2S VPN tunnels to both gateway instances with traffic being routed through both tunnels simultaneously. There will still be only a single connection resource, but the on-premises VPN device must be configured to establish both of these tunnels.
The most highly available arrangement would use multiple VPN devices with the VPN gateway in active-active configuration, creating 4 IPsec tunnels that evenly carry Azure traffic. 

=== "Active-Standby"

    ![](/img/active-standby.png)

=== "Active-Active"

    ![](/img/active-active.png)

=== "Dual redundancy"

    ![](/img/dual-redundancy.png)

#### Bigquery

Petabyte-scale analytics database service for data warehousing

#### BigTable

**Cloud BigTable** is a GCP realtime database used for Big Data.

BigTable evolved out of Google's need to ensure access to petabytes of data in its web search business line.
It was described in a 2006 research paper that ended up launching the entire NoSQL industry.
In 2015 it was made available as a service to cloud customers. <sup>[YouTube](https://www.youtube.com/watch?v=1qieV-WCU_w "YouTube - Introduction to Google BigTable: Best Uses, Design, and Demo")</sup>

BigTable doesn't support secondary indexes. 

[cbt][cbt] is BigTable's CLI utility.

Resources

- 📄 [The Right Bigtable Index Makes All the Difference](https://www.youtube.com/watch?v=oxC_iTLGtLA "YouTube - The Right Bigtable Index Makes All the Difference") 
- ▶ [The Right Bigtable Index Makes All the Difference](https://medium.com/@duhroach/the-right-cloud-bigtable-index-makes-all-the-difference-3bcabe9bd65a "The right Cloud Bigtable index makes all the difference")
- [Bigtable vs. Firestore](https://db-engines.com/en/system/Google+Cloud+Bigtable%3BGoogle+Cloud+Firestore "System Properties Comparison Google Cloud Bigtable vs. Google Cloud Firestore")</sup>


#### Cloud AutoML

**Cloud AutoML** is a GCP service that allows developers without machine learning experience to develop machine learning models.

#### Cloud Functions

Cloud Functions is GCP's serverless compute offering and is suited to running short-running logic, such as calling other APIs in response to an event.

Resources:

- [Cloud Functions in a minute](https://youtu.be/brhA9uaz7Xs "YouTube - Cloud Functions in a minute")
- [Quickstart](https://www.youtube.com/watch?v=vM-2O-uKBNQ 'YouTube - Getting Started: Cloud Functions quickstart')

#### Cloud Machine Learning Engine

Platform for building and deploying scalable machine learning systems to production.

#### Cloud Natural Language Processing

GCP tool for analyzing human languages and extracting information from text.

#### Cloud Run

**Google Cloud Run** is built on a native open standard that will allow using the same container on other cloud providers.
It bills down to the nearest 100 ms interval.
Cloud Run provides an HTTPS endpoint to the container.

Cloud Run can also run on your own K8S cluster running on [GKE][GKE], recommended for workloads that have a consistently high level of traffic, since you are billed for the provisioned cluster resources.
However, resources like CPU, GPU, and other items can be customized.

Resources:

- ▶ [Cloud Run in a minute](https://youtu.be/lzQNjZIGKaM "YouTube - Cloud Run in a minute")
- [Differences between Cloud Run and Cloud Run on GKE](https://youtu.be/RVdhyprptTQ)
- [Cloud Run: deploy a prebuilt container](https://youtu.be/Xd-BNy1IqcQ)
- [Build and deploy with Cloud Run](https://youtu.be/nJ0L28ZfmUA)


#### Cloud Vision

Image analysis platform for annotating images with metadata, extracting text, or filtering content

Sources:

- ▶ [Getting started: Image recognition and classification](https://www.youtube.com/watch?v=BN8aO0LULyw 'YouTube - Getting started: Image recognition and classification')

#### CloudFormation

**CloudFormation** is AWS's declarative automation service, which can use JSON or YAML-format templates.
These resources are placed into a named **stack**, a container that organizes the resources described by the template, and the stack name must be unique to the account.
This allows provisioned resources to be easily managed, since the stack contains a record of events, and to be quickly destroyed by deleting the stack.

CloudFormation Designer allows templates to be viewed as a diagram of resources.

#### CloudFront

Amazon **CloudFront** is a CDN that helps deliver static and dynamic content worldwide.

CloudFront caches content in **edge locations**, of which there are more than 150 spread out across 6 continents.
Edge locations may not be chosen arbitrarily, rather there are three options:

- US, Canada, and Europe
- US, Canada, Europe, Asia, and Africa
- All edge locations

In order to make content available on CloudFront, you must create a **distribution**, which defines the type and origin of the content to cache.
There are two types of distribution:

- A **Web distribution** is used for static and dynamic content, including streaming video, accessible via HTTP or HTTPS. Its origin can be a web server or a **public** S3 bucket.
- **Real-Time Messaging Protocol (RTMP) distribution** delivers streaming audio or video. The media player and media files must be stored in S3 buckets.

#### CloudWatch

**Amazon CloudWatch** collects logs, metrics, and events from AWS resources and non-AWS on-premises servers and presents a dashboard for visual analysis.
All AWS resources automatically send their metrics to CloudWatch Metrics, which stores the data for up to 15 months.
CloudWatch alarms can be configured for single metrics.

Applications and AWS services have to be configured to send log events to CloudWatch Logs, and they are stored indefinitely by default although retention settings can be configured.
Log events from the same source are organized into a log stream. Log streams are then organized into log groups.
**Metric filters** extract metric data from log events.

CloudWatch Events is a feature that monitors for changes in AWS resources as a result of API operations.


#### Cloudyn

Although the **Cloudyn** service, which had been purchased by Microsoft, was being offered as a standalone service, it has now been deprecated because its functionality has been incorporated natively into other sections of the **Cost Management + Billing** blade.

#### CodeCommit

**CodeCommit** is the AWS private git repo service.

#### CodeDeploy

**CodeDeploy** is an AWS service for automatically deploying applications to AWS compute resources or on-prem servers.
CodeDeploy can pull source code from [S3][S3] and repos from GitHub or Bitbucket but notably **not** [CodeCommit][CodeCommit] (ref. [CodePipeline][CodePipeline]).

#### CodePipeline

**CodePipeline** is an AWS service for orchestrating and automating every stage of software development.
It defines a series of stages, two of which are required - **source** and **deployment** - but other stages like testing or approval can be incorporated.

#### Cognito

Cognito is an AWS service that integrates with identity providers like Amazon, Google, Microsoft, and Facebook to add user access control to an application.

#### Compute Engine

**Compute Engine** is GCP's IaaS offering.

An **instance group** is a collection of VM instances that you can manage as a single entity. 

Two types:

- **Managed** instance groups operate applications like web front-ends across a group of identical VMs created with a template.
They provide high availability, healing, scaling, and automatic updates.
- **Unmanaged** instance groups allow you to manually load balance a group of VMs.
VMs can be added or removed at will.

- ▶ [Getting started with GCE](https://youtu.be/1XH0gLlGDdk "YouTube - Getting Started with Google Cloud Compute Engine")

#### Container Instances

**Azure Container Instances (ACI)** is a PaaS service that facilitates deployment of individual containers.

#### CosmosDB

**Cosmos DB** started as Project Florence in 2010 to address shortcomings with SQL Server in supporting highly available services like Xbox. 
In 2015 the product was relaunched as Document DB, then renamed Cosmos DB in 2017.

An emulator is available for Cosmos DB [here](aka.ms/cosmosdb-emulator). 
A Cosmos DB account can be used for free for 30 days, and does not require an Azure subscription.

Throughput is measured and billed in **Request Units (RU)** per second. The minimum manually provisioned throughput level is 400 RU/sec.

There are three throughput provisioning offers:

- **Manual**, where a static throughput level is provisioned. This is best for highly predictable workloads.
- **Autoscaling**, where Azure will automatically scale throughput based on usage, reducing it down to a minimum of 10% of the provisioned throughput.
- **Serverless**, where you pay for only the RUs you need. This throughput provisioning model is ideal for small demonstration projects. This feature is forthcoming.

The cost of using a CosmosDB database can be approximated using the [**Capacity calculator**](https://cosmos.azure.com/capacitycalculator/). 
In general, these are reasonable back-of-hand estimates for common operations to estimate costs:

- Read item: 1 RU
- SQL query: ~2.8 RU
- Create item: 10 RU

There are various choices of API for Cosmos DB accounts which affect the data model used for databases.

- **SQL API** is the Core API, and works off JSON documents and SQL query syntax
- **MongoDB API** uses BSON documents (binary encoded JSON) and MongoDB query syntax
- **Table API** and uses Key-Value database design reflects API of Azure Table Storage
- Gremlin API is a graph database using a flat store of vertices and edges
- Cassandra API is columnar, and unlike most NoSQL databases does specify a schema

**Consistency**, in a distributed NoSQL database like Cosmos DB, describes the uniformity of data across replicas. 
[**Consistency levels**](https://aka.ms/cosmos-consistency-levels "Consistency levels in Azure Cosmos DB") describe how and when data is replicated to provide varying consistency guarantees.

- **Strong consistency** is the strongest consistency model and requires synchronous replication after every change to database, increasing latency for each write.
- **Session consistency** is unique, in that it offers consistent prefix to databases that support a single session or an application with a single token. 
- **Eventual consistency** is the weakest consistency model and provides no ordering guarantees.
**Consistent prefix** offers read throughput, availability, and write latency comparable to eventual consistency while guaranteeing global order.
- **Bounded staleness** implies asynchronous replication and offers guarantees on the number of versions (**K**) or time interval (**T**) reads lag behind writes, referred to as the **staleness window**. 
As the staleness window approaches, Azure will delay writes by providing *back pressure* on writes. 
    - Outside the staleness window, data is guaranteed to be globally consistent. 
    - Outside the region in which the writes were made, Azure guarantees *total global order* or *consistent prefix*, which means, the global order is maintained.

=== "Strong"

    ![](/img/strong-consistency.gif)


=== "Session"


    ![](/img/session-consistency.gif)


=== "Eventual"

    ![](/img/eventual-consistency.gif)


=== "Bounded staleness"

    ![](/img/bounded-staleness-consistency.gif)

**Horizontal partitioning** is what allows Cosmos DB to scale-out massively to provide high availability and elasticity. 
Partitions can be thought of as physical fixed-capacity data buckets that back every container. 
A **partition split** occurs when a new physical partition is brought online, resulting in half of the documents existing on a previously existing partition being moved to the new one.
Cosmos DB automatically and transparently splits horizontal partitions to achieve elasticity.
**Logical partitions**, determined by the **partition key** which is set at container creation, group individual documents in ways that are kept on the same physical partition. 
It is recommended to have a high number of logical partitions, so that CosmosDB has greater flexibility partitioning documents.
The partition key is immutable, so the correct choice of partition key is an important architectural consideration.
Even distribution of documents is ideal to avoid **hot partitions**, where some partitions have much greater activity than others, due to uneven distribution of documents.
Any partition may not be greater than 20 GB in size.
Physical partitions have 4 replicas within a region.

There are several common partitioning patterns:

- Partitioning on `/id`, which results in every document existing in its own logical partition. This pattern is write-optimized and ideal for IoT applications. Any SQL query for more than one document would be cross-partition by necessity, so direct reads using the `/id` value would be far more economical.
- Partitioning small lookup lists on a `/type` property. This will keep lists of related items used for lookups in the same partition.
- Optimizing for queries by organizing multiple types of document according to a key data-point. For example, customer data could be kept in the same partition as that customer's orders, avoiding cross-partition queries.

Sources:

- ▶ [**Learning Azure Cosmos DB**](https://app.pluralsight.com/courses/106da442-dfd4-4109-850d-efca92baae2b/table-of-contents)

#### Data Box

**Azure Data Box** is a Microsoft-provided appliance that allows for the transfer of large volumes of data to Azure. 
These services are only available for EA, CSP, and Microsoft Partner Network Sponsorship offer types.

| Offering       | Capacity | Storage saccounts |
| -------------- | -------: | ----------------: |
| Data Box Disk  |    35 TB |                 1 |
| Data Box       |   100 TB |                10 |
| Data Box Heavy | 1,000 TB |                10 |


Workflow

1. Order: Use Portal to order a data box by creating a Data Box resource
2. Receive: Connect Data Box to network
3. Copy data: Mount file shares and copy data to the device.
4. Return: to Microsoft
5. Upload: Microsoft will upload the data and securely erase it from the device


#### Dataflow

Cloud Dataflow is a GCP streaming data framework for defining batch and stream processing pipelines.

#### Dataprep

GCP [big data](#big-data) service that allows analysts to explore and prepare data for analysis

#### Dataproc

Dataproc is a managed Hadoop and Spark service offered by GCP

#### DynamoDB

**DynamoDB** is a NoSQL database known for fast (1-9 ms) query times. 


DynamoDB measures capacity in **Read Capacity Units (RCU)** and **Write Capacity Units (WCU)**.

- 1 RCU = 1 record at most 4 KB in size
- 1 WCU = 1 record at most 1 KB in size

DynamoDB offers the choice between **strongly consistent** and **eventually consistent** (half the cost) reads. 

DynamoDB offers two types of indexes: 

- **Global Secondary Index** allows you to create a completely new aggregation of data.
GSI updates are [**eventually consistent**](https://youtu.be/HaEPXoXVf2k "AWS re:Invent 2018: Amazon DynamoDB Deep Dive: Advanced Design Patterns for DynamoDB (DAT401)"), with asynchronous updates populated after an update response is passed to the client.
- **Local Secondary Index (LSI)** alternate sort key attribute that allows only sorting

**DynamoDB Streams** (changelog for the DynamoDB table) interfaces with AWS Lambda to implement **complex queries**, computed values like sum, average, maximum, etc. 
These are implemented in a different **processing space** than the DynamoDB table itself, so that it does not affect the table.

AWS Lambda has an **invocation role** which defines what Lambda can **see** (triggered upon a change to the table as reported in DynamoDB Streams) and an **execution role** which defines what it can **do**.

#### ECS

#### EKS

#### Elastic Beanstalk

**AWS Elastic Beanstalk** is a PaaS offering.

#### Elastic File System

**Elastic File System (EFS)** is a scalable file system for AWS Linux instances. Multiple instances can be attached to a single EFS volume to share files.
EFS volumes are highly available, spanning multiple Availability Zones in a single VPC.

#### Elastic MapReduce

**Elastic MapReduce (EMR)** facilitates Big Data analysis, supporting Apache Hadoop, Apache Spark, HBase, Presto, and Flink.

#### Enterprise Agreement

Azure customers on an **Enterprise Agreement** can add up-front commitments to Azure then be billed annually. 
If the committed spend is exceeded, the overage is billed at the same EA rate. 
EA customers can create spending quotas and set notification thresholds through the EA Portal.

3 portals used to manage Azure subscriptions

1. EA Portal (ea.azure.com) available only to customers with an Enterprise Agreement
2. Account Portal
3. Azure Portal, includes Azure Cost Management

#### ExpressRoute

There are four main architectures used with ExpressRoute

- **Any-to-any connection** is used to integrate on-premises WANs using IPVPN.
- **Co-location with cloud exchange** is used to order virtual cross-connections to the Azure cloud through the co-location provider's Ethernet exchange.
- **Point-to-point Ethernet connection** is used to configure on-premises data center connectivity to Azure through individual point-to-point links

#### Firebase

Firebase is a completely unstructured NoSQL database that is known for its client libraries.
Firebase Auth offers a free user interface for applications, **Firebase UI**.


#### Firestore

**Cloud Firestore** was released from beta in early 2019 and combines and improves upon functionality of previous products named **Cloud Datastore** and **Firebase Realtime Database**. 

Firestore is organized into **documents**, which consist of key-value pairs and are similar to JSON objects, and **collections**. 
JSON-like objects are called **maps** and keys are called **fields** in Firestore. 
Collections can contain only documents, but documents can contain sub-collections. 
Root can only contain collections. So navigating deeper and deeper into the information store will involve alternating between collections and documents. 

Firestore features a compatibility mode that emulates the behavior of Datastore in accessing Firestore's storage layer while removing some of Datastore's limitations.

Queries in Firestore can only be used to find documents stored in one specific collection or sub-collection.
However a **collection group query**, meaning one that spans multiple collections, began to be supported in 2019.
Complex relational queries are not possible (in a single query), and query results are usually returned based on equality or greater-than/less-than comparisons.
The field has to be specified as having a scope of "Collection group" within GCP, and there is a limit of (about) 200 for these queries. 

An index is created for every field in every document added to a collection, which results in very fast query times that are proportional to the number of **results**, not records searched. 
This structure ensures that equality searches are highly performant, as are comparison searches using greater-than or less-than.
But this implementation creates bizarre limitations to Firestore's querying capabilities:
There is no native way to perform wildcard searches or `OR` queries. 
For common instances of such queries, Google recommends adding a field that contains the value for each record 

Inequality searches present a challenge for Firestore.
For some queries that combine conditions on more than one field (i.e. restaurants within a certain range of a location), Firebase will create a "composite index" (only within the index, the document itself is not affected) automatically to facilitate searches on those fields.

Unlike **Firebase**, which charges based on the volume of data stored, **Firestore** charges based on number of operations performed and records returned.

Sources:

- ▶ [What is a NoSQL Database?](https://youtu.be/v_hR4K4auoQ?t=620 "YouTube - What is a NoSQL Database? How is Cloud Firestore structured? | Get to Know Cloud Firestore #1")
- ▶ [Introducing Firebase Realtime database](https://youtu.be/U5aeM5dvUpA "YouTube - Introducing Firebase Realtime Database")
- ▶ [Firebase web application tutorial](https://youtu.be/9kRgVxULbag "YouTube - Firebase - Ultimate Beginner's guide")
- ▶ [Firebase Realtime DB vs Firestore](https://youtu.be/TmXct7seeBY)
- ▶ [How queries work in Firestore](https://youtu.be/Ofux_4c94FI "YouTube - How do queries work in Cloud Firestore? | Get to Know Cloud Firestore #2")
- 📄 [Cloud Firestore vs the Realtime Database: Which one do I use?](https://firebase.googleblog.com/2017/10/cloud-firestore-for-rtdb-developers.html "Cloud Firestore vs the Realtime Database: Which one do I use?")
- [Firebase blog](https://firebase.googleblog.com/2017/10/cloud-firestore-for-rtdb-developers.html "Cloud Firestore vs the Realtime Database: Which one do I use?") 


#### Front Door

**Azure Front Door** works like [Azure Load Balancer](Azure-Load-Balancer) for web apps.

Resources

- [Pricing](https://azure.microsoft.com/en-us/pricing/details/frontdoor/)

#### gcloud

[doc:gcloud-app]: https://cloud.google.com/sdk/gcloud/reference/app "gcloud app documentation"
[doc:gcloud-compute]: https://cloud.google.com/sdk/gcloud/reference/compute "gcloud compute documentation"
[doc:gcloud-container]: https://cloud.google.com/sdk/gcloud/reference/container "gcloud container documentation"
[doc:gcloud-functions]: https://cloud.google.com/sdk/gcloud/reference/functions "gcloud functions documentation"
[doc:gcloud-run]: https://cloud.google.com/sdk/gcloud/reference/run "gcloud run documentation"
[doc:gcloud-services]: https://cloud.google.com/sdk/gcloud/reference/services "gcloud services documentation"

[gcloud-app]: #app-engine '```&#10;gcloud app &#10;```&#10;App Engine'
[gcloud-compute]: #gcloud-compute '```&#10;gcloud compute &#10;```&#10;Compute Engine'
[gcloud-container]: #gcloud-container '```&#10;gcloud container &#10;```&#10;Kubernetes Engine'
[gcloud-functions]: #gcloud-functions '```&#10;gcloud functions &#10;```&#10;Cloud Functions'
[gcloud-run]: #google-cloud-run '```&#10;gcloud run &#10;```&#10;Manage Cloud Run applications'
[gcloud-services]: #gcloud-services '```&#10;gcloud services &#10;```&#10;manage project's access to APIs'

[`app`][gcloud-app]<sup>[?][doc:gcloud-app]</sup>
[`compute`][gcloud-compute]<sup>[?][doc:gcloud-compute]</sup>
[`container`][gcloud-container]<sup>[?][doc:gcloud-container]</sup>
[`functions`][gcloud-functions]<sup>[?][doc:gcloud-functions]</sup>
[`run`][gcloud-run]<sup>[?][doc:gcloud-run]</sup>
[`services`][gcloud-services]<sup>[?][doc:gcloud-services]</sup>
`source`

Google Cloud Source Control repositories
```sh
gcloud source repos clone
gcloud source repos create
```

Sources:

- [Google Command Line for beginners](https://youtu.be/j274vq9a2Rs)


#### Glacier

**S3 Glacier** offers long-term archival at low cost.
One or more files are stored in an archive, typically a .zip or .tar file containing multiple files.
Archives can range from 1 B to 40 TB in size.

Archives are stored in a Glacier **vault**, a region-specific container analogous to S3 buckets.
Vaults must have regionally unique names, but there is no need for a globally unique name.

Glacier vaults can be created and deleted using the Glacier service console.
But uploading, downloading, or deleting archives must be done through the [AWS CLI](#aws-cli) or an application using the SDK.
Some third-party applications can also interact with Glacier.

#### Import/Export Service

**Azure Import/Export service** allows the physical shipment of disks procured by the user to Azure for import. 
This data can be placed into blob or file storage.
This service requires the use of a Windows computer with BitLocker and .NET Framework and is dependent on the [WAImportExport.exe](#waimportexport) utility.

1. Procure 2.5-inch or 3.5-inch SATA (not SAS) disks
2. Connect the disks to a Windows machine.
3. Create a volume and encrypt it using BitLocker
4. Install the [**Azure Import/Export tool** (WAImportExport.exe)](#waimportexport) on the disks. 
5. Copy files
6. Create an **import job** in the Azure Portal

#### Kinesis

Kinesis is an AWS service for ingestion and processing of streaming data, such as access logs, video, audio, and telemetry.

#### Kubeflow

**Kubeflow** is a cloud-native platform for machine learning based on Google’s internal machine learning pipelines.

Resources:

- ▶ [Kubeflow 101 (playlist)](https://www.youtube.com/playlist?list=PLIivdWyY5sqLS4lN75RPDEyBgTro_YX7x 'YouTube - KubeFlow 101')
- ▶ [Talk - Kubeflow at Spotify](https://www.youtube.com/watch?v=m9XhsnNSMAI 'YouTube - Building and managing a centralized Kubeflow platform at Spotify')
- ▶ [Talk - Kubeflow on Kubernetes](https://www.youtube.com/watch?v=I6iMznIYwM8 'YouTube - Kubeflow ML on Kubernetes')

#### ⚓ Kubernetes

**Kubernetes** (Greek for "helmsman", "pilot", or "captain" and "k8s" for short) has emerged as the leading **container orchestrator** in the industry since 2018. 

Kubernetes was first announced by Google in mid-2014. 
It had been developed by Google after deciding to open-source the internally developed container management system **Borg**.
Borg is a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise.
Kubernetes coalesced from a fusion between developers working on Borg and [Compute Engine][GCE]

By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. 
They created a ubiquitous abstraction that could run better than anyone else.

At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. 
Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing trade secrets.

Google ultimately donated it to the **Cloud Native Computing Foundation**.

A **pod** is the most basic unit that K8s deals with, representing one or more **tightly-coupled** containers that should be controlled as a single application (typically one main container with subsidiary helper containers). 
Within a pod you can specify more than one container image.

A pod's containers should:

- operate closely together
- share a lifecycle
- always be scheduled on the same node

- **Worker**: a container host, with a Kubelet process that communicates with K8s cluster services.
- **Desired State Management** system, used by Kubernetes to describe a cluster's desired state declaratively.

Kubernetes can be visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels.
One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. 

- A master node runs 3 processes: `kube-apiserver`, `kube-controller-manager`, and `kube-scheduler`
- **Master (control plane) components** also run on the master node: `kube-apiserver`, `kube-controller-manager`, `kube-scheduler`, and Cluster Store

Other machines in the cluster are called **nodes** or **workers** and accept and run workloads using available resources. 

- Each node is equipped with a container runtime like Docker, which it uses to create and destroy containers according to instructions from the master server.
- Each node runs 2 processes: `kubelet` and `kube-proxy`.

![](/img/persistent-volume-claims.png)

A volume represents a way to store, retrieve, and persist data across pods and through the application lifecycle. In the context of Azure, Kubernetes can use two types of data volume:
- **Azure Disks** using Azure Premium (SSDs) or Azure Standard (HDDs).
- **Azure Files** using a SMB 3.0 share backed by an Azure Storage account.

A **PersistentVolumeClaim** requests either Disk or File storage of a particular StorageClass, access mode, and size. It is bound to a **PersistentVolume** once an available storage resource has been assigned to the pod requesting it.


#### [Kusto](Kusto)

**Kusto** is a case-sensitive query language developed by Microsoft and used in several Azure services:

- [Azure Data Explorer](#azure-data-explorer)
- [Log Analytics](#log-analytics)
- [Sentinel](#sentinel)
- [Application Insights](#application-insights)
- Microsoft Defender ATP

#### Lightsail

**Amazon Lightsail** offers blueprints that will automatically provision all compute, storage, database, and network resources needed for a deployment.

#### Macie

Macie is an AWS service that automatically finds and classifies sensitive data stored in AWS using machine learning to recognize sensitive data such as PII or trade secrets.

#### MARS

The **Microsoft Azure Recovery Services (MARS)** agent is for [backing up](#backups) Windows machines only, but can be installed on VMs on other cloud providers like AWS.
MARS can be configured to protect the entire system, volumes, or individual files and folders.

#### Monitor

Resources:

- ▶ [Dashboards with Azure Monitor Data](https://www.youtube.com/watch?v=XS2b_rxkwMY "YouTube - Create Dashboards with Azure Monitor Data")

#### Neptune

**Neptune** is an AWS graph database.

#### NPM


**Network Performance Monitor** is a [Log Analytics](#log-analytics) network monitoring solution for hybrid networks, providing 3 services:

- [**Performance Monitor**](#performance-monitor) monitors connectivity between various points in both Azure and on-prem networks
- [**Service Connectivity Monitor**](#service-connectivity-monitor) monitors outbound connectivity from network nodes to external TCP services, monitoring performance metrics like latency, response time, and packet loss
- [**ExpressRoute**](#expressroute) monitors end-to-end connectivity between on-prem network and Azure over ExpressRoute


#### Network Watcher

**Network Watcher** appears like a normal resource in a resource group, but it is deployed as a single instance per Azure region.

Network Watcher monitoring and diagnostic tools:

- [IP Flow Verify](Task-Network-Watcher#ip-flow-verify)
- [Next Hop](Task-Network-Watcher#next-hop)
- [Packet Captures](Task-Network-Watcher#packet-capture) link a Network Watcher resource, a target VM, a storage account, and a filter that specifies the characteristics of network traffic (source and destination IP addresses and ports as well as protocol) to capture, as well as a time limit.
- [Network Topology](Task-Network-Watcher#network-topology)

#### OpsWorks

**OpsWorks** is AWS's **declarative** configuration management service that uses the Chef and Puppet configuration management platforms and comes in three varieties:

- **OpsWorks for Puppet Enterprise**
- **OpsWorks for Chef Automate**
- **OpsWorks Stacks**

#### Recovery Services Vault

A **Recovery Services Vault** is an Azure resource used to centrally manage the backup and recovery of Azure resources, and the centerpiece of any backup strategy.

- A **Backup  protection policy** defines how a backup plan is implemented. These are most easily created through the Portal.
- A vault can only back up data from other resources that exist in its region.

#### Rekognition

AWS deep learning-based image recognition service.

#### Route 53

**Route 53** is AWS's managed DNS service.
Like any other DNS system, it relies on **resource records** defined in a  **zone**.

Route 53 can also provide name resolution for **private domain names**, used on private networks.
**Private hosted zones** provide DNS resolution for a single domain name within multiple VPCs.

But when a resource record must be changed dynamically to work around failures or route users to an underutilized server, **routing policies** can be used.


- **Simple policy** is the default for new resource records and maps a domain name to a single value (i.e. an IP address).
- **Weighted policy** distributes traffic across multiple resources according to a predefined ratio.
- **Latency policy** sends users to resources in their closest Region.
- **Failover policy** allows a secondary resource to be marked for routing when the primary resource is unavailable.
- **Geolocation policy** routes users based on their specific continent, country, or state.
- **Multivalue answer policy** allows even distribution of traffic across multiple resources by randomizing the order of returned records.

All routing policies except Simple can use health checks to modulate routing action.
All health checks occur every 10 or 30 seconds and can check one of three resources:

- **Endpoint** makes a test connection to a TCP port
- **CloudWatch alarm** can be set off in case of high latency or other metrics.
- **Calculated** monitors the status of other health checks.

Route 53 also offers the Route 53 Traffic Flow visual editor that allows you to create a diagram to represent the desired routing.
The diagram isn't translated to individual resource records but rather represents a single policy record which costs 50 USD/month each.
In addition to the routing policies above, Traffic Flow also offers the **Geoproximity** routing policy that directs users to a geographic location based on how close they are.


#### S3

**Simple Storage Service (S3)** is Amazon's data storage service.
S3 stores **objects** in a container called a **bucket**.
Each bucket must have a globally unique name and exposes a HTTP endpoint (at https://$BUCKET.s3.amazonaws.com/)

Each object is associated with a **key**.
Keys are equivalent to filenames, and the bucket is equivalent to a flat filesystem.
However, directories can be simulated by placing slashes in the key.

- **Bucket policies** (applied to buckets) and **user policies** (applied to IAM principals) can be used to modulate accessibility.
Public or anonymous access to an object can only be granted by bucket policies.
Bucket and object ACLs are legacy access control methods that are still usable.
- S3 buckets store data unencrypted, although **encryption at rest** is available in two options:
    - Server-side encryption: S3 encrypts uploaded objects before storing them, and decrypts it again before delivery.
    - Client-side encryption: User must encrypt data prior to uploading and decrypt it after downloading.

S3 offers various **storage classes** that differ in their availability and **durability**, the percent likelihood that an object within it will not be lost over the course of a year.

Frequently accessed objects:

- `STANDARD`
- `REDUCED_REDUNDANCY`

Infrequently accessed objects

- `STANDARD_IA`
- `ONEZONE_IA`
- [`GLACIER`](#glacier)

`INTELLIGENT_TIERING` automatically moves objects to the most cost-effective storage tier based on access patterns.

**Storage Gateway** is an on-premises VM that provides a connection to S3 for on-premises infrastructure.

- **File gateway** lets you use NFS and SMB file shares to transfer data to S3. Data is stored in S3 and cached locally.
- **Volume gateway** can be used as an iSCSI target by on-premises servers. Two configuration variants exist:
    - **Stored volumes**: All data is stored locally and asynchronously backed up to S3 as [EBS](#ebs) snapshots. A stored volume can range from 1 GB to 16 TB in size.
    - **Cached volumes**: Data is stored in S3 and frequently used data is cached locally. A cached volume can range from 1 GB to 32 TB in size.
- **Tape gateway** is configured as an iSCSI target by a backup application. Virtual tapes range from 100 GB to 2.5 TB in size. These tapes are asynchronously transferred to a **virtual tape library (VTL)** backed by S3 and removed when the upload is complete. Recovery requires downloading the virtual tape again.

▶ [Cloud Storage in Minutes with AWS Storage Gateway](https://youtu.be/2I4CKdNESoQ)

#### Sentinel

**Azure Sentinel** is a cloud-native SIEM and SOAR soluation that can collect data from many sources and present it to security analysts, who can run [Kusto](Kusto) queries against the dataset.

Azure Sentinel can ingest data from on-premises devices using one of several types of **connector**, categorized by the type of data ingestion:

- **Native connectors** integrate directly with other Microsoft security products, like Azure AD, M365, and Azure Security Center
- **Direct connectors** are configured from their source location, such as AWS CloudTrail, Azure Firewall, and Azure Front Door 
- **API connectors** are implemented by security providers, like Azure Information Protection (AIP), Barracuda Web Application Firewall (WAF), and Microsoft WAF
- **Agent-based connectors**, using the Log Analytics agent, make it possible to ingest data from any source that can stream logs in Common Event Format (CEF), such as Windows and Linux machines.

**Analytic rules** are rules that users create to help detect threats and anomalies in an environment:

- Scheduled rules run on a predetermined schedule
- Microsoft Security
- Machine learning behavior analytic rules can (currently) only be created from templates provided by Microsoft using proprietary ML algorithms

#### Simple Queue Service

**Simple Queue Service (SQS)** is an AWS service that can broker messages between components of highly decoupled applications.

#### Snowball

**AWS Snowball** is a physical appliance designed to move large amounts of data to the cloud.
The largest Snowball device can store 72 TB of information.

**Snowball Edge** refers to a family of options similar to Snowball but with compute power to run EC2 instances and Lambda functions locally.
All Snowball Edge options feature a QSFP+ network interface that is capable of speeds up to 100 Gbps.
Snowball Edge devices can also be clustered together.

- **Storage Optimized** provides up to 80 TB of storage and 24 vCPUs.
- **Compute Optimized** provides up to 39.5 TB of storage and 52 vCPUs.
- **Compute Optimized with GPU** is similar to Compute Optimized but includes an NVIDIA GPU, making it useful for ML and HPC applications.

#### Spanner

GCP managed scaleable database service.


#### Stackdriver

GCP service that collects metrics, logs, and event data from applications and infrastructure and integrates the data so DevOps engineers can monitor, assess, and diagnose operational problems.

#### Storage accounts

Azure storage accounts are managed through [Azure Resource Manager][ARM] and management operations are authenticated and authorized using [Azure Active Directory][Azure AD]. 

There are four **services** provided within each storage account:

1. **Blobs** provides a highly scalable service for storing arbitrary data objects, such as text or binary data. There can be multiple **containers** within a storage account, and a container can have its own folder structure. There are three types of blob: **page**, **block**, and **append** blobs.
2. **Tables** provides a NoSQL-style store for storing structured data. Tables in Azure storage do not require a fixed schema, thus different entries in the same table can have different fields
3. **Queues** provides reliable message queueing between application components
4. [**Files**](Azure-File-Service) provides managed file shares that can be used by VMs or on-premises servers

Options that must be selected when creating a storage account:

- **Performance tier**
    - Standard supports all storage services and uses magnetic disks to provide cost-efficient and reliable storage
    - Premium only supports page blobs with the locally-redundant (LRS) replication option, uses high-performance SSD disks
- **Account kind**
    - General-purpose V2: only kind to support ZRS
    - General-purpose V1: does not support various access tiers.
    - Blob storage: specialized storage account used to store block and append blobs
- **Replication mode**: Storage accounts can be freely moved between the following replication modes, except ZRS, in which case it is recommended to copy data to a new account.
    - Locally-redundant storage (LRS): makes 3 local sychronous within the same Azure facility (zone)
    - Zone-redundant storage (ZRS): makes 3 synchronous copies across multiple availability zones; available for general-purpose v2 storage accounts at Standard performance tier only. 
    - Geographically-redundant storage (GRS): makes 3 local synchronous copies plus 3 additional asynchronous copies (typically within 15 minutes, but no SLA) to a second data center far away from the primary region
    - Read-access geographically redundant storage (RA-GRS): makes 3 local synchronous copies plus 3 additional asynchronous copies to a second data center far away from the primary region, which has only read-only access
- **Access tier**: Both Blob and StorageV1 can be upgraded to StorageV2, a process which is irreversible. 
    - Hot blob storage access tier optimized for the frequent access of objects in the storage account
    - Cool blob storage access tier optimized for storing large amounts of data that is infrequently accessed and stored for at least 30 days
    - Archive blob storage access tier designed for long-term storage of infrequently-used data that can tolerate several hours of retrieval latency, remaining in the Archive tier for at least 180 days. It is stored offline and can take up to 15 hours for it to be "rehydrated" to the Cool or Hot tier before it can be accessed.
    - Premium providing high-performance access for frequently-used data on SSD, only available from the Block Blob storage account type.


Every storage account service exposes its own Internet-facing endpoint, which must be secured in one of several ways. 
A firewall can be implemented by using network rules to limit traffic to particular networks.
The **storage firewall** controls IP addresses and VNets can access the storage account and applies to all storage account services.

Access can be restricted to specific [VNets](VNet) by creating a [**Virtual Network Service Endpoint**](#virtual-network-service-endpoint), however this still uses the public IP address.
**Private Link** allows similar functionality using private IPs. <sup> [MS Docs](https://docs.microsoft.com/en-us/azure/private-link/private-link-overview "What is Azure Private Link?")

Public access to blobs can be restricted at the container level on container creation.
By default, no public read access is enabled for anonymous users, but users with RBAC rights or with the storage account name and key can have access. This can be done through ARM APIs, the Portal, or Azure Storage Explorer. Container access levels:

- No public read access: container and blobs can only be accessed by storage account owner  (default for new containers)
- Public read-only access for blobs only (container data is not available, and anonymous clients cannot enumerate the blobs within the container)
- Full public read-only access: all container and blob data can be read by anonymous requests:

Access can also be switched between [**Shared Key**-based authentication (relying on storage account keys)](#shared-key-access) and [Azure AD authentication](Azure-AD), where a [RBAC](RBAC) role determines access to a Container. :point_right: [Authorize access to blobs and queues using Azure Active Directory](https://docs.microsoft.com/en-us/azure/storage/common/storage-auth-aad)

**Access keys** grant full access to all data in all services of a storage account and represent the simplest and most powerful control over access. 
Access keys are typically used by applications for access to Azure storage, either through a **Shared Access Signature (SAS)** token or directly accessing the storage itself with the name and key.

Storage account keys were implemented early in the history of Azure and grant full access to the entire storage account. However, it is considered an anti-pattern to distribute this key; a [SAS token](#sas-token) should be [generated](#create-sas-token) for every stored item to be distributed. 

Because storage account keys provide write access, a storage account with a [`ReadOnly` resource lock](Resources#locks) will not enumerate its storage account keys, and users with Read permission will not be able to retrieve the keys either.

#### Systems Manager

**Systems Manager** is an AWS service for imperative configuration management.
Systems Manager relies on several types of script:

- **Command documents** use normal shell commands and can be run periodically or on a trigger, so long as the instance to be managed has the required agent.
- **Automation documents** allow administration of AWS resources, similar in effect to using the Management Console or the [AWS CLI](#aws-cli).


#### Trusted Advisor

**Trusted Advisor** is an AWS service allows a visual check of resource configurations to ensure compliance with best practices, and is available only to Business and Enterprise [Support plans](#-support). It offers several categories ([src](#sources "Piper 41"))

- Cost optimization
- Performance
- Security
- Fault tolerance
- Service limits

#### VM Agent

**Microsoft Azure Virtual Machine Agent (VM Agent)** manages VM interaction with the Azure Fabric Controller and comes preinstalled with Windows images from the Marketplace. 
It can also be [installed](https://docs.microsoft.com/en-us/azure/virtual-machines/extensions/agent-windows) on a custom image.

VM Agent supports the [VMSnapshot][VMSnapshot] extension, which is added when backups are enabled. 
This extension takes a snapshot of the storage at the block level and sends it to the RSV configured. 
For Windows VMs, this extension leverable the [Volume Shadow Copy][Volume Shadow Copy] service.

#### VMSnapshot

#### Volume Shadow Copy

#### waagent

**Microsoft Azure Linux Agent (waagent)** manage VM interaction with the Azure Fabric Controller on Linux VMs.

#### WAImportExport

**WAImportExport.exe** is a CLI tool associated with [Azure Import/Export service](#importexport-service).
It requires a Windows computer with .NET Framework and BitLocker. 

There are two versions:

- Version 1 is recommended for **blob storage**
- Version 2 is recommended for **files storage**.

Check disks required for selected blobs

```cmd
WAImportExport.exe PreviewExport 
    /sn:<Storage account name> 
    /sk:<Storage account key> 
    /ExportBlobListFile:<Path to XML blob list file> 
    /DriveSize:<Size of drives used>
```

Various flags in `WAImportExport.exe` allow an XML-format "blob list" file to be used to specify files, or as output.

=== "All"

    Export all blobs in the storage account

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>
        <BlobPath>/</BlobPath>
    </BlobList>
    ```

=== "Root"

    Export all blobs in the root container

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>  
        <BlobPath>/$root</BlobPath>
    </BlobList>
    ```

=== "Blob in root"

    Export blob "logo.bmp" in the root container

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>  
        <BlobPath>$root/logo.bmp</BlobPath>
    </BlobList>
    ```

=== "Containers"

    Export all blobs in container "music"

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>  
        <BlobPath>/music/</BlobPath>
    </BlobList>
    ```

=== "Pattern"

    Export all blobs in any container that begins with "book"

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>  
        <BlobPath>/book</BlobPath>
    </BlobList>
    ```


=== "Pattern in container"

    Export all blobs in container "music" that begin with prefix "love"

    ```xml
    <?xml version="1.0" encoding="utf-8"?>  
    <BlobList>  
        <BlobPath>/music/love</BlobPath>
    </BlobList>
    ```

#### WebJobs

WebJobs is a feature of [Azure App Service](#app-service) that enables you to run a program or script in the same instance as a web app, API app, or mobile app, at no additional cost and supported **only on Windows App Service plans**. 

There are two types:

- **Continuous** webjobs default to running on all instances of the linked web app (although it can be configured to run on only one)
- **Triggered** webjobs run only when triggered or on a schedule and on only a single instance of the linked web app selected by Azure.




[App Engine]: #app-engine 'App Engine is a GCP PaaS offering'
[App Service]: #app-service 'Azure App Service is an Azure PaaS offering for hosting websites.'
[Athena]: #athena "AWS service that allows SQL queries to be run against data stored in a S3 bucket"
[AKS]: #aks "Azure Kubernetes Service is Azure's managed Kubernetes offering."
[Azure Automation]: https://azure.microsoft.com/en-us/services/automation/ "cloud-based configuration management"
[Azure Container Instances]: #azure-container-instances "Simpler way of deploying containers in Azure than Azure Kubernetes Service, where containers are deployed into container groups that share the same lifecycle"
[Azure Key Vault]: https://azure.microsoft.com/en-us/services/key-vault/  "helps safeguard cryptographic keys and secrets used by cloud applications and services"
[Bigquery]: #bigquery 'Petabyte-scale analytics database service for data warehousing'
[BigTable]: #bigtable 'GCP realtime database used for Big Data'
[cbt]: #cbt 'Command-line interface for performing several different operations on Cloud Bigtable'
[Cloud AutoML]: #cloud-automl 'GCP service that allows developers without machine learning experience to develop machine learning models'
[Cloud Functions]: #cloud-functions 'GCP serverless compute offering'
[Cloud Inference API]: # 'GCP service for computing correlations over time-series data'
[Cloud Machine Learning Engine]: #cloud-machine-learning-engine 'Cloud Machine Learning Engine Platform for building and deploying scalable machine learning systems to production'
[Cloud Natural Language Processing]: #cloud-natural-language-processing 'Tool for analyzing human languages and extracting information from text'
[Cloud Run]: #cloud-run 'Google Cloud Run Fully managed compute environment that facilitates container deployment'
[Cloud Vision]: #cloud-vision 'Image analysis platform for annotating images with metadata, extracting text, or filtering content'
[CloudFormation]: #cloudformation 'CloudFormation gives developers and systems administrators an easy way to create and manage a collection of related AWS resources, provisioning and updating them in an orderly and predictable fashion'
[CodeBuild]: #codebuild 'CodeBuild is an AWS managed build service'
[CodeCommit]: #codecommit 'CodeCommit is the AWS private git repo service.'
[CodeDeploy]: #codedeploy 'CodeDeploy is an AWS service for automatically deploying applications to AWS compute resources or on-prem servers.'
[CodePipeline]: #codepipeline 'CodePipeline is an AWS service for orchestrating and automating every stage of software development.'
[CosmosDB]: #cosmosdb 'Azure NoSQL database service optimized for mobile and web applications that offers graph, document, and key-value APIs'
[Dataprep]: # 'Cloud Dataprep Service that allows analysts to explore and prepare data for analysis'
[EC2]: #iaas 'Elastic Compute Cloud (EC2) makes virtual machines available in AWS and provides a managed environment for Docker containers'
[ECS]: #ecs "Elastic Container Service"
[EKS]: #eks "Elastic Container Service for Kubernetes"
[Firestore]: #firestore 'Firestore GCP NoSQL document database service offering high performance and automatic horizontal scaling intended for serverless mobile and web application development with Cloud App Engine'
[GKE]: # 'Google Kubernetes Engine (GKE) allows users to easily run containerized applications on a cluster of servers'
[Google Cloud Functions]: # 'Cloud Functions lightweight computing option well-suited to event-driven processing'
[Google Compute Engine]: # 'Compute Engine allows users to create VMs, attach persistent storage to them, and make use of other GCP services like Cloud Storage'
[Kubeflow]: #kubeflow 'Kubeflow '
[Lambda]: #serverless 'AWS serverless compute offering'
[Lightsail]: #lightsail "Amazon Lightsail offers blueprints that will automatically provision all compute, storage, database, and network resources needed for a deployment after specifying a desired monthly cost."
[Microsoft Azure Linux agent]: #waagent '...' 
[Neptune]: #neptune "Neptune is an AWS graph database"
[Project Bicep]: #bicep 'Azure domain-specific language and CLI utility that can generate ARM templates'
[Redshift]: # 'Redshift fast, fully managed petabyte-scale data warehouse that makes it simple and cost-effective to analyze all your data using your existing business intelligence tools'
[Rekognition]: #rekognition 'Rekognition AWS deep learning-based image recognition service'
[Spanner]: #spanner 'Spanner GCP managed scaleable database service'
[SQS]: #simple-queue-service "Simple Queue Service (SQS) is an AWS service that can broker messages between components of highly decoupled applications."
[Stackdriver]: #monitoring 'GCP monitoring service that collects and integrates metrics, logs, and event data from applications and infrastructure'
[Trace]: #monitoring 'Distributed tracing service that captures latency data about an application to help identify performance problem areas'
[VMSnapshot]: #vmsnapshot '...'
[Volume Shadow Copy]: #volume-shadow-copy '...'
[Elastic Beanstalk]: #elastic-beanstalk "AWS Elastic Beanstalk is a PaaS offering."

[ACI]: #container-instances "Azure Container Instances (ACI) is a PaaS service that facilitates deployment of individual containers."
[Dataflow]: #dataflow "Cloud Dataflow is a GCP streaming data framework for defining batch and stream processing pipelines."
[Dataproc]: #dataproc "Cloud Dataproc is a managed Hadoop and Spark service offered by GCP."