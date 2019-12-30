# makefiles
A common formula when installing software from source is the following
```sh
./configure
make
make install
```

## use case
Given 3 files in a directory
1. main.cpp
2. message.cpp
3. message.h

Produces `a.out` which is executable
```sh
g++ main.cpp message.cpp
```

But for large projects, with potentially thousands of files, this is impractical

## format
follows the pattern:
```makefile
{target}: {dependencies}
  {action}
```
  - because makefiles are whitespace-sensitive, the indentation is significant
  - `{target}` is the filename produced by the operation `{action}`

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
  - for any changes in `main.o` and `message.o`, they will be recompiled into `output`, which is the executable
  - `-c` flag on `g++` will compile the code into an object file but not into a binary, creating `main.o`
## Command line
`make`
  - command-line command which will executes the operations specified in the makefile
  - executing the command a second time without any changes will produce a notification that there have been no changes
  - updates of the source files are detected via timestamps
`make clean`
  executes the `clean` section, removing the files

## Targets
`tinyconfig` smallest possible kernel configuration
`allnoconfig` answer no to every question when creating a config file

## configure script
Responsible for preparing the software build, ensuring dependencies are available, such as a C compiler for C programs. __make__ is invoked once the __configure__ script has done its job. The __configure__ script converts a __Makefile.in__ template into a __Makefile__. They are not built by hand but packaged by yet another program in the __autotools__ suite, such as __autoconf__, __automake__, and others.

A __configure.ac__ file written in m4sh (a combination of m4 macros and shell script) is prepared. The first m4 macro called i __AC_INIT__, which initializes autoconf:
```m4
AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
```
The __AM_INIT_AUTOMAKE__ macro is also called because we're using __automake__:
```m4
AM_INIT_AUTOMAKE
```

#### Projects that use `make`
- [`most`](https://github.com/FauxFaux/most-pager/ "GitHub - FauxFaux/most-pager")

## Sources
- [Thoughtbot](https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install)