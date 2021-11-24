#### iptables
:   
    Like `firewalld`, a frontend for the kernel-level [**netfilter**](#netfilter) service. 

    | Description          | Option | POSIX option |
    | -------------------- | ------ | ------------ |
    | Specify a **chain**  | `-A`   | `--append`   |
    | Specify a **target** | `-j`   | `--jump`     |

    By default, the INPUT chain accepts incoming packets.
    However, this policy can be changed by specifying a DROP rule specification.
    Here incoming SSH traffic is allowed only from a specific source IP.
    ```sh
    iptables -A INPUT -p tcp --dport 22 -j DROP
    iptables -A INPUT -p tcp --dport 22 -s 1.2.3.4 -j ACCEPT
    ```

    Display rules as written on disk
    ```sh
    iptables --list-rules
    ```
    Accept SSH traffic from a particular IP
    ```sh
    iptables -A INPUT -p ssh -s 10.0.222.222 -j ACCEPT
    ```
    Accept incoming TCP traffic to port 80
    ```sh
    iptables -A INPUT -p tcp --dport 80 -j ACCEPT
    ```
    Reload configuration file
    ```sh
    iptables -F
    ```
    Show statistics for configuration lines
    ```sh
    iptables -vnL --lines
    ```
