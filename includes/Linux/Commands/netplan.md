#### netplan
:   
    **netplan** is a [utility for network configuration](https://netplan.io/) using YAML files

    ```yaml
    network:
      version: 2
      renderer: networkd
      ethernets:
        eth01:
          dhcp4: yes
    ```
