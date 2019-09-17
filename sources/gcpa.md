# Google Cloud Platform Administration
## Contents
\#  | Title | Links
:---| :---  | :---
1   | Introduction to GCP             | 
1A  | Introduction to cloud computing | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/1/ch01lvl1sec10/introduction-to-cloud-computing)
1B  | Introducing GCP | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/1/ch01lvl1sec11/introducing-gcp)
1C  | Data centers and regions
1D  | Relating AWS and Azure to GCP | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/1/ch01lvl1sec13/relating-aws-and-azure-to-gcp)
1E  | Using the command line  | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/1/ch01lvl1sec14/using-the-command-line)
2   | GCP Compute
2A  | Google Compute Engine | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec16/google-compute-engine)
2B  | Creating a VM instance | Single VM through GCP Console<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec17/creating-a-vm-instance)
2C  | Preemptible VM instances | **Preemptible instances** are created at a lower price than a regular instance, with the caveat being that GCE can terminate them if resources are needed for other tasks, or after 24 hours. To make a VM preemptible, simple set the **Preemptibility** option in **Availability policy** to **On**.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec18/preemptible-vm-instances)
2D  | Live migration | **Live migration** refers to when a VM is moved to another host without interruption during a host system event (updates). Instances with GPUs cannot be live migrated.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec19/live-migration)
2E  | Google App Engine | App Engine offers two environments: **standard** and **flexible**. All infrastructure required to run an App Engine instance is located in **one** region and is redundantly available across **all zones** within it. Once set, the app's region cannot be changed.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec20/google-app-engine)
2F  | Kubernetes engine | [Notes](#kubernetes-engine) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec21/kubernetes-engine)
2G  | Node pools | The `default-node-pool` is defined by the number of type of nodes specified at cluster creation. By editing the cluster you created and scrolling to the bottom, you can change the `Size` of the current node pool, delete it, or add additional node pools.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec22/node-pools)
2H  | Google Cloud Functions  | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/2/ch02lvl1sec23/google-cloud-functions)
3   | GCP Storage
3A  | Persistent storage | **Persistent storage** consists of persistent disks that are durable network storage devices mapped to your instance. A Compute instance gets deployed with one root persistent disk by default, though more can be added. A persistent disk can only exist in one zone and may not span multiple zones or regions. <br/>Maximum size of a persistent disk is 64 TB, and most VMs can have up to a maximum of 64TB of persistent disk storage space and a maximum of 16 attached disks. Machine with less than 3.75 GB of memory are limited to 3TB of total persistent disk space and 4 attached disks.<br/>Using **local SSDs** that are physically attached to the server that hosts your VM is an option.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/3/ch03lvl1sec25/persistent-storage)
3B  | Google Cloud Storage buckets | [Notes](#google-cloud-storage-buckets) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/3/ch03lvl1sec26/google-cloud-storage-buckets)
3C  | Google Cloud Spanner | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/3/ch03lvl1sec27/google-cloud-spanner)
3D  | Google Cloud SQL | [Notes](#google-cloud-sql) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/3/ch03lvl1sec28/google-cloud-sql)
3E  | Google Cloud BigTable | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/3/ch03lvl1sec29/google-cloud-bigtable)
4   | GCP Networking
4A  | VPC networks [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec31/vpc-networks)
4B  | Routes Every route has a priority value associated with it (lower values have higher precedence) defaulting to 1000. <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec32/routes)
4C  | Firewall | Firewall rules are unique to a VPC network and only support IPv4 traffic. There is **no** logging mechanism for firewall rules. The GCP firewall allows bidirectional traffic once a session is established (stateful connections). <br/>Every VPC network has an **implied egress** rule and an **implied deny ingress** rule. GCP permanently blocks some traffic types (protocols other than TCP, UDP, ICMP, and IPIP and egress traffic on TCP ports 25, 465, and 587), and these block rules cannot be removed.<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec33/firewall)
4D  | VPC network peering | One VPC network can directly peer with up to 25 others, including active and inactive peers. A VPC network can have up to 7,500 instances in itself and all direct peers.  <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec34/vpc-network-peering)
4E  | Private Google access | Private Google access allows instances to reach GCP services and APIs (BigQuery, Bigtable, container registry, Dataproc, etc) using an internal IP address, rather than a public one.<br/>Cloud SQL does not get Private Google access.<br/>Private Google access is enabled during creation of a VPC subnet. <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec35/private-google-access)
4F  | Other networking concepts | Load balancing <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec36/other-networking-concepts)
4G  | Google Cloud CDN | An **origin** is a server that responds to user requests. <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec37/google-cloud-cdn)
4H  | Cloud VPN | Connect on-premises network to GCP using an IPSEC VPN tunnel. Recommended for low-volume data. <br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec38/cloud-vpn)
4I  | Cloud interconnect | Two ways of consuming Cloud Interconnect: **Dedicated** (direct phycial connection) and **Partner** (connectivity provided through a service provider partner).<br/>[PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/4/ch04lvl1sec39/cloud-interconnect)
5   | GCP Containers
5A  | Kubernetes concepts | [Notes](#kubernetes-concepts) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/5/ch05lvl1sec41/kubernetes-concepts)
5B  | Administering a cluster | [Notes](#administering-a-cluster) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/5/ch05lvl1sec42/administering-a-cluster)
5C  | Configuring cluster networking | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/5/ch05lvl1sec43/configuring-cluster-networking)
5D  | Preemtible instances | **Preemptible instances** last no more than 24 hours, but are priced lower than regular VM instances. [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/5/ch05lvl1sec44/preemptible-instances)
6   | TCP Operations | 
6A  | Stackdriver monitoring and logging | 
6B  | Logging
6C  | Stackdriver error reporting
6D  | Stackdriver debugger
6E  | Stackdriver profiler
6F  | Stackdriver Trace
7   | GCP Identity and Security
7A  | Infrastructure and cloud platform security
7B  | Identity and access management
7C  | Key management service
7D  | Cloud security scanner
7E  | Data loss prevention
7F  | Security keys
8   | GCP Billing
8A  | Billing concepts
8B  | Managing billing
8C  | Analyzing a billing account
8D  | Setting up a budget
9   | GCP Tools
9A  | Deployment Manager
9B  | GCP Marketplace | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/9/ch09lvl1sec66/gcp-marketplace)
9C  | GCP Cloud SDK | [Notes](#gcp-cloud-sdk) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/9/ch09lvl1sec67/gcp-cloud-sdk)
9D  | Cloud API | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/9/ch09lvl1sec68/cloud-api)
9E  | Cloud shell | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/9/ch09lvl1sec69/cloud-shell)

#### Kubernetes concepts
Kubernetes provides a managed environment for deploying and managing containerized applications. Multiple GCE instances are grouped together to form a **container cluster**, managed by GKE. Containers are called **workloads** in Kubernetes, and only Docker containers are supported.
Kubernetes cluster architecture is composed of a **cluster master** and worker machines called **nodes**. Nodes are GCE VMs that run containerized workloads with 1 vCPU and 3.75 GB of RAM.
Kubernetes nodes run pods, which is the simplest element of Kubernetes architecture. A pod typically contains one container, but can contain more than one if they function together as a single entity. A pod is a self-contained logical host that has everything needed for a container to run. Pods are created, updated, and deleted by the **controller manager**, a service on the cluster master which has many functions.

#### Kubernetes engine
A **container cluster** consists of one or more **cluster masters**, which run all **control plane** processes, and multiple GCE machine instances called **nodes**. Control plane processes include the Kubernetes API server (which serves as the **single source of truth** for the entire cluster), scheduler, and core resource controllers.\
Clusters can be either **Zonal** or **Regional**. A zonal cluster allows you to deploy nodes in multiple zones in a region. A regional cluster allows you to have one or more cluster master managing nodes in multiple regions.\
GCP supports two node images: **Container-Optimized OS (cos)** or Ubuntu.\
Number of nodes equates to number of GCE instances, which must be considered for billing purposes. Each node runs necessary services to support Docker containers that make up the cluster **workloads**, which includes Docker runtime and the Kubernetes node agent **kubelet**. 
#### Administering a cluster
A **PersistentVolume (PV)** is a storage unit in a cluster that can be dynamically provisioned by Kubernetes or manually by an admin. PVs are backed by GCP persistent disks or an NFS share, etc. A **PersistentVolumeClaim (PVC)** is a request for storage by a user that can be filled by a PV. Both PVs and PVCs are independent of a pod's lifecycle.

#### Google Cloud SQL
After starting a new SQL server named {$SQL} instance using the Console, you can connect to it from any terminal using Cloud SDK
```sh
gcloud sql connect $SQL --user=root
```
#### Google Cloud Storage buckets
4 storage classes:
  - **Multi-regional** storage: data stored in at least two geographically separate locations with 99.95% SLA.
  - **Regional** storage: no redundancy but offers better performance with a 99.90% SLA.
  - **Nearline** storage: ideal for backups and archives that are rarely accessed; 99.0% SLA. Data retrievel costs and 30-day minimum storage duration.
  - **Coldline** storage: long-term archival storage at low cost; 99.0% SLA. Data retrieval costs and 90-day minimum storage duration.
#### Preemptible VM instances
#### GCP Cloud SDK
Cloud SDK is made up of **components**, installable packages that contain dependencies for tools. When you install Cloud SDK, the `gcloud`, `bq` (BigQuery), `gsutil` (GCP Storage), and `core` components are installed by default.\
Using `gcloud` you can manage configurations. The configuration set by `gcloud init` becomes the `default`, but additional configurations can be created and saved under names, and you can browse them and switch between them.

## Syntax
Syntax  | Effect
:---    | :---
`gcloud init` | initialize Cloud SDK; first command that you run to configure your account [9C](#gcp-cloud-sdk)
`gcloud config list` | view your active configuration properties [9C](#gcp-cloud-sdk)
`gcloud config configurations create $NAME` | save a configuration under {$NAME} [9C](#gcp-cloud-sdk)
`gcloud config configurations list`       | list all available configurations [9C](#gcp-cloud-sdk)
`gcloud components install $COMPONENT`    | install {$COMPONENT} [9C](#gcp-cloud-sdk)
`gcloud components install kubectl`       | install Kubernetes components [9C](#gcp-cloud-sdk)
`gcloud components update`                | update Cloud SDK [9C](#gcp-cloud-sdk)
