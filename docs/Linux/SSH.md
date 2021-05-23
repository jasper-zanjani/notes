# SSH

The SSH server daemon has slightly different names on Debian and Red Hat systems

=== "Debian"

    ```sh
    service ssh start
    ```

=== "Red Hat"

    ```sh
    service sshd start
    ```

--8<-- "includes/Linux/Commands/endlessh.md"
--8<-- "includes/Linux/Commands/ssh-copy-id.md"
--8<-- "includes/Linux/Commands/ssh-keygen.md"

**/etc/ssh/sshd_config**

Disable cleartext passwords
```ini
PasswordAuthentication no
```

