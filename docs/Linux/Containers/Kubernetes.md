# Kubernetes

**Kubernetes** (Greek for "helmsman", "pilot", or "captain" and "k8s" for short) has emerged as the leading **container orchestrator** in the industry since 2018. 
It provides a layer that abstracts infrastructure, including computers, networks, and other computers, for applications deployed on top.

Kubernetes can be visualized as a system built from layers, with each higher layer abstracting the complexity of the lower levels.
One server serves as the **master**, exposing an API for users and clients, assigning workloads, and orchestrating communication between other components.
The processes on the master node are also called the **control plane**.
Other machines in the cluster are called [**nodes**](#node) or **workers** and accept and run workloads using available resources. 
A Kubernetes configuration files is called a [kubeconfig](#kubeconfig).

Kubernetes **resources** or **objects**, each associated with a URL, represent the configuration of a cluster.
Resource and object are often used interchangeably, but more precisely the resource refers to the URL path that points to the object, and an object may be accessible through multiple resources.
Every object type in the Kubernetes API has a **controller** (i.e. deployment controller, etc.) that reads desired state from the Spec section of the manifest and reports its actual state by writing to the Status section.

An object's **manifest**, presented in JSON or YAML, represents its declarative configuration, and contains four sections:

- **`type`** metadata, specifying the type of resource
- **`object`** metadata, specifying name and other identifying information
- **`spec`**: desired state of resource
- **`state`**: produced strictly by the resource controller and represents the current status of resource

An explanation of each field available in the API of any object type can be displayed on the command-line
```sh
kubectl explain nodes
kubectl explain no.spec
```

Display the manifest of a node

=== "get"

    ```sh
    kubectl get node $NODE -o yaml
    ```

=== "describe"

    ```sh
    kubectl describe node kind-worker-2
    ```

A [**pod**](#pod) is the most atomic unit of work which encompasses one or more **tightly-coupled** containers that will be deployed together on the same node.
All containers in a pod share the same Linux namespace, hostname, IP address, network interfaces, and port space.
This means containers in a pod can communicate with each other over localhost, although care must be taken to ensure individual containers do not attempt to use the same port.
However their filesystems are isolated from one another unless they share a [**Volume**](#volume).

Every Pod occupies one address in a shared range, so communication between Pods is simple.

Compute resources of containers can be limited at **`pod.spec.containers.resources`**

```yaml
# nginx-limited.yaml
apiVersion: v1
kind: Pod
metadata:
  name: nginx
spec:
  containers:
  - image: nginx
    name: nginx
    resources:
      requests:
        memory: "64Mi"
        cpu: "500m"
      limits:
        memory: "128Mi"
        cpu: "500m"
```

Kubernetes can monitor Pod health by using **probes**, which can be categorized by how they measure health:

- [**Readiness**](#readiness-probe): i.e. Is the container ready to serve user requests?
- **Liveness**: i.e. Is the container running as intended?

--8<-- "includes/Containers/K8s/storage.md"

--8<-- "includes/Containers/K8s/history.md"

--8<-- "includes/Containers/K8s/kubectl.md

--8<-- "includes/Containers/K8s/defs.md"