# clap

**Clap** is a command-line parser with both declarative (preferred, using **Parser**) and procedural APIs.

=== "Declarative"

    ```rs
    use clap::Parser; // (1)

    #[derive(Parser)]
    #[clap(name = "Hello, World!", version, author)] // (2)
    struct Cli {
        #[clap(short, long, default_value_t = String::from("Hello"))]
        greeting: String,

        #[clap(default_value_t = String::from("World"))]
        name: String,
    }

    fn main() {
        let cli = Cli::parse();
        println!("{}, {}!", cli.greeting, cli.name);
    }
    ```

    1. **Parser** requires the **derive** and **std** features:
    ```toml title="Cargo.toml"
    clap = { version = "3.0.12", features = ["std", "derive"], default-features = false}
    ```
    2. Without providing arguments to version or author, the relevant values will be pulled from the crate itself, similar to the [crate\_authors](https://docs.rs/clap/latest/clap/macro.crate_version.html) and [crate\_version](https://docs.rs/clap/latest/clap/macro.crate_version.html) macros for the procedural API.

=== "Procedural"

    ```rs
    use clap::{App, Arg, crate_version, crate_authors};

    fn main() {
        let args = App::new("Say hello")
            .version(crate_version!()) // (1)
            .author(crate_authors!())
            .arg(Arg::new("name") // (2)
                .default_value("World")
            .arg(Arg::new("greeting")
                .default_value("Hello")
                .short('g')
                .long("greeting")
            .get_matches();

        println!("{}, {}!", args.value_of("greeting").unwrap(), args.value_of("name").unwrap());
    }
    ```

    1. The [**crate\_authors**](https://docs.rs/clap/latest/clap/macro.crate_version.html) and [**crate\_version**](https://docs.rs/clap/latest/clap/macro.crate_version.html) macros allow you to pull information from the Cargo.toml at compile time.
    2. Since clap 3.0.0, **new()** takes the place of **with\_name()**, which is now deprecated.

## API

#### Parser
:   
    Using the [**Parser**](https://docs.rs/clap/latest/clap/trait.Parser.html#) derive allows command-line arguments and options to be defined on a struct with an attribute.
    Any **Command**, **Arg**, or **PossibleValue** method can be used as an attribute.
    
    === "Option"

        ```rs
        use clap::Parser;

        #[derive(Parser)]
        #[clap(name = "Hello, World!")]
        struct Args {
            #[clap(short, long, default_value_t = String::from("Hello"))]
            greeting: String,

            #[clap(default_value_t = String::from("World"))]
            name: String,
        }

        fn main() {
            let args = Args::parse();
            println!("{}, {}!", args.greeting, args.name);
        }
        ```

    === "Command"

        ```rs
        use clap::{Parser, Subcommand};

        #[derive(Parser)]
        #[clap(name = "Hello, World!")]
        struct Args {
            #[clap(subcommand)]
            greeting: Greeting,

            #[clap(default_value_t = String::from("World"))]
            name: String
        }

        #[derive(Subcommand)]
        enum Greeting {
            Hello,
            Greetings
        }

        fn main() {
            let args = Args::parse();
            println!("{}, {}!", args.greeting, args.name); // (1)
        }
        ```

        1. This requires the **Display** trait to be implemented
        ```rs
        impl std::fmt::Display for Greeting {
            fn fmt(&self, _: &mut std::fmt::Formatter) -> std::fmt::Result {
                match self {
                    Greeting::Hello => { print!("Hello"); Ok(()) },
                    _               => { print!("Greetings"); Ok(()) }
                }
            }
        }
        ```

#### clap\_app
:   
    The (now deprecated) **clap\_app** macro was used to create simple applications.

    Boolean values can be set to true with `+` and false with `!`:
    ```rs
    +required // Arg::required(true)
    !required // Arg::required(false)
    ```

## API

#### Parser
:   
    [**ArgEnum**](https://docs.rs/clap/latest/clap/trait.ArgEnum.html) and [**Subcommand**](https://docs.rs/clap/latest/clap/trait.Subcommand.html) can be used in very similar ways.
    ArgEnum variants do show up in the help output but inline with the Subcommand.

    === "ArgEnum"

        ```rs hl_lines="5 10"
        use clap::{ArgEnum, Parser};

        #[derive(Parser)]
        struct Cli {
            #[clap(arg_enum)]
            command: Actions,
        }

        #[derive(Copy, Clone, ArgEnum)]
        enum Actions {
            Eat,
            Drink,
        }

        fn main() {
            let cli = Cli::parse();

            match cli.command {
                Actions::Eat    => println!("Eating"),
                Actions::Drink  => println!("Drinking"),
            }
        }
        ```

    === "Subcommand"

        ```rs hl_lines="5 10"
        use clap::{Subcommand, Parser};

        #[derive(Parser)]
        struct Cli {
            #[clap(subcommand)]
            command: Actions,
        }

        #[derive(Subcommand)]
        enum Actions {
            Eat,
            Drink,
        }

        fn main() {
            let cli = Cli::parse();

            match cli.command {
                Actions::Eat    => println!("Eating"),
                Actions::Drink  => println!("Drinking"),
            }
        }
        ```

    Apparently they may not be used together, enums with a Subcommand derive attribute require variants that contain Args derived values:

    ```rs
    use clap::{Args, Parser, Subcommand};

    #[derive(Parser)]
    struct Cli {
        #[clap(subcommand)]
        command: Actions,
    }

    #[derive(Subcommand)]
    enum Actions {
        #[clap(arg_enum)]
        Eat(Foods),
        #[clap(arg_enum)]
        Drink(Drinks),
    }

    #[derive(Args)]
    struct Foods {
        name: String,
    }

    #[derive(Args)]
    struct Drinks {
        name: String
    }

    fn main() {
        let cli = Cli::parse();

        match cli.command {
            Actions::Eat(f) => {
                println!("Eating {}", f.name);
            }
            Actions::Drink(d) => {
                println!("Drinking {}", d.name);
            }
        }
    }
    ```

    ```rs
    use std::string::ParseError;

    use clap::{ArgEnum, Args, Parser, Subcommand, };

    #[derive(Parser)]
    struct Cli {
        #[clap(subcommand)]
        command: Actions,
    }

    #[derive(Subcommand)]
    enum Actions {
        #[clap(arg_enum)]
        Eat(Food),
        #[clap(arg_enum)]
        Drink(Drink),
    }

    #[derive(Args)]
    struct Food {
        name: String,
    }

    #[derive(Args)]
    struct Drink {
        drink: Drinks
    }

    #[derive(ArgEnum, Clone)]
    enum Drinks {
        Coke,
        Pepsi,
        Other
    }

    impl std::str::FromStr for Drinks {
        type Err = ParseError;

        fn from_str(s: &str) -> Result<Self, Self::Err> {
            match s {
                "coke" => Ok(Self::Coke),
                "pepsi" => Ok(Self::Pepsi),
                _ => Ok(Self::Other),
            }
        }
    }

    impl From<Drinks> for String {
        fn from(item: Drinks) -> String {
            match item {
                Drinks::Coke => String::from("Coke"),
                Drinks::Pepsi => String::from("Pepsi"),
                _ => String::from("Other")
            }
        }
    }

    fn main() {
        let cli = Cli::parse();

        match cli.command {
            Actions::Eat(f) => {
                println!("Eating {}", f.name);
            }
            Actions::Drink(d) => {
                println!("Drinking {}", String::from(d.drink));
            }
        }
    }
    ```

#### Starships
:   

    ```rs
    #[macro_use] extern crate diesel;
    use diesel::prelude::*;
    use diesel::result::QueryResult;
    use diesel::sqlite::SqliteConnection;

    mod models; // (1)
    use models::Starship;
    mod schema; // (2)
    use schema::starships::dsl::*;

    use clap::{Parser, Subcommand};

    #[derive(Parser)]
    struct Cli {
        #[clap(subcommand)]
        command: Commands,
    }

    #[derive(Subcommand)]
    enum Commands {
        Add(Starship),
        Update,
        Remove,
        List,
    }

    fn main() {
        let app = Cli::parse();
        match app.command {
            Commands::Add(s)    => add_ship(&s),
            Commands::List      => list_ships(),
            Commands::Remove    => println!("Removing"),
            Commands::Update    => println!("Updating"),
        }
    }

    fn add_ship(s: &Starship) {
        let conn = get_connection().unwrap();
        println!("Adding {:?}", s);
        s.insert_into(starships)
            .execute(&conn)
            .unwrap();
    }

    fn list_ships() {
        println!("{:?}", get_ships().unwrap());
    }

    fn get_connection() -> ConnectionResult<SqliteConnection> {
        dotenv::dotenv().expect("Couldn't load .env file");
        let url = &std::env::var("DATABASE_URL").unwrap();
        SqliteConnection::establish(url)
    }

    fn get_ships() -> QueryResult<Vec<Starship>> {
        let conn = get_connection().unwrap();
        starships
            .load::<Starship>(&conn)
    }
    ```

    1. Not that the order of the fields matters (for both postgres as well as sqlite connections), and the primary key should be the first field defined.
    ```rs
    use crate::schema::starships;
    use clap::Args;

    #[derive(Args,Debug, Queryable, Insertable, Identifiable, Clone)]
    #[primary_key(registry)]
    pub struct Starship {
        #[clap(long, short)]
        pub registry: String,
        #[clap(long, short)]
        pub name: String,
        #[clap(long, short)]
        pub crew: i32,
    }
    ```
    2.
    ```rs
    table! {
        starships (registry) {
            registry -> Text,
            name -> Text,
            crew -> Integer,
        }
    }
    ```