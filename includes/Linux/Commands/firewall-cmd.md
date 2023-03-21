#### firewall-cmd
:   
    Frontend to [Netfilter](#netfilter) in Red Hat distributions.
    
    ```sh
    firewall-cmd --state # "running"
    ```

    Firewalld has a runtime configuration and a saved, persistent configuration.
    Only the runtime configuration will be consulted for any command, unless the persistent configuration is specified with **--permanent**.

    The runtime configuration can be saved with this command, which obviates the need to execute every change twice.
    ```sh
    firewall-cmd --runtime-to-permanent
    ```

    Alternatively, the persistent configuration can be loaded into memory:
    ```sh
    firewall-cmd --reload
    ```

    ```sh title="Display firewall rules"
    firewall-cmd --list-all --permanent
    ```

    Firewalld uses **zones** to define the level of trust for network connections.
    A connection can only be part of one zone, but a zone can be used for many network connections.
    Builtin zones have XML-format configs found in **/usr/lib/firewalld/zones**.
    ```sh
    firewall-cmd --get-active-zones     # Display active zones along with interfaces
    firewall-cmd --info-zone=public     # Inspect zone
    firewall-cmd --new-zone=testlab     # Create new zone
    ```

    Firewalld rules are generally managed through builtin **services**.
    These bundle network settings together for well-known applications like SSH, etc.
    Builtin services are also XML-format configs found in **/usr/lib/firewalld/services**.
    
    ```sh title="Services"
    firewall-cmd --list-services
    firewall-cmd --add-service=http
    firewall-cmd --remove-service=http
    ```

    Firewalld's config file is at **/etc/firewalld/firewalld.conf**
    ```ini title="/etc/firewalld/firewalld.conf"
    AllowZoneDrifting=no
    ```

    Since RHEL 8, firewalld's backend has been changed to nftables.
    ```ini title="/etc/firewalld/firewalld.conf"
    FirewallBackend=nftables
    ```