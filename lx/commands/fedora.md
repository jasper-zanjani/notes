# Fedora
Repos added
- RPM Fusion
  - `https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-31.noarch.rpm`
  - `https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-free-release-31.noarch.rpm`

Packages added:
- `snap`
- `breeze-cursor-theme`
- `f30-backgrounds-gnome` .. `f20-backgrounds-gnome`

Keyboard shortcuts:
- M+Enter: `terminal-gnome`
- M+F1, F2... workspaces

Icons: `Qogir`

### `dnf`
View all `dnf` commands
```sh
dnf history
```
View all packages installed by user
```sh
dnf history userinstalled
```

### `rpm`

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-e`    | `--erase`               | remove specified package, including config files
`-i`    | `--install`             | install specified package
`-q`    | `--query`               | query for specified package
`-U`    | `--upgrade`             | upgrade specified package

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-a`       |                         | list all installed packages
`-c`       |                         | list configs installed with specified package
`-d`       |                         | list documentation files installed with specified package
`-i`       |                         | display information about specified package
`-K`       |                         | Verify integrity of specified package
`-l`       |                         | List all files installed with specified package
`-provides`|                         | List which capabilities the specified package provides
`-R`       |                         | list which capabilities the specified package requires
`-s`       |                         | display state of each file that was installed by specified package (normal, not installed, or replaced)

Query repos for information on {package}
```sh
rpm -qi package
rpm --query --info package
```
Upgrade or install {package}, with progress bars
```sh
rpm -Uvh package
rpm --upgrade --verbose --hash package
```
Display version of Fedora
```sh
rpm -E %fedora
```

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
