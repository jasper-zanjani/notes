#### pacman
:   
    ```sh
    pacman -Q # --query
    ```

    Display all orphaned dependencies (no longer needed)
    ```sh
    pacman -Qdt # --query --deps --unrequired
    ```

    Display only explicitly installed packages and versions
    ```sh
    pacman -Qe # --query --explicit
    ```

    Display explicitly installed packages, limiting output to program names
    ```sh
    pacman -Qeq # pacman --query --explicit --quiet
    ```

    Display all packages installed from the AUR
    ```sh
    pacman -Qm # --query --foreign
    ```

    Display all packages installed from main repos
    ```sh
    pacman -Qn # --query --native
    ```

    Find which package owns {file}
    ```sh
    pacman -Qo file # --query --owns
    ```

    List all install packages, filtering output to packages that are out-of-date on the local system
    ```sh
    pacman -Qu # --query --upgrades
    ```

    Remove `$PACKAGE`
    ```sh
    pacman -R $PACKAGE # --remove package
    ```

    Remove `$PACKAGE`, dependencies, and config files
    ```sh
    pacman -Rns $PACKAGE # --remove --recursive --nosave
    ```

    Remove `$PACKAGE` as well as its dependencies
    ```sh
    pacman -Rs # --remove --recursive
    ```

    Install `$PACKAGE` from the AUR
    ```sh
    pacman -S $PACKAGE # --sync
    ```

    Remove all packages from the cache as well as unused sync databases
    ```sh
    pacman -Scc # --sync --clean --clean
    ```

    Display information about {package}
    ```sh
    pacman -Si $PACKAGE # --sync --info package
    ```

    Search for `$PACKAGE` in AUR repos
    ```sh
    pacman -Ss $PACKAGE # --sync --search package
    ```

    Search for packages matching `$PATTERN`
    ```sh
    pacman -Ss $PATTERN # --sync --search pattern
    ```

    Update package database
    ```sh
    pacman -Sy #  --sync --refresh
    ```

    Update all packages from AUR and official repos
    ```sh
    pacman -Syu # --sync --refresh --sysupgrade
    ```

    Force refresh of all package databases, even if they appear to be up-to-date
    ```sh
    pacman -Syy # --sync --refresh --refresh
    ```

    Download program updates but don't install them
    ```sh
    pacman -Syyuw # --sync --refresh --refresh --sysupgrade --downloadonly
    ```

    Get number of total installed packages
    ```sh
    pacman -Q | wc -l
    ```