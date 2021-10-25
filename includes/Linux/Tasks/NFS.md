#### NFS
:   
    NFS is a distributed filesystem based on the RPC protocol that provides transparent access to remote disks.

    Traditionally, NFS shares are enabled using the **/etc/exports** file.

    ```
    /public *(ro,sync)
    ```

    The **rpcbind** service had to be enabled before starting the **nfs** service, but this service was no longer used as of NFS 4.0.

    ```sh
    service rpcbind enable
    service nfs start
    ```

    Then the **showmount** command is used to confirm local shares

    ```sh
    showmount -e # =>
    # Export list for truenas.local:
    # /public *
    ```

    On TrueNAS, permissions need to be changed to allow writing.

    If sharing from a ZFS dataset, turn off sync to improve performance

    ```sh
    zfs set sync=disabled tank/share
    ```

    Once the NFS share is created, it is consumed on the client by mounting it to the filesystem.
    ```sh hl_lines="2"
    mkdir -p /mnt/share
    mount nas:/share /mnt/share
    ```

    ??? info "Resources"

        - [:material-youtube: How to Share Files Using NFS: Linux Server Training 101](https://youtu.be/c3dL0ULEH-s)