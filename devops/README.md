[DevOps monitoring tools]: https://opensource.com/downloads/devops-monitoring-guide "The open source guide to DevOps monitoring tools"
[What Is DevOps]: https://dzone.com/articles/what-is-devops-an-intersection-of-culture-processe "What is DevOps? An intersection of culture, processes, and tools"
[ULSAH]: # 'Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._'

# DevOps
> DevOps is a way to deliver software with shared pain and responsibility.

The term "DevOps" began to gain currency in 2009-2010, before the emergence of containers. DevOps was a necessary response in infrastructure to the quickening pace of software development that emerged after the emergence of the Agile manifesto. <sup>[dzone.com][What is DevOps]</sup>

Features like self-healing, scalability, resource monitoring, automatic DNS management, etc have since become built-in to Kubernetes. <sup>[linuxcontainers.org](linuxcontainers.org)</sup>

DevOps provides the cultural and tooling advantage a company needs in order to deliver software more quickly. <sup>[dzone.com](https://dzone.com/articles/devsecops-explained-in-5-minutes "DevSecOps explained in 5 minutes")</sup>

#### Concepts
[ansible]: https://github.com/jasper-zanjani/notes/master/devops/ansible.md 'ansible&#10;Agentless configuration management and automation tool using YAML templates, developed by Red Hat'
[artifact]: # 'artifact&#10;packaged software ready for deployment, produced after code is brought through the build process'
[Bosun]: # 'Bosun&#10;Pull-based alerting tool developed by Stack Exchange and written in Golang. Redis is used to store state and metadata.&#10;"The open source guide to DevOps monitoring tools"'
[Cabot]: # 'Cabot&#10;Pull-based alerting tool that stores alerting data in a Postgres database as well as a Redis cache.&#10;Named after its creator\'s dog, developed by Arachnys for Christmas when its developers became frustrated with Nagios. Cabot can integrate with Google Calendar for on-call rotations, a feature called Rota.&#10;"The open source guide to DevOps monitoring tools"'
[CD]: # 'Continuous Delivery (CD)&#10;Taking code to artifact, then provisioning cloud environment to deploy it'
[CI]: # 'Continuous Integration (CI)&#10;Taking code to artifact'
[containerd]: # 'containerd&#10;Container runtime that sits right below the Kubernetes kubelet as well as Docker.&#10;Beneath containerd there is the runtime, most commonly RunC, which is the reference implementation of the OCR open container. Containerd was originally designed to interface directly with RunC so that Docker could be decoupled from the actual containers. Since then, containerd grew to include image resources, which means it could entirely replace Docker.&#10;"containerd, with Derek McGowan". Kubernetes Podcast.'
[CRI-O]: https://cri-o.io 'CRI-O&#10;lightweight container runtime for Kubernetes&#10;Previously known as OCID, OCI-compliant runtime.'
[declarative]: # 'declarative&#10;code that describes the state to be achieved'
[Fluentd]: # 'Fluentd&#10;Log aggregator written in C and Ruby and adopted as an **Incubating** project by the CNCF that has become a replacement for Logstash in many contexts.&#10;Fluentd has a robust plugin system with over 500 plugins that allow quick and easy integration with different data sources and outputs. In Kubernetes, each pod has a Fluentd "sidecar".&#10;"The open source guide to DevOps monitoring tools"'
[Frakti]: https://github.com/kubernetes/frakti 'Frakti&#10;Hypervisor-based container runtime for Kubernetes'
[Graphite]: # 'Graphite&#10;Push-based system, where applications push data into the Carbon component which stores data in the Whisper database&#10;"The open source guide to DevOps monitoring tools"'
[InfluxDB]: # 'InfluxDB&#10;Uses a a key-value pair system ("tags") to add dimensionality to metrics and a "system similar to the log-structured merge tree" for storage.&#10;Uses an open core model and forms part of the "TICK" stack. Core version is self-contained within a single host, but the commercial version has a distributed architecture.&#10;"The open source guide to DevOps monitoring tools"'
[InfluxQL]: # 'InfluxQL&#10;Query language associated with InfluxDB&#10;"The open source guide to DevOps monitoring tools"'
[LXC]: # 'LXC&#10;Well-known, established low-level Linux container toolset with templates, library, and language bindings'
[LXCFS]: # 'LXCFS&#10;'
[LXD]: # 'LXD&#10;Offers a user experience similar to VMs, using a single command-line tool to manage containers, but using Linux containers instead. At its core lies a privileged daemon that exposes a REST API over a local Unix socket as well as over the network.'
[OpenTSDB]: # 'OpenTSDB&#10;"Open source time-series database", stores metrics in Hadoop&#10;"The open source guide to DevOps monitoring tools"'
[Operation]: # 'Operation&#10;small-scale configuration changes and checks used by a configuration management to achieve a particular state on a machine&#10;Operations differ from commands in that they:&#10;  - are idempotent&#10;  - know when they change the system\'s actual state&#10;  - know when the system state needs to be changed&#10;  - report results to the configuration management system&#10;  - are cross-platform&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 836'
[procedural]: # 'procedural&#10;code that describes actions to take'
[Prometheus]: # 'Prometheus&#10;The most well-recognized time-series monitoring solution for cloud-native applications. It was created by Matt Proud and Julius Volz and sponsored by SoundCloud, hosted now within the CNCF.&#10;Prometheus is a **pull**-based system that uses local configuration to describe the endpoints to collect from and the collection interval. Each endpoint has a client to collect the data and update it upon request.&#10;"The open source guide to DevOps monitoring tools"'
[PromQL]: # 'PromQL&#10;Query language associated with Prometheus&#10;"The open source guide to DevOps monitoring tools"'
[Whisper]: # 'Whisper&#10;Database used by Graphite which is lossy but fixed-size (metrics lose resolution over time)&#10;"The open source guide to DevOps monitoring tools"'
[environment]: # 'environment&#10;Grouping of client machines that implement a variation of multiple aspects of a base configuration&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 839'
[configuration management]: # 'configuration management&#10;Software that automates the management of operating systems on a network.&#10;Mark Burgess developed CFEngine in 1993, considered the first configuration management software.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 841'
[bundle]: # 'bundle&#10;Collection of operations that perform a specified function, typically defined by a directory whose name defines the name of the bundle.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 839'
[facts]: # 'facts&#10;Information about the current configuration of the system, gathered by configuration management systems.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 838'
[handler]: # 'handler&#10;Operations automatically triggered in response to an event or situation, rather than as part of a baseline configuration&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 838'
[binding]: # 'binding&#10;Associate specific sets of operations to specific hosts or groups thereof.&#10;Nemeth, Evi. _Unix and Linux System Administration Handbook, 5th ed._: 838'

[artifact][artifact] &bull;
[Bosun][Bosun] &bull;
[Cabot][Cabot] &bull;
[CI][CI]/[CD][CD] &bull;
[containerd][containerd] &bull;
[Fluentd][Fluentd] &bull;
[Graphite][Graphite] &bull;
[InfluxDB][InfluxDB] ([InfluxQL][InfluxQL]) &bull;
[OpenTSDB][OpenTSDB] &bull;
[Prometheus][Prometheus] ([PromQL][PromQL]) &bull;
[Whisper][Whisper] 

###### Configuration management concepts
[Ansible][ansible] &bull;
[Binding][binding] &bull;
[Bundle][bundle] &bull;
[Configuration management][configuration management] &bull;
[Declarative][declarative] and [procedural][procedural] code &bull;
[Environment][environment] &bull;
[Facts][facts] &bull;
[Handler][handler] &bull;
[Operation][operation] &bull;
Chef &bull;
Puppet &bull;
Salt &bull;

###### Container runtime concepts
[CRI-O][CRI-O] &bull;
[Frakti][Frakti] &bull;
[LXC][LXC] &bull;
[LXCFS][LXCFS] &bull;
[LXD][LXD] &bull;

#### Contents
[CI/CD](#cicd) &bull;
[Container runtimes](#container-runtimes) &bull;
[Culture](#culture) &bull;
[Docker](docker.md) &bull;
[Kubernetes](k8s.md) &bull;
[Linux containers](#linux-containers) &bull;
[Podman](podman.md) &bull;
[Vagrant](vagrant.md) &bull;
[Windows containers](#windows-containers) &bull;
[YAML](yaml.md)

## Tooling
Traditionally, developers had incentives that were not aligned with those of operations who were to use the software. DevOps attempts to fuse development and operations, with the goal of aligning development with revenue generation.

There is an agreed-upon set of tools and concepts that most companies use with regard to DevOps. The end-goal is **end-to-end process automation**, a digital pipeline that moves bits around in assembly line-like fashion.

Most DevOps practices can be applied via effective tooling. Various software stacks can be composed together from modular components that have emerged as both open-source and commercial products.

Types of observability tools <sup>[opensource.com][DevOps monitoring tools]</sup>
- **Metrics aggregation**: time-ordered data collected at a consistent interval, allowing advanced calculations and predictive analytics to be applied
- **Log aggregation**: 
- **Alerting/visualizations**
- **Distributed tracing**

###### Monitoring
Metrics aggregation is primarily time-series data, which has the following features: <sup>[opensource.com][DevOps monitoring tools]</sup>

- **Counter**: numeric values that only increase (total number of web requests, visitors, etc)
- **Gauges**: numeric value that can increase or decrease (CPU, network, and memory usage, threads, etc)
- **Quantiles**: allow better understanding of data than mean or other statistical functions that don't account for uneven distributions and outliers ("percentile")
- **Histograms**: sample of observations

## Learning
The Foundational Layer is composed of Three technologies that individually take a lifetime to master. Learning these skills represent an eternal commitment.
1. Linux
2. Python (progressing to Golang)
3. AWS (progressing to GCP)

Once you have learned the Foundational Layer, learn Real-world skills 
- **Configure**: Terraform (progressing to [Ansible][ansible])
- **Version**: Git and GitHub (progressing to GitLab)
- **Package**: [Docker][] (progressing to Lambda)
- **Deploy**: Jenkins (progressing to CodeDeploy)
- **Run**: ECS (progressing to Kubernetes)
- **Monitor**: ELK Stack (progressing to [Prometheus][Prometheus])


## Culture
> "DevOps is not at all about getting code to production, but rather getting ideas into production and failing quick." <sup>[dzone.com](https://dzone.com/articles/what-is-devops-an-intersection-of-culture-processe "What is DevOps? An intersection of culture, processes, and tools")</sup>

DevOps culture is centered around collaboration and small multidisciplinary teams that bridge traditional gaps between infrastructure and software development personnel. Teams focus on competencies instead of rules and continuous learning. DevOps principles are oriented to business outcomes.

#### Three Ways of DevOps
DevOps involves 3 main patterns, called the **"Three Ways"** of DevOps:

1. **Systems thinking**: visualized as flow from left to right as of an idea to production. Managing this flow is referred to as **global optimization** or **bottleneck reduction**. This perspective emphasizes that the performance of the whole system is more important than the importance of a specific department
2. **Amplifying feedback loops**: visualized as flow from right to left, enhancement and shortening of feedback loops such that corrections are made fast and continuously. 
3. **Continuous learning**: analogous to the culture of *kaizen* in Toyota, which inspired the Lean software development methodology and by extension the practice of DevOps. Organizations should be brave enough to continuously experiment and bring about new innovations.

## Containers
A VM has to emulate a full hardware stack, boot an operating system, and then launch your app. It's a virtualized hardware environment. Docker containers function at the application layer and skip all the steps VMs take.

A container provides a type of virtualization just like VMs, but container offer **process** isolation while a hypervisor provides **hardware** isolation.
<sup>[opensource.com](https://opensource.com/article/19/8/moving-files-linux-depth "How to move a file in Linux")</sup>

VMs and containers solve different problems. Hardware virtualization was originally developed to make fuller use of physical servers by enabling the over-provisioning of resources and reusing them at the end of the virtual server lifecycle. By consolidating physical hardware, you can scale and automate virtual infrastructure. Containers, on the other hand, are actually closer to the bare metal and provie almost no overhead. LXC, inspired by Solaris Containers and FreeBSD jails, enables a virtual environment with its own process and network space using kernel-native **cgroups** functionality. This created **process isolation** using namespaces, preventing processes from monitoring or affecting those running in another container or on the host machine. 
<sup>[tecmint.com](https://www.tecmint.com/linux-tree-command-examples/ "Linux tree command usage examples for beginners")</sup>

### Windows containers
Windows server containers, like Linux containers, package dependencies. Windows offers two base images: **Windows Server Core** and **Nano Server**.

The differences between Windows and Linux containers originate in historical differences. Linux was developed with the goal of producing a stable kernel with a consistent application binary interface and limited syscalls in order to move applications from other commercial Unix-type OSes. In contrast, Windows was developed to be an entire operating system, not just a kernel, including APIs like Win16 and Win32. The border between kernel and user mode was always much blurrier than in Linux. The concept of a **session** was innovated to handle the problem of what to do when multiple users are making inputs simultaneously. A Windows container is essentially equivalent to a headless session.

Windows Server containers are focused on running headless applications.

Every Windows installation has its own security database that is handled by the local security agent, and for every new user a unique binary identifier is generated that is unique to that database. Containers also create their own database upon creation. Without Active Directory, every container is completely isolated. Active Directory has been around since Windows Server 2000, but the replication interval for AD databases is prohibitively long, which is too long for container applications. The solution is Group-Managed Service Accounts, which is a security principal that can be used by multiple users and computers. This turned out to be perfect for containers, but it still required the machine to be domain-joined, which is something we wanted to avoid for containers because of the delay in Active Directory replication, as mentioned.

For the network control plane, configuration was exposed in what's called the **Host Networking Service (HNS)**. Another service called the **Virtual Networking Platform** made it possible to write granular rules governing how individual packets are forwarded, rewritten, and how policy is applied to them. This functions analogously to `iptables`. KubeProxy was updated to talk to the HNS to set those up.

Today, our focus is on being able to run the Kubelet and KubeProxy, which allows you to add a Windows node to an existing Kubernetes cluster.

There is support to share the GPU with what's already on the node, which allows you to use some DirectX APIs.

The container has to run Windows Server 2016 or newer. So the first question to ask is, can this application work on Windows Server 2016 or 2019? The application can't rely on a component that has since been deprecated, but some frameworks like .NET Core offer compatibility for versions of .NET as early as 2.0, which dates back to the early 2000s.

Windows container types include **Helium**, **Argon**, **Krypton**, and **Xenon**.

#### Update container when Microsoft issues an update
On Patch Tuesday, open up the Docker file and update the top line that says "from". Then rebuild and redeploy it. Microsoft has begun implementing security patches into updated Windows container images that are available on Docker Hub. Pull those down and rebuild the container. Deploy it and shut down the old one.

## CI/CD
[CI][CI]/[CD][CD] basically means running scripts to build pipelines that build applications. <sup>[hackernoon.com](https://hackernoon.com/understanding-the-basic-concepts-of-cicd-73t3zec "Understanding the basic concepts of CI/CD")</sup>

## Configuration Management
[Configuration management (CM)][configuration management] software automates the management of operating systems on a network.
<sup>[Nemeth][ULSAH]: 833</sup>

Configuration management, which captures desired state in the form of [declarative][declarative] code, contrasts with the traditional approach to sysadmin automation, sometimes jokingly referred to as the **"snowflake"** model of system administration. That model depended on homegrown shell scripts (written [procedurally][procedural]) supplemented by fire fighting when they fail. Configuration management systems administer machines by applying a series of [operations][operation], which can vary in scope.
<sup>[Nemeth][ULSAH]: 834</sup>

Competing configuration management systems use incompatible conceptual models that also differ in terminology. <sup>[Nemeth][ULSAH]: 835</sup>

Operations can be [bundled][bundle] together, run in [response to events][handler], or [bound][binding] to specific clients which can be grouped by their [environment][environment] (traditionally development, test, production, etc). <sup>[Nemeth][ULSAH]: 838</sup>
