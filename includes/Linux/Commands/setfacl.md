#### setfacl
:   
    [setfacl -&#98;]:               #setfacl                       '```&#10;$ setfacl -b&#10;$ setfacl --remove-all&#10;```&#10;Remove all extended ACL entries, retaining the base ACL entries of the owner, group, and others'
    [setfacl -&#107;]:              #setfacl                       '```&#10;$ setfacl -k&#10;$ setfacl --remove-default&#10;```&#10;Remove the default ACL'
    [setfacl -&#109;]:              #setfacl                       '```&#10;$ setfacl -m&#10;$ setfacl --modify&#10;```&#10;Modify ACL of a directory'
    [setfacl -&#77;]:               #setfacl                       '```&#10;$ setfacl -M&#10;$ setfacl --modify-file&#10;```&#10;Modify ACL of a file'
    [setfacl -&#115;]:              #setfacl                       '```&#10;$ setfacl -s&#10;```&#10;Overwrite or "set"'
    [setfacl -&#120;]:              #setfacl                       '```&#10;$ setfacl -x&#10;$ setfacl --remove&#10;```&#10;Remove ACL entries from a directory'
    [setfacl -&#88;]:               #setfacl                       '```&#10;$ setfacl -X&#10;$ setfacl --remove-file&#10;```&#10;Remove ACL entries from a file'

    <code>&nbsp;</code>   <code>&nbsp;</code> [`b`][setfacl -&#98;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`k`][setfacl -&#107;] <code>&nbsp;</code> [`m`][setfacl -&#109;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`s`][setfacl -&#115;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`x`][setfacl -&#120;] <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`M`][setfacl -&#77;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`X`][setfacl -&#88;] <code>&nbsp;</code> <code>&nbsp;</code> 

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
