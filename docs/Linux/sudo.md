# sudo
### /etc/sudoers
Allow sudo access to user `linuxize` only for command `/bin/mkdir`
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