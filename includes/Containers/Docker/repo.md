Add the Docker repo

=== "Ubuntu"

    ```sh
    add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
    ```

=== "Fedora"

    ```sh
    dnf config-manager --add-repo https://download.docker.com/linux/fedora/docker-ce.repo
    ```
