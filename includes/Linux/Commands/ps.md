#### ps
:   
    Display processes in a tree-like display illustrating parent-child relationships
    ```sh
    ps -f # --forest
    ```

    Show system processes

    === "BSD syntax"

        ```sh
        ps ax
        ```

    === "POSIX syntax"

        ```sh
        ps -ef
        ```

    Display full listing of processes
    ```sh
    ps u # -f
    ```

    Display user processes
    ```sh
    ps xG # -a
    ```

    Display SELinux contexts for processes
    ```sh
    ps auxZ
    ```

    Display kernel threads
    ```sh
    ps -ef
    ```