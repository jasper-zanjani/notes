```rs linenums="1" hl_lines="4-5 6"
use std::process;
use std::env;

use lib::Config;
use lib::run;

pub mod lib;

fn main() {
    let args: Vec<String> = env::args().collect();

    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    println!("Searching for {} in file {}", config.query, config.filename);

    if let Err(e) = run(config) {
        println!("Application error: {}", e);

        process::exit(1);
    }
}
```
