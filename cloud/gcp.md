[Sullivan]: # "Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_"
[https://cloud.google.com/source-repositories/docs/creating-an-empty-repository]: https://cloud.google.com/source-repositories/docs/creating-an-empty-repository "GCP Developer Tools: \"Creating an empty repository\""
[https://www.youtube.com/watch?v=j274vq9a2Rs]: https://www.youtube.com/watch?v=j274vq9a2Rs "YouTube: \"Google Cloud Command Line for Beginners, or 'How to gcloud' | 9.13.18 | Linux Academy\""
[https://cloud.google.com/functions/docs/quickstart]: https://cloud.google.com/functions/docs/quickstart "GCP Developer Tools: \"Quickstart: Using the gcloud Command-Line Tool\""

[App Engine]:                             #storage            'App Engine&#10;Allows users to deploy applications in a popular programming language without configuring VMs or Kubernetes clusters&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 20'
[appengine.appAdmin]: #identity '`appengine.appAdmin`&#10;IAM role, grants identities the ability to read, write, and modify all application settings&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 48'
[appengine.ServiceAdmin]: #identity '`appengine.ServiceAdmin`&#10;IAM role, grants read-only access to application settings and write-level access to module-level and version-level settings&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 48'
[appengine.appViewer]: #identity '`appengine.appViewer`&#10;IAM role, grants read-only access to applications&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 48'
[Bigquery]:                               #etc                'Bigquery&#10;Petabyte-scale analytics database service for data warehousing&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 30'
[Cloud Automl]:                           #etc                'Cloud Automl&#10;Allows developers without machine learning experience to develop machine learning models&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Functions]:                        #storage            'Cloud Functions&#10;Lightweight computing option well-suited to event-driven processing&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 20'
[Cloud Machine Learning Engine]:          #etc                'Cloud Machine Learning Engine&#10;Platform for building and deploying scalable machine learning systems to production&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Natural Language Processing]:      #etc                'Cloud Natural Language Processing&#10;Tool for analyzing human languages and extracting information from text&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Cloud Vision]:                           #etc                'Cloud Vision&#10;Image analysis platform for annotating images with metadata, extracting text, or filtering content&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 31'
[Compute Engine]:                         #storage            'Compute Engine&#10;Allows users to create VMs, attach persistent storage to them, and make use of other GCP services like Cloud Storage&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 17'
[Dataflow]:                               #etc                'Cloud Dataflow&#10;Framework for defining batch and stream processing pipelines&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 30'
[Dataproc]:                               #etc                'Cloud Dataproc&#10;Managed Hadoop and Spark service&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 30'
[Dataprep]:                               #etc                'Cloud Dataprep&#10;Service that allows analysts to explore and prepare data for analysis&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 30'
[Folder]: #resources 'Folder&#10;Organizations contain folders; folders can contain other folders or projects&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 42'
[Kubernetes Engine]:                      #storage            'Kubernetes Engine&#10;Allows users to easily run containerized applications on a cluster of servers&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 19'
[Organization]: #resources 'Organization&#10;Root of the resource hierarchy, typically corresponding to a company or organization (equivalent to G-Suite domains and Cloud Identity accounts)&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 41'
[Organization Administrator]:             #identity           'Organization Administrator&#10;IAM role responsible for defining the structure and IAM policies of resource hierarchy and delegating management roles to other users&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 42'
[Primitive Role]: #identity 'Primitive Role&#10;Grant wide ranges of permissions that may not always be needed by a user&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 48'
[Project]: #resources 'Project&#10;Contain resources, manage permissions and billing options, and use GCP services&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 43'
[Role]: #identity 'Role&#10;Collection of permission&#10;Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_: 47'
[Kubeflow]: #kubeflow 'Kubeflow&#10;Cloud Native platform for machine learning based on Google’s internal machine learning pipelines'
[Spanner]: # 'Spanner&#10;GCP managed scaleable database service'
[gcloud]: #gcloud '`gcloud`&#10;Command used for many cloud management tasks, organized into a hierarchy of groups'
[gsutil]: #gsutil '`gsutil`&#10;Command used to manipulate GCS'

# Google Cloud Platform 
## Identity
[Role][Role] types
- [Primitive roles][Primitive Role]
- Predefined roles
- Custom roles

IAM roles
- [`appengine.appAdmin`][appengine.appAdmin]
- [`appengine.appViewer`][appengine.appAdmin]
- [`appengine.ServiceAdmin`][appengine.ServiceAdmin]
- Billing Account Creator
- [Organization Administrator][Organization Administrator]
- Project Creator
### Group membership
- [Group membership and hierarchy](https://www.youtube.com/watch?v=b33-gN0lidA&t=77s 'YouTube - Group membership and hierarchy')
## Services
Storage services:
- [App Engine (GAE)][App Engine]
- [Compute Engine (GCE)][Compute Engine]
- [Kubernetes Engine (GKE)][Kubernetes Engine]
- [Cloud Functions][Cloud Functions]

Specialized services:
- [Bigquery][Bigquery]
- [Cloud Dataflow][Dataflow]
- [Cloud Dataproc][Dataproc]
- [Cloud Dataprep][Dataprep]

AI services:
- [Cloud AutoML][Cloud Automl]
- [Cloud Machine Learning Engine][Cloud Machine Learning Engine]
- [Cloud NLP][Cloud Natural Language Processing]
- [Cloud Vision][Cloud Vision]
- [Kubeflow][Kubeflow]

### Compute
#### Cloud Functions
- [Quickstart](https://www.youtube.com/watch?v=vM-2O-uKBNQ 'YouTube - Getting Started: Cloud Functions quickstart')
### Machine learning
#### Cloud Vision
- [Getting started: Image recognition and classification](https://www.youtube.com/watch?v=BN8aO0LULyw 'YouTube - Getting started: Image recognition and classification')
#### Kubeflow
- [Kubeflow 101 (playlist)](https://www.youtube.com/playlist?list=PLIivdWyY5sqLS4lN75RPDEyBgTro_YX7x 'YouTube - KubeFlow 101')
- [Talk - Kubeflow at Spotify](https://www.youtube.com/watch?v=m9XhsnNSMAI 'YouTube - Building and managing a centralized Kubeflow platform at Spotify')
- [Talk - Kubeflow on Kubernetes](https://www.youtube.com/watch?v=I6iMznIYwM8 'YouTube - Kubeflow ML on Kubernetes')

## SDK
[`cbt`][cbt]
[`gcloud`][gcloud]
[`gsutil`][gsutil]

Resources:
- [CLI for GCP](https://www.youtube.com/watch?v=D0x6B-4oUNM 'YouTube - Getting started: CLI for GCP')
- [Build and package container artifacts](https://www.youtube.com/watch?v=ysjCt3tNyV0 'YouTube - Getting started: Build and package container artifacts')
- [Private container registry](https://www.youtube.com/watch?v=s46l_PmXBAQ 'YouTube - Getting started: Private container registry/storage')

### `cbt`
### `gcloud`
[gcloud app]:                             #gcloud             '`gcloud app`&#10;App Engine'
[gcloud compute]:                         #gcloud             '`gcloud compute`&#10;Compute Engine'
[gcloud container]:                       #gcloud             '`gcloud container`&#10;Kubernetes Engine'
[gcloud compute]:                         #gcloud             '`gcloud compute`&#10;Compute Engine'
[gcloud functions]:                       #functions          '`gcloud functions`&#10;Cloud Functions'
[gcloud services]:                        #gcloud             '`gcloud services`&#10;Manage project\'s access to APIs'

[`app`][gcloud app]
[`compute`][gcloud compute]
[`container`][gcloud container]
[`functions`][gcloud functions]
[`services`][gcloud services]
`source`

Compute Engine (GCE) VMs
```sh
gcloud compute instances create
```
Google Cloud Source Control repositories
```sh
gcloud source repos clone
gcloud source repos create
```
### `gsutil`
`mb` 
`mv` 
[`rewrite`](#change-storage-class)
`rsync`


# Tasks
#### To-do application using MongoDB
Create two VMs, {backend} and {frontend}, running on Ubuntu. Make sure ports 80 and 22 are open.

#### Create a new Google Cloud Source Repository
These steps require:
  1. Cloud SDK and Git to be installed
  2. A GCP project with billing and the Cloud Source Repositories API enabled
Create a new repository [^](#sources)
```sh
gcloud source repos create hello-world
```
Clone it locally
```sh
gcloud source repos clone hello-world
```
Create scripts, then add, commit and push them as usual.
```sh
git commit -am "Initial"
git push origin master
```
#### Create a VM
[YouTube][https://www.youtube.com/watch?v=j274vq9a2Rs]
```sh
gcloud compute instances create instance-1 --zone-uscentral1-a
```
#### Functions
Deploy <sup>[Google][https://cloud.google.com/functions/docs/quickstart]</sup>
```sh
gcloud functions deploy hello_get --runtime python37 --trigger-http
```
Test <sup>[Google][https://cloud.google.com/source-repositories/docs/creating-an-empty-repository]</sup>
```sh
gcloud functions describe hello_get
```
#### Change storage class
`$STORAGE_CLASS` can be `multi_regional`, `regional`, `nearline`, or `coldline`
```sh
gsutil rewrite -s $STORAGE_CLASS gs://$PATH_TO_OBJECT
```

