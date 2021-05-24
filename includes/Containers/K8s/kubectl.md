## kubectl

### Contexts

Show available contexts

```sh
kubectl config get-contexts
```

Switch to a different context

```sh
kubectl config use-context $namespace
kubectl config use $namespace
```


### Administration

Resource types can be referenced in a variety of ways, including the full name singular and plural as well as an abbreviated **short name**.

=== "Nodes"

    ```sh
    kubectl get nodes
    kubectl get node
    kubectl get no
    ```

=== "Pods"

    ```sh
    kubectl get pods
    kubectl get pod
    kubectl get po
    ```

=== "Deployments"

    ```sh
    kubectl get deployments
    kubectl get deployment
    kubectl get deploy
    ```

```sh
kubectl describe nodes/gke-*4ff6f64a-6f4v
```

Execute a command on a pod with only a single container, returning output [<sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/tasks/debug-application-cluster/get-shell-running-container/)

```sh
kubectl exec $pod -- env
```

Get a shell to a running container [<sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/tasks/debug-application-cluster/get-shell-running-container/)

```sh
kubectl exec --stdin --tty $pod -- /bin/bash
```

When a pod contains more than one container, the container must be specified with **-c**/**--container**. [<sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/tasks/debug-application-cluster/get-shell-running-container/)

=== ":material-bash:"

    ```sh
    kubectl exec -it $pod -c $container -- /bin/bash
    ```

=== "POSIX"

    ```sh
    kubectl exec --stdin --tty $pod --container $container -- /bin/bash
    ```

### Pods

=== ":material-plus: Create"

    ```sh
    kubectl run nginx --image=nginx
    ```

=== ":material-trash-can: Delete"

    ```sh
    kubectl delete pod nginx
    ```

### Deployments

```sh
kubectl create deployment nginx --image=nginx
```

Number of replicas can be set on creation of a deployment by specifying an argument to **--replicas**
```sh
kubectl create deployment nginx --image=nginx --replicas=4
```

Replica count is set in an existing deployment by **scaling**
```sh
kubectl scale deploy/nginx --replicas=2
```

Expose a port
```sh
kubectl expose deployment/nginx --port=80 --type=LoadBalancer
```

### Help

List Kubernetes objects

```sh
kubectl api-resources
```

Get a description of a resource

```sh
kubectl explain nodes.status.addresses.address
```

### Logs



### Tasks

Override a container's [CMD](#cmd) declaration.

=== ":material-bash:"

    Start a new pod from the command-line.
    ```sh
    kubectl run alpine --image=alpine --restart=Never --attach -- sh -c "while true; do date; sleep 1; done"
    ```
    Output:
    ```
    Mon May 24 17:09:44 UTC 2021
    Mon May 24 17:09:45 UTC 2021
    ...
    ```

=== ":material-code-json:"

    Using a [manifest](#manifest):
    ```yaml
    # alpine-script.yaml
    apiVersion: v1
    kind: Pod
    metadata:
    name: alpine
    spec:
    containers:
    - name: alpine
        image: alpine
        args:
        - sh
        - -c
        - |
        while true;
            do date;
            sleep1;
        done
    ```
    ```sh
    kubectl apply -f alpine-script.yaml
    ```

=== "2"

    Display pod manifest
    ```sh
    kubectl get po/alpine -o yaml | grep "spec:" -A 5
    ```
    Output:
    ```
    spec:
        containers:
        - args:
        - sh
        - -c
        - while true; do date; sleep 1; done
    ```

---
