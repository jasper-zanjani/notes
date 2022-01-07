```rs
fn main() {
    println!("Enter name: ");
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let name = input.trim();
    println!("Hello, {}!", name);
}
```