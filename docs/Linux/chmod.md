Set sticky bit on `$FILE`
```sh
chmod +t $FILE
```
Clear sticky bit on `$FILE`
```sh
chmod -t file
```
Clear SGID bit on `$FILE`
```sh
chmod g-s file
```
Set SGID bit on `$FILE`
```sh
chmod g+s file
```
Clear SUID bit on `$FILE`
```sh
chmod u-s file
```
Set SUID bit on `$FILE`
```sh
chmod u+s file
```
Set `setuid` permission on `$FILE`
```sh
chmod +s file
```