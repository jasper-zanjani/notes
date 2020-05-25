# .NET
[Assembly]: #net 'Assembly&#10;a reusable, versionable, and self-describing building block of a common language runtime application'
[.NET Framework]: #.net '.NET Framework&#10;set of APIs associated with the C# programming language that facilitate the management of Microsoft-based products and development of Windows applications&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2013.: 504'
[.NET]: #net '.NET&#10;open-source development platform that includes languages and libraries'
[NuGet]: #net 'NuGet&#10;.NET package manager'
[.NETCoreKoans]: https://github.com/NotMyself/DotNetCoreKoans ".NET Core Koans"

The .NET ecosystem has 3 **runtimes**, all of which implement the **.NET Standard Library** and rest on common **build tools**, languages, and **runtime components**
- [**.NET Framework**][.NET Framework] released in 2002, making it the oldest runtime, and runs only on Windows. Two major components:
  - **Common Language Runtime (CLR)** runs **managed code** and performs garbage collection
  - **.NET Framework Class Library** (also called the **Base Class Library**) is composed of many classes, interfaces, and value types
- **.NET Core** is cross-platform, open-source, and optimized for performance. Its application host is `dotnet.exe`
  - **Core Common Language Runtime (CoreCLR)** is more lightweight than that of .NET Framework, but implements **Just-In Time** compilation
  - **.NET Core Class Library** is smaller than (and actually a subset of) that of .NET Framework
- **Mono for Xamarin** is used for mobile platforms like IOS, Android, and OS X

**.NET Standard** is a specification of which APIs are available across all these runtimes. It evolved from **Portable Class Libraries (PCL)** and will eventually replace them.
.NET's package manager is [NuGet][NuGet].

An [assembly][Assembly] can be compiled to EXE or DLL.

# Assemblies
- [System.Reflection.Assembly](pwsh.md#winforms)
- [System.Windows.Forms](pwsh.md#winforms)
- [System.Web.Security.Membership](pwsh.md#generate-password)

# Syntax
### dotnet watch
#### dotnet watch run
Run .NET Core Koans <sup>[github.com][.NETCoreKoans]</sup>
```sh
dotnet watch --quiet run
```

