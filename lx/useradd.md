# useradd

Short option | Long option    | Effect
:--- | :---                   | :---
`-b` | `--base-dir BASE_DIR`  | default base directory for the system if `-d HOME_DIR` is not specified; if `-m` is not used, `BASE_DIR` must exist
`-c` | `--comment COMMENT`    | generally a short description of the login, currently used as the field for the user's full name
`-d` | `--home-dir HOME_DIR`  | new user will be created using `HOME_DIR` as the value for the user's login directory
`-D` | `--defaults`
`-e` | `--expiredate`         | date on which the user account will be disabled (`YYYY-MM-DD`)
`-f` | `--inactive`
`-g` | `--gid`
`-G` | `--groups`
`-h` | `--help`
`-k` | `--skel`
`-K` | `--key`
`-l` | `--no-log-init`
`-m` | `--create-home`
`-M` | `--no-create-home`
`-N` | `--no-user-group`
`-o` | `--non-unique`
`-p` | `--password`
`-r` | `--system`
`-R` | `--root`
`-P` | `--prefix`
`-s` | `--shell`
`-u` | `--uid`
`-U` | `--user-group`
`-Z` | `--selinux-user`

## Configuration

Value | Description
:---  | :---
`CREATE_HOME`
`GID_MAX`
`GID_MIN`
`MAIL_DIR`
`MAIL_FILE`
`MAX_MEMBERS_PER_GROUP`
`PASS_MAX_DAYS`
`PASS_MIN_DAYS`
`PASS_WARN_AGE`
`SUB_GID_MAX`,`SUB_GID_MIN`,`SUB_GID_COUNT`
`SUB_UID_MAX`,`SUB_UID_MIN`,`SUB_UID_COUNT`
`SYS_GID_MAX`,`SYS_GID_MIN`
`SYS_UID_MAX`,`SYS_UID_MIN`
`UID_MAX`, `UID_MIN`
`UMASK`
`USERGROUPS_ENAB`

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



Syntax | Effect
:--- | :---
`useradd -s /bin/bash` | create a new user, setting their default shell to /bin/bash
`useradd -m -g wheel luke` | create a new user account {luke} belonging to default group {wheel}, creating a home directory
`useradd -c "comment"` | create a new user account with {comment}
`useradd -G grp1 grp2` | create a new user account, adding it to groups {grp1} and {grp2}
`useradd -u UUID` | create a new user account, specifying {UUID}


