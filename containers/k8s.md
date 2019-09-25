# Kubernetes
Kubernetes (K8s) has emerged as the leading container orchestrator in the industry since 2018. It is a **container management** system developed by Google then donated to the **Cloud Native Computing Foundation**. It aims to provide better ways of managing distributed components and services across varied infrastructure.\
A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). A pod's containers should operate closely container, share a lifecycle, and always be scheduled on the same node.\
A "worker" is a container host, with a Kubelet process that communicates with K8s cluster services. K8s uses a **Desired State Management** system. Within a **pod** you can specify more than one container image.\
Kubernetes was first announced by Google in mid-2014. It coalesced from a fusion between developers working on Google's Compute Engine and Google's **Borg**, a cluster manager that runs hundreds of thousands of jobs at Google, representing the infrastructure powering the entire Google enterprise. By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. They created a ubiquitous abstraction that could run better than anyone else.\
Kubernetes is visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels. One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. Other machines in the cluster are **nodes**, which accept and run workloads using available resources. Each node is equipped with a **container runtime** like Docker, which it uses to create and destroy containers according to instructions from the master server.\
Before the popularization of containers, **application servers** provided **non-functional requirements** including security, isolation, fault tolerance, configuration management, and others. If applications are compared to CDs, then application servers are analogous to CD players.\
At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing too much of its secret sauce.
### Design principles
1. Kubernetes APIs are **declarative** rather than **imperative**, that is they describe a desired state.
2. Kubernetes control plane has no hidden APIs
3. Meet the users where they are: Kubernetes nodes can serve secrets as volumes or environmental variables to fit the requirements of the application
4. Workload portability: Kubernetes acts like an operating system for distributed systems, abstracting peculiarities of infrastructure without changing the application.\
[[18](README.md#sources)]
### Distributions
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
### Master server components
- etcd
- kube-apiserver
- kube-controller-manager
- kube-scheduler
- cloud-controller-manager
### Node server components
- `kubelet`
### Tools
Name          | Description
:---          | :---
Aporeto       | security policies [Web](https://www.aporeto.com/)
Ark           | see **Velero** [[K8S 12](../sources/README.md#k8s-12)]
Bootkube      | Launch self-hosted Kubernetes clusters. [GitHub](https://github.com/kubernetes-incubator/bootkube)
cAdvisor      | collecting metrics [GitHub](https://github.com/google/cadvisor)
Conjure-up    | Canonical product that allows you to deploy The Canonical Distribution of Kubernetes on Ubuntu. 
Consul        | Hashicorp service networking solution [Web](https://www.hashicorp.com/products/consul/)
Contour       | ingress controller based on Envoy to solve Northwest problems [[K8S 12](../sources/README.md#k8s-12)]
CoreDNS       | set of plugins written in Go which perform DNS functions [Web](https://coredns.io/)
Dynatrace     | monitoring [Web](https://www.dynatrace.com/support/help/technology-support/cloud-platforms/kubernetes/installation-and-operation/further-integrations/connect-your-kubernetes-clusters-to-dynatrace/#configure-activegate)
Fission       | serverless framework for Kubernetes [Web](https://fission.io/)
Fnproject     | FaaS framework for Kubernetes, written in Go [Web](http://fnproject.io/)
Funktion      | FaaS framework for Kubernetes, now sandboxed [GitHub](https://github.com/funktionio/funktion)
Gimbal        | ingress controller based on Envoy to solve Northwest problems [[K8S 12](../sources/README.md#k8s-12)]
Helm          | Kubernetes package manager [GitHub](https://github.com/kubernetes/helm)
IronFunction  | FaaS framework for Kubernetes, written in Go [GitHub](https://github.com/iron-io/functions)
Istio         | service mesh [[Web](https://istio.io/)]
Jaeger        | implementation of a Kubernetes Operator [Web](https://www.jaegertracing.io/)
JAAS          | "Juju as a Service". Simplifies configuration, scaling, and operation of complex software by deploying workloads to cloud provider of choice. 
Kail          | "Kubernetes tail", tail Docker logs for all matched pods [GitHub](https://github.com/boz/kail)
Kops          | Provision Kubernetes clusters from the command-line on AWS. [GitHub](https://github.com/kubernetes/kops)
Ksonnet       | Templating language for creating Kubernetes objects [[K8S 12](../sources/README.md#k8s-12)]
Kube-AWS      | "Kubernetes on AWS" console tool provided by CoreOS which deploys a Kubernetes cluster using AWS CloudFormation [GitHub](https://github.com/kubernetes-incubator/kube-aws)
Kube-monkey   | Kubernetes version of Netflix's Chaos Monkey, intended to stress-test systems [GitHub](https://github.com/asobti/kube-monkey)
Kube-ops-view | "Kubernetes Operational View", read-only system dashboard for multiple Kubernetes clusters. [GitHub](https://github.com/hjacobs/kube-ops-view)
Kube-shell    | Enables command auto-completion and auto-suggestion, inline documentation about executed commands [GitHub](https://github.com/cloudnativelabs/kube-shell)
Kube-state-metrics | metrics [GitHub](https://github.com/kubernetes/kube-state-metrics)
Kubeadm       | Bootstrap best-practice Kubernetes clusters on existing infrastructure. [GitHub](https://github.com/kubernetes/kubeadm)
Kubebox       | Provides a console interface for a Kubernetes cluster that allows monitoring of pod resource usage, cluster monitoring, logs, etc. [GitHub](https://github.com/astefanutti/kubebox)
Kubeless      | FaaS framework [GitHub](https://github.com/kubeless/kubeless)
Kubens        | switch between Kubernetes namespaces [GitHub](https://github.com/ahmetb/kubectx)
Kubernetes Dashboard  | general-purpose web-based UI for Kubernetes clusters [GitHub](https://github.com/kubernetes/dashboard#kubernetes-dashboard)
Kubespray     | Provides Ansible roles for Kubernetes deployment and configuration. [GitHub](https://github.com/kubernetes-incubator/kubespray)
Kubetail      | Small bash script that aggregates logs from multiple pods. [GitHub](https://github.com/aks/kubetail)
Kubewatch     | Publishes Kubernetes events to Slack.  [GitHub](https://github.com/bitnami-labs/kubewatch)
Linkerd       | open-source service mesh tool that facilitates traffic between services [Web](https://linkerd.io/) [GitHub](https://github.com/linkerd/linkerd2)
Minikube      | Conveniently launch a single-node Kubernetes cluster inside a locally hosted VM. Used to try out and learn the platform. [GitHub](https://github.com/kubernetes/minikube)
Nuclio        | serverless project that support high-performance events and large amounts of data [Web](https://github.com/nuclio/nuclio)
OpenFaaS      | framework to manage serverless functions on Docker Swarm or Kubernetes and analyze metrics [GitHub](https://github.com/openfaas/faas)
OpenWhisk     | open-source FaaS platform that can be deployed on-premise or on the cloud [Web](https://console.bluemix.net/openwhisk/)
PowerfulSeal  | chaos engineering tool, similar to Chaos Monkey [GitHub](https://github.com/bloomberg/powerfulseal)
Prometheus    | Go-to tool for Kubernetes monitoring. [Web](https://prometheus.io/)
Replex        | namesake governance and cost management platform [Web](https://www.replex.io/)
Searchlight   | Kubernetes operator for Icinga [GitHub](https://github.com/appscode/searchlight)
Sonobuoy      | Diagnostic tool and basis for the **Conformance** suite [Web](https://sonobuoy.io/) [[K8S 12](../sources/README.md#k8s-12)]
Sumo Logic App | metrics [Web](https://www.sumologic.com/application/kubernetes/)
Test-infra    | suite of tools for testing [GitHub](https://github.com/kubernetes/test-infra)
Trireme       | Kubernetes Network Policies [GitHub](https://github.com/aporeto-inc/trireme-kubernetes)
Twistlock     | monitoring and security [Web](https://www.twistlock.com/)
Velero        | formerly (Heptio Ark) [GitHub](https://github.com/heptio/velero)
Virtual-Kubelet | Kubernetes Kubelet implementation that masquerades as a kubelet for the purposes of connecting Kubernetes to other APIs [Web](https://virtual-kubelet.io/)
Weave Scope   | Automatically generate applications and infrastructure topologies which identify application performance bottlenecks. [Web](https://www.weave.works/oss/scope/)

[[29](README.md#sources)]
