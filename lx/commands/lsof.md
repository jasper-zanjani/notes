### `lsof`
Display open files, open network ports, and network connections [[23](sources.md)]

Option  | Effect
:---    | :---
`-i`    | display network connections
`-n`    | prevent the conversion of IP addresses to hostnames
`-P`    | prevent the conversion of port numbers to port names

Show open network connections
```sh
sudo lsof -Pni
```