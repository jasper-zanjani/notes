--8<-- "includes/Network/abbrs.md"

# Networking

## IPv6

Various **address types** are associated with IPv6 ranges:

- **Global Unicast**: unique address that may be used on the public Internet
- **Unique Local** (FD00::/8): equivalent to RFC 1918 private ranges in IPv4, and not routable on the Internet
- **Link Local** (FE80::/10): equivalent to loopback addresses and automatically generated by IPv6 devices. This is enabled by the command `ipv6 enable`
- **Multicast** (FF00::/8): equivalent to broadcast, where a packet is sent to a group of subscribed devices
    - FF02::1: all devices
    - FF02::2: all routers
- **Anycast**: allows multiple devices to share the same IPv6 address


**EUI-64**{: #eui-64}
:   
    Generates an IPv6 host address from the device's MAC address


**SLAAC**{: #slaac }
:   
    IPv6 device learns its prefix information automatically over the local link from another device (i.e. router).
    The device can then generate its own **host portion** using [EUI-64](#eui-64)
    Because SLAAC cannot provide additional information such as DNS addresses, it is typically used alongside stateless DHCP.



Permit router to run IPv6-related routing protocols like EIGRP for IPv6 or OSPF version 3.

```
ipv6 unicast-routing
```

## Switching

When a switch receives an Ethernet frame, it examines the destination MAC address and compares it to its **MAC address table**.
This table is continuously updated by the switch as it learns new addresses and discards or **ages** old ones.
 
!!! cisco "MAC address table"

    ```
    S1>show mac address-table
    ```

When it finds an unknown destination, it proceeds with **frame flooding** where a frame is sent out all ports for the unknown MAC address's VLAN.
If it knows the destination MAC, it transmits the frame on the appropriate port.

Collisions no longer occur in modern networks because switches create a separate collision domain for each connection with a host, a condition called **microsegmentation**.
In older half duplex networks, technologies like CSMA/CD were used to negotiate the possibility of collisions.
Modern Cisco devices perform **autonegotiation** to resolve a common duplex and speed.

Ethernet frames have a common format:

- **Preamble** (7 bytes) is a pattern of alternating 1's and 0's for synchronization
- **Start Frame Delimiter (SFD)** (1 byte)
- **Destination MAC** (6 bytes)
- **Source MAC** (6 bytes)
- **Type** (2 bytes) identifies IPv4 or IPv6
- **Data and Pad** ranges in size from 46 to 1500 bytes. Padding is necessary if the frame would otherwise be less than the minimum 46 bytes.
- **Frame Check Sequence (FCS)** (4 bytes) is for error-checking

Larger frame sizes are possible with **baby giants** (1600 bytes) and **jumbo frames** (9216 bytes).

--8<-- "includes/Network/tasks/interface.md"

--8<-- "includes/Network/tasks/admin.md"

--8<-- "includes/Network/tasks/ip.md"

#### VLAN

--8<-- "includes/Network/defs/Switch/vlan.md"

--8<-- "includes/Network/tasks/vlan.md"

#### VTP

--8<-- "includes/Network/defs/Switch/vtp.md"

#### Trunking

802.1Q trunk links are the modern way of sharing traffic between switches by injecting a 4-byte tag value in the existing frame between the Source MAC address and Type fields rather than fully re-encapsulating the frame to add a VLAN marking as was the case in ISL.

--8<-- "includes/Network/tasks/trunking.md"

#### STP

--8<-- "includes/Network/defs/Switch/stp.md"

#### CDP

--8<-- "includes/Network/defs/Switch/cdp.md"

#### EtherChannel

EtherChannel aggregates multiple physical links to have them act as as a single one, providing redundancy and increased bandwidth.
It is often brought up in the context of [STP](#stp) because although STP does not permit redundant links it will also not block any one of the links within an EtherChannel bundle or **port-channel interface**.


Other **aggregation** technologies that make multiple switches act as one logical device:

- **Switch stacking**{: #stacking } is used in the access layer and uses special stacking ports and cables.
- **Chassis aggregation**{: #chassis-aggregation } is used in the distribution and core layers to aggregate only **two** switches with Ethernet interfaces. It is more complex to setup but is also more functional.

--8<-- "includes/Network/tasks/etherchannel.md"

## Routing

The routing table of a Cisco router has various sources, including many protocols of varying reliability.
Each source is associated with:

- A letter code (i.e. **R** for RIP, etc)
- **Administrative distance**, a numeric value which reflects Cisco's measure of the source's trustworthiness.
A lower value indicates higher trustworthiness, and the maximum value of 255 indicates an unusable route.
The administrative values associated with each routing protocol must be memorized for the CCNA exam.
- For dynamic routing protocols a **metric** is also provided whose significance varies with protocol. 
For example, with RIP the metric signifies **hop count**.

Administrative distance and metric are delimited by a forward slash and appear within square brackets following the **prefix**.

--8<-- "includes/Network/tasks/routing.md"

--8<-- "includes/Network/tasks/ip.md"

### Inter-VLAN routing

A multilayer switch possesses a **routing engine (RE)** to route between VLANs.
Without an RE, a **Router on a stick**{: #roas } configuration is necessary.

--8<-- "includes/Network/tasks/roas.md"