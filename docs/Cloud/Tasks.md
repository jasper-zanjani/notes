# Tasks

[**Cloud APIs** <sup>:material-google:</sup>](https://cloud.google.com/apis) are equivalent to Azure [**resource providers** <sup>:material-microsoft-azure:</sup>](https://docs.microsoft.com/en-us/azure/azure-resource-manager/management/azure-services-resource-providers).
Unlike Azure, which automatically registers resource providers on use, Cloud APIs must be enabled per project.

=== ":material-google:"

    ```sh
    gcloud services enable container.googleapis.com
    ```

=== ":material-microsoft-azure:"

    ```sh
    az provider register -n Microsoft.ContainerService
    ```

Display all available regions

=== ":material-google:"

    ```sh
    gcloud compute regions list
    ```


## CLI

Installing command-line utility

=== ":material-microsoft-azure:"

    Prerequisites
    ```sh
    apt install apt-transport-https ca-certificates curl  lsb-release gnupg
    ```
    Signing key
    ```sh
    curl -sL https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor |
    sudo tee /etc/apt/trusted.gpg.d/microsoft.gpg > /dev/null
    ```
    Repo
    ```sh
    echo "deb [arch=amd64] https://packages.microsoft.com/repos/azure-cli/ $(lsb_release -cs) main" |
    sudo tee /etc/apt/sources.list.d/azure-cli.list
    ```
    Install
    ```sh
    sudo apt-get update && sudo apt-get install azure-cli
    ```


=== ":material-google:"

    Prerequisites
    ```sh
    apt install apt-transport-https ca-certificates gnupg
    ```
    Signing key
    ```sh
    curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | 
    sudo apt-key --keyring /usr/share/keyrings/cloud.google.gpg add -
    ```
    Repo
    ```sh
    echo "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] https://packages.cloud.google.com/apt cloud-sdk main" | 
    sudo tee -a /etc/apt/sources.list.d/google-cloud-sdk.list
    ```
    Install
    ```sh
    sudo apt-get update && sudo apt-get install google-cloud-sdk
    ```

## Kubernetes

Clusters

=== ":material-google:"

    Create
    ```sh
    gcloud container clusters create $name --num-nodes=1    # Standard mode
    gcloud container clusters create-auto $name             # Autopilot mode
    ```
    Read
    ```sh

    ```
    Update
    ```sh

    ```
    Delete
    ```sh
    gcloud container clusters delete $name
    ```

=== ":material-microsoft-azure:"

    Create
    ```sh
    az aks create -g $group -n $name --node-count 1 --enable-addons monitoring --generate-ssh-keys
    ```
    Read
    ```sh
    az aks list
    ```
    Update
    ```sh

    ```
    Delete
    ```sh
    az aks delete -g $group -n $name
    ```

Add context to kubeconfig

=== ":material-google:"

    ```sh
    gcloud container clusters get-credential $name
    ```

=== ":material-microsoft-azure:"

    ```sh
    az aks get-credentials -g $group -n $name
    ```
