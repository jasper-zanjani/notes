#### ps
:   
    Display processes in a tree-like display illustrating parent-child relationships
    ```sh
    ps -f # --forest
    ```
    Show system processes
    ```sh
    ps ax # -e
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