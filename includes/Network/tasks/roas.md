!!! cisco "Configure ROAS"

    A **subinterface** can be configured by specifying a VLAN number after a period on the physical interface, then associating an IP range with it.
    Theese IP addresses can be used as default gateway addresses hosts will use in respective subnets.

    ROAS can be configured with or without setting an IP address on the interface.

    === "IP"

        ``` hl_lines="1"
        R1(config-if)#ip address 10.1.0.1 255.255.255.0
        R1(config-if)#interface gi0/1.10
        R1(config-subif)#encapsulation dot1q 10
        R1(config-subif)#ip address 10.1.10.1 255.255.255.0
        R1(config-subif)#end
        R1(config)#inteface gi0/1.20
        R1(config-subif)#encapsulation dot1q 20
        R1(config-subif)#ip address 10.1.20.1 255.255.255.0
        R1(config-subif)#end
        ```

    === "No IP"

        ```
        R1(config-if)#interface gi0/1.10
        R1(config-subif)#encapsulation dot1q 10
        R1(config-subif)#ip address 10.1.10.1 255.255.255.0
        R1(config-subif)#end
        R1(config)#inteface gi0/1.20
        R1(config-subif)#encapsulation dot1q 20
        R1(config-subif)#ip address 10.1.20.1 255.255.255.0
        R1(config-subif)#end
        ```

    ```
    SW1(config)#interface gi0/1
    SW1(config-if)#switchport trunk encapsulation dot1q
    SW1(config-if)#switchport mode trunk
    ```

!!! cisco "Verify ROAS"

    === "`show ip interface brief`"

        ```
        R1#show ip interface brief
        ```
    
    === "`show vlans``