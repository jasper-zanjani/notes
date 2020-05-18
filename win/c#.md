# C#

Template
```c#
namespace HelloWorld {
  class Program {
    public static void Main() {
      Console.WriteLine('Hello World!');
}}}
```
Formatted strings
```c#
string word1 = "dreary";
string word2 = "weary";

Console.WriteLine($"Once upon a midnight {0}," word1);
Console.WriteLine($"While I pondered weak and {word2}");
```