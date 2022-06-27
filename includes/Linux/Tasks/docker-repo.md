#### Docker repo
:   
    ```sh title="Add Docker repo"
    #Ubuntu
    add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

    # Fedora
    dnf config-manager --add-repo "https://download.docker.com/linux/fedora/docker-ce.repo"
    ```
