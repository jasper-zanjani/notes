# Five Principles for Deploying and Managing Linux in the Cloud (With Azure)
> Source: [md](https://docs.microsoft.com/en-us/learn/modules/principles-cloud-computing/2-what-is-cloud-computing)

## 1. Introduction

#### 1.2 Benefits of cloud computing
  - _Agility_: quickly implement a cloud ienvironment (vice setting up hardware)
  - _Pay-for-use_ billing model
  - _Lower cost_: lesser capital expense of buying hardware and other components required for a datacenter
  - _Elasticity_: ability to quickly ramp up and down computing capacity
  - _Reliability_: built-in reseiliency measures in the form of multiple, geographically separate backups
  - _Security_: responsibility is shared between application security (client) and infrastructure security (provider)
  - _Performance_: cloud provider can offer the latest in computing hardware and lower network latency

#### 1.3 Types of cloud services:
  - _IaaS_
  - _PaaS_
  - _SaaS_

#### 1.4 Types of cloud deployments
  - _Public cloud_
  - _Private cloud_
  - _Hybrid cloud_

#### 1.6 Cloud computing architecture
Features common to cloud computing providers:
  - _On-demand_ usage of resources: clients are free to provision any resources at any time
  - _Measured usage_: billing is based on usage
  - _Resource pooling_ 
  - _Elasticity_
  - _Resiliency_: redundant computing resources are located in different geographical areas
  - _Load balancing_

#### 1.7 Running Linux in the cloud: the role of containers
Use cases for containers:
  - Microservices
  - Batch and __ETL__ jobs
  - CI/CD

## Principle 1: Understand which Linux VMs are adaptable to the cloud

#### 2.1 The Cloud RoadMap
Concerns addressed by a well-built cloud adoption roadmap
  - _Benefits_ of migrating to the cloud
  - _What_ to move to the cloud
  - _Technology_ to be chosen
  - _Method_ of optimizing

#### 2.3 Essentials of a cloud-readiness assessment
  - Shareholder interviews
  - Current infrastructure analysis
  - Workload, application, and database analysis
  - Prioritization
  - Cloud architectures and the cloud deployment
  - Cloud personnel requirements
  - Cost analysis
  - Compliance and regulation requirements
  - Cloud migration plan

#### 2.4 Cloud migration strategies
  1. _Lift and shift_: entire current software stack is migrated
  2. _Architect applications before migration_: software is redesigned to take advantage of cloud features. This is more risky because you are planning an infrastructure migration at the same time as an application upgrade.

#### 2.5 Cloud migration tasks
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

##### Azure Migrate Service
Performs dependency mapping and supports the successful migration of multitier applications. Assists in the following ways:
  - _Assesses your readiness for the Azure cloud_
  - _Recommends the best sizes for your cloud VMs_ along with a confidence rating on a scale of 1-5 stars
  - _Estimates monthly costs_

#### 2.6 The three key phases of cloud migration
- Discovery phase
- Migration phase
- Optimization phase

##### Discovery
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

##### Migration
Custom tools from Microsoft or third parties are more effective than scripting or manual migration
  - Azure Site Recovery tool
  - CloudEndure, a third-party tool, can move a wider range of support VMs to Azure
  - Velostrata performs migration more quickly by migrating only the VM's compute runtime and replicating VM's storage slowly over time

##### Optimization
Crucial elements:
  - Performance management
  - Cost optimization

## 3. Principle 2: Define your workload's required availability

__Ensuring high availability__ is a complex and risky task in a datacenter, supported by a variety of techniques and tools. But with geographically dispersed __Availability Zones__, cloud computing can help to ensure high availability.

In order to deploy reliable VMS, Azure uses __availability sets__, logical groupings that ensure that VMs are distributed across multiple hardware clusters, isolated from each other. Azure assigns every VM in an availability set to a __fault domain__, a set of VMs that share a common power source and network switch, and an __update domain__. Availability sets are created before VM deployment.

#### 3.1 Load balancing and high availability in the cloud
Load balancing__ refers to the process of spreading incoming requests across multiple VMs. Load balancers come in two types:
  - __Application__ load balancers, which sit between incoming application traffic and computing resources. They monitor targets and route traffic to the healthy ones.
  - __Network__ load balancers work at the Network OSI layer

## 4. Principle 3: Monitor your applications running on Linux across the entire stack
- Application hosting services: __Azure App Service__, Google Compute Engine, Heroku

#### 4.1 Application performance monitoring (APM) and the cloud
- Serverless computing: __Azure Function__ and __AWS Lambda__

#### 4.2 Challenges of monitoring hybrid architectures
Monitoring issues typical to cloud and hybrid cloud architectures:
  - _Multiple tools_
  - _Lack of visibility into resource utilization_
  - _Dynamic resource provision_

#### 4.3 Monitoring Linux VMs and containers in the cloud
- Log analysis
- Linux server monitoring
- Monitoring and tracking API calls

#### 4.4 Cloud performance monitoring
Tools for performance monitor vary by cloud provider

#### 4.5 Performance benchmarks
Key Linux server metrics to monitor
  - _CPU usage_: The key statistic is the percentage of time the CPU is in use. This has to be analyzed for what portion of usage is attributed to user applications (__CPU user time__) vs. the system (__CPU privileged time__)
  - _Disk I/O_: If I/O writes are high, causing bottlenecks, a new instance type may be needed from the cloud provider.
  - _Memory utilization_: Excessive paging events indicate more RAM should be provisioned.
  - _Network performance_


#### 4.6 Getting a unified view of your infrastructure
Although cloud providers provide proprietary tools for monitoring cloud infrastructure, third-party tools like __Datadog__ can be integrated with Azure and provide additional metrics not available from first-party tools. They can even be linked to other third-party tools like __PagerDuty__ and __Slack__ to get automatic alerts.

#### 4.7 Cloud-monitoring tools
Cloud monitoring is increasingly being offered as a fully managed SaaS by independent providers.
  - Amazon CloudWatch
  - Google Stackdriver
  - Microsoft Azure Monitor

#### 4.8 The importance of a comprehensive monitoring solution
Effective monitoring solution must help you:
  - Understand detailed operation of infrastructure components
  - Understand how application components perform
  - Enhance availability of applications with proactive notifications about critical issues
  - Integrate with other tools or fix problems discovered by monitoring

#### 4.9 Best practices for cloud monitoring
  - Identify the right metrics
  - Support __autoscaling__: automatic adjustment of computing capacity to meet changes in cloud workloads
  - Monitor the user experience
  - Gather uniform metrics
  - Monitor cloud service usage and costs

## 5. Principle 4: Ensure your Linux VMs are secure and backed up

The enhanced security afforded by cloud providers is one of their major draws. The cloud provider is responsible for security of the cloud platform (security __of__ the cloud). The customer is responsible for security of the environment (security __in__ the cloud).

Tools and mechanisms that contribute to better security include:
  - _Strong network security_: cloud providers offer built-in firewalls (security groups) and encryption of data transmitted to/from clouds is common
  - _Configuration Management (CM) tools_ like __Chef__ and __Puppet__ facilitate creation of preconfigured VMs and manage resources according to organizational standards.
  - _Access control_: centralized __IAM__ to manage users, security credentails, and authorization policies
  - _Virtual Private Clouds (VPC)_

__Elasticity__ and __virtualization__, enabling on-demand provisioning of computing power, are the two features of cloud computing that allow it to offer superior __Disaster Recovery (DR)__ solutions, reducing __Recovery time objective (RTO)__ and __Recovery point objective (RPO)__.

There are 3 types of DR solutions. But the prevalence of the cloud has led organizations to consider cloud storage as an alternative to these expensive measures.
  - _Real-time data replication_: A failover is configured for critical applications, such that a mirror of the production system is on standby at the DR site ready to continue operations on little to no notice. 
  - _Off-site storage of tapes_
  - _Backup target appliance in the DR site_
 
Compared to traditional physical DR measures, the cloud offers solutions that are _simpler_, _cheaper_, and _quicker_.

## 6. Principle 5: Govern your cloud environment 

Governance in the cloud is affected the following challenges:
  - Customer has less control of governance
  - Customer shares resources with, but has no insight into the control exercised by, provider
  - International and national regulations on data storage of nationals
  - Data disclosures to governments
  - Data moves around within cloud
  - Varying IAM controls
  - Accountable encryption key management, required by some government and industrial certifying bodies, is facilitated by tools provided by some cloud providers

Pillars of secure and compliant cloud service
  - Security
  - Compliance
  - Privacy and control
  - Transparency

Strategies and tools for enhanced governance in the cloud
  - Security policies
    - _RBAC_: fine-grained access management technique, ensuring users are granted only specific, approved permissions
    - _Network controls_: VPNs and Network security groups (virtual firewalls)
    - _Account hierarchies_: Limit the use of cloud services within the customer's business
  - Continuous security assessments in the cloud are essential, and tools like __Amazon Inspector__ automate them, improving security.
  - Geo-specific services, where operations are confined to specific jurisdictional boundaries, are required by laws and regulations


## Glossary

Term                                    | Definition | Source
:---                                    | :---       | ---
Amazon CloudWatch                       |            | 
Autoscaling                             | automatic adjustment of computing capacity to meet changes in cloud workloads | 5PLC: 64
Availability Zones                      | term used in AWS and Azure to refer to redundant, geographically dispersed computing resources | 5PLC: 19
Availability set                        | Azure capability that groups VMs to ensure they are distributed across multiple hardware clusters, isolated from each other | 5PLC: 42
Business Continuity and Disaster Recovery (BCDR) |    | 5PLC: 38
Cloud provisioning                      | computing model that remotely provisions scalable and measured computing resources and services | 5PLC: 9
Cloud storage device                    | mechanisms which implement the interfaces to __object storage__, accessed via REST or web services | 5PLC: 17
Configuration Management (CM)           | tools that facilitate automation of infrastructure tasks or track changes in configurations made by users to cloud resources | 5PLC: 70
Disaster Recovery (DR)                  | preparing for and recovering from an interruption in operations | 5PLC: 70
Dynamic scalability                     | ability of a cloud provider to transparently scale computing resources in response to the runtime conditions of a user's environment | 5PLC: 19
Elasciticy                              | cf. __dynamic scalability__
Extract, Transform, and Load (ETL)      | type of job used with containers | 5PLC: 20
Hybrid cloud                            | two or more cloud deployment models, where private and public clouds share data and applications and data flows freely between them | 5PLC: 14 
Identity and Access Management (IAM)    | 
Infrastructure as a Service (IaaS)      | cloud provider supplies the IT infrastructure (servers, strorage, and networks) which is paid for based on usage, providing the client with a high degree of control over the cloud environment | 5PLC: 12
Load balancing                          | manner by which a cloud provider manages online traffic by distributing workloads across many servers and computing resources | 5PLC: 19
Microservices                           | small, self-contained applications that perform single tasks or run single processes; spreading incoming requests across multiple VMs; two types | 5PLC: 20, 43
Object storage                          | various types of resources are stored as web resources | 5PLC: 17
Platform as a Service (PaaS)            | computing model in which the cloud provider provisions and manages all the computing infrastructure (servers, networks, and databases), providing a ready-to-use computing environment | 5PLC: 13
Public cloud                            | cloud accessed over the public internet, run by a third-party cloud provider, such as Azure, AWS, or GCP | 5PLC: 14 
Private cloud                           | cloud run on an on-site datacenter, or hosted by a third-party service but owned by the client itself | 5PLC: 14 
Recovery point objective (RPO)          | acceptable amount of data loss, as measured by time | 5PLC: 71
Recovery time objective (RTO)           | time it takes to restore a business process to established operational service levels during disaster recovery | 5PLC: 71
Resource                                | physical or virtual server, software programs, services, storage, or network devices | 5PLC: 9
Resource replication                    | creation of multiple instances of the same computing resource | 5PLC: 17
Resource pooling                        | method by which a cloud provider can provide commoditized computing resources, whereby a large amount of computing resources services many clients | 5PLC: 18
SOAP                                    | messaging format relied upon for web services | 5PLC: 17 
Software as a Service (SaaS)            | cloud provider delivers software applications on demand over the Internet, managing not only the infrastructure but also the software applications themselves | 5PLC: 13
Universal Description, Discovery, and Integration (UDDI) | standard for regulating service registries where WSDL definitions can be publish | 5PLC: 17 
Virtual Machine Scale Set (VMSS)        | create and manage a group of identical load-balanced VMs, the number of which automatically increases or decreases
Virtual Private Cloud (VPC)             | allow cloud users to provision a logically isolated section of the broader cloud where they can launch their own resources in a private network, offered by both AWS and Azure | 5PLC: 70
Virtualization                          | process of converting a physical IT resource into (multiple) virtual resources | 5PLC: 15
Web Service Description Language (WSDL) | markup language used for API of a web service

## Products and features
### Microsoft products and features, including Azure

Term                             | Definition | Source
---                              | ---        | ---
Azure Application Gateway        | Layer 7 load balancer that protects web applications against well-known web exploits | 5PLC: 43
Azure Container Instances (ACI)  | for running Docker containers on Azure VMs | 5PLC: 23
Azure Container Registry (ACR)   | for storing and managing container images | 5PLC: 23
Azure Container Service          | Azure feature that offers Jenkins and Kubernetes | 5PLC: 21
Azure Data Migration Assistant (Azure DMA)   | Microsoft tools to help with database discovery and assessment, can create migration workflows to move database schemas, data, users, roles, and SQL logins; cf. __Azure DMS__ | 5PLC: 36
Azure Database Migration Service (Azure DMS) | specialized tool for migrating data during cloud deployment, migrates on-premise Oracle, MySQL, and SQL Server databases to an Azure managed database in the cloud or to an on-premises database running in an Azure VM | 5PLC: 32
Azure ExpressRoute               | high-performance network solution that helps you create private connections between Azure datacenters and infrastructure located in your datacenters or in colocated environments | 5PLC: 48
Azure Kubernetes Service (AKS)   | Linux-based service offered by Azure to orchestrate containers using Kubernetes, DC/OS, or Docker | 5PLC: 22
Azure Migrate Service            | tool explicitly development for supporting cloud migration | 5PLC: 32-36
Azure Monitor                    |             | 
Azure Security Center            | scans Azure cloud resources for vulnerabilities, such as web apps not protected by __WAF__
Azure Service Fabric             | like __Azure Container Service__, can be used to develop microservices and orchestrate containers on Linux | 5PLC: 23
Azure Site Recovery              | cloud-based recovery solution that can also be used to move Azure-compatible Linux VMs of any distribution | 5PLC: 38, 74
Azure Virtual Machine Scale Sets (VMSSs) |             | 
Azure VNets                      | cloud-based VPN service | 5PLC: 85
Brigade             | event-driven scripting tool for Kubernetes offered by Microsoft
Draft               | Microsoft tool that makes it easy to develop container-based applications and to deploy them to Kubernetes clusters | 5PLC: 24
Microsoft Web Application Firewall (WAF) | feature of __Azure Application Gateway__

### Third-party products and features

Term                | Definition | Source
---                 | ---        | ---
Amazon Inspector    | automated security assessment service | 5PLC: 85
Amazon Virtual Private Cloud  | cloud-based VPN service | 5PLC: 85
AWS Fargate         | cloud-based container service | 5PLC: 21
Chef                | configuration management tool | 5PLC: 70
CloudEndure         | third-party tool used for migrating on-premise VMs to Azure | 5PLC: 39
Google Stackdriver  |             | 
Helm                | open-source packaging tool used to install, deploy, and manage containers in a Kubernetes cluster, manage Kubernetes charts (packages of preconfigured Kubernetes resources) | 5PLC: 23
Puppet              | configuration management tool | 5PLC: 70
Velostrata          | third-party tool used for migrating on-premise VMs to Azure quickly, by replicating only the VM's compute runtime and replicating the VM's storage slowly | 5PLC: 39
Oracle Data Guard   | high-availability system
Oracle Real Application Clusters | high-availability system for databases
