# MSCS

*[IPC]: Inter-Process Communication
*[ELF]: Executable and Linkable Format
*[LKM]: Loadable Kernel Module
*[eBPF]: extended Berkeley Packet Filter
*[PID]: process identifier

??? info "Links"

    - [Program description](https://catalog.usf.edu/preview_program.php?catoid=12&poid=4002&returnto=1384#)
    - [Course descriptions](http://ugs.usf.edu/pdf/cat0405/allcour.pdf)

## Core requirements

- COP 6611 Operating Systems 
    - [Course description (2021-2022)](https://catalog.usf.edu/content.php?filter%5B27%5D=COP&filter%5B29%5D=6611&filter%5Bcourse_type%5D=-1&filter%5Bkeyword%5D=&filter%5B32%5D=1&filter%5Bcpage%5D=1&cur_cat_oid=15&expand=&navoid=2112&search_database=Filter&filter%5Bexact_match%5D=1#acalog_template_course_filter)
    - [Syllabus](http://www.cse.usf.edu/~lohall/cop6611/syllabus17.pdf)
    - Book: Silberschatz, et al. *Operating Systems Concepts*. 10th ed.
- EEL 6764 Principles of computer architecture 
    - [Course description (2021-2022)](https://catalog.usf.edu/content.php?filter%5B27%5D=EEL&filter%5B29%5D=6764&filter%5Bcourse_type%5D=-1&filter%5Bkeyword%5D=&filter%5B32%5D=1&filter%5Bcpage%5D=1&cur_cat_oid=15&expand=&navoid=2112&search_database=Filter&filter%5Bexact_match%5D=1#acalog_template_course_filter)
    - [Syllabus](https://cse.usf.edu/~haozheng/teach/eel6764/syllabus/f18.pdf)
    - Book: Hennessy, et al. *Computer Architecture: A Quantitative Approach*.
- COT 6405 Theory of Algorithms
    - [Course description (2021-2022)](https://catalog.usf.edu/content.php?filter%5B27%5D=COT&filter%5B29%5D=6405&filter%5Bcourse_type%5D=-1&filter%5Bkeyword%5D=&filter%5B32%5D=1&filter%5Bcpage%5D=1&cur_cat_oid=15&expand=&navoid=2112&search_database=Filter&filter%5Bexact_match%5D=1#acalog_template_course_filter)
    - [Syllabus](https://cse.usf.edu/~yliu21/Algorithm/syllabus.pdf)
    - Book: Cormen, et al. *Introduction to Algorithms*. 3rd ed.

## Operating Systems

**System calls** provide an interface to operating system services, but are to be distinguished from
**API**s (like **libc** in Linux) that expose functions intended for use by application programmers and abstract and hide the implementation detail of system calls.
The **runtime environment (RTE)** includes all software needed to run applications written in a particular language, such as compilers, interpreters, libraries, and loaders.
The RTE constitutes a **system-call interface** that links API functional calls to OS syscalls.

At the level of CPU architecture, the ABI defines how binary code interfaces for a given OS on a given architecture.

Three methods passing parameters to system calls:

- Parameters passed to registers individually
- Passing to a single register the address a block or table in memory containing parameters (if there are more parameters than registers)
- Push parameters onto a stack, which is popped by the OS

Syscalls can be grouped into several functional categories:

- Process control: creating, controlling, and ending processes
- File management: creating, deleting, opening, reading, writing, repositioning files and getting and setting file attributes
- Device management: granting access to system resources, including physical and virtual devices
- Information maintenance: dumping memory for debugging, the **single step** CPU mode which executes a trap after every instruction, as well as trivial calls to retrieve date and time
- Communications: both **message-passing** and **shared-memory** models of IPC as well as network stack
- Protection: file and disk permissions
  
**System utilities** facilitate user interfaces to system calls with CLI and GUI tools.

Source files are compiled into **relocatable object files** that are combined into a single binary **executable** file by the **linker**, which is then loaded into memory by the **loader**.
Associated with this process is **relocation** which assigns final memory addresses to the program parts, adjusting code and data accordingly.
Most systems allow **dynamically linked libraries** which are linked and loaded when needed, reducing the size of the executable.

Object and executable files have standard formats that determine the layout of the header, instructions, and variables which must be at certain locations in specified structures so that the OS can open the file:

- Linux: ELF
- Windows: Portable Executable (PE)
- macOS: Mach-O

Operating systems can be categorized by design methodology:

- **Monolithic** kernels have the greatest performance because all the functionality of the kernel runs in a single address space loaded from a single binary file. However these kernels are **tightly coupled** systems and are harder to design and maintain.
- **Layered** operating systems have the advantage of simplicity, since once lower layers are debugged they can be relied on to support higher-level functions. However, performance is poor due to the overhead of traversing multiple layers.
- **Microkernels** remove all nonessential functions and move them into userspace. Extending the OS is easier, and security is good, but performance is worse than monolithic kernels.
- **Modularity**, as implemented in Linux device drivers which are implemented as LKMs, allows a kernel to dynamically load dependencies when needed.

In practice, all OSes in use combine different structures as expedient, forming hybrids of these ideal types.

**Debugging** is the activity of finding and fixing errors in a system.
OSes typically write error information to logs and can also capture **core dumps**, a capture of the memory of a process.

Performance of a system can be monitored using **counters** and **tracing**:

- Counters on Linux like ps, top, vmstat, netstat, and iostat can provide information on a granular, per-process level or across the system. They rely on the virtual filesystems mounted by the Linux kernel at /proc.
- Tracing tools like strace, gdb, perf, and tcpdump are used to investigate an individual event in the course of debugging. 

A promising new approach to debugging is using **eBPF**, which can also capture tracing information using an in-kernel virtual machine that executes eBPF instructions.
**BPF Compiler Collection (BCC)** is a set of Python scripts that embed C code and provide a frontend to eBPF.

### Processes

A **process** is a program in execution and comprises the fundamental unit of work and main concern of a computer system.

The memory layout of a process can be separated into several sections:

- Text: executable code
- Data: global variables
- Heap: memory dynamically allocated during runtime
- Stack: parameters, return addresses, and local variables used during function invocation

Each time a function is called, an **activation record** containing function parameters, local variables, and the return address is pushed onto the stack. 
When control is returned from the function, the activation record is popped from the stack.
The stack (which begins at the **top** of the program's allocated memory range) and heap sections will grow toward each other but must never overlap.
The memory used by these sections can be displayed with the **size** command.

Each process is represented in the operating system by a **process control block (PCB)**{: #pcb } (represented by [**task\_struct**](/Coding/C/#task_struct) in Linux).
On systems that support threads, the PCB is expanded to include information for each thread.

The **CPU scheduler** selects processes for execution, a process called **dispatching**, or moves them to and from various queues: the **ready queue** where a process awaits dispatch or the **wait queue** where a process awaits the completion of I/O.
When the CPU core switches to another process, the **state** of one process is saved and that of another is restored, a process called **context-switching**.

A parent process may create new processes called children (see [**fork**](/Coding/C/#fork)), identified by an integer number known as a PID.
In a normal operating system the processes form a **process tree** stemming from a single root, the initial process which has a PID of 1 (on modern Linux systems, **systemd**).

Processes can terminate themselves (see [**exit**](/Coding/C/#exit)) or be terminated due to a variety of circumstances.
A parent process can wait for the termination of a child process with [**wait**](/Coding/C/#wait).
A process that has terminated but whose parent has not yet called wait is a **zombie** process. All processes transition to this state briefly when they terminate.
Some OSes like LInux allow **orphan** processes to continue existing after the parent process has terminated.
In other systems, terminating all children when the parent is terminated is referred to as **cascading termination**.


In IPC, processes exchange data using one of two methods: **shared memory** or **message passing**.
Shared memory in Linux is implemented with **memory-mapped files** 

### Concurrency

A **thread**, comprising a thread identifier, a program counter (PC), a register set, and a stack, is the basic unit of CPU utilization. 
All threads from a single process share its code and data sections and other OS resources like open files and signals.

Multithreaded programming allows more efficient use of multicore and multi-CPU systems, since each core is only capable of processing a single thread at a time.
Such systems are **pareallel** systems because they can perform more than one task at a time.
**Concurrent** systems are ones that support more than one task by allowing all tasks to make progress.
Single-core systems could achieve concurrency through the use of CPU schedulers, but not parallelism.

Contemporary OSes support **kernel threads** which are managed directly by the OS.
**User threads** in contrast are supported above the kernel and managed without kernel support.

**Pthreads** is the threads extension of the POSIX specification and can be provided as either a kernel-level or user-level library.
In a Pthreads program, separate threads begin execution in a specified function.

**Implicit threading** refers to the increasingly popular strategy of transfering the burden of creating and managing threading from application developers to compilers and runtime libraries.
Several implicit threading approaches have evolved:

- **Thread pools** maintain a finite number of threads which await work, preventing resource exhaustion by having an unbounded number of possible threads.
- **Fork-join model** is often characterized as explicit thread creation, but by creating parallel tasks using the library instead of threads during the fork phase directly it can be implicit.
- **OpenMP** is a C++ library that provides an API of compiler directives that mark out **parallel regions**, or blocks of code that may run in parallel, creating as many threads as there are processing cores available.
- **Grand Central Dispatch (GCD)** is an Apple runtime library, API, and language extensions that allow developers to identify sections of code to run in parallel.
- **Thread Building Blocks (TBB)** is a C++ template library

In Linux, a **struct task\_struct**, which contains pointers to other data structures where data are stored, exists for each task in the system.