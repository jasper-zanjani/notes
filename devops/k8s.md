# Kubernetes
Kubernetes is Greek for "helmsman", "pilot", or "captain". [[35](sources.md)]\
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a **container management** or **orchestration** system developed by Google after deciding to release an internal container management system named "Borg" to the public, and it was subsequently donated to the **Cloud Native Computing Foundation** in 2014 [[35](sources.md)]. It aims to provide better ways of managing distributed components and services across varied infrastructure.\
A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.\
A "worker" is a container host, with a Kubelet process that communicates with K8s cluster services. K8s uses a **Desired State Management** system. Within a **pod** you can specify more than one container image.\
Kubernetes was first announced by Google in mid-2014. It coalesced from a fusion between developers working on Google's Compute Engine and Google's **Borg**, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise. By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. They created a ubiquitous abstraction that could run better than anyone else.\
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. Other machines in the cluster are **nodes**, which accept and run workloads using available resources. Each node is equipped with a **container runtime** like Docker, which it uses to create and destroy containers according to instructions from the master server.\
Before the popularization of containers, **application servers** provided **non-functional requirements** including security, isolation, fault tolerance, configuration management, and others. If applications are compared to CDs, then application servers are analogous to CD players.\
At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.

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

#### Master server components
- etcd
- kube-apiserver
- kube-controller-manager
- kube-scheduler
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

## Tasks
Launch a single-node Kubernetes cluster [[37](sources.md)]
```sh
kubectl cluster-info
kubectl get nodes
kubectl create deployment first-deployment --image=katacoda/docker-http-server
kubectl get pods
kubectl expose deployment first-deployment --port=80 --type=NodePort
export PORT=$(kubectl get svc first-deployment -o go-template='{{range.spec.ports}}{{if .nodePort}}{{.nodePort}}{{"\n"}}{{end}}{{end}}')
echo "Accessing host01:$PORT"
curl host01:$PORT
minikube addons enable dashboard
kubectl apply -f /opt/kubernetes-dashboard.yaml
kubectl get pods -n kube-system -w
```
Launch a multi-node Kubernetes cluster with kubeadm [[38](sources.md)]
```sh
# on master
kubeadm init --token=102952.1a7dd4cc8d1f4cc5 --kubernetes-version $(kubeadm version -o short)
sudo cp /etc/kubernetes/admin.conf $HOME/
sudo chown $(id -u):$(id -g) $HOME/admin.conf
export KUBECONFIG=$HOME/admin.conf
kubectl apply -f /opt/weave-kube
kubectl get pod -n kube-systemo
kubeadm token list

# on node
kubeadm join --discovery-token-unsafe-skip-ca-verification --token=102952.1a7dd4cc8d1f4cc5 172.17.0.20:6443

# on master
kubectl create deployment http --image=katacoda/docker-http-server:latest
kubectl get pods
kubectl apply -f dashboard.yaml
```
