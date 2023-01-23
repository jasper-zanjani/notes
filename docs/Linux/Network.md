--8<-- "includes/Network/abbrs.md"

# Networking

The Linux kernel supports several **packet-filtering**{: #packet-filtering } mechanisms.

- [**Netfilter**](#netfilter) using the venerable [iptables](#iptables) utility
- **nftables** subsystem, introduced with kernel 3.13 (2014), had been commonly assumed to eventually take the place of iptables. Firewall rules are implemented in an in-kernel VM.
- **bpfilter** 

Netfilter is a software firewall and packet filtering framework introduced with Linux 2.4.0 (2001) and controlled by the [iptables](#iptables) command.

Netfilter rules are stored in **tables** and in **chains**, and tables are associated with various chains.

By convention, table names are specified in lowercase and chain names in uppercase.
Every packet starts at the top of a chain and is matched rule by rule.
When a match is found the specified action, called the **target**, is triggered: i.e. "DROP" or "ACCEPT".

| Tables | INPUT     | OUTPUT    | FORWARD   | PREROUTING | POSTROUTING |
| ------ | --------- | --------- | --------- | ---------- | ----------- |
| filter | ✔&#xfe0f; | ✔&#xfe0f; | ✔&#xfe0f; |            |
| nat    |           | ✔&#xfe0f; |           | ✔&#xfe0f;  | ✔&#xfe0f;   |
| mangle | ✔&#xfe0f; | ✔&#xfe0f; | ✔&#xfe0f; | ✔&#xfe0f;  | ✔&#xfe0f;   |
| raw    |           | ✔&#xfe0f; |           | ✔&#xfe0f;  |

There are five builtin netfilter **chains**, though user-defined chains are also possible:

- **INPUT** used for filtering incoming packets where the host itself is the destination packet.
- **OUTPUT** for outgoing packets, where the host is the source of the packet.
- **FORWARD** for filtering routed packets, where the host is router.
- **PREROUTING** used for DNAT or port forwarding
- **POSTROUTING** used for SNAT

Netfilter **tables**:

- **filter** default
- **nat** for SNAT and DNAT
- **mangle** for packet alteration
- **raw** used only to mark packets that should not be handled by the connection tracking system using the NOTRACK target

## NetworkManager

[**NetworkManager**](https://networkmanager.dev/) provides a high-level interface for the configuration of network interfaces.
It was developed by Red Hat and [released](https://en.wikipedia.org/wiki/NetworkManager) in late 2004.

The config file format native to NetworkManager is the ini-format [**keyfile**](https://networkmanager.dev/docs/api/latest/nm-settings-keyfile.html){: #keyfile } stored in **/etc/NetworkManager/system-connections**.
These files define network interfaces, or **connection profiles** in NetworkManager's terminology.

--8<--

includes/Linux/Commands/nmcli.md

includes/Linux/Commands/nmtui.md

--8<--

## Netplan

**netplan** is a [utility for network configuration](https://netplan.io/) using YAML files that is the default network management tool used by recent versions of Ubuntu (since Ubuntu 17.10).
**Netplan** is used as the default network management tool (previously ifconfig and its config at **/etc/network/interfaces** was used).

Netplan supports two **renderers** or backends: **NetworkManager** and **networkd**.

Netplan configs are YAML format and placed in **/etc/netplan**.
Ubuntu installations usually come with a single config in this location named **01-network-manage-all-yaml**, but many configs can be created in subdirectories.
These are processed in **lexicographical order** regardless of subdirectory (unless there are multiple files with the same name).
If a boolean or scalar parameter is defined in more than one config, the last value is assumed. Values that are sequences are concatenated.

```yaml title="Default config"
# Let NetworkManager manage all devices on this system
network:
    version: 2
    renderer: NetworkManager # (1)
```

1. This may require the **python3-networkmanager** package to be installed first.

```yaml title="Static IP configuration"
--8<-- "includes/Linux/Tasks/netplan-static.yaml"
```

--8<-- "includes/Linux/Commands/netplan.md"

## Tasks

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

#### Downloading files
:   
    [**Wget**](#wget) defaults to file operations in a way that is more natural for downloading.

    ```sh
    wget $url
    ```

    [**Curl**](#curl) depends on piping and defaults to STDOUT in a manner similar to **cat**.
    
    ```sh
    curl -O $url 
    ```

#### Wireguard tunnel
:   
    === ":material-redhat: Red Hat"

        ```sh
        dnf install wireguard-tools
        ```

    === ":material-ubuntu: Ubuntu"

        ```sh
        apt install wireguard
        ```

    Successful installation can be confirmed by running the following, which should produce no output (and no error) on success.
    ```sh
    sudo modprobe wireguard
    ```

    The first step in [creating a Wireguard tunnel](https://www.youtube.com/watch?v=88GyLoZbDNw) is to create a private key on each endpoint of the tunnel.
    The **genkey** subcommand creates a 44-character base64 encoded key ending in `=` which can be redirected to a file.
    If the file will be world-readable, the utility will ask you to change the umask.
    ```sh
    wg genkey # ▓▓░░░▓░▒▓▒▓▒░▓░▒░▓░▒▒░▓░▓░▒░▒▓▒▒▒░░▒▒░░░▒▒▓▓=
    ```

    The public key can be generated by piping the private key from STDIN or from the file.
    ```sh
    wg pubkey private > public
    wg genkey | tee private | wg pubkey > public
    ```

    Then a Wireguard interface is created, typically named **wg0**, using network management utilities.
    ```sh
    ip link add wg0 type wireguard
    ```

    An IP address is assigned to that interface, to be used within the tunnel:
    ```sh
    ip addr add 10.0.0.1/24 dev wg0
    ```

    Now the private key is associated with the interface:
    ```sh
    wg set wg0 private-key ~/.config/wireguard/private
    ```

    Finally, the interface is brought up:
    ```sh
    ip link set wg0 up
    ```

    The public key of the peer is now associated with the Wireguard interface and the public IP and port of the other endpoint are specified.
    ```sh
    wg set wg0 peer $PUBKEY allowed-ips 10.0.0.2/32 endpoint $IP
    ```

    The tunnel is dismantled by removing the interface.
    ```sh
    ip link delete wg0
    ```

    Alternatively, many of these steps can be consolidated into creating a config for the Wireguard interface at **/etc/wireguard/wg0.conf** with the following contents:
    ```ini
    [Interface]
        PrivateKey = ▓▓░░░▓░▒▓▒▓▒░▓░▒░▓░▒▒░▓░▓░▒░▒▓▒▒▒░░▒▒░░░▒▒▓▓=
        Address = 10.0.0.1/24
        PostUp = iptables -A FORWARD -i wg0 -j ACCEPT; iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
        PostDown = iptables -D FORWARD -i wg0 -j ACCEPT; iptables -t nat -D POSTROUTING -o eth0 -j MASQUERADE
        ListenPort = 51820

    [Peer]
        PublicKey = ▓▒▓▒▓▓░▓▒▒░░▒▒▒▓▒░▒▓▒░▒▒▓▒░▒░░░░▒░▒▒▒░░▒▒▓░▒=
        AllowedIps = 10.0.0.2/32
        Endpoint = 123.45.67.89:51820
    ```

    Then to bring it up quickly:
    ```sh
    wg-quick up wg0
    ```

    The same utility can be used to teardown the tunnel
    ```sh
    wg-quick down wg0
    ```

#### Static IP
:   
    Static IP configuration varies by the network management toolset and backend presenton a system. 
    Ubuntu systems use [**Netplan**](#netplan) whereas other distributions most commonly use [**Network Manager**](#networkmanager).

    
    === "Netplan"

        ```yaml
        --8<-- "includes/Linux/Tasks/netplan-static.yaml"
        ```
    
    === "Network Manager"

        ```ini
        --8<-- "includes/Linux/Tasks/networkmanager-static.ini"
        ```


    Setting a static IP address on Red Hat distributions could involve multiple methods:

    - [nmcli commands](https://linuxhint.com/configure-static-ip-address-fedora/)
    - [NetworkManager keyfiles](Network/#networkmanager)
    - [ifcfg files](Network/#ifcfg-files) (prior to distributions downstream to Fedora 36)



## Commands

--8<--
includes/Linux/Commands/curl.md

includes/Linux/Commands/firewall-cmd.md

includes/Linux/Commands/ip.md

includes/Linux/Commands/iptables.md

includes/Linux/Commands/netcat.md



includes/Linux/Commands/nft.md

includes/Linux/Commands/nmap.md

includes/Linux/Commands/tcpdump.md

includes/Linux/Commands/ufw.md

includes/Linux/Commands/wg.md

includes/Linux/Commands/wget.md
--8<--


## Glossary

#### eBPF
:   
    eBPF is an extended version of the Berkeley Packet Filter (BPF). 
    It is a sandboxed environment that allows code to be inserted into the running kernel. 
    Kernel functionality must normally be extended by building an entirely new kernel with custom modules or upstream patching of the Linux kernel.

    eBPF's architecture includes a JIT compiler that compiles the program's generic bytecode, which means eBPF programs run as efficiently as natively compiled kernel code.

    eBPF programs can be bound to kernel events, such as receipt of a packet from the NIC.

    **bpftool** is a core eBPF CLI tool.

    ```sh
    bpftool prog     # Display running eBPF programs
    bpftool map show # Display maps
    ```


#### ifcfg
:   
    Historically, [**ifcfg** (interface configuration) files](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/networking_guide/sec-configuring_ip_networking_with_ifcg_files) were ini-format files found in **/etc/sysconfig/network-scripts/** in Red Hat distributions.
    They were used to control network interfaces on the legacy "network" service, now part of the network-scripts package, which included the [sysconfig.txt](https://github.com/fedora-sysv/initscripts/blob/master/doc/sysconfig.txt#L416) file which documents the ifcfg file format.

    After the introduction of [NetworkManager](#networkmanager), this format survived and was [expanded](https://networkmanager.dev/docs/api/latest/nm-settings-ifcfg-rh.html) with new 
    directives specific to NetworkManager.
    
    By convention, the string value of the DEVICE directive was the suffix of the filename itself.
    ```ini title="ifcfg-eth0"
    DEVICE=eth0
    BOOTPROTO=dhcp
    ONBOOT=yes
    TYPE=Ethernet
    ```

    The nmcli utility exposes a command that can change the configuration backend from ifcfg to a NetworkManager [**keyfile**](#keyfile).
    ```sh title="Migrate a connection profile"
    nmcli connection migrate eth0
    ```

    Ifcfg file support was finally removed in [RHEL 9](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/9/html-single/9.0_release_notes/index#overview-major-changes) and [Fedora 36](https://fedoraproject.org/wiki/Changes/NoIfcfgFiles).
    If no ifcfg files are present, the configuration backend that supports them can be removed.
    ```sh
    dnf remove NetworkManager-initscripts-ifcfg-rh
    ```




#### Netfilter
:   
    Netfilter is a software firewall and packet filtering framework introduced with Linux 2.4.0 (2001) and controlled by the [iptables](#iptables) command.
