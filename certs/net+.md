# CompTIA Network+

Commands
:---
`dig` `ifconfig` `ipconfig` `iptables` `netstat` `nmap` `nslookup` `pathping` `ping` `route` `tcpdump` `traceroute` <br/>Windows: [`arp`](#arp-command) [`ipconfig`](#ipconfig) [`pathping`](#pathping) [`tracert`](#tracert)

#### IEEE speccifications
Term    | Description
:---    | :---
802.1   | Media Access Control
802.1az | SPB
802.1q  | VLANs, Trunking
802.1X  | Port authentication
802.2   | Logical Link Control (LLC) of Data Link Layer
802.3   | Ethernet, [ CSMA/CD ](#access-methods)
802.3af | [ PoE ](#poe)
802.3at | PoE+
802.11  | Wi-Fi
RFC 2131  | [DHCP](#DHCP)

#### Exam objectives 
\#    | Title | Description
:---  | :---  | :---
1.0 | Networking concepts
1.1 | Ports and protocols | [**DHCP**](#dhcp) [**DNS**](#dns) FTP H.323 HTTP HTTPS [**ICMP**](#icmp) IMAP [**IP**](#ip) [**LDAP**](#ldap) [**LDAPS**](#ldaps) NTP POP RDDP SFTP SIP SMB SMTP SNMP SSH TCP TELNET TFTP UDP
1.2 | Explain devices, applications, protocols and services at their appropriate OSI layers | 
1.3 | Explain the concepts and characteristics of routing and switching | **Properties of network traffic** <br/>Broadcast domains, CSMA/CD, CSMA/CA, Collision domains, Protocol data units, MTU, Broadcast, Multicast, Unicast <br/>**Segmentation and interface properties**<br/> VLANs, Trunking, Tagging and untagging ports, Port mirroring, Switching loops/spanning tree, PoE and PoE+, DMZ, MAC address table, ARP table<br/>**Routing**<br/> RIP, EIGRP, OSPF, BGP, Routing types<br/>**IPv6 concepts**<br/> Addressing, Tunneling, Dual stack, Router advertisement, Neighbor discovery<br/>**Performance concepts**<br/> Traffic shaping, QoS, Diffserv, CoS <br/>**Other topics**<br/> NAT, PAT, Port forwarding, Access control list, Distributed switching, Packet-switched network, Circuit-switched network, Software-defined networking
1.4 | Given a scenario, configure the appropriate IP addressing components | **Subnetting** Classful, Classless, VLSM, CIDR<br/>**Address assignments** DHCP, DHCPv6, Static, APIPA, EUI64, IP reservations
1.5 | Compare and contrast the characteristics of network topologies, types and technologies | **Wired topologies** Logical vs. physical, Star, Ring, Mesh, Bus, Mesh, Ad hoc, Infrastructure <br/>**Types** LAN, WLAN, MAN, WAN, CAN, SAN, PAN<br/>**IoT** Z-Wave, Ant+, Bluetooth, NFC, IR, RFID, 802.11
1.6 | Given a scenario, implement the appropriate wireless technologies and configurations | **802.11 standards** a, b, g, n, ac<br/>**Cellular** GSM, TDMA, CDMA <br/>**Frequencies** 2.4GHz, 5.0GHz <br/>**Other topics** Speed and distance requirements, Channel bandwidth, Channel bonding, MIMO/MU-MIMO, Unidirectional/omnidirectional, Site surveys
1.7 | Summmarize cloud concepts and their purposes | **Types of services** SaaS, PaaS, IaaS <br/>**Cloud delivery models** Private, Public, Hybrid<br/>**Other topics** Connectivity methods, Security implications/considerations, Relationship between local and cloud resources
1.8 | Explain the functions of network services | **DNS records** A, AAAA, TXT, SPF, DKIM, SRV, MX, CNAME, NS, PTR <br/>**DNS topics** Internal vs. external DNS, Third-party/cloud-hosted DNS, Hierarchy, Forward vs. reverse zone<br/>**DHCP service** MAC reservations, Pools, IP exclusions, Scope options, Lease time, TTL, DHCP relay, IP helper <br/>**Other topics** NTP, IPAM
2.0 | Infrastructure
2.1 | Given a scenario, deploy the appropriate cabling solution | **Media types** UTP, STP, Coaxial, Single-mode fiber, Multimode fiber, Plenum vs. PVC<br/>**Connector types** RJ-45, RJ-11, BNC, DB-9, DB-25, F-type, LC, ST, APC, UPC<br/>**Transceivers** SFP, GBIC, SFP+, QSFP, Bidrectional vs. Duplex <br/>**Termination points** 66 block, 110 block, Patch panel, Fiber distribution panel<br/>**Copper cable standards** Cat 3, Cat 5, Cat 5e, Cat 6, Cat 6a, Cat 7, RG-6, RG-59<br/>**Copper termination standards** TIA/EIA 568a, TIA/EIA 568b, Crossover, Straight-through<br/>**Ethernet deployment standards** 100BaseT, 1000BaseT, 1000BaseLX, 1000BaseSX, 10GBaseT
2.2 | Given a scenario, determine the appropriate placement of networking devices on a network and install/configure them | Firewall, Router, Switch, Hub, Bridge, Modems, WAP, Media converter, Wireless range extender, VoIP endpoint
2.3 | Explain the purposes and use cases for advanced networking devices | Multilayer switch, Wireless controller, Load balancer, IDS/IPS, Proxy server, VPN concentrator, AAA/RADIUS server, UTM appliance, NGFW/Layer 7 firewall, VoIP PBX, VoIP gateway, Content filter
2.4 | Explain the purposes of virtualization and network storage technologies | **Virtual networking components** Virtual switch, Virtual firewall, Virtual NIC, Virtual router, Hypervisor<br/>**Network storage types** NAS SAN<br/>**Connection type** FCoE, Fibre Channel, iSCSI, InfiniBand<br/>Jumbo Frame
2.5 | Compare and contrast WAN technologies
3.0 | Network operations
3.1 | Given a scenario, use appropriate documentation and diagrams to manage the network
3.2 | Compare and contrast business continuity and disaster recovery concepts
3.3 | Explain common scanning, monitoring and patching processes and summarize their expected outputs
3.4 | Given a scenario, use remote access methods
3.5 | Identify policies and best practices  | 
4.0 | Network security
4.1 | Summarize the purposes of physical security devices
4.2 | Explain authentication and access controls
4.3 | Given a scenario, secure a basic wireless network
4.4 | Summarize common networking attacks
4.5 | Given a scenario, implement network device hardening
4.6 | Explain common mitigation techniques and their purposes
5.0 | Network troubleshooting and tools
5.1 | Explain the network troubleshooting methodology
5.2 | Given a scenario, use the appropriate tool | **Hardware tools** Crimper, Cable tester, Punchdown tool, OTDR, Light meter, Tone generator, Loopback adapter, Multimeter, Spectrum analyzer<br/>**Software tools** Packet sniffer, Port scanner, Protocol analyzer, WiFi analyzer, Bandwidth speed tester<br/>**Command-line utilities** 
5.3 | Given a scenario, troubleshoot common wired connectivity and performance issues | Attenuation, Latency, Jitter, Crosstalk, EMI, Open/short, Incorrect pin-out, Incorrect cable type, Bad port, Transceiver mismatch, TX/RX reverse, Duplex/speed mismatch, Damaged cables, Bent pins, Bottlenecks, VLAN mismatch, Network connection LED status indicator
5.4 | Given a scenario, troubleshoot common wireless connectivity and performance issues | Reflection, Refraction, Absorption, LAtency, Jitter, Attenuation, Incorrect antenna type, Interference, Incorrect antenna placement, Channel overlap, Overcapacity, Distance limitations, Frequency mismatch, Wrong SSID, Wrong passphrase, Security type mismatch, Power levels, Signal-to-noise ratio
5.5 | Given a scenario, troubleshoot common network service issues | Names not resolving, Incorrect gateway, Incorrect netmask, Duplicate IP addresses, Duplicate MAC addresses, Expired IP address, Rogue DHCP server, Untrusted SSL certificate, Incorrect time, Exhausted DHCP scope, Blocked TCP/UDP ports, Incorrect host-based firewall settings, Incorrect ACL settings, Unresponsive service, Hardware failure

## Wireless
Wireless access [[1](#sources): 247]
- **Basic service set (BSS)**: single AP
- **Extended service set (ESS)**: multiple APs
- **Independent basic service set (IBSS)**: ad hoc mode

## IP
#### Addresses
**IP addresses** provide two items of information: **network address** and **node address**. Every device on a logical network segment must have the same network address but different node addresses.\
- An IPv4 address is a 32 bit value written as 4 decimal **octets** delimited by periods. [[1](#sources): 81] 
- An IPv6 address is a 128 bit value written as 8 16-bit hexadecimal blocks delimited by colons. [[1](#sources): 90]

IPv4 address types: [[1](#sources) 88]
- **Unicast address**: delivered to a specific node identified by the address
- **Broadcast address**: delivered to all systems on a subnet or network
- **Multicast address**: deliver to all members of a group

IPv6 address types: [[1](#sources): 91]
- **Unicast address**: specifies a single interface
- **Global unicast address**: equivalent of IPv4 public addresses, routable and travel throughout the network
- **Link-local address**: designated for use on a single local network and automatically configured, comparable to the APIPA automatically assigned addressing scheme used in IPv4
- **Site-local address**: equivalent to IPv4 private address space
- **Multicast address**: groups of nodes
- **Anycast address**: deliver messages to any one node in a multicast group

Notable address or range  | Description
:---            | :---
127.0.0.1       | reserved for loopback testing
169.254.0.0/16  | range of addresses used in APIPA
::0, ::1        | loopback address
2000::/3        | global unicast range
fc00::/7        | unique local unicast
ff00::/8        | multicast range
fe80::/64       | IPv6 link-local addresses
fec0::/10       | IPv6 site-local addresses

#### Network Address Translation
**NAT** allows many computers to hide behind a single IP address, using one of several addressing schemes [[1](#sources): 99-101].
- **Destination Network Address Translation (DNAT)**: destination IP addresses of individual packets is changed by the router
- **Port Address Translation (PAT)**: internal IPs correspond to the same external IP but with different port numbers
- **Static Network Address Tranlsation (SNAT)**: a private IP is mapped to a single external public one
- **Destination Network Address Translation (DNAT)**: destination IP addresses of individual packets is changed by the router

#### Switching
- **Packet switching**: also known as independent routing, messages are broken down into smaller pieces called **packets**
  - **Virtual-circuit** packet switching: where a logical connection is established between the source and destination device
  - **Datagram** packet switching: packets are independently sent
- **Circuit switching**: requires a dedicated physical connection between sending and receiving devices

#### Routing 
- **Static routing**: manually entered routes
- **Dynamic routing**: involves routers communicating known routes to all directly attached routers. Communication between distance-vector routers is known as **hops**: each router represents one hop. There are **two** types of routing protocols used:
  - **Distance-vector protocols** operate by having each router send updates about all the other routers it knows about to directly connected routers, with updates automatically sent every 30 or 60 seconds. Routers can be configured to send **triggered updates** when a change is detected. The process by which routers learn of updates to network topology is called **convergence**.
    - **Router Information Protocol (RIP)** limited to 15 hops, no support for authentication. **RIPv2** also limited to 15 hops to maintain compatibility with v1, but supports authentication.
    - **Enhanced Interior Gateway Routing Protocol (EIGRP)**: enables routers to exchange information more efficiently than RIP, using neighbors to determine routing information. Uses **Diffusing Update Algorithm (DUAL)** to determine best route to a destination.
  - **Link-state protocols**: newer option where the router builds a map of the entire network. Routers send **link-state advertisements (LSA)** that contain information about the networks to which they connect. [[1](#sources): 114]
    - **Open Shortest Path First (OSPF)**: based on the **shortest path first (SPF)** algorithm to find the least-cost path to any network node
    - **Intermediate System-to-Intermediate System (IS-IS)**: discover shortest path for data to travel using the **SPF** algorithm
  - **Hybrid Routing Protocols**
    - **Border Gateway Protocol (BGP)** can be used between gateway hosts on the Internet. BGP supports the use of **autonomous system numbers (ASN)**, globally unique numbers used by connected groups of IP networks that share the same routing policy.

Another way of categorizing routing protocols:
- **Interior Gateway Protocols (IGP)** include distance-vector and link-state protocols, i.e. RIP, OSPF, and IS-IS
- **Exterior Gateway Protocols (EGP)** include BGP

**Routing loops** occur when routers are too slow in updating their routing tables and a redundant communication cycle is created between them. This is mitigated by:
- **Split horizon** prevents router from advertising routes to routers from which they were learned
- **Poison reverse** route is advertised back on the interface from which it was learned but with a hop count of infinity, which tells the node that the route is unreachable.

#### Access methods
- **Carrier sense multiple access/collision detection (CSMA/CD)**: known as a **contention media access method**, before sending data a system checks to see if the network medium is free because the medium can carry only one network signal at a time. When a collision is detected, systems wait a randomly calculated amount of time in milliseconds known as the **backoff** period before attempting to transmit again.
- **Carrier sense multiple access with collision avoidance (CSMA/CA)**: systems announce intent to transmit data, and others wait their turn. If the medium is busy, the system waits for a backoff interval before trying again.

#### Routing metrics
- **Hop counts**: number of hops necessary to reach a node
- **Maximum transmission unit (MTU)**: largest data unit that can be passed without fragmentation
- **Bandwidth**: maximum packet size permitted for Internet transmission
- **Costs**: numbers associated with traveling from hop to hop
- **Administrative distance:** numerical value assigned to a route based on its perceived quality, assigned based on an algorithm employed by a routing protocol
- **Latency**: amount of time it takes for a packet to travel from one location to another

### Switching
#### VLAN
VLANs are groups of connected computers that act as if they are on their own network segment, even though they might not be, and they are used for network segmentation. [[1](#sources): 119-120]\ 
VLAN membership
- **Protocol-based VLANs**: computers are assigned to VLANs using the protocol in use and the Layer 3 address
- **Port-based VLANs**: require that specific ports on a network switch be assigned to a LAN
- **MAC address-based VLANs**

#### STP
**Spanning Tree Protocol (STP)**, used with network [ **bridges** ](#bridge) and **switches** uses the **Spanning Tree Algorithm (STA)** to prevent the occurrence of switching loops. It also uses **bridge protocol data units (BPDUs)** to identify the status of ports and bridges across the network.

#### Interface configuration
There are various ways of adjusting the functionality of switch interfaces:
- **Tag or untag VLANs**: tag if you are trunking
- **Default VLAN**: cannot be deleted and is used for communication between switches (VLAN 1 in Cisco switches)
- **Port mirroring**: duplicating data for one port and sending it to another, most commonly to monitor traffic using **Remote Switched Port Analyzer (RSPAN)** or **Switched Port Analyzer (SPAN)**.
- **Authentication, accounting, and authorization (AAA)** through [**RADIUS**](#radius), [**TACACS+**](#tacacs), or [**Kerberos**](#kerberos) 
- Usernames/passwords
- **Virtual consoles and terminals**



## Other protocols
#### ARP
A system will first attempt to determine whether it is on the same network as the requested IP. If so, the ARP **cache**, a locally stored table that maps Internet to physical addresses, is consulted to determine the corresponding MAC address entry. If the requested host is not found, a broadcast asks the host with the target IP to send back its MAC address and only the target system will reply. Cache entries can be made dynamically (they will be automatically updated) or statically (added with `arp -s` and removed with `arp -d`). [[1](#sources): 61-62]

#### DHCP
**Dynamic Host Configuration Protocol (DHCP)** enables IP address ranges ("**scopes**" or "**address pools**") to be used to randomly assign IP addresses to hosts. **Scope options** can be configured, such as supplying a specific address to a client which is known as a **reservation**, or where certain addresses are **not** given out to clients which is known as an **exclusion**.


DHCP process [[1](#sources): 74-75]
1. **DHCPDISCOVER** packet is sent by system configured to use DHCP
2. **DHCPOFFER** sent by DHCP server, containing IP address and other information such as lease duration
3. **DHCPREQUEST** packet notifies the server that the offer has been accepted
4. **DHCPACK**, sent as a broadcast, acknowledges the offer

#### ICMP
In addition to `ping`, ICMP can return error messages like "Destination unreachable" and "Time exceeded". ICMP can also perform **source quench**, where the receiving host sends ICMP messages back to the sender when it cannot handle an excessive influx of data. [[1](#sources): 51]

#### LDAP
LDAP supports command-line queries executed directly against the database, but mostly authentication programs and search utilities provide a layer of abstraction. [[1](#sources): 52]

#### LDAPS
Differs from LDAP in two ways [[1](#sources): 52]
1. LDAP messages are transferred over a TLS session
2. LDAPS connection must be closed if TLS closes

#### SNMP
In an SNMP configuration, a central system known as a **manager** acts as the central communication point for all SNMP-enabled devices on the network. Each SNMP-enabled device runs an SNMP agent which communicates the occurrence of certaine events to the manager by sending it messages, called **traps**. [[1](#sources): 52-53]\
An **SNMP management system** runs an application called the **network management system (NMS)**. All NMS applications today offer GUI-based interaction with the network to locate and then query network devices. Command-line SNMP requests are still possible, but no longer commonly used. Each of these network devices runs an application called an **agent** which facilitates communication with the SNMP manager. [[1](#sources): 56, 323]\
SNMP commands can be sent from the manager to agents, including `Get`, `Get Next`, `Set`, and `Walk`. These commands demand that manager and agents share the same list.\
**Management Information Bases (MIBs)** are databases that define what parameters are accessible, read-only, and writable. Creation of MIBs is governed by ISO, which assigns every organization an ID number which is then associated with the MIBs it creates. These numbers are assigned in a model called the **hierarchical name tree**. [[1](#sources): 56, 324]\
SNMP **communities** are logical groupings of systems within which devices only communicate with one another and only accept SNMP commands from a manager with the correct community name. There are typically two communities configured by default: public (read-only) and private (read-write). [[1](#sources): 56]

## Network services
Network services provide functionality enabling the network to operate

### DNS 
**Domain Name System (DNS)** originated to support the growth of email. **RFC 805** introduced the concepts of domains (previous to that, emails took the format `USER@HOST` with no domain.\
DNS has 3 main components: [[2]]
- **Domain namespace**: which has logical divisions that are **hierarchically organized** into a tree-like structure composed of top-level or country domains (`.gov`, `.ca`, etc), sub- or second-level domains (`example.com`), and then further subdomains. The **fully qualified domain name (FQDN)** contains the top-level domain, domain, and subdomains (if any) of a host. [[1](#sources): 68]
- **Name servers**: server programs that contain the domain tree's structure and can set or cache it.
- **Resolvers**: client programs that extract information from name servers in response to user requests.

#### DNS records
A domain name identifies a set of resources that is associated with separate **resource registry (RR)**. The most common ones are: [[2](#sources)]
- **`A`**: host address associated with the domain name
- **`NS`**: authoritative name server
- **`SOA`**: start of a zone of authority
- **`CNAME`**: canonical name of an alias
- **Pointer (`PTR`)** records are used for **reverse lookup**, that is resolving IP address to hostnames. [[1](#sources): 69]

#### NetBIOS resolution
**Network Basic Input/Output System (NetBIOS)** name resolution can be performed 3 ways
- **Windows Internet Name Service (WINS)** on Windows networks
- **`LMHOSTS`** file which must be manually configured
- Using broadcasts, but broadcasts create additional traffic and cannot traverse routers without additional configuration, so name resolution across segments becomes impossible.

### [ DHCP ](#dhcp)


## Business continuity and disaster recovery
#### Backup types
[[1](#sources): 307]
- **Full**
- **Incremental**: backup of data that has changed since the previous incremental backup
- **Differential**: backup of data that has changed since the last full backup
- **Snapshot**: read-only copy of data, frozen at a point in time

#### Power disruptions
[[1](#sources): 311]
- **Blackout**: total failure of power supply
- **Spike**: Short but intense increase in voltage
- **Surge**: Increase in power that is longer but less intense than a spike
- **Sage**: Short-term voltage drop
- **Brownout**: drop in voltage that lasts more than a few minutes

#### Technologies that enable high availability
[[1](#sources): 314]
- **Fault tolerance**: capability to withstand a fault without losing tolerance
- **Load balancing**: technique in which the workload is distrbuted among several servers

#### Policies
[[1](#sources): 315]
- **Standard business documents**:
  - **Service-level agreement (SLA)**: 
  - Memorandum of understanding (MOU)
  - Master license agreement (MLA)
  - Statement of work (SOW)
- **Acceptable use policy (AUP)** describe how the employees in an organization can use company systems and resources
- Network policies
- **Security policy** defines what controls are required to implement and maintain the security of systems, users, and networks
- Bring your own device (BYOD) policy


#### Network test types
[[1](#sources): 329]
- **Performance test**: measures network's current performance level
- **Load test**: also called ""volume"" or ""endurance"" testing, involve placing the network under a larger-than-normal workload
- **Stress test**: push resources to the limit by placing the network under intense pressure

#### Primary event logs in Windows
[[1](#sources): 331]
- **Security logs**: contains events related to security incidents, such as successful and unsuccessful logon attempts and failed resource access
- **Application log**: contains information logged by applications that run on a particular system rather than the operating system itself
- **System logs**: contains information about components or drivers in the system



## Devices
#### Bridge


## Commands
### arp command
Used to view and work with the IP adress to MAC address resolution cache.

Option  | Effect
:---    | :---
`-a`    | Display both the IP and MAC addresses and whether they are dynamic or static entries [[1](#sources): 436]
`-s`    | manually add a static entry to the cache
`-d`    | delete an entry from the cache

### route
[[1](#sources): 107]
Command | Effect
:---    | :---
`add`   | add a static route to a routing table

Option  | Effect
:---    | :---
`-p`    | make a route **p**ersistent

Basic syntax:
```sh
route add 192.168.2.1 mask (255.255.255.0) 192.168.2.4
```

### tracert
On Windows, this command is aliased to `traceroute` which is the Linux command. [[1](#sources): 112]
Option  | Effect
:---    | :---
`-6`    | IPv6, aliased to `traceroute6`

## Sources
1. "Exam Cram: CompTIA Network+ N10-007". Dulaney, Emmett. 
2. "DNS 101: An introduction to Domain Name Servers". [Red Hat](https://www.redhat.com/sysadmin/dns-domain-name-servers): 2019/10/17.
