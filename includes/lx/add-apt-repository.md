**add-apt-repository**{: #add-apt-repository }
:   === "Docker"

        ```sh
        add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
        ```
    
    === "Ubuntu repo"

        ```sh
        add-apt-repository "deb http://security.ubuntu.com/ubuntu trusty-security main universe"
        ```
    
    === "Regolith Linux"

        ```sh
        add-apt-repository -y ppa:kgilmer/regolith-stable
        ```