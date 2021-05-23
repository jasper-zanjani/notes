### sudo

**/etc/sudoers**{: #sudoers }

The sudoers file contains **user specifications** that define commands that users may execute.

```
$USER $HOST = ($RUNAS) $CMD
```

- **$USER**: usernames, UIDs, group names when prefixed with `%` i.e. `%wheel`, or GIDs when prefixed with `%#`
- **$HOST**: hostnames, IP addresses, or a CIDR range (i.e. `192.0.2.0/24`)
- **$RUNAS**: optional clause that controls the user or group sudo will run the command as. If a username is is specified, sudo will not accept a `-g` argument when runing sudo. 
- **$CMD**: full path to an executable, or a comma-delimited list of commands.

Any of these elements can be replaced with the keyword **`ALL`**.


Ansible service account
```
ansible ALL=(ALL) NOPASSWD: ALL
```





Allow sudo access to user only for command `/bin/mkdir`
```
linuxize ALL=/bin/mkdir
```
Allow user `linuxize` to run `sudo` commands without authenticating himself
```
linuxize ALL=(ALL) NOPASSWD: ALL
```
Change timeout to 10 minutes
```
Defaults timestamp_timeout=10
```
Change timeout to 10 minutes only for user `linuxize`
```
Defaults:linuxize timestamp_timeout=10
```