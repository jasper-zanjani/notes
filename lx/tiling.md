# Tiling window managers
## i3
Perhaps the most popular tiling window manager, trending toward **manual** rather than **dynamic**. 
### Configuration
i3 configuration file is in a format similar to that of other whitespace-delimited config files like .bashrc. Comments (`#`) must be placed on their own line and  may not be placed after a statement.\
#### Key definitions
Key definitions are those provided in the output of `xmodmap`\ 
`floating_modifier` : holding this key will allow windows to be dragged around with the mouse
### Window management
Window splitting uses the convention opposite to that of vim:
- `split h` : split horizontally (to the right)
- `split v` : split vertically (down)
#### Polybar communication
IPC process communication is a Unix socket
## polybar
Polybar configuration is in `dosini` format, with comments preceded by `;` and values set with `=`. Although whitespace appears to be ignored in most places, any whitespace after the closing bracket on the line reading "[module/i3]",for example, will cause that module not to be loaded.\
Each module has to have one of a few accepted `type` values which will determine what other values it can accept and the module's behavior in the finished bar.
### Command-line ptions
Option            | Effect
:---              | :---
`-c $CONFIGFILE`  | specify {$CONFIGFILE}
### Icons
The established demos appear to rely on old versions of Font Awesome, the following font names should be used after installing\
The following changes fixed the error where "-1" would appear for every workspace:
```ini
label-focused = %name%
label-unfocused=%name%
label-visible=%name%
label-urgent=%name%
```
## Syntax
`; Comment` : comments marked by semicolon
`[bar/barname]` : begin definition of {barname}
`[module/mpd]` : disabling this module by commenting it out removed a lot of error
`bspwm` : another tiling window manager, removing references to this appear not to have a deleterious effect
`polybar -vvv` : "+i3" will appear in the output if this module is installed
`pin-workspaces = true` will show monitor-specific workspaces
`ANY extraneous whitespace is likely to cause issues; for example aws-icon-n=label;icon` {label} needs to match name of the i3 workspace
`format` appears to interpolate or concatenate various values enclosed in `<>` angle brackets
`format = <label-state> <label-mode>` appears to display the raw name of the workspace as configured in the i3 config file, and is common to many of the polybar configs
## Theming
Mouse pointer changes in Firefox, probably because it uses GTK and it is defaulting to a different set of defaults. A user on [Ask Ubuntu](https://askubuntu.com/questions/598943/how-to-de-uglify-i3-wm) received a recommendation to install 3 applications:
  1. `lxappearance`
  2. `gtk-chtheme`
  3. `qt4-qtconfig`
Then to choose the same theme in `lxappearance` as well as `gtk-chtheme` before configuring `qt4-config` to inherit the GTK+ settings.
#### Simple polybar configuration example
```ini
[bar/bar]
width=100%
height=40
background=#c00
foreground=#000
font-0 = Noto Sans Mono:style=Regular:size=18;0
modules-center=i3
[module/i3]
type=internal/i3
format=<label-state>
; vim:ft=dosini
```
## dwm
One of the oldest and lightest tiling window managers. Because suckless wants the source code not to exceed 2,000 lines of code, a lot of functionality is incorporated by means of "patches", which modify the source code using diff files.\
Workspaces are called **tags**. A window can be associated with more than one tag, placing it on more than one workspace. Each monitor has a separate pool of workspaces. [[1](#sources)]
## xmonad
Tiling window manager made especially difficult to configure because the program written in Haskell, as the config must be. All monitors share the same pool of workspaces.\
Unusually for tiling window managers, when using multiple monitors, switching to another workspace actually switches the position of that workspace with the previous one. That is, the workspace that had previously been on the active monitor is sent to the workspace being called.[[1](#sources)]
## awesome
Originating as a form of [dwm](#dwm), it offers creature comforts that make it the easiest to adjust to as a new user of tiling window managers. It is written in Lua, as its config must be. Like dwm, each monitor has an independent pool of workspaces. [[1](#sources)]
## herbstluft
Herbstluft has a single pool of workspaces that is shared across all monitors.[[1](#sources)]
## bspwm
"Binary Space Partitioning Window Manager" uses tree partitioning as the logic for organizing tiles, with the default being the "dwindle" pattern. Like [awesome](#awesome), bspwm uses a shared pool of workspaces, but they are individually assigned to monitors in the configuration file.\
Notably, it uses two config files: **bspwmrc** which determines what programs to autoload but doesn't contain any key bindings; and **sxhkdrc** which uses a syntax similar to [ i3 ](#i3) or [ herbstluft ](#herbstluft).[[1](#sources)]
## Sources
1. "A Comprehensive Guide to Tiling Window Managers". [YouTube](https://youtu.be/Obzf9ppODJU): 2019/09/22.