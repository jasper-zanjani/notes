# TGIK 1
Kubernetes 1.7 was released on the date of filming.\
Use a [quick start link](https://aws.amazon.com/quickstart/architecture/vmware-kubernetes/) provided by Heptio to launch an AWS CloudFormation stack. This architecture include a **bastion host**, a VM whose only purpose is to provide access to a private subnet from the public Internet.\
Although it is common to talk about a **master node**, in deployed and highly scalable production systems the control plane components are distributed over several nodes.\
Assign the SSH key to the environment variable `SSH_KEY`.\
```sh
scp -i $SSH_KEY -o ProxyCommand="ssh -i \"${SSH_KEY}\" ubuntu@54.201.158.186 nc %h %p" ubuntu@10.0.23.208:~/kubeconfig ./kubeconfig
```
```sh
export KUBECONFIG=~/demo/kubeconfig
```
Examine cluster
```sh
kubectl get nodes
```
Display processes necessary for Kubernetes itself, analogous to how `ps` displays system processes on Linux
```sh
kubectl get pods --namespace=kube-system
```
Run a single pod. `kuard` is short for "Kubernetes Up and Running Daemon", a reference to Joe Beda's book. This is a really fancy `curl`, it generates a text file and then uploads it to the server.
```sh
kubectl run --generator=run-pod/v1 --image=gcr.io/kuar-demo/kuard-amd64:1 kuard
```
This begs the question, "what's a pod?" For most users, a **pod** is a container. But sometimes you want to make sure more than one container are on the same machine because they are meant to work together. The most relevant concrete example would be a networking **sidecar**. Pods are the fundamental unit of Kubernetes. \
This will output the YAML file that is sent to the server. YAML files **are** the Kubernetes API.
```sh
kubectl run --generator=run-pod/v1 --image=gcr.io/kuar-demo/kuard-amd64:1 kuard --dry-run -o yaml
```
`kubectl port-forward` is analogous to an SSH tunnel.
```sh
kubectl port-forward kuard 8080:8080
```
Now navigating to `localhost:8080` will produce the kuard landing page.\
Delete the pod
```sh
kubectl delete pod kuard
kubectl get pods # confirm the pod has been deleted
```
Kubernetes was designed to deal with **sets** of things, which means dealing with pods is awkward because pods are manipulated one at a time. Pods are also associated with nodes, meaning if a node is destroyed then its pods also go away.\
This YAML becomes more complicated, and it creates 5 pods
```sh
kubectl run --image=gcr.io/kuar-demo/kuard-amd64:1 kuard --replicas=5 
kubectl get deployments # This confirms that kuard has five replicas
```
This creates a **service**, which finds a way to name a set of pods and then puts a load balancer **internal** to Kubernetes. It also creates an Elastic Load Balancer on AWS.
```sh
kubectl expose deployment kuard --type=LoadBalancer --port=80 --target-port=8080
```
This displays the **NodePort** as well as the external IP or address ("$HEXSTRING.us-west-2.elb.amazonaws.com", for example).
```sh
kubectl get service kuard -o wide
```
You can confirm that the ELB has been stood up by performing a `dig` query to that external IP. Accessing that IP will produce the `kuard` landing page, but refreshing will show that requests are being load balanced, producing different pod identifiers each time.\
This loop will also demonstrate that curl queries are being load balanced by hitting one of the endpoints exposed by `kuard`.
```sh
while true; do curl -s http://$HEXSTRING.us-west-2.elb.amazonaws.com/env/api | jq '.env.HOSTNAME'; done
```
This scales up the `kuard` deployment to 10 replicas, which can be confirmed with `kubectl get pods`.
```sh
kubectl scale deployment kuard --replicas=10
```
Open an editor to edit the replica number , scaling the cluster back down to 5. Upon saving the file, the cluster will be updated.
```sh
kubectl edit deployment kuard
```
Change the image: the cluster doesn't miss a beat.
```sh
kubectl set image deployment kuard kuard=gcr.io/kuar-demo/kuard-amd64:2
```
Scale up again
```sh
kubectl scale deployment kuard --replicas=10
```
Change the image again
```sh
kubectl set image deployment kuard kuard=gcr.io/kuar-demo/kuard-amd64:2
```
Go back to version 2
```sh
kubectl rollout undo deployment kuard
```
Scale up to 20 replicas
```sh
kubectl scale deployment kuard --replicas=20
```
`CustomResourceDefinition` replaces `ThirdPartyResource`, which is deprecated. There are two ways to extend the Kubernetes API: CRDs and `apiservers` which can be aggregated.
