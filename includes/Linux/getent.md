Get entries from the `passwd` file ]
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