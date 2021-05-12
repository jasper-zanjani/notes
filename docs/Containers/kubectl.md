# kubectl

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

Resources can be referenced in a variety of names, including the full name singular and plural as well as an abbreviated **short name**.

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

=== "POSIX"

    ```sh
    kubectl exec -i -t $pod -c $container -- /bin/bash
    ```

=== "Long options"

    ```sh
    kubectl exec --stdin --tty $pod --container $container -- /bin/bash
    ```

### Pods

=== "Create"

    ```sh
    kubectl run nginx --image=nginx
    ```

=== "Delete"

    ```sh
    kubectl delete pod nginx
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