The classic version of STP is PVST+, which is slower to converge than RSTP.
Cisco's implementation of RSTP is called RPVST+.

!!! cisco "STP"

    ```
    Switch#show spanning-tree
    ```

**PortFast**{: #portfast } is a STP feature that speeds up the process of moving a port from **blocking** to **forwarding** and is used exclusively on ports connected to servers and workstations.

!!! cisco "PortFast"

    ```
    Switch(config-if)#spanning-tree portfast
    ```

**BPDU Guard**{: #bpdu-guard } is a related feature that can detect if a switch was mistakenly connect to a PortFast port and error disable the port for safety and security.

!!! cisco "BPDU Guard"

    ```
    Switch(config-if)#spanning-tree bpduguard enable
    ```



!!! cisco "Confirming PortFast and BPDU Guard"

    ```
    Switch#show spanning-tree interface gi0/3 detail
    ```