# Network


### Web requests

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

### Commands

--8<-- "includes/lx/curl.md"

--8<-- "includes/lx/nmap.md"

--8<-- "includes/lx/tcpdump.md"

--8<-- "includes/lx/wget.md"
