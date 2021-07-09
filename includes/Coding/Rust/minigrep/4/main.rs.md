``` rs linenums="1" hl_lines="4 13-16 18-22"
fn main() {
    let args: Vec<String> = std::env::args().collect();

    let config = parse_config(&args);

    println!("Searching for {} in file {}", config.query, config.filename);

    let contents = std::fs::read_to_string(config.filename).expect("Couldn't read file");

    println!("{}", contents);
}

struct Config {
    query: String,
    filename: String,
}

fn parse_config(args: &[String]) -> Config {
    let query = args[1].clone();
    let filename = args[2].clone();
    Config { query, filename }
}
```