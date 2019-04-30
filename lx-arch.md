# Arch Linux Installation
1. `lsblk` inspect available drives and partitions before/after inserting USB drive
2. `dd if=Downloads/archlinux-2018.03.01-x86_64.iso of=/dev/sdba status="progress"` mount ISO (`if`)to USB drive (`of`), with progress displayed
3. reboot from the USB drive
4. `ls /sys/firmware/efi/efivars` if there are values displayed a UEFI system is required and a different installation sequence is needed
5. ensure an Ethernet internet connection  or `wi-fi menu` a valid Wi-Fi connection is present
6. `timedatectl set-ntp true`
7. `fdisk /dev/sdb` begin the process of partitioning the disk; enter the `fdisk` command prompt
   1. `d` delete partition
   2. `n` new partition, for boot partition
   3. `1` default for first new partition
   4. `<Enter>` default first sector
   5. `+200M`
   6. `Y` remove the signature of the previous partition
   7. repeat steps `7.2`-`7.6` for swap partition (1.5xTotal RAM e.g. `+12G`)
   8. repeat steps `7.2`-`7.6` for root partition (at least 15GB e.g. `+25G`)
   9. repeat steps `7.2`-`7.6` for home partition (remainder of hard drive, `<Enter>` for first and last sectors)
   10. `w` to write
8.  set up `ext4` filesystem on boot, root, and home partitions
    1.  `mkfs.ext4 /dev/sdb1`
    2.  `mkfs.ext4 /dev/sdb3`
    3.  `mkfs.ext4 /dev/sdb4`
9.  make the swap partition a swap drive
    1.  `mkswap /dev/sdb2`
    2.  `swapon /dev/sdb2`
10. mount partitions
    1.  `mount /dev/sdb3 /mnt` mount root partition
    2.  `mkdir /mnt/home` prepare `home` directory
    3.  `mkdir /mnt/boot` prepare `boot` directory
    4.  `mount /dev/sdb1 /mnt/boot`
    5.  `mount /dev/sdb4 /mnt/home`
11. `pacstrap /mnt base base-devel vim` install Arch Linux on the directory provided with the packages `base`, `base-devel` (which includes `sudo` and other development tools), `vim`
12. `genfstab -U /mnt > /mnt/etc/fstab` make an `fstab` file, taking all the drives mounted at that location, going off of UUIDs rather than the `sd` identifiers (which might change)
13. `arch-chroot /mnt` change root to new Arch Linux installation
14. `pacman -S networkmanager` install `networkmanager` which will allow Ethernet Internet connections upon reboot
15. `systemctl enable NetworkManager` tell SystemD to start NetworkManager upon login
16. `pacman -S grub` install GRUB
17. `grub-install --target=i386-pc /dev/sdb` install GRUB as bootloader
18. `grub-mkconfig -o /boot/grub/grub.cfg` generate GRUB configuration
19. `passwd` set password for root
20. `vim /etc/locale.gen` uncomment the two lines referring to US English
21. `locale-gen` read that file and set locale
22. `echo "LANG=en-US.UTF-8" > /etc/locale.conf` set `LANG` language variable
23. `ln -sf /usr/share/zoneinfo/America/New_York /etc/localtime` set timezone by making `localtime` a link to the correct timezone (this command is all that is required when resetting timezone during travel)
24. `echo archizard > /etc/hostname` write new hostname
25. `exit` return to USB shell
26. `umount -R /mnt` unmount hard drive for safety
27. `reboot`
### Graphical environments
  - Install `noto-fonts` and `ttf-linux-libertine` `ttf-inconsolata`
  - `~/.config/fontconfig/fonts.conf` XML file that defines fonts as serif, monospace, etc
### Example: installing `xfce4` desktop environment
  - `pacman -S xfce4`
  - `exec xfce4-session` to `~/.xinitrc`
### Installing user login screens
  `sudo pacman -S lightdm lightdm-gtk-greeter`
  `sudo systemctl enable lightdm.service`
### Potential problems
  - Ctrl+Alt+F2|F3|F4... bring up another TTY
  - Alt+LeftArrow|RightArrow navigate to adjacent TTY
