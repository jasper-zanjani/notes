# useradd

Short option  | Long option    | Effect
:---          | :---                   | :---
`-b`          | `--base-dir BASE_DIR`  | default base directory for the system if `-d HOME_DIR` is not specified; if `-m` is not used, `BASE_DIR` must exist
`-c`          | `--comment COMMENT`    | generally a short description of the login, currently used as the field for the user's full name
`-d`          | `--home-dir HOME_DIR`  | new user will be created using `HOME_DIR` as the value for the user's login directory
`-e`          | `--expiredate`         | date on which the user account will be disabled (`YYYY-MM-DD`)
## Files

File | Description
:--- | :---
/etc/passwd
/etc/shadow
/etc/group
/etc/gshadow
/etc/default/useradd
/etc/skel/
/etc/subgid
/etc/subuid
/etc/login.defs

#### Create a new user, setting their default shell to /bin/bash
```
useradd -s /bin/bash
```
#### Create a new user account {luke} belonging to default group {wheel}, creating a home directory
```
useradd -m -g wheel luke
```
#### Create a new user account with {comment}
```
useradd -c "comment"
```
#### Create a new user account, adding it to groups {grp1} and {grp2}
```
useradd -G grp1 grp2
```
#### Create a new user account, specifying {UUID}
```
useradd -u UUID
```


