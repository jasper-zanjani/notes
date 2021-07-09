```rs
use std::io;

fn main() {
    println!("Enter name: ");
    let mut name = String::new();

    io::stdin()
        .read_line(&mut name)
        .expect("Didn't catch that...");

    println!("Hello, {}!", name.trim());
}
```