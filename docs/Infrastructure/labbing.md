# Labbing

#### Hyper-V

A [NAT network](https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/user-guide/setup-nat-network) can be configured in Hyper-V for use with VMs.


!!! info "NAT network limit"

    There is only a single NAT network allowed per host.

A new internal virtual switch is created, with a gateway explicitly configured.

``` powershell
New-VMSwitch -Name Ansible -Type Internal
New-NetIPAddress -IPAddress 192.168.2.1 -PrefixLength 24 -InterfaceIndex 14 # (1)
New-NetNat -Name Ansible -InternalIPInterfaceAddressPrefix 192.168.2.0/24
```

1. Only a single NetIPAddress can be assigned to the interface

WinNAT does not allocate IP addresses to endpoints, so IP addresses must be statically configured within each individual guest.

```sh
ip address add 192.168.2.100 dev eth0
ip route add 192.168.2.0/24 dev eth0
ip route add default via 192.168.2.1 dev eth0
```

WinNAT also does not provide DNS services, so the host's DNS will have to be inspected and used.

??? warn "WiFi complications"

    Documentation for [VirtualBox](https://docs.oracle.com/en/virtualization/virtualbox/6.0/user/network_bridged.html) states that WLAN adapters do not support **promiscuous mode** and therefore the **Bridge** networking option operates differently when using the computer's WiFi adapter. This potentially may be the cause of odd behavior when using External networking in Hyper-V...

Static IP configuration varies by the network management toolset and backend presenton a system. 
Ubuntu systems use [**Netplan**](../../Linux/Network#netplan) whereas other distributions most commonly use [**Network Manager**](../../Linux/Network#networkmanager).

=== "Netplan"

    ```yaml
    --8<-- "includes/Linux/Tasks/netplan-static.yaml"
    ```

=== "Network Manager"

    ```ini
    --8<-- "includes/Linux/Tasks/networkmanager-static.ini"
    ```

WSLv2 distros will [not be able to access](https://github.com/microsoft/WSL/issues/4288) Hyper-V guests unless forwarding is enabled on both IP interfaces for the Hyper-V NAT as well as WSL

``` powershell
Set-NetIpInterface -ifIndex $NAT -Forwarding Enabled
Set-NetIpInterface -ifIndex $WSL -Forwarding Enabled # (1)
```

1. The setting for the WSL interface appears not to be persistent.

!!! info "History"

    Traditionally, network interfaces on Linux were configured in **/etc/network/interfaces**