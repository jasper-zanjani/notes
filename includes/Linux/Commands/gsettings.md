#### gsettings
:   
    **gsettings** is the CLI frontend intended to support changes to GNOME application settings, stored in [dconf](#dconf) databases.

    Change function of [++Caps Lock++](https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland)
    ```sh
    gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
    ```

    Change [mouse cursor size](https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/) to various sizes (valid sizes include 24, 32, 48, 64, and 96)
    ```sh
    gsettings set org.gnome.desktop.interface cursor-size 24 # (1)
    ```

    1. This can also be done via GUI in **Settings** &gt; **Accessibility**.

    Enable the GTK Inspector which can be run with ++Ctrl+Shift+D++
    ```sh
    gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true
    ```