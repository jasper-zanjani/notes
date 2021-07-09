```rs linenums="1" hl_lines="20-22"
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
        if args.len() < 3 {
            panic!("Not enough args!");
        }
        let query = args[1].clone();
        let filename = args[2].clone();
        Config { query, filename }
    }
}
```