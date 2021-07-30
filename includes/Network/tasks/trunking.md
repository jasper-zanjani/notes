![](/img/cisco-trunk.png)

Without configuring trunking, the interfaces are in **access** mode.

=== "SW1"

    ??? output "`SW1#show interfaces gi0/1 switchport`"

        ``` hl_lines="3 4"
        Name: GigabitEthernet0/1
        Switchport: Enabled 
        Administrative Mode: dynamic auto
        Operational Mode: static access
        Administrative Trunking Encapsulation: dot1q 
        Operational Trunking Encapsulation: native
        Negotiation of Trunking: false
        Access Mode VLAN: 1
        Trunking Native Mode VLAN: 1 (default) 
        Administrative Native VLAN tagging: enabled
        Voice VLAN: none
        Administrative private-vlan host-association: none
        Administrative private-vlan mapping: none
        Administrative private-vlan trunk native VLAN: none
        Administrative private-vlan trunk Native VLAN tagging: enabled
        Administrative private-vlan trunk encapsulation: dot1q
        Administrative private-vlan trunk normal VLANs: none
        Administrative private-vlan trunk private VLANs: none
        Operational private-vlan: none
        Trunking VLANs Enabled: All
        Pruning VLANs Enabled: none
        Capture Mode Disabled
        Capture VLANs Allowed: ALL

        Protected: false
        Unknown unicast blocked: disabled
        Unknown multicast blocked: disabled
        Appliance trust: none
        ```

=== "SW3"

    ??? output "`SW3#show interfaces gi0/2 switchport`"

        ``` hl_lines="3 4"
        Name: GigabitEthernet0/1
        Switchport: Enabled 
        Administrative Mode: dynamic auto
        Operational Mode: static access
        Administrative Trunking Encapsulation: dot1q 
        Operational Trunking Encapsulation: native
        Negotiation of Trunking: false
        Access Mode VLAN: 1
        Trunking Native Mode VLAN: 1 (default) 
        Administrative Native VLAN tagging: enabled
        Voice VLAN: none
        Administrative private-vlan host-association: none
        Administrative private-vlan mapping: none
        Administrative private-vlan trunk native VLAN: none
        Administrative private-vlan trunk Native VLAN tagging: enabled
        Administrative private-vlan trunk encapsulation: dot1q
        Administrative private-vlan trunk normal VLANs: none
        Administrative private-vlan trunk private VLANs: none
        Operational private-vlan: none
        Trunking VLANs Enabled: All
        Pruning VLANs Enabled: none
        Capture Mode Disabled
        Capture VLANs Allowed: ALL

        Protected: false
        Unknown unicast blocked: disabled
        Unknown multicast blocked: disabled
        Appliance trust: none
        ```

Now the interface of one switch is configured as a trunk, and because the adminstrative mode of either is "dynamic", the facing interface accepts the change.

!!! cisco "Configure interface as trunk"

    ``` hl_lines="3"
    SW1#configure terminal
    SW1(config)#interfaces gi0/2
    SW1(config-if)#switchport mode trunk
    ```

There are several ways of confirming the trunk status:


=== "status"

    ??? output "SW1#show interfaces status"

        ``` hl_lines="27"
        Interface  Name  Status      Vlan   Duplex  Speed   Type                             
        Fa0/1            connected   1      a-full  a-100   media type is 10/100BaseTX       
        Fa0/2            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/3            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/4            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/5            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/6            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/7            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/8            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/9            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/10           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/11           connected   1      a-full  a-100   media type is 10/100BaseTX       
        Fa0/12           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/13           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/14           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/15           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/16           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/17           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/18           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/19           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/20           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/21           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/22           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/23           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/24           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Gi0/1            connected   1      a-full  a-1000  media type is 10/100/1000BaseTX  
        Gi0/2            connected   trunk  a-full  a-1000  media type is 10/100/1000BaseTX  
        vlan1            connected   1      auto    auto    media type is 10/100/1000BaseTX  
        ```

=== "switchport"

    ??? output "SW1#show interfaces gi0/2 switchport"

        ``` hl_lines="3 4"
        Name: GigabitEthernet0/2
        Switchport: Enabled 
        Administrative Mode: dynamic auto
        Operational Mode: trunk
        Administrative Trunking Encapsulation: dot1q 
        Operational Trunking Encapsulation: native
        Negotiation of Trunking: false
        Access Mode VLAN: 1
        Trunking Native Mode VLAN: 1 (default) 
        Administrative Native VLAN tagging: enabled
        Voice VLAN: none
        Administrative private-vlan host-association: none
        Administrative private-vlan mapping: none
        Administrative private-vlan trunk native VLAN: none
        Administrative private-vlan trunk Native VLAN tagging: enabled
        Administrative private-vlan trunk encapsulation: dot1q
        Administrative private-vlan trunk normal VLANs: none
        Administrative private-vlan trunk private VLANs: none
        Operational private-vlan: none
        Trunking VLANs Enabled: All
        Pruning VLANs Enabled: none
        Capture Mode Disabled
        Capture VLANs Allowed: ALL

        Protected: false
        Unknown unicast blocked: disabled
        Unknown multicast blocked: disabled
        Appliance trust: none
        ```

=== "trunk"

    ??? output "SW1#show interfaces trunk"

        ```
        Port        Mode         Encapsulation  Status        Native vlan
        Gi0/2       on           802.1q         trunking      1

        Port        Vlans allowed on trunk
        Gi0/2       1-4094

        Port        Vlans allowed and active in management domain
        Gi0/2       1

        Port        Vlans in spanning tree forwarding state and not pruned
        Gi0/2       1
        ```

On SW3, the three commands produce similar output, except for the interface's Administrative Mode.

=== "status"

    ??? output "`SW3#show interfaces status`"

        ``` hl_lines="26"
        Interface  Name  Status      Vlan   Duplex  Speed   Type                             
        Fa0/1            disabled    1      auto    auto    media type is 10/100BaseTX       
        Fa0/2            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/3            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/4            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/5            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/6            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/7            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/8            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/9            notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/10           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/11           connected   1      a-full  a-100   media type is 10/100BaseTX       
        Fa0/12           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/13           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/14           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/15           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/16           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/17           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/18           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/19           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/20           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/21           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/22           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/23           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Fa0/24           notconnect  1      auto    auto    media type is 10/100BaseTX       
        Gi0/1            connected   trunk  a-full  a-1000  media type is 10/100/1000BaseTX  
        Gi0/2            notconnect  1      auto    auto    media type is 10/100/1000BaseTX  
        vlan1            connected   1      auto    auto    media type is 10/100/1000BaseTX 
        ```


=== "switchport"

    ??? output "`SW3#show interfaces gi0/2 switchport`"

        ``` hl_lines="3"
        Name: GigabitEthernet0/2
        Switchport: Enabled 
        Administrative Mode: trunk
        Operational Mode: trunk
        Administrative Trunking Encapsulation: dot1q 
        Operational Trunking Encapsulation: native
        Negotiation of Trunking: false
        Access Mode VLAN: none
        Trunking Native Mode VLAN: 1 (default) 
        Administrative Native VLAN tagging: enabled
        Voice VLAN: none
        Administrative private-vlan host-association: none
        Administrative private-vlan mapping: none
        Administrative private-vlan trunk native VLAN: none
        Administrative private-vlan trunk Native VLAN tagging: enabled
        Administrative private-vlan trunk encapsulation: dot1q
        Administrative private-vlan trunk normal VLANs: none
        Administrative private-vlan trunk private VLANs: none
        Operational private-vlan: none
        Trunking VLANs Enabled: 
        Pruning VLANs Enabled: none
        Capture Mode Disabled
        Capture VLANs Allowed: ALL

        Protected: false
        Unknown unicast blocked: disabled
        Unknown multicast blocked: disabled
        Appliance trust: none
        ```

=== "trunk"

    ??? output "`SW3#show interfaces trunk`"

        ```
        Port        Mode         Encapsulation  Status        Native vlan
        Gi0/1       on           802.1q         trunking      1

        Port        Vlans allowed on trunk
        Gi0/1       1-4094

        Port        Vlans allowed and active in management domain
        Gi0/1       1

        Port        Vlans in spanning tree forwarding state and not pruned
        Gi0/1       1
        ```


Encapsulation method is 802.1Q by default, although it can be explicitly specified.

!!! cisco "&nbsp;"

    ``` 
    SW1(config-if)#switchport trunk encapsulation dot1q
    SW1(config-if)#switchport mode trunk
    ```