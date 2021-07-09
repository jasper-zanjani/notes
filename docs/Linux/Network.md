# Network

**Curl** depends on piping and defaults to STDOUT in a manner similar to **cat**.
**Wget** defaults to file operations in a way that is more natural for downloading.

=== "wget"

    ```sh
    wget $url
    ```

=== "curl"

    ```sh
    curl -O $url 
    ```


--8<-- "includes/Linux/Commands/curl.md"

--8<-- "includes/Linux/Commands/netcat.md"

#### netplan [:material-link:](https://netplan.io/)

netplan is a utility for network configuration using YAML files

```yaml
network:
  version: 2
  renderer: networkd
  ethernets:
    eth01:
      dhcp4: yes
```

--8<-- "includes/Linux/Commands/nmap.md"

--8<-- "includes/Linux/Commands/tcpdump.md"

--8<-- "includes/Linux/Commands/wget.md"
