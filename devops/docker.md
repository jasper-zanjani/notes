[Zacker]: # 'Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017'

# Docker

Microsoft maintained a [Powershell module](https://github.com/microsoft/Docker-PowerShell "PowerShell for Docker") which has been deprecated for years.

## Syntax
###### Command groups
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

[docker attach]: #docker-attach '```&#10;$ docker attach&#10;```&#10;Attach local standard input, output, and error streams to a running container'
[docker build]: #docker-build '```&#10;$ docker build&#10;```&#10;Build an image from a Dockerfile'
[docker builder]: #docker-builder '```&#10;$ docker builder&#10;```&#10;Manage builds'
[docker checkpoint]: #docker-checkpoint '```&#10;$ docker checkpoint&#10;```&#10;Manage checkpoints'
[docker commit]: #docker-commit '```&#10;$ docker commit&#10;```&#10;Create a new image from a container’s changes'
[docker config]: #docker-config '```&#10;$ docker config&#10;```&#10;Manage Docker configs'
[docker container]: #docker-container '```&#10;$ docker container&#10;```&#10;Manage containers'
[docker context]: #docker-context '```&#10;$ docker context&#10;```&#10;Manage contexts'
[docker cp]: #docker-cp '```&#10;$ docker cp&#10;```&#10;Copy files/folders between a container and the local filesystem'
[docker create]: #docker-create '```&#10;$ docker create&#10;```&#10;Create a new container'
[docker diff]: #docker-diff '```&#10;$ docker diff&#10;```&#10;Inspect changes to files or directories on a container’s filesystem'
[docker events]: #docker-events '```&#10;$ docker events&#10;```&#10;Get real time events from the server'
[docker exec]: #docker-exec '```&#10;$ docker exec&#10;```&#10;Run a command in a running container'
[docker export]: #docker-export '```&#10;$ docker export&#10;```&#10;Export a container’s filesystem as a tar archive'
[docker history]: #docker-history '```&#10;$ docker history&#10;```&#10;Show the history of an image'
[docker image]: #docker-image '```&#10;$ docker image&#10;```&#10;Manage images'
[docker images]: #docker-images '```&#10;$ docker images&#10;```&#10;List images'
[docker import]: #docker-import '```&#10;$ docker import&#10;```&#10;Import the contents from a tarball to create a filesystem image'
[docker info]: #docker-info '```&#10;$ docker info&#10;```&#10;Display system-wide information'
[docker inspect]: #docker-inspect '```&#10;$ docker inspect&#10;```&#10;Return low-level information on Docker objects'
[docker kill]: #docker-kill '```&#10;$ docker kill&#10;```&#10;Kill one or more running containers'
[docker load]: #docker-load '```&#10;$ docker load&#10;```&#10;Load an image from a tar archive or STDIN'
[docker login]: #docker-login '```&#10;$ docker login&#10;```&#10;Log in to a Docker registry'
[docker logout]: #docker-logout '```&#10;$ docker logout&#10;```&#10;Log out from a Docker registry'
[docker logs]: #docker-logs '```&#10;$ docker logs&#10;```&#10;Fetch the logs of a container'
[docker manifest]: #docker-manifest '```&#10;$ docker manifest&#10;```&#10;Manage Docker image manifests and manifest lists'
[docker network]: #docker-network '```&#10;$ docker network&#10;```&#10;Manage networks'
[docker node]: #docker-node '```&#10;$ docker node&#10;```&#10;Manage Swarm nodes'
[docker pause]: #docker-pause '```&#10;$ docker pause&#10;```&#10;Pause all processes within one or more containers'
[docker plugin]: #docker-plugin '```&#10;$ docker plugin&#10;```&#10;Manage plugins'
[docker port]: #docker-port '```&#10;$ docker port&#10;```&#10;List port mappings or a specific mapping for the container'
[docker ps]: #docker-ps '```&#10;$ docker ps&#10;```&#10;List containers'
[docker pull]: #docker-pull '```&#10;$ docker pull&#10;```&#10;Pull an image or a repository from a registry'
[docker push]: #docker-push '```&#10;$ docker push&#10;```&#10;Push an image or a repository to a registry'
[docker rename]: #docker-rename '```&#10;$ docker rename&#10;```&#10;Rename a container'
[docker restart]: #docker-restart '```&#10;$ docker restart&#10;```&#10;Restart one or more containers'
[docker rm]: #docker-rm '```&#10;$ docker rm&#10;```&#10;Remove one or more containers'
[docker rmi]: #docker-rmi '```&#10;$ docker rmi&#10;```&#10;Remove one or more images'
[docker run]: #docker-run '```&#10;$ docker run&#10;```&#10;Run a command in a new container'
[docker save]: #docker-save '```&#10;$ docker save&#10;```&#10;Save one or more images to a tar archive (streamed to STDOUT by default)'
[docker search]: #docker-search '```&#10;$ docker search&#10;```&#10;Search the Docker Hub for images'
[docker secret]: #docker-secret '```&#10;$ docker secret&#10;```&#10;Manage Docker secrets'
[docker service]: #docker-service '```&#10;$ docker service&#10;```&#10;Manage services'
[docker stack]: #docker-stack '```&#10;$ docker stack&#10;```&#10;Manage Docker stacks'
[docker start]: #docker-start '```&#10;$ docker start&#10;```&#10;Start one or more stopped containers'
[docker stats]: #docker-stats '```&#10;$ docker stats&#10;```&#10;Display a live stream of container(s) resource usage statistics'
[docker stop]: #docker-stop '```&#10;$ docker stop&#10;```&#10;Stop one or more running containers'
[docker swarm]: #docker-swarm '```&#10;$ docker swarm&#10;```&#10;Manage Swarm'
[docker system]: #docker-system '```&#10;$ docker system&#10;```&#10;Manage Docker'
[docker tag]: #docker-tag '```&#10;$ docker tag&#10;```&#10;Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE'
[docker top]: #docker-top '```&#10;$ docker top&#10;```&#10;Display the running processes of a container'
[docker trust]: #docker-trust '```&#10;$ docker trust&#10;```&#10;Manage trust on Docker images'
[docker unpause]: #docker-unpause '```&#10;$ docker unpause&#10;```&#10;Unpause all processes within one or more containers'
[docker update]: #docker-update '```&#10;$ docker update&#10;```&#10;Update configuration of one or more containers'
[docker version]: #docker-version '```&#10;$ docker version&#10;```&#10;Show the Docker version information'
[docker volume]: #docker-volume '```&#10;$ docker volume&#10;```&#10;Manage volumes'
[docker wait]: #docker-wait '```&#10;$ docker wait&#10;```&#10;Block until one or more containers stop, then print their exit codes'

[`context`][docker context][^][docker:context]
[`cp`][docker cp][^][docker:cp]
[`create`][docker create][^][docker:create]
[`diff`][docker diff][^][docker:diff]
[`events`][docker events][^][docker:events]
[`exec`][docker exec][^][docker:exec]
[`export`][docker export][^][docker:export]
[`history`][docker history][^][docker:history]
[`image`][docker image][^][docker:image]
[`images`][docker images][^][docker:images]
[`import`][docker import][^][docker:import]
[`info`][docker info][^][docker:info]
[`inspect`][docker inspect][^][docker:inspect]
[`kill`][docker kill][^][docker:kill]
[`load`][docker load][^][docker:load]
[`login`][docker login][^][docker:login]
[`logout`][docker logout][^][docker:logout]
[`logs`][docker logs][^][docker:logs]
[`manifest`][docker manifest][^][docker:manifest]
[`network`][docker network][^][docker:network]
[`node`][docker node][^][docker:node]
[`pause`][docker pause][^][docker:pause]
[`plugin`][docker plugin][^][docker:plugin]
[`port`][docker port][^][docker:port]
[`ps`][docker ps][^][docker:ps]
[`pull`][docker pull][^][docker:pull]
[`push`][docker push][^][docker:push]
[`rename`][docker rename][^][docker:rename]
[`restart`][docker restart][^][docker:restart]
[`rm`][docker rm][^][docker:rm]
[`rmi`][docker rmi][^][docker:rmi]
[`run`][docker run][^][docker:run]
[`save`][docker save][^][docker:save]
[`search`][docker search][^][docker:search]
[`secret`][docker secret][^][docker:secret]
[`service`][docker service][^][docker:service]
[`stack`][docker stack][^][docker:stack]
[`start`][docker start][^][docker:start]
[`stats`][docker stats][^][docker:stats]
[`stop`][docker stop][^][docker:stop]
[`swarm`][docker swarm][^][docker:swarm]
[`system`][docker system][^][docker:system]
[`tag`][docker tag][^][docker:tag]
[`top`][docker top][^][docker:top]
[`trust`][docker trust][^][docker:trust]
[`unpause`][docker unpause][^][docker:unpause]
[`update`][docker update][^][docker:update]
[`version`][docker version][^][docker:version]
[`volume`][docker volume][^][docker:volume]
[`wait`][docker wait][^][docker:wait]

##### `docker attach`
Connect to a session on a running container <sup>[Zacker][Zacker]: 279</sup>
```sh
docker attach $CONTID
```
##### `docker commit`
Save changes made to a modified container to a new image <sup>[Zacker][Zacker]: 279</sup>
```sh
docker commit $CONTID $USER/$CONT
```
##### `docker container`
[docker container commit]:                        #docker-container              '```&#10;$ docker container commit $CONTAINERID&#10;```&#10;Save container as a new, custom image'
[docker container diff]:                          #docker-container              '```&#10;$ docker container diff $CONTAINERID&#10;```&#10;Display all files added to or removed from base image'
[docker container ls]:                            #docker-container              '```&#10;$ docker container ls&#10;```&#10;'

[`commit`][docker container commit] 
[`diff`][docker container diff] 
[`ls`][docker container ls] 
##### `docker image`
[docker image build]:                         #docker-image                  '```&#10;$ docker image build&#10;```&#10;Create Docker image named '
[docker image tag]:                           #docker-image                  '```&#10;$ docker image tag $IMAGEID $TAG&#10;```&#10;Tag a container image'

[`build`][docker image build] 
[`tag`][docker image tag] 

Create docker image named "hello" with tag "v0.1" from contents of current directory
```
docker image build -t hello:v0.1 . | 
```
##### `docker network`
[docker network connect]: #docker-network-connect '```&#10;$ docker network connect&#10;```&#10;Connect a container to a network'
[docker network create]: #docker-network-create '```&#10;$ docker network create&#10;```&#10;Create a network'
[docker network disconnect]: #docker-network-disconnect '```&#10;$ docker network disconnect&#10;```&#10;Disconnect a container from a network'
[docker network inspect]: #docker-network-inspect '```&#10;$ docker network inspect&#10;```&#10;Display detailed information on one or more networks'
[docker network ls]: #docker-network-ls '```&#10;$ docker network ls&#10;```&#10;List networks'
[docker network prune]: #docker-network-prune '```&#10;$ docker network prune&#10;```&#10;Remove all unused networks'
[docker network rm]: #docker-network-rm '```&#10;$ docker network rm&#10;```&#10;Remove one or more networks'

[`connect`][docker network connect] 
[`create`][docker network create] 
[`disconnect`][docker network disconnect] 
[`inspect`][docker network inspect] 
[`ls`][docker network ls] 
[`prune`][docker network prune] 
[`rm`][docker network rm] 

Create a new network using the **transparent driver** <sup>[Zacker][Zacker]: 285</sup>
```sh
docker network create -d transparent $NETWORK
```
Create a transpare network with static IP addresses
```sh
docker network create -d transparent --subnet=10.0.0.0/24 --gateway=10.0.0.1 $NETWORK
```
##### `docker ps`
Display a list of all running containers <sup>[Zacker][Zacker]: 278</sup>
```sh
docker ps -a
```
##### `docker rm`
Remove a container completely (must be stopped, unless `-f` is used) <sup>[Zacker][Zacker]: 279</sup>
```sh
docker rm $CONTID
```
##### `docker run`
[docker run -&#105;]: #docker-run '```&#10;$ docker run -i&#10;$ docker run --interactive&#10;```&#10;Keep STDIN open even if not attached&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[docker run -&#116;]: #docker-run '```&#10;$ docker run -t&#10;$ docker run --tty&#10;```&#10;Allocate a pseudo-TTY&#10;Zacker, Craig. _Installation, Storage and Compute with Windows Server 2016: Exam Ref 70-740_. 2017: 274'
[docker run -&#100;]: #docker-run '```&#10;$ docker run -d&#10;$ docker run --detach&#10;```&#10;Run container in background and print container ID'
[docker run -&#112;]: #docker-run '```&#10;$ docker run -p $HOSTPORT:$CONTPORT&#10;$ docker run --publish $HOSTPORT:$CONTPORT&#10;```&#10;Publish a container port to the host port'

<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][docker run -&#100;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`i`][docker run -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][docker run -&#112;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`t`][docker run -&#116;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

Create a Hyper-V container <sup>[Zacker][Zacker]: 275</sup>
```sh
docker run -it --isolation=hyperv microsoft/windowsservercore powershell
```
Bind port 80 of the container to port 8080 of the host <sup>[Zacker][Zacker]: 284</sup>
```sh
docker run -it -p 8080:80 microsoft/windowsservercore powershell
```
Create a container with a static IP address on the network you created
```sh
docker run -it --network=$NETWORK --ip=10.0.0.16 --dns=10.0.0.10 microsoft/windowsservercore powershell
```
##### `docker start`
Start a stopped container <sup>[Zacker][Zacker]: 278</sup>
```sh
docker start $CONTID
```
##### `docker stop`
Stop a container <sup>[Zacker][Zacker]: 278</sup>
```sh
docker stop $CONTID
```
##### `docker tag`
Tag an image on local container host <sup>[Zacker][Zacker]: 272</sup>
```sh
docker tag $USERNAME/$IMAGENAME:$TAG
```
# Dockerfile
A Docker image consists of read-only **layers**, each of which represents an **instruction** that incrementally the changes the image being built up.
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