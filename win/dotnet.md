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
[dotnet new]: #syntax '```&#10;dotnet new &#10;```&#10;Create a new project'
[dotnet add]: #syntax '```&#10;dotnet add &#10;```&#10;Add a reference to a project'
[dotnet build]: #syntax '```&#10;dotnet build &#10;```&#10;Build a project'
[dotnet clean]: #syntax '```&#10;dotnet clean &#10;```&#10;Clean build outputs'
[dotnet list]: #syntax '```&#10;dotnet list &#10;```&#10;List references of the project'
[dotnet nuget]: #syntax '```&#10;dotnet nuget &#10;```&#10;Start additional NuGet commands'
[dotnet pack]: #syntax '```&#10;dotnet pack &#10;```&#10;Create a NuGet package for the project'
[dotnet publish]: #syntax '```&#10;dotnet publish &#10;```&#10;Publish a project for deployment, including the runtime'
[dotnet remove]: #syntax '```&#10;dotnet remove &#10;```&#10;Remove a reference from the project'
[dotnet restore]: #syntax '```&#10;dotnet restore &#10;```&#10;Restore dependencies specified in the project'
[dotnet run]: #syntax '```&#10;dotnet run &#10;```&#10;Compile and execute a project'
[dotnet sln]: #syntax '```&#10;dotnet sln &#10;```&#10;Modify a Visual Studio solution file'
[dotnet test]: #syntax '```&#10;dotnet test &#10;```&#10;Run unit tests using the tyest runner specified in the project'

[**`new`**][dotnet new]
[**`run`**][dotnet run]
**`watch`**

[`add`][dotnet add]
[`build`][dotnet build]
[`clean`][dotnet clean]
[`list`][dotnet list]
[`nuget`][dotnet nuget]
[`pack`][dotnet pack]
[`publish`][dotnet publish]
[`remove`][dotnet remove]
[`restore`][dotnet restore]
[`sln`][dotnet sln]
[`test`][dotnet test]
`tool`
`try`

### dotnet add
```sh
dotnet add package PowerShellStandard.Library
```
### dotnet new
[dotnet new console]: #dotnet-new '```&#10;dotnet new console &#10;```&#10;Create a .NET Core console app'
[dotnet new web]: #dotnet-new '```&#10;dotnet new web &#10;```&#10;Create an ASP.NET Core empty project'
[dotnet new angular]: #dotnet-new '```&#10;dotnet new angular &#10;```&#10;Create an ASP.NET Core with Angular'
[dotnet new react]: #dotnet-new '```&#10;dotnet new react &#10;```&#10;Create an ASP.NET Core with React'

[`console`][dotnet new console]
[`web`][dotnet new web]
[`angular`][dotnet new angular]
[`react`][dotnet new react]

Start a new "hello world" console application in the current directory
```sh
dotnet new console
```
Start a new "hello world" web application in the current directory
```sh
dotnet new web
```
Global.json specifies the .NET Core SDK version
```sh
dotnet new globaljson
```
### dotnet run
### dotnet tool
Install dotnet [ `try` ](#dotnet-try) <sup>[ref](https://github.com/dotnet/try/blob/master/DotNetTryLocal.md)</sup>
```sh
dotnet tool update -g Microsoft.dotnet-try
```
### dotnet try
Run a local server that supports .NET Interactive-style markdown:
<pre>
```cs --source-file ./Program.cs --project ./project.csproj
```
</pre>
### dotnet watch
Run .NET Core Koans <sup>[github.com][.NETCoreKoans]</sup>
```sh
dotnet watch --quiet run
```
# Tasks
### Hello world
Start a new "hello world" console application <sup>[ref](https://channel9.msdn.com/Blogs/dotnet/Create-NET-App-on-Linux)</sup>
```sh
mkdir helloworld
cd helloworld
dotnet new console
dotnet run
```
