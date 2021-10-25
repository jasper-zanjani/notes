#### gsettings
:   
    Change function of <kbd>Caps Lock</kbd> [:material-file-document:](https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland)
    
    ```sh
    gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
    ```

    Change mouse cursor size to various sizes [:material-file-document:](https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/)

    === "24"

        ```sh
        gsettings set org.gnome.desktop.interface 24
        ```

    === "32"

        ```sh
        gsettings set org.gnome.desktop.interface 32
        ```

    === "48"

        ```sh
        gsettings set org.gnome.desktop.interface 48
        ```

    === "64"

        ```sh
        gsettings set org.gnome.desktop.interface 64
        ```

    === "96"

        ```sh
        gsettings set org.gnome.desktop.interface 96
        ```

    Enable the GTK Inspector which can be run with <kbd>Ctrl</kbd><kbd>Shift</kbd><kbd>D</kbd>
    ```sh
    gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true
    ```