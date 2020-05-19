[Miles]: # "Miles, Robert. _C# Programming: The Yellow Book_."

# C#
Hello World program illustrating the basic structural template
```c#
using System;

namespace HelloWorld 
{
  class Program 
  {
    public static void Main() 
    {
      Console.WriteLine('Hello World!'); 
    }
  }
}
```
Abstracting a function and calling it <sup>[Miles][Miles]</sup>
```c#
using System;

namespace HelloWorld 
{
  class Program 
  {
    static void doit () 
    {
      Console.WriteLine ("Hello"); 
    }
    public static void Main () 
    {
      doit();
      doit(); 
    }
  }
}
```

Formatted strings
```c#
string word1 = "dreary";
string word2 = "weary";

Console.WriteLine($"Once upon a midnight {0}," word1);
Console.WriteLine($"While I pondered weak and {word2}");
```