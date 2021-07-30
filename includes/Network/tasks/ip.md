<!-- Tabs showing various ways of configuring the IP address of a Cisco router -->

!!! cisco "Configure router IP"

    === "IPv4"

        ``` hl_lines="2"
        R1(config)#interface fa0/0
        R1(config-if)#ip address 0.10.10.1 255.255.255.0
        R1(config-if)#no shutdown
        R1(config-if)#end
        ```

    === "IPv6"

        ``` hl_lines="2"
        R1(config)#interface fa0/0
        R1(config-if)#ipv6 address 2001:aaaa:bbbb::1/64
        R1(config-if)#no shutdown
        R1(config-if)#end
        ```

    === "EUI-64"

        ``` hl_lines="2"
        R1(config)#interface fa0/0
        R1(config-if)#ipv6 address 2001:aaaa:bbbb::/64 eui-64
        R1(config-if)#no shutdown
        R1(config-if)#end
        ```

    === "SLAAC"

        ``` hl_lines="2"
        R1(config)#interface fa0/0
        R1(config-if)#ipv6 address autoconfig
        R1(config-if)#no shutdown
        R1(config-if)#end
        ```