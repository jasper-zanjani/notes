# ICND1

## Network design
Hierarchical network design refers to three-layered or three-tiered network design:
  1. Access layer: no routing takes place, L2 only
  2. Distribution layer: routing switches that transfer between Core and Access
  3. Core layer: network backbone that emphasizes fast transport between distribution switches
    - high redundancy and aailability, fast
    - avoid packet manipulation
Collapsed core design collapses the Distribution and Core layers
  - more cost-effective for small enterprises which won't grow

## Topics
Ethernet frame components
  1. Preamble: 7 Bytes
  2. Start Frame Delimiter (SFD): 1B
  3. Destination MAC Address: 6B
  4. Source MAC Address: 6B
  5. Type of protocol listed within frame Data: 2B
  6. Frame Check Sequence (FCS): 4B

TCP/IP Transport protocol (L4)
  - most import functions: error recovery and flow control
  - TCP provides more services than UDP, but UDP is leaner and faster
  - UDP used by VoIP, video applications
  - multiplexing refers to L4's use of port numbers, which allow packet data to be served to individual applications
  - Socket has 3 components:
    1. IP address
    2. Transport protocol (implied in use of TCP/IP)
    3. Port number
  - SNMP used by Cisco Prime network management software
### IPv6
Anycast addressing: one to one-of-many addressing where packets are routed to any single member of a group of potential receivers that are all identified by the same destination address; one is selected from the group by a routing algorithm based on topological proximity
  1. `enable` enable privileged EXEC mode
  2. `configure terminal` enter global configuration mode
  3. `interface TYPE NUMBER` specify interface type and number, place device in interface configuration mode
  4. `tunnel mode ipv6ip [6rd | 6to4 | auto-tunnel | isatap]` configure a static IPv6 tunnel interface
  5. `tunnel source { ip address | ipv6-address | interface-type interface-number }` set source address for a tunnel interface
  6. `ipv6 address {ipv6-prefix/prefix-length | prefix-nae sub-bits/prefix-length}` configure IPv6 address and enable IPv6 processing on the interface
  7. `ipv6 address ipv6-prefix/prefix-length anycast`
### VLANs
VLANs allow switches to separate broadcast domains
VLAN is an L2 concept which corresponds to subnets, an L3 concept
VLAN trunking allows switches to tag frames with an extra header and coordinate the same VLANs between them (on a single interface)
IEEE 802.1Q trunking protocol
  - has largely replaced Cisco's proprietary Inter-Switch Link (ISL) trunking protocol
  - Fields:
    - Destination Address
    - Source Address
    - Tag
      - Type
      - Priority
      - Flag
      - VLAN ID (12 bits)
    - Type
    - Data
    - FCS
  - Supports a maximum of 4094 VLANs (2^12 - 2)
Layer 3 switches allow a single switch to negotiate the transfer of packets between VLANs, which because they map to L3 subnet masks, would normally require a router (router-on-a-stick)
VLAN Trunking Protocol (VTP) should be noted for later study because it can complicate trunking, but largely ignored for the ICND1
### OSPF
don't forget to go back to Udemy GNS3 video 8 after learning OSPF to make sense of what is happening
