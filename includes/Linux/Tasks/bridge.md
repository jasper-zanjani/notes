#### Bridge
:   
    A bridge is used to unite two or more network segments, typically used to establish communication channels between VMs, containers, and the host.

    Unlike the virtual bridge that Windows uses for WSL2 distributions, the bridge in Linux is strictly L2.
    That is, VMs connecting to the bridge are assigned IPs by the same DHCP server (i.e. the router) in the same subnet as that of the physical hosts.
    In Windows, the virtual bridge assigns an internal IP in a private range (usually 172.16.0.0/12), and connectivity to the host or the Internet has to be accomplished via NAT.

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
    Note this is not the IP address of the interface but rather that of the **gateway**.
    Also note that this gateway must already have its own network segment defined.
    That is, in order for a default route to be defined at least one static route must also be defined, which is the gateway's own local subnet.
    ```sh
    ip route delete default
    ip route add default via 192.168.1.1
    ```

