# Other programming languages
## C
> "A programming language is low level when its programs require attention to the irrelevant." 
> \- Alan Perlis\
Despite C's reputation as a low-level programming language, in fact it merely emulates the ancient PDP-11, which is the only machine for which its abstract machine can be described as "close to the metal". 
In the age of parallel processes, C's serial nature [[1](#sources)]
### Glossary
Term                                    | Description
:---                                    | :---
Loop unswitching                        | one of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control
Register rename engine                  | component of modern high-end cores which is one of the largest consumers of die area and power
Scalar Replacement Of Aggregates (SROA) | one of the core optimizations that a C compiler performs; attempts to replace `struct`s and arrays with fixed lengths with individual variables, which allows the compiler to treat accesses as independent and elide operations entirely if it can prove the results are neve visible, which also deletes padding sometimes
Scalar Vector Extensions (SVE)          | "", produced by ARM
Segmented architecture                  | pointers might be segment IDs and an offset
## Ruby
Syntax            | Definition
:---              | :---
`irb`             | REPL shell
`def`             | begin a function definition
`end`             | end a function definition
`require package` | import {package}, or 'gem'
`puts(*obj)`      | write given objects to `ios`; writes newline after any that do not already have one
`print(*obj)`     | write given objects to `ios`, with no newline
`array.sort()`    | sort in-place
## Rust 
`cargo` Rust's compilation manager, package manager, and general-purpose tool
`rustc` Rust compiler, usually invoked by `cargo`
`rustdoc` Rust documentation tool
### CLI
`cargo new --bin hello`
  - start a new package directory `hello`
`rustup doc --book`
  - load the locally-stored Rust book "The Rust Programming Language"
### tokens
`->` precedes return data type
### keywords
`mut` mutable, when preceding variable identifiers, allows their values to be changed
### data types
  - `u64` unsigned 64-bit integer
  - `i32` signed 32-bit integer
  - `u8` unsigned 8-bit integer (byte values)
  - `f32` single-precision floating point
  - `f64` double-precision floating point
### macros
`assert!()` verifies conditions within parentheses
## Sources
  1. "C is not a low-level programming language". [acm.org](https://queue.acm.org/detail.cfm?id=3212479)