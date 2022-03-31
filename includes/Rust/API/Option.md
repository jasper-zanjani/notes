```rs
enum Option<T> {
    Some(T),
    None
}
```
[**Option**](https://doc.rust-lang.org/stable/core/option/index.html) serves as a wrapper around a value.

Rust doesn't have the same implementation of null values that other languages do because handling null values is complicated and when unexpected they cause bugs.
Rather than null values, Rust implements null as a variant **`None`** of the enum **`Option<T>`**

The reason for this is because Rust conventionally handles enums in a [`match`](#match) statement, which requires **exhaustive** enumeration of all possible cases.
The compiler itself will raise an error if you compose a match statement which leaves some potential cases unhandled.
