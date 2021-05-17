#### ansible

**ansible** is used to run **ad-hoc commands** from the command-line.

Display all available hosts

=== "localhost"

    ```sh
    ansible localhost --list-hosts
    ```

=== "all"

    ```sh
    ansible all --list-hosts
    ```

Specify a module in an ad-hoc.
The **command** module is default and does not have to be made explicit


=== "Shell"

    ```sh
    ansible all -m shell -a env
    ```

=== "Command"

    ```sh
    ansible all -a env
    ```
