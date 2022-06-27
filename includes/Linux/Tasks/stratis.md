#### Stratis
:   
    Stratis is an open-source managed pooled storage solution in the vein of ZFS or btrfs.

    Stratis block devices can be disks, partitions, LUKS-encrypted volumes, LVM logical volumes, or DM multipath devices.
    Stratis pools are mounted under **/stratis** and, like other pooled storage systems, support multiple filesystems.
    Stratis file systems are thinly provisioned and formatted with **xfs**, although vanilla xfs utilities cannot be used on Stratis file systems.

    ```sh
    dnf -y install stratisd stratis-cli
    systemctl enable --now stratisd
    ```
    ```sh title="Create a pool"
    stratis pool create pool /dev/sda /dev/sdb /dev/sdc # (1)
    ```

    1. An error about the devices being "owned" can be resolved by wiping it.
    ```sh
    wipefs -a /dev/sda
    ```

    ```sh title="Display block devices managed by Stratis"
    stratis blockdev # (1)
    ```

    1. This command is equivalent to **pvs** in LVM.

    ```sh title="Create filesystem"
    stratis fs create pool files
    ```

    ```sh title="Confirm"
    stratis fs
    ```

    ```fstab title="/etc/fstab"
    /stratis/pool/files /mnt/stratisfs xfs defaults,x-systemd.requires=stratisd.service 0 0
    ```

    ```sh title="Expand pool"
    stratis pool add-data pool /dev/sdb
    ```

    ```sh title="Save snapshot"
    stratis fs snapshot pool files files-snapshot
    ```

    ```sh title="Restore from snapshot"
    stratis fs rename files files-orig
    stratis fs rename files-snapshot files
    umount /mnt/files; mount /mnt/files
    ```

