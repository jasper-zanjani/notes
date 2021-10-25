#### sysbench
:   
    Benchmark CPU by calculating prime numbers [YouTube](https://youtu.be/KkMWXVx-Ul8 "How to Benchmark your Linux system, Hak5 1502.1")
    ```sh
    sysbench --test=cpu --cpu-max-prime=20000 run
    ```
    File I/O benchmarking [YouTube](https://youtu.be/KkMWXVx-Ul8 "How to Benchmark your Linux system, Hak5 1502.1")
    ```sh
    sysbench --test=fileio --file-total-size=10G --file-test-mode=rndrw --init-rng=on --max-time=300 --max-requests=0 run
    ```