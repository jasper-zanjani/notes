# GNOME

GTK3 attempted to get away from strong dependency on theming engines by introducing CSS stylesheets.
This was supposed to make application theming simple and portable.

In GTK4 you can choose either a theming engine or CSS stylesheets.


## Applications

#### dconf
:   
    Update the system databases
    ```sh
    dconf update
    ```

#### dconf-editor
:   
    GUI editor for dconf values

--8<-- "includes/Linux/Commands/gio.md"

--8<-- "includes/Linux/Commands/gsettings.md"

## dconf

- **dconf** is a key-based blob database for storing GNOME configurations and application settings. These settings are stored as **keys** grouped under **paths** in a way analogous to the Windows Registry. dconf is also a [CLI utility](#dconf-1) for reading and writing individual values or entire directories to and from a dconf database.
- **GSettings** is a high-level API for application settings that serves as the frontend for [dconf](#dconf-2) as well as a [CLI utility](#gsettings-1) for changing user settings.

Direct manipulation of dconf is discouraged, rather users and developers are encouraged to use [dconf-editor](#dconf-editor) or [gsettings](#gsettings).

#### dconf profile

A **dconf profile** is a list of binary [dconf](#dconf-2) databases, typically stored at **/etc/dconf/profile/user**

Here is a representative dconf profile. **user** is the name of the user database, typically found at **~/.config/dconf/** and **local** and **site** refer to binary databases named as such in **/etc/dconf/db/**.
```
user-db:user
system-db:local
system-db:site
```

When home directories are mounted over NFS, the **dconf keyfile backend** must be set by placing the following line must be at the top of /etc/dconf/profile/user
```
service-db:keyfile/user
```

**Keyfiles** are INI-format configs placed in directories like **local.d/** that allow dconf settings to be specified declaratively.

```ini
[org/gnome/desktop/input-sources]
xkb-options=['terminate:ctrl_alt_bksp', 'compose:ralt']
```

```sh
gsettings set org.gnome.desktop.input-sources xkb-options=['terminate:ctrl_alt_bksp', 'compose:ralt']
```

## Tasks

Setting default background

Create a keyfile for the local database in **/etc/dconf/db/local.d/01-background**
```ini
[org/gnome/desktop/background]

picture-uri='file:///usr/local/share/backgrounds/wallpaper.jpg'
picture-options='scaled'
primary-color='000000'
secondary-color='FFFFFF'
```

