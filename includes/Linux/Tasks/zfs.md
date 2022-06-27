### ZFS
:   
    ```sh title="Create a storage pool"
    zpool create tank raidz /dev/sd{a,b,c} # (1)
    ```

    1. In ZFS documentation, zpools are conventionally named "tank".

    ```sh title="Display pools and associated data"
    zpool status tank -L # (1)
    zpool list -v
    ```

    1. By default, disks are identified by UUID. Use **-L** to display real paths (i.e. block device names).


    ```sh title="Destroy pool"
    zpool destroy tank
    ```

    ```sh title="Add device"
    zpool add tank mirror /dev/sde /dev/sdf
    ```

    ```sh title="Remove device"
    zpool detach /dev/sdb # (1)
    ```

    1. In ZFS a disk may only be removed from a mirrored pool

    ```sh title="Replace device"
    zpool clear tank # Errors must be cleared first
    zpool replace tank /dev/sdb /dev/sdc # (1)
    ```

    1. This will begin an automatic **resilvering** process, which can be monitored in realtime.
    ```sh
    watch zpool status tank
    ```


#### [Dataset](#dataset) management
:   
    ??? info "Terminology"
    
        A **subvolume** in BtrFS is defined as an independently mountable POSIX filetree, and appears to be equivalent to the ZFS **dataset**.

    ```sh title="Create dataset"
    zfs create tank/dataset # Create
    zfs list                # Display
    zfs remove tank/dataset # Delete
    ```

    ```sh title="Rename dataset"
    zfs rename tank zpool
    ```

    ```sh title="Configure dataset"
    zfs set compression=on tank/dataset # Enable compression
    zfs set sync=disabled tank/dataset  # Disable sync
    zfs set acme:disksource=vendorname  # Set tag
    ```

#### Snapshot management
:   
    ```sh title="Create snapshot"
    zfs snapshot tank@snapshot1
    ```

    ```sh title="Roll back snapshot"
    zfs rollback tank@snapshot1
    ```

    ```sh title="Delete snapshot"
    zfs destroy tank@snapshot1
    ```
