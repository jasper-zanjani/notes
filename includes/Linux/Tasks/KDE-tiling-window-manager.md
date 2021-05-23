#### Simulating a tiling window manager in KDE

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

Key definitions are those provided in the output of `xmodmap`

`floating_modifier` : holding this key will allow windows to be dragged around with the mouse

Window splitting uses the convention opposite to that of vim:

- `split h` : split horizontally (to the right)
- `split v` : split vertically (down)