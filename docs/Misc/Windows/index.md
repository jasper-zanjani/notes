# Windows

Like other multiuser OSes, Windows architecture draws a distinction between [kernel mode](#kernel-mode) and [user mode](#user-mode).
When user-mode threads call a system service, a special instruction is executed that switches the calling thread to kernel mode.
When the call completes, the thread context is switched back to user mode.

--8<-- "includes/Windows/abbrs.md"

--8<-- "includes/Windows/defs.md"

--8<-- "includes/Windows/files.md"