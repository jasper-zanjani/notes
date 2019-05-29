# Ricing guide
#### Terminal applications configuration
- [ ] castero
- [ ] nnn
- [ ] most
- [ ] newsboat
- [ ] neofetch
- [ ] 
#### Tiling window managers
- [ ] i3
- [ ] qtile
- [ ] polybar
- [ ] rofi
#### Display managers
- [ ] Difference between "desktop environment" and "display manager"
- [ ] Changing display manager


## Terminal applications
- __castero__ : config file ($HOME/.config/castero/castero.conf) with variables set to fixed enums `black`, `red`, `green`, etc. representing the standard 8 terminal colors
- __nnn__ : environment variable `NNN_CONTEXT_COLORS`, set to values 0-7 representing the standard 8 terminal colors
- __most__ : environment variable `MOST_INITFILE` points to config
- __newsboat__ : by default it will look in $HOME/.newsboat/config, but the CLI option `-C` can specify a custom configuration file
- __neofetch__ : `--config` option

## Tiling window managers

## Display managers
Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).

### Changing display manager
_How to choose and switch Linux display managers_ [MakeUseOf.com](https://www.makeuseof.com/tag/choose-switch-linux-display-managers/)
#### Produce a curses-based interface where you can select a display manager
```sh
dpkg-reconfigure gdm
``` 
#### Configuration file can be edited as well
```sh
vim /etc/X11/default-display/manager
```
#### Enable systemd service for newly-installed {displaymanager}; may require disabling previous display manager first
```sh
systemctl enable displaymanager.service -f
```
