```rs
fn main() {
    let name = std::env::args().nth(1)
        .expect("Missing name. Usage: hello <name>");
    println!("Hello, {name}!", name = name);
}
```