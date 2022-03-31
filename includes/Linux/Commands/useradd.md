#### useradd
:   
    Create a new user, setting their default shell to /bin/bash
    ```sh
    useradd -s /bin/bash
    ```
    Create a new user account {luke} belonging to default group {wheel}, creating a home directory
    ```sh
    useradd -m -g wheel luke
    ```
    Create a new user account with {comment}
    ```sh
    useradd -c "comment"
    ```
    Create a new user account, adding it to groups {grp1} and {grp2}
    ```sh
    useradd -G grp1 grp2
    ```
    Create a new user account, specifying {UUID}
    ```sh
    useradd -u UUID
    ```
    Add `$USER`
    ```sh
    useradd $USER
    ```
    Add `$USER`, noting her full `$NAME`
    ```sh
    useradd $USER -c $NAME
    ```
    Add `$USER`, specifying home directory at `$PATH`
    ```sh
    useradd $USER -d $PATH
    ```
    Add `$USER`, specifying expiration `$DATE` (YYYY-MM-DD)
    ```sh
    useradd $USER -e $DATE
    ```
    Create new `$USER` leaving a `$COMMENT` field (conventionally noting the full name of the user) and creating a home directory
    ```sh
    useradd -c $COMMENT -m $USER
    ```
    Create a system user rather than a normal user
    ```sh
    useradd -r
    ```

    ## 🛠&#xfe0f; Config

    /etc/default/useradd

    Default values for account creation. Properties: `EXPIRE`, `GROUP`, `HOME`, `INACTIVE`, `SHELL`, `SKEL`


    [useradd -&#98;]:               #useradd                       '```&#10;$ useradd -b&#10;$ useradd --base-dir&#10;```&#10;Default base directory for the system if `$HOME_DIR` is not specified (sets `$HOME` variable in /etc/default/useradd)'
    [useradd -&#99;]:               #useradd                       '```&#10;$ useradd -c $COMMENT&#10;$ useradd --comment $COMMENT&#10;```&#10;Set comment or GECOS field for user&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#100;]:              #useradd                       '```&#10;$ useradd -d $HOMEDIR&#10;$ useradd --home-dir $HOMEDIR&#10;```&#10;Specify home directory for user&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#68;]:               #useradd                       '```&#10;$ useradd -D&#10;$ useradd --defaults&#10;```&#10;List (and optionally change) system default values&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 323'
    [useradd -&#101;]:              #useradd                       '```&#10;$ useradd -e&#10;$ useradd --expire-date&#10;```&#10;Set account expiration date&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#102;]:              #useradd                       '```&#10;$ useradd -f&#10;```&#10;Set account inactive value&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#103;]:              #useradd                       '```&#10;$ useradd -g&#10;```&#10;Specify primary group&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#71;]:               #useradd                       '```&#10;$ useradd -G&#10;```&#10;Specify secondary groups&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#107;]:              #useradd                       '```&#10;$ useradd -k&#10;$ useradd --skel&#10;```&#10;Specify skel directory&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#109;]:              #useradd                       '```&#10;$ useradd -m&#10;$ useradd --create-home&#10;```&#10;Create and populate the home directory&#10;Haeder, Adam. _LPI Linux Certification in a Nutshell_. 2010.: 323'
    [useradd -&#114;]:              #useradd                       '```&#10;$ useradd -r&#10;$ useradd --system&#10;```&#10;Create a system account'
    [useradd -&#115;]:              #useradd                       '```&#10;$ useradd -s $SHELL&#10;$ useradd --shell $SHELL&#10;```&#10;Specify login shell&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
    [useradd -&#117;]:              #useradd                       '```&#10;$ useradd -u&#10;$ useradd --uid&#10;```&#10;Specify UID&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 94'
