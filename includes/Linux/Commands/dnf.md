#### dnf

View history of dnf commands
```sh
dnf history
```

View all packages installed by user
```sh
dnf history userinstalled
```

[**Package group** <sup>:material-fedora:</sup>][https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/]

=== "Display information"

    ```sh
    dnf group info virtualization
    ```

=== "Install"

    ```sh
    dnf group install virtualization
    dnf install @virtualization

    # Include optional packages
    dnf group install --with-optional virtualization
    ```

Global dnf configuration is stored in either **/etc/yum.conf** or **/etc/dnf.conf**{: #dnf-config }.

Exclude packages from updates permanently
```ini
[main]
exclude=kernel* php*
```

Repositories are INI files placed in  **/etc/yum.repos.d/**, but they can also be added from the command-line using **dnf config-manager**.
The argument to **`--add-repo`** can be the repo file or the baseurl itself, although setting multiple options from the command-line does not appear to be supported.

=== ":material-docker: Docker"

    ```ini
    [docker-ce-stable]
    name=Docker CE Stable - $basearch
    baseurl=https://download.docker.com/linux/fedora/$releasever/$basearch/stable
    enabled=1
    gpgcheck=1
    gpgkey=https://download.docker.com/linux/fedora/gp
    ```

=== ":material-kubernetes: Kubernetes"

    ```ini
    [kubernetes]
    name=Kubernetes
    baseurl=https://packages.cloud.google.com/yum/repos/kubernetes-el7-x86_64
    enabled=1
    gpgcheck=1
    repo_gpgcheck=1
    gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg
    ```

=== ":material-google: gcloud"

    ```ini
    [google-cloud-sdk]
    name=Google Cloud SDK
    baseurl=https://packages.cloud.google.com/yum/repos/cloud-sdk-el7-x86_64
    enabled=1
    gpgcheck=1
    repo_gpgcheck=0
    gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg
            https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg
    ```

