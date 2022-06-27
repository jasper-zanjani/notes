#### NFS
:   
    NFS is a distributed filesystem based on the RPC protocol that provides transparent access to remote disks.

    Modern NFS deployments in the wild are usually versions 3 or 4:

    - V4 has superior performance, requires only the additional **rpc.mountd** service, and **TCP port 2049** to be open
    - V3 requires additional services (**rpcbind**, **lockd**, **rpc.statd**) and many firewall ports

    NFS shares are enabled using the **/etc/exports** file.
    ``` title="/etc/exports"
    /export/web_data1 *(ro,sync)
    /export/web_data2 127.0.0.1(rw,sync,no_root_squash)
    ```

    Once exports are defined, the NFS server can be started
    ```sh
    systemctl enable --now nfs-server.service
    ```

    Exports on localhost can be displayed using **showmount**
    ```sh
    showmount -e
    ```

    Shares can be mounted in /etc/fstab using the following syntax:
    ```
    127.0.0.1:/export/web_data1 /mnt/nfs_web_data1 nfs defaults,_netdev 0 0
    127.0.0.1:/export/web_data2 /mnt/nfs_web_data2 nfs defaults,_netdev 0 0
    ```

    Better still is using [autofs](#autofs).

    ??? info "Resources"

        - [:material-youtube: How to Share Files Using NFS: Linux Server Training 101](https://youtu.be/c3dL0ULEH-s)