# makefiles

## use case
Given 3 files in a directory
  1. main.cpp
  2. message.cpp
  3. message.h
`g++ main.cpp message.cpp`
  produces `a.out` which is executable

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
