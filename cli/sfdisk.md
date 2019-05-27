# sfdisk
Script-based partition table editor, similar to __[fdisk](fdisk.md)__ and __[gdisk](gdisk.md)__, which can be run interactively. It does not interface with GPT format, neither is it designed for large partitions.

#### List partitions on all devices
```sh
sfdisk -l
```
<hr>

```sh
sfdisk --list
```

#### List partitions on {device}
```sh
sfdisk -l device
```
<hr>

```sh
sfdisk --list device
```

#### Display size of {partition} or {device}
```sh
sfdisk -s partition
sfdisk -s device
```
This command produces the size of {partition} (i.e. `/dev/sda1`) or even {device} (`/dev/sda`) in blocks

#### Apply consistency checks to {partition} or {device}
```sh
sfdisk -V partition
sfdisk -V device
```
<hr>

```sh
sfdisk --verify partition
sfdisk --verify device
```


#### Create a partition
```sh
sfdisk device
```

#### Save sectors changed
```sh
sfdisk /dev/hdd -O hdd-partition-sectors.save
```
This command will allow recovery using the following command

#### Recovery
```sh
sfdisk /dev/hdd -I hdd-partition-sectors.save
```




## Sources
  - [ComputerHope](https://www.computerhope.com/unix/sfdisk.htm)
