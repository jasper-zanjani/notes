### Kubernetes

#### Clusters

=== ":material-plus: Create"

    !!! GCP "GCP"
        ```sh
        gcloud container clusters create $name --num-nodes=1    # Standard mode
        gcloud container clusters create-auto $name             # Autopilot mode
        ```
    !!! Azure
        ```sh
        az aks create -g $group -n $name --node-count 1 --enable-addons monitoring --generate-ssh-keys
        ```


=== ":material-eye: Read"

    !!! GCP "GCP"
        ```sh
        gcloud container clusters describe $name
        ```
    
    !!! Azure
        ```sh

        ```


=== ":material-format-list-text: List"

    !!! GCP "GCP"
        ```sh
        gcloud container clusters list
        ```

    !!! Azure
        ```sh
        az aks list
        ```

=== ":material-pencil: Update"

    !!! GCP "GCP"
        ```sh

        ```

    !!! Azure
        ```sh

        ```

=== ":material-trash-can: Delete"

    !!! GCP "GCP"
        ```sh
        gcloud container clusters delete $name
        ```

    !!! Azure
        ```sh
        az aks delete -g $group -n $name
        ```


#### Add context to kubeconfig

!!! GCP "GCP"
    ```sh
    gcloud container clusters get-credential $name
    ```

!!! Azure

    === ":material-bash:"
        ```sh
        az aks get-credentials -g $group -n $name
        ```
    === ":material-powershell:"
        ```powershell
        Get-AzAKSCredentials
        ```
