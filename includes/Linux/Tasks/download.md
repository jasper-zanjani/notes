#### Downloading files
:   
    === "wget"

        [**Wget**](#wget) defaults to file operations in a way that is more natural for downloading.

        ```sh
        wget $url
        ```

    === "curl"

        [**Curl**](#curl) depends on piping and defaults to STDOUT in a manner similar to **cat**.
        
        ```sh
        curl -O $url 
        ```