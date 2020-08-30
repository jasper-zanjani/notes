[Miles]: # "Miles, Robert. _C# Programming: The Yellow Book_."

# C#
TOLEARN:
- What are the files created in projects, like csproj, etc?
- What are the most common C# snippets supported by the VS Code plugin? (possibly [here](https://docs.microsoft.com/en-us/visualstudio/ide/visual-csharp-code-snippets?view=vs-2019))
  - How to add snippets in vim?
- What do some of the vocabulary used by C# mean? "accessor", "backing field"
- Where to learn more about C# concepts like **interface**?


Hello World program illustrating the basic structural template
```c#
using System;

namespace HelloWorld {
  class Program {
    public static void Main() {
      Console.WriteLine('Hello World!'); 
} } }
```
Abstracting a function and calling it <sup>[Miles][Miles]</sup>
```c#
using System;

namespace HelloWorld {
  class Program {
    static void doit () {
      Console.WriteLine ("Hello"); 
    }
    public static void Main () {
      doit();
      doit(); 
} } }
```

Formatted strings
```c#
string word1 = "dreary";
string word2 = "weary";

Console.WriteLine($"Once upon a midnight {0}," word1);
Console.WriteLine($"While I pondered weak and {word2}");
```
Object-oriented programming <sup>[ref](https://channel9.msdn.com/Series/CSharp-Fundamentals-for-Absolute-Beginners/Understanding-Classes)</sup>
```c#
namespace SimpleClasses {
  class Program {
    static void Main(string[] args) {
      Car myCar = new Car();
      myCar.Make = "Oldsmobile";
      myCar.Model = "Cutlass Supreme";
      myCar.Year = 1986;
      myCar.Color = "Silver";
      Console.WriteLine("{0} {1} {2} {3}", myCar.Make, myCar.Model, myCar.Year, myCar.Color);
    }
  class Car {
    public string Make { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    public string Color { get; set; }
  }
}
```
A more fully-featured way of setting class properties uses the `propfull` snippet
```csharp
private int myVar;
public int MyProperty {
  get { return myVar; }
  set { myVar = value; }
}
```
A class constructor is specified by setting a method with no data type that shares the class's name.
```csharp
class TestClass {
  string firstName;
  string lastName;
  int age;
  
  public TestClass() { }

  public TestClass(string fName, stringlName, int ageInt) {
    this.firstName = fName;
    this.lastName = lName;
    age = ageInt;
} }
```


## GUI Frameworks
Windows has a long history of introducing UI frameworks to facilitate the creation of GUI applications
- **MFC** (1992) was based on Native C++
- **WinForms** (2002) was based on .NET Framework
- **WPF** (2006) was also based on .NET Framework
- **UWP XAML** (2012) was based on C++ and .NET
- **WinUI 2** contains controls and styles for UWP Apps
- **WinUI 3** (2020) is meant to provide a UX framework for both Win32 and UWP applications <sup>[YouTube](https://youtu.be/1ZBMHFoMVAs)</sup>
In possibly related news, Microsoft announced **Project Reunion** to roll back this fragmentation, which originated in Windows 8, and merge Win32 and UWP platforms. <sup>[How-To Geek](https://www.howtogeek.com/673351/microsoft-will-merge-uwp-and-win32-apps-with-project-reunion/ "Microsoft will merge UWP and Win32 apps with Project Reunion")</sup>

#### UWP
Microsoft announced **Project Reunion** which will reunite the 

UWP introduced a new type of app ("UWP Apps") which used a different set of APIs than the previous frameworks which facilitated the creation of Desktop (Win32) Apps.

UWP apps **adaptively** adjust UI elements to fit all Windows 10 devices.  The **Fluent Design System** provides guidelines to provide a consistent and beautiful appearance to UWP apps. <sup>[Microsoft Docs](https://docs.microsoft.com/en-us/windows/uwp/design/basics/design-and-ui-intro "Microsoft Docs: \"Introduction to UWP app design\"")</sup>

Interesting new applications are not being developed on UWP, which does not bode well for the future of Windows as a consumer desktop computer platform.
<sup>[Microsoft Docs](https://mspoweruser.com/uwp-is-dead-because-windows-apps-are-dead/ "mspoweruser.com: \"UWP is dead because Windows apps are dead\"")</sup>
