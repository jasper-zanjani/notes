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
### `dnf`
View all `dnf` commands
```sh
dnf history
```
View all packages installed by user
```sh
dnf history userinstalled
```
Display information about a **package group** [^][https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/]
```sh
dnf groupinfo virtualization
```
Install a package group [^][https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/]
```sh
dnf install @virtualization
```
Install a package group, including optional packages [^][https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/]
```sh
dnf group install --with-optional virtualization
```
### `gem`
Install a Ruby `$PACKAGE`
```sh
gem install $PACKAGE
```
Display currently installed Ruby packages
```sh
gem list
```
Remove `$PACKAGE`
```sh
gem uninstall package
```
Update `$PACKAGE`
```sh
gem update package
```
### `make`
A common formula when installing software from source is the following sequence of commands [^](https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install "thoughtbot.com: \"The magic behind configure, make, make install\"")
```sh
./configure
make
make install
```
Given there are 3 example files (main.cpp, message.cpp, and message.h) in a directory, it produces an executable file named `a.out`
```sh
g++ main.cpp message.cpp
```
But for large projects, with potentially thousands of files, this is impractical

#### makefiles
Makefiles are sensitive to whitespace, so indentation is significant. The format follows the pattern:
```makefile
{target}: {dependencies}
  {action}
```
where `{target}` is the filename produced by the operation `{action}`, each of which are shell commands.

For any changes in `main.o` and `message.o`, they will be recompiled into `output`, which is the executable. `g++ -c` will compile the code into an object file but not into a binary, creating `main.o`.
```makefile
output: main.o message.o
  g++ main.o message.o -o output

message.o: message.cpp message.h
  g++ -c message.cpp
  
main.o: main.cpp
  g++ -c main.cpp

clean:
  rm *.o output
```
  - 

Execute the operations specified in the makefile (if executed a second time without any changes, it will produce a notification that there have been no changes):
```sh
make
```
Execute the `clean` section, removing files
```sh
make clean
```

Targets
- `tinyconfig` smallest possible kernel configuration
- `allnoconfig` answer no to every question when creating a config file

#### configure script
Responsible for preparing the software build, ensuring dependencies are available, such as a C compiler for C programs. `make` is invoked after the `configure` script has done its job. The __configure__ script converts a __Makefile.in__ template into a __Makefile__. They are not built by hand but packaged by yet another program in the __autotools__ suite, such as __autoconf__, __automake__, and others.

A configure.ac file written in **m4sh** (a combination of m4 macros and shell script) is prepared. The first m4 macro called i __AC_INIT__, which initializes autoconf:
```m4
AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
```
The __AM_INIT_AUTOMAKE__ macro is also called because we're using __automake__:
```m4
AM_INIT_AUTOMAKE
```
#### Other examples
Recompile [mail.md#sendmail]
```sh
make -C/etc/mail
```
### `pacman`
Option  | POSIX option            | Effect
:---    | :---                    | :---
`Q`     | `--query`               | list all installed packages
`-R`    |                         | remove {pkg}, but leave dependencies
`-Qe`   |                         | list programs explicitly installed by user or program command
`-Qeq`  |                         | list only program names explicitly installed
`-Qm`   |                         | list programs only installed from AUR
`-Qn`   |                         | list programs only installed from main repositories
`-Qdt`  |                         | list dependencies no longer needed (orphans)
`-Ql`   | `--query` `--list`      | list all files owned by a package
`-S`    | `--sync`                | install {pkg}
`-Sy`   |                         | synchronize package database 
`-Su`   |                         | update programs 
`-Syu`  |                         | sync package database (`Sy`) and upgrade all programs (`u`) (equivalent to `apt-get update && apt-get upgrade`)
`-Syy`  |                         | force double-check of repositories
`-Syyuw` |                        | downloads programs but doesn't install them, for the option of manual installation
`-Rs`   |                         | remove {pkg} as well as its dependencies
`-Rns`  |                         | remove {pkg}, dependencies, as well as config files 
List installed packages
```sh
pacman -Q
pacman --query
```
List all orphaned dependencies (no longer needed)
```sh
pacman -Qdt
pacman --query --deps --unrequired
```
List only explicitly installed packages and versions
```sh
pacman -Qe
pacman --query --explicit
```
List explicitly installed packages, limiting output to program names
```sh
pacman -Qeq
pacman --query --explicit --quiet
```
List all packages installed from the AUR
```sh
pacman -Qm
pacman --query --foreign
```
List all packages installed from main repos
```sh
pacman -Qn
pacman --query --native
```
Find which package owns {file}
```sh
pacman -Qo file
pacman --query --owns file
```
List all install packages, filtering output to packages that are out-of-date on the local system
```sh
pacman -Qu
pacman --query --upgrades
```
Remove {package}
```sh
pacman -R package
pacman --remove package
```
Remove {package}, dependencies, and config files
```sh
pacman -Rns package
pacman --remove --recursive --nosave
```
Remove {package} as well as its dependencies
```sh
pacman -Rs
pacman --remove --recursive
```
Install {pkg} from the AUR
```sh
pacman -S package
pacman --sync package
```
Remove all packages from the cache as well as unused sync databases
```sh
pacman -Scc
pacman --sync --clean --clean
```
Display information about {package}
```sh
pacman -Si package
pacman --sync --info package
```
Search for {pkg} in AUR repos
```sh
pacman -Ss package
pacman --sync --search package
```
Search for packages matching {searchexpression}
```sh
pacman -Ss pattern
pacman --sync --search pattern
```
Update package database
```sh
pacman -Sy
pacman --sync --refresh
```
Update all packages from AUR and official repos
```sh
pacman -Syu
pacman --sync --refresh --sysupgrade
```
Force refresh of all package databases, even if they appear to be up-to-date
```sh
pacman -Syy
pacman --sync --refresh --refresh
```
Download program updates but don't install them
```sh
pacman -Syyuw
pacman --sync --refresh --refresh --sysupgrade --downloadonly
```
Get number of total installed packages
```sh
pacman -Q | wc -l
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
`-I`       |                         | display information about specified package
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
### `snap`
Disable snap `$PACKAGE
```sh
snap disable $PACKAGE
```
Enable disabled snap `$PACKAGE`
```sh
snap enable $PACKAGE
```
Display information about `$PACKAGE`
```sh
snap info --verbose $PACKAGE
```
Install snap `$PACKAGE`
```sh
snap install $PACKAGE
```
Display logs of snap `$PACKAGE`
```sh
snap logs $PACKAGE
```
Check for snap updates
```sh
snap refresh
```
Uninstall snap `$PACKAGE`
```sh
snap remove $PACKAGE
```
### `yay`
Display all AUR packages that need to be updated (deprecated)
```sh
yay -Pu
yay --show --upgrades package
```
List all install packages, filtering output to packages that are out-of-date on the local system
```sh
yay -Qu
yay --query --upgrades
```
Install {pkg} from the AUR
```sh
yay -S package
yay --sync package
```
Display information about {package}
```sh
yay -Si package
yay --sync --info package
```
Search for {pkg} in AUR repos
```sh
yay -Ss package
yay --sync --search package
```
Update all packages from AUR and official repos
```sh
yay -Syu
yay --sync --refresh --sysupgrade
```
Remove unwanted dependencies of now-removed installations of AUR repos
```sh
yay -Yc
yay --yay --clean
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
## 
[https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/]: https://docs.fedoraproject.org/en-US/quick-docs/getting-started-with-virtualization/ "Fedora Docs: \"Getting started with virtualization\""