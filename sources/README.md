# Sources
## Abbreviations
\#      | Links
:---    | :---
A-E     | [AAP](#admin-admin-podcast) [ADAC](adac.md) [AZ-103](az-103.md) [ADP](#azure-devops-podcast) [AID](#adventures-in-devops) [AWST](#aws-techchat) [BNP](#bash-notes-for-professionals) [BPR](#bash-pocket-reference) [BRM](#bash-reference-manual) [BSD](#bsd-now) [CB](#coding-blocks) [CCP](ccp.md) [CGF](#chengdu-gaming-federation) [CLKF](clkf.md) [CL](#choose-linux) [CR](#coder-radio) [CSFM](#cloudskillsfm) [CSP](csp.md) [DD](#devops-and-docker) 
F-P     | [FP](#fluent-python) [FPLC](fplc.md) [FPP](#functional-python-programming) [GL](#going-linux) [GCPC](gcpc.md) [HPR](#hacker-public-radio) [IMWS](imws.md) [ITP](#itprotv) [JDG](jdg.md) [JNP](jnp.md) [JSJ](#javascript-jabber) [K8S](#kubernetes-podcast-from-google) [LALOS](lalos.md) [LAN](#linux-action-news) [LJ](#linux-journal) [LNL](#late-night-linux) [LSSP](lssp.md) [LU](#linux-unplugged) [MintCast](#mintcast) [NSM](#new-stack-makers) [PodCTL](#podctl) [PBX](pbx.md) [PGL](pgl.md) 
R-Z     | [RunAs](#runas-radio) [s&a](s-and-a.md) [SY](#syntax) [TP](#talk-python) [TechSNAP](#techsnap) [UE](#user-error) [USLAH](ulsah.md) [WSAC](wsac.md) [WSAF](wsaf.md) [YUG](yug.md)

## Notes
### Admin Admin Podcast
[Web](http://www.adminadminpodcast.co.uk/) [Twitter](https://twitter.com/admadmpodcast)

### Adventures in DevOps
[Web](https://devchat.tv/adventures-in-devops/)
#### AID 9
Nell recommends starting with Digital Ocean's tutorials to learn cloud technologies.

### AWS Podcast
[Web](https://aws.amazon.com/podcasts/aws-podcast/) Notes: 
\#          | Title     | Links
:---        | :---      | :---
329         | Choosing a Database Platform | [Notes](#aws-329)
#### AWS 329
The historical motivation for the invention of relational databases was minimizing the cost of storage by eliminating duplication. At the turn of the century, as storage cost fell, other database paradigms emerged, producing **7 fundamental categories of data**:
  - **Relational** data
  - **Key-value** data: divided into **key-to-blob** storage and **key-to-document** storage
  - **In-memory** storage: i.e. Redis, MemCacheD
  - **Graph** storage
  - **Search**: introspection into natural-language queries, i.e. **Managed Elastic Search**
  - **Time-series**
  - **Ledger**

The recommended approach to select a database is to determine the **access pattern** needed. Organizations should be open to encouraging innovation by using more than one database, rather than overemphasizing reducing the cost of infrastructure by insisting on using a single, monolithic database that may not be suited to every business purpose.

### AWS TechCHAT
\#          | Title     | Links
:---        | :---      | :---
35          | Deep dive on databases  | Notes
53          | SysAdmin & Hybrid Cloud Special | [Notes](#awst-53)
#### AWST 53
AWS CLI and AWS Tools for PowerShell are available for AWS.

### Azure DevOps Podcast
[Web](http://azuredevopspodcast.clear-measure.com/)

\#          | Title     | Links
:---        | :---      | :---
57          | Craig Loewen on the Windows Subsystem for Linux story | [Notes](#adp-57) [Web](http://azuredevopspodcast.clear-measure.com/craig-loewen-on-the-windows-subsystem-for-linux-devops-story-episode-57)
48          | Steve Smith on DevOps quality | [Notes](#adp-48) [Web](http://azuredevopspodcast.clear-measure.com/steve-smith-on-devops-quality-episode-48)
#### ADP 57
**Windows Subsystem for Linux (WSL)** is shipped with Windows and tied to the Windows release cycle. Windows ships from a single massive codebase, of which WSL is part. WSL was written mostly in C and and has 3 million monthly active users.\
WSL implements **user services** to connect to WSL distros and to run Windows-native applications like CMD.exe. WSL implements a **9P Protocol** file server to provide seamless integration of the virtualized Linux filesystem and that of the Windows host.\
In version 1, WSL worked under a **translation architecture** where system calls were translated to NT kernel calls. This meant that applications that used system calls that were newer or more difficult to implement, like GUI applications or Docker, did not run on v1. But WSL2 shifted to a **lighweight virtualization** model using the Linux kernel. Now Docker runs on WSL2 and GUI applications can run by using an X server.\
WSL v1 is available on Azure VMs if **nested virtualization** is enabled. WSL2 support is forthcoming.
#### ADP 48
Several different types of automated tests
- **Unit tests** test functionality without dependencies (i.e. file system, database, network, etc). `XUnit` is recommended for .NET Core
- **Integration tests** 
- **Functional tests** test the full stack of the system, except for the client. ASP .NET core functional tests are easily written.
- **UI tests** simulate user interaction using systems like Selenium, which uses .NET, or Cypress, which uses JavaScript.

Test coverage metrics are a double-edged sword, because they incentivize developers to "gold-plate" their code by implementing spurious tests which pass easily.
**Cyclomatic complexity** refers to the number of pathways through the code, measured at the method level.
### Bash Notes for Professionals
[Web](goalkicker.com)
### Bash Pocket Reference
[ Robbins, Arnold ](#arnold-robbins). **Bash Pocket Reference (2nd ed.)**.
### Bash Reference Manual
[ Ramey, Chet ](#chet-ramey) and [ Fox, Brian ](#brian-fox). **Bash Reference Manual**
### BSD Now
[Web](https://www.bsdnow.tv/) [Subreddit](https://www.reddit.com/r/bsdnow) [FaceBook](https://www.facebook.com/BSDNow/) [Twitter](https://twitter.com/bsdnow)
### CloudSkills.fm
[Web](https://cloudskills.fm/) 
\#          | Title     | Links
:---        | :---      | :---
2           | Infrastructure as Code in the Cloud | [Notes](#csfm-2) [Web](https://cloudskills.fm/002)
3           | Cloud Migration Strategy | [Notes](#csfm-3) [Web](https://cloudskills.fm/003)
5           | Automation with PowerShell  | [Notes](#csfm-5) [Web](https://cloudskills.fm/005)
29          | Building Serverless Apps on AWS | [Notes](#csfm-29) [Web](https://cloudskills.fm/029)
40          | What to Do When You Don't Have Experience | [Notes](#csfm-40) [Web](https://cloudskills.fm/040)
41          | Kuberneetes Q&A | [Notes](#csfm-41) [Web](https://cloudskills.fm/041)
#### CSFM 2
- An alternative job title to DevOps Engineer is "Infrastructure Developer"
- Infrastructure as Code and automation are terms that refer to the use of deployment templates to provision resources reproducibly.
- Automation templates are especially useful when testing software. The development environment for that version of the application can be provisioned and comprehensively tested before risking the production environment.
- Go for the Azure Solutions Architect Expert, since it demonstrates the skills needed
#### CSFM 3
- Azure's Site Recovery has been a game-changer that AWS has had no answer for, until Amazon acquired CloudEndure, which had offered a similar service for multiple cloud providers.
- "architectural patterns"
#### CSFM 5
- A good project idea is to spin up a Windows 10 VM in Azure
#### CSFM 29
> "Unless you're an infrastructure company, infrastructure is overhead."
- Guest Yan Cui discusses AWS Lambda's market dominance.
- It makes no sense to worry about migration from one cloud provider to another before it becomes an issue: CAPEX (capital expenditure) vs. OPEX (operating expenditure). And transferring Compute is easy.
- Although Lambda is capable, there are hard limits. For example, there is a limit on increasing concurrency of 500 per minute. So highly spiky workloads that exceed that limit make Lambda less appealing.
- When analyzing costs, we shouldn't fall for the fallacy of thinking that minimizing the AWS bill is equivalent to reducing infrastructure costs. Some solutions that may drastically reduce monthly costs on AWS, such as Lambda, may actually require much higher costs to support from competent engineers.
#### CSFM 40
Mike talks about his own work history, starting as a customer service representative working at AOL in the 1990s, then working tech support at Gateway, ultimately ending up in Phoenix where he remains today. 
> [Getting certified] is a no-brainer. If you're not looking at certifications and you're thinking about doing this career transition, that's a mistake. So don't even get into this if you're not willing to do the certifications at this point because it's way too important, there are way too many people who are looking for that in these job openings.

#### CSFM 41
Interview with Anthony Nocentino, Data Platform MVP\
Certified Kubernetes Administrator (CKA) certification from the Linux Foundation\
Appliation monitoring for containers is wide open because most applications will still write to STDERR\
Pfeiffer's experience with Kubernetes has not included manually creating a cluster, but rather using managed services\
Containers are how applications are going to be deployed for the next 5 to 10 years\

### Choose Linux
[Web](https://chooselinux.show) [Twitter](https://twitter.com/chooselinux)
### Coder Radio
[Web](https://coder.show/) [Twitter](https://twitter.com/coderradioshow) Notes: [325](#cr-325) [361](#cr-361)
#### CR 361
[Notes](https://coder.show/361): 2019/06/10.
  - Apple changing from bash to zsh for the next release of Mac OS X
  - Designing UIs in Swift
    - Functional programming
#### CR 325
[Notes](https://coder.show/325): 2018/09/07.
- Wes Payne is a big fan of Clojure, in particular with the professionalism of the clojure community. Clojure is not as closely tied to Java as it was in its inception when it was a "JAR", but it still needs a JVM.

### DevOps and Docker
[Web](https://podcast.bretfisher.com/)

\#          | Title     | Links
:---        | :---      | :---
\-          | K8s setup, GitOps, and more! | [Notes](#dd-gitops) [Web](https://podcast.bretfisher.com/episodes/k8s-setup-gitops-and-more)
\-          | Alpine Linux  | [Notes](#dd-alpine) [Web](https://podcast.bretfisher.com/episodes/alpine-linux-as-a-base-image-is-it-really-secure)
\-          | Learning Kubernetes | [Notes](#dd-learning-k8s) [Web](https://podcast.bretfisher.com/episodes/learning-kubernetes-with-jerome-petazzoni)

#### DD GitOps
DevOps is essentially about making software development faster. GitOps is a **style** of doing DevOps where the git protocol is used to log changes to infrastructure, which is stored as YAML or other automation scripts. 
#### DD Alpine
Alpine may have an undeserved reputation for security, since it is tricky to scan containers running it.
#### DD Learning K8S
No notes taken.
### Destination Linux
[Web](http://destinationlinux.com/)
### Fluent Python
[Author](#luciano-ramalho)
### Functional Python Programming
[Author](#steven-lott)
### Going Linux
[Host](#larry-bushey) [Web](https://goinglinux.com) [Twitter](https://twitter.com/goinglinux)
### Hacker Public Radio
[Web](http://hackerpublicradio.org/) 
\#          | Title     | Links
:---        | :---      | :---
1938        | How I prepare HPR shows | [Notes](#hpr-1938) [Web](hackerpublicradio.org/eps/hpr1938**full**shownotes.html) 
2107        | Makefiles for everyday use | [Notes](#hpr-2107) [Web](https://hackerpublicradio.org/eps.php?id=2107)
#### HPR 1938
- `make`
#### HPR 2107
- `make`
### ITPro.TV
[Web](https://itpro.tv/)

\#          | Title     | Links
:---        | :---      | :---
Courses     |           | [Azure](itp-azure.md) [Linux+](itp-linux-plus.md) [LPIC-1](itp-lpic.md) [PowerShell](itp-ps.md) Windows Server [MCSA](itp-winsrv-mcsa.md) [MTA](itp-winsrv-mta.md) [101](itp-ws101.md)
### JavaScript Jabber
### Kubernetes Podcast from Google
[Twitter](http://twitter.com/mkubernetespod) [Email](mailto:kubernetespodcast@google.com) [Web](https://kubernetespodcast.com)

\#          | Title     | Links
:---        | :---      | :---
5           |           | Notes [Web](https://kubernetespodcast.com/episode/005-documentation/)
12          | Kubernetes Origins, with Joe Beda | [Notes](#k8s-12) [Web](https://kubernetespodcast.com/episode/012-kubernetes-origins/)
13          | Google Cloud Services Platform, with Aparna Sinha | [Notes](#k8s-13) [Web](https://kubernetespodcast.com/episode/013-gke-and-cloud-services-platform/)
67          | Orka, with Chris Chapman | [Notes](#k8s-67) [Web](https://kubernetespodcast.com/episode/067-orka/)
70          | Windows Server Containers, with Patrick Lang | [Notes](#k8s-70) [Web](https://kubernetespodcast.com/episode/070-windows-server-containers/)
71          | `containerd` with Derek McGowan | [Notes](#k8s-71) [Web](https://kubernetespodcast.com/episode/071-containerd/)

#### K8S 71
Containerd is a container runtime that manages all the resources related to containers. It sits right below the Kubernetes `kubelet` as well as Docker. Beneath containerd there is the runtime, most commonly **runC**, which is the reference implementation of the OCR open container.

Containerd was originally designed to interface directly with runC so that Docker could be decoupled from the actual containers. Since then, containerd grew to include image resources, which means it could entirely replace Docker.

`ctr` is an unsupported tool that used for debugging containerd.

Container metrics (logging and monitoring information) is exposed through **Prometheus**.

#### K8S 70
Windows server containers, like Linux containers, package dependencies. Windows offers two base images: **Windows Server Core** and **Nano Server**. Windows Server containers are focused on running headless applications.

The differences between Windows and Linux containers originate in historical differences. Linux was developed with the goal of producing a stable kernel with a consistent application binary interface and limited syscalls in order to move applications from other commercial Unix-type OSes. In contrast, Windows was developed to be an entire operating system, not just a kernel, including APIs like Win16 and Win32. The border between kernel and user mode was always much blurrier than in Linux. The concept of a **session** was innovated to handle the problem of what to do when multiple users are making inputs simultaneously. A Windows container is essentially equivalent to a headless session.

Every Windows installation has its own security database that is handled by the local security agent, and for every new user a unique binary identifier is generated that is unique to that database. Containers also create their own database upon creation. Without Active Directory, every container is completely isolated. Active Directory has been around since Windows Server 2000, but the replication interval for AD databases is too long for container applications. The solution is **Group-Managed Service Accounts**, which is a **security principal** that can be used by multiple users and computers. This turned out to be perfect for containers, but it still required the machine to be domain-joined, which is something we wanted to avoid for containers because of the delay in replication, as mentioned.

The initial target for Windows Server 2016 was support for Docker and Docker Swarm, which implemented a **network plugin** model and a **storage plugin** model, which were deferred but still tightly coupled to the Docker engine. In Kubernetes, network and storage management was handled by the kubelet calling additional plugins like the **Container Network Interface** or the **Container Storage Interface** with a different order of operations. This necessitated the development of network namespaces in Windows, which were released in 2017 and 2018 for Windows Server, which allowed the creation of multiple containers with the same IP and the same virtual NIC. Storage also necessitated the creation of a mapped volume using symlinks in order to create a filesystem.

For the network control plane, configuration was exposed in what's called the **Host Networking Service (HNS)**. Another service called the **Virtual Networking Platform** made it possible to write granular rules governing how individual packets are forwarded, rewritten, and how policy is applied to them. This functions analogously to `iptables`. KubeProxy was updated to talk to the HNS to set those up.

If you have a Windows 10 machine, Docker for Windows can run containers on Linux or Windows, and you can switch between them using the system tray icon. Go to [aka.ms/windowscontainers](https://aka.ms/windowscontainers). If you don't have a machine, all the major cloud providers allow you to form a Windows Server or Windows 10 VM.

Get connected with the Kubernetes community repo, every SIG has a folder in there which links to our weekly meetings and agenda. Get an invite to the Kubernetes Slack server and join the SIG Windows Slack channel.
#### K8S 67
Orka is a virtualization layer for Mac build infrastructure offered by hosting company MacStadium. iPhone architecture and security make building for that platform very different. Virtual Mac instances first became possible in Snow Leopard, but the EULA allows only 2 VMs per machine. MacStadium is an enterprise-scale cloud for Apple. A typical lifecycle for an iOS build begins with a simulator, followed by a physical test, typically in a build farm of physical iOS devices.
#### K8S 13
**Cloud Services Platform**: Google hybrid cloud software, comprising a set of software and services that work both on-premises and in GCP and are managed by GCP\
3 components that form the core of Cloud services Platform:
  - **GKE On-Prem**: Kubernetes for on-premises environments.
  - **GKE Policy Manager**: allows admins to gain centralized control over the hybrid environment
  - **Istio**

**Kubernetes Operators**: allow you to deploy and manage applications on Kubernetes clusters, such as Spark Operator, Airflow Operator, etc.
#### K8S 12
Kubernetes started at Google at the same time as Google Compute Engine, as developers thought deeply about how to improve the value proposition of virtual machines. Joe Beda was an early user of Borg, and him and others pushed for it to be released as a product. However, it was decided that Borg and Omega specifically were too closely aligned with internal Google products, so a new open-source product was imagined, although there was internal resistance to opening it up to the community completely.

Red Hat's buy-in early in the history of Kubernetes by deciding to use Kubernetes as a basis. Namespaces are called projects in OpenShift.

Joe Beda is an advocate of a microkernel, minimalist architecture for the Kubernetes core with additional features layered on top.

### Late Night Linux
\#          | Title     | Links
:---        | :---      | :---
71          |           | [Notes](#lnl-71)
65          |           | [Notes](#lnl-65)
#### LNL 71
- 
#### LNL 65
- KDE App page
- Google Stadia
- How can the FLOSS community take advantage of the opportunity presented by the sunsetting of Windows 7?
### Linux Action News
[Web](https://linuxactionnews.com/) [Twitter](https://twitter.com/linuxactionnews)
### Linux Journal
\#          | Title     | Links
:---        | :---      | :---
283         |           | [Notes](#lj-283)
#### LJ 283
- **ClusterShell**: Python tool and library to connect a set of nodes in parallel through SSH
### Linux Unplugged
[Twitter](https://twitter.com/LinuxUnplugged) [Web](https://linuxunplugged.com/)

\#          | Title     | Links
:---        | :---      | :---
320         | RHELhide | [Notes](#lu-320) [Web](https://linuxunplugged.com/320)
318         | Manjaro Levels Up | [Notes](#lu-318) [Web](https://linuxunplugged.com/318)
315         | Wayland Buddies | [Notes](#lu-315) [Web](https://linuxunplugged.com/315)
#### LU 320
- Ubuntu Touch on the Pinebook
- CentOS 8.1905
- CentOS Stream: Sits between Fedora and RHEL, providing a rolling preview of future RHEL features.
- Transforming the development experience within CentOS
- Reinventing Home Directories
- Twitch becomes premiere sponsor of OBS
#### LU 318
Philip Muller discussed the transition of Manjaro to a for-profit business model.

Chrome OS has become Linux for the masses, in particular now that support for Linux applications has improved, and it has had great success penetrating the education market.

CloudReady OS allows you to install Chrome OS on other hardware. It is available in free and paid commercial editions. They are essentially reselling a version of Chrome OS with their commercial support which can be installed on any x86 machine. It offers a choice of Linux distros, or even a combination of them, including Debian.

Chris reflects on how Chrome OS has evolved since he first tried it in 2014. It has become much more complicated and powerful since its launch, and grudgingly admits he likes it, in particular how users can login with their own unique Linux environments.
#### LU 289
Clear Linux
### MintCast
#### MintCast 318.5
`rxync` is the backend to many file syncing frontends\
Resilio Sync started as BTSync or BitTorrent Sync, and it has a checkered past because the developers tried to convert it to a paid commercial product after it had been a popular open-source alternative to `rsync` for years. 
### New Stack Makers
[Storage in a DevOps World](#storage-in-a-devops-world)
#### Storage in a DevOps World
[Web](https://thenewstack.io/storage-in-a-devops-world/)\
The term "DevOps" began to gain currency in 2009-2010, before the emergence of containers. Features like self-healing, scalability, resource monitoring, automatic DNS management, etc have since become built-in to Kubernetes.
### PodCTL
Description | Links
:---        | :---
Contact     | [Web](http://podcast.podctl.com/) [Twitter](https://www.twitter.com/podctl) 
5           | [Notes](#podctl-5) [Web](http://podcast.podctl.com/110399/563052-understanding-the-cloud-native-ecosystem)
#### PodCTL 5
**Pivotal Container Services (PKS)** started as a project between Google and Pivotal originally called "Kubo" which takes the BOSH installer from Cloud Foundry Foundation and installs a Kubernetes instance. Kubernetes doesn't have an official installer, and many open-source solutions have been implemented. **Time to Success** is a metric used by developers that want to test out new products or technologies. **MiniKube** is the most commonly used Kubernetes Engine for installation on a laptop for experimentation or learning purposes. **MiniShift** is to OpenShift what MiniKube is to Kubernetes. Both of these tools provide a **single-node**, **single-master** environment.

**Kubeadm** is the official Kubernetes installer from the CNCF, but it is not widely used because it doesn't deploy multiple Kubernetes masters. Kubernetes has the concept of masters that provide the **control plane** and **workers** which run Kubelets. In reality, the masters are just Kubernetes worker nodes that are running only Kubernetes core services, and those are the first pods that are deployed by K8S. **Kargo** builds highly available containers.

There are two main types of container engine installers: normal ones that install locally and interactively ask what Linux host is desired, and thne another type that interfaces with an IaaS provider and demands resources from it. The tools typically defined as configuration management tools like Chef, Ansible, Puppet, Salt, and Terraform are also typically used to package containerized software and can perform orchestration. Kargo, for example, uses Terraform to build the nodes and then Ansible to do the actual installation. OpenShift's installer uses Ansible.

**Prometheus** has become the go-to open-source monitoring and alerting tool. Other tools include the **ELK stack**, the **EFK stack**, and **Loggly**.

### RunAs Radio
[Web](http://www.runasradio.com/) [Twitter](https://twitter.com/RunAsRadio)

\#  | Title     | Links
:---| :---      | :---
616 | 2018 Recap with Jeffrey Snover | [Notes](#runas-616) [Web](http://runasradio.com/Shows/Show/534)
534 | Azure Stack Update with Jeffrey Snover | [Notes](#runas-534) [Web](http://runasradio.com/Shows/Show/534)
510 | The DevOps Handbook with Gene Kim | [Notes](#runas-510) [Web](http://runasradio.com/Shows/Show/510)
471 | Just Enough Admin and Windows Server 2016 with Jeffrey Snover | [Notes](#runas-471) [Web](http://runasradio.com/Shows/Show/471)
467 | DevOps in 2015 with Gene Kim | [Notes](#runas-467) [Web](http://runasradio.com/Shows/Show/467)
455 | Chef, PowerShell, and DSC with Steven Murawski | [Notes](#runas-455) [Web](http://runasradio.com/Shows/Show/455)
408 | PowerShell Past and Future with Lee Holmes | [Notes](#runas-408) [Web](http://runasradio.com/Shows/Show/408)
406 | DevOps in 2015 with Gene Kim | [Notes](#runas-406) [Web](http://runasradio.com/Shows/Show/406)
384 | DSC Update with Jeffrey Snover | [Notes](#runas-384) [Web](http://runasradio.com/Shows/Show/406)
357 | Talking DevOps with Gene Kim  | [Notes](#runas-357) [Web](http://runasradio.com/Shows/Show/357)

#### RunAs 616
- **Just Enough Admin** ("GEE-ah") breaking things into microservices
- **Azure Stack** is an appliance. 
- **AWS Outpost** is a new product that competes directly with Azure Stack.

#### RunAs 534
3 enduring use cases for **Azure Stack**
1. Edge/disconnected: for cases where connectivity is absent or latency is too great for use of the public cloud (i.e. submarines, cruise ships, factory floors)
2. Compliance and data sovereignty: deploying cloud services in countries where the public cloud has not yet established a Region.
3. Modernization of apps: to support mainframe applications and progressively update their functionality by implementing the cloud piecemeal ("strangler" design pattern)

#### RunAs 510
_The DevOps Handbook_ took five years to write and contains 48 concrete case studies highlighting how DevOps practices translate to faster and better software development, happier employees, and a healthier bottom line.\
While architects used to be ignored by working personnel, now architecture is a top-level leadership concern.\
Conway's Law dictates that adding more people will result in a more complex product.\
Richard Campbell is working on something called the "Humanitarian ToolBox"

#### RunAs 471
> "Really, the DevOps revolution is taking some of the things that we did in the Japanese quality revolution of the 1980s, which is all manufacturing-focused, and we're taking a lot of those principles and applying them to IT." -Jeffrey Snover

#### RunAs 467
Gene and Robert fawn over Jeffrey Snover, father of PowerShell, and Mark Russinovitch, CTO of Azure.\
On the topic of the recent DevOps Summit, Gene remarks that the emphasis of the conference has switched from a techhnical to an organization change management focus. He observes that security and management people are now trying to educate themselves on the new philosophy.\

#### RunAs 455
Chef is an automation platform, not just single-node configuration management.
#### RunAs 408
PowerShell, known originally as Monad, was the brain child of Jeffrey Snover. It started as an effort introduce the functionality of a unifying command-line interface that maintained and interfaced directly with Windows objects, skirting around the painful process of parsing and reparsing text output in bash.\
The **administrative development model** prior to PowerShell consisted of 2 phases:
1. Discovery, where an admin explored the GUI to accomplish a task
2. Documentation, for which there was no structure and which took the form of Word documents, blog posts, etc.

The practice used to be that GUI utilities had to have console programs programmed with custom-made expressive languages to support the tool from the command line. PowerShell offers a way to replace these with cmdlets.\
**OneGet** (now known as the **PackageManagement** module in the PowerShell Gallery) was mentioned in the context of virtualizing Windows Servers.

#### RunAs 406
Gene Kim recaps 2014 and looks forward to the publication of his book _The DevOps Handbook_.
> "DevOps is not just for the unicorns, it's for the horses as well." -Gene Kim
> "If you like solving problems, I cannot think of a better place to be than in a DevOps initiative." -Gene Kim

#### RunAs 384
CI/CD vs. DevOps: accelerate end to end software delivery process\
2 subcomponents of the problem: delivering feedback to the developer\
"Combined CI/CD



### Syntax
[Web](https://syntax.fm/) [Twitter](https://twitter.com/syntaxfm)
### Talk Python
Contact | Notes
:---    | :---
[Web](https://talkpython.fm) [Twitter](https://twitter.com/TalkPython) | [213](#tp-213) [216](#tp-216) [224](#tp-224)
#### TP 213
WebAssembly and CPython\
Web Assembly is gaining steam in the developer community, and several Web Assembly projects are in train. **Pyodide** is the **SciPy** stack into web assembly. The interpreter is on the order of 40MB, which is still too large for convenient use on the web. Compiling to CPython may not be the correct answer in the future as technology evolves. A straight Python to web-assembly compilation target would have some difficulties, but it is possible. If you turn Web Assembly as a general interpreter layer, various possibilities open up.
#### TP 216
Digging into Visual Studio Code
#### TP 224
12 lessons from 100 days of code\
Netlify will watch changes to a GitHub repo as a continuous delivery platform for static sites.
### TechSNAP
[Web](https://techsnap.systems) [Twitter](https://twitter.com/techsnapsystems)
#### TechSNAP 413
- Google support of **DNS Over HTTPS (DOH)** is getting resistance from ISPs because it will remove an optic into users' web traffic
- CloudFlare has offered a completely free VPN named **WARP**, but it doesn't provide private web browsing because the `mmproxy` service is being used to embed your true IP in the TCP headers.
- CloudFlare has announced support for **HTTP3** and **QUIC**, which allows you to reuse the same TCP session when loading multiple elements on one webpage. It has not yet been implemented by major browsers. The canary build of Chrome does support it, only on Mac and Windows, when executed with particular command-line arguments.
- Startpage.com works as an anonymizing wrapper to Google, sending search queries to Google while removing personalizing information from the request. They also offer an email service called StartMail. The company is private and from the Netherlands.
- Google has extended support for some Chromebook models in the wake of criticism of their six and half-year "death sentence".
- Google Quantum Supremacy

### TGI Kubernetes
\#  | Title     | Links
:---| :---      | :---
1   | A Quick Tour | [Notes](tgik-01.md) [YouTube](https://youtu.be/9YYeE-bMWv8)
91  | kpack     | [Notes](#tgik-91) [YouTube](https://youtu.be/4zkRX9PSJ5k)

#### TGIK 91
**Endpoint Slices** are a new feature in K8S 1.16 which provide a scalable and extensible alternative to Endpoints resources.\
**kpack** is a K8S-native system for using **Buildpacks**: a structured, opinionated method of building container images. Buildpacks were first conceived by Heroku in 2011, and since then they have been adopted by Cloud Foundry and other PaaS (GitLab, Knative, Deis, Dokku, and Drie). kpack is a less opinionated alternative to Buildpack assocaited with Pivotal.\
Dockerfiles can be a bit too flexible sometimes.
### User Error
[Web](https://error.show/) [Twitter](https://twitter.com/usererrorshow)
