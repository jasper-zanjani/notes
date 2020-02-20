[blkid]:                                             #blkid                                      '```&#10;$ blkid&#10;```&#10;Display label and UUIDs of block devices.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 51'
[dumpe2fs]:                                          #dumpe2fs                                   '```&#10;$ dumpe2fs&#10;```&#10;Display filesystem metadata&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 51'
[e2label]:                                           #e2label                                    '```&#10;$ e2label&#10;```&#10;Change the label of a filesystem&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 53'
[fsck]:                                              #fsck                                       '```&#10;$ fsck&#10;```&#10;Find filesystem problems on unmounted filesystems&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 52'
[ioping]:                                            #ioping                                     '```&#10;$ ioping&#10;```&#10;Perform simple latency tests on a disk&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 288'
[iostat]:                                            #iostat                                     '```&#10;$ iostat&#10;```&#10;Display input/output statistics on devices, including partitions&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 48'
[mdadm]:                                             #mdadm                                      '```&#10;$ mdadm&#10;```&#10;Create a software RAID device&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 45'
[mkfs]:                                              #mkfs                                       '```&#10;$ mkfs&#10;```&#10;Create a filesystem on a partition; actually a frontend utility to other commands.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 48'
[mkswap]:                                            #mkswap                                     '```&#10;$ mkswap&#10;```&#10;Format a partition as a swap device&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 293'
[parted]:                                            #parted                                     '```&#10;$ parted&#10;```&#10;Interactive tool that can display and modify traditional and GUID partition tables and create a filesystem on a partition.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 46'
[partprobe]:                                         #partprobe                                  '```&#10;$ partprobe&#10;```&#10;Inform system of changes to partition table, typically used after making changes using `fdisk`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 289'
[resize2fs]:                                         #resize2fs                                  '```&#10;$ resize2fs&#10;```&#10;Resize a logical volume&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 52'
[swapoff]:                                           #swapoff                                    '```&#10;$ swapoff&#10;```&#10;Stop using a swap file or device&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 292'
[swapon]:                                            #swapon                                     '```&#10;$ swapon&#10;```&#10;Begin using a swap file or device&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 292'
[tune2fs]:                                           #tune2fs                                    '```&#10;$ tune2fs&#10;```&#10;Display or modify specific metadata for an ext filesystem.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 53'
[umount]:                                            #umount                                     '```&#10;$ umount&#10;```&#10;Unmount a filesystem&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 50'
[xfs_info]:                                          #xfs_info                                   '```&#10;$ xfs_info&#10;```&#10;Display the geometry of an XFS filesystem (cf. `dumpe2fs`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 44'
[xfs_metadump]:                                      #xfs_metadump                               '```&#10;$ xfs_metadump&#10;```&#10;Dump metadata from an unmounted XFS filesystem into a file for debugging purposes.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 44'

Commands  | Options
---       | ---
[`blkid`][blkid] |
[`dumpe2fs`][dumpe2fs] |
[`e2label`][e2label] |
[`fsck`][fsck] |
[`ioping`][ioping] |
[`iostat`][iostat] |
[`mdadm`][mdadm] |
[`mkfs`][mkfs] |
[`mkswap`][mkswap] |
[`parted`][parted] |
[`partprobe`][partprobe] |
[`resize2fs`][resize2fs] |
[`swapoff`][swapoff] |
[`swapon`][swapon] |
[`tune2fs`][tune2fs] |
[`umount`][umount] |
[`xfs_info`][xfs_info] |
[`xfs_metadump`][xfs_metadump] |

### `partx`
`partx` is a utility that provides information on drive partitions to the Linux kernel. [[12](sources.md)]
Display partition table of a drive
```bash
partx --show /dev/sda
```
Show details of only one partition of a drive
```bash
partx --show /dev/sda1
```
Specify a range of partitions on a drive
```bash
partx -o START, END --nr 10 /dev/sda
```
Add all partitions on a disk to the system
```bash
partx -a /dev/sda
```
Display length in sectors and human-readable size of a partition
```bash
partx -o SECTORS,SIZE /dev/sda1 /dev/sda
```
Remove the last partition
```bash
partx -d --nr -1:-1 /dev/sda
```
Disable headers
```bash
partx -o START -g --nr 5 /dev/sda
```
## Logical volume management
### lvcreate
Create a 20 gigabyte logical volume named "Marketing" from volume group {vg1}
```sh
lvcreate -L 20G vg1 -n Marketing
```
Create logical volume named `lv1` of size 500G from volume group `vg1`
```sh
lvcreate-L 500G vg1 -n lv1
```
### `lvresize`
Resize existent logical volume {Marketing} in volume group {vg1} to have an additional 10 gigabytes of space
```sh
lvresize -L +10G /dev/vg1/Marketing
```
