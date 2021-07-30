CDP allows Cisco devices to communicate about each other to directly connected neighbors.
VoIP in particular is reliant on CDP, however CDP messages cannot be passed from router to router through a switch.

It is also considered a security issue, since it is enabled by default on Cisco routers and switches on all interfaces and devices may share information with an unauthorized neighbor.

!!! cisco "Disable CDP on a device"

    ```
    Switch(config)#no cdp run
    ```

!!! cisco "Enable CDP on an individual interface"

    ``` hl_lines="3"
    Switch(config)#cdp run
    Switch(config)#interface gi1/0
    Switch(config-if)#cdp enable
    ```

LLDP is an open standard similar to CDP, but it is not enabled by default

!!! cisco "Enable LLDP"

    ``` hl_lines="1 3 4"
    Switch(config)#lldp run
    Switch(config)#interface gi1/0
    Switch(config-if)#lldp transmit
    Switch(config-if)#lldp receive
    ```