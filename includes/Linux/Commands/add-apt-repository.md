#### add-apt-repository


=== ":material-ubuntu: Ubuntu repo"

    ```sh
    add-apt-repository "deb http://security.ubuntu.com/ubuntu trusty-security main universe"
    ```

=== ":material-docker: Docker"

    ```sh
    add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
    ```
 
=== ":material-google: gcloud"

    ```sh
    add-apt-repository "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] http://packages.cloud.google.com/apt cloud-sdk main"
    ```

=== "mailx"

    ```sh
    add-apt-repository "deb http://security.ubuntu.com/ubuntu trusty-security main universe"
    ```

=== "MongoDB repo"

    ```sh
    add-apt-repository"deb [ arch=amd64 ] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.2 multiverse"
    ```

=== "Regolith Linux"

    ```sh
    add-apt-repository "add-apt-repository -y ppa:kgilmer/regolith-stable"
    ```



APT **repositories** (/etc/apt/sources.list) are made of three parts, delimited by whitespace: ([src](https://kali.training/topic/introduction-to-apt/ "Introduction to APT"))

- Source type: `deb` for binary packages or `deb-src` for source packages
- Base URL of the source: beginning with `http://`, `ftp://`, `file://`, or even `cdrom:`
- Name of the chosen distribution followed by sections that differentiate packages by license. Kali, for example, contains `main`, `non-free`, and `contrib`.

```sh
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic main restricted
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic universe
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic-updates main restricted
deb http://us-central1.gce.archive.ubuntu.com/ubuntu/ bionic-updates universe
```
