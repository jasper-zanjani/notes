#### at
:   
    Execute a command at a given time.

    Jobs can be created by piping strings or by using the interactive shell.

    ```sh
    at $TIME
    at> echo "Hello, world!" # (1)
    at>^D
    ```

    1. Equivalent to:
    ```sh
    echo "Hello, world!" | at $TIME
    ```

    There is considerable flexibility with regard to format of time specifications.
    ```sh
    at now + 1 min
    ```