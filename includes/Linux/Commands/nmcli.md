#### nmcli
:   
    Control NetworkManager and report network status

    Display devices and statuses
    ```
    nmcli device status
    ```

    Display information on interfaces as well as status
    Including other network connections not managed by network manager ("unmanaged") or not connected ("unavailable") 
    ```
    nmcli dev status
    ```

    Display what connections are enabled 
    ```
    nmcli general status
    ```

    Display UUIDs associated with network connections 
    ```
    nmcli connection show --active
    ```

    Display much more information on network devices
    ```
    nmcli device show
    ```

    Configure settings for network interface {ens01} via interactive shell
    ```sh
    nmcli connection edit ens01
    ```

    List all connections NetworkManager has
    ```sh
    nmcli connection show
    ```

    Show settings for network interface {ens01}
    ```sh
    nmcli device show ens01
    ```

    Show status for all devices
    ```sh
    nmcli device status
    ```

    Display currently configured hostname
    ```sh
    nmcli general hostname
    ```

    Set hostname to {hostname}
    ```sh
    nmcli general hostname hostname
    ```

    Show overall status of NetworkManager
    ```sh
    nmcli general status
    ```

    ```sh title="Migrate a connection profile"
    nmcli connection migrate eth0
    ```