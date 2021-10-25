#### dd
:   
    Implement a simple CPU benchmark by writing 1 GB of zeroes and piping it to md5sum
    ```sh
    dd if=/dev/zero bs=1M count=1024 | md5sum
    ```
