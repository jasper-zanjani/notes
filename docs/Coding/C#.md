# C&#35;
## To-do

- Sort out [Events](#events) section, in particular the example cited
- <strike>Develop C# implementation of CSV parser. This appears to be harder than it should be, apparently because the object returned by the `CsvReader.GetRecords<T>()` method is an `IEnumerable` which is one of the confusing points of the UWP course. YouTube tutorials do not seem helpful..</strike>

## Variables

### Parsing

Data types can be used as static classes, exposing a `TryParse` method.

=== "Int32"

    ```csharp
    parsedInt = Int32.TryParse(rawInt);
    ```

=== "DateTime"

    ```csharp
    parsedDate = DateTime.TryParse(rawDate);
    ```

### String

Specify a **verbatim** literal string by prepending **`@`**, which disables escape characters and forces interpretation of backslashes literally:
```csharp
string filePath = @"C:\televisions\sony\bravia.txt";
```


Specify a formatted string by prepending a **`$`**
```csharp
int n;
string s = $"{n} is a number";
```
[**Standard numeric format strings**](https://docs.microsoft.com/en-us/dotnet/standard/base-types/standard-numeric-format-strings) are used to format common numeric types. They take the form of a character (i.e. **`C`** for currency, **`N`** for number) followed by a number. They can be passed as arguments to the `ToString` method of the literal or in the placeholder of a formatted string after `:`.
```csharp
Console.WriteLine($"{123.456789:C }");          // $123.46
Console.WriteLine(123.456789d.ToString("C"));   // $123.46
```
A **precision specifier** can define the number of fractional digits after the decimal separator.
```csharp
Console.WriteLine($"{123.456789:C3 }"); // $123.457
```
Empty space can be added to either side of the value to create evenly spaced output by placing a number after a comma (positive for right-alignment, negative for left-alignment):
```csharp
Console.WriteLine($"{123.456789, 15}");
```

### Casting

Because real numbers are stored as `double`s by default, in order to assign to a float variable you must append **`f`** to the literal:
```csharp
float num = 3.14f;
```
A similar logic pertains for integers to be declared as `doubles`:
```csharp
double num = 3d;
```
`decimal` data type literals, which have 28-29 significant digits, can be declared with the **`m`** suffix
```csharp
decimal num = 123.4567890123456789m
```
`char` literals can be encoded in Unicode:
```csharp
char umlaut = '\u00F6';
```
Variables can be explicitly cast to some other data types by placing the new data type in parentheses before the value:
```csharp
int pi = (int)System.Math.PI;
```
This casting won't work with `string`, which can be cast by using the `Convert` type or parsed using the data type's `Parse` method. The differense is that using `Convert` will return a 0 if the value is null while `Parse` will throw an exception.
```csharp
w = "5";
int wConverted = System.Convert.ToInt32(w);
int wParsed = int.Parse(w);
```

### Collection
#### Arrays

Arrays are declared differently from built-in arrays in C++.

=== "C#"
    ```csharp
    int[] primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
    ```
=== "C++"
    ```cpp
    int primes[10] {1, 2, 3, 5, 7, 11, 13, 17, 19, 23}
    ```

An empty array must still have its size declared
```csharp
int[] primes = new int[10];
```
An unnamed array:
```csharp
new[] {1, 2, 3};
```
Arrays can be traversed with a `foreach` loop, but the elements can not be changed.:
```csharp
foreach (var i in container)
{
    // ...
}
```

Arrays can be copied with the `Clone()` and `Copy()` methods: see [ArrayCloning](#arraycloning).

Arrays can be reversed in place with the `Reverse` method.
```csharp
int[] primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
Array.Reverse(primes);
```

#### LINQ

**Language Integrated Query (LINQ)** refers to a C# library that facilitates querying of collections. 
These are exposed as [**extension methods**](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/extension-methods): methods that are available on already existing [**queryable types**](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries)
This means extension methods are exposedon existing collection types like Array and List because they are derived from `IEnumerable<T>`, and thus need no modification to serve as a LINQ data source.

Linq methods are available in two semantically identical syntaxes: **query syntax** and **method syntax** (also lambda syntax). 
Query syntax is meant to be more intuitive for developers familiar with SQL. Method syntax allows method chaining.

=== "Query syntax"

    ```csharp
    int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    var evens = from n in nums where n % 2 == 0 orderby n descending select n;
    ```

=== "Method syntax"

    ```csharp
    int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    var evens = nums.Where(n => n % 2 == 0).OrderByDescending(n => n);
    ```

=== "Python"

    ```python
    numbers = [1,2,3,4,5,6,7,8,9,10]
    evens = [n for n in numbers if n % 2 == 0]
    list(reversed(evens))
    ```

Notably, unlike loop structures in C#, LINQ methods can work on unordered collections like Dictionaries.

#### ObservableCollection

The [**`ObservableCollection`**](https://docs.microsoft.com/en-us/dotnet/api/system.collections.objectmodel.observablecollection-1?view=net-5.0) class is used to define collections that provide notifications to data bindings when items are added or removed.
As such, it is used in GUI programming...

### DateTime

**`DateTimeOffset`** is preferred over **`DateTime`** because it includes an offset value that indicates the timezone.




#### Parsing

**`DateTime`** is a class that exposes several static methods of parsing raw values.
All of them have overloads that accept CultureInfo objects (implementing `IFormatProvider`) which can affect parsing of ambiguous dates.

- **`Parse()`** will attempt to parse a string and raise a **FormatException** if unable to do so.
- **`ParseExact()`** requires an exact string template and requires a `CultureInfo` object as well.

=== "Parse()"

    ```csharp
    string rawDate = "07/04/1776";
    try 
    {
        DateTime parsedDate = DateTime.Parse(rawDate);
    }
    catch (FormatException)
    {
        Console.WriteLine("Unparsable!")
    }
    Console.WriteLine(parsedDate.ToLongDateString()); // => "July 4, 1776"
    ```

=== "Specifying culture"

    ```csharp
    string rawDate = "07/04/1776";
    try 
    {
        DateTime parsedDate = DateTime.Parse(rawDate, CultureInfo.GetCultureInfo("en-GB"));
    }
    catch (FormatException)
    {
        Console.WriteLine("Unparsable!")
    }
    Console.WriteLine(parsedDate.ToLongDateString()); // => "April 7, 1776"
    ```

=== "ParseExact()"

    ```csharp
    string rawDate = "07/04/1776";
    try 
    {
        DateTime parsedDate = DateTime.ParseExact(rawDate, "M/d/yyyy", CultureInfo.InvariantCulture);
    }
    catch (FormatException)
    {
        Console.WriteLine("Unparsable!")
    }
    Console.WriteLine(parsedDate.ToLongDateString()); // => "July 4, 1776"
    ```


**`TryParse()`** returns no value, but takes an [**`out`**](#out) parameter. It does not throw an exception if the date is unparsable, but rather outputs the default date January 1, 1 AD.
The overload that accepts a Culture object also requires a DateTimeStyles object.

=== "TryParse()"

    ```csharp
    string rawDate = "07/04/1776";
    DateTime parsedDate;
    DateTime.TryParse(
        rawDate, 


        out parsedDate
    );
    Console.WriteLine(parsedDate.ToLongDateString()); // => "July 4, 1776"
    ```

=== "Specifying culture"

    ```csharp
    string rawDate = "07/04/1776";
    DateTime parsedDate;
    DateTime.TryParse(
        rawDate, 
        CultureInfo.GetCultureInfo("en-GB"), 
        DateTimeStyles.None, 
        out parsedDate
    );
    Console.WriteLine(parsedDate.ToLongDateString()); // => "April 7, 1776
    ```

`ParseExact()`
`TryParseExact()`

### Timezones

**`TimeZoneInfo`** includes static methods that can access system timezones.
`DateTime` does not include timezone information, so it must be specified at runtime.

```csharp
TimeZoneInfo sidneyTimeZone = TimeZoneInfo.FindSystemTimeZoneById("E. Australia Standard Time");
var sydneyTime = TimeZoneInfo.ConvertTime(DateTime.Now, sydneyTimeZone);
```

Enumerating all system timezones.

```csharp
foreach (var timeZone in TimeZoneInfo.GetSystemTimeZones())
{
    Console.WriteLine(timeZone.GetUtcOffset());
}
```

## Methods

### Lambda

A [**lambda expression**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-expressions) can have two forms, both of which use the [ **lambda declaration operator** ](Operators) `=>`

=== "Expression lambda"

    ```csharp
    (input-parameters) => expression
    ```

=== "Statement lambda"

    ```csharp
    (input-parameters) => { statements }
    ```

Anonymous [event handlers](Events) can be reformulated as lambdas to reduce code complexity.

```csharp
SubmitButton.Click += delegate(object sender, EventArgs e)
{
  MessageBox.Show("Button Clicked");
}

// Using a (statement) lambda:
SubmitButton.Click += (s,e) => MessageBox.Show("Button Clicked");
```

### `ref`

**`ref`** allows variables that are normally passed by value to be passed by reference.

=== "Pass by value"

    Integers are normally passed by value, so `number` will not change

    ```csharp
    static void Main() 
    {
        int number = 0;
        plusOne(number);
    }
    static void plusOne(int n) 
    {
        n++;
    }
    ```

=== "Pass by reference"

    Now `number` will increment by one because it is being passed by reference.

    ```csharp
    static void Main() 
    {
        int number = 0;
        plusOne(ref number);
    }
    static void plusOne(ref int n) 
    {
        n++;
    }
    ```

=== "Returning a value"

    Alternatively, `number` can be reassigned a variable if the method is refactored to return the new value. 

    ```csharp
    static void Main() 
    {
        int number = 0;
        number = plusOne(number);
    }
    static int plusOne(ref int n) 
    {
        n++;
        return n;
    }
    ```


### `out`

**`out`** allows a method to assign a value to a variable that has no value yet. It can be used to return multiple values.

```csharp
static void Main()
{
    double n = 5;
    double nSquared;
    square(n, out nSquared);
    Console.WriteLine($"{n} ^ 2 = {nSquared}");
}
static void square(double x, out double y)
{
    y = System.Math.Pow(x, 2);
}
```

**`out`** is prominently used in the [`TryParse`](#readingcharacter) method.

### `params`

**`params`** allows you to process a variable number of similarly-typed arguments in the method signature. This collection of arguments is abstracted as an array.
```csharp
static void method(int[] args)
{
    foreach (int el in args) 
    {
        Console.WriteLine(el);
    }
}
```
If the arguments to be accepted are themselves arrays, then you must define an array of arrays ([ex.](#listexamples)). This technique may not have worked in previous versions of C#.
```csharp
static void method(int[][] args)
{
    foreach (var array in args){
        foreach (int el in array) {
            Console.WriteLine(el);
        }
    }
}
```

### Delegates

**Delegates** are a functional programming feature in C# that facilitate loose coupling. They allow a function to be abstracted so that updated logic can be implemented without incurring technical debt.

Delegates take the form of a method signature using the `delegate` keyword. 
One or more methods implementing the delegate can be formulated which do not reference the delegate in any way, shape, or form, except for the fact that their method signature matches that specified by the delegate.

Where the method is to be used, instead of calling the method directly, the delegate is instantiated like an object, but the name of the specific method that implements the delegate is passed as a parameter. 
The instantiated delegate can then be called, which passes the parameters to the method. 
This results in looser coupling because when changing implementation, only the parameter specifying the improved method needs to be adjusted, and the delegate ensures that the same pattern of parameters is enforced at compile-time.

Delegates can be used for messaging in .NET and especially to tie [ **events** ](#events) to event handlers, but they are no longer used as much as **`Func<T,TResult>`** and **`Action<T>`**.

=== "Initial implementation"

    ```csharp
    public delegate void InformationNeeded(int n, string s);

    static void Main()
    {
        InformationNeeded form = new InformationNeeded(SimpleReport)
        
        // ...
        
        form(2, "kiwi");
        form(3, "jackfruit");
    }

    void SimpleReport(int m, string t)
    {
        Console.WriteLine($"int: {m}, string: {t}");
    }
    ```

=== "Improved implementation"

    ```csharp
    public delegate void InformationNeeded(int n, string s);

    static void Main()
    {
        InformationNeeded form = new InformationNeeded(BetterReport)

        // ...
        
        form(2, "kiwi");
        form(3, "jackfruit");
    }

    void BetterReport(int m, string t)
    {
        Console.WriteLine($"There are {m} items of type {t}");
    }
    ```

### Events

[Events](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/events-and-routed-events-overview) signal the occurrence of an action or notification. 
They are **raised** or **fired** (invoked) by the **publisher** and received by the **event handler** or **subscriber**. 
They represent a syntactic sugar over the [ **delegate** ](Delegate) structure, 
which is used in the background as the pipeline to connect publisher and handler.

The simplest way to **define** an event, using the builtin EventHandler type, is as follows:
```csharp
public event EventHandler Occurrence;
```

In actuality, EventHandler is itself a wrapper around a delegate, and any delegate can be wrapped
by the event by the delegate's name as the event's data type:
```csharp
public delegate void InformationNeeded(int n, string s);

class Form
{
  public event InformationNeeded FormEvent;
}
```

But because the event structure requires an object reference, the simplest implementation for **raising**
an event is more involved. This is because the **Main** entry-point for C# programs is static, 
and not an object instance.

The event must be defined within a class that is then instantiated.
The event is implemented in an event handler that is a method within the same class that defines the
event. After first checking if the event is null (abbreviated syntax
using the [null-conditional member access operator](Operators) is equivalent) the event object is called.

Here, the event handler is called by the constructor itself.
```csharp
namespace SimpleEvent
{

  class Program
  {
    static void Main(string[] args)
    {
      TriggeringEvent eventTrigger = new TriggeringEvent();
    }

    public class TriggeringEvent
    {
      public event EventHandler Event;

      public TriggeringEvent()
      {
        OnEvent(this, EventArgs.Empty);
      }

      protected virtual void OnEvent(object s, EventArgs e)
      {
        var newEvent = Event as EventHandler;

        if (newEvent != null)
        {
          newEvent(this, EventArgs.Empty);
        }
        // Null-conditional operator available since C# 6:
        // newEvent?.Invoke(this, EventArgs.Empty);
      }
    }
  }
}
```

If the method signature of the event handler is made **public**, then the event can be raised externally
and called like any other method, and a slightly simpler example can be constructed.
```csharp
namespace SimpleEvent
{
  class Program
  {
    static void Main(string[] args)
    {
      TriggeringEvent eventTrigger = new TriggeringEvent();
      eventTrigger.OnEvent(eventTrigger, EventArgs.Empty);
    }

    public class TriggeringEvent
    {
      public event EventHandler Event;

      public virtual void OnEvent(object s, EventArgs e)
      {
        Console.WriteLine("OnEvent");
        var newEvent = Event as EventHandler;
        newEvent?.Invoke(this, EventArgs.Empty);
      }
    }
  }
}
```
Conventionally, however, the event handler is not made public, but defined using the 
`protected virtual void` method signature.

**Event wiring** refers to the process of adding subscribers to an event.
In implementation, this involves adding the subscribers to the invocation list of the 
delegate that is used to tie the event to event handler.
```csharp
Event += EventSubscriber;
```

In actuality, this syntax uses **delegate inference**, where the compiler automatically determines
the correct delegate to use. The fuller syntax avoiding the use of this feature would be
```csharp
Event += new EventHandler(EventSubscriber);
```

The event is then fired by calling it, but this can only occur from **within** the type in which
it is defined. So it has to be fired from within another of that type's methods.

Anonymous methods and lambdas can also be used after the `+=` operator:
```csharp
Event += (s,e) => Console.WriteLine("Subscribing to event!");
```

In [ this example ](https://github.com/jasper-zanjani/CSharp/commit/ff3fde8e44b9aa80f5a6efd459bcf5d68d2d02df)
, adapted from a Pluralsight course, the `OnMissionAccomplished` and `OnMissionStatusReport` 
event handlers send two different types of events, respectively: `MissionStatusReport` 
and `MissionAccomplished`. Even though both of these events are `EventHandler` types,
they are actually events.


### Async

The **`async`** modifier is used to construct asynchronous code.
By convention, asynchronous methods are named with "Async" to distinguish them.
The **`await`** keyword marks the variable containing the result.

```csharp
public int Addition()
{
  var a = SlowMethodOne();
  var b = SlowMethodTwo();
  return a + b;
}
```
```csharp
public async Task<int> AdditionAsync()
{
  var a = SlowMethodOneAsync();
  var b = SlowMethodTwoAsync();
  return await a + await b;
}
```

Return types used for async include:
- `Task`
- `Task<T>`
- `Void` should generally be avoided with the exception of event handlers

Async does not create new threads by default, so it is only suitable for UI and IO-bound methods, not CPU-bound methods.

Here async is used to return an enumerable collection of `Customer` objects from the [file IO system](API#windowsstorage).

```csharp
public class CustomerDataProvider
{
  private static readonly string _customersFileName = "customers.json";
  private static readonly StorageFolder _localFolder = ApplicationData.Current.LocalFolder;
  public async Task<IEnumerable<Customer>> LoadCustomersAsync()
  {
    var storageFile = await _localFolder.TryGetItemAsync(_customersFileName) as StorageFile;
    List<Customer> customerList = null;
    // ...
  }
}
```

Here threads are used to handle JSON files and data on application load in the data provider for a GUI application
=== "LoadCustomersAsync"
    ```csharp
    public async Task<IEnumerable<Customer>> LoadCustomersAsync()
    {

    }
    ```
=== "SaveCustomersAsync"
    ```csharp
    public async Task SaveCustomersAsync(IEnumerable<Customer> customers) 
    { 

    }
    ```

## Exceptions

Exceptions expose **`Message`** and **`StackTrace`** attributes that can be inspected for further information (ref. [ExceptionHandling](#exceptionhandling))

[Member access operators](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/member-access-operators) are syntactic sugars that allow operations to be performed without exception handling.

| Operator                                                                                                                                          | Name                                         | Description                                                                                                              |
| :------------------------------------------------------------------------------------------------------------------------------------------------ | :------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------- |
| [**`=>`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-expressions)                                        | [ Lambda declaration operator ](Lambda)      |
| [**`?.`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/member-access-operators#null-conditional-operators--and-)  | Null-conditional **member access** operator  | Applies the operation to its operand only if it evaluates to non-null, otherwise it returns `null`                       |
| [**`?[]`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/member-access-operators#null-conditional-operators--and-) | Null-conditional **element access** operator | Applies the operation to its operand only if it evaluates to non-null, otherwise it returns `null`                       |
| [**`??`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/null-coalescing-operator)                                  | Null-coalescing operator                     | Returns value of left-hand operand if non-null, otherwise returns result of right-hand operand.                          |
| [**`??=`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/null-coalescing-operator)                                 | Null-coalescing assignment operator          | Assigns the value of the right-hand operand to the left-hand operand, only if the left-hand operand evaluates to `null`. |

## Classes

### Access modifiers

Classes can be declared with various [**access modifiers**](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers) that affect the compiler's behavior.
These are intended to prevent what would be runtime errors by turning them into compile-time errors,
improving code quality.
- **static** prevents instantiation
- **abstract** indicates the class is to be completed in a derived class. 
Every method marked as abstract has to be implemented in the derived class, and the class has to be marked with `abstract` as well.
- **sealed** prevents inheritance
- **partial** allows the same class to be defined across multiple files

### Constructor

If not defined, the compiler will provide a default constructor.

A constructor can be overloaded by using the `this` keyword in the constructor's signature after a colon, as if invoking the second constructor:
```csharp
using System;

class Car
{
    public string brand { get; set; }
    public Car() : this("Ford") { }
    public Car(string brand)
    {
        this.brand = brand;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Car ford = new Car();
        Console.WriteLine(ford.brand); // => Ford
    }
}
```

### Properties

A [**property**](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/using-properties) protects the data of a private variable ("field") by implementing getter and setter **accessor** functions. 
These allow data validation or other logic to be performed when the variable is changed. The private variable being protected is called the **backing store**.

By convention, properties have identifiers in title case.
The identifier for the backing field of a property is conventionally the same as the property, except lowercase or prepended with an underscore.

In the **`set`** accessor, the keyword **`value`** is used for the argument passed in.
```csharp
private string name; // field
public string Name   // property
{
    get { return name; }
    set { this.name = value; }
}
```
A common shorthand was introduced in C# 3 called **automatically implemented properties**, where the p
```csharp
public string Name { get; set; }
```
The set accessor uses an implicit parameter **`value`**, whose value is the type of the property.
```csharp
class Person
{
  private string _name; // the name field
  public string Name    // the Name property
  {
    get => _name;
    set => _name = value;
  }
}
```
Data validation for setter accessor:
```csharp
public class Date
{
  private int _month = 7;  // Backing store

  public int Month
  {
    get => _month;
    set
    {
      if ((value > 0) && (value < 13))
      {
        _month = value;
      }
    }
  }
}
```
A property can be made read-only by simply removing the setter.

An access modifier can also be applied to only one or the other of the accessors to enforce encapsulation.
This can make the property read-only externally while still allowing the class's own logic to change the property's value:
```csharp
private set
{
    if ((value > 0) && (value < 13))
    {
        _month = value;
    }
}
```
Similarly, fields can be modified with the **`readonly`** access modifier. 
This will prevent the variable from being changed in external code as well as in any internal methods.
Readonly fields can only be set by the constructor or variable initializers.


### Static classes

Classes marked with **`static`** are not instantiated.
An example is the `System.Console` class, which is never instantiated even though its methods are available for use.
This structure is called a **singleton** and is useful as a container for assorted utilities.

Methods marked with `static` are independent of the class instance itself, and as such do not have access to fields that are not `const`.




### Polymorphism

Modifiers like `abstract`, `virtual`, and `override` allow derived classes to implement logic that builds upon that of a base class.

- [**`virtual`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/virtual) allows you to declare methods and properties in a base class which can be overriden in a derived class.
`virtual` **cannot** be used with `static`, `abstract`, `private`, or `override`. 
- [**`abstract`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract) is similar, except that the class itself must also be marked as an abstract class, preventing instantiation of the base class. 
Instead of defining a base function, only the signature is declared. 
- In both cases, [**`override`**](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/override) is used to mark the implementation in the derived class.

=== "Base class (`abstract`)"

    ```csharp
    abstract class Shape
    {
        public abstract double GetArea();
    }
    ```
    ```csharp
    class Shape
    {
        public virtual double GetArea()
        {
            return;
        }
    }
    ```

=== "Derived class"

    ```csharp
    class Rectangle : Shape
    {
        public double Length { get; set; }
        public double Width { get; set; }

        public Rectangle()
        {
            Length = 2;
            Width = 3;
        }

        public override double GetArea()
        {
            return Length * Width;
        }
    }
    ```

=== "Derived class"

    ```csharp
    class Circle : Shape
    {
        public double Radius { get; set; }

        public Circle()
        {
            Radius = 3;
        }

        public override double GetArea()
        {
            return System.Math.PI * System.Math.Pow(Radius, 2);
        }
    }
    ```

### Interfaces

[**Interfaces**](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interfaces/) can be used to break up dependencies and implement the **dependency inversion principle**.
This principle holds that components should be dependent on abstractions, and not on implementations. ([src](https://app.pluralsight.com/course-player?clipId=77bf1e15-99ef-432e-b6c1-62c192414edb))

Interfaces contain property and method definitions that must be implemented in derived classes, and as such are similar in concept to abstract classes.
Like abstract classes, an interface may not be instantiated.
Unlike abstract classes, the `override` keyword is not used on classes that implement interfaces, and access modifiers are not acceptable for interface members.
Also unlike abstract classes, smplementation of interface members is mandatory.
And although a derived class can only inherit from a single base class, there is no limit on the number of interfaces that a derived class can inherit from.

Interface identifiers conventionally with the capital `I`.

=== "Interface"

    ```csharp
    interface IAnimal
    {
        void AnimalSound();
    }
    ```

=== "Implementation"

    ```csharp
    class Pig : IAnimal
    {
        public void AnimalSound()
        {
            Console.WriteLine("Oink");
        }
    }
    ```

Notably, a commonly encountered interface is **IEnumerable** because both Lists and Arrays implement it.
So methods that iterate over either Lists or Arrays typically use IEnumerable to accept either data type.

### Attributes

**Attributes** appear to resemble Python **decorators** because like decorators appear on the line preceding a function or class definition, but they appear to be used for something else.
Attributes in C# are used to adjust the function of code in a variety of ways.

**`ObsoleteAttribute`** will produce a compiler warning or error (preventing compilation entirely) when deprecated code is being used.

=== "Warning"

    ```csharp
    [Obsolete("Don't use this class anymore, instead use ...")]
    class Cow { }

    static void Main()
    {
        Cow betsy = new Cow();
    }
    ```

=== "Error"

    ```csharp
    [Obsolete("Don't use this class anymore", true)]
    class Cow { }

    static void Main()
    {
        Cow betsy = new Cow();
    }
    ```

A family of attributes exist to assist debugging.

=== "DebuggerStepThrough"

    [**`DebuggerStepThrough`**](https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.debuggerstepthroughattribute) can decorate certain methods to be stepped through or skipped while debugging.
    This is useful for situations where only some properties of a class have to be debugged.
    This allows more controlled debugging than using the "Step over properties and operators" setting in Debugging Options. ([src](https://youtu.be/o4GRN_3ulNw))

    ```csharp
    using System.Diagnostics;

    struct Cow 
    {
        public string Name { [DebuggerStepThrough] get { return "Bessy"; } }
        public int Weight { get { return 5; } }
    }

    static void Main()
    {
        Cow betsy = new Cow();
    }
    ```

=== "DebuggerDisplay"

    [**`DebuggerDisplayAttribute`**](https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.debuggerdisplayattribute) allows an object's state to be formatted to be more understandable in the debugger's watch window. ([src](https://youtu.be/QUhI2BbP8VA))
    ![](/img/DebuggerDisplayAttribute.gif)

    ```csharp
    using System.Diagnostics;

    [DebuggerDisplay("{Name} weighs {Weight} lbs")]
    struct Cow
    {
        public string Name;
        public int Weight;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            // This triggers instantiation of the attribute
            typeof(Program).GetCustomAttributes(false);

            Cow betsy = new Cow { Name = "Betsy", Weight = 1000 };
            Console.WriteLine($"{betsy.Name} weighs {betsy.Weight} lbs");
        }
    }
    ```

The `CallerMemberNameAttribute` can be added to string parameters in functions that are meant to process the name of the function calling them.
This avoids the verbosity of placing `nameof()` on every invocation. ([src](https://app.pluralsight.com/course-player?clipId=5940e51b-bed0-491b-a847-edfcc7ed0981))
```csharp
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace WiredBrainCoffee.UWP.Models
{
    public class Customer : INotifyPropertyChanged
    {
        private string firstName;

        public string FirstName
        {
            get => firstName;
            set
            {
                firstName = value;
                OnPropertyChanged(nameof(FirstName));
            }
        }
        public string LastName { get; set; }
        public bool IsCoffeeDrinker { get; set; }

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged([CallerMemberName]string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
```

In XAML, the `ContentPropertyAttribute` attribute is used to define whether or not a control accepts a default `Content` property field

```csharp
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Markup;

[ContentProperty(Name = nameof(Customer))]
public sealed partial class CustomerDetailControl : UserControl
{
    public CustomerDetailControl()
    {
        this.InitializeComponent();
    }
}
```

## Files

### Streams

A [**Stream**](https://docs.microsoft.com/en-us/dotnet/api/system.io.stream?view=net-5.0) is an abstraction of a **backing store**, or sequence of bytes, which can be a file, an input/output device, a websocket, or an inter-process communication pipe. 
The `Stream` class itself is an abstract base class that can't be instantiated.
`FileStream` is the concrete class that uses files as its backing store.

Streams can support seeking, although network streams do not support seeking.
This can be checked by calling the stream's boolean `CanSeek` property.

`Stream` implements [`IDisposable`](https://docs.microsoft.com/en-us/dotnet/api/system.idisposable?view=net-5.0), which means it can be disposed indirectly by being placed in a `using` block.

A **bit bucket** is a stream with no backing store and is implemented as **`Stream.Null`**.

## Testing



Tests are usually organized in a separate [project](#project-files) that is linked to the project containing the **system under test** (SUT).

Visual Studio has a built-in test-runner, but the `dotnet` CLI utility also allows the entire test suite to be executed from the command-line.

```sh
dotnet test
```

.NET supports several test frameworks.

### xUnit 

In **xUnit**, tests are organized into public classes, and **test cases** are composed by individual methods on this class, decorated with the `Fact` attribute.
Test assertions are made with static `Assert` method calls. ([src](https://app.pluralsight.com/course-player?clipId=1ad7d7a4-80f8-4309-bc6d-6f0896dae79d))

```csharp
public class TestCases
{
    [Fact]
    public void TestCase()
    {
        Assert.Equal(2 + 2, 4);
    }
}
```

Assertions that an exception must be thrown are generic method calls typed to the specific exception.

```csharp
public class StarshipDeploymentShould
{
    [Fact]
    public void ThrowOnNullValidator()
    {
        var sut = new StarshipDeployment(null);
        Assert.Throws<ArgumentNullException>(sut);
    }
}
```


**Test fixtures** can be formed on properties of the main test class.
They must be initialized with the test class's constructor.


=== "Xunit"

    ```csharp
    public class DeskBookerRequestProcessorTests
    {
        public DeskBookerRequestProcessor processor { get; set; }

        public DeskBookerRequestProcessorTests()
        {
            processor = new DeskBookerRequestProcessor();
        }

        [Fact]
        public void ShouldReturnDeskBookerResultWithRequestValues()
        {
            var request = new DeskBookerRequest
            {
                FirstName = "Thomas",
                LastName = "Huber",
                Email = "thomas@huber.com",
                Date = new DateTime(2020, 1, 28)

            };
            var result = processor.BookDesk(request);

            Assert.NotNull(result);
            Assert.Equal(request.FirstName, result.FirstName);
            Assert.Equal(request.LastName, result.LastName);
            Assert.Equal(request.Email, result.Email);
            Assert.Equal(request.Date, result.Date);

        }

        [Fact]
        public void ShouldThrowExceptionIfRequestIsNull()
        {
            var exception = Assert.Throws<ArgumentNullException>(() => processor.BookDesk(null));
            Assert.Equal("request",exception.ParamName);
        }
    }
    ```

=== "Classes under test"

    ```csharp
    namespace DeskBooker.Core.Processor
    {

        public class DeskBookingResult
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public DateTime Date { get; set; }
        }

        public class DeskBookingRequest
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public DateTime Date { get; set; }
        }

        public class DeskBookingRequestProcessor
        {
            public DeskBookingResult BookDesk(DeskBookingRequest request)
            {
                return new DeskBookingResult
                {
                    FirstName = request.FirstName,
                    LastName = request.LastName,
                    Date = request.Date,
                };
            }
        }
    }
    ```

In this example, `PersonProcessor` is a public class whose constructor takes an `ISqlDataAccess` data provider by means of dependency injection.
The `LoadData` method is setup, and the mocked object is instantiated with the `Create` method call.
The mock will inject the mock data provider, which returns a `List<PersonModel>`.

```csharp
using (var mock = AutoMock.GetLoose())
{
    mock.Mock<ISqliteDataAccess>()
        .Setup(x => x.LoadData<PersonModel>("SELECT * FROM Person"))
        .Returns(GetSamplePeople());
    var sut = mock.Create<PersonProcessor>();
    var expected = GetSamplePeople();
    var actual = sut.LoadPeople();
    Assert.True(actual != null);
    Assert.Equal(actual.Count,expected.Count);
}
```

The **`Theory`** attribute decorates a parameterized test and commonly appears in conjunction with **`InlineData`** attributes that contain the parameter values.

```csharp
using System;
using Xunit;
using System.Linq;

namespace MathTests
{
    public class MathWorks
    {
        [Theory]
        [InlineData(2,2)]
        [InlineData(3,3,3)]
        [InlineData(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)]
        public void Addition(params int[] ops)
        {
            int loopsum = 0;
            foreach (int i in ops)
            {   
                loopsum += i;
            }
            int linqsum = ops.Sum();
            Assert.Equal(loopsum,linqsum);
        }
    }
}
```

The xUnit test-runner can be modified using a JSON file named xunit.runner.json. This file must be copied to the output directory by selecting "Copy if newer" in the file's properties.

This example will display the method names only, rather than the fully-qualified dotted name with namespace and class.
```json
{
    "methodDisplay": "method"
}
```

### Moq

**Moq** ("mock-you") is an open-source mocking library available as a NuGet package.
**Mock objects** are generics that take the abstract base class or interface used by the mocked object (see [provider pattern](#provider-pattern)).
Naturally, this means the concrete objects they are replacing must also be implementing those interfaces.

There are two mock modes, **strict** and **loose**.
By default, mock objects are loose, which means they will return default type values and not throw any exceptions to methods that have not been setup.

=== "Loose (default)"

    ```csharp
    var mock = new Mock<IMockTarget>();
    ```

=== "Strict"

    ```csharp
    var mock = new Mock<IMockTarget>(MockBehavior.Strict);
    ```

Mock properties require setup.

```csharp
mock.Setup(x => x.Property).Returns("Hello, world!");
```

Methods of mock objects also require setup using an identical syntax.
Concrete arguments can be provided, but preferable is using [**argument matching**](https://documentation.help/Moq/FBE0FFA5.htm).
In argument matching, `It.IsAny<T>` is used like a type declaration to fill the place of any concrete variable used as an argument. 
([src](https://app.pluralsight.com/course-player?clipId=b7d5385b-44c8-4632-80c6-2091b213eee4))

=== "Argument matching"

    ```csharp
    mock.Setup(x => x.IsValid(It.IsAny<string>())).Returns(true);
    ```

=== "Concrete"

    ```csharp
    mock.Setup(x => x.IsValid("Hello, world!")).Returns(true);
    ```

The mock object exposes an `Object` property that can be used to test assertions against properties of the mocked object.

```csharp
Assert.Equal(mock.Object.Property, value)
```

A mock object's **`Verify`** is used to verify that a mocked method was called by the system under test.
Verification is specific to the parameters of the mocked method call, and argument matching is available just as it is for setting up mocked methods.

Here, the mocked validator, which is passed in to the SUT by dependency injection, must make a call to the validator's `Evaluate()` method.
If the call is removed, the test will fail ("Expected invocation on the mock at least once, but was never performed...").

An overload of the `Verify` method also allows a custom error message to be specified.
Another overload can ensure that the mocked method was **not** called, by passing `Times.None` after the lambda.
The Times struct exposes other members like `AtLeastOnce` and `Between` that can specify any imaginable number or range of invocations.

=== "Test"

    ```csharp
    public class StarshipDeploymentShould
    {
        [Theory]
        [InlineData("Betelgeuse")]
        public void EvaluateStarship(string destination)
        {
            var mockValidator = new Mock<IStarshipValidator>();
            mockValidator.Setup(x => x.Evaluate()).Returns(true);

            var mockStarship = new Mock<IStarship>();

            var sut = new StarshipDeployment(mockValidator.Object as IStarshipValidator);
            sut.Deploy(mockStarship.Object as Starship, destination);
            mockValidator.Verify(x => x.Evaluate());
        }
    }
    ```

=== "Custom error message"

    ```csharp
    public class StarshipDeploymentShould
    {
        [Theory]
        [InlineData("Betelgeuse")]
        public void EvaluateStarship(string destination)
        {
            var mockValidator = new Mock<IStarshipValidator>();
            mockValidator.Setup(x => x.Evaluate()).Returns(true);

            var mockStarship = new Mock<IStarship>();

            var sut = new StarshipDeployment(mockValidator.Object as IStarshipValidator);
            sut.Deploy(mockStarship.Object as Starship, destination);
            mockValidator.Verify(x => x.Evaluate(), "Starships should be validated");
        }
    }
    ```

=== "SUT"

    ```csharp
    public class StarshipDeployment
    {
        public IStarshipValidator StarshipValidator { get; set; }

        public StarshipDeployment(IStarshipValidator validator)
        {
            StarshipValidator = validator ?? throw new ArgumentNullException(nameof(validator));
        }

        public bool ValidateDestination(string destination)
        {
            return destination.Length > 1 ? true : false;
        }

        public StarshipMission Deploy(Starship starship, string destination)
        {
            bool destinationValidated = ValidateDestination(destination);
            bool starshipValidated = StarshipValidator.Evaluate();

            return destinationValidated && starshipValidated
                ? new StarshipMission { Starship = starship as Starship, Destination = destination }
                : throw new ArgumentException();
        }
    }
    ```

A mocked method can also be setup to throw an exception with the **`Throw<Exception>()`** method, a generic method that takes an Exception type.



### Application design

Test-driven development and the requirement to be able to mock data providers has a strong influence on application architecture.
Instead of tightly coupling models with a particular data provider (such as an hardcoding, an in-memory database, or parsing a file), the recommended pattern is **dependency injection**.
A data provider that implements an interface is passed as an argument to the controller or viewmodel upon entry.

For example, a `DataProvider` class is used to provide a list of integers on application load implements 

```csharp
public interface IDataProvider
{
    IEnumerable<int> LoadAsync();
}

public class DataProvider : IDataProvider
{
    async public List<int> LoadAsync()
    {
        return await List<int> {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    }
}
```

A mocked data provider also implementing that interface can then be used in testing.




## .NET


[.NET Framework]: #net '.NET Framework&#10;set of APIs associated with the C# programming language that facilitate the management of Microsoft-based products and development of Windows applications&#10;Desmond, Brian et al. _Active Directory_. O\'Reilly Media, 2013.: 504'
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

### dotnet

Install [dotnet-format](https://github.com/dotnet/format)
```sh
dotnet tool install -g dotnet-format
```
Install the [ASP.NET scaffolding engine](https://github.com/dotnet/Scaffolding)
```sh
dotnet tool install -g dotnet-aspnet-codegenerator
```
Create a new [xUnit](#xunit) project named tests
```sh
dotnet new xunit -n tests
```
Add a [project file](#project-files) to a solution
```sh
dotnet sln add ./Project/Project.csproj
```
Add a [project reference](https://docs.microsoft.com/en-us/dotnet/core/tools/dotnet-add-reference) to a project
```sh
dotnet add reference ./path/to/Project.csproj
```
Install a NuGet package and add a `PackageReference` in the project file

=== "Moq"

    ```sh
    dotnet add package Moq
    ```

=== "System.CommandLine"

    ```sh
    dotnet add package System.CommandLine
    ```


Run the **dotnet try** web server that supports .NET Interactive-style markdown:

```md
    ```cs --source-file ./Program.cs --project ./project.csproj
    ```
```

### Project files

Project files are XML files that describe various metadata to the dotnet compiler.
The root node is **`Project`** which has two subnodes that collect various information about the project:

**PropertyGroup** can contain various elements that affect project settings:

- `RootNamespace` specifies the namespace that contains the `Main()` method for console applications
- `TargetFramework` specifies the targeted CLR framework: `net5.0`, `netcoreapp3.1`, etc
- `LangVersion` C# version: `9.0`, etc [:material-dot-net:](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/configure-language-version)
- `Nullable` Enable nullable reference types [:material-dot-net:](https://docs.microsoft.com/en-us/dotnet/csharp/nullable-references#nullable-contexts)

**ItemGroup** contains references to NuGet packages (`PackageReference`) and other projects (`ProjectReference`).

=== "LangVersion"

    ```xml
    <PropertyGroup>
        <LangVersion>preview</LangVersion>
    </PropertyGroup>
    ```

=== "Nullable"

    ```xml
    <PropertyGroup>
        <Nullable>enable</Nullable>
    </PropertyGroup>
    ```

=== "ItemGroup"

    ```xml
    <ItemGroup>
        <ProjectReference Include="/path/to/OtherProject.csproj"/>
        <PackageReference Include="xunit" Version="2.4.0"/>
    </ItemGroup>
    ```

Adding a reference to another project is also easily accomplished from the command-line.

```sh
dotnet add project /path/to/OtherProject.csproj
```


### Packages

**NuGet** is the official package manager for .NET.

NuGet packages required for any project were [stored](https://youtu.be/DA0ggvtfUJg?t=240) in a XML [ **packages.config** ](https://docs.microsoft.com/en-us/nuget/reference/packages-config) file. 

But projects that use [**PackageReference**](https://docs.microsoft.com/en-us/nuget/consume-packages/package-references-in-project-files) may store that information in /obj/project.assets.json.


#### System.CommandLine [:material-dot-net:](https://www.nuget.org/packages/System.CommandLine) [:octicons-mark-github-16:](https://github.com/dotnet/command-line-api)

Prior to System.CommandLine, it had been up to the developer to build a custom solution resolving command-line arguments as an array of strings.
Although .NET includes several earlier attempts at solving this problem, none had emerged as a default solution.

Similar to Python's [argparse :material-file-document-edit-outline:](/Coding/Python#argparse), the CommandLine library allows you to construct a **`RootCommand`** object that accepts definitions of argument and options.

Here, an argument is required:

=== "C#"

    ```csharp
    using System;
    using System.CommandLine;
    using System.CommandLine.Invocation;

    namespace CommandLine
    {
        class Program
        {
            static int Main(string[] args)
            {
                var cmd = new RootCommand
                {
                    new Argument<string>("name")
                };

                cmd.Handler = CommandHandler.Create<string>(HandleGreeting);

                return cmd.Invoke(args);
            }

            static void HandleGreeting(string name = "world")
            {
                Console.WriteLine($"Hello, {name}");
            }
        }
    }
    ```

=== "Python"

    ```python
    import argparse


    def get_args():
        parser = argparse.ArgumentParser(description="Say hello")
        parser.add_argument(
            dest="name",metavar="name", default="World", help="Name to greet"
        )
        return parser.parse_args()


    def main():
        args = get_args()
        print(f"Hello, {args.name}!")


    if __name__ == "__main__":
        main()
    ```


Here, the greeting can be specified with an optional parameter

=== "C#"

    ```csharp
    using System;
    using System.CommandLine;
    using System.CommandLine.Invocation;

    namespace CommandLine
    {
        class Program
        {
            static int Main(string[] args)
            {
                var cmd = new RootCommand
                {
                    new Argument<string>("name"),//, "Your name"),
                    new Option<string?>(new[] {"--greeting", "-g" },"The greeting to use"),
                };

                cmd.Handler = CommandHandler.Create<string, string?>(HandleGreeting);

                return cmd.Invoke(args);
            }

            static void HandleGreeting(string? greeting, string name)
            {
                Console.WriteLine($"{greeting}, {name}");
            }
        }
    }
    ```
=== "Python"

    ```py
    import argparse


    def get_args():
        parser = argparse.ArgumentParser(description="Say hello")
        parser.add_argument(
            dest="name",metavar="name", default="World", help="Name to greet"
        )
        parser.add_argument(
            "--greeting","-g", dest="greeting", default="Hello", help="Greeting to use"
        )
        return parser.parse_args()


    def main():
        args = get_args()
        print(f"{args.greeting}, {args.name}!")


    if __name__ == "__main__":
        main()

    ```



## Documentation

C# supports **documentation comments** that can be exported to an XML file, which can then be imported into a static site generator (especially DocFX).

Visual Studio can be [set](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/doc-compiler-option#to-set-this-compiler-option-in-the-visual-studio-2019-development-environment) to export these comments upon build.

## SDKs

### DynamoDB

To develop a .NET application using DynamoDB, add the [**AWSSDK.DynamoDBv2**](https://www.nuget.org/packages/awssdk.dynamodbv2) NuGet package.
The AWS Explorer, part of the [AWS Toolkit for Visual Studio](https://aws.amazon.com/visualstudio/) extension, is also useful for setting up a new table.
A user with programmatic access, including an Access Key and Secret Key, is necessary to use the toolkit. ([src](https://www.youtube.com/watch?v=hNAWdXaW0Fs))

Both .NET Core and .NET Framework are supported as target frameworks, but .NET Core uses exclusively asynchronous operations.

A **service client** object is formed by instantiating **`AmazonDynamoDBClient`**.

The exposed method `PutItemAsync` is used to save an item to a table as a `PutItemRequest` object.
The item itself is provided as a Dictionary in the `Item` key, but the Dictionary's values are `AttributeValue` objects, formed with a magic key that determines the data type of the value.

=== "String"

    ```csharp
    new AttributeValue{ S = "Hello, world!" }
    ```

=== "Integer"

    ```csharp
    new AttributeValue{ N = "3" }
    ```

=== "Boolean"

    ```csharp
    new AttributeValue{ BOOL = true }
    ```

=== "List"

    ```csharp
    new AttributeValue{ L = new List<AttributeValue>
    {
        new AttributeValue{ S = "Socrates" },
        new AttributeValue{ S = "Plato" },
        new AttributeValue{ S = "Aristotle" },
    }}
    ```

```csharp
using Amazon.DynamoDBv2;

namespace DynamoDBDemo
{
    public class LowLevelSample
    {
        public static async Task ExecuteAsync()
        {
            using (IAmazonDynamoDB ddbClient = new AmazonDynamoDBClient()
            {
                await ddbClient.PutItemAsync(new PutItemRequest
                {
                    TableName = "Users",
                    Item = new Dictionary<string, AttributeValue>
                    {
                        { "Id", new AttributeValue { S = "john@doe.com" } },
                        { "String", new AttributeValue { /* ... */ } }
                    }
                })
            })
        }
    }
}
```

## Concurrency

### Asynchronous programming

Consuming APIs:

- HttpClient [:material-file-document-multiple-outline:](https://docs.microsoft.com/en-us/dotnet/api/system.net.http.httpclient?view=net-5.0)

### Multithreading

The **Task Parallel Library** offers a high-level way to set up multiple threads.

A **Task** represents an asynchronous operation.

**Task.Run()** queues the work passed as the action to run on a different thread in the thread pool.
**`Task.Run<T>()`** represents an asynchronous operation that returns a specific value type.

```csharp
Task.Run( () => 
{
    // ...
});
```

Objects in other threads will be inaccessible without using an object like **Dispatcher** in WPF

```csharp
Task.Run( () =>
{
    Dispatcher.Invoke(() => 
    {
        // ...
    });
});
```

To avoid blocking, we can make it asynchronous

```csharp
private async void Search_Click(object sender, RoutedEventArgs e)
{
    await Task.Run() =>
    {
        // ...

        Dispatcher.Invoke(() =>
        {
            // ...
        }
    }
}
```

## 📘 Glossary

[Assembly]: #net 'Assembly&#10;a reusable, versionable, and self-describing building block of a .NET application'
[Module]: #module 'Module&#10;A portable executable file (DLL or EXE) consisting of one or more classes and interfaces.'
[Provider pattern]: #provider-pattern 'Provider pattern&#10;A favored development model in .NET, and a form of dependency injection where a class is passed as an argument to another class that uses it for some purpose.'

[Assembly][Assembly]{: #assembly}
: A collection of types and resources that are built to work together and form a logical unit of functionality and which form the building blocks of .NET applications.

[Module][Module]{: #module}
: A portable executable file (DLL or EXE) consisting of one or more classes and interfaces.
  Although multiple modules can theoretically compose a single assembly, in practice an assembly and module can be considered one and the same for most .NET applications.

[Provider pattern][Provider pattern]{: #provider-pattern} [:material-wikipedia:](https://en.wikipedia.org/wiki/Provider_model)
: A favored development model in .NET, and a form of dependency injection where a class is passed as an argument to another class that uses it for some purpose.
  The key is that the provider must derive from an abstract base class or an interface to support mocks in unit testing.
