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

--8<-- "includes/Linux/ssh-copy-id.md"

--8<-- "includes/Linux/ssh-keygen.md"

#### /etc/ssh/sshd_config

Disable cleartext passwords
```ini
PasswordAuthentication no
```

#### endlessh

Log verbosity can be configured from the command-line or the config

=== "Silent"

    ```sh
    endlessh
    ```

    /etc/endlessh/config
    ```
    LogLevel 0
    ```


=== "Normal"

    ```sh
    endlessh -v
    ```

    /etc/endlessh/config
    ```
    LogLevel 1
    ```


=== "Debug"

    ```sh
    endlessh -vv
    ```
    
    /etc/endlessh/config
    ```
    LogLevel 2
    ```
