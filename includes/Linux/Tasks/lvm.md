#### LVM volume
:   
    ```sh
    pvcreate /dev/vd{b,c,d}
    vgcreate group /dev/vd{b,c,d}
    lvcreate -l 100%FREE -n volume group
    ```