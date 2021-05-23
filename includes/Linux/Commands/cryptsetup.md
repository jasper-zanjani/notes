Incorporate full-disk encryption on /dev/sdb1, asking for passphrase twice
```sh
cryptsetup --verify-passphrase luksFormat /dev/sdb1
```
Assign virtual name "storage1" to encrypted disk /dev/sdb1
```sh
cryptsetup luksOpen /dev/sdb1 storage1
```