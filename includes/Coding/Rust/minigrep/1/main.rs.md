```rs linenums="1"
fn main() {
    let args: Vec<String> = std::env::args().collect();
    println!("{:?}", args);
}
```