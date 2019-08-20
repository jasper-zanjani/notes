# Containers
## Linux containers
### LXC
Well-known, established low-level toolset with templates, library and language bindings.
### LXD
Offers a user experience similar to virtual machines, using a single command-line tool to manage containers, but using Linux containers instead. At its core lies a privileged daemon that exposes a REST API over a local Unix socket as well as over the network.
### LXCFS
## Windows containers
  - __Helium__ : virtualized filesystem and registry
  - __Argon__ : isolation of object manager, network virtualization
  - __Krypton__ : thin Hyper-V partition
  - __Xenon__ : Argon with BAse OS image
## Kubernetes
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a __container management__ system developed by Google then donated to the __Cloud Native Computing Foundation__. It aims to provide better ways of managing distributed components and services across varied infrastructure.\ 
A __pod__ is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.\ 
A "worker" is a container host, with a Kublet process that communicates with K8s cluster services. K8s uses a __Desired State Management__ system. Within a __pod__ you can specify more than one container image.\
Kubernetes was first announced by Google in mid-2014. It coalesced from a fusion between developers working on Google's Compute Engine and Google's __Borg__, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise. By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. They created a ubiquitous abstraction that could run better than anyone else.\ 
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the __master__, exposing an API for users and clients, assigning or __scheduling__ work, and orchestrating communication between other components. Other machines in the cluster are __nodes__, which accept and run workloads using available resources. Each node is equipped with a __container runtime__ like Docker, which it uses to create and destroy containers according to instructions from the master server.\ 
Before the popularization of containers, __application servers__ provided __non-functional requirements__ including security, isolation, fault tolerance, configuration management, and others. If applications are compared to CDs, then application servers are analogous to CD players.\ 
At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.
### Master server components
  - __etcd__ configuration store, which stores configuration data that can be accessed by cluster nodes.
  - __kube-apiserver__ allows a user to configure K8s workloads and organizational units; implements a RESTful interface, allowing many different tools and libraries to communicate with it
  - __kube-controller-manager__ general service with many responsibilities
  - __kube-scheduler__
  - __cloud-controller-manager__
### Node server components
  - __kubelet__, main contact point for each node with the cluster group
## Podman
Comprehensive container management technology that borrows Docker syntax, developed by Red Hat. The name is short for "pod manager", using Kubernetes' coinage of the term "pod". Unlike Docker, in which containers send messages to the Docker daemon which runs as root (potentially a security concern), Podman containers run as traditional **fork-exec** children of the Podman process, allowing these processes to be run without root privileges.\
Every podman pod contains an **infra container** whose only purpose is to hold the namespaces associated with the pod and allow podman to connect other containers to the pod.\
Podman uses a utility named **Conmon**, or container monitor, which keeps the terminal of containers open in order to execute commands.
#### Create a pod
```sh
podman pod create --name heise
```
#### List pods
```sh
podman pod list
```
#### Download a container image
Podman uses the `pull` command, a borrowing from Docker
```sh
podman pull docker.io/library/alpine:latest
```
#### Run a container
```sh
podman run -d alpine top 
```
#### Run a command within the container
This will display running processes, including the `top` command from the example above.
```sh
podman exec 5f421b01faa ps -ef
```
#### List pods
```sh
podman ps --pod - all
```
## Glossary
Term                | Description
:---                | :---
**Conmon**          | utility used by **Podman** to keep the PTY terminal of containers open in order to execute commands
**container**       | form of lightweight virtualization; low overhead wrapper around an application or set of services
**Container Storage Interface** | Kubernetes component that facilitates storage (ref [N](#sources))
**infra container** | component of a **Podman** pod that holds namespaces associated with the pod itself, allowing it to connect to containers
**Kube Master**     | primary control point for distributed orchestration across different nodes (ref [N](#sources))
**Node**            | system resources that perform tasks as passigned by **Kube Master** (ref [N](#sources))
**Pod**             | collection of one or more containers sharing an IP address, network, and storage
**Helium**          | Windows container with a virtualized filesystem and registry
**Argon**           | Windows container with isolation of object manager, network virtualization
**Krypton**         | Windows container with a thin Hyper-V partition
**Xenon**           | Argon Windows container with Base OS image
## Sources
  A. "Microsoft Azure for Beginners: Introduction - Scott Duffy [YouTube](https://www.youtube.com/watch?v=3gnLwSI4d9E)
  B. "AZ-103 Microsoft Azure Administrator" [microsoft.com](https://www.microsoft.com/en-us/learning/exam-az-103.aspx)
  C. "Fundamentals of Kubernetes on Microsoft Azure - BRK2396" [YouTube](https://www.youtube.com/watch?v=gmN732qN1Gg)
  D. "Kubernetes in 5 mins" [YouTube](https://www.youtube.com/watch?v=PH-2FfFD2PU)
  E. "What is Kubernetes" [YouTube](https://www.youtube.com/watch?v=F-p_7XaEC84)
  F. "An Introduction to Kubernetes [digitalocean.com](https://www.digitalocean.com/community/tutorials/an-introduction-to-kubernetes)
  G. [linuxcontainers.org](https://linuxcontainers.org/)
  H. "Beginner's Guide to Containers and Orchestration". [Udemy](https://www.udemy.com/linux-academy-beginners-guide-to-containers-and-orchestration/)
  I. "A Practical Introduction to Container Terminology". [developers.redhat.com](https://developers.redhat.com/blog/2018/02/22/container-terminology-practical-introduction/)
  J. "Kubernetes Co-Founders On K8’s Past, Present and Future (It Ain’t All Pretty)". [thenewstack.io](https://thenewstack.io/learning-from-the-success-of-kubernetes/)
  K. "Podman: Managing pods and containers in a local container runtime". [Red Hat Developers](https://developers.redhat.com/blog/2019/01/15/podman-managing-containers-pods/)
  L. Interactive Podman Tutorial. [katacoda.com](https://www.katacoda.com/courses/containers-without-docker/running-containers-with-podman)
  M. "Helium, Argon, Krypton & Xenon: The Noble Gases of Windows Containers". [alex-ionescu.com](http://www.alex-ionescu.com/publications/syscan/syscan2017.pdf): 2017/05.
  N. "Understanding Kubernetes Storage". [enterprisestorageforum.com](https://www.enterprisestorageforum.com/cloud-storage/kubernetes-storage.html): 2019/08/16.