# Other programming languages
## C
> "A programming language is low level when its programs require attention to the irrelevant." -Alan Perlis

Despite C's reputation as a low-level programming language, in fact it merely emulates the ancient PDP-11, which is the only machine for which its abstract machine can be described as "close to the metal". 
In the age of parallel processes, C's serial nature [[1](#sources)]

## Golang
Golang or "**Go**" is a fast, high-performance, open-source, statically-typed compiled programming language. It was designed at Google by Rob Pike, Robert Giesemer, and Ken Thompson and first appeared in late 2009. Go has a syntax similar to C, but offers additional features such as memory safety, garbage collection, and others. [[2](#sources)]\
Hello world
```go
package main
import "fmt"
func main() {
  fmt.Println("Hello, Go World!")
}
```
Compile code [[3](#sources)]
```sh
go build script.go # compiles to a binary executable in the same directory named "script"
go run script.go   # compiles and runs the program
```
Mathematical function [[3](#sources)]
```go
package main

import ("fmt" "math")

func main() {
  fmt.Println(math.Max(9, 5))
}
```
Get a GitHub package named `$REPO` by `$AUTHOR`
```sh
go get github.com/$AUTHOR/$REPO
go get gopkg.in/kyokomi/emoji.v1 # Emoji support
```
Evaluate type of data
```go
package main
import ("fmt" "reflect")
func main() {
  fmt.Println(reflect.TypeOf(1))        # => int
  fmt.Println(reflect.TypeOf(9.5))      # => float64
  fmt.Println(reflect.TypeOf("string")) # => string
  fmt.Println(reflect.TypeOf(true))     # => bool
}
```


## Ruby
REPL shell
```sh
irb
```
Begin a function definition
```rb
def
```
End a function definition
```rb
end
```
Import {package}, or 'gem'
```rb
require package
```
Write given objects to `ios`; writes newline after any that do not already have one
```rb
puts(*obj)
```
Write given objects to `ios`, with no newline
```rb
print(*obj)
```
Sort in-place
```rb
array.sort()
```

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

## Glossary
Term                                    | Description
:---                                    | :---
Loop unswitching                        | one of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control
Register rename engine                  | component of modern high-end cores which is one of the largest consumers of die area and power
Scalar Replacement Of Aggregates (SROA) | one of the core optimizations that a C compiler performs; attempts to replace `struct`s and arrays with fixed lengths with individual variables, which allows the compiler to treat accesses as independent and elide operations entirely if it can prove the results are neve visible, which also deletes padding sometimes
Scalar Vector Extensions (SVE)          | "", produced by ARM
Segmented architecture                  | pointers might be segment IDs and an offset

## Sources
1. "C is not a low-level programming language". [acm.org](https://queue.acm.org/detail.cfm?id=3212479)
2. "Why is [Golang](#golang) so popular these days?" [DZone](https://dzone.com/articles/why-is-golang-so-popular-these-days-here-are-your?utm_medium=feed&utm_source=feedpress.me&utm_campaign=Feed:%20dzone): 2019/10/07.
3. "Go language for beginners in 16 parts!" [DZone](https://dzone.com/articles/go-language-for-beginners-in-16-parts): 2018/01/29.
