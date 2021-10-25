#### fallocate
:   
    Create a file of a given size with the `--length`/`-l` option

    === "1 gigabyte"

        ```sh
        fallocate -l 1GB $FILENAME # gigabyte
        ```
    
    === "1 gibibyte"
    
        ```sh
        fallocate -l 1G $FILENAME  # gibibyte
        ```
