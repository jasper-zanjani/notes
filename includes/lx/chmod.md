**chmod**{: #chmod }
:   === "Sticky bit"

        ```sh
        # set
        chmod +t $FILE

        # clear
        chmod -t $FILE
        ```

    === "SGID bit"

        ```sh
        # set
        chmod g+s file

        # clear
        chmod g-s file
        ```
    
    === "SUID bit"

        ```sh
        # set
        chmod u+s file

        # clear
        chmod u-s file
        ```

    === "setuid"

        ```sh
        chmod +s file
        ```
