[aclocal]:                                           #aclocal                                            '```&#10;$ aclocal&#10;```&#10;Place m4 macro definitions needed by `autoconf` into a single file. `aclocal` first scans for macro definitions in m4 files in its default directory (/usr/share/aclocal) and in the file acinclude.m4, then in the configure.ac file. IT generates an aclocal.m4 file that contains definitions of all m4 macros required by `autoconf`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 16'
[autoconf]:                                          #autoconf                                           '```&#10;$ autoconf&#10;```&#10;Generate a configuration script from m4 macros defined in a template file, if given, or in a configure.ac or configure.in file in the CWD. The generated script is almost invariably called "configure".&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoheader]:                                        #autoheader                                         '```&#10;$ autoheader&#10;```&#10;Generate a template file of C `#define` statements from m4 macros defined in a template file, if specified, or in configure.ac or configure.in in the CWD. The generated template file is almost invariably called config.h.in or config.hin&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 22'
[automake]:                                          #automake                                           '```&#10;$ automake&#10;```&#10;Create GNU standards-compliant Makefile.in files from Makefile.am template files&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 23'
[autoreconf]:                                        #autoreconf                                         '```&#10;$ autoreconf&#10;```&#10;Update configure scripts by running `autoconf`, `autoheader`, `aclocal`, `automake`, and `libtoolize` as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoscan]:                                          #autoscan                                           '```&#10;$ autoscan&#10;```&#10;Create or maintain a preliminary configure.ac file named configure.scan based on source files in specified directory or CWD.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[autoupdate]:                                        #autoupdate                                         '```&#10;$ autoupdate&#10;```&#10;Update the configure template file or configure.ac if none is specified&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 21'
[bison]:                                             #bison                                              '```&#10;$ bison&#10;```&#10;Convert specified "file.y" containing a context-free grammar into tables for subsequent parsing while sending output to a new file named "file.c". Largely compatible with `yacc`, from which it derives its name.&#10;Originated as an adaptation of Bob Corbett\'s reimplementation of yacc which was distributed under the Berkeley license. Now maintained as a project of the FSF under a GPL license.'
[cc]:                                                #cc                                                 '```&#10;$ cc&#10;```&#10;Compile one or more C (.c), assembler (.s), ore preprocessed C (.i) source files. Automatically invokes the loader `ld`, unless `-c` is supplied. In some cases, `cc` generates an object file having a .o suffix and a corresponding root name. By default, output is placed in a.out&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[flex]:                                              #flex                                               '```&#10;$ flex&#10;```&#10;"fast lexical analyzer generator", version of `lex` translated into C by Vern Paxson'
[ldd]:                                               #ldd                                                '```&#10;$ ldd&#10;```&#10;Display shared libraries used by a specified command&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 87'
[lex]:                                               #lex                                                '```&#10;$ lex&#10;```&#10;Generate a lexical analysis program based on the regular expressions and C statements contained in one or more input files&#10;Lexical analyzer generator written by Eric Schmidt'
[make]:                                              #make                                               '```&#10;$ make&#10;```&#10;Utility for building and maintaining programs from source code using a makefile&#10;Rothwell, William. _CompTIA Linux+ Portable Command Guide_.: 86'
[yacc]:                                              #yacc                                               '```&#10;$ yacc&#10;```&#10;"yet another compiler-compiler", parser generator that converts a file containing a context-free LALR grmamar and converts it to tables for subsequent pasring, sending output to y.tab.c. Written between 1975 and 1978 by Stephen C. Johnson at Bell Labs.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 237'

<!-- `cc` options -->
[cc -c]:                                              #cc                                                '```&#10;$ cc -c&#10;```&#10;suppress loading and keep any object files that were produced&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -D]:                                              #cc                                                '```&#10;$ cc -D $NAME=$DEF&#10;```&#10;supply a `#define` directive, defining `$NAME` to be `$DEF` (or 1 by default)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -E]:                                              #cc                                                '```&#10;$ cc -E&#10;```&#10;run only the macro preprocessor, sending results to STDOUT&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -g]:                                              #cc                                                '```&#10;$ cc -g&#10;```&#10;generate more symbol-table information needed for debuggers&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -I]:                                              #cc                                                '```&#10;$ cc -I $PATH&#10;```&#10;search for include files in directory `$PATH` (in addition to standard locations). Supply a `-I` for each new `$PATH` to be searched.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -l]:                                              #cc                                                '```&#10;$ cc -l $NAME&#10;```&#10;Link source file with library files "lib$NAME.so" or "lib$NAME.a"&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -L]:                                              #cc                                                '```&#10;$ cc -L $PATH&#10;```&#10;Like `-I`, but search `$PATH` for library archives&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -o]:                                              #cc                                                '```&#10;$ cc -o $FILE&#10;```&#10;Send object output to `$FILE` instead of to a.out.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -O]:                                              #cc                                                '```&#10;$ cc -O&#10;```&#10;Optimize object code (produced from .c or .i files). Some compilers accept an additional argument to `-O` specifying the optimization level.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -p]:                                              #cc                                                '```&#10;$ cc -p&#10;```&#10;Generate benchmark code to count&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -P]:                                              #cc                                                '```&#10;$ cc -P&#10;```&#10;Run only the preprocessor and place the result in "file.i"&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -S]:                                              #cc                                                '```&#10;$ cc -S&#10;```&#10;Compile (and optimize, if `-O` is supplied), but do not assemble or load; assembler output is placed in file.s.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'
[cc -U]:                                              #cc                                                '```&#10;$ cc -U $NAME&#10;```&#10;Remove definition of `$NAME`, as if through an `#undef` directive.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 32'

<!-- `make` options -->
[make -b]:                                            #make                                              '```&#10;$ make -b&#10;```&#10;Silently accepted, but ignored, for compatibility with other versions of `make`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 746'
[make -B]:                                            #make                                              '```&#10;$ make -B&#10;$ make --always-make&#10;```&#10;Treat all targets as out of date. All targets are remade, no matter what the actual status is of their prerequisites&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 746'
[make -C]:                                            #make                                              '```&#10;$ make -C $PATH&#10;$ make --directory $PATH&#10;```&#10;Change directory to `$PATH` before reading makefiles; usually used for recursive invocations of `make`.'
[make -d]:                                            #make                                              '```&#10;$ make -d&#10;$ make --debug=a&#10;```&#10;Print debugging information in addition to regular output. This information includes which files are out of date, the file names being compared, '
[make -e]:                                            #make                                              '```&#10;$ make -e&#10;$ make --environment-overrides&#10;```&#10;Environment variables override any macros defined in makefiles.'
[make -f]:                                            #make                                              '```&#10;$ make -f $MAKEFILE&#10;$ make --file $MAKEFILE&#10;```&#10;Use `$MAKEFILE` as the makefile; can be used more than once to concatenate multiple makefiles.If not specified, `make` looks for "GNUmakefile", "makefile", and "Makefile" in that order.'
[make -h]:                                            #make                                              '```&#10;$ make -h&#10;$ make --help&#10;```&#10;Print a usage summary, and then exit.'
[make -i]:                                            #make                                              '```&#10;$ make -i&#10;$ make --ignore-errors&#10;```&#10;Ignore error codes from commands (equivalent to `.IGNORE`)'
[make -I]:                                            #make                                              '```&#10;$ make -I $PATH&#10;$ make --include-dir $PATH&#10;```&#10;Look in `$PATH` for makefiles included with the `include` directive. Multiple options add more directories to the list, which is searched by `make` in order.'
[make -j]:                                            #make                                              '```&#10;$ make -j $COUNT&#10;$ make --jobs $COUNT&#10;```&#10;Run commands in parallel.'
[make -k]:                                            #make                                              '```&#10;$ make -k&#10;$ make --keep-going&#10;```&#10;Abandon the current target when it fails, but keep working with unrelated targets.'
[make -l]:                                            #make                                              '```&#10;$ make -l $LOAD&#10;$ make --load-average $LOAD&#10;```&#10;If there are jobs running and the system load average is at least load, do not start any new jobs running.'
[make -m]:                                            #make                                              '```&#10;$ make -m&#10;```&#10;Silently accepted, but ignored, for compatibility with other version of `make`.'
[make -n]:                                            #make                                              '```&#10;$ make -n&#10;$ make --dry-run&#10;```&#10;Print commands but do not execute; used for testing.'
[make -o]:                                            #make                                              '```&#10;$ make -o $FILE&#10;$ make --assume-old $FILE&#10;```&#10;Pretend that `$FILE` is older than the files that depend upon it. This avoids remaking other files that depend on `$FILE`.'
[make -p]:                                            #make                                              '```&#10;$ make -p&#10;$ make --print-data-base&#10;```&#10;Print macro definitions, suffixes, and built-in rules. In a directory without a makefile, use `env -i make -p` to print out the default variable definitions and built-in rules.'
[make -q]:                                            #make                                              '```&#10;$ make -q&#10;$ make --question&#10;```&#10;Query; return 0 if the target is up to date; nonzero otherwise.'
[make -r]:                                            #make                                              '```&#10;$ make -r&#10;$ make --no-builtin-rules&#10;```&#10;Do not use the default rules. This also clears out the default list of suffixes and suffix rules.'
[make -s]:                                            #make                                              '```&#10;$ make -s&#10;$ make --silent&#10;```&#10;Do not display command lines (same as `.SILENT`)'
[make -S]:                                            #make                                              '```&#10;$ make -S&#10;$ make --stop&#10;```&#10;Cancel the effect of a previous `-k`. Only needed for recursive `make` invocations, where the `-k` option might be inherited via the `MAKEFLAGS` environment variable.'
[make -t]:                                            #make                                              '```&#10;$ make -t&#10;$ make --touch&#10;```&#10;Touch the target files, causing them to be updated.'
[make -v]:                                            #make                                              '```&#10;$ make -v Print version, copyright, and author information, and exit.&#10;$ make --version Print version, copyright, and author information, and exit.&#10;```&#10;'
[make -w]:                                            #make                                              '```&#10;$ make -w&#10;$ make --print-directory&#10;```&#10;Print the working directory, before and after executing the makefile. Useful for recursive `make` invocations. This is usually done by default, so it is rare to explicitly need this option.'
[make -W]:                                            #make                                              '```&#10;$ make -W $FILE&#10;$ make --assume-new $FILE&#10;```&#10;Treat $FILE as if it had just been modified. Together with `-n`, this lets you see what `make` would do if `$FILE` were modified, without actually doing anything.'

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
[`cc`][cc]                | <code>&nbsp;</code>  <code>&nbsp;</code>  [`c`][cc -c]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`g`][cc -g]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`l`][cc -l]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`o`][cc -o]  [`p`][cc -p]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code><br>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`D`][cc -D]  [`E`][cc -E]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`I`][cc -I]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`L`][cc -L]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`O`][cc -O]  [`P`][cc -P]  <code>&nbsp;</code>  <code>&nbsp;</code>  [`S`][cc -S]  <code>&nbsp;</code>  [`U`][cc -U]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
[`flex`][flex] | 
[`ldd`][ldd] | 
[`lex`][lex] | 
[`make`][make] | <code>&nbsp;</code>  <code>&nbsp;</code>  [`b`][make -b]  <code>&nbsp;</code>  [`d`][make -d]  [`e`][make -e]  [`f`][make -f]  <code>&nbsp;</code>  [`h`][make -h]  [`i`][make -i]  [`j`][make -j]  [`k`][make -k]  [`l`][make -l]  [`m`][make -m]  [`n`][make -n]  [`o`][make -o]  [`p`][make -p]  [`q`][make -q]  [`r`][make -r]  [`s`][make -s]  [`t`][make -t]  <code>&nbsp;</code>  [`v`][make -v]  [`w`][make -w]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code> <br><code>&nbsp;</code>  <code>&nbsp;</code>  [`B`][make -B]  [`C`][make -C]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`I`][make -I]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`S`][make -S]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>  [`W`][make -W]  <code>&nbsp;</code>  <code>&nbsp;</code>  <code>&nbsp;</code>
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