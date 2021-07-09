Add the Docker repo

=== ":material-ubuntu:"

    ```sh
    add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
    ```

=== "":material-fedora:"

    ```sh
    dnf config-manager --add-repo "https://download.docker.com/linux/fedora/docker-ce.repo"
    ```
