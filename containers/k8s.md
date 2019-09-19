# Kubernetes
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a **container management** system developed by Google then donated to the **Cloud Native Computing Foundation**. It aims to provide better ways of managing distributed components and services across varied infrastructure.\ 
A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.\ 
A "worker" is a container host, with a Kubelet process that communicates with K8s cluster services. K8s uses a **Desired State Management** system. Within a **pod** you can specify more than one container image.\
Kubernetes was first announced by Google in mid-2014. It coalesced from a fusion between developers working on Google's Compute Engine and Google's **Borg**, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise. By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. They created a ubiquitous abstraction that could run better than anyone else.\ 
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. Other machines in the cluster are **nodes**, which accept and run workloads using available resources. Each node is equipped with a **container runtime** like Docker, which it uses to create and destroy containers according to instructions from the master server.\ 
Before the popularization of containers, **application servers** provided **non-functional requirements** including security, isolation, fault tolerance, configuration management, and others. If applications are compared to CDs, then application servers are analogous to CD players.\ 
At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.
### Distributions
  - Kontena Pharos
  - Pivotal Container Service (PKS)
  - Rancher 2.0
  - CoreOS
  - Canonical Distribution of Kubernetes
  - Docker
  - Heptio Kubernetes Subscription
  - Red Hat OpenShift
  - SUSE Container as a Service Platform
  - Telekube
### Master server components
  - **etcd** configuration store, which stores configuration data that can be accessed by cluster nodes.
  - **kube-apiserver** allows a user to configure K8s workloads and organizational units; implements a RESTful interface, allowing many different tools and libraries to communicate with it
  - **kube-controller-manager** general service with many responsibilities
  - **kube-scheduler**
  - **cloud-controller-manager**
### Node server components
  - **kubelet**, main contact point for each node with the cluster group