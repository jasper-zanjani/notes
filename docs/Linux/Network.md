--8<-- "includes/Network/abbrs.md"

# Network

The Linux kernel supports several packet-filtering mechanisms.

- [**Netfilter**](#netfilter) using the venerable [iptables](#iptables) utility
- **nftables** subsystem, introduced with kernel 3.13 (2014), had been commonly assumed to eventually take the place of iptables. Firewall rules are implemented in an in-kernel VM.
- **bpfilter** 

## Netfilter

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

#### Chains
:   There are five builtin netfilter chains, though user-defined chains are also possible:

    - **INPUT** used for filtering incoming packets where the host itself is the destination packet.
    - **OUTPUT** for outgoing packets, where the host is the source of the packet.
    - **FORWARD** for filtering routed packets, where the host is router.
    - **PREROUTING** used for DNAT or port forwarding
    - **POSTROUTING** used for SNAT

#### Tables
:   
    - **filter** default
    - **nat** for SNAT and DNAT
    - **mangle** for packet alteration
    - **raw** used only to mark packets that should not be handled by the connection tracking system using the NOTRACK target


## Tasks

--8<-- "includes/Linux/Tasks/download.md"

--8<-- "includes/Linux/Tasks/wireguard-tunnel.md"

## Commands

--8<-- "includes/Linux/Commands/curl.md"

--8<-- "includes/Linux/Commands/firewall-cmd.md"

--8<-- "includes/Linux/Commands/iptables.md"

--8<-- "includes/Linux/Commands/netcat.md"

--8<-- "includes/Linux/Commands/netplan.md"

--8<-- "includes/Linux/Commands/nmap.md"

--8<-- "includes/Linux/Commands/nmcli.md"

--8<-- "includes/Linux/Commands/tcpdump.md"

--8<-- "includes/Linux/Commands/ufw.md"

--8<-- "includes/Linux/Commands/wg.md"

--8<-- "includes/Linux/Commands/wget.md"

## Glossary
