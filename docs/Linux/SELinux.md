# SELinux

!!! info Resources

    - [SELinux (Arch Linux Wiki)](https://wiki.archlinux.org/title/SELinux)

SELinux implements **Mandatory Access Control (MAC)** in Linux, which is distinguished from traditional Linux access controls (file permission octets, the use of sudo, etc) which constitute **Discretionary Access Control (DAC)**.

#### Security context
:   
    SELinux [**security contexts**](https://wiki.archlinux.org/title/SELinux) define access controls and are most easily understood by the linguistic paradigm in the terms **subject**, **verb**, and **object**.

    ```
    user:role:type[:level]
    ``` 
    
    - **user** (subject) refers to the SELinux user identity, which can be associated with one or more roles that the SELinux user is allowed to use
    - **role** (object) refers to the SELinux role, which can be associated to one or more types that the SELinux user is allowed to access
    - **type** (verb) is associated with a process and defines what processes or domains the user can access


    ```sh title="SELinux extends existing utilities to handle contexts"
    ps auxZ # (1)
    ls -Z # (2)
    ```

    1. Display SELinux contexts for processes
    2. Display SELinux context for files

#### Labels
:   
    When mounting bind mount volumes to rootless containers, SELinux **labels** of the content [must be changed](https://www.redhat.com/sysadmin/user-namespaces-selinux-rootless-containers).


## Tasks

Enabling a Samba file share requires setting a specific SELinux context using `semanage`
```sh
semanage fcontext -a -t samba_share_t '/samba(/.*)?'
```
The context must then be restored
```sh
restorecon -vvFR /samba
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
