# Book of GNS3
Jason C. Neumann

## Nodes
- **Frame Relay switch node** capable of emulating the basics of a generic Frame Relay switch. To configure **DLCI** to serial port mappings, open Node configurator, set Source and Destination Ports, then click Add. [[Neumann](#neumann): 97]

Dynamips switches [[Neumann](#neumann): 96]:
- **Ethernet Hub node** simulates a hub in GNS3, only the number of ports can be configured [[Neumann](#neumann): 95]
- **EtherSwitch Router node** Dynamips router that runs Cisco IOS and configured with a 16-port switch module; requires a c3745 router image with IOS [[Neumann](#neumann): 96]
- **Cloud node** allows GNS3 virtual devices to communicate with other programs or real hardware, like the host's Ethernet adapter [[Neumann](#neumann): 104]

Cloud Node **Netowrk Input/Output (NIO)** options
- **NIO Ethernet** create a connection to one or more physical or logical interfaces in host [[Neumann](#neumann): 104]
- **NIO UDP** create a UDP socket [[Neumann](#neumann): 104]
- **NIO TAP** create a connection to a virtual TAP interface, which are often bridged to physical interfaces in the host machine [[Neumann](#neumann): 105]
- **NIO UNIX** create a Unix Socket [[Neumann](#neumann): 105]
- **NIO VDE** create a link between GNS3 and a VDE device [[Neumann](#neumann): 105]
  - **virtual distributed ethernet (VDE)**  [[Neumann](#neumann): 105]
- **NIO NULL** create a link between GNS3 and a NULL device to form a dummylink [[Neumann](#neumann): 105]


## Tasks
Task                        | Ref
:---                        | :---
Frame Relay hub and spoke   | [[Neumann](#neumann): 98-100]

## Sources
##### Neumann
"The Book of GNS3: Build Virtual Network Labs Using Cisco, Juniper, and More". Jason C. Neumann. No Starch Press: 2015.