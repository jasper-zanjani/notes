# CompTIA Linux+
Passing this exam also gives you the LPIC-1 certification

2 exams:
  1. LX0-103 (60 questions)
  2. LX0-104 (60 questions)

New XK0-004 to be released in April 2019, complete refresh that ends the cooperation with LPI.
Additional topics:
  - Security
  - Kernel modules
  - Storage and virtualization
  - Device management at enterprise level
  - Git and automation
  - Networking and firewalls
  - Serverside and command-line
  - Servers
  - Troubleshooting
  - SELinux

Remove:
  - X 11
  - Mail
  - SQL
  - Printing
  - End-user support
  - GNU Privacy Guard

# ITPRO.TV course on CompTIA Linux+

#### Using vi
vi can generally be assumed to exist on almost any Linux system, whereas others like Nano and Emacs are somewhat less widespread.
using `sudo` might bring up the original `vi` vs. `vim`

## Package managers

### Red Hat package managers: rpm and yum

#### rpm
Red Hat systems do their own thing. Other distributions based on Red Hat, like Fedora and CentOS, use Red Hat's package manager. In the days when all software was compiled by the end-user, Red Hat pioneered with the Red Hat Package Manager (RPM).  RPM can refer to the package manager as well as the packages themselves. RPM utility does not resolve dependencies.

RPM filenames have a structure: {name}-{version}-{build number}-{Red Hat version}-{processor architecture}.rpm
  - Some packages have "noarch" for processor architecture, meaning they are processor agnostic

RPM utility can `install` or `update` a package
`rpm -i package`
: install {pkg}

`rpm -U package`
: update {pkg}, this command can also be used to install

`rpm -Uvhi package`
: `vh` gives *visual* indicators of progress, namely progress bars

`rpm -qi package`
: *query* for information about a package

`rpm -e package`
: remove or *erase* a package; won't touch installed dependencies

`rpm --install gpgkeyurl`
: install a GPG key from a package developer

RPM files are CPIO archives, comparable to a ZIP or TAR file. Red Hat provides the application `rpm2cpio` to convert the file into a format which can then be extracted.

`rpm2cpio rpmfile > cpiofile`
: convert {rpmfile} to CPIO format, saving to {cpiofile}

`cpio -i --make-directories < cpiofile`
: extract {cpiofile}, preserving directories

`rpm2cpio rpmfile | cpio -i --make-directories`
: convert {rpmfile} and extract it to the current directory

#### yum
Red Hat systems also have a second package manager called yum (Yellow Dog Update Manager, Yellow Dog was a variation of Red Hat for Power PC systems), which is more commonly used nowadays. It does track dependencies and removes them, if they are no longer used by an installed package. Repo files can be added in `/etc/yum.repos.d/`

`yum list package`
: query for {package} on the repos

`yum info package`
: information on an installed package

`yum install package`
: install a package, including dependencies

`yum update package` | `yum upgrade package`

#### Debian package managers
apt-get can retrieve packages automatically, dpkg cannot

`dpkg -i` | `dpkg --install`

`dpkg -r` | `dpkg --remove`

`dpkg -P` | `dpkg --purge`
: remove package and configs

`dpkg --get-selections`
: list installed packages

`dpkg -I`
: information about installable package

`dpkg -p` | `dpkg --print-avail`
: info about installed packages

## Shared libraries
Shared libraries avoid multiple versions and copies of the same libraries. The admin will have to deal with this when compiling software from source, such that a package manager is not available to automatically resolve dependencies. `ld` is the library daemon that manages shared libraries. Major versions of shared libraries are actually symlinks that point to the current version with the full semver number.

`ldconfig -v`
: see all shared libraries

`ldd program`
: display dependencies of a particular program

## Hardware configuration



## Installing Linux

#### CentOS
CentOS (Community Enterprise Operating System) recompiled, debranded version of RHEL. Many in CentOS community are actually RH employees. CentOS serves as a kind of proving ground for the full enterprise version of Red Hat.  RHEL (Red Hat Enterprise Linux) costs a few hundred dollars a year, including support.

(CentOS Homepage)[https://www.centos.org/] lists recommended requirements for CentOS: 392MB of RAM for command-line only, 512 MB for graphical install.

GNOME desktop environment is the one that you have to be familiar with for the purpose of the exam

Standard system security profile
