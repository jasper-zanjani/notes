```rs
fn main() {
    let name = String::from(match std::env::args().nth(1) { // (1)
        Some(s) => s,
        _ => "World";
    });
    println!("Hello, {}!", name);
}
```

1. **if let** is also possible, if more verbose.
```rs
let mut name = String::new();
if let Some(s) = std::env::args().nth(1) {
    name = s;
} else {
    name = String::from("World");
}
```