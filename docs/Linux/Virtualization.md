*[KVM]: Kernel-based Virtual Machine

# Virtualization

The typical virtualization stack on Linux is referred to as [**QEMU**](#qemu)/[**KVM**](#kvm); each of these are separate technologies.


## Tasks

#### Check CPU for virtualization support
:   
    ```sh title=""
    grep -E 'svm|vmx' /proc/cpuinfo # (1)
    ```

    1. AMD CPUs will have **svm** in the flags section, whereas Intel CPUs will have **vmx**.

#### Create VM
:   
    The easiest way to create a VM is with the [**Boxes**](#boxes) GNOME Desktop Environment application.
    


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

## Glossary

#### Boxes
:   
    **Boxes** is a GNOME Desktop Environment application intended as a more user-friendly alternative to **virt-manager** to make virtualization easier for end-users.

#### domain
:   
    In libvirt, a **domain** is a reference to an instance of a virtual operating system, i.e. a guest.

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

## Commands

--8<--
includes/Linux/Commands/virt-install.md
includes/Linux/Commands/virsh.md
--8<--
