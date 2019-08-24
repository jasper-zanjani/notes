# Command Prompt

### bootrec
Windows Recovery Environment command that repairs a system partition
#### Windows Recovery Environment command to use when boot sector not found
```
bootrec /fixboot
```
#### Windows Recovery Environment command to use when BCD file has been corrupted
```
bootrec /rebuildbcd
```
#### Change Windows bootloader to Linux, while dual booting
```cmd
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi
```