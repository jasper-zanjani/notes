#### chmod
:   
    === ":material-plus: Add permissions"

        ```sh
        chmod +t $FILE # Sticky bit
        chmod g+s file # SGID
        chmod u+s file # SUID
        ```

    === ":material-trash-can: Remove permissions"

        ```sh
        chmod -t $FILE # Sticky bit
        chmod g-s file # SGID
        chmod u-s file # SUID
        ```
