[make -&#98;]:                  #make                          'Silently accepted, but ignored, for compatibility with other versions of `make`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 746'
[make -&#66;]:                  #make                          'Treat all targets as out of date. All targets are remade, no matter what the actual status is of their prerequisites&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 746'
[make -&#67;]:                  #make                          'Change directory to `$PATH` before reading makefiles; usually used for recursive invocations of `make`.'
[make -&#100;]:                 #make                          'Print debugging information in addition to regular output. This information includes which files are out of date, the file names being compared, '
[make -&#101;]:                 #make                          'Environment variables override any macros defined in makefiles.'
[make -&#102;]:                 #make                          'Use `$MAKEFILE` as the makefile; can be used more than once to concatenate multiple makefiles. If not specified, `make` looks for "GNUmakefile", "makefile", and "Makefile" in that order.'
[make -&#104;]:                 #make                          'Print a usage summary, and then exit.'
[make -&#105;]:                 #make                          'Ignore error codes from commands (equivalent to `.IGNORE`)'
[make -&#73;]:                  #make                          'Look in `$PATH` for makefiles included with the `include` directive. Multiple options add more directories to the list, which is searched by `make` in order.'
[make -&#106;]:                 #make                          'Run commands in parallel.'
[make -&#107;]:                 #make                          'Abandon the current target when it fails, but keep working with unrelated targets.'
[make -&#108;]:                 #make                          'If there are jobs running and the system load average is at least load, do not start any new jobs running.'
[make -&#109;]:                 #make                          'Silently accepted, but ignored, for compatibility with other version of `make`.'
[make -&#110;]:                 #make                          'Print commands but do not execute; used for testing.'
[make -&#111;]:                 #make                          'Pretend that `$FILE` is older than the files that depend upon it. This avoids remaking other files that depend on `$FILE`.'
[make -&#112;]:                 #make                          'Print macro definitions, suffixes, and built-in rules. In a directory without a makefile, use `env -i make -p` to print out the default variable definitions and built-in rules.'
[make -&#113;]:                 #make                          'Query; return 0 if the target is up to date; nonzero otherwise.'
[make -&#114;]:                 #make                          'Do not use the default rules. This also clears out the default list of suffixes and suffix rules.'
[make -&#115;]:                 #make                          'Do not display command lines (same as `.SILENT`)'
[make -&#83;]:                  #make                          'Cancel the effect of a previous `-k`. Only needed for recursive `make` invocations, where the `-k` option might be inherited via the `MAKEFLAGS` environment variable.'
[make -&#116;]:                 #make                          'Touch the target files, causing them to be updated.'
[make -&#118;]:                 #make                          ''
[make -&#119;]:                 #make                          'Print the working directory, before and after executing the makefile. Useful for recursive `make` invocations. This is usually done by default, so this option is rarely seen.'
[make -&#87;]:                  #make                          'Treat $FILE as if it had just been modified. Together with `-n`, this lets you see what `make` would do if `$FILE` were modified, without actually doing anything.'

<code>&nbsp;</code>   <code>&nbsp;</code> [`b`][make -&#98;] <code>&nbsp;</code> [`d`][make -&#100;] [`e`][make -&#101;] [`f`][make -&#102;] <code>&nbsp;</code> [`h`][make -&#104;] [`i`][make -&#105;] [`j`][make -&#106;] [`k`][make -&#107;] [`l`][make -&#108;] [`m`][make -&#109;] [`n`][make -&#110;] [`o`][make -&#111;] [`p`][make -&#112;] [`q`][make -&#113;] [`r`][make -&#114;] [`s`][make -&#115;] [`t`][make -&#116;] <code>&nbsp;</code> [`v`][make -&#118;] [`w`][make -&#119;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> [`B`][make -&#66;] [`C`][make -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`I`][make -&#73;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`S`][make -&#83;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`W`][make -&#87;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> 

A common formula when installing software from source is the [following](https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install "thoughtbot.com: \"The magic behind configure, make, make install\"") sequence of commands 
```sh
./configure
make
make install
```
Given there are 3 example files (main.cpp, message.cpp, and message.h) in a directory, it produces an executable file named `a.out`
```sh
g++ main.cpp message.cpp
```
Install an alternate version of a program like Python
```sh
cd /opt
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tgz
tar xzf Python-3.8.0.tgz
cd Python-3.8.0
./configure --enable-optimizations
make altinstall
```
**Makefiles** are sensitive to whitespace, so indentation is significant. The format follows the pattern:
```makefile
{target}: {dependencies}
  {action}
```
where `{target}` is the filename produced by the operation `{action}`, each of which are shell commands.

In [this example](https://subscription.packtpub.com/book/programming/9781838646554/1/ch01lvl1sec06/using-a-makefile-to-compile-and-link-a-program), **hw.o** is produced from **hw.cpp** first because it is a dependency of the executable **hw**. Notably, Makefiles appear to require hard tabs.
```make
CC = g++
all: hw
hw: hw.o
  ${CC} -o hw hw.o
hw.o: hw.cpp
  ${CC} -c hw.cpp
clean:
  rm *.o
```
To remove the .o files:
```sh
make clean
```
Targets
- `tinyconfig` smallest possible kernel configuration
- `allnoconfig` answer no to every question when creating a config file

A **configure script** is responsible for preparing the software build, ensuring dependencies are available, such as a C compiler for C programs. 
`make` is invoked after the `configure` script has done its job. 
The **configure** script converts a `Makefile.in` template into a **Makefile**. 
They are not built by hand but packaged by yet another program in the **autotools** suite, such as **autoconf**, **automake**, and others.

A configure.ac file written in **m4sh** (a combination of m4 macros and shell script) is prepared. The first m4 macro called i **AC_INIT**, which initializes autoconf:
```m4
AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
```
The **AM_INIT_AUTOMAKE** macro is also called because we're using **automake**:
```m4
AM_INIT_AUTOMAKE
```
