# Linux distributions

## Clear Linux
Linux distribution backed by Intel, which also backed 4 similar Linux distros in the past 

## Fedora CoreOS
**CoreOS** is a Fedora edition built specifically for running containerized workloads securely and at scale. Because containers can be deployed across many nodes for redundancy, the system can be updated and rebooted automatically without affecting uptime.\
CoreOS systems are meant to be **immutable infrastructure**, meaning they are only configured through the provisioning process and not modified in-place. All systems start with a generic OS image, but on first boot it uses a system called **Ignition** to read an **Ignition config** (which is converted from a **Fedora CoreOS Config** file) from the cloud or a remote URL, by which it provisions itself, creating disk partitions, file systems, users, etc.\
CoreOS automatically installs upgrades automatically without user intervention, although they can be stopped if a problem is found.

## Sources
  Clear Linux segment. [Linux Unplugged](../sources/sources.md): 289
  "Introducing Fedora CoreOS". [Fedora Magazine](https://fedoramagazine.org/introducing-fedora-coreos/): 2019/07/24.