```rs linenums="1" hl_lines="11 14-20"
fn main() {
    let args: Vec<String> = std::env::args().collect();

    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        std::process::exit(1);
    });

    println!("Searching for {} in file {}", config.query, config.filename);

    run(config).unwrap();
}

fn run(config: Config)  -> Result<(), Box<dyn std::error::Error>> {
    let contents = std::fs::read_to_string(config.filename)?;
    
    println!("{}", contents);

    Ok(())
}

struct Config {
    query: String,
    filename: String,
}

impl Config {
    fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("not enough arguments");
        }
        let query = args[1].clone();
        let filename = args[2].clone();
        Ok(Config { query, filename })
    }
}
```