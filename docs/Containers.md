# ⚓ Containers

## Docker

Docker **repositories** are associated with a single image, various versions of which can be specified with a **tag**.

**Docker Desktop** is Docker's runtime for Windows which Docker integrates with WSL 2 since June 2019. Docker traditionally distributed its own Linux kernel to use with **Docker Desktop**.

[attach][docker attach] [📄][docker:attach] 
[build][docker build] [📄][docker:build] 
[builder][docker builder] [📄][docker:builder] 
[checkpoint][docker checkpoint] [📄][docker:checkpoint] 
[commit][docker commit] [📄][docker:commit] 
[config][docker config] [📄][docker:config] 
[container][docker container] [📄][docker:container] 
[context][docker context] [📄][docker:context] 
[cp][docker cp] [📄][docker:cp] 
[create][docker create] [📄][docker:create] 
[diff][docker diff] [📄][docker:diff] 
[events][docker events] [📄][docker:events] 
[exec][docker exec] [📄][docker:exec] 
[export][docker export] [📄][docker:export] 
[history][docker history] [📄][docker:history] 
[image][docker image] [📄][docker:image] 
[images][docker images] [📄][docker:images] 
[import][docker import] [📄][docker:import] 
[info][docker info] [📄][docker:info] 
[inspect][docker inspect] [📄][docker:inspect] 
[kill][docker kill] [📄][docker:kill] 
[load][docker load] [📄][docker:load] 
[login][docker login] [📄][docker:login] 
[logout][docker logout] [📄][docker:logout] 
[logs][docker logs] [📄][docker:logs] 
[manifest][docker manifest] [📄][docker:manifest] 
[network][docker network] [📄][docker:network] 
[node][docker node] [📄][docker:node] 
[pause][docker pause] [📄][docker:pause] 
[plugin][docker plugin] [📄][docker:plugin] 
[port][docker port] [📄][docker:port] 
[ps][docker ps] [📄][docker:ps] 
[pull][docker pull] [📄][docker:pull] 
[push][docker push] [📄][docker:push] 
[rename][docker rename] [📄][docker:rename] 
[restart][docker restart] [📄][docker:restart] 
[rm][docker rm] [📄][docker:rm] 
[rmi][docker rmi] [📄][docker:rmi] 
[run][docker run] [📄][docker:run] 
[save][docker save] [📄][docker:save] 
[search][docker search] [📄][docker:search] 
[secret][docker secret] [📄][docker:secret] 
[service][docker service] [📄][docker:service] 
[stack][docker stack] [📄][docker:stack] 
[start][docker start] [📄][docker:start] 
[stats][docker stats] [📄][docker:stats] 
[stop][docker stop] [📄][docker:stop] 
[swarm][docker swarm] [📄][docker:swarm] 
[system][docker system] [📄][docker:system] 
[tag][docker tag] [📄][docker:tag] 
[top][docker top] [📄][docker:top] 
[trust][docker trust] [📄][docker:trust] 
[unpause][docker unpause] [📄][docker:unpause] 
[update][docker update] [📄][docker:update] 
[version][docker version] [📄][docker:version] 
[volume][docker volume] [📄][docker:volume] 
[wait][docker wait] [📄][docker:wait] 

### attach
Connect to a session on a running container [Zacker][Zacker]: 279
```sh
docker attach $CONTID
```
### build
[docker build -&#116;]: #docker-build '```&#10;$ docker build -t&#10;$ docker build --tag&#10;```&#10;Name and optionally a tag in the "name:tag" format'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [t][docker build -&#116;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Build a Docker image from a Dockerfile in the present working directory [PluralSight][pluralsight:70-740-containers]
```sh
docker build -t web .
```
### commit
Save changes made to a modified container to a new image [Zacker][Zacker]: 279
```sh
docker commit $CONTID $USER/$CONT
```
### compose
`up`
`down`
`-d`
`-v`

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



[docker:attach]: https://docs.docker.com/engine/reference/commandline/attach/ "docker attach"
[docker:build]: https://docs.docker.com/engine/reference/commandline/build/ "docker build"
[docker:builder]: https://docs.docker.com/engine/reference/commandline/builder/ "docker builder"
[docker:checkpoint]: https://docs.docker.com/engine/reference/commandline/checkpoint/ "docker checkpoint"
[docker:commit]: https://docs.docker.com/engine/reference/commandline/commit/ "docker commit"
[docker:config]: https://docs.docker.com/engine/reference/commandline/config/ "docker config"
[docker:container]: https://docs.docker.com/engine/reference/commandline/container/ "docker container"
[docker:context]: https://docs.docker.com/engine/reference/commandline/context/ "docker context"
[docker:cp]: https://docs.docker.com/engine/reference/commandline/cp/ "docker cp"
[docker:create]: https://docs.docker.com/engine/reference/commandline/create/ "docker create"
[docker:diff]: https://docs.docker.com/engine/reference/commandline/diff/ "docker diff"
[docker:events]: https://docs.docker.com/engine/reference/commandline/events/ "docker events"
[docker:exec]: https://docs.docker.com/engine/reference/commandline/exec/ "docker exec"
[docker:export]: https://docs.docker.com/engine/reference/commandline/export/ "docker export"
[docker:history]: https://docs.docker.com/engine/reference/commandline/history/ "docker history"
[docker:image]: https://docs.docker.com/engine/reference/commandline/image/ "docker image"
[docker:images]: https://docs.docker.com/engine/reference/commandline/images/ "docker images"
[docker:import]: https://docs.docker.com/engine/reference/commandline/import/ "docker import"
[docker:info]: https://docs.docker.com/engine/reference/commandline/info/ "docker info"
[docker:inspect]: https://docs.docker.com/engine/reference/commandline/inspect/ "docker inspect"
[docker:kill]: https://docs.docker.com/engine/reference/commandline/kill/ "docker kill"
[docker:load]: https://docs.docker.com/engine/reference/commandline/load/ "docker load"
[docker:login]: https://docs.docker.com/engine/reference/commandline/login/ "docker login"
[docker:logout]: https://docs.docker.com/engine/reference/commandline/logout/ "docker logout"
[docker:logs]: https://docs.docker.com/engine/reference/commandline/logs/ "docker logs"
[docker:manifest]: https://docs.docker.com/engine/reference/commandline/manifest/ "docker manifest"
[docker:network]: https://docs.docker.com/engine/reference/commandline/network/ "docker network"
[docker:node]: https://docs.docker.com/engine/reference/commandline/node/ "docker node"
[docker:pause]: https://docs.docker.com/engine/reference/commandline/pause/ "docker pause"
[docker:plugin]: https://docs.docker.com/engine/reference/commandline/plugin/ "docker plugin"
[docker:port]: https://docs.docker.com/engine/reference/commandline/port/ "docker port"
[docker:ps]: https://docs.docker.com/engine/reference/commandline/ps/ "docker ps"
[docker:pull]: https://docs.docker.com/engine/reference/commandline/pull/ "docker pull"
[docker:push]: https://docs.docker.com/engine/reference/commandline/push/ "docker push"
[docker:rename]: https://docs.docker.com/engine/reference/commandline/rename/ "docker rename"
[docker:restart]: https://docs.docker.com/engine/reference/commandline/restart/ "docker restart"
[docker:rm]: https://docs.docker.com/engine/reference/commandline/rm/ "docker rm"
[docker:rmi]: https://docs.docker.com/engine/reference/commandline/rmi/ "docker rmi"
[docker:run]: https://docs.docker.com/engine/reference/commandline/run/ "docker run"
[docker:save]: https://docs.docker.com/engine/reference/commandline/save/ "docker save"
[docker:search]: https://docs.docker.com/engine/reference/commandline/search/ "docker search"
[docker:secret]: https://docs.docker.com/engine/reference/commandline/secret/ "docker secret"
[docker:service]: https://docs.docker.com/engine/reference/commandline/service/ "docker service"
[docker:stack]: https://docs.docker.com/engine/reference/commandline/stack/ "docker stack"
[docker:start]: https://docs.docker.com/engine/reference/commandline/start/ "docker start"
[docker:stats]: https://docs.docker.com/engine/reference/commandline/stats/ "docker stats"
[docker:stop]: https://docs.docker.com/engine/reference/commandline/stop/ "docker stop"
[docker:swarm]: https://docs.docker.com/engine/reference/commandline/swarm/ "docker swarm"
[docker:system]: https://docs.docker.com/engine/reference/commandline/system/ "docker system"
[docker:tag]: https://docs.docker.com/engine/reference/commandline/tag/ "docker tag"
[docker:top]: https://docs.docker.com/engine/reference/commandline/top/ "docker top"
[docker:trust]: https://docs.docker.com/engine/reference/commandline/trust/ "docker trust"
[docker:unpause]: https://docs.docker.com/engine/reference/commandline/unpause/ "docker unpause"
[docker:update]: https://docs.docker.com/engine/reference/commandline/update/ "docker update"
[docker:version]: https://docs.docker.com/engine/reference/commandline/version/ "docker version"
[docker:volume]: https://docs.docker.com/engine/reference/commandline/volume/ "docker volume"
[docker:wait]: https://docs.docker.com/engine/reference/commandline/wait/ "docker wait"

[docker attach]: #attach '```&#10;$ docker attach&#10;```&#10;Attach local standard input, output, and error streams to a running container'
[docker build]: #build '```&#10;$ docker build&#10;```&#10;Build an image from a Dockerfile'
[docker builder]: #builder '```&#10;$ docker builder&#10;```&#10;Manage builds'
[docker checkpoint]: #checkpoint '```&#10;$ docker checkpoint&#10;```&#10;Manage checkpoints'
[docker commit]: #commit '```&#10;$ docker commit&#10;```&#10;Create a new image from a container’s changes'
[docker config]: #config '```&#10;$ docker config&#10;```&#10;Manage Docker configs'
[docker container]: #container '```&#10;$ docker container&#10;```&#10;Manage containers'
[docker context]: #context '```&#10;$ docker context&#10;```&#10;Manage contexts'
[docker cp]: #cp '```&#10;$ docker cp&#10;```&#10;Copy files/folders between a container and the local filesystem'
[docker create]: #create '```&#10;$ docker create&#10;```&#10;Create a new container'
[docker diff]: #diff '```&#10;$ docker diff&#10;```&#10;Inspect changes to files or directories on a container’s filesystem'
[docker events]: #events '```&#10;$ docker events&#10;```&#10;Get real time events from the server'
[docker exec]: #exec '```&#10;$ docker exec&#10;```&#10;Run a command in a running container'
[docker export]: #export '```&#10;$ docker export&#10;```&#10;Export a container’s filesystem as a tar archive'
[docker history]: #history '```&#10;$ docker history&#10;```&#10;Show the history of an image'
[docker image]: #image '```&#10;$ docker image&#10;```&#10;Manage images'
[docker images]: #images '```&#10;$ docker images&#10;```&#10;List images'
[docker import]: #import '```&#10;$ docker import&#10;```&#10;Import the contents from a tarball to create a filesystem image'
[docker info]: #info '```&#10;$ docker info&#10;```&#10;Display system-wide information'
[docker inspect]: #inspect '```&#10;$ docker inspect&#10;```&#10;Return low-level information on Docker objects'
[docker kill]: #kill '```&#10;$ docker kill&#10;```&#10;Kill one or more running containers'
[docker load]: #load '```&#10;$ docker load&#10;```&#10;Load an image from a tar archive or STDIN'
[docker login]: #login '```&#10;$ docker login&#10;```&#10;Log in to a Docker registry'
[docker logout]: #logout '```&#10;$ docker logout&#10;```&#10;Log out from a Docker registry'
[docker logs]: #logs '```&#10;$ docker logs&#10;```&#10;Fetch the logs of a container'
[docker manifest]: #manifest '```&#10;$ docker manifest&#10;```&#10;Manage Docker image manifests and manifest lists'
[docker network]: #network '```&#10;$ docker network&#10;```&#10;Manage networks'
[docker node]: #node '```&#10;$ docker node&#10;```&#10;Manage Swarm nodes'
[docker pause]: #pause '```&#10;$ docker pause&#10;```&#10;Pause all processes within one or more containers'
[docker plugin]: #plugin '```&#10;$ docker plugin&#10;```&#10;Manage plugins'
[docker port]: #port '```&#10;$ docker port&#10;```&#10;List port mappings or a specific mapping for the container'
[docker ps]: #ps '```&#10;$ docker ps&#10;```&#10;List containers'
[docker pull]: #pull '```&#10;$ docker pull&#10;```&#10;Pull an image or a repository from a registry'
[docker push]: #push '```&#10;$ docker push&#10;```&#10;Push an image or a repository to a registry'
[docker rename]: #rename '```&#10;$ docker rename&#10;```&#10;Rename a container'
[docker restart]: #restart '```&#10;$ docker restart&#10;```&#10;Restart one or more containers'
[docker rm]: #rm '```&#10;$ docker rm&#10;```&#10;Remove one or more containers'
[docker rmi]: #rmi '```&#10;$ docker rmi&#10;```&#10;Remove one or more images'
[docker run]: #run '```&#10;$ docker run&#10;```&#10;Run a command in a new container'
[docker save]: #save '```&#10;$ docker save&#10;```&#10;Save one or more images to a tar archive (streamed to STDOUT by default)'
[docker search]: #search '```&#10;$ docker search&#10;```&#10;Search the Docker Hub for images'
[docker secret]: #secret '```&#10;$ docker secret&#10;```&#10;Manage Docker secrets'
[docker service]: #service '```&#10;$ docker service&#10;```&#10;Manage services'
[docker stack]: #stack '```&#10;$ docker stack&#10;```&#10;Manage Docker stacks'
[docker start]: #start '```&#10;$ docker start&#10;```&#10;Start one or more stopped containers'
[docker stats]: #stats '```&#10;$ docker stats&#10;```&#10;Display a live stream of container(s) resource usage statistics'
[docker stop]: #stop '```&#10;$ docker stop&#10;```&#10;Stop one or more running containers'
[docker swarm]: #swarm '```&#10;$ docker swarm&#10;```&#10;Manage Swarm'
[docker system]: #system '```&#10;$ docker system&#10;```&#10;Manage Docker'
[docker tag]: #tag '```&#10;$ docker tag&#10;```&#10;Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE'
[docker top]: #top '```&#10;$ docker top&#10;```&#10;Display the running processes of a container'
[docker trust]: #trust '```&#10;$ docker trust&#10;```&#10;Manage trust on Docker images'
[docker unpause]: #unpause '```&#10;$ docker unpause&#10;```&#10;Unpause all processes within one or more containers'
[docker update]: #update '```&#10;$ docker update&#10;```&#10;Update configuration of one or more containers'
[docker version]: #version '```&#10;$ docker version&#10;```&#10;Show the Docker version information'
[docker volume]: #volume '```&#10;$ docker volume&#10;```&#10;Manage volumes'
[docker wait]: #wait '```&#10;$ docker wait&#10;```&#10;Block until one or more containers stop, then print their exit codes'
[Zacker]: # 'Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017'
[pluralsight:70-740-containers]: https://app.pluralsight.com/library/courses/windows-server-2016-containers-implementing/table-of-contents "Implementing Containers on Windows Server 2016"
[udemy]: https://www.udemy.com/course/docker-mastery-for-nodejs/ "Docker for Node.js Projects From a Docker Captain"
