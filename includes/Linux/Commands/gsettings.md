#### gsettings
:   
    **gsettings** is the CLI frontend intended to support changes to GNOME application settings, stored in [dconf](#dconf) databases.

    ```sh title="Examples"
    # Change function of Caps Lock
    gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"

    # Change mouse cursor size to various sizes. This can also be done in GNOME as Settings > Accessibility
    gsettings set org.gnome.desktop.interface cursor-size 24 # (1)

    # Enable GTK Inspector
    gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true # (2)
    ```

    1. Valid sizes include 24, 32, 48, 64, and 96
    2. Can be run with ++ctrl+shift+d++