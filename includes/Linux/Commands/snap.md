#### snap
:   
    Snap is one of several recent containerized application distribution solutions for Linux.

    Snap apps are slow to start because data is stored in [squashfs](../Files#squashfs) images.

    [Installation](https://snapcraft.io/docs/installing-snap-on-fedora)

    === ":material-redhat: Red Hat"

        ```sh
        dnf install -y snapd
        ln -s /var/lib/snapd/snap /snap
        ```

