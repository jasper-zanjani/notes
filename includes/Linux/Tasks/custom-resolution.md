#### Custom resolution
:   
    Specify a [custom resolution](https://stafwag.github.io/blog/blog/2018/04/22/high-screen-resolution-on-a-kvm-virtual-machine-with-qxl/ 'stafwag.github.io: "High screen resolution on a KVM virtual machine with QXL") in a VM using KVM
    ```sh
    cvt 2560 1440
    xrandr --newmode "2560x1440_60.00" 312.25 2560 2752 3024 3488  1440 1443 1448 1493 -hsync +vsync
    xrandr --addmode Virtual-1 2560x1440_60.00
    xrandr --output Virtual-1 --mode 2560x1440_60.0
    ```
    
    On a Hyper-V VM, this method will not work, but a simple change to a line in **/etc/default/grub** will do the trick after running [update-grub](#update-grub) and restarting

    ```ini
    GRUB_CMDLINE_LINUX_DEFAULT="quiet splash video=hyperv_fb:1920x1080"
    ```