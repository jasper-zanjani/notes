#### chown
:   
    Change a file or directory's ownership. 
    
    To change the user and group owner of a file to `$USER` and `$GROUP`:

    ```sh
    chown $USER:$GROUP $file
    ```

    Recursively grant `$USER` ownership to `$PATH`
    ```sh
    chown -R $USER $PATH
    ```

    Use a **reference** file to match the configuration of a particular file
    ```sh
    chown -vR --reference=. $PATH
    ```

    `--preserve-root` prevents changes to files in the root directory but only when used together with `--recursive`
    
    ```sh
    chown -cfR --preserve-root $USER 
    ```
