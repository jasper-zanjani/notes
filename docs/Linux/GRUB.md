# GRUB2

Kernel [**command line parameters**](https://www.kernel.org/doc/html/v4.14/admin-guide/kernel-parameters.html) passed in on boot can be queried during runtime:
```sh
cat /proc/cmdline
```

## Tasks

#### Text-mode installation
:   
    RHEL can be installed from the console by providing **inst.text** as a kernel parameter on boot by pressing ++Tab++ on the GRUB splash screen.

--8<--
includes/Linux/Tasks/GRUB-rescue-prompt.md
--8<--


## Commands

--8<--
includes/Linux/Commands/grub-install.md"

includes/Linux/Commands/grub-mkconfig.md

includes/Linux/Commands/grub2-mkconfig.md

includes/Linux/Commands/grub2-editenv.md

includes/Linux/Commands/update-grub.md

--8<--
