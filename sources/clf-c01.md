# AWS Certified Cloud Practitioner (CLF-C01) Cert Guide, by Anthony Sequeira
## Objectives
1. Cloud Concepts
   1.1. Define the AWS Cloud and its value proposition
   1.2. Identify aspects of AWS Cloud economics
   1.3. List the different cloud architecture design principles
2. Security
   2.1. Define the **AWS Shared Responsibility** model
   2.2. Define AWS Cloud security and compliance concepts
   2.3. Identify AWS access management capabilities
   2.4. Identify resources for security support
3. Technology
   3.1. Define methods of deploying and operating in the AWS Cloud
   3.2. Define the **AWS global infrastructure**
   3.3. Identify the core AWS services
   3.4. Identify resources for technology support
4. Billing and pricing
   4.1. Compare and contrast the various pricing models for AWS
   4.2. Recognize the various account structures in relation to AWS billing and pricing
   4.3. Identify resources available for billing support
## Contents
### 1: The AWS Cloud Defined
5 essential characterstics of the cloud, according to National Institute for Standards and Technology (NIST):
  - **On-demand self-service**: customers can provision and manage resources independently
  - **Broad network access**: cloud resources should be available through normal approaches like HTTPS
  - **Resource pooling**: One provider's computing resources are pooled to satisfy many clients (multitenant model)
  - **Rapid elasticity**: capabilities are rapidly and automatically scalable
  - **Measured service**: resources are metered and charged for by usage

Cloud services categories: **IaaS**, **PaaS**, **Saas**

Cloud deployment models:
  - Private cloud: infrastructure provisioned for exclusive use by a single organization
  - Community cloud: infrastructure is provisioned for exclusive use by a specific community of consumers from organizations that have shared concerns
  - Public cloud
  - Hybrid cloud: composition of two or more distinct cloud infrastructures
  
AWS compute service categories [8-10]
  - EC2
  - Lambda
  - Elastic Beanstalk
  - Elastic Container Service

AWS storage services [10-11]
  - S3
  - EBS
  - Glacier
  - EFS

AWS network services [11-12]
  - VPC
  - Route 53
  - CloudFront
  - API Gateway
  - Direct Connect

AWS databse services [13]
  - RDS
  - DynamoDB
  - ElastiCache
  - Redshift

Security services [13-14]
  - IAM
  - Security groups
  - Network ACLs

Automation and application support [14-15]
  - CodeDeploy
  - CloudFormation
  - OpsWorks
  
Management tools [15]
  - Service Catalog
  - Systems Manager
  - Trusted Advisor

AWS Monitoring [15-16]
  - CloudWatch
  - CloudTrail

Advantages of the cloud [20-23]
  - CapEx replaced by OpEx
  - Lack of contractual commitments
  - Reduction of required negotiations
  - Pay as you go
  - High levels of security possible
  - Flexibility
  - Massive global infrastructure
  - SaaS, PaaS, and IaaS offerings
  - Emphasis on API support

Advantages of AWS cloud [24-25]
  - Speed
  - Experimentation
  - Culture of innovation

Elastic Load Balancing load balancer types [27]
  - **Application** Load Balancer
  - **Network** Load Balancer
  - **Classic** Load Balancer

Components of AWS Global Infrastructure [36]
  - **Regions**
  - **Availability Zones**
  - **Edge Locations**: host cached content for fast delivery to clients using CloudFront

VPC features [37-38]
  - High availability
  - Subnets
  - Route tables
  - Internet Gateway (IGW)
  - NAT Gateway
  - Network access control lists (NACL)

Lambda workflow [40]
  1. Upload code to Lambda
  2. Set up trigger from other AWS services, HTTP endpoints, or in-app activity
  3. Lambda runs code when triggered
  4. Pay for compute time required

EC2 pricing models [42]
  - **On-demand** instances
  - **Reserved** intstances: up to 75% discount
  - **Spot** instances: bid on spare EC2 computing capacity, with savings of up to 90%

S3 advantages [45]
  - Simple
  - Durable
  - Scalable
  - Secure
  - Available
  - Low cost
  - Simple data transfer
  - Integrated
  - Easy to manage

Aurora benefits [47]
  - High performance
  - Highly secure
  - MySQL and PostGreSQL compatible
  - Highly scalable
  - High availability and durability
  - Fully managed

RDS Benefits [48]
  - Fast and easy to administer
  - Highly scalable
  - Available and durable
  - Secure
  - Inexpensive

5 pillars of the Well-Architected Framework [55]
  1. **Operational excellence**: running and monitoring systems to ensure that they are providing value for the business goals of the organization
  2. **Security**: protection of assets, systems, and information
  3. **Reliability**: easy recovery from service failures and on-demand resource growth
  4. **Performance efficiency**: efficient use of resources
  5. **Cost optimization**: saving money

AWS services that enable high-availability [58]
  - Elastic Load Balancing
  - Elastic IP Addresses
  - Route 53
  - Auto Scaling
  - CloudWatch

AWS services that buttress fault tolerance [58]
  - SQS
  - SNS
  - SimpleDB

AWS web hosting benefits:
  - Cost effectiveness
  - On-demand resources

IT control categories [66]
  - **Inherited controls**: security controls the customer fully inherits from AWS (e.g. physical and environmental security controls)
  - **Shared controls**: controls that apply to both the infrastructur layer of Amazon and customer responsibilities (e.g. IAM)
  - **Customer-specific controls**: controls the customer is solely responsible for (e.g. applying specific patches to an EC2 instance OS)

AWS responsibilities in the Shared Responsibility framework:
  - Cloud software
  - Hardware
  - AWS Global Infrastructure

Client responsibilities in the Shared Responsibility model:
  - Customer data
  - Platform, applications, IAM
  - Guest operating systems
  - Network and firewall configuration
  - Client-side data encryption
  - Server-side encryption
  - Networking traffic protection

Security Triad:
  - Confidentiality: encrypting data
  - Integrity: protecting data
  - Availability: ensuring access

Main identities used in AWS:
  - AWS account root user
  - Users
  - Groups
  - Roles

IAM best practice recommendations [85-86]
  - Store root user access keys securely
  - Create individual IAM users
  - Use groups to assign permissions to IAM users
  - Use AWS-defined policies for permissions
  - Grant least privilege
  - Review IAM permissions
  - Strong password policy for users
  - Enable MFA
  - Use roles
  - Use roles to delegate permissions
  - Don't share access keys
  - Rotate credentials
  - Remove unnecessary credentials
  - Use policy conditions
  - Monitor, monitor, monitor

Elements of automation [105]
  - Configuration templates
  - Code deployment automation
  - Self-healing infrastructures
  - Reduction in need for manual interventions
  - Reduction in potential for errors
  - Lowered operating costs for MSPs

Common areas where automation plays a huge role in AWS [105]
  - Backup generation and retention
  - Security compliance
  - Code deployments
  - AWS infrastructure changes

Benefits of orchestration tools [107]
  - Lowering of overall IT costs
  - Gained time for new or experimental projects
  - Improved delivery times to customers
  - Reduced friction between system and development teams

AWS resource management options [109]
  - AWS Management Console
  - AWS CLI
  - Programmatic access using SDKs and APIs

AWS Global Infrastructure [116-118]
  - **Region**: physical location in the world with at least 2 AZs
  - **Availability Zone (AZ)**: consiste of one or more discrete data centers, each with redundant power, networking, and connectivity, housed in separate facilities
  - 18 regions and 55 AZs at time of writing of book

Direct Connect features [118]
  - Private connection to AWS
  - Reduction of network costs
  - Increase in bandwidth throughput
  - More consistent network experience
  - Use of 802.1Q VLANs that enable partitioning the connection into multiple virtual interfaces

VPC endpoint types: [119]
  - interface endpoint
  - gateway endpoint


AWS cost cateogories [157]
  - Compute
  - Storage
  - Data Transfer Out
No charges for:
  - Data transfer in
  - Data transfers between AWS resources

Variables for pricing of AWS services [157-158]
  - EC2
    - Total clock hours of usage
    - Amount and distribution of load balancing
    - Machine configuration
    - Detailed monitoring
    - Machine purchase type
    - Software/OS
    - Elastic IP addresses
    - Number of instances
    - Cross-AZ data transfer
  - S3
    - Storage type
    - Storage class
    - Requests
    - Data transfer out
  - EBS
    - Volume type
    - IOPS
    - Snapshots
  - RDS
    - Total clock hours of usage
    - Additional storage
    - Database configuration
    - Purchase type
    - Deployment type
    - Number of databases
    - Data transfer out
    - Provisioned storage
  - CloudFormation
    - Traffic distribution location
    - Request
    - Data transfer out

AWS support goals [163]
  - Proactive guidance: **TAM**
  - Best practices: **AWS Trusted Advisor**
  - Account assistance: **Concierge**
  - Launch support: **IEM**

AWS support plans [165]
  - Basic
  - Developer
  - Business
  - Enterprise

TCO calculator capabilities [171]
  - Compare cost of application on-prem vs. on-cloud
  - Describe on-prem configuration to produce a detailed cost comparison with AWS
  - Instant summary report that shows you 3-year TCO comparison by cost category
  - Download full report

Features and capabilities of AWS Billing and Cost Management Service [173]
  - Analyzing costs with Graphs: includes **Cost Explorer** tool
  - Budgets: also uses Cost Explorer
  - Payment currencies: AWS converts bill to preferred currency after bill is finalized; until then, all amounts are shown in USD
  - AWS Cost and Usage reports: publish billing reports to an S3 bucket; daily updates published in CSV format