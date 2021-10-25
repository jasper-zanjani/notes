#### nmap
:   
    Scan hosts from a text file
    ```sh
    nmap -iL hosts.txt
    ```
    Identify a host's operating system
    ```sh
    nmap -A localhost.example.com
    ```
    Determine whether a host has a firewall enabled
    ```sh
    nmap -sA localhost.example.com
    ```
    Scan a specified range of ports
    ```sh
    nmap -p 10-300 localhost.example.com
    ```
    Perform a SYN TCP scan, stealthier than the TCP connect scan
    ```sh
    nmap -sT localhost.example.com
    ```
    Aggressive scan
    ```sh
    nmap -A 192.168.1.0/24
    ```
    Ping scan home network (not bothering with ports)
    ```sh
    nmap -sn 192.168.1.0/24
    ```
    Fast port scan using SYN packets
    ```sh
    nmap -sS -F 192.168.1.0/24
    ```
    Port scan using SYN ("synchronize") packet, first element of TCP handshake
    ```sh
    nmap -sS 192.168.1.0/24
    ```
    Port scan using normal TCP
    ```sh
    nmap -sT 192.168.1.0/24
    ```
    Port scan using UDP
    ```sh
    nmap -sU 192.168.1.0/24
    ```
    Xmas scan
    ```sh
    nmap -sX
    ```
    Scan a range of IPs [ref][Sec+ Lab]
    ```sh
    nmap 192.168.27.0/24 > hosts.txt
    ```
    Identify operating system and scan ports using TCP SYN packets [ref][Sec+ Lab]
    ```sh
    nmap -O -sS 192.168.27.0/24 > hosts.txt
    ```
