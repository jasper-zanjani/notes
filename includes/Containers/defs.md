## 📘 Glossary

*[K8S]: Kubernetes

#### Deployment :material-kubernetes:



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


**kubeconfig**{: #kubeconfig} [:material-kubernetes:](https://kubernetes.io/docs/concepts/configuration/organize-cluster-access-kubeconfig/)
:   YAML configuration file located at **$HOME/.kube/config** by default.
    A colon-delimited list of kubeconfigs can be specified by setting the **`KUBECONFIG`** environment variable.
    A kubeconfig can be explicitly specified with the **--kubeconfig** flag.

**Master node**{: #master-node } :material-kubernetes:
:   A master node runs 3 processes, called master (control plane) components: 

    - [kube-apiserver](#kube-apiserver)
    - [kube-controller-manager](#kube-controller-manager)
    - [kube-scheduler](#kube-scheduler).

**Node**{: #node } :material-kubernetes:
:   A **node** or worker is any container host that accepts workloads from the master node. 
    Each node is equipped with a container runtime like Docker, which it uses to create and destroy containers according to instructions from the master server.

    Each node runs 2 processes

    - [kubelet](#kubelet), which communicates with Kubernetes cluster services
    - [kube-proxy](#kube-proxy)

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

#### ReplicaSet :material-kubernetes:

#### Volume :material-docker:

A volume is a special directory in the Docker host that can be mounted to the container that is used to achieve persistent storage.

#### Worker :material-kubernetes:

