### btrfs
:   
    ```sh title="Create a storage pool"
    mkfs.btrfs --data raid0 /dev/sd{a,b,c} # (1)
    ```

    1. Valid arguments to **-d**/**--data** include raid0, raid1, raid1c3, raid1c4, raid5, raid6, raid10, single, or dup.

    ```sh title="Add device"
    btrfs device add /dev/sde /data
    btrfs filesystem balance /data
    ```

    ```sh title="Remove device"
    btrfs device delete /dev/sdb /data
    btrfs filesystem balance /data
    ```

    ```sh title="Replace device"
    btrfs device add /dev/sdc /data
    btrfs device delete /dev/sdb /data
    btrfs filesystem balance /data
    ```

#### Filesystem management
:   
    Filesystems in btrfs are equivalent to ZFS datasets except that filesystems can be divided into "subvolumes".
    ```sh title="Display subvolumes"
    btrfs subvolume list / # (1)
    ```
    
    1. Subvolume names begin with **@**.

    Subvolumes can be mounted to separate mountpoints, even though they specify the same filesystem, using the **subvol** directive.
    
    ```fstab
    UUID=5530f7df-65b7-4fd5-8757-0e69aad14f75 /              btrfs   subvol=/@,defaults,noatime,autodefrag,compress=zstd,discard=async,ssd 0 0
    UUID=5530f7df-65b7-4fd5-8757-0e69aad14f75 /home          btrfs   subvol=/@home,defaults,noatime,autodefrag,compress=zstd,discard=async,ssd 0 0
    ```

    ```sh title="Rename filesystem"
    btrfs filesystem label / tank # (1)
    ```

    1. 
    ```sh title="Verify"
    btrfs filesystem show
    blkid
    ```

    ```sh title="Measure free space"
    btrfs filesystem df /
    ```

#### Snapshots
:   
    In btrfs, you can take snapshots of btrfs subvolumes only, and the snapshots are subvolumes themselves.
    In fact, by [definition](https://btrfs.wiki.kernel.org/index.php/SysadminGuide#Snapshots) a btrfs snapshot is simply a subvolume that shares its data and metadata with some other subvolume using btrfs's CoW capabilities.
    ```sh
    btrfs subvolume list /
    ```

    These are stored in the **.snapshots** directory at the root of the subvolume as numbered subdirectories.
    Restoring from these snapshots can be done with simple file tools like **rsync**.
    ```sh
    rsync -avz /.snapshots/141/snapshot/$PATH $PATH
    ```
    
    Snapshots are read-only by default, but can also be writable.
    Snapshots can be investigated:
    ```sh
    btrfs subvolume show /.snapshots/141/snapshot
    ```

    ```sh title="Delete snapshot"
    btrfs subvolume delete /.snapshots/141/snapshot
    ```
