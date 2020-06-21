# TGIK 2: Networking and Services
https://youtu.be/PlnvxqKR28A
```sh
export KUBECONFIG=~/tgik/kubeconfig
k get nodes # 4 nodes
k version # Kubernetes server 1.6.6 and kubectl client 1.6.5 
```
Create a deployment on the cluster, preferable Joe Beda's `kuard`
```sh
k run --replicas=10 --image=gcr.io/kuar-demo/kuard-amd64:1 kuard # creates 10 pods
```
Forward host's port to pod's
```sh
k port-forward kuard-1002304007-1cjd2 8080:8080
```
Execute `bash`-like but lighter-weight `ash` <sup>[9:00](https://youtu.be/PlnvxqKR28A?t=540)</sup>
```sh
k exec -ti kuard-1002304007-1cjd2 ash
```
Within the pod, `ifconfig` reveals every pod get its own IP address that is separate from the node it's running on.

The IP address listed for each pod in the output this command corresponds with the IP address reported within the pod (running `ash` above).
The IP address of the **node** can be seen in the "NODE" column.
```sh
k get pods -o wide
```
Joe Beda launches into a historical discussion of how Kubernetes differs from Borg, which worked off of ports.

Direct communication from one container to another is possible and demonstrable using `wget` at the command line.