# Five Principles for Deploying and Managing Linux in the Cloud (With Azure)

Term                                              | Definition | Source
---                                               | ---        | ---
Amazon CloudWatch                                 |             | 
Availability Zones                                | term used in AWS and Azure to refer to redundant, geographically dispersed computing resources | 5PLC: 19
Azure Virtual Machine Scale Sets (VMSSs)          |             | 
Azure Kubernetes Service (AKS)                    | Linux-based service offered by Azure to orchestrate containers using Kubernetes, DC/OS, or Docker | 5PLC: 22
Azure Container Service                           | Azure feature that offers Jenkins and Kubernetes | 5PLC: 21
cloud provisioning                                | computing model that remotely provisions scalable and measured computing resources and services | [5PLC](file-lx-azure.md): 9
cloud storage device                              | mechanisms which implement the interfaces to __object storage__, accessed via REST or web services | 5PLC: 17
dynamic scalability                               | ability of a cloud provider to transparently scale computing resources in response to the runtime conditions of a user's environment | 5PLC: 19
elasciticy                                        | cf. __dynamic scalability__
extract, transform, and load (ETL)                | type of job used with containers | 5PLC: 20
Google Stackdriver                                |             | 
hybrid cloud                                      | two or more cloud deployment models, where private and public clouds share data and applications and data flows freely between them | [5PLC](file-lx-azure.md): 14 
load balancing                                    | manner by which a cloud provider manages online traffic by distributing workloads across many servers and computing resources | 5PLC: 19
Infrastructure as a Service (IaaS)                | cloud provider supplies the IT infrastructure (servers, strorage, and networks) which is paid for based on usage, providing the client with a high degree of control over the cloud environment | [5PLC](file-lx-azure.md): 12
Microservices                                     | small, self-contained applications that perform single tasks or run single processes | 5PLC: 20
Microsoft Azure Monitor                           |             | 
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
virtualization                                    | process of converting a physical IT resource into (multiple) virtual resources | [5PLC](file-lx-azure.md): 15
Web Service Description Language (WSDL)           | markup language used for API of a web service



## Introduction
Benefits of cloud computing ([5PLC](file-lx-azure.md): 9)
  - __Agility__: qickly implement a cloud ienvironment (vice setting up hardware)
  - __Pay-for-use__ billing model
  - __Lower cost__: lesser capital expense of buying hardware and other components required for a datacenter
  - __Elasticity__: ability to quickly ramp up and down computing capacity
  - __Reliability__: built-in reseiliency measures in the form of multiple, geographically separate backups
  - __Security__: responsibility is shared between application security (client) and infrastructure security (provider)
  - __Performance__: cloud provider can offer the latest in computing hardware and lower network latency

Types of cloud services:
  - __IaaS__
  - __PaaS__
  - __SaaS__

Types of cloud deployments
  - __Public cloud__
  - __Private cloud__
  - __Hybrid cloud__

Features common to cloud computing providers:
  - __On-demand__ usage of resources: clients are free to provision any resources at any time
  - __Measured usage__: billing is based on usage
  - __Resource pooling__ 
  - __Elasticity__
  - __Resiliency__: redundant computing resources are located in different geographical areas
  - __Load balancing__

Use cases for containers:
  - Microservices
  - Batch and __ETL__ jobs
  - CI/CD



## Principle 1: Understand which Linux VMs are adaptable to the cloud

## Principle 2: Define your workload's required availability

## Principle 3: Monitor your applications running on Linux across the entire stack

## Principle 4: Ensure your Linux VMs are secure and backed up

## Principle 5: Govern your cloud environment


