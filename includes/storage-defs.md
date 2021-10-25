*[ARC]: Adaptive Replacement Cache
*[CoW]: Copy on Write
*[LRU]: Least Recently Used
*[SLOG]: Secondary LOG device
*[TXG]: Transaction Group
*[ZIL]: ZFS Intent Log
*[NFS]: Network File System
*[ZFS]: Zettabyte File System
*[ZED]: ZFS Event Daemon

**ARC**{: #arc }
:   
    ARC serves as ZFS's read cache mechanism and avoids the [thrashing](#thrashing) possible with standard OS page caches by using a more efficient algorithm.


**B-tree**{: #btree }
:   
    A **B-tree** is a self-balancing tree data structure used by [btrfs](#btrfs) to organize and store metadata.

**block group**{: #block-group}
:   
    In [btrfs](#btrfs) the fundamental unit of storage allocation consisting of one or more **chunks**, depending on RAID level, each stored on a different **device**.

**boot environment**
:   
    Allow changes to OS installations to be reverted

**copy-on-write**{: #cow }
:   
    In a **CoW** filesystem like [ZFS](#zfs) and [btrfs](#btrfs), when data on the filesystem is modified, that data is copied first before being modified and then written back to a different free location. 
    The main advantage of this method is that the original data [extent](#extent) is not modified, so the risk of data corruption or partial update due to power failure is eliminated.
    This ensures that writes are atomic and the filesystem will always be in a consistent state.

**dataset**{: #dataset}
:   
    In ZFS, one or more **datasets** constitute a unified filesystem.
    Improves on the use of traditional use of partitions in, say, Linux installations where mount points are typically separate partitions.
    Datasets allow quotas and other rules to be enforced.

**extent**{: #extent }
:   
    In [btrfs](#btrfs), an **extent** is the fundamental storage unit corresponding to a contiguous sequence of bytes on disk that holds file data. 
    Files can be fragmented into multiple extents, and this fragmentation can be measured using the `filefrag` CLI utility.

**Extended File System**{: #ext } 
:   
    Ext was first implemented in 1992 by Remy Card to address limitations in the MINIX filesystem, which was used to develop the first Linux kernel. 
    It could address up to 2GB of storage and handle 255-character filenames and had only one timestap per file.

    - **Ext2**{ #ext2} was developed by Remy Card only a year after ext's release as a commercial-grade filesystem, influenced by BSD's Berkeley Fast File System. It was prone to corruption if the system crashed or lost power while data was being written and performance losses due to fragmentation. Nevertheless, it was quickly and widely adopted, and still used as a format for USB drives.
    - **Ext3**{ #ext3 } was adopted by mainline Linux in 2001 and uses **journaling**, whereby disk writes are stored as transactions in a special allocation, which allows a rebooted system to roll back incomplete transactions.
    - **Ext4**{ #ext4 } was added to mainline Linux in 2008, developed by Theodore Ts'o, and improves upon ext3 but is still reliant on old technology.

#### inode
:   
    An **inode** (index node) is a data structure that stores all the metadata about a file but not its name or data.

**subvolume**{: #subvolume}
:   
    A tree of files and directories inside a [btrfs](#btrfs) that can be mounted as if it were an independent filesystem.
    Each btrfs filesystem has at least one subvolume that contains everything else in the filesystem, called the **top-level subvolume**.

**thrashing**{: #thrashing }
:   
    All OSes implement the page cache using the LRU algorithm, which maintains a queue of the most recently read blocks.
    As more recent blocks are read, older blocks are evicted from the bottom of the queue even if they are more frequently accessed.
    This process is referred to as **thrashing**.
    

**RAID hole**{: #raid-hole }
:   
    Condition in which a stripe is only partially written before the system crashes, making the array inconsistent and corrupt after a restart

**RAIDz**{: #raidz }
:   
    **RAIDz1**, **RAIDz2**, and **RAIDz3** are special varieties of parity RAID in [ZFS](#zfs): the number indicates how many parity blocks are allocated to each data **stripe**.

**Resilvering**
:   
    Process of rebuilding redundant groups after disk replacement

**SMB**{: #smb }
:   
    Client/server protocol developed in the early 1980s by Intel, Microsoft, and IBM that has become the native protocol for file and printer sharing on Windows.
    It is implemented in the **Samba**{: #samba } application suite.

**stripe**{: #stripe }
:   



#### vdev
:   
    In [ZFS](#zfs) a **vdev** ("virtual device") is an abstraction of one or more storage devices.
    This is equivalent to a volume group in LVM.

    A collection of vdevs constitutes a [**zpool**](#zpool).

    Vdevs support one of five **topologies**:

    - **Single-device** vdevs cannot survive any failure
    - **Mirror** vdevs duplicate every block on each of their devices
    - [**RAIDz1**](#raidz)
    - [**RAIDz2**](#raidz)
    - [**RAIDz3**](#raidz)

    Special support classes of vdev:

    - `CACHE`
    - **LOG** (also SLOG), because it usually has faster write performance, provides the pool with a separate vdev to store the ZIL in.
    - `SPECIAL`

**ZED**{: #zed }
:   
    Daemon that will listen to kernel events related to ZFS, conducting action defined in **zedlets**.

**zfs-fuse**
:   
    ZFS filesystem daemon

**ZFS**
:   
    ZFS is a technology that combines the functions of a 128-bit CoW filesystem, a volume manager, and software RAID.

    Like RAID, ZFS attempts to achieve data reliability by abstracting [volumes](#zpool) over [physical devices](#vdev). 
    But ZFS improves on RAID with error handling: it can use [checksum](#metadata) information to correct corrupted files.
    This is unlike hardware RAID mirrors, where failures occur silently and are typically only detected upon reading a corrupt file.

    ZFS writes use CoW meaning they are atomic and aren't affected by issues like [RAID holes](#raid-hole).

    ZFS can also transparently compress data written to datasets

**ZIL**{: #zil }
:   
    The ZIL is a special storage area used for **synchronous** writes.

    Most writes are **asynchronous**, where the filesystem is allowed to aggregate and commit them in batches to reduce fragmentation and increase throughput.

    **Synchronous** writes in ZFS are committed to the ZIL while also kept in memory.
    Writes saved to the ZIL are committed to main storage in normal TXGs moments later.

    Normally, the ZIL is written to and never read from again.
    Writes saved to ZIL are committed to main storage from RAM in normal TXGs after a few moments and unlinked from the ZIL.

    The ZIL is only read during pool imports that occur after a crash and restart.

    The ZIL can be placed on the LOG vdev to take advantage of higher write performance during sync writes.

    The ZIL is typically mirrored because that is where data can be lost.

#### zpool
:   
    A **zpool** is the largest structure in the ZFS taxonomy, representing an independent collection of one or more [**vdevs**](#vdev).
    Essentially, a zpool is a JBOD with special characteristics.

    Writes are distributed across available vdevs in accordance with their available free space, such that they fill more or less evenly.

    A **utilization awareness mechanism** built into ZFS also accounts for if one vdev is significantly more busy than another, i.e. reading.
    In such a case, writes to that busy vdev will be deferred in favor of less busy ones.

    Zpools are automatically mounted at root upon creation (without the need to edit fstab).
