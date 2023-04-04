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


## Tasks

#### Create virtual disks
:   
    ```sh
    fallocate -l 100M /tmp/disk0    # Create sparse file
    losetup -f /tmp/disk0           # Create loopback device
    ```

--8<--
includes/Linux/Tasks/filesystems.md

includes/Linux/Tasks/hdd-serial-numbers.md

includes/Linux/Tasks/smb.md

includes/Linux/Tasks/nfs.md

includes/Linux/Tasks/autofs.md

includes/Linux/Tasks/lvm.md

includes/Linux/Tasks/vdo.md

includes/Linux/Tasks/stratis.md

includes/Linux/Tasks/zfs.md
--8<--

## Glossary

--8<-- "includes/storage-defs.md"

## Commands

--8<--
includes/Linux/Commands/btrfs.md

includes/Linux/Commands/fallocate.md

includes/Linux/Commands/filefrag.md

includes/Linux/Commands/hdparm.md

includes/Linux/Commands/losetup.md

includes/Linux/Commands/lsblk.md

includes/Linux/Commands/sfdisk.md

includes/Linux/Commands/shred.md
--8<--


### LVM

--8<--
includes/Linux/Commands/lvm.md
--8<--
