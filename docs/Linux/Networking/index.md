--8<-- "includes/Network/abbrs.md"

# Networking

The Linux kernel supports several **packet-filtering**{: #packet-filtering } mechanisms.

- [**Netfilter**](#netfilter) using the venerable [iptables](#iptables) utility
- **nftables** subsystem, introduced with kernel 3.13 (2014), had been commonly assumed to eventually take the place of iptables. Firewall rules are implemented in an in-kernel VM.
- **bpfilter** 


## Glossary

#### ifcfg
:   
    Historically, [**ifcfg** (interface configuration) files](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/networking_guide/sec-configuring_ip_networking_with_ifcg_files) were ini-format files found in **/etc/sysconfig/network-scripts/** in Red Hat distributions.
    They were used to control network interfaces on the legacy "network" service, now part of the network-scripts package, which included the [sysconfig.txt](https://github.com/fedora-sysv/initscripts/blob/master/doc/sysconfig.txt#L416) file which documents the ifcfg file format.

    After the introduction of [NetworkManager](#networkmanager), this format survived and was [expanded](https://networkmanager.dev/docs/api/latest/nm-settings-ifcfg-rh.html) with new 
    directives specific to NetworkManager.
    
    Ifcfg file support was finally removed in [Fedora 36](https://fedoraproject.org/wiki/Changes/NoIfcfgFiles).

    ```ini title="DHCP"
    DEVICE=eth0 ; (1)
    BOOTPROTO=dhcp
    ONBOOT=yes
    TYPE=Ethernet
    ```

    1. By convention, the string value of the DEVICE directive was the suffix of the filename itself.

    The nmcli utility exposes a command that can change the configuration backend used by a connection profile.
    ```sh title="Migrate a connection profile from ifcfg to keyfile"
    nmcli connection migrate eth0
    ```

    If no ifcfg files are present, the configuration backend that supports them can be removed.
    ```sh
    dnf remove NetworkManager-initscripts-ifcfg-rh
    ```

#### NetworkManager
:   
    [**NetworkManager**](https://networkmanager.dev/) provides a high-level interface for the configuration of network interfaces.
    It was developed by Red Hat and [released](https://en.wikipedia.org/wiki/NetworkManager) in late 2004.

    The config file format native to NetworkManager is the ini-format [**keyfile**](https://networkmanager.dev/docs/api/latest/nm-settings-keyfile.html){: #keyfile }, typically stored in **/etc/NetworkManager/system-connections**.
    These files define network interfaces, or **connection profiles** in NetworkManager's terminology.

#### Netfilter
:   
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
