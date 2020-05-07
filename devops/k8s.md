[https://www.youtube.com/watch?v=ZuIQurh_kDk]: https://www.youtube.com/watch?v=ZuIQurh_kDk "Kubernetes Design Principles: Understand the Why".
[PodCTL 5]: https://github.com/jasper-zanjani/notes/tree/master/sources/README.md#podctl-5 "PodCTL: Understanding the Cloud Native Ecosystem"


# Kubernetes
**Kubernetes** ("k8s" for short, Greek for "helmsman", "pilot", or "captain") has emerged as the leading container orchestrator in the industry since 2018. 
It aims to provide better ways of managing distributed components and services across varied infrastructure.

It is a **container management** or **orchestration** system developed by Google after deciding to release an internal container management system named "Borg" to the public and donating it to the **Cloud Native Computing Foundation**.

Kubernetes terminology:
- **Pod**: the most basic unit that K8s deals with, representing one or more **tightly-coupled** containers that should be controlled as a single application (typically one main container with subsidiary helper containers). Within a pod you can specify more than one container image.
A pod's containers should:
  - operate closely together
  - share a lifecycle
  - always be scheduled on the same node
- **Worker**: a container host, with a Kubelet process that communicates with K8s cluster services.
- K8s uses a **Desired State Management** system, where Kubernetes API objects are used to describe a cluster's desired state declaratively.

##### History
Kubernetes was first announced by Google in mid-2014.
It coalesced from a fusion between developers working on Google's **Compute Engine** and Google's **Borg**, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise.

By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built.
They created a ubiquitous abstraction that could run better than anyone else.

At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism.
Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.

##### Architecture
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. 
One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. 
Other machines in the cluster are **nodes**, which accept and run workloads using available resources. Each node is equipped with a **container runtime** like Docker, which it uses to create and destroy containers according to instructions from the master server.

Before the popularization of containers, **application servers** provided **non-functional requirements** including security, isolation, fault tolerance, configuration management, and others.
If applications are compared to CDs, then application servers are analogous to CD players.

##### Design principles

1. Kubernetes APIs are **declarative** rather than **imperative**, that is they describe a desired state.<sup>[YouTube][https://www.youtube.com/watch?v=ZuIQurh_kDk]</sup>
2. Kubernetes control plane has no hidden APIs
3. Meet the users where they are: Kubernetes nodes can serve secrets as volumes or environmental variables to fit the requirements of the application
4. Workload portability: Kubernetes acts like an operating system for distributed systems, abstracting peculiarities of infrastructure without changing the application.

##### Distributions
- **Pivotal Container Service (PKS)** <sup>[PodCTL][PodCTL 5]</sup>
- Kontena Pharos
- Rancher 2.0
- Container Linux (formerly CoreOS)
- Canonical Distribution of Kubernetes
- Docker
- Heptio Kubernetes Subscription
- Red Hat OpenShift
- SUSE Container as a Service Platform
- Telekube

##### Kubernetes Master
Collection of 3 processes that run on a single node in the cluster, which is then designated the **master node** [[42](sources.md)]
- `kube-apiserver`
- `kube-controller-manager`
- `kube-scheduler`

- `etcd`
- `cloud-controller-manager`

Controlling services are called the **master (control plane) components**. It is a collection of 4 processes that run on the master node: [[35](sources.md)]
- **Kube-apiserver**
- **Cluster Store**
- **Kube-controller-manager**
- **Kube-scheduler** 

##### Kubernetes node
Worker nodes are called **nodes**, and each node runs 2 processes [[35](sources.md)]:
- **Kubelet**
- **Kube-proxy**

# Syntax
#### `kubeadm`
#### `kubectl`
[kubectl apply]: #kubectl-apply '```&#10;$ kubectl apply&#10;```&#10;Apply a configuration to a resource'
[kubectl apply]: #kubectl-apply '```&#10;$ kubectl apply&#10;```&#10;Apply a configuration to a resource'
[kubectl create]: #kubectl-create '```&#10;$ kubectl create&#10;```&#10;Create a resource'
[kubectl cluster-info]: #kubectl-cluster-info '```&#10;$ kubectl cluster-info&#10;```&#10;Display addresses of the master and services'
[kubectl delete]: #kubectl-delete '```&#10;$ kubectl delete&#10;```&#10;Delete resources'
[kubectl describe]: #kubectl-describe '```&#10;$ kubectl describe&#10;```&#10;Show details of a specific resource or group of resources'
[kubectl edit]: #kubectl-edit '```&#10;$ kubectl edit&#10;```&#10;Edit a resource'
[kubectl expose]: #kubectl-expose '```&#10;$ kubectl expose&#10;```&#10;Expose a resources as a new Kubernetes service'
[kubectl get]: #kubectl-get '```&#10;$ kubectl get&#10;```&#10;Display one or more resources'
[kubectl port-forward]: #kubectl-port-forward '```&#10;$ kubectl port-forward&#10;```&#10;Forward one or more local ports to a pod'
[kubectl rollout]: #kubectl-rollout '```&#10;$ kubectl rollout&#10;```&#10;Manage the rollout of a resource.'
[kubectl run]: #kubectl-run '```&#10;$ kubectl run&#10;```&#10;Create and run a particular image in a pod.'
[kubectl scale]: #kubectl-scale '```&#10;$ kubectl scale&#10;```&#10;Set a new size for a Deployment, ReplicaSet, Replication Controller, or StatefulSet'
[kubectl set]: #kubectl-set '```&#10;$ kubectl set&#10;```&#10;Configure application resources'
[kubectl version]: #kubectl-version '```&#10;$ kubectl version&#10;```&#10;Print the client and server version information for the current context'

[k8s:kubectl-apply]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#apply "kubectl apply"
[k8s:kubectl-create]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#create "kubectl create"
[k8s:kubectl-cluster-info]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#cluster-info "kubectl cluster-info"
[k8s:kubectl-delete]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#delete "kubectl delete"
[k8s:kubectl-describe]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#describe "kubectl describe"
[k8s:kubectl-edit]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#edit "kubectl edit"
[k8s:kubectl-expose]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#expose "kubectl expose"
[k8s:kubectl-get]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#get "kubectl get"
[k8s:kubectl-port-forward]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#port-forward "kubectl port-forward"
[k8s:kubectl-rollout]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#rollout "kubectl rollout"
[k8s:kubectl-run]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#run "kubectl run"
[k8s:kubectl-scale]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#scale "kubectl scale"
[k8s:kubectl-set]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#set "kubectl set"
[k8s:kubectl-version]: kubectl https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#version "kubectl version"

[`apply`][kubectl apply][^][k8s:kubectl-apply]
[`create`][kubectl create][^][k8s:kubectl-create]
[`cluster-info`][kbectl cluster-info] [^][k8s:kubectl-cluster-info]
[`delete`][kubectl delete][^][k8s:kubectl-delete]
[`describe`][kubectl describe][^][k8s:kubectl-describe]
[`edit`][kubectl edit][^][k8s:kubectl-edit]
[`expose`][kubectl expose][^][k8s:kubectl-expose]
[`get`][kubectl get][^][k8s:kubectl-get]
[`port-forward`][kbectl port-forward] [^][k8s:kubectl-port-forward]
[`rollout`][kubectl rollout][^][k8s:kubectl-rollout]
[`run`][kubectl run][^][k8s:kubectl-run]
[`scale`][kubectl scale][^][k8s:kubectl-scale]
[`set`][kubectl set][^][k8s:kubectl-set]
[`version`][kubectl version][^][k8s:kubectl-version]

##### `kubectl create`
Create a new deployment named `$DEPLOYMENT` from `$IMAGE`
```sh
kubectl create deployment $DEPLOYMENT --image=$IMAGE
```
##### `kubectl delete`
Delete $POD
```sh
kubectl delete $POD
```
Delete pod `kuard` [[40](sources.md)]
```sh
delete pod kuard
```
##### `kubectl describe`
[[41](sources.md)]
```sh
kubectl describe deployment http
kubectl describe svc http
```
##### `kubectl edit`
Open an editor to modify deployment `kuard` [[40](sources.md)]
```sh
kubectl edit deployment kuard
```
##### `kubectl expose`
Create a load-balancing service from an existing deployment. `target-port` refers to the ports on deployed pods, while `port` refers to the external facing port of the cluster.  [[40, 41](sources.md)]
```sh
kubectl expose deployment kuard --type=LoadBalancer --port=80 --target-port=8080
kubectl expose deployment http --external-ip="172.17.0.15" --port=8000 --target-port=80
```
##### `kubectl get`
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
##### `kubectl run`
```sh
kubectl run --image=$IMGURL:$VERSION
kubectl run --generator=run-pod/v1 --image=gcr.io/kuar-demo/kuard-amd64:1 kuard
kubectl run --image=gcr.io/kuar-demo/kuard-amd64:1 kuard --replicas=5 
kubectl run http --image=katacoda/docker-http-server:latest --replicas=1
kubectl run httpexposed --image=katacoda/docker-http-server:latest --replicas=1 --port=80 --hostport=8001
```