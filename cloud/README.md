# Cloud providers 
## Service comparison table
Service                           | Azure                       | AWS   | GCP
:---                              | :---                        | :---  | :---
Certifications                    | [Azure certs](#azure-certs) | [AWS certs](#aws-certs) | [GCP certs](#gcp-certs)
Command-line tools                | [Azure PowerShell](azure/azure-ps.md) [Azure CLI](azure/azure-cli.md) | AWS Command Line Interface<br/>AWS Tools for PowerShell| [gsutil](#gsutil) [gcloud](#gcloud)
IaaS                              | Virtual Machines            | Elastic Compute Cloud (EC2) | Compute Engine
PaaS                              | App Service, Cloud Services | Elastic Beanstalk  | App Engine
Containers                        | Container Service, Service Fabric | Elastic Container Service (ECS) | Google Kubernetes Engine
Serverless functions              | Functions                   | Lambda | Functions
Containers                        | Container Service, Service Fabric | Elastic Container Service (ECS) | Google Kubernetes Engine
Virtual networks                  | VNets                       | Virtual Private Cloud (VPC) | Virtual Private Cloud
Load Balancer                     | Load Balancer, Application Gateway | Elastic Load Balancer  | Load Balancing
Private connection to cloud       | ExpressRoute                | Direct Connect  | Interconnect
DNS                               | DNS                         | Route 53              | DNS
CDN                               | CDN                         | CloudFront            | CDN
Object Storage                    | Blob Storage                | Simple Storage Service (S3) | Storage
Block Storage                     | Disk Storage                | Elastic Block Store (EBS) | Persistent Disk
File Storage                      | File Storage                | Elastic File System (EFS) | Filestore (beta)
Reduced-availability Storage      | Cool Blob Storage           | S3 Standard-Infrequent Access, S3 One Zone-Infrequent Access  | Storage Nearline
Archival Storage                  | Archive Blob Storage        | Glacier |  [ Coldline ](https://cloud.google.com/storage/archival/)
Physical data transport           | Import/Export Service, Data Box | Snowball | GCS Transfer appliance [[16](#sources)]
RDBMS                             | SQL Database                | Relational Database Service (RDS), Aurora | SQL, [ Spanner ](#spanner)
NoSQL: Key-value                  | Table Storage               | [ DynamoDB ](#dynamodb)   | [Firestore](#firestore), [Bigtable](#bigtable)
NoSQL: Indexed                    | [Cosmos DB](#cosmosdb)      | SimpleDB |  [Firestore](#firestore)
Batch Data Processing             | HDInsight, Batch            | Elastic MapReduce (EMR), Batch | Dataproc, Dataflow
Stream Data Processing            | Stream Analytics            | Kinesis |  Dataflow
Stream Data Ingest                | Event Hubs, Service Bus     | Kinesis  | Pub/Sub
Big Data Analytics                | Data Lake Analytics, Data Lake Store | Redshift, Athena  | BigQuery
Messaging                         | Service Bus                 | Simple Notification Service (SNS), Simple Queueing Service (SQS) | Pub/Sub
Monitoring                        | Monitor                     | CloudWatch   | Stackdriver 
Deployment                        | Resource Manager            | CloudFormation   | Deployment Manage
## Certifications
### AWS certs
[Certification](https://aws.amazon.com/certification/) | Links
:---                                  | :---
AWS Certified Cloud Practitioner      | [Certification](https://aws.amazon.com/certification/certified-cloud-practitioner/)
AWS Certified Solutions Architect     | [Certification](https://aws.amazon.com/certification/certified-solutions-architect-associate/)
AWS Certified Developer - Associate   | [Certification](https://aws.amazon.com/certification/certified-developer-associate/)
AWS Certified SysOps Administrator - Associate | [Certification](https://aws.amazon.com/certification/certified-sysops-admin-associate/)
AWS Certified Solutions Architect - Professional | [Certification](https://aws.amazon.com/certification/certified-solutions-architect-professional/)
AWS Certified DevOps Engineer - Professional | [Certification](https://aws.amazon.com/certification/certified-devops-engineer-professional/)
AWS Certified Security - Specialty    | [Certification](https://aws.amazon.com/certification/certified-security-specialty/)
AWS Certified Big Data - Specialty    | [Certification](https://aws.amazon.com/certification/certified-big-data-specialty/)
AWS Certified Advanced Networking - Specialty | [Certification](https://aws.amazon.com/certification/certified-advanced-networking-specialty/)
AWS Certified Machine Learning - Specialty | [Certification](https://aws.amazon.com/certification/certified-machine-learning-specialty/)
AWS Certified Alexa Skill Builder - Specialty | [Certification](https://aws.amazon.com/certification/certified-alexa-skill-builder-specialty/)
### Azure certs
[Certification](https://www.microsoft.com/en-us/learning/browse-all-certifications.aspx) | Links
:---                                  | :---
Azure Administrator Associate         | [Certification](https://www.microsoft.com/en-us/learning/azure-administrator.aspx) Exam: [AZ-103](https://www.microsoft.com/en-us/learning/exam-az-103.aspx)
Azure Security Engineer Associate     | [Certification](https://www.microsoft.com/en-us/learning/azure-security-engineer.aspx) Exam: [AZ-500](https://www.microsoft.com/en-us/learning/azure-security-engineer.aspx#cert-expansion-tab-exam-az-500)
Azure AI Engineer Associate           | [Certification](https://www.microsoft.com/en-us/learning/azure-ai-engineer.aspx) Exam: [AI-100](https://www.microsoft.com/en-us/learning/azure-ai-engineer.aspx#cert-expansion-tab-exam-ai-100)
Azure Data Engineer Associate         | [Certification](https://www.microsoft.com/en-us/learning/azure-data-engineer.aspx) Exams: [DP-200](https://www.microsoft.com/en-us/learning/azure-data-engineer.aspx#cert-expansion-tab-exam-DP-200) [DP-201](https://www.microsoft.com/en-us/learning/azure-data-engineer.aspx#cert-expansion-tab-exam-DP-201)
Azure Data Scientist Associate        | [Certification](https://www.microsoft.com/en-us/learning/azure-data-scientist.aspx) Exam: [DP-100](https://www.microsoft.com/en-us/learning/azure-data-scientist.aspx#cert-expansion-tab-exam-DP-100)
Azure Developer Associate             | [Certification](https://www.microsoft.com/en-us/learning/azure-developer.aspx) Exam: [AZ-203](https://www.microsoft.com/en-us/learning/azure-developer.aspx#cert-expansion-tab-exam-az-203)
Azure DevOps Engineer Expert          | [Certification](https://www.microsoft.com/en-us/learning/azure-devops.aspx) Exam: [AZ-400](https://www.microsoft.com/en-us/learning/azure-devops.aspx#cert-expansion-tab-exam-az-400)
Azure Solutions Architect Expert      | [Certification](https://www.microsoft.com/en-us/learning/azure-solutions-architect.aspx) Exams: [AZ-300](https://www.microsoft.com/en-us/learning/azure-solutions-architect.aspx#cert-expansion-tab-exam-az-300), [AZ-301](https://www.microsoft.com/en-us/learning/azure-solutions-architect.aspx#cert-expansion-tab-exam-az-301)
### GCP certs
[Certification](https://cloud.google.com/certification/)| Links
:---                                  | :---
Associate Cloud Engineer              | [Certification](https://cloud.google.com/certification/cloud-engineer) [Exam](https://cloud.google.com/certification/guides/cloud-engineer/)
Professional Cloud Architect          | [Certification](https://cloud.google.com/certification/cloud-architect/)
Professional Data Engineer            | [Certification](https://cloud.google.com/certification/data-engineer/)
Professional Cloud Developer          | [Certification](https://cloud.google.com/certification/cloud-developer/)
Professional Cloud Network Engineer   | [Certification](https://cloud.google.com/certification/cloud-network-engineer)
Professional Cloud Security Engineer  | [Certification](https://cloud.google.com/certification/cloud-security-engineer/)
Professional Collaboration Engineer   | [Certification](https://cloud.google.com/certification/collaboration-engineer)
## Resources
### GCP resources
GCP resources are organized in a **resource hierarchy** organized under an **Organization**, which is considered the top level of the hierarchy, although it can be further subsumed by an even higher **Domain**.[[19](#sources), [20](#sources)]\
A **Billing Account** tracks charges and billing account admins can set budgets.\
The **Payments Profile** is a Google-level resource that is used to pay for all Google services.\
**Projects** are organized under **Folders** which can be nested within each other, and can also have **Labels**. A project can have many labels, but only lives in a **single** folder. Resources are the lowest levels of the hierarchy and can **only** be parented by projects.[[19](#sources), [20](#sources)]
## Services
## Command-line tools
#### AWS Command Line Interface and AWS Tools for PowerShell
[[17](#sources)]
#### GCP utilities: `gsutil` and `gcloud`
`gsutil` is a Python application that enables command-line access to Cloud Storage [[15](#sources)].\
`gsutil` uses the prefix `gs://` to indicate a resource in Cloud Storage:
```
gs://BUCKET_NAME/OBJECT_NAME
```
[gcloud command-line tool](https://cloud.google.com/sdk/gcloud/)
## NoSQL
#### Spanner
Managed scaleable database service.
#### CosmosDB
Microsoft Azure NoSQL database service optimized for mobile and web applications that offers graph, document, and key-value APIs [[11](#sources)].
#### DynamoDB
Wide-column NoSQL database with the choice between **strongly consistent** and **eventually consistent** (half the cost) reads. DynamoDB offers two types of indexes: **Global Secondary Index** and **Local Secondary Index (LSI)**. The LSI is an alternate sort key attribute. GSI allow you to create a completely new aggregation of data, whereas LSI only allows sorting.\
GSI updates are eventually consistent, with asynchronous updates populated after an update response is passed to the client.[[18](#sources)]\
DynamoDB Streams (changelog for the DynamoDB table) interfaces with AWS Lambda to implement **complex queries**, computed values like sum, average, maximum, etc. These are implemented in a different **processing space** than the DynamoDB table itself, so that it does not affect the table. AWS Lambda has an **invocation role** which defines what Lambda can **see** (triggered upon a change to the table as reported in DynamoDB Streams) and an **execution role** which defines what it can **do**.[[18](#sources)]
#### Firestore
NoSQL Document database service offering high performance and automatic scaling intended for serverless mobile and web application development with Cloud App Engine.
  - **History**: Firestore was released from beta in early 2019 and combines and improves upon functionality of previous products named **Cloud Datastore** and **Firebase Realtime Database** [[8,9](#sources)]. Firestore features a compatibility mode that emulates the behavior of Datastore in accessing Firestore's storage layer while removing some of Datastore's limitations.
  - **Queries** [[3](#sources)]
    - Queries in Firestore are intended to be used to find documents stored in one specific collection or sub-collection. 
    - A query that spans multiple sub-collections ("collection group query") was not possible until recently, but the field has to be specified as having a scope of "Collection group" within GCP, and there is a limit of (about) 200 for these queries. 
    - An index is created for every field in every document added to a collection, which results in very fast query times that are proportional to the number of **results**, not records searched. But this means that there is no native way to perform wildcard searches or OR queries. For common instances of such queries, Google recommends adding a field that contains that result for each record 
    - Firestore's structure ensures that equality searches are highly performant.
    - "Inequality searches" present a challenge for Firestore. For some queries that combine conditions on more than one field (i.e. restaurants within a certain range of a location), Firebase will create a "composite index" (only within the index, the document itself is not affected) automatically to facilitate searches on those fields.
  - **Pricing**: Firestore primarily charges based on the number of reads, writes, and deletes performed on the database, each of which have a different unit charge. [[10](#sources)]
#### BigTable
GCP Realtime database used for Big Data [[7](#sources)].
  - **History**: BigTable evolved out of Google's need to ensure access to petabytes of data in its web search business line. It was described in a 2006 research paper that ended up launching the entire NoSQL industry. In 2015 it was made available as a service to cloud customers. [[4](#sources)]
  - **Queries**: BigTable doesn't support secondary indexes [[5,6](#sources)]
## PaaS
#### App Engine
Google Cloud Platform Platform-as-a-Service offering.\
Video | Link
:---  | :---
Get to know Google App Engine | [YouTube](https://youtu.be/2PRciDpqpko) 
#### Compute Engine
Video | Link
:---  | :---
Getting Started with Google Cloud Compute Engine | [YouTube](https://youtu.be/1XH0gLlGDdk)
#### Coldline

## Glossary
Term                                | Definition  
:---                                | :---
Elasticity                          | ability to increase or decrease the __instance count or size__ of existing resources based on fluctuations in traffic or load, or in resource workload 
FaaS                                | **Function as a Service**
Function as a Service               | **serverless** architecture
Fault tolerance                     | a system's ability to __continue operating properly__ when one or more of its components fails [[7](#sources)]
High availability                   | maintaining __acceptable continuous performance__ despite temporary load fluctuations or failures in services, hardware, or data centers | 
Online Analytics Processing (OLAP)
Online Transaction Processing (OLAP)
Platform as a Service               | software design pattern where a third-party service (i.e. Heroku, [Azure Web Apps](), and AWS [Elastic Beanstalk](#elastic-beanstalk)) eliminates the need for managing infrastructure but unlike **serverless architecture**, does not scale automatically. Typically an application deployed over PaaS is running on at least one server at all times.
Serverless architecture             | software design pattern where applications are hosted by a third-party service and are executed only when needed. Typically used for simple, transaction-type functions that are run often.
application programming interface   | provides programmatic access to resources [21](../sources/clf-c01.md
API Gateway                         | fully managed service that allows you to create and publish secure APIs to scale [21](../sources/clf-c01.md
artifact                            | central resource for compliance-related information [21](../sources/clf-c01.md
Atomicity, Consistency, Isolation, Durability (ACID) | properties of database transactions intended to guarantee validity even in the event of error or failure
Auto Scaling                        | automatic addition and subtraction of resources based on various factors, often their demand [21](../sources/clf-c01.md
automation                          | automation generation and/or performance of required IT tasks [21](../sources/clf-c01.md
availability                        | ensuring data is available when needed [21](../sources/clf-c01.md
Availability Zone                   | division of geographic locations within regions; each Availability Zone contains at least one separate and distinct data center [21](../sources/clf-c01.md
AWS Auditor Learning Path           | AWS Learning Path that focuses on compliance and legal roles [21](../sources/clf-c01.md
AWS Global Infrastructure           | resources owned by AWS around the globe and used by customers [21](../sources/clf-c01.md
AWS Partner Network                 | AWS global partner program that seeks to help partners build successful AWS solutions [21](../sources/clf-c01.md
AWS Professional Services           | organization made up of a global team of experts that can help you with your desired business outcomes for AWS [21](../sources/clf-c01.md
AWS Shared Responsibility model     | overall security model followed by AWS; this model divides the client responsibilities from those of Amazon [21](../sources/clf-c01.md
Basic support plan                  | AWS support plan that is included free of charge for every account [21](../sources/clf-c01.md
Business support plan               | third tier of 4 support plan tiers; features a response time to your issues of 1 hour [21](../sources/clf-c01.md
Cisco Meraki                        | company that produces infrastructure equipment like cloud-managed switches, cameras, wireless access points, etc
ClassicLink                         | allows the linking of EC2-Classic instances to a VPC in your account [21](../sources/clf-c01.md
Classless Inter-Domain Domain Routing | style of describing IP address ranges where a slash followed by a number follows the IP address (i.e. `10.0.0.0/8`) describes what portion of an IP address is variable and what portion describes the host [[A](#sources): 280]
Cloud Services Platform             | Google hybrid cloud software, comprising a set of software and services that work both on-premises and in GCP and are managed by GCP [K8S 13](#../sources/README.md#k8s-13)
CloudFormation                      | gives developers and systems administrators an easy way to create and manage a collection of related AWS resources, provisioning and updating them in an orderly and predictable fashion [21](../sources/clf-c01.md
CloudFront                          | global content delivery network service that accelerates delivery of your websites, APIs, video content, or other web assets [21](../sources/clf-c01.md
CloudTrail                          | web service that records AWS API calls for your account and delivers log files to you [21](../sources/clf-c01.md
CloudWatch                          | monitoring service for AWS Cloud resources and the applications you run on AWS [21](../sources/clf-c01.md
CodeDeploy                          | fully managed code deployment service that helps you deploy software to things like EC2 instances [21](../sources/clf-c01.md
Community cloud                     | cloud provisioned for use by a select group of companies or organization [21](../sources/clf-c01.md
Confidentiality                     | keeping data secure (often through encryption) [21](../sources/clf-c01.md
Developer support plan              | second of 4 support tiers; first level of support plan that provides you with access to tech support [21](../sources/clf-c01.md
Direct Connect                      | alternative to a shared Internet connection to AWS; completely private connection from on-premises network to AWS [21](../sources/clf-c01.md
document store                      | also "document-oriented database", a type of **NoSQL database** that relies on the concept of the record as **document**, whose **content** may differ in format and structure from document to document. Documents are placed within a **collection**, and each document is addressed via a unique key.
DymanoDB                            | fast and flexible NoSQL database service for all applications that need consistent, single-digit millisecond latency at any scale [21](../sources/clf-c01.md
Elastic Block Store                 | offers persistent block storage volumes for use with EC2 instances [21](../sources/clf-c01.md
Elastic Compute Cloud               | makes virtual machines available in AWS and provides a managed environment for Docker containers [21](../sources/clf-c01.md
Edge locations                      | locations that deliver cached CloudFront content [21](../sources/clf-c01.md
Elastic File System                 | provides simple, scalable file storage for use with EC2 instances [21](../sources/clf-c01.md
Elastic Beanstalk                   | service that permits you to upload your code and have it hosted automatically by AWS [21](../sources/clf-c01.md
Elastic Load Balancing              | AWS tool for distributing requests for a resource among various resources [21](../sources/clf-c01.md
ElastiCache                         | web service that makes it easy to deploy, operate, and scale an in-memory cache in the cloud [21](../sources/clf-c01.md
Elasticity                          | ability of the cloud to grow or shrink resources dynamically based on demand or other factors [21](../sources/clf-c01.md
Enterprise support plan             | premier level of support available in AWS; features a response time of just 15 minutes to major issues you are experiencing [21](../sources/clf-c01.md
Federation                          | permitting an account to use its accses with another trusted service in order to access AWS [21](../sources/clf-c01.md
free tier                           | trial account for AWS that is completely free, with some constraints [21](../sources/clf-c01.md
fault tolerance                     | property that enables a system to continue operating properly in the event of the failure of some (one or more faults within) of its components [21](../sources/clf-c01.md
Glacier                             | secure, durable, and extremely low-cost storage service for data archiving and long-term backup [21](../sources/clf-c01.md
group                               | collection of user accounts; permissions are assigned to groups [21](../sources/clf-c01.md
high availability                   | characteristic of a system that aims to ensure an agreed level of operational performance, usually uptime, for a higher than normal period [21](../sources/clf-c01.md
hybrid cloud                        | companies that host some cloud technologies privately and rely on public cloud resources for other technologies [21](../sources/clf-c01.md
integrity                           | ensuring data is not manipulated at rest or in transit [21](../sources/clf-c01.md
Lambda                              | main serverless compute service of AWS [21](../sources/clf-c01.md
Network ACL                         | used to control traffic moving between subnets in the VPC [21](../sources/clf-c01.md
Networking and Content Delivery     | service category that features low-latency delivery of cached content to specific geographic locations [21](../sources/clf-c01.md
On-demand instances                 | EC2 instances that are launched at a current price of compute time [21](../sources/clf-c01.md
OpsWorks                            | configuration management service that uses Chef or Puppet, an automation platform that treats server configurations as code [21](../sources/clf-c01.md
orchestration                       | scheduling and coordination of automated tasks for an entire process or workflow [21](../sources/clf-c01.md
private cloud                       |  cloud technology kept "in-house" and fully managed by the private organization [21](../sources/clf-c01.md
public cloud                        | massive cloud providers that make various "as a Service" models available to the public [21](../sources/clf-c01.md
Relational Database Services        | make it easy to set up, operate, and scale a relational database in the cloud [21](../sources/clf-c01.md
Redshift                            | fast, fully managed petabyte-scale data warehouse that makes it simple and cost-effective to analyze all your data using your existing business intelligence tools [21](../sources/clf-c01.md
Region                              | physical, geographic location int he world where AWS creates multiple Availability Zones [21](../sources/clf-c01.md
Reserved instances                  | instances at a fixed price that you have contractually reserved for your purposes [21](../sources/clf-c01.md
Roles                               | similar to user accounts but with no credentials; used to provide access from one AWS service to another [21](../sources/clf-c01.md
Route 53                            | highly available and scalable cloud Domain Name System web service [21](../sources/clf-c01.md
Scalability                         | ability to increase the __instance count or size__ of existing resources [[7](#sources)
Scale out                           | increase __instance count__ of existing resources: non-disruptive [[7](#sources)]
Scale up                            | increase __instance size__ of existing resources: __disruptive__ [[7](#sources)]
Security groups                     | built-in firewalls that are associated with EC2 isntances and provide security at the protocol and port lwevel [21](../sources/clf-c01.md
Security **in** the cloud           | reference to the client security responsibilities in the AWS Shared Responsibility model [21](../sources/clf-c01.md
Security **of** the cloud           | reference to the Amazon security responsibilities in the AWS Shared Responsibility model [21](../sources/clf-c01.md
Service Catalog                     | allows creation and maintenance of a catalog of IT resources approved for use with AWS [21](../sources/clf-c01.md
Simple Storage Service (S3)         | flexible, object-based storage for a wide variety of purposes [21](../sources/clf-c01.md
Simple Monthly Calculator           | free AWS tool that allows you to calculate monthly AWS costs for various services [21](../sources/clf-c01.md
Spot instance                       | instance where you bid on unused capacity in AWS [21](../sources/clf-c01.md
Systems Manager                     | tool for grouping resources for ease of monitoring and configuration changes [21](../sources/clf-c01.md
Total Cost of Ownership calculators | set of free AWS tools that permit you to reduce TCO by estimating cost savings using AWS [21](../sources/clf-c01.md
Trusted Advisor                     | management tools that checks your configurations and provides modification advice to help you adhere to best practices [21](../sources/clf-c01.md
Users                               | entities created to represent individuals who need access to AWS [21](../sources/clf-c01.md
Virtual Private Cloud               | provides virtual network components in AWS [21](../sources/clf-c01.md
endpoint                            | permits private connections from your VPC to supported AWS services [21](../sources/clf-c01.md
peering                             | connection between multiple VPCs in AWS [21](../sources/clf-c01.md
whitepaper                          | document made available by Amazon that provides valuable best practices and architectures to follow [21](../sources/clf-c01.md
zone                                | a part of the domain namespace delegated to a legal entity (person or organization) who is responsible for maintaining it, i.e. Top-Level Domains (".com"), second-level domains ("example.com"), and subdomains; also an administrative function allowing for granular control of DNS components [[14](#sources)]

## Sources
  1. Washam, Michael; Tuliani, Jonathan; Hoag, Scott. _Exam Ref AZ-103 Microsoft Azure Administrator_. [AZ-103](sources/az-103.md)
  2. "Zero to App: Live Coding an App with Firebase (Firebase Dev Summit 2017)". [YouTube](https://www.youtube.com/watch?v=VTkM5BbnslU)
  3. "How do queries work in Cloud Firestore/ | Get to Know Cloud Firestore #2". [YouTube](https://youtu.be/Ofux_4c94FI): 2018/05/30.
  4. "Introduction to Google BigTable: Best Uses, Design, and Demo". [YouTube](https://www.youtube.com/watch?v=1qieV-WCU_w)
  5. "The Right Bigtable Index Makes All the Difference". [YouTube](https://www.youtube.com/watch?v=oxC_iTLGtLA): 2019/01/17.
  6. "The right Cloud Bigtable index makes all the difference". [Medium](https://medium.com/@duhroach/the-right-cloud-bigtable-index-makes-all-the-difference-3bcabe9bd65a): 2019/01/17.
  7. "System Properties Comparison Google Cloud Bigtable vs. Google Cloud Firestore". [db-engines.com](https://db-engines.com/en/system/Google+Cloud+Bigtable%3BGoogle+Cloud+Firestore)
  8. "Introducing Firebase Realtime Database". [YouTube](https://youtu.be/U5aeM5dvUpA): 2016/05/18.
  9. "Cloud Firestore vs the Realtime Database: Which one do I use?". [The Firebase Blog](https://firebase.googleblog.com/2017/10/cloud-firestore-for-rtdb-developers.html): 2017/10/03.
  10. "Cloud Firestore Pricing | Get to Know Cloud Firestore #3". [YouTube](https://youtu.be/6NegFl9p_sE): 2018/06/27.
  11. "Azure Friday | Azure Cosmos DB with Scott Hanselman". [YouTube](https://youtu.be/4fRKzcU__jY): 2017/06/27.
  12. "Archival cloud storage: Nearline & Coldline". [Google Cloud](https://cloud.google.com/storage/archival/)
  13. "Linux Academy: Microsoft Azure Concepts". [Udemy](https://www.udemy.com/linux-academy-microsoft-azure-concepts/)
  14. "DNS zones explained". [Pocket](https://app.getpocket.com/read/2495535941) -> [ns1.com](https://ns1.com/resources/dns-zones-explained)
  15. "gsutil tool". [Google Cloud](https://cloud.google.com/storage/docs/gsutil).
  16. "Uploading files to GCS (Cloud Storage Bytes". [YouTube](https://youtu.be/nmZxfuFIP08).
  17. "SysAdmin & Hybrid Cloud Special". [AWS TechChat](../sources/README.md#aws-53) 
  18. "AWS re:Invent 2018: Amazon DynamoDB Deep Dive: Advanced Design Patterns for DynamoDB (DAT401)". [YouTube](https://youtu.be/HaEPXoXVf2k).
  19. "Organizing your GCP resources - Beyond Your Bill". [YouTube](https://youtu.be/NOOhDq1JyIM): 2019/08/27.
  20. "Resource Hierarchy". [Google Cloud](https://cloud.google.com/resource-manager/docs/cloud-platform-resource-hierarchy?utm_source=youtube&utm_medium=unpaidsocial&utm_campaign=ram-20190806-Resource-Hierarchy)
  21. Sequeira, Anthony. "AWS Certified Cloud Practitioner (CLF-C01) Cert Guide". [CLF-C01](../sources/clf-c01.md)
