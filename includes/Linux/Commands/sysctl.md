#### sysctl
:   
    View and configure kernel parameters at runtime

    Kernel parameters can be delimited with dots or slashes
    ```sh
    sysctl kernel.hostname
    sysctl kernel/hostname
    ```

    The key name can be suppressed with `-n`
    ```sh
    sysctl -n kernel.hostname # --values
    ```

    Kernel parameters can be set with sysctl, or settings can be defined in **/etc/sysctl.conf** or other .conf files placed in **/etc/sysctl.d/** and loaded with:
    ```sh
    sysctl -p # --load
    ```

    === "Config"

        ```conf
        # /etc/sysctl.conf
        net.ipv4.ip_forward = 1
        ```
        ```sh
        sysctl -p
        ```

    === "Command-line"

        ```sh
        sysctl net.ipv4.ip_forward=1
        ```

    [Disable IPv6](https://www.techrepublic.com/article/how-to-disable-ipv6-on-linux/)
    ```sh
    sysctl -w net.ipv6.conf.all.disable_ipv6=1
    sysctl -w net.ipv6.conf.default.disable_ipv6=1
    ```