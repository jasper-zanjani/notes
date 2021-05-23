## 📘 Glossary

*[K8S]: Kubernetes

**Container Network Interface**{: #cni} :material-kubernetes:
:   alias

#### Deployment :material-kubernetes:

A uniformly managed set of Pod instances, all based on the same container image.
The **Deployment controller** enables **release capabilities**, the deployment of new Pod versions with no downtime.
Exposing a Deployment creates a [**Service**](#service).

**Desired State Management**{: #desired-state-management} :material-kubernetes:
:   The **Desired State Management** system is used by Kubernetes to describe a cluster's desired state declaratively.

#### Dockerfile :material-docker:
A Docker image consists of read-only **layers**, each of which represents an **instruction** that incrementally the changes the image being built up. 
Dockerfiles can be used to construct new images using `docker build`.
The build process can be optimized by placing multiple commands in the same `RUN` instruction.
Dockerfiles are named simply "Dockerfile" with no extension or variation.

=== "Node on Alpine"

    ```dockerfile
    FROM alpine
    RUN apk update && apk add nodejs
    COPY . /app
    WORKDIR /app
    CMD ["node","index.js"]
    ```

=== "Windows Server Nano"

    ```dockerfile
    FROM microsoft/windowsservercore
    RUN powershell -command install-windowsfeature dhcp -includemanagementtools
    RUN powershell -configurationname microsoft.powershell -command add-dhcpserverv4scope -state active -activatepolicies $true -name scopetest -startrange 10.0.0.100 -endrange 10.0.0.200 -subnetmask 255.255.255.0
    RUN md boot
    COPY ./bootfile.wim c:/boot/
    CMD powershell
    ```

=== "Windows Server Core"

    ```dockerfile
    FROM microsoft/windowsservercore
    MAINTAINER @mike_pfeiffer
    RUN powershell.exe -Command Install-WindowsFeature Web-Server
    COPY ./websrc c:/inetpub/wwwroot
    CMD [ "powershell" ]
    ```

**etcd**{: #etcd } :material-kubernetes:
:   Distributed key-value data store


**kubeconfig**{: #kubeconfig} [:material-kubernetes:](https://kubernetes.io/docs/concepts/configuration/organize-cluster-access-kubeconfig/)
:   YAML configuration file located at **$HOME/.kube/config** by default.
    A colon-delimited list of kubeconfigs can be specified by setting the **`KUBECONFIG`** environment variable.
    A kubeconfig can be explicitly specified with the **--kubeconfig** flag.


#### Label [:material-kubernetes:](https://kubernetes.io/docs/concepts/overview/working-with-objects/labels/)

Labels are key-value pairs that are attached to Kubernetes objects.

Config for a Pod with two labels:
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: label-demo
  labels:
    environment: production
    app: nginx
spec:
  containers:
  - name: nginx
    image: nginx:1.14.2
    ports:
    - containerPort: 80
```


**Master node**{: #master-node } :material-kubernetes:
:   A master node runs 3 processes, called master (control plane) components: 

    - [kube-apiserver](#kube-apiserver)
    - [kube-controller-manager](#kube-controller-manager)
    - [kube-scheduler](#kube-scheduler).

**Node**{: #node } :material-kubernetes:
:   A **node** or worker is any container host that accepts workloads from the master node. 
    Each node is equipped with a container runtime like Docker, which it uses to create and destroy containers according to instructions from the master server.

    Each node runs 2 processes:

    - **kubelet**{: #kubelet } communicates with Kubernetes cluster services
    - **kube-proxy**{: #kube-proxy } handles container network routing using iptables rules
    - **kube-apiserver**{: #kube-apiserver } exposes a RESTful API and serves as a glue between other Kubernetes components
    - **kube-scheduler**{: #kube-scheduler } determines how to balance container workloads across nodes using an algorithm
    - **kube-controller-manager**{: #kube-controller-manager } performs cluster operations like managing nodes and making changes to desired status



#### PersistentVolume [:material-kubernetes:](https://kubernetes.io/docs/concepts/storage/persistent-volumes/)

A **PersistentVolume** is a piece of storage in the cluster that has been provisioned using Storage Classes.

#### PersistentVolumeClaim
![](/img/persistent-volume-claims.png)
A **PersistentVolumeClaim** requests either Disk or File storage of a particular StorageClass, access mode, and size. It is bound to a [PersistentVolume](#persistenvolume) once an available storage resource has been assigned to the pod requesting it.

#### Pod :material-kubernetes:
A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). 
Within a pod you can specify more than one container image.

A pod's containers should:

- operate closely together
- share a lifecycle
- always be scheduled on the same node

#### Replica :material-kubernetes:

An instance of a Pod

#### ReplicaSet :material-kubernetes:

#### Selector [:material-kubernetes:](https://jamesdefabia.github.io/docs/user-guide/labels/#label-selectors)

A **label selector** provides a way to identify a set of objects and is the core grouping primitive supported by Kubernetes.
It can be made of multiple **requirements** that are comma-separated, all of which must be satisfied.

There are two types of selector:

- [**Equality-based** <sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/concepts/overview/working-with-objects/labels/#equality-based-requirement) admits the operators **=**, **!=**, and **==**.
- [**Set-based** <sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/concepts/overview/working-with-objects/labels/#set-based-requirement) admits the operators **in**, **notin**, and **exists**.

=== "Equality-based selector"

    ```
    environment = production
    tier != frontend
    ```

=== "Set-based selector"

    ```
    environment in (production, qa)
    tier notin (frontend, backend)
    partition
    !partition
    ```

#### Service [:material-kubernetes:](https://jamesdefabia.github.io/docs/user-guide/services/)

A Service is an abstraction over a logical set of Pods and a policy by which to access them, i.e. a microservice.
Because Pods are mortal, the **Service controller** keeps track of Pod addresses and publishes this information to the consumers of Services, a function called **service discovery**.




#### Volume :material-docker:

A volume is a special directory in the Docker host that can be mounted to the container that is used to achieve persistent storage.

#### Worker :material-kubernetes:
