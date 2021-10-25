#### rename
:   
    Use regular expressions to rename multiple files

    ```sh
    # Renaming file.old to file.new
    rename 's/old/new/' this.old

    # Use globbing to rename all matching files
    rename 's/old/new/' *.old
    rename 's/report/review/' *

    # Change all uppercase letters to lowercase
    rename 'y/A-Z/a-z/' *
    ```