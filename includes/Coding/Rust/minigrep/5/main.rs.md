``` rs linenums="1" hl_lines="4 18-24"
fn main() {
    let args: Vec<String> = std::env::args().collect();

    let config = Config::new(&args);

    println!("Searching for {} in file {}", config.query, config.filename);

    let contents = std::fs::read_to_string(config.filename).expect("Couldn't read file");

    println!("{}", contents);
}

struct Config {
    query: String,
    filename: String,
}

impl Config {
    fn new(args: &[String]) -> Config {
        let query = args[1].clone();
        let filename = args[2].clone();
        Config { query, filename }
    }
}
```