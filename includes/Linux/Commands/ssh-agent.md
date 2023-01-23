ssh-agent is a [helper program](https://www.ssh.com/academy/ssh/agent) that keeps track of identity keys and passphrases, allowing them to be used without further interaction, similar to SSO.
Running it produces output that is meant to be used with the **eval** command in order to set the environment variables **SSH_AGENT_PID** and **SSH_AUTH_SOCK**, which are needed by [ssh-add](#ssh-add).

```sh
eval $(ssh-agent); ssh-add <(cat "$(keyFile.secureFilePath)")
```

If only a single process is running, the **-k** option will kill it (although it is possible to fork multiple ssh-agent processes).
```sh
ssh-agent -k # (1)
```

1. Equivalent to
```sh
kill $SSH_AGENT_PID
```