*[KVM]: Kernel-based Virtual Machine

# Virtualization

The typical virtualization stack on Linux is referred to as [**QEMU**](#qemu)/[**KVM**](#kvm); both of these are separate technologies.


## Tasks

#### Check CPU for virtualization support
:   
    ```sh title=""
    grep -E 'svm|vmx' /proc/cpuinfo # (1)
    ```

    1. AMD CPUs will have **svm** in the flags section, whereas Intel CPUs will have **vmx**.

#### Virtual machine
:   
    The easiest way to create a VM is with the [**Boxes**](#boxes) GNOME Desktop Environment application or virt-manager.

    ```sh
    virt-install \
        --cdrom=/tmp/debian-9.0.0-amd64-netinst.iso \
        --vcpus=1 --memory=1024 --disk size=5 \
        --os-variant=debian8
        --name=linuxconfig-vm \
    ```

#### Virtual networking
:   
    Using [**Boxes**](#boxes), a new interface will be created (apparently named **tap0**, etc) and slaved to a bridge, or a bridge will be created if none exist.

#### Console access
:   
    In order to enable console access to a domain, the **serial-gettty@.service** service must be started.
    ```sh
    systemctl enable --now serial-getty@ttyS0.service
    ```
    Now console access is available from the host
    ```sh
    virsh console $DOMAIN
    ```

    Note that the console will remain at 24 lines by 80 columns no matter if the terminal window is resized.


#### Virtual disk
:   
    ??? info "CoW filesystems"

        If the disk image is created on a filesystem that does not support **O\_DIRECT** (ref. `man 5 open`), i.e. COW filesystem like btrfs and ZFS, the cache must be disabled. 
        This appears to be impossible on btrfs, so disk images must be created on partitions with non-CoW alternatives, like ext4 and xfs.

    A virtual disk can be created in various ways and in various formats (the sparse
    [QCOW2](https://fileinfo.com/extension/qcow2) disk image format, associated with QEMU, is preferred).

    One way is to create the image using a utility like **qemu-img**.
    ```sh title="Create qcow2 disk image"
    qemu-img create -f qcow2 disk0.qcow2 5G # (1)
    ```

    1. By omitting **-f**, qemu-img will create a RAW format file.

    Alternatively, and more circuitously, a volume can be created within a [**storage pool**](#storage-pool).
    ```sh
    virsh pool-define-as --name Disks --type dir --target /disk/Disks # (1)
    virsh pool-start Disks # (2)
    virsh vol-create-as Disks disk0.qcow2 10G --format qcow2
    ```

    1. A pool is deleted by first making sure its contents are deleted (but not the containing folder, in the case of a directory-based storage pool)
    ```sh
    virsh pool-destroy Disks  # Destroy the contents
    virsh pool-delete Disks   # Delete directory
    virsh pool-undefine Disks # Delete resource
    ```
    2. Alternatively, activate pool on boot
    ```sh
    virsh pool-autostart Disks
    ```

    Regardless of the method, the disk image is then attached to the domain, whether or not it is running.

    ```sh
    virsh attach-disk rhel \
        --source /tmp/Disks/disk0.qcow2 \
        --target vdb --cache none \
        --driver qemu --subdriver qcow2 \
        --persistent # (1)
    ```

    1. **--persistent** is necessary for the disk to remain attached after a shutdown.
    If the domain is not running, **--config** is necessary.
    ```sh hl_lines="5"
    virsh attach-disk rhel \
        --source /tmp/Disks/disk0.qcow2 \
        --target vdb --cache none \
        --driver qemu --subdriver qcow2 \
        --config
    ```
    This can be reversed with the following command.
    ```sh
    virsh detach-disk rhel /tmp/Disks/disk0.qcow2
    virhs detach-disk rhel vdb # Specifying target instead
    ```

#### Snapshots
:   
    Snapshots of VMs can be taken from within Boxes or via the command-line:
    ```sh
    virsh snapshot-create-as rhel --name "Disks added"
    ```

    These produce XML records that can then be viewed: note that the field that Boxes uses to identify each snapshot is actually "description".
    ```sh
    virsh snapshot-dumpxml rhel "Disks added"
    ```

    Snapshots can be renamed by changing the value of the **name** element in a text editor.
    ```sh
    virsh snapshot-edit rhel --snapshotname "Disks added" --rename
    ```

    Revert to a snapshot
    ```sh
    virsh snapshot-revert rhel --snapshotname 
    ```

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

## Commands

--8<--
includes/Linux/Commands/virt-install.md

includes/Linux/Commands/virsh.md

--8<--

## Glossary

#### Boxes
:   
    **Boxes** is a GNOME Desktop Environment application intended as a more user-friendly alternative to **virt-manager** to make virtualization easier for end-users.

#### domain
:   
    In libvirt, a **domain** is a guest VM.

#### KVM
:   
    KVM is a FreeBSD and Linux kernel module that allows the kernel to function as a hypervisor.

    KVM was first merged into kernel [2.6.20](https://kernelnewbies.org/Linux_2_6_20#Virtualization_support_through_KVM).

#### libvirt
:   
    **libvirt** is an open-source API, daemon, and management tool for managing virtualization.
    It is a C toolkit to interact with the virtualization capabilities of the Linux [KVM module](#kvm), but it can also be used with KVM along with other virtualization technologies like [QEMU](#qemu).

#### QEMU
:   
    **QEMU** is an open-source emulator that interoperates with KVM to run VMs at near-native speed when the guest architecture is the same as that of the host.

#### storage pool
:   
    In libvirt, a [**storage pool**](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/configuring_and_managing_virtualization/managing-storage-for-virtual-machines_configuring-and-managing-virtualization#understanding-storage-pools_understanding-virtual-machine-storage) is a file, directory, or storage device managed by libvirt to provide storage for [domains](#domain).
