### ZFS management
:   

    ```sh
    # Create a storage pool, conventionally named "tank" in documentation
    zpool create tank raidz /dev/sd{a,b,c}
    
    # By default, disks are identified by UUID
    zpool status tank
    zpool list

    # Display real paths (i.e. block device names)
    zpool status tank -L 
    zpool list -v

    # Destroy pool
    zpool destroy tank
    ```

    ```sh title="Mirrored arrays"
    zpool add tank mirror sde sdf
    zpool detach sdb
    ```

    
    ```sh title="Hot spares"
    zpool add tank spare sdg
    zpool remove tank sdg # (1)
    ```

    1. The [**zpool remove**](https://openzfs.github.io/openzfs-docs/man/8/zpool-remove.8.html) command is used to remove hot spares, as well as cache and log devices.

    [Replacing](https://docs.oracle.com/cd/E19253-01/819-5461/gazgd/index.html) a used disk with one that is unused uses **zpool replace**, initiating the [**resilvering**](#resilvering) process.
    
    ```sh
    zpool replace tank sdb sdc
    ```
    
    Ongoing resilvers can be cancelled using **zpool detach**:
    ```sh
    zpool detach tank sdc
    ```

    If a disk has gone bad, it must first be taken offline (apparently requiring its UUID) before physically replacing it.

    ```sh title="Replace disk"
    zpool clear tank
    zpool offline $UUID
    zpool replace tank sdb sdc
    watch zpool status tank
    ```


    A [**dataset**](#dataset) in ZFS is equivalent to the [btrfs](#btrfs) [**subvolume**](#subvolume), defined as an independently mountable POSIX filetree.

    ```sh title="Create dataset"
    zfs create tank/dataset
    zfs list
    zfs rename tank zpool
    zfs remove zpool/dataset
    ```

    ```sh title="Configure dataset"
    zfs set compression=on tank/dataset # Enable compression
    zfs set sync=disabled tank/dataset  # Disable sync
    zfs set acme:disksource=vendorname  # Set tag
    ```

    ```sh title="Snapshot management"
    zfs snapshot tank@snapshot1
    zfs rollback tank@snapshot1
    zfs destroy tank@snapshot1
    ```
