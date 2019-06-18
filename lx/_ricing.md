# Ricing guide
#### Terminal applications configuration
- [ ] castero
- [ ] nnn
- [ ] most
- [ ] newsboat
- [ ] neofetch

#### Tiling window managers
- [ ] i3
- [ ] qtile
- [ ] polybar
- [ ] rofi

#### Display managers
- [ ] Difference between "desktop environment" and "display manager"
- [ ] Changing display manager

## Terminal applications
Application   | Configuration
:---          | :---
__castero__   | config file ($HOME/.config/castero/castero.conf) with variables set to fixed enums `black`, `red`, `green`, etc. representing the standard 8 terminal colors
__nnn__       | environment variable `NNN_CONTEXT_COLORS`, set to values 0-7 representing the standard 8 terminal colors
__most__      | environment variable `MOST_INITFILE` points to config
__newsboat__  | config file ($HOME/.newsboat/config, then $HOME/.config/newsboat), CLI option `-C` can specify a custom config
__neofetch__  | `--config` option

## Simulating a tiling window manager in KDE
  1. Run Command > Run Command (Meta+R)
  2. KDE Daemon > Launch Konsole (Meta+Return)
  3. Desktop navigation keyboard shortcuts: KWin >
    - Switch to Desktop (Meta+Fkey)
    - Switch to Previous/Next Desktop (Meta + PgUp/PgDown)
    - Switch to Window Above/Below/to the Left/Right (Meta+ K/J/H/L)
    - Window to Desktop (Meta+Shift+Fkey)
    - Window to Previous/Next Desktop (Meta+Shift_PgUp/PgDown)
  4. Panel screen edge -> top
  5. Pager settings > General: Display only Desktop name
  6. Configure Desktops
    - Change names of desktops to Font Awesome icons
    - Check "Show on-screen display when switching"

## Display managers
Basically display managers are the login screens, while the GUI manipulated during normal use represents the desktop environment (i.e. GNOME, KDE, XFCE, etc).

### Changing display manager
"How to choose and switch Linux display managers" [MakeUseOf.com](https://www.makeuseof.com/tag/choose-switch-linux-display-managers/)

Command   |  Effect
:---      | :---
`dpkg-reconfigure gdm` | Produce a curses-based interface where you can select a display manager
`vim /etc/X11/default-display/manager` | Configuration file can be edited as well
`systemctl enable displaymanager.service -f` | Enable systemd service for newly-installed {displaymanager}; may require disabling previous display manager first

