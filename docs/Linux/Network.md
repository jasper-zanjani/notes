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

--8<-- "includes/Linux/curl.md"

--8<-- "includes/Linux/nmap.md"

--8<-- "includes/Linux/tcpdump.md"

--8<-- "includes/Linux/wget.md"
