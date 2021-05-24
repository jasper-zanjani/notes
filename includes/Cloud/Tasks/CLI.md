#### Install CLI utility

=== ":material-check: Prerequisites"

    !!! GCP "GCP"
        ```sh
        apt install apt-transport-https ca-certificates gnupg
        ```

    !!! Azure
        ```sh
        apt install apt-transport-https ca-certificates curl  lsb-release gnupg
        ```
    
=== ":material-key: Signing key"

    !!! GCP "GCP"
        ```sh
        curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | 
        sudo apt-key --keyring /usr/share/keyrings/cloud.google.gpg add -
        ```
    !!! Azure
        ```sh
        curl -sL https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor |
        sudo tee /etc/apt/trusted.gpg.d/microsoft.gpg > /dev/null
        ```
=== ":material-package: Repo"

    !!! GCP "GCP"
        ```sh
        echo "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] https://packages.cloud.google.com/apt cloud-sdk main" | 
        sudo tee -a /etc/apt/sources.list.d/google-cloud-sdk.list
        ```
    !!! Azure
        ```sh
        echo "deb [arch=amd64] https://packages.microsoft.com/repos/azure-cli/ $(lsb_release -cs) main" |
        sudo tee /etc/apt/sources.list.d/azure-cli.list
        ```
=== ":material-content-save: Install"

    !!! GCP "GCP"
        ```sh
        sudo apt-get update && sudo apt-get install google-cloud-sdk
        ```
    !!! Azure
        ```sh
        sudo apt-get update && sudo apt-get install azure-cli
        ```

