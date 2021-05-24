## :material-book: Glossary

*[K8S]: Kubernetes

**apiVersion**{: #apiversion } :material-kubernetes:
:   Kubernetes object field found in **Type** metadata.

    apiVersion is typically **v1**, but for some object types the API group is specified, i.e. for Deployments: 
    ```yaml
    apiVersion: apps/v1
    ```



**Container Network Interface**{: #cni} :material-kubernetes:
:   ...



**Deployment**{: #deployment } :material-kubernetes:
:   A uniformly managed set of Pod instances, all based on the same container image.
    The **Deployment controller** enables **release capabilities**, the deployment of new Pod versions with no downtime.
    Exposing a Deployment creates a [**Service**](#service).



**Desired State Management**{: #desired-state-management} :material-kubernetes:
:   The **Desired State Management** system is used by Kubernetes to describe a cluster's desired state declaratively.




**emptyDir**{: #emptydir } [:material-kubernetes:](https://kubernetes.io/docs/concepts/storage/volumes/#emptydir)
:   Ephemeral Kubernetes volume type that shares the Pod's lifetime and where data is stored in RAM.
    emptyDir volumes can use [tmpfs](#tmpfs) file systems.



**etcd**{: #etcd } :material-kubernetes:
:   Distributed key-value data store


**Event**{: #event } :material-kubernetes:
:   Kubernetes object type that contains information about what happened to the object.
    Events are deleted one hour after creation by default.
    ```sh
    kubectl get events
    kubectl get ev
    ```
    Unlike most other objects, Event manifests have no **spec** or **status** sections.


**kind**{: #kind } :material-kubernetes:
:   Kubernetes object field found in the **Type** metadata which specifies the type of resource, i.e. [Node](#node), [Deployment](#deployment), [Service](#service), [Pod](#pod), etc.



**kubeconfig**{: #kubeconfig} [:material-kubernetes:](https://kubernetes.io/docs/concepts/configuration/organize-cluster-access-kubeconfig/)
:   YAML configuration file located at **$HOME/.kube/config** by default.
    A colon-delimited list of kubeconfigs can be specified by setting the **`KUBECONFIG`** environment variable.
    A kubeconfig can be explicitly specified with the **--kubeconfig** flag.



**Label**{: #label } [:material-kubernetes:](https://kubernetes.io/docs/concepts/overview/working-with-objects/labels/)
:   Labels are key-value pairs that are attached to Kubernetes objects.

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

    - **kube-apiserver**{: #kube-apiserver } exposes a RESTful API and serves as a glue between other Kubernetes components
    - **kube-scheduler**{: #kube-scheduler } determines how to balance container workloads across nodes using an algorithm
    - **kube-controller-manager**{: #kube-controller-manager } performs cluster operations like managing nodes and making changes to desired status


**millicore**{: #millicore } (m) :material-kubernetes:
:   One-thousandth of a vCPU or a CPU core and the preferred measurement unit of compute resources in Kubernetes.
    !!! example 
        - 128m = 12.8% of a CPU core
        - 2000m = Two CPU cores


**Node**{: #node } :material-kubernetes:
:   A **node** or worker is any container host that accepts workloads from the master node. 
    Each node is equipped with a container runtime like Docker, which it uses to create and destroy containers according to instructions from the master server.

    Each node runs 2 processes:

    - **kubelet**{: #kubelet } communicates with Kubernetes cluster services
    - **kube-proxy**{: #kube-proxy } handles container network routing using iptables rules



**PersistentVolume**{: #persistentvolume} [:material-kubernetes:](https://kubernetes.io/docs/concepts/storage/persistent-volumes/)
:   A **PersistentVolume** is a piece of storage in the cluster that has been provisioned using Storage Classes.



**PersistentVolumeClaim**{: #persistentvolumeclaim} :material-kubernetes:
:   ![](/img/persistent-volume-claims.png)
    A **PersistentVolumeClaim** requests either Disk or File storage of a particular StorageClass, access mode, and size. It is bound to a [PersistentVolume](#persistenvolume) once an available storage resource has been assigned to the pod requesting it.



**Pod**{: #pod } :material-kubernetes:
:   A **pod** is the most basic unit that K8s deals with, representing one or more tightly-coupled containers that should be controlled as a single application (typically one main container with subsidiary helper containers). 
    Every container should have only a single process, so if several processes need to communicate they should be implemented as separate containers in a pod.
    
    A pod's containers should:

    - operate closely together
    - share a lifecycle
    - always be scheduled on the same node
   


**Replica**{: #replica } :material-kubernetes:
:   An instance of a [Pod](#pod)



**ReplicaSet** :material-kubernetes:
:   ...



**Selector**{: #selector } [:material-kubernetes:](https://jamesdefabia.github.io/docs/user-guide/labels/#label-selectors)
:   A **label selector** provides a way to identify a set of objects and is the core grouping primitive supported by Kubernetes.
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



**Service** [:material-kubernetes:](https://jamesdefabia.github.io/docs/user-guide/services/)
:   A Service is an abstraction over a logical set of Pods and a policy by which to access them, i.e. a microservice.
    Because Pods are mortal, the **Service controller** keeps track of Pod addresses and publishes this information to the consumers of Services, a function called **service discovery**.


**Worker** :material-kubernetes: see [Node](#node)