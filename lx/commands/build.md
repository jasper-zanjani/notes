[aclocal]:                                           build.md#aclocal                                   '```&#10;$ aclocal&#10;```&#10;Place m4 macro definitions needed by `autoconf` into a single file. `aclocal` first scans for macro definitions in m4 files in its default directory (/usr/share/aclocal) and in the file acinclude.m4, then in the configure.ac file. IT generates an aclocal.m4 file that contains definitions of all m4 macros required by `autoconf`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[autoconf]:                                          build.md#autoconf                                  '```&#10;$ autoconf&#10;```&#10;Generate a configuration script from m4 macros defined in a template file, if given, or in a configure.ac or configure.in file in the CWD. The generated script is almost invariably called "configure".&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoheader]:                                        build.md#autoheader                                '```&#10;$ autoheader&#10;```&#10;Generate a template file of C `#define` statements from m4 macros defined in a template file, if specified, or in configure.ac or configure.in in the CWD. The generated template file is almost invariably called config.h.in or config.hin&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 22'
[automake]:                                          build.md#automake                                  '```&#10;$ automake&#10;```&#10;Create GNU standards-compliant Makefile.in files from Makefile.am template files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 23'
[autoreconf]:                                        build.md#autoreconf                                '```&#10;$ autoreconf&#10;```&#10;Update configure scripts by running `autoconf`, `autoheader`, `aclocal`, `automake`, and `libtoolize` as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoscan]:                                          build.md#autoscan                                  '```&#10;$ autoscan&#10;```&#10;Create or maintain a preliminary configure.ac file named configure.scan based on source files in specified directory or CWD.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoupdate]:                                        build.md#autoupdate                                '```&#10;$ autoupdate&#10;```&#10;Update the configure template file or configure.ac if none is specified&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[bison]:                                             build.md#bison                                     '```&#10;$ bison&#10;```&#10;Convert specified "file.y" containing a context-free grammar into tables for subsequent parsing while sending output to a new file named "file.c". Largely compatible with `yacc`, from which it derives its name.&#10;Originated as an adaptation of Bob Corbett's reimplementation of yacc which was distributed under the Berkeley license. Now maintained as a project of the FSF under a GPL license.'
[flex]:                                              build.md#flex                                      '```&#10;$ flex&#10;```&#10;"fast lexical analyzer generator", version of `lex` translated into C by Vern Paxson'
[ldd]:                                               build.md#ldd                                       '```&#10;$ ldd&#10;```&#10;Display shared libraries used by a specified command&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 87'
[lex]:                                               build.md#lex                                       '```&#10;$ lex&#10;```&#10;Generate a lexical analysis program based on the regular expressions and C statements contained in one or more input files&#10;Lexical analyzer generator written by Eric Schmidt'
[make]:                                              build.md#make                                      '```&#10;$ make&#10;```&#10;Utility for building and maintaining programs from source code using a makefile&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'
[yacc]:                                              build.md#yacc                                      '```&#10;$ yacc&#10;```&#10;"yet another compiler-compiler", parser generator that converts a file containing a context-free LALR grmamar and converts it to tables for subsequent pasring, sending output to y.tab.c. Written between 1975 and 1978 by Stephen C. Johnson at Bell Labs.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 237'

# Linux build tools

Commands                  | Options
---                       | ---
[`aclocal`][aclocal] | 
[`autoconf`][autoconf] | 
[`autoheader`][autoheader] | 
[`automake`][automake] | 
[`autoreconf`][autoreconf] | 
[`autoscan`][autoscan] | 
[`autoupdate`][autoupdate] | 
[`bison`][bison] | 
[`flex`][flex] | 
[`ldd`][ldd] | 
[`lex`][lex] | 
[`make`][make] | 
[`yacc`][yacc] | 

## Autotools
GNU autotools are three packages: [`autoconf`][autoconf], [`automake`][automake], and `libtool`

&nbsp;  | Commands
---     | ---
&nbsp;  | [`aclocal`][aclocal] [`autoconf`][autoconf] [`autoheader`][autoheader] [`automake`][automake]

### `aclocal`
### `as`
### `autoconf`
Other related programs are usually invoked automatically by tools in the `autoconf` suite: `autoreconf`, `autoscan`, and `autoupdate`
### `make`
A common formula when installing software from source is the following sequence of commands [^](https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install "thoughtbot.com: \"The magic behind configure, make, make install\"")
```sh
./configure
make
make install
```
Given there are 3 example files (main.cpp, message.cpp, and message.h) in a directory, it produces an executable file named `a.out`
```sh
g++ main.cpp message.cpp
```
But for large projects, with potentially thousands of files, this is impractical

#### makefiles
Makefiles are sensitive to whitespace, so indentation is significant. The format follows the pattern:
```makefile
{target}: {dependencies}
  {action}
```
where `{target}` is the filename produced by the operation `{action}`, each of which are shell commands.

For any changes in `main.o` and `message.o`, they will be recompiled into `output`, which is the executable. `g++ -c` will compile the code into an object file but not into a binary, creating `main.o`.
```makefile
output: main.o message.o
  g++ main.o message.o -o output

message.o: message.cpp message.h
  g++ -c message.cpp
  
main.o: main.cpp
  g++ -c main.cpp

clean:
  rm *.o output
```
  - 

Execute the operations specified in the makefile (if executed a second time without any changes, it will produce a notification that there have been no changes):
```sh
make
```
Execute the `clean` section, removing files
```sh
make clean
```

Targets
- `tinyconfig` smallest possible kernel configuration
- `allnoconfig` answer no to every question when creating a config file

#### configure script
Responsible for preparing the software build, ensuring dependencies are available, such as a C compiler for C programs. `make` is invoked after the `configure` script has done its job. The __configure__ script converts a __Makefile.in__ template into a __Makefile__. They are not built by hand but packaged by yet another program in the __autotools__ suite, such as __autoconf__, __automake__, and others.

A configure.ac file written in **m4sh** (a combination of m4 macros and shell script) is prepared. The first m4 macro called i __AC_INIT__, which initializes autoconf:
```m4
AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
```
The __AM_INIT_AUTOMAKE__ macro is also called because we're using __automake__:
```m4
AM_INIT_AUTOMAKE
```
#### Other examples
Recompile [mail.md#sendmail]
```sh
make -C/etc/mail
```