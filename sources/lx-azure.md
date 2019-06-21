# Five Principles for Deploying and Managing Linux in the Cloud (With Azure)

Term                                              | Definition | Source
---                                               | ---        | ---
Amazon CloudWatch                                 |             | 
Availability Zones                                | term used in AWS and Azure to refer to redundant, geographically dispersed computing resources | 5PLC: 19
Availability set                                  | Azure capability that groups VMs to ensure they are distributed across multiple hardware clusters, isolated from each other | 5PLC: 42
Azure Application Gateway                         | Layer 7 load balancer that protects web applications against well-known web exploits | 5PLC: 43
Azure Container Instances (ACI)                   | for running Docker containers on Azure VMs | 5PLC: 23
Azure Container Registry (ACR)                    | for storing and managing container images | 5PLC: 23
Azure Container Service                           | Azure feature that offers Jenkins and Kubernetes | 5PLC: 21
Azure Data Migration Assistant (Azure DMA)        | Microsoft tools to help with database discovery and assessment, can create migration workflows to move database schemas, data, users, roles, and SQL logins; cf. __Azure DMS__ | 5PLC: 36
Azure Database Migration Service (Azure DMS)      | specialized tool for migrating data during cloud deployment, migrates on-premise Oracle, MySQL, and SQL Server databases to an Azure managed database in the cloud or to an on-premises database running in an Azure VM | 5PLC: 32
Azure Kubernetes Service (AKS)                    | Linux-based service offered by Azure to orchestrate containers using Kubernetes, DC/OS, or Docker | 5PLC: 22
Azure Migrate Service                             | tool explicitly development for supporting cloud migration | 5PLC: 32-36
Azure Security Center                             | scans Azure cloud resources for vulnerabilities, such as web apps not protected by __WAF__
Azure Service Fabric                              | like __Azure Container Service__, can be used to develop microservices and orchestrate containers on Linux | 5PLC: 23
Azure Site Recovery                               | tool used to move Azure-compatible Linux VMs of any distribution | 5PLC: 38
Azure Virtual Machine Scale Sets (VMSSs)          |             | 
Brigade                                           | event-driven scripting tool for Kubernetes offered by Microsoft
cloud provisioning                                | computing model that remotely provisions scalable and measured computing resources and services | [5PLC](file-lx-azure.md): 9
cloud storage device                              | mechanisms which implement the interfaces to __object storage__, accessed via REST or web services | 5PLC: 17
Draft                                             | Microsoft tool that makes it easy to develop container-based applications and to deploy them to Kubernetes clusters | 5PLC: 24
dynamic scalability                               | ability of a cloud provider to transparently scale computing resources in response to the runtime conditions of a user's environment | 5PLC: 19
elasciticy                                        | cf. __dynamic scalability__
extract, transform, and load (ETL)                | type of job used with containers | 5PLC: 20
Google Stackdriver                                |             | 
Helm                                              | open-source packaging tool used to install, deploy, and manage containers in a Kubernetes cluster, manage Kubernetes charts (packages of preconfigured Kubernetes resources) | 5PLC: 23
hybrid cloud                                      | two or more cloud deployment models, where private and public clouds share data and applications and data flows freely between them | [5PLC](file-lx-azure.md): 14 
Identity and Access Management (IAM)              | 
Infrastructure as a Service (IaaS)                | cloud provider supplies the IT infrastructure (servers, strorage, and networks) which is paid for based on usage, providing the client with a high degree of control over the cloud environment | [5PLC](file-lx-azure.md): 12
load balancing                                    | manner by which a cloud provider manages online traffic by distributing workloads across many servers and computing resources | 5PLC: 19
Microservices                                     | small, self-contained applications that perform single tasks or run single processes; spreading incoming requests across multiple VMs; two types | 5PLC: 20, 43
Microsoft Azure Monitor                           |             | 
Microsoft Web Application Firewall (WAF)          | feature of __Azure Application Gateway__
object storage                                    | various types of resources are stored as web resources | 5PLC: 17
Platform as a Service (PaaS)                      | computing model in which the cloud provider provisions and manages all the computing infrastructure (servers, networks, and databases), providing a ready-to-use computing environment | [5PLC](file-lx-azure.md): 13
public cloud                                      | cloud accessed over the public internet, run by a third-party cloud provider, such as Azure, AWS, or GCP | [5PLC](file-lx-azure.md): 14 
private cloud                                     | cloud run on an on-site datacenter, or hosted by a third-party service but owned by the client itself | [5PLC](file-lx-azure.md): 14 
resource                                          | physical or virtual server, software programs, services, storage, or network devices | [5PLC](file-lx-azure.md): 9
resource replication                              | creation of multiple instances of the same computing resource | 5PLC: 17
resource pooling                                  | method by which a cloud provider can provide commoditized computing resources, whereby a large amount of computing resources services many clients | 5PLC: 18
SOAP                                              | messaging format relied upon for web services | [5PLC](file-lx-azure.md): 17 
Software as a Service (SaaS)                      | cloud provider delivers software applications on demand over the Internet, managing not only the infrastructure but also the software applications themselves | [5PLC](file-lx-azure.md): 13
Universal Description, Discovery, and Integration (UDDI) | standard for regulating service registries where WSDL definitions can be publish | [5PLC](file-lx-azure.md): 17 
Virtual Machine Scale Set (VMSS)                  | create and manage a group of identical load-balanced VMs, the number of which automatically increases or decreases
Virtual Private Cloud (VPC)                       | VPN-like service offered by Azure
virtualization                                    | process of converting a physical IT resource into (multiple) virtual resources | [5PLC](file-lx-azure.md): 15
Web Service Description Language (WSDL)           | markup language used for API of a web service

## Introduction
Benefits of cloud computing
  - _Agility_: qickly implement a cloud ienvironment (vice setting up hardware)
  - _Pay-for-use_ billing model
  - _Lower cost_: lesser capital expense of buying hardware and other components required for a datacenter
  - _Elasticity_: ability to quickly ramp up and down computing capacity
  - _Reliability_: built-in reseiliency measures in the form of multiple, geographically separate backups
  - _Security_: responsibility is shared between application security (client) and infrastructure security (provider)
  - _Performance_: cloud provider can offer the latest in computing hardware and lower network latency

Types of cloud services:
  - _IaaS_
  - _PaaS_
  - _SaaS_

Types of cloud deployments
  - _Public cloud_
  - _Private cloud_
  - _Hybrid cloud_

Features common to cloud computing providers:
  - _On-demand_ usage of resources: clients are free to provision any resources at any time
  - _Measured usage_: billing is based on usage
  - _Resource pooling_ 
  - _Elasticity_
  - _Resiliency_: redundant computing resources are located in different geographical areas
  - _Load balancing_

Use cases for containers:
  - Microservices
  - Batch and __ETL__ jobs
  - CI/CD

## Principle 1: Understand which Linux VMs are adaptable to the cloud

Concerns addressed by a well-built cloud adoption roadmap
  - _Benefits_ of migrating to the cloud
  - _What_ to move to the cloud
  - _Technology_ to be chosen
  - _Method_ of optimizing

Elements of a cloud-readiness assessment
  - Shareholder interviews

Strategies for cloud migration
  1. _Lift and shift_: entire current software stack is migrated
  2. _Architect applications before migration_: software is redesigned to take advantage of cloud features. This is more risky because you are planning an infrastructure migration at the same time as an application upgrade.

Tasks to be performed for cloud migration
- Pre-deployment tasks
  - _Understanding the scope of the migration_: correct cloud assessment
  - _Creating the cloud architectures_: select types of cloud services to be adopted
  - _Setting up cloud accounts_: IAM, then creation of users and groups, specifying access to specific resources
- Migration tasks
  - _Setting up networks_: set up a VPN to allow connection between organization and cloud. 
  - _Create computing infrastructure_: VMs, databases, and analytical services
  - _Deploying applications and databases_: migrate data using nnative database tools (export/import or SQL dumps) or specialized database migration tools (i.e. Azure Database Migration Service)
  - _Planning the cutover to the cloud_: after deployment, on-premise databases and cloud databases need to be synchronized
    - Performance testing: stress testing new systems and benchmarking execution
    - Security assessment: vulnerability assessments and penetration tests
- Go-Live Tasks

#### Azure Migrate Service
Performs dependency mapping and supports the successful migration of multitier applications. Assists in the following ways:
  - _Assesses your readiness for the Azure cloud_
  - _Recommends the best sizes for your cloud VMs_ along with a confidence rating on a scale of 1-5 stars
  - _Estimates monthly costs_

### Key phases of cloud migration
  - Discovery phase
  - Migration phase
  - Optimization phase

#### Discovery
Key questions:
  - What is the nature of the current environment?
  - Will the application or workload run properly on the cloud provider's environment?
  - What is the cost of running the current computing environment?

Database migration procedure using Azure DMA
  1. Create target database in Azure
  2. Migrate database schemas using Azure DMA
  3. Create an instance of Azure DMS
  4. Create a migration project by specifying the source and target databases, and the tables, to be migrated
  5. Initiate the target database load (full load)
  6. Manually switch over the production environment to the Azure-based database.

Server categorization used by Azure Migrate
  - _Ready for Azure_: machine can be migrated as-is to Azure with full Azure support
  - _Conditionally ready for Azure_: machine has cloud-readiness issues that need remediation; may boot in Azure but it may not have full Azure support
  - _Not ready for Azure_: machine won't boot in Azure and can't be hosted on Azure (e.g. if it has a disk larger than 4 TB)
  - _Readiness unknown_: insufficient data in vCenter Server for Azure Migrate to determine readiness

#### Migration
Custom tools from Microsoft or third parties are more effective than scripting or manual migration
  - Azure Site Recovery tool
  - CloudEndure, a third-party tool, can move a wider range of support VMs to Azure
  - Velostrata performs migration more quickly by migrating only the VM's compute runtime and replicating VM's storage slowly over time

### Optimization
Crucial elements:
  - Performance management
  - Cost optimization

## Principle 2: Define your workload's required availability

__Ensuring high availability__ is a complex and risky task in a datacenter, supported by a variety of techniques and tools. But with geographically dispersed __Availability Zones__, cloud computing can help to ensure high availability.

In order to deploy reliable VMS, Azure uses __availability sets__, logical groupings that ensure that VMs are distributed across multiple hardware clusters, isolated from each other. Azure assigns every VM in an availability set to a __fault domain__, a set of VMs that share a common power source and network switch, and an __update domain__. Availability sets are created before VM deployment.

### Load balancing and high availability in the cloud
Load balancing__ refers to the process of spreading incoming requests across multiple VMs. Load balancers come in two types:
  - __Application__ load balancers, which sit between incoming application traffic and computing resources. They monitor targets and route traffic to the healthy ones.
  - __Network__ load balancers work at the Network OSI layer

## Principle 3: Monitor your applications running on Linux across the entire stack

## Principle 4: Ensure your Linux VMs are secure and backed up

## Principle 5: Govern your cloud environment 
