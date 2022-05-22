=== ":material-arch: Arch"

    ```sh
    pacman -S postgresql
    su - postgres -c 'initdb --pgdata /var/lib/postgres/data' # (1)
    systemctl enable postgresql --now
    ```
    
    1. On Arch, this step appears to be necessary before the postgresql service can be enabled.
    **initdb** requires a directory to be explicitly specified using **--pgdata** or alternatively the **PGDATA** environment variable.

=== ":material-redhat: Red Hat"

    ```sh
    dnf install libpq-devel mariadb-devel postgresql postgresql-server
    postgresql-setup --initdb # (1)
    systemctl enable postgresql --now
    ```

    1. This command facilitates initialization of the database cluster, which defaults to **/var/lib/pgsql/data**, similar to using **initdb**.

=== ":material-ubuntu: Ubuntu"

    ```sh
    apt install libpq-dev
    ```
