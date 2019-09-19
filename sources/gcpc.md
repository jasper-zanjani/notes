# Google Cloud Platform Cookbook
## Contents
\#  | Title                   | Description
:---| :---                    | :---
1   | Compute
1A  | Hosting a Node.js application on GCE | [PacktPub](https://subscription.packtpub.com/book/virtualization_and_cloud/9781788291996/1/ch01lvl1sec12/hosting-a-node-js-application-on-google-compute-engine)
1B  | Hosting the Node.js application on Google App Engine
1C  | Hosting a Kubernetes Engine
1D  | Hosting an application on Google Cloud Functions
1E  | Hosting a highly scalable application GCE
2   | Storage and Databases
2A  | Hosting a static application using Google Cloud Storage
2B  | Image resizing using GCS and Cloud Functions
2C  | Migrating a MariaDB to Cloud Spanner
2D  | Loading temperature data to Cloud Bigtable and BigQuery
2E  | Storage metadata in Google Cloud Datastore
3   | Networking
3A  | Network management using a data and a management network
3B  | Content-based load balancing
3C  | VPC network peering between two networks
3D  | VPN connection between two networks
3E  | CDN setup for a static website
4   | Security
4A  | Scanning for vulnerabilities using Cloud Security Scanner
4B  | Using Identity-Aware Proxy on App Engine
4C  | Securing financial data using Cloud KMS
4D  | Using Data Loss Prevention API
4E  | Creating IAM custom roles
4F  | Creating service accounts
4G  | Automatic recon and defense
5   | Machine Learning and Big Data
5A  | Uploading data to the Google BigQuery table
5B  | Translating text to a target language
5C  | Creating a Dataflow pipeline to store streaming data
5D  | Using the Vision API
5E  | Using the Google Cloud Speech API
5F  | Using the Cloud IoT Core
6   | Management Tools
6A  | Creating alerts on specific events
6B  | Monitoring a webserver using Stackdriver Monitoring
6C  | Creating tailor-made instances using Deployment Manager
6D  | Error Reporting on a Python Flask application
6E  | Viewing application state using Stackdriver Debugger
7   | Best practices
7A  | Creating a custom VM using Terraform
7B  | Monitoring a GCP account using Security Monkey
7C  | Creating instance backups
7D  | Simulating VM migration
7E  | Creating a golden image using Packer

#### Hosting a Node.js application on GCE
Retrieve and prepare a pre-made repository
```sh
git clone https://github.com/legorie/gcpcookbook.git 
cd gcpcookbook/Chapter01/mysite
npm install
```
Make a new file named `.env` with the following configuration
```conf
COOKIE_SECRET=d44d5c45e7f8149aabc068244 
MONGO_URI=mongodb://localhost/mysite 
```
Run the server, which will serve the application at **http://localhost:3000**
```sh
node keystone.js
```
Commit changes
```sh
git commit -am "Ready for GCP"
```
Create a new Google Cloud Source Repository and add it as the remote for the repo and push it to GCSR.