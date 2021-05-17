#### ssh-copy-id

In Windows, this command is not available, so a workaround is to simply [pipe the public key](https://www.chrisjhart.com/Windows-10-ssh-copy-id/) over SSH itself.

```sh
type $env:USERPROFILE\.ssh\id_rsa.pub | ssh {IP-ADDRESS-OR-FQDN} "cat >> .ssh/authorized_keys"
```
