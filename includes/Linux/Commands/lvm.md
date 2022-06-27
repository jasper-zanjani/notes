#### lvm
:   
    ```sh
    lvm version
    ```

#### lvresize
:   
    Resize existent logical volume **Marketing** in volume group **vg1** to have an additional 10 gigabytes of space
    ```sh
    lvresize -L +10G /dev/vg1/Marketing
    ```
    
#### pvcreate
:   
    ```sh
    pvcreate /dev/sd{a,b,c}
    ```
    
#### lvresize
:   
    Resize existent logical volume **Marketing** in volume group **vg1** to have an additional 10 gigabytes of space
    ```sh
    lvresize -L +10G /dev/vg1/Marketing
    ```

    It is possible to use LVM to format the storage media when installing CentOS or RHEL on a virtual machine, even if there is only a single disk.
    This will result in a swap partition being created as a small logical volume.
    This can be removed:
    ```sh
    swapoff cs/swap
    lvremove cs/swap
    ```
    Then the remaining logical volume mounted to root can be expanded:
    ```sh
    lvresize -l 100%VG cs/root
    ```

#### pvcreate
:   
    ```sh
    pvcreate /dev/loop0
    ```
    