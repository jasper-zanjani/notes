#### gio

*[GVFS]: GNOME Virtual File System

GIO (Gnome Input/Output) is a library that facilitates interaction with virtual file systems.
Applications built with the GIO library can access GVFS mounts, which can have many backends.

GIO commands appear to substitute for common POSIX commands and GNU utilities (e.g. `gio cat`, `gio mkdir`, `gio rename`, etc).

Set custom GIO metadata [:material-file-document:](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/using_the_desktop_environment_in_rhel_8/managing-storage-volumes-in-gnome_using-the-desktop-environment-in-rhel-8)
```sh
touch /tmp/myfile

# Read (empty) attribute of new file
gio info -a 'metadata::*' /tmp/myfile

# Create attribute
gio set -t string /tmp/myfile 'metadata::mynote' 'Please remember to delete this file!'

# Rename file
gio move /tmp/myfile /tmp/newfile

# Confirm that attribute still exists
gio info -a 'metadata::*' /tmp/newfile
```
