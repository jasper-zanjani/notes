#### gsettings
:   
    **gsettings** is the CLI frontend intended to support changes to GNOME application settings, stored in [dconf](#dconf-2) databases.
    
    Most useful subcommands require at least a "**schema**" or dconf path, like **`list-keys`**, **`list-recursively`**, **`monitor`** etc. 
    Others like **`describe`**, **`get`**, and **`reset`** additionally require a key.
    The subcommand **`set`** requires a key as well as a value.

    Change function of [<kbd>Caps Lock</kbd>](https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland)
    ```sh
    gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
    ```

    Change [mouse cursor size](https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/) to various sizes (valid sizes include 24, 32, 48, 64, and 96)
    ```sh
    gsettings set org.gnome.desktop.interface cursor-size 24
    ```

    Enable the GTK Inspector which can be run with <kbd>Ctrl</kbd><kbd>Shift</kbd><kbd>D</kbd>
    ```sh
    gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true
    ```