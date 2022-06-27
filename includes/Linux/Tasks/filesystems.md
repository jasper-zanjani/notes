#### Formatting filesystems
:   
    ```sh
    mkfs.ext4 /dev/sda1
    mkfs.xfs /dev/sda2
    ```

    Check filesystems
    ```sh
    fsck.ext4 /dev/sda1
    xfs_repair /dev/sda2
    ```