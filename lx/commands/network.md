### `hping3`


Hping3 crafts "SYN" (sequence) packets from random spoofed IP addresses and sends them out at very short intervals. [^][Sec+ Lab]

Option  | POSIX option            | Effect [^][Kali hping3]
:---    | :---                    | :---
`-i`    | `--interval`            | wait for specified number of microseconds
`-p`    | `--destport`            | destination port 
`-q`    | `--quiet`               | quiet
`-S`    | `--baseport`            | base source port (default random)
&nbsp;  | `--rand-source`         | random source address mode


```sh
hping3 192.168.0.2 -p 80 -i u10 -S -q --rand-source
```

[Sec+ Lab]: https://pts.measureup.com/web/index.php#dashboard.php "Practice Lab: CompTIA Security+ (SY0-501)"
[Kali hping3]: https://tools.kali.org/information-gathering/hping3 "tools.kali.org: \"hping3 - Active Network Smashing Tool\""