

!!! cisco "Configure EtherChannel"

    EtherChannel can be configured using PAgP (`desirable`), LACP (`active`), statically (`on`), or at Layer 3.
    Because PAgP is the default, all other methods require the interfaces to be shutdown first.
    
    === "PAgP"

        ``` hl_lines="2"
        SW1(config)#interface range gi0/2 , gi1/1
        SW1(config-if-range)#channel-group 2 mode desirable
        ```
        ``` hl_lines="2"
        SW2(config)#interface range gi0/1 , gi0/3
        SW2(config-if-range)#channel-group 2 mode desirable
        ```

    === "LACP"

        ``` hl_lines="3"
        SW1(config)#interface range gi0/2 , gi1/1
        SW1(config-if-range)#shutdown
        SW1(config-if-range)#channel-group 3 mode active
        ```
        ``` hl_lines="2"
        SW2(config)#interface range gi0/2 , gi1/0
        SW2(config-if-range)#channel-group 3 mode active
        ```
        ```
        SW3(config)#interface range gi0/2 , gi1/0
        SW3(config-if-range)#no shutdown
        ```

    === "Static"

        ``` hl_lines="3"
        SW1(config)#interface range gi0/1 , gi0/3
        SW1(config-if-range)#shutdown
        SW1(config-if-range)#channel-group 1 mode on
        ```
        ``` hl_lines="2"
        SW2(config)#inteface range gi0/1 , gi1/0
        SW2(config-if-range)#channel-group 1 mode on
        ```
        ```
        SW1(config)#interface range gi0/1 , gi0/3
        SW1(config-if-range)#no shutdown
        ```

!!! cisco "Verify EtherChannels"

    ```
    SW1#show etherchannel summary
    ```