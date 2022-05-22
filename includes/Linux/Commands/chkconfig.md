**chkconfig**{: #chkconfig }
:   
    Turn services on or off for runlevels
    
    Without arguments, chkconfig defaults to runlevels 3 or 5:

    Display all services and runlevels
    ```sh
    chkconfig --list
    ```

    Turn NetworkManager on or off
    ```sh
    chkconfig NetworkManager on
    chkconfig NetworkManager off
    ```
    
    Turn NetworkManager on for runlevels 3 and 5
    ```sh
    chkconfig --level 35 NetworkManager on
    ```