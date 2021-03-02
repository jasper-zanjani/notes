# ☁&#xfe0f; Cloud

## Compute

### IaaS

=== "Azure"

    **Virtual Machines** represent Azure's IaaS offering.

    A **dedicated host group** has to be [created](#dedicated-host) and placed in a resource group and associated with a location and availability zone and assigned a fault domain. A host then has to be created, a size specified, and associated with a host group. Any VM intended to run on the host has to be created in the same location and availability zone and associated with the host in the **Advanced** tab.

    Azure **spot instances** are available at deep discounts.

    3 types of disk are available to Azure VMs:

    - Operating System Disk (OS Disk)
    - Temporary Disk
    - Data Disk

    Azure VM image types include:

    - **Managed** images (recommended), which remove the dependency of the VM to the image, at least within the same region. Copying a VM to another region still requires the managed image to be copied first.
    - **Unmanaged** images, which required the VM to be created in the same storage account as that of the image. VM copies required the image to be copies first.

    VM images are captured from an existing VM that has been **generalized** (prepared), removing unique settings (hostname, security IDs, personal information, user accounts, domain join information, etc) but not customizations (software installations, patches, additional files, folders), using `sysprep.exe` for Windows machines or Microsoft Azure Linux Agent (`waagent`) for Linux machines.

=== "AWS"

    [Elastic Compute Cloud (EC2)][EC2]

=== "GCP"

    **Google Compute Engine (GCE)** is GCP's IaaS offering.

    An **instance group** is a collection of VM instances that you can manage as a single entity. 
    
    Two types:
    - **Managed** instance groups operate applications like web front-ends across a group of identical VMs created with a template.
    They provide high availability, healing, scaling, and automatic updates.
    - **Unmanaged** instance groups allow you to manually load balance a group of VMs.
    VMs can be added or removed at will.


    - ▶ [Getting started with GCE](https://youtu.be/1XH0gLlGDdk "YouTube - Getting Started with Google Cloud Compute Engine")

### PaaS

- **Azure**
    - [App Service](#app-service)
- **AWS**
    - Elastic Beanstalk (EBS)
- **GCP**
    - [App Engine][App Engine]

### Containers

=== "Azure"

    [Azure Container Instances][Azure Container Instances] is a simpler way of deploying isolated containers than [Azure Kubernetes Service](Azure-Kubernetes-Service).

=== "AWS"

=== "GCP"

    - ▶ [GCP - Build and package container artifacts](https://www.youtube.com/watch?v=ysjCt3tNyV0 'YouTube - Getting started: Build and package container artifacts')
    - ▶ [GCP - Private container registry](https://www.youtube.com/watch?v=s46l_PmXBAQ 'YouTube - Getting started: Private container registry/storage')


### Serverless

=== "Azure"



=== "AWS"

    - [Lambda][Lambda]

=== "GCP"

    - [Cloud Functions][Cloud Functions]

## Storage

- **AWS**: [S3](#s3)
- **GCP**
    - [gsutil](gsutil) is the CLI interface for GCS

### Archive

=== "Azure"

=== "AWS"

    **S3 Glacier** offers long-term archival at low cost.
    One or more files are stored in an archive, typically a .zip or .tar file containing multiple files.
    Archives can range from 1 B to 40 TB in size.

    Archives are stored in a Glacier **vault**, a region-specific container analogous to S3 buckets.
    Vaults must have regionally unique names, but there is no need for a globally unique name.

    Glacier vaults can be created and deleted using the Glacier service console.
    But uploading, downloading, or deleting archives must be done through the [AWS CLI](#aws-cli) or an application using the SDK.
    Some third-party applications can also interact with Glacier.

=== "GCP"

### Backups

=== "Azure"

    [Backups](Azure-Backup) are integrated into Portal and clickable from the VM blade. 
    You have to specify a **Recovery Services vault** and a **Backup policy**. 
    The policy can specify frequency of backups, and other settings. Using Backup service costs $10 per VM plus the cost of used storage.

    2 methods to restore data after backing up a VM to Azure Backup:
    1. Restore a recovery point as a new VM
    2. Restore access to files only

=== "AWS"
=== "GCP"

### Physical media

=== "Azure"

    - Import/Export Service
    - [Data Box](#data-box)


=== "AWS"

    AWS Snowball is a physical appliance designed to move large amounts of data to the cloud.
    The largest Snowball device can store 72 TB of information.

    **Snowball Edge** refers to a family of options similar to Snowball but with compute power to run EC2 instances and Lambda functions locally.
    All Snowball Edge options feature a QSFP+ network interface that is capable of speeds up to 100 Gbps.
    Snowball Edge devices can also be clustered together.

    - **Storage Optimized** provides up to 80 TB of storage and 24 vCPUs.
    - **Compute Optimized** provides up to 39.5 TB of storage and 52 vCPUs.
    - **Compute Optimized with GPU** is similar to Compute Optimized but includes an NVIDIA GPU, making it useful for ML and HPC applications.

=== "GCP"

    - GCS Transfer appliance
    
    ▶ [Uploading files to GCS](https://youtu.be/nmZxfuFIP08 "YouTube - Uploading files to GCS (Cloud Storage Bytes)")

## Virtual networking

=== "Azure"

    A **Virtual Network (VNet)** consists of one or more IP ranges and exists within a single subscription and region.

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

    - No gateways are required for peering, although each peering is one-way and not transitive (i.e. VNet A can be peered to both VNets B and C, allowing traffic to/from both. But without a peering directly between B and C they will not be able to communicate to each other.)
    - There is a maximum of 100 peering connections per VNet
    - Peerings cannot be moved to another resource group or subscription, so they must be disabled before moving peered VNets.

    **ExpressRoute** is the main service used to connect Azure to on-premises networks, although P2S and S2S VPNs are also options.

    Before the introduction of peering, virtual networks were connected using S2S VPN or by connecting to the same ExpressRoute circuit.

    **Service endpoints** facilitate restricting traffic from Azure services. 
    **Service endpoint policies** allow restricting traffic to the granularity of individual Azure service instances.

=== "AWS"

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

    **Direct Connect** provides dedicated network connectivity to a VPC through links offered through [APN](#apn) partners.

=== "GCP"

### User-defined routes

=== "Azure"

    A **virtual appliance** refers to a VM running a network application like a load-balancer, firewall, or router. 
    **Service chaining** refers to the process of deploying a network virtual appliance (NVA) into a hub network to route traffic between spokes using [**user-defined routes (UDR)**](#create-user-defined-routes). 
    This is a method of reducing the complexity of pairing between individual spoke networks in complex hub-and-spoke architectures. <sup>AZ-103: 309</sup>

    - In such a deployment, the peerings must be set to **Allow Forwarded Traffic**.

    Alternatively, two peered networks can share a single virtual network gateway, say to connect to an external network.

    - The pairing connection **to** the network that contains the gateway must be set to **Use Remote Gateways**
    - The pairing connection **from** the network containing the gateway must be set to **Allow Gateway Transit**

=== "AWS"


=== "GCP"


### Network security

=== "Azure"

    **Network Security Groups (NSGs)** are assocated with **network interfaces** and contain an arbitrary number of **security rules**.
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

=== "AWS"
=== "GCP"


### DNS

=== "AWS"

    Route 53 is Amazon's managed DNS service.
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


### CDN

=== "AWS"

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


### VPN

**Virtual network gateways** in Azure are of two types: **VPN gateways** and **ExpressRoute gateways**.
Any virtual network can have only a single gateway of each type.

**VPN gateways** send encrypted traffic between the virtual network and an on-premises location. VPN Gateways must be deployed into their own dedicated subnet (named **"GatewaySubnet"**) with a minimum size of CIDR /29, although a CIDR /27 address block is recommended. VPN connections between an on-premises network and a VNet are only possible if the network ranges do not overlap.

VPN gateways can be classified by the topology of the connection:

- [**Site-to-Site (S2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#S2S) connections require an on-premises **VPN device** associated with a public IP address.
![](img/vpngateway-site-to-site-connection-diagram.png)
- [**Multi-Site**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#Multi) connections require a **RouteBased** VPN type. 
![](img/vpngateway-multisite-connection-diagram.png)
- [**Point-to-Site (P2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#P2S) allows individual computers to securely connect to a VNet without need for a VPN device, which is useful for telecommuting, and can use SSTP, OpenVPN, or IKEv2. There are several [authentication](#authentication) considerations.
![](img/point-to-site.png)
- [**VNet-to-VNet**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#V2V) connections are also possible, but VNet [peering](VNet#peering) may be preferable if the virtual networks meet certain requirements.
![](img/vpngateway-vnet-to-vnet-connection-diagram.png)

VPN gateways can also be classified on [VPN type](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#vpntype). 
- Route-based VPNs (previously called "dynamic routing gateways") require routes to be defined in a routing table to direct packets into tunnel interfaces.
![](img/routebasedmultisite.png)
- Policy-based VPNs (previously called "static routing gateways" in the classic deployment model) can only be used on the Basic gateway SKU and offer only a single S2S tunnel.
![](img/policybasedmultisite.png)

There is a profusion of [Gateway SKUs](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#gwsku) that determine the maximum connections, throughput, and availability of other features like BGP and zone-redundancy available for each topology.

A VPN gateway also requires a **local network gateway** (previously referred to as a Local Site), which is an Azure resource representing the on-premises VPN device or VPN concentrator.


---


- **Containers**: Container Service, Service Fabric
- **NoSQL**: [CosmosDB][CosmosDB], Table storage
- **Monitoring**: [Monitor](Azure#azure-monitor), App Insights
- **Messaging**: Service Bus
- **Load Balancing**: Load Balancer, Application Gateway
- **CDN**: Azure CDN
- **Batch data processing**: HDInsight, Batch
- **Streaming data**: 
    - Ingest: Event Hubs, Service Bus
    - Processing: Stream Analytics
- **Private connection**: ExpressRoute

- **Serverless**: [Lambda][Lambda]
- **Containers**: Elastic Container Service (ECS), Elastic Kubernetes Service (EKS)
- **Monitoring**: [CloudFormation][CloudFormation]
- **Messaging**: Simple Notification Service (SNS), Simple Queueing Service (SQS)
- **Load Balancing**: Elastic Load Balancer
- **CDN**: CloudFront
- **Batch data processing**: Elastic MapReduce (EMR), Batch
- **Streaming data**: Kinesis
- **Machine learning**: [Rekognition][Rekognition]
- **Private connection**: Direct Connect

- Command-line utilities: [AWS Command Line Interface](https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html), AWS Tools for PowerShell



- **Serverless**: [Google Cloud Functions][Google Cloud Functions]
- **Containers**: [Google Kubernetes Engine][GKE], [Cloud Run][Google Cloud Run], Cloud Run on GKE
- **NoSQL**: 
- **Monitoring**: [Stackdriver][Stackdriver], [Trace][Trace]
- **Messaging**: Pub/Sub
- **Load Balancing**: Load Balancing
- **CDN**:  CDN
- **Batch data processing**: [Dataflow][Dataflow], [Dataproc][Dataproc]
- **Streaming data**
    - Ingest: Dataflow
    - Processing: Pub/Sub


- Command-line utilities: [`cbt`][cbt], [`gcloud`][gcloud], [`gsutil`][gsutil]

## Databases


### NoSQL

NoSQL databases differ from **relational databases** in that they do not obey the principle of data **normalization**.
That is, the same data can be stored in more than one place.

This is an advantage for databases that are optimized for reads as opposed to writes, because fewer queries are needed to retrieve information.
However, when changing information that is duplicated in several places, write operations will be more laborious and prone to error.
NoSQL databases are also **horizontally scalable** because the information can be sharded horizontally more easily than relational database, which are only **vertically scalable** (meaning scaling them requires larger and larger computers) and can only be sharded vertically. ([src](https://youtu.be/v_hR4K4auoQ?t=620 "YouTube - What is a NoSQL Database? How is Cloud Firestore structured? | Get to Know Cloud Firestore #1"))

=== "Azure"

    - [CosmosDB][CosmosDB]


=== "AWS"

    - [DynamoDB][DynamoDB]

=== "GCP"

    - Firebase
    - [BigTable][BigTable]
    - [Cloud Firestore][Firestore]
    - [Spanner][Spanner]


    **Firestore** has almost completely supplanted Firebase for most applications. 

    **Firebase** is a completely unstructured NoSQL database that is known for its client libraries.

    **Firebase Auth** offers a free user interface for applications, **Firebase UI**.

    Cloud Firestore was released from beta in early 2019 and combines and improves upon functionality of previous products named **Cloud Datastore** and **Firebase Realtime Database**. 


    Cloud Firestore is organized into **documents**, which consist of key-value pairs and are similar to JSON objects, and **collections**. 
    JSON-like objects are called **maps** and keys are called **fields** in Firestore. 
    Collections can contain only documents, but documents sub-collections. 
    Root can only contain collections. So navigating deeper and deeper into the information store will involve alternating between collections and documents. <sup>[YouTube](https://youtu.be/v_hR4K4auoQ?t=620 "YouTube - What is a NoSQL Database? How is Cloud Firestore structured? | Get to Know Cloud Firestore #1")</sup>

    Firestore features a compatibility mode that emulates the behavior of Datastore in accessing Firestore's storage layer while removing some of Datastore's limitations.

    Queries in Firestore can only be used to find documents stored in one specific collection or sub-collection.
    However a **collection group query**, meaning one that spans multiple collections, began to be supported in 2019.
    Complex relational queries are not possible (in a single query), and query results are usually returned based on equality or greater-than/less-than comparisons.
    The field has to be specified as having a scope of "Collection group" within GCP, and there is a limit of (about) 200 for these queries. 
    <sup>[Firebase blog](https://firebase.googleblog.com/2017/10/cloud-firestore-for-rtdb-developers.html "Cloud Firestore vs the Realtime Database: Which one do I use?") [YouTube](https://youtu.be/U5aeM5dvUpA "YouTube - Introducing Firebase Realtime Database") [YouTube](https://youtu.be/Ofux_4c94FI "YouTube - How do queries work in Cloud Firestore? | Get to Know Cloud Firestore #2")</sup>

    An index is created for every field in every document added to a collection, which results in very fast query times that are proportional to the number of **results**, not records searched. 
    This structure ensures that equality searches are highly performant, as are comparison searches using greater-than or less-than.
    But this implementation creates bizarre limitations to Firestore's querying capabilities:
    There is no native way to perform wildcard searches or `OR` queries. 
    For common instances of such queries, Google recommends adding a field that contains the value for each record 

    Inequality searches present a challenge for Firestore.
    For some queries that combine conditions on more than one field (i.e. restaurants within a certain range of a location), Firebase will create a "composite index" (only within the index, the document itself is not affected) automatically to facilitate searches on those fields.

    Unlike **Firebase**, which charges based on the volume of data stored, **Firestore** charges based on number of operations performed and records returned.

    Sources:

    - ▶ [Introducing Firebase Realtime database](https://youtu.be/U5aeM5dvUpA "YouTube - Introducing Firebase Realtime Database")
    - ▶ [Firebase web application tutorial](https://youtu.be/9kRgVxULbag "YouTube - Firebase - Ultimate Beginner's guide")
    - ▶ [Firebase Realtime DB vs Firestore](https://youtu.be/TmXct7seeBY)
    - 📄 [Cloud Firestore vs the Realtime Database: Which one do I use?](https://firebase.googleblog.com/2017/10/cloud-firestore-for-rtdb-developers.html "Cloud Firestore vs the Realtime Database: Which one do I use?")

### Big Data

=== "Azure"

    Data Lake Analytics, Data Lake Store

=== "AWS"

    [Redshift][Redshift], Athena

=== "GCP"

    - [Bigquery][Bigquery]
    - [Dataprep][Dataprep]

## Administration

### Resources

=== "Azure"


=== "AWS"


=== "GCP"

    The **resource hierarchy** organizes GCP resources in 3 levels

    - **Domain**
        - **Organization** corresponds to a company or organization. A single **cloud identity** is associated with a single organization and can have **super admins**
            - **Folders** can contain other folders or projects and facilitate multilayer organizational hierarchies.
                - **Projects** are the direct parents of all GCP resources and can also have **Labels**. A project can have many labels, but only lives in a **single** folder.

    **Billing Account** tracks charges and billing account admins can set budgets.

    **Payments Profile** is a Google-level resource that is used to pay for all Google services.

### Tags

Tags are case-insensitive key-value pairs used to organize Azure resources.

### Infrastructure

=== "AWS"

    The AWS Global Infrastructure is composed of **Regions** and **Availability Zones**. 
    Most services are regionally based, meaning the underlying hardware of that service's instance will exist in only a single Region.
    Some regions, like **AWS GovCloud**, have restricted access.

    Some AWS resources, however, are technically running on hardware that exists in a single Region, but presented as global. 

    Resources

    - [Services available on Free Tier](https://aws.amazon.com/free/?all-free-tier.sort-by=item.additionalFields.SortRank&all-free-tier.sort-order=asc)

### IAM

=== "Azure"


=== "AWS"


=== "GCP"

    **Roles** are collections of permissions
    - **Primitive roles** are basic privileges that can be applied to most resources and include Owner, Editor, and Viewer
    - **Predefined roles** are specific to GCP products. For example, App Engine roles include:

    Resources

    - [Group membership and hierarchy](https://www.youtube.com/watch?v=b33-gN0lidA&t=77s 'YouTube - Group membership and hierarchy')

### Monitoring

=== "Azure"

    Azure Monitor

    - ▶ [Dashboards with Azure Monitor Data](https://www.youtube.com/watch?v=XS2b_rxkwMY "YouTube - Create Dashboards with Azure Monitor Data")

=== "AWS"

    Cloudwatch

=== "GCP"
    
    - [Stackdriver][Stackdriver]
    - [Trace][Trace]

### CLI

=== "Azure"

    - Azure CLI
    - Azure PowerShell

=== "AWS"

    - [AWS CLI](#aws-cli)

=== "GCP"

    - [gsutil](gsutil) is the CLI interface for GCS

    - [CLI for GCP](https://www.youtube.com/watch?v=D0x6B-4oUNM 'YouTube - Getting started: CLI for GCP')


### Support

=== "Azure"

=== "AWS"

    AWS offers various support plan tiers that provide 24/7 email, chat, and phone access to AWS cloud support engineers.

    - Basic Support Plan
    - Developer Support Plan (greater of $29 or 3% of monthly account usage)
    - Business Support Plan
    - Enterprise Support Plan (>$15,000/mo.) offers a **Technical Account Manager (TAM)**, a dedicated guide and advocate

    Documentation is available in several places:

    - [AWS documentation](https://docs.aws.amazon.com)
    - [AWS Knowledge Center](https://aws.amazon.com/premiumsupport/knowledge-center) is a sprawling FAQ
    - [AWS security resources](https://aws.amazon.com/security/security-resources)
    - [AWS forums](https://forums.aws.amazon.com)
    - Professional Services team makes white papers and webinars publicly available

=== "GCP"

## 📘 Glossary

#### APN

Amazon Partner Network

#### App Engine

App Engine allows developers to deploy applications developed in popular programming languages to a serverless environment.
It is available in two environment types:

- **Standard** where the application is ryun in a sandbox and isolated from the underlying server's OS.
- **Flexible** where Docker containers are run in the environment, useful when third-party software or libraries are needed.

Resources

- ▶ [App Engine in a minute](https://youtu.be/Xuf3J6SKVV0 "YouTube - App Engine in a minute")
- ▶ [Get to know GAE](https://youtu.be/2PRciDpqpko "YouTube - Get to know Google App Engine") 
- ▶ [Introduction App Engine's new Python 3 runtime](https://youtu.be/qeSpDwA2qcU)


#### App Service


![](..img/az-app-service.png)

An **App Service plan** resource determines the billable compute resources available for the App Services applications managed by it.
A plan acts as a container for multiple web applications sharing the same server farm ("workers"), and for this reason Windows and Linux apps can't be mixed in the same App Service plan.
"Web app" is the legacy name for Azure **App Service**.


Resources

- 💰 [Pricing](https://azure.microsoft.com/en-us/pricing/details/app-service/windows/)
- 📄 [Tutorial: build and run a custom image in Azure App Service](https://docs.microsoft.com/en-us/azure/app-service/tutorial-custom-container?pivots=container-linux)
- 📄 [Create an App Service app with deployment from GitHub using Azure CLI](https://docs.microsoft.com/en-us/azure/app-service/scripts/cli-deploy-github?toc=/cli/azure/toc.json)
- 📄 [Create a web app with continuous deployment from GitHub](https://docs.microsoft.com/en-us/azure/app-service/scripts/powershell-continuous-deployment-github?toc=/powershell/module/toc.json)
- 📄 [`New-AzAppServicePlan`](https://docs.microsoft.com/en-us/powershell/module/az.websites/new-azappserviceplan?view=azps-4.8.0)
- 📄 [`New-AzWebApp`](https://docs.microsoft.com/en-us/powershell/module/az.websites/new-azwebapp?view=azps-4.8.0)
- 📄 [What is Azure Front Door?](https://docs.microsoft.com/en-us/azure/frontdoor/front-door-overview)
- 📄 Create a Front Door - [PowerShell](https://docs.microsoft.com/en-us/azure/frontdoor/quickstart-create-front-door-powershell)

#### Application Gateway

**Azure Application Gateway** is used to load balance a large-scale set using more than 100 instances in place of [**Azure Load Balancer**](Azure-Load-Balancer). <sup>AZ-103: p. 223</sup>

Application Gateway supports **session affinity** to save user state using browser cookies.

Unlike Azure Load Balancer, which operates at OSI layer 4 and has limited security capabilities, Application Gateway operates at OSI layer 7 and provides Web Application Firewall (WAF) functioanlity to block attacks like SQL injection, cross-site scripting, and header injection. HTTPS is also only available with layer 7 load balancers like Application Gateway.


#### AWS CLI

AWS CLI is available in [versions](https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html) 1 and 2. 
Version 1 is maintained for legacy compatibility purposes.

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

#### Azure Container Instances

**Azure Container Instances (ACI)** allows a simpler way of running isolated containers in smaller-scale deployments than [Azure Kubernetes Service][AKS].

The top-level resource in ACI is the **container group**, a collection of containers that get scheduled on the same host machine. 
These containers share a lifecycle, resources, local network, and storage volumes, and is equivalent to a Kubernetes pod. 
Container groups can be deployed to a subnet that already hosts a container group or an empty one, but it may not be deployed to a subnet that already has other resources like VMs.

Resources

- 📄 [What is Azure Container Instances?](https://docs.microsoft.com/en-us/azure/container-instances/container-instances-overview)
- 📄 [Container groups in ACI](https://docs.microsoft.com/en-us/azure/container-instances/container-instances-container-groups)

#### Azure Data Explorer

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
**Consistency models** describe how and when data is replicated to provide varying consistency guarantees. ([src](https://aka.ms/cosmos-consistency-levels "Consistency levels in Azure Cosmos DB"))

- **Strong consistency** is the strongest consistency model and requires synchronous replication after every change to database, increasing latency for each write.
![](..img/strong-consistency.gif)
- **Bounded staleness** implies asynchronous replication and offers guarantees on the number of versions (**K**) or time interval (**T**) reads lag behind writes, referred to as the **staleness window**. As the staleness window approaches, Azure will delay writes by providing *back pressure* on writes. 
    - Outside the staleness window, data is guaranteed to be globally consistent. 
    - Outside the region in which the writes were made, Azure guarantees *total global order* or *consistent prefix*, which means, the global order is maintained.
![](..img/bounded-staleness-consistency.gif)
- **Session consistency** is unique, in that it offers consistent prefix to databases that support a single session or an application with a single token. 
![](..img/session-consistency.gif)
- **Consistent prefix** offers read throughput, availability, and write latency comparable to eventual consistency while guaranteeing global order.
- **Eventual consistency** is the weakest consistency model provides no ordering guarantees.
![](..img/eventual-consistency.gif)


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

- [**Learning Azure Cosmos DB**](https://app.pluralsight.com/courses/106da442-dfd4-4109-850d-efca92baae2b/table-of-contents)

#### Data Box

**Azure Data Box** is a Microsoft-provided appliance that allows for the transfer of large volumes of data to Azure. 
These services are only available for EA, CSP, and Microsoft Partner Network Sponsorship offer types.

| Offering       | Capacity | Storage saccounts |
| -------------- | -------: | ---------------: |
| Data Box Disk  |    35 TB |                1 |
| Data Box       |   100 TB |               10 |
| Data Box Heavy | 1,000 TB |               10 |


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

#### ExpressRoute

There are four main architectures used with ExpressRoute

- **Any-to-any connection** is used to integrate on-premises WANs using IPVPN.
- **Co-location with cloud exchange** is used to order virtual cross-connections to the Azure cloud through the co-location provider's Ethernet exchange.
- **Point-to-point Ethernet connection** is used to configure on-premises data center connectivity to Azure through individual point-to-point links

#### Front Door

**Azure Front Door** works like [Azure Load Balancer](Azure-Load-Balancer) for web apps.

Resources

- [Pricing](https://azure.microsoft.com/en-us/pricing/details/frontdoor/)

#### Import/Export Service

**Azure Import/Export service** allows the physical shipment of disks procured by the user to Azure for import. 
This data can be placed into blob or file storage.
This service requires the use of a Windows computer with BitLocker and .NET Framework and is dependent on the [WAImportExport.exe](#waimportexport) utility.

1. Procure 2.5-inch or 3.5-inch SATA (not SAS) disks
2. Connect the disks to a Windows machine.
3. Create a volume and encrypt it using BitLocker
4. Install **Azure Import/Export tool** (WAImportExport.exe) on the disks. This requires a Windows computer with .NET Framework and BitLocker. There are two versions: 
   - Version 1 is recommended for **blob storage**
   - Version 2 is recommended for **Files storage**.
5. Copy files
6. Create an **import job** in the Azure Portal


#### Kubeflow

**Kubeflow** is a cloud Native platform for machine learning based on Google’s internal machine learning pipelines

Resources:

- ▶ [Kubeflow 101 (playlist)](https://www.youtube.com/playlist?list=PLIivdWyY5sqLS4lN75RPDEyBgTro_YX7x 'YouTube - KubeFlow 101')
- ▶ [Talk - Kubeflow at Spotify](https://www.youtube.com/watch?v=m9XhsnNSMAI 'YouTube - Building and managing a centralized Kubeflow platform at Spotify')
- ▶ [Talk - Kubeflow on Kubernetes](https://www.youtube.com/watch?v=I6iMznIYwM8 'YouTube - Kubeflow ML on Kubernetes')

#### [Kusto](Kusto)

**Kusto** is a case-sensitive query language developed by Microsoft and used in several Azure services:

- [Azure Data Explorer](#azure-data-explorer)
- [Log Analytics](#log-analytics)
- [Sentinel](#sentinel)
- [Application Insights](#application-insights)
- Microsoft Defender ATP

#### Recovery Services Vault

A **Recovery Services Vault** is an Azure resource used to centrally manage the backup and recovery of Azure resources, and the centerpiece of any backup strategy.

- A **Backup  protection policy** defines how a backup plan is implemented. These are most easily created through the Portal.
- A vault can only back up data from other resources that exist in its region.

#### Rekognition

AWS deep learning-based image recognition service.

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

S3 offers various storage classes that differ in their availability and **durability**, the percent likelihood that an object within it will not be lost over the course of a year.

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

#### Spanner

GCP managed scaleable database service.


#### Stackdriver

GCP service that collects metrics, logs, and event data from applications and infrastructure and integrates the data so DevOps engineers can monitor, assess, and diagnose operational problems.

#### Trusted Advisor

**Trusted Advisor** is an AWS service allows a visual check of resource configurations to ensure compliance with best practices, and is available only to Business and Enterprise [Support plans](#-support). It offers several categories ([src](#sources "Piper 41"))

- Cost optimization
- Performance
- Security
- Fault tolerance
- Service limits

#### WAImportExport

**WAImportExport.exe** is a CLI tool associated with [Azure Import/Export service](#importexport-service)

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




[App Engine]: #app-engine 'GCP PaaS offering'
[Azure Container Instances]: #azure-container-instances "Simpler way of deploying containers in Azure than Azure Kubernetes Service, where containers are deployed into container groups that share the same lifecycle"
[BigTable]: #bigtable 'GCP realtime database used for Big Data'
[Bigquery]: #bigquery 'Petabyte-scale analytics database service for data warehousing'
[Cloud AutoML]: #cloud-automl 'GCP service that allows developers without machine learning experience to develop machine learning models'
[Cloud Functions]: #cloud-functions 'GCP serverless compute offering'
[Cloud Inference API]: # 'GCP service for computing correlations over time-series data'
[Cloud Machine Learning Engine]: #cloud-machine-learning-engine 'Cloud Machine Learning Engine&#10;Platform for building and deploying scalable machine learning systems to production&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Natural Language Processing]: #cloud-natural-language-processing 'Tool for analyzing human languages and extracting information from text'
[Cloud Run]: #cloud-run 'Google Cloud Run&#10;Fully managed compute environment that facilitates container deployment'
[Cloud Vision]: #cloud-vision 'Image analysis platform for annotating images with metadata, extracting text, or filtering content'
[CloudFormation]: #cloudformation 'CloudFormation&#10;gives developers and systems administrators an easy way to create and manage a collection of related AWS resources, provisioning and updating them in an orderly and predictable fashion'
[CosmosDB]: #cosmosdb 'Azure NoSQL database service optimized for mobile and web applications that offers graph, document, and key-value APIs'
[Dataprep]: # 'Cloud Dataprep&#10;Service that allows analysts to explore and prepare data for analysis&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 30'
[EC2]: #iaas 'Elastic Compute Cloud (EC2)&#10;makes virtual machines available in AWS and provides a managed environment for Docker containers'
[Firestore]: #firestore 'Firestore&#10;GCP NoSQL document database service offering high performance and automatic horizontal scaling intended for serverless mobile and web application development with Cloud App Engine'
[GKE]: # 'Google Kubernetes Engine (GKE)&#10;allows users to easily run containerized applications on a cluster of servers&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 19'
[Google Cloud Functions]: # 'Cloud Functions&#10;lightweight computing option well-suited to event-driven processing&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 20'
[Google Compute Engine]: # 'Compute Engine&#10;allows users to create VMs, attach persistent storage to them, and make use of other GCP services like Cloud Storage&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 17'
[Kubeflow]: #kubeflow 'Kubeflow&#10;'
[Lambda]: #serverless 'AWS serverless compute offering'
[Redshift]: # 'Redshift&#10;fast, fully managed petabyte-scale data warehouse that makes it simple and cost-effective to analyze all your data using your existing business intelligence tools'
[Rekognition]: #rekognition 'Rekognition&#10;AWS deep learning-based image recognition service'
[Spanner]: #spanner 'Spanner&#10;GCP managed scaleable database service'
[Stackdriver]: #monitoring 'GCP monitoring service that collects and integrates metrics, logs, and event data from applications and infrastructure'
[Trace]: #monitoring 'Distributed tracing service that captures latency data about an application to help identify performance problem areas'
[cbt]: #cli 'Command-line interface for performing several different operations on Cloud Bigtable'