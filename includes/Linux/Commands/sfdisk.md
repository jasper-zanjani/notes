#### sfdisk
:   
    Script-based partition table editor, similar to [**fdisk**](#fdisk) and [**gdisk**](#gdisk), which can be run interactively. 
    It does not interface with GPT format, neither is it designed for large partitions.

    ```sh
    # Display size of a partition or disk
    sfdisk -s $PARTITION
    sfdisk -s $DEVICE

    # Apply consistency checks to partition or disk
    sfdisk -V $PARTITION
    sfdisk --verify $DEVICE

    # Create a partition
    sfdisk $DEVICE
    ```