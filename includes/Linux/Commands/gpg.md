#### gpg
:   
    --8<-- "includes/Linux/Tasks/gpg.md"

    Decrypt file
    ```sh
    gpg file.txt
    ```
    
    Export GPG public key
    ```sh
    gpg --export --output ~/jdoe.pub
    ```
    
    Import another person's public key
    ```sh
    gpg --import jdoe.pub
    ```
    
    List available GPG keys
    ```sh
    gpg --list-key
    ```
    
    Encrypt a file
    ```sh
    gpg --encrypt -r jdoe@dplaptop.lab.itpro.tv $FILE
    ```
    
    Sign $FILE without encrypting it (produces file.asc)
    ```sh
    gpg --clearsign $FILE
    ```
    
   
    Import another person's public key
    ```sh
    gpg --import ~/jdoe.pub
    ```
    
    Send keys to **$SERVER**
    ```sh
    gpg --send-keys keyIDs --keyserver $SERVER
    ```