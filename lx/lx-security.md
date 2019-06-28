# Linux security issues

## Library injections
Similar to DLL files on Windows systems, .so ("shared object") library files on Linux allow code to be shared by various processes. They are vulnerable to injection attacks. One file in particular, __linux-vdso.so.1__, finds and locates other shared libraries and is mapped by the kernel into the address space of every process. This library-loading mechanism can be exploited through the use of the environment variable __`LD_PRELOAD`__, which is considered the most convenient way to load a shared library in a process at startup. If defined, this variable is read by the system and the library is loaded immediately after linux-vdso.so.1 into every process that is run.

This attack can be detected using the __[osquery](https://osquery.io/)__ tool. This tool represents the system as a relational database which can then be queried, in particular against the __process_envs__ table.

## Sources
  - "Tracking down library injections on Linux". [NetworkWorld](https://www.networkworld.com/article/3404621/tracking-down-library-injections-on-linux.html)
