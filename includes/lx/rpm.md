[rpm -&#97;]:                   #rpm                           'In query mode, display a list of all packages installed on the system&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 55'
[rpm -&#99;]:                   #rpm                           'List only configuration files installed with specified package&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#100;]:                  #rpm                           'List only documentation files installed with specified package&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#101;]:                  #rpm                           'Remove specified package, including config files&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#102;]:                  #rpm                           'In query mode, display the package that contains a particular file&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 55'
[rpm -&#104;]:                  #rpm                           'Prints a string of 50 hash marks during installation as a progress indicator&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 54'
[rpm -&#105;]:                  #rpm                           'Install specified packages&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#73;]:                   #rpm                           'Display information about specified package&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#75;]:                   #rpm                           'Verify integrity of specified package'
[rpm -&#108;]:                  #rpm                           'List all files installed with specified package&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#112;]:                  #rpm                           'Query a package file (most useful with `-i`)&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.'
[rpm -&#113;]:                  #rpm                           'Query for specified package'
[rpm -&#82;]:                   #rpm                           'List packages on which this package depends&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 56'
[rpm -&#115;]:                  #rpm                           'Display the state of each file that was installed by the specified package (`normal`, `not installed`, or `replaced`)'
[rpm -&#85;]:                   #rpm                           'Upgrade specified package'
[rpm -&#86;]:                   #rpm                           'Compare files from installed packages against their expected configuration from the RPM database.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 58'
[rpm -&#118;]:                  #rpm                           'Verbose output&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 54'
[rpm --force]:                  #rpm                           'Allows the replacement of existing packages and of files from previously installed packages; for upgrades, it allows the replacement of a newer package with an older one.&#10;Equivalent to using all of the following options:&#10;  `--replacepkgs`&#10;  `--replacefiles`&#10;  `--oldpackage`&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 54'
[rpm --nodeps]:                 #rpm                           'Allows you to install a package without checking for dependencies.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 54'
[rpm --nofiles]:                #rpm                           'In verify mode, ignore missing files&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 58'
[rpm --nomd5]:                  #rpm                           'In verify mode, ignore MD5 checksum errors&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 58'
[rpm --nopgp]:                  #rpm                           'In verify mode, ignore PGP checking errors&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 58'
[rpm --provides]:               #rpm                           'List which capabilities the specified package provides'
[rpm --test]:                   #rpm                           'Runs through all the motions except for actually writing files; useful to verify that a package will install correctly prior to making the attempt&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 54'

<code>&nbsp;</code>  [`a`][rpm -&#97;] <code>&nbsp;</code> [`c`][rpm -&#99;] [`d`][rpm -&#100;] [`e`][rpm -&#101;] [`f`][rpm -&#102;] <code>&nbsp;</code> [`h`][rpm -&#104;] [`i`][rpm -&#105;] <code>&nbsp;</code> <code>&nbsp;</code> [`l`][rpm -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`p`][rpm -&#112;] [`q`][rpm -&#113;] <code>&nbsp;</code> [`s`][rpm -&#115;] <code>&nbsp;</code> <code>&nbsp;</code> [`v`][rpm -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`I`][rpm -&#73;] <code>&nbsp;</code> [`K`][rpm -&#75;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`R`][rpm -&#82;] <code>&nbsp;</code> <code>&nbsp;</code> [`U`][rpm -&#85;] [`V`][rpm -&#86;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <br>[`force`][rpm --force] [`nodeps`][rpm --nodeps] [`nofiles`][rpm --nofiles] [`nomd5`][rpm --nomd5] [`nopgp`][rpm --nopgp] [`provides`][rpm --provides] [`test`][rpm --test] 


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