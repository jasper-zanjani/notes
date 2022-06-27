#### Diagnosing network problems
:   
    Test from the inside out, starting with the loopback

    1. ping loopback address, testing the TCP/IP stack
    2. ping the hardware interface
    3. ping another host on the network
    4. ping the gateway
    5. ping an IP address on the Internet
    6. ping a hostname on the Internet

#### Filters
:   
    Display contents of a random file
    ```sh
    ls | sort -R | sed 1q | xargs cat
    ```
    Find out which commands you use most often
    ```sh
    history | awk '{print $2' | sort | uniq -c | sort -rn | head
    ```
    Count the number of occurrences of a string
    ```sh
    echo $STRING | uniq -c | sort -
    ```

#### Change hostname 
:   
    ```sh
    hostnamectl set-hostname $NEWHOSTNAME
    ```

#### Check kernel version 
:   
    ```bash
    uname -srm
    hostnamectl | grep "Kernel"
    cat /proc/version
    ```