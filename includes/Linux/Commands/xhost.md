**xhost**{: #xhost }
:   Enable access control to X server
    ```sh
    xhost -
    ```
    Disable access control to X server, allowing clients from any host to connect (not unsafe if you use a firewall that allows only SSH)
    ```sh
    xhost +
    ```
    Add `$HOST` to list of authorized clients for X server
    ```sh
    xhost +$HOST
    ```
    Remove `$HOST` from list of authorized clients for X server
    ```sh
    xhost -$HOST
    ```
    Add `$USER` to ACL
    ```sh
    xhost si:localuser:$USER
    ```