#### podman
:   
    With few exceptions, podman exposes a command-line API that precisely imitates that of Docker.

    ```sh
    podman run -d --rm -p=8080:80 
        -v=/home/jasper/notes/site:/usr/share/nginx/html:Z \ # (1)
        --name=notes nginx
    ```

    1. The **Z** option tells Podman to label the content with a private unshared label.
    On systems running SELinux, rootless containers must be explicitly allowed to access bind mounts.
    Containerized processes are not allowed to access files without a SELinux label.


    Output a [SystemD service file](https://docs.podman.io/en/latest/markdown/podman-generate-systemd.1.html) from a container to STDOUT (this must be redirected to a file)
    ```sh
    podman generate systemd --restart-policy=always notes
    ```