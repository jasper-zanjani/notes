#### pkg-config
:   
    Compiling a GTK program written in C

    ```sh
    gcc -Wall -g helloworld.c -o helloworld \
        $(pkg-config --cflags gtk+-3.0)     \ // (1)
        $(pkg-config --libs gtk+-3.0)         // (2)
    ```

    1. pkg-config returns directory names, which gcc will use tto ensure all header files are available.
    2. Here, pkg-config appends options to eh command-line used by the linker including library directory path extensions and a list of libraries needed for linking to the executable.