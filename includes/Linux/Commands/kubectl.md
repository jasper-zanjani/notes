#### kubectl
:   
    ```sh title="Show available contexts"
    kubectl config get-contexts
    ```

    ```sh title="Switch to a different context"
    kubectl config use-context $NAMESPACE
    kubectl config use $NAMESPACE
    ```

    ```sh title="Display resources"
    kubectl get nodes
    kubectl get pods
    kubectl get deployments
    ```

    ```sh
    kubectl describe nodes/gke-*4ff6f64a-6f4v
    ```
    
    ```sh title="Execute a command on a pod with only a single container, returning output"
    kubectl exec $pod -- env
    ```

    ```sh title="Get a shell to a running container"
    kubectl exec --stdin --tty $pod -- /bin/bash
    ```

    When a pod contains more than one container, the container must be specified with **-c**/**--container**. 
    ```sh
    kubectl exec --stdin --tty $pod --container $container -- /bin/bash
    ```

    ```sh
    kubectl run nginx --image=nginx
    kubectl delete pod nginx
    ```

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

    List Kubernetes objects

    ```sh
    kubectl api-resources
    ```

    Get a description of a resource

    ```sh
    kubectl explain nodes.status.addresses.address
    ```


