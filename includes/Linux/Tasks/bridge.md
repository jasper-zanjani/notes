#### Bridge
:   
    A bridge is used to unite two or more network segments, typically used to establish communication channels between VMs, containers, and the host.

    ```sh
    ip link add virbr0 type bridge # (1)
    ip link set virbr0 up
    ```

    1. The link can be deleted thus:
    ```sh
    ip link delete virbr0
    ```

    Adding an interface to the bridge is done by setting its master.
    ```sh
    ip link set enp2s0f0 master virbr0 # (1)
    ```

    1. This can be undone as follows:
    ```sh
    ip link set enp2s0f0 nomaster
    ```

    The iproute2 **bridge** utility can be used to verify the command has taken effect:
    ```sh
    bridge link
    ```

    This may interrupt network connectivity.
    In this case, the IP address must be removed from the linked interface and assigned to the bridge
    ```sh
    ip address delete 192.168.1.3 dev enp2s0f0
    ip address add 192.168.1.3 dev virbr0
    ```

    The default route in the routing table must also be amended.
    ```sh
    ip route delete default
    ip route add default via 192.168.1.1
    ```

