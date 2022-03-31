# C

## Linux 

### Compiling

--8<-- "includes/Linux/Commands/pkg-config.md"

### Syscalls

The [**open()**](#open), [**close()**](#close), [**read()**](#read), and [**write()**](#write) syscalls form the heart of low-level file I/O in Linux.

Some system calls accept **flag arguments**, specified using symbolic constants.
Some of these are single-bit values which are combined into a single value using the bitwise OR operator **|**.


#### close
:   
    ```c
    close(fd);
    ```

    ```c hl_lines="22-23"
    --8<-- "includes/C/copy1.c"
    ```

#### exec
:   
    There are seven variations of **exec()**, all of which are used to replace the current process with the contents of another thread.
    
    These variations are distinguished by how they pass arguments (**l**ist or **v**ector), whether or not they create a new environment (**e**), and whether they require a full pathname or must search on the path environment variable (**p**).
    For example, **execvpe** specifies an executable on the path, creates a new environment, and passes arguments in a vector.

    ```c hl_lines="11"
    --8<-- "includes/C/tinyshell.c"
    ```

#### exit
:   
    **exit()** ends the program, returning the integer provided in parentheses as the exit status of the process.

#### fork
:   
    **fork()** is used to create a new process and is typically associated with [**exec()**](#exec) and [**wait()**](#wait).

    This simple example shows how the value returned by the fork() call differs between the parent and child processes.
    ```c
    --8<-- "includes/C/fork.c"
    ```

    ```c hl_lines="2 8"
    --8<-- "includes/C/learning-fork.c"
    ```

#### ftruncate
:   
    ```c hl_lines="23"
    --8<-- "includes/C/ipc-producer.c"
    ```

#### getpid
:   
    ```c
    #include <unistd.h>

    getpid();
    ```

    ```c hl_lines="15"
    --8<-- "includes/C/exit-status.c"
    ```

#### getrandom
:   
    [Introduced](https://lwn.net/SubscriberLink/884875/58f88e6eb7913686/) in Linux 3.17 to allow userspace applications to request random numbers in the case of no access to random devices (i.e. containers).
    By default it will use the [/dev/urandom]() pool, which normally does not block. 
    A flag can be provided to use the /dev/random pool instead.

#### lseek
:   
    Repositions the file read/write offset, allowing random access to an open file descriptor.
    ```c
    #include <unistd.h>

    lseek(
        fd, 
        offset, // (1)
        whence  // (2)
    );
    ```

    1. Byte offset, positive or negative (usually negative when with respect to end-of file using **SEEK\_END** flag).
    2. Accepts one of several flags that determine where the offset is relative to: **SEEK\_SET** (beginning of file), **SEEK\_CUR** (current position), or **SEEK\_END** (end of file).

    ```c
    --8<-- 
    ```

#### malloc
:   


#### memcpy
:   
    Used for copying stack-allocated data.

    ```c
    memcpy(
        dst,  //
        size, //
        flags //
    );
    ```

#### mmap
:   
    Maps a file into memory, allowing it to be accessed as if were an array.
    ```c
    mmap(
        addr,   // (1)
        length, // (2)
        prot,   // (3)
        flags,  // (4)
        fd,     // (5)
        offset  // (6)
    );  // (7)
    ```

    1. Commonly set to **NULL**, allowing the kernel to choose the address.
    2. Length of the mapping
    3. Typically a combination of **PROT\_READ** and/or **PROT\_WRITE**
    4. Determines whether the mapped region is shared with other processes: **MAP\_SHARED** or **MAP\_PRIVATE**
    5. File descriptor from [**open()**](#open)
    6. Multiple of page size, and often set to 0 to map the entire file
    7. Return value is the address to which the file has been mapped (similar to [**malloc()**](#malloc))

    === "IPC producer"

        ```c hl_lines="26"
        --8<-- "includes/C/ipc-producer.c"
        ```

    === "IPC consumer"

        ```c hl_lines="16"
        --8<-- "includes/C/ipc-consumer.c"
        ```

#### msync
:   


#### open
:   
    A call to **open()** creates a new open file descriptor

    ```c
    fd = open("foo", O_RDWR   | // (1) 
                    O_TRUNC  | // (2) 
                    O_APPEND   // (3)
    );
    ```

    1. **Access mode** flag specifying reading and writing: **O\_RDWR**, **O\_RDONLY**, or **O\_WRONLY**.
    2. **Open-time** flag required for writing. However, calling [**ftruncate()**](#ftruncate) is recommended over use of this flag in [**open()**](#open), which is retained for backwards compatibility.
    3. **Operating mode** flag that makes all write operations write data at the end of the file, extending it, regardless of the current file position.

    ```c
    --8<-- "includes/C/copy1.c"
    ```

#### read
:   
    Like [**write()**](#write), calls to read() require require a pointer to the buffer as well as the count of bytes which must not exceed the buffer's actual size.
    read() will return the number of bytes actually read and 0 on end-of-file.
    ```c
    read(fd, buffer, count);
    ```

    ```c hl_lines="19"
    --8<-- "includes/C/copy1.c"
    ```

#### shm_open
:   
    ```c hl_lines="20"
    --8<-- "includes/C/ipc-producer.c"
    ```

#### shm_unlink
:   
    Removes the shared-memory segment after the consumer has accessed it.
    ```c hl_lines="20"
    --8<-- "includes/C/ipc-consumer.c"
    ```

#### wait
:   
    wait() blocks until one of the process's children terminates and returns an integer.

    ```c
    int status;
    wait(&status); // (1)
    ```

    1. Passing 0 or NULL will discard the child's exit status.

    The exit status is separted into upper and lower bytes.
    If the process was killed by a signal the top bit of the lower byte is called the "Core Dumped" flag.
    There are several macros used to analyze the exit status.

    - **WIFEXITED** true if child exited normally
    - **WEXITSTATUS**
    - **WIFSIGNALED** true if child terminated by signal
    - **WTERMSIG** signal number

    ```c
    --8<-- "includes/C/exit-status.c"
    ```

    ```c hl_lines="16"
    --8<-- "includes/C/learning-fork.c"
    ```

#### write
:   
    Like [**read()**](#read), write() takes an integer file descriptor, a pointer to the buffer, as well as a count of bytes which must not exceed the buffer's size.

    ```c hl_lines="20"
    write(fd, buffer, count);
    ```

    ```c
    --8<-- "includes/C/copy1.c"
    ```

### Pthreads

Pthreads provides an API for multithreaded programming in C.
In Pthreads, new threads are spawned explicitly using [**pthread\_create**](#pthread_create) passing the name of a function which the thread will run.

Notably, this function must have precisely the following signature:
```c
void *func(void *arg)
```

Also, when compiling a program using Pthreads with gcc the **-lpthread** option must be set.

#### pthread\_attr\_init
:   
    ```c hl_lines="13"
    ---8<-- "includes/C/pthreads.c"
    ```

#### pthread\_create
:   
    ```c hl_lines="14"
    --8<-- "includes/C/pthreads.c"
    ```

#### pthread\_exit
:   
    ```c hl_lines="28"
    --8<-- "includes/C/pthreads.c"
    ```


#### pthread\_join
:   
    ```c hl_lines="15"
    --8<-- "includes/C/pthreads.c"
    ```

### Structs

#### task\_struct
:   
    Represents the [**process control block**](/Coding/CS/#pcb)

## Tasks

### GTK

#### Hello, World!
:   
    <figure markdown> ![](/img/GTK/Hello-World/label.png) </figure>

    ```c
    --8<-- "includes/C/GTK/hw.c"
    ```

    1. Without connecting the signals, the process will not terminate after clicking the close button, although the window will close.
