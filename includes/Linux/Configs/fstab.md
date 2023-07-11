**/etc/fstab** is a whitespace-delimited config file that contains descriptive information about the filesystems the system can mount.

Typical fstab entries have six columns, delimited by whitespace:

- **fs\_spec** describes the block special device. It can appear in any number of ways depending on the nature of the device
- **fs\_file** describes the mount point
- **fs\_vfstype** describes the type of filesystem
- **fs\_mntops** describes mount options
- **fs\_freq** is used by **dump** to determine which filesystems need to be dumped
- **fs\_passno** is used by **fsck** to determine the order in which filesystem checks are done at boot time

```sh
# NFS
nas:/export/storage     /mnt/nfs_storage        nfs     defaults,_netdev 0 0

# SMB
//nas/storage           /mnt/smb_storage        cifs    guest,uid=1000,iocharset=utf-8  0 0

# VDO
/dev/mapper/storage     /mnt/vdo_storage        xfs     _netdev,x-systemd.device-timeout=0,x-systemd.requires=vdo.service 0 0

# Stratis
/stratis/pool/storage     /mnt/stratis_storage  xfs     defaults,x-systemd.requires=stratisd.service 0 0

# btrfs
UUID=5530f7df-65b7-4fd5-8757-0e69aad14f75 /     btrfs   subvol=/@,defaults,noatime,autodefrag,compress=zstd,discard=async,ssd 0 0
UUID=5530f7df-65b7-4fd5-8757-0e69aad14f75 /home btrfs   subvol=/@home,defaults,noatime,autodefrag,compress=zstd,discard=async,ssd 0 0
```