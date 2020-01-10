### lvcreate
Create a 20 gigabyte logical volume named "Marketing" from volume group {vg1}
```sh
lvcreate -L 20G vg1 -n Marketing
```
Create logical volume named {lv1} of size {500G} from volume group {vg1}
```sh
lvcreate-L 500G vg1 -n lv1
```

### `lvdisplay`
### `lvs`
View logical volumes
### `lvremove`
Remove logical volume {/dev/vg1/lv1}
```sh
lvremove /dev/vg1/lv1
```
### `lvresize`
Resize existent logical volume {Marketing} in volume group {vg1} to have an additional 10 gigabytes of space
```sh
lvresize -L +10G /dev/vg1/Marketing
```
### `pvcreate`
Create physical volumes from {/dev/sdb} and {/dev/sdc}
```sh
pvcreate /dev/sdb /dev/sdc
```
Create physical volumes from {partitions}
```sh
pvcreate*partitions
```
### `pvdisplay`
View physical volumes
```sh
pvdisplay | pvs
```
### `pvremove`
Remove physical volumes {/dev/sdb1}, {/dev/sdc1}, {/dev/sdd1}
```sh
pvremove /dev/sdb1 /dev/sdc1 /dev/sdd1
```
### `vgcreate`
Create volume group {vg1} from physical volumes {/dev/sdb} and {/dev/sdc}
```sh
vgcreate vg1 /dev/sdb /dev/sdc
```
Create a volume group {vg1} from device {/dev/sdb1}
```sh
vgcreatevg1 /dev/sdb1
```
### `vgdisplay`
### `vgs`
View volume groups
### `vgextend`
Add an additional drive {/dev/sdd} to existent volume group {vg1}
```sh
vgextend vg1 /dev/sdd
```
### `vgremove`
Remove volume group {/dev/vg1}
```sh
vgremove /dev/vg1
```
### `vgscan`
Build the LVM cache file