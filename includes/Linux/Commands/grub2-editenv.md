#### grub2-editenv
:   
    Disable the [Nouveau display driver](https://linuxconfig.org/how-to-install-the-nvidia-drivers-on-fedora-31 "How to install the NVIDIA drivers on Fedora 31") while installing the proprietary Nvidia display driver on Fedora 

    ```sh
    grub2-editenv - set "$(grub2-editenv - list | grep kernelopts) nouveau.modeset=0"
    ```
