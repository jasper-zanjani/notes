!!! cisco "Configure VLAN settings"

    === "Name a VLAN"
    
        ```
        SW1#configure terminal
        SW1(config)#vlan 30
        SW1(config-vlan)#name WEST
        SW1(config-vlan)#do show vlan brief
        ```

    === "Data VLAN"

        ``` hl_lines="4"
        SW1#configure terminal
        SW1(config)#interface gi0/1
        SW1(config-if)#switchport mode access
        SW1(config-if)#switchport access vlan 20
        SW1(config-if)#end
        SW1#show vlan brief
        ```

    === "Voice VLAN"

        ``` hl_lines="5"
        SW1#configure terminal
        SW1(config)#interface gi0/2
        SW1(config-if)#switchport mode access
        SW1(config-if)#switchport access vlan 30
        SW1(config-if)#switchport voice vlan 50
        SW1(config-if)#end
        SW1#show vlan brief
        SW1#show interface gi0/2 switchport
        ```