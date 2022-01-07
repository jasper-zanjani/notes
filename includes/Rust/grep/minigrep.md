From RPL p. 233-263

=== "1"
    === "main.rs"

        ```rs
        fn main() {
            let args: Vec<String> = std::env::args().collect();
            println!("{:?}", args);
        }
        ```

    Read any command line arguments passed, collecting into a vector.


=== "2"
    === "main.rs"

        ```rs
        fn main() {
            let args: Vec<String> = std::env::args().collect();

            let query = &args[1];
            let filename = &args[2];

            println!("Searching for {}", query);
            println!("In file {}", filename);
        }
        ```

=== "3"
    === "main.rs"

        ```rs
        fn main() {
            let args: Vec<String> = std::env::args().collect();

            let query = &args[1];
            let filename = &args[2];

            println!("Searching for {}", query);
            println!("In file {}", filename);

            let contents = fs::read_to_string(filename)
                .expect("Somethign went wrong reading the file");

            println!("With text:\n{}", contents);
        }
        ```

    `fs::read_to_string()` takes the filename, opens it, and returns a `Result<String>` of the file's contents.


=== "4"
    === "main.rs"

        ``` rs hl_lines="4 13-16 18-22"
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

    Refactoring to abstract command-line argument parsing logic to its own function


=== "5"
    === "main.rs"

        ``` rs hl_lines="4 18-24"
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

    Refactor the config parser into Config's constructor


=== "6"
    === "main.rs"

        ```rs hl_lines="20-22"
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

    Implement error message on invalid number of arguments 


=== "7"
    === "main.rs"

        ``` rs hl_lines="4-7 24"
        fn main() {
            let args: Vec<String> = std::env::args().collect();

            let config = Config::new(&args).unwrap_or_else(|err| {
                println!("Problem parsing arguments: {}", err);
                std::process::exit(1);
            });

            println!("Searching for {} in file {}", config.query, config.filename);

            let contents = std::fs::read_to_string(config.filename).expect("Couldn't read file");

            println!("{}", contents);
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

    Remove previous error message and incorporate error in the Err variant of a [`Result<T,E>`](#resultte).
    The argument passed to `unwrap_or_else()` is a [**closure**](#closure).


=== "8"
    === "main.rs"

        ``` rs hl_lines="11 14-19"
        fn main() {
            let args: Vec<String> = std::env::args().collect();

            let config = Config::new(&args).unwrap_or_else(|err| {
                println!("Problem parsing arguments: {}", err);
                std::process::exit(1);
            });

            println!("Searching for {} in file {}", config.query, config.filename);

            run(config);
        }

        fn run(config: Config) {
            let contents = std::fs::read_to_string(config.filename)
                .expect("Couldn't read file");
            
            println!("{}", contents);
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

    Abstract program logic into `run()`


=== "9"
    === "main.rs"

        ```rs hl_lines="11 14-20"
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

    Refactor `run()` to return a [`Result<T,E>`](#resultte) in the `Ok` case and the **trait object** `Box<dyn Error>` for the error type.
    This allows various error types to be returned.

    Also, the `expect()` method is replaced by the `?` operator which returns the error type for the calling function to handle, rather than a boilerplate error message. 


=== "10"
    === "main.rs"


        ``` rs hl_lines="11-15"
        fn main() {
            let args: Vec<String> = std::env::args().collect();

            let config = Config::new(&args).unwrap_or_else(|err| {
                println!("Problem parsing arguments: {}", err);
                std::process::exit(1);
            });

            println!("Searching for {} in file {}", config.query, config.filename);

            if let Err(e) = run(config) {
                println!("Application error: {}", e);

                std::process::exit(1);
            }
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

    Rather than `unwrap()`, we use [`if let`](#if-let) to check for and handle errors from `run()`.


=== "11"
    === "lib.rs"

        ```rs
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
        ```

    === "main.rs"

        ```rs hl_lines="4-5 7"
        use std::process;
        use std::env;

        use lib::run;
        use lib::Config;

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

    Abstract all elements except `main()` into a library module


=== "12"
    === "lib.rs"

        ``` rs hl_lines="28-38 40-53"
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

    === "main.rs"

        ``` rs
        use std::process;
        use std::env;

        use lib::run;
        use lib::Config;

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

    Implement `search()` function and a unit test


=== "13"
    === "lib.rs"

        ```rs hl_lines="11-23 36-38"
        use std::fs;
        use std::error::Error;

        pub struct Config {
            pub query: String,
            pub filename: String,
        }

        impl Config {
            pub fn new(mut args: std::env::Args) -> Result<Config, &'static str> {
                args.next();

                let query = match args.next() {
                    Some(arg) => arg,
                    None => return Err("Didn't get a query string"),
                };

                let filename = match args.next() {
                    Some(arg) => arg,
                    None => return Err("Didn't get a file name")
                };

                Ok(Config { query, filename })
            }
        }

        pub fn run(config: Config)  -> Result<(), Box<dyn Error>> {
            let contents = fs::read_to_string(config.filename)?;
            
            println!("{}", contents);

            Ok(())
        }

        pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
            contents.lines()
                .filter(|line| line.contains(query))
                .collect()
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

    === "main.rs"

        ``` rs
        use std::process;
        use std::env;

        use lib::run;
        use lib::Config;

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

    Implementing iterators
