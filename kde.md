# KDE Plasma desktop environment

## Appearance
- __Colors__ affects the appearance of text
- __Workspace Theme__ opens up several dialogs
  - __Look and Feel__ allows selection of Look and Feel Themes that affect window appearance
  - __Plasma theme__ appears to affect the appearance of widgets only

## Comparison with other OSes
File dialogs have highly configurable views, with icon sizes scalable from 16 to 128 px and filenames available to the side or below the icon.
- A view similar to the Icons view in Mac OS X or the List view in Windows can be reproduced by setting View to the icon size to the minimum 16px and placing the filename to the side (`Icon Position` > `Next to file name`)

## Wallpapers
Wallpaper types "Haenau" and "Hunyango" are QML (Qt Modeling Language) animated wallpapers that were introduced in Plasma 5.1 (2014)

## Widgets
"Plasmoids" are dragged and dropped onto the Desktop, where they function as buttons. A long click will allow them to be moved, rotated, or resized. Each plasmoid can be configured with a keyboard shortcut. They occupy all virtual desktops
One plasmoid in particular is the "Grouping Plasmoid", which allows other plasmoids to be placed within it, where they occupy separate tabs. 

## Login manager
Workspace > Startup and Shutdown > Login Screen (SDDM)
The advanced tab allows you to select Mouse cursor theme and auto login of user and session type. These appear to affect specifically settings in /etc/sddm.conf (`Session=gnome-xorg` under `[Autologin]`)

## Default shortcuts
Workspace > Shortcuts > Global Shortcuts
"Run Command" refers to `krunner`, a single-line application launcher similar to the Run command on Windows.
- __Alt-t__ : open a terminal window

## Restarting KDE Plasma
Source: [Lifewire](https://www.lifewire.com/kubuntu-p2-2202573)

#### Restarting KDE Plasma 4
```sh
killall plasma-desktop
kstart plasma-desktop
```

#### Restarting KDE Plasma 5
```sh
killall plasmashell
kstart plasmashell
```

```sh
kquitapp5 plasmashell
kstart plasmashell
```

## Commands
#### kquitapp
Allows you to quit a dbus enabled application. Two options:
##### Specify service to be stopped
```sh
kquitapp --service
```
##### Specify path to dbus interface 
```sh
kquitapp --path
```
#### kstart
When used to launch an application, prevents the application from being tied to the terminal.
#### krunner
single-line application launcher, similar to dmenu or the Run command on Windows
