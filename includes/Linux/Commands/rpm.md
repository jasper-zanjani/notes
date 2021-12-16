#### rpm
:   
    Query repos for information on a package
    ```sh
    rpm -qi $PACKAGE # --query --info
    ```

    Upgrade or install a package, with progress bars
    ```sh
    rpm -Uvh $PACKAGE # --upgrade --verbose --hash
    ```

    Display version of Fedora
    ```sh
    rpm -E %fedora
    ```
