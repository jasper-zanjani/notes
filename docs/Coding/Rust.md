*[TOML]: Tom's Obvious Minimal Language
*[LIFO]: Last-In First-Out
*[RPL]: Klabnik, Steve and Nichols, Carol. <i>The Rust Programming Language</i>. 2019.

<!----------------------------------------------------------------------------
TODO: 

- Return to exercism and other code sites to find applications of iterator methods, i.e. finding odd or even numbers, etc

----------------------------------------------------------------------------->

# Rust

> Rust's distinguishing feature as a programming language is its ability to prevent invalid data access at compile time.
> 
> &mdash;Tim McNamara

Rust offers **zero-cost abstractions**, where using the abstraction imposes no addition runtime overhead.

#### Documentation

Rust uses C-style line comments using `//` and block comments using `/*`, `*/`

**Doc comments** support markdown and are used to generate documentation with the use of a built-in static site generator that can compile inline comments (**`--open`** opens the site in the default web browser).

```sh
cargo doc --open
```


Markdown code blocks containing test cases are known as **doc tests** and can be run with `cargo test`, for library crates only.
Note that markdown code blocks in Rust doc comments don't need a language annotation.

- **Outer doc comments** are preceded by `///` and are written immediately preceding the code blocks they document
- **Inner doc comments** are preceded by `//!` and are written within code blocks, similar to docstrings in Python

---8<-- "includes/Coding/Rust/Starships/1/starship.rs.md"


#### Organization

Projects in Rust are called **crates**{:#crate}, and they can be created with the **`cargo`** command-line utility.
By default, cargo will initiate a Git repo

=== ":material-git: Default"
    ```sh
    cargo new hello_cargo
    ```

=== ":no_entry_sign: None"
    ```sh
    cargo new hello_cargo --vcs none
    ```

The **`add`** subcommand can be enabled by running `cargo install cargo-edit`.
Now dependencies can be added thus:

``` sh
cargo add num
```

This creates a TOML configuration file for the project.
Rust refers to code dependencies as **crates**, equivalent to **modules** in Python.
Open-source crates are stored in the **registry**.

A **package** contains one or more [**crates**](#crate) and contains a Cargo.toml file.

**Modules** allow code to be organized within a crate into groups for readability.

- **`mod`** declares a module, which can be nested
- **`crate`** is the root of the module tree, equivalent to `cd /`
- **`super`** moves up the module tree one node, similar to `cd ..`
- **`use .. as`** is similar to creating a shortcut or symlink. Rust convention is to bring a function's parent into scope in order to mark function calls as unmistakeably belonging to external code. However, for structs and other data structures the full path is specified.
- **`pub use`** statements are used to construct a convenient API by allowing the namespace to be flattened

!!! rs "&nbsp;"

    === "lib.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/lib.rs.md"

    === "starship.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/starship.rs.md"

    === "officer.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/officer.rs.md"


### Error handling

Rust distinguishes between *recoverable* and *unrecoverable* errors.
Recoverable errors can be handled by program logic, whereas unrecoverable errors result in a crash (ref. [`panic!()`](#macro)).

A key data structure used in error handling in Rust is a [`match`](#match) statement with two arms to handle the two variants of a [`Result<T,E>`](#resultte) enum.
However, `match` statements are also considered hard to read, and seasoned Rustaceans will be able to improve readability by using `Result<T,E>` helper methods like `unwrap()` and `expect()` when they are better.

=== "Idiomatic"

    ```rs
    use std::fs::File;
    use std::io::ErrorKind;

    fn main() {
        let f = File::open("hello.txt").unwrap_or_else(|error| {
            if error.kind() == ErrorKind::NotFound {
                File::create("hello.txt").unwrap_or_else(|error| {
                    panic!("Problem creating the file: {:?}", error);
                })
            } else {
                panic!("Problem opening the file: {:?}", error);
            }
        });
    }
    ```

=== "Naive"

    ```rs
    use std::fs::File;
    use std::io::ErrorKind;

    fn main() {
        let f = match File::open("hello.txt") {
            Ok(file) => file,
            Err(e) => match error.kind() {
                ErrorKind::NotFound => match File::create("hello.txt") {
                    Ok(fc) => fc,
                    Err(e) => panic!("Problem creating the file: {:?}", e),
                },
                other_error => panic!("Problem opening the file: {:?}", other_error)m
            },
        };
    }
    ```


### Data


Variable declarations are called **bindings** in Rust, and by convention variable names are in **snake_case** (lower-case letters with words delimited by `_`).
They are globally scoped by default unless they are declared in a code block.

Variables are immutable by default, so if their values are to change they must be marked with `mut`.
However, immutable variables are distinct from constants declared using `const`, which cannot be made mutable at all.
`const` identifiers are conventionally written in capitalized snake_case.

=== "Immutable"

    ```rs
    let language = "&nbsp;";
    ```

=== "Mutable"

    ```rs
    let mut language = "&nbsp;";
    ```

=== "Constant"

    ```rs
    const language = "&nbsp;";
    ```

Data type is explicitly specified on initialization after colon, and this same syntax is used to type function parameters and return types:

```rs
let language: String = "&nbsp;";
```

A special **`!`** type indicates that the function never returns

```rs
// RIA p. 78
fn read(f: &mut File, save_to: &mut Vec<u8>) -> ! {
    unimplemented!();
}
```

Numbers can be typed by appending the data type to the value itself. Digits can be separated with **`_`**

```rs
let x = 255i8;
let y = 1_024_i16;
```

Because implicit integer conversions are a well-known source of bugs and security holes, conversion must be explicit using the **as** keyword:
```rs
do_something(x as i32);
```

Common mathematical calculations are implemented as methods, which can be called directly on variables or literals or as associated functions of the type:

```rs
let x = (4.5_f64).floor()

let y = 4.0_f64;
let z = y.sqrt();

let a = f64::sqrt(4.0);
```

Common constants can be found in each type's **consts** module, i.e. **std::f32::consts**.
Other values like `MIN`, `MAX`, `INFINITY`, `NEG_INFINITY`, and `NAN` (not-a-number) are also implemented as consts.

**Shadowing** and **masking** are terms that refer to using a locally scoped variable with the same identifier as a global variable.
When in the local variable's block, the local variable is said to be **masking** the global one, which conversely is **shadowing** the local.
Once the local scope is exited, the global variable's variable is accessible again and the local variable is destroyed.

Shadowing is used in the [Guessing Game coding task](../#guessing-game) to parse the input string as an integer.

Integers can be fixed-length or variable-length.
Fixed-size integers can be signed (`i`) or unsigned (`u`) and 8, 16, 32, or 64 bits: i.e. `i8`, `u64` etc.
Variable-size integers can be **pointer-sized signed** `isize` or **pointer-sized unsigned** `usize`, the size of both of which depend on the architecture of the host system.

Type can be inferred by the compiler or explicitly annotated after a colon

=== "Implicit"

    ```rs
    let var = 0;
    ```

=== "Explicit"

    ```rs
    let var:u8 = 0;
    ```

Arrays and Tuples are considered primitive data types, albeit **Compound** ones.
Integer and Float are considered **Numeric Scalars**, while Boolean and Chars are considered **Non-Numeric Scalars**.

- Floating point numbers can be single-precision `f32` or double-precision `f64`.
- Booleans are `true` or `false` (lower-case).

Arrays are **homogeneous** sequences of elements and must be of a fixed length, declared at initialization, although the type can be determined implicitly.

=== "Explicit"

    ```rs
    let arr:[i32; 4] = [0, 0, 0, 0];
    ```

=== "Implicit"

    ```rs
    let arr = [0 ; 4];
    ```

Array length can be given by the `len()` method.

Array slicing 

```rs
let arr:[i32;4] = [1, 2, 3, 4]; 
let slice_array2:&[i32] = &arr[0..2];
```

Tuples, like arrays, are fixed-length.
But unlike arrays they are **heterogeneous** sequences of elements.

Tuples can also be typed explicitly or implicitly

=== "Explicit"

    ```rs
    let person : (&str, i32, &str) = ("John", 35, "Doe");
    ```

=== "Implicit"

    ```rs
    let person = ("John", 35, "Doe");
    ```

Tuples can be **destructured** (i.e. unpacked)
```rs
let person = ("John", 35, "Doe");
let (fn, age, ln) = person;
```

Tuples **can** be made mutable with the `mut` keyword.

Rust's standard library includes a number of collections

- A [**vector**](#vector) stores a variable number of values of a single type in a sequence
- A [**String**](#string) is a collection of characters
- A **hash map** is a key-value store


#### Ownership

One of the key and unique features of Rust is the concept of **ownership**, which achieves memory safety without the use of a garbage collector.

The stack and heap are locations in memory that are available to the application at runtime.

- The **stack** is a LIFO that is used for sizes that are known at compile-time. Values are said to be "**pushed onto**" or "**popped off**" the stack.
- The **heap** is less organized and less efficient, and is used for sizes that are known only at runtime. The operating system must search for an appropriate memory location based on the application's request at runtime, returning a pointer, and this process makes the heap less efficient than the stack. Memory locations are said to be "**allocated**" on the heap. 

Some complex data types like `String` are composed of a pointer, stored in the stack because its size is known at compile-time, that points to a location on the heap that holds the String's contents, which are known only at runtime.

In other languages these statements would cause s2 to become a shallow copy of s1, pointing to the same location in memory where the String contents are stored.
However, ownership rules in Rust cause s1 to be invalidated because s2 becomes the owner of the data contents on the heap, and this is called a **move**.
```rs
let s1 = String::from("Hello, world!");
let s2 = s1;
println("{}", s1); // compiler error
```

This allows Rust to avoid the **double free** error caused by attempting to free the same memory location twice, which can cause corruption and security issues.
When the variable goes out of scope, its **backing memory** is freed.

A deep copy is still possible with the common `clone` method:

```rs
let s2 = s1.clone();
```

This behavior is only for data that is stored on the heap, not the stack.
The size of integers is known at compile-time, so they are stored entirely on the stack, and therefore copies of the values are efficiently made.

```rs
let x = 5;
let y = x;
println!("{}",x); // no error
```

More specifically, certain types have a special annotation called the **`Copy` [trait](#trait)** which enable this behavior.
For types that "are `Copy`" - i.e. have the `Copy` trait - an older variable is still usable after assignment.
`Copy` types include integers, booleans, chars, floats, and tuples containing only other `Copy` types.

Function calls also exhibit move behavior; after a variable is passed as argument to a function, the function owns it and it may not be used again in its original context unless ownership is returned.
If the value is not returned, the argument's contents are consumed and it may not be used again in the calling context.

This is why most function calls in Rust use [**references**](#references), prefixing the variable identifier with `&`, a process called **borrowing**.

Passing a value to a function while transferring ownership is called "passing by value" or a **move**, whereas using a reference is called "passing by reference".

=== "Passing by value"

    ```rs linenums="1" hl_lines="4"
    fn main() {
        let s = String::from("Dgiapusccu");
        hello_world(s);
        println!("Hello again, {}!", s); // compiler error
    }

    fn hello_world(s:String) {
        println!("Hello, {}!", s)

    }
    ```

=== "Returning value"

    ```rs linenums="1" hl_lines="3 9"
    fn main() {
        let s = String::from("Dgiapusccu");
        let s = hello_world(s);
        println!("Hello again, {}!", s);
    }

    fn hello_world(s:String) -> String {
        println!("Hello, {}!", s);
        s
    }
    ```

=== "By reference"

    ```rs linenums="1" hl_lines="3 7"
    fn main() {
        let s = String::from("Dgiapusccu");
        hello_world(&s);
        println!("Hello again, {}!", s);
    }

    fn hello_world(s:&String) {
        println!("Hello, {}!", s)

    }
    ```

#### References

Pointer types like [**`Box<T>`**](#box) and those internal to [String](#string) and [Vec](#vector) are **owning pointers**: when the owner is dropped the referent is deallocated.
Nonowning pointer types are called **references** and have no effect on their referents' lifetimes.

There are two types of reference:

- **Shared references** let you read but not modify the referent
Multiple shared references to the same value can be created.
- **Mutable references** allow both reading and modifying of the referent
To prevent **data races** only one mutable reference to a location in a scope can exist.

A mutable reference and an immutable one cannot coexist in the same scope.
Moves after a borrow are also forbidden, for this same reason.

Here, the call to `push()` causes the [vector](#vector) to be reallocated on the heap after an immutable borrow was made.
```rs
let mut data = vec![1, 2, 3];
let x = &data[0];
data.push(4);

println!("{}", x);
```

#### Lifetimes

Every reference must have a **lifetime**, which helps the compiler avoid *dangling references*, a known source of bugs and vulnerabilities.

The Rust compiler has a **borrow checker** that compares scopes to ensure that all scopes are valid.
But when a function has references to code from outside the function, it is impossible for Rust to determine the lifetimes of parameters or return values on its own.

Reference parameters must be annotated with **lifetime annotations** with an unusual syntax using a single single-quotation character **`'`** followed by a very short identifier, conventionally the letter **a**:
```rs
&i32        // immutable reference
&'a i32     // immutable reference with explicit lifetime
&'a mut i32 // mutable reference with explicit lifetime
```
However, lifetime annotations are only understood in a function signature where more than one is used. 

This example tells the compiler that the function takes two parameters and returns a value that all live at least as long as lifetime **`'a`**.
When concrete references are passed to this function, the smaller of the two concrete lifetimes passed in the arguments is substituted for the generic value:
```rs
fn do_something<'a>(x: &'a str, y: &'a str) -> &'a str { 
    // --snip--
}
```

The lifetime for the returned value must match that of one of the parameters. 
If not, the value would necessarily refer to a value created within the function, which would go out of scope at the end of the function and creating a dangling reference.

[Structs](#oop) that hold references must also hold lifetime annotations and cannot outlive the referenced values.
Function definitions also take the lifetime annotation on the `impl` keyword, i.e. `impl<'a>`

=== "struct"

    ```rs
    struct Starship<'a> {
        name: &'a str

    }

    fn main() {
        let name = "USS Enterprise";
        let enterprise = Starship{ name: &name };
        println!("{}", enterprise.name); // => "USS Enterprise"
    }
    ```

=== "method"

    ```rs
    struct Starship<'a> {
        name: &'a str,
        registry: &'a str,
    }

    impl<'a> std::fmt::Display for Starship<'a> {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            write!(f, "{} {}", self.name, self.registry)
        }
    }

    fn main() {
        let name = "USS Enterprise";
        let registry = "NCC-1701";
        let enterprise = Starship { name: &name , registry: &registry};
        println!("{}", enterprise); // => "USS Enterprise NCC-1701"
    }
    ```

### Collections

Accessing tuple elements is done with the **`.`** operator

``` rs
let coord: (i8, i8) = (10, 20);
println!("{}, {}", coord.0, coord.1);
```

## Paradigms

### OOP

Objects are implemented in Rust as `struct`s and `impl`s.

A group of methods that are shared by multiple types can have their signatures defined by a [**trait**](#trait).
Types then implement the trait, and functions can be defined that accept any type that does so by specifying the trait instead of a single concrete type.

```rs
pub fn notify(item: impl Summary) {
    println!("Breaking news! {}", item.summarize());
}
```


### TDD

Tests are functions annotated with the `#[test]` [**attribute**](#attribute).
Tests fail when the test function panics.

```rs
#[test]
fn math_works() {
    assert_eq!(2+2, 4);
}

#[test]
fn fails() {
    panic!("This test will fail");
}
```

Tests can also be incorporated in documentation as markdown code blocks.

---8<-- "includes/Coding/Rust/Starships/1/starship.rs.md"

## 📘 Glossary

**associated type**{: #associated-type }
:   
    Associated types connect a type placeholder with a trait such that the trait method definitions use these placeholder types in their signatures.

    With generics, we must annotate the types in **each** implementation,
    but using an associated type forces a **single** implementation.

    === "Associated type"

        ``` rs hl_lines="2"
        pub trait Iterator {
            type Item;

            fn next(&mut self) -> Option<Self::Item>;
        }
        ```

    === "Generic"

        ``` rs
        pub trait Iterator<T> {
            fn next(&mut self) -> Option<T>;
        }
        ```

#### Attribute
:   
    metadata that decorates code.

    - **`#![allow(unused_variables)]`** suppresses compiler warnings
    - **`#[allow(dead_code)`** suppresses compiler warnings about unused functions
    - **`#[derive(Debug)]`** etc.
    - `#[cfg(test)]`
    - `#[test]`
    - `#[ignore]`

#### `Box<T>`
:   
    The most straightforward and commonly used [smart pointer](#smart-pointer), allowing data to be stored on the heap rather than the stack.

    ``` rs
    let b = Box::new(5);
    ```

    Boxes can be dereferenced just like references.

    === "Box"

        ```rs hl_lines="2"
        let x = 5;
        let y = Box::new(x);
        assert_eq!(5, *y);
        ```

    === "Reference"

        ```rs
        let x = 5;
        let y = &x;
        assert_eq!(5, *y);
        ```

#### Closure
:   
    Closures are anonymous functions that can be saved in a variable or passed as arguments to functions.
    Closure definitions in Rust use pipe characters `|` to enclose the parameter list, followed by a code block. 
    Because this code block is placed on the right side of a variable assignment statement, the closing curly bracket is followed by a semicolon.
    Type annotations are optional with closures because the compiler is typically able to infer type information from the context.

    === "Closure"
    
        ``` rs
        let do_stuff = |arg| {
            // ...
        };
        ```

    === "Function"

        ``` rs
        fn do_stuff(arg: u8) -> u32 {
            // ...
        }
        ```
    
    This variable is then called like a function.
    ```rs
    do_stuff("bla");
    ```

    Compute-expensive closures can be memoized by placing them in a struct that caches the resulting value:

    ``` rs
    struct Cacher<T>
        where T: Fn(u32) -> u32 {
            calculation: T,
            value: Option<u32>,
        }
    
    impl<T> Cacher<T>
        where T: Fn(u32) -> u32
    {
        fn new(calculation: T) -> Cacher<T> {
            Cacher {
                calculation,
                value: None,
            }
        }

        fn value(&mut self, arg: u32) -> u32 {
            match self.value {
                Some(v) => v,
                None => {
                    let v = (self.calculation)(arg);
                    self.value=Some(v);
                    v
                }
            }
        }
    }
    ```
    
    Closures can access variables from their **environment**, or enclosing scope, something which functions are forbidden to do.

    Here, the compiler will raise an error when using the function and suggest the closure form in the error message.

    === "Function"

        ```rs
        fn main() {
            let x = 4;

            fn equal_to_x(z: i8) -> bool { z == x }

            let y = 4;

            assert!(equal_to_x(y));
        }
        ```
    
    === "Closure"

        ```rs
        fn main() {
            let x = 4;

            let equal_to_x(z: i8) = |z| z == x;

            let y = 4;

            assert!(equal_to_x(y));
        }
        ```

    The **`move`**{: #move } [:material-language-rust:](https://doc.rust-lang.org/std/keyword.move.html) keyword makes a closure take ownership of all captured variables

    Here, using `move` produces a compile-time error because `println!()` attempts to borrow x after it is moved in the closure definition.
    Commenting this line removes the error.

    === "`move`"

        ```rs hl_lines="3 4"
        fn main() {
            let x = vec![1, 2, 3];
            let equal_to_x = move |z| z == x;
            println!("can't use x here: {:?}", x);
            let y = vec![1, 2, 3];
            assert!(equal_to_x(y));
        }
        ```

    === "Without `move`"

        ```rs
        fn main() {
            let x = vec![1, 2, 3];
            let equal_to_x = |z| z == x;

            let y = vec![1, 2, 3];
            assert!(equal_to_x(y));
        }
        ```

**crate**{: #crate}
:   
    A crate is a component of a package which produces a library or executable.

    There are two types of crate:

    - **Library crates**, of which there may at most one in a package
    - **Binary crates**, of which there may be many in a package

    The **crate root** is the source file that the compiler uses to create the root module of the crate.

**Custom derive**{: #custom-derive } 
:   
    One of the three types of [**macro**](#macro) in Rust that specifies code added with the `derive` [**attribute**](#attribute).

    Feature where the default implementation of a [trait](#trait) is generated by annotating a struct with an [attribute](#attribute).

    Here, `#[derive(Debug)]` supports the use of the `{:?}` placeholder for pretty-printing.

    ```rs
    #[derive(Debug)]
    struct Starship {
        name: String,
        registry: String,
        crew: i16,
        captain: Officer,
        class: StarshipClass,
    }
    ```

#### `dbg` [:material-language-rust:](https://doc.rust-lang.org/std/macro.dbg.html)
:   

    !!! info "&nbsp;"

        Not to be confused with the [Debug trait](#trait), which is used with the normal [`println!()` macro](#macro)!

    Allows evaluation and printing of expressions during debugging or running with `cargo run`.

    === "Code"

        ```rs
        fn main() {
            let mut a:i32 = 0;
            while a < 100 {
                a += 1;
                dbg!(a);
            }
            println!("Done");
        }
        ```

    === "Output"

        ```
        [src/main.rs:5] a = 1
        [src/main.rs:5] a = 2
        [src/main.rs:5] a = 3
        [src/main.rs:5] a = 4
        ...
        ```

#### `enum`
:   
    The **variants** of an enum can have different types and associated data.

    ```rs
    enum IpAddr {
        V4 ( u8, u8, u8, u8 ),
        V6(String)
    }
    ```

#### `HashMap`
:   
    ```rs
    use std::collections::HashMap;

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 20);
    ```

    Hash maps are homogeneous: all keys must be of one type and all values of another.
    A hash map can be zipped from two vectors:

    ```rs
    use std::collections::HashMap;

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10,50];

    let scores:HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();
    ```
    For non-Copy types, the hash map becomes the new owner of data values on assignment.



#### `if let`
:   
    **`if let`** is syntactic sugar for a pattern that matches one pattern while ignoring the rest.
    Notably, the syntax takes the pattern before the expression similar to a [`match`](#match) arm.
    
    === "if let"

        ``` rs
        if let Some(3) = some_u8_value {
            println!("three");
        }
        ```
    
    === "Naive"

        ``` rs
        let some_u8_value = Some(0u8);
        match some_u8_value {
            Some(3) => println!("three"),,
            _ => (),
        }
        ```

#### Iterator
:   
    The **iterator pattern** is one that allows logic to be performed on a sequence of items in turn.

    An **iterator** in Rust is anything that implements the **`Iterator`** [trait](#trait).
    This trait only requires implementation of a single method: `next()`, which returns one item of the iterator at a time wrapped in `Some` and `None` when the iterator is consumed.
    
    Many types return an iterator by calling the **`iter()`** method, which can then be iterated over using a **`for .. in`** loop.
    Alternatively, the `next()` method can be called directly.

    === "Loop"

        ```rs
        let v1 = vec![1, 2, 3];

        for i in v1.iter() {
            println!("{}", i);
        }
        ```

    === "`next()`"

        ```rs
        let v1 = vec![1, 2, 3];
        let v1_iter = v1.iter();

        assert_eq!(v1_iter.next(),Some(&1));
        assert_eq!(v1_iter.next(),Some(&2));
        assert_eq!(v1_iter.next(),Some(&3));
        assert_eq!(v1_iter.next(),None);
        ```

    Other methods are defined on the Iterator trait.
    
    - **Consuming iterators** are those that call `next()`: 
        - **`sum`**{: #sum }
        - **`collect`** [:material-language-rust:](https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.collect) transforms an iterator into a collection
    - **Iterator adapters** change iterators into different kinds of iterators:
        - **`map`**{: #map } [:material-language-rust:](https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.map)
        - **`filter`**{: #filter } [:material-language-rust:](https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.filter)

    === "sum"

        ```rs hl_lines="4"
        fn iterator_sum() {
            let v1 = vec![1, 2, 3];

            let total: i32 = v1.iter().sum();
            assert_eq!(total, 6);
        }
        ```

    === "map"

        ```rs hl_lines="3"
        fn main() {
            let v1 = vec![1, 2, 3];
            let v2 : Vec<_> = v1.iter().map(|x| x + 1).collect();
            let total: i32 = v2.iter().sum();
            println!("{}", total);
        }
        ```



#### macro
:   
    Referring to a family of features in Rust:

    - **Declarative** macros with `macro_rules!`
    - **procedural macros**:
        - [**Custom `#[derive]`**](#custom-derive) macros that specify code added with the `derive` attribute used on structs and enums
        - **[Attribute](#attribute)-like** macros that define custom attributes usable on any item
        - **Function-like** macros that look like function calls but operate on the tokens specified as their argument

  - `assert` [:material-language-rust:](https://doc.rust-lang.org/std/macro.assert.html) invokes `panic` if the provided expression cannot be evaluated to true at runtime
  - [`dbg`](#dbg)
  - `panic` [:material-language-rust:](https://doc.rust-lang.org/std/macro.panic.html) terminates the program with code 101 and should be used when the program reaches an unrecoverable state
  - `println`
  - `unimplemented` [:material-language-rust:](https://doc.rust-lang.org/core/macro.unimplemented.html)

#### `match`
:   
    **`match`** is a powerful control flow operator that resembles a `switch` statement.
    `match` works on integers, ranges of integers, bools, enums, tuples, arrays, and structs.
    `match` allows a value to be compared against a series of patterns, which can be literal values as well as numerous other things.
    Each pattern is within a `match` **arm**, which is composed of the pattern and some code, here an expression.

    Recursive Fibonacci sequence implementation:

    === "if/else"

        ```rs linenums="1"
        const FIB_ZERO: u64 = 1;
        const FIB_ONE: u64 = 1;

        fn fib(n: u64) -> u64 {
            if n == 0 {
                FIB_ZERO
            } else if n==1 {
                FIB_ONE
            } else {
                fib(n-1) + fib(n-2)
            }
        }

        fn main() {
            let n: u64 = std::env::args().nth(1).unwrap().parse().unwrap();
            for i in 1..n {
                println!("{}: {}", i, fib(i));
            }
        }
        ```

    === "`match`"

        ```rs linenums="1" hl_lines="4-10"
        const FIB_ZERO: u64 = 1;
        const FIB_ONE: u64 = 1;

        fn fib(n: u64) -> u64 {
            match n {
                0 => FIB_ZERO,
                1 => FIB_ONE,
                _ => fib(n-1) + fib(n-2)
            }
        }



        fn main() {
            let n: u64 = std::env::args().nth(1).unwrap().parse().unwrap();
            for i in 1..n {
                println!("{}: {}", i, fib(i));
            }
        }
        ```

    Patterns can also bind to parts of the values that match the pattern.

    === "Simple enum"

        ```rs linenums="1"
        enum Coin {
            Penny,
            Nickel,
            Dime,
            Quarter
        }







        fn value_in_cents(coin: Coin) -> u8 {
            match coin {
                Coin::Penny => 1,
                Coin::Nickel => 5,
                Coin::Dime => 10,
                Coin::Quarter => 25,



            }
        }
        ```

    === "Nested enum"

        ```rs linenums="1" hl_lines="5 8-12 19-22"
        enum Coin {
            Penny,
            Nickel,
            Dime,
            Quarter(UsState)
        }

        enum UsState {
            Alabama,
            Alaska,
            // --snip--
        }

        fn value_in_cents(coin: Coin) -> u8 {
            match coin {
                Coin::Penny => 1,
                Coin::Nickel => 5,
                Coin::Dime => 10,
                Coin::Quarter => {
                    println!("State quarter from {:?}!", state);
                    return 25;
                }
            }
        }
        ```

    In this example, the match statement only announces when a `Coin::Quarter(state)` is encountered, but all other cases are handled by the placeholder `_`.
    The `if let` syntax is equivalent:

    === "match"

        ```rs
        let mut count = 0;
        match coin {
            Coin::Quarter(state) => println!("State quarter from {:?}!", state),
            _ => count += 1,
        }
        ```

    === "if let"

        ```rs
        let mut count = 0;
        if let Coin::Quarter(state) = coin {
            println!("State quarter from {:?}!", state);
        } else {
            count += 1;
        }
        ```

#### `Option<T>`
:   
    Rust doesn't have the same implementation of null values that other languages do because handling null values is complicated and when unexpected they cause bugs.
    Rather than null values, Rust implements null as a variant **`None`** of the enum **`Option<T>`**
    ```rs
    enum Option<T> {
        Some(T),
        None
    }
    ```

    The reason for this is because Rust conventionally handles enums in a [`match`](#match) statement, which requires **exhaustive** enumeration of all possible cases.
    The compiler itself will raise an error if you compose a match statement which leaves some potential cases unhandled.

#### `Result<T,E>`
:   
    Appears to be similar to [**`Option<T>`**](#optiont), in that it is a generic meant to wrap other values..

    ```rs
    enum Result<T, E> {
        Ok(T),
        Err(E),
    }
    ```

    The `?` operator is similar to using a [`match()`](#match) expression in that the value inside the `Ok` or `Err` enums is returned to the calling code. 
    But error values that have `?` called on them go through the `from` function, defined in the `From` [trait](#trait) in the standard library.
    This operator is used to avoid boilerplate code.

    === "With `?`"

        ```rs
        use std::io;
        use std::io::Read;
        use std::fs::File;

        fn read_username_from_file() -> Result<String, io::Error> {
            let mut s = String::new();
            File::open("hello.txt")?.read_to_string(&mut s)?;
            Ok(s)
        }
        ```

    === "Naive"

        ```rs hl_lines="6-10 13-16"
        use std::io;
        use std::io::Read;
        use std::fs::File;

        fn read_username_from_file() -> Result<String, io::Error> {
            let mut f = File::open("hello.txt");
            let mut f = match f {
                Ok(file) => file,
                Err(e) => return Err(e),
            };

            let mut s = String::new();
            match f.read_to_string(&mut s) {
                Ok(_) => Ok(s),
                Err(e) => Err(e),
            }
            Ok(s)
        }
        ```

    Helper methods:

    - [`expect()` :material-language-rust:](https://doc.rust-lang.org/std/result/enum.Result.html#method.expect) returns the contained `Ok` value or panics with the provided error message.
    - [`unwrap()` :material-language-rust:](https://doc.rust-lang.org/std/result/enum.Result.html#method.unwrap) returns the contained `Ok` value or panics.
    - [`unwrap_or_else()` :material-language-rust:](https://doc.rust-lang.org/std/result/enum.Result.html#method.unwrap_or_else) returns the contained `Ok` value or computes it from a [closure](#closure).

**Smart pointer**{: #smart-pointer }
:   
    Smart pointers are data structures that act like references but provide additional functionality and metadata.
    The smart pointer pattern is used frequently in Rust.

    In Rust, smart pointers are structs that implement two [traits](#trait):
    
    - **`Deref`**{: #deref } allows an instance of the smart pointer struct to behave like a reference
    - **`Drop`** allows you to run custom logic when the pointer goes out of scope

    === "MyBox"

        ``` rs
        struct MyBox<T>(T) {
            data: String,
        }

        impl<T> MyBox<T> {
            fn new(x: T) -> MyBox<T> {
                MyBox(x)
            }
        }
        ```

    === "Deref"

        ``` rs
        impl<T> std::ops::Deref for MyBox<T> {
            // Define an **associated type** for the Deref trait to use
            type Target = T; 

            fn deref(&self) -> &T {
                &self.0
            }
        }
        ```

    === "Drop"

        ``` rs
        impl<T> Drop for MyBox<T> {
            fn drop(&mut self) {
                println!("Dropping MyBox");
            }
        }
        ```

    Now the smart pointer supports the dereferencing operator `*` and a message is displayed when it goes out of scope.

    ``` rs hl_lines="4"
    fn main() {
        let x = 5;
        let y = MyBox::new(x);
        assert_eq!(5, *y);
    }
    ```

    Behind the scenes, the compiler is really dereferencing the value returned by `deref()`:

    ``` rs
    *(y.deref())
    ```

    The `drop()` method may not be called explicitly in order to avoid the **double free** error that would occur when the variable goes out of scope.
    Alternatively, `std::mem::drop()` (already in the prelude) can be called explicitly.
    
    ``` rs
    drop(y);
    ```

    Other smart pointers in the standard library include:

    - **`Rc<T>`**w hich enables multiple owners of the same data and is used to count references, but only in single-threaded contexts
    - **`RefCell<T>`** which enforces borrowing rules but only at runtime

#### String
:   
    The **String** type provided by Rust's standard library is implemented as a series of bytes and is distinct from **string slices** (**`&str`**) which are implemented in the core language.

    Strings can be initialized with the `new()` method just like [vectors](#vector).

    String slices expose a `to_string()` method for conversion to a String.
    Alternatively, you can use `String::from()` to convert a string slice to a string.


    === "to_string"

        ```rs
        let s = "initial contents".to_string();
        ```

    === "String::from()"

        ```rs
        let s = String::from("initial contents");
        ```

    Mutable strings can be concatenated with the `push_str()` method or with the `+` operator, which results in a [move](#ownership) of the left operand and requires a reference for the right operand.
    The `format!` macro, which returns a String, is also available for more complicated concatenations.

    === "push_str"

        ```rs
        let mut s = String::from("Hello, ");
        s.push_str("world!");
        ```

    === "`+` operator"

        ```rs
        let s1 = String::from("Hello, ");
        let s2 = String::from("world!");
        let s = s1 + &s2;
        ```

    Strings do not support indexing because they do not have the `std::ops::Index` [trait](#trait).
    However, the `chars()` method returns an iterator that can be looped:

    ```rs
    for c in "Hello, world!".chars() {
        println!("{}", c);
    }
    ```

    String slices can be generated from Strings using **slice operator**{: #slice } **`..`**, which is equivalent to the `:` operator in languages like Python.

    !!! rs "&nbsp;"

        ```rs
        let s = String::from("Hello, world!");
        let w1 = s[..5]; // equivalent to s[0..5]
        let w2 = s[7..]; // equivalent to s[7..len]
        ```

    ??? py "&nbsp;"

        ```py
        s = "Hello, world!"
        w1 = s[:5]
        w2 = s[7:]
        ```

    Because the compiler implicitly converts String to `&str`, as a practical matter functions that accept strings should be refactored to accept string slices.

    Strings must be initialized with the constructor.
    In the following example, for some reason, the compiler produces a "borrow after move" error if the constructor is not called.
    This might be because without the constructor, the `Copy` [trait](#trait) is not implemented in the initialized object.

    === "Compiler error"

        ```rs linenums="1" hl_lines="5"
        fn main() {
            let mut v: Vec<String> = Vec::new();
            
            loop {
                let mut input: String;
                println!("Enter to-do list item ('q' to quit): ");
                std::io::stdin().read_line(&mut input).unwrap();
                match input.trim() {
                    "q" => break,
                    s => v.push(s.trim().to_string()),
                }
            }
            for i in v {
                println!("{}", i);
            }
        }
        ```

    === "No error"

        ```rs linenums="1" hl_lines="5"
        fn main() {
            let mut v: Vec<String> = Vec::new();
            
            loop {
                let mut input: String = String::new();
                println!("Enter to-do list item ('q' to quit): ");
                std::io::stdin().read_line(&mut input).unwrap();
                match input.trim() {
                    "q" => break,
                    s => v.push(s.trim().to_string()),
                }
            }
            for i in v {
                println!("{}", i);
            }
        }
        ```

    String methods:

    - **`push_str`** [:material-language-rust:](https://doc.rust-lang.org/std/string/struct.String.html#method.push_str) append a string slice
    - **`lines`** [:material-language-rust:](https://doc.rust-lang.org/std/string/struct.String.html#method.push_str) returns an iterator of string slices

#### Trait
:   
    A trait defines functionality that can be shared with many types in a way that recalls dunder methods in Python.
    
    For example, default output to the terminal is implemented in the **Display** trait.
    A Rust Display object will output text to stdout using `println!()` in the same way that a Python object with the **`__str__`** method defined will output text when using `print()`.

    !!! rs "Display"

        ```rs
        struct Starship<'a> {
            // --snip--
        }

        impl<'a> std::fmt::Display for Starship<'a> {
            fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
                write!(f, "{} {}", self.name, self.registry)
            }
        }

        fn main() {
            let enterprise = Starship::new();
            println!(enterprise);
        }
        ```

    !!! py "`__str__`"

        ```py
        class Starship:
            def __init__(self):
                # --snip--
            def __str__(self):
                return f"{self.name} {self.registry}"
        
        def main():
            enterprise = Starship()
            print(enterprise)
        ```

    A trait defines the signature of a method intended to be implemented by many types, similar to virtual methods or interfaces.

    The syntax of a trait definition looks similar to the signature of a function with no code block.
    Traits are implemented in `impl` blocks that specify the type.
    **Default implementations** of a trait can be provided in the trait definition.

    === "Simple definition"

        ```rs
        pub trait Summary {
            fn summarize(&self) -> String;

        }
        ```

    === "Default"

        ```rs
        pub trait Summary {
            fn summarize(&self) -> String {
                String::from("(Read more...)");
            }
        }
        ```

    === "Implementation"

        ```rs
        impl Summary for NewsArticle {
            fn summarize(&self) -> &str {
                format!("{}, by {} ({})", self.headline, self.author, self.location);
            }
        }
        ```

    Common traits:

    - `Copy`
    - [`Deref`](#deref)
    - [`Drop`](#drop)
    - `Display`
    - `Fn`
    - [`Iterator`](#iterator)

**trait bound**{: #trait-bound}
:   
    A trait bound allows functions to accept any type that implements a trait. 
    Multiple traits by delimiting trait names with `+`.
    A simpler syntax accommodates simple cases by specifying the `impl` keyword followed by the trait name, rather than a concrete type.

    === "Trait bound"

        ```rs
        pub fn notify<T: Summary>(item: T) { // ...
        pub fn notify<T: Summary + Display>(item: T) { // ...
        ```

    === "Syntactic sugar"

        ```rs
        pub fn notify(item: impl Summary) { // ...
        pub fn notify(item: impl Summary + Display) { // ...
        ```

    Multiple trait bounds can clutter the function signature, reducing legibility.
    In these cases, a `where` clause can be used:

    ```rs
    fn some_function<T, U>(t: T, u: U) -> i32
        where T: Display + Clone,
              U: Clone + Debug
    { // ...
    ```

    The `impl Trait` syntax is also available for return values:

    ```rs
    fn returns_summarizable() -> impl Summary { // ...
    ```

#### Vector
:   
    A vector can be built using the `vec` macro or by instantiating it and adding elements with the `push()` method.

    ```rs
    let v = vec![1, 2, 3];

    let mut v = Vec::new();
    v.push(1);
    v.push(2);
    v.push(3);
    ```

    Referencing elements can be done with the index operator, which panics on an invalid index, or the `get()` method, which returns [`None`](#optiont) without panicking.

    ```rs
    let invalid = &v[100];

    let invalid = v.get(100);
    ```

    The `for .. in` loop works well with a vector.
    If vector elements are going to be changed, the reference must be made mutable and the **dereference operator** must be used.

    === "Immutable"

        ```rs
        let v = vec![100, 32, 57];
        for i in &v {
            println!("{}", i);
        }
        ```

    === "Mutable"

        ```rs
        let v = vec![100, 32, 57];
        for i in &mut v {
            *i += 50;
        }
        ```

    Although a vector's elements must be of the same type, because [enum](#enum) variants can be associated with a type and value they can be combined with [`match()`](#match) to create collections with many types.

    ```rs
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String)
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ]
    ```

    **Vector methods:**{: #vector-methods }

    - **reserve** [:material-language-rust:](https://doc.rust-lang.org/std/vec/struct.Vec.html#method.reserve) reserves space in memory for more elements, greater than or equal to `self.len()` + argument (`usize`)

## Projects

### To-Do

=== "1a"

    ```rs hl_lines="6"
    fn main() {
        let mut v: Vec<String> = Vec::new();


        loop {
            let mut input: String = String::new();
            println!("Enter to-do list item ('q' to quit): ");
            std::io::stdin().read_line(&mut input).unwrap();
            match input.trim() {
                "q" => break,
                s => v.push(s.trim().to_string()),
            }

        }
        for i in v {
            println!("{}", i);
        }
    }
    ```

    A simple [String](#string) [Vector](#vector) in a loop.

    Note that `read_line()` must take a [String](#string) argument passed by mutable [reference](#references) - i.e. a [borrow](#ownership).

    Here the `input` variable is instantiated and destroyed in each iteration of the loop.
    
=== "1b"


    ```rs hl_lines="3 13"
    fn main() {
        let mut v: Vec<String> = Vec::new();
        let mut input: String = String::new();

        loop {

            println!("Enter to-do list item ('q' to quit): ");
            std::io::stdin().read_line(&mut input).unwrap();
            match input.trim() {
                "q" => break,
                s => v.push(s.trim().to_string()),
            }
            input.clear();
        }
        for i in v {
            println!("{}", i);
        }
    }
    ```

    Alternatively, `input` can be instantiated before the loop, but it must be cleared with every iteration. 
    Otherwise, `read_line()` will continue to append data.


### Fibonacci

=== "Recursive"

    ```rs
    use std::collections::HashMap;

    fn fib(n: u64) -> u64 {
        match n {
            0 | 1 => 1,
            n => fib(n - 1) + fib(n - 2)
        }
    }

    fn main() {
        let n: u64 = std::env::args().nth(1).unwrap().parse().unwrap();
        for i in 1..n {
            println!("{}: {}", i, fib(i));
        }
    }
    ```

=== "Memoized"

    ```rs
    use std::collections::HashMap;

    fn fib(n: u64, map: &mut HashMap<u64, u64>) -> u64 {
        match n {
            0 | 1 => 1,
            n => {
                if map.contains_key(&n) {
                    *map.get(&n).unwrap()
                } else {
                    let val = fib(n-1, map) + fib(n-2, map);
                    map.insert(n, val);
                    val
                }
            }
        }
    }

    fn main() {
        let n: u64 = std::env::args().nth(1).unwrap().parse().unwrap();
        let mut map = HashMap::new();
        for i in 1..n {
            println!("{}: {}", i, fib(i, &mut map));
        }
    }
    ```

### Server

=== "1"

    === "main.rs"

        --8<-- "includes/Coding/Rust/Server/1/main.rs.md"

    The Server can be started from a humble struct

=== "2"

    === "main.rs"

        --8<-- "includes/Coding/Rust/Server/2/main.rs.md"

    Add another struct to represent the Request object, and define the available HTTP verbs

=== "3"

    
    === "main.rs"

        --8<-- "includes/Coding/Rust/Server/3/main.rs.md"

    Accommodate the possibility that the Request object's `query_string` may be null (`None`) by changing its type to `Object<String>`

=== "4"

    
    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/4/server.rs.md"

    ===  "main.rs"
        --8<-- "includes/Coding/Rust/Server/4/main.rs.md"

    === "http/"

        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/4/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/4/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/4/http/request.rs.md"

    Organize code into modules. 

    - **Server** is placed into a server module as a file.
    - **Method** and **Request** are made into modules that are then nested into the **http** module as files in a folder. 
    **mod.rs** not only is necessary for folder-style modules, but it also raises its constituent modules with the `use` statements, which remove the need to specify the submodules.

=== "5"

    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/5/server.rs.md"

    === "main.rs"
        --8<-- "includes/Coding/Rust/Server/5/main.rs.md"

    === "http/"
        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/5/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/5/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/5/http/request.rs.md"

    Implement a **TCPListener** object from the **net** module.

=== "6"
    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/6/server.rs.md"

    === "main.rs"
        --8<-- "includes/Coding/Rust/Server/6/main.rs.md"

    === "http/"
        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/6/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/6/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/6/http/request.rs.md"

    Handle the [result](#resultte) object returned by the `TcpListener::bind` method

=== "7"
    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/7/server.rs.md"

    === "main.rs"
        --8<-- "includes/Coding/Rust/Server/7/main.rs.md"

    === "http/"
        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/7/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/7/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/7/http/request.rs.md"

    Complete the main event loop.

    - The listener object also returns a result object. The listener's `accept()` method returns a tuple of values, including a **stream** object. 
    - The stream object, in turn, exposes a `read()` method that takes an empty array as buffer and also returns a result object. 
    - `String::from_utf8_lossy()` takes a slice (reference) to the buffer and attempts to parse the data that was placed within it as UTF-8, failing silently.
    The server will now accept TCP connections and display text sent via [**netcat**](/Linux/Network#netcat)
    ```sh
    echo "Hello, world!" | netcat localhost 8080
    ```

=== "8"
    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/8/server.rs.md"

    === "main.rs"
        --8<-- "includes/Coding/Rust/Server/8/main.rs.md"

    === "http/"
        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/8/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/8/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/8/http/request.rs.md"

    Convert the byte array to a Request.

    - Instead of defining a specific function in the Request implementation, we can use the the **TryFrom** trait from the **convert** standard library module. Traits are powerful because they allow you to extend standard types.
    - Because the TryFrom implementation is generic, the reference to the buffer must be passed as a slice of the entire array. Alternatively, we can use the automatically implemented **TryInto** trait in the server module.
    ```rs
    let res: &Result<Request, _> = &buffer[..].try_into();
    ```
    - The **crate** keyword allows access to the root of the project's namespace for importing the Request object.

=== "9"
    === "server.rs"
        --8<-- "includes/Coding/Rust/Server/9/server.rs.md"

    === "main.rs"
        --8<-- "includes/Coding/Rust/Server/9/main.rs.md"

    === "http/"
        === "mod.rs"
            --8<-- "includes/Coding/Rust/Server/9/http/mod.rs.md"
        === "method.rs"
            --8<-- "includes/Coding/Rust/Server/9/http/method.rs.md"
        === "request.rs"
            --8<-- "includes/Coding/Rust/Server/9/http/request.rs.md"


    Create a **ParseError** custom error type as an enum and implement the **Error** trait for it. This trait requires the Debug and Display traits as well.
    ```rs
    pub trait Error: Debug + Display {}
    ```
    These traits implement are formatters for use in the `println()` macro: Display is the default formatter most commonly used. Debug can be selected by placing the **debug formatter** `:?` within the placeholder of the template. Debug is also used in the **dbg!()** macro.
    ```rs
    println!("{:?}", String::from("Hello, world!"));
    ```
    This finally allows us to change the Error type in TryFrom to our newly-defined ParseError.

### Starships

=== "1"


    ---8<-- "includes/Coding/Rust/Starships/1/lib.rs.md"

    - Using the Debug [trait](#trait), any Starship or Officer object can be pretty-printed.
    - An example in the [doc comments](#documentation) can be run as a test case by running `cargo test`


=== "2"


    === "lib.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/lib.rs.md"

    === "starship.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/starship.rs.md"

    === "officer.rs"

        ---8<-- "includes/Coding/Rust/Starships/2/officer.rs.md"

### Emulator

    === "1"

        ```rs
        struct CPU {
            current_operation: u16,
            registers: [u8; 2],
        }
        ```


## grep ports

Porting grep to Rust provides the opportunity to explore various ways of using  [iterators](#iterator), evolving from a naive `for in` loop to the [**`filter()`**](#filter) iterator method using a [closure](#closure).

=== "Loop"

    ```rs

    fn main() {
        let mut results = Vec::new();

        for line in contents.lines() {
            if line.contains(query) {
                results.push(line);
            }
        }
        results
    }
    ```

=== "Filter"

    ```rs
    fn main() {


        contents.lines()
            .filter(|line| line.contains(query))
            .collect()
    }
    ```

### grep-lite

--8<-- "includes/Coding/Rust/grep/grep-lite.md"

### minigrep

--8<-- "includes/Coding/Rust/grep/minigrep.md"
