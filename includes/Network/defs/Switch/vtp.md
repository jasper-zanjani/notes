**VTP** is a Cisco protocol that facilitates VLAN creation and management across many switches using interswitch links called **trunks**.

There are three VTP **Operating Modes**:

- **Server** (default) permits you to create and modify VLANs on the local device.
- **Transparent** disables VTP.
- **Client** allows switches to inherit the VLAN information from a server. You **cannot** create VLANs locally on a VTP Client device.

!!! cisco "Display VTP mode"

    ```
    SW1#show vtp status
    ```

