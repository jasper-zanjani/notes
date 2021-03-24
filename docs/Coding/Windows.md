# Windows programming

## 📘 Glossary


### C++/CX

**C++/CX** is a legacy [language projection](#language-projection) that uses nonstandard C++ (see [C++/WinRT](#cwinrt)).

Compile a C++ to a DLL ([src](https://app.pluralsight.com/course-player?clipId=a1559ea6-7439-4ab5-b3ca-81faa1716cb7))

Invoke :material-file-document-multiple-outline: [MSVC](https://docs.microsoft.com/en-us/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-160), creating:

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

### C++/WinRT [:octicons-mark-github-16:](https://github.com/microsoft/cppwinrt)

## C#/Win32 [:material-dot-net:](https://www.nuget.org/packages/Microsoft.Windows.CsWin32)

Resources:

- ▶ [Windows APIs Everywhere in .NET](https://www.youtube.com/watch?v=InQtHPumUyw)

### C#/WinRT [:material-dot-net:](https://www.nuget.org/packages/Microsoft.Windows.CsWinRT/) [:octicons-mark-github-16:](https://github.com/microsoft/CsWinRT)


.NET Core 3 and .NET Framework ("NETFX") applications can continue to use the **Microsoft.Windows.SDK.Contracts** NuGet package.

**C#/WinRT** is the [WinRT](#winrt) [language projection](#language-projection) for C#, created after .NET5 removed WinRT projection support for C# out of the .NET compiler. 
This represents a decoupling of the Windows-specific APIs from .NET

It is used to create C# **runtime components** hosted in non-.NET languages by first building [interop assemblies](#interop-assembly) from [Windows Metadata](#winmd) files using  **cswinrt.exe**.


Resources:

- ▶ [How to call WinRT APIs from .NET5 applications](https://www.youtube.com/watch?v=wy5VB-2kF6I)


### COM

**Component Object Model** was developed in the late 1980s by Microsoft.
The **Component Object Model** is a binary standard interface specification for objects.
It originated in 1993 as a renaming of OLE (Object Linking and Embedding) 2.0, used by Microsoft Office at the time to link data between applications.

COM objects support a collection of interfaces, most importantly **`IUnknown`** which all COM objects must implement.
IUnknown includes `QueryInteface()` which returns pointers to the other interfaces also implemented by the COM object.
It also includes `AddRef()` and `Release()`, which manage the object's lifetime.

COM uses **`HRESULT`**s, 32-bit longs, to indicate success or failure.
Bit 31 indicates success (0) or failure (1).
With .NET [interop](#interop-assembly), a failed `HRESULT` turns into a thrown COMException.
Common `HRESULT`s include `S_OK`, `S_FALSE`, `E_FAIL`, and many other failure codes also beginning with `E_`.

COM objects are created by calling `CoCreateInstance()`.
This function, which is stored in **ole32.dll**, searches the Registry for the given class ID, then loads the apropriate **COM Server** DLL file.
This DLL file then creates a class factory which then creates the COM instance, which is passed back to the client as an interface pointer.
([src](https://app.pluralsight.com/course-player?clipId=741b49fc-646c-49ba-8ec3-497d046bbaf1))

COM classes must be registered in the Registry, at minimum by mapping the class ID (a GUID) to a DLL, in the **HKEY_CLASSES_ROOT** hive.
This is done using the **regsvr32.exe** utility.
([src](https://app.pluralsight.com/course-player?clipId=dc4cc210-1265-48c2-aafe-36da5481e544))


### Core application

**Core application** refers to the lifecycle of a UWP application, through which Windows offers app-specific services relating to power management, security, etc and abstracts the app itself.
It offers a level of control over graphical applications comparable to that available for apps as services. ([src](https://app.pluralsight.com/course-player?clipId=b35aed5b-22a5-401d-82c8-75909092cab6))


### DirectX

DirectX is a gaming API that was created by Eric Engstrom (d. 2020), Alex St. John, and Craig Eisler in 1994 to support game development on Windows 95.

### Interop assembly

**Interop assemblies** allow .NET applications to call native code. 
They can be distributed along with applications that reference them.

[Language projections](#language-projection) like [C#/WinRT](#cwinrt) produce interop assemblies composed in C# which can then be compiled into a **projection assembly**.

### Language projection

A **language projection** (or simply "projection") is a native adapter that enables programming APIs in a way that is idiomatic to a given language.

| Framework       | C#                  | C++                                                |
| --------------- | ------------------- | -------------------------------------------------- |
| [WinRT](#winrt) | [C#/WinRT](#cwinrt_1) | [C++/WinRT](#cwinrt)  
| Win32           | C#/Win32            | ?                                                  |

Resources:

- :material-file-document-multiple-outline: [C#/WinRT (MSDocs)](https://docs.microsoft.com/en-us/windows/uwp/csharp-winrt/)
- ▶ [Windows APIs Everywhere in .NET](https://www.youtube.com/watch?v=InQtHPumUyw)

### TFM

**Target Framework Monikers (TFM)** are used in NuGet packages and project files to refer to the flavor of .NET targeted by an application.

[Only for .NET5](https://github.com/dotnet/designs/blob/main/accepted/2020/net5/net5.md), Microsoft introduced new monikers that indicate the targeted OS after a hyphen, e.g. `net5.0-windows`, etc.
These monikers will pull in the projection assemblies that are needed to access those APIs and replace earlier use of the Microsoft.Windows.SDK.Contracts package reference.

Example TMFs include:

- `net5.0-windows10.0.19041.0` Windows 10 version 2004
- `net5.0-windows10.0.18362.0` Windows 10 version 1903
- `net5.0-windows10.0.17763.0` Windows 10 version 1809

References:

- ▶ [Windows APIs Everywhere in .NET](https://www.youtube.com/watch?v=InQtHPumUyw)

### WinMD

**Windows metadata** files (*.winmd) are machine-readable files that define [Windows Runtime](#winrt) APIs.
All public types in a .winmd file must be WinRT types.
They use the same physical file format as CLR assemblies.

Resources:

- :material-file-document-multiple-outline: [Windows Metadata (WinMD) files](https://docs.microsoft.com/en-us/uwp/winrt-cref/winmd-files)

### Win32



### WinRT

The **Windows Runtime** is a framework introduced with Windows 8 to provide access to system resources. 
WinRT is separate from, although it is used by, .NET.
Under the surface, WinRT is implemented as [COM](#com) components.

UWP XAML controls were included in WinRT until recently when they were moved to the WinUI NuGet package.

Resources:

- ▶ [Windows APIs Everywhere in .NET](https://www.youtube.com/watch?v=InQtHPumUyw)