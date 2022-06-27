# SELinux

!!! info Resources

    - [SELinux (Arch Linux Wiki)](https://wiki.archlinux.org/title/SELinux)

SELinux implements **Mandatory Access Control (MAC)** in Linux, which is distinguished from traditional Linux access controls (file permission octets, the use of sudo, etc) which constitute **Discretionary Access Control (DAC)**.

SELinux's config is at **/etc/selinux/config**
```ini title="Example config"
# This file controls the state of SELinux on the system.
# SELINUX= can take one of these three values:
#     enforcing - SELinux security policy is enforced.
#     permissive - SELinux prints warnings instead of enforcing.
#     disabled - No SELinux policy is loaded.
SELINUX=enforcing
# SELINUXTYPE= can take one of these three values:
#     targeted - Targeted processes are protected,
#     minimum - Modification of targeted policy. Only selected processes are protected.
#     mls - Multi Level Security protection.
SELINUXTYPE=targeted
```

#### Contexts
:   
    SELinux [**security contexts**](https://wiki.archlinux.org/title/SELinux) define access controls and are also referred to as "labels".
    All system objects have such contexts associated with them, stored in the extended attributes of the filesystem.

    Contexts are compared to **subject**, **verb**, and **object** in English sentences and have the following structure:
    ```sh
    user_u:role_r:type_t:level
    ``` 

    The **user** or user identity can be associated with one or more roles. User identities are suffixed with **\_u**, and there a eight such identities builtin. 
    
    - By default, all non-root users are mapped to **unconfined\_u** as is root itself, which means they operate with unlimited privileges. 
    - Users labeled with **user\_u** cannot run su or sudo or programs in their home directories.
    
    The **role** is an attribute of the RBAC security model that classifies who is allowed to access what (domains, types). It can be associated to one or more types and is suffixed with **\_r**.
    
    The **type** (for file contexts) or **domain** (for process contexts) defines what processes or domains the user can access. Types are suffixed with **\_t**.

    - Certain files have their own types, like **passwd\_file\_t** which is associated with /etc/passwd.
    - Builtin and user-created file contexts are stored in the **file\_contexts** and **file\_contexts.local** files under **/etc/selinux/targeted/contexts/files/**.
    
    A **level** is an attribute of Multi-Level Security and Multi-Category Security.

    SELinux extends existing utilities to handle contexts with the **-Z** flag:
    ```sh
    ps auxZ
    ls -Z
    id -Z
    ```

#### Booleans
:   
    In SELinux, **booleans**{: #booleans} refers to optional settings that can be turned on and off.

## Tasks

#### Samba share
:   
    Enabling a Samba file share requires setting a specific SELinux context using **semanage**
    ```sh
    semanage fcontext -a -t samba_share_t '/samba(/.*)?'
    ```

    The context must then be restored
    ```sh
    restorecon -vvFR /samba
    ```

#### Troubleshooting Apache
:   
    In this scenario, an Apache httpd daemon fails to start due to SELinux.

    SELinux provides recommended commands to resolve the issue in the audit log at **/var/log/messages**:
    ```sh
    grep httpd /var/log/messages | less
    ```

    Generate and install a new **policy module** from the logs
    ```sh
    ausearch -c httpd --raw | audit2allow -M my-httpd
    semodule -i my-httpd
    ```

#### Apache home directories
:   
    A feature of Apache is that users can host personal websites from the directory named **public\_html** in their home directories.
    When Apache policies are in effect, this directory is automatically given the **http\_user\_content\_t** tag, which will allow the httpd daemon to host the website at the path **/~user** where "user" is the name of the user.
    ```sh
    curl localhost/~user/index.html
    ```

    However, without a specific boolean enabled, the files will not be accessible:
    ```sh
    setsebool -P httpd_enable_homedirs 1
    ```

#### Apache port
:   
    Default Apache settings appear in the main config file located at **/etc/httpd/conf/httpd.conf**.
    
    For example, the default directory served by Apache can be changed by setting a new value for the **DocumentRoot** directive.
    ```ini title="/etc/httpd/conf/httpd.conf"
    DocumentRoot "/web"
    # ...
    <Directory "/web">
    ```

    Create example content
    ```sh
    echo "Hello, World!" > /web/index.html
    ```
    The context for the content must be set.
    ```sh
    # Set context manually
    chcon -R /web -t http_content_t

    # Alternatively, set policy and restore the contexts
    semanage -a -t httpd_sys_content_t '/web(/.*)?'
    restorecon -R /web
    ```

    The default port can also be changed with the **Listen** directive.
    ```ini title="/etc/httpd/conf/httpd.conf"
    Listen 1000
    ```

    Now Apache will attempt to serve /web from port 1000, however while SELinux is enforcing policy this port will not be accessible to the daemon, and in fact Apache will exit with an error code.

    These errors can be inspected in a variety of ways.
    ```sh
    journalctl -xe
    ausearch -m AVC -ts recent

    # Find SELinux message IDs, which provide remediation tips:
    grep sealert /var/log/messages
    sealert -l $MESSAGE_ID
    ```

    ```sh title="Add port context"
    semanage port -a -t http_port_t -p tcp 1000
    ```

    Now starting httpd succeeds, and we can confirm that port 1000 is open:
    ```sh
    ss -nlt
    ```

## Commands

SELinux commands are separated into get/set varieties similar to PowerShell cmdlets:

| get                       | set                       | object                |
| ------------------------- | ------------------------- | --------------------- |
| [getenforce](#getenforce) | [setenforce](#setenforce) | Operating mode        |
| [getsebool](#getsebool)   | [setsebool](#setsebool)   | [Booleans](#booleans) |

Similarly,

| restore                   | change          | object                |
| ------------------------- | --------------- | --------------------- |
| [restorecon](#restorecon) | [chcon](#chcon) | [Contexts](#contexts) |

#### audit2allow
:   
    ```sh title="Generate policy module from logs of denied operations"
    ausearch -c httpd --raw | audit2allow -M my-httpd
    ```

#### ausearch
:   
    Display events in a date range
    ```sh
    ausearch --start $STARTDATE --end $ENDDATE
    ```

    Search events for today for logins of UID 500
    ```sh
    ausearch --start today --loginuid 500
    ```

    Search for events associated with an executable.
    ```sh
    ausearch -c httpd --raw
    ```

    ```sh title="Display recent (10 minutes) events"
    ausearch -m AVC -ts recent
    ```

#### chcon
:   
    Change context of a file to be hosted via httpd
    ```sh
    chcon system_u:object_r:httpd_sys_content_t:s0 index.html
    chcon -t httpd_sys_content_t index.html # (1)
    ```

    1. Change only the **type** portion of the context.


#### getenforce
:   
    **getenforce** displays the operating **mode** of SELinux, which can be one of three values:

    - enforcing
    - permissive
    - disabled


#### getsebool
:   
    ```sh title="Display all booleans"
    getsebool -a # (1)
    ```

    1. A more descriptive listing of the booleans can be displayed with [**semanage**](#semanage)
    ```sh
    semanage bool -l
    ```


#### restorecon
:   
    Restore security context policy
    ```sh
    restorecon -R /web
    ```

#### seinfo
:   
    ```sh title="List users"
    seinfo -u
    ```

#### semanage
:   
    semanage is used to configure certain elements of SELinux policy without requiring modification to or recompilation from policy sources.

    ```sh title="File contexts"
    semanage fcontext -l
    semanage fcontext -a -t httpd_sys_content_t /web 
    ```

    ```sh title="Port contexts"
    semanage port -l
    semanage port -a -t http_port_t -p tcp 1000
    ```

    ```sh title="Booleans"
    semanage bool -l
    ```

    Examine the mapping between Linux login names and SELinux users.
    ```sh
    semanage login -l
    ```

#### semodule
:   
    ```sh title="Install a policy module"
    semodule -i my-httpd.pp
    ```

#### sestatus
:   
    ```sh
    sestatus
    ```

#### setenforce
:   
    ```sh
    setenforce 0 # Permissive
    setenforce 1 # Enforcing
    ```

#### setsebool
:   
    ```sh
    # Allow SELinux to work with Samba (-P makes the change persistent)
    setsebool -P samba_export_all_ro 1

    # Allow httpd to serve HTML from home directories
    setsebool -P httpd_enable_homedirs 1

    # Prevent runtime changes to SELinux mode
    setsebool -P secure_mode_policyload 1
    ```