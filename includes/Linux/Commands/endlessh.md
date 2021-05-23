#### endlessh

Log verbosity can be configured from the command-line or the config

=== "Silent"

    ```sh
    endlessh
    ```

    /etc/endlessh/config
    ```
    LogLevel 0
    ```


=== "Normal"

    ```sh
    endlessh -v
    ```

    /etc/endlessh/config
    ```
    LogLevel 1
    ```


=== "Debug"

    ```sh
    endlessh -vv
    ```
    
    /etc/endlessh/config
    ```
    LogLevel 2
    ```
