### `gpasswd`
Add `$USER` to `$GROUP`
```sh
gpasswd -a $USER $GROUP
```
Add `$USER` as admin of `$GROUP`
```sh
gpasswd -A $USER $GROUP
```
Remove `$USER` from `$GROUP`
```sh
gpasswd -d $USER $GROUP
```