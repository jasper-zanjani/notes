# Cloud providers 
## Service comparison table
Service                           | Azure                       | AWS   | GCP
:---                              | :---                        | :---  | :---
Certifications                    | [Azure certs](../certs/README.md#azure-certs) | [AWS certs](../certs/README.md#aws-certs) | [GCP certs](../certs/README.md#gcp-certs)
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
High availability                   | maintaining __acceptable continuous performance__ despite temporary load fluctuations or failures in services, hardware, or data centers
Online Analytics Processing (OLAP)
Online Transaction Processing (OLAP)
Platform as a Service               | software design pattern where a third-party service (i.e. Heroku, [Azure Web Apps](), and AWS [Elastic Beanstalk](#elastic-beanstalk)) eliminates the need for managing infrastructure but unlike **serverless architecture**, does not scale automatically. Typically an application deployed over PaaS is running on at least one server at all times.
Serverless architecture             | software design pattern where applications are hosted by a third-party service and are executed only when needed. Typically used for simple, transaction-type functions that are run often.
application programming interface   | provides programmatic access to resources [21](../sources/clf-c01.md)
API Gateway                         | fully managed service that allows you to create and publish secure APIs to scale [21](../sources/clf-c01.md)
artifact                            | central resource for compliance-related information [21](../sources/clf-c01.md)
Atomicity, Consistency, Isolation, Durability (ACID) | properties of database transactions intended to guarantee validity even in the event of error or failure
Auto Scaling                        | automatic addition and subtraction of resources based on various factors, often their demand [21](../sources/clf-c01.md)
automation                          | automation generation and/or performance of required IT tasks [21](../sources/clf-c01.md)
availability                        | ensuring data is available when needed [21](../sources/clf-c01.md)
Availability Zone                   | division of geographic locations within regions; each Availability Zone contains at least one separate and distinct data center [21](../sources/clf-c01.md)
AWS Auditor Learning Path           | AWS Learning Path that focuses on compliance and legal roles [21](../sources/clf-c01.md)
AWS Global Infrastructure           | resources owned by AWS around the globe and used by customers [21](../sources/clf-c01.md)
AWS Partner Network                 | AWS global partner program that seeks to help partners build successful AWS solutions [21](../sources/clf-c01.md)
AWS Professional Services           | organization made up of a global team of experts that can help you with your desired business outcomes for AWS [21](../sources/clf-c01.md)
AWS Shared Responsibility model     | overall security model followed by AWS; this model divides the client responsibilities from those of Amazon [21](../sources/clf-c01.md)
Azure Bastion                       | fully managed PaaS service that provides secure and seamless RDP and SSH access to your virtual machines directly through the Azure Portal [[22](#sources)]
Basic support plan                  | AWS support plan that is included free of charge for every account [[21](../sources/clf-c01.md)]
Business support plan               | third tier of 4 support plan tiers; features a response time to your issues of 1 hour [21](../sources/clf-c01.md)
Cisco Meraki                        | company that produces infrastructure equipment like cloud-managed switches, cameras, wireless access points, etc
ClassicLink                         | allows the linking of EC2-Classic instances to a VPC in your account [21](../sources/clf-c01.md)
Classless Inter-Domain Domain Routing | style of describing IP address ranges where a slash followed by a number follows the IP address (i.e. `10.0.0.0/8`) describes what portion of an IP address is variable and what portion describes the host [[A](#sources): 280]
Cloud Services Platform             | Google hybrid cloud software, comprising a set of software and services that work both on-premises and in GCP and are managed by GCP [K8S 13](#../sources/README.md#k8s-13)
CloudFormation                      | gives developers and systems administrators an easy way to create and manage a collection of related AWS resources, provisioning and updating them in an orderly and predictable fashion [21](../sources/clf-c01.md)
CloudFront                          | global content delivery network service that accelerates delivery of your websites, APIs, video content, or other web assets [21](../sources/clf-c01.md)
CloudTrail                          | web service that records AWS API calls for your account and delivers log files to you [21](../sources/clf-c01.md)
CloudWatch                          | monitoring service for AWS Cloud resources and the applications you run on AWS [21](../sources/clf-c01.md)
CodeDeploy                          | fully managed code deployment service that helps you deploy software to things like EC2 instances [21](../sources/clf-c01.md)
Community cloud                     | cloud provisioned for use by a select group of companies or organization [21](../sources/clf-c01.md)
Confidentiality                     | keeping data secure (often through encryption) [21](../sources/clf-c01.md)
Developer support plan              | second of 4 support tiers; first level of support plan that provides you with access to tech support [21](../sources/clf-c01.md)
Direct Connect                      | alternative to a shared Internet connection to AWS; completely private connection from on-premises network to AWS [21](../sources/clf-c01.md)
document store                      | also "document-oriented database", a type of **NoSQL database** that relies on the concept of the record as **document**, whose **content** may differ in format and structure from document to document. Documents are placed within a **collection**, and each document is addressed via a unique key.
Top-Level Domains (".com"), second-level domains ("example.com"), and subdomains; also an administrative function allowing for granular control of DNS components [[14](#sources)]

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
22. "Azure Bastion". [Microsoft](https://azure.microsoft.com/en-us/services/azure-bastion/).
