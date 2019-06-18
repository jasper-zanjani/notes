# pacman

Option | Long option | Effect
:---   | :--- | :---
`-Q` : list all installed packages
`-Q \| wc -l` : get number of total installed packages by counting the lines of output of `pacman -Q`
`-Qe` : list programs explicitly installed by user or program command
`-Qeq` : list only program names explicitly installed
`-Qm` : list programs only installed from AUR
`-Qn` : list programs only installed from main repositories
`-Qdt` : dependencies no longer needed (orphans)
`-Ql` | `--query --list` : list all files owned by a package
`-S pkg` : typical syntax to install a package
`-Sy` : synchronize package database (equivalent to `apt-get update`)
`-Su` : update programs (equivalent to `apt-get upgrade`)
`-Syu` : sync package database (`Sy`) and upgrade all programs (`u`) (equivalent to `apt-get update && apt-get upgrade`)
`-Syy` : force double-check of repositories
`-Syyuw` : downloads programs but doesn't install them, for the option of manual installation
`-R pkg` : remove <pkg>, but leaving dependencies
`-Rs pkg` : remove <pkg> as well as its dependencies
`-Rns pkg` : remove <pkg>, dependencies, as well as config files 
