[date]:                                              #date                                       '```&#10;$ date&#10;```&#10;Display the system clock&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 72'
[df]:                                                #df                                         '```&#10;$ df&#10;```&#10;Display usage of partitions and logical devices&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 49'
[du]:                                                #du                                         '```&#10;$ du&#10;```&#10;Display estimate disk space usage in a directory structure&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 49'
[free]:                                              #free                                       '```&#10;$ free&#10;```&#10;Display amount of free and used memory in the system&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 294'
[glances]:                                           #glances                                    '```&#10;$ glances&#10;```&#10;Cross-platform monitoring tool, written in Python&#10;'
[hwclock]:                                           #hwclock                                    '```&#10;$ hwclock&#10;```&#10;Access the BIOS clock&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 72'
[loadaverage]:                                       #loadaverage                                '```&#10;$ loadaverage&#10;```&#10;Display system load average (cf. `uptime`)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 291'
[logrotate]:                                         #logrotate                                  '```&#10;$ logrotate&#10;```&#10;Utility designed to ensure the partition that holds log files has enough room to handle them by rotating log files, reducing the space they use, typically configured to run automatically as a cron job&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 250'
[lscpu]:                                             #lscpu                                      '```&#10;$ lscpu&#10;```&#10;Display CPU architecture information&#10;'
[mpstat]:                                            info.md#mpstat                                     '```&#10;$ mpstat&#10;```&#10;Utility for monitoring CPU performance&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 635-637'
[nproc]:                                             #nproc                                      '```&#10;$ nproc&#10;```&#10;Display number of CPU processors or cores'
[pmap]:                                              #pmap                                       '```&#10;$ pmap&#10;```&#10;Report memory map of a process&#10;'
[printenv]:                                          #printenv                                   '```&#10;$ printenv&#10;```&#10;Display environment variables&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 331'
[rsyslogd]:                                          #rsyslogd                                   '```&#10;$ rsyslogd&#10;```&#10;Responsible for logging of application and system events&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 249'
[sar]:                                               #sar                                        '```&#10;$ sar&#10;```&#10;Displays the same information as `iostat`, but displayed as it occurs over time (typically at 10-minute intervals)&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 291'
[sysbench]:                                          #sysbench                                   '```&#10;$ sysbench&#10;```&#10;Multi-threaded benchmark tool for database systems'
[syslogd]:                                           #syslogd                                    '```&#10;$ syslogd&#10;```&#10;Responsible for logging of application and system events&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 249'
[time]:                                              #time                                       '```&#10;$ time&#10;```&#10;Determine how long it takes to run a command&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 302'
[timedatectl]:                                       #timedatectl                                '```&#10;$ timedatectl&#10;```&#10;Display system clock&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 71'
[tty]:                                               #tty                                        '```&#10;$ tty&#10;```&#10;Determine terminal device file for current session&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 121'
[uptime]:                                            #uptime                                     '```&#10;$ uptime&#10;```&#10;Show how long the system has been running&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 291'
[vmstat]:                                            #vmstat                                     '```&#10;$ vmstat&#10;```&#10;Provides more detail than `free`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 293'

[`A`][date +%&#65;]
[`a`][date +%&#97;]

<!-- `date` metacharacters -->

<!-- `date` options -->

<!-- `df` options -->

<!-- `du` options -->

<!-- `sar` options -->

# Linux diagnostic and benchmarking commands
Commands                      | Options
---                           | ---
[`date`][date]                | <code>&nbsp;</code>  [`a`][date +%a]  [`b`][date +%b]  [`c`][date +%c]  [`d`][date +%d]  [`e`][date +%e]  <code>&nbsp;</code>  [`g`][date +%g]  [`h`][date +%h]  <code>&nbsp;</code>  [`j`][date +%j]  [`k`][date +%k]  [`l`][date +%l]  [`m`][date +%m]  [`n`][date +%n]  <code>&nbsp;</code>  [`p`][date +%p]  <code>&nbsp;</code>  [`r`][date +%r]  [`s`][date +%s]  [`t`][date +%t]  [`u`][date +%u]  <code>&nbsp;</code>  [`w`][date +%w]  [`x`][date +%x]  [`y`][date +%y]  <code>&nbsp;</code> <br><code>&nbsp;</code>  [`A`][date +%A]  [`B`][date +%B]  <code>&nbsp;</code>  [`D`][date +%D]  <code>&nbsp;</code>  [`F`][date +%F]  [`G`][date +%G]  [`H`][date +%H]  [`I`][date +%I]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`M`][date +%M]  [`N`][date +%N]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`R`][date +%R]  [`S`][date +%S]  [`T`][date +%T]  [`U`][date +%U]  [`V`][date +%V]  [`W`][date +%W]  [`X`][date +%X]  [`Y`][date +%Y]  [`Z`][date +%Z]
[`df`][df]                    | <code>&nbsp;</code>  [`a`][df -a]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`h`][df -h]  [`i`][df -i]  <code>&nbsp;</code>  [`k`][df -k]  [`l`][df -l]  [`m`][df -m]  <code>&nbsp;</code>  [`o`][df -o]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`t`][df -t]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`x`][df -x]  <code>&nbsp;</code>  <code>&nbsp;</code> <br><code>&nbsp;</code>  <code>&nbsp;</code>  [`B`][df -B]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`H`][df -H]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`P`][df -P]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`T`][df -T]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`du`][du]                    | [`0`][du -0]  [`a`][du -a]  [`b`][du -b]  [`c`][du -c]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`h`][du -h]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`k`][du -k]  [`l`][du -l]  [`m`][du -m]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`s`][du -s]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`x`][du -x]  <code>&nbsp;</code>  <code>&nbsp;</code> <br><code>&nbsp;</code>  <code>&nbsp;</code>  [`B`][du -B]  <code>&nbsp;</code>  [`D`][du -D]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`L`][du -L]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`P`][du -P]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`S`][du -S]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`X`][du -X]  <code>&nbsp;</code>  <code>&nbsp;</code>
[`free`][free]                | 
[`glances`][glances]          | 
[`hwclock`][hwclock]          | 
[`loadaverage`][loadaverage]  | 
[`logrotate`][logrotate]      | 
[`lscpu`][lscpu]              | 
[`mpstat`][mpstat]            | 
[`nproc`][nproc]              | 
[`pmap`][pmap]                | 
[`printenv`][printenv]        | 
[`rsyslogd`][rsyslogd]        | 
[`sar`][sar]                  | <code>&nbsp;</code>  <code>&nbsp;</code>  [`b`][sar -b]  <code>&nbsp;</code>  [`d`][sar -d]  <code>&nbsp;</code>  [`f`][sar -f]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`n`][sar -n]  [`o`][sar -o]  <code>&nbsp;</code>  [`q`][sar -q]  [`r`][sar -r]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`u`][sar -u]  [`v`][sar -v]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br><code>&nbsp;</code>  [`A`][sar -A]  [`B`][sar -B]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`P`][sar -P]  <code>&nbsp;</code>  [`R`][sar -R]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`W`][sar -W]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`sysbench`][sysbench]        | 
[`syslogd`][syslogd]          | 
[`time`][time]                | 
[`timedatectl`][timedatectl]  | 
[`tty`][tty]                  | 
[`uptime`][uptime]            | 
[`vmstat`][vmstat]            | 

### `free`
Display amount of free and used memory in the system [^][L5PMT-memory]
```sh
free -m
```
### `glances`
Cross-platform monitoring tool, written in Python. [^][L5PMT-glances]

Config                | Description
---                   | ---
/etc/default/glances  | Change value of `RUN` to `"True"` in order to have glances run on startup [^][L5PMT-glances]
### `ioping`
Displays disk latency in the same way that `ping` shows network latency [^][L5PMT-disk]
### `iotop`
### `lscpu`
Display CPU architecture information [^][L5PMT-cpu]
### `mpstat`
Report processor-related statistics (part of "sysstat" package). [^][L5PMT-network]
```sh
mpstat -P all
```
### `netstat`
```sh
netstat -tulpn
```
### `nproc`
Display number of CPU processors or cores [^][L5PMT-cpu]
### `pmap`
Report memory map of a process (part of "sysstat" package). [^][L5PMT-network]

### `sosreport`
**SOS** is an open-source data collection tool that can be used to collect system configuration details and diagnostic information from a Unix-like operating system. It is installed by default on Ubuntu Server. [^][39]

Option  | POSIX option            | Effect
:---    | :---                    | :---
`-l`    |                         | list plugins
\-      | `--compression-type`    | specify alternative compression (`xz` by default)
\-      | `--tmp-dir`             | specify alternative temporary directory

Collect system configuration details (without arguments, the report will be generated and stored in `$TMPDIR`)
```sh
sosreport
```
Specify alternative temporary directory
```sh
sosreport --tmp-dir /opt
```
Specify alternative compression (`xz` by default)
```sh
sosreport --compression-type gzip
```
Generate report for only specific plugins
```sh
sosreport -o apache --batch
```
### `sysbench`
Benchmark CPU by calculating prime numbers [^][https://youtu.be/KkMWXVx-Ul8]
```sh
sysbench --test=cpu --cpu-max-prime=20000 run
```
File I/O benchmarking [^][https://youtu.be/KkMWXVx-Ul8]
```sh
sysbench --test=fileio --file-total-size=10G --file-test-mode=rndrw --init-rng=on --max-time=300 --max-requests=0 run
```
### `uptime`
[^][L5PMT-cpu]
### `vmstat`

Output header | Description [^][Eckert]
---           | ---
`r`           | number of processes waiting to be run
`b`           | number of sleeping processes
`swpd`        | amount of swap memory used (KB)
`free`        | free physical memory (KB)
`buff`        | memory used by buffers (KB)
`cache`       | memory used as cache
`si`          | memory swapped in to the disk (KB/s)
`so`          | memory swapped out to the disk (KB/s)
`bi`          | blocks per second sent to block devices
`bo`          | blocks per second received from block devices
`in`          | number of interrupts sent to the CPU per second
`cs`          | number of context changes sent to the CPU per second
`us`          | CPU user time
`sy`          | CPU system time
`id`          | CPU idle time
`wa`          | time spent waiting for I/O
`st`          | time stolen from a virtual machine
### /proc/meminfo
Free and used memory [^][L5PMT-memory]
## 
[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."
[L5PMT-glances]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_3/glances-tool 'Linux 5 Performance Monitoring and Tuning: "Glances Tool"'
[L5PMT-cpu]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_2/cpu-run-queue-and-load-average 'Linux 5 Performance Monitoring and Tuning: "CPU - Run Queue and Load Average"'
[L5PMT-memory]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_4/memory-and-swap-management-on-linux 'Linux 5 Performance Monitoring and Tuning: "Memory and Swap Management on Linux"'
[L5PMT-disk]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_5/disk-io-operations-on-linux 'Linux 5 Performance Monitoring and Tuning: "Disk IO Operations on Linux"'
[L5PMT-network]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_6/monitoring-and-understanding-network 'Linux 5 Performance Monitoring and Tuning: "Monitoring and Understanding Network"'
[L5PMT-subsystem]: https://subscription.packtpub.com/video/programming/9781838559250/p2/video2_1/subsystem-analysis-with-vmstat 'Linux 5 Performance Monitoring and Tuning: "Subsystem Analysis with vmstat"'
[https://youtu.be/KkMWXVx-Ul8]: https://youtu.be/KkMWXVx-Ul8 "YouTube: How to Benchmark your Linux system, Hak5 1502.1"
