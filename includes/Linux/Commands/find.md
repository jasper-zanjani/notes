#### find
:   
    Search for files in a directory hierarchy
    Find all files in $PATH that are owned by $USER
    ```sh
    find $PATH -user $USER
    ```

    Find recently modified files/folders
    
    There are 3 timestamps associated with files in Linux 

    - **`atime`** "access time": last time file was accessed by a command or application
    - **`mtime`** "modify time": last time file's contents were modified
    - **`ctime`** "change time": last time file's attribute was modified 

    Numerical arguments can be specified in 3 ways:

    - **`+n`** greater than {n} days ago
    - **`-n`** less than {n} days ago
    - **`n`** exactly n days ago
    ```sh
    find $PATH -type f -mtime +120 -ls # Find only files that were modified more than 120 days ago
    find $PATH -type f -mtime -15 -ls # Modified less than 15 days ago
    find $PATH -type f -mtime 10 -ls # Modified exactly 10 days ago

    # Find files modified over the past day
    find $PATH -type f -newermt "1 day ago" -ls
    find $PATH -type f -newermt "-24 hours" -ls
    find $PATH -type f -newermt "yesterday" -ls

    find $PATH -type f -ctime -1 -ls # Find files created today
    ```
