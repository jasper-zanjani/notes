### useradd
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
Delete an existing user account;\
Delete an existing user account as well as the user's home directory
```sh
userdel-r  user
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

Lock account of {user}
```sh
usermod -L user
```
Rename {user} {new}
```sh
usermod -l user new
```
Unlock account of {user}
```sh
usermod -U user
```
Add {user} to {group}
```sh
usermod user -a -G group
```

### `adduser`
Create a new user (on Debian systems, preferred to `useradd`)
```sh
adduser 
```

### groupadd
Create a new group

### groupdel
Delete a group

### groupmod
Modify definition of specified group by modifying the appropriate entry in the group database

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-n`    | `--newname`             | Rename {$GROUP} to {$NEWNAME}
