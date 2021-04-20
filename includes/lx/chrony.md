**chrony**{: #chrony }
:   Synchronize system time using NTP (cf. [`timedatectl`][timedatectl]

    Stop the `systemd-timesyncd` service
    ```sh
    sudo systemctl stop systemd-timesyncd.service
    ```
    Install `chrony` if it is not already present and enable and start the service
    ```sh
    sudo systemctl enable chronyd && sudo systemctl start chronyd
    ```