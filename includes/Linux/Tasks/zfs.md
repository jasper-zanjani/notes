### ZFS management
:   


    ```sh
    # Create a storage pool, conventionally named "tank" in documentation
    zpool create tank raidz /dev/sd{a,b,c}
    
    # By default, disks are identified by UUID
    zpool status tank
    zpool list

    # Display block device names
    zpool status tank -L 
    zpool list -v

    # Destroy pool
    zpool destroy tank
    ```

    ```sh title="Mirrored arrays"
    zpool add tank mirror sde sdf
    zpool detach sdb
    ```

#### Removing devices
:   
    [**zpool remove**](https://openzfs.github.io/openzfs-docs/man/8/zpool-remove.8.html) is used to remove spare, cache, log and top-level data devices that are **not** raidz (top-level raidz vdevs cannot be removed).
    
    ```sh
    # Hot spares
    zpool add tank spare sdg
    zpool remove tank sdg
    
    # When incorrectly adding a device to a pool
    zpool add tank sdh
    zpool remove sdh
    zpool add tank mirror sdh
    ```

    Alternatively, [**zpool detach**](https://openzfs.github.io/openzfs-docs/man/8/zpool-detach.8.html) is used exclusively to remove a mirrored data device.

#### Disk replacement
:   
    If a disk has gone bad, it must first be taken offline using [**zpool offline**](https://openzfs.github.io/openzfs-docs/man/8/zpool-offline.8.html) before physically replacing it.
    Then [**zpool replace**](https://openzfs.github.io/openzfs-docs/man/8/zpool-replace.8.html) is used, which initiates the [**resilvering**](#resilvering) process.
    
    
    ```sh
    zpool replace tank sdb sdc
    ```
    
    Ongoing resilvers can be cancelled using **zpool detach**:
    ```sh
    zpool detach tank sdc
    ```

    ```sh title="Replace disk"
    # Clear errors first
    zpool clear tank

    # Take disk offline
    zpool offline tank sdb

    # Replace disk physically
    
    # Begin the resilvering process
    zpool replace tank sdb sdc

    # Monitor resilvering process
    watch zpool status tank
    ```

    Sometimes the UUID must be provided to take a disk offline.
    This can be retrieved using [**blkid**](#blkid).

    ```sh
    blkid /dev/sdb2
    zpool offline $UUID
    ```
    
    When simply moving a disk's physical location (from one bay to another), it must also be taken offline.

    ```sh
    zpool offline tank sdb

    # Move disk physically

    zpool online tank sdb
    ```

    [Replacing](https://docs.oracle.com/cd/E19253-01/819-5461/gazgd/index.html) a used disk with one that is unused similarly uses **zpool replace**, 

### Dataset management
:   
    A [**dataset**](#dataset) in ZFS is equivalent to the [btrfs](#btrfs) [**subvolume**](#subvolume), defined as an independently mountable POSIX filetree.

    ```sh
    # Display all datasets
    zfs list

    # Providing a pool name as argument alone will not display contained datasets.
    zfs list -r tank
    ```

    ```sh title="Create dataset"
    zfs create tank/dataset
    zfs list tank/dataset
    zfs rename tank zpool
    zfs remove zpool/dataset
    ```

    ```sh title="Configure dataset"
    # Enable compression
    zfs set compression=on tank/dataset

    # Disable sync
    zfs set sync=disabled tank/dataset
    
    # Set tag
    zfs set acme:disksource=vendorname  
    ```

#### Snapshots
:   
    [**Snapshots**](https://docs.oracle.com/cd/E19253-01/819-5461/gbciq/index.html) are read-only copies of file systems or volumes.
    They are created using **zfs snapshot** and appear as directories at the root of the file system under **.zfs/snapshot**.

    ```sh
    # Create a snapshot of the tank pool, creating the directory /tank/.zfs/snapshot/now
    zfs snapshot tank@now
    ```

    Snapshots are displayed using **zfs list**.

    ```sh
    zfs list -t snapshot
    ```

    ```sh title="Snapshot management"
    zfs snapshot tank@snapshot1
    zfs rollback tank@snapshot1
    zfs destroy tank@snapshot1
    ```

    ZFS datasets are automatically mounted when created, but this behavior can be managed and changed.
    
    ```sh
    zfs get mountpoint tank
    zfs set mountpoint=/tank tank
    ```

#### Migration
:   
    [Migrating pools](https://serverfault.com/questions/88638/moving-a-zfs-filesystem-from-one-pool-to-another) is apparently done using snapshots as well.
    A snapshot must first be taken before it is sent to the other pool using [**zfs send**](https://openzfs.github.io/openzfs-docs/man/8/zfs-send.8.html).

    ```sh
    # First take a snapshot
    zfs snapshot source-tank@moving

    # Send the snapshot
    zfs send source-tank@moving | zfs receive -F receive-tank/Destination

    # Use pv to monitor progress
    zfs send source-tank@moving | pv | zfs receive -F receive-tank/
    ```