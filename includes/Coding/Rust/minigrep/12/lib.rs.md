``` rs linenums="1" hl_lines="28-38 40-53"
use std::fs;
use std::error::Error;

pub struct Config {
    pub query: String,
    pub filename: String,
}

impl Config {
    pub fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("not enough arguments");
        }
        let query = args[1].clone();
        let filename = args[2].clone();
        Ok(Config { query, filename })
    }
}

pub fn run(config: Config)  -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;
    
    println!("{}", contents);

    Ok(())
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut results = Vec::new();

    for line in contents.lines() {
        if line.contains(query) {
            results.push(line);
        }
    }

    results
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn one_result() {
        let query = "duct";
        let contents= "\nRust:\nsafe, fast, productive.\nPick three.";
        assert_eq!(
            vec!["safe, fast, productive."],
            search(query, contents)
        )
    }
}
```