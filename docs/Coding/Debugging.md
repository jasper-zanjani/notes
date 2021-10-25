# Debugging

## Debuggers

### pdb <sup>:material-language-python:</sup>

```sh
python -m pdb script.py
```

--8<-- "includes/Coding/Python/hwp.md"

Use debugging to intercept the value of the variable before the final string is displayed.

--8<-- "includes/Coding/Python/factorial.md"

When running pdb with no breakpoints, top-level statements begin to be executed. The debugger proceeds from top to bottom, following the interpreter, from import statements to function definitions, until it finally reaches the entrypoint.
If the debugger is directed to **step over** the main function, the program will execute normally.

The entirety of the source code can be printed to the interactive pdb shell by using [**`ll`** or **`longlist`** <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-ll).

A similar command is [**l**[ist] <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-list) which lists 11 lines around the current line. 
Repeated execution progressively print more of the source.

The [**c**[ontinue] <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-continue) command results in the execution being resumed without interruption until the next breakpoint. 
If no breakpoints are defined, the program is executed as it would be normally.

Invoking pdb without any breakpoints and proceeding with [**n**[ext] <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-next) results in top-level code being executed.

Stepping into function calls with [**s**[tep] <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-step) is similar to adding a breakpoint at the function definition with [**b**[reak] <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-break), at least for a single function call.

In these examples, the factorial is being incorrectly calculated, such that it will always produce a 0.
This can be inspected in the debugger by using the [**p** <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-p) command, which evaluates the following arguments as an **expression**.

Alternatively, any Python **statement** can be preceded with the [**!** <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-!) command, with which you can change variable values.
Notably, any whitespace after `!` will cause an IndentationError


``` pdb
p factorial
!factorial = 120
```

The [**interact** <sup>:material-language-python:</sup>](https://docs.python.org/3/library/pdb.html#pdbcommand-interact) command allows you to enter a Python REPL, which allows statements to be interactively entered. 
However these do not have an effect on the program state once the shell is terminated.


``` pdb
(Pdb) p factorial
0
(Pdb) interact
>>> factorial = 120
>>> ^D
now exiting InteractiveConsole...
(Pdb) p factorial
0
```

### gdb

Invoke on executable "program", compiled with debugging symbols.
```sh
gdb program
```
Display the first 10 lines of source code from main.rs
```
list main.rs:0
```
Display the source code of the `stack_only` function
```
list stack_only
```

Run code after placing a breakpoint on functions "stack_only" and "stack_and_heap"
```gdb
b stack_only
b stack_and_heap
r
```
Display stack frames
```
bt 2
```
Inspect local variables and arguments
```
info locals
info args
```
Step forward
```
n
```
Display data at given memory location as a digit
```
x /d 0x55555559bba0
```
Enter TUI mode <kbd>Ctrl-X</kbd><kbd>A</kbd>. <sup>[:material-youtube:](https://www.youtube.com/watch?v=PorfLSr3DDI "CppCon 2015: Greg Law  Give me 15 minutes & I'll change your view of GDB")</sup>
This mode does not work well with print statements.

GDB also contains a Python runtime, so you can run commands inline using the **python** command.


## 📘 Glossary

**step into**
:   
    If the current line contains a function call, move execution context into it to continue stepwise execution of code statements within that function.

    If not, identical to **step over**

**step over**
:   
    Execute the current line and pause on the next.