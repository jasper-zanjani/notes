# Containers

Containers run applications in an **isolated namespace**, meaning it only has access to resources that are made available to it by the container runtime.
**Resource governance** means that a container has access only to a specified number of processor cycles, system memory, and other resources.
Containers allow applications to be packaged with their dependencies in **container images**, which will run the same regardless of underlying operating system or infrastructure and are downloaded from **container registries** like **Docker Hub**.
Container registries are not to be confused with **repositories**, which are subcomponents of registries.

<!-- #region Windows Server -->

Windows Server 2016 supports **Windows Server Containers** and **Hyper-V Containers**, which create a separate copy of the operating system kernel for each container.
The "Containers" feature must be installed on Windows Server 2016 hosts, and to create Hyper-V containers the Hyper-V role must also be installed (although the Hyper-V management tools are not necessary if VMs are not going to created).
Windows container hosts need to have Windows installed to C:.

Nano Server once could serve as Docker hosts, but no longer; Nano Servers are now intended to be deployed as containers themselves.

The [Powershell Docker module](https://github.com/microsoft/Docker-PowerShell "PowerShell for Docker") has been deprecated for years.

<!-- #endregion -->

### :material-microsoft-azure: Azure

A volume represents a way to store, retrieve, and persist data across pods and through the application lifecycle. 
In the context of Azure, Kubernetes can use two types of data volume:

- **Azure Disks** using Azure Premium (SSDs) or Azure Standard (HDDs).
- **Azure Files** using a SMB 3.0 share backed by an Azure Storage account.

### :material-google: GCP

--8<-- "includes/Cloud/GCP/gcloud-container.md"
