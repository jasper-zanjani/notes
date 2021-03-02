#### GRUB rescue prompt
When GRUB2 is unable to find the GRUB folder or its contents are missing or corrupted, it displays the prompt 
```
grub rescue>
``` 
This means it failed to load the `normal` module. [howtoforge.com](https://www.howtoforge.com/tutorial/repair-linux-boot-with-grub-rescue/ "Repair Linux boot failures in GRUB 2 rescue mode")

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

#### grub-install
Install GRUB as bootloader
```sh
grub-install --target=i386-pc /dev/sdb
```
Install boot images within a directory other than /boot
```sh
grub-install --boot-directory
```
#### grub-mkconfig
Generate GRUB configuration
```sh
grub-mkconfig -o /boot/grub/grub.cfg
```
#### grub2-mkconfig
Send output of grub2-mkconfig to the correct location for booting
```sh
grub2-mkconfig --output=/boot/grub2/grub.cfg
```
#### grub2-editenv
Disable the Nouveau display driver while installing the proprietary Nvidia display driver on Fedora [linuxconfig.org](https://linuxconfig.org/how-to-install-the-nvidia-drivers-on-fedora-31 "How to install the NVIDIA drivers on Fedora 31")
```sh
grub2-editenv - set "$(grub2-editenv - list | grep kernelopts) nouveau.modeset=0"
```
#### update-grub
Update GRUB config file
```sh
update-grub
```
