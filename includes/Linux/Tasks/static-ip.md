#### Static IP
:   
    In Ubuntu 17.10 and later, **Netplan** is used as the default network management tool (previously ifconfig and its config at **/etc/network/interfaces** was used).
    Netplan configs are YAML format and placed in **/etc/netplan**.

    The default config may look something like this, with DHCP enabled.
    Netplan supports two **renderers**: NetworkManager (desktops) and Systemd-networkd (headless servers).

    ```yaml
    # Let NetworkManager manage all devices on this system
    network:
      version: 2
      renderer: NetworkManager
    ```

    To [set a static IP address](https://linuxize.com/post/how-to-configure-static-ip-address-on-ubuntu-20-04/) in Ubuntu 20.04, the interface is configured in a way similar to the following:

    ```yaml
    network:
      version: 2
      renderer: NetworkManager
      ethernets:
        eno1:
          dhcp4: no
          addresses:
          - 192.168.1.70/24
          gateway4: 192.168.1.1
          nameservers:
            addresses: [68.94.156.9, 68.94.157.9]
    ```

    Setting a static IP address on Red Hat distributions could involve multiple methods:

    - [nmcli commands](https://linuxhint.com/configure-static-ip-address-fedora/)
    - [NetworkManager keyfiles](Network/#networkmanager)
    - [ifcfg files](Network/#ifcfg-files) (prior to distributions downstream to Fedora 36)

