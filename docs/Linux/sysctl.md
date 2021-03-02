View and configure kernel parameters at runtime

Display current hostname as known to the kernel
```sh
sysctl -n kernel.hostname
```



=== "Disable IPv6"

    ```sh
    sysctl -w net.ipv6.conf.all.disable_ipv6=1
    sysctl -w net.ipv6.conf.default.disable_ipv6=1
    ```

=== "Enable IPv6"

    ```sh
    sysctl -w net.ipv6.conf.all.disable_ipv6=0
    sysctl -w net.ipv6.conf.default.disable_ipv6=0
    ```

([src](https://www.techrepublic.com/article/how-to-disable-ipv6-on-linux/))