### `apt`
Upgrade distribution
```sh
apt dist-upgrade
```
Install local {file} as a package
```sh
apt install file
```
Install {package}
```sh
apt install package
```
Search for packages matching {searchexpression}
```sh
apt list pattern
```
Remove {package}
```sh
apt remove package
```
Update package database
```sh
apt update
```
Upgrade all packages
```sh
apt upgrade
```

### `apt-cache`
Display package information regarding package cache

Command   | Description
:---      | :---
`search`  | display all packages with the search term listed in the package name or description
`showpkg` | display information about a package
`stats`   | display statistics about the package cache
`showsrc` | display information about a source package
`depends` | display a package's dependencies
`rdepends`| display a package's reverse dependencies, i.e. what packages for which this package is a dependency

Display basic information about each available package and its dependencies 
```sh
apt-cache dump
```

### `apt-key`
Add a public GPG key to keyring
```sh
curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add - # Google Cloud SDK
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -	# Docker
```

### `add-apt-repository`
Add a repository
```sh
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu trusty-security main universe"
```
