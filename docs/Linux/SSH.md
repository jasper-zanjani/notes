# SSH

[curl]: #curl 'Noninteractively transfer data from a large number of protocols, including FTP, FTPS, HTTP, SCP, SFTP, SMB, SMBS, Telnet, and TFTP&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 90'
[ftp]: #ftp 'Establish an interactive FTP connection with a host to transfer files interactively.&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 378'
[rsync]: #rsync '```&#10;rsync&#10;```&#10;Copy files remotely; used in situations where only updated files are to be transferred in order to preserve bandwidth.&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 131'
[ssh]: #ssh '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 266'
[ssh-add]: #ssh-add '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-agent]: #ssh-agent '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 268'
[ssh-keygen]: #ssh-keygen '&#10;Rothwell, William. _CompTIA Linux+/LPIC-1 Portable Command guide_.: 267'
[ssh-keyscan]: #ssh-keyscan '...'
[stty]: #stty '```&#10;stty&#10;```&#10;'
[vncpasswd]: #vncpasswd '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 561'
[vncviewer]: #vncviewer '&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 561'
[sshfs]: #sshfs '```&#10;sshfs&#10;```&#10;'

- [curl][curl] 
- [ftp][ftp] 
- [rsync][rsync] 
- [ssh][ssh] 
- [ssh-add][ssh-add] 
- [ssh-agent][ssh-agent] 
- [ssh-keygen][ssh-keygen] 
- [ssh-keyscan][ssh-keyscan] 
- [stty][stty] 
- [sshfs][sshfs] 

### ssh-copy-id

In Windows, this command is not available, so a workaround is to simply [pipe the public key](https://www.chrisjhart.com/Windows-10-ssh-copy-id/) over SSH itself.

```sh
type $env:USERPROFILE\.ssh\id_rsa.pub | ssh {IP-ADDRESS-OR-FQDN} "cat >> .ssh/authorized_keys"
```

### ssh-keygen

Before starting the SSH daemon, hostkeys must be generated:
```sh
sudo ssh-keygen -A
```

### /etc/ssh/sshd_config

Disable cleartext passwords
```ini
PasswordAuthentication no
```