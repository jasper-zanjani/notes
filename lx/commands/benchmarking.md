# Linux benchmarking commands
&nbsp;  | Commands
---     | ---
&nbsp;  | [`free`][free] &bull; [`glances`][glances] &bull; `ioping` `iotop` &bull; [`lscpu`][lscpu] &bull; `mpstat` &bull; `netstat` [`nproc`][nproc] &bull; [`pmap`][pmap] &bull; `sosreport` [`sysbench`][sysbench] &bull; `uptime` &bull; [`vmstat`][vmstat]
### `free`
Display amount of free and used memory in the system [<sup>Olushile</sup>][L5PMT-memory]
```sh
free -m
```
### `glances`
Cross-platform monitoring tool, written in Python. [<sup>Olushile</sup>][L5PMT-glances]

Config                | Description
---                   | ---
/etc/default/glances  | Change value of `RUN` to `"True"` in order to have glances run on startup [<sup>Olushile</sup>][L5PMT-glances]
### `ioping`
Displays disk latency in the same way that `ping` shows network latency [<sup>Olushile</sup>][L5PMT-disk]
### `iotop`
### `lscpu`
Display CPU architecture information [<sup>Olushile</sup>][L5PMT-cpu]
### `mpstat`
Report processor-related statistics (part of "sysstat" package). [<sup>Olushile</sup>][L5PMT-network]
```sh
mpstat -P all
```
### `netstat`
```sh
netstat -tulpn
```
### `nproc`
Display number of CPU processors or cores [<sup>Olushile</sup>][L5PMT-cpu]
### `pmap`
Report memory map of a process (part of "sysstat" package). [<sup>Olushile</sup>][L5PMT-network]
### `sar`
Option  | Description
---     | ---
`-A`    | display the most information: equivalent to **a**ll options
`-b`    | display input/output statistics
`-B`    | display swap statistics
`-d`    | display input/output statistics for each block device on the system
`-f`    | display information from the specified `$FILE` (typically within /var/log/sa)
`-n ALL`  | report all network statistics
`-o`    | save output to `$FILE` in binary
`-P`    | specify statistics for a single CPU (0-indexed)
`-q`    | display statistics for the processor queue
`-r`    | display memory and swap statistics
`-R`    | display memory statistics
`-u`    | display CPU statistics (default when no options are specified)
`-v`    | display kernel-related statistics
`-W`    | display swapping statistics
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
[<sup>Olushile</sup>][L5PMT-cpu]
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
Free and used memory [<sup>Olushile</sup>][L5PMT-memory]
## 
[Eckert]: # "Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012."
[L5PMT-glances]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_3/glances-tool 'Linux 5 Performance Monitoring and Tuning: "Glances Tool"'
[L5PMT-cpu]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_2/cpu-run-queue-and-load-average 'Linux 5 Performance Monitoring and Tuning: "CPU - Run Queue and Load Average"'
[L5PMT-memory]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_4/memory-and-swap-management-on-linux 'Linux 5 Performance Monitoring and Tuning: "Memory and Swap Management on Linux"'
[L5PMT-disk]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_5/disk-io-operations-on-linux 'Linux 5 Performance Monitoring and Tuning: "Disk IO Operations on Linux"'
[L5PMT-network]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_6/monitoring-and-understanding-network 'Linux 5 Performance Monitoring and Tuning: "Monitoring and Understanding Network"'
[L5PMT-subsystem]: https://subscription.packtpub.com/video/programming/9781838559250/p2/video2_1/subsystem-analysis-with-vmstat 'Linux 5 Performance Monitoring and Tuning: "Subsystem Analysis with vmstat"'
[https://youtu.be/KkMWXVx-Ul8]: https://youtu.be/KkMWXVx-Ul8 "YouTube: How to Benchmark your Linux system, Hak5 1502.1"

[free]:                                               #free             "Display amount of free and used memory in the system"
[glances]:                                            #glances          "Cross-platform monitoring tool, written in Python"
[lscpu]:                                              #lscpu            "Display CPU architecture information"
[nproc]:                                              #nproc            "Display number of CPU processors or cores"
[pmap]:                                               #pmap             "Report memory map of a process"
[sysbench]:                                           #sysbench         '```&#10;$ sysbench&#10;```&#10;Multi-threaded benchmark tool for database systems'
[vmstat]:                                             #vmstat           '`vmstat`&#10;Provides more detail than `free`&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.&#10;Eckert, Jason. _Linux+ Guide to Linux Certification_. Course Technology, 2012: 642'