# ZFS

## Glossary

#### RAIDz

**RAIDz1**, **RAIDz2**, and **RAIDz3** are special varieties of parity RAID: the number indicates how many parity blocks are allocated to each data stripe.

#### vdev

A **vdev** is an abstraction of one or more devices.
One or more vdevs constitute a [**zpool**](#zpool).

Special support classes of vdev:

- `CACHE`
- `LOG`
- `SPECIAL`

Vdevs support one of five **topologies**:

- **Single-device** vdevs cannot survive any failure
- [**RAIDz1**](#raidz), [**RAIDz2**](#raidz), and [**RAIDz3**](#raidz)
- **Mirror** vdevs duplicate every block on each of their devices

#### zpool

A **zpool** is the largest structure in the ZFS taxonomy, representing an independent  collection of one or more [**vdevs**](#vdev).
Essentially, a zpool is a JBOD with special characteristics.

Writes are distributed across available vdevs in accordance with their available free space, such that they fill more or less evenly.

A **utilization awareness mechanism** built into ZFS also accounts for if one vdev is significantly more busy than another, i.e. reading.
In such a case, writes to that busy vdev will be deferred in favor of less busy ones.

## Further reading

- [ZFS 101](https://arstechnica.com/information-technology/2020/05/zfs-101-understanding-zfs-storage-and-performance/)