# DevOps
\#      | Links
:---    | :---
A-Z     | [CI/CD](#cicd) [Container runtimes](#container-runtimes) [Culture](#culture) [Docker](docker.md) [Glossary](glossary.md) [Kubernetes](k8s.md) [Linux containers](#linux-containers) [Podman](podman.md) [Sources](sources.md) [Windows containers](#windows-containers) [YAML](yaml.md)

> DevOps is a way to deliver software with shared pain and responsibility.

The term "DevOps" began to gain currency in 2009-2010, before the emergence of containers. DevOps was a necessary response in infrastructure to the quickening pace of software development that emerged after the emergence of the Agile manifesto. [[39](sources.md)]\
Features like self-healing, scalability, resource monitoring, automatic DNS management, etc have since become built-in to Kubernetes. [[7](sources.md)]\
DevOps provides the cultural and tooling advantage a company needs in order to deliver software more quickly. [[44](sources.md)]

## CI/CD
CI/CD basically means running scripts to build pipelines that build applications.[[45](sources.md)]
- **Continuous Integration (CI)** is about taking code to **artifact**, which is the packaged software ready for deployment produced after code is brought through the build process. 
- **Continuous Delivery (CD)** refers to the stages of provisioning cloud environments to deploy the artifact.

## Culture
> "DevOps is not at all about getting code to production, but rather getting ideas into production and failing quick." [[39](sources.md)]

DevOps culture is centered around collaboration and small multidisciplinary teams that bridge traditional gaps between infrastructure and software development personnel. Teams focus on competencies instead of rules and continuous learning. DevOps principles are oriented to business outcomes. [[39](sources.md)]\
DevOps involves 3 main patterns, called the "Three Ways" of DevOps:
1. **Systems thinking**: visualized as flow from left to right as of an idea to production. Managing this flow is referred to as **global optimization** or **bottleneck reduction**. This perspective emphasizes that the performance of the whole system is more important than the importance of a specific department
2. **Amplifying feedback loops**: visualized as flow from right to left, enhancement and shortening of feedback loops such that corrections are made fast and continuously. 
3. **Continuous learning**: analogous to the culture of *kaizen* in Toyota, which inspired the Lean software development methodology and by extension the practice of DevOps. Organizations should be brave enough to continuously experiment and bring about new innovations.

## Tools
Traditionally, developers had incentives that were not aligned with those of operations who were to use the software. DevOps attempts to fuse development and operations, with the goal of aligning development with revenue generation.

There is an agreed-upon set of tools and concepts that most companies use with regard to DevOps. The end-goal is __endo-to-end process automation__, a digital pipeline that moves bits around in assembly line-like fashion.[[4](sources.md)]\
The Foundational Layer is composed of Three technologies that individually take a lifetime to master. Learning these skills represent an eternal commitment.[[4](sources.md)]\
1. Linux
2. Python (progressing to Golang)
3. AWS (progressing to GCP)

Once you have learned the Foundational Layer, learn Real-world skills [[4](sources.md)]:\
- **Configure**: Terraform (progressing to Ansible)
- **Version**: Git and GitHub (progressing to GitLab)
- **Package**: Docker (progressing to Lambda)
- **Deploy**: Jenkins (progressing to CodeDeploy)
- **Run**: ECS (progressing to Kubernetes)
- **Monitor**: ELK Stack (progressing to Prometheus)

## DevOps tools
Most DevOps practices can be applied via effective tooling. Various software stacks can be composed together from modular components that have emerged as both open-source and commercial products.\

Types of observability tools [[31](sources.md)]
- **Metrics aggregation**: time-ordered data collected at a consistent interval, allowing advanced calculations and predictive analytics to be applied
- **Log aggregation**: 
- **Alerting/visualizations**
- **Distributed tracing**

### Metrics aggregation ("monitoring") tools
Metrics aggregation is primarily time-series data, which has the following features: [[31](sources.md)]
- **Counter**: numeric values that only increase (total number of web requests, visitors, etc)
- **Gauges**: numeric value that can increase or decrease (CPU, network, and memory usage, threads, etc)
- **Quantiles**: allow better understanding of data than mean or other statistical functions that don't account for uneven distributions and outliers ("percentile")
- **Histograms**: sample of observations

#### Prometheus
The most well-recognized time-series monitoring solution for cloud-native applications. It was created by Matt Proud and Julius Volz and sponsored by SoundCloud, hosted now within the CNCF. [[31](sources.md)]\
Prometheus is a **pull**-based system that uses local configuration to describe the endpoints to collect from and the collection interval. Each endpoint has a client to collect the data and update it upon request.\
Prometheus includes an expression language for selecting and presenting data called **PromQL**. It also comes with **AlertManager** to handle alerts.

#### Graphite
Push-based system. Applications push data into Graphite's **Carbon** component which stores data in the **Whisper** database. [[31](sources.md)]\
Whisper is a lossy but fixed-size database, meaning the resolution of metrics will degrade over time.

#### InfluxDB
Uses an open core model (scaling and clustering cost extra), forming part of the **TICK** stack. Uses a key-value pair system ("tags") to add dimensionality to metrics. Uses a "system similar to a log-structured merge tree" for storage. [[31](sources.md)]\
Open-source InfluxDB system is self-contained within a single host, but the commercial version has a distributed architecture.\
InfluxDB includes the **InfluxQL** language for querying data.

#### OpenTSDB
"Open source time-series database" storing metrics in Hadoop. [ [31](sources.md) ]

### Log aggregation tools

#### Fluentd
Log aggregator written in C and Ruby and adopted as an **Incubating** project by the CNCF that has become a replacement for **Logstash** in many contexts. Fluentd has a robust plugin system with over 500 plugins that allow quick and easy integration with different data sources and outputs. In Kubernetes, each pod has a "Fluentd **sidecar**". [[31](sources.md)]

### Alert management tools
#### Bosun
Pull-based alerting tool developed by Stack Exchange and written in Golang. **Redis** is used to store state and metadata. [[31](sources.md)]
#### Cabot
Pull-based alerting tool that stores alerting data in a **Postgres** database as well as a **Redis** cache. Named after its creator's dog, developed by Arachnys for Christmas when its developers became frustrated with Nagios. Cabot can integrate with Google Calendar for on-call rotations, a feature called **Rota**. [[31](sources.md)]

## Containers
A VM has to emulate a full hardware stack, boot an operating system, and then launch your app. It's a virtualized hardware environment. Docker containers function at the application layer and skip all the steps VMs take.\
A container provides a type of virtualization just like VMs, but container offer **process** isolation while a hypervisor provides **hardware** isolation.[[30](#sources)]

## Container runtimes
- [ containerd ](#containerd): manages all the resources related to containers. It sits right below the Kubernetes `kubelet` as well as Docker. Beneath containerd there is the runtime, most commonly **runC**, which is the reference implementation of the OCR open container. Containerd was originally designed to interface directly with runC so that Docker could be decoupled from the actual containers. Since then, containerd grew to include image resources, which means it could entirely replace Docker. [[22](#sources)]\
- [ Docker ](docker.md)
- [ Podman ](podman.md)
- CRI-O
- frakti

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

