#### Xmonad
:   
    ```sh title="Install"
    dnf install xmonad \
                xterm dmenu # (1)
    ```

    1. At the [recommendation](https://youtu.be/3noK4GTmyMw?t=190 "YouTube: Getting Started With Xmonad") of DistroTube.
    
    Default keybindings which must be known by the neophyte:

    | Default keybinding  | Description |
    | ------------------- | ----------- |
    | ++Alt+Shift+Enter++ | Terminal    |
    | ++Alt+Shift+C++     | Close pane  |

    The config is typically placed in **$XDG\_CONFIG\_HOME/xmonad/** (resolving to ~/.config/xmonad/), although other locations are possible.
    A good default config is available [here](http://code.haskell.org/xmonad/man/xmonad.hs).

    Change Mod key to Super
    ```haskell
    myModMask = mod4Mask
    ```

    