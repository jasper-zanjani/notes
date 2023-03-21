Port forwarding is accomplished in one of two ways, local or remote with respect to the **server** not the client.

- **Local** (**`-L`**): connections to the client are forwarded through the SSH tunnel to the SSH server. This technique is used to provide functionality similar to a VPN, where remote access is made possible to content on a private network, such as file shares or web applications that are not exposed publicly.
- **Remote** (**`-R`**)...
- **Dynamic**

Here, a private web application served locally on **ssh-server** will be served on the client at the same port.
The first "localhost" can actually be omitted, since the connection will be exposed on localhost host by default and is almost universally.

The confusing part is the second "localhost", because that is actually in reference to the ssh server itself.
```sh
ssh -L localhost:80:localhost:80 ssh-server
```
It is actually possible to forward a request to another host on ssh-server's network, creating a jump box.
Here a connection on the client's localhost:81 is forwarded to ssh-server, which then sends it to 192.168.1.1:80.
```sh
ssh -L 81:192.168.1.1:80 ssh-server
```
