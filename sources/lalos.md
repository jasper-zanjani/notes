# Linux Administration: the Linux Operating System and Command Line Guide for Linux Administrators, by Jason Cannon
## Booting
## System Logging
Syslog standard uses facilities and __severities__ to categorize messages (cf. "priorities" in LXLC). A _syslog server_ accepts syslog messages and processes them based on configurable rules. Traditionally the `syslogd` daemon served this purpose, but more recently alternatives like `rsyslog` and `syslog-ng` have emerged. Logging rules consist of two fields, separated by whitespace:
  1. Selector field: `facility.severity`; multiple selectors can be separated by semicolon; `.*` wildcard can be omitted
  2. Action field, most commonly to write the messages to a log file; if the path starts with a minus sign that means rsyslog doesn't have to perform a `sync()` operation for each log message (caching mode, typically used for less critical messages)
/etc/rsyslog.conf : main config file for `rsyslog`
/etc/logrotate.conf : config file for `logrotate`
`$IncludeConfig` : directive that allows additional config files to be loaded
`logrotate` : utility to rotate, compress, remove, and mail log files
`weekly`, `rotate n`, `create`, `compress`, `daily`, `notifempty`
`missingok` ignore missing log files (suppress error)
`postrotate ... endscript` : enclosed lines are executed with /bin/sh
#### Load all .conf files within /etc/rsyslog.d/
```conf
$IncludeConfig /etc/rsyslog.d/*.conf
```
#### Generate syslog messages
```sh
logger
```
#### Provide a facility.severity level (defaults to `user.notice`)
```sh
logger -p
```
#### Tag message
```sh
logger -t
```
#### Test logrotate config 
```
logrotate -fv /etc/logrotate.conf
```
## Disk management
## Managing users and groups
## Networking
## Linux networking
## Network troubleshooting
## Process management
## File and directory permissions
## Managing software
## Viewing and editing files
## Shell scripting
