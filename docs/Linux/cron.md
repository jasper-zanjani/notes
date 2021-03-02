### crontab
| Directive             | Effect                    |
| --------------------- | ------------------------- |
| `@hourly`             | equivalent to `0 * * * *` |
| `@midnight` `@daily`  | equivalent to `0 0 * * *` |
| `@weekly`             | equivalent to `0 0 * * 0` |
| `@monthly`            | equivalent to `0 0 1 * *` |
| `@annually` `@yearly` | equivalent to `0 0 1 1 *` |
| `@reboot`             | run at startup            |

Run /root/backup.sh at 0300 everyday
```sh
0 3 * * * /root/backup.sh
```
Run /path/to/script.sh at 16:30 on the 2nd of every month
```sh
30 16 2 * * /path/to/script.sh
```
Run /scripts/phpscript.php at 22:00 every weekday
```sh
0 22 * * 1-5 /scripts/phpscript.php
```
Run /path/to/perlscript.pl at 00:23, 02:23, and 04:23 everyday
```sh
23 0-23/2 * * * /path/to/perlscript.pl
```
Run `linuxcommand` at 04:05 every Sunday
```sh
5 4 * * sun /path/to/linuxcommand
```