#### lvcreate
:   
    Create a 20 gigabyte logical volume named "Marketing" from volume group {vg1}
    ```sh
    lvcreate -L 20G vg1 -n Marketing
    ```
    Create logical volume named `lv1` of size 500G from volume group `vg1`
    ```sh
    lvcreate -L 500G vg1 -n lv1
    ```