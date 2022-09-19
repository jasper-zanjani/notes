#### VDO
:   
    **Virtual disk optimizer (VDO)** is a kernel module introduced in RHEL 7.5 that provides data deduplication and compression on block devices.

    The physical storage of a VDO volume is divided into a number of **slabs**, which are contiguous regions of the physical space. 
    All slabs for a given volume have the same size, which can be any power of 2 multiple of 128 MB up to 32 GB (2 GB by default).
    The maximum number of slabs is 8,192.
    The maximum physical storage of the VDO is provided to the user on creation.

    Like LVM volumes, VDO volumes appear under **/dev/mapper**

    VDO appears not to be installed by default, but it is available in the BaseOS repo.
    ```sh
    dnf install vdo
    systemctl enable --now vdo
    ```

    ```sh title="Create a VDO volume"
    vdo create --name=web_storage --device=/dev/xvdb --vdoLogicalSize=10G
    vdostats --human-readable
    mkfs.xfs -K /dev/mapper/web_storage
    udevadm settle
    ```

    The fstab file requires a variety of options
    ```sh
    /dev/mapper/web_storage /mnt/web_storage xfs _netdev,x-systemd.device-timeout=0,x-systemd.requires=vdo.service 0 0
    ```