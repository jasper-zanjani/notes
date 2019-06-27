# free
Simple utility that display realtime memory information. Without any options, `free` returns a table listing general statistics in kilobytes:
```bash
free
```

Option  | Effect
:---    | :---
`-h`    | human-readable output
`-s n`  | run the program every <n> seconds, until the program is manually interrupted
`-c n`  | run the program <n> times

#### Example: Dashboard
```bash
watch free -h
```


## Sources
  - "Free Command in Linux Explained With Examples". [linuxhandbook.com](https://linuxhandbook.com/free-command/)
