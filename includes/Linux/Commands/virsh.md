#### virsh
:   
    virsh is the main interface for managing libvirt [**guest domains**](#domain).

    List all active and inactive domains by name:
    ```sh
    virsh list --all
    ```

    Edit XML configuration file for a domain
    ```sh
    virsh edit $DOMAIN
    ```

    **Autostarting domains**
    ```sh
    virsh autostart $DOMAIN
    ```