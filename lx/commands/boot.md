# Linux boot
## GRUB
#### Rescue prompt
When GRUB2 is unable to find the GRUB folder or its contents are missing or corrupted, it displays the prompt `grub rescue>`. This means it failed to load the `normal` module. [[1][1]]

From GRUB rescue prompt:
```grub
set prefix=(hd0,1)/boot/grub
set root=(hd0,1)
insmod normal
normal
```
After booting the system, GRUB should be updated and reinstalled:
Update GRUB config file
```sh
update-grub
```
Reinstall GRUB
```sh
grub-install /dev/sdx
```

[1]: https://www.howtoforge.com/tutorial/repair-linux-boot-with-grub-rescue/ "howtoforge.com - \"Repair Linux boot failures in GRUB 2 rescue mode\""
Install boot images within a directory other than /boot
```sh
grub-install --boot-directory
```
Send output of grub2-mkconfig to the correct location for booting
```sh
grub2-mkconfig --output=/boot/grub2/grub.cfg
```
