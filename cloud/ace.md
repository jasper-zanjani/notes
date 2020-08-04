# Google Cloud Certified Associate Cloud Engineer
[App Engine]: # 'App Engine&#10;allows users to deploy applications in a popular programming language without configuring VMs or Kubernetes clusters&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 20'
[Cloud AutoML]: # 'Cloud AutoML&#10;allows developers without machine learning experience to develop machine learning models&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Natural Language Processing]: # 'Cloud Natural Language Processing&#10;tool for analyzing human languages and extracting information from text&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Vision]: # 'Cloud Vision&#10;image analysis platform for annotating images with metadata, extracting text, or filtering content&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Inference API]: # 'Cloud Inference API&#10;service for computing correlations over time-series data&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 8'
[Cloud Functions]: #storage 'Cloud Functions&#10;lightweight computing option well-suited to event-driven processing&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 20'
[preemptible]: # 'preemptible&#10;VM that costs less than a normal one but which may be shut down at any time by Google&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 18'
[IaaS]: # 'Infrastructure as a Service (IaaS)&#10;most basic method of cloud service computing; users install everything from the OS up&#10;Dulaney, Emmett. _CompTIA Network+ N10-007 Exam Cram, 6th Edition_.: 479'
[PaaS]: # 'platform as a service (PaaS)&#10;cloud computing service model in which the provider supplies the operating system and the user is responsible for the stack above it&#10;Dulaney, Emmett. _CompTIA Network+ N10-007 Exam Cram, 6th Edition_.: 268'

#### Overview
Public cloud providers like Google, Amazon, and Microsoft offer services that fall into 4 broad categories
- [Compute](#compute)
  - **Google Compute Engine (GCE)** VMs
  - **Google [Kubernetes](https://github.com/jasper-zanjani/notes/blob/master/devops/k8s.md "Kubernetes") Engine (GKE)** container clusters
  - Serverless compute: [**App Engine**][App Engine] and [**Cloud Functions**][Cloud Functions]
- Storage
  - **Cloud Storage (GCS)** (object storage) manages "objects" or "blobs" which are grouped into **buckets**.
  - **Filestore** (file storage) provides network shared file systems
  - Block storage is available wihtin GCE as **persistent** or **ephemeral** disks attached to VMs.
Block size can vary to suit various needs.
  - Caches, which ensure fast (submillisecond) access to data
- Networking: networks internal to GCP are known as **virtual private clouds (VPC)**.
**Peering** refers to the process of linking networks to each other.
External IP addresses can be static or ephemeral.
- Specialized services are typically serverlessm, offered via an API, and charged based on usage, such as [**Cloud AutoML**][Cloud AutoML], [**Cloud Natural Language**][Cloud Natural Language], [**Cloud Vision**][Cloud Vision], and [**Cloud Inference API**][Cloud Inference API], among many other examples

Using cloud services instead of outfitting a data center can be compared to renting instead of buying.
Cloud services offer **elasticity**, meaning new compute and storage resources can be provisioned quickly.

#### Compute
GCP's [IaaS][IaaS] IaaS offering is GCE.
VMs can be configured in a variety of ways, including choice of OS, size of persistent storage, virtualized hardware, and [**preemptibility**][preemptible].

GKE is a managed service for Kubernetes clusters that allows users to describe the compute, storage, and memory resources for their cluster.

GCP's [PaaS][PaaS] offerings come in the form of [App Engine][App Engine] and [Cloud Functions][Cloud Functions].

App Engine allows developers to deploy applications developed in popular programming languages to a serverless environment.
It is available in two environment types:
- **Standard** where the application is ryun in a sandbox and isolated from the underlying server's OS.
- **Flexible** where Docker containers are run in the environment, useful when third-party software or libraries are needed.

Cloud Functions is suited to running short-running logic, such as calling other APIs in response to an event.

#### Administration
The **resource hierarchy** organizes GCP resources in 3 levels
1. **Organization** corresponds to a company or organization.
A single **cloud identity** is associated with a single organization, and they have **super admins**
2. **Folders** can contain other folders or projects and facilitate multilayer organizational hierarchies.
3. **Projects** are the direct parents of all GCP resources being organized

**Roles** are collections of permissions
- **Primitive roles** are basic privileges that can be applied to most resources and include Owner, Editor, and Viewer
- **Predefined roles** are specific to GCP products. For example, App Engine roles include:
  - `appengine.appAdmin` grants identities the ability to read, write, and modify all application settings
  - `appengine.ServiceAdmin` grants read-only access to application settings and write-level access to module-level and version-level settings
  - `appengine.appViewer` grants read-only access to applications

#### VMs

#### Managing VMs