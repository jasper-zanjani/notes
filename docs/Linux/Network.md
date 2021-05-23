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

--8<-- "includes/Linux/Commands/nmap.md"

--8<-- "includes/Linux/Commands/tcpdump.md"

--8<-- "includes/Linux/Commands/wget.md"
