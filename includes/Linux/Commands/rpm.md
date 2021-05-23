#### rpm

Query repos for information on a package

=== ":material-bash:"

    ```sh
    rpm -qi package
    ```

=== "POSIX"

    ```sh
    rpm --query --info package
    ```

Upgrade or install a package, with progress bars

=== ":material-bash:"

    ```sh
    rpm -Uvh package
    ```

=== "POSIX"

    ```sh
    rpm --upgrade --verbose --hash package
    ```

Display version of Fedora

```sh
rpm -E %fedora
```
