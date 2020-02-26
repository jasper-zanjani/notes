# Podman
Comprehensive container management technology that borrows Docker syntax, developed by Red Hat. The name is short for "pod manager", using Kubernetes' coinage of the term "pod". Unlike Docker, in which containers send messages to the Docker daemon which runs as root (potentially a security concern), Podman containers run as traditional **fork-exec** children of the Podman process, allowing these processes to be run without root privileges.

Every podman pod contains an **infra container** whose only purpose is to hold the namespaces associated with the pod and allow podman to connect other containers to the pod.\
Podman uses a utility named **`conmon`**, or container monitor, which keeps the terminal of containers open in order to execute commands.

Create a pod
```sh
podman pod create --name heise
```
List pods
```sh
podman pod list
```
Download a container image
Podman uses the `pull` command, a borrowing from Docker
```sh
podman pull docker.io/library/alpine:latest
```
Run a container
```sh
podman run -d alpine top 
```
Run a command within the container
This will display running processes, including the `top` command from the example above.
```sh
podman exec 5f421b01faa ps -ef
```
List pods
```sh
podman ps --pod - all
```