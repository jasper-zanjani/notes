### `yum`
Yellow Dog Updater, Modified package manager (Yellow Dog was a variation of Red Hat for PowerPC architectures), package manager more commonly used today. [[35](sources.md), [37](sources.md)]

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-y`    | `--assumeyes`           | respond to any prompt with "yes" automatically
`-x`    | `--exclude`             | exclude specific packages from updates [[38](sources.md)]

Install {package}
```sh
yum install package
yum groupinstall packagegroup # package group
yum --enablerepo=repo install package # from a specific {repo}
```
Remove {package} 
```sh
yum remove package
yum -y remove package # without confirmation
yum erase package # as well as the cached package
yum groupremove packagegroup
```
Update installed packages
```sh
yum update
yum update package # update a specific {package}
yum upgrade # equivalent to `yum update --obsoletes`
yum groupupdate packagegroup

# Exclude some packages from update
yum update --exclude=kernel
yum update --exclude=httpd,php
```
List all available packages in database
```sh
yum list
yum grouplist
```
List all installed packages
```sh
yum list installed
```
Query repos for information on {package}
```sh
yum info package
```
Find packages
```sh
yum list name # name matching {name} exactly
yum search pattern # search for package name matching {pattern}
```
Find what package {config} belongs to
```sh
yum provides /path/to/config
```
List repositories
```sh
yum repolist
yum repolist all # enabled and disabled repos
```
Interactive shell
```sh
yum shell
```
Clear cache
```sh
yum clean all
```
View command history
```sh
yum history
```
