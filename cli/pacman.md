# pacman
package manager for Linux [Luke Smith](https://yt/-dEuXTMzRKs)

`pacman Xx` : commands typically come with uppercase major commands and lowercase subcommands
`pacman -Q` : list all installed packages
`pacman -Q | wc -l` : get number of total installed packages by counting the lines of output of `pacman -Q`
`pacman -Qe` : list programs explicitly installed by user or program command
`pacman -Qeq` : list only program names explicitly installed
`pacman -Qm` : list programs only installed from AUR
`pacman -Qn` : list programs only installed from main repositories
`pacman -Qdt` : dependencies no longer needed (orphans)
`pacman -Ql` `pacman --query --list` : list all files owned by a package
`pacman -S emacs` : typical syntax to install a package
`pacman -Sy` : synchronize package database (equivalent to `apt-get update`)
`pacman -Su` : update programs (equivalent to `apt-get upgrade`)
`pacman -Syu` : sync package database (`Sy`) and upgrade all programs (`u`) (equivalent to `apt-get update && apt-get upgrade`)
`pacman -Syy` : force double-check of repositories
`pacman -Syyuw` : downloads programs but doesn't install them, for the option of manual installation
`pacman -R package` : remove {package}, but leaving dependencies
`pacman -Rs package` : remove a package as well as its dependencies
`pacman -Rns package` : remove a package, dependencies, as well as config files 
