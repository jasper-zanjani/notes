```rs linenums="1"
fn main() {
    let args: Vec<String> = std::env::args().collect();

    let query = &args[1];
    let filename = &args[2];

    println!("Searching for {}", query);
    println!("In file {}", filename);
}
```