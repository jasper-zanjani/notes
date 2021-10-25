#### dar
:   
    Create a differential (or incremental) backup of {file}, using full.bak as reference
    ```sh
    dar -R /path/to/file -c diff1.bak -A full.bak
    ```
    Create a full backup of {file}
    ```sh
    dar -R /path/to/file -c full.bak
    ```
    Restore full.bak
    ```sh
    dar -x full.bak
    ```