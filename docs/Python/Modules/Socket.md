# socket


The socket module is Python's standard interface for the transport layer.
Sockets can be classified by **`family`**

- **`AF_INET`** Internet
- `AF_UNIX` for UNIX sockets

and **`type`**:
  - **`SOCK_STREAM`** TCP
  - `SOCK_DGRAM` UDP

These enum values are required upon initialization of a socket object: <sup>[Ortega][Ortega]: 25</sup>

```py
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

Sources: 

- [Sockets tutorial](https://youtu.be/Lbfe3-v7yE0)


=== "TCP server"

    ```py
    import socket
    

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST,PORT))
    ```

=== "TCP Client" 

    ```py
    import socket


    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST,PORT))
    ```

=== "UDP server"

    ```py
    import socket


    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind((HOST,PORT))
    ```

=== "UDP client"

    ```py
    import socket

    msg = "Hello, world!"
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.sendto(msg.encode(), (HOST,PORT))
    ```

Define port on which to listen for connections.
```py
serversocket.bind(('localhost',80))
```
Connect to a remote socket in one direction
```py
client_socket.connect(('www.packtpub.com',80))
```
Convert a domain name into IPv4 address
```py
socket.gethostbyname('packtpub.com') # '83.166.169.231'
```
Defaults to **localhost** with no arguments
```py
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1234))
```
Get protocol name from port number
```py
socket.getservbyport(80) # 'http'
```
Listen to a maximum of 10 connections
```py
serversocket.listen(10)
```
Receive bytestream from server
```py
msg = s.recv(1024)
print(msg.decode('utf-8'))
```