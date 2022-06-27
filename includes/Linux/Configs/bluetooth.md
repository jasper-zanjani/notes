#### /etc/bluetooth
:   
    - **/etc/bluetooth/input.conf**
    Fix bluetooth mouse [constantly disconnecting](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects)
    ```ini
    UserspaceHID=true
    ```
    - **/etc/bluetooth/main.conf**
    Power on Bluetooth adapter [at startup](https://askubuntu.com/questions/1065335/bluetooth-mouse-constantly-disconnects-and-reconnects)
    ```ini
    [Policy]
    AutoEnable=true
    ```
