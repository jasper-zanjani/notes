**partx**{: #partx }
:   Displays information on drive partitions to the Linux kernel. 
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