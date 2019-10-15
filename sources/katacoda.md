# Katacoda tutorials
Title     | Links
:---      | :---
Start containers using [`kubectl`](../devops/k8s.md#kubectl) | [Notes](#start-containers-using-kubectl) [Web](https://www.katacoda.com/courses/kubernetes/kubectl-run-containers)
Getting started with [`kubeadm`](../devops/k8s.md#kubeadm) | [Notes](#getting-started-with-kubadm) [Web](https://www.katacoda.com/courses/kubernetes/getting-started-with-kubeadm)

#### Getting started with `kubeadm`
##### Step 1 - Initialise Master
Kubeadm has been installed on the nodes. Packages are available for Ubuntu 16.04+, CentOS 7 or HypriotOS v1.0.1+.\
The first stage of initialising the cluster is to launch the master node. The master is responsible for running the control plane components, etcd and the API server. Clients will communicate to the API to schedule workloads and manage the state of the cluster.
##### Task
The command below will initialise the cluster with a known token to simplify the following steps.
```sh
kubeadm init --token=102952.1a7dd4cc8d1f4cc5 --kubernetes-version $(kubeadm version -o short)
```
In production, it's recommend to exclude the token causing kubeadm to generate one on your behalf. To manage the Kubernetes cluster, the client configuration and certificates are required. This configuration is created when kubeadm initialises the cluster. The command copies the configuration to the users home directory and sets the environment variable for use with the CLI.
```sh
sudo cp /etc/kubernetes/admin.conf $HOME/
sudo chown $(id -u):$(id -g) $HOME/admin.conf
export KUBECONFIG=$HOME/admin.conf
```
##### Step 2 - Deploy Container Networking Interface (CNI)
The Container Network Interface (CNI) defines how the different nodes and their workloads should communicate. There are multiple network providers available, some are listed here.
Task\
In this scenario we'll use WeaveWorks. The deployment definition can be viewed at 
```sh
cat /opt/weave-kube
```
This can be deployed using `kubectl apply`.
```sh
kubectl apply -f /opt/weave-kube
```
Weave will now deploy as a series of Pods on the cluster. The status of this can be viewed using the command 
```sh
kubectl get pod -n kube-system
```
When installing Weave on your cluster, visit https://www.weave.works/docs/net/latest/kube-addon/ for details.
##### Step 3 - Join Cluster
Once the Master and CNI has initialised, additional nodes can join the cluster as long as they have the correct token. The tokens can be managed via kubeadm token, for example kubeadm token list.
Task\
On the second node, run the command to join the cluster providing the IP address of the Master node.
```sh
kubeadm join --discovery-token-unsafe-skip-ca-verification --token=102952.1a7dd4cc8d1f4cc5 172.17.0.49:6443
```
This is the same command provided after the Master has been initialised.
The `--discovery-token-unsafe-skip-ca-verification` tag is used to bypass the Discovery Token verification. As this token is generated dynamically, we couldn't include it within the steps. When in production, use the token provided by kubeadm init.
##### Step 4 - View Nodes
The cluster has now been initialised. The Master node will manage the cluster, while our one worker node will run our container workloads.\
Task\
The Kubernetes CLI, known as `kubectl`, can now use the configuration to access the cluster. For example, the command below will return the two nodes in our cluster.
```sh
kubectl get nodes
```
##### Step 5 - Deploy Pod
The state of the two nodes in the cluster should now be Ready. This means that our deployments can be scheduled and launched.\
Using Kubectl, it's possible to deploy pods. Commands are always issued for the Master with each node only responsible for executing the workloads.\
The command below create a Pod based on the Docker Image `katacoda/docker-http-server`.
```sh
kubectl create deployment http --image=katacoda/docker-http-server:latest
```
The status of the Pod creation can be viewed using `kubectl get pods`\
Once running, you can see the Docker Container running on the node.
```sh
docker ps | grep docker-http-server
```
##### Step 6 - Deploy Dashboard
Kubernetes has a web-based dashboard UI giving visibility into the Kubernetes cluster.\
Task\
Deploy the dashboard yaml with the command `kubectl apply -f dashboard.yaml`\
The dashboard is deployed into the kube-system namespace. View the status of the deployment with 
```sh
kubectl get pods -n kube-system
```
A `ServiceAccount` is required to login. A `ClusterRoleBinding` is used to assign the new `ServiceAccount` (`admin-user`) the role of `cluster-admin` on the cluster.
```sh
cat <<EOF | kubectl create -f - 
apiVersion: v1
kind: ServiceAccount
metadata:
  name: admin-user
  namespace: kube-system
---
apiVersion: rbac.authorization.k8s.io/v1beta1
kind: ClusterRoleBinding
metadata:
  name: admin-user
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: cluster-admin
subjects:
- kind: ServiceAccount
  name: admin-user
  namespace: kube-system
EOF
```
This means they can control all aspects of Kubernetes. With `ClusterRoleBinding` and RBAC, different level of permissions can be defined based on security requirements. More information on creating a user for the Dashboard can be found in the Dashboard documentation.\
Once the `ServiceAccount` has been created, the token to login can be found with:
```sh
kubectl -n kube-system describe secret $(kubectl -n kube-system get secret | grep admin-user | awk '{print $1}')
```
When the dashboard was deployed, it used externalIPs to bind the service to port 8443. This makes the dashboard available to outside of the cluster and viewable at https://2886795328-8443-cykoria01.environments.katacoda.com/\
Use the `admin-user` token to access the dashboard.\ 
For production, instead of externalIPs, it's recommended to use kubectl proxy to access the dashboard. See more details at https://github.com/kubernetes/dashboard.

#### Start containers using `kubectl`
##### Step 1 - Launch Cluster
To start we need to launch a Kubernetes cluster. Execute the command below to start the cluster components and download the Kubectl CLI.
```sh
minikube start --wait=false
```
Wait for the Node to become Ready by checking 
```sh
kubectl get nodes
```
##### Step 2 - Kubectl Run
The `run` command creates a deployment based on the parameters specified, such as the image or replicas. This deployment is issued to the Kubernetes master which launches the Pods and containers required. `kubectl run` is similar to `docker run` but at a cluster level. The format of the command is 
```sh
kubectl run <name of deployment> <properties>
```
Task\
The following command will launch a deployment called `http` which will start a container based on the Docker Image `katacoda/docker-http-server:latest`.
```sh
kubectl run http --image=katacoda/docker-http-server:latest --replicas=1
```
You can then use `kubectl` to view the status of the deployments
```sh
kubectl get deployments
```
To find out what Kubernetes created you can describe the deployment process.
```sh
kubectl describe deployment http
```
The description includes how many replicas are available, labels specified and the events associated with the deployment. These events will highlight any problems and errors that might have occurred. In the next step we'll expose the running service.
##### Step 3 - Kubectl Expose
With the deployment created, we can use kubectl to create a service which exposes the Pods on a particular port. Expose the newly deployed http deployment via kubectl expose. The command allows you to define the different parameters of the service and how to expose the deployment.
Task\
Use the following command to expose the container port 80 on the host 8000 binding to the external-ip of the host.
```sh
kubectl expose deployment http --external-ip="172.17.0.15" --port=8000 --target-port=80
```
You will then be able to ping the host and see the result from the HTTP service.
```sh
curl http://172.17.0.15:8000
```
##### Step 4 - Kubectl Run and Expose
With kubectl run it's possible to create the deployment and expose it as a single command.\
Task\
Use the command command to create a second `http` service exposed on port 8001.\
```sh
kubectl run httpexposed --image=katacoda/docker-http-server:latest --replicas=1 --port=80 --hostport=8001
```
You should be able to access it using `curl http://172.17.0.15:8001`\
Under the covers, this exposes the Pod via **Docker Port Mapping**. As a result, you will not see the service listed using `kubectl get svc`\
To find the details you can use 
```sh
docker ps | grep httpexposed
```
##### Pause Containers
Running the above command you'll notice the ports are exposed on the Pod, not the http container itself. The Pause container is responsible for defining the network for the Pod. Other containers in the pod share the same network namespace. This improves network performance and allow multiple containers to communicate over the same network interface..
#### Step 5 - Scale Containers
With our deployment running we can now use kubectl to scale the number of replicas.\
Scaling the deployment will request Kubernetes to launch additional Pods. These Pods will then automatically be load balanced using the exposed Service.
##### Task
The command `kubectl scale` allows us to adjust the number of Pods running for a particular deployment or replication controller.
```sh
kubectl scale --replicas=3 deployment http
```
Listing all the pods, you should see three running for the http deployment 
```sh
kubectl get pods
```
Once each Pod starts it will be added to the load balancer service. By describing the service you can view the endpoint and the associated Pods which are included.
```sh
kubectl describe svc http
```
Making requests to the service will request in different nodes processing the request.
```sh
curl http://172.17.0.15:8000
```

