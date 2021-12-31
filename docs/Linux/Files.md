# Files

## Glossary

#### squashfs
:   
    [Squashfs](https://www.kernel.org/doc/html/latest/filesystems/squashfs.html) is a compressed read-only filesystem for Linux using zlib compression for files, inodes, and directories.

## Commands

--8<-- "includes/Linux/Commands/cp.md"

#### du
:   
    du does not double-count hard-linked files, so it can be used to analyze deduplication in app distribution solutions like [Flatpak](../Package#flatpak).

    Here the second command will display a smaller value for the 21.08 version of the freedesktop Platform runtime, indicating that hard-linked files have not been double-counted.
    ```sh
    du -sh /var/lib/flatpak/runtime/org.freedesktop.Platform/x86_64/21.08
    du -sh /var/lib/flatpak/runtime/org.freedesktop.Platform/x86_64/21.08 /var/lib/flatpak/runtime/org.freedesktop.Platform/x86_64/20.08
    ```

--8<-- "includes/Linux/Commands/find.md"

--8<-- "includes/Linux/Commands/mv.md"

--8<-- "includes/Linux/Commands/rename.md"

--8<-- "includes/Linux/Commands/rsync.md"

--8<-- "includes/Linux/Commands/setfacl.md"