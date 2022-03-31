#### sqlite3
:   
    **sqlite3** is an interactive frontend to the SQLite library.

    **Meta-commands**, prefixed by **`.`**, can be used to examine database files or perform administrative operations.

    ```sql
    .databases  -- (1)
    .tables     -- (2)
    .show       -- (3)
    .exit       
    ```

    1. List names and files of attached databases.
    2. List names of tables matching a given pattern.
    3. Show the current values for various settings.

    Files can be provided on invocation from the command-line or they can be provided after the **.open** meta-command.
    ```sql
    .open database.db
    ```

    Without providing an argument on invocation, sqlite3 will open an in-memory database by default, which can also be explicitly specified with a meta-command.
    ```sql
    .open :memory:
    ```