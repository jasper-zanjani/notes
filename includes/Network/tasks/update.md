!!! cisco "Update Cisco OS"

    ``` hl_lines="1 4"
    SW1#copy tftp flash
    Address or name of remote host []? 10.0.0.10
    Source filename []? file.bin
    SW1(config)#boot system flash:/file.bin
    ```