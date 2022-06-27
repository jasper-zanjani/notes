#### fstab
:   
    **/etc/fstab** is a whitespace-delimited config file that contains descriptive information about the filesystems the system can mount.

    Typical fstab entries have six columns, delimited by whitespace:

    - **fs\_spec** describes the block special device. It can appear in any number of ways depending on the nature of the device
    - **fs\_file** describes the mount point
    - **fs\_vfstype** describes the type of filesystem
    - **fs\_mntops** describes mount options
    - **fs\_freq** is used by **dump** to determine which filesystems need to be dumped
    - **fs\_passno** is used by **fsck** to determine the order in which filesystem checks are done at boot time

    