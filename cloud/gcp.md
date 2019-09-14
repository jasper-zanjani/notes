# Google Cloud Platform 
## Syntax
Gcloud command groups, subgroups, commands, and description:
Command group    | Commands       | Description
:---             | :---           | :---
gcloud compute instances    | create        | Compute Engine (GCE) VMs
gcloud source repos         | clone create  | Google Cloud Source Control repositories
gcloud app        |                         | App Engine
gcloud container  |                         | Kubernetes Engine (GKE)
gcloud services   |                         | Manage project's access to APIs

## Tasks
#### To-do application using MongoDB
Create two VMs, {backend} and {frontend}, running on Ubuntu. Make sure ports 80 and 22 are open.

#### Create a new Google Cloud Source Repository
These steps require:
  1. Cloud SDK and Git to be installed
  2. A GCP project with billing and the Cloud Source Repositories API enabled
Create a new repository
```sh
gcloud source repos create hello-world
```
Clone it locally
```sh
gcloud source repos clone hello-world
```
Create scripts, then add, commit and push them as usual.
```sh
git add .
git commit -m "Initial"
git push origin master
```
[[1](#sources)]
#### Create a VM
```sh
gcloud compute instances create instance-1 --zone-uscentral1-a
```
[[2](#sources)]
#### Deploy a function
```sh
gcloud functions deploy hello_get --runtime python37 --trigger-http
```
[[3](#sources)]
#### Test the function
```sh
gcloud functions describe hello_get
```
[[3](#sources)]
## Sources
1. "Creating an empty repository". [Web](https://cloud.google.com/source-repositories/docs/creating-an-empty-repository).
2. "Google Cloud Command Line for Beginners, or 'How to gcloud' | 9.13.18 | Linux Academy". [YouTube](https://www.youtube.com/watch?v=j274vq9a2Rs).
3. "Quickstart: Using the gcloud Command-Line Tool". [Google Cloud](https://cloud.google.com/functions/docs/quickstart)
