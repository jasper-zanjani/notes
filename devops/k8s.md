# Kubernetes
Kubernetes is Greek for "helmsman", "pilot", or "captain". [[35](sources.md)]\
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a **container management** or **orchestration** system developed by Google after deciding to release an internal container management system named "Borg" to the public, and it was subsequently donated to the **Cloud Native Computing Foundation** in 2014 [[35](sources.md)]. It aims to provide better ways of managing distributed components and services across varied infrastructure.\
A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.\
A "worker" is a container host, with a Kubelet process that communicates with K8s cluster services. K8s uses a **Desired State Management** system. Within a **pod** you can specify more than one container image.\
Kubernetes was first announced by Google in mid-2014. It coalesced from a fusion between developers working on Google's Compute Engine and Google's **Borg**, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise. By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. They created a ubiquitous abstraction that could run better than anyone else.\
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. Other machines in the cluster are **nodes**, which accept and run workloads using available resources. Each node is equipped with a **container runtime** like Docker, which it uses to create and destroy containers according to instructions from the master server.\
Before the popularization of containers, **application servers** provided **non-functional requirements** including security, isolation, fault tolerance, configuration management, and others. If applications are compared to CDs, then application servers are analogous to CD players.\
At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.

## Concepts
**Kubernetes API objects** are used to describe a cluster's **desired state**. This makes programming Kubernetes **declarative** rather than **imperative**. 

#### Design principles
1. Kubernetes APIs are **declarative** rather than **imperative**, that is they describe a desired state.
2. Kubernetes control plane has no hidden APIs
3. Meet the users where they are: Kubernetes nodes can serve secrets as volumes or environmental variables to fit the requirements of the application
4. Workload portability: Kubernetes acts like an operating system for distributed systems, abstracting peculiarities of infrastructure without changing the application.\
[[18](README.md#sources)]

#### Distributions
- Kontena Pharos
- Pivotal Container Service (PKS) [[23](README.md#sources)]
- Rancher 2.0
- Container Linux (formerly CoreOS)
- Canonical Distribution of Kubernetes
- Docker
- Heptio Kubernetes Subscription
- Red Hat OpenShift
- SUSE Container as a Service Platform
- Telekube

#### Kubernetes Master
Collection of 3 processes that run on a single node in the cluster, which is then designated the **master node** [[42](sources.md)]
- kube-apiserver
- kube-controller-manager
- kube-scheduler

- etcd
- cloud-controller-manager

#### Kubernetes Master
Controlling services are called the **master (control plane) components**. It is a collection of 4 processes that run on the master node: [[35](sources.md)]
- **Kube-apiserver**
- **Cluster Store**
- **Kube-controller-manager**
- **Kube-scheduler** 

#### Kubernetes node
Worker nodes are called **nodes**, and each node runs 2 processes [[35](sources.md)]:
- **Kubelet**
- **Kube-proxy**

## Syntax
### kubeadm

### kubectl
Command groups  | Links
:---            | :---
`cluster-info`
`create`          | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#create) [Notes](#kubectl-create)
`delete`          | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#delete) [Notes](#kubectl-delete)
`describe`        | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#describe) 
`edit`
`expose`          | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#expose) [Notes](#kubectl-expose)
`get`             | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#get) [Notes](#kubectl-get)
`port-forward`
`rollout`
`run`             | [Docs](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#run) [Notes](#kubectl-run)
`scale`
`set`
`token`
`version`

#### kubectl create
Create a new deployment named `$DEPLOYMENT` from `$IMAGE`
```sh
kubectl create deployment $DEPLOYMENT --image=$IMAGE
```


#### kubectl delete
Delete $POD
```sh
kubectl delete $POD
```
Delete pod `kuard` [[40](sources.md)]
```sh
delete pod kuard
```


#### kubectl describe
[[41](sources.md)]
```sh
kubectl describe deployment http
kubectl describe svc http
```


#### kubectl edit
Open an editor to modify deployment `kuard` [[40](sources.md)]
```sh
kubectl edit deployment kuard
```


#### kubectl expose
Create a load-balancing service from an existing deployment. `target-port` refers to the ports on deployed pods, while `port` refers to the external facing port of the cluster.  [[40, 41](sources.md)]
```sh
kubectl expose deployment kuard --type=LoadBalancer --port=80 --target-port=8080
kubectl expose deployment http --external-ip="172.17.0.15" --port=8000 --target-port=80
```


#### kubectl get
View nodes in cluster [[40](sources.md)]
```sh
kubectl get nodes
```
View status of deployments
```sh
kubectl get deployments
kubectl get pods
kubectl get pods --namespace=kube-system # background processes necessary for Kubernetes itself
```
Display details of service `kuard`
```sh
kubectl get service kuard -o wide
```


#### kubectl run
```sh
kubectl run --image=$IMGURL:$VERSION
kubectl run --generator=run-pod/v1 --image=gcr.io/kuar-demo/kuard-amd64:1 kuard
kubectl run --image=gcr.io/kuar-demo/kuard-amd64:1 kuard --replicas=5 
kubectl run http --image=katacoda/docker-http-server:latest --replicas=1
kubectl run httpexposed --image=katacoda/docker-http-server:latest --replicas=1 --port=80 --hostport=8001
```


