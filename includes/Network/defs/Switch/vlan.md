A **VLAN** is a broadcast domain created on a switch that corresponds to a TCP/IP subnet

All non-trunk ports on a Cisco switch are assigned to VLAN 1 by default.
And in order to be part of a VLAN, an interface must be set to **access mode**.

The **Native VLAN** or VLAN 1 is intended to ensure that management traffic (i.e. CDP) can still flow between devices even if a link loses its status as a trunk.
It is considered best practice to tag the Native VLAN or use an unused VLAN for this purpose, for security.

!!! cisco "Display VLAN assignments"

    ```
    SW1#show vlan brief
    ```

