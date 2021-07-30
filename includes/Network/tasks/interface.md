!!! cisco "Interfaces"

    ![](/img/cisco1.png)

    === "Display state"

        ```
        Switch>show interfaces status
        ```
    
    === "Bring up"

        ``` hl_lines="4"
        Switch>enable
        Switch#configure terminal
        Switch(config)#interface fa0/1
        Switch(config-if)#no shutdown
        Switch(config-if)#end
        ```