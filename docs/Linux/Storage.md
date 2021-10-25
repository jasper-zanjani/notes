# Storage


??? info "Resources"

    Unlike ZFS which has a lot of material in written and video form for potential users to learn from, BtrFS appears not to have much available.
    BtrFS does have an [official wiki](https://btrfs.wiki.kernel.org/index.php/Glossary), but written articles on FOSS blogs focus on operation from the command-line but don't do a good job of describing the taxonomy of concepts, aside from the [glossary](https://btrfs.wiki.kernel.org/index.php/Glossary).

    Users of ZFS, in contrast, have taken the trouble to create introductory material, including Ars Technica's [ZFS 101](https://arstechnica.com/information-technology/2020/05/zfs-101-understanding-zfs-storage-and-performance/) article, and many talks by enthusiasts like [Philip Paeps](https://youtu.be/Hjpqa_kjCOI).

    This might be because btrfs's concepts seem less well thought-out, or at least more poorly described.
    For example, the term [subvolume](#subvolume) is used in btrfs but the container for subvolumes is not "volume" but rather "top-level subvolume".

    Jim Salter from Ars Technica (who wrote the ZFS 101 article above) appears to have devoted some effort to fleshing out the topic:

    - [Examining btrfs, Linux's perpetually half-finished filesystem](https://arstechnica.com/gadgets/2021/09/examining-btrfs-linuxs-perpetually-half-finished-filesystem/)



    - [Install and configure Samba server](https://vitux.com/how-to-install-and-configure-samba-on-ubuntu/)
    - [Install Samba4 on RHEL 8 for File Sharing on Windows](https://www.tecmint.com/install-samba-on-rhel-8-for-file-sharing-on-windows/)
    - [FreeNAS 11.3 - How to Set Up Windows SMB Shares](https://youtu.be/mCfX4sqDmzs)
    - [BtrFS](http://rkeene.org/projects/info/wiki/btrfs)
    - [Creating and Destroying ZFS Storage Pools](https://docs.oracle.com/cd/E19253-01/819-5461/6n7ht6quu/index.html)
    - [Managing devices in ZFS storage pools](https://docs.oracle.com/cd/E19253-01/819-5461/gayrd/index.html)
    - [Getting started with btrfs for Linux](https://opensource.com/article/20/11/btrfs-linux)
    - [Understanding Linux filesystems: ext4 and beyond](https://opensource.com/article/18/4/ext4-filesystem)


#### TrueNAS

<figure><img src="/img/Logos/TrueNAS.svg"/></figure>

There is a middleware client named [**midclt**](https://www.truenas.com/community/threads/no-way-to-start-stop-services.87322/)

#### ZFS
:   
    **ZFS** is a true next-generation filesystem with a problematic license.
    **ZFS on Linux (ZOL)** is considered the ugly stepchild of the ZFS community despite the fact that the Linux implementation has the most features and the most community support.
    ZFS is too tightly bound to the operation of the kernel to operate in true userspace, and that is why each implementation is different for operating systems.

#### btrfs
:   
    **B-Tree Filesystem "butter fs"** is an open-source [CoW](#cow) filesystem that offers many of the same features as [ZFS](#zfs). It was founded by Chris Mason in 2007.
    By 2009, btrfs 1.0 was accepted into the mainline Linux kernel.
    
    Btrfs takes its name from the [b-tree](#btree) data structure which it uses to manage filesystem metadata.
    The [superblock](#superblock) holds pointers to the tree roots of the tree of tree roots and the chunk tree.
    
    Btrfs was adopted by [SUSE Enterprise Linux](#suse), but support was dropped by Red Hat in 2017.



## Tasks

#### Create virtual disks
:   
    Sparse files can be created with [**fallocate**](#fallocate) and then used as virtual disks by creating loopback devices with [**losetup**](#losetup)

    ```sh
    fallocate -l 100M /tmp/disk0
    losetup -f /tmp/disk0
    ```


### [Pool](#zpool) management

In ZFS documentation, zpools are conventionally named "tank".


Create a storage pool

=== "ZFS"

    ```sh
    zpool create tank raidz /dev/sd{a,b,c}
    ```

=== "BtrFS"

    Valid arguments to `--data`/`-d` include raid0, raid1, raid1c3, raid1c4, raid5, raid6, raid10, single, or dup.

    ```sh
    mkfs.btrfs --data raid0 /dev/sd{a,b,c}
    ```

Display pools and associated data

=== "ZFS"

    `status` and verbose `list` show different data in a similar tabular format

    ```sh
    zpool status tank
    ```

    ```sh
    zpool list -v
    ```

    By default, disks are identified by UUID. Use `-L` to display real paths (i.e. device names).

=== "BtrFS"

    ```sh
    ?
    ```

Destroy a storage pool

=== "ZFS"

    ```sh
    zpool destroy tank
    ```

=== "BtrFS"

    ```sh
    ?
    ```

Add a device

=== "ZFS"

    ```sh
    zpool add tank mirror /dev/sde /dev/sdf
    ```

=== "BtrFS"

    ```sh
    btrfs device add /dev/sde /data
    btrfs filesystem balance /data
    ```

Remove a device

=== "ZFS"

    ```sh
    # In ZFS a disk may only be removed from a mirrored pool
    zpool detach /dev/sdb
    ```

=== "BtrFS"

    ```sh
    btrfs device delete /dev/sdb /data
    btrfs filesystem balance /data
    ```

Replace a disk

=== "ZFS"

    ```sh
    zpool clear tank # Errors must be cleared first
    zpool replace tank /dev/sdb /dev/sdc
    ```

    This will begin an automatic **resilvering** process, which can be monitored in realtime.
    ```sh
    watch -n 0.1 zpool status tank
    ```

=== "BtrFS"

    ```sh
    btrfs device add /dev/sdc /data
    btrfs device delete /dev/sdb /data
    btrfs filesystem balance /data
    ```

Tuning

- Turn `atime` off
- Set `ashift=12`, which sets block size to 4096 bytes, also called **Advanced Layout (AL)**
- Disable deduplication, which can use excessive RAM and CPU. A dedup value of 1.00x in the output of `zpool` indicates no deduplication.
- Enable compression, which saves space and adds speed. It can be enabled or disabled on individual datasets.


#### [Dataset](#dataset) management

A **subvolume** in BtrFS is defined as an independently mountable POSIX filetree, and appears to be equivalent to the ZFS **dataset**.

=== ":material-plus: Create"

    ```sh
    zfs create tank/dataset
    ```

=== ":material-format-list-text: List"

    ```sh
    zfs list
    ```

    ```sh
    btrfs filesystem show
    ```

=== ":material-trash-can: Delete"

    ```sh
    zfs remove
    ```

=== ":material-rename-box: Rename"

    ```sh
    zfs rename tank $newname
    ```

    BtrFS appears to 

    ```sh
    btrfs filesystem label / $newname
    ```

Setting configuration options for a ZFS dataset

=== "Compression"

    ```sh
    zfs set compression=on zroot/dataset
    ```
=== "Sync"

    ```sh
    zfs set sync=disabled tank/share
    ```

=== "Tag"

    ```sh
    zfs set acme:disksource=vendorname
    ```

#### Snapshots

Create snapshot

=== "ZFS"

    ```sh
    zfs snapshot tank@snapshot1
    ```

=== "BtrFS"

    ```sh
    btrfs subvolume snapshot /data /data/snapshot1
    ```

Rollback a snapshot

=== "ZFS"

    ```sh
    zfs rollback tank@snapshot1
    ```

=== "BtrFS"

    ```sh
    ?
    ```

Delete a snapshot

=== "ZFS"

    ```sh
    zfs destroy tank@snapshot1
    ```

=== "BtrFS"

    ```sh
    btrfs subvolume delete /data/snapshot1
    ```

### File sharing

--8<-- "includes/Linux/Tasks/NFS.md"

--8<-- "includes/Linux/Tasks/Samba.md"

--8<-- "includes/Linux/Tasks/hdd-serial-numbers.md"


## Glossary

--8<-- "includes/storage-defs.md"

## Commands

--8<-- "includes/Linux/Commands/fallocate.md"

--8<-- "includes/Linux/Commands/hdparm.md"

--8<-- "includes/Linux/Commands/losetup.md"

--8<-- "includes/Linux/Commands/sfdisk.md"

--8<-- "includes/Linux/Commands/shred.md"

### btrfs

--8<-- "includes/Linux/Commands/btrfs.md"

--8<-- "includes/Linux/Commands/filefrag.md"

### LVM

--8<-- "includes/Linux/Commands/lvcreate.md"

--8<-- "includes/Linux/Commands/lvm.md"

--8<-- "includes/Linux/Commands/lvresize.md"

--8<-- "includes/Linux/Commands/lvs.md"

--8<-- "includes/Linux/Commands/pvcreate.md"

--8<-- "includes/Linux/Commands/pvremove.md"

--8<-- "includes/Linux/Commands/pvs.md"

--8<-- "includes/Linux/Commands/vgcreate.md"

--8<-- "includes/Linux/Commands/vgreduce.md"

--8<-- "includes/Linux/Commands/vgs.md"
