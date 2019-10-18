# CompTIA Network+

## Wireless
Wireless access [[1](#sources): 247]
- Basic service set (BSS): when a single AP is connected to the wired network
- Extended service set (ESS): using multiple BSSs to form a single subnetwork
- Independent basic service set (IBSS): ad hoc mode

## Addresses
127.0.0.1: reserved for loopback testing

## Protocols
#### ARP
A system will first attempt to determine whether it is on the same network as the requested IP. If so, the ARP **cache**, a locally stored table that maps Internet to physical addresses, is consulted to determine the corresponding MAC address entry. If the requested host is not found, a broadcast asks the host with the target IP to send back its MAC address and only the target system will reply. Cache entries can be made dynamically (they will be automatically updated) or statically (added with `arp -s` and removed with `arp -d`). [[1](#sources): 61-62]

Option  | Effect
:---    | :---
`-a`    | display entries in the cache
`-s`    | manually add a static entry to the cache
`-d`    | delete an entry from the cache

#### DHCP
DHCP process [[1](#sources): 74-75]
1. DHCPDISCOVER packet is sent by system configured to use DHCP
2. DHCPOFFER sent by DHCP server, containing IP address and other information such as lease duration
3. DHCPREQUEST packet notifies the server that the offer has been accepted
4. DHCPACK, sent as a broadcast, acknowledges the offer

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
An **SNMP management system** runs an application called the **network management system (NMS)**. All NMS applications today offer GUI-based interaction with the network to locate and then query network devices. Command-line SNMP requests are still possible, but no longer commonly used. Each of these network devices runs an application called an **agent** which facilitates communication with the SNMP manager. [[1](#sources): 56]\
SNMP commands can be sent from the manager to agents, including `Get`, `Get Next`, `Set`, and `Walk`. These commands demand that manager and agents share the same list.\
**Management Information Bases (MIBs)** are databases that define what parameters are accessible, read-only, and writable. Creation of MIBs is governed by ISO, which assigns every organization an ID number which is then associated with the MIBs it creates. These numbers are assigned in a model called the **hierarchical name tree**. [[1](#sources): 56]\
SNMP **communities** are logical groupings of systems within which devices only communicate with one another and only accept SNMP commands from a manager with the correct community name. There are typically two communities configured by default: public (read-only) and private (read-write). [[1](#sources): 56]

## Glossary
Term                                      | Definition
:---                                      | :---
Address Resolution Protocol (ARP)         | defined in **RFC 826**, responsible for resolving IP addresses to MAC addresses [[more...](#arp)]
administrative distance (AD)              | indicates a routing protocol's trustworthiness
Enhanced Interior Gateway Routing Protocol (EIGRP) | 
File Transfer Protocol (FTP)              | defined in **RFC 959**, protocol for uploading and downloading files [[1](#sources): 45]
H.323                                     | ITU-T standard that addresses call, multimedia, and bandwidth control for voice and videoconferencing [[1](#sources): 53]
Hypertext Transfer Protocol (HTTP)        | defined in **RFC 2068**, protocol that enables text, graphics, multimedia, and other material to be downloaded from an HTTP server [[1](#sources): 48]
Hypertext Transfer Protocol Secure (HTTPS)| [[1](#sources): 48]
Internet Control Message Protocol (ICMP)  | defined in **RFC 792**, provides error checking and reporting functionality, in particular in association with `ping` [[more...](#icmp)]
Internet Message Access Protocol Version 4 (IMAP4) | defined in **RFC 1731**
Internet Protocol (IP)                    | 
Lightweight Directory Access Protocol (LDAP) | provides a mechanism to access and query directory services systems [[more...](#ldap)]
Lightweight Directory Access Protocol over SSL (LDAPS) | known as "Secure LDAP", it provides an additional layer of security [[more...](#ldaps)]
Media Access Control (MAC)                | 
maximum transmission unit (MTU)           | concept in **IP** which makes fragmentation and reassembly necessary for sending large files [[1](#sources): 43]
Network Time Protocol (NTP)               | defined in **RFC 958**, facilitates time synchronization [[1](#sources): 51-52]
Post Office Protocol Version 3 (POP3)     | defined in **RFC 1939**
Remote Desktop Protocol (RDP)             | used in a Windows environment for remote connections [[1](#sources): 58]
Reverse Address Resolution Protocol (RARP)| defined in **RFC 903**, resolves MAC addresses to IP addresses [[1](#sources): 62]
Secure File Transfer Protocol (SFTP)      | secure file transfer, based on **SSH** [[1](#sources): 47]
Secure Shell (SSH)                        | secure virtual terminal protocol available in two incompatible versions (SSH1 and SSH2) [[1](#sources): 50]
Server Message Block (SMB)                | provides access to resources like files, printers, ports, etc [[1](#sources): 58]
Session Initiation Protocol (SIP)         | application layer protocol used to create **multimedia** sessions, including **VoIP**, using default ports **5060** and **5061** [[1](#sources): 57]
Simple Mail Transfer Protocol (SMTP)      | defined in **RFC 821** [[1](#sources): 47]
Simple Network Management Protocol        | protocol that enables network devices to communicate information about their state to a central system [[more...](#snmp)]
source quench                             | feature of **ICMP** where a receiving host can tell a sending host to slow down messages when the data influx is too great [[1](#sources): 51]
Telnet                                    | defined in **RFC 854**, unsecure virtual terminal protocol still used to access routers and managed network devices [[1](#sources): 50]
three-way handshake                       | process of establishing a **TCP** session [[1](#sources): 44]
Transmission Control Protocol (TCP)       | defined in **RFC 793**, connection-oriented transport protocol that adds features like **flow control**, **sequencing**, and error detection and correction to **IP** communication, [[1](#sources): 43]
trap                                      | messages sent from agents to the **SNMP** manager [[1](#sources): 54]
Trivial File Transfer Protocol            | defined in **RFC 1350**, unsecure file transfer protocol typically associated with simple downloads to managed devices. It offers **no** directory navigation, requiring precise paths to be specified, and uses UDP instead of TCP. [[1](#sources): 47]
User Datagram Protocol (UDP)              | defined in **RFC 768**, connectionless transport protocol [[1](#sources): 44]

## Sources
1. "Exam Cram: CompTIA Network+ N10-007". Dulaney, Emmett. 
