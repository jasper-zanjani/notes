#### podman
:   
    On RHEL, podman can be installed as a package or as part of a module
    ```sh
    dnf module install container-tools
    ```

    With few exceptions, podman exposes a command-line API that closely imitates that of Docker.

    ??? info "Arch Linux"

        On Arch, **/etc/subuid** and **/etc/subgid** have to be [set](https://wiki.archlinux.org/title/Podman#Set_subuid_and_subgid).
        These are colon-delimited files that define the ranges for namespaced UIDs and GIDs to be used by each user. 
        Conventionally, these ranges begin at 100,000 (for the first, primary user) and contain 65,536 possible values.
        ```
        terry:100000:65536
        alice:165536:65536
        ```

        Then podman has to be migrated
        ```sh
        podman system migrate
        ```

    Podman supports pulling from various repos using aliases that are defined in **/etc/containers/registries.conf.d**.
    RHEL and derivative distributions support additional aliases, some of which reference images that require a [login](https://access.redhat.com/RegistryAuthentication#red-hat-registries-1).
    
    For example, Red Hat offers a Python 2.7 runtime from the RHSCL ([Red Hat Software Collections](https://developers.redhat.com/products/softwarecollections/overview)) repository on registry.access.redhat.com, which does not require authentication.
    However, Python 3.8 is only available from registry.redhat.io, which does.
    Interestingly, other Python runtimes are available from the ubi7 and ubi8 repos from unauthenticated registries.

    Container images are stored in **~/.local/share/containers/storage**.
    ```sh
    podman pull rhscl/httpd-24-rhel7 # (1)
    ```

    1. Alias to **registry.access.redhat.com/rhscl/httpd-24-rhel7**

    The **Z** option is necessary on SELinux systems (like RHEL and derivatives) and tells Podman to label the content with a private unshared label.
    On systems running SELinux, rootless containers must be explicitly allowed to access bind mounts.
    Containerized processes are not allowed to access files without a SELinux label.
    ```sh
    podman run -d -v=/home/jasper/notes/site:/usr/share/nginx/html:Z -p=8080:80 --name=notes nginx
    podman run -d -v=/home/jasper/notes/site:/usr/local/apache2/htdocs:Z -p=8080:80 --name=notes httpd-24
    ```

    Mapped ports can be displayed
    ```sh
    podman port -a
    ```

    Output a [SystemD service file](https://docs.podman.io/en/latest/markdown/podman-generate-systemd.1.html) from a container to STDOUT (this must be redirected to a file)
    ```sh
    podman generate systemd notes \
        --restart-policy=always   \
        --name                    \ # (3)
        --files                   \ # (2)
        --new                     \ # (1)
    ```

    1. Yield unit files that do not expect containers and pods to exist but rather create them based on their configuration files.
    2. Generate a file with a name beginning with the prefix (which can be set with **--container-prefix** or **--pod-prefix**) and followed by the ID or name (if **--name** is also specified)
    3. In conjunction with **--files**, name the service file after the container and not the ID number.

