#### firewall-cmd
:   
    Frontend to [Netfilter](#netfilter) in Red Hat distributions.
    
    Places network traffic into zones. Commands have to be written twice: once to affect running config and again to have the change saved

    Display active zones
    ```sh
    firewall-cmd --list-active-zones
    ```

    Display firewall rules
    ```sh
    firewall-cmd --list-all
    ```

    Add a new zone, and write the change to disk
    ```
    firewall-cmd --new-zone=testlab  --permanent
    ```