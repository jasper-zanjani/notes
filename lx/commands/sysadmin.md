### `adduser`
Create a new user (on Debian systems, preferred to `useradd`)
```sh
adduser 
```
### `chage`
Change user password expiry information
Remove expiration date from an account
```sh
chage -E -1 user
```
Set the date (or number of days since January 1, 1970) on which the user's account will no longer be accessible to {date} (YYYY-MM-DD)
```sh
chage -E $DAYS 
chage --expiredate $DAYS
```
Set the maximum number of days during which a password is valid
```sh
chage -M $DAYS 
chage --maxdays $DAYS
```
Set the minimum number of days between password changes
```sh
chage -m $DAYS
chage --mindays $DAYS
```
Set the number of days of warning before a password change is required
```sh
chage -W days chage --warndays days
```
### `chcon`
Change context for website directory
```sh
chcon -Rv --type=httpd_sys_content_t website
```
### `chgrp`
Change ownership of `$FILE` to `$USER` and `$GROUP`
```sh
chgrp $USER:$GROUP $FILE
```
### `chmod`
Set sticky bit on `$FILE`
```sh
chmod +t $FILE
```
Clear sticky bit on `$FILE`
```sh
chmod -t file
```
Clear SGID bit on `$FILE`
```sh
chmod g-s file
```
Set SGID bit on `$FILE`
```sh
chmod g+s file
```
Clear SUID bit on `$FILE`
```sh
chmod u-s file
```
Set SUID bit on `$FILE`
```sh
chmod u+s file
```
Set `setuid` permission on `$FILE`
```sh
chmod +s file
```
### `chpass`
Change default shell to Fish
```sh
chpass -s /usr/local/bin/fish
```
### `chrony`
Synchronize system time using NTP (cf. [`timedatectl`][timedatectl]

Stop the `systemd-timesyncd` service
```sh
sudo systemctl stop systemd-timesyncd.service
```
Install `chrony` if it is not already present and enable and start the service
```sh
sudo systemctl enable chronyd && sudo systemctl start chronyd
```
### `chsh`
Change the user's default shell to Bash
```sh
chsh-s /bin/bash
```
Change the user's default shell to Fish
```sh
chsh-s /usr/local/bin/fish
```
### `chown`
Change a file or directory's ownership. To change the user and group owner of a file to {user} and {group}, `chown`'s syntax is of the format `user:group` [[32](sources.md)].
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
### `free`
Simple utility that displays realtime memory information.

Option  | Effect
:---    | :---
`-c`    | run the program {n} times
`-h`    | human-readable output
`-s`    | run the program every {n} seconds, until the program is manually interrupted

List memory statistics in kilobytes. Without any options, `free` returns a table listing general statistics in kilobytes:
```bash
free
```
Command-line memory dashboard
```bash
watch free -h
```
### `getent`
Get entries from the `passwd` file [[50](sources.md)]
```sh
getent passwd sonny timmy
```
```
sonny:x:1001:1002:Sonny:/home/sonny:/bin/bash
timmy:x:1002:1003::/home/timmy:/bin/bash
```

```sh
getent group sonny timmy
```
```
sonny:x:1002:
timmy:x:1003:
```
### `gpasswd`
Add `$USER` to `$GROUP`
```sh
gpasswd -a $USER $GROUP
```
Add `$USER` as admin of `$GROUP`
```sh
gpasswd -A $USER $GROUP
```
Remove `$USER` from `$GROUP`
```sh
gpasswd -d $USER $GROUP
```
### `groupadd`
Create a new group
### `groupdel`
Delete a group
### `groupmod`
Modify definition of specified group by modifying the appropriate entry in the group database

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-n`    | `--newname`             | Rename {$GROUP} to {$NEWNAME}

[groupadd]: useradd.md#groupadd "Create a new group"
### `ps`
Display processes in a tree-like display illustrating parent-child relationships
```sh
ps -f
ps --forest
```
Show system processes
```sh
ps ax
ps -e
```
Display full listing of processes
```sh
ps u
ps -f
```
Display user processes
```sh
ps xG
ps -a
```
Display SELinux contexts for processes
```sh
ps auxZ
```
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
### `top`
Option  | Effect
:---    | :---
`-n`    | change update interval
### `uname`

Option  | Effect
:---    | :---
`-a`    | display all information
`-s`    | display the kernel name
`-n`    | display the network node (i.e. host name)
`-v`    | display version (date) of the kernel
`-m`    | display the machine hardware name
`-p`    | display the processor type
`-r`    | display operating system release number
`-o`    | display operating system

Check kernel version
```bash
uname -srm
```
### `useradd`
Create a new user

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-b`    | `--base-dir`         | default base directory for the system if `HOME_DIR` is not specified (sets `HOME` variable in [/etc/default/useradd](#etcdefaultuseradd)
`-c`    | `--comment`          | typically user's full name
`-d`    | `--home-dir`         | specify user's login directory: default is to append the `LOGIN` name to `BASE_DIR`
`-D`    | `--defaults`         | view **d**efaults for new users
`-e`    | `--expire-date`      | specify date on which the user account will be disabled (in format `YYYY-MM-DD`) (sets `EXPIRE` variable in [/etc/default/useradd](#etcdefaultuseradd))
`-k`    | `--skel`             | specify skeleton directory (defaulting to definition of `SKEL` variable in [/etc/default/useradd](#etcdefaultuseradd), failing to /etc/skel)
`-m`    | `--create-home`      | create user's home directory if it does not exist, copying contents of skeleton directory
`-r`    | `--system`           | create a system account
`-s`    | `--shell`            | specify user's login shell (defaulting to definition of `SHELL` variable in [/etc/default/useradd](#etcdefaultuseradd), failing to an empty string)
`-u`    | `--uid`              | specify UID

File                  | Description
:---                  | :---
/etc/passwd
/etc/shadow
/etc/group
/etc/gshadow
/etc/default/useradd
/etc/skel/
/etc/subgid
/etc/subuid
/etc/login.defs

Create a new user, setting their default shell to /bin/bash
```
useradd -s /bin/bash
```
Create a new user account {luke} belonging to default group {wheel}, creating a home directory
```
useradd -m -g wheel luke
```
Create a new user account with {comment}
```
useradd -c "comment"
```
Create a new user account, adding it to groups {grp1} and {grp2}
```
useradd -G grp1 grp2
```
Create a new user account, specifying {UUID}
```
useradd -u UUID
```

Add {user}
```sh
useradd user
```
Add {user}, noting her full {name}
```sh
useradd user -c name
```
Add {user}, specifying home directory at {path}
```sh
useradd user -d path
```
Add {user}, specifying expiration {date} (YYYY-MM-DD)
```sh
useradd user -e date
```
Create new {user} leaving a {comment} field (conventionally noting the full name of the user) and creating a home directory
```sh
useradd -c comment -m user
```
Create a system user rather than a normal user
```sh
useradd -r
```
### `userdel`
Delete an existing user account

Delete an existing user account as well as the user's home directory
```sh
userdel -r  user
```
### `usermod`

Modify user account files

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-a`    | `--append`              | add user to supplementary group(s), only used with `-G`
`-G`    | `--groups`              | specify a list of groups to which the user will be added
`-l`    | `--login`               | change user's name or "login"
`-L`    | `--lock`                | lock a user's password
`-u`    | `--uid`                 | change UID
`-U`    | `--unlock`              | unlock account

Lock account of `user`
```sh
usermod -L $USER
```
Rename `$USER` `$NEW`
```sh
usermod -l $USER $NEW
```
Unlock account of `$USER`
```sh
usermod -U $USER
```
Add `$USER` to `$GROUP`
```sh
usermod $USER -a -G $GROUP
```







