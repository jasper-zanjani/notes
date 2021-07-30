!!! cisco "Basic administration"

    Change hostname
    ```
    Switch(config)#hostname SW2
    ```

    Set banner message
    ```
    Switch(config)#banner motd #Hello, world!#
    ```

    Restart
    ```
    Switch#reload
    ```
    
    Display configuration

    === "Current"
        ```
        Switch#show running-config
        ```
    === "Saved"
        ```
        Switch#show startup-config
        ```

    Display contents of NVRAM
    ```
    Switch>show flash:
    ```