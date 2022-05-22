#### sysctl
:   
    View and configure **kernel parameters** at runtime.
    Kernel parameters are [tunable values](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/managing_monitoring_and_updating_the_kernel/configuring-kernel-parameters-at-runtime_managing-monitoring-and-updating-the-kernel) that can be adjusted during runtime.

    Kernel parameters can be delimited with dots or slashes
    ```sh
    sysctl kernel.hostname
    sysctl kernel/hostname
    ```

    The key name can be suppressed with `-n`
    ```sh
    sysctl -n kernel.hostname
    ```

    Kernel parameters can be set with sysctl, or settings can be defined in **/etc/sysctl.conf** or other 
    .conf files placed in **/etc/sysctl.d/** and loaded with `sysctl -p` or `sysctl --load`:
    
    ```conf title="/etc/sysctl.conf"
    net.ipv4.ip_forward = 1 # (1)
    ```

    1. Equivalent to:
    ```sh
    sysctl -w net.ipv4.ip_forward=1
    ```

    [Disable IPv6](https://www.techrepublic.com/article/how-to-disable-ipv6-on-linux/)
    ```conf
    net.ipv6.conf.all.disable_ipv6=1
    net.ipv6.conf.default.disable_ipv6=1
    ```

    Alternatively, kernel parameters can be viewed or even edited through the virtual filesystem mounted at **/proc/sys**
    