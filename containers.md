# Containers
  - "Beginner's Guide to Containers and Orchestration". [Udemy](https://www.udemy.com/linux-academy-beginners-guide-to-containers-and-orchestration/)

## Kubernetes
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a __container management__ system developed by Google then donated to the __Cloud Native Computing Foundation__. It aims to provide better ways of managing distributed components and services across varied infrastructure.

A "worker" is a container host, with a Kublet process that communicates with K8s cluster services. K8s uses a __Desired State Management__ system. Within a __pod__ you can specify more than one container image.

### Architecture
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the __master__, exposing an API for users and clients, assigning or __scheduling__ work, and orchestrating communication between other components. Other machines in the cluster are __nodes__, which accept and run workloads using available resources. Each node is equipped with a __container runtime__ like Docker, which it uses to create and destroy containers according to instructions from the master server.

### Concepts
  - a __pod__ is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.

### Master server components
  - __etcd__ configuration store, which stores configuration data that can be accessed by cluster nodes.
  - __kube-apiserver__ allows a user to configure K8s workloads and organizational units; implements a RESTful interface, allowing many different tools and libraries to communicate with it
  - __kube-controller-manager__ general service with many responsibilities
  - __kube-scheduler__
  - __cloud-controller-manager__

### Node server components
  - __kubelet__, main contact point for each node with the cluster group

## Sources
  - "Microsoft Azure for Beginners: Introduction - Scott Duffy [YouTube](https://www.youtube.com/watch?v=3gnLwSI4d9E)
  - "AZ-103 Microsoft Azure Administrator" [microsoft.com](https://www.microsoft.com/en-us/learning/exam-az-103.aspx)
  - "Fundamentals of Kubernetes on Microsoft Azure - BRK2396" [YouTube](https://www.youtube.com/watch?v=gmN732qN1Gg)
  - "Kubernetes in 5 mins" [YouTube](https://www.youtube.com/watch?v=PH-2FfFD2PU)
  - "What is Kubernetes" [YouTube](https://www.youtube.com/watch?v=F-p_7XaEC84)
  - "An Introduction to Kubernetes [digitalocean.com](https://www.digitalocean.com/community/tutorials/an-introduction-to-kubernetes)
