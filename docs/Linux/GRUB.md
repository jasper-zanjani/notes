# GRUB2

!!! info "Manual"

    The GNU GRUB Manual is available [here](https://www.gnu.org/software/grub/manual/grub/grub.html).


GNU GRUB provides a shell environment with limited capabilities.

```
grub>
```



Kernel [**command line parameters**](https://www.kernel.org/doc/html/v4.14/admin-guide/kernel-parameters.html) passed in on boot can be queried during runtime:
```sh
cat /proc/cmdline
```

## Tasks

#### Loading linux
:   
    ```
    grub> set prefix=(hd0,1)/boot/grub
    grub> set root=(hd0,1)
    grub> insmod normal
    grub> normal
    ```

    The most common task done at the GRUB command-line is simply starting linux.
    The prefix and root environment variables are set before loading and running the normal module.
    
    - [**prefix**](https://www.gnu.org/software/grub/manual/grub/grub.html#prefix) is an [absolute filename](https://www.gnu.org/software/grub/manual/grub/grub.html#File-name-syntax) (UNIX-style path but including the device name in parentheses) indicating where GRUB modules are found
    - [**root**](https://www.gnu.org/software/grub/manual/grub/grub.html#root) specifies a device for files which do not specify one
    - [**insmod**](https://www.gnu.org/software/grub/manual/grub/grub.html#insmod) inserts a dynamic GRUB module
    - [**normal**](https://www.gnu.org/software/grub/manual/grub/grub.html#normal) enters normal mode and displays the GRUB menu



    Running [**ls**](https://www.gnu.org/software/grub/manual/grub/grub.html#ls)  displays devices or files using the GRUB [device syntax](https://www.gnu.org/software/grub/manual/grub/grub.html#Device-syntax).
    
    Here, only the USB drive is available to the system.
    When additional drives are available, their

    ``` hl_lines="2"
    grub> ls
    (proc) (hd0) (hd0,msdos1)
    ```
    
    Invoking the [**set**](https://www.gnu.org/software/grub/manual/grub/grub.html#set) command without arguments will display all environment variables.
    Here the prefix and root variables are set before inserting and loading the normal module:
    ```
    grub> set prefix=(hd0,msdos1)/boot/grub
    grub> set root=(hd0,msdos1)
    grub> insmod normal
    grub> normal
    ```

#### Resetting root password
:   
    Append **rd.break** to the list of command-line parameters to GRUB.
    Once the shell is ready, run the following commands
    ```sh
    mount -o remount,rw /sysroot
    chroot /sysroot
    passwd root
    ```

#### Text-mode installation
:   
    RHEL can be installed from the console by providing **inst.text** as a kernel parameter on boot by pressing ++Tab++ on the GRUB splash screen.

#### GRUB rescue prompt
:   
    During GRUB's normal startup procedure, the **prefix** and **root** environment variables are first set before loading the **normal module**.
    When the normal module has failed to load because the GRUB folder or its contents are missing or corrupted, it displays a [**rescue shell**](https://www.gnu.org/software/grub/manual/grub/grub.html#GRUB-only-offers-a-rescue-shell)
    ```
    grub rescue>
    ``` 

    ```
    grub rescue> set prefix=(hd0,1)/boot/grub
    grub rescue> set root=(hd0,1)
    grub rescue> insmod normal
    grub rescue> normal
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


## Commands

--8<--
includes/Linux/Commands/grub-install.md"

includes/Linux/Commands/grub-mkconfig.md

includes/Linux/Commands/grub2-mkconfig.md

includes/Linux/Commands/grub2-editenv.md

includes/Linux/Commands/update-grub.md

--8<--
