# Google Cloud Platform Administration
## Contents
\#  | Title | Links
:---| :---  | :---
1   | Introduction to GCP             | 
1A  | Introduction to cloud computing | 
1B  | Introducing GCP
1C  | Data centers and regions
1D  | Relating AWS and Azure to GCP
1E  | Using the command line
2   | GCP Compute
2A  | Google Compute Engine
2B  | Creating a VM instance
2C  | Preemptible VM instances
2D  | Live migration
2E  | Google App Engine
2F  | Kubernetes engine
2G  | Node pools
2H  | Google Cloud Functions 
3   | GCP Storage
3A  | Persistent storage
3B  | Google Cloud Storage buckets
3C  | Google Cloud Spanner
3D  | Google Cloud SQL
3E  | Google Cloud BigTable
4   | GCP Networking
4A  | VPC networks
4B  | Routes
4C  | Firewall
4D  | VPC network peering
4E  | Private Google access
4F  | Other networking concepts
4G  | Google Cloud CDN
4H  | Cloud VPN
4I  | Cloud interconnect
5   | GCP Containers
5A  | Kubernetes concepts
5B  | Administering a cluster
5C  | Configuring cluster networking
5D  | Preemtible instances
6   | TCP Operations
6A  | Stackdriver monitoring and logging
6B  | Logging
6C  | Stackdriver error reporting
6D  | Stackdriver debugger
6E  | Stackdriver profiler
6F  | Stackdriver Trace
7   | GCP Identity and Security
7A  | Infrastructure and cloud platform security
7B  | Identity and access management
7C  | Key management service
7D  | Cloud security scanner
7E  | Data loss prevention
7F  | Security keys
8   | GCP Billing
8A  | Billing concepts
8B  | Managing billing
8C  | Analyzing a billing account
8D  | Setting up a budget
9   | GCP Tools
9A  | Deployment Manager
9B  | GCP Marketplace
9C  | GCP Cloud SDK | [Notes](#gcp-cloud-sdk) [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788624350/9/ch09lvl1sec67/gcp-cloud-sdk)
9D  | Cloud API
9E  | Cloud shell

#### GCP Cloud SDK
Cloud SDK is made up of **components**, installable packages that contain dependencies for tools. When you install Cloud SDK, the `gcloud`, `bq` (BigQuery), `gsutil` (GCP Storage), and `core` components are installed by default.\
Using `gcloud` you can manage configurations. The configuration set by `gcloud init` becomes the `default`, but additional configurations can be created and saved under names, and you can browse them and switch between them.
## Syntax
Syntax  | Effect
:---    | :---
`gcloud init` | initialize Cloud SDK; first command that you run to configure your account [9C](#gcp-cloud-sdk)
`gcloud config list` | view your active configuration properties [9C](#gcp-cloud-sdk)
`gcloud config configurations create $NAME` | save a configuration under {$NAME} [9C](#gcp-cloud-sdk)
`gcloud config configurations list`       | list all available configurations [9C](#gcp-cloud-sdk)
`gcloud components install $COMPONENT`    | install {$COMPONENT} [9C](#gcp-cloud-sdk)
`gcloud components install kubectl`       | install Kubernetes components [9C](#gcp-cloud-sdk)
`gcloud components update`                | update Cloud SDK [9C](#gcp-cloud-sdk)
