#### ansible
:   
    Used to run **ad-hoc commands** from the command-line.

    Display all available hosts
    ```sh
    ansible localhost --list-hosts
    ```

    Specify a module in an ad-hoc.

    ```sh
    ansible all -m shell -a env
    ansible all -a env # (1)
    ```

    1. The **command** module is default and does not have to be made explicit
