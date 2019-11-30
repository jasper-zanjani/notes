# Command Prompt
### `bootrec`
Windows Recovery Environment command that repairs a system partition

Use when boot sector not found
```
bootrec /fixboot
```
Use when BCD file has been corrupted
```
bootrec /rebuildbcd
```
Change Windows bootloader to Linux, while dual booting
```cmd
bcdedit /set {bootmgr} path \EFI\manjaro\grubx64.efi
```

### `netsh`

Turn off Windows firewall
```cmd
netsh advfirewall set allprofiles state off
```

## Sources
A. "Practice Lab: CompTIA Security+ (SY0-501)". [Web](https://pts.measureup.com/web/index.php#dashboard.php)