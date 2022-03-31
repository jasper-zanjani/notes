# pythonnet
- Docs: [?](https://github.com/pythonnet/pythonnet "Github") [!](http://pythonnet.github.io/)
Developers recommend Mono version 5.20.1 <sup>Issues [939](https://github.com/pythonnet/pythonnet/issues/939)</sup>

On Ubuntu, the `eoan` `universe` repository has to be added 
```
deb https://archive.ubuntu.com/ubuntu/ eoan universe
deb https://archive.ubuntu.com/ubuntu/ eoan-updates universe
```
But I can't figure out how to add the older version, because the recommended syntax produces the error "Unable to correct problems, you have held broken packages"
```sh
sudo apt install mono-devel=5.18.0.240+dfsg-3
```
Maybe try the [tarballs](https://download.mono-project.com/sources/mono/) on Mono's website...
Or maybe there's [another repo](https://github.com/jonemo/pythonnet-docker/blob/master/python3.6.5-mono5.4.1.6-pythonnet2.4.0.dev0.Dockerfile) I don't know about..
```sh
apt install clang libglib2.0-dev python3-dev
```
```sh
pip install pycparser pythonnet
pip install -U setuptools
```