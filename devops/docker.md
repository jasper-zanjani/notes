# Docker
## Syntax
###### Command groups
[`container`](#docker-container)
[`image`](#docker-image)

#### `docker container`
[docker container commit]:                        #docker-container              '```&#10;$ docker container commit $CONTAINERID&#10;```&#10;Save container as a new, custom image'
[docker container diff]:                          #docker-container              '```&#10;$ docker container diff $CONTAINERID&#10;```&#10;Display all files added to or removed from base image'
[docker container ls]:                            #docker-container              '```&#10;$ docker container ls&#10;```&#10;'

[`commit`][docker container commit] 
[`diff`][docker container diff] 
[`ls`][docker container ls] 

#### `docker image`
[docker image build]:                         #docker-image                  '```&#10;$ docker image build&#10;```&#10;Create Docker image named '
[docker image tag]:                           #docker-image                  '```&#10;$ docker image tag $IMAGEID $TAG&#10;```&#10;Tag a container image'

[`build`][docker image build] 
[`tag`][docker image tag] 

Create docker image named "hello" with tag "v0.1" from contents of current directory
```
docker image build -t hello:v0.1 . | 
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