#### GRUB rescue prompt
:   
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