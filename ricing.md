# Ricing guide
- [ ] Terminal applications
  - [ ] castero
  - [ ] nnn
  - [ ] most
  - [ ] newsboat
  - [ ] neofetch
  - [ ] 
- [ ] Tiling window managers
  - [ ] i3
  - [ ] qtile
  - [ ] polybar
    - [ ] polybar tutorial
- [ ] Display managers
  - [ ] Difference between "desktop environment" and "display manager"
  - [ ] Changing display manager


## Terminal applications
- __castero__ : config file ($HOME/.config/castero/castero.conf) with variables set to fixed enums `black`, `red`, `green`, etc. representing the standard 8 terminal colors
- __nnn__ : environment variable `NNN_CONTEXT_COLORS`, set to values 0-7 representing the standard 8 terminal colors
- __most__ : 
- __newsboat__ : 
- __neofetch__ : 

## Tiling window managers

## Display managers
Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).

### Changing display manager
[MakeUseOf.com](https://www.makeuseof.com/tag/choose-switch-linux-display-managers/)
- `dpkg-reconfigure gdm` produces a curses-based interface where you can select a display manager (Ubuntu et al.)
  - /etc/X11/default-display/manager can be edited as well
- `systemctl enable displaymanager.service -f` enable systemd service for newly-installed {displaymanager}; may require disabling previous display manager first
