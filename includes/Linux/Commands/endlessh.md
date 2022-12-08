#### endlessh
:   
    Log verbosity can be configured from the command-line or the config

    === "Silent"

        ```sh
        endlessh
        ```

        ``` title="/etc/endlessh/config"
        LogLevel 0
        ```


    === "Normal"

        ```sh
        endlessh -v
        ```

        ``` title="/etc/endlessh/config"
        LogLevel 1
        ```


    === "Debug"

        ```sh
        endlessh -vv
        ```
                
        ``` title="/etc/endlessh/config"
        LogLevel 2
        ```
