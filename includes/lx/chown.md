**chown**{: #chown }
:   <code>&nbsp;</code>   <code>&nbsp;</code> <code>&nbsp;</code> [`c`][chown -&#99;] <code>&nbsp;</code> <code>&nbsp;</code> [`f`][chown -&#102;] <code>&nbsp;</code> [`h`][chown -&#104;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`v`][chown -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`H`][chown -&#72;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`L`][chown -&#76;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`P`][chown -&#80;] <code>&nbsp;</code> [`R`][chown -&#82;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

    Change a file or directory's ownership. To change the user and group owner of a file to {user} and {group}, `chown`'s syntax is of the format `user:group` ].
    ```sh
    chown susan:delta file          # Assign {file} to user `susan` and group `delta`
    chown alan file                 # Assign {file} to user `alan`
    chown alan: file                # Assign {file} to user and group `alan`
    chown :gamma file               # Assign {file} to the group `gamma`
    ```
    Recursively grant {user} ownership to {path}
    ```sh
    chown -R user path
    ```
    Assign {path} to `susan` and group `delta`, recursively and with verbose output
    ```sh
    chown --verbose --recursive susan:delta path 
    chown -vR susan:delta path
    ```
    ```sh
    chown -vR --reference=. path    # Use a `reference` file to match the configuration of a particular file
    chown -cfR --preserve-root alan # `preserve-root` prevents changes to files in the root directory, but has no effect when not used with `recursive`
    ```

[chown -&#99;]: #chown '&#10;$ chown -c&#10;$ chown --changes&#10;&#10;Print information about files that are changed&#10;'
[chown -&#102;]: #chown '&#10;$ chown -f&#10;$ chown --quiet&#10;&#10;Do not print error messages about files that cannot be changed.&#10;'
[chown -&#104;]: #chown '&#10;$ chown -h&#10;$ chown --no-dereference&#10;&#10;Change the owner on symbolic links&#10;'
[chown -&#72;]: #chown '&#10;$ chown -H&#10;&#10;When used with `-R`, if a command-line argument is a symbolic link to a directory, recursively traverse the directory.&#10;'
[chown -&#76;]: #chown '&#10;$ chown -L&#10;&#10;When used with `-R`, if any symbolic link points to a directory, recursively traverse the directory&#10;'
[chown -&#80;]: #chown '&#10;$ chown -P&#10;&#10;When used with `-R`, do not follow any symbolic links (default).&#10;'
[chown -&#82;]: #chown '&#10;$ chown -R&#10;$ chown --recursive&#10;&#10;Recursively descend through the directory, including subdirectories and symbolic links. When used with `-H`, `-L`, and `-P` the latest takes precedence.&#10;'
[chown -&#118;]: #chown '&#10;$ chown -v&#10;$ chown --verbose&#10;&#10;Verbose output&#10;'
[chown --dereference]: #chown '&#10;$ chown --dereference&#10;&#10;Change the group of the file pointed to by a symbolic link, not the group of the symbolic link itself (default)&#10;'
[chown --no-preserve-root]: #chown '&#10;$ chown --no-preserve-root&#10;&#10;Do not treat the root directory specially (default)&#10;'
[chown --preserve-root]: #chown '&#10;$ chown --preserve-root&#10;&#10;Do not operate recusrsively on the root directory.&#10;'
[chown --reference]: #chown '&#10;$ chown --reference $FILENAME&#10;&#10;change the group to that associated with `$FILENAME`. In this case, `$NEWGROUP` is not specified&#10;'