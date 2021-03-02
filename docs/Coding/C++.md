

## Preprocessing

**Preprocessing** is the phase of executing **preprocessing directives** in a source file, which are then removed from the resulting **translation unit**, which combines the pure C or C++ code of a source file with all its included header files. The translation unit is then compiled into an **object file**, and it is the **linker** that then forms **linkages** between object files to produce an executable module.

- [`#define`](#define)
- [`#include`](#include)

The **`#define`** directive specifies a **macro** which can define a text replacement to occur in code before it is compiled. Macros are considered a holdover from C, and other constructs like **variable templates** and **function templates** are considered better suited in C++. In practice, `#define` statements are most commonly used to handle header files.

Here, any instance of "`PI`" in the source code will be replaced by the string of digits "3.14159265", but it will not be replaced if it forms part of an identifier or appears in a string literal or comment.
```c
#define PI 3.14159265
```
If a substitution string isn't specified then any instance of the identifier will simply be removed.
```c
#define break
```
Macros may not span multiple lines without escaped line breaks, but during preprocessing these are removed and the substitution is made inline.
```c
#define PI 3.14\
159265
```

**Function-like macros** are possible because the preprocessor can recognize a function call in the macro identifier and replace its arguments intelligently. Here any invocation of the `MAX()` function call will have its arguments incorporated into the substitution statement.
```c
#define MAX(A, B) A >= B ? A : B
```

All the lines following `#ifndef` (`#if !defined`) will be kept in the file as long as the identifier "MYHEADER_H" has not already been defined. This common is called an **[`#include`](#include) guard**.
```cpp
#ifndef MYHEADER_H
#define MYHEADER_H
// ...
#endif
```

## Variables
Since **C++14**, you can separate digits in a long integer with a single quote to make it more readable.
```cpp
int num {12'345}; // 12,345
```
Hexadecimal literals are prefixed with "0x" and octals with "0":
```cpp
int hex {0xabcdef};
int oct {0567};
```
**`constexpr`** is used in some situations I can't figure out yet.
```cpp
static constexpr u32 MAX_MEM = 1024 * 64;
```

**`size_t`** is a type alias defined in the Standard Library (in the `cstddef` header). It is an alias for an unsigned integer type.

### Initialization
A **braced initializer** refers to placing the initial value of a variable in braces. 
This is a novel style of initialization introduced in **C++11**. 
Its main advantage is that it will raise a compile-time error if the compiler has to perform a **narrowing conversion** of the value to match the declared type.
```cpp
int apples {15};
```

Older but equally valid ways of initializing variables:
```cpp
int oranges = 12;
int kiwis(13); // "functional notation"
```
**Zero initialization** refers to initializing a variable with empty braces. It works for any fundamental type, and numeric types initialize to zero.
```cpp
int grapes {}; // 0
```

Sequences, like this [array class](Arrays) can be efficiently zero-initialized; the braces can contain any number of values up to the declared size of the array (remaining values will be zero-initialized).
```cpp
#include <array>

array<int, 5> myIntArray{};
```
[Multi-dimensional arrays](Arrays#multi-dimensional-arrays) can be initialized with nested initializers:
```cpp
int myNums[2][3] 
{
  {1, 2, 3},
  {4, 5, 6}
};
```

### Pointers
**Smart pointers** (also called **managed pointers**) are pointers that manage their own memory. They were introduced in C++11, and there is no longer a reason to use the earlier [raw pointers](#raw-pointers). In older versions of C++, memory leaks were common because the programmer had to remember to release memory allocated dynamically from the heap/free store using the `delete` keyword. These older pointers are now called [**raw pointers**](#raw-pointers)

The most commonly used smart pointer is [**`unique_ptr`**](#unique_ptr): others include `shared_ptr` and `weak_ptr`.

Only a single `unique_ptr<T>` can point to any memory address, unless ownership is transfered with `move()`.
Since C++14, it is recommended to create unique pointers using `makeunique<T>()`.
```cpp
auto pdbl = make_unique<dbouble>();
```

When variables are declared with an asterisk **`*`** appended to the datatype or prepended to the identifier, the variable becomes a **pointer** to that type. 
Pointer identifiers usually begin with "p", a convention known as **Hungarian notation**. 
The size of pointers corresponds to the address space of available memory (4 bytes for 32-bit architectures, and 8 bytes for 64-bit).
```cpp
// The following statements are equivalent.
long* pnum {}; 
long *pnum {nullptr};
```
`void *` is known as "pointer to void type", meaning variables defined as such are pointers to data of an unspecified type, making it similar to `var` in C#.

The **address-of** operator **`&`** obtains the address of a variable. The address-of operator typically also occurs with the **indirection operator** or **dereference operator** (also **`*`**) to access the data pointed to by a pointer. Using a dereferenced pointer is the same as using the variable to which it points.
```cpp
long num {12345L};
long* pnum {&num};
long newnum {*pnum + 1};
```
When a pointer points to an object with methods, like a `vector<T>` [ container ](C++-containers), the **indirect member selection operator** (**`->`**) can be used to access the methods.
```cpp
// The following statements are equivalent.
auto* pdata {new std::vector<int>{}};

std::vector<int> data;
auto* pdata = &data;

// The following statements are equivalent.
(*pdata).push_back(66);
pdata->push_back(66);
```

Pointers to classes can be recast with the following syntax:
```cpp
Animal* ptr = &kitty;
((Cat*)ptr)->chaseMouse();

// newer, safer syntax
(reinterpret_cast<Cat>(ptr))->chaseMouse();
```


## Containers

**Containers** are a type of data structure used to contain elements for various purposes. They are deeply tied to **algorithms** through **iterators**.

Two array-like data structures defined in the **Standard Library** that are more typically used are [`array<T,N>`](#sequence-containers) and [`vector<T>`](#sequence-containers)

### Arrays
An array is a variable that represents a contiguous sequence of memory locations, each storing an item of data of the same data type, each of which are called **elements**. Arrays must be declared with a constant integer expression that is fixed at compile time. Built-in arrays in C++ are inherited from C. 

```cpp
int primes[10] {1, 2, 3, 5, 7, 11, 13, 17, 19, 23}
```


### Sequence containers
The two most common sequence containers are [**`array<T,N>`**](#sequence-containers) and [**`vector<T>`**](#sequence-containers). 

All sequence containers expose several of a family of related member functions:

| Member function                                            | vector | array | list | forward_list | deque |
| ---------------------------------------------------------- | ------ | ----- | ---- | ------------ | ----- |
| [`front()`](# "First element in the sequence")             | ✅      | ✅     | ✅    | ✅            | ✅     |
| [`back()`](# "Last element in the sequence")               | ✅      | ✅     | ✅    | ❌            | ✅     |
| [`push_front()`](# "Add element to front of sequence")     | ❌      | ❌     | ✅    | ✅            | ✅     |
| [`pop_front()`](# "Remove element from front of sequence") | ❌      | ❌     | ✅    | ✅            | ✅     |
| [`push_back()`](# "Add element to back of sequence")       | ✅      | ❌     | ✅    | ❌            | ✅     |
| [`pop_back()`](# "Remove element from back of sequence")   | ✅      | ❌     | ✅    | ❌            | ✅     |
| `insert()`                                                 | ✅      | ❌     | ✅    | ✅            | ✅     |
| `erase()`                                                  | ✅      | ❌     | ✅    | ✅            | ✅     |

**`array<T,N>`** (also "[**array class**](https://subscription.packtpub.com/video/programming/9781800564084/p4/video4_3/the-array-class)") is a fixed sequence defined with two **template parameters** to create an array of `N` elements of type `T`. Here it is zero initialized with an [empty braced initializer](#initialization).
```cpp
#include <array>

array<int, 5> myIntArray{};
```
Other methods:
- [`fill()`](# "Beginning C++ 17: p. 165"): Set every element of the array to the same value
- [`size()`](# "Beginning C++ 17: p. 165"): Return the number of elements as a type `size_t`
- [`at()`](# "Beginning C++ 17: p. 166"): Access an element at a given index but testing for a valid range. Safer than using the built-in index method.

**Vectors** are sequential containers with typed elements like the [array class](#sequence-containers), but are not limited to fixed sizes. The `push_back()` method is similar to a Python `List.append()`. Other methods like `front()`, `back()`, and `pop_back()` can be used to manipulate the vector. 
```cpp
#include <vector>
vector<int> vals;
```
The [`insert()`](https://subscription.packtpub.com/video/programming/9781800564084/p4/video4_4/the-vector-class) method takes two arguments, one is an **iterator**, here provided by yet another vector method - `begin()`, and the content to be inserted. This code will insert the string at index 2.
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<string> family;
  family.push_back("Plato");
  family.push_back("Aristotle");
  family.push_back("Socrates");
  family.push_back("Pythagoras");
  family.push_back("Aristarchos");

  family.insert(family.begin() + 2, "Dgiapusccu");
  family.pop_back();
  for (string i : family) {
    cout << i << endl;
  }

  return 0;
}
```


A `forward_list<T>` is an implementation of the **singly-linked list** and is rarely used.

A `list<T>` is an implementation of the **doubly-linked list** and is rarely used.

The **double-ended queue (deque)** exposes `push_Front()` and `push_back()` methods.

### Container adapters

A `stack<T>` implements **last-in first-out (LIFO)** semantics.

Stacks support `push` and `pop` methods.

A `queue<T>` implements **first-in first-out (FIFO)** semantics.

### Associate containers

### Standard iterators
There are three types of iterator supported by containers in the Standard Library:
- **random access iterator** support the widest variety of operations: `vector<T>`, `array<T,N>`, and `deque<T>`
- **forward iterators** do not support decrement operations ("going backwards"), and this describes the operation of a [`forward_list<T>`](#forward_list)
- **bidirectional iterators** support both increment and decrement operations, but cannot jump more than one value, describing the operation of a [`list<T>`](#list)

`stack<T>`, `queue<T>`, and `priority_queue<T>` do not have iterators whatsoever.

Containers in the Standard Library expose a **`begin()`** member function, which is the most commonly used iterator.
```cpp
std::vector<char> letters{'a','b','c','d','e'}
auto iter{letters.begin()};

// Specifying type explicitly
std::vector::iterator iter{letters.begin()};
```
At a deep level, iterators are pointers, so dereferencing them produces the element of the container being iterated.
```cpp
std::cout << *iter << std:: endl; // a
```
The container can now be traversed by incrementing and (sometimes) decrementing the iterator.
```cpp
++iter;
std::cout << *iter << std:: endl; // b
```

A string can be reversed using the **`rbegin()`** and **`rend()`** iterators:
```cpp
string name{"Lorem ipsum..."};
string reverse(name.rbegin(), name.rend());
```
### Maps

A syntactic sugar has been available since C++17:
```cpp
for ([x, y] : coords)
{
  std::cout << x << y << endl;
}
```
It is equivalent to:
```cpp
for (std::pair<int, int> el : coords)
{
  std::cout << el.first << el.second << endl;
}
```
The **`pair`** type has two public fields:

- `first`
- `second`## Math

```cpp
#include <math.h>
using namespace std;

int main() {
  int num{2};
  cout << pow(num,2) << endl;
}
```

## Classes

New data types in C++ are created as **classes**, which can be composites of **member variables** of other types and **member functions**, allowing complex and intuitive models to be created.

The three primary principles of OOP are:

- **Encapsulation**: member variables and functions are packaged together
    - **Data hiding** preserves the integrity of an object
- [**Inheritance**](#inheritance) allows one type to define another.
- [**Polymorphism**](#polymorphism) (in C++ implemented by calling member functions using a pointer or reference) allow behavior of base classes to be exposed from objects of derived classes

### Member variables
Classes can contain **member variables** that are `public` or `private` ("**access specifiers**"), but it is best practice to make variables private while implementing **accessor** functions (getters and setters):
- Hiding data preserves the integrity of objects
- Loose coupling facilitates future change in codebase
- Extra code can be injected for logging or data validation
- Debuggers can set breakpoints on these getters and setters 
```cpp
class Box
{
private:
  double length {1,0};
  double width {1,0};
  double height {1,0};
public:
  double volume()
  {
    return length * width * height;
  }
};
```
### Initialization

A **member initializer list** can be used to initialize fields more efficiently than explicit assignment. 
```cpp
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}
```
This technique **must** have an expression in braces, even if they are empty.
```cpp
// Compiler error
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} 
```
Notably, this technique doesn't appear to work in derived class constructors.
```cpp
class Animal 
{
public:
  std::string _name{};
  Animal(std::string n) : _name {n} {}
}

class Dog : public Animal
{
public:
  Dog(std::string n, std::string b) : Animal(n) {_breed = b;};
}
```

A class **constructor** is called whenever a new instance of the class is defined. It always has the same name as the class itself and has no return data type because it returns no data.
```cpp
class Box
{
private:
  // ...
public:
  Box( double l, double w, double h)
  {
    length = l;
    width = w;
    height = h;
  }
};
```

If a constructor isn't defined, the compiler will supply a **default default constructor** when an object is instantiated without initial values.
To define a default constructor:
```cpp
Box() = default;
```

A **destructor** is a special member of a class executed to deal with cleanup upon use of the `delete` operator. A class can have only one destructor, and if one isn't defined then the compiler provides a default destructor that does nothing. The name of the destructor for a class is always the class name prefixed with a tilde, and similar to a constructor it cannot have a return type or parameters.
```cpp
~Box() = default;
Box::~Box() = default; // when defined outside the class
```

Base class destructors should always be declared as [`virtual`](#polymorphism).

### Access

When variables of class types are instantiated with the `const` keyword, they are called **const objects**, and none of their member variables can be altered (member variables of const objects become immutable). The compiler will throw an error when attempting to invoke methods of const objects unless they are identified as **const member functions** by using the `const` keyword in the signature **after** the identifier ("attribute"?):
```cpp
class Box {
  double volume () const { /* ... */ }
  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }
}
```

`public`, `private`, and `protected` are **access specifiers** that determine how a member variables and functions can be accessed from the outside. When inheriting from a base class, an access specifier can also be used to determine how accessible that base class's members are within the derived class.
```cpp
class Dog : public Animal 
{
  // ...
}
```
- When the base class specifier is `public`, inherited members are unchanged
- When the base class specifier is `protected`, inherited public and protected members become protected
- When the base class specifier is private, all inherited members become private.

A **friend** is a function to which a class grants access to its private internals. They may be useful in rare situations where a single function needs access to the internals of different kinds of objects.

### Inheritance
When creating subclasses, you must remember:
- Private variables must be placed in the **`protected`** access specifier so that they are accessible to child classes.
- The **base class [access specifier](#access-specifiers)** must allow access to the base class's private variables (**`public`** or `protected`)
- Parent class must have a [**default constructor**](#default-constructor)
```cpp
class Animal {
protected: // not `private:`!
  std::string _name;
public:
  Animal() = default;
}
class Dog : public Animal { /* ... */ } // 
```
### Polymorphism

**Polymorphism** in C++ refers to the practice of invoking a base class's member function rather than the derived class. 

Because the compiler performs **early binding** by default, a pointer typed to a base class but initialized to a derived class will invoke the base class's member function. **Late binding** can be used to force the pointer to use the derived class's member function even when the type of the pointer is the base class. This is done by using the **`virtual`** keyword on the base class's member function. 

Classes with virtual functions are called **abstract classes** and may not be instantiated. Abstract classes that are made of **only** virtual functions are called **interfaces**.
```cpp
class Base 
{
public:
  virtual void doStuff() { /* ... */ }
}

class Derived : public Base
{
public:
  void doStuff() { /* ... */ }
}

int main() 
{
  Derived derived{};
  Base* pointer = &derived; // a pointer to an abstract class **may** be used
  pointer->doStuff();
}
```
Derived classes must then **override** this virtual function with the **`override`** keyword. 
```cpp
class Derived : public Base {
  override doStuff() // ...
}
```
### Enumerations

Enumerations can be specified with **`enum`**. Without specifying a value, each element of the enum is given a successively greater integer value starting with 0, like the indexes of an array (an **ordinal value**).
```cpp
enum Choices {A, B, C, D }
```
These elements can be specified with or without the **scope resolution operator** `::`
```cpp
cout << A;          // 0
cout << Choices::A; // 0
```
### Templates

**Templates** are used to have the compiler generate code automatically for a given data type. This is to avoid highly repetitive overloaded function definitions which only differ in parameter lists. 

The **`template`** and **`typename`** keywords define a template. The placeholder **"T"** represents the data type that will be replaced by a specific type by the compiler.
```cpp
template <typename T> T larger (T a, T b) {
  return a>b ? a : b;
}
```
More than one data type can be used for the parameters, but in that case the return type must be explicitly specified:
```cpp
template <typename T1, typename T2> bool larger (T1 a, T2 b) {
  return a>b;
}
```

## Control flow

The choices in a **`switch`** statement are called **cases**. You can only switch on constant expressions that can be evaluated at compile-time, typically literals but excluding strings. Each case must be followed by a **`break`** statement to prevent **fallthrough**, except for the **default case**.
```cpp
switch (choice)
{
  case 1:
    // ...
    break;
  case 2:
    // ...
    break;
  default:
    // ...
}
```

Since C++11, the **range-based for-loop** is available, which works very similar to a Python for-in loop:
```cpp
for (string num : nums)
{
  cout << num << endl;
}
```

## Functions

**Function prototypes**, defining the **function header** (return data type, function name, and parameter list), describe a function sufficiently for the compiler to be able to compile calls to it and are required before using a function if the function declaration doesn't precede all the locations where it's called.
```cpp
#include <iostream>
using namespace std;

// Without this prototype, there is a  compile-time error.
void printSomething();

int main() {
  printSomething();
  return 0;
}

void printSomething()
{
  cout << "something..." << endl;
}
```
**Passing by reference** allows variables to be changed in-place and works by using the reference to the argument. **Passing by value** is the default **parameter passing scheme**, which works by actually copying the argument.
```cpp
int func(int a) {
  // Pass by value
}
int func(int &a) {
  // Pass by reference
}
```
## Recursion
Recursion requires a **base case** and at least one **recursive case**. The **call stack** is a **stack** data structure that figures prominently in recursive computing.## Home

| Project                  | Description                                                                                                    |
| ------------------------ | -------------------------------------------------------------------------------------------------------------- |
| JamoftheMonthProject.cpp | CLI application that calculates how much the user owes based on selected subscription tier and units purchased |
| TicTacToe.cpp            |
| RPGCharGen.cpp           | Multiple classes using inheritance, [virtual](#polymorphism) member functions, [enums](Enum)                   |


| Task             | Description     |
| ---------------- | --------------- |
| Reverse a string | ...## Iterators |

An **iterator** is a classical and widespread design pattern that allows a wide variety of container-like objects to be traversed by exposing a uniform interface.

However, loops based on iterators should only be used if access to the iterator is needed for advanced processing in the loop body. A [range-based for loop](Control-flow#for-loops) is the recommended way to iterate over all elements of a container.

- [Standard iterators](#standard-iterators)
  - [`begin()`](#begin)
  - [`end()`](#end)
  - [`rbegin()`](#rbegin)



## Memory

Memory leaks can be detected using **valgrind**.

## Namespaces

A **namespace** is a block that attaches an extra name to every entity name that is declared or defined within it. The **qualified name** of each entity is the namespace name followed by the **scope resolution operator** `::` followed by the basic entity name. Namespaces can be used to partition large codebases into logical groupings to avoid name clashes. If a namespace isn't defined, the **global namespace**, where entities have no namespace name attached, applies by default.

You can define a namespace using the `namespace` keyword.
```cpp
namespace foo {
  // ...
}
```
Namespaces can be nested..
```cpp
namespace outer {
  namespace inner {
    void foo() {
      // ...
    }
  }
}
outer::inner::foo()
```
Namespace aliases can be formed:
```cpp
namespace outin = outer::inner;
outin::foo()
```

The **`using`** keyword allows you to reference any name from a namespace without qualifying it.
```cpp
using namespace std;
```
It can also be used specify a **type alias**, where an alternative name is used to refer to an existing data type.
```cpp
using BigOnes = unsigned long long;
typedef unsigned long long BigOnes; // Older, less intuitive syntax
```
## Operators

Each operator is associated with a particular named function. Operators can be overloaded by implementing that function.

```cpp
bool Rectangle::operator==(const Rectangle& other) const
{
  return _length == other._length && _width == other._width;
}
```

## Header files
| Topic                             | Header file   |
| --------------------------------- | ------------- |
| [array](#sequence-containers)     | `<array>`     |
| [deque](#dequet)                  | `<deque>`     |
| exception                         | `<exception>` |
| [map](#maps)                      | `<map>`       |
| [Mathematical functions](Math)    | `<math.h>`    |
| [queue](#queue)                   | `<queue>`     |
| [stack](#stack)                   | `<stack>`     |
| [vector](#sequence-containers)    | `<vector>`    |
| [Smart pointers](#smart-pointers) | `<memory>`    |

## Applications
### gtkmm

[**gtkmm**](https://developer.gnome.org/gtkmm-tutorial/3.24/) (historically "GTK--") is a C++ wrapper for an underlying GTK code base written in C. Compared to **Qt**, another GUI library, gtkmm uses more modern and native C++ features.

In [Ubuntu](https://packages.ubuntu.com/focal/devel/gnome-devel), installing the development environment is done with the `gnome-devel` metapackage:
```sh
sudo apt install gnome-devel
```
### [NES emulator](6502.md)

## Courses

### C++ Standard Template Library in Practice

| /#    | Topic                   | Video                                                                                    | Projects         |
| ----- | ----------------------- | ---------------------------------------------------------------------------------------- | ---------------- |
| 01.01 |                         | [The Course Overview](# "video01_01.mp4")                                                |
| 01.02 | [Templates](#templates) | [Introduction to the STL](# "video01_02.mp4")                                            | TemplateSTL.cpp  |
| 01.03 |                         | [General Concepts](# "video01_03.mp4")                                                   | ExceptionSTL.cpp |
| 01.04 |                         | [Utilities - Common Utilities](# "video01_04.mp4")                                       | StringSTL.cpp    |
| 01.05 |                         | [Utilities - Regex](# "video01_05.mp4")                                                  | RegexSTL.cpp     |
| 01.06 |                         | [Project - Bitcoin Exchange Program](# "video01_06.mp4")                                 | BTCX.cpp         |
| 01.07 |                         | [Project - Coding](# "video01_07.mp4")                                                   |
| 01.08 |                         | [Project - Custom Writer Function](# "video01_08.mp4")                                   |
| 01.09 |                         | [Review](# "video01_09.mp4")                                                             |
| 02.01 |                         | [Understanding Containers](# "video02_01.mp4")                                           |
| 02.02 |                         | [Vectors](# "video02_02.mp4")                                                            |
| 02.03 |                         | [Standard Array](# "video02_03.mp4")                                                     |
| 02.04 |                         | [Lists](# "video02_04.mp4")                                                              |
| 02.05 |                         | [Stacks and Queues](# "video02_05.mp4")                                                  |
| 02.06 |                         | [Maps and Multimaps - Overview](# "video02_06.mp4")                                      |
| 02.07 |                         | [Maps - Coding](# "video02_07.mp4")                                                      |
| 02.08 |                         | [Multimaps - Coding](# "video02_08.mp4")                                                 |
| 02.09 |                         | [Sets and Multisets](# "video02_09.mp4")                                                 |
| 02.10 |                         | [Project](# "video02_10.mp4")                                                            |
| 02.11 |                         | [Review](# "video02_11.mp4")                                                             |
| 03.01 |                         | [Iterators](# "video03_01.mp4")                                                          |
| 03.02 |                         | [Input Iterators](# "video03_02.mp4")                                                    |
| 03.03 |                         | [Output Iterators](# "video03_03.mp4")                                                   |
| 03.04 |                         | [Forward Iterators](# "video03_04.mp4")                                                  |
| 03.05 |                         | [Bidirectional Iterators](# "video03_05.mp4")                                            |
| 03.06 |                         | [Random Access Iterators](# "video03_06.mp4")                                            |
| 03.07 |                         | [Auxiliary Iterator Functions](# "video03_07.mp4")                                       |
| 03.08 |                         | [Iterator Adaptors](# "video03_08.mp4")                                                  |
| 03.09 |                         | [Writing Generic Functions for Iterators](# "video03_09.mp4")                            |
| 03.10 |                         | [User - Defined Iterators](# "video03_10.mp4")                                           |
| 03.11 |                         | [Project](# "video03_11.mp4")                                                            |
| 03.12 |                         | [Review](# "video03_12.mp4")                                                             |
| 04.01 |                         | [Introduction to Algorithms](# "video04_01.mp4")                                         |
| 04.02 |                         | [Sequence Algorithms - for_each](# "video04_02.mp4")                                     |
| 04.03 |                         | [Sequence Algorithms - equals](# "video04_03.mp4")                                       |
| 04.04 |                         | [Copying](# "video04_04.mp4")                                                            |
| 04.05 |                         | [Moving](# "video04_05.mp4")                                                             |
| 04.06 |                         | [Removing](# "video04_06.mp4")                                                           |
| 04.07 |                         | [Sorting and Gathering - std::sort](# "video04_07.mp4")                                  |
| 04.08 |                         | [Sorting and Gathering - std::partial_sort algorithm](# "video04_08.mp4")                |
| 04.09 |                         | [Sorting and Gathering - std::partition](# "video04_09.mp4")                             |
| 04.10 |                         | [Sorting and Gathering - std::partition_copy](# "video04_10.mp4")                        |
| 04.11 |                         | [Searching and Finding - std::find](# "video04_11.mp4")                                  |
| 04.12 |                         | [Sorting and Gathering - std::find_first_of, std::adjacent_find](# "video04_12.mp4")     |
| 04.13 |                         | [Sorting and Gathering - std::search](# "video04_13.mp4")                                |
| 04.14 |                         | [Sorting and Gathering - std::binary_search](# "video04_14.mp4")                         |
| 04.15 |                         | [Counting](# "video04_15.mp4")                                                           |
| 05.01 |                         | [Replacing and Transforming - std::replace](# "video05_01.mp4")                          |
| 05.02 |                         | [Replacing and Transforming - std::replace_copy](# "video05_02.mp4")                     |
| 05.03 |                         | [Replacing and Transforming - equals](# "video05_03.mp4")                                |
| 05.04 |                         | [Swapping](# "video05_04.mp4")                                                           |
| 05.05 |                         | [Rotating](# "video05_05.mp4")                                                           |
| 05.06 |                         | [Randomizing](# "video05_06.mp4")                                                        |
| 05.07 |                         | [Permutations](# "video05_07.mp4")                                                       |
| 05.08 |                         | [Sampling](# "video05_08.mp4")                                                           |
| 05.09 |                         | [Min](# "video05_09.mp4")                                                                |
| 05.10 |                         | [Max](# "video05_10.mp4")                                                                |
| 05.11 |                         | [Clamp](# "video05_11.mp4")                                                              |
| 05.12 |                         | [Fill and Generate](# "video05_12.mp4")                                                  |
| 05.13 |                         | [Numeric Algorithms - std::accumulate](# "video05_13.mp4")                               |
| 05.14 |                         | [Numeric Algorithms - std::partial_sum and std::adjacent_difference](# "video05_14.mp4") |
| 05.15 |                         | [Numeric Algorithms - std::gcd, and std::lcm](# "video05_15.mp4")                        |
| 05.16 |                         | [Numeric Algorithms - std::inner_product and std::iota](# "video05_16.mp4")              |
| 05.17 |                         | [Review](# "video05_17.mp4")                                                             |
| 06.01 |                         | [Basic Architecture of the I/O Stream Library](# "video06_01.mp4")                       |
| 06.02 |                         | [Console I/O - Interact with a User](# "video06_02.mp4")                                 |
| 06.03 |                         | [Console I/O - Read Input](# "video06_03.mp4")                                           |
| 06.04 |                         | [File I/O](# "video06_04.mp4")                                                           |
| 06.05 |                         | [String Streams](# "video06_05.mp4")                                                     |
| 06.06 |                         | [Manipulators and Formatters](# "video06_06.mp4")                                        |
| 06.07 |                         | [Stream States](# "video06_07.mp4")                                                      |
| 06.08 |                         | [Low Level I/O](# "video06_08.mp4")                                                      |
| 06.09 |                         | [Overloading Stream Operators](# "video06_09.mp4")                                       |
| 06.10 |                         | [Project - Overview](# "video06_10.mp4")                                                 |
| 06.11 |                         | [Project - Classes and structures](# "video06_11.mp4")                                   |
| 06.12 |                         | [Project - Implementation](# "video06_12.mp4")                                           |
| 06.13 |                         | [Review](# "video06_13.mp4")                                                             |
| 07.01 |                         | [Unique Pointers](# "video07_01.mp4")                                                    |
| 07.02 |                         | [Shared Pointers](# "video07_02.mp4")                                                    |
| 07.03 |                         | [Allocators](# "video07_03.mp4")                                                         |
| 07.04 |                         | [Defining an Allocator](# "video07_04.mp4")                                              |
| 07.05 |                         | [Uninitialized Memory](# "video07_05.mp4")                                               |
| 07.06 |                         | [Review](# "video07_06.mp4")                                                             |
| 08.01 |                         | [Introduction to Threading](# "video08_01.mp4")                                          |
| 08.02 |                         | [Creating Threads](# "video08_02.mp4")                                                   |
| 08.03 |                         | [Locks](# "video08_03.mp4")                                                              |
| 08.04 |                         | [Shared Locks](# "video08_04.mp4")                                                       |
| 08.05 |                         | [Atomic Values](# "video08_05.mp4")                                                      |
| 08.06 |                         | [Async](# "video08_06.mp4")                                                              |
| 08.07 |                         | [Condition Variables](# "video08_07.mp4")                                                |
| 08.08 |                         | [Project](# "video08_08.mp4")                                                            |
| 08.09 |                         | [Review](# "video08_09.mp4")                                                             |
| 09.01 |                         | [Concepts](# "video09_01.mp4")                                                           |
| 09.02 |                         | [Modules](# "video09_02.mp4")                                                            |
| 09.03 |                         | [Coroutines](# "video09_03.mp4")                                                         |
| 09.04 |                         | [Course Review](# "video09_04.mp4")                                                      |

### Complete C++ Developer Course

| /#    | Topic                                                           | Video                                                                                                        | Projects                                     |
| ----- | --------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ | -------------------------------------------- |
| 1.1   |                                                                 | [Section Overview](# "video01_01.mp4")                                                                       |
| 1.2   |                                                                 | [Getting Started on Windows with Visual Studio Integrated Development Environment (IDE)](# "video01_02.mp4") |
| 1.3   |                                                                 | [Getting Started on macOS or Linux with CodeBlocks IDE](# "video01_03.mp4")                                  |
| 1.4   |                                                                 | [Getting Started with macOS Catalina or Higher with Visual Studio Code](# "video01_04.mp4")                  |
| 1.5   |                                                                 | [Finding Answers to Your Questions](# "video01_05.mp4")                                                      |
| 2.1   |                                                                 | [Section Overview](# "video02_01.mp4")                                                                       |
| 2.2   |                                                                 | [Saying "Hello" to C++](# "video02_02.mp4")                                                                  |
| 2.3   |                                                                 | [Variables and Data Types - Part 1](# "video02_03.mp4")                                                      |
| 2.4   |                                                                 | [Variables and Data Types - Part Two](# "video02_04.mp4")                                                    |
| 2.5   |                                                                 | [Variables and Data Types - Part Three](# "video02_05.mp4")                                                  |
| 2.6   |                                                                 | [Comments](# "video02_06.mp4")                                                                               |
| 2.7   |                                                                 | [Arithmetic Operators](# "video02_07.mp4")                                                                   |
| 2.8   |                                                                 | [Relational Operators](# "video02_08.mp4")                                                                   |
| 2.9   |                                                                 | [Logical Operators](# "video02_09.mp4")                                                                      |
| 2.10  |                                                                 | [Symbolic Constants and Naming Conventions](# "video02_10.mp4")                                              |
| 2.11  |                                                                 | [User Input](# "video02_11.mp4")                                                                             |
| 2.12  |                                                                 | [Project - Average of Three](# "video02_12.mp4")                                                             |
| 2.13  |                                                                 | [Project - MadLibs Clone](# "video02_13.mp4")                                                                |
| 2.14  |                                                                 | [Section Wrap-Up](# "video02_14.mp4")                                                                        |
| 3.1   |                                                                 | [Section Overview](# "video03_01.mp4")                                                                       |
| 3.2   |                                                                 | [Introduction to Control Statements](# "video03_02.mp4")                                                     |
| 3.3   |                                                                 | [Selection Control Statements](# "video03_03.mp4")                                                           |
| 3.4   |                                                                 | [Repetition Control Statements](# "video03_04.mp4")                                                          |
| 3.5   |                                                                 | [The Break and Continue Statements](# "video03_05.mp4")                                                      |
| 3.6   |                                                                 | [Random Numbers](# "video03_06.mp4")                                                                         |
| 3.7   |                                                                 | [Project - Jam of the Month Club](# "video03_07.mp4")                                                        |
| 3.8   |                                                                 | [Project - Odds and Evens](# "video03_08.mp4")                                                               |
| 3.9   |                                                                 | [Project - Guess the Number](# "video03_09.mp4")                                                             |
| 3.10  |                                                                 | [Section Wrap-Up](# "video03_10.mp4")                                                                        |
| 4.1   |                                                                 | [Section Overview](# "video04_01.mp4")                                                                       |
| 4.2   |                                                                 | [Built-in Arrays](# "video04_02.mp4")                                                                        |
| 4.3   |                                                                 | [The Array Class](# "video04_03.mp4")                                                                        |
| 4.4   |                                                                 | [The Vector Class](# "video04_04.mp4")                                                                       |
| 4.5   |                                                                 | [Multi-Dimensional Arrays](# "video04_05.mp4")                                                               |
| 4.6   |                                                                 | [Project - Array Data](# "video04_06.mp4")                                                                   |
| 4.7   |                                                                 | [Project - Vector Data](# "video04_07.mp4")                                                                  |
| 4.8   |                                                                 | [Project - Parallel Arrays/Vectors](# "video04_08.mp4")                                                      |
| 4.9   |                                                                 | [Section Wrap-Up](# "video04_09.mp4")                                                                        |
| 5.1   |                                                                 | [Section Overview](# "video05_01.mp4")                                                                       |
| 5.2   |                                                                 | [Function Prototypes and Definitions](# "video05_02.mp4")                                                    | FunctionFun.cpp                              |
| 5.3   |                                                                 | [Function Return Types and Parameters](# "video05_03.mp4")                                                   |
| 5.4   |                                                                 | [Parameter Passing: Pass-by-Value and Pass-by-Reference](# "video05_04.mp4")                                 | PassingSchemes.cpp                           |
| 5.5   |                                                                 | [Variable Scope and Lifetime](# "video05_05.mp4")                                                            | ScopeFun                                     |
| 5.6   |                                                                 | [Function Overloading](# "video05_06.mp4")                                                                   |
| 5.7   |                                                                 | [The 	&lt;cmath&gt; Library](# "video05_07.mp4")                                                             |
| 5.8   |                                                                 | [Recursion](# "video05_08.mp4")                                                                              |
| 5.9   |                                                                 | [Project - Return the Product of Three Parameters](# "video05_09.mp4")                                       |
| 5.10  |                                                                 | [Project - Return the Sum of Built-in Array Elements](# "video05_10.mp4")                                    |
| 5.11  |                                                                 | [Project - Return the Sum of Array Object Elements](# "video05_11.mp4")                                      |
| 5.12  |                                                                 | [Project - Retrieve the Sum of Array Object Elements by Reference](# "video05_12.mp4")                       |
| 5.13  |                                                                 | [Project - Tic-Tac-Toe (ADVANCED)](# "video05_13.mp4")                                                       |
| 5.14  |                                                                 | [Section Wrap-Up](# "video05_14.mp4")                                                                        |
| 6.1   |                                                                 | [Section Overview](# "video06_01.mp4")                                                                       |
| 6.2   |                                                                 | [Basics of Object Oriented Programming (OOP)](# "video06_02.mp4")                                            |
| 6.3   |                                                                 | [Encapsulation: Data Members and Member Functions](# "video06_03.mp4")                                       |
| 6.4   |                                                                 | [Separate Compilation](# "video06_04.mp4")                                                                   |
| 6.5   |                                                                 | [Constructors and Destructors](# "video06_05.mp4")                                                           |
| 6.6   |                                                                 | [A Rectangle Class](# "video06_06.mp4")                                                                      | Rectangle.cpp                                |
| 6.7   |                                                                 | [A Book Class](# "video06_07.mp4")                                                                           |
| 6.8   |                                                                 | [Project - A Bank Account Class](# "video06_08.mp4")                                                         |
| 6.9   |                                                                 | [Project - A Pizza Class](# "video06_09.mp4")                                                                |
| 6.10  |                                                                 | [Project - A Circle Class](# "video06_10.mp4")                                                               |
| 6.11  |                                                                 | [Section Wrap-Up](# "video06_11.mp4")                                                                        |
| 7.1   |                                                                 | [Section Overview](# "video07_01.mp4")                                                                       |
| 7.2   |                                                                 | [Exceptions and the Exception Hierarchy](# "video07_02.mp4")                                                 |
| 7.3   |                                                                 | [Logic Errors](# "video07_03.mp4")                                                                           |
| 7.4   |                                                                 | [Runtime Errors and Throwing Exceptions](# "video07_04.mp4")                                                 |
| 7.5   |                                                                 | [Rethrowing Exceptions](# "video07_05.mp4")                                                                  |
| 7.6   |                                                                 | [Custom Exceptions](# "video07_06.mp4")                                                                      |
| 7.7   |                                                                 | [Basic Testing and Debugging](# "video07_07.mp4")                                                            |
| 7.8   |                                                                 | [Project - Throwing and Handling an Out_of_Range Exception](# "video07_08.mp4")                              |
| 7.9   |                                                                 | [Project - Creating and Using Your Own Exception](# "video07_09.mp4")                                        |
| 7.10  |                                                                 | [Section Wrap-Up](# "video07_10.mp4")                                                                        |
| 8.1   |                                                                 | [Section Overview](# "video08_01.mp4")                                                                       |
| 8.2   |                                                                 | [Introduction to Pointers](# "video08_02.mp4")                                                               |
| 8.3   |                                                                 | [Dynamic Memory - Part 1](# "video08_03.mp4")                                                                |
| 8.4   |                                                                 | [Dynamic Memory (- Part 2](# "video08_04.mp4")                                                               |
| 8.5   |                                                                 | [Const Correctness](# "video08_05.mp4")                                                                      |
| 8.6   |                                                                 | [Project - Dynamically Creating Rectangles](# "video08_06.mp4")                                              |
| 8.7   |                                                                 | [Project - Dynamically Creating Circles](# "video08_07.mp4")                                                 |
| 8.8   |                                                                 | [Section Wrap-Up](# "video08_08.mp4")                                                                        |
| 9.1   |                                                                 | [Section Overview](# "video09_01.mp4")                                                                       |
| 9.2   |                                                                 | [Sequential File Output](# "video09_02.mp4")                                                                 |
| 9.3   |                                                                 | [Sequential File Input](# "video09_03.mp4")                                                                  |
| 9.4   |                                                                 | [More File Input/ Output (I/O)](# "video09_04.mp4")                                                          |
| 9.5   |                                                                 | [Project - Reading Data from File and Printing Statistics](# "video09_05.mp4")                               |
| 9.6   |                                                                 | [Project - Dynamically Creating Rectangles from File](# "video09_06.mp4")                                    |
| 9.7   |                                                                 | [Project - Shopping Item File](# "video09_07.mp4")                                                           |
| 9.8   |                                                                 | [Section Wrap-Up](# "video09_08.mp4")                                                                        |
| 10.1  |                                                                 | [Section Overview](# "video10_01.mp4")                                                                       |
| 10.2  |                                                                 | [Inheritance - Part 1](# "video10_02.mp4")                                                                   |
| 10.3  |                                                                 | [Inheritance - Part 2)](# "video10_03.mp4")                                                                  |
| 10.4  |                                                                 | [Polymorphism and Late Binding](# "video10_04.mp4")                                                          |
| 10.5  |                                                                 | [Enumerated Types This video explains enumerated types.](# "video10_05.mp4")                                 | EnumFun.cpp                                  |
| 10.6  |                                                                 | [Project - Derived Cat Class](# "video10_06.mp4")                                                            | Cat.cpp                                      |
| 10.7  |                                                                 | [Project – Role Playing Game (RPG) Player Character Creation](# "video10_07.mp4")                            | [RPGCharGen](#rpgchargen)                        |
| 10.8  |                                                                 | [Section Wrap-Up](# "video10_08.mp4")                                                                        |
| 11.1  |                                                                 | [Section Overview](# "video11_01.mp4")                                                                       |
| 11.2  |                                                                 | [Templates - Standard Template Library (STL)](# "video11_02.mp4")                                            | TemplateFun.cpp                              |
| 11.3  | [`queue<T>`](#queue) [`stack<T>`](#stack) [`deque<T>`](#dequet) | [Standard Template Library (STL) - Part 1)](# "video11_03.mp4")                                              | DequeFun.cpp, StackFun.cpp, QueueProject.cpp |
| 11.4  | [`map<T>`](Maps)                                                | [Standard Template Library (STL) - Part 2](# "video11_04.mp4")                                               | ContactsFun.cpp, AlgorithmFun.cpp            |
| 11.5  | [`unique_ptr<T>`](Pointers#smart-pointers)                      | [Smart Pointers](# "video11_05.mp4")                                                                         | SmartPointerFun.cpp, Car.cpp                 |
| 11.6  | [Friend functions](#friends)                                    | [Friend Functions and Friend Classes](# "video11_06.mp4")                                                    | FriendFunctions.cpp                          |
| 11.7  |                                                                 | [Operator Overloading](# "video11_07.mp4")                                                                   | OverloadingFun.cpp, Rectangle.h              |
| 11.8  | [`map<T>`](Maps)                                                | [Project - Dictionary of Terms](# "video11_08.mp4")                                                          | DictionaryProject.cpp                        |
| 11.9  |                                                                 | [Project - Aliens](# "video11_09.mp4")                                                                       | Aliens.cpp                                   |
| 11.10 |                                                                 | [Section Wrap-Up](# "video11_10.mp4")                                                                        |

#### RPGCharGen

=== "cpp"
    ```cpp
    #include <iostream>
    #include "RPGCharGen.h"
    using namespace std;

    int main() {
    
    Warrior w{"Doofus McGroober", Race::HUMAN};
    cout << "Player name: " << w.getName() << endl;
    cout << "Player HP:   " << w.getHp() << endl;
    cout << "Player MP:   " << w.getMp() << endl;
    cout << "Player race: " << w.getRace() << endl;
    w.attack();

    Priest m{"Brother Tolkien", Race::ELF};
    cout << "Player name: " << m.getName() << endl;
    cout << "Player HP:   " << m.getHp() << endl;
    cout << "Player MP:   " << m.getMp() << endl;
    cout << "Player race: " << m.getRace() << endl;
    m.attack();

    Mage n{"Smart Frodo", Race::DWARF};
    cout << "Player name: " << n.getName() << endl;
    cout << "Player HP:   " << n.getHp() << endl;
    cout << "Player MP:   " << n.getMp() << endl;
    cout << "Player race: " << n.getRace() << endl;
    n.attack();
    return 0;
    }
    ```

=== "h"

    ```cpp
    #if !defined(RPGCHARGEN_H)
    #define RPGCHARGEN_H
    #include <string>

    enum Race { HUMAN, ELF, DWARF };

    class Player {

    protected:
    std::string _name{ "Johnny Bravo" };
    Race _race{Race::HUMAN };
    int _hp{ 100 };
    int _mp{ 100 };

    public:
    Player(std::string n, Race r, int hp, int mp) : _name{n}, _race{r}, _hp(hp), _mp(mp) {}
    virtual std::string attack()= 0;
    int getHp()                 { return _hp;   }
    int getMp()                 { return _mp;   }
    
    std::string getRace()              
    {
        switch (_race)
        {
        case 0:
        return "human";
        break;
        
        case 1:
        return "elf";
        break;
        case 2:
        return "dwarf";
        break;

        default:
        return "none";
        break;
        }
    }
    std::string getName()       { return _name; }
    void setHp(int n)           { _hp = n;   }
    void setMp(int n)           { _mp = n;   }
    void setName(std::string s) { _name = s; }
    void setRace(Race r)        { _race = r;}
    };

    class Warrior : public Player {
    public:
    Warrior(std::string n, Race r) : Player(n, r, 200, 0) {}
    std::string attack() {return "I will destroy you with my sword, foul demon!";}
    };

    class Priest : public Player {
    public:
    Priest(std::string n, Race r) : Player(n, r, 100, 200) {}
    std::string attack() {return "Taste the wrath of the Two True Gods!";}
    };

    class Mage : public Player {
    public:
    Mage(std::string n, Race r) : Player(n, r, 150, 150) {}
    std::string attack() {return "You are overmatched by my esoteric artifices!";}
    };

    #endif // RPGCHARGEN_H
    ```