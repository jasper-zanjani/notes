#### virsh
:   
    virsh is the main interface for managing libvirt [**guest domains**](#domain).
    In virsh terminology, the word **domain** refers to a VM.

    virsh commands can be entered from the virsh shell or from the command-line.

    ```sh
    virsh list --all
    virsh start rhel
    virsh shutdown rhel
    virsh destroy rhel  # Forcefully
    virsh undefine rhel
    virsh autostart rhel # (1)
    ```

    1. Start domain at boot

    Inspect a running domain
    ```sh
    virsh dominfo $DOMAIN
    virsh domiflist $DOMAIN
    virsh domblklist $DOMAIN
    virsh domrename $DOMAIN $NEWNAME`
    ```

    Virsh uses XML documents to define domain resources.
    ```sh
    virsh dumpxml $DOMAIN
    virsh edit $DOMAIN
    ```

    Several virsh commands come in two varieties, one to handle XML documents that define resources and another to define them inline from the command-line.

    | XML         | CLI            | Description                      |
    | ----------- | -------------- | -------------------------------- |
    | pool-define | pool-define-as | Define a persistent storage pool |
    | vol-create  | vol-create-as  | Create a volume                  |

    The commands ending in **-as** also support use of the **--print-xml** option, which will output the equivalent XML document to stdout.
