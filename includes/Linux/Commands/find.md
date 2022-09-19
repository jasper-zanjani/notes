*[atime]: access time
*[mtime]: modify time
*[ctime]: change time

#### find
:   
    Search for files in a directory hierarchy
    
    ```sh title="Find all files owned by user"
    find . -user $USER
    ```

    **-exec** allows a command to be executed for every foudn file, which has to be terminated with an escaped semicolon, i.e. **`\;`**.

    ```sh title="Remove whitespace from filenames"
    find . -type f -name "* *" -exec bash -c 'mv "$0" "${0// /_}"' {} \;
    ```

    Find recently modified files/folders
    
    There are 3 timestamps associated with files in Linux 

    - **atime** "access time": last time file was accessed by a command or application
    - **mtime** "modify time": last time file's contents were modified
    - **ctime** "change time": last time file's attribute was modified 

    Numerical arguments can be specified in 3 ways:

    - **`+n`** greater than {n} days ago
    - **`-n`** less than {n} days ago
    - **`n`** exactly n days ago
    
    ```sh
    # Find only files that were modified more than 120 days ago
    find . -type f -mtime +120 -ls

    # Modified less than 15 days ago 
    find . -type f -mtime -15 -ls

    # Modified exactly 10 days ago 
    find . -type f -mtime 10 -ls 

    # Find files modified over the past day
    find . -type f -newermt "1 day ago" -ls
    find . -type f -newermt "-24 hours" -ls
    find . -type f -newermt "yesterday" -ls

    # Find files created today
    find . -type f -ctime -1 -ls 
    ```

    