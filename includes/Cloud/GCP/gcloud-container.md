Create a Kubernetes cluster in GKE.
```sh
gcloud container clusters create hello-cluster --num-nodes=1    # Standard cluster
```

GKE clusters are made of Compute Engine instances. To list them:
```sh
gcloud compute instances list
```

If a default zone is set, an [Autopilot](#gke) cluster won't be able to be created without explicitly specifying **--region**.
```sh
gcloud container clusters create-auto hello-cluster
```

Interrogate a running cluster
```sh
gcloud container clusters describe hello-cluster
```

Save a Kubernetes cluster's credentials to a [kubeconfig](/Containers#kubeconfig).
```sh
gcloud container clusters get-credentials my-cluster
```