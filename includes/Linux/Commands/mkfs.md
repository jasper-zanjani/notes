#### mkfs
:   
    Create an ext4 filesystem on {partition}
    ```sh
    mkfs -t ext4 partition
    ```

    Create an XFS filesystem
    ```sh
    mkfs.xfs -K /dev/mapper/web_storage # (1)
    ```

    1. **-K** prevents discarding of blocks at mkfs time.