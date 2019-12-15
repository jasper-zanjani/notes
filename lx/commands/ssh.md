### ssh
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

### ssh-keygen
Generate a MD5 fingerprint from public key at {file}
```sh
ssh-keygen -E md5-lf /path/to/file
```
Generate a SHA512 fingerprint from public key at {file}
```sh
ssh-keygen -E sha512 -lf /path/to/file
```
Generate a fingerprint from the public key
```sh
ssh-keygen -lf /path/to/file
```
### ssh-keyscan
Display the public key of {host}
```sh
ssh-keyscan host
```

### `sshfs`
Mount a directory from a remote server on your local host via SSH
[[23](sources.md)]
```sh
sshfs remotehost:/directory mountpoint
```