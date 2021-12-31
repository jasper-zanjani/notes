#### podman
:   
    Create a [SystemD service file](https://docs.podman.io/en/latest/markdown/podman-generate-systemd.1.html) of a container
    ```sh
    podman generate systemd --restart-policy=always syncthing
    ```