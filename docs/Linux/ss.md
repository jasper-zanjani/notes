[ss -&#108;]:                   #ss                            '```&#10;$ ss -l&#10;$ ss --listening&#10;```&#10;Display sockets that are listening'
[ss -&#97;]:                    #ss                            '```&#10;$ ss -a&#10;$ ss --all&#10;```&#10;Display both listening sockets and established connections'
[ss -&#116;]:                   #ss                            '```&#10;$ ss -t&#10;$ ss --tcp&#10;```&#10;Display TCP sockets'
[ss -&#117;]:                   #ss                            '```&#10;$ ss -u&#10;$ ss --udp&#10;```&#10;Display UDP sockets'
[ss -&#120;]:                   #ss                            '```&#10;$ ss -x&#10;$ ss --unix&#10;```&#10;Display Unix domain sockets'

<code>&nbsp;</code> [`a`][ss -&#97;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`l`][ss -&#108;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`t`][ss -&#116;] [`u`][ss -&#117;] <code>&nbsp;</code> <code>&nbsp;</code> [`x`][ss -&#120;] <code>&nbsp;</code> <code>&nbsp;</code> 

Options are of two kinds:
1. Connection type (listening or established)
2. Protocol type

Display port numbers instead of protocol names
```
ss -n
```
```
ss --numeric
```
Do **name** lookups and display **all** information
```
ss -an
```
Display all active TCP sessions
```
ss -atp
```
Display active TCP sessions
```
ss -tp
```
Display routing table (cf. `ip route`)
```
ss --route
```
Display programs with open ports 
```
ss --program
```
Show all running servers 
"Tuna please"
```
ss -tunapl
```
Do name lookups and display all information
```sh
ss -an
ss --all --numeric
```
Display all sessions, filtering to just TCP that are actively listening
```sh
ss -atp
ss --all --tcp --processes
```
Display active TCP connections
```sh
ss -tp
ss --tcp --processes
```