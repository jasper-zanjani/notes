**Apigee**{: #apigee }
:   The **Apigee** API platform is a management service that allows developers to deploy, monitor, and secure their APIs and generates API proxies.

**App Engine**{: #app-engine }
:   App Engine allows developers to deploy applications developed in popular programming languages to a serverless environment.
    It is available in two environment types: Standard and Flexible.

    - **Standard environment** is the original App Engine environment, consisting of a preconfigured, language-specific runtime like Java, Python, PHP, Node.js, or Go.
    - **Flexible environment** is similar to [GKE][GKE] in that it can run a customized container.

    App Engine is designed to support applications implemented as a microservices architecture. There are four components:

    - The **application** is the top-level container that houses all other components.
    - **Services** are versioned and provide a specific function.
    - **Versions** are produced every time a service is updated.
    - Every version runs on an **instance**.


    Each version of a service runs on its own instance, whose size can be determined by specifying the **instance class**.
    Instances can be dynamic or resident.

    - **Resident instances** run continually and can be added or removed manually.
    - **Dynamic instances** support autoscaling based on load.

    App Engine has three modes of scaling:

    - **Automatic** scaling creates an instance with a specified request rate, response latency, and application metrics.
    - **Basic** scaling creates instances only when requests are received
    - **Manual** scaling supports operational continuity regardless of load level.

**App Engine Deployer**{: #app-engine-deployer} [:material-google:](https://cloud.google.com/iam/docs/understanding-roles)
:   Read-only access to all application configuration and settings.

**App Engine Service Admin**{: #app-engine-service-admin} [:material-google:](https://cloud.google.com/iam/docs/understanding-roles)
:   Read-only access to all application configuration and settings.
    Write access to module-level and version-level settings. Cannot deploy a new version.

**App Service**{: #app-service}
:   An **App Service plan** resource determines the billable compute resources available for the App Services applications managed by it.
    A plan acts as a container for multiple web applications sharing the same server farm ("workers"), and for this reason Windows and Linux apps can't be mixed in the same App Service plan.
    "Web app" is the legacy name for Azure **App Service**.

    App Service SSL certificates need to be deleted from each App Service before moving it to a new resource group.

**Application Gateway**{: #application-gateway }
:   **Azure Application Gateway** is used to load balance a large-scale set using more than 100 instances in place of [**Azure Load Balancer**](Azure-Load-Balancer). <sup>AZ-103: p. 223</sup>

    Application Gateway supports **session affinity** to save user state using browser cookies.

    Unlike Azure Load Balancer, which operates at OSI layer 4 and has limited security capabilities, Application Gateway operates at OSI layer 7 and provides Web Application Firewall (WAF) functioanlity to block attacks like SQL injection, cross-site scripting, and header injection. HTTPS is also only available with layer 7 load balancers like Application Gateway.

**Athena**{: #athena }
:   **Athena** is a serverless AWS service that allows SQL queries to be run against data stored in a [S3][S3] bucket.
    Athena works closely with [AWS Glue][AWS Glue] to extract schema information and crawl data sources.
    Before running for the first time, you must provide a path to a S3 bucket to store query results.

**AWS CLI**{: #aws-cli }
:   AWS CLI is version 1 is maintained for legacy compatibility purposes.

**AWS Developer Tools**{: #aws-developer-tools }
:   A collection of tools that provide CI services:

    - [CodeCommit][CodeCommit]
    - [CodeBuild][CodeBuild]
    - [CodeDeploy][CodeDeploy]
    - [CodePipeline][CodePipeline]

**AWS Glue**{: #aws-glue }
:   

**AzCopy**{: #azcopy }
:   **AzCopy** can be used to copy files to File storage.

**Azure Bastion**{: #azure-bastion }
:   **Azure Bastion** is a PaaS service deployed within a VNet that allows connectivity to a VM from the Portal. 
    Once deployed in a VNet, RDP/SSH is available to all VMs in that VNet. 
    This session is streamed to your local device over an HTMLS session using the browser.

    - It is not deployed per VM, but once per VNet to its **own dedicated subnet**, at least /27 or larger
    - No public IP is necessary on the VM, the connection from Bastion to the VM is to the private IP. However, the Bastion itself does require a public IP.
    - Bastion can now span peered VNets

    IPv6 support is limited in Azure. 
    IPv6 addresses are not added to VMs by default and  must be explicitly defined by adding an endpoint to each VM to be using it. 
    Routing by IPv6 is also not supported, so load balancers have to be deployed.

**Bicep [:material-github:](https://github.com/Azure/bicep)**{: #bicep }
:   Project Bicep is a domain-specific language and command-line utility that can be used to generate [ARM][ARM] templates.

    :octicons-play-24: [Project Bicep – Next generation ARM Templates](https://youtu.be/wkQIyenVfxc)

**Azure Container Instances**{: #azure-container-instances }
:   **Azure Container Instances (ACI)** allows a simpler way of running isolated containers in smaller-scale deployments than [Azure Kubernetes Service][AKS].

    The top-level resource in ACI is the **container group**, a collection of containers that get scheduled on the same host machine. 
    These containers share a lifecycle, resources, local network, and storage volumes, and is equivalent to a Kubernetes pod. 
    Container groups can be deployed to a subnet that already hosts a container group or an empty one, but it may not be deployed to a subnet that already has other resources like VMs.

**Azure Data Explorer**{: #adx }
:   **Azure Data Explorer (ADX)** has two architectural elements:

    - **Data Management**
    - **Engine**

ADX does not hold large tables in a single table, rather it automatically shards them into **Extents**

**Azure DevOps**{: #azure-devops }
:   Azure DevOps used to be known as **Visual Studio Team Services** and **Team Foundation Server**.

    Install DevOps CLI
    ```sh
    az extension add --name azure-devops
    ```

**Azure DNS**{: #azure-dns }
:   **Azure DNS** supports private zones, which provide name resolution for VMs on a VNet and between VNets without having to create a custom DNS solution.

    Time-to-live for DNS record sets is provided in seconds.

    Azure DNS **alias records** allow other Azure resources to be referenced from the DNS zone, rather than static IP addresses or domain names. 
    This allows these records to be automatically updated or deleted when the underlying Azure resource is changed.

    - An **A alias record set** is a special type of record set that allows you to create an alternative name for a record set in your domain zone or for resources in your subscription.
    - A **CNAME alias record set** can only point to another CNAME record set. Custom domains can be used by implementing **CNAME** DNS records, which are used in DNS to map alias domain names to the "canonical" name.

**Azure File Service**{: #azure-file-service }
:   **Azure File Service** allows you to create one or more file shares in the cloud (up to 5 TB per share), similar to a regular Windows File Server. 
    It supports the SMB protocol, so you can connect directly to a file share from outside of Azure, if traffic to port 445 is allowed through the LAN and ISP. It can also be mapped within Windows.

    A clever use of a file share is as persistent storage for the Azure Cloud Shell. [src](https://portal.cloudskills.io/products/azure-administrator-az-104-exam-prep-course/categories/2692678/posts/8980122 "Configure Azure Files and Azure Blob Storage 32:00")

**Azure File Sync**{: #azure-file-sync }
:   **Azure File Sync** extends Azure File Service to allow on-premises file services to be extended to Azure while maintaining performance and compatibility, communicating over TCP 443 over SSL, and **not** IPSec. 

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

**Azure Policy**{: #azure-policy }
:   **Azure Policy** is a service that can create, assign, and manage policies to enforce governance. Policy definitions, authored in JSON, implement policy by describing desired behavior for Azure resources when they are created or updated. <sup>AZ-103: p. 72</sup>

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

**Azure VMs**{: #azure-vms }
:   **Virtual Machines** represent Azure's IaaS offering.

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

**Azure VPN**{: #azure-vpn }
:   **Virtual network gateways** in Azure are of two types: **VPN gateways** and **ExpressRoute gateways**.
    Any virtual network can have only a single gateway of each type.

    **VPN gateways** send encrypted traffic between the virtual network and an on-premises location. VPN Gateways must be deployed into their own dedicated subnet (named **"GatewaySubnet"**) with a minimum size of CIDR /29, although a CIDR /27 address block is recommended. VPN connections between an on-premises network and a VNet are only possible if the network ranges do not overlap.

    VPN gateways can be classified by the topology of the connection:

    - [**Site-to-Site (S2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#S2S) connections require an on-premises **VPN device** associated with a public IP address.
    - [**Multi-Site**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#Multi) connections require a **RouteBased** VPN type. 
    - [**Point-to-Site (P2S)**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#P2S) allows individual computers to securely connect to a VNet without need for a VPN device, which is useful for telecommuting, and can use SSTP, OpenVPN, or IKEv2. There are several [authentication](#authentication) considerations.
    - [**VNet-to-VNet**](https://docs.microsoft.com/en-us/azure/vpn-gateway/design#V2V) connections are also possible, but VNet [peering](VNet#peering) may be preferable if the virtual networks meet certain requirements.

    === "Site-to-Site"

        ![](./img/vpngateway-site-to-site-connection-diagram.png)

    === "Multi-Site"

        ![](./img/vpngateway-multisite-connection-diagram.png)

    === "Point-to-Site"

        ![](./img/point-to-site.png)

    === "VNet-to-VNet"

        ![](./img/vpngateway-vnet-to-vnet-connection-diagram.png)

    VPN gateways can also be classified on [VPN type](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#vpntype). 

    - **Route-based VPNs** (previously called "dynamic routing gateways") require routes to be defined in a routing table to direct packets into tunnel interfaces.
    - **Policy-based VPNs** (previously called "static routing gateways" in the classic deployment model) can only be used on the Basic gateway SKU and offer only a single S2S tunnel.

    === "Route-based"

        ![](./img/routebasedmultisite.png)

    === "Policy-based"

        ![](./img/policybasedmultisite.png)

    There is a profusion of [Gateway SKUs](https://docs.microsoft.com/en-us/azure/vpn-gateway/vpn-gateway-about-vpn-gateway-settings#gwsku) that determine the maximum connections, throughput, and availability of other features like BGP and zone-redundancy available for each topology.

    Every Azure VPN gateway consists of two instances in an active-standby configuration. During failover, a brief interruption of 10-15 seconds for planned maintenance or up to 60-90 seconds in the case of unplanned disruption, may occur.
    But the gateway can be configured to be **active-active**, which will establish S2S VPN tunnels to both gateway instances with traffic being routed through both tunnels simultaneously. There will still be only a single connection resource, but the on-premises VPN device must be configured to establish both of these tunnels.
    The most highly available arrangement would use multiple VPN devices with the VPN gateway in active-active configuration, creating 4 IPsec tunnels that evenly carry Azure traffic. 

    === "Active-Standby"

        ![](./img/active-standby.png)

    === "Active-Active"

        ![](./img/active-active.png)

    === "Dual redundancy"

        ![](./img/dual-redundancy.png)

**Bigquery**{: #bigquery }
: Petabyte-scale analytics database service for data warehousing. BigQuery can be executed using the [**bq**][bq] command-line utility.

**BigTable**{: #bigtable }
:   GCP realtime database used for Big Data. BigTable can be executed using the [**cbt**][cbt] command-line utility.
    BigTable evolved out of Google's need to ensure access to petabytes of data in its web search business line.
    It was described in a 2006 research paper that ended up launching the entire NoSQL industry.
    In 2015 it was made available as a service to cloud customers. [src](https://www.youtube.com/watch?v=1qieV-WCU_w "YouTube - Introduction to Google BigTable: Best Uses, Design, and Demo")

    BigTable doesn't support secondary indexes. 

**Billing Account Administrator**{: #Billing Account Administrator }
: GCP predefined role that grants permissions to manage self-service accounts but not to create new ones.

**Billing Account Creator**{: #billing-account-creator }
: Predefined GCP role that grants permissions to create new self-service accounts.

**Billing Account User**{: #billing-account-user }
: GCP predefined role that enables user to link projects to a billing account.

**Billing Account Viewer**{: #billing-account-viewer }
: GCP predefined role that grants permissions to view transactional and billing data associated to a GCP account.

**Cloud AutoML**{: #cloud-automl }
: GCP service that allows developers without machine learning experience to develop machine learning models.

**Cloud Device Administrator**{: #cloud-device-administrator} [:material-microsoft:](https://docs.microsoft.com/en-us/azure/active-directory/roles/permissions-reference#cloud-device-administrator-permissions): 
:   Azure built-in role that grants users full access to manage devices in Azure AD. 

**Cloud Functions**{: #cloud-functions }
: GCP serverless compute offering suited to running short-running logic, such as calling other APIs in response to an event.

**Cloud IAM**{: #cloud-iam}
:   GCP's identity and access management platform.

    Permissions include:

    - roles/container.admin
    - roles/container.clusterAdmin
    - roles/container.clusterViewer
    - roles/container.developer
    - roles/container.hostServiceAgentUser

    Predefined roles include:

    - [App Engine Deployer](#app-engine-deployer)
    - [App Engine Service Admin](#app-engine-service-admin)
    - [Billing Account Administrator][Billing Account Administrator]
    - [Billing Account Creator][Billing Account Creator]
    - [Billing Account User][Billing Account User]
    - [Billing Account Viewer][Billing Account Viewer]
    - [Compute Engine Admin][Compute Engine Admin]
    - [Compute Engine Network Admin][Compute Engine Network Admin]
    - [Compute Engine Security Admin][Compute Engine Security Admin]
    - [Compute Engine Viewer][Compute Engine Viewer]
    - [Compute Service Agent][Compute Service Agent]
    - [Folder Admin][Folder Admin]
    - [Project Creator][Project Creator]
    - Shared VPC Admin

**Cloud Machine Learning Engine**{: #cloud-machine-learning-engine }
: Platform for building and deploying scalable machine learning systems to production.

**Cloud Natural Language Processing**{: #cloud-natural-language-processing }
: GCP tool for analyzing human languages and extracting information from text.

**Cloud Run**{: #cloud-run }
:   **Google Cloud Run** is built on a native open standard that will allow using the same container on other cloud providers.
    It bills down to the nearest 100 ms interval.
    Cloud Run provides an HTTPS endpoint to the container.

    Cloud Run can also run on your own K8S cluster running on [GKE][GKE], recommended for workloads that have a consistently high level of traffic, since you are billed for the provisioned cluster resources.
    However, resources like CPU, GPU, and other items can be customized.

**Cloud Vision**{: #cloud-vision }
: Image analysis platform for annotating images with metadata, extracting text, or filtering content.

**CloudFormation**{: #cloudformation }
:   AWS declarative automation service, which can use JSON or YAML-format templates.
    These resources are placed into a named **stack**, a container that organizes the resources described by the template, and the stack name must be unique to the account.
    This allows provisioned resources to be easily managed, since the stack contains a record of events, and to be quickly destroyed by deleting the stack.

    CloudFormation Designer allows templates to be viewed as a diagram of resources.

**CloudFront**{: #cloudfront }
:   AWS CDN offering that helps deliver static and dynamic content worldwide.
    CloudFront caches content in **edge locations**, of which there are more than 150 spread out across 6 continents.
    Edge locations may not be chosen arbitrarily, rather there are three options:

    - US, Canada, and Europe
    - US, Canada, Europe, Asia, and Africa
    - All edge locations

    In order to make content available on CloudFront, you must create a **distribution**, which defines the type and origin of the content to cache.
    There are two types of distribution:

    - A **Web distribution** is used for static and dynamic content, including streaming video, accessible via HTTP or HTTPS. Its origin can be a web server or a **public** S3 bucket.
    - **Real-Time Messaging Protocol (RTMP) distribution** delivers streaming audio or video. The media player and media files must be stored in S3 buckets.

**CloudTrail**{: #cloudtrail }
:    AWS service that logs actions against AWS resources. These events are divided into API and non-API actions.

    - **API actions** include creating, modifying, or deleting resources.
    - **Non-API actions** include everything else, like logging into the management console.

    Events are also classified as management events and data events

    - **Management events** (also **control plane operations**) are operations that a principal attempts to execute against an AWS resource.
    - **Data events** are S3 object-level activity and Lambda function executions. These are treated separately from management events because they tend to be higher volume.

**CloudWatch**{: #cloudwatch }
:   **Amazon CloudWatch** collects logs, metrics, and events from AWS resources and non-AWS on-premises servers and presents a dashboard for visual analysis.
    All AWS resources automatically send their metrics to CloudWatch Metrics, which stores the data for up to 15 months.
    CloudWatch alarms can be configured for single metrics.

    Applications and AWS services have to be configured to send log events to CloudWatch Logs, and they are stored indefinitely by default although retention settings can be configured.
    Log events from the same source are organized into a log stream. Log streams are then organized into log groups.
    **Metric filters** extract metric data from log events.

    CloudWatch Events is a feature that monitors for changes in AWS resources as a result of API operations.


**Cloudyn**{: #cloudyn }
: Previously a standalone service available in Azure, now deprecated because its functionality has been incorporated natively into other sections of the **Cost Management + Billing** blade.

**CodeCommit**{: #codecommit }
: AWS private git repo service.

**CodeDeploy**{: #codedeploy }
:   AWS service for automatically deploying applications to AWS compute resources or on-prem servers.
    CodeDeploy can pull source code from [S3][S3] and repos from GitHub or Bitbucket but notably **not** [CodeCommit][CodeCommit] (ref. [CodePipeline][CodePipeline]).

**CodePipeline**{: #codepipeline }
:   AWS service for orchestrating and automating every stage of software development.
    It defines a series of stages, two of which are required - **source** and **deployment** - but other stages like testing or approval can be incorporated.

**Cognito**{: #cognito }
: AWS service that integrates with identity providers like Amazon, Google, Microsoft, and Facebook to add user access control to an application.

**Compute Engine**{: #compute-engine }
:   **Compute Engine** is GCP's IaaS offering.
    An **instance group** is a collection of VM instances that you can manage as a single entity. 

    Two types:

    - **Managed** instance groups operate applications like web front-ends across a group of identical VMs created with a template.
    They provide high availability, healing, scaling, and automatic updates.
    - **Unmanaged** instance groups allow you to manually load balance a group of VMs.
    VMs can be added or removed at will.

    - :octicons-play-24: [Getting started with GCE](https://youtu.be/1XH0gLlGDdk "YouTube - Getting Started with Google Cloud Compute Engine")

**Compute Engine Admin**{: #compute-engine-admin }
: Predefined GCP role that grants full control of Compute Engine resources.

**Compute Engine Network Admin**{: #compute-engine-network-admin }
: Predefined GCP role that grants full control of Compute Engine networking resources.

**Compute Engine Security Admin**{: #compute-engine-security-admin }
: Predefined GCP role that grants full control of Compute Engine security resources.

**Compute Engine Viewer**{: #compute-engine-viewer }
: Predefined GCP role that grans read-only access to all Compute Engine resources, but exclusive of data stored on disks, images, and snapshots.

**Compute Service Agent**{: #compute-service-agent }
: Predefined GCP role that grants Compute Engine Service Account access to assert service account authority.

**Computer Vision**{: #computer-vision }
: subfield of artificial intelligence concerned with developing the capability of computers to recognize objects in images and to understand visual information.

**Container Instances**{: #container-instances }
:   **Azure Container Instances (ACI)** is a PaaS service that facilitates deployment of individual containers.

**CosmosDB**{: #cosmosdb }
:   Azure NoSQL offering.
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

**Consistency**{: #consistency }
:   Uniformity of data across replicas in a distributed database.

    **Consistency levels** [:material-microsoft:](https://aka.ms/cosmos-consistency-levels "Consistency levels in Azure Cosmos DB") describe how and when data is replicated to provide varying consistency guarantees.

    - **Strong consistency** is the strongest consistency model and requires synchronous replication after every change to database, increasing latency for each write.
    - **Session consistency** is unique, in that it offers consistent prefix to databases that support a single session or an application with a single token. 
    - **Eventual consistency** is the weakest consistency model and provides no ordering guarantees.
    **Consistent prefix** offers read throughput, availability, and write latency comparable to eventual consistency while guaranteeing global order.
    - **Bounded staleness** implies asynchronous replication and offers guarantees on the number of versions (**K**) or time interval (**T**) reads lag behind writes, referred to as the **staleness window**. 
    As the staleness window approaches, Azure will delay writes by providing *back pressure* on writes. 
        - Outside the staleness window, data is guaranteed to be globally consistent. 
        - Outside the region in which the writes were made, Azure guarantees *total global order* or *consistent prefix*, which means, the global order is maintained.

    === "Strong"

        ![](./img/strong-consistency.gif)


    === "Session"


        ![](./img/session-consistency.gif)


    === "Eventual"

        ![](./img/eventual-consistency.gif)


    === "Bounded staleness"

        ![](./img/bounded-staleness-consistency.gif)

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

**Cost Management Contributor**{: #cost-management-contributor }
: Azure built-in role that grants access to the **Cost Management** blade.

**Cost Management Reader**{: #cost-management-reader }
: Azure built-in role that grants access to the **Cost Management** blade.

**Data Box**{: #data-box }
: Microsoft-provided appliance that allows for the transfer of large volumes of data to Azure, available only to [EA](#ea), CSP, and Microsoft Partner Network Sponsorship offer types.

    Workflow

    1. Order: Use Portal to order a data box by creating a Data Box resource
    2. Receive: Connect Data Box to network
    3. Copy data: Mount file shares and copy data to the device.
    4. Return: to Microsoft
    5. Upload: Microsoft will upload the data and securely erase it from the device

    | Offering       | Capacity | Storage saccounts |
    | -------------- | -------: | ----------------: |
    | Data Box Disk  |    35 TB |                 1 |
    | Data Box       |   100 TB |                10 |
    | Data Box Heavy | 1,000 TB |                10 |

**Dataflow**{: #dataflow }
: GCP streaming data framework for defining both batch and stream processing pipelines.

**Dataprep**{: #dataprep }
: GCP managed service that allows analysts to visually explore, clean, and prepare data for later analysis.

**Dataproc**{: #dataproc }
: GCP service that manages the creation of data science clusters and data analysis jobs.

**DynamoDB**{: #dynamodb }: NoSQL database known for fast (1-9 ms) query times. 
:   DynamoDB measures capacity in **Read Capacity Units (RCU)** and **Write Capacity Units (WCU)**.

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

**Elastic Container Service**{: #ecs }

**Elastic Kubernetes Service**{: #eks }

**Elastic Beanstalk**{: #elastic-beanstalk }:  AWS PaaS offering.

**Elastic File System**{: #efs }: Scalable file system for AWS Linux instances that allows multiple instances to be attached to a single EFS volume to share files.
:   EFS volumes are highly available, spanning multiple Availability Zones in a single VPC.

**Elastic MapReduce**{: #emr }: AWS's managed Big Data analysis service, supporting Apache Hadoop, Apache Spark, HBase, Presto, and Flink.

**Enterprise Agreement**{: #ea }
:   Azure customers on an **Enterprise Agreement** can add up-front commitments to Azure then be billed annually. 
    If the committed spend is exceeded, the overage is billed at the same EA rate. 
    EA customers can create spending quotas and set notification thresholds through the EA Portal.

    3 portals used to manage Azure subscriptions

    1. EA Portal (ea.azure.com) available only to customers with an Enterprise Agreement
    2. Account Portal
    3. Azure Portal, includes Azure Cost Management

**ExpressRoute**{: #expressroute }
:   There are four main architectures used with ExpressRoute

- **Any-to-any connection** is used to integrate on-premises WANs using IPVPN.
- **Co-location with cloud exchange** is used to order virtual cross-connections to the Azure cloud through the co-location provider's Ethernet exchange.
- **Point-to-point Ethernet connection** is used to configure on-premises data center connectivity to Azure through individual point-to-point links

**Firebase**{: #firebase }: GCP NoSQL database offering known for its client libraries.
:   Firebase Auth offers a free user interface for applications, **Firebase UI**.


**Firestore**{: #firestore } was released from beta in early 2019 and combines and improves upon functionality of previous products named **Cloud Datastore** and **Firebase Realtime Database**. 
:   Firestore is organized into **documents**, which consist of key-value pairs and are similar to JSON objects, and **collections**. 
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

**Folder Admin**{: #folder-admin }: Predefined GCP role that allows folders to be created at an Organization.

**Front Door**{: #front-door }: Azure offering that works like [Azure Load Balancer](Azure-Load-Balancer) for web apps.

**Glacier**{: #glacier }: AWS storage service that offers long-term archival at low cost.
:   One or more files are stored in an archive, typically a .zip or .tar file containing multiple files.
    Archives can range from 1 B to 40 TB in size.

    Archives are stored in a Glacier **vault**, a region-specific container analogous to S3 buckets.
    Vaults must have regionally unique names, but there is no need for a globally unique name.

    Glacier vaults can be created and deleted using the Glacier service console.
    But uploading, downloading, or deleting archives must be done through the [AWS CLI](#aws-cli) or an application using the SDK.
    Some third-party applications can also interact with Glacier.

**Google Cloud Identity**{: #google-cloud-identity }
: Google's IDaaS provider.

#### GKE

![](/Cloud/img/gke-512-color.png){ align=left width=120px }

Clusters have two [modes](https://cloud.google.com/kubernetes-engine/docs/concepts/types-of-clusters#modes) of operation, **Standard** and [**Autopilot** <sup>:material-google:</sup>](https://cloud.google.com/kubernetes-engine/docs/concepts/autopilot-overview), that offer a more configurable and a more managed experience respectively.

In GKE, clusters are billed at a flat fee of [**$0.10 per cluster hour** <sup>:material-google:</sup>](https://cloud.google.com/kubernetes-engine/pricing#cluster_management_fee_and_free_tier). 
The GKE free tier provides $74.40 in monthly credits per billing account, available to Autopilot and Standard zonal clusters but **not** [Standard regional <sup>:material-google:</sup>](https://cloud.google.com/kubernetes-engine/docs/concepts/types-of-clusters#regional_clusters) clusters.
Note that there are 744 hours in a 31-day month, and the free tier monthly credit corresponds to exactly this amount of usage for a single cluster.



**Import/Export Service**{: #import-export-service }
:   Azure service that allows the physical shipment of disks procured by the user to Azure for import into a [storage account <sup>:material-file-document-edit-outline:</sup>](#storage-account), which can be placed into blob or file storage.
    This service requires the use of a Windows computer with BitLocker and .NET Framework and is dependent on the [WAImportExport.exe <sup>:material-file-document-edit-outline:</sup>](#waimportexport) utility.

    1. Procure 2.5-inch or 3.5-inch SATA (not SAS) disks
    2. Connect the disks to a Windows machine.
    3. Create a volume and encrypt it using BitLocker
    4. Install the [**Azure Import/Export tool** (WAImportExport.exe)](#waimportexport) on the disks. 
    5. Copy files
    6. Create an **import job** in the Azure Portal

**Kinesis**{: #kinesis }
: AWS service for ingestion and processing of streaming data, such as access logs, video, audio, and telemetry.

**Kubeflow**{: #kubeflow }
: Cloud-native platform for machine learning based on Google’s internal machine learning pipelines.

#### [Kusto <sup>:material-file-document-edit-outline:</sup>](Kusto)
Case-sensitive query language developed by Microsoft and used in several Azure services:

- [Azure Data Explorer <sup>:material-file-document-edit-outline:</sup>](#azure-data-explorer)
- [Log Analytics <sup>:material-file-document-edit-outline:</sup>](#log-analytics)
- [Sentinel <sup>:material-file-document-edit-outline:</sup>](#sentinel)
- [Application Insights <sup>:material-file-document-edit-outline:</sup>](#application-insights)
- Microsoft Defender ATP


**Lightsail**{: #lightsail }
: offers blueprints that will automatically provision all compute, storage, database, and network resources needed for a deployment.

**Macie**{: #macie }
: AWS service that automatically finds and classifies sensitive data stored in AWS using machine learning to recognize sensitive data such as PII or trade secrets.

**Microsoft Azure Recovery Services**{: #mars }
:   Azure agent for [backing up](#backups) Windows machines only, but can also be installed on instances of other cloud providers like AWS.
    MARS can be configured to protect the entire system, volumes, or individual files and folders.

**Monitor**{: #monitor }

**Neptune**{: #neptune }
: AWS graph database.

**Network Performance Monitor**{: #npm }
:   Azure [Log Analytics](#log-analytics) network monitoring solution for hybrid networks, providing 3 services:
    - [**Performance Monitor**](#performance-monitor) monitors connectivity between various points in both Azure and on-prem networks
    - [**Service Connectivity Monitor**](#service-connectivity-monitor) monitors outbound connectivity from network nodes to external TCP services, monitoring performance metrics like latency, response time, and packet loss
    - [**ExpressRoute**](#expressroute) monitors end-to-end connectivity between on-prem network and Azure over ExpressRoute


**Network Watcher**{: #network-watcher }
:   **Network Watcher** appears like a normal resource in a resource group, but it is deployed as a single instance per Azure region.

Network Watcher monitoring and diagnostic tools:

- [IP Flow Verify](Task-Network-Watcher#ip-flow-verify)
- [Next Hop](Task-Network-Watcher#next-hop)
- [Packet Captures](Task-Network-Watcher#packet-capture) link a Network Watcher resource, a target VM, a storage account, and a filter that specifies the characteristics of network traffic (source and destination IP addresses and ports as well as protocol) to capture, as well as a time limit.
- [Network Topology](Task-Network-Watcher#network-topology)

**OpsWorks**{: #opsworks }
:   **OpsWorks** is AWS's **declarative** configuration management service that uses the Chef and Puppet configuration management platforms and comes in three varieties:

    - **OpsWorks for Puppet Enterprise**
    - **OpsWorks for Chef Automate**
    - **OpsWorks Stacks**

**Project**{: #project }
: direct parent of all other GCP resources, consisting of a project name, project ID, and project number.

**Project Creator**{: #project-creator }
: Predefined GCP role given to all users currently assigned to a project.

**Pub/Sub**{: #pub-sub }
: GCP messaging service, allowing services and applications to communicate.

**Recovery Services Vault**{: #Recovery Services Vault }
:   Azure resource used to centrally manage the backup and recovery.

    - A **Backup  protection policy** defines how a backup plan is implemented. These are most easily created through the Portal.
    - A vault can only back up data from other resources that exist in its region.

**Rekognition**{: #rekognition }
:   AWS deep learning-based image recognition service.

**Resource Policy Contributor**{: #resource-policy-contributor }
:   Azure built-in role that includes access to most Policy operations and should be considered privileged.

**Route 53**{: #route-53 }
:   AWS managed DNS service.
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


**Simple Storage Service**{: #s3 }
:   AWS storage service.
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

    :octicons-play-24: [Cloud Storage in Minutes with AWS Storage Gateway](https://youtu.be/2I4CKdNESoQ)

**Sentinel**{: #sentinel }
:   Azure cloud-native SIEM and SOAR soluation that can collect data from many sources and present it to security analysts, who can run [Kusto](Kusto) queries against the dataset.
    Azure Sentinel can ingest data from on-premises devices using one of several types of **connector**, categorized by the type of data ingestion:

    - **Native connectors** integrate directly with other Microsoft security products, like Azure AD, M365, and Azure Security Center
    - **Direct connectors** are configured from their source location, such as AWS CloudTrail, Azure Firewall, and Azure Front Door 
    - **API connectors** are implemented by security providers, like Azure Information Protection (AIP), Barracuda Web Application Firewall (WAF), and Microsoft WAF
    - **Agent-based connectors**, using the Log Analytics agent, make it possible to ingest data from any source that can stream logs in Common Event Format (CEF), such as Windows and Linux machines.

    **Analytic rules** are rules that users create to help detect threats and anomalies in an environment:

    - Scheduled rules run on a predetermined schedule
    - Microsoft Security
    - Machine learning behavior analytic rules can (currently) only be created from templates provided by Microsoft using proprietary ML algorithms

**Simple Queue Service**{: #sqs }
:   AWS service that can broker messages between components of highly decoupled applications.

**Snowball**{: #snowball }
:   Physical appliance designed to move large amounts of data to the cloud.
    The largest Snowball device can store 72 TB of information.

    **Snowball Edge** refers to a family of options similar to Snowball but with compute power to run EC2 instances and Lambda functions locally.
    All Snowball Edge options feature a QSFP+ network interface that is capable of speeds up to 100 Gbps.
    Snowball Edge devices can also be clustered together.

    - **Storage Optimized** provides up to 80 TB of storage and 24 vCPUs.
    - **Compute Optimized** provides up to 39.5 TB of storage and 52 vCPUs.
    - **Compute Optimized with GPU** is similar to Compute Optimized but includes an NVIDIA GPU, making it useful for ML and HPC applications.

**Spanner**{: #spanner }
: GCP managed scaleable database service.

**Stackdriver**{: #stackdriver }
: GCP service that collects metrics, logs, and event data from applications and infrastructure and integrates the data so DevOps engineers can monitor, assess, and diagnose operational problems.

**Super administrator**{: #super-administrator }
: Unique GCP role associated with the root Organization which has powers that exceed that of other administrative users.

**Storage accounts**{: #storage-accounts }
:   Azure storage accounts are managed through [Azure Resource Manager][ARM] and management operations are authenticated and authorized using [Azure Active Directory][Azure AD]. 

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

    Because storage account keys provide write access, a storage account with a **ReadOnly** resource lock will not enumerate its storage account keys, and users with Read permission will not be able to retrieve the keys either.

**Systems Manager**{: #systems-manager }
:   AWS service for imperative configuration management.
    Systems Manager relies on several types of script:

    - **Command documents** use normal shell commands and can be run periodically or on a trigger, so long as the instance to be managed has the required agent.
    - **Automation documents** allow administration of AWS resources, similar in effect to using the Management Console or the [AWS CLI](#aws-cli).


**Trusted Advisor**{: #trusted-advisor }
:   AWS service allows a visual check of resource configurations to ensure compliance with best practices, available only to Business and Enterprise Support plans. 
    It offers several categories

    - Cost optimization
    - Performance
    - Security
    - Fault tolerance
    - Service limits

**User Access Administrator**{: #user-access-administrator  }
:   Azure built-in role that grants the permissions necessary to assign a user administrative access at the subscription scope.

    Permissions:

    - `Microsoft.Authorization/roleAssignments/write`
    - `Microsoft.Authorization/roleAssignments/delete`

**User Administrator**{: #user-administrator } [:material-microsoft:](https://docs.microsoft.com/en-us/azure/active-directory/roles/permissions-reference#user-administrator-permissions)
:   Azure built-in role that grants the power to manage all aspects of users and groups, including resetting passwords for limited admins.

**VM Agent**{: #vm-agent }
:   **Microsoft Azure Virtual Machine Agent (VM Agent)** manages VM interaction with the Azure Fabric Controller and comes preinstalled with Windows images from the Marketplace. 
    It can also be [installed](https://docs.microsoft.com/en-us/azure/virtual-machines/extensions/agent-windows) on a custom image.

    VM Agent supports the [VMSnapshot][VMSnapshot] extension, which is added when backups are enabled. 
    This extension takes a snapshot of the storage at the block level and sends it to the RSV configured. 
    For Windows VMs, this extension leverable the [Volume Shadow Copy][Volume Shadow Copy] service.

**Microsoft Azure Linux Agent**{: #waagent } 
:   Azure agent that manages VM interaction with the Azure Fabric Controller on Linux VMs.

**WAImportExport.exe**{: #waimportexport }
:   CLI tool associated with [Azure Import/Export service](#import-export-service) that requires a Windows computer with .NET Framework and BitLocker. 
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

**WebJobs**{: #webjobs }
:   a feature of [Azure App Service](#app-service) that enables you to run a program or script in the same instance as a web app, API app, or mobile app, at no additional cost and supported **only on Windows App Service plans**. 
    There are two types:

    - **Continuous** webjobs default to running on all instances of the linked web app (although it can be configured to run on only one)
    - **Triggered** webjobs run only when triggered or on a schedule and on only a single instance of the linked web app selected by Azure.
