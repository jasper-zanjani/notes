**Associated type**{: #associated-type }
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

    ```rs
    #![allow(unused_variables)] // suppress compiler warnings about unused variables
    #[allow(dead_code)          // unused functions
    #[derive(Debug)]
    #[cfg(test)]
    #[test]
    #[ignore]

    #[structopt(default_value = "World")] // set a default value for a field
    ```

#### Box
:   
    The most straightforward and commonly used [smart pointer](#smart-pointer), allowing data to be stored on the heap rather than the stack.
    Boxes can be dereferenced just like references.

    ```rs hl_lines="2"
    let x = 5;
    let y = Box::new(x); // Equivalent to: let y = &x;
    assert_eq!(5, *y);
    ```

#### Cell
:   
    [**`Cell<T>`**](https://doc.rust-lang.org/std/cell/struct.Cell.html) is a [smart pointer](#smart-pointer) that allows mutation inside an immutable struct ("interior mutability").

    To access the referenced value, unlike other pointers it does not take the dereferencing operator **`*`** but exposes various getter and setter methods such as **get()**, **set()**, etc.

    ``` rs hl_lines="5 7"
    use std::cell::Cell;

    fn main() {
        let num: i8 = 20;
        let cell: Cell<i8> = Cell::new(num);
        println!("Value of number: {}", num);
        println!("Value of cell:   {}", cell.get());
    }
    ```

    Immutable structs can be made partially mutable using Cells.
    In this example, the crew value is changed despite the fact that the object is immutable.
    Cell is used less often than the similar [RefCell](#refcell)

    === "Cell"

        ``` rs hl_lines="1 7 14 17"
        use std::cell::Cell;

        #[derive(Debug)]
        struct Starship {
            name: String,
            registry: String,
            crew: Cell<i16>
        }

        fn main() {
            let enterprise = Starship { 
                name : "USS Enterprise".to_string(), 
                registry : "NCC-1701".to_string(), 
                crew : Cell::new(400)
            };
            dbg!(&enterprise);
            enterprise.crew.set(405);
            dbg!(&enterprise);
        }
        ```

    === "RefCell"

        ``` rs hl_lines="1 7 14 17"
        use std::cell::RefCell;

        #[derive(Debug)]
        struct Starship {
            name: String,
            registry: String,
            crew: RefCell<i16>
        }

        fn main() {
            let enterprise = Starship { 
                name : "USS Enterprise".to_string(), 
                registry : "NCC-1701".to_string(), 
                crew : RefCell::new(400)
            };
            dbg!(&enterprise);
            *enterprise.crew.borrow_mut() = 405;
            dbg!(&enterprise);
        }
        ```



#### Clap
:   
    [Clap](https://docs.rs/clap/) is a CLI framework.

    Also see [structopt](#structopt).

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

**Crate**{: #crate}
:   
    A crate is a component of a package which produces a library or executable.

    There are two types of crate:

    - **Library crates**, of which there may at most one in a package
    - **Binary crates**, of which there may be many in a package

    The **crate root** is the source file that the compiler uses to create the root module of the crate.

#### Copy
:   
    Copy is a [trait](#trait) that is implemented on simple types that are allocated on the stack alone.
    These types include integer and floating-point number types, char, bool, and fixed-size arrays and tuples.

#### Cursive
:   
    [cursive](https://docs.rs/cursive/) is a TUI framework.

    Cursive widgets are called **Views** (i.e. TextView).

    ```rs
    use cursive::views::TextView;
    use cursive::{Cursive, CursiveExt};

    fn main() {
        let mut siv = Cursive::new();
        siv.add_layer(TextView::new("Hello World!\nPress q to quit."));
        siv.add_global_callback('q', |s| s.quit());
        siv.run();
    }
    ```

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

**`cfg`**{: #cfg } [:material-language-rust:](https://doc.rust-lang.org/std/macro.cfg.html)
:   
    The **`cfg`** [macro](#macro) is used for conditional compilation and evaluates configuration at compile-time.
    

    Debug-only code not to be used in release builds
    
    ```rs
    if cfg!debug_assertions) {
        eprintln!("debug: {:?} -> {:?}", record, fields);
    }
    ```

    ```rs
    let my_directory = if cfg!(windows) {
        "windows-specific-directory"
    } else {
        "unix-directory"
    };
    ```

#### dbg
:   

    !!! info "&nbsp;"

        Not to be confused with the [Debug trait](#trait), which is used with the normal [`println!()` macro](#macro)!

    [`dbg!`](https://doc.rust-lang.org/std/macro.dbg.html) allows evaluation and printing of expressions during debugging or running with `cargo run`.

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

**Enum**{: #enum }
:   
    The **variants** of an enum can have different types and associated data.

    ```rs
    enum IpAddr {
        V4 ( u8, u8, u8, u8 ),
        V6(String)
    }
    ```

#### extern
:   
    **`extern`** facilitates the creation and use of FFI.
    
    Here, the "C" ABI, which specifies how to call the function at the assembly level, is specified:
    ```rs
    extern "C" {
        fn abs(input: i32) -> i32;
    }

    fn main() {
        unsafe {
            println!("Absolute value of -3 according to C: {}", abs(-3));
        }
    }
    ```

    **`extern crate`** specifies a dependency on an external crate

**futures**
:   
    Rust's main mechanism for asynchronous programming, implemented in the **Tokio** crate

#### HashMap
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



#### if let
:   
    **`if let`** is syntactic sugar for a pattern that matches one pattern while ignoring the rest.
    Notably, the syntax takes the pattern before the expression similar to a [`match`](#match) arm.
    
    === "if let"

        ``` rs
        if let Some(3) = some_u8_value {
            println!("three");
        }
        ```
    
    === "match"

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

#### Lifetimes
:   
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

#### macro
:   
    Referring to a family of features in Rust:

    - **Declarative** macros with `macro_rules!`
    - **procedural macros**:
        - [**Custom `#[derive]`**](#custom-derive) macros that specify code added with the `derive` attribute used on structs and enums
        - **[Attribute](#attribute)-like** macros that define custom attributes usable on any item
        - **Function-like** macros that look like function calls but operate on the tokens specified as their argument

    - `assert` [:material-language-rust:](https://doc.rust-lang.org/std/macro.assert.html) invokes `panic` if the provided expression cannot be evaluated to true at runtime
    - [`cfg`](#cfg) [:material-language-rust:](https://doc.rust-lang.org/std/macro.cfg.html) compiles code based on compile-time evaluation of configuration
    - [`dbg`](#dbg)
    - `eprintln` print to STDERR
    - `panic` [:material-language-rust:](https://doc.rust-lang.org/std/macro.panic.html) terminates the program with code 101 and should be used when the program reaches an unrecoverable state
    - `println` print to STDOUT
    - `unimplemented` [:material-language-rust:](https://doc.rust-lang.org/core/macro.unimplemented.html)
    - `try` for which the `?` operator is syntactic sugar

#### match
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

#### Option
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

#### Rc
:   
    **`Rc<T>`** is a *reference-counting* pointer that will keep track of how many owners it has.
    This number is exposed using **Rc::strong_count()**, passing a reference to the Rc pointer being interrogated.
    
    This smart pointer allows multiple owners of the same value.
    However, the dereferenced value may not be modified because the **DerefMut** trait is not implemented for Rc.

    ```rs
    use std::rc::Rc;

    fn main() {
        println!("Hello, world!");
        let num: i8 = 7;
        let pointer1: Rc<i8> = Rc::new(num);
        let pointer2: Rc<i8> = Rc::clone(&pointer1);
        let pointer3: Rc<i8> = Rc::clone(&pointer2);
        *pointer3 += 1; // Error!
        println!("Number of references: {}", Rc::strong_count(&pointer1)); // 3
        println!("Value of num: {}", *pointer1);
    }
    ```

    To achieve interior mutability, Rc is paired with [RefCell](#refcell) or [Cell](#cell).

#### RefCell
:   
    [**RefCell**](https://doc.rust-lang.org/std/cell/struct.RefCell.html) is a mutable memory location with dynamically checked borrow rules (i.e. at runtime).
    Unlike the getter and setter methods of its cousin [Cell](#cell), RefCell can be treated like any pointer by using the dereferencing operator **`*`**.
    RefCell does expose methods that determine how the wrapped value is returned.

    The **`borrow_mut()`** method is used to change the value of a RefCell which must be dereferenced because it returns a memory location.

    === "RefCell"

        ``` rs hl_lines="1 7 14 17"
        use std::cell::RefCell;

        #[derive(Debug)]
        struct Starship {
            name: String,
            registry: String,
            crew: RefCell<i16>
        }

        fn main() {
            let enterprise = Starship { 
                name : "USS Enterprise".to_string(), 
                registry : "NCC-1701".to_string(), 
                crew : RefCell::new(400)
            };
            dbg!(&enterprise);
            *enterprise.crew.borrow_mut() = 405;
            dbg!(&enterprise);
        }
        ```

    === "Cell"

        ``` rs hl_lines="1 7 14 17"
        use std::cell::Cell;

        #[derive(Debug)]
        struct Starship {
            name: String,
            registry: String,
            crew: Cell<i16>
        }

        fn main() {
            let enterprise = Starship { 
                name : "USS Enterprise".to_string(), 
                registry : "NCC-1701".to_string(), 
                crew : Cell::new(400)
            };
            dbg!(&enterprise);
            enterprise.crew.set(405);
            dbg!(&enterprise);
        }
        ```

    Here a mutable struct is owned by two [Rc](#rc) pointers, and a change applied through one pointer can be investigated using the other one.
    Note that there is no dereferencing operator because the Rc itself points to the RefCell which returns a memory location.

    ```rs
    use std::rc::Rc;
    use std::cell::RefCell;

    #[derive(Debug)]
    struct Starship {
        name: String,
        registry: String,
        crew: i16
    }

    fn main() {
        let enterprise = Starship {
            name: "USS Enterprise".to_string(),
            registry: "NCC-1701".to_string(),
            crew: 400
        };

        let enterprise_ptr1 = Rc::new(RefCell::new(enterprise));
        let enterprise_ptr2 = Rc::clone(&enterprise_ptr1);

        enterprise_ptr1.borrow_mut().crew=405;
        dbg!(&enterprise_ptr2);
    }
    ```

#### Result
:   
    Appears to be similar to [Option](#option), in that it is a generic meant to wrap other values..

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

#### Rnd
:   
    - `gen_ratio` [:material-language-rust:](https://docs.rs/rand/0.8.4/rand/trait.Rng.html#method.gen_ratio) return true based on the probability defined by the fraction defined by the arguments (i.e. `gen_ratio(1,5)` returns true 20% of the time)

#### Smart pointer
:   
    Smart pointers are data structures that act like references (which is but one of and the simplest pointer) but provide additional functionality and metadata.
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

    - [Box](#box)
    - **`Rc<T>`** which enables multiple owners of the same data and is used to count references, but only in single-threaded contexts
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

    - [`push_str`](https://doc.rust-lang.org/std/string/struct.String.html#method.push_str) append a string slice
    - [`lines`](https://doc.rust-lang.org/std/string/struct.String.html#method.push_str) returns an iterator of string slices
    - `replace` replace a pattern
        ```rs
        let s = String::from("Hello, World!");
        let s = &s.replace("World", "Planet");
        ```

#### structopt
:   
    [structopt](https://docs.rs/structopt/) is a CLI framework.

    Also see [clap](#clap).

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

    Referencing elements can be done with the index operator, which panics on an invalid index, or the `get()` method, which returns [None](#option) without panicking.

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

    **Methods:**

    - **reserve** [:material-language-rust:](https://doc.rust-lang.org/std/vec/struct.Vec.html#method.reserve) reserves space in memory for more elements, greater than or equal to `self.len()` + argument (`usize`)
