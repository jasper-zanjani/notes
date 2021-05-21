#### gcloud

Ubuntu repo
```sh
deb [signed-by=/usr/share/keyrings/cloud.google.gpg] http://packages.cloud.google.com/apt cloud-sdk main
```

In GCP, APIs are enabled per project.

List all APIs

```sh
# Enabled APIs only
gcloud services list 

# Including disabled APIs
gcloud services list --available
```

Enable API

```sh
gcloud services enable compute.googleapis.com container.googleapis.com
```

Display all available [regions](https://cloud.google.com/compute/docs/regions-zones) and zones

```sh
gcloud compute regions list
gcloud compute zones list
```

Set default region and zone

```sh
gcloud config set compute/region us-east1 # Moncks Corner, South Carolina
gcloud config set compute/zone us-east1-c
```

Create a Kubernetes cluster in GKE.

```sh
gcloud container clusters create hello-cluster --num-nodes=1    # Standard cluster
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
```-