Adjust various ...
Run `fsck` on {/dev/sdb1} on every boot
```sh
tune2fs -c 1 /dev/sdb1
```
Run `fsck` on {/dev/sda1} at intervals of 60 mounts or 6 months
```sh
tune2fs -c 60 -i 6m /dev/sda1
```
Enable journaling on ext2 partition {/dev/sdc1}
```sh
tune2fs -j /dev/sdc1
```
Assign label "Sales" to logical volume {/dev/vg1/Sales}
```sh
tune2fs -L Sales /dev/vg1/Sales
```