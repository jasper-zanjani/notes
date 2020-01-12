# Linux benchmarking commands
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
### `uptime`
[^][L5PMT-cpu]
### `vmstat`
### /proc/meminfo
Free and used memory [^][L5PMT-memory]

---

[L5PMT-glances]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_3/glances-tool 'Linux 5 Performance Monitoring and Tuning: "Glances Tool"'
[L5PMT-cpu]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_2/cpu-run-queue-and-load-average 'Linux 5 Performance Monitoring and Tuning: "CPU - Run Queue and Load Average"'
[L5PMT-memory]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_4/memory-and-swap-management-on-linux 'Linux 5 Performance Monitoring and Tuning: "Memory and Swap Management on Linux"'
[L5PMT-disk]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_5/disk-io-operations-on-linux 'Linux 5 Performance Monitoring and Tuning: "Disk IO Operations on Linux"'
[L5PMT-network]: https://subscription.packtpub.com/video/programming/9781838559250/p1/video1_6/monitoring-and-understanding-network 'Linux 5 Performance Monitoring and Tuning: "Monitoring and Understanding Network"'
[L5PMT-subsystem]: https://subscription.packtpub.com/video/programming/9781838559250/p2/video2_1/subsystem-analysis-with-vmstat 'Linux 5 Performance Monitoring and Tuning: "Subsystem Analysis with vmstat"'

[free]: benchmarking.md#free "Display amount of free and used memory in the system"
[glances]: benchmarking.md#glances "Cross-platform monitoring tool, written in Python"
[lscpu]: benchmarking.md#lscpu "Display CPU architecture information"
[mpstat]: benchmarking.md#mpstat "Report processor-related statistics"
[nproc]: benchmarking.md#nproc "Display number of CPU processors or cores"
[pmap]: benchmarking.md#pmap "Report memory map of a process"
