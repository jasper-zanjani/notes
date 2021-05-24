#### journalctl

Show current disk usage of all journal files
```sh
journalctl --disk-usage
```
Continuously update the display as new log entries are created
```sh
journalctl -f
```
Display output in reverse (newest entries first)
```sh
journalctl -r
```