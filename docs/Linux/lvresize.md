Resize existent logical volume {Marketing} in volume group {vg1} to have an additional 10 gigabytes of space
```sh
lvresize -L +10G /dev/vg1/Marketing
```