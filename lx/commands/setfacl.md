### `setfacl`
Set file access control list

Option  | POSIX option  | Description
:---    | :---          | :---
`-b`    | `--remove-all` | remove all extended ACL entries, retaining the base ACL entries of the owner, group, and others
`-k`    | `--remove-default` | remove the Default ACL
`-m`    | `--modify` | modify ACL of a directory
`-M`    | `--modify-file` | modify ACL of a file
`-s`    |               | overwrite or **s**et
`-x`    | `--remove` | remove ACL entries from a directory
`-X`    | `--remove-file` | remove ACL entries from a file

Grant user {lisa} right to read {file}
```sh
setfacl -m u:lisa:r file
```
Remove named group {staff} from {file}'s ACL
```sh
setfacl -x g:staff file
```
Modify file access control list for {file} to revoke write access from all groups and all named users
```sh
setfacl -m m::rx file
```
Grant read access to **o**ther users
```sh
setfacl -m o::rwx file4.txt
```
Add user {zach} to list of users of file4.txt
```sh
setfacl -m u:zach:rw file4.txt
```