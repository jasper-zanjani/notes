#### sysctl
:   
    View and configure **kernel parameters** at runtime.
    Kernel parameters are [tunable values](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/managing_monitoring_and_updating_the_kernel/configuring-kernel-parameters-at-runtime_managing-monitoring-and-updating-the-kernel) that can be adjusted during runtime.

    Kernel parameters can be delimited with dots or slashes
    ```sh
    sysctl kernel.hostname
    sysctl kernel/hostname
    ```

    ```sh title="Suppress 
    sysctl -n kernel.hostname
    ```

    Kernel parameters are set persistently by defining values in **/etc/sysctl.conf** or other .conf files placed in **/etc/sysctl.d/**.
    ```ini title="/etc/sysctl.conf"
    net.ipv4.ip_forward=1
    ```

    These values are then loaded into memory ad-hoc with:
    ```sh
    sysctl -p # --load
    ```

    The runtime can be manipulated directly from the command-line with a different flag"
    ```sh
    sysctl -w net.ipv4.ip_forward=1
    ```

    Alternatively, values can be echoed to the virtual filesystem exposed at **/proc/sys**
    ```sh
    echo 1 > /proc/sys/net/ipv4/ip_forward
    ```

    [Disable IPv6](https://www.techrepublic.com/article/how-to-disable-ipv6-on-linux/)
    ```conf
    net.ipv6.conf.all.disable_ipv6=1
    net.ipv6.conf.default.disable_ipv6=1
    ```

    Alternatively, kernel parameters can be viewed or even edited through the virtual filesystem mounted at **/proc/sys**
    