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