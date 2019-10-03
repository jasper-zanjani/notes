# Containers
A VM has to emulate a full hardware stack, boot an operating system, and then launch your app. It's a virtualized hardware environment. Docker containers function at the application layer and skip all the steps VMs take.\
A container provides a type of virtualization just like VMs, but container offer **process** isolation while a hypervisor provides **hardware** isolation.[[30](#sources)]

Table of contents
:---
[Container runtimes](#container-runtimes)
[Linux containers](#linux-containers)
[Windows containers](#windows-containers)
[Glossary](#glossary)
[Sources](#sources)

## Container runtimes
- [ Docker ](docker.md)
- [ Podman ](podman.md)
- [ containerd ](#containerd)
- CRI-O
- frakti
#### containerd
Containerd is a container runtime that manages all the resources related to containers. It sits right below the Kubernetes `kubelet` as well as Docker. Beneath containerd there is the runtime, most commonly **runC**, which is the reference implementation of the OCR open container.\
Containerd was originally designed to interface directly with runC so that Docker could be decoupled from the actual containers. Since then, containerd grew to include image resources, which means it could entirely replace Docker. [[22](#sources)]\
## Linux containers
- **LXC**: Well-known, established low-level toolset with templates, library and language bindings.
- **LXD**: Offers a user experience similar to virtual machines, using a single command-line tool to manage containers, but using Linux containers instead. At its core lies a privileged daemon that exposes a REST API over a local Unix socket as well as over the network.
- **LXCFS**
## Windows containers
Windows server containers, like Linux containers, package dependencies. Windows offers two base images: **Windows Server Core** and **Nano Server**.\
The differences between Windows and Linux containers originate in historical differences. Linux was developed with the goal of producing a stable kernel with a consistent application binary interface and limited syscalls in order to move applications from other commercial Unix-type OSes. In contrast, Windows was developed to be an entire operating system, not just a kernel, including APIs like Win16 and Win32. The border between kernel and user mode was always much blurrier than in Linux. The concept of a **session** was innovated to handle the problem of what to do when multiple users are making inputs simultaneously. A Windows container is essentially equivalent to a headless session.\
Windows Server containers are focused on running headless applications.\
Every Windows installation has its own security database that is handled by the local security agent, and for every new user a unique binary identifier is generated that is unique to that database. Containers also create their own database upon creation. Without Active Directory, every container is completely isolated. Active Directory has been around since Windows Server 2000, but the replication interval for AD databases is prohibitively long, which is too long for container applications. The solution is Group-Managed Service Accounts, which is a security principal that can be used by multiple users and computers. This turned out to be perfect for containers, but it still required the machine to be domain-joined, which is something we wanted to avoid for containers because of the delay in Active Directory replication, as mentioned.\
For the network control plane, configuration was exposed in what's called the **Host Networking Service (HNS)**. Another service called the **Virtual Networking Platform** made it possible to write granular rules governing how individual packets are forwarded, rewritten, and how policy is applied to them. This functions analogously to `iptables`. KubeProxy was updated to talk to the HNS to set those up.\
Today, our focus is on being able to run the Kubelet and KubeProxy, which allows you to add a Windows node to an existing Kubernetes cluster.\
There is support to share the GPU with what's already on the node, which allows you to use some DirectX APIs.
The container has to run Windows Server 2016 or newer. So the first question to ask is, can this application work on Windows Server 2016 or 2019? The application can't rely on a component that has since been deprecated, but some frameworks like .NET Core offer compatibility for versions of .NET as early as 2.0, which dates back to the early 2000s.\
Windows container types include **Helium**, **Argon**, **Krypton**, and **Xenon**.
#### Update container when Microsoft issues an update
On Patch Tuesday, open up the Docker file and update the top line that says "from". Then rebuild and redeploy it. Microsoft has begun implementing security patches into updated Windows container images that are available on Docker Hub. Pull those down and rebuild the container. Deploy it and shut down the old one.
## Glossary
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
## Sources
1. "Microsoft Azure for Beginners: Introduction - Scott Duffy [YouTube](https://www.youtube.com/watch?v=3gnLwSI4d9E)
2. "AZ-103 Microsoft Azure Administrator" [Microsoft](https://www.microsoft.com/en-us/learning/exam-az-103.aspx)
3. "Fundamentals of Kubernetes on Microsoft Azure - BRK2396" [YouTube](https://www.youtube.com/watch?v=gmN732qN1Gg)
4. "Kubernetes in 5 mins" [YouTube](https://www.youtube.com/watch?v=PH-2FfFD2PU)
5. "What is Kubernetes" [YouTube](https://www.youtube.com/watch?v=F-p_7XaEC84)
6. "An Introduction to Kubernetes [Web](https://www.digitalocean.com/community/tutorials/an-introduction-to-kubernetes)
7. "Linux containers". [Web](https://linuxcontainers.org/)
8. "Beginner's Guide to Containers and Orchestration". [Web](https://www.udemy.com/linux-academy-beginners-guide-to-containers-and-orchestration/)
9. "A Practical Introduction to Container Terminology". [Red Hat](https://developers.redhat.com/blog/2018/02/22/container-terminology-practical-introduction/)
10. "Kubernetes Co-Founders On K8’s Past, Present and Future (It Ain’t All Pretty)". [Web](https://thenewstack.io/learning-from-the-success-of-kubernetes/)
11. "Podman: Managing pods and containers in a local container runtime". [Web](https://developers.redhat.com/blog/2019/01/15/podman-managing-containers-pods/)
12. Interactive Podman Tutorial. [katacoda.com](https://www.katacoda.com/courses/containers-without-docker/running-containers-with-podman)
13. "Helium, Argon, Krypton & Xenon: The Noble Gases of Windows Containers". [Web](http://www.alex-ionescu.com/publications/syscan/syscan2017.pdf): 2017/05.
14. "Understanding Kubernetes Storage". [Web](https://www.enterprisestorageforum.com/cloud-storage/kubernetes-storage.html): 2019/08/16.
15. "Windows Server Containers". [K8S 70](../sources/README.md#k8s-70). 
16. "Intro: Operator Framework BoF - Diane Mueller & Sebastian Pahl, Red Hat". [YouTube](https://youtu.be/8k_ayO1VRXE): 2018/12/16.
17. "Standardized Glossary". [Kubernetes](https://kubernetes.io/docs/reference/glossary/?all=true)
18. "Kubernetes Design Principles: Understand the Why". [YouTube](https://www.youtube.com/watch?v=ZuIQurh_kDk)
19. 'Kubernetes Deconstructed: Understanding Kubernetes by Breaking It Down". [YouTube](https://www.youtube.com/watch?v=90kZRyPcRZw)
20. "Concepts: Operator Pattern". [Kubernetes](https://kubernetes.io/docs/concepts/extend-kubernetes/operator/)
21. "Google Cloud Services Platform, with Aparna Sinha". [K8S](../sources/README.md#k8s-13)
22. "containerd, with Derek McGowan". [K8S](../sources/README.md#k8s-71)
23. "Understanding the Cloud Native Ecosystem". [PodCTL](../sources/README.md#podctl-5)
24. "First Alpine Linux Container". [Play with Docker classroom](https://training.play-with-docker.com/ops-s1-hello/)
25. "Doing More with Docker Images". [Play with Docker classroom](https://training.play-with-docker.com/ops-s1-images/)
26. "Best practices for writing Dockerfiles". [Docker](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
27. "A Practical Introduction to Docker Containers". [Red Hat](https://developers.redhat.com/blog/2014/05/15/practical-introduction-to-docker-containers/): 2014/05/15.
28. "A Practical Introduction to Docker Container Terminology". [Red Hat](https://developers.redhat.com/blog/2016/01/13/a-practical-introduction-to-docker-container-terminology/): 2016/01/13.
29. "50+ useful [ Kubernetes ](k8s.md) tools". [DZone](https://dzone.com/articles/50-useful-kubernetes-tools?utm_medium=feed&utm_source=feedpress.me&utm_campaign=Feed:%20dzone): 2018/06/03.
30. "Kubernetes 101-Concepts, Potential, and lots of container orchestrations". [Hacker Noon](https://hackernoon.com/kubernetes-101-concepts-and-why-it-matters-g27536x2?source=rss): 2019/10/02.
