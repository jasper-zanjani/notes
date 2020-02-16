[Haeder]: # 'Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.'
[xfs]:                                               x.md#xfs                                           '```&#10;$ xfs&#10;```&#10;X fonts server&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 307'

# Linux commands related to X Windows System

&nbsp;  | Commands
---     | ---
&nbsp;  | [`x`][x] [`xdpyinfo`][xdpyinfo] [`xfs`][xfs] [`xhost`][xhost] [`xlsclients`][xlsclients] [`xmodmap`][xmodmap] [`xorg`][xorg] [`xrandr`][xrandr] [`xset`][xset] [`xwininfo`][xwininfo]

### `X`
Test X11 with the config file automatically generated after `Xorg -configure`
```sh
X -config $HOME/xorg.conf.new
```
### `xhost`
Enable access control to X server
```sh
xhost -
```
Disable access control to X server, allowing clients from any host to connect (not unsafe if you use a firewall that allows only SSH)
```sh
xhost +
```
Add `$HOST` to list of authorized clients for X server
```sh
xhost +$HOST
```
Remove `$HOST` from list of authorized clients for X server
```sh
xhost -$HOST
```
Add `$USER` to ACL
```sh
xhost si:localuser:$USER
```
### `xmodmap`
Replacing Caps Lock with Escape
```
! Swap caps lock and escape
remove Lock = Caps_Lock
keysym Escape = Caps_Lock
keysym Caps_Lock = Escape
add Lock = Caps_Lock
```
### `Xorg`
Enable automatic configuration of X11 server
```sh
Xorg -configure
```
### `xrandr`
Change resolution of DisplayPort1 to 1920x1080
```sh
xrandr --output DP1 --mode 1920x1080
```
Disable VGA1 output
```sh
xrandr --output VGA1 --off
```
Display current state of the system
```sh
xrandr -q  --query
```
### `xset`
Dynamically add fonts [<sup>Haeder: 307</sup>][Haeder]
```ssh
xset fp+ /usr/local/fonts
```
