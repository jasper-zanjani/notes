# Linux certification exams
## CompTIA Linux+
2 exams:
  1. LX0-103 (60 questions)
  2. LX0-104 (60 questions)
New XK0-004 released in April 2019, complete refresh that ends the cooperation with LPI. Older exams still available until October 2019.
### Additional topics:
  - Security
  - Kernel modules
  - Storage and virtualization
  - Device management at enterprise level
  - Git and automation
  - Networking and firewalls
  - Serverside and command-line
  - Servers
  - Troubleshooting
  - SELinux
### Discarded topics
  - X 11
  - Mail
  - SQL
  - Printing
  - End-user support
  - GNU Privacy Guard

## LPIC-1
V4 exams available until July 1 2019:
  1. 101-400
  2. 102-400
###   Objectives:
####  Exam 101-400
##### 101 System architecture
- 101.1 Determine and configure hardware settings
  - Enable and disable integrated peripherals.
  - Configure systems with or without external peripherals such as keyboards.
  - Differentiate between the various types of mass storage devices.
  - Know the differences between coldplug and hotplug devices.
  - Determine hardware resources for devices.
  - Tools and utilities to list various hardware information (e.g. lsusb, lspci, etc.).
  - Tools and utilities to manipulate USB devices.
  - Conceptual understanding of sysfs, udev, dbus.
  - Topics: /sys/ /proc/ /dev/ modprobe lsmod lspci lsusb
- 101.2 Boot the system
  - Provide common commands to the boot loader and options to the kernel at boot time.
  - Demonstrate knowledge of the boot sequence from BIOS to boot completion.
  - Understanding of SysVinit and systemd.
  - Awareness of Upstart.
  - Check boot events in the log files. 
  - Topics: dmesg BIOS bootloader kernel initramfs init SysVinit systemd
- 101.3 Change runlevels, boot targets, and shutdown or reboot the system
  - Set the default runlevel or boot target.
  - Change between runlevels / boot targets including single user mode.
  - Shutdown and reboot from the command line.
  - Alert users before switching runlevels / boot targets or other major system events.
  - Properly terminate processes.
  - Topics: /etc/inittab shutdown init /etc/init.d/ telinit systemd systemctl /etc/systemd/ /usr/lib/systemd/ wall 
##### 102 Linus installation and package management
- 102.1 Hard disk layout design
  - Allocate filesystems and swap space to separate partitions or disks.
  - Tailor the design to the intended use of the system.
  - Ensure the /boot partition conforms to the hardware architecture requirements for booting.
  - Knowledge of basic features of LVM.
  - Topics: / (root) filesystem /var filesystem /home filesystem /boot filesystem swap space mount points partitions
- 102.2 Boot manager installation
  - Providing alternative boot locations and backup boot options.
  - Install and configure a boot loader such as GRUB Legacy.
  - Perform basic configuration changes for GRUB 2.
  - Interact with the boot loader. 
  - Topics: menu.lst, grub.cfg and grub.conf grub-install grub-mkconfig MBR
- 102.3 Manage shared libraries
  - Identify shared libraries.
  - Identify the typical locations of system libraries.
  - Load shared libraries. 
  - Topics: ldd ldconfig /etc/ld.so.conf LD_LIBRARY_PATH 
- 102.4 Debian package management
  - Install, upgrade and uninstall Debian binary packages.
  - Find packages containing specific files or libraries which may or may not be installed.
  - Obtain package information like version, content, dependencies, package integrity and installation status (whether or not the package is installed).
  - Topics: /etc/apt/sources.list dpkg dpkg-reconfigure apt-get apt-cache aptitude
- 102.5 RPM and YUM package management
  - Install, re-install, upgrade and remove packages using RPM and YUM.
  - Obtain information on RPM packages such as version, status, dependencies, integrity and signatures.
  - Determine what files a package provides, as well as find which package a specific file comes from. 
  - Topics: rpm rpm2cpio /etc/yum.conf /etc/yum.repos.d/ yum yumdownloader 
##### 103 GNU and Unix commands
  - 
##### 104 Devices, Linux filesystems, FHS
####  Exam 102-400
##### 105 Shells, scripting, and data management
##### 106 User interfaces and desktops
##### 107 Administrative tasks
##### 108 Essential system services
##### 109 Networking fundamentals
##### 110 Security

