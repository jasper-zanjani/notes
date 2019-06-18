# crontab

There are 2 types of crontab, taking similar syntax:
  1. User crontabs, where cron jobs take the syntax: `minute hour day month weekday cmd`
  2. System crontabs found in /etc/cron.d/, /etc/cron.hourly, /etc/cron.weekly, or /etc/monthly specify a user: `minute hour day  month weekday user cmd`

Command | Effect
:--- | :---
`crontab -e` | create or __edit__ crontab (using $EDITOR path variable)
`crontab -l` | list cron jobs
`crontab -u user -l` | list {user}'s cron jobs
`crontab -r` | delete all cron jobs
`crontab -u user -r` | delete {user}'s cron jobs
`crontab -u user newcrontab` | replace {user}'s current cron job with newcrontab

Directive | Effect
:--- | :---
`@hourly`|  equivalent to `0 * * * *`
`@midnight`, `@daily` | equivalent to `0 0 * * *`
`@weekly`|  equivalent to `0 0 * * 0`
`@monthly`|  equivalent to `0 0 1 * *`
`@annually`,  `@yearly`| equivalent to `0 0 1 1 *`
`@reboot`|  run at startup

#### Examples
`0 3 * * * /root/backup.sh` run /root/backup.sh at 03:00 everyday
`30 16 2 * * /path/to/script.sh` run /path/to/script.sh at 16:30 on the 2nd of every month
`0 22 * * 1-5 /scripts/phpscript.php` run /scripts/phpscript.php at 22:00 every weekday
`23 0-23/2 * * * /path/to/perlscript.pl` run /path/to/perlscript.pl at 00:23, 02:23, and 04:23 everyday
`5 4 * * sun /path/to/linuxcommand` run linuxcommand at 04:05 every Sunday

#### Files
  - /etc/cron.allow
  - /etc/cron.deny
  - /etc/crontab
  - /etc/anacrontab
  - /etc/cron.daily
  - /etc/cron.hourly
  - /etc/cron.weekly
  - /etc/cron.monthly
  - /etc/cron.d
  - /var/spool/cron/ contains user crontables

## 


## Sources
  - [tecmint.com](https://www.tecmint.com/create-and-manage-cron-jobs-on-linux/)
  - [help.ubuntu.com](https://help.ubuntu.com/community/CronHowto)
