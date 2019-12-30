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