# Overview

<!-- 

Learning Rust has been exceptionally challenging for me, at least partly because the examples given
by teachers and books are very difficult. It seems that most people who take an interest in Rust 
already have familiarity with computer science topics that seem bizarre to me.

This is especially apparent in the Smart Pointers chapter of Klabnik (Chapter 15) where the section
on Rc<T> uses a scenario that assumes familiarity with "cons lists" from the Lisp programming lang-
uage. This is another unfortunate case of too many "dependencies" in the teaching material for a
technical topic. Klabnik also doesn't touch on Cells specifically but launches into RefCell<T>s and
uses the same cons list scenario he began in the beginning of the chapter. Unfortunately this is of 
very little use to anyone who is not familiar with that topic.

The Starships scenario provides a great case study on interior mutability. An immutable Starship
can be made partially mutable by changing a field to a Cell<T> type. This allows the crew complement
to be updated, which is a very intuitive and easy to understand application.


Cursive makes for an interesting use-case in learning closure semantics. This is especially true
when it comes to how some widgets do not implement the Nameable trait. This forces any retrieval
of the selection a user made to take place in a closure. Not only that, the `move` keyword must
be used because it must necessarily capture the environment of the current scope.

- Lifetime parameters and implementing std Traits was key in extending the Cursive Starships application.


Interactively discussing code may be best done using by pasting code into the styling generator here:
https://romannurik.github.io/SlidesCodeHighlighter/

Then pasting the output into Google Slides.

-->

> Rust's distinguishing feature as a programming language is its ability to prevent invalid data access at compile time.
> 
> &mdash;Tim McNamara

Rust offers **zero-cost abstractions**, where using the abstraction imposes no additional runtime overhead.

#### Documentation

Rust uses C-style line comments using `//` and block comments using `/*`, `*/`

**Doc comments** support markdown and are used to generate documentation with the use of [`cargo doc`](Glossary#cargo).

Markdown code blocks containing test cases are known as **doc tests** and can be run with `cargo test`, for library crates only.
Note that markdown code blocks in Rust doc comments don't need a language annotation.

- **Outer doc comments** are preceded by `///` and are written immediately preceding the code blocks they document
- **Inner doc comments** are preceded by `//!` and are written within code blocks, similar to docstrings in Python

### Data

Variable declarations are called **bindings** in Rust, and by convention variable names are in **snake\_case** (lower-case letters with words delimited by **\_**).
They are globally scoped by default unless they are declared in a code block.

Variables are immutable by default, so if their values are to change they must be marked with `mut`.
However, immutable variables are distinct from constants declared using `const`, which cannot be made mutable at all.
`const` identifiers are conventionally written in capitalized snake_case.

```rs
let language = "&nbsp;";        // Immutable
let mut language = "&nbsp;";    // Mutable
const language = "&nbsp;";      // Constant
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


Arrays and Tuples are considered primitive data types, albeit **Compound** ones.
Integer and Float are considered **Numeric Scalars**, while Boolean and Chars are considered **Non-Numeric Scalars**.

- Floating point numbers can be single-precision `f32` or double-precision `f64`.
- Booleans are `true` or `false` (lower-case).

Arrays are **homogeneous** sequences of elements and must be of a fixed length, declared at initialization, although the type can be determined implicitly.

Type can be inferred by the compiler or explicitly annotated after a colon:
=== "Implicit"

    ```rs
    let var = 0;
    let arr = [0 ; 4];
    let person = ("John", 35, "Doe");
    ```

=== "Explicit"

    ```rs
    let var:u8 = 0;
    let arr:[i32; 4] = [0, 0, 0, 0];
    let person : (&str, i32, &str) = ("John", 35, "Doe");
    ```

Array length can be given by the `len()` method.

Array slicing 

```rs
let arr:[i32;4] = [1, 2, 3, 4]; 
let slice_array2:&[i32] = &arr[0..2];
```

Tuples, like arrays, are fixed-length.
But unlike arrays they are **heterogeneous** sequences of elements.

Tuples can be **destructured** (i.e. unpacked)
```rs
let person = ("John", 35, "Doe");
let (first_name, age, last_name) = person;
```

Tuples **can** be made mutable with the `mut` keyword.

Rust's standard library includes a number of collections

- A [**vector**](Glossary#vector) stores a variable number of values of a single type in a sequence
- A [**String**](Glossary#string) is a collection of characters
- A **hash map** is a key-value store


#### Ownership

One of the key and unique features of Rust is the concept of **ownership**, which achieves memory safety without the use of a garbage collector.

!!! info "Stack versus heap"

    The stack and heap are locations in memory that are available to the application at runtime.

    - The **stack** is a LIFO that is used for sizes that are known at compile-time. It is comparable to a stack of plates of uniform size from which plates can be removed only from the top. Values are said to be "**pushed onto**" or "**popped off**" the stack. 
    - The **heap** is less organized and less efficient, and is used for sizes that are known only at runtime. The operating system must search for an appropriate memory location based on the application's request at runtime, returning a pointer, and this process makes the heap less efficient than the stack. Memory locations are said to be "**allocated on**" the heap. 

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

More specifically, certain types have a special annotation called the **`Copy` [trait](Glossary#trait)** which enable this behavior.
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

Pointer types like [**`Box<T>`**](Glossary#box) and those internal to [String](Glossary#string) and [Vec](Glossary#vector) are **owning pointers**: when the owner is dropped the referent is deallocated.
Nonowning pointer types are called **references** and have no effect on their referents' lifetimes.

There are two types of reference:

- **Shared references** let you read but not modify the referent
Multiple shared references to the same value can be created.
- **Mutable references** allow both reading and modifying of the referent
To prevent **data races** only one mutable reference to a location in a scope can exist.

A mutable reference and an immutable one cannot coexist in the same scope.
Moves after a borrow are also forbidden, for this same reason.

Here, the call to `push()` causes the [vector](Glossary#vector) to be reallocated on the heap after an immutable borrow was made.
```rs
let mut data = vec![1, 2, 3];
let x = &data[0];
data.push(4);

println!("{}", x);
```

#### Copy and Clone

Rust provides two traits that relate to the copying of data: [**Copy** and **Clone**](https://doc.rust-lang.org/book/appendix-03-derivable-traits.html?highlight=clone#clone-and-copy-for-duplicating-values).

- **Copy** allows values stored on the **stack only** to be duplicated. Any type whose parts all implement Copy can also derive Copy. However, this trait is rarely required since primitives stored on the stack already have optimizations available. In the background this relies on the **memcpy** syscall.
- **Clone** is for explicitly creating a **deep copy** of values, especially those allocated on the heap. Types that implement Copy also trivially implement Clone. 

### Collections

Accessing tuple elements is done with the **`.`** operator

``` rs
let coord: (i8, i8) = (10, 20);
println!("{}, {}", coord.0, coord.1);
```

## Paradigms

### OOP

Strictly speaking, OOP is not actually implemented in Rust because there is no inheritance.
However, objects that combine data with logic can be created `struct`s and `impl`s.

A group of methods that are shared by multiple types can have their signatures defined by a [**trait**](Glossary#trait).
Types then implement the trait, and functions can be defined that accept any type that does so by specifying the trait instead of a single concrete type.

```rs
pub fn notify(item: impl Summary) {
    println!("Breaking news! {}", item.summarize());
}
```


### TDD

Tests are functions annotated with the `#[test]` [**attribute**](Glossary#attribute).
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

### Concurrency

[**std::sync::atomic**](https://doc.rust-lang.org/stable/std/sync/atomic/index.html) provides thread-safe types modeled on the [atomics](https://doc.rust-lang.org/stable/nomicon/atomics.html) of C++20.
This model introduces the concept of **atomic accesses** which tell the hardware and compiler what ordering it has with relation to other accesses. 
This largely boils down to preventing reordering of instructions and determining how writes are propagated to other threads.

[**std::sync::RwLock**](https://doc.rust-lang.org/stable/std/sync/struct.RwLock.html) is a reader-writer lock, which allows a number of readers or at most one writer at any point in time.
A Mutex, by comparison, does not distinguish between readers or writers and blocks any threads waiting for the lock to become available.

```rs
let lock = std::sync::RwLock::new(1);

let mut n = lock.write().unwrap(); // (1)
*n = 2;

assert!(lock.try_read().is_err()); // (2)
```

1. **write** attempts to acquire the rwlock with exclusive write access and returns a [**LockResult**](https://doc.rust-lang.org/stable/std/sync/type.LockResult.html), which is really just a type alias for a Result.
2. [**try\_read**](https://doc.rust-lang.org/stable/std/sync/struct.RwLock.html) attempts to acquire the rwlock with shared read access.