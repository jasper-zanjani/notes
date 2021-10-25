#### xrandr
:   
    Change resolution of DisplayPort1 to 1920x1080
    ```sh
    xrandr --output DP1 --mode 1920x1080
    ```
    Disable VGA1 output
    ```sh
    xrandr --output VGA1 --off
    ```
    Display current state of the system
    ```sh
    xrandr -q  --query
    ```