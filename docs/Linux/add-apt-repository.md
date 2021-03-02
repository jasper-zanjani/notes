Add Docker repos ([src](https://medium.com/faun/docker-running-seamlessly-in-windows-subsystem-linux-6ef8412377aa))
```sh
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
```

```sh
add-apt-repository "deb http://security.ubuntu.com/ubuntu trusty-security main universe"
```
[Convert][LPM 231 Regolith Linux] Ubuntu to Regolith Linux 
```sh
add-apt-repository -y ppa:kgilmer/regolith-stable
apt updatelib
apt install regolith-desktop
```