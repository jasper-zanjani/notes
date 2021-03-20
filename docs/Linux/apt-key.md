# apt-key

Add a public GPG key to keyring
```sh
# Google Cloud SDK
curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add -

# https://medium.com/faun/docker-running-seamlessly-in-windows-subsystem-linux-6ef8412377aa
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```
Install key from Mono
```sh
apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
```

[Add](https://itsfoss.com/solve-gpg-error-signatures-verified-ubuntu/ "How to fix \"The following signatures couldn't be verified\" error in Ubuntu") key specified by apt in error message
```sh
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 68980A0EA10B4DE8
```