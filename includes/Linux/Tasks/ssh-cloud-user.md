#### SSH to a transient server
:   
    To prevent recording an unimportant server to the client's known hosts file, change **UserKnownHostsFile** to "/dev/null".
    To suppress the warning about the unfamiliar address, change **StrictHostKeyChecking** to "no".
    ```sh
    ssh user@host -o "UserKnownHostsFile=/dev/null" -o "StrictHostKeyChecking=no"
    ```

    Alternatively, place these settings in a config, with an appropriate IP address range.
