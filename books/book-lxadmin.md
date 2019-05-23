# Linux Administration: the Linux Operating System and Command Line Guide for Linux Administrators, by Jason Cannon
## Booting
## System Logging
Syslog standard uses facilities and __severities__ to categorize messages (cf. "priorities" in LXLC). A _syslog server_ accepts syslog messages and processes them based on configurable rules. Traditionally the `syslogd` daemon served this purpose, but more recently alternatives like `rsyslog` and `syslog-ng` have emerged.
/etc/rsyslog.conf : main config file for `rsyslog`
`$IncludeConfig` : directive that allows additional config files to be loaded
`$IncludeConfig /etc/rsyslog.d/*.conf` : load all .conf files within /etc/rsyslog.d/
Logging rules consist of two fields, separated by whitespace:
  1. Selector field: `facility.severity`; multiple selectors can be separated by semicolon; `.*` wildcard can be omitted
  2. Action field, most commonly to write the messages to a log file; if the path starts with a minus sign that means rsyslog doesn't have to perform a `sync()` operation for each log message (caching mode, typically used for less critical messages)
`logger` : generate syslog messages
`logger -p` : provide a facility.severity level (defaults to `user.notice`)
`logger -t` : tag message
/etc/logrotate.conf : config file for `logrotate`
`logrotate` : utility to rotate, compress, remove, and mail log files
`weekly`, `rotate n`, `create`, `compress`, `daily`, `notifempty`
`missingok` ignore missing log files (suppress error)
`postrotate ... endscript` : enclosed lines are executed with /bin/sh
`logrotate -fv /etc/logrotate.conf` : test logrotate config 
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
