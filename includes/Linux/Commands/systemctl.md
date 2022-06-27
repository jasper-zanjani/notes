#### systemctl
:   
    ```sh title="Services"
    systemctl list-unit-files --type=service    # Display all services
    systemctl enable --now $SERVICE             # Configure service to start on boot and start it immediately
    systemctl status $SERVICE
    systemctl is-active $SERVICE 
    systemctl disable $SERVICE
    systemctl mask $SERVICE                     # Prevent service from being started inadvertently by another process
    systemctl restart $SERVICE
    ```

    ```sh title="Boot targets"
    systemctl get-default
    systemctl set-default graphical.target
    systemctl isolate emergency.target          # Change target
    systemctl suspend                           # Suspend system
    ```

    **--user** specifies the service manager of the calling user.
    ```sh
    systemctl --user enable --now container-notes.service # (1)
    systemctl --user status container-notes.service
    ```

    1. Here, container-notes.service has been created at **~/.config/systemd/user**