# Tiling window managers

- **i3**{: #i3 } is perhaps the most popular tiling window manager, typically used with polybar.
- **awesome**{: #awesome } is written and configured in Lua. It originated as a fork of [**dwm**](#dwm), it offers creature comforts that make it the easiest for neophytes to tiling window managers.
- **bspwm** ("Binary Space Partitioning Window Manager") uses tree partitioning as the logic for organizing tiles, with the default being the "dwindle" pattern. 
Notably, it uses two config files: 
    - **.bspwmrc** which determines what programs to autoload but doesn't contain any key bindings
    - **.sxhkdrc** which uses a syntax similar to [i3](#i3) or herbstluft.
- **dwm**{: #dwm }: One of the oldest and lightest tiling window managers. 
Because Suckless wants the source code not to exceed 2,000 lines of code, a lot of functionality is incorporated by means of **patches**, which modify the source code using diff files. 
- **herbstluft** has a single pool of workspaces that is shared across all monitors.
- **xmonad** is written and configured in Haskell, making it challenging to configure.

All window managers place an INI-format .desktop file in **/usr/share/xsessions/**.
```ini title="xmonad.desktop"
[Desktop Entry]
Name=xmonad
Comment=Tiling window manager
Exec=xmonad-start
Terminal=false

[Window Manager]
SessionManaged=true
```


--8<-- "includes/Linux/Tasks/Xmonad.md"
