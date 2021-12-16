#### flatpak
:   
    Flatpak is one of several recent containerized application distribution solutions for Linux.
    
    Flatpak runtimes are compiled reproducibly using [BuildStream](https://www.buildstream.build/) and they are installed in **/var/lib/flatpak/runtime**.
    Like Steam, flatpak uses [BubbleWrap](https://github.com/containers/bubblewrap) to implement sandboxing.

    Flathub is the de facto Flatpak repo, but it must be added to flatpak installations manually.
    ```sh
    flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
    
    # Confirming success
    flatpak remotes 
    ```

    Display installed flatpak applications, including runtime
    ```sh
    flatpak list --app --runtime
    ```

    Output columns can also be specified individually after `--column` (comma-delimited)
    ```sh
    flatpak list --app --columns=name,application,runtime
    ```

    Flatpak applications sometimes do not adopt the [system theme](https://itsfoss.com/flatpak-app-apply-theme/).
    The workaround involves first granting some or all applications access to the themes folder.
    ```sh
    flatpak override --filesystem=$HOME/.themes
    ```

    Then apply the theme by setting the `GTK_THEME` environment variable.
    The value of this variable must be the folder name of a theme installed to the themes folder (typically **~/.themes**).
    ```sh
    flatpak override --env=GTK_THEME=my-theme 
    ```

    The value of the current theme can be retrieved using [**gsettings**](../Gnome/#gsettings)
    ```sh
    gsettings get org.gnome.desktop.interface gtk-theme
    ```
