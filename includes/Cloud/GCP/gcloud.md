## gcloud

Adding repo

=== "Ubuntu"
    ```sh
    deb [signed-by=/usr/share/keyrings/cloud.google.gpg] http://packages.cloud.google.com/apt cloud-sdk main
    ```

=== "Fedora"

    To be saved in /etc/yum.repos.d/google-cloud-sdk.repo
    ```ini
    [google-cloud-sdk]
    name=Google Cloud SDK
    baseurl=https://packages.cloud.google.com/yum/repos/cloud-sdk-el7-x86_64
    enabled=1
    gpgcheck=1
    repo_gpgcheck=0
    gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg
        https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg
    ```

Initialize [<sup>:material-google:</sup>](https://cloud.google.com/sdk/docs/initializing)
```sh
gcloud init
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

