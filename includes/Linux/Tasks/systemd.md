### SystemD Tasks

#### Persistent logging
:   
    Set persistent loggin
    ```ini title="/etc/systemd/journald.conf"
    [Journal]
    Storage=persistent
    ```

    Save logs to disk
    ```sh
    journalctl --flush
    ```

#### Container service
:   
    ```sh title="Create service file from container"
    mkdir -p ~/.config/systemd/user
    cd ~/.config/systemd/user
    podman generate systemd --name --files --new $CONTAINER
    ```

    Allow user services to remain running even if user is not logged on
    ```sh
    loginctl enable-linger $(whoami)
    ```

    Enable and start user service
    ```sh
    systemctl enable container-$CONTAINER.service --now --user
    ```