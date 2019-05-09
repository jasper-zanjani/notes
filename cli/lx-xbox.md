# XBox 360 wireless controller on Linux
[UnixBlogger](https://www.unixblogger.com/how-to-get-your-xbox-360-wireless-controller-working-under-your-linux-box/)

`sudo apt-get install xboxdrv`
: install the driver on Debian distros

`sudo xboxdrv`
: start driver with default settings

`sudo xboxdrv --detach-kernel-driver`
: unload xpad module

`rmmod xpad`
: unload xpad module

`sudo xboxdrv --detach-kernel-driver --silent`
: silence the output which will be displayed on the terminal while using the controller

`sudo xboxdrv --detach-kernel-driver --silent --mimic-xpad`
: use xboxdrv with WINE


