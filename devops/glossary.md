# Glossary
Term                        | Description
:---                        | :---
Aporeto                     | security policies [Web](https://www.aporeto.com/)
Argon                       | Windows container with isolation of object manager, network virtualization
Ark                         | see **Velero** [[K8S 12](../sources/README.md#k8s-12)]
base image                  | image with no parent layer. Easily identified in a Dockerfile since it follows the `FROM` directive. [[28](sources.md)]
Bootkube                    | Launch self-hosted Kubernetes clusters. [GitHub](https://github.com/kubernetes-incubator/bootkube)
Bosun                       | alert management system open-sourced by Stack Exchange and written in Golang [[31](sources.md)]
Cabot                       | alert management system created by Arachnys [[31](sources.md)]
cAdvisor                    | collecting metrics [GitHub](https://github.com/google/cadvisor)
Cluster Store               | one of the 4 Kubernetes master server components [[35](sources.md)]
Conjure-up                  | Canonical product that allows you to deploy The Canonical Distribution of Kubernetes on Ubuntu. 
`conmon`                    | utility used by **Podman** to keep the PTY terminal of containers open in order to execute commands
Consul                      | Hashicorp service networking solution [Web](https://www.hashicorp.com/products/consul/)
container                   | form of lightweight virtualization; low overhead wrapper around an application or set of services
Container Runtime Interface | (CRI) [[22](sources.md)]
Container Storage Interface | Kubernetes component that facilitates storage [[14](sources.md)]
Contour                     | ingress controller based on Envoy to solve Northwest problems [[K8S 12](../sources/README.md#k8s-12)]
Controller                  | control loop that watches the shared state of the cluster through the `apiserver` and makes changes attempting to move the current state towards the desired state. [[17](sources.md)]
CoreDNS                     | set of plugins written in Go which perform DNS functions [Web](https://coredns.io/)
ctr                         | unsupported tool used to debug containerd [[22](sources.md)]]
`dockviz`                   | CLI tool that allows inspection of container image layers [[28](sources.md)]
domain specific language (DSL) | computer language specialized to a particular application domain (cf. **general-purpose language**)
Dynatrace                   | monitoring [Web](https://www.dynatrace.com/support/help/technology-support/cloud-platforms/kubernetes/installation-and-operation/further-integrations/connect-your-kubernetes-clusters-to-dynatrace/#configure-activegate)
EFK stack                   | **Elasticsearch**, **Fluentd**, and **Kibana** [[23, 31](sources.md)]
ELK stack                   | **Elasticsearch**, **Logstash**, and **Kibana**: most popular open source log aggregation tool on the market [[31](sources.md)]
Etcd                        | open-source key-value data store for configuration data that can be accessed by cluster nodes.<br/>Consistent and highly-available key value store used as Kubernetes's backing store for all cluster data. [[17, 36](sources.md)]
Fission                     | serverless framework for Kubernetes [Web](https://fission.io/)
Fluentd                     | log aggregation tool that often replaces **Logstash** [[31](sources.md)]
Fnproject                   | FaaS framework for Kubernetes, written in Go [Web](http://fnproject.io/)
Funktion                    | FaaS framework for Kubernetes, now sandboxed [GitHub](https://github.com/funktionio/funktion)
general-purpose language (GPL) | 
Gimbal                      | ingress controller based on Envoy to solve Northwest problems [[K8S 12](../sources/README.md#k8s-12)]
GitOps                      | managing Kubernetes through YAML files that are updated through version control systems like Git [[30](sources.md)]
Grafana                     | visualization tool [[31](sources.md)]
Graphite                    | push-based metrics aggregation tool [[31](sources.md)]
Helium                      | Windows container with a virtualized filesystem and registry
Helm                        | Kubernetes package manager [GitHub](https://github.com/kubernetes/helm)
Heptio                      | Seattle-based startup founded by Kubernetes co-creators [Joe Beda](../people.md) and [ Craig McLuckie ](../people.md) that was acquired by VMware in late 2018. [[34](sources.md)]
Host Networking Service     | how configuration is exposed in Windows containers
InfluxDB                    | monitoring database included as part of **TICK** stack, offered in a single-node open-source version and a commercial version that supports clustering and scaling [[31](sources.md)]
InfluxQL                    | query language associated with **InfluxDB**
infra container             | component of a **Podman** pod that holds namespaces associated with the pod itself, allowing it to connect to containers
IronFunction                | FaaS framework for Kubernetes, written in Go [GitHub](https://github.com/iron-io/functions)
Istio                       | service mesh [[Web](https://istio.io/)]
JAAS                        | "Juju as a Service". Simplifies configuration, scaling, and operation of complex software by deploying workloads to cloud provider of choice. 
Jaeger                      | implementation of a Kubernetes Operator [Web](https://www.jaegertracing.io/)
Kail                        | "Kubernetes tail", tail Docker logs for all matched pods [GitHub](https://github.com/boz/kail)
Kargo                       | [[23](sources.md)]
Kibana                      | [[31](sources.md)]
Kops                        | Provision Kubernetes clusters from the command-line on AWS. [GitHub](https://github.com/kubernetes/kops)
Krypton                     | Windows container with a thin Hyper-V partition
Ksonnet                     | Templating language for creating Kubernetes objects [[K8S 12](../sources/README.md#k8s-12)]
Kube Master                 | primary control point for distributed orchestration across different nodes [[14](sources.md)]
Kubernetes Master           | collection of 4 processes that run on the master node: **Kube-apiserver**, **Cluster Store**, **Kube-controller-manager**, and **Kube-scheduler** [[35](sources.md)]
Kube-apiserver              | one of the 4 Kubernetes master server components, exposes the Kubernetes API and frontend for the Kubernetes control plane. [[17](sources.md)]
Kube-AWS                    | "Kubernetes on AWS" console tool provided by CoreOS which deploys a Kubernetes cluster using AWS CloudFormation [GitHub](https://github.com/kubernetes-incubator/kube-aws)
Kube-controller-manager     | one of the 4 Kubernetes master server components, embeds the core control loops shipped with Kubernetes. [[17](sources.md)]<br/>Manages **controllers** like `namespace-controller`, `deployment-controller`, etc.[[19](sources.md)]
Kube-monkey                 | Kubernetes version of Netflix's Chaos Monkey, intended to stress-test systems [GitHub](https://github.com/asobti/kube-monkey)
Kube-ops-view               | "Kubernetes Operational View", read-only system dashboard for multiple Kubernetes clusters. [GitHub](https://github.com/hjacobs/kube-ops-view)
Kube-proxy                  | one of the 2 Kubernetes node server components, makes services real. [[19](sources.md)]<br/>network proxy that runs on each node in your cluster, implementing part of the Kubernetes Service concept [[17](sources.md)]
Kube-scheduler              | one of the 4 Kubernetes master sever components [[35](sources.md)]
Kube-shell                  | Enables command auto-completion and auto-suggestion, inline documentation about executed commands [GitHub](https://github.com/cloudnativelabs/kube-shell)
Kube-state-metrics          | metrics [GitHub](https://github.com/kubernetes/kube-state-metrics)
Kubeadm                     | "cube-admin": a tool for quickly installing Kubernetes and setting up a secure cluster [[17](sources.md)] [GitHub](https://github.com/kubernetes/kubeadm)
Kubectl                     | "cube-control" or "cube-cuddle": CLI tool for communicating with a Kubernetes API server<br/>Kubectl is a command line interface for running commands against Kubernetes clusters. `kubectl` looks for a file named config in $HOME/.kube/ but other kubeconfig files can be specified by setting the `$KUBECONFIG` environment variable or setting the `--kubeconfig` flag.[[17](sources.md)]
Kubelet                     | one of the 2 Kubernetes node server components that acts as the main contact point for each Kubernetes node with the cluster group<br/>An agent that runs on each node in the cluster. It makes sure that containers are running in a pod. [[17](sources.md)]<br/>Makes containers real.[[19](sources.md)]
Kubebox                     | Provides a console interface for a Kubernetes cluster that allows monitoring of pod resource usage, cluster monitoring, logs, etc. [GitHub](https://github.com/astefanutti/kubebox)
Kubeless                    | FaaS framework [GitHub](https://github.com/kubeless/kubeless)
Kubens                      | switch between Kubernetes namespaces [GitHub](https://github.com/ahmetb/kubectx)
Kubernetes API              | application that serves Kubernetes functionality through a RESTful interface and stores the state of the cluster. [[17](sources.md)]
Kubernetes Dashboard        | general-purpose web-based UI for Kubernetes clusters [GitHub](https://github.com/kubernetes/dashboard#kubernetes-dashboard)
Kubernetes Marketplace      | 
Kubespray                   | Provides Ansible roles for Kubernetes deployment and configuration. [GitHub](https://github.com/kubernetes-incubator/kubespray)
Kubetail                    | Small bash script that aggregates logs from multiple pods. [GitHub](https://github.com/aks/kubetail)
Kubewatch                   | Publishes Kubernetes events to Slack.  [GitHub](https://github.com/bitnami-labs/kubewatch)
layer                       | represents changes between itself and a parent layer in a container image. [[28](sources.md)]
Linkerd                     | open-source service mesh tool that facilitates traffic between services [Web](https://linkerd.io/) [GitHub](https://github.com/linkerd/linkerd2)
Loggly                      | [[23](sources.md)]
Logstash                    | [[31](sources.md)]
MiniKube                    | most commonly used Kubernetes Engine for local installation for learning or experimentation purposes [[23](sources.md)]
MiniShift                   | lightweight OpenShift instance intended for installation on a local host for learning or experimentation purposes [[23](sources.md)]
Minikube                    | Conveniently launch a single-node Kubernetes cluster inside a locally hosted VM. Used to try out and learn the platform. [GitHub](https://github.com/kubernetes/minikube)
namespace                   | tool for separating groups of repositories [[28](sources.md)]<br/>equivalent to **projects** in **OpenShift** [K8S 12](../sources/README.md)
Node                        | system resources that perform tasks as passigned by **Kube Master** [[14](sources.md)]
Nuclio                      | serverless project that support high-performance events and large amounts of data [Web](https://github.com/nuclio/nuclio)
Octant                      | Kubernetes cluster application monitoring tool, written in Go and developed by **Vmware Tanzu** [[Web](https://github.com/vmware-tanzu/octant)]
OpenFaaS                    | framework to manage serverless functions on Docker Swarm or Kubernetes and analyze metrics [GitHub](https://github.com/openfaas/faas)
OpenShift                   | Red Hat PaaS offering, providing an abstraction layer on top of Kubernetes. It comes in 4 flavors: **Origin**, **Online**, **Dedicated**, and **Enterprise**
OpenTSDB                    | "open source time-series database" metrics aggregation tool that stores data in Hadoop [[31](sources.md)]
OpenWhisk                   | open-source FaaS platform that can be deployed on-premise or on the cloud [Web](https://console.bluemix.net/openwhisk/)
Operator                    | software extensions to Kubernetes that make use of **custom resources** to manage applications and their components. [[20](sources.md)]<br/>Pattern for building K8S native applications that leverages and extends the K8S API (usable with **`kubectl`**) and runs on K8S as containers [[16](sources.md)]<br/>Allow you to deploy and manage applications on Kubernetes clusters. [[21]]
Operator Lifecycle Manager  | helps you to install, update, and manage the lifecycle of all Operators and associated services running on clusters [[16](sources.md)]
Operator Metering           | enable usage reporting for Operators and resources within K8S. <br/>Intended to aid **chargeback** of infrastructure costs to tables, services, etc. especially in the context of a cloud infrastructure. [[16](sources.md)]
Operator Pattern            | a system design that links a **Controller** to one or more custom resources. [[17](sources.md)]
Operator SDK                | allows developers to build, package, and test an Operator based on expertise without requiring deep knowledge of K8S API [[16](sources.md)]
Pod                         | collection of one or more containers sharing an IP address, network, and storage
PowerfulSeal                | chaos engineering tool, similar to Chaos Monkey [GitHub](https://github.com/bloomberg/powerfulseal)
Prometheus                  | pull-based metrics aggregation tool, considered the gold standard and written in Golang [Notes](README.md#prometheus) [Web](https://prometheus.io/) [[23, 31](sources.md)]
PromQL                      | query language associated with **Prometheus** [Notes](README.md#prometheus)
Registry Server             | Docker centralized image management server [[27](sources.md)]
Replex                      | namesake governance and cost management platform [Web](https://www.replex.io/)
SDK                         | software development kit
Scheduler                   | master server component that looks for pods without nodes and assigns them when found. When a node recognizes a pod belongs to it because Scheduler has assigned it to it, then it queries itself to see if the pod has been deployed. [[18](sources.md)]
Searchlight                 | Kubernetes operator for Icinga [GitHub](https://github.com/appscode/searchlight)
Secret                      | stores sensitive information, such as passwords, tokens, and keys [[17](sources.md)]
Sonobuoy                    | Diagnostic tool and basis for the **Conformance** suite [Web](https://sonobuoy.io/) 
StatsAgg                    | alerting tool developed by Pearson [[31](sources.md)]
Sumo Logic App              | metrics [Web](https://www.sumologic.com/application/kubernetes/)
Test-infra                  | suite of tools for testing [GitHub](https://github.com/kubernetes/test-infra)
TICK stack                  | Telegraf, **InfluxDB**, Chronograf, and Kapacitor [[31](sources.md)]
Time to success             | metric used by developers that want to test out new products or technologies [[23](sources.md)]
Trireme                     | Kubernetes Network Policies [GitHub](https://github.com/aporeto-inc/trireme-kubernetes)
Twistlock                   | monitoring and security [Web](https://www.twistlock.com/)
Velero                      | open source tool that facilitates backup, restoration, and migration of Kubernetes cluster resources and persistent volumes, formerly (**Heptio** Ark) [Web](https://github.com/heptio/velero)
Virtual Networking Platform | what Windows containers use to implement firewall rules, analogous to `iptables` in Linux and Linux containers
Virtual-Kubelet             | Kubernetes Kubelet implementation that masquerades as a kubelet for the purposes of connecting Kubernetes to other APIs [Web](https://virtual-kubelet.io/)
VMware Tanzu                | GitHub organization announced at VMworld 2019 that will incorporate **Velero**, **Sonobuoy**, and **Octant** among other projects [[33](sources.md)] [ [Web](https://github.com/vmware-tanzu) ]
Whisper                     | database associated with **Graphite** [Notes](README.md#prometheus)
Xenon                       | Argon Windows container with Base OS image
