# Containers


## Docker

Docker **repositories** are associated with a single image, various versions of which can be specified with a **tag**.

**Docker Desktop** is Docker's runtime for Windows which Docker integrates with WSL 2 since June 2019. Docker traditionally distributed its own Linux kernel to use with **Docker Desktop**.


Connect to a session on a running container ([src][Zacker])
```sh
docker attach $CONTID
```

Build a Docker image from a Dockerfile in the present working directory ([src][pluralsight:70-740-containers])
```sh
docker build -t web .
```

Save changes made to a modified container to a new image ([Zacker][Zacker])
```sh
docker commit $CONTID $USER/$CONT
```

- separate binary coded in Python, available through `pip`
- can be used from the CLI as well as from YAML files ("compose file")
- can be used as a replacement for the normal `docker` CLI
- intended for use in developer workflows to avoid shell scripts that would typically be used to facilitate long command-line `docker` invocations
- not intended for production, for which Docker Swarm is preferable
- v2 is focused on development or testing with a single node
- v3 is focused on multi-node orchestration features

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

### container
[docker container commit]:                        #docker-container              '```&#10;$ docker container commit $CONTAINERID&#10;```&#10;Save container as a new, custom image'
[docker container diff]:                          #docker-container              '```&#10;$ docker container diff $CONTAINERID&#10;```&#10;Display all files added to or removed from base image'
[docker container ls]:                            #docker-container              '```&#10;$ docker container ls&#10;```&#10;'

[commit][docker container commit] 
[diff][docker container diff] 
[ls][docker container ls] 
### image
[docker image build]:                         #docker-image                  '```&#10;$ docker image build&#10;```&#10;Create Docker image named '
[docker image tag]:                           #docker-image                  '```&#10;$ docker image tag $IMAGEID $TAG&#10;```&#10;Tag a container image'

[build][docker image build] 
[tag][docker image tag] 

Create docker image named "hello" with tag "v0.1" from contents of current directory
```
docker image build -t hello:v0.1 . | 
```
### network
[docker network connect]: #docker-network-connect '```&#10;$ docker network connect&#10;```&#10;Connect a container to a network'
[docker network create]: #docker-network-create '```&#10;$ docker network create&#10;```&#10;Create a network'
[docker network disconnect]: #docker-network-disconnect '```&#10;$ docker network disconnect&#10;```&#10;Disconnect a container from a network'
[docker network inspect]: #docker-network-inspect '```&#10;$ docker network inspect&#10;```&#10;Display detailed information on one or more networks'
[docker network ls]: #docker-network-ls '```&#10;$ docker network ls&#10;```&#10;List networks'
[docker network prune]: #docker-network-prune '```&#10;$ docker network prune&#10;```&#10;Remove all unused networks'
[docker network rm]: #docker-network-rm '```&#10;$ docker network rm&#10;```&#10;Remove one or more networks'

[connect][docker network connect] 
[create][docker network create] 
[disconnect][docker network disconnect] 
[inspect][docker network inspect] 
[ls][docker network ls] 
[prune][docker network prune] 
[rm][docker network rm] 

Container networks can use various drivers, which are associated with specific key-value pairs in `daemon.json`:
- **NAT**: containers reside in their own network and the host acts as gateway and set with `{ "fixed-cidr" : "10.0.0.0/24" }`.
- **Transparent**: containers are assigned IP addresses on the same physical network to which the host belongs (similar to **External** virtual switches in Hyper-V), set with `{ "bridge": "none" }`.

Create a new network using the **transparent driver** [Zacker][Zacker]: 285
```sh
docker network create -d transparent $NETWORKNAME
```
Create a transparent network with static IP addresses
```sh
docker network create -d transparent --subnet=10.0.0.0/24 --gateway=10.0.0.1 $NETWORK
```
### ps
Display a list of all running containers [Zacker][Zacker]: 278
```sh
docker ps -a
```
### rm
Remove a container completely (must be stopped, unless `-f` is used) [Zacker][Zacker]: 279
```sh
docker rm $CONTID
```
### rmi
Can be used to remove extraneous tags
### run
[docker run -&#105;]: #docker-run '```&#10;$ docker run -i&#10;$ docker run --interactive&#10;```&#10;Keep STDIN open even if not attached&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[docker run -&#116;]: #docker-run '```&#10;$ docker run -t&#10;$ docker run --tty&#10;```&#10;Allocate a pseudo-TTY&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[docker run -&#100;]: #docker-run '```&#10;$ docker run -d&#10;$ docker run --detach&#10;```&#10;Run container in background and print container ID'
[docker run -&#112;]: #docker-run '```&#10;$ docker run -p $HOSTPORT:$CONTPORT&#10;$ docker run --publish $HOSTPORT:$CONTPORT&#10;```&#10;Publish a container port to the host port'
[docker run -&#118;]: #docker-run '```&#10;$ docker run -v $HOSTPATH:$CONTAINERPATH&#10;$ docker run --volume $HOSTPATH:$CONTAINERPATH&#10;```&#10;Bind-mount a volume.'
[docker run -&#109;]: #docker-run '```&#10;$ docker run -m&#10;$ docker run --memory&#10;```&#10;Limit memory'
[docker run --cpu-percent]: #docker-run '```&#10;$ docker run --cpu-percent&#10;```&#10;CPU percent (Windows only)'
[docker run --network]: #docker-run '```&#10;$ docker run --network&#10;```&#10;Connect a container to a network'
[docker run --volumes-from]: #docker-run '```&#10;$ docker run --volumes-from&#10;```&#10;Mount volumes from the specified container(s)'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][docker run -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`i`][docker run -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`m`][docker run -&#109;] <code>&nbsp;</code> <code>&nbsp;</code> [`p`][docker run -&#112;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`t`][docker run -&#116;] <code>&nbsp;</code> [`v`][docker run -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>\
[cpu-percent][docker run --cpu-percent]
[network][docker run --network]
[volumes-from][docker run --volumes-from]

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
### start
Start a stopped container [Zacker][Zacker]: 278
```sh
docker start $CONTID
```
### stop

Stop a container [Zacker][Zacker]: 278
```sh
docker stop $CONTID
```
### tag
`docker tag` can be used to rename images and to prepare them to be [pushed][docker push] to a repository.

Tag an image on local container host [Zacker][Zacker]: 272
```sh
docker tag $USERNAME/$IMAGENAME:$TAG
```
### volume

Docker has several options for containers to store files in a persistent manner:
- **Volumes** are stored in a part of the host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Docker).
- **Bind mounts** may be stored anywhere on the host system and are specified by [docker run --volume][docker run -&#118;].
- **`tmpfs` mounts** are stored in the host system's memory only, and are available only on Linux.

Display data volumes [PluralSight][pluralsight:70-740-containers]
```sh
docker volume ls
```

### Dockerfile

A Docker image consists of read-only **layers**, each of which represents an **instruction** that incrementally the changes the image being built up. 
Using [docker build][docker build], Dockerfiles can be used to construct new images.
The build process can be optimized by placing multiple commands in the same `RUN` instruction.
Dockerfiles are named simply "Dockerfile" with no extension or variation.

```dockerfile
FROM alpine
RUN apk update && apk add nodejs
COPY . /app
WORKDIR /app
CMD ["node","index.js"]
```
[Zacker][Zacker]: 289
```dockerfile
FROM microsoft/windowsservercore
RUN powershell -command install-windowsfeature dhcp -includemanagementtools
RUN powershell -configurationname microsoft.powershell -command add-dhcpserverv4scope -state active -activatepolicies $true -name scopetest -startrange 10.0.0.100 -endrange 10.0.0.200 -subnetmask 255.255.255.0
RUN md boot
COPY ./bootfile.wim c:/boot/
CMD powershell
```
[PluralSight][pluralsight:70-740-containers]
```dockerfile
FROM microsoft/windowsservercore
MAINTAINER @mike_pfeiffer
RUN powershell.exe -Command Install-WindowsFeature Web-Server
COPY ./websrc c:/inetpub/wwwroot
CMD [ "powershell" ]
```

## Kubernetes

## 📘 Glossary

### Deployment

### Pod

### ReplicaSet

<!-- #region -->
[Zacker]: # 'Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017'
[pluralsight:70-740-containers]: https://app.pluralsight.com/library/courses/windows-server-2016-containers-implementing/table-of-contents "Implementing Containers on Windows Server 2016"
[udemy]: https://www.udemy.com/course/docker-mastery-for-nodejs/ "Docker for Node.js Projects From a Docker Captain"
<!-- #endregion -->