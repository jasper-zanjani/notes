# SELinux

When mounting bind mount volumes to rootless containers, SELinux **labels** of the content [must be changed <sup>:material-redhat:</sup>](https://www.redhat.com/sysadmin/user-namespaces-selinux-rootless-containers).


SELinux extends existing utilities to handle SELinux contexts

=== "ps"

    Display SELinux contexts for processes
    ```sh
    ps auxZ
    ```

=== "ls"

    Display SELinux context for files
    ```sh
    ls -Z
    ```

## Commands


--8<-- "includes/Linux/Commands/chcon.md"

--8<-- "includes/Linux/Commands/getenforce.md"

--8<-- "includes/Linux/Commands/getsebool.md"

--8<-- "includes/Linux/Commands/restorecon.md"

--8<-- "includes/Linux/Commands/semanage.md"

--8<-- "includes/Linux/Commands/sestatus.md"

--8<-- "includes/Linux/Commands/setenforce.md"

--8<-- "includes/Linux/Commands/setsebool.md"
