[ssh-add](https://www.ssh.com/academy/ssh/add-command) adds private key identities to the OpenSSH authentication agent, [ssh-agent](#ssh-agent).
Notably, ssh-add requires the **SSH\_AUTH\_SOCK** environment variable set by ssh-agent.

When run without arguments, it adds the private keys found in **~/.ssh**, i.e.

- id\_rsa
- id\_dsa
- id\_ecdsa
- id\_ecdsa\_sk
- id\_ed25519
- id\_ed25519\_sk

```sh
eval $(ssh-agent); ssh-add <(cat "$(keyFile.secureFilePath)")
```