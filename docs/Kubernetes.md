#  ⎈&#xfe0f; Kubernetes

**Kubernetes** (Greek for "helmsman", "pilot", or "captain" and "k8s" for short) has emerged as the leading **container orchestrator** in the industry since 2018. It provides a layer that abstracts infrastructure, including computers, networks, and other computers, for applications deployed on top.

## History

Kubernetes was first announced by Google in mid-2014. 
It had been developed by Google after deciding to open-source the Borg system, a cluster and container management system that formed the automation infrastructure that powered the entire Google enterprise.
Kubernetes coalesced from a fusion between developers working on Borg and [Compute Engine](/Cloud#compute-engine). Borg eventually evolved into Omega.

By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. 
They created a ubiquitous abstraction that could run better than anyone else.

At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. 
Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing trade secrets.

Google ultimately donated iKubernetes to the **Cloud Native Computing Foundation**.


## Architecture


Kubernetes can be visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels.
One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. 

Other machines in the cluster are called **nodes** or **workers** and accept and run workloads using available resources. 



### Azure

A volume represents a way to store, retrieve, and persist data across pods and through the application lifecycle. In the context of Azure, Kubernetes can use two types of data volume:

- **Azure Disks** using Azure Premium (SSDs) or Azure Standard (HDDs).
- **Azure Files** using a SMB 3.0 share backed by an Azure Storage account.



## 📘 Glossary

### Deployment

### Desired State Management

The **Desired State Management** system is used by Kubernetes to describe a cluster's desired state declaratively.

### kube-apiserver

One of the three processes run by a [master node](#master-node)

### kube-controller-manager

One of the three processes run by a [master node](#master-node)

### kube-scheduler

One of the three processes run by a [master node](#master-node)

### Kubelet

### Master node

A master node runs 3 processes, called master (control plane) components: 

- [kube-apiserver](#kube-apiserver)
- [kube-controller-manager](#kube-controller-manager)
- [kube-scheduler](#kube-scheduler).

### Node

A **node** or worker is any container host that accepts workloads from the master node. 
Each node is equipped with a container runtime like Docker, which it uses to create and destroy containers according to instructions from the master server.

Each node runs 2 processes

- [kubelet](#kubelet), which communicates with Kubernetes cluster services
- [kube-proxy](#kube-proxy)

### PersistentVolume

### PersistentVolumeClaim

![](/img/persistent-volume-claims.png)

A **PersistentVolumeClaim** requests either Disk or File storage of a particular StorageClass, access mode, and size. It is bound to a [PersistentVolume](#persistenvolume) once an available storage resource has been assigned to the pod requesting it.

### Pod

A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). 
Within a pod you can specify more than one container image.

A pod's containers should:

- operate closely together
- share a lifecycle
- always be scheduled on the same node

### ReplicaSet

### Worker
