# GRUB
Install boot images within a directory other than /boot
```sh
grub-install --boot-directory
```
Send output of grub2-mkconfig to the correct location for booting
```sh
grub2-mkconfig --output=/boot/grub2/grub.cfg
```

### `update-grub`
Make changes take effect for a GRUB2 configuration change

