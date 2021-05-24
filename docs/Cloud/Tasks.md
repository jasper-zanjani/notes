# Tasks

[**Cloud APIs** <sup>:material-google:</sup>](https://cloud.google.com/apis) are equivalent to Azure [**resource providers** <sup>:material-microsoft-azure:</sup>](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/azure-services-resource-providers).
Unlike Azure, which automatically registers resource providers on use, Cloud APIs must be enabled per project.

!!! gcp "GCP"
    ```sh
    gcloud services enable container.googleapis.com
    ```

!!! azure
    ```sh
    az provider register -n Microsoft.ContainerService
    ```


#### Display all available regions

!!! gcp "GCP"
    ```sh
    gcloud compute regions list
    ```

--8<-- "includes/Cloud/Tasks/CLI.md"

--8<-- "includes/Cloud/Tasks/K8s.md"

--8<-- "includes/Cloud/Tasks/Storage.md"