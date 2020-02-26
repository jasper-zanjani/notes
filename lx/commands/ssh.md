[https://gist.github.com/zentralwerkstatt/9e6c83e757cdfe430d6710585b2275c7]: https://gist.github.com/zentralwerkstatt/9e6c83e757cdfe430d6710585b2275c7 "GitHub Gist - SSH into Linux Subsystem for Windows"]
[Cannon]: https://github.com/jasper-zanjani/notes/master/sources/clkf.md "Cannon, Jason. _Command Line Kung Fu_."

# Linux SSH commands
[`ssh`][ssh] [`ssh-keygen`][ssh-keygen] [`ssh-keyscan`][ssh-keyscan] [`sshfs`][sshfs]

### `ssh`
Display timer information
```sh
ss -o
ss --options
```
Request a SSHv1 connection to {user@host}
```sh
ssh -1 user@host
```
Request a SSHv2 connection to {user@host}
```sh
ssh -2 user@host
```
Request a IPv4 connection to {user@host}
```sh
ssh -4 user@host
```
Request a IPv6 connection to {user@host}
```sh
ssh -6 user@host
```
Enable the use of a key for authentication
```sh
ssh -i privatekey
```
Ssh to {user} at {host} and {hostport} from {port}
```sh
ssh -L port:host:hostport user@host
```
Set the port for the remote host
```sh
ssh -p
```
Initiate a SSH session with {user@host}, enabling X forwarding
```sh
ssh -Y user@host
```
List currently loaded keys
```sh
ssh-add -l
```
Compare the differences between a remote and local file.  `cat` a file over SSH and pipe the output into a diff or sdiff command [[23](sources.md)j]
```sh
ssh remotehost cat /path/to/remotefile | diff /path/to/localfile
```
Create an SSH tunnel to access remote resources
Tunnel into a server to access a website which your local machine may not; `-L` creates the SSH tunnel; first port is the port that will be opened on the local machine [[23](sources.md)]
```sh
ssh -N -L localport:host:remoteport remotehost
```
### `ssh-keygen`
Generate a MD5 fingerprint from public key at `$FILE`
```sh
ssh-keygen -E md5-lf $FILE
```
Generate a SHA512 fingerprint from public key at {file}
```sh
ssh-keygen -E sha512 -lf $FILE
```
Generate a fingerprint from the public key
```sh
ssh-keygen -lf $FILE
```
Generate host keys for WSL [<sup>ref</sup>][https://gist.github.com/zentralwerkstatt/9e6c83e757cdfe430d6710585b2275c7]
```sh
sudo ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key
sudo ssh-keygen -t dsa -f /etc/ssh/ssh_host_dsa_key
sudo ssh-keygen -t ecdsa -f /etc/ssh/ssh_host_ecdsa_key
```
### `ssh-keyscan`
Display the public key of `$HOST`
```sh
ssh-keyscan host
```
### `sshfs`
Mount a directory from a remote server on your local host via SSH
[<sup>ref</sup>][Cannon]
```sh
sshfs remotehost:/directory mountpoint
```