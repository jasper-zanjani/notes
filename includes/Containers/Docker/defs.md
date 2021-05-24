## :material-book: Glossary


**Dockerfile**{: #dockerfile } :material-docker:
:   A Docker image consists of read-only **layers**, each of which represents an **instruction** that incrementally the changes the image being built up. 
    Dockerfiles can be used to construct new images using `docker build`.
    The build process can be optimized by placing multiple commands in the same `RUN` instruction.
    Dockerfiles are named simply "Dockerfile" with no extension or variation.

    === "Node on Alpine"

        ```dockerfile
        FROM alpine
        RUN apk update && apk add nodejs
        COPY . /app
        WORKDIR /app
        CMD ["node","index.js"]
        ```

    === "Windows Server Nano"

        ```dockerfile
        FROM microsoft/windowsservercore
        RUN powershell -command install-windowsfeature dhcp -includemanagementtools
        RUN powershell -configurationname microsoft.powershell -command add-dhcpserverv4scope -state active -activatepolicies $true -name scopetest -startrange 10.0.0.100 -endrange 10.0.0.200 -subnetmask 255.255.255.0
        RUN md boot
        COPY ./bootfile.wim c:/boot/
        CMD powershell
        ```

    === "Windows Server Core"

        ```dockerfile
        FROM microsoft/windowsservercore
        MAINTAINER @mike_pfeiffer
        RUN powershell.exe -Command Install-WindowsFeature Web-Server
        COPY ./websrc c:/inetpub/wwwroot
        CMD [ "powershell" ]
        ```

**ENTRYPOINT**{: #entrypoint } :material-docker:
:   Rarely used Docker declaration.
    When ENTRYPOINT is present, the [CMD](#cmd) declaration becomes the default argument passed to the command in ENTRYPOINT.

    The Kubernetes **--command** flag (**`pod.spec.containers.command`** resource) can override the contents of ENTRYPOINT.


**tmpfs**{: #tmpfs } :material-docker:
:   RAM-backed file system used in Docker containers

**Volume**{: #volume } :material-docker:
:   A volume is a special directory in the Docker host that can be mounted to the container that is used to achieve persistent storage.

