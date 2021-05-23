# ifconfig

Enable an interface

=== "ifconfig"

    ```sh
    ifconfig eth0 up
    ```

=== "ifup"

    ```
    ifup eth0
    ```

Disable an interface

=== "ifconfig"

    ```sh
    ifconfig eth0 down
    ```

=== "ifdown"

    ```sh
    ifdown eth0
    ```

Apply a static IP address to interface {eth0} and turn it on ("up")

```
ifconfig eth0 up 10.1.230.245 netmask 255.255.255.0
```

Display details of all interfaces, even those that are disabled
("RX" and "TX" stand for received and transmitted).
```sh
ifconfig -a
```

Configure `eth0` with an additional IPv6 address
```sh
ifconfig eth0 inet6 add fdd6:551:b09e::/128
```

### ifup

Bring online all interfaces marked as auto within the networking configuration
```sh
ifup -a
```
