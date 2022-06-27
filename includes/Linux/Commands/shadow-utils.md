#### gpasswd
:   
    Administer /etc/group and /etc/gshadow 
    
    ```sh title="Add user to group"
    gpasswd -a $USER $GROUP
    ```
    ```sh title="Add user as admin of group"
    gpasswd -A $USER $GROUP
    ```
    ```sh title="Remove user from group"
    gpasswd -d $USER $GROUP
    ```

#### groupadd
:   

#### groupdel
:   

#### groupmod
:   

#### useradd
:   
    ```sh title="Add user"
    useradd $USER               \
            -m                  \ # Create home directory
            -d $PATH            \ # Specify home directory
            -s /bin/bash        \ # Default shell
            -c $FULLNAME        \ # Note full name in comment
            -G $GROUP1 $GROUP2  \ # Add groups        
            -u $UID             \ # Specify user ID
            -e $DATE            \ # Specify expiration date (YYYY-MM-DD)
            -r                  \ # System user
    ```

    Useradd's config is at **/etc/default/useradd** but it also inherits settings from **/etc/login.defs**.
    

    ```ini title="Example config"
    # useradd defaults file for ArchLinux
    # original changes by TomK
    GROUP=users
    HOME=/home
    INACTIVE=-1
    EXPIRE=
    SHELL=/bin/bash
    SKEL=/etc/skel
    CREATE_MAIL_SPOOL=no
    ```

    These settings can be displayed with:
    ```sh
    useradd -D
    ```


#### userdel
:   
    Delete an existing user account as well as the user's home directory
    ```sh
    userdel -r $USER
    ```

#### usermod
:   

