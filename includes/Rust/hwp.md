```rs
fn main() {
    let mut name = String::new();
    if let Some(s) = std::env::args().nth(1) {
        name = s;
    } else {
        name = String::from("World");
    }
    println!("Hello, {}!", name);
}
```