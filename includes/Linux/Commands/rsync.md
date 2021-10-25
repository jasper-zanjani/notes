#### rsync
:   
    [rsync -&#116;]: #rsync 'Preserve original modification timestamp&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
    [rsync -&#118;]: #rsync 'Verbose output&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
    [rsync -&#114;]: #rsync 'Recursive (transfer entire directory)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
    [rsync -&#108;]: #rsync 'Maintain symbolic links&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
    [rsync -&#112;]: #rsync 'Preserve original permissions&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 132'
    [rsync -&#97;]: #rsync 'Copy recursively, preserving group, owner, modification times, and device-files (if super-user) (equivalent to `-rptlgoD`)'
    [rsync -&#98;]: #rsync 'Create a backup of every file transferred'
    [rsync -&#101;]: #rsync 'Specify remote shell to use'
    [rsync -&#103;]: #rsync 'Preserve group'
    [rsync -&#111;]: #rsync 'Preserve owner'
    [rsync --delete]: #rsync 'Remove files and folders that are not in the sender system'
    [rsync --exclude]: #rsync 'Exclude files (accepts globbing)'
    [rsync --include]: #rsync 'Specify specific files (accepts globbing)'
    [rsync --progress]: #rsync 'Display a progress bar'
    [rsync --remove-source-files]: #rsync 'Remove original files after synchronization'
    [rsync -&#122;]: #rsync 'Compress file data during the transfer'

    <code>&nbsp;</code> [`a`][rsync -&#97;] [`b`][rsync -&#98;] <code>&nbsp;</code> <code>&nbsp;</code> [`e`][rsync -&#101;] <code>&nbsp;</code> [`g`][rsync -&#103;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][rsync -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> [`o`][rsync -&#111;] [`p`][rsync -&#112;] <code>&nbsp;</code> [`r`][rsync -&#114;] <code>&nbsp;</code> [`t`][rsync -&#116;] <code>&nbsp;</code> [`v`][rsync -&#118;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`z`][rsync -&#122;] 


    Copy $FILE locally 
    ```sh
    rsync -zvr $FILE $PATH
    ```

    Copy $FILE to $PATH on remote $HOST
    ```sh
    rsync $FILE $HOST:$PATH
    ```

    Copy $FILE from $HOST to local $PATH
    ```sh
    rsync $HOST:$FILE $PATH
    ```

    Copy `$DIR` recursively
    ```sh
    rsync -zvr $DIR $PATH
    rsync -avz $DIR $PATH
    ```

    Copy to remote systems over SSH
    ```sh
    rsync -zvre ssh $DIR $HOST:$REMOTEPATH
    rsync -avze ssh $DIR $HOST:$REMOTEPATH
    ```

    Synchronize only specific file type
    ```sh
    rsync -zvre ssh --include '*.php' --exclude '*' $PATH
    ```