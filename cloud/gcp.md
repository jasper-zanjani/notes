# Google Cloud Platform 

Contents
---
[Syntax]


## Syntax
\#      | Commands
---     | ---
**C**   | [`cbt`][cbt]
**GC**  | [`gcloud`][gcloud]
**GS**  | [`gsutil`][gsutil]

### `cbt`
### [`gcloud`][gcloud]

\#      | Command groups
---     | ---
**A**   | [`app`][gcloud app]
**C**   | [`compute`][gcloud compute] [`container`][gcloud container]
**F**   | [`functions`][gcloud functions]
**S**   | [`services`][gcloud services] `source`


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

\#      | Command groups
---     | ---
**M**   | `mb` `mv`
**R**   | [`rewrite`](#change-storage-class) `rsync`

## Compute
## Storage

Storage services: [GAE][App Engine], [GCE][Compute Engine], [GKE][Kubernetes Engine], [Cloud Functions][Cloud Functions]

Storage classes: 

## Etc
#### Services
Specialized services: [Bigquery][Bigquery], [Cloud Dataflow][Dataflow], [Cloud Dataproc][Dataproc], [Cloud Dataprep][Dataprep]\
AI services: [Cloud AutoML][Cloud Automl], [Cloud Machine Learning Engine][Cloud Machine Learning Engine], [Cloud NLP][Cloud Natural Language Processing], [Cloud Vision][Cloud Vision]
#### Resources
[Organization][Organization] > [Folder][Folder] > [Project][Project]

## Identity
[Role][Role] types
- [Primitive roles][Primitive Role]
- Predefined roles
- Custom roles

\#    | IAM roles
---   | ---
A     | [`appengine.appAdmin`][appengine.appAdmin] [`appengine.appViewer`][appengine.appAdmin] [`appengine.ServiceAdmin`][appengine.ServiceAdmin]
B     | Billing Account Creator
O     | [Organization Administrator][Organization Administrator]
P     | Project Creator


## Tasks
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
git add .
git commit -m "Initial"
git push origin master
```
#### Create a VM
[^][2]
```sh
gcloud compute instances create instance-1 --zone-uscentral1-a
```
#### Functions
Deploy [^][3]
```sh
gcloud functions deploy hello_get --runtime python37 --trigger-http
```
Test [^][3]
```sh
gcloud functions describe hello_get
```
#### Change storage class
`$STORAGE_CLASS` can be `multi_regional`, `regional`, `nearline`, or `coldline`
```sh
gsutil rewrite -s $STORAGE_CLASS gs://$PATH_TO_OBJECT
```

---

## 

[1]: https://cloud.google.com/source-repositories/docs/creating-an-empty-repository "GCP Developer Tools: \"Creating an empty repository\""
[2]: https://www.youtube.com/watch?v=j274vq9a2Rs "YouTube: \"Google Cloud Command Line for Beginners, or 'How to gcloud' | 9.13.18 | Linux Academy\""
[3]: https://cloud.google.com/functions/docs/quickstart "GCP Developer Tools: \"Quickstart: Using the gcloud Command-Line Tool\""

[Sullivan]: # "Sullivan, Dan. _Official Google Cloud Certified Associate Cloud Engineer Study Guide_"

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

[gcloud]:                                 #gcloud             '`gcloud`&#10;Command used for many cloud management tasks, organized into a hierarchy of groups'
[gcloud app]:                             #gcloud             '`gcloud app`&#10;App Engine'
[gcloud compute]:                         #gcloud             '`gcloud compute`&#10;Compute Engine'
[gcloud container]:                       #gcloud             '`gcloud container`&#10;Kubernetes Engine'
[gcloud compute]:                         #gcloud             '`gcloud compute`&#10;Compute Engine'
[gcloud functions]:                       #functions          '`gcloud functions`&#10;Cloud Functions'
[gcloud services]:                        #gcloud             '`gcloud services`&#10;Manage project\'s access to APIs'

[gsutil]:                                 #gsutil             '`gsutil`&#10;Command used to manipulate GCS'

