[https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/]: https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/ 'vitux.com: "Change cursor size on Ubuntu through the command line"'
[https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland]: https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland 'superuser.com - "How to remap CAPS LOCK on Wayland"'

### `gconf-editor`
GUI-based configuration editor for GNOME

### `gsettings`
Change function of Caps Lock key [<sup>ref</sup>][https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland]
```sh
gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
```
Change mouse cursor size to `$SIZE`, which can be one of the values 24 (default), 32, 48, 64, or 96. [<sup>ref</sup>][https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/]
```sh
gsettings set org.gnome.desktop.interface $SIZE
```