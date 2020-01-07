### `ip`
Newer alternative to the old `ifconfig`
```sh
ip addr
```
Show L2 status (links)
```sh
ip link
```
Listen for netlink messages
```sh
ip monitor 
```
Display routing information
```sh
ip route
```
Change the default gateway to 192.168.1.1 on eth0
```sh
ip route change default via 192.168.1.1 dev eth0
```

Turn on interface `wlp2s0`
```sh
sudo ip link set wlp2s0 up
```