```rs
use std::env;

fn main() {
    let name = env::args().nth(1)
        .expect("Missing name. Usage: hello <name>");
    println!("Hello, {name}!", name = name);
}
```