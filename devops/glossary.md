# Glossary
Term                        | Description
:---                        | :---
Argon                       | Windows container with isolation of object manager, network virtualization
base image                  | image with no parent layer. Easily identified in a Dockerfile since it follows the `FROM` directive. [[28](#sources)]
`conmon`                    | utility used by **Podman** to keep the PTY terminal of containers open in order to execute commands
container                   | form of lightweight virtualization; low overhead wrapper around an application or set of services
Container Storage Interface | Kubernetes component that facilitates storage [[14](#sources)]
Container Runtime Interface | (CRI) [[22](#sources)]
Controller                  | control loop that watches the shared state of the cluster through the `apiserver` and makes changes attempting to move the current state towards the desired state. [[17](#sources)]
ctr                         | unsupported tool used to debug containerd [[22](#sources)]]
`dockviz`                   | CLI tool that allows inspection of container image layers [[28](#sources)]
domain specific language (DSL) | computer language specialized to a particular application domain (cf. **general-purpose language**)
EFK stack                   | [[23](#sources)]
ELK stack                   | Elasticsearch, Logstash, Kibana 
`etcd`                      | configuration store which stores configuration data that can be accessed by cluster nodes.<br/>Consistent and highly-available key value store used as Kubernetes's backing store for all cluster data. [[17](#sources)]
general-purpose language (GPL) | 
GitOps                      | managing Kubernetes through YAML files that are updated through version control systems like Git [[30](#sources)]
Helium                      | Windows container with a virtualized filesystem and registry
Helm                        | Kubernetes package manager
Host Networking Service     | how configuration is exposed in Windows containers
infra container             | component of a **Podman** pod that holds namespaces associated with the pod itself, allowing it to connect to containers
Istio                       | 
Kube Master                 | primary control point for distributed orchestration across different nodes [[14](#sources)]
`kube-apiserver`            | component on the master that exposes the Kubernetes API and frontend for the Kubernetes control plane. [[17](#sources)]
`kube-controller-manager`   | kubernetes master server component that embeds the core control loops shipped with Kubernetes. [[17](#sources)]<br/>Manages **controllers** like `namespace-controller`, `deployment-controller`, etc.[[19](#sources)]
`kube-proxy`                | makes services real. [[19](#sources)]<br/>network proxy that runs on each node in your cluster, implementing part of the Kubernetes Service concept [[17](#sources)]
`kubeadm`                   | a tool for quickly installing Kubernetes and setting up a secure cluster [[17](#sources)]
`kubectl`                   | CLI tool for communicating with a Kubernetes API server<br/>Kubectl is a command line interface for running commands against Kubernetes clusters. `kubectl` looks for a file named config in $HOME/.kube/ but other kubeconfig files can be specified by setting the `$KUBECONFIG` environment variable or setting the `--kubeconfig` flag.[[17](#sources)]
`kubelet`                   | node server component that acts as the main contact point for each Kubernetes node with the cluster group<br/>An agent that runs on each node in the cluster. It makes sure that containers are running in a pod. [[17](#sources)]<br/>Makes containers real.[[19](#sources)]
Kubernetes API              | application that serves Kubernetes functionality through a RESTful interface and stores the state of the cluster. [[17](#sources)]
Kubernetes Marketplace      | 
Kargo                       | [[23](#sources)]
Krypton                     | Windows container with a thin Hyper-V partition
layer                       | represents changes between itself and a parent layer in a container image. [[28](#sources)]
Loggly                      | [[23](#sources)]
MiniKube                    | most commonly used Kubernetes Engine for local installation for learning or experimentation purposes [[23](#sources)]
MiniShift                   | lightweight OpenShift instance intended for installation on a local host for learning or experimentation purposes [[23](#sources)]
namespace                   | tool for separating groups of repositories [[28](#sources)]<br/>equivalent to **projects** in **OpenShift** [K8S 12](../sources/README.md)
Node                        | system resources that perform tasks as passigned by **Kube Master** [[14](#sources)]
OpenShift                   | Red Hat PaaS offering, providing an abstraction layer on top of Kubernetes. It comes in 4 flavors: **Origin**, **Online**, **Dedicated**, and **Enterprise**
Operator                    | software extensions to Kubernetes that make use of **custom resources** to manage applications and their components. [[20](#sources)]<br/>Pattern for building K8S native applications that leverages and extends the K8S API (usable with **`kubectl`**) and runs on K8S as containers [[16](#sources)]<br/>Allow you to deploy and manage applications on Kubernetes clusters. [[21]]
Operator Lifecycle Manager  | helps you to install, update, and manage the lifecycle of all Operators and associated services running on clusters [[16](#sources)]
Operator Metering           | enable usage reporting for Operators and resources within K8S. <br/>Intended to aid **chargeback** of infrastructure costs to tables, services, etc. especially in the context of a cloud infrastructure. [[16](#sources)]
Operator Pattern            | a system design that links a **Controller** to one or more custom resources. [[17](#sources)]
Operator SDK                | allows developers to build, package, and test an Operator based on expertise without requiring deep knowledge of K8S API [[16](#sources)]
Pod                         | collection of one or more containers sharing an IP address, network, and storage
Prometheus                  | has become the go-to open-source monitoring and alerting tool [[23](#sources)]
Registry Server             | Docker centralized image management server [[27](#sources)]
SDK                         | software development kit
Scheduler                   | master server component that looks for pods without nodes and assigns them when found. When a node recognizes a pod belongs to it because Scheduler has assigned it to it, then it queries itself to see if the pod has been deployed. [[18](#sources)]
Secret                      | stores sensitive information, such as passwords, tokens, and keys [[17](#sources)]
Time to success             | metric used by developers that want to test out new products or technologies [[23](#sources)]
Virtual Networking Platform | what Windows containers use to implement firewall rules, analogous to `iptables` in Linux and Linux containers
Xenon                       | Argon Windows container with Base OS image