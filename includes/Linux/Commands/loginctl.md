#### loginctl
:   
    Enable user **lingering**, which allows users that are not logged in to run long-running services.
    ```sh
    loginctl enable-linger
    loginctl show-user | grep Linger - # Confirm
    ```