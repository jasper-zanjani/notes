Change function of Caps Lock key [ref][https://superuser.com/questions/1196241/how-to-remap-caps-lock-on-wayland]
```sh
gsettings set org.gnome.desktop.input-sources xkb-options "['caps:ctrl_modifier']"
```
Change mouse cursor size to `$SIZE`, which can be one of the values 24 (default), 32, 48, 64, or 96. [ref][https://vitux.com/how-to-change-cursor-size-on-ubuntu-desktop/]
```sh
gsettings set org.gnome.desktop.interface $SIZE
```