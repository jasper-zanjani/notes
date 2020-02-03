# Autotools
GNU autotools are three packages: [`autoconf`][autoconf], [`automake`][automake], and `libtool`

&nbsp;  | Commands
---     | ---
&nbsp;  | [`aclocal`][aclocal] [`autoconf`][autoconf] [`autoheader`][autoheader] [`automake`][automake]

### `aclocal`
### `as`
### `autoconf`
Other related programs are usually invoked automatically by tools in the `autoconf` suite: `autoreconf`, `autoscan`, and `autoupdate`
## 
[aclocal]:                                           #aclocal                                                   '```&#10;aclocal&#10;```&#10;Place m4 macro definitions needed by `autoconf` into a single file. `aclocal` first scans for macro definitions in m4 files in its default directory (/usr/share/aclocal) and in the file acinclude.m4, then in the configure.ac file. IT generates an aclocal.m4 file that contains definitions of all m4 macros required by `autoconf`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[autoconf]:                                          #autoconf                                                  '```&#10;autoconf&#10;```&#10;Generate a configuration script from m4 macros defined in a template file, if given, or in a configure.ac or configure.in file in the CWD. The generated script is almost invariably called "configure".&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoheader]:                                        #autoheader                                                '```&#10;autoheader&#10;```&#10;Generate a template file of C `#define` statements from m4 macros defined in a template file, if specified, or in configure.ac or configure.in in the CWD. The generated template file is almost invariably called config.h.in or config.hin&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 22'
[automake]:                                          #automake                                                  '```&#10;automake&#10;```&#10;Create GNU standards-compliant Makefile.in files from Makefile.am template files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 23'