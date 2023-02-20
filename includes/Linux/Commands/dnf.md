### dnf
:   
    View history of dnf commands
    ```sh
    dnf history
    dnf history userinstalled # View all packages installed by user
    ```

    [**Package groups**](https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/) can be specified using the **group** command or by prefixing the package group name with **`@`**

    ```sh
    dnf info @virtualization # dnf group info virtualization
    dnf install @virtualization # dnf group install virtualization
    dnf install --with-optional @virtualization # Include optional packages
    ```

    Remove the configuration backend supporting the use of legacy ifcfg files in NetworkManager.
    ```sh
    dnf remove NetworkManager-initscripts-ifcfg-rh
    ```

    [**Modules**](https://docs.fedoraproject.org/en-US/modularity/using-modules/) are special package groups representing an application, runtime, or a set of tools. 
    The [Node.js module](https://nodejs.org/en/download/package-manager/#centos-fedora-and-red-hat-enterprise-linux) allows you to select several **streams** corresponding to major versions.
    ```sh
    dnf module install nodejs:12
    ```

    Global dnf configuration is stored in either **/etc/yum.conf** or **/etc/dnf.conf**.

    ```ini
    [main]
    ; Exclude packages from updates permanently
    exclude=kernel* php*
    ; Suppress confirmation
    assumeyes=True
    ```

    The configuration can be dumped from the command-line (as root)
    ```sh
    dnf config-manager --dump
    ```

#### Repos
:   
    Repositories are INI files placed in  **/etc/yum.repos.d/**, but they can also be displayed and manipulated from the command-line.
    
    ```sh title="Repositories"
    # Display repos
    dnf repolist # -v

    # Display enabled repos
    dnf repolist --enabled

    # Display a single repo
    dnf repoinfo docker-ce-stable

    # Add repo
    dnf config-manager --add-repo $REPO-URL
    
    # Disable repo
    dnf config-manager --set-disabled $REPO-NAME
    ```

    ```ini title="Example repos"
    [docker-ce-stable]
    name=Docker CE Stable - $basearch
    baseurl=https://download.docker.com/linux/fedora/$releasever/$basearch/stable
    enabled=1
    gpgcheck=1
    gpgkey=https://download.docker.com/linux/fedora/gp

    [kubernetes]
    name=Kubernetes
    baseurl=https://packages.cloud.google.com/yum/repos/kubernetes-el7-x86_64
    enabled=1
    gpgcheck=1
    repo_gpgcheck=1
    gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg

    [google-cloud-sdk]
    name=Google Cloud SDK
    baseurl=https://packages.cloud.google.com/yum/repos/cloud-sdk-el7-x86_64
    enabled=1
    gpgcheck=1
    repo_gpgcheck=0
    gpgkey=https://packages.cloud.google.com/yum/doc/yum-key.gpg https://packages.cloud.google.com/yum/doc/rpm-package-key.gpg
    ```

    **Modules** are collections of packages that are installed together.
    They often also have **profiles** available, which are variants of the module: i.e. client, server, common, devel, etc.
    ```sh
    dnf module list php
    dnf module install php:7.4/devel
    dnf module reset php
    ```
