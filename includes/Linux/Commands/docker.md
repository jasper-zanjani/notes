#### docker
:   
    Docker **repositories** are associated with a single image, various versions of which can be specified with a **tag**.

--8<-- "includes/Containers/repo.md"

On Windows, **Docker Desktop** is Docker's runtime which has been integrated with WSL 2 since June 2019. 
Previous to that, Docker distributed its own Linux kernel to use on Windows hosts.

On Linux, Docker must be run as root, although a user can be added to the **docker** group to manage Docker as a [non-root user](https://docs.docker.com/engine/install/linux-postinstall/) for convenience.
This is called [**rootless mode**](https://docs.docker.com/engine/security/rootless/), where both the daemon and containers run in a user namespace.


#### docker-network
:   
    On Linux, the Docker daemon creates a bridge named **docker0**, which is assigned an unused private IP range and address.
    Every container is associated with a pair of virtual Ethernet interfaces, of which one is visible to the container and the other is tied to this bridge.

    Container networks can use various drivers, which are associated with specific key-value pairs in daemon.json:

    - **NAT**: containers reside in their own network and the host acts as gateway and set with `{ "fixed-cidr" : "10.0.0.0/24" }`.
    - **Transparent**: containers are assigned IP addresses on the same physical network to which the host belongs (similar to **External** virtual switches in Hyper-V), set with `{ "bridge": "none" }`.

    Create a new network bridge using the **transparent driver**
    ```sh
    docker network create -d transparent $NETWORKNAME
    ```

    Create a transparent network bridge with static IP addresses
    ```sh
    docker network create -d transparent --subnet=10.0.0.0/24 --gateway=10.0.0.1 $NETWORK
    ```

#### docker-volume
:   
    Docker has several options for persistent storage:

    - [**Volumes**](https://docs.docker.com/storage/volumes/) are stored in a part of the host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Docker).
    - [**Bind mounts**](https://docs.docker.com/storage/bind-mounts/) map a file or directory on the host machine to a mount point in the container. They have less functionality than volumes.
    - **tmpfs mounts** are stored in-memory only, and are available only on Linux.

    Volumes can be mounted using **--volume** or **--mount**.

    - **--volume** syntax combines all options together in one field.
    - **--mount** is more explicit and verbose, with key-value pairs defined for the following keys:
        - `type`
        - `source`
        - `destination` (also `dst`, `target`)
        - `readonly`
        - `volume-opt`

    Connect to a session on a running container
    ```sh
    docker attach $CONTID
    ```

Build a Docker image from a [Dockerfile](#dockerfile) in the present working directory
```sh
docker build -t web .
```

Save changes made to a modified container to a new image
```sh
docker commit $CONTID $USER/$CONT
```

#### docker-compose
:   
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

Remove a container completely (must be stopped, unless `-f` is used)
```sh
docker rm $CONTID
```

Create a Hyper-V container
```sh
docker run -it --isolation=hyperv microsoft/windowsservercore powershell
```

Bind port 80 of the container to port 8080 of the host
```sh
docker run -it -p 8080:80 microsoft/windowsservercore powershell
```

Create a container with a static IP address on the network you created
```sh
docker run -it --network=$NETWORK --ip=10.0.0.16 --dns=10.0.0.10 microsoft/windowsservercore powershell
```

To detach from a running container use the keyboard shortcuts ++Ctrl+P+Ctrl+Q++

Start a stopped container
```sh
docker start $CONTID
```

Stop a container
```sh
docker stop $CONTID
```

**docker tag** can be used to rename images and to prepare them to be pushed to a repository using **docker push**

Tag an image on local container host
```sh
docker tag $USERNAME/$IMAGENAME:$TAG
```

Display data volumes
```sh
docker volume ls
```

## Glossary

--8<-- "includes/Containers/Docker/glossary.md"