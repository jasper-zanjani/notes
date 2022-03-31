```rs
fn main() {
    get_name().and_then(display_name);
}

fn get_name() -> Result<String, std::io::Error > {
    let mut name = String::new();
    std::io::stdin().read_line(&mut name)?;
    Ok(name.trim().to_string())
}

fn display_name(name: String) -> Result<(), std::io::Error> {
    println!("Hello, {}!", name);
    Ok(())
}
```