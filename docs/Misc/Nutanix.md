# Nutanix

*[HCI]: Hyper-Converged Infrastructure, where cluster nodes host both storage and compute 
*[AHV]: Acropolis Hypervisor

Nutanix **AOS** is an offering that creates a storage fabric distributed across all nodes of an HCI cluster, intended for data center.
Nutanix was the first to offer an HCI solution in 2011, and since then the market has exploded.

AOS supports multiple hypervisors, including Nutanix's native AHV, as well as ESXi and Hyper-V.

AOS nodes are able to run all the core services of the cluster.

Nutanix has a CLI, known as **NCLI**.
**Prism** is the name of the graphical management console.

 

## Architecture

UVMs are controlled by the **CVM** or **Controller VM** which runs the Nutanix software.
The CVM is a hardened Linux appliance and a "User Mode VM" which exists in only a single instance per node.
AOS has a "shared-nothing" architecture, so in the event of one node's CVM failing, the cluster's other nodes take over management of that node's UVMs until the CVM has recovered.
The CVM runs several services, including:

- **Stargate** the data I/O manager
- **Cassandra** metadata store
- **Prism** user interface
- **Cerebro** replication and "DR"
- **Zookeeper** distributed configuration store
- **Curator** MapReduce cluster manager and cleanup
- **Acropolis** AHV 

A **block** refers to a chassis that supports 1-4 nodes, providing power, cooling, and a shared backplane to all hosted nodes. However unlike a blade chassis it does not have shared networking.

### Storage

Several blocks connected to a third-party switch form a **Distributed Storage Fabric**, which combines every block's storage into a single storage pool.

**Containers** are logical storage policies and do not correspond with physical disks, and all are thinly provisioned.
In ESXi a container is presented as a **datastore**.