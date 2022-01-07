#### setfacl
:   
    [Clear](https://unix.stackexchange.com/questions/339765/how-to-remove-acl-from-a-directory-and-back-to-usual-access-control) FACL from a directory
    ```sh
    setfacl -bn foo
    ```
    Grant user {lisa} right to read $FILE
    ```sh
    setfacl -m u:lisa:r $FILE
    ```
    Remove named group {staff} from $FILE's ACL
    ```sh
    setfacl -x g:staff $FILE
    ```
    Modify file access control list for $FILE to revoke write access from all groups and all named users
    ```sh
    setfacl -m m::rx $FILE
    ```
    Grant read access to **o**ther users
    ```sh
    setfacl -m o::rwx $FILE
    ```
    Add user {zach} to list of users of file4.txt
    ```sh
    setfacl -m u:zach:rw $FILE
    ```
