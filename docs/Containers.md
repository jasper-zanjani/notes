# Containers

Containers run applications in an **isolated namespace**, meaning it only has access to resources that are made available to it by the container runtime.
**Resource governance** means that a container has access only to a specified number of processor cycles, system memory, and other resources.
Containers allow applications to be packaged with their dependencies in **container images**, which will run the same regardless of underlying operating system or infrastructure and are downloaded from **container registries** like **Docker Hub**.
Container registries are not to be confused with **repositories**, which are subcomponents of registries.

<!-- #region Windows Server -->

Windows Server 2016 supports **Windows Server Containers** and **Hyper-V Containers**, which create a separate copy of the operating system kernel for each container.
The "Containers" feature must be installed on Windows Server 2016 hosts, and to create Hyper-V containers the Hyper-V role must also be installed (although the Hyper-V management tools are not necessary if VMs are not going to created).
Windows container hosts need to have Windows installed to C:.

Nano Server once could serve as Docker hosts, but no longer; Nano Servers are now intended to be deployed as containers themselves.

The [Powershell Docker module](https://github.com/microsoft/Docker-PowerShell "PowerShell for Docker") has been deprecated for years.

<!-- #endregion -->

## :material-docker: Docker

Docker **repositories** are associated with a single image, various versions of which can be specified with a **tag**.

**Docker Desktop** is Docker's runtime for Windows which Docker integrates with WSL 2 since June 2019. 
Docker historically distributed its own Linux kernel to use on Windows hosts.

Docker has several options for persistent storage:

- **Volumes** are stored in a part of the host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Docker).
- **Bind mounts** may be stored anywhere on the host system and are specified by [docker run --volume][docker run -&#118;].
- **`tmpfs` mounts** are stored in the host system's memory only, and are available only on Linux.

### Networking

On Linux, the Docker daemon creates a virtual Ethernet bridge named **docker0**, which is assigned an unused private IP range and address.
Every container is associated with a pair of virtual Ethernet interfaces, of which one is visible to the container and the other is tied to this bridge.

- The container's interface is named following a pattern similar to `eth0@if17`, where the number after **if** is the index of the host's interface.
The IP address visible to the container belongs to the bridge's subnet.
- The host's interface is named similar to `vethe8b40b8@if16`, where again the number after **if** indicates the index of the container's interface.

Container networks can use various drivers, which are associated with specific key-value pairs in `daemon.json`:

- **NAT**: containers reside in their own network and the host acts as gateway and set with `{ "fixed-cidr" : "10.0.0.0/24" }`.
- **Transparent**: containers are assigned IP addresses on the same physical network to which the host belongs (similar to **External** virtual switches in Hyper-V), set with `{ "bridge": "none" }`.

Create a new network bridge using the **transparent driver** [Zacker][Zacker]: 285
```sh
docker network create -d transparent $NETWORKNAME
```
Create a transparent network bridge with static IP addresses
```sh
docker network create -d transparent --subnet=10.0.0.0/24 --gateway=10.0.0.1 $NETWORK
```

### Storage

Connect to a session on a running container ([src][Zacker])
```sh
docker attach $CONTID
```

Build a Docker image from a [Dockerfile](#dockerfile) in the present working directory
```sh
docker build -t web .
```

Save changes made to a modified container to a new image ([Zacker][Zacker])
```sh
docker commit $CONTID $USER/$CONT
```

[Simple][udemy] Docker compose file
```yaml
version: '2.0'

services:
  web:
    image: sample-01
    build: .
    ports:
      - '3000:3000'
```

```sh
docker-compose up -d
```
Bring everything down
```sh
docker-compose down -v
```

Create docker image named "hello" with tag "v0.1" from contents of current directory
```sh
docker image build -t hello:v0.1 . | 
```


Display a list of all running containers
```sh
docker ps -a
```
Remove a container completely (must be stopped, unless `-f` is used) [Zacker][Zacker]: 279
```sh
docker rm $CONTID
```

Create a Hyper-V container [Zacker][Zacker]: 275
```sh
docker run -it --isolation=hyperv microsoft/windowsservercore powershell
```
Bind port 80 of the container to port 8080 of the host [Zacker][Zacker]: 284
```sh
docker run -it -p 8080:80 microsoft/windowsservercore powershell
```
Create a container with a static IP address on the network you created
```sh
docker run -it --network=$NETWORK --ip=10.0.0.16 --dns=10.0.0.10 microsoft/windowsservercore powershell
```
To detach from a running container use the keyboard shortcuts <kbd>Ctrl</kbd><kbd>P</kbd><kbd>Ctrl</kbd><kbd>Q</kbd>


Start a stopped container [Zacker][Zacker]: 278
```sh
docker start $CONTID
```

Stop a container [Zacker][Zacker]: 278
```sh
docker stop $CONTID
```

`docker tag` can be used to rename images and to prepare them to be [pushed][docker push] to a repository.

Tag an image on local container host [Zacker][Zacker]: 272
```sh
docker tag $USERNAME/$IMAGENAME:$TAG
```

Display data volumes [PluralSight][pluralsight:70-740-containers]
```sh
docker volume ls
```

##  :material-kubernetes: Kubernetes

**Kubernetes** (Greek for "helmsman", "pilot", or "captain" and "k8s" for short) has emerged as the leading **container orchestrator** in the industry since 2018. It provides a layer that abstracts infrastructure, including computers, networks, and other computers, for applications deployed on top.

Kubernetes can be visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels.
One server serves as the **master**, exposing an API for users and clients, assigning or **scheduling** work, and orchestrating communication between other components. 

Other machines in the cluster are called [**nodes**](#node) or **workers** and accept and run workloads using available resources. 


### History

Kubernetes was first announced by Google in mid-2014. 
It had been developed by Google after deciding to open-source the Borg system, a cluster and container management system that formed the automation infrastructure that powered the entire Google enterprise.
Kubernetes coalesced from a fusion between developers working on Borg and [Compute Engine](/Cloud#compute-engine). Borg eventually evolved into Omega.

By that time, Amazon had established a market advantage and the developers decided to change their approach by introducing a disruptive technology to drive the relevance of the Compute platform they had built. 
They created a ubiquitous abstraction that could run better than anyone else.

At the time, Google had been trying to engage the Linux kernel team and trying to overcome their skepticism. 
Internally, the project was framed as offering "Borg as a Service", although there were concerns that Google was in danger of revealing trade secrets.

Google ultimately donated iKubernetes to the **Cloud Native Computing Foundation**.


### Azure

A volume represents a way to store, retrieve, and persist data across pods and through the application lifecycle. 
In the context of Azure, Kubernetes can use two types of data volume:

- **Azure Disks** using Azure Premium (SSDs) or Azure Standard (HDDs).
- **Azure Files** using a SMB 3.0 share backed by an Azure Storage account.


--8<-- "includes/containers-defs.md"
