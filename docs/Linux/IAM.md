# Users

## Tasks

#### User management
:   
    ```sh title="Lock user"
    usermod -L $USER # --lock
    passwd -l $USER  # --lock
    ```

    ```sh title="Unlock user"
    usermod -U $USER # --unlock
    passwd -u $USER  # --unlock
    ```

#### Groups
:   
    ```sh title="Display groups of effective user"
    id -Gn
    getent group | grep $(whoami) -
    ```

## Commands

--8<--
includes/Linux/Commands/chage.md

includes/Linux/Commands/getent.md

includes/Linux/Commands/lastb.md

includes/Linux/Commands/sudo.md

includes/Linux/Commands/shadow-utils.md

--8<--