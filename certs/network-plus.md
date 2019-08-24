# Network Plus
## Ethernet standards

Standard    | Maximum rate  | Maximum range | Description
:---        | :---          | :---          | :---
100BASE-TX  | 100 Mbps      | 100 m         | UTP, STP
100BASE-FX  | 100 Mbps      | 412 m (multimode half duplex) <br/> 10,000 m (single-mode full duplex) | fiberoptic with SC or ST connectors
1000Base-LX | 1000Mbps      | 550 m         | single-mode fiber
1000Base-SX | 1000 Mbps     | 220 m (default installations) <br/> 550 m (with the right optics and terminations)        | multimode fiber
## Syslog
#     | Severity      | Description
:---  | :---          | :---  
0     | Emergencies   | Most severe error conditions that render the system unusable
1     | Alerts        | Conditions requiring immediate attention
2     | Critical      | Condition that should be addressed to prevent an interruption of service
3     | Error         | Error conditions that do not render the system unusable
4     | Warning       | Specific operations failed to complete successfully
5     | Notifications | Non-error notifications that alert an administrator about state changes within a system
6     | Informational | Detailed dinformation about the normal operation of a system
7     | Debugging     | Highly detailed information used for troubleshooting

## IPv6

Address or range  | Description
:---              | :---
FF00::/8          | multicast addresses
## Glossary

Term                                              | Description
:---                                              | :---
AUP                                               | typically employed to provide restrictions and overall guidelines on how a network should be used
Bit error rate tester (BERT)                      | tool to test a transmission link using both a pattern generator and an error detector, allowing it to calculate its **bit error rate (BER)** 
LACP                                              | Layer 3 redundancy that is achieved by having multiple links and assigning multiple physical links to a logical interface which appears as a single link to a route processor
leased line                                       | T3 connection is an example
Management Information Base (MIB)                 | database that defines and stores data about interfaces and details, such as errors, utilization, discards, packet drops, resets, speed, duplex, etc
MMF                                               | type of fiber optic cable that contains a core with a diameter large enough to transport light arriving at various angles
native VLAN                                       | VLAN on an IEEE 802.1Q trunk that does not have any tag bytes added
OC-48                                             | optical carrier level with a data rate of 2.488 Gbps
Orthogonal Frequency Division Multiplexing (OFDM) | wireless LAN transmission method **not** supported by 802.11b
PAP                                               | insecure PPP authentication method, providing one-way authentication while sending credentials in cleartext
rolled/rollover cable                             | used to allow a host to communicate with a router through its console, or COM port
SNAT                                              | NAT technology that assigns one inside local address to one outside global address