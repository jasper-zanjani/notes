
### `free`
Simple utility that displays realtime memory information.

Option  | Effect
:---    | :---
`-c`    | run the program {n} times
`-h`    | human-readable output
`-s`    | run the program every {n} seconds, until the program is manually interrupted

List memory statistics in kilobytes. Without any options, `free` returns a table listing general statistics in kilobytes:
```bash
free
```
Command-line memory dashboard
```bash
watch free -h
```

### `getent`
Get entries from the `passwd` file [[50](sources.md)]
```sh
getent passwd sonny timmy
```
```
sonny:x:1001:1002:Sonny:/home/sonny:/bin/bash
timmy:x:1002:1003::/home/timmy:/bin/bash
```

```sh
getent group sonny timmy
```
```
sonny:x:1002:
timmy:x:1003:
```


### `top`
Option  | Effect
:---    | :---
`-n`    | change update interval

### `uname`

Option  | Effect
:---    | :---
`-a`    | display all information
`-s`    | display the kernel name
`-n`    | display the network node (i.e. host name)
`-v`    | display version (date) of the kernel
`-m`    | display the machine hardware name
`-p`    | display the processor type
`-r`    | display operating system release number
`-o`    | display operating system

Check kernel version
```bash
uname -srm
```
