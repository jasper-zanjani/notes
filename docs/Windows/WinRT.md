## C#/WinRT

**C#/WinRT** represents a decoupling of the Windows-specific APIs from .NET
It builds **interop assemblies** from a Windows Metadata file (/*.winmd).
It builds C# code from such a WinMD file, then compiles it into a **projection assembly**.
This allows the creation of C# **runtime components** hosted in non-.NET languages.

.NET Core 3 and .NET Framework ("NETFX") applications can continue to use the **Microsoft.Windows.SDK.Contracts** NuGet package.

Resources:

- ▶ [How to call WinRT APIs from .NET5 applications](https://www.youtube.com/watch?v=wy5VB-2kF6I)

## C++/CX

Compile a C++ to a DLL ([src](https://app.pluralsight.com/course-player?clipId=a1559ea6-7439-4ab5-b3ca-81faa1716cb7))

Invoke 📄 [MSVC](https://docs.microsoft.com/en-us/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-160), creating:

- **Library.dll**
- **Library.lib**
- Library.exp
- Library.obj

=== "Command-line"

    ```cmd
    cl /w4 /ld Library.cpp Library.def
    ```

=== "Library.cpp"

    ```cpp
    #include "Library.h"
    #include <stdio.h>

    void Cluck()
    {
        printf("C-style cluck!\n");
    }
    ```

=== "Library.h"

    ```cpp
    #pragma once

    void Cluck();
    ```

=== "Library.def"

    A definitions file is broken into sections, all of which are optional.
    ```
    EXPORTS

    Cluck
    ```

Now the libary can be used in an application

=== "Command-line"

    ```cmd
    cl /W4 Application.cpp /link Library.lib
    ```

=== "Application.cpp"

    ```cpp
    #include "Library.h"

    int main()
    {
        Cluck();
    }
    ```
