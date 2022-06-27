# GNOME

GTK3 attempted to get away from strong dependency on theming engines by introducing CSS stylesheets.
This was supposed to make application theming simple and portable.

In GTK4 you can choose either a theming engine or CSS stylesheets.

#### Keyring
:   
    [GNOME Keyring](https://wiki.gnome.org/action/show/Projects/GnomeKeyring) is a collection of components that store and manage application access to secrets, passwords, keys, and certificates.

    GNOME Keyring can be managed:
    
    - [Seahorse](https://wiki.gnome.org/Apps/Seahorse) via GUI
    - secret-tool which uses (and is included in) [libsecret](https://gitlab.gnome.org/GNOME/libsecret)
    - [gnome-keyring-query](https://web.archive.org/web/20160326164641/http://www.gentoo-wiki.info/HOWTO_Use_gnome-keyring_to_store_SSH_passphrases) which uses the archived [libgnome-keyring](https://gitlab.gnome.org/GNOME/libgnome-keyring)


#### Extensions
:   
    GNOME Extensions provide a variety of popular hacks and changes to the Shell.
    They are managed by [gnome-extensions-app](https://gitlab.gnome.org/GNOME/gnome-shell/-/tree/HEAD/subprojects/extensions-app) but they are typically added from the [GNOME Extensions website](https://extensions.gnome.org/) using a browser plugin.

    These extensions are added to **~/.local/share/gnome-shell/extensions**, but many of them can also be made available to all users by installing them using a package manager, in which case they are placed in **/usr/share/gnome-shell/extensions**.

    Extensions appear to be mostly JavaScript applications, so they can probably simply be git cloned into the respective directories as well.

#### Configuration
:   
    **dconf** is a key-based blob database for storing GNOME configurations and application settings. These settings are stored as **keys** grouped under **paths** in a way analogous to the Windows Registry. 

    - **dconf** is also a [CLI utility](#dconf) for reading and writing individual values or entire directories to and from a dconf database. 
    Direct manipulation of dconf is discouraged, rather users and developers are encouraged to use [dconf-editor](#dconf-editor) or [gsettings](#gsettings).
    - **GSettings** is a high-level API for application settings that serves as the frontend for [dconf](#dconf) as well as a [CLI utility](#gsettings-1) for changing user settings.

    A **dconf profile** is a list of binary [dconf](#dconf) databases, typically stored at **/etc/dconf/profile/user**

    Here is a representative dconf profile. **user** is the name of the user database, typically found at **~/.config/dconf/** or **/etc/dconf/profile/user** and **local** and **site** refer to binary databases named as such in **/etc/dconf/db/**.
    ```sh
    service-db:keyfile/user # (1)
    user-db:user
    system-db:local
    system-db:site
    ```

    1. This line sets the **dconf keyfile backend**, required when home directories are mounted over NFS

    **Keyfiles** are INI-format configs placed in directories like **local.d/** that allow dconf settings to be specified declaratively.
    ```ini
    [org/gnome/desktop/input-sources]
    xkb-options=['terminate:ctrl_alt_bksp', 'compose:ralt'] # (1)
    ```

    1. Equivalent to:
    ```sh
    gsettings set org.gnome.desktop.input-sources xkb-options=['terminate:ctrl_alt_bksp', 'compose:ralt']
    ```

## Tasks

#### Desktop background
:   
    Create a keyfile for the local database in **/etc/dconf/db/local.d/01-background**
    ```ini
    [org/gnome/desktop/background]

    picture-uri='file:///usr/local/share/backgrounds/wallpaper.jpg'
    picture-options='scaled'
    primary-color='000000'
    secondary-color='FFFFFF'
    ```

#### Custom application shortcut
:   
    Custom shortcuts are stored in dconf using a ["relocatable schema"](https://wiki.ubuntu.com/Keybindings) which has three keys: **name**, **command**, and **binding**.

    ```sh
    gsettings set org.gnome.setting-daemon.plugins.media-keys.custom-keybinding:/org/gnome/settings-daemon/plugins/media-keys/custom-keybindings/custom0 name 'Terminal'
    gsettings set org.gnome.setting-daemon.plugins.media-keys.custom-keybinding:/org/gnome/settings-daemon/plugins/media-keys/custom-keybindings/custom0 binding '<Super>Enter'
    gsettings set org.gnome.setting-daemon.plugins.media-keys.custom-keybinding:/org/gnome/settings-daemon/plugins/media-keys/custom-keybindings/custom0 command '/usr/bin/gnome-terminal'
    ```

    Note that this doesn't seem to work...

#### File associations
:   
    File associations are stored in .desktop files stored in **/usr/share/applications/**. 
    These INI-format files store all kinds of metadata on installed applications, including names and keywords in all supported languages.
    Filetypes are stored under the **MimeType** key as semicolon-delimited [MIME Types](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/desktop_migration_and_administration_guide/file_formats).

    ```ini
    [Desktop Entry]
    Type=Application
    MimeType=application/x-newtype
    Name=My Application 1
    Exec=myapplication1
    ```

    MIME Type descriptors as stored as XML files stored in **/usr/share/mime/packages/**:

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <mime-info xmlns="http://www.freedesktop.org/standards/shared-mime-info">
      <mime-type type="application/x-newtype">
        <comment>new mime type</comment>
        <glob pattern="*.xyz"/>
      </mime-type>
    </mime-info>
    ```

## Applications

--8<--
includes/Linux/Commands/dconf.md"
includes/Linux/Commands/gio.md
includes/Linux/Commands/gsettings.md
includes/Linux/Commands/notify-send.md
--8<--