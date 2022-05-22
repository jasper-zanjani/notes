#### zfs
:   
    [Allow an unprivileged user to create snapshots of his home directory only](https://www.youtube.com/watch?v=qXOZmDoy2Co&list=WL&index=11&t=775s)
    ```sh
    zfs allow -u lucas snapshot,rollback zroot/usr/home/lucas
    ```
