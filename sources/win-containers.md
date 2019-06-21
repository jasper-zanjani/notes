# Introduction to Windows Containers, John McCabe and Michael Friis

## Containers 101

A __container__ is a form of virtualzied focused at the operating system layer, geared toward deploying and running applications without requiring a full virtual machine. A __container engine__ is to a container what a __hypervisor__ is to a virtual machine.

In a containerized environment, each application runs in an isolated memory space, but sharing the underlying host kernel.

### Containers versus virtual machines

VMs offer flexibility to an enterprise, which can run any type of application within them and assigned resources based on need. They are scaled-up effectively to improve performance. But they require individual management, which increases overhead. And a VM will take up a predefined set of resources while running.

Containers have a much smaller footprint in terms of resources and management overhead. Scaling with containers is far more efficient.

### Container types
  - __Windows Server Containers__ share a kernel with the container host and all running containers 
  - __Windows Server Containers with Hyper-V Isolation__ provide an isolated kernelthrough a utility VM on the host, increasing security of the container because isolation mechanisms are enforced at the hardware level

### Container host architecture

With Windows Server 2016, nested virtualization can be combined with Windows Server Container types, such that a VM running on Hyper-V can run a Hyper-V container which runs, in turn, another Windows Server container

### Container management

Docker is the main management tool used for administering containers.

### Container images

Container images are built upon a base OS layer, provided and maintained by Microsoft in an image registry.
