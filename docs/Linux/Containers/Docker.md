# Docker

Docker **repositories** are associated with a single image, various versions of which can be specified with a **tag**.

--8<-- "includes/Containers/repo.md"

On Windows, **Docker Desktop** is Docker's runtime which has been integrated with WSL 2 since June 2019. 
Previous to that, Docker distributed its own Linux kernel to use on Windows hosts.

On Linux, Docker must be run as root, although a user can be added to the **docker** group to manage Docker as a [non-root user <sup>:material-docker:</sup>](https://docs.docker.com/engine/install/linux-postinstall/) for convenience.
This is called [**rootless mode** <sup>:material-docker:</sup>](https://docs.docker.com/engine/security/rootless/), where both the daemon and containers run in a user namespace.


On systems running SELinux, rootless containers must be explicitly allowed to access bind mounts.
Containerized processes are not allowed to access files without a SELinux label.

=== "Podman"

    The **Z** option tells Podman to label the content with a private unshared label
    ```sh
    podman run -d --rm -p=8080:80 -v=/home/jasper/notes/site:/usr/share/nginx/html:Z --name=notes nginx
    ```



### Networking

On Linux, the Docker daemon creates a virtual Ethernet bridge named **docker0**, which is assigned an unused private IP range and address.
Every container is associated with a pair of virtual Ethernet interfaces, of which one is visible to the container and the other is tied to this bridge.

- The container's interface is named following a pattern similar to `eth0@if17`, where the number after **if** is the index of the host's interface.
The IP address visible to the container belongs to the bridge's subnet.
- The host's interface is named similar to `vethe8b40b8@if16`, where again the number after **if** indicates the index of the container's interface.

Container networks can use various drivers, which are associated with specific key-value pairs in `daemon.json`:

- **NAT**: containers reside in their own network and the host acts as gateway and set with `{ "fixed-cidr" : "10.0.0.0/24" }`.
- **Transparent**: containers are assigned IP addresses on the same physical network to which the host belongs (similar to **External** virtual switches in Hyper-V), set with `{ "bridge": "none" }`.

Create a new network bridge using the **transparent driver** [Zacker][Zacker]: 285
```sh
docker network create -d transparent $NETWORKNAME
```
Create a transparent network bridge with static IP addresses
```sh
docker network create -d transparent --subnet=10.0.0.0/24 --gateway=10.0.0.1 $NETWORK
```

### Storage

Docker has several options for persistent storage:

- [**Volumes** <sup>:material-docker:</sup>](https://docs.docker.com/storage/volumes/) are stored in a part of the host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Docker).
- [**Bind mounts** <sup>:material-docker:</sup>](https://docs.docker.com/storage/bind-mounts/) map a file or directory on the host machine to a mount point in the container. They have less functionality than volumes.
- **`tmpfs` mounts** are stored in the host system's memory only, and are available only on Linux.

Volumes can be mounted using `-v`/`--volume` or `--mount`.

- **`--volume`** syntax combines all options together in one field.
- **`--mount`** is more explicit and verbose, with key-value pairs defined for the following keys:
    - `type`
    - `source`
    - `destination` (also `dst`, `target`)
    - `readonly`
    - `volume-opt`

Connect to a session on a running container ([src][Zacker])
```sh
docker attach $CONTID
```

Build a Docker image from a [Dockerfile](#dockerfile) in the present working directory
```sh
docker build -t web .
```

Save changes made to a modified container to a new image ([Zacker][Zacker])
```sh
docker commit $CONTID $USER/$CONT
```

[Simple][udemy] Docker compose file
```yaml
version: '2.0'

services:
  web:
    image: sample-01
    build: .
    ports:
      - '3000:3000'
```

```sh
docker-compose up -d
```
Bring everything down
```sh
docker-compose down -v
```

Create docker image named "hello" with tag "v0.1" from contents of current directory
```sh
docker image build -t hello:v0.1 .
```


Display a list of all running containers
```sh
docker ps -a
```
Remove a container completely (must be stopped, unless `-f` is used) [Zacker][Zacker]: 279
```sh
docker rm $CONTID
```

Create a Hyper-V container [Zacker][Zacker]: 275
```sh
docker run -it --isolation=hyperv microsoft/windowsservercore powershell
```
Bind port 80 of the container to port 8080 of the host [Zacker][Zacker]: 284
```sh
docker run -it -p 8080:80 microsoft/windowsservercore powershell
```
Create a container with a static IP address on the network you created
```sh
docker run -it --network=$NETWORK --ip=10.0.0.16 --dns=10.0.0.10 microsoft/windowsservercore powershell
```
To detach from a running container use the keyboard shortcuts <kbd>Ctrl</kbd><kbd>P</kbd><kbd>Ctrl</kbd><kbd>Q</kbd>


Start a stopped container [Zacker][Zacker]: 278
```sh
docker start $CONTID
```

Stop a container [Zacker][Zacker]: 278
```sh
docker stop $CONTID
```

`docker tag` can be used to rename images and to prepare them to be [pushed][docker push] to a repository.

Tag an image on local container host [Zacker][Zacker]: 272
```sh
docker tag $USERNAME/$IMAGENAME:$TAG
```

Display data volumes [PluralSight][pluralsight:70-740-containers]
```sh
docker volume ls
```

## Glossary

--8<-- "includes/Containers/Docker/glossary.md"